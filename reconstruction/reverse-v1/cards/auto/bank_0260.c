/* libyoyo.so 覆盖卡组 0260
 * 函数 0x2af521..0x2afbb8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2af521 · png_set_read_user_chunk_fn · size=12 · insn=0 */

/* ── FUNC 0x2af52d · png_set_rows · size=44 · insn=0 */

/* ── FUNC 0x2af559 · png_set_compression_buffer_size · size=46 · insn=0 */

/* ── FUNC 0x2af586 · anon_2af586 · size=16 · insn=4 */
/* @0x2af586 tstlt r9, r0, lsr #2 */
/* @0x2af58a b 0xb897be <b2_toiTime+0x43031a> */
/* @0x2af58e addvs r0, r11, r2, lsl #6 */
/* @0x2af592 tstlt r8, r0, ror r7 */

/* ── FUNC 0x2af587 · png_set_invalid · size=14 · insn=0 */

/* ── FUNC 0x2af594 · anon_2af594 · size=492 · insn=123 */
/* @0x2af594 .word 0xf8c0b118 */
/* @0x2af598 .word 0xf8c01308 */
/* @0x2af59c ldrbmi r2, [r0, -r12, lsl #6]! */
/* @0x2af5a0 .word 0xf8c0b108 */
/* @0x2af5a4 .word 0x47701310 */
/* @0x2af5a8 .word 0xf8c0b108 */
/* @0x2af5ac ldrbmi r1, [r0, -r0, lsr #3]! */
/* @0x2af5b0 push {r3, r4, r6, r8, r9, r11, lr} */
/* @0x2af5b4 ldrbtmi r4, [r11], #-4080 */
/* @0x2af5b8 sadd16mi r6, r6, r11 */
/* @0x2af5bc ldmdavs r10, {r0, r1, r2, r3, r7, r12, sp, pc} */
/* @0x2af5c0 strmi r2, [r5], -r0, lsl #14 */
/* @0x2af5c4 .word 0x46896037 */
/* @0x2af5c8 andls r9, sp, #67108864 */
/* @0x2af5cc strmi r11, [r8], -r1, lsr #2 */
/* @0x2af5d0 svc #0xb2f606 */
/* @0x2af5d4 ldmdblt r0!, {r2, r9, r10, lr} */
/* @0x2af5d8 strtmi r4, [r8], -pc, asr #18 */
/* @0x2af5dc .word 0xf7f64479 */
/* @0x2af5e0 andhs pc, r0, r9, asr #30 */
/* @0x2af5e4 strtmi lr, [r8], -r12, lsl #1 */
/* @0x2af5e8 .word 0xf7f71ca1 */
/* @0x2af5ec pkhbtmi pc, r0, r4, lsl #23 */
/* @0x2af5f0 teqlt r8, r0, lsr r0 */
/* @0x2af5f4 .word 0xb124f8df */
/* @0x2af5f8 beq 0x5eba34 <g_SWFaavertbuff+0x1896c> */
/* @0x2af5fc stceq p0, c15, [r0], #-316 */
/* @0x2af600 ldrsh r4, [r5], -r11 */
/* @0x2af604 strtmi r4, [r8], -r6, asr #18 */
/* @0x2af608 .word 0xe7e84479 */
/* @0x2af60c ldmdale r6, {r0, r1, r2, r3, r4, r8, r9, r11, sp} */
/* @0x2af610 ldrbmi r2, [r10], -r8, lsr #2 */
/* @0x2af614 .word 0xf8cd4650 */
/* @0x2af618 .word 0xf606c000 */
/* @0x2af61c .word 0x4628efd6 */
/* @0x2af620 .word 0xf7f64651 */
/* @0x2af624 .word 0xf8ddff27 */
/* @0x2af628 .word 0xf808c000 */
/* @0x2af62c strlo r12, [r1, -r7] */
/* @0x2af630 andlo pc, r7, r9, lsl r8 */
/* @0x2af634 andeq lr, r7, #8, #22 */
/* @0x2af638 mvnle r2, r0, lsl #22 */
/* @0x2af63c .word 0xf1a3e006 */
/* @0x2af640 bhs 0xaf0044 <b2_toiTime+0x396ba0> */
/* @0x2af644 .word 0xf808d9e4 */
/* @0x2af648 ldrb r3, [r0, r7]! */
/* @0x2af64c mcrne p0, #0x3, r7, c1, c3, #0x0 */
/* @0x2af650 stmdane r7, {r4, r5, r11, sp, lr} ^ */
/* @0x2af654 bhs 0xac6764 <b2_toiTime+0x36d2c0> */
/* @0x2af658 ldmdbmi r2!, {r0, r2, r3, r8, r12, lr, pc} */
/* @0x2af65c movwls r4, #0x628 */
/* @0x2af660 .word 0xf7f64479 */
/* @0x2af664 blls 0x2ef288 <FT_Done_Memory+0x5614> */
/* @0x2af668 vldrpl d1, [r1, #-232] */
/* @0x2af66c .word 0xd1022920 */
/* @0x2af670 .word 0x3c015513 */
/* @0x2af674 ldmdavs r7!, {r0, r3, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x2af678 blhs 0xacd76c <b2_toiTime+0x3742c8> */
/* @0x2af67c stmdbmi r10!, {r2, r3, r8, r12, lr, pc} */
/* @0x2af680 ldrbtmi r4, [r9], #-1576 */
/* @0x2af684 mrc2 p7, #0x7, apsr_nzcv, c6, c6, #0x7 */
/* @0x2af688 shasxmi r1, r11, r9 */
/* @0x2af68c bne 0xff5c0f10 <b2_toiTime+0xfffffffffee67a6c> */
/* @0x2af690 movwlo r7, #0x183a */
/* @0x2af694 rscsle r2, r9, r0, lsr #20 */
/* @0x2af698 svclo #0x16833 */
/* @0x2af69c andhs r2, r0, r0, lsl #2 */
/* @0x2af6a0 svchs #0x1f817 */
/* @0x2af6a4 bhs 0xadbc34 <b2_toiTime+0x382790> */
/* @0x2af6a8 ldmdblt r8, {r0, r1, r2, r8, r12, lr, pc} */
/* @0x2af6ac movwlo r7, #0x101a */
/* @0x2af6b0 ldrb r2, [r5, r1]! */
/* @0x2af6b4 mrshs r3, apsr */
/* @0x2af6b8 ldrshvc lr, [r10], -r10 */
/* @0x2af6bc strb r3, [lr, r1, lsl #6]! */
/* @0x2af6c0 .word 0xb121701a */
/* @0x2af6c4 qadd16mi r4, r8, r9 */
/* @0x2af6c8 .word 0xf7f64479 */
/* @0x2af6cc stmdblt r12, {r0, r1, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2af6d0 ldmdavs r1!, {r3, r5, r9, r10, lr} */
/* @0x2af6d4 blx 0x76d6ba <b2_toiTime+0x14216> */
/* @0x2af6d8 qadd16mi r4, r8, r5 */
/* @0x2af6dc .word 0xf7f64479 */
/* @0x2af6e0 and pc, r12, r9, asr #29 */
/* @0x2af6e4 stmdble r10, {r0, r1, r2, r3, r6, r10, r11, sp} */
/* @0x2af6e8 qadd16mi r4, r8, r2 */
/* @0x2af6ec .word 0xf7f64479 */
/* @0x2af6f0 ldmdavs r3!, {r0, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2af6f4 subhs r2, pc, r0, lsl #4 */
/* @0x2af6f8 subhs pc, pc, r3, lsl #17 */
/* @0x2af6fc strtmi lr, [r0], -r0 */
/* @0x2af700 bls 0x615b0c <g_SWFaavertbuff+0x42a44> */
/* @0x2af704 addsmi r6, r10, #720896 */
/* @0x2af708 .word 0xf606d001 */
/* @0x2af70c andlt lr, pc, r4, ror #30 */
/* @0x2af710 svchi #0xf0e8bd */
/* @0x2af714 mulseq r3, lr, r3 */
/* @0x2af718 andeq lr, sp, r4, ror #14 */
/* @0x2af71c andeq lr, sp, r10, ror r7 */
/* @0x2af720 andeq lr, sp, r12, asr #14 */
/* @0x2af724 andeq lr, sp, r11, lsr r7 */
/* @0x2af728 andeq lr, sp, lr, lsr r7 */
/* @0x2af72c andeq lr, sp, r12, lsl r7 */
/* @0x2af730 andeq lr, sp, r3, lsr r7 */
/* @0x2af734 andeq lr, sp, r7, lsr r7 */
/* @0x2af738 .word 0xf8d0b128 */
/* @0x2af73c .word 0xf0433134 */
/* @0x2af740 .word 0xf8c00301 */
/* @0x2af744 .word 0x47703134 */
/* @0x2af748 .word 0xf890b148 */
/* @0x2af74c blhs 0x6bbf00 <g_SWFlinevertbuff+0x68e38> */
/* @0x2af750 .word 0xf8d0d105 */
/* @0x2af754 .word 0xf0433134 */
/* @0x2af758 .word 0xf8c00310 */
/* @0x2af75c .word 0x47703134 */
/* @0x2af760 .word 0xf890b160 */
/* @0x2af764 blhs 0x47bf18 <targetStr+0xcd8> */
/* @0x2af768 .word 0xf8d0d808 */
/* @0x2af76c .word 0xf0433134 */
/* @0x2af770 .word 0xf8c00304 */
/* @0x2af774 movwhs r3, #0x8134 */
/* @0x2af778 mvnlo pc, r0, lsl #17 */
/* @0x2af77c .word 0xb1484770 */

/* ── FUNC 0x2af595 · png_set_user_limits · size=12 · insn=0 */

/* ── FUNC 0x2af5a1 · png_set_chunk_cache_max · size=8 · insn=0 */

/* ── FUNC 0x2af5a9 · png_set_chunk_malloc_max · size=8 · insn=0 */

/* ── FUNC 0x2af5b1 · png_check_keyword · size=392 · insn=0 */

/* ── FUNC 0x2af739 · png_set_bgr · size=16 · insn=0 */

/* ── FUNC 0x2af749 · png_set_swap · size=24 · insn=0 */

/* ── FUNC 0x2af761 · png_set_packing · size=30 · insn=0 */

/* ── FUNC 0x2af77e · anon_2af77e · size=360 · insn=90 */
/* @0x2af77e .word 0xf890b148 */
/* @0x2af782 blhs 0x47bf36 <targetStr+0xcf6> */
/* @0x2af786 .word 0xf8d0d805 */
/* @0x2af78a vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2af78e .word 0xf8c03380 */
/* @0x2af792 .word 0x47703134 */
/* @0x2af796 .word 0xf8d0b158 */
/* @0x2af79a .word 0xf0433134 */
/* @0x2af79e .word 0xf8c00308 */
/* @0x2af7a2 stmdavs r11, {r2, r4, r5, r8, r12, sp} */
/* @0x2af7a6 sublo pc, r5, #192, #16 */
/* @0x2af7aa .word 0xf880790b */
/* @0x2af7ae ldrbmi r3, [r0, -r9, asr #4]! */
/* @0x2af7b2 .word 0xf890b150 */
/* @0x2af7b6 teqlt r11, r7, ror #3 */
/* @0x2af7ba ldrsblo pc, [r4, -r0]! */
/* @0x2af7be movweq pc, #0x2043 */
/* @0x2af7c2 teqlo r4, r0, asr #17 */
/* @0x2af7c6 ldrbmi r2, [r0, -r7]! */
/* @0x2af7ca ldrbmi r2, [r0, -r1]! */
/* @0x2af7ce .word 0xf8d0b1f8 */
/* @0x2af7d2 bhs 0x2fbcaa <ps_hints_apply+0xa8aa> */
/* @0x2af7d6 mvnsne pc, r0, lsr #17 */
/* @0x2af7da movwmi pc, #0x443 */
/* @0x2af7de teqlo r4, r0, asr #17 */
/* @0x2af7e2 ldrsblo pc, [r0, -r0]! */
/* @0x2af7e6 .word 0xf043bf0c */
/* @0x2af7ea .word 0xf0230380 */
/* @0x2af7ee .word 0xf8c00380 */
/* @0x2af7f2 .word 0xf8903130 */
/* @0x2af7f6 blhs 0x33bfa6 */
/* @0x2af7fa movwhs sp, #0x4101 */
/* @0x2af7fe ldmdblt r3!, {r0, r2, sp, lr, pc} */
/* @0x2af802 .word 0x31ebf890 */
/* @0x2af806 stmdble r2, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x2af80a .word 0xf8802302 */
/* @0x2af80e ldrbmi r3, [r0, -pc, ror #3]! */
/* @0x2af812 .word 0x4604b510 */
/* @0x2af816 .word 0xf7ffb138 */
/* @0x2af81a .word 0xf8d4ffd9 */
/* @0x2af81e .word 0xf0433134 */
/* @0x2af822 .word 0xf8c47380 */
/* @0x2af826 ldclt p1, c3, [r0, #-208] */
/* @0x2af82a .word 0xf8d0b128 */
/* @0x2af82e vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2af832 .word 0xf8c03300 */
/* @0x2af836 .word 0x47703134 */
/* @0x2af83a .word 0xf8d0b128 */
/* @0x2af83e vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2af842 .word 0xf8c02300 */
/* @0x2af846 .word 0x47703134 */
/* @0x2af84a .word 0xf8d0b128 */
/* @0x2af84e .word 0xf0433134 */
/* @0x2af852 .word 0xf8c00320 */
/* @0x2af856 .word 0x47703134 */
/* @0x2af85a bvc 0x39cca2 <ft_adobe_glyph_list+0xc37e> */
/* @0x2af85e stmdavs r3, {r0, r1, r3, r6, r8, r11, r12, sp, pc} ^ */
/* @0x2af862 addsmi r4, r9, #184549376 */
/* @0x2af866 stmdavc r10, {r2, r12, lr, pc} */
/* @0x2af86a .word 0xf80143d2 */
/* @0x2af86e ldrb r2, [r8, r1, lsl #22]! */
/* @0x2af872 stmdbhi r3, {r4, r8, r10, r11, r12, sp, pc} */
/* @0x2af876 andeq pc, r4, #64, #12 */
/* @0x2af87a swple r4, r3, [r9] */
/* @0x2af87e movwhs r6, #0x842 */
/* @0x2af882 andle r4, r4, #805306377 */
/* @0x2af886 bicmi r5, r0, #200, #24 */
/* @0x2af88a movwlo r5, #0x24c8 */
/* @0x2af88e ldclt p7, c14, [r0, #-992] */
/* @0x2af892 andeq pc, r4, #268435460 */
/* @0x2af896 swple r4, r3, [r12] */
/* @0x2af89a movwhs r6, #0x840 */
/* @0x2af89e andle r4, r8, #805306376 */
/* @0x2af8a2 bicsmi r5, r2, #51712 */
/* @0x2af8a6 stmne r10, {r1, r3, r6, r7, r10, r12, lr} ^ */
/* @0x2af8aa ldmdavc r4, {r2, r8, r9, r12, sp} ^ */
/* @0x2af8ae subsvc r4, r4, r4, ror #7 */
/* @0x2af8b2 ldclt p7, c14, [r0, #-976] */
/* @0x2af8b6 bvc 0x139ccfe <b2_toiTime+0xc4385a> */
/* @0x2af8ba tstle r1, r0, lsl r11 */
/* @0x2af8be stmdavs r2, {r0, r1, r7, r9, r11, r12, sp, lr} */
/* @0x2af8c2 movwhs r4, #0x35a */
/* @0x2af8c6 .word 0xf1014293 */
/* @0x2af8ca andle r0, r9, r2, lsl #2 */
/* @0x2af8ce .word 0x0c02f811 */
/* @0x2af8d2 .word 0xf8113301 */
/* @0x2af8d6 .word 0xf8014c01 */
/* @0x2af8da .word 0xf8010c01 */
/* @0x2af8de ldrb r4, [r1, r2, lsl #24]! */
/* @0x2af8e2 bvc 0x139ed2a <b2_toiTime+0xc45886> */

/* ── FUNC 0x2af77f · png_set_packswap · size=24 · insn=0 */

/* ── FUNC 0x2af797 · png_set_shift · size=28 · insn=0 */

/* ── FUNC 0x2af7b3 · png_set_interlace_handling · size=28 · insn=0 */

/* ── FUNC 0x2af7cf · png_set_filler · size=68 · insn=0 */

/* ── FUNC 0x2af813 · png_set_add_alpha · size=24 · insn=0 */

/* ── FUNC 0x2af82b · png_set_swap_alpha · size=16 · insn=0 */

/* ── FUNC 0x2af83b · png_set_invert_alpha · size=16 · insn=0 */

/* ── FUNC 0x2af84b · png_set_invert_mono · size=16 · insn=0 */

/* ── FUNC 0x2af85b · png_do_invert · size=92 · insn=0 */

/* ── FUNC 0x2af8b7 · png_do_swap · size=46 · insn=0 */

/* ── FUNC 0x2af8e4 · anon_2af8e4 · size=700 · insn=175 */
/* @0x2af8e4 blhs 0x48e1f8 <prim_v+0x4844> */
/* @0x2af8e8 blhs 0x32595c */
/* @0x2af8ec andle r6, r8, r2, asr #16 */
/* @0x2af8f0 andle r2, r9, r2, lsl #22 */
/* @0x2af8f4 tstle r4, r4, lsl #22 */
/* @0x2af8f8 ldrbtmi r4, [r11], #-2826 */
/* @0x2af8fc movwvc pc, #0x503 */
/* @0x2af900 blmi 0x527920 <SrcVerts+0x84964> */
/* @0x2af904 and r4, r3, r11, ror r4 */
/* @0x2af908 ldrbtmi r4, [r11], #-2824 */
/* @0x2af90c orrvc pc, r0, #12582912 */
/* @0x2af910 addsmi r4, r1, #167772160 */
/* @0x2af914 andle r4, r4, #8, #12 */
/* @0x2af918 .word 0x5c187800 */
/* @0x2af91c bleq 0x32d928 */
/* @0x2af920 .word 0x4770e7f7 */
/* @0x2af924 andeq r0, lr, r6, ror #2 */
/* @0x2af928 andeq r0, lr, r12, asr r1 */
/* @0x2af92c andeq r0, lr, r6, asr r1 */
/* @0x2af930 bvc 0x3dcef8 <error_g0017+0x35b9c> */
/* @0x2af934 .word 0x2c026803 */
/* @0x2af938 .word 0x2c06d005 */
/* @0x2af93c addhi pc, r1, r0, asr #32 */
/* @0x2af940 .word 0xf1400255 */
/* @0x2af944 bvc 0xfe40fc74 <b2_toiTime+0xfffffffffdcb67d0> */
/* @0x2af948 cmnle r10, r4, lsl #26 */
/* @0x2af94c .word 0xf0027a44 */
/* @0x2af950 .word 0x2c080580 */
/* @0x2af954 stmdblt r5!, {r0, r2, r3, r5, r8, r12, lr, pc} */
/* @0x2af958 strmi r2, [r12], -r3, lsl #10 */
/* @0x2af95c strne pc, [r3, #-0xb05] */
/* @0x2af960 stcne p0, c14, [r12, #-92] */
/* @0x2af964 strhs r3, [r1, #-0x103] */
/* @0x2af968 andle r4, lr, #-805306359 */
/* @0x2af96c strlo r7, [r1, #-0x826] */
/* @0x2af970 mrslo r3, apsr */
/* @0x2af974 .word 0x6c03f801 */
/* @0x2af978 .word 0x6c03f814 */
/* @0x2af97c .word 0x6c02f801 */
/* @0x2af980 .word 0x6c02f814 */
/* @0x2af984 .word 0x6c01f801 */
/* @0x2af988 tsths r8, lr, ror #15 */
/* @0x2af98c smlabths r3, r1, r2, r7 */
/* @0x2af990 adcmi lr, r12, #54 */
/* @0x2af994 stmdavc lr, {r0, r3, r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x2af998 .word 0x31043403 */
/* @0x2af99c .word 0x6c03f804 */
/* @0x2af9a0 .word 0x6c02f811 */
/* @0x2af9a4 .word 0x6c02f804 */
/* @0x2af9a8 .word 0x6c01f811 */
/* @0x2af9ac .word 0x6c01f804 */
/* @0x2af9b0 stmdblt sp, {r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2af9b4 eor r4, r7, r12, lsl #12 */
/* @0x2af9b8 streq pc, [r8], #-257 */
/* @0x2af9bc strhs r3, [r1, #-0x106] */
/* @0x2af9c0 andsle r4, r10, #-805306359 */
/* @0x2af9c4 strlo r7, [r1, #-0x826] */
/* @0x2af9c8 .word 0x31063408 */
/* @0x2af9cc .word 0x6c06f801 */
/* @0x2af9d0 .word 0x6c07f814 */
/* @0x2af9d4 .word 0x6c05f801 */
/* @0x2af9d8 .word 0x6c06f814 */
/* @0x2af9dc .word 0x6c04f801 */
/* @0x2af9e0 .word 0x6c05f814 */
/* @0x2af9e4 .word 0x6c03f801 */
/* @0x2af9e8 .word 0x6c04f814 */
/* @0x2af9ec .word 0x6c02f801 */
/* @0x2af9f0 .word 0x6c03f814 */
/* @0x2af9f4 .word 0x6c01f801 */
/* @0x2af9f8 teqhs r0, r2, ror #15 */
/* @0x2af9fc smlabths r6, r1, r2, r7 */
/* @0x2afa00 subvs r4, r3, r11, asr #6 */
/* @0x2afa04 rsb r2, r7, r3, lsl #6 */
/* @0x2afa08 smlalsle r4, r6, sp, r2 */
/* @0x2afa0c strlo r7, [r1, #-0x88e] */
/* @0x2afa10 strlo r3, [r6], #-264 */
/* @0x2afa14 .word 0x6c06f804 */
/* @0x2afa18 .word 0x6c05f811 */
/* @0x2afa1c .word 0x6c05f804 */
/* @0x2afa20 .word 0x6c04f811 */
/* @0x2afa24 .word 0x6c04f804 */
/* @0x2afa28 .word 0x6c03f811 */
/* @0x2afa2c .word 0x6c03f804 */
/* @0x2afa30 .word 0x6c02f811 */
/* @0x2afa34 .word 0x6c02f804 */
/* @0x2afa38 .word 0x6c01f811 */
/* @0x2afa3c .word 0x6c01f804 */
/* @0x2afa40 tstlt r12, r2, ror #15 */
/* @0x2afa44 mrsle r2, spsr */
/* @0x2afa48 strble r0, [r6, #-0x254] */
/* @0x2afa4c .word 0x2c027a84 */
/* @0x2afa50 bvc 0x13e3f64 <b2_toiTime+0xc8aac0> */
/* @0x2afa54 .word 0xf0022c08 */
/* @0x2afa58 tstle r3, r0, lsl #9 */
/* @0x2afa5c strhs r11, [r0], #-340 */
/* @0x2afa60 mulle r4, r12, r2 */
/* @0x2afa64 andspl pc, r4, r1, lsl r8 */
/* @0x2afa68 strlo r5, [r1], #-1293 */
/* @0x2afa6c strdhs lr, pc, [r8, -r8] */
/* @0x2afa70 eor r7, r0, r1, asr #5 */
/* @0x2afa74 smlalsle r4, r10, r12, r2 */
/* @0x2afa78 strbeq lr, [r4, #-0xb01] */
/* @0x2afa7c strpl r7, [sp, #-0x86d] */
/* @0x2afa80 ldrb r3, [r7, r1, lsl #8]! */
/* @0x2afa84 strmi r11, [sp], -r12, lsl #18 */
/* @0x2afa88 stcne p0, c14, [r12, #-96] */
/* @0x2afa8c strhs r3, [r1, #-0x102] */
/* @0x2afa90 .word 0xf104429d */
/* @0x2afa94 .word 0xf1010404 */
/* @0x2afa98 andle r0, r9, #-2147483648 */
/* @0x2afa9c .word 0x6c04f814 */
/* @0x2afaa0 .word 0xf8013501 */
/* @0x2afaa4 .word 0xf8146c02 */
/* @0x2afaa8 .word 0xf8016c03 */
/* @0x2afaac strb r6, [pc, r1, lsl #24]! */
/* @0x2afab0 tsths r0, r11, asr r0 */
/* @0x2afab4 subvs r7, r3, r1, asr #5 */
/* @0x2afab8 and r2, sp, r1, lsl #6 */
/* @0x2afabc .word 0xf105429c */
/* @0x2afac0 rscsle r0, r5, r2, lsl #10 */
/* @0x2afac4 strlo r7, [r1], #-2190 */
/* @0x2afac8 .word 0xf8053104 */
/* @0x2afacc .word 0xf8116c02 */
/* @0x2afad0 .word 0xf8056c01 */
/* @0x2afad4 ldrb r6, [r1, r1, lsl #24]! */
/* @0x2afad8 subseq r7, r3, #805306376 */
/* @0x2afadc bvc 0x3a4ef0 <af_blue_strings+0x2bcc> */
/* @0x2afae0 movweq pc, #0x4023 */
/* @0x2afae4 ldcllt p2, c7, [r0, #-12]! */
/* @0x2afae8 bvc 0x39cf30 <ft_adobe_glyph_list+0xc60c> */
/* @0x2afaec ldrble r0, [r5, #-0x79a] */
/* @0x2afaf0 bvc 0x12c9b00 <b2_toiTime+0xb7065c> */
/* @0x2afaf4 .word 0xd1222808 */
/* @0x2afaf8 .word 0xd10e2b02 */
/* @0x2afafc blx 0x378712 <_ZTS13C_UTF16String+0xf7be> */
/* @0x2afb00 addsmi r1, r1, #536870912 */
/* @0x2afb04 stmdavc r11, {r3, r12, lr, pc} */
/* @0x2afb08 .word 0xf8113103 */
/* @0x2afb0c .word 0xf8010c01 */
/* @0x2afb10 .word 0xf8013c01 */
/* @0x2afb14 ldrb r0, [r4, r3, lsl #24]! */
/* @0x2afb18 blhs 0x45ef60 <g_RomDisk+0x67740> */
/* @0x2afb1c movwhs sp, #0x13e */
/* @0x2afb20 .word 0xf1014293 */
/* @0x2afb24 andle r0, r9, r4, lsl #2 */
/* @0x2afb28 .word 0x0c04f811 */
/* @0x2afb2c .word 0xf8113301 */
/* @0x2afb30 .word 0xf8014c02 */
/* @0x2afb34 .word 0xf8010c02 */
/* @0x2afb38 ldrb r4, [r1, r4, lsl #24]! */
/* @0x2afb3c ldmdahs r0, {r4, r8, r10, r11, r12, sp, pc} */
/* @0x2afb40 blhs 0x363ff8 <_ZTS12CDS_Priority+0x6050> */
/* @0x2afb44 movwhs sp, #0x114 */
/* @0x2afb48 mulsle r0, r3, r2 */
/* @0x2afb4c movwlo r7, #0x1808 */
/* @0x2afb50 .word 0x3106790c */
/* @0x2afb54 .word 0x0c02f801 */
/* @0x2afb58 .word 0x4c06f801 */
/* @0x2afb5c .word 0x0c05f811 */
/* @0x2afb60 .word 0x4c01f811 */
/* @0x2afb64 .word 0x0c01f801 */
/* @0x2afb68 .word 0x4c05f801 */
/* @0x2afb6c ldclt p7, c14, [r0, #-944] */
/* @0x2afb70 tstle r3, r6, lsl #22 */
/* @0x2afb74 addsmi r2, r3, #0, #6 */
/* @0x2afb78 stmdavc r8, {r4, r12, lr, pc} */
/* @0x2afb7c stmdbvc r12, {r0, r8, r9, r12, sp} */
/* @0x2afb80 .word 0xf8013108 */
/* @0x2afb84 .word 0xf8010c04 */
/* @0x2afb88 .word 0xf8114c08 */
/* @0x2afb8c .word 0xf8110c07 */
/* @0x2afb90 .word 0xf8014c03 */
/* @0x2afb94 .word 0xf8010c03 */
/* @0x2afb98 strb r4, [r12, r7, lsl #24]! */
/* @0x2afb9c .word 0xb128bd10 */

/* ── FUNC 0x2af8e5 · png_do_packswap · size=76 · insn=0 */

/* ── FUNC 0x2af931 · png_do_strip_filler · size=440 · insn=0 */

/* ── FUNC 0x2afae9 · png_do_bgr · size=182 · insn=0 */

/* ── FUNC 0x2afb9e · anon_2afb9e · size=28 · insn=7 */
/* @0x2afb9e .word 0xf8c0b128 */
/* @0x2afba2 .word 0xf8801124 */
/* @0x2afba6 .word 0xf8802128 */
/* @0x2afbaa ldrbmi r3, [r0, -r9, lsr #2]! */
/* @0x2afbae .word 0xf8d0b108 */
/* @0x2afbb2 ldrbmi r0, [r0, -r4, lsr #2]! */
/* @0x2afbb6 ldrlt r0, [r8, #-0x0]! */

/* ── FUNC 0x2afb9f · png_set_user_transform_info · size=16 · insn=0 */

/* ── FUNC 0x2afbaf · png_get_user_transform_ptr · size=8 · insn=0 */

/* ── FUNC 0x2afbb8 · anon_2afbb8 · size=2448 · insn=612 */
/* @0x2afbb8 sasxmi r11, r5, r8 */
/* @0x2afbbc cmnlt r0, r4, lsl #12 */
/* @0x2afbc0 .word 0xf8d44608 */
/* @0x2afbc4 .word 0x21013118 */
/* @0x2afbc8 cdp p6, #0x7, c15, c8, c6, #0x0 */
/* @0x2afbcc andle r4, r6, r8, lsr #5 */
/* @0x2afbd0 strtmi r4, [r0], -r3, lsl #18 */
/* @0x2afbd4 ldrhtmi lr, [r8], -sp */
/* @0x2afbd8 .word 0xf7f64479 */
/* @0x2afbdc ldclt p12, c11, [r8, #-156]! */
/* @0x2afbe0 andeq lr, sp, r4, ror r2 */
/* @0x2afbe4 .word 0xf8d0b118 */
/* @0x2afbe8 .word 0xf06b0118 */
/* @0x2afbec .word 0x4770bf97 */
/* @0x2afbf0 .word 0xf8d0b508 */
/* @0x2afbf4 .word 0xb10b3110 */
/* @0x2afbf8 stclt p7, c4, [r8, #-608] */
/* @0x2afbfc pop {r1, r8, r11, lr} */
/* @0x2afc00 ldrbtmi r4, [r9], #-8 */
/* @0x2afc04 .word 0xbc12f7f6 */
/* @0x2afc08 andeq lr, sp, r6, asr r2 */
/* @0x2afc0c .word 0xf8d0b508 */
/* @0x2afc10 .word 0xb1033210 */
/* @0x2afc14 stclt p7, c4, [r8, #-608] */
/* @0x2afc18 .word 0x4604b510 */
/* @0x2afc1c .word 0xf8c0b1f8 */
/* @0x2afc20 ldmdblt r2, {r3, r4, r8, r12} */
/* @0x2afc24 ldrbtmi r4, [r10], #-2574 */
/* @0x2afc28 .word 0xf8c46812 */
/* @0x2afc2c ldmdblt r3, {r4, r8, sp} */
/* @0x2afc30 ldrbtmi r4, [r11], #-2828 */
/* @0x2afc34 .word 0xf8c4681b */
/* @0x2afc38 .word 0xf8d43210 */
/* @0x2afc3c cmnlt r3, r4, lsl r1 */
/* @0x2afc40 strtmi r4, [r0], -r9, lsl #18 */
/* @0x2afc44 .word 0xf8c42300 */
/* @0x2afc48 ldrbtmi r3, [r9], #-276 */
/* @0x2afc4c .word 0xfc12f7f6 */
/* @0x2afc50 strtmi r4, [r0], -r6, lsl #18 */
/* @0x2afc54 pop {r0, r3, r4, r5, r6, r10, lr} */
/* @0x2afc58 .word 0xf7f64010 */
/* @0x2afc5c ldclt p12, c11, [r0, #-44] */
/* @0x2afc60 andseq r1, r4, lr, ror lr */
/* @0x2afc64 andseq r1, r4, r6, ror lr */
/* @0x2afc68 andeq lr, sp, r10, lsr #4 */
/* @0x2afc6c andeq lr, sp, r8, asr r2 */
/* @0x2afc70 mvnsmi lr, sp, lsr #18 */
/* @0x2afc74 addlt r4, lr, r12, lsl #12 */
/* @0x2afc78 stmdahs r0, {r0, r2, r9, r10, lr} */
/* @0x2afc7c sbchi pc, r2, r0 */
/* @0x2afc80 .word 0xf0002900 */
/* @0x2afc84 .word 0xf8d080bf */
/* @0x2afc88 .word 0xf413312c */
/* @0x2afc8c .word 0xf0406680 */
/* @0x2afc90 .word 0xf00180b9 */
/* @0x2afc94 .word 0xf8d5fa55 */
/* @0x2afc98 ldrbeq r3, [r10], #300 */
/* @0x2afc9c .word 0xf8d5d509 */
/* @0x2afca0 ldrsblt r3, [r3, -r12]! */
/* @0x2afca4 qsaxmi r4, r8, r9 */
/* @0x2afca8 .word 0xf7f64479 */
/* @0x2afcac .word 0xf8c5fbe3 */
/* @0x2afcb0 mcrvc p2, #0x3, r6, c2, c12, #0x6 */
/* @0x2afcb4 cdpvc p6, #0x2, c4, c3, c8, #0x1 */
/* @0x2afcb8 cdpvc p2, #0xa, c9, c2, c0, #0x0 */
/* @0x2afcbc cdpvc p2, #0xe, c9, c2, c1, #0x0 */
/* @0x2afcc0 svcvc #0x229202 */
/* @0x2afcc4 ldm r4, {r0, r1, r9, r12, pc} */
/* @0x2afcc8 .word 0xf0010006 */
/* @0x2afccc stmvs r3!, {r0, r1, r3, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2afcd0 strle r0, [r8, #-0x7db] */
/* @0x2afcd4 bvc 0x56b42c <g_SWFlineaavertbuff+0x18364> */
/* @0x2afcd8 bvs 0xffcab7bc <b2_toiTime+0xffffffffff552318> */
/* @0x2afcdc mrrc p6, #0x2, r4, r3, c8 */
/* @0x2afce0 .word 0xf0012b16 */
/* @0x2afce4 stmvs r3!, {r0, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2afce8 strle r0, [r4, #-0x51f] */
/* @0x2afcec .word 0xf8944628 */
/* @0x2afcf0 .word 0xf001102c */
/* @0x2afcf4 stmvs r3!, {r0, r1, r3, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2afcf8 strle r0, [r10, #-0x4de] */
/* @0x2afcfc .word 0x30ccf8d4 */
/* @0x2afd00 .word 0xf8d44628 */
/* @0x2afd04 andhs r1, r0, #196 */
/* @0x2afd08 .word 0xf8d49300 */
/* @0x2afd0c .word 0xf00130c8 */
/* @0x2afd10 stmvs r3!, {r0, r1, r2, r3, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2afd14 strle r0, [r5, #-0x798] */
/* @0x2afd18 .word 0xf1044628 */
/* @0x2afd1c cdpvc p1, #0x6, c0, c2, c4, #0x2 */
/* @0x2afd20 cdp2 p0, #0xc, c15, c4, c1, #0x0 */
/* @0x2afd24 ldrbeq r6, [r9, -r3, lsr #17] */
/* @0x2afd28 ldc p5, c13, [r4, #200] */
/* @0x2afd2c .word 0xeeb77a21 */
/* @0x2afd30 vldr s15, [r4, #796] */
/* @0x2afd34 strtmi r6, [r8], -r0, lsr #20 */
/* @0x2afd38 blvc 0x2eb374 <FT_Done_Memory+0x1700> */
/* @0x2afd3c bvc 0xb6b394 <b2_toiTime+0x411ef0> */
/* @0x2afd40 bvc 0xff4ab824 <b2_toiTime+0xfffffffffed52380> */
/* @0x2afd44 blvc 0x36b380 <_ZTS13C_UTF16String+0x242c> */
/* @0x2afd48 bvc 0xbab3a0 <b2_toiTime+0x451efc> */
/* @0x2afd4c bvc 0xff4ab830 <b2_toiTime+0xfffffffffed5238c> */
/* @0x2afd50 blvc 0x3eb38c <bdf_driver_class+0x804> */
/* @0x2afd54 bvc 0xbeb3ac <b2_toiTime+0x491f08> */
/* @0x2afd58 bvc 0xff4ab83c <b2_toiTime+0xfffffffffed52398> */
/* @0x2afd5c blvc 0x46b398 <g_RomDisk+0x73b78> */
/* @0x2afd60 bvc 0xc2b3b8 <b2_toiTime+0x4d1f14> */
/* @0x2afd64 bvc 0xff4ab848 <b2_toiTime+0xfffffffffed523a4> */
/* @0x2afd68 blvc 0x4eb3a4 <SrcVerts+0x483e8> */
/* @0x2afd6c bvc 0xc6b3c4 <b2_toiTime+0x511f20> */
/* @0x2afd70 bvc 0xff4ab854 <b2_toiTime+0xfffffffffed523b0> */
/* @0x2afd74 blvc 0x56b3b0 <g_SWFlineaavertbuff+0x182e8> */
/* @0x2afd78 bvc 0xcab3d0 <b2_toiTime+0x551f2c> */
/* @0x2afd7c bvc 0xff4ab860 <b2_toiTime+0xfffffffffed523bc> */
/* @0x2afd80 blvc 0x5eb3bc <g_SWFaavertbuff+0x182f4> */
/* @0x2afd84 bvc 0xffc6b868 <b2_toiTime+0xffffffffff5123c4> */
/* @0x2afd88 blhs 0x8aaedc <b2_toiTime+0x151a38> */
/* @0x2afd8c cdp2 p0, #0xe, c15, c0, c1, #0x0 */
/* @0x2afd90 .word 0x30c0f8d4 */
/* @0x2afd94 .word 0xf8d5b933 */
/* @0x2afd98 vst4.8 {d19, d21, d23, d25}, [r3:128], r12 */
/* @0x2afd9c .word 0xf8c56380 */
/* @0x2afda0 eor r3, pc, r12, lsr #2 */
/* @0x2afda4 .word 0x8068f8df */
/* @0x2afda8 .word 0xf8d42714 */
/* @0x2afdac ldrbtmi r6, [r8], #188 */
/* @0x2afdb0 .word 0x20c0f8d4 */
/* @0x2afdb4 ldrsbtlo pc, [r12], r4 */
/* @0x2afdb8 movwlo pc, #0x2b07 */
/* @0x2afdbc rscle r4, r10, #-536870903 */
/* @0x2afdc0 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x2afdc4 .word 0xf90ef7f6 */
/* @0x2afdc8 andsle r2, r9, r1, lsl #16 */
/* @0x2afdcc .word 0xb1bb7c33 */
/* @0x2afdd0 svceq #0x6f013 */
/* @0x2afdd4 ldmvc r3!, {r2, r4, r8, r12, lr, pc} ^ */
/* @0x2afdd8 strle r0, [r5], #-1690 */
/* @0x2afddc andle r2, r3, r3, lsl #16 */
/* @0x2afde0 ldrsblo pc, [r0, -r5]! */
/* @0x2afde4 strle r0, [r11, #-0x3db] */
/* @0x2afde8 ldmdblt r11, {r0, r1, r4, r5, r6, r7, r11, sp, lr} */
/* @0x2afdec strbmi r4, [r1], -r8, lsr #12 */
/* @0x2afdf0 blx 0x12eddd2 <b2_toiTime+0xb9492e> */
/* @0x2afdf4 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x2afdf8 ldmvs r3!, {r1, r4, r5, r7, r11, sp, lr} ^ */
/* @0x2afdfc blx 0x1a6be08 <b2_toiTime+0x1312964> */
/* @0x2afe00 bfi r3, r4, #12, #10 */
/* @0x2afe04 pop {r1, r2, r3, r12, sp, pc} */
/* @0x2afe08 svclt #0x81f0 */
/* @0x2afe0c andeq r12, sp, r2, lsr #19 */
/* @0x2afe10 andeq lr, sp, r2, lsr r1 */
/* @0x2afe14 svcmi #0xf0e92d */
/* @0x2afe18 addlt r4, r5, lr, lsl #12 */
/* @0x2afe1c stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x2afe20 rscshi pc, pc, r0 */
/* @0x2afe24 .word 0xf0002900 */
/* @0x2afe28 .word 0xf7ff80fc */
/* @0x2afe2c ldmvs r3!, {r0, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2afe30 strle r0, [r5, #-0x71a] */
/* @0x2afe34 ldmdbvs r1!, {r3, r4, r5, r9, r10, lr} */
/* @0x2afe38 .word 0xf0018ab2 */
/* @0x2afe3c and pc, r7, r9, asr #23 */
/* @0x2afe40 blhs 0x38f814 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x3870> */
/* @0x2afe44 ldmdbmi r8!, {r2, r8, r12, lr, pc} ^ */
/* @0x2afe48 ldrbtmi r4, [r9], #-1592 */
/* @0x2afe4c blx 0xffe6de2c <b2_toiTime+0xffffffffff714988> */
/* @0x2afe50 .word 0x06db68b3 */
/* @0x2afe54 .word 0xf8d7d51a */
/* @0x2afe58 tsteq sp, #52, #2 */
/* @0x2afe5c cdpvc p4, #0x7, c13, c2, c9, #0x0 */
/* @0x2afe60 bhi 0xfff81748 <b2_toiTime+0xffffffffff8282a4> */
/* @0x2afe64 andls r6, r0, #61696 */
/* @0x2afe68 subseq pc, r0, #-2147483647 */
/* @0x2afe6c .word 0xff88f001 */
/* @0x2afe70 cdpvc p0, #0x7, c14, c3, c12, #0x0 */
/* @0x2afe74 mvnsle r2, r3, lsl #22 */
/* @0x2afe78 bhi 0xfff38a80 <b2_toiTime+0xffffffffff7df5dc> */
/* @0x2afe7c ble 0xffe408d0 <b2_toiTime+0xffffffffff6e742c> */
/* @0x2afe80 ldclpl p12, c6, [r1], {242} */
/* @0x2afe84 ldrbpl r4, [r1], #969 */
/* @0x2afe88 ldrb r3, [r6, r1, lsl #6]! */
/* @0x2afe8c .word 0x069c68b3 */
/* @0x2afe90 ldrtmi sp, [r8], -r5, lsl #10 */
/* @0x2afe94 cmpeq r10, r6, lsl #2 */
/* @0x2afe98 .word 0xf0017e72 */
/* @0x2afe9c ldmvs r3!, {r0, r1, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2afea0 strle r0, [r4, #-0x658] */
/* @0x2afea4 svcvs #0xf14638 */
/* @0x2afea8 .word 0xf0028ab2 */
/* @0x2afeac ldmvs r3!, {r0, r2, r3, r4, r5, r11, r12, sp, lr, pc} */
/* @0x2afeb0 strle r0, [r6, #-0x5d9] */
/* @0x2afeb4 mrcvs p6, #0x3, r4, c1, c8, #0x1 */
/* @0x2afeb8 .word 0xf8966eb2 */
/* @0x2afebc .word 0xf002306c */
/* @0x2afec0 ldmvs r3!, {r0, r1, r3, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2afec4 ldrle r0, [r1, #-0x55a] */
/* @0x2afec8 umlalslo pc, r4, r6, r8 */
/* @0x2afecc lsleq pc, r6, #2 */
/* @0x2afed0 movwls r4, #0x638 */
/* @0x2afed4 umlalslo pc, r5, r6, r8 */
/* @0x2afed8 .word 0xf8d69301 */
/* @0x2afedc movwls r3, #0x20ac */
/* @0x2afee0 ldrsbtlo pc, [r0], r6 */
/* @0x2afee4 stmdbgt lr, {r0, r1, r8, r9, r12, pc} */
/* @0x2afee8 rfeib r2! */
/* @0x2afeec ldrbeq r6, [r11], #-2227 */
/* @0x2afef0 ldmib r6, {r1, r3, r8, r10, r12, lr, pc} ^ */
/* @0x2afef4 shasxmi r4, r8, r10 */
/* @0x2afef8 smullsne pc, r12, r6, r8 */
/* @0x2afefc teqhs r8, #3506176 */
/* @0x2aff00 strmi lr, [r0, #-0x9cd] */
/* @0x2aff04 blx 0x126bf14 <b2_toiTime+0xb12a70> */
/* @0x2aff08 .word 0x061d68b3 */
/* @0x2aff0c ldrtmi sp, [r8], -r6, lsl #10 */
/* @0x2aff10 svcvs #0x726f31 */
/* @0x2aff14 .word 0x3078f896 */
/* @0x2aff18 blx 0x226bf28 <b2_toiTime+0x1b12a84> */
/* @0x2aff1c ldreq r6, [r12, #0x8b3] */
/* @0x2aff20 ldrtmi sp, [r8], -r10, lsl #10 */
/* @0x2aff24 teqeq r12, r6, lsl #2 */
/* @0x2aff28 blx 0xfef6bf38 <b2_toiTime+0xfffffffffe812a94> */
/* @0x2aff2c .word 0x312cf8d7 */
/* @0x2aff30 movwvc pc, #0x443 */
/* @0x2aff34 smlawtlo r12, r7, r8, pc */
/* @0x2aff38 ldreq r6, [r8], #2227 */
/* @0x2aff3c strhs sp, [r0], #-1281 */
/* @0x2aff40 .word 0xf04fe008 */
/* @0x2aff44 .word 0xf04f0800 */
/* @0x2aff48 .word 0xf06f0a1c */
/* @0x2aff4c .word 0xf06f0902 */
/* @0x2aff50 ands r0, r8, r1, lsl #22 */
/* @0x2aff54 ldrsblo pc, [r8], #134 */
/* @0x2aff58 ble 0xfff409d0 <b2_toiTime+0xffffffffff7e752c> */
/* @0x2aff5c ldrsbne pc, [r4], #134 */
/* @0x2aff60 bl 0x301848 <TT_New_Context+0x1640> */
/* @0x2aff64 strlo r1, [r1], #-260 */
/* @0x2aff68 ldc2 p0, c15, [r0, #-4] */
/* @0x2aff6c ldrshle lr, [pc, -r2] */
/* @0x2aff70 ldrtmi r9, [r8], -r0, lsl #6 */
/* @0x2aff74 stmvs r2!, {r0, r5, r6, r11, sp, lr} */
/* @0x2aff78 .word 0xf844f002 */
/* @0x2aff7c .word 0xf8436bb3 */
/* @0x2aff80 .word 0xf108b005 */
/* @0x2aff84 blvs 0xf71f90 <b2_toiTime+0x818aec> */
/* @0x2aff88 ble 0xa015f0 <b2_toiTime+0x2a814c> */
/* @0x2aff8c .word 0xf508fb0a */
/* @0x2aff90 ldmdbne r12, {r0, r1, r4, r5, r7, r8, r9, r11, sp, lr} ^ */
/* @0x2aff94 blhs 0x2c6508 <_ZN16b2BlockAllocatorC2Ev+0x38> */
/* @0x2aff98 stmibvs r2!, {r0, r3, r5, r6, r7, r8, r10, r11, r12, lr, pc} */
/* @0x2aff9c shadd16mi r4, r8, r9 */
/* @0x2affa0 stmvs r2!, {r9, r12, pc} */
/* @0x2affa4 stmdavs r2!, {r0, r9, r12, pc} ^ */
/* @0x2affa8 .word 0xf0026963 */
/* @0x2affac and pc, r7, r5, lsl #17 */
/* @0x2affb0 mvnle r3, r1, lsl #6 */
/* @0x2affb4 stmdavs r1!, {r3, r4, r5, r9, r10, lr} ^ */
/* @0x2affb8 movwhs r6, #0x8a2 */
/* @0x2affbc .word 0xffeaf001 */
/* @0x2affc0 .word 0xf8436bb3 */
/* @0x2affc4 ldrb r9, [r12, r5] */
/* @0x2affc8 .word 0x30c0f8d6 */
/* @0x2affcc .word 0xf8d6b34b */
/* @0x2affd0 ldrhs r4, [r4, #-0xbc] */
/* @0x2affd4 .word 0x20c0f8d6 */
/* @0x2affd8 ldrsbtlo pc, [r12], r6 */
/* @0x2affdc movwlo pc, #0x2b05 */
/* @0x2affe0 andsle r4, lr, #156, #4 */
/* @0x2affe4 qasxmi r4, r1, r8 */
/* @0x2affe8 .word 0xfffcf7f5 */
/* @0x2affec andsle r2, r6, r1, lsl #16 */
/* @0x2afff0 .word 0xb1a37c23 */
/* @0x2afff4 andeq pc, r6, #3 */
/* @0x2afff8 tstle r0, r2, lsl #20 */
/* @0x2afffc strle r0, [lr], #-1817 */
/* @0x2b0000 ldreq r7, [r10], r3, ror #17 */
/* @0x2b0004 stmdahs r3, {r0, r2, r10, r12, lr, pc} */
/* @0x2b0008 .word 0xf8d7d003 */
/* @0x2b000c bicseq r3, r11, #48, #2 */
/* @0x2b0010 ldrtmi sp, [r8], -r5, lsl #10 */
/* @0x2b0014 stmvs r2!, {r0, r5, r9, r10, lr} */
/* @0x2b0018 .word 0xf00168e3 */
/* @0x2b001c ldrlo pc, [r4], #-2383 */
/* @0x2b0020 ldrdlt lr, pc, [r5], -r8 */
/* @0x2b0024 svchi #0xf0e8bd */
/* @0x2b0028 strheq lr, [sp], -r8 */
/* @0x2b002c svcmi #0xf7e92d */
/* @0x2b0030 strmi r4, [r4], -sp, lsl #12 */
/* @0x2b0034 .word 0xf0002800 */
/* @0x2b0038 .word 0xf8d08081 */
/* @0x2b003c ldrbeq r3, [pc, -r12, lsr #2] */
/* @0x2b0040 stmdbmi r0, {r0, r1, r10, r12, lr, pc} ^ */
/* @0x2b0044 .word 0xf7f64479 */
/* @0x2b0048 ldmdblt sp, {r0, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc} ^ */
/* @0x2b004c .word 0x312cf8d4 */
/* @0x2b0050 .word 0xf0434620 */
/* @0x2b0054 .word 0xf8c40308 */
/* @0x2b0058 andlt r3, r3, r12, lsr #2 */
/* @0x2b005c svcmi #0xf0e8bd */
/* @0x2b0060 bllt 0xfe7ec06c <b2_toiTime+0xfffffffffe092bc8> */
/* @0x2b0064 ldreq r6, [lr, #0x8ab] */
/* @0x2b0068 .word 0xf8d4d508 */
/* @0x2b006c ldreq r3, [r8, #0x12c] */
/* @0x2b0070 strtmi sp, [r0], -r4, lsl #8 */
/* @0x2b0074 teqeq r12, r5, lsl #2 */
/* @0x2b0078 blx 0x56c088 <g_SWFlineaavertbuff+0x18fc0> */
/* @0x2b007c stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2b0080 beq 0x9ec1c4 <b2_toiTime+0x292d20> */
/* @0x2b0084 stmdbeq r2, {r0, r1, r2, r3, r5, r6, r12, sp, lr, pc} */
/* @0x2b0088 bleq 0x32c24c */
/* @0x2b008c ldrmi r6, [r8, #0xb2b] */
/* @0x2b0090 blx 0x566942 <g_SWFlineaavertbuff+0x1387a> */
/* @0x2b0094 blvs 0xfedadcbc <b2_toiTime+0xfffffffffe654818> */
/* @0x2b0098 ldmibpl r11, {r1, r2, r3, r4, r6, r7, r8, r11, r12} ^ */
/* @0x2b009c vstrle d2, [r10, #-0] */
/* @0x2b00a0 .word 0x461969b2 */
/* @0x2b00a4 andls r4, r0, #32, #12 */
/* @0x2b00a8 andls r6, r1, #11665408 */
/* @0x2b00ac ldmdbvs r3!, {r1, r4, r5, r6, r11, sp, lr} ^ */
/* @0x2b00b0 .word 0xf802f002 */
/* @0x2b00b4 .word 0xd109e012 */
/* @0x2b00b8 strtmi r9, [r0], -r0, lsl #6 */
/* @0x2b00bc ldmvs r2!, {r0, r4, r5, r6, r11, sp, lr} */
/* @0x2b00c0 .word 0xffa0f001 */
/* @0x2b00c4 .word 0xf8436bab */
/* @0x2b00c8 and r11, r10, r7 */
/* @0x2b00cc .word 0xd1083301 */
/* @0x2b00d0 ldmdavs r1!, {r5, r9, r10, lr} ^ */
/* @0x2b00d4 movwhs r6, #0x8b2 */
/* @0x2b00d8 .word 0xff5cf001 */
/* @0x2b00dc .word 0xf8436bab */
/* @0x2b00e0 .word 0xf1089007 */
/* @0x2b00e4 ldrb r0, [r1, r1, lsl #16] */
/* @0x2b00e8 .word 0x30c0f8d5 */
/* @0x2b00ec adcle r2, sp, r0, lsl #22 */
/* @0x2b00f0 ldrsbtvs pc, [r12], r5 */
/* @0x2b00f4 .word 0xf8d52714 */
/* @0x2b00f8 .word 0xf8d520c0 */
/* @0x2b00fc blx 0x47c3f6 <targetStr+0x11b6> */
/* @0x2b0100 addsmi r3, lr, #134217728 */
/* @0x2b0104 strtmi sp, [r0], -r2, lsr #5 */
/* @0x2b0108 .word 0xf7f54631 */
/* @0x2b010c stmdahs r1, {r0, r1, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b0110 ldcvc p0, c13, [r3], #-72 */
/* @0x2b0114 ldreq r11, [r9, -r3, lsl #3] */
/* @0x2b0118 ldmvc r3!, {r1, r2, r3, r8, r10, r12, lr, pc} ^ */
/* @0x2b011c strle r0, [r5], #-1690 */
/* @0x2b0120 andle r2, r3, r3, lsl #16 */
/* @0x2b0124 ldrsblo pc, [r0, -r4]! */
/* @0x2b0128 strle r0, [r5, #-0x3db] */
/* @0x2b012c ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2b0130 ldmvs r3!, {r1, r4, r5, r7, r11, sp, lr} ^ */
/* @0x2b0134 .word 0xf8c2f001 */
/* @0x2b0138 bfi r3, r4, #12, #17 */
/* @0x2b013c pop {r0, r1, r12, sp, pc} */
/* @0x2b0140 svclt #0x8ff0 */
/* @0x2b0144 andeq sp, sp, r9, ror #29 */
/* @0x2b0148 .word 0xf203694b */
/* @0x2b014c andhi r7, r3, r12, ror #6 */
/* @0x2b0150 movwlo r6, #0x190b */
/* @0x2b0154 stmvs r11, {r0, r1, r7, r12, sp, lr} ^ */
/* @0x2b0158 stmvs r11, {r0, r1, r6, r7, r12, sp, lr} */
/* @0x2b015c stmdavs r11, {r0, r1, r8, r12, sp, lr} ^ */
/* @0x2b0160 stmdavs r11, {r0, r1, r6, r8, r12, sp, lr} */
/* @0x2b0164 ldrbmi r7, [r0, -r3, lsl #3]! */
/* @0x2b0168 .word 0x4604b513 */
/* @0x2b016c .word 0xf840a802 */
/* @0x2b0170 .word 0xf6061d04 */
/* @0x2b0174 strmi lr, [r1], -r12, ror #29 */
/* @0x2b0178 .word 0xf7ff4620 */
/* @0x2b017c andlt pc, r2, r5, ror #31 */
/* @0x2b0180 andeq r11, r0, r0, lsl sp */
/* @0x2b0184 .word 0xb0a1b5f0 */
/* @0x2b0188 stmdals r6!, {r12, pc} */
/* @0x2b018c blls 0xcd4db0 <b2_toiTime+0x57b90c> */
/* @0x2b0190 stmdami sp!, {r1, r12, pc} ^ */
/* @0x2b0194 movwls r9, #0x4206 */
/* @0x2b0198 bls 0xc81380 <b2_toiTime+0x527edc> */
/* @0x2b019c andls r4, r1, r11, ror #22 */
/* @0x2b01a0 ldrmi r9, [r1], -r5, lsl #2 */
/* @0x2b01a4 stmpl r3, {r0, r1, r9, r12, pc} ^ */
/* @0x2b01a8 bls 0x3381b4 */
/* @0x2b01ac tstls pc, #1769472 */
/* @0x2b01b0 movwls r2, #0x9300 */
/* @0x2b01b4 stc2 p7, c15, [r5, #-984]! */
/* @0x2b01b8 stmdals r10, {r1, r3, r12, pc} */
/* @0x2b01bc .word 0xf0002800 */
/* @0x2b01c0 bls 0x5504a0 <gp_ActiveMaskObjects+0xb7d8> */
/* @0x2b01c4 .word 0xf8c24b5f */
/* @0x2b01c8 bls 0x53cdf0 <obj_has_event+0x2280> */
/* @0x2b01cc .word 0xf8c2980a */
/* @0x2b01d0 bls 0x2fce08 <TT_RunIns+0x14> */
/* @0x2b01d4 ldmpl r1, {r1, r2, r3, r4, r6, r8, r9, r11, lr} ^ */
/* @0x2b01d8 addvc pc, r0, #1325400064 */
/* @0x2b01dc .word 0xf9aef7f6 */
/* @0x2b01e0 bl 0xfe6eda00 <b2_toiTime+0xfffffffffdf9455c> */
/* @0x2b01e4 .word 0xb1084604 */
/* @0x2b01e8 stcl p6, c15, [lr, #-24] */
/* @0x2b01ec stmdals r10, {r1, r8, r11, sp, pc} */
/* @0x2b01f0 .word 0xf7f6c90e */
/* @0x2b01f4 stmdbge r5, {r0, r1, r2, r3, r4, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2b01f8 stmdbgt lr, {r1, r3, r11, r12, pc} */
/* @0x2b01fc .word 0xf9a7f7f6 */
/* @0x2b0200 stmdblt r11!, {r8, r9, r11, r12, pc} */
/* @0x2b0204 .word 0xf8d39b0a */
/* @0x2b0208 orrseq r3, r11, #48, #2 */
/* @0x2b020c rsb sp, r0, r0, lsr #8 */
/* @0x2b0210 .word 0xf04f4d50 */
/* @0x2b0214 .word 0x260133ff */
/* @0x2b0218 stmdals r0, {r0, r2, r3, r4, r5, r6, r10, lr} */
/* @0x2b021c ldclpl p3, c3, [r10, #-4] */
/* @0x2b0220 stclpl p6, c4, [r1], {31} */
/* @0x2b0224 mulle r6, r1, r2 */
/* @0x2b0228 .word 0xf8d1990a */
/* @0x2b022c vst4.8 {d16, d18, d20, d22}, [r0:256], r0 */
/* @0x2b0230 .word 0xf8c13000 */
/* @0x2b0234 stmdals r0, {r4, r5, r8} */
/* @0x2b0238 stmdbhs lr!, {r0, r6, r7, r8, r10, r11, r12, lr} */
/* @0x2b023c .word 0x2c00d103 */
/* @0x2b0240 ldrtmi sp, [r4], -r0, ror #3 */
/* @0x2b0244 stmdbhs r0, {r0, sp, lr, pc} */
/* @0x2b0248 bhs 0x2e45c0 <_ZN11b2GearJointC2EPK14b2GearJointDef+0x38> */
/* @0x2b024c ldrb sp, [r9, r5, ror #3] */
/* @0x2b0250 movtlt r9, #0x2a00 */
/* @0x2b0254 ldmdavc r4, {sp} */
/* @0x2b0258 mrc2 p7, #0x5, apsr_nzcv, c8, c5, #0x7 */
/* @0x2b025c adcmi r7, r3, #196608 */
/* @0x2b0260 stmdals r0, {r0, r2, r4, r8, r12, lr, pc} */
/* @0x2b0264 blhs 0xf0e278 <b2_toiTime+0x7b4dd4> */
/* @0x2b0268 bls 0x2e4280 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x21c> */
/* @0x2b026c blhs 0xece2c0 <b2_toiTime+0x774e1c> */
/* @0x2b0270 and sp, r8, pc, lsr #2 */
/* @0x2b0274 andhs r9, r0, r0, lsl #22 */
/* @0x2b0278 .word 0xf7f5789c */
/* @0x2b027c stmvc r3, {r0, r1, r2, r5, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2b0280 smlatble r4, r3, r2, r4 */
/* @0x2b0284 stmdals r0, {r0, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2b0288 blhs 0x10ce49c <b2_toiTime+0x974ff8> */
/* @0x2b028c .word 0xac0bd821 */
/* @0x2b0290 cmphs r0, r1, lsr r10 */
/* @0x2b0294 strtmi r9, [r0], -r0, lsl #22 */
/* @0x2b0298 .word 0xf606447a */
/* @0x2b029c stmdals r10, {r1, r2, r4, r7, r8, r11, sp, lr, pc} */
/* @0x2b02a0 .word 0xf7f64621 */
/* @0x2b02a4 andhs pc, r0, r7, ror #17 */
/* @0x2b02a8 .word 0xf7f5ac0b */
/* @0x2b02ac bmi 0xdafcf0 <b2_toiTime+0x65684c> */
/* @0x2b02b0 ldrbtmi r2, [r10], #-336 */
/* @0x2b02b4 strtmi r4, [r0], -r3, lsl #12 */
/* @0x2b02b8 stmib r6, {r1, r2, r9, r10, r12, sp, lr, pc} */
/* @0x2b02bc strtmi r9, [r1], -r10, lsl #16 */
/* @0x2b02c0 .word 0xf8d8f7f6 */
/* @0x2b02c4 stmdals r10, {r1, r2, r5, r8, r11, lr} */
/* @0x2b02c8 .word 0xf7f64479 */
/* @0x2b02cc movwhs pc, #0x18d3 */
/* @0x2b02d0 blls 0x554efc <g_SWFlineaavertbuff+0x1e34> */
/* @0x2b02d4 andpl pc, r0, #1325400064 */
/* @0x2b02d8 cmnhs r4, r3, asr #17 */
/* @0x2b02dc ldmdblt r3!, {r0, r3, r8, r9, r11, r12, pc} ^ */
/* @0x2b02e0 stmdals r10, {r1, r3, r10, r11, r12, pc} */
/* @0x2b02e4 .word 0xf8d39b0a */
/* @0x2b02e8 .word 0xf7f61174 */
/* @0x2b02ec blls 0x56f744 <g_SWFlineaavertbuff+0x1c67c> */
/* @0x2b02f0 cmneq r0, r4, asr #17 */
/* @0x2b02f4 ldrsblo pc, [r0, #-131]! */
/* @0x2b02f8 movwhs r11, #0x190b */
/* @0x2b02fc stmdbls r9, {r0, r3, r8, r9, r12, pc} */
/* @0x2b0300 cmnlt r9, r10, lsl #16 */
/* @0x2b0304 strhs r9, [r0], #-2826 */
/* @0x2b0308 ldrsbne pc, [r0, #-131]! */
/* @0x2b030c ldc2l p7, c15, [r6], #984 */
/* @0x2b0310 stmdbls r4, {r1, r3, r8, r9, r11, r12, pc} */
/* @0x2b0314 .word 0xf8c3980a */
/* @0x2b0318 bls 0x3408e0 */
/* @0x2b031c ldc2 p7, c15, [pc], {246} */
/* @0x2b0320 and r4, r4, r0, lsr #12 */
/* @0x2b0324 strmi r4, [r11], -r10, lsl #12 */
/* @0x2b0328 ldc2l p7, c15, [r6], #-1020 */
/* @0x2b032c bls 0x31635c <FT_Bitmap_Embolden+0x1516> */
/* @0x2b0330 ldmpl r3, {r1, r2, r8, r9, r11, lr} ^ */
/* @0x2b0334 ldmdavs r11, {r0, r1, r2, r3, r4, r9, r11, r12, pc} */
/* @0x2b0338 mulle r1, r10, r2 */
/* @0x2b033c stmdb r10, {r1, r2, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2b0340 ldcllt p0, c11, [r0, #132]! */
/* @0x2b0344 andeq r4, pc, r0, asr #4 */
/* @0x2b0348 ldrheq r1, [r4], -r12 */
/* @0x2b034c .word 0xffffbd00 */
/* @0x2b0350 .word 0xffffe4ac */
/* @0x2b0354 andeq r12, sp, r8, asr r1 */
/* @0x2b0358 andeq r12, sp, r8, lsl #10 */
/* @0x2b035c andeq r12, sp, r9, asr #8 */
/* @0x2b0360 andeq r12, sp, r9, ror #8 */
/* @0x2b0364 strhs r11, [r0], #-1311 */
/* @0x2b0368 strls r9, [r1], #-1024 */
/* @0x2b036c .word 0xf7ff9402 */
/* @0x2b0370 andlt pc, r4, r9, lsl #30 */
/* @0x2b0374 andeq r11, r0, r0, lsl sp */
/* @0x2b0378 .word 0x460db538 */
/* @0x2b037c stmdahs r0, {r2, r9, r10, lr} */
/* @0x2b0380 adcshi pc, r2, r0 */
/* @0x2b0384 .word 0x31a8f8d0 */
/* @0x2b0388 .word 0xf890b96b */
/* @0x2b038c ldmdblt r3, {r3, r5, r6, r7, r8, r12, sp} ^ */
/* @0x2b0390 .word 0x312cf8d0 */
/* @0x2b0394 strle r0, [r3], #-1370 */
/* @0x2b0398 ldrbtmi r4, [r9], #-2388 */
/* @0x2b039c .word 0xf846f7f6 */
/* @0x2b03a0 .word 0xf0024620 */
/* @0x2b03a4 .word 0xf894f8b5 */
/* @0x2b03a8 blhs 0x2bcb4c <jpeg_alloc_huff_table+0x244> */
/* @0x2b03ac .word 0xf8d4d040 */
/* @0x2b03b0 .word 0x079b3134 */
/* @0x2b03b4 .word 0xf894d53c */
/* @0x2b03b8 blhs 0x43cb60 <g_RomDisk+0x45340> */
/* @0x2b03bc ldm pc, {r3, r4, r5, r11, r12, lr, pc} ^ */
/* @0x2b03c0 stceq p0, c15, [r4, #-12] */
/* @0x2b03c4 bhs 0xb77020 <b2_toiTime+0x41db7c> */
/* @0x2b03c8 .word 0xf8d40033 */
/* @0x2b03cc ldrbeq r3, [r8, -r8, lsr #3] */
/* @0x2b03d0 strtmi sp, [r0], -lr, lsr #32 */
/* @0x2b03d4 ldrhtmi lr, [r8], -sp */
/* @0x2b03d8 ldmdblt r8, {r1, r12, sp, lr, pc} */
/* @0x2b03dc .word 0x31a8f8d4 */
/* @0x2b03e0 mvnsle r0, r9, asr r7 */
/* @0x2b03e4 .word 0x318cf8d4 */
/* @0x2b03e8 ands r2, r11, r4, lsl #22 */
/* @0x2b03ec .word 0x31a8f8d4 */
/* @0x2b03f0 movweq pc, #0x7003 */
/* @0x2b03f4 and r2, r12, r4, lsl #22 */
/* @0x2b03f8 .word 0x31a8f8d4 */
/* @0x2b03fc .word 0xd1e8079a */
/* @0x2b0400 .word 0x318cf8d4 */
/* @0x2b0404 and r2, sp, r2, lsl #22 */
/* @0x2b0408 .word 0x31a8f8d4 */
/* @0x2b040c movweq pc, #0x3003 */
/* @0x2b0410 andle r2, sp, r2, lsl #22 */
/* @0x2b0414 .word 0xf8d4e7dd */
/* @0x2b0418 ldrbeq r3, [r11, r8, lsr #3] */
/* @0x2b041c .word 0xf8d4d4d9 */
/* @0x2b0420 blhs 0x2fca58 <ps_hints_apply+0xb658> */
/* @0x2b0424 ldrb sp, [r4, r4, lsl #16] */
/* @0x2b0428 .word 0x31a8f8d4 */
/* @0x2b042c ldrble r0, [r0, #0x7d8] */
/* @0x2b0430 .word 0x31eaf894 */
/* @0x2b0434 .word 0x01eff894 */
/* @0x2b0438 ldrsbhs pc, [r8, r4] */
/* @0x2b043c biclo pc, r12, r4, lsl #17 */
/* @0x2b0440 .word 0x31ecf894 */
/* @0x2b0444 bichs pc, r4, r4, asr #17 */
/* @0x2b0448 biceq pc, lr, r4, lsl #17 */
/* @0x2b044c biclo pc, sp, r4, lsl #17 */
/* @0x2b0450 sbcslt r4, r11, #201326593 */
/* @0x2b0454 biclo pc, pc, r4, lsl #17 */
/* @0x2b0458 stmdble r2, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x2b045c cmpmi r10, #14352384 */
/* @0x2b0460 cmpmi r10, #2 */
/* @0x2b0464 ldmeq r2, {r0, r1, r2, r9, r12, sp} ^ */
/* @0x2b0468 ldrsbeq pc, [r0, r4]! */
/* @0x2b046c .word 0xf8c44629 */
/* @0x2b0470 .word 0xf50421c8 */
/* @0x2b0474 andlo r7, r1, r2, ror #11 */
/* @0x2b0478 stm r0!, {r1, r2, r9, r10, r12, sp, lr, pc} */
/* @0x2b047c .word 0x31e7f894 */
/* @0x2b0480 .word 0xf894b18b */
/* @0x2b0484 bhs 0x3f8c2c <g_RomDisk+0x140c> */
/* @0x2b0488 .word 0xf8d4d80d */
/* @0x2b048c .word 0x07993134 */
/* @0x2b0490 .word 0xf8d4d509 */
/* @0x2b0494 .word 0x462811b0 */
/* @0x2b0498 .word 0xf0023101 */
/* @0x2b049c .word 0xf8d4f97f */
/* @0x2b04a0 blhs 0x2bcbb8 <jpeg_alloc_huff_table+0x2b0> */
/* @0x2b04a4 .word 0xf8d4d095 */
/* @0x2b04a8 tstlt r3, r4, lsr r1 */
/* @0x2b04ac .word 0xf0004620 */
/* @0x2b04b0 .word 0xf8d4fc85 */
/* @0x2b04b4 smmlseq r11, r12, r2, r3 */
/* @0x2b04b8 .word 0xf894d509 */
/* @0x2b04bc blhs 0x12bd054 <b2_toiTime+0xb63bb0> */
/* @0x2b04c0 .word 0xf8d4d105 */
/* @0x2b04c4 .word 0x462811b0 */
/* @0x2b04c8 .word 0xf0003101 */
/* @0x2b04cc qsub8mi pc, r0, r4 */
/* @0x2b04d0 .word 0xf0024629 */
/* @0x2b04d4 .word 0xf8d4fa81 */
/* @0x2b04d8 .word 0xb12b3260 */
/* @0x2b04dc .word 0xf8d44620 */
/* @0x2b04e0 .word 0xf89411a8 */
/* @0x2b04e4 ldrmi r2, [r8, r8, ror #3] */
/* @0x2b04e8 svclt #0xbd38 */
/* @0x2b04ec andeq sp, sp, lr, lsr #23 */
/* @0x2b04f0 .word 0x460eb5f8 */
/* @0x2b04f4 .word 0x46054617 */
/* @0x2b04f8 strhs r11, [r0], #-328 */
/* @0x2b04fc strhle r4, [r6], -r12 */
/* @0x2b0500 eorne pc, r4, r6, asr r8 */
/* @0x2b0504 .word 0xf7ff4628 */
/* @0x2b0508 strlo pc, [r1], #-3895 */
/* @0x2b050c ldcllt p7, c14, [r8, #984]! */
/* @0x2b0510 mvnsmi lr, sp, lsr #18 */
/* @0x2b0514 strmi r4, [r6], -pc, lsl #12 */
/* @0x2b0518 .word 0xf7ffb198 */
/* @0x2b051c strhs pc, [r0, #-0x94a] */
/* @0x2b0520 strbmi r4, [r5, #-0x680] */
/* @0x2b0524 strhs sp, [r0], #-2573 */
/* @0x2b0528 ldrsblo pc, [r0, r6] */
/* @0x2b052c andle r4, r6, #156, #4 */
/* @0x2b0530 eorne pc, r4, r7, asr r8 */
/* @0x2b0534 .word 0xf7ff4630 */
/* @0x2b0538 strlo pc, [r1], #-3871 */
/* @0x2b053c strlo lr, [r1, #-0x7f4] */
/* @0x2b0540 pop {r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2b0544 ldrshlt r8, [r8, -r0] */
