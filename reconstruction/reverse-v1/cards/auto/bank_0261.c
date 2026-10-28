/* libyoyo.so 覆盖卡组 0261
 * 函数 0x2afbb9..0x2b0911，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2afbb9 · png_default_write_data · size=44 · insn=0 */

/* ── FUNC 0x2afbe5 · png_default_flush · size=12 · insn=0 */

/* ── FUNC 0x2afbf1 · png_write_data · size=28 · insn=0 */

/* ── FUNC 0x2afc0d · png_flush · size=12 · insn=0 */

/* ── FUNC 0x2afc19 · png_set_write_fn · size=88 · insn=0 */

/* ── FUNC 0x2afc71 · png_write_info_before_PLTE · size=420 · insn=0 */

/* ── FUNC 0x2afe15 · png_write_info · size=536 · insn=0 */

/* ── FUNC 0x2b002d · png_write_end · size=284 · insn=0 */

/* ── FUNC 0x2b0149 · png_convert_from_struct_tm · size=32 · insn=0 */

/* ── FUNC 0x2b0169 · png_convert_from_time_t · size=26 · insn=0 */

/* ── FUNC 0x2b0185 · png_create_write_struct_2 · size=480 · insn=0 */

/* ── FUNC 0x2b0365 · png_create_write_struct · size=18 · insn=0 */

/* ── FUNC 0x2b0379 · png_write_row · size=376 · insn=0 */

/* ── FUNC 0x2b04f1 · png_write_rows · size=32 · insn=0 */

/* ── FUNC 0x2b0511 · png_write_image · size=54 · insn=0 */

/* ── FUNC 0x2b0546 · anon_2b0546 · size=16 · insn=4 */
/* @0x2b0546 b 0xb1c9ae <b2_toiTime+0x3c350a> */
/* @0x2b054a .word 0xf8c071e1 */
/* @0x2b054e .word 0x47701214 */
/* @0x2b0552 ldrblt r0, [r0, #-0x0]! */

/* ── FUNC 0x2b0547 · png_set_flush · size=12 · insn=0 */

/* ── FUNC 0x2b0554 · anon_2b0554 · size=320 · insn=80 */
/* @0x2b0554 .word 0x4604b570 */
/* @0x2b0558 suble r2, r2, r0, lsl #16 */
/* @0x2b055c .word 0x21a8f8d0 */
/* @0x2b0560 ldrsblo pc, [r4, r0] */
/* @0x2b0564 eorsle r4, r12, #-1610612727 */
/* @0x2b0568 .word 0xf5004e1e */
/* @0x2b056c ldrbtmi r7, [lr], #-1436 */
/* @0x2b0570 .word 0x21024628 */
/* @0x2b0574 b 0x96dd94 <b2_toiTime+0x2148f0> */
/* @0x2b0578 .word 0xf8d4b130 */
/* @0x2b057c qsaxmi r1, r0, r0 */
/* @0x2b0580 ldrtmi r11, [r1], -r1, lsl #18 */
/* @0x2b0584 .word 0xff52f7f5 */
/* @0x2b0588 .word 0x3148f8d4 */
/* @0x2b058c qsub16mi r11, r0, r11 */
/* @0x2b0590 ldrsbne pc, [r0, #-132]! */
/* @0x2b0594 ldrsbhs pc, [r4, #-132]! */
/* @0x2b0598 .word 0xf882f001 */
/* @0x2b059c ldrsblo pc, [r0, #-132]! */
/* @0x2b05a0 smlalbtlo pc, r4, r4, r8 */
/* @0x2b05a4 ldrsblo pc, [r4, #-132]! */
/* @0x2b05a8 smlalbtlo pc, r8, r4, r8 */
/* @0x2b05ac .word 0xf8d4e7e0 */
/* @0x2b05b0 addsmi r2, r10, #116, #2 */
/* @0x2b05b4 bne 0xff7645f0 <b2_toiTime+0xffffffffff00b14c> */
/* @0x2b05b8 .word 0xf8d44620 */
/* @0x2b05bc .word 0xf0011170 */
/* @0x2b05c0 .word 0xf8d4f86f */
/* @0x2b05c4 .word 0xf8c43170 */
/* @0x2b05c8 .word 0xf8d43144 */
/* @0x2b05cc .word 0xf8c43174 */
/* @0x2b05d0 movwhs r3, #0x148 */
/* @0x2b05d4 .word 0xf8c44620 */
/* @0x2b05d8 pop {r3, r4, r9, r12, sp} */
/* @0x2b05dc .word 0xf7ff4070 */
/* @0x2b05e0 .word 0xbd70bb15 */
/* @0x2b05e4 andeq sp, sp, pc, lsl #20 */
/* @0x2b05e8 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x2b05ec sbclt r4, r0, r4, lsl #12 */
/* @0x2b05f0 addsvc pc, r12, r0, lsl #10 */
/* @0x2b05f4 stmib r0!, {r1, r2, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2b05f8 .word 0xf8d44620 */
/* @0x2b05fc vst4.16 {d17, d19, d21, d23}, [pc:256], r0 */
/* @0x2b0600 .word 0xf7f67580 */
/* @0x2b0604 qsub16mi pc, r0, r11 */
/* @0x2b0608 ldrsbne pc, [r0, r4]! */
/* @0x2b060c blx 0x206e5ee <b2_toiTime+0x191514a> */
/* @0x2b0610 .word 0xf8d44620 */
/* @0x2b0614 .word 0xf7f611ac */
/* @0x2b0618 qsub16mi pc, r0, r1 */
/* @0x2b061c ldrsbne pc, [r4, r4]! */
/* @0x2b0620 blx 0x1dee602 <b2_toiTime+0x169515e> */
/* @0x2b0624 .word 0xf8d44620 */
/* @0x2b0628 .word 0xf7f611b8 */
/* @0x2b062c strtmi pc, [r0], -r7, ror #22 */
/* @0x2b0630 ldrsbne pc, [r12, r4]! */
/* @0x2b0634 blx 0x1b6e616 <b2_toiTime+0x1415172> */
/* @0x2b0638 .word 0xf8d44620 */
/* @0x2b063c .word 0xf7f611c0 */
/* @0x2b0640 qsaxmi pc, r0, sp */
/* @0x2b0644 adcsne pc, r12, #212, #16 */
/* @0x2b0648 blx 0x18ee62a <b2_toiTime+0x1195186> */
/* @0x2b064c strtmi r4, [r10], -r1, lsr #12 */
/* @0x2b0650 .word 0xf6054668 */
/* @0x2b0654 .word 0xf8d4efb4 */
/* @0x2b0658 .word 0xf8d4a104 */
/* @0x2b065c strtmi r9, [r0], -r8, lsl #2 */
/* @0x2b0660 .word 0x810cf8d4 */
/* @0x2b0664 .word 0xf8d42100 */
/* @0x2b0668 vst1.64 {d23, d24, d25, d26}, [pc:256], r0 */
/* @0x2b066c .word 0xf605724e */
/* @0x2b0670 .word 0xf8c4efa0 */
/* @0x2b0674 .word 0xf8c4a104 */
/* @0x2b0678 strtmi r9, [r0], -r8, lsl #2 */
/* @0x2b067c smlabthi r12, r4, r8, pc */
/* @0x2b0680 .word 0xf8c44669 */
/* @0x2b0684 qsub8mi r7, r10, r0 */
/* @0x2b0688 svc #0x98f605 */
/* @0x2b068c pop {r6, r12, sp, pc} */
/* @0x2b0690 push {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2b0555 · png_write_flush · size=148 · insn=0 */

/* ── FUNC 0x2b05e9 · png_write_destroy · size=170 · insn=0 */

/* ── FUNC 0x2b0692 · anon_2b0692 · size=128 · insn=32 */
/* @0x2b0692 .word 0x43f8e92d */
/* @0x2b0696 strmi r4, [r5], -r8, lsl #13 */
/* @0x2b069a stmdavs r4, {r3, r5, r8, r12, sp, pc} */
/* @0x2b069e rscsvc pc, r0, #212, #16 */
/* @0x2b06a2 rscvs pc, r8, #212, #16 */
/* @0x2b06a6 strmi lr, [r4], -r2 */
/* @0x2b06aa strmi r4, [r7], -r6, lsl #12 */
/* @0x2b06ae svceq #0xf1b8 */
/* @0x2b06b2 .word 0xf8d8d020 */
/* @0x2b06b6 .word 0xf1b99000 */
/* @0x2b06ba andsle r0, r11, r0, lsl #30 */
/* @0x2b06be .word 0xf04fb194 */
/* @0x2b06c2 qsub8mi r3, r0, pc */
/* @0x2b06c6 .word 0xf6474649 */
/* @0x2b06ca .word 0xf7f572ff */
/* @0x2b06ce .word 0xf8d4fa78 */
/* @0x2b06d2 teqlt r11, r12, asr #5 */
/* @0x2b06d6 .word 0xf8d44620 */
/* @0x2b06da .word 0xf7f612d0 */
/* @0x2b06de movwhs pc, #0xb0e */
/* @0x2b06e2 sbclo pc, r12, #196, #16 */
/* @0x2b06e6 ldrtmi r4, [r9], -r8, asr #12 */
/* @0x2b06ea .word 0xf7f64632 */
/* @0x2b06ee movwhs pc, #0xab7 */
/* @0x2b06f2 andlo pc, r0, r8, asr #17 */
/* @0x2b06f6 strtmi r11, [r0], -r12, asr #2 */
/* @0x2b06fa .word 0xff75f7ff */
/* @0x2b06fe ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2b0702 .word 0xf7f64632 */
/* @0x2b0706 movwhs pc, #0xaab */
/* @0x2b070a pop {r0, r1, r3, r5, sp, lr} */
/* @0x2b070e ldrlt r8, [r0, #-0x3f8] */

/* ── FUNC 0x2b0693 · png_destroy_write_struct · size=126 · insn=0 */

/* ── FUNC 0x2b0710 · anon_2b0710 · size=376 · insn=94 */
/* @0x2b0710 .word 0x4604b510 */
/* @0x2b0714 .word 0xf0002800 */
/* @0x2b0718 .word 0xf8d080a9 */
/* @0x2b071c smmlseq r8, r12, r2, r3 */
/* @0x2b0720 stmdbhs r0, {r0, r8, r10, r12, lr, pc} ^ */
/* @0x2b0724 stmdbhs r0, {r1, r12, lr, pc} */
/* @0x2b0728 addshi pc, r9, r0, asr #32 */
/* @0x2b072c blhs 0x49d280 <TimingData+0x3268> */
/* @0x2b0730 ldm pc, {r0, r1, r2, r4, r11, r12, lr, pc} ^ */
/* @0x2b0734 .word 0x0c04f003 */
/* @0x2b0738 sadd16eq r1, r4, r0 */
/* @0x2b073c movwhs r0, #0x8606 */
/* @0x2b0740 stmdbmi r11, {r1, r2, sp, lr, pc} ^ */
/* @0x2b0744 ldrbtmi r4, [r9], #-1568 */
/* @0x2b0748 mrc2 p7, #0x4, apsr_nzcv, c4, c5, #0x7 */
/* @0x2b074c tsths r0, #11 */
/* @0x2b0750 mvnlo pc, r4, lsl #17 */
/* @0x2b0754 .word 0x2320e007 */
/* @0x2b0758 movths lr, #0x7fa */
/* @0x2b075c orrhs lr, r0, #248, #14 */
/* @0x2b0760 .word 0xf884e7f6 */
/* @0x2b0764 .word 0xf8d421e9 */
/* @0x2b0768 blhs 0x2bce30 <jpeg_alloc_huff_table+0x528> */
/* @0x2b076c .word 0xf894d07e */
/* @0x2b0770 ldrbeq r3, [r9], r9, ror #3 */
/* @0x2b0774 .word 0xf8d4d50c */
/* @0x2b0778 stmdblt r11, {r2, r4, r5, r7, r8, r12, sp} ^ */
/* @0x2b077c ldrsbne pc, [r12, r4] */
/* @0x2b0780 .word 0x31014620 */
/* @0x2b0784 blx 0xfe5ee764 <b2_toiTime+0xfffffffffde952c0> */
/* @0x2b0788 .word 0xf8c42301 */
/* @0x2b078c strhvc r0, [r3], -r4 */
/* @0x2b0790 .word 0x31e9f894 */
/* @0x2b0794 ldrle r0, [r11, #-0x69a] */
/* @0x2b0798 ldrsblo pc, [r8, r4]! */
/* @0x2b079c .word 0xf8d4b9c3 */
/* @0x2b07a0 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^ */
/* @0x2b07a4 qasxmi r4, r0, r3 */
/* @0x2b07a8 .word 0xf7f54479 */
/* @0x2b07ac .word 0xf894fe63 */
/* @0x2b07b0 .word 0xf02331e9 */
/* @0x2b07b4 .word 0xf8840320 */
/* @0x2b07b8 and r3, r9, r9, ror #3 */
/* @0x2b07bc ldrsbne pc, [r12, r4] */
/* @0x2b07c0 .word 0x31014620 */
/* @0x2b07c4 blx 0x1dee7a4 <b2_toiTime+0x1695300> */
/* @0x2b07c8 .word 0xf8c42302 */
/* @0x2b07cc strhvc r0, [r3], -r8 */
/* @0x2b07d0 .word 0x31e9f894 */
/* @0x2b07d4 ldrle r0, [r11, #-0x65b] */
/* @0x2b07d8 ldrsblo pc, [r12, r4]! */
/* @0x2b07dc .word 0xf8d4b9c3 */
/* @0x2b07e0 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^ */
/* @0x2b07e4 strtmi r4, [r0], -r4, lsr #18 */
/* @0x2b07e8 .word 0xf7f54479 */
/* @0x2b07ec .word 0xf894fe43 */
/* @0x2b07f0 .word 0xf02331e9 */
/* @0x2b07f4 .word 0xf8840340 */
/* @0x2b07f8 and r3, r9, r9, ror #3 */
/* @0x2b07fc ldrsbne pc, [r12, r4] */
/* @0x2b0800 .word 0x31014620 */
/* @0x2b0804 blx 0x15ee7e4 <b2_toiTime+0xe95340> */
/* @0x2b0808 .word 0xf8c42303 */
/* @0x2b080c strhvc r0, [r3], -r12 */
/* @0x2b0810 .word 0x31e9f994 */
/* @0x2b0814 ble 0x97b41c <b2_toiTime+0x221f78> */
/* @0x2b0818 .word 0x31c0f8d4 */
/* @0x2b081c .word 0xf8d4b9c3 */
/* @0x2b0820 ldmdblt r11, {r2, r3, r5, r7, r8, r12, sp} ^ */
/* @0x2b0824 qadd16mi r4, r0, r5 */
/* @0x2b0828 .word 0xf7f54479 */
/* @0x2b082c .word 0xf894fe23 */
/* @0x2b0830 .word 0xf00331e9 */
/* @0x2b0834 .word 0xf884037f */
/* @0x2b0838 and r3, r9, r9, ror #3 */
/* @0x2b083c ldrsbne pc, [r12, r4] */
/* @0x2b0840 .word 0x31014620 */
/* @0x2b0844 blx 0xdee824 <b2_toiTime+0x695380> */
/* @0x2b0848 .word 0xf8c42304 */
/* @0x2b084c andvc r0, r3, r0, asr #3 */
/* @0x2b0850 .word 0x31e9f894 */
/* @0x2b0854 movwhs r11, #0x8953 */
/* @0x2b0858 mvnlo pc, r4, lsl #17 */
/* @0x2b085c stmdbmi r8, {r4, r8, r10, r11, r12, sp, pc} */
/* @0x2b0860 pop {r5, r9, r10, lr} */
/* @0x2b0864 ldrbtmi r4, [r9], #-16 */
/* @0x2b0868 stcllt p7, c15, [r0, #980]! */
/* @0x2b086c svclt #0xbd10 */
/* @0x2b0870 andeq sp, sp, r2, asr #16 */
/* @0x2b0874 andeq sp, sp, r0, lsl #16 */
/* @0x2b0878 andeq sp, sp, r3, ror #15 */
/* @0x2b087c andeq sp, sp, r11, asr #15 */
/* @0x2b0880 strheq sp, [sp], -r3 */
/* @0x2b0884 teqlt r8, r0, ror r7 */

/* ── FUNC 0x2b0711 · png_set_filter · size=372 · insn=0 */

/* ── FUNC 0x2b0885 · png_set_filter_heuristics · size=2 · insn=0 */

/* ── FUNC 0x2b0886 · anon_2b0886 · size=64 · insn=16 */
/* @0x2b0886 .word 0xf8d0b138 */
/* @0x2b088a .word 0xf8c03130 */
/* @0x2b088e .word 0xf0431178 */
/* @0x2b0892 .word 0xf8c00302 */
/* @0x2b0896 .word 0x47703130 */
/* @0x2b089a .word 0xf8d0b138 */
/* @0x2b089e .word 0xf8c03130 */
/* @0x2b08a2 .word 0xf0431184 */
/* @0x2b08a6 .word 0xf8c00304 */
/* @0x2b08aa .word 0x47703130 */
/* @0x2b08ae .word 0xf8d0b138 */
/* @0x2b08b2 .word 0xf8c03130 */
/* @0x2b08b6 .word 0xf0431188 */
/* @0x2b08ba .word 0xf8c00301 */
/* @0x2b08be .word 0x47703130 */
/* @0x2b08c2 ldrlt r0, [r8, #-0x0]! */

/* ── FUNC 0x2b0887 · png_set_compression_level · size=20 · insn=0 */

/* ── FUNC 0x2b089b · png_set_compression_mem_level · size=20 · insn=0 */

/* ── FUNC 0x2b08af · png_set_compression_strategy · size=20 · insn=0 */

/* ── FUNC 0x2b08c4 · anon_2b08c4 · size=316 · insn=79 */
/* @0x2b08c4 .word 0x460cb538 */
/* @0x2b08c8 bicslt r4, r0, r5, lsl #12 */
/* @0x2b08cc stcle p9, c2, [r2, #-60] */
/* @0x2b08d0 ldrbtmi r4, [r9], #-2316 */
/* @0x2b08d4 stmdbhs r7, {r0, r1, sp, lr, pc} */
/* @0x2b08d8 stmdbmi r11, {r2, r10, r11, r12, lr, pc} */
/* @0x2b08dc .word 0xf7f54479 */
/* @0x2b08e0 and pc, r6, r9, asr #27 */
/* @0x2b08e4 .word 0xd1042908 */
/* @0x2b08e8 strhs r4, [r9], #-2312 */
/* @0x2b08ec .word 0xf7f54479 */
/* @0x2b08f0 .word 0xf8d5fdc1 */
/* @0x2b08f4 .word 0xf8c53130 */
/* @0x2b08f8 .word 0xf0434180 */
/* @0x2b08fc .word 0xf8c50308 */
/* @0x2b0900 ldclt p1, c3, [r8, #-192]! */
/* @0x2b0904 andeq sp, sp, r4, ror #14 */
/* @0x2b0908 andeq sp, sp, r11, lsl #15 */
/* @0x2b090c andeq sp, sp, r12, lsr #15 */
/* @0x2b0910 .word 0x460db538 */
/* @0x2b0914 .word 0xb1684604 */
/* @0x2b0918 andle r2, r3, r8, lsl #18 */
/* @0x2b091c ldrbtmi r4, [r9], #-2310 */
/* @0x2b0920 stc2 p7, c15, [r8, #980]! */
/* @0x2b0924 ldrsblo pc, [r0, -r4]! */
/* @0x2b0928 cmnpl r12, r4, asr #17 */
/* @0x2b092c tsteq r0, #67 */
/* @0x2b0930 teqlo r0, r4, asr #17 */
/* @0x2b0934 svclt #0xbd38 */
/* @0x2b0938 andeq sp, sp, r3, lsr #15 */
/* @0x2b093c .word 0xf8c0b108 */
/* @0x2b0940 ldrbmi r1, [r0, -r0, ror #4]! */
/* @0x2b0944 .word 0xf8d0b138 */
/* @0x2b0948 .word 0xf8c03134 */
/* @0x2b094c vst4.8 {d17, d19, d21, d23}, [r3:128], r0 */
/* @0x2b0950 .word 0xf8c01380 */
/* @0x2b0954 .word 0x47703134 */
/* @0x2b0958 .word 0x460eb570 */
/* @0x2b095c .word 0x46044615 */
/* @0x2b0960 suble r2, r11, r0, lsl #16 */
/* @0x2b0964 suble r2, r9, r0, lsl #18 */
/* @0x2b0968 blx 0x17ee96c <b2_toiTime+0x10954c8> */
/* @0x2b096c strle r0, [r2, #-0x6a9] */
/* @0x2b0970 .word 0xf7fe4620 */
/* @0x2b0974 strbteq pc, [r10], -r10, ror #30 */
/* @0x2b0978 ldmvs r3!, {r0, r1, r2, r8, r10, r12, lr, pc} */
/* @0x2b097c strle r0, [r4, #-0x79b] */
/* @0x2b0980 .word 0xf1064620 */
/* @0x2b0984 .word 0xf7fe0144 */
/* @0x2b0988 strbeq pc, [r8, -r6, lsl #30]! */
/* @0x2b098c strtmi sp, [r0], -r2, lsl #10 */
/* @0x2b0990 mcr2 p7, #0x7, pc, c6, c14, #0x7 */
/* @0x2b0994 strle r0, [r2, #-0x5e9] */
/* @0x2b0998 .word 0xf7fe4620 */
/* @0x2b099c .word 0xf415ff46 */
/* @0x2b09a0 andle r5, r3, r0, lsl #3 */
/* @0x2b09a4 .word 0x21004620 */
/* @0x2b09a8 and r2, r3, r1, lsl #4 */
/* @0x2b09ac strle r0, [r3, #-0x52a] */
/* @0x2b09b0 strmi r4, [r10], -r0, lsr #12 */
/* @0x2b09b4 .word 0xff0bf7fe */
/* @0x2b09b8 strle r0, [r2, #-0x62b] */
/* @0x2b09bc .word 0xf7fe4620 */
/* @0x2b09c0 streq pc, [r8, #0xebb]! */
/* @0x2b09c4 strtmi sp, [r0], -r2, lsl #10 */
/* @0x2b09c8 mrc2 p7, #0x5, apsr_nzcv, c14, c14, #0x7 */
/* @0x2b09cc strle r0, [r2, #-0x729] */
/* @0x2b09d0 .word 0xf7fe4620 */
/* @0x2b09d4 strbeq pc, [r10, #-0xed4]! */
/* @0x2b09d8 strtmi sp, [r0], -r2, lsl #10 */
/* @0x2b09dc .word 0xff2df7fe */
/* @0x2b09e0 ldreq r6, [r11], #-2227 */
/* @0x2b09e4 strtmi sp, [r0], -r4, lsl #10 */
/* @0x2b09e8 ldrsbtne pc, [r8], #134 */
/* @0x2b09ec ldc2 p7, c15, [r0, #1020] */
/* @0x2b09f0 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2b09f4 ldrhtmi lr, [r0], #-141 */
/* @0x2b09f8 bllt 0x8ee9fc <b2_toiTime+0x195558> */
/* @0x2b09fc stmvs r3, {r4, r5, r6, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2b08c5 · png_set_compression_window_bits · size=76 · insn=0 */

/* ── FUNC 0x2b0911 · png_set_compression_method · size=44 · insn=0 */
