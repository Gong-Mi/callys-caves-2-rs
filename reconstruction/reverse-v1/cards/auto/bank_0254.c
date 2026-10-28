/* libyoyo.so 覆盖卡组 0254
 * 函数 0x2a66de..0x2a6ad1，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a66de · anon_2a66de · size=32 · insn=8 */
/* @0x2a66de .word 0xb141b160 */
/* @0x2a66e2 .word 0xf4106888 */
/* @0x2a66e6 andle r7, r7, r0, lsl #1 */
/* @0x2a66ea mlslo r12, r1, r8, pc */
/* @0x2a66ee mcrvs p9, #0x4, r11, c8, c11, #0x0 */
/* @0x2a66f2 .word 0x46084770 */
/* @0x2a66f6 andhs r4, r0, r0, ror r7 */
/* @0x2a66fa tstlt r8, r0, ror r7 */

/* ── FUNC 0x2a66df · png_get_y_offset_pixels · size=30 · insn=0 */

/* ── FUNC 0x2a66fc · anon_2a66fc · size=28 · insn=7 */
/* @0x2a66fc .word 0xb109b118 */
/* @0x2a6700 ldrbmi r7, [r0, -r8, asr #30]! */
/* @0x2a6704 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a6708 tstlt r1, r0, lsr #2 */
/* @0x2a670c eoreq pc, r0, r1, lsl #2 */
/* @0x2a6710 .word 0x46084770 */
/* @0x2a6714 .word 0xb1604770 */

/* ── FUNC 0x2a66fd · png_get_channels · size=12 · insn=0 */

/* ── FUNC 0x2a6709 · png_get_signature · size=14 · insn=0 */

/* ── FUNC 0x2a6716 · anon_2a6716 · size=32 · insn=8 */
/* @0x2a6716 .word 0xb141b160 */
/* @0x2a671a .word 0xf0106888 */
/* @0x2a671e andle r0, r7, r0, lsr #32 */
/* @0x2a6722 cmplo r10, r10, lsr #2 */
/* @0x2a6726 andsvs r2, r1, r0, lsr #32 */
/* @0x2a672a .word 0x46084770 */
/* @0x2a672e ssub16mi r4, r0, r0 */
/* @0x2a6732 push {r4, r5, r6, r8, r9, r10, lr} */

/* ── FUNC 0x2a6717 · png_get_bKGD · size=30 · insn=0 */

/* ── FUNC 0x2a6734 · anon_2a6734 · size=172 · insn=43 */
/* @0x2a6734 mvnsmi lr, sp, lsr #18 */
/* @0x2a6738 .word 0xf8dd4698 */
/* @0x2a673c blls 0x4967a4 <g_prim_v+0x6798> */
/* @0x2a6740 cdpls p15, #0x0, c9, c9, c8, #0x0 */
/* @0x2a6744 .word 0x9c0b9d0a */
/* @0x2a6748 suble r2, r6, r0, lsl #16 */
/* @0x2a674c suble r2, r0, r0, lsl #18 */
/* @0x2a6750 .word 0xf0106888 */
/* @0x2a6754 suble r0, r0, r4 */
/* @0x2a6758 ldc p1, c11, [r1, #168] */
/* @0x2a675c .word 0xeeb77a20 */
/* @0x2a6760 vstr s14, [r2, #796] */
/* @0x2a6764 .word 0xf1b87b00 */
/* @0x2a6768 andle r0, r5, r0, lsl #30 */
/* @0x2a676c bvc 0xb21db8 <b2_toiTime+0x3c8914> */
/* @0x2a6770 bvc 0xff4a2254 <b2_toiTime+0xfffffffffed48db0> */
/* @0x2a6774 blvc 0x2e1d9c <_ZN23b2ChainAndCircleContactC2EP9b2FixtureiS1_i+0x2c> */
/* @0x2a6778 svceq #0xf1bc */
/* @0x2a677c ldc p0, c13, [r1, #20] */
/* @0x2a6780 .word 0xeeb77a22 */
/* @0x2a6784 vstr s14, [r12, #796] */
/* @0x2a6788 .word 0xb12b7b00 */
/* @0x2a678c bvc 0xba1dd8 <b2_toiTime+0x448934> */
/* @0x2a6790 bvc 0xff4a2274 <b2_toiTime+0xfffffffffed48dd0> */
/* @0x2a6794 blvc 0x2e1da8 <_ZN23b2ChainAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator> */
/* @0x2a6798 ldc p1, c11, [r1, #188] */
/* @0x2a679c .word 0xeeb77a24 */
/* @0x2a67a0 vstr s14, [r7, #796] */
/* @0x2a67a4 .word 0xb12e7b00 */
/* @0x2a67a8 bvc 0xc21df4 <b2_toiTime+0x4c8950> */
/* @0x2a67ac bvc 0xff4a2290 <b2_toiTime+0xfffffffffed48dec> */
/* @0x2a67b0 blvc 0x2e1dd0 <_ZN23b2ChainAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x28> */
/* @0x2a67b4 ldc p1, c11, [r1, #180] */
/* @0x2a67b8 .word 0xeeb77a26 */
/* @0x2a67bc vstr s14, [r5, #796] */
/* @0x2a67c0 .word 0xb14c7b00 */
/* @0x2a67c4 bvc 0xca1e10 <b2_toiTime+0x54896c> */
/* @0x2a67c8 bvc 0xff4a22ac <b2_toiTime+0xfffffffffed48e08> */
/* @0x2a67cc blvc 0x2e1de4 <_ZN23b2ChainAndCircleContact6CreateEP9b2FixtureiS1_iP16b2BlockAllocator+0x3c> */
/* @0x2a67d0 strmi lr, [r8], -r2 */
/* @0x2a67d4 ldrhhi lr, [r0, #141]! */
/* @0x2a67d8 pop {r2, sp} */
/* @0x2a67dc push {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2a6735 · png_get_cHRM · size=170 · insn=0 */

/* ── FUNC 0x2a67de · anon_2a67de · size=124 · insn=31 */
/* @0x2a67de mvnsmi lr, sp, lsr #18 */
/* @0x2a67e2 .word 0xf8dd4698 */
/* @0x2a67e6 blls 0x49684e <g_prim_v+0x6842> */
/* @0x2a67ea cdpls p15, #0x0, c9, c9, c8, #0x0 */
/* @0x2a67ee .word 0x9c0b9d0a */
/* @0x2a67f2 cmplt r1, #120, #6 */
/* @0x2a67f6 .word 0xf0106888 */
/* @0x2a67fa eorle r0, r10, r4 */
/* @0x2a67fe .word 0xf8d1b112 */
/* @0x2a6802 andsvs r0, r0, r0, lsl #2 */
/* @0x2a6806 svceq #0xf1b8 */
/* @0x2a680a .word 0xf8d1d003 */
/* @0x2a680e .word 0xf8c82104 */
/* @0x2a6812 .word 0xf1bc2000 */
/* @0x2a6816 andle r0, r3, r0, lsl #30 */
/* @0x2a681a .word 0x2108f8d1 */
/* @0x2a681e andhs pc, r0, r12, asr #17 */
/* @0x2a6822 .word 0xf8d1b113 */
/* @0x2a6826 andsvs r2, r10, r12, lsl #2 */
/* @0x2a682a .word 0xf8d1b117 */
/* @0x2a682e eorsvs r3, r11, r0, lsl r1 */
/* @0x2a6832 .word 0xf8d1b116 */
/* @0x2a6836 eorsvs r3, r3, r4, lsl r1 */
/* @0x2a683a .word 0xf8d1b115 */
/* @0x2a683e eorvs r3, r11, r8, lsl r1 */
/* @0x2a6842 .word 0xf8d1b134 */
/* @0x2a6846 eorvs r3, r3, r12, lsl r1 */
/* @0x2a684a strmi lr, [r8], -r2 */
/* @0x2a684e ldrhhi lr, [r0, #141]! */
/* @0x2a6852 pop {r2, sp} */
/* @0x2a6856 strdlt r8, r9, [r0, r0] */

/* ── FUNC 0x2a67df · png_get_cHRM_fixed · size=122 · insn=0 */

/* ── FUNC 0x2a6858 · anon_2a6858 · size=40 · insn=10 */
/* @0x2a6858 smulbblt r1, r0, r1 */
/* @0x2a685c .word 0xf0106888 */
/* @0x2a6860 andle r0, r11, r1 */
/* @0x2a6864 ldc p1, c11, [r1, #296] */
/* @0x2a6868 vmov.f32 s14, #1.625000e+00 */
/* @0x2a686c andhs r7, r1, r7, asr #21 */
/* @0x2a6870 blvc 0x2e1e80 <_ZN24b2ChainAndPolygonContact8EvaluateEP10b2ManifoldRK11b2TransformS4_+0x4c> */
/* @0x2a6874 .word 0x46084770 */
/* @0x2a6878 ssub16mi r4, r0, r0 */
/* @0x2a687c .word 0xb1684770 */

/* ── FUNC 0x2a6859 · png_get_gAMA · size=38 · insn=0 */

/* ── FUNC 0x2a687e · anon_2a687e · size=68 · insn=17 */
/* @0x2a687e .word 0xb149b168 */
/* @0x2a6882 .word 0xf0106888 */
/* @0x2a6886 andle r0, r8, r1 */
/* @0x2a688a .word 0xf8d1b132 */
/* @0x2a688e strdhs r3, r4, [r1], -r12 */
/* @0x2a6892 .word 0x47706013 */
/* @0x2a6896 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a689a .word 0x47704610 */
/* @0x2a689e cmplt r1, r0, ror r1 */
/* @0x2a68a2 .word 0xf4106888 */
/* @0x2a68a6 andle r6, r9, r0 */
/* @0x2a68aa .word 0xf891b13a */
/* @0x2a68ae vst4.8 {d19, d20, d21, d22}, [pc:128], r12 */
/* @0x2a68b2 andsvs r6, r3, r0 */
/* @0x2a68b6 .word 0x46084770 */
/* @0x2a68ba ssub16mi r4, r0, r0 */
/* @0x2a68be ldrlt r4, [r0, #-0x770]! */

/* ── FUNC 0x2a687f · png_get_gAMA_fixed · size=32 · insn=0 */

/* ── FUNC 0x2a689f · png_get_sRGB · size=34 · insn=0 */

/* ── FUNC 0x2a68c0 · anon_2a68c0 · size=72 · insn=18 */
/* @0x2a68c0 stcls p5, c11, [r3, #-192] */
/* @0x2a68c4 mvnlt r9, r4, lsl #24 */
/* @0x2a68c8 stmvs r8, {r0, r3, r5, r7, r8, r12, sp, pc} */
/* @0x2a68cc addpl pc, r0, r0, lsl r4 */
/* @0x2a68d0 orrslt sp, r2, r8, lsl r0 */
/* @0x2a68d4 .word 0xb1a4b19d */
/* @0x2a68d8 .word 0x00c4f8d1 */
/* @0x2a68dc vst4.8 {d22, d23, d24, d25}, [pc:64], r0 */
/* @0x2a68e0 .word 0xf8d15080 */
/* @0x2a68e4 eorvs r2, r10, r8, asr #1 */
/* @0x2a68e8 .word 0x20ccf8d1 */
/* @0x2a68ec .word 0xf8916022 */
/* @0x2a68f0 ldrsbvs r2, [r10], -r0 */
/* @0x2a68f4 .word 0x4608bd30 */
/* @0x2a68f8 sasxmi r11, r0, r0 */
/* @0x2a68fc qasxmi r11, r8, r0 */
/* @0x2a6900 qasxmi r11, r0, r0 */
/* @0x2a6904 cmplt r0, r0, lsr sp */

/* ── FUNC 0x2a68c1 · png_get_iCCP · size=70 · insn=0 */

/* ── FUNC 0x2a6906 · anon_2a6906 · size=28 · insn=7 */
/* @0x2a6906 teqlt r1, r0, asr r1 */
/* @0x2a690a .word 0xf8d1b13a */
/* @0x2a690e ldrsbvs r3, [r3], -r4 */
/* @0x2a6912 ldrsbeq pc, [r8], #129 */
/* @0x2a6916 .word 0x46084770 */
/* @0x2a691a ssub16mi r4, r0, r0 */
/* @0x2a691e .word 0xb1604770 */

/* ── FUNC 0x2a6907 · png_get_sPLT · size=26 · insn=0 */

/* ── FUNC 0x2a6920 · anon_2a6920 · size=32 · insn=8 */
/* @0x2a6920 .word 0xb141b160 */
/* @0x2a6924 .word 0xf0106888 */
/* @0x2a6928 andle r0, r7, r0, asr #32 */
/* @0x2a692c svcvs #0xcbb12a */
/* @0x2a6930 andsvs r2, r3, r0, asr #32 */
/* @0x2a6934 .word 0x46084770 */
/* @0x2a6938 ssub16mi r4, r0, r0 */
/* @0x2a693c push {r4, r5, r6, r8, r9, r10, lr} */

/* ── FUNC 0x2a6921 · png_get_hIST · size=30 · insn=0 */

/* ── FUNC 0x2a693e · anon_2a693e · size=204 · insn=51 */
/* @0x2a693e mvnsmi lr, sp, lsr #18 */
/* @0x2a6942 stcls p6, c4, [r10, #-48] */
/* @0x2a6946 .word 0xf8dd990b */
/* @0x2a694a .word 0xf8ddc030 */
/* @0x2a694e svcls #0xe8034 */
/* @0x2a6952 eorsle r2, r8, r0, lsl #16 */
/* @0x2a6956 eorle r2, sp, r0, lsl #24 */
/* @0x2a695a eorle r2, sp, r0, lsl #20 */
/* @0x2a695e eorle r2, sp, r0, lsl #22 */
/* @0x2a6962 eorle r2, sp, r0, lsl #26 */
/* @0x2a6966 eorle r2, sp, r0, lsl #18 */
/* @0x2a696a andsvs r6, r6, r6, lsr #16 */
/* @0x2a696e andsvs r6, r10, r2, ror #16 */
/* @0x2a6972 eorvs r7, r11, r3, lsr #28 */
/* @0x2a6976 andvs r7, r11, r3, ror #28 */
/* @0x2a697a svceq #0xf1b8 */
/* @0x2a697e cdpvc p0, #0xa, c13, c3, c2, #0x0 */
/* @0x2a6982 andlo pc, r0, r8, asr #17 */
/* @0x2a6986 cdpvc p1, #0xe, c11, c3, c15, #0x0 */
/* @0x2a698a .word 0xf1bc603b */
/* @0x2a698e andle r0, r2, r0, lsl #30 */
/* @0x2a6992 .word 0xf8cc7f23 */
/* @0x2a6996 cdpvc p0, #0x6, c3, c2, c0, #0x0 */
/* @0x2a699a andls r7, r0, #560 */
/* @0x2a699e andls r7, r1, #34, #30 */
/* @0x2a69a2 andls r7, r2, #2592 */
/* @0x2a69a6 andls r7, r3, #3616 */
/* @0x2a69aa muleq r6, r4, r8 */
/* @0x2a69ae blx 0x2a49b4 <_Z16_zip_name_locateP3zipPKciP9zip_error+0x10> */
/* @0x2a69b2 and r2, r8, r1 */
/* @0x2a69b6 and r4, r6, r0, lsr #12 */
/* @0x2a69ba and r4, r4, r0, lsl r6 */
/* @0x2a69be and r4, r2, r8, lsl r6 */
/* @0x2a69c2 and r4, r0, r8, lsr #12 */
/* @0x2a69c6 andlt r4, r4, r8, lsl #12 */
/* @0x2a69ca ldrhhi lr, [r0, #141]! */
/* @0x2a69ce .word 0x9c02b510 */
/* @0x2a69d2 orrlt r11, r1, r0, asr #3 */
/* @0x2a69d6 .word 0xf4106888 */
/* @0x2a69da andsle r7, r3, r0, lsl #1 */
/* @0x2a69de cmnlt r3, r10, ror #2 */
/* @0x2a69e2 mcrvs p1, #0x2, r11, c8, c12, #0x3 */
/* @0x2a69e6 vst4.8 {d22, d23, d24, d25}, [pc:64], r0 */
/* @0x2a69ea cdpvs p0, #0x8, c7, c10, c0, #0x4 */
/* @0x2a69ee .word 0xf891601a */
/* @0x2a69f2 eorvs r3, r3, r12, rrx */
/* @0x2a69f6 .word 0x4608bd10 */
/* @0x2a69fa sadd16mi r11, r0, r0 */
/* @0x2a69fe sadd16mi r11, r8, r0 */
/* @0x2a6a02 qadd16mi r11, r0, r0 */
/* @0x2a6a06 ldrblt r11, [r0, #0xd10]! */

/* ── FUNC 0x2a693f · png_get_IHDR · size=144 · insn=0 */

/* ── FUNC 0x2a69cf · png_get_oFFs · size=58 · insn=0 */

/* ── FUNC 0x2a6a08 · anon_2a6a08 · size=100 · insn=25 */
/* @0x2a6a08 svcls #0x5b5f0 */
/* @0x2a6a0c stcls p14, c9, [r7, #-24] */
/* @0x2a6a10 .word 0xf8dd9c08 */
/* @0x2a6a14 teqlt r8, #36 */
/* @0x2a6a18 stmvs r8, {r0, r3, r5, r8, r9, r12, sp, pc} */
/* @0x2a6a1c addvs pc, r0, r0, lsl r4 */
/* @0x2a6a20 movwlt sp, #0x2022 */
/* @0x2a6a24 ldrshlt r11, [r7, #27]! */
/* @0x2a6a28 mvnlt r11, lr, ror #3 */
/* @0x2a6a2c .word 0xf1bcb1dc */
/* @0x2a6a30 andsle r0, r8, r0, lsl #30 */
/* @0x2a6a34 .word 0x00a0f8d1 */
/* @0x2a6a38 vst4.8 {d22, d23, d24, d25}, [pc:64], r0 */
/* @0x2a6a3c .word 0xf8d16080 */
/* @0x2a6a40 andsvs r2, r10, r4, lsr #1 */
/* @0x2a6a44 .word 0x30a8f8d1 */
/* @0x2a6a48 .word 0xf891603b */
/* @0x2a6a4c ldrhtvs r3, [r3], -r4 */
/* @0x2a6a50 umlalslo pc, r5, r1, r8 */
/* @0x2a6a54 .word 0xf8d1602b */
/* @0x2a6a58 eorvs r3, r3, r12, lsr #1 */
/* @0x2a6a5c ldrsbtlo pc, [r0], r1 */
/* @0x2a6a60 andlo pc, r0, r12, asr #17 */
/* @0x2a6a64 strdhs r11, r12, [r0], -r0 */
/* @0x2a6a68 ldrlt r11, [r0, #-0xdf0] */

/* ── FUNC 0x2a6a09 · png_get_pCAL · size=98 · insn=0 */

/* ── FUNC 0x2a6a6a · anon_2a6a6a · size=52 · insn=13 */
/* @0x2a6a6a sadd16mi r11, r12, r0 */
/* @0x2a6a6e orrslt r11, r1, r0, lsr #3 */
/* @0x2a6a72 .word 0xf4106888 */
/* @0x2a6a76 andle r4, pc, r0, lsl #1 */
/* @0x2a6a7a smullslo pc, r12, r1, r8 */
/* @0x2a6a7e addmi pc, r0, pc, asr #8 */
/* @0x2a6a82 ldmib r1, {r0, r1, r4, sp, lr} ^ */
/* @0x2a6a86 stmib r4, {r3, r4, r5, r8, r9, sp} ^ */
/* @0x2a6a8a ldmib r1, {r8, r9, sp} ^ */
/* @0x2a6a8e stmdbls r2, {r1, r3, r4, r5, r8, r9, sp} */
/* @0x2a6a92 movwhs lr, #0x9c1 */
/* @0x2a6a96 .word 0x4608bd10 */
/* @0x2a6a9a ldrlt r11, [r0, #-0xd10] */

/* ── FUNC 0x2a6a6b · png_get_sCAL · size=50 · insn=0 */

/* ── FUNC 0x2a6a9c · anon_2a6a9c · size=88 · insn=22 */
/* @0x2a6a9c .word 0x9c02b510 */
/* @0x2a6aa0 orrslt r11, r9, r8, lsr #3 */
/* @0x2a6aa4 .word 0xf0106888 */
/* @0x2a6aa8 andsle r0, r0, r0, lsl #1 */
/* @0x2a6aac svcvs #0x8b11a */
/* @0x2a6ab0 addhs r6, r0, r0, lsl r0 */
/* @0x2a6ab4 ldrmi lr, [r0], -r0 */
/* @0x2a6ab8 svcvs #0x4ab113 */
/* @0x2a6abc andsvs r2, r10, r0, lsl #1 */
/* @0x2a6ac0 .word 0xf891b12c */
/* @0x2a6ac4 addhs r3, r0, r8, ror r0 */
/* @0x2a6ac8 ldclt p0, c6, [r0, #-140] */
/* @0x2a6acc ldclt p6, c4, [r0, #-32] */
/* @0x2a6ad0 cmplt r1, r0, ror r1 */
/* @0x2a6ad4 .word 0xf0106888 */
/* @0x2a6ad8 andle r0, r9, r8 */
/* @0x2a6adc stmdbvs r8, {r1, r3, r4, r5, r8, r12, sp, pc} */
/* @0x2a6ae0 andhs r6, r8, r0, lsl r0 */
/* @0x2a6ae4 andsvs r8, r10, r10, lsl #21 */
/* @0x2a6ae8 .word 0x46084770 */
/* @0x2a6aec ssub16mi r4, r0, r0 */
/* @0x2a6af0 .word 0xb1604770 */

/* ── FUNC 0x2a6a9d · png_get_pHYs · size=52 · insn=0 */

/* ── FUNC 0x2a6ad1 · png_get_PLTE · size=34 · insn=0 */
