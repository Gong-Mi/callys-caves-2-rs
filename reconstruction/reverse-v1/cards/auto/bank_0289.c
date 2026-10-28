/* libyoyo.so 覆盖卡组 0289
 * 函数 0x2e5525..0x2e5dc2，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e5525 · FT_Select_Metrics · size=100 · insn=0 */

/* ── FUNC 0x2e5589 · FT_Request_Metrics · size=370 · insn=0 */

/* ── FUNC 0x2e56fa · anon_2e56fa · size=52 · insn=13 */
/* @0x2e56fa orrslt r11, r0, r0, lsl r5 */
/* @0x2e56fe streq r6, [r4, r4, lsl #17]! */
/* @0x2e5702 stmdbhs r0, {r0, r1, r2, r3, r8, r10, r12, lr, pc} */
/* @0x2e5706 stmibvs r4, {r0, r1, r2, r3, r8, r9, r11, r12, lr, pc} ^ */
/* @0x2e570a ble 0x5f6196 <g_SWFaavertbuff+0x230ce> */
/* @0x2e570e ldmvs r2, {r1, r9, r10, r11, sp, lr} ^ */
/* @0x2e5712 ldrsblt r6, [r4, -r4] */
/* @0x2e5716 strmi r6, [r0, r0, lsl #27]! */
/* @0x2e571a .word 0xf7ffbd10 */
/* @0x2e571e strtmi pc, [r0], -r2, lsl #30 */
/* @0x2e5722 eorhs r11, r3, r0, lsl sp */
/* @0x2e5726 andhs r11, r6, r0, lsl sp */
/* @0x2e572a ldrlt r11, [r7, #-0xd10]! */

/* ── FUNC 0x2e56fb · FT_Select_Size · size=50 · insn=0 */

/* ── FUNC 0x2e572c · anon_2e572c · size=168 · insn=42 */
/* @0x2e572c .word 0x4604b537 */
/* @0x2e5730 movtlt r11, #0x1338 */
/* @0x2e5734 bhs 0x2ff864 <TT_RunIns+0x2a70> */
/* @0x2e5738 stmvs r10, {r0, r2, r5, r8, r9, r11, r12, lr, pc} */
/* @0x2e573c blle 0xb6ff44 <b2_toiTime+0x416aa0> */
/* @0x2e5740 blhs 0x3ff774 <g_RomDisk+0x7f54> */
/* @0x2e5744 stcvs p8, c13, [r3, #124] */
/* @0x2e5748 bvs 0xfe9adf50 <b2_toiTime+0xfffffffffe254aac> */
/* @0x2e574c mcrvs p0, #0x0, r6, c3, c10, #0x6 */
/* @0x2e5750 ldcvs p8, c6, [sp, #876] */
/* @0x2e5754 stcvs p1, c11, [r0, #84] */
/* @0x2e5758 ands r4, r5, r8, lsr #15 */
/* @0x2e575c .word 0xf0036883 */
/* @0x2e5760 blhs 0x366374 <_ZTS12CDS_Priority+0x83cc> */
/* @0x2e5764 strtmi sp, [r10], -r9, lsl #2 */
/* @0x2e5768 .word 0xf7ffab01 */
/* @0x2e576c ldmdblt r8, {r0, r1, r3, r4, r6, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e5770 stmdbls r1, {r5, r9, r10, lr} */
/* @0x2e5774 .word 0xffc1f7ff */
/* @0x2e5778 .word 0xf7ffe006 */
/* @0x2e577c strtmi pc, [r8], -r5, lsl #30 */
/* @0x2e5780 eorhs lr, r3, r2 */
/* @0x2e5784 andhs lr, r6, r0 */
/* @0x2e5788 ldclt p0, c11, [r0, #-12]! */
/* @0x2e578c addlt r11, r7, r0, lsr r5 */
/* @0x2e5790 tstlt r9, r10, lsl #24 */
/* @0x2e5794 svclt #0x82a00 */
/* @0x2e5798 and r4, r0, r10, lsl #12 */
/* @0x2e579c tstlt r11, r1, lsl r6 */
/* @0x2e57a0 svclt #0x82c00 */
/* @0x2e57a4 and r4, r0, r12, lsl r6 */
/* @0x2e57a8 stmdbhs r0, {r0, r1, r5, r9, r10, lr} ^ */
/* @0x2e57ac strhhs r11, [r0, #-248] */
/* @0x2e57b0 svclt #0xb82a40 */
/* @0x2e57b4 stmdblt r11, {r6, r9, sp} */
/* @0x2e57b8 strtmi r2, [r3], -r8, asr #8 */
/* @0x2e57bc stmdbge r1, {r1, r8, r12, pc} */
/* @0x2e57c0 andls r2, r3, #0, #10 */
/* @0x2e57c4 movwls r9, #0x4501 */
/* @0x2e57c8 .word 0xf7ff9405 */
/* @0x2e57cc andlt pc, r7, pc, lsr #31 */
/* @0x2e57d0 ldrlt r11, [r0, #-0xd30] */

/* ── FUNC 0x2e572d · FT_Request_Size · size=96 · insn=0 */

/* ── FUNC 0x2e578d · FT_Set_Char_Size · size=70 · insn=0 */

/* ── FUNC 0x2e57d2 · anon_2e57d2 · size=76 · insn=19 */
/* @0x2e57d2 .word 0xf64fb510 */
/* @0x2e57d6 strdlt r7, r8, [r6], lr */
/* @0x2e57da bhs 0x311c46 <af_shaper_get_elem+0x74b4> */
/* @0x2e57de strmi r11, [r10], -r8, lsl #30 */
/* @0x2e57e2 teqlt r2, r1 */
/* @0x2e57e6 .word 0xf64f4611 */
/* @0x2e57ea addsmi r7, r9, #-16777216 */
/* @0x2e57ee strtmi r11, [r1], -r8, lsl #31 */
/* @0x2e57f2 mrshs lr, apsr */
/* @0x2e57f6 .word 0xf64f460a */
/* @0x2e57fa addsmi r7, r10, #-16777216 */
/* @0x2e57fe strtmi r11, [r2], -r8, lsl #31 */
/* @0x2e5802 smlabbls r2, r9, r1, r0 */
/* @0x2e5806 movwhs r10, #0x901 */
/* @0x2e580a movwls r0, #0x1192 */
/* @0x2e580e movwls r9, #0x4203 */
/* @0x2e5812 .word 0xf7ff9305 */
/* @0x2e5816 andlt pc, r6, r10, lsl #31 */
/* @0x2e581a ldrblt r11, [r8, #0xd10]! */

/* ── FUNC 0x2e57d3 · FT_Set_Pixel_Sizes · size=74 · insn=0 */

/* ── FUNC 0x2e581c · anon_2e581c · size=356 · insn=89 */
/* @0x2e581c ssub8mi r11, lr, r8 */
/* @0x2e5820 strmi r9, [r5], -r6, lsl #24 */
/* @0x2e5824 eorsle r2, r12, r0, lsl #16 */
/* @0x2e5828 eorsle r2, r12, r0, lsl #24 */
/* @0x2e582c movwhs r6, #0xe07 */
/* @0x2e5830 rsbvs r6, r3, r3, lsr #32 */
/* @0x2e5834 ldclvs p8, c6, [pc], {251} */
/* @0x2e5838 eorsle r2, r0, r0, lsl #30 */
/* @0x2e583c ldrmi r4, [r8, r3, lsr #12]! */
/* @0x2e5840 teqle r1, r0, lsl #16 */
/* @0x2e5844 eorle r2, r10, r2, lsl #28 */
/* @0x2e5848 stmdavs r0!, {r0, r1, r3, r5, r7, r8, r10, r11, sp, lr} */
/* @0x2e584c .word 0xf7ff6919 */
/* @0x2e5850 .word 0x6020fafd */
/* @0x2e5854 stmdavs r0!, {r0, r1, r3, r5, r7, r8, r10, r11, sp, lr} ^ */
/* @0x2e5858 .word 0xf7ff6959 */
/* @0x2e585c .word 0x2e01faf7 */
/* @0x2e5860 rsbvs r4, r0, r7, lsl #12 */
/* @0x2e5864 stcvs p0, c13, [r11, #108]! */
/* @0x2e5868 ldmibhi r9, {r5, r11, sp, lr} */
/* @0x2e586c stmdale r3, {r3, r4, r8, r11, sp} */
/* @0x2e5870 .word 0xf7ff2219 */
/* @0x2e5874 eorvs pc, r0, r3, ror #20 */
/* @0x2e5878 ldmibhi r9, {r0, r1, r3, r5, r7, r8, r10, r11, sp, lr} ^ */
/* @0x2e587c stmdale r4, {r3, r4, r8, r11, sp} */
/* @0x2e5880 andshs r4, r9, #56, #12 */
/* @0x2e5884 blx 0x19a3888 <b2_toiTime+0x124a3e4> */
/* @0x2e5888 stmdavs r3!, {r5, r6, sp, lr} */
/* @0x2e588c .word 0xf0233320 */
/* @0x2e5890 eorvs r0, r3, pc, lsr r3 */
/* @0x2e5894 .word 0x33206863 */
/* @0x2e5898 teqeq pc, #35 */
/* @0x2e589c andhs r6, r0, r3, rrx */
/* @0x2e58a0 .word 0x2023bdf8 */
/* @0x2e58a4 strdhs r11, r12, [r6], -r8 */
/* @0x2e58a8 strdeq r11, r12, [r0], -r8 */
/* @0x2e58ac mvnsmi lr, sp, lsr #18 */
/* @0x2e58b0 ldrmi r4, [r0], pc, lsl #12 */
/* @0x2e58b4 .word 0x4604461d */
/* @0x2e58b8 .word 0xb1b3b1a0 */
/* @0x2e58bc stmdavs r3, {r9, r10, r11, sp, lr} */
/* @0x2e58c0 ldmdblt r3, {r0, r1, r3, r4, r9, r11, sp, lr} */
/* @0x2e58c4 pop {r0, r1, r2, sp} */
/* @0x2e58c8 stmdbmi r9, {r4, r5, r6, r7, r8, pc} */
/* @0x2e58cc .word 0x47984479 */
/* @0x2e58d0 rscsle r2, r7, r0, lsl #16 */
/* @0x2e58d4 ldrtmi r6, [r9], -r6, lsl #16 */
/* @0x2e58d8 strbmi r4, [r2], -r0, lsr #12 */
/* @0x2e58dc ldrmi r4, [r0, r11, lsr #12]! */
/* @0x2e58e0 ldrhhi lr, [r0, #141]! */
/* @0x2e58e4 pop {r0, r1, r5, sp} */
/* @0x2e58e8 strdhs r8, r9, [r6], -r0 */
/* @0x2e58ec ldrhhi lr, [r0, #141]! */
/* @0x2e58f0 andeq r8, r10, r8, lsl lr */
/* @0x2e58f4 .word 0x4603b530 */
/* @0x2e58f8 ldrhlt r11, [r9, r0]! */
/* @0x2e58fc addsmi r4, r1, #53248 */
/* @0x2e5900 pop {r0, r1, r8, r12, lr, pc} */
/* @0x2e5904 .word 0xf7ff4030 */
/* @0x2e5908 bvs 0xfe393af4 <b2_toiTime+0xfffffffffdc3a650> */
/* @0x2e590c bvs 0x1311f1c <b2_toiTime+0xbb8a78> */
/* @0x2e5910 streq lr, [r0, #0xb02] */
/* @0x2e5914 andle r4, r9, #-1610612726 */
/* @0x2e5918 bleq 0x423a68 <g_RomDisk+0x2c248> */
/* @0x2e591c addmi r6, r12, #68, #16 */
/* @0x2e5920 ldrbvs sp, [r8, #0x1f8] */
/* @0x2e5924 ldclt p0, c2, [r0, #-0]! */
/* @0x2e5928 ldclt p0, c2, [r0, #-140]! */
/* @0x2e592c ldclt p0, c2, [r0, #-24]! */
/* @0x2e5930 ldclt p0, c2, [r0, #-152]! */
/* @0x2e5934 strbvc r6, [lr, #-0x963]! */
/* @0x2e5938 .word 0xb160b510 */
/* @0x2e593c cmplt r2, r2, lsl #16 */
/* @0x2e5940 movwhs r6, #0xa54 */
/* @0x2e5944 ble 0x5363d8 <_IO_myKeyDown+0xca8> */
/* @0x2e5948 .word 0xf8516a91 */
/* @0x2e594c addmi r1, r1, #35 */
/* @0x2e5950 movwlo sp, #0x1004 */
/* @0x2e5954 .word 0xf04fe7f6 */
/* @0x2e5958 ldclt p0, c3, [r0, #-1020] */
/* @0x2e595c ldclt p6, c4, [r0, #-96] */
/* @0x2e5960 .word 0x4604b510 */
/* @0x2e5964 andhs r11, r0, r8, lsl #18 */
/* @0x2e5968 stclvs p13, c11, [r0, #64] */
/* @0x2e596c rscsle r2, r10, r0, lsl #16 */
/* @0x2e5970 ldmvs r11, {r0, r1, r6, r7, r11, sp, lr} ^ */
/* @0x2e5974 stmdbvs r3!, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e5978 rscsle r4, r4, #152, #4 */
/* @0x2e597c ldrblt r11, [r7, #0xd10]! */

/* ── FUNC 0x2e581d · FT_Get_Kerning · size=142 · insn=0 */

/* ── FUNC 0x2e58ad · FT_Get_Track_Kerning · size=72 · insn=0 */

/* ── FUNC 0x2e58f5 · FT_Select_Charmap · size=68 · insn=0 */

/* ── FUNC 0x2e5939 · FT_Get_Charmap_Index · size=40 · insn=0 */

/* ── FUNC 0x2e5961 · FT_Get_Char_Index · size=30 · insn=0 */

/* ── FUNC 0x2e597e · anon_2e597e · size=64 · insn=16 */
/* @0x2e597e ssub8mi r11, r7, r7 */
/* @0x2e5982 orrslt r4, r0, r4, lsl #12 */
/* @0x2e5986 orrslt r6, r5, r5, asr #27 */
/* @0x2e598a orrlt r6, r11, r3, lsl #18 */
/* @0x2e598e .word 0xf846ae02 */
/* @0x2e5992 stmvs r11!, {r2, r8, r10, r11, r12} ^ */
/* @0x2e5996 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x2e599a .word 0x4798691b */
/* @0x2e599e addsmi r6, r0, #557056 */
/* @0x2e59a2 rscsle r4, r6, #3145728 */
/* @0x2e59a6 stmdals r1, {r5, r8, r12, sp, pc} */
/* @0x2e59aa strmi lr, [r3], -r3 */
/* @0x2e59ae strtmi lr, [r11], -r0 */
/* @0x2e59b2 .word 0xb1074618 */
/* @0x2e59b6 andlt r6, r3, r11, lsr r0 */
/* @0x2e59ba ldrlt r11, [r7, #-0xdf0]! */

/* ── FUNC 0x2e597f · FT_Get_Next_Char · size=62 · insn=0 */

/* ── FUNC 0x2e59bc · anon_2e59bc · size=1032 · insn=258 */
/* @0x2e59bc .word 0x460db537 */
/* @0x2e59c0 .word 0x21004604 */
/* @0x2e59c4 stmdblt r8, {r0, r8, r12, pc} */
/* @0x2e59c8 and r2, pc, r0 */
/* @0x2e59cc blhs 0x3010e0 <TT_New_Context+0xed8> */
/* @0x2e59d0 stmdbvs r3, {r1, r3, r4, r5, r6, r7, r12, lr, pc} */
/* @0x2e59d4 rscsle r2, r7, r0, lsl #22 */
/* @0x2e59d8 .word 0xffc2f7ff */
/* @0x2e59dc andls r4, r1, r1, lsl #12 */
/* @0x2e59e0 mvnsle r2, r0, lsl #16 */
/* @0x2e59e4 bge 0x33726c */
/* @0x2e59e8 .word 0xffc9f7ff */
/* @0x2e59ec blls 0x351e28 */
/* @0x2e59f0 andlt r6, r3, r11, lsr #32 */
/* @0x2e59f4 andeq r11, r0, r0, lsr sp */
/* @0x2e59f8 svcmi #0xf0e92d */
/* @0x2e59fc andlo r11, r8, #1589248 */
/* @0x2e5a00 ldrsblt pc, [r8], pc */
/* @0x2e5a04 .word 0xf04f4e23 */
/* @0x2e5a08 svcmi #0x233cff */
/* @0x2e5a0c .word 0xf04f2400 */
/* @0x2e5a10 .word 0xf04f08ff */
/* @0x2e5a14 ands r0, r10, r1, lsl #18 */
/* @0x2e5a18 mvnsle r2, r0, lsl #20 */
/* @0x2e5a1c pop {r1, r2, sp} */
/* @0x2e5a20 .word 0xf8528ff0 */
/* @0x2e5a24 ldrbmi r3, [r11, #-0xc08] */
/* @0x2e5a28 .word 0xf852d117 */
/* @0x2e5a2c .word 0xf8d0ac04 */
/* @0x2e5a30 .word 0xf1ba3080 */
/* @0x2e5a34 andle r0, sp, r0, lsl #30 */
/* @0x2e5a38 mulge r0, r10, r8 */
/* @0x2e5a3c svceq #0x1f1ba */
/* @0x2e5a40 .word 0x46cabf14 */
/* @0x2e5a44 .word 0xf88346a2 */
/* @0x2e5a48 stmdblo r1, {r3, r4, r5, sp, pc} */
/* @0x2e5a4c stmdbhs r0, {r3, r9, r12, sp} */
/* @0x2e5a50 ands sp, r8, r7, ror #3 */
/* @0x2e5a54 eorshi pc, r8, r3, lsl #17 */
/* @0x2e5a58 adcsmi lr, r3, #64749568 */
/* @0x2e5a5c adcsmi sp, r11, #22 */
/* @0x2e5a60 .word 0xf852d1dc */
/* @0x2e5a64 .word 0xf8d03c04 */
/* @0x2e5a68 smlalbblt r10, r11, r0, r0 */
/* @0x2e5a6c .word 0xf8ca681b */
/* @0x2e5a70 .word 0xf8d0303c */
/* @0x2e5a74 blvs 0xffa31c7c <b2_toiTime+0xffffffffff2d87d8> */
/* @0x2e5a78 ble 0xffc70e80 <b2_toiTime+0xffffffffff5179dc> */
/* @0x2e5a7c ubfx r6, r12, #0x7, #0x5 */
/* @0x2e5a80 eorsgt pc, r12, r10, asr #17 */
/* @0x2e5a84 strmi lr, [r8], -r1, ror #15 */
/* @0x2e5a88 svchi #0xf0e8bd */
/* @0x2e5a8c pop {r0, r1, r2, sp} */
/* @0x2e5a90 svclt #0x8ff0 */
/* @0x2e5a94 stclvs p4, c6, [r3], #-408 */
/* @0x2e5a98 .word 0x73656564 */
/* @0x2e5a9c strbtvs r7, [r1], #-619 */
/* @0x2e5aa0 .word 0x460db538 */
/* @0x2e5aa4 stmdblt r8, {r2, r9, r10, lr} */
/* @0x2e5aa8 ldclt p0, c2, [r8, #-0]! */
/* @0x2e5aac ldreq r6, [r9, #0x883] */
/* @0x2e5ab0 stchs p5, c13, [r0, #-1000] */
/* @0x2e5ab4 .word 0xf8d0d0f8 */
/* @0x2e5ab8 bvs 0xfe9b1cc0 <b2_toiTime+0xfffffffffe25881c> */
/* @0x2e5abc smlalsle r1, r3, r10, r12 */
/* @0x2e5ac0 cdpvs p9, #0x0, c11, c0, c3, #0x4 */
/* @0x2e5ac4 bvs 0x77fad4 <b2_toiTime+0x26630> */
/* @0x2e5ac8 stmdbmi r10, {r1, r3, r4, r8, r12, sp, pc} */
/* @0x2e5acc .word 0x47904479 */
/* @0x2e5ad0 .word 0xf8d44603 */
/* @0x2e5ad4 blhs 0x2edcdc <FT_Done_Memory+0x4068> */
/* @0x2e5ad8 sadd16mi r11, r9, r4 */
/* @0x2e5adc .word 0x0101f06f */
/* @0x2e5ae0 smlalle r6, r1, r1, r2 */
/* @0x2e5ae4 blhs 0x2ffc58 <TT_RunIns+0x2e64> */
/* @0x2e5ae8 .word 0x4620d0de */
/* @0x2e5aec ldrmi r4, [r8, r9, lsr #12] */
/* @0x2e5af0 svclt #0xbd38 */
/* @0x2e5af4 andeq r8, r10, r0, lsr #24 */
/* @0x2e5af8 mvnsmi lr, sp, lsr #18 */
/* @0x2e5afc ldrmi r4, [r5], -pc, lsl #12 */
/* @0x2e5b00 .word 0x46044698 */
/* @0x2e5b04 eorle r2, lr, r0, lsl #16 */
/* @0x2e5b08 andhs r11, r6, r2, lsl r9 */
/* @0x2e5b0c ldrhhi lr, [r0, #141]! */
/* @0x2e5b10 rscsle r2, r10, r0, lsl #22 */
/* @0x2e5b14 andsvc r2, r3, r0, lsl #6 */
/* @0x2e5b18 addsmi r6, r9, #49152 */
/* @0x2e5b1c stmvs r3, {r1, r2, r5, r9, r11, r12, lr, pc} */
/* @0x2e5b20 ldrble r0, [r2, #0x59a]! */
/* @0x2e5b24 .word 0x3080f8d0 */
/* @0x2e5b28 vstmiane r3, {s12, s13, s14, s15, s16, s17, s18, s19, s20, s21, s22, s23, s24, s25, s26, s27, s28, s29, s30, s31} */
/* @0x2e5b2c stmiblt r0, {r0, r2, r3, r5, r6, r7, r12, lr, pc} */
/* @0x2e5b30 ldmdavs r3, {r1, r5, r9, r10, r11, sp, lr} */
/* @0x2e5b34 tstlt r11, r11, lsl r10 */
/* @0x2e5b38 ldrmi r4, [r0], -lr, lsl #18 */
/* @0x2e5b3c .word 0x47984479 */
/* @0x2e5b40 .word 0x3080f8d4 */
/* @0x2e5b44 svclt #0x142800 */
/* @0x2e5b48 .word 0xf06f4602 */
/* @0x2e5b4c addsvs r0, r10, #268435456 */
/* @0x2e5b50 stmdavs r6, {r0, r1, r3, r4, r6, r7, r12, lr, pc} */
/* @0x2e5b54 sbcsle r2, r8, r0, lsl #28 */
/* @0x2e5b58 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2e5b5c strbmi r4, [r3], -r10, lsr #12 */
/* @0x2e5b60 pop {r4, r5, r7, r8, r9, r10, lr} */
/* @0x2e5b64 .word 0x202381f0 */
/* @0x2e5b68 ldrhhi lr, [r0, #141]! */
/* @0x2e5b6c pop {r4, sp} */
/* @0x2e5b70 svclt #0x81f0 */
/* @0x2e5b74 strheq r8, [r10], -r0 */
/* @0x2e5b78 .word 0x4604b510 */
/* @0x2e5b7c andhs r11, r0, r8, lsl #18 */
/* @0x2e5b80 .word 0xf8d0bd10 */
/* @0x2e5b84 ldmibvs r11, {r7, r12, sp} ^ */
/* @0x2e5b88 smlalsle r1, r8, r10, r12 */
/* @0x2e5b8c cdpvs p9, #0x0, c11, c0, c3, #0x4 */
/* @0x2e5b90 bvs 0x77fba0 <b2_toiTime+0x266fc> */
/* @0x2e5b94 stmdbmi r9, {r1, r3, r4, r8, r12, sp, pc} */
/* @0x2e5b98 .word 0x47904479 */
/* @0x2e5b9c .word 0xf8d44603 */
/* @0x2e5ba0 blhs 0x2edda8 <FT_Done_Memory+0x4134> */
/* @0x2e5ba4 sadd16mi r11, r9, r4 */
/* @0x2e5ba8 .word 0x0101f06f */
/* @0x2e5bac .word 0xd0e661d1 */
/* @0x2e5bb0 blhs 0x2ffc24 <TT_RunIns+0x2e30> */
/* @0x2e5bb4 strtmi sp, [r0], -r3, ror #1 */
/* @0x2e5bb8 ldclt p7, c4, [r0, #-608] */
/* @0x2e5bbc andeq r8, r10, pc, asr r11 */
/* @0x2e5bc0 .word 0x460db538 */
/* @0x2e5bc4 stmdblt r8, {r2, r9, r10, lr} */
/* @0x2e5bc8 ldclt p0, c2, [r8, #-0]! */
/* @0x2e5bcc ldreq r6, [r11, -r3, lsl #17] */
/* @0x2e5bd0 mcrvs p5, #0x0, sp, c0, c10, #0x7 */
/* @0x2e5bd4 bvs 0x9bfbe8 <b2_toiTime+0x266744> */
/* @0x2e5bd8 rscsle r2, r5, r0, lsl #22 */
/* @0x2e5bdc ldrbtmi r4, [r9], #-2308 */
/* @0x2e5be0 stmdahs r0, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e5be4 stmdavs r3, {r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x2e5be8 strtmi r4, [r0], -r9, lsr #12 */
/* @0x2e5bec ldclt p7, c4, [r8, #-608]! */
/* @0x2e5bf0 andeq r8, r10, lr, lsr #22 */
/* @0x2e5bf4 mvnsmi lr, sp, lsr #18 */
/* @0x2e5bf8 ldrmi r4, [r0], lr, lsl #12 */
/* @0x2e5bfc .word 0x4604461f */
/* @0x2e5c00 stmvs r0, {r4, r5, r7, r8, r12, sp, pc} */
/* @0x2e5c04 ldrle r0, [r3, #-0x703] */
/* @0x2e5c08 stmdavs r5, {r5, r9, r10, r11, sp, lr} */
/* @0x2e5c0c stmdblt sp, {r0, r2, r3, r5, r9, r11, sp, lr} */
/* @0x2e5c10 and r2, lr, r7 */
/* @0x2e5c14 ldrbtmi r4, [r9], #-2312 */
/* @0x2e5c18 stmdahs r0, {r3, r5, r7, r8, r9, r10, lr} */
/* @0x2e5c1c stcls p0, c13, [r8, #-992] */
/* @0x2e5c20 .word 0x46424631 */
/* @0x2e5c24 strls r4, [r0, #-0x63b] */
/* @0x2e5c28 strtmi r6, [r0], -r5, lsl #16 */
/* @0x2e5c2c and r4, r0, r8, lsr #15 */
/* @0x2e5c30 andlt r2, r2, r3, lsr #32 */
/* @0x2e5c34 ldrhhi lr, [r0, #141]! */
/* @0x2e5c38 strdeq r8, r9, [r10], -r6 */
/* @0x2e5c3c mvnsmi lr, sp, lsr #18 */
/* @0x2e5c40 ldrmi r4, [r7], -lr, lsl #12 */
/* @0x2e5c44 .word 0x46044698 */
/* @0x2e5c48 stmvs r0, {r4, r5, r7, r8, r12, sp, pc} */
/* @0x2e5c4c ldrle r0, [r3, #-0x703] */
/* @0x2e5c50 stmdavs r5, {r5, r9, r10, r11, sp, lr} */
/* @0x2e5c54 stmdblt sp, {r0, r2, r3, r5, r9, r11, sp, lr} */
/* @0x2e5c58 and r2, lr, r7 */
/* @0x2e5c5c ldrbtmi r4, [r9], #-2312 */
/* @0x2e5c60 stmdahs r0, {r3, r5, r7, r8, r9, r10, lr} */
/* @0x2e5c64 .word 0xf8cdd0f8 */
/* @0x2e5c68 ldrtmi r8, [r1], -r0 */
/* @0x2e5c6c ldrtmi r6, [r10], -r5, lsl #17 */
/* @0x2e5c70 blge 0x3b74f8 <error_g0017+0x1019c> */
/* @0x2e5c74 and r4, r0, r8, lsr #15 */
/* @0x2e5c78 andlt r2, r4, r3, lsr #32 */
/* @0x2e5c7c ldrhhi lr, [r0, #141]! */
/* @0x2e5c80 andeq r8, r10, lr, lsr #21 */
/* @0x2e5c84 .word 0x4604b513 */
/* @0x2e5c88 andhs r11, r0, r8, lsl #18 */
/* @0x2e5c8c stmdavs r3, {r0, r1, r4, sp, lr, pc} */
/* @0x2e5c90 rscsle r2, r10, r0, lsl #22 */
/* @0x2e5c94 stmdavs r3, {r3, r4, r9, r10, r11, sp, lr} */
/* @0x2e5c98 blhs 0x30050c <TT_New_Context+0x304> */
/* @0x2e5c9c stmdbmi r7, {r0, r2, r4, r5, r6, r7, r12, lr, pc} */
/* @0x2e5ca0 .word 0x47984479 */
/* @0x2e5ca4 rscsle r2, r0, r0, lsl #16 */
/* @0x2e5ca8 strbtmi r6, [r9], -r3, lsl #16 */
/* @0x2e5cac ldrmi r4, [r8, r0, lsr #12] */
/* @0x2e5cb0 mvnle r2, r0, lsl #16 */
/* @0x2e5cb4 andlt r9, r2, r0, lsl #16 */
/* @0x2e5cb8 svclt #0xbd10 */
/* @0x2e5cbc andeq r8, r10, r7, ror r10 */
/* @0x2e5cc0 .word 0x4604b513 */
/* @0x2e5cc4 .word 0xf04fb910 */
/* @0x2e5cc8 ldrsh r3, [r3], -pc */
/* @0x2e5ccc blhs 0x2ffce0 <TT_RunIns+0x2eec> */
/* @0x2e5cd0 mrcvs p0, #0x0, sp, c8, c9, #0x7 */
/* @0x2e5cd4 bvs 0x9bfce8 <b2_toiTime+0x266844> */
/* @0x2e5cd8 rscsle r2, r4, r0, lsl #22 */
/* @0x2e5cdc ldrbtmi r4, [r9], #-2310 */
/* @0x2e5ce0 stmdahs r0, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e5ce4 stmdavs r3, {r0, r1, r2, r3, r5, r6, r7, r12, lr, pc} */
/* @0x2e5ce8 strtmi r4, [r0], -r9, ror #12 */
/* @0x2e5cec stmdahs r0, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e5cf0 stmdals r1, {r0, r3, r5, r6, r7, r8, r12, lr, pc} */
/* @0x2e5cf4 ldclt p0, c11, [r0, #-8] */
/* @0x2e5cf8 andeq r8, r10, r9, lsr r10 */
/* @0x2e5cfc .word 0x460db570 */
/* @0x2e5d00 orrslt r4, r8, r4, lsl #12 */
/* @0x2e5d04 orrslt r6, lr, r6, lsl #21 */
/* @0x2e5d08 .word 0x4608b191 */
/* @0x2e5d0c .word 0xffd8f7ff */
/* @0x2e5d10 andle r2, pc, lr, lsl #16 */
/* @0x2e5d14 bl 0x4806a8 <_ZN10InputQuery13ms_InputText2E+0x12b8> */
/* @0x2e5d18 addsmi r0, lr, #201326594 */
/* @0x2e5d1c .word 0xf856d20a */
/* @0x2e5d20 adcmi r2, r10, #4, #22 */
/* @0x2e5d24 strbvs sp, [r5, #0x1f9]! */
/* @0x2e5d28 ldcllt p0, c2, [r0, #-0]! */
/* @0x2e5d2c ldcllt p0, c2, [r0, #-140]! */
/* @0x2e5d30 ldcllt p0, c2, [r0, #-152]! */
/* @0x2e5d34 ldcllt p0, c2, [r0, #-24]! */
/* @0x2e5d38 bvs 0xfe413300 <b2_toiTime+0xfffffffffdcb9e5c> */
/* @0x2e5d3c andhs r11, r0, r12, lsl #18 */
/* @0x2e5d40 bvs 0x1495308 <b2_toiTime+0xd3be64> */
/* @0x2e5d44 streq lr, [r6], r4, lsl #22 */
/* @0x2e5d48 .word 0x462542b4 */
/* @0x2e5d4c .word 0xf854d2f7 */
/* @0x2e5d50 stmvs r3, {r2, r8, r9, r11} */
/* @0x2e5d54 svchs #0xa0f5b3 */
/* @0x2e5d58 .word 0xf7ffd1f6 */
/* @0x2e5d5c stmdahs lr, {r0, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e5d60 stmdavs r8!, {r1, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x2e5d64 andeq r11, r0, r0, ror sp */
/* @0x2e5d68 .word 0x460fb5f8 */
/* @0x2e5d6c .word 0x46044616 */
/* @0x2e5d70 andhs r11, r0, r8, lsl #18 */
/* @0x2e5d74 stclvs p13, c11, [r5, #992] */
/* @0x2e5d78 rscsle r2, r10, r0, lsl #26 */
/* @0x2e5d7c blmi 0x4bff2c <SrcVerts+0x1cf70> */
/* @0x2e5d80 .word 0xd1f6429a */
/* @0x2e5d84 .word 0xffd8f7ff */
/* @0x2e5d88 stmdahs r0, {r0, r5, r6, r7, r8, r10, r11, sp, lr} */
/* @0x2e5d8c stmvs r3, {r0, r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x2e5d90 ldmdbvs r12, {r1, r3, r4, r5, r9, r10, lr} ^ */
/* @0x2e5d94 .word 0x47a04633 */
/* @0x2e5d98 svclt #0xbdf8 */
/* @0x2e5d9c strbvc r6, [lr, #-0x963]! */
/* @0x2e5da0 .word 0x460db538 */
/* @0x2e5da4 ldmdblt r0, {r2, r4, r9, r10, lr} */
/* @0x2e5da8 rscslo pc, pc, pc, asr #32 */
/* @0x2e5dac .word 0xf7ffbd38 */
/* @0x2e5db0 stmdahs r0, {r0, r1, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e5db4 stmvs r3, {r3, r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x2e5db8 strtmi r4, [r2], -r9, lsr #12 */
/* @0x2e5dbc .word 0x4798699b */
/* @0x2e5dc0 ldrlt r11, [r0, #-0xd38] */

/* ── FUNC 0x2e59bd · FT_Get_First_Char · size=58 · insn=0 */

/* ── FUNC 0x2e59f9 · FT_Face_Properties · size=168 · insn=0 */

/* ── FUNC 0x2e5aa1 · FT_Get_Name_Index · size=88 · insn=0 */

/* ── FUNC 0x2e5af9 · FT_Get_Glyph_Name · size=128 · insn=0 */

/* ── FUNC 0x2e5b79 · FT_Get_Postscript_Name · size=72 · insn=0 */

/* ── FUNC 0x2e5bc1 · FT_Get_Sfnt_Table · size=52 · insn=0 */

/* ── FUNC 0x2e5bf5 · FT_Load_Sfnt_Table · size=72 · insn=0 */

/* ── FUNC 0x2e5c3d · FT_Sfnt_Table_Info · size=72 · insn=0 */

/* ── FUNC 0x2e5c85 · FT_Get_CMap_Language_ID · size=60 · insn=0 */

/* ── FUNC 0x2e5cc1 · FT_Get_CMap_Format · size=60 · insn=0 */

/* ── FUNC 0x2e5cfd · FT_Set_Charmap · size=60 · insn=0 */

/* ── FUNC 0x2e5d69 · FT_Face_GetCharVariantIndex · size=56 · insn=0 */

/* ── FUNC 0x2e5da1 · FT_Face_GetCharVariantIsDefault · size=34 · insn=0 */

/* ── FUNC 0x2e5dc2 · anon_2e5dc2 · size=168 · insn=42 */
/* @0x2e5dc2 .word 0x4604b510 */
/* @0x2e5dc6 andhs r11, r0, r8, lsl #18 */
/* @0x2e5dca .word 0xf7ffbd10 */
/* @0x2e5dce stmdahs r0, {r2, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e5dd2 stmvs r3, {r0, r3, r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x2e5dd6 ldmibvs r11, {r0, r5, r6, r9, r10, r11, sp, lr} ^ */
/* @0x2e5dda ldclt p7, c4, [r0, #-608] */
/* @0x2e5dde .word 0x460cb538 */
/* @0x2e5de2 stmdblt r8, {r0, r2, r9, r10, lr} */
/* @0x2e5de6 ldclt p0, c2, [r8, #-0]! */
/* @0x2e5dea .word 0xffa5f7ff */
/* @0x2e5dee rscsle r2, r9, r0, lsl #16 */
/* @0x2e5df2 strtmi r6, [r2], -r3, asr #17 */
/* @0x2e5df6 bvs 0x9c17a2 <b2_toiTime+0x2682fe> */
/* @0x2e5dfa ldclt p7, c4, [r8, #-608]! */
/* @0x2e5dfe .word 0x460cb538 */
/* @0x2e5e02 stmdblt r8, {r0, r2, r9, r10, lr} */
/* @0x2e5e06 ldclt p0, c2, [r8, #-0]! */
/* @0x2e5e0a .word 0xff95f7ff */
/* @0x2e5e0e rscsle r2, r9, r0, lsl #16 */
/* @0x2e5e12 strtmi r6, [r2], -r3, asr #17 */
/* @0x2e5e16 bvs 0x19c17c2 <b2_toiTime+0x126831e> */
/* @0x2e5e1a ldclt p7, c4, [r8, #-608]! */
/* @0x2e5e1e stmdavs r3, {r4, r5, r8, r12, sp, pc} */
/* @0x2e5e22 mrcvs p1, #0x0, r11, c10, c3, #0x1 */
/* @0x2e5e26 ldrvs r11, [r8, #0x122] */
/* @0x2e5e2a ldrbmi r2, [r0, -r0]! */
/* @0x2e5e2e ldrbmi r2, [r0, -r4, lsr #32]! */
/* @0x2e5e32 ldrbmi r2, [r0, -r3, lsr #32]! */
/* @0x2e5e36 stmdblt r8, {r4, r8, r10, r12, sp, pc} */
/* @0x2e5e3a ldclt p0, c2, [r0, #-0] */
/* @0x2e5e3e ldrsblo pc, [r4], r0 */
/* @0x2e5e42 ldmdavs r0, {r1, r4, r6, r8, r12, sp, pc} */
/* @0x2e5e46 stmdavs r3, {r8, r12, sp, pc} ^ */
/* @0x2e5e4a andsvs r2, r0, r0 */
/* @0x2e5e4e ldmvs r8, {r2, sp, lr, pc} */
/* @0x2e5e52 addmi r6, r12, #4, #18 */
/* @0x2e5e56 ldmdavs r11, {r0, r1, r12, lr, pc} ^ */
/* @0x2e5e5a mvnsle r2, r0, lsl #22 */
/* @0x2e5e5e smlattlt r10, r12, r7, lr */
/* @0x2e5e62 ldclt p0, c6, [r0, #-76] */
/* @0x2e5e66 andhs r11, r0, #16, #26 */
