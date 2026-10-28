/* libyoyo.so 覆盖卡组 0257
 * 函数 0x2a8824..0x2abc0d，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a8824 · anon_2a8824 · size=780 · insn=195 */
/* @0x2a8824 ssub8mi r11, r5, r8 */
/* @0x2a8828 .word 0x4604461f */
/* @0x2a882c subsle r2, r5, r0, lsl #16 */
/* @0x2a8830 andle r2, r8, r2, lsl #18 */
/* @0x2a8834 andle r2, sp, r3, lsl #18 */
/* @0x2a8838 tstle r0, r1, lsl #18 */
/* @0x2a883c ldrsblo pc, [r4, -r0]! */
/* @0x2a8840 biceq pc, r0, #1124073472 */
/* @0x2a8844 .word 0xf8d0e003 */
/* @0x2a8848 vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2a884c .word 0xf8c40380 */
/* @0x2a8850 and r3, r8, r4, lsr r1 */
/* @0x2a8854 ldrsblo pc, [r4, -r0]! */
/* @0x2a8858 movwne pc, #0x443 */
/* @0x2a885c stmdbmi r2!, {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a8860 .word 0xf7fd4479 */
/* @0x2a8864 .word 0xf894fde3 */
/* @0x2a8868 blhs 0x375018 <_ZTS13C_UTF16String+0xc0c4> */
/* @0x2a886c .word 0xf8d4d105 */
/* @0x2a8870 vst4.8 {d19, d21, d23, d25}, [r3:256], r4 */
/* @0x2a8874 .word 0xf8c45380 */
/* @0x2a8878 stchs p1, c3, [r0, #-208] */
/* @0x2a887c svchs #0xdb1c */
/* @0x2a8880 .word 0x4e17db1a */
/* @0x2a8884 adcsmi r1, r3, #3850240 */
/* @0x2a8888 .word 0x03e8dc11 */
/* @0x2a888c .word 0xf0704631 */
/* @0x2a8890 .word 0x4631e9dc */
/* @0x2a8894 .word 0x03f8b285 */
/* @0x2a8898 ldmib r6, {r4, r5, r6, r12, sp, lr, pc} ^ */
/* @0x2a889c .word 0xf8a44b11 */
/* @0x2a88a0 addlt r5, r0, #1610612749 */
/* @0x2a88a4 sbcseq pc, r8, #164, #16 */
/* @0x2a88a8 blne 0x196f11c <b2_toiTime+0x1215c78> */
/* @0x2a88ac stmdbmi pc, {r2, r4, sp, lr, pc} */
/* @0x2a88b0 ldrbtmi r4, [r9], #-1568 */
/* @0x2a88b4 ldc2l p7, c15, [lr, #1012] */
/* @0x2a88b8 sbcslo pc, r6, #180, #16 */
/* @0x2a88bc .word 0xf8d4b973 */
/* @0x2a88c0 ldmdblt r11, {r3, r4, r6, r7, r9, r12, sp} ^ */
/* @0x2a88c4 teqlo r8, #68157440 */
/* @0x2a88c8 sbcslo pc, r6, #164, #16 */
/* @0x2a88cc orrlo pc, r10, #72351744 */
/* @0x2a88d0 sbcslo pc, r8, #164, #16 */
/* @0x2a88d4 teqne lr, #64, #12 */
/* @0x2a88d8 sbcslo pc, r10, #164, #16 */
/* @0x2a88dc svclt #0xbdf8 */
/* @0x2a88e0 andeq r8, r1, r0, lsr #13 */
/* @0x2a88e4 .word 0xffff8000 */
/* @0x2a88e8 andeq r4, lr, r8, lsl #3 */
/* @0x2a88ec andeq r4, lr, r2, ror #2 */
/* @0x2a88f0 mcrr p5, #0x7, r11, r3, c0 */
/* @0x2a88f4 vldr d2, [sp, #88] */
/* @0x2a88f8 strmi r7, [sp], -r4, lsl #22 */
/* @0x2a88fc stmdahs r0, {r2, r9, r10, lr} */
/* @0x2a8900 ldc p0, c13, [pc, #256] */
/* @0x2a8904 .word 0xeeb44b21 */
/* @0x2a8908 vsqrt.f64 d22, d4 */
/* @0x2a890c .word 0xdc10fa10 */
/* @0x2a8910 blpl 0xaa3f94 <b2_toiTime+0x34aaf0> */
/* @0x2a8914 blvs 0xff4243ec <b2_toiTime+0xfffffffffeccaf48> */
/* @0x2a8918 blx 0x6e44e4 <g_SWFvertbuff+0x1141c> */
/* @0x2a891c cdp p4, #0xb, c13, c4, c9, #0x0 */
/* @0x2a8920 vsqrt.f64 d23, d4 */
/* @0x2a8924 .word 0xdc04fa10 */
/* @0x2a8928 blvc 0xff424400 <b2_toiTime+0xfffffffffeccaf5c> */
/* @0x2a892c blx 0x6e44f8 <g_SWFvertbuff+0x11430> */
/* @0x2a8930 ldmdbmi r11, {r3, r8, r10, r12, lr, pc} */
/* @0x2a8934 ldrbtmi r4, [r9], #-1568 */
/* @0x2a8938 ldc2 p7, c15, [r12, #1012] */
/* @0x2a893c .word 0x33fff04f */
/* @0x2a8940 ands r4, r9, r10, lsl r6 */
/* @0x2a8944 blpl 0x2e4424 <_ZN11b2GearJoint23InitVelocityConstraintsERK12b2SolverData+0x3c0> */
/* @0x2a8948 blmi 0x7a3fcc <b2_toiTime+0x4ab28> */
/* @0x2a894c blvs 0xff464430 <b2_toiTime+0xfffffffffed0af8c> */
/* @0x2a8950 blvc 0xff4a4434 <b2_toiTime+0xfffffffffed4af90> */
/* @0x2a8954 bvs 0xff464438 <b2_toiTime+0xfffffffffed0af94> */
/* @0x2a8958 bvc 0xff4a443c <b2_toiTime+0xfffffffffed4af98> */
/* @0x2a895c bllo 0x1424424 <b2_toiTime+0xccaf80> */
/* @0x2a8960 blpl 0x3e4184 <error_g0017+0x3ce28> */
/* @0x2a8964 bllo 0x3e4184 <error_g0017+0x3ce28> */
/* @0x2a8968 blvc 0xff424564 <b2_toiTime+0xfffffffffeccb0c0> */
/* @0x2a896c bllo 0xff3a4568 <b2_toiTime+0xfffffffffec4b0c4> */
/* @0x2a8970 blo 0xfe6e41d4 <b2_toiTime+0xfffffffffdf8ad30> */
/* @0x2a8974 bhs 0xfe6e41c8 <b2_toiTime+0xfffffffffdf8ad24> */
/* @0x2a8978 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2a897c ldrhtmi lr, [r0], #-141 */
/* @0x2a8980 svclt #0x50f7ff */
/* @0x2a8984 svclt #0xbd70 */
/* @0x2a8988 ldmhi r9!, {r0, r2, r7, r8, r9, r10, r12, sp, lr} */
/* @0x2a898c ldrhmi pc, [r4], #133 */
/* @0x2a8990 stmhi r3!, {r0, r4, r5, r6, r7, r11, sp, lr} ^ */
/* @0x2a8994 ldrhgt pc, [r4], #133 */
/* @0x2a8998 andeq r0, r0, r0 */
/* @0x2a899c rscsmi r6, r8, r0, lsl #20 */
/* @0x2a89a0 ldrdeq r4, r5, [lr], -lr */
/* @0x2a89a4 andhi pc, r0, pc, lsr #7 */
/* @0x2a89a8 .word 0xf8d0b138 */
/* @0x2a89ac .word 0xf8c03134 */
/* @0x2a89b0 vst4.8 {d17, d19, d21, d23}, [r3:64], r12 */
/* @0x2a89b4 .word 0xf8c01380 */
/* @0x2a89b8 .word 0x47703134 */
/* @0x2a89bc .word 0x4602b530 */
/* @0x2a89c0 ldrsbeq pc, [r4, -r0]! */
/* @0x2a89c4 strbeq r4, [r4], #1547 */
/* @0x2a89c8 mcrvc p5, #0x2, sp, c9, c7, #0x0 */
/* @0x2a89cc ldrhmi pc, [lr, #130] */
/* @0x2a89d0 mrsle r2, apsr */
/* @0x2a89d4 .word 0x2106b10c */
/* @0x2a89d8 .word 0x2102e000 */
/* @0x2a89dc and r7, r8, r9, asr r6 */
/* @0x2a89e0 orreq r11, r0, r4, lsr #2 */
/* @0x2a89e4 .word 0xf041bf44 */
/* @0x2a89e8 ldrbvc r0, [r9], -r4, lsl #2 */
/* @0x2a89ec stmdbhs r7, {r0, r3, r4, r9, r10, r11, r12, sp, lr} */
/* @0x2a89f0 .word 0x2108d801 */
/* @0x2a89f4 .word 0x21007619 */
/* @0x2a89f8 .word 0xf8d282d9 */
/* @0x2a89fc .word 0x060d1134 */
/* @0x2a8a00 cdpvc p5, #0x5, c13, c9, c15, #0x0 */
/* @0x2a8a04 ldrbtvc pc, [lr], #1282 */
/* @0x2a8a08 ldrbeq pc, [r10, #-0x103] */
/* @0x2a8a0c .word 0x0104f021 */
/* @0x2a8a10 qaddhs r7, r9, r0 */
/* @0x2a8a14 .word 0xcc0382d9 */
/* @0x2a8a18 subseq pc, r10, r3, asr #17 */
/* @0x2a8a1c stmdahi r1!, {r0, r3, r5, r6, sp, lr} */
/* @0x2a8a20 .word 0xf8d28129 */
/* @0x2a8a24 streq r1, [r12], #308 */
/* @0x2a8a28 .word 0xf8d2d506 */
/* @0x2a8a2c addsvs r1, r9, #32, #4 */
/* @0x2a8a30 rscne pc, r0, #13762560 */
/* @0x2a8a34 rscsne pc, r12, r3, asr #17 */
/* @0x2a8a38 ldrsbne pc, [r4, -r2]! */
/* @0x2a8a3c strle r0, [r4, #-0x548] */
/* @0x2a8a40 ldmdbhs r0, {r0, r3, r4, r9, r10, r11, r12, sp, lr} */
/* @0x2a8a44 .word 0x2108bf04 */
/* @0x2a8a48 .word 0xf8d27619 */
/* @0x2a8a4c strbeq r1, [r9], #-308 */
/* @0x2a8a50 cdpvc p5, #0x5, c13, c9, c3, #0x0 */
/* @0x2a8a54 .word 0x0102f041 */
/* @0x2a8a58 .word 0xf8d27659 */
/* @0x2a8a5c .word 0xf4111134 */
/* @0x2a8a60 andle r0, r3, r0, asr #31 */
/* @0x2a8a64 .word 0xf0217e59 */
/* @0x2a8a68 ldrbvc r0, [r9], -r2, lsl #2 */
/* @0x2a8a6c ldrsbne pc, [r4, -r2]! */
/* @0x2a8a70 svceq #0x40f011 */
/* @0x2a8a74 andle r7, r11, r9, lsl lr */
/* @0x2a8a78 .word 0xf0007e58 */
/* @0x2a8a7c stmdahs r2, {r0, r1, r3, r4, r5, r6, r7} */
/* @0x2a8a80 .word 0xf8d2d106 */
/* @0x2a8a84 ldrhlt r0, [r8, -r0] */
/* @0x2a8a88 svclt #0x42908 */
/* @0x2a8a8c ldrbvc r2, [r8], -r3 */
/* @0x2a8a90 ldrsbeq pc, [r4, -r2]! */
/* @0x2a8a94 strle r0, [r3, #-0x745] */
/* @0x2a8a98 svclt #0x9c2907 */
/* @0x2a8a9c ldrvc r2, [r9], -r8, lsl #2 */
/* @0x2a8aa0 stmdbhs r3, {r0, r3, r4, r6, r9, r10, r11, r12, sp, lr} */
/* @0x2a8aa4 andhs sp, r1, r1, lsl #2 */
/* @0x2a8aa8 streq lr, [r12, r2] */
/* @0x2a8aac strdhs sp, lr, [r3], -r11 */
/* @0x2a8ab0 .word 0xf8d27758 */
/* @0x2a8ab4 subeq r0, r0, #48, #2 */
/* @0x2a8ab8 .word 0xf021bf44 */
/* @0x2a8abc ldrbvc r0, [r9], -r4, lsl #2 */
/* @0x2a8ac0 smlsldeq r7, sp, r9, lr */
/* @0x2a8ac4 svcvc #0x58d502 */
/* @0x2a8ac8 ldrbvc r3, [r8, -r1] */
/* @0x2a8acc ldrsbeq pc, [r4, -r2]! */
/* @0x2a8ad0 strle r0, [r12, #-0x404] */
/* @0x2a8ad4 svceq #0xfdf011 */
/* @0x2a8ad8 svcvc #0x58d109 */
/* @0x2a8adc ldrbvc r3, [r8, -r1] */
/* @0x2a8ae0 ldrsbeq pc, [r4, -r2]! */
/* @0x2a8ae4 svclt #0x4401c0 */
/* @0x2a8ae8 .word 0x0104f041 */
/* @0x2a8aec .word 0xf8d27659 */
/* @0x2a8af0 sbceq r1, r9, #52, #2 */
/* @0x2a8af4 .word 0xf892d50b */
/* @0x2a8af8 cdpvc p1, #0x1, c1, c8, c8, #0x1 */
/* @0x2a8afc svclt #0x384288 */
/* @0x2a8b00 .word 0xf8927619 */
/* @0x2a8b04 svcvc #0x592129 */
/* @0x2a8b08 svclt #0x384291 */
/* @0x2a8b0c mrcvc p7, #0x0, r7, c9, c10, #0x2 */
/* @0x2a8b10 movtmi r7, #0xaf5a */
/* @0x2a8b14 sbcslt r6, r2, #1638400 */
/* @0x2a8b18 bhs 0x486988 <g_States+0xfc0> */
/* @0x2a8b1c ldmeq r2, {r1, r8, r11, r12, lr, pc} ^ */
/* @0x2a8b20 and r4, r2, r10, asr #6 */
/* @0x2a8b24 andlo r4, r7, #671088641 */
/* @0x2a8b28 ldrsbvs r0, [r10], #130 */
/* @0x2a8b2c bvc 0x1357ff4 <b2_toiTime+0xbfeb50> */

/* ── FUNC 0x2a8825 · png_set_rgb_to_gray_fixed · size=204 · insn=0 */

/* ── FUNC 0x2a88f1 · png_set_rgb_to_gray · size=180 · insn=0 */

/* ── FUNC 0x2a89a9 · png_set_read_user_transform_fn · size=20 · insn=0 */

/* ── FUNC 0x2a89bd · png_read_transform_info · size=370 · insn=0 */

/* ── FUNC 0x2a8b2e · anon_2a8b2e · size=508 · insn=127 */
/* @0x2a8b2e ldrblt r7, [r0, #-0xa42]! */
/* @0x2a8b32 ldmdale r12, {r0, r1, r2, r9, r11, sp} ^ */
/* @0x2a8b36 stmdavs r3, {r1, r9, r11, sp} */
/* @0x2a8b3a bhs 0x3dcbba <error_g0017+0x3585e> */
/* @0x2a8b3e bhs 0x31cc26 */
/* @0x2a8b42 cdpne p1, #0x5, c13, c13, c14, #0x2 */
/* @0x2a8b46 bl 0x2f02b6 <FT_Done_Memory+0x6642> */
/* @0x2a8b4a strtmi r0, [r9], #-1237 */
/* @0x2a8b4e bne 0xff5f9a9e <b2_toiTime+0xfffffffffeea05fa> */
/* @0x2a8b52 andeq pc, r7, #2 */
/* @0x2a8b56 suble r4, r3, r9, lsr #5 */
/* @0x2a8b5a bhs 0x486bfa <g_States+0x1232> */
/* @0x2a8b5e .word 0xf104bf08 */
/* @0x2a8b62 blx 0x1435f66 <b2_toiTime+0xcdcac2> */
/* @0x2a8b66 svclt #0x8f602 */
/* @0x2a8b6a .word 0xf0062200 */
/* @0x2a8b6e svclt #0x180601 */
/* @0x2a8b72 .word 0xf8013201 */
/* @0x2a8b76 strb r6, [sp, r1, lsl #18]! */
/* @0x2a8b7a mrcne p12, #0x2, r1, c13, c10, #0x6 */
/* @0x2a8b7e .word 0xf00243d2 */
/* @0x2a8b82 bl 0x2e9396 <FT_New_Face+0x2be> */
/* @0x2a8b86 strtmi r0, [r9], #-1173 */
/* @0x2a8b8a bne 0xff5e8cda <b2_toiTime+0xfffffffffee8f836> */
/* @0x2a8b8e eorle r4, r7, r9, lsr #5 */
/* @0x2a8b92 bhs 0x446c32 <g_RomDisk+0x4f412> */
/* @0x2a8b96 .word 0xf104bf08 */
/* @0x2a8b9a blx 0x1435f9e <b2_toiTime+0xcdcafa> */
/* @0x2a8b9e svclt #0x8f602 */
/* @0x2a8ba2 .word 0xf0062200 */
/* @0x2a8ba6 svclt #0x180603 */
/* @0x2a8baa .word 0xf8013202 */
/* @0x2a8bae strb r6, [sp, r1, lsl #18]! */
/* @0x2a8bb2 .word 0xf0131e5d */
/* @0x2a8bb6 svclt #0xc0f01 */
/* @0x2a8bba andhs r2, r4, #0, #4 */
/* @0x2a8bbe ldrbeq lr, [r5], #-2817 */
/* @0x2a8bc2 bne 0xff5f9c6e <b2_toiTime+0xfffffffffeea07ca> */
/* @0x2a8bc6 andle r4, r11, r9, lsr #5 */
/* @0x2a8bca tstmi r6, r6, lsr #16 */
/* @0x2a8bce streq pc, [pc], -r6 */
/* @0x2a8bd2 stmdbvs r1, {r0, r11, r12, sp, lr, pc} */
/* @0x2a8bd6 .word 0x3c01b112 */
/* @0x2a8bda ldrb r2, [r3, r0, lsl #4]! */
/* @0x2a8bde ldrb r2, [r1, r4, lsl #4]! */
/* @0x2a8be2 subvc r2, r2, #8, #4 */
/* @0x2a8be6 cmpmi r3, #532480 */
/* @0x2a8bea sbcvc r0, r1, #209 */
/* @0x2a8bee ldcllt p0, c6, [r0, #-268]! */
/* @0x2a8bf2 mvnsmi lr, sp, lsr #18 */
/* @0x2a8bf6 bvc 0x2fa42e <ps_hints_apply+0x902e> */
/* @0x2a8bfa .word 0xf0002903 */
/* @0x2a8bfe .word 0xf0118091 */
/* @0x2a8c02 stmdavs r6, {r1, r8, r9, r10, r11} */
/* @0x2a8c06 andle r7, r10, r3, asr #20 */
/* @0x2a8c0a blne 0x1a06c66 <b2_toiTime+0x12ad7c2> */
/* @0x2a8c0e ldmdavc r5, {r8, r10, r12, pc} ^ */
/* @0x2a8c12 strls r1, [r1, #-0xb5d] */
/* @0x2a8c16 blne 0x1a06e72 <b2_toiTime+0x12ad9ce> */
/* @0x2a8c1a strhs r9, [r3, #-0x502] */
/* @0x2a8c1e ldmvc r5, {r0, r1, sp, lr, pc} ^ */
/* @0x2a8c22 strls r1, [r0, #-0xb5d] */
/* @0x2a8c26 strbeq r2, [r9, -r1, lsl #10] */
/* @0x2a8c2a svcge #0x4d507 */
/* @0x2a8c2e bl 0x48707e <g_States+0x16b6> */
/* @0x2a8c32 strlo r0, [r1, #-0x185] */
/* @0x2a8c36 .word 0xf8411a9a */
/* @0x2a8c3a .word 0x21002c10 */
/* @0x2a8c3e strmi r4, [r8], r10, lsl #12 */
/* @0x2a8c42 ble 0x5396f2 <obj_numb_event+0x2782> */
/* @0x2a8c46 eorvc pc, r2, sp, asr r8 */
/* @0x2a8c4a svclt #0xd82f00 */
/* @0x2a8c4e eorhi pc, r2, sp, asr #16 */
/* @0x2a8c52 andeq pc, r1, #-2147483648 */
/* @0x2a8c56 smlabths r1, r8, pc, r11 */
/* @0x2a8c5a stmdbhs r0, {r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a8c5e blhs 0x3dcde6 <error_g0017+0x35a8a> */
/* @0x2a8c62 stmdale r4, {r1, r2, r4, r12, lr, pc} */
/* @0x2a8c66 cmple r11, r2, lsl #22 */
/* @0x2a8c6a strtmi r6, [r3], #-2115 */
/* @0x2a8c6e blhs 0x4e0c92 <SrcVerts+0x3dcd6> */
/* @0x2a8c72 blhs 0x6dccfe <g_SWFvertbuff+0x9c36> */
/* @0x2a8c76 blx 0x45d1d0 <g_RomDisk+0x659b0> */
/* @0x2a8c7a strhs pc, [r0], -r5, lsl #14 */
/* @0x2a8c7e addsmi lr, r12, #49 */
/* @0x2a8c82 stmdavc r2!, {r1, r2, r3, r6, r12, lr, pc} */
/* @0x2a8c86 .word 0xf0020852 */
/* @0x2a8c8a .word 0xf8040255 */
/* @0x2a8c8e ldrb r2, [r6, r1, lsl #22]! */
/* @0x2a8c92 mvnshs r9, r0, lsl #22 */
/* @0x2a8c96 tstmi r9, pc, lsl #4 */
/* @0x2a8c9a .word 0xf021411a */
/* @0x2a8c9e tstmi r1, #-1073741821 */
/* @0x2a8ca2 sbclt r6, r9, #4325376 */
/* @0x2a8ca6 addsmi r4, r4, #570425344 */
/* @0x2a8caa stmdavc r0!, {r1, r3, r4, r5, r12, lr, pc} */
/* @0x2a8cae andmi r4, r8, r8, lsl r1 */
/* @0x2a8cb2 bleq 0x326cca */
/* @0x2a8cb6 blx 0x462c9c <g_RomDisk+0x6b47c> */
/* @0x2a8cba strhs pc, [r0], -r5, lsl #14 */
/* @0x2a8cbe .word 0xd02f42be */
/* @0x2a8cc2 qasxmi r4, r9, r0 */
/* @0x2a8cc6 ldmda r4, {r4, r5, r6, r12, sp, lr, pc} */
/* @0x2a8cca .word 0xf814ab04 */
/* @0x2a8cce bl 0x388cee <_ZTS13C_UTF16String+0x1fd9a> */
/* @0x2a8cd2 .word 0xf8510181 */
/* @0x2a8cd6 blx 0x14b7d1e <b2_toiTime+0xd5e87a> */
/* @0x2a8cda .word 0xf804f803 */
/* @0x2a8cde strlo r8, [r1], -r6 */
/* @0x2a8ce2 adcsmi lr, lr, #236, #14 */
/* @0x2a8ce6 streq pc, [r2], #-260 */
/* @0x2a8cea .word 0xf814d01a */
/* @0x2a8cee ldrtmi r8, [r0], -r2, lsl #24 */
/* @0x2a8cf2 .word 0x3c01f814 */
/* @0x2a8cf6 strlo r4, [r1], -r9, lsr #12 */
/* @0x2a8cfa stmdahs r8, {r0, r1, r8, r9, r11, sp, lr, pc} */
/* @0x2a8cfe svc #0xf8f06f */
/* @0x2a8d02 blx 0xa9391a <b2_toiTime+0x33a476> */
/* @0x2a8d06 bl 0x3a6f2e <_ZTSPKDn+0x1766> */
/* @0x2a8d0a .word 0xf8510181 */
/* @0x2a8d0e blx 0x14b7d56 <b2_toiTime+0xd5e8b2> */
/* @0x2a8d12 .word 0xf804f303 */
/* @0x2a8d16 .word 0xf3c33c01 */
/* @0x2a8d1a .word 0xf8042207 */
/* @0x2a8d1e strb r2, [r0, r2, lsl #24]! */
/* @0x2a8d22 pop {r2, r12, sp, pc} */
/* @0x2a8d26 bvc 0x13894ee <b2_toiTime+0xc3004a> */

/* ── FUNC 0x2a8b2f · png_do_unpack · size=196 · insn=0 */

/* ── FUNC 0x2a8bf3 · png_do_unshift · size=310 · insn=0 */

/* ── FUNC 0x2a8d28 · anon_2a8d28 · size=276 · insn=69 */
/* @0x2a8d28 ldrlt r7, [r0, #-0xa43] */
/* @0x2a8d2c tstle r2, r0, lsl r11 */
/* @0x2a8d30 bvc 0xfe342d44 <b2_toiTime+0xfffffffffdbe98a0> */
/* @0x2a8d34 movwhs r4, #0x35a */
/* @0x2a8d38 mulle r4, r3, r2 */
/* @0x2a8d3c andsmi pc, r3, r1, lsl r8 */
/* @0x2a8d40 movwlo r5, #0x14cc */
/* @0x2a8d44 movwhs lr, #0x87f8 */
/* @0x2a8d48 bvc 0xfe38565c <b2_toiTime+0xfffffffffdc2c1b8> */
/* @0x2a8d4c sbcvc r0, r2, #218 */
/* @0x2a8d50 cmpmi r3, #131072 */
/* @0x2a8d54 ldclt p0, c6, [r0, #-268] */
/* @0x2a8d58 bvc 0x356220 */
/* @0x2a8d5c bhs 0x442d70 <g_RomDisk+0x4b550> */
/* @0x2a8d60 bvc 0x135d268 <b2_toiTime+0xc03dc4> */
/* @0x2a8d64 stmdavs r2, {r3, r9, r11, sp} ^ */
/* @0x2a8d68 .word 0xf04f4411 */
/* @0x2a8d6c tstle r4, r0, lsl #4 */
/* @0x2a8d70 mulsle r1, r10, r2 */
/* @0x2a8d74 .word 0x4c02f811 */
/* @0x2a8d78 .word 0xf8113201 */
/* @0x2a8d7c .word 0xf8010c01 */
/* @0x2a8d80 .word 0xf8114c01 */
/* @0x2a8d84 .word 0xf8014c03 */
/* @0x2a8d88 .word 0xf8114c02 */
/* @0x2a8d8c .word 0xf8014c04 */
/* @0x2a8d90 .word 0xf8014c03 */
/* @0x2a8d94 strb r0, [r11, r4, lsl #26]! */
/* @0x2a8d98 addsmi r11, r10, #48, #26 */
/* @0x2a8d9c .word 0xf811d021 */
/* @0x2a8da0 andlo r5, r1, #768 */
/* @0x2a8da4 .word 0x4c01f811 */
/* @0x2a8da8 .word 0x0c02f811 */
/* @0x2a8dac .word 0x5c01f801 */
/* @0x2a8db0 .word 0x5c04f811 */
/* @0x2a8db4 .word 0x5c02f801 */
/* @0x2a8db8 .word 0x5c05f811 */
/* @0x2a8dbc .word 0x5c03f801 */
/* @0x2a8dc0 .word 0x5c06f811 */
/* @0x2a8dc4 .word 0x5c04f801 */
/* @0x2a8dc8 .word 0x5c07f811 */
/* @0x2a8dcc .word 0x4c07f801 */
/* @0x2a8dd0 .word 0x5c05f801 */
/* @0x2a8dd4 .word 0x5c08f811 */
/* @0x2a8dd8 .word 0x5c06f801 */
/* @0x2a8ddc stceq p8, c15, [r8, #-4] */
/* @0x2a8de0 ldclt p7, c14, [r0, #-876]! */
/* @0x2a8de4 .word 0xd1272a04 */
/* @0x2a8de8 bhs 0x4c76f8 <SrcVerts+0x2473c> */
/* @0x2a8dec ldrmi r6, [r1], #-2114 */
/* @0x2a8df0 andeq pc, r0, #79 */
/* @0x2a8df4 addsmi sp, r10, #12, #2 */
/* @0x2a8df8 .word 0xf811d009 */
/* @0x2a8dfc andlo r0, r1, #256 */
/* @0x2a8e00 .word 0x4c02f811 */
/* @0x2a8e04 .word 0x4c01f801 */
/* @0x2a8e08 stceq p8, c15, [r2, #-4] */
/* @0x2a8e0c ldclt p7, c14, [r0, #-972]! */
/* @0x2a8e10 mulsle r1, r10, r2 */
/* @0x2a8e14 .word 0x5c03f811 */
/* @0x2a8e18 .word 0xf8113201 */
/* @0x2a8e1c .word 0xf8114c01 */
/* @0x2a8e20 .word 0xf8010c02 */
/* @0x2a8e24 .word 0xf8115c01 */
/* @0x2a8e28 .word 0xf8015c04 */
/* @0x2a8e2c .word 0xf8014c03 */
/* @0x2a8e30 .word 0xf8015c02 */
/* @0x2a8e34 strb r0, [r11, r4, lsl #26]! */
/* @0x2a8e38 bvc 0x358300 */

/* ── FUNC 0x2a8d29 · png_do_chop · size=48 · insn=0 */

/* ── FUNC 0x2a8d59 · png_do_read_swap_alpha · size=226 · insn=0 */

/* ── FUNC 0x2a8e3a · anon_2a8e3a · size=628 · insn=157 */
/* @0x2a8e3a stmdavs r3, {r1, r9, r11, r12, sp, lr} */
/* @0x2a8e3e tstle sp, r6, lsl #20 */
/* @0x2a8e42 bhs 0x4c7752 <SrcVerts+0x24796> */
/* @0x2a8e46 ldrmi r6, [r1], #-2114 */
/* @0x2a8e4a andeq pc, r0, #79 */
/* @0x2a8e4e addsmi sp, r10, #1073741826 */
/* @0x2a8e52 .word 0xf811d006 */
/* @0x2a8e56 andlo r0, r1, #256 */
/* @0x2a8e5a bicmi r3, r0, #4, #18 */
/* @0x2a8e5e ldrb r7, [r6, r8, asr #1]! */
/* @0x2a8e62 addsmi r4, r10, #112, #14 */
/* @0x2a8e66 .word 0xf811d009 */
/* @0x2a8e6a andlo r0, r1, #256 */
/* @0x2a8e6e bicmi r3, r0, #8, #18 */
/* @0x2a8e72 stmibvc r8, {r3, r6, r7, r8, r12, sp, lr} */
/* @0x2a8e76 orrvc r4, r8, r0, asr #7 */
/* @0x2a8e7a .word 0x4770e7f3 */
/* @0x2a8e7e tstle r12, r4, lsl #20 */
/* @0x2a8e82 bhs 0x4c7792 <SrcVerts+0x247d6> */
/* @0x2a8e86 ldrmi r6, [r1], #-2114 */
/* @0x2a8e8a andeq pc, r0, #79 */
/* @0x2a8e8e addsmi sp, r10, #1073741826 */
/* @0x2a8e92 .word 0xf811d006 */
/* @0x2a8e96 andlo r0, r1, #256 */
/* @0x2a8e9a bicmi r3, r0, #32768 */
/* @0x2a8e9e ldrb r7, [r6, r8, asr #32]! */
/* @0x2a8ea2 addsmi r4, r10, #112, #14 */
/* @0x2a8ea6 .word 0xf811d009 */
/* @0x2a8eaa andlo r0, r1, #256 */
/* @0x2a8eae bicmi r3, r0, #4, #18 */
/* @0x2a8eb2 stmvc r8, {r3, r6, r7, r12, sp, lr} */
/* @0x2a8eb6 addvc r4, r8, r0, asr #7 */
/* @0x2a8eba .word 0x4770e7f3 */
/* @0x2a8ebe .word 0xf3c2b5f0 */
/* @0x2a8ec2 bvc 0x4322e6 <g_RomDisk+0x3aac6> */
/* @0x2a8ec6 stmdavs r4, {r1, r4, r6, r7, r9, r12, sp, pc} */
/* @0x2a8eca cmple r8, r0, lsl #28 */
/* @0x2a8ece vmlshs.f32 s14, s16, s12 */
/* @0x2a8ed2 .word 0xf013d120 */
/* @0x2a8ed6 strtmi r0, [r1], #-3968 */
/* @0x2a8eda movweq lr, #0x4b01 */
/* @0x2a8ede strhs sp, [r1, #-0xa] */
/* @0x2a8ee2 .word 0xf80342a5 */
/* @0x2a8ee6 andle r2, pc, #256 */
/* @0x2a8eea stcvs p8, c15, [r1, #-68] */
/* @0x2a8eee .word 0xf8033501 */
/* @0x2a8ef2 ldrb r6, [r5, r2, lsl #26]! */
/* @0x2a8ef6 adcmi r1, r9, #13312 */
/* @0x2a8efa .word 0xf811d006 */
/* @0x2a8efe .word 0xf8036d01 */
/* @0x2a8f02 .word 0xf8036c01 */
/* @0x2a8f06 ldrb r2, [r6, r2, lsl #26]! */
/* @0x2a8f0a rsbeq r2, r4, r2, lsl #6 */
/* @0x2a8f0e tsths r0, #805306376 */
/* @0x2a8f12 adc r7, r1, r3, asr #5 */
/* @0x2a8f16 .word 0xf0402e10 */
/* @0x2a8f1a .word 0xf01380c7 */
/* @0x2a8f1e b 0x1669d26 <b2_toiTime+0xf10882> */
/* @0x2a8f22 ldrtmi r0, [r1], #-1604 */
/* @0x2a8f26 stmibne r11, {r0, r1, r4, r12, lr, pc} */
/* @0x2a8f2a adcmi r2, r6, #1048576 */
/* @0x2a8f2e .word 0x5c01f803 */
/* @0x2a8f32 .word 0x2c02f803 */
/* @0x2a8f36 .word 0xf811d209 */
/* @0x2a8f3a strlo r7, [r1], -r1, lsl #24 */
/* @0x2a8f3e .word 0x7c03f803 */
/* @0x2a8f42 stcvc p8, c15, [r2, #-68] */
/* @0x2a8f46 stcvc p8, c15, [r4, #-12] */
/* @0x2a8f4a movwhs lr, #0x27ef */
/* @0x2a8f4e strmi lr, [lr], #-78 */
/* @0x2a8f52 andle r4, sp, r3, lsr #5 */
/* @0x2a8f56 .word 0x7c01f811 */
/* @0x2a8f5a .word 0xf8063301 */
/* @0x2a8f5e .word 0xf8117c01 */
/* @0x2a8f62 .word 0xf8067d02 */
/* @0x2a8f66 .word 0xf8065c03 */
/* @0x2a8f6a .word 0xf8067c02 */
/* @0x2a8f6e strb r2, [pc, r4, lsl #26]! */
/* @0x2a8f72 addseq r2, r11, r2, lsl #4 */
/* @0x2a8f76 eorhs r7, r0, #536870920 */
/* @0x2a8f7a sbcvc r6, r2, #67 */
/* @0x2a8f7e mcrhs p13, #0x0, r11, c2, c0, #0x7 */
/* @0x2a8f82 addshi pc, r2, r0, asr #32 */
/* @0x2a8f86 vmlshs.f32 s14, s16, s12 */
/* @0x2a8f8a .word 0xf013d135 */
/* @0x2a8f8e .word 0xf04f0f80 */
/* @0x2a8f92 andsle r0, r5, r3, lsl #10 */
/* @0x2a8f96 .word 0x1104fb05 */
/* @0x2a8f9a stmdbne r11, {r0, r8, r10, sp} */
/* @0x2a8f9e .word 0xf80342a5 */
/* @0x2a8fa2 eorle r2, r2, #256 */
/* @0x2a8fa6 .word 0x6c01f811 */
/* @0x2a8faa .word 0xf8033501 */
/* @0x2a8fae .word 0xf8116c02 */
/* @0x2a8fb2 .word 0xf8036c02 */
/* @0x2a8fb6 .word 0xf8116c03 */
/* @0x2a8fba .word 0xf8036d03 */
/* @0x2a8fbe strb r6, [sp, r4, lsl #26]! */
/* @0x2a8fc2 strtmi r4, [r9], #-869 */
/* @0x2a8fc6 blne 0x15ef3fa <b2_toiTime+0xe95f56> */
/* @0x2a8fca andle r4, lr, r9, lsr #5 */
/* @0x2a8fce .word 0x6c01f811 */
/* @0x2a8fd2 .word 0x6c01f803 */
/* @0x2a8fd6 .word 0x6c02f811 */
/* @0x2a8fda .word 0x6c02f803 */
/* @0x2a8fde stcvs p8, c15, [r3, #-68] */
/* @0x2a8fe2 .word 0x6c03f803 */
/* @0x2a8fe6 stchs p8, c15, [r4, #-12] */
/* @0x2a8fea movwhs lr, #0x47ee */
/* @0x2a8fee adceq r7, r4, r3, lsl #5 */
/* @0x2a8ff2 sbcvc r2, r3, #32, #6 */
/* @0x2a8ff6 mrchs p0, #0x0, lr, c0, c0, #0x1 */
/* @0x2a8ffa smlsdhs r6, r6, r1, sp */
/* @0x2a8ffe pkhbteq pc, r0, r3 */
/* @0x2a9002 .word 0x1104fb07 */
/* @0x2a9006 movteq lr, #0x4a4f */
/* @0x2a900a eorle r4, r7, r11, lsl #8 */
/* @0x2a900e adcmi r2, r6, #1048576 */
/* @0x2a9012 .word 0x5c01f803 */
/* @0x2a9016 .word 0x2c02f803 */
/* @0x2a901a .word 0xf811d219 */
/* @0x2a901e strlo r7, [r1], -r1, lsl #24 */
/* @0x2a9022 .word 0x7c03f803 */
/* @0x2a9026 .word 0x7c02f811 */
/* @0x2a902a .word 0x7c04f803 */
/* @0x2a902e .word 0x7c03f811 */
/* @0x2a9032 .word 0x7c05f803 */
/* @0x2a9036 .word 0x7c04f811 */
/* @0x2a903a .word 0x7c06f803 */
/* @0x2a903e .word 0x7c05f811 */
/* @0x2a9042 .word 0x7c07f803 */
/* @0x2a9046 stcvc p8, c15, [r6, #-68] */
/* @0x2a904a stcvc p8, c15, [r8, #-12] */
/* @0x2a904e .word 0x00e4e7df */
/* @0x2a9052 addvc r2, r3, #4, #6 */
/* @0x2a9056 sbcvc r2, r3, #64, #6 */
/* @0x2a905a ldcllt p0, c6, [r0, #272]! */
/* @0x2a905e andsle r4, sp, r6, lsr #5 */
/* @0x2a9062 .word 0x7c01f811 */
/* @0x2a9066 .word 0xf8033601 */
/* @0x2a906a .word 0xf8117c01 */
/* @0x2a906e .word 0xf8037c02 */
/* @0x2a9072 .word 0xf8117c02 */
/* @0x2a9076 .word 0xf8037c03 */
/* @0x2a907a .word 0xf8117c03 */
/* @0x2a907e .word 0xf8037c04 */
/* @0x2a9082 .word 0xf8117c04 */
/* @0x2a9086 .word 0xf8037c05 */
/* @0x2a908a .word 0xf8117c05 */
/* @0x2a908e .word 0xf8037d06 */
/* @0x2a9092 .word 0xf8035c07 */
/* @0x2a9096 .word 0xf8037c06 */
/* @0x2a909a ldrb r2, [pc, r8, lsl #26] */
/* @0x2a909e rscseq r2, r6, r4, lsl #6 */
/* @0x2a90a2 movths r7, #0x283 */
/* @0x2a90a6 sbcvc r6, r3, #70 */
/* @0x2a90aa bvc 0x1358872 <b2_toiTime+0xbff3ce> */

/* ── FUNC 0x2a8e3b · png_do_read_invert_alpha · size=132 · insn=0 */

/* ── FUNC 0x2a8ebf · png_do_read_filler · size=494 · insn=0 */

/* ── FUNC 0x2a90ac · anon_2a90ac · size=4140 · insn=1035 */
/* @0x2a90ac ldrblt r7, [r0, #-0xa42]! */
/* @0x2a90b0 stmdavs r3, {r0, r1, r2, r9, r11, sp} */
/* @0x2a90b4 bvc 0x3df6a0 <error_g0017+0x38344> */
/* @0x2a90b8 streq pc, [r2], -r4 */
/* @0x2a90bc ldrbeq pc, [pc, #0x6]! */
/* @0x2a90c0 cmnle r2, r0, lsl #28 */
/* @0x2a90c4 bhs 0x4d773c <SrcVerts+0x34780> */
/* @0x2a90c8 subeq lr, r3, #323584 */
/* @0x2a90cc cdpne p1, #0x5, c13, c12, c2, #0x1 */
/* @0x2a90d0 bicsmi r4, r12, #553648128 */
/* @0x2a90d4 strmi r4, [r12], #-1034 */
/* @0x2a90d8 adcmi r3, r1, #16384 */
/* @0x2a90dc stmdavc sp, {r0, r3, r12, lr, pc} ^ */
/* @0x2a90e0 sbcsvc r3, r5, r3, lsl #20 */
/* @0x2a90e4 addsvc r7, r5, sp, asr #16 */
/* @0x2a90e8 subsvc r7, r5, sp, asr #16 */
/* @0x2a90ec .word 0x2c04e7f4 */
/* @0x2a90f0 bvc 0xfe35d194 <b2_toiTime+0xfffffffffdc03cf0> */
/* @0x2a90f4 andlo r7, r2, #4096 */
/* @0x2a90f8 .word 0x0102f041 */
/* @0x2a90fc bvc 0x1305908 <b2_toiTime+0xbac464> */
/* @0x2a9100 addvc r11, r2, #536870925 */
/* @0x2a9104 sbcslt r4, r2, #671088641 */
/* @0x2a9108 bhs 0x485c18 <g_States+0x250> */
/* @0x2a910c ldmeq r2, {r0, r3, r6, r8, r11, r12, lr, pc} ^ */
/* @0x2a9110 sub r4, r9, r3, asr r3 */
/* @0x2a9114 ldrmi r3, [r1], #-2561 */
/* @0x2a9118 addeq lr, r3, #1024 */
/* @0x2a911c .word 0xf1a1429c */
/* @0x2a9120 rscle r0, r6, r2, lsl #2 */
/* @0x2a9124 strlo r7, [r1], #-2189 */
/* @0x2a9128 orrsvc r3, r5, r6, lsl #20 */
/* @0x2a912c cmpvc r5, sp, asr #16 */
/* @0x2a9130 tstvc r5, sp, lsl #17 */
/* @0x2a9134 sbcsvc r7, r5, sp, asr #16 */
/* @0x2a9138 addsvc r7, r5, sp, lsl #17 */
/* @0x2a913c subsvc r7, r5, sp, asr #16 */
/* @0x2a9140 bhs 0x4e30f8 <SrcVerts+0x4013c> */
/* @0x2a9144 subseq sp, r10, r2, lsl r1 */
/* @0x2a9148 strtmi r1, [r1], #-3668 */
/* @0x2a914c strmi r4, [r10], #-1580 */
/* @0x2a9150 smullle r4, lr, r12, r2 */
/* @0x2a9154 strlo r7, [r1], #-2061 */
/* @0x2a9158 blo 0x3b7568 <error_g0017+0x1020c> */
/* @0x2a915c stmdavc sp, {r0, r2, r4, r8, r12, sp, lr} ^ */
/* @0x2a9160 stmdavc sp, {r0, r2, r4, r6, r7, r12, sp, lr} ^ */
/* @0x2a9164 stmdavc sp, {r0, r2, r4, r7, r12, sp, lr} ^ */
/* @0x2a9168 ubfx r7, r5, #0x0, #0x12 */
/* @0x2a916c mrcne p0, #0x2, r0, c4, c10, #0x4 */
/* @0x2a9170 strtmi r4, [r12], -r1, lsr #8 */
/* @0x2a9174 addsmi r4, r12, #167772160 */
/* @0x2a9178 stmdavc sp, {r0, r1, r3, r4, r5, r7, r12, lr, pc} */
/* @0x2a917c stmdblo r4, {r0, r10, r12, sp} */
/* @0x2a9180 andsvc r3, r5, #8, #20 */
/* @0x2a9184 bicsvc r7, r5, sp, asr #17 */
/* @0x2a9188 orrsvc r7, r5, sp, lsl #17 */
/* @0x2a918c cmpvc r5, sp, asr #16 */
/* @0x2a9190 tstvc r5, sp, lsl #17 */
/* @0x2a9194 sbcsvc r7, r5, sp, asr #16 */
/* @0x2a9198 addsvc r7, r5, sp, lsl #17 */
/* @0x2a919c subsvc r7, r5, sp, asr #16 */
/* @0x2a91a0 cmpmi r3, #61079552 */
/* @0x2a91a4 ldmeq r11, {r0, r1, r2, r8, r9, r12, sp} ^ */
/* @0x2a91a8 ldcllt p0, c6, [r0, #-268]! */
/* @0x2a91ac push {r0, r1, r3, r9, r11, r12, sp, lr} */
/* @0x2a91b0 .word 0xf0034ff7 */
/* @0x2a91b4 stchs p5, c0, [r2, #-12] */
/* @0x2a91b8 .word 0xf040680c */
/* @0x2a91bc rfeia r0! */
/* @0x2a91c0 blhs 0x33dd20 */
/* @0x2a91c4 sbcsls pc, r8, #176, #16 */
/* @0x2a91c8 .word 0xf8cd9500 */
/* @0x2a91cc rfeia r0! */
/* @0x2a91d0 .word 0xf04052da */
/* @0x2a91d4 bvc 0x15895f8 <b2_toiTime+0xe30154> */
/* @0x2a91d8 cmple r12, r8, lsl #22 */
/* @0x2a91dc eorlo pc, r12, #208, #16 */
/* @0x2a91e0 beq 0x3a5324 <af_blue_strings+0x3000> */
/* @0x2a91e4 ssaxmi r1, r6, r7 */
/* @0x2a91e8 bhs 0x3e7e18 <error_g0017+0x40abc> */
/* @0x2a91ec movwhs r11, #0x90b */
/* @0x2a91f0 .word 0xf8d0e049 */
/* @0x2a91f4 blhs 0x2b5abc <jinit_input_controller+0x1bdc> */
/* @0x2a91f8 movwhs sp, #0xf9 */
/* @0x2a91fc .word 0xf0004556 */
/* @0x2a9200 .word 0xf8d080f2 */
/* @0x2a9204 .word 0xf8968230 */
/* @0x2a9208 .word 0xf8969001 */
/* @0x2a920c .word 0xf818c000 */
/* @0x2a9210 .word 0xf818b009 */
/* @0x2a9214 .word 0xf896c00c */
/* @0x2a9218 ldrbmi r9, [r12, #0x2] */
/* @0x2a921c andhi pc, r9, r8, lsl r8 */
/* @0x2a9220 strbmi sp, [r4, #0x101] */
/* @0x2a9224 blls 0x2dd274 <_ZN12b2EPCollider24ComputePolygonSeparationEv+0x50> */
/* @0x2a9228 .word 0x9004f8dd */
/* @0x2a922c .word 0xfc0cfb03 */
/* @0x2a9230 eorlo pc, r12, #208, #16 */
/* @0x2a9234 blgt 0x5a7e60 <g_SWFlineaavertbuff+0x54d98> */
/* @0x2a9238 stmdalt r8, {r0, r2, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2a923c ldmlo r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^ */
/* @0x2a9240 andlo pc, r8, r3, lsl r8 */
/* @0x2a9244 .word 0x3c01f807 */
/* @0x2a9248 and r2, r1, r1, lsl #6 */
/* @0x2a924c .word 0x9c01f807 */
/* @0x2a9250 strlo r3, [r1, -r3, lsl #12] */
/* @0x2a9254 .word 0xf896e7d2 */
/* @0x2a9258 .word 0xf896c000 */
/* @0x2a925c .word 0xf8969001 */
/* @0x2a9260 strbmi r8, [r12, #0x2] */
/* @0x2a9264 .word 0xf8ddd012 */
/* @0x2a9268 blls 0x315270 <FT_Bitmap_Embolden+0x42a> */
/* @0x2a926c .word 0xfc0cfb0b */
/* @0x2a9270 stmdbgt r9, {r0, r1, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2a9274 blx 0x3f1e82 */
/* @0x2a9278 b 0x168f2a0 <b2_toiTime+0xf35dfc> */
/* @0x2a927c .word 0xf80738d8 */
/* @0x2a9280 strlo r8, [r3], -r1, lsl #24 */
/* @0x2a9284 ldrbmi r3, [r6, #-0x701] */
/* @0x2a9288 adc sp, r12, r5, ror #3 */
/* @0x2a928c mvnle r4, r4, asr #11 */
/* @0x2a9290 .word 0xcc01f807 */
/* @0x2a9294 .word 0xf8d0e7f5 */
/* @0x2a9298 ldcne p2, c3, [r7], {60} */
/* @0x2a929c ldmdblt r3, {r1, r2, r4, r9, r10, lr} */
/* @0x2a92a0 ldrmi r2, [r12], r0, lsl #6 */
/* @0x2a92a4 .word 0xf8d0e099 */
/* @0x2a92a8 blhs 0x2b5b90 <jinit_input_controller+0x1cb0> */
/* @0x2a92ac movwhs sp, #0xf8 */
/* @0x2a92b0 .word 0x469846bc */
/* @0x2a92b4 .word 0xf00045a0 */
/* @0x2a92b8 .word 0xf8968096 */
/* @0x2a92bc ldmdavc r7!, {r12, pc} ^ */
/* @0x2a92c0 mulge r2, r6, r8 */
/* @0x2a92c4 strhs lr, [r9, -r7, asr #20] */
/* @0x2a92c8 mulls r3, r6, r8 */
/* @0x2a92cc mullt r4, r6, r8 */
/* @0x2a92d0 bhs 0x563bfc <g_SWFlineaavertbuff+0x10b34> */
/* @0x2a92d4 mulls r5, r6, r8 */
/* @0x2a92d8 b 0x14fa83c <b2_toiTime+0xda1398> */
/* @0x2a92dc mrsle r2, apsr */
/* @0x2a92e0 suble r4, r1, pc, asr #10 */
/* @0x2a92e4 blx 0xfe567c6a <b2_toiTime+0xfffffffffde0e7c6> */
/* @0x2a92e8 andslo pc, r12, #208, #16 */
/* @0x2a92ec bhs 0x963c30 <b2_toiTime+0x20a78c> */
/* @0x2a92f0 blx 0x3a7c26 <error_g0017+0x8ca> */
/* @0x2a92f4 eorslo pc, r12, #208, #16 */
/* @0x2a92f8 eorlt pc, r11, r3, asr r8 */
/* @0x2a92fc andslo pc, r12, #208, #16 */
/* @0x2a9300 andsge pc, r10, r11, lsr r8 */
/* @0x2a9304 blx 0xfe4a7c8a <b2_toiTime+0xfffffffffdd4e7e6> */
/* @0x2a9308 blx 0x156bc0c <b2_toiTime+0xe12768> */
/* @0x2a930c .word 0xf8d0fb03 */
/* @0x2a9310 .word 0xf853323c */
/* @0x2a9314 blls 0x3153c8 <FT_Bitmap_Embolden+0x582> */
/* @0x2a9318 andsvc pc, r7, r11, lsr r8 */
/* @0x2a931c .word 0xb000f8dd */
/* @0x2a9320 .word 0xf707fb0b */
/* @0x2a9324 bvc 0x567f38 <g_SWFlineaavertbuff+0x14e70> */
/* @0x2a9328 .word 0xf789fa5f */
/* @0x2a932c andslo pc, r12, #208, #16 */
/* @0x2a9330 ldmdbhs r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a9334 .word 0xf8d0411f */
/* @0x2a9338 .word 0xf853323c */
/* @0x2a933c .word 0xf8d07027 */
/* @0x2a9340 rfeda r7! */
/* @0x2a9344 blx 0x4053b2 <g_RomDisk+0xdb92> */
/* @0x2a9348 vmlsl.u8 q13, d10, d7 */
/* @0x2a934c blx 0x1a77e90 <b2_toiTime+0x131e9ec> */
/* @0x2a9350 b 0x16a7180 <b2_toiTime+0xf4dcdc> */
/* @0x2a9354 blx 0x1473bc4 <b2_toiTime+0xd1a720> */
/* @0x2a9358 .word 0xf8d0f903 */
/* @0x2a935c .word 0xf8577238 */
/* @0x2a9360 rfeda r3! */
/* @0x2a9364 movwhs r7, #0x101a */
/* @0x2a9368 ldmdbhs r7, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a936c .word 0x7c01f80c */
/* @0x2a9370 .word 0x9c02f80c */
/* @0x2a9374 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2a9378 .word 0xf10c3606 */
/* @0x2a937c ldr r0, [r9, r2, lsl #24] */
/* @0x2a9380 mulls r0, r6, r8 */
/* @0x2a9384 mulhi r1, r6, r8 */
/* @0x2a9388 mulge r2, r6, r8 */
/* @0x2a938c stmdahs r9, {r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a9390 mulls r3, r6, r8 */
/* @0x2a9394 mullt r4, r6, r8 */
/* @0x2a9398 stmdbhs r10, {r0, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a939c mulge r5, r6, r8 */
/* @0x2a93a0 b 0x153aac8 <b2_toiTime+0xde1624> */
/* @0x2a93a4 tstle r11, r11, lsl #20 */
/* @0x2a93a8 svclt #0x1845d0 */
/* @0x2a93ac .word 0xf8dd2301 */
/* @0x2a93b0 .word 0xf10cb000 */
/* @0x2a93b4 strlo r0, [r6], -r1, lsl #24 */
/* @0x2a93b8 blx 0x576fca <g_SWFlineaavertbuff+0x23f02> */
/* @0x2a93bc .word 0xf8ddf808 */
/* @0x2a93c0 blx 0x5953da <g_SWFlineaavertbuff+0x42312> */
/* @0x2a93c4 blx 0x40b3f2 <g_RomDisk+0x13bd2> */
/* @0x2a93c8 b 0x168bbf8 <b2_toiTime+0xf32754> */
/* @0x2a93cc .word 0xf8073ada */
/* @0x2a93d0 vmull.u8 q13, d10, d3 */
/* @0x2a93d4 .word 0xf8072807 */
/* @0x2a93d8 strmi r8, [r4, #0xc04]! */
/* @0x2a93dc ldrd sp, lr, [r2], -r0 */
/* @0x2a93e0 strb r2, [r4, r1, lsl #6]! */
/* @0x2a93e4 bvc 0x631fec <g_SWFaavertbuff+0x5ef24> */
/* @0x2a93e8 .word 0xf0402e06 */
/* @0x2a93ec bvc 0x1649820 <b2_toiTime+0xef037c> */
/* @0x2a93f0 .word 0xd1612e08 */
/* @0x2a93f4 eorvs pc, r12, #208, #16 */
/* @0x2a93f8 stmdblt lr, {r0, r1, r2, r4, r7, r10, r11, r12} */
/* @0x2a93fc subs r2, r6, r0 */
/* @0x2a9400 eorsvs pc, r0, #208, #16 */
/* @0x2a9404 rscsle r2, r9, r0, lsl #28 */
/* @0x2a9408 .word 0x0c00f04f */
/* @0x2a940c .word 0xf00045a4 */
/* @0x2a9410 .word 0xf8d080f9 */
/* @0x2a9414 ldmdavc r6, {r4, r5, r9, pc} */
/* @0x2a9418 mulls r1, r2, r8 */
/* @0x2a941c mulge r2, r2, r8 */
/* @0x2a9420 andvs pc, r6, r8, lsl r8 */
/* @0x2a9424 andls pc, r9, r8, lsl r8 */
/* @0x2a9428 andhi pc, r10, r8, lsl r8 */
/* @0x2a942c .word 0xd103454e */
/* @0x2a9430 svclt #0x184546 */
/* @0x2a9434 and r2, r0, r1, lsl #6 */
/* @0x2a9438 .word 0xf8dd2301 */
/* @0x2a943c .word 0xf10ca000 */
/* @0x2a9440 .word 0xf8dd0c01 */
/* @0x2a9444 andlo r11, r4, #4 */
/* @0x2a9448 blx 0x53705a <obj_numb_event+0xea> */
/* @0x2a944c blx 0x5a6c6e <g_SWFlineaavertbuff+0x53ba6> */
/* @0x2a9450 .word 0xf8d06909 */
/* @0x2a9454 blx 0x401d0e <g_RomDisk+0xa4ee> */
/* @0x2a9458 b 0x168f480 <b2_toiTime+0xf35fdc> */
/* @0x2a945c .word 0xf81638d8 */
/* @0x2a9460 .word 0xf8076008 */
/* @0x2a9464 .word 0xf8126c04 */
/* @0x2a9468 .word 0xf8076c01 */
/* @0x2a946c strb r6, [sp, r3, lsl #24] */
/* @0x2a9470 .word 0xf8927816 */
/* @0x2a9474 .word 0xf8928001 */
/* @0x2a9478 strbmi r12, [r6, #-0x2] */
/* @0x2a947c strbmi sp, [r6, #-0x11a]! */
/* @0x2a9480 movwhs r11, #0x1f18 */
/* @0x2a9484 .word 0x9000f8dd */
/* @0x2a9488 .word 0xf8dd3001 */
/* @0x2a948c andlo r10, r4, #4 */
/* @0x2a9490 blx 0x4f70a2 <SrcVerts+0x540e6> */
/* @0x2a9494 blx 0x566cb6 <g_SWFlineaavertbuff+0x13bee> */
/* @0x2a9498 blx 0x4034c2 <g_RomDisk+0xbca2> */
/* @0x2a949c b 0x168c4d4 <b2_toiTime+0xf33030> */
/* @0x2a94a0 .word 0xf8073cdc */
/* @0x2a94a4 .word 0xf812cc04 */
/* @0x2a94a8 .word 0xf8076c01 */
/* @0x2a94ac adcmi r6, r0, #768 */
/* @0x2a94b0 .word 0xe0a7d1de */
/* @0x2a94b4 strb r2, [r5, r1, lsl #6]! */
/* @0x2a94b8 eorsvs pc, r12, #208, #16 */
/* @0x2a94bc sadd16mi r11, r0, r6 */
/* @0x2a94c0 adds r2, r10, r0, lsl #12 */
/* @0x2a94c4 eorsvs pc, r8, #208, #16 */
/* @0x2a94c8 rscsle r2, r8, r0, lsl #28 */
/* @0x2a94cc .word 0xf04f4617 */
/* @0x2a94d0 strmi r0, [r4, #0xc00]! */
/* @0x2a94d4 addshi pc, r6, r0 */
/* @0x2a94d8 mulhi r0, r2, r8 */
/* @0x2a94dc .word 0xf8927856 */
/* @0x2a94e0 b 0x144d4f0 <b2_toiTime+0xcf404c> */
/* @0x2a94e4 .word 0xf8922608 */
/* @0x2a94e8 .word 0xf8928003 */
/* @0x2a94ec b 0x14d1504 <b2_toiTime+0xd78060> */
/* @0x2a94f0 .word 0xf8922909 */
/* @0x2a94f4 strbmi r8, [lr, #-0x5] */
/* @0x2a94f8 stmdahs r10, {r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a94fc strbmi sp, [r6, #-0x101] */
/* @0x2a9500 .word 0xf8d0d038 */
/* @0x2a9504 blx 0x1a75d7c <b2_toiTime+0x131c8d8> */
/* @0x2a9508 .word 0xf8d0fa89 */
/* @0x2a950c b 0x1695e04 <b2_toiTime+0xf3c960> */
/* @0x2a9510 blx 0x153397c <b2_toiTime+0xdda4d8> */
/* @0x2a9514 .word 0xf85bfa03 */
/* @0x2a9518 rfeda r10! */
/* @0x2a951c blx 0x1a8d588 <b2_toiTime+0x13340e4> */
/* @0x2a9520 beq 0x1067f40 <b2_toiTime+0x90ea9c> */
/* @0x2a9524 blx 0x3a7e54 <error_g0017+0xaf8> */
/* @0x2a9528 eorge pc, r10, r11, asr r8 */
/* @0x2a952c andsvs pc, r6, r10, lsr r8 */
/* @0x2a9530 .word 0xa000f8dd */
/* @0x2a9534 .word 0xf606fb0a */
/* @0x2a9538 .word 0xa004f8dd */
/* @0x2a953c stmdbvs r9, {r1, r3, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2a9540 .word 0xf688fa5f */
/* @0x2a9544 ldmdahs r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a9548 .word 0xf85b411e */
/* @0x2a954c rfeda r6! */
/* @0x2a9550 blx 0x4015ba <g_RomDisk+0x9d9a> */
/* @0x2a9554 .word 0xf3c99906 */
/* @0x2a9558 blx 0x1a77c9c <b2_toiTime+0x131e7f8> */
/* @0x2a955c b 0x16a6f88 <b2_toiTime+0xf4dae4> */
/* @0x2a9560 blx 0x14339cc <b2_toiTime+0xcda528> */
/* @0x2a9564 .word 0xf8d0f303 */
/* @0x2a9568 .word 0xf8566238 */
/* @0x2a956c rfeda r3! */
/* @0x2a9570 movwhs r6, #0x1019 */
/* @0x2a9574 b 0x1685774 <b2_toiTime+0xf2c2d0> */
/* @0x2a9578 .word 0xf8872816 */
/* @0x2a957c .word 0xf10c8000 */
/* @0x2a9580 ldmibvc r6, {r0, r10, r11} */
/* @0x2a9584 andlo r3, r8, #4, #14 */
/* @0x2a9588 .word 0x6c02f807 */
/* @0x2a958c .word 0x6c01f812 */
/* @0x2a9590 .word 0x6c01f807 */
/* @0x2a9594 .word 0xf892e79d */
/* @0x2a9598 ldmdavc r7, {lr, pc} ^ */
/* @0x2a959c mulhi r2, r2, r8 */
/* @0x2a95a0 strhs lr, [r12, -r7, asr #20] */
/* @0x2a95a4 mulgt r3, r2, r8 */
/* @0x2a95a8 mulls r4, r2, r8 */
/* @0x2a95ac stmdahs r8, {r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a95b0 mulgt r5, r2, r8 */
/* @0x2a95b4 b 0x15baad8 <b2_toiTime+0xe61634> */
/* @0x2a95b8 .word 0xd1212c09 */
/* @0x2a95bc svclt #0x184567 */
/* @0x2a95c0 .word 0xf8dd2301 */
/* @0x2a95c4 strlo r11, [r1], -r0 */
/* @0x2a95c8 .word 0x9004f8dd */
/* @0x2a95cc andlo r3, r4, r8, lsl #4 */
/* @0x2a95d0 .word 0xf707fb0b */
/* @0x2a95d4 strvc pc, [r8, -r9, lsl #22] */
/* @0x2a95d8 strvc pc, [r12, -r5, lsl #22] */
/* @0x2a95dc .word 0xf8000bff */
/* @0x2a95e0 .word 0xf3c77c03 */
/* @0x2a95e4 .word 0xf8002c07 */
/* @0x2a95e8 .word 0xf812cc04 */
/* @0x2a95ec .word 0xf8007c02 */
/* @0x2a95f0 .word 0xf8127c02 */
/* @0x2a95f4 .word 0xf8007c01 */
/* @0x2a95f8 adcmi r7, r6, #256 */
/* @0x2a95fc and sp, r1, r11, asr #3 */
/* @0x2a9600 ldrb r2, [lr, r1, lsl #6] */
/* @0x2a9604 bvc 0x4c8034 <SrcVerts+0x25078> */
/* @0x2a9608 .word 0xf0203a02 */
/* @0x2a960c andvc r0, r8, #2 */
/* @0x2a9610 sbcslt r7, r2, #72, #20 */
/* @0x2a9614 movtmi r7, #0x228a */
/* @0x2a9618 sbcvc r11, r10, #536870925 */
/* @0x2a961c stmdble r2, {r0, r1, r2, r9, r11, sp} */
/* @0x2a9620 cmpmi r4, #13762560 */
/* @0x2a9624 cmpmi r4, #2 */
/* @0x2a9628 stmeq r4!, {r0, r1, r2, r10, r12, sp} ^ */
/* @0x2a962c and r6, r0, r12, asr #32 */
/* @0x2a9630 ldrmi r2, [r8], -r0, lsl #6 */
/* @0x2a9634 pop {r0, r1, r12, sp, pc} */
/* @0x2a9638 strdeq r8, r9, [r0], -r0 */
/* @0x2a963c bicslt r11, r9, r0, lsr r5 */
/* @0x2a9640 stmdahs r7, {r0, r11, r12, sp} */
/* @0x2a9644 blmi 0x61f664 <g_SWFaavertbuff+0x4c59c> */
/* @0x2a9648 rfedb r3! */
/* @0x2a964c ldrmi r5, [r8], #-16 */
/* @0x2a9650 and r7, r1, r0, lsl #24 */
/* @0x2a9654 strmi r2, [r5], -r0 */
/* @0x2a9658 ldrmi r2, [r10], -r0, lsl #6 */
/* @0x2a965c .word 0xf10142aa */
/* @0x2a9660 ble 0x4e9a74 <SrcVerts+0x46ab8> */
/* @0x2a9664 andlo r11, r1, #220, #4 */
/* @0x2a9668 .word 0x4c03f801 */
/* @0x2a966c .word 0xf8014403 */
/* @0x2a9670 .word 0xf8014c02 */
/* @0x2a9674 ldrb r4, [r1, r1, lsl #24]! */
/* @0x2a9678 svclt #0xbd30 */
/* @0x2a967c andeq r6, lr, r4, ror #6 */
/* @0x2a9680 svcmi #0xf0e92d */
/* @0x2a9684 andls r11, r3, r7, lsl #1 */
/* @0x2a9688 mrcls p12, #0x0, r9, c3, c1, #0x0 */
/* @0x2a968c ldrsbge pc, [r4], #-141 */
/* @0x2a9690 ldrsbls pc, [r8], #-141 */
/* @0x2a9694 ldrsblt pc, [r12], #-141 */
/* @0x2a9698 blhs 0x2c36a0 <_Z16b2GetPointStatesP12b2PointStateS0_PK10b2ManifoldS3_+0x3c> */
/* @0x2a969c ldrhi pc, [r8, #-0x0] */
/* @0x2a96a0 bvc 0x12112b4 <b2_toiTime+0xab7e10> */
/* @0x2a96a4 strle r0, [r2, #-0x76f] */
/* @0x2a96a8 .word 0xf0002a00 */
/* @0x2a96ac stchs p5, c8, [r6, #-68] */
/* @0x2a96b0 ldrbthi pc, [r5], #512 */
/* @0x2a96b4 .word 0xf015e8df */
/* @0x2a96b8 ldrbteq r0, [r3], #7 */
/* @0x2a96bc ldrbteq r0, [r3], #326 */
/* @0x2a96c0 ldrbteq r0, [r3], #561 */
/* @0x2a96c4 mcrls p3, #0x0, r0, c3, c3, #0x0 */
/* @0x2a96c8 vstrlo s14, [r1, #-468] */
/* @0x2a96cc vadd.f32 d2, d0, d15 */
/* @0x2a96d0 ldm pc, {r1, r2, r5, r6, r7, r10, pc} ^ */
/* @0x2a96d4 andseq pc, r0, r5, lsl r0 */
/* @0x2a96d8 strbteq r0, [r4], #48 */
/* @0x2a96dc strbteq r0, [r4], #139 */
/* @0x2a96e0 strbteq r0, [r4], #1252 */
/* @0x2a96e4 strbteq r0, [r4], #223 */
/* @0x2a96e8 strbteq r0, [r4], #1252 */
/* @0x2a96ec strbteq r0, [r4], #1252 */
/* @0x2a96f0 strbteq r0, [r4], #1252 */
/* @0x2a96f4 strhs r0, [r7], #-250 */
/* @0x2a96f8 .word 0xf6472500 */
/* @0x2a96fc addmi r7, r5, #32512 */
/* @0x2a9700 strbhi pc, [sp], #0 */
/* @0x2a9704 ldmdbhi r6, {r0, r1, r2, r3, r11, r12, sp, lr} */
/* @0x2a9708 .word 0xf804fa47 */
/* @0x2a970c stmdaeq r1, {r3, r12, sp, lr, pc} */
/* @0x2a9710 strhle r4, [r9, -r0] */
/* @0x2a9714 streq pc, [r7], -r4, asr #3 */
/* @0x2a9718 .word 0xf606fa4c */
/* @0x2a971c andvc r4, lr, lr, lsr r0 */
/* @0x2a9720 adcmi r8, r7, pc, lsl r9 */
/* @0x2a9724 andvc r4, lr, lr, lsr r3 */
/* @0x2a9728 .word 0x3101b914 */
/* @0x2a972c and r2, r0, r7, lsl #8 */
/* @0x2a9730 strlo r3, [r1, #-0xc01] */
/* @0x2a9734 strhs lr, [r6, #-0x7e3] */
/* @0x2a9738 .word 0xf643b914 */
/* @0x2a973c sub r7, pc, pc, lsr r12 */
/* @0x2a9740 .word 0xf6432700 */
/* @0x2a9744 addmi r7, r7, #4128768 */
/* @0x2a9748 strthi pc, [r9], #0 */
/* @0x2a974c mulgt r0, r1, r8 */
/* @0x2a9750 strhls pc, [r8], -r2 */
/* @0x2a9754 .word 0xf605fa4c */
/* @0x2a9758 streq pc, [r3], -r6 */
/* @0x2a975c .word 0xf1c5454e */
/* @0x2a9760 .word 0xd10c0906 */
/* @0x2a9764 .word 0xf909fa48 */
/* @0x2a9768 .word 0x0c09ea0c */
/* @0x2a976c andgt pc, r0, r1, lsl #17 */
/* @0x2a9770 strhls pc, [r8], -r3 */
/* @0x2a9774 .word 0xf905fa09 */
/* @0x2a9778 .word 0x0c09ea4c */
/* @0x2a977c rscslt lr, r6, #17 */
/* @0x2a9780 .word 0xf909fa48 */
/* @0x2a9784 .word 0x0c09ea0c */
/* @0x2a9788 bne 0x4640cc <g_RomDisk+0x6c8ac> */
/* @0x2a978c beq 0xfe4640bc <b2_toiTime+0xfffffffffdd0ac18> */
/* @0x2a9790 beq 0x4640c0 <g_RomDisk+0x6c8a0> */
/* @0x2a9794 strne lr, [r6], r10, asr #20 */
/* @0x2a9798 ldmibeq r6!, {r1, r2, r5, r7, r8, r10, r11, r12, lr} */
/* @0x2a979c b 0x1439a5c <b2_toiTime+0xce05b8> */
/* @0x2a97a0 .word 0xf8810c0c */
/* @0x2a97a4 ldmdblt r5, {lr, pc} */
/* @0x2a97a8 strhs r3, [r6, #-0x101] */
/* @0x2a97ac stclo p0, c14, [r2, #-0] */
/* @0x2a97b0 strb r3, [r8, r1, lsl #14] */
/* @0x2a97b4 ldmdbhi r6, {r0, r1, r2, r3, r11, r12, sp, lr} */
/* @0x2a97b8 .word 0xf805fa47 */
/* @0x2a97bc stmdaeq r3, {r3, r12, sp, lr, pc} */
/* @0x2a97c0 strhle r4, [r9, -r0] */
/* @0x2a97c4 streq pc, [r6], -r5, asr #3 */
/* @0x2a97c8 .word 0xf606fa4c */
/* @0x2a97cc andvc r4, lr, lr, lsr r0 */
/* @0x2a97d0 adcmi r8, pc, pc, lsl r9 */
/* @0x2a97d4 andvc r4, lr, lr, lsr r3 */
/* @0x2a97d8 .word 0x3101b935 */
/* @0x2a97dc strlo r2, [r1], #-1286 */
/* @0x2a97e0 mvnle r4, r4, lsl #5 */
/* @0x2a97e4 mrrclt p0, #0x0, pc, r11, c0 */
/* @0x2a97e8 ldrb r3, [r8, r2, lsl #26]! */
/* @0x2a97ec ldmdblt r4, {r2, r8, r10, sp} */
/* @0x2a97f0 .word 0x7c0ff640 */
/* @0x2a97f4 strhs lr, [r0], -r8, asr #32 */
/* @0x2a97f8 stmdavc pc, {r6, r9, r10, r12, sp, lr, pc} */
/* @0x2a97fc .word 0xf0004286 */
/* @0x2a9800 stmdavc pc, {r1, r2, r3, r6, r10, pc} */
/* @0x2a9804 strhls pc, [r8], -r2 */
/* @0x2a9808 .word 0xfc05fa47 */
/* @0x2a980c .word 0x0c0ff00c */
/* @0x2a9810 .word 0xf1c545cc */
/* @0x2a9814 mrsle r0, apsr */
/* @0x2a9818 .word 0xf909fa48 */
/* @0x2a981c streq lr, [r9, -r7, lsl #20] */
/* @0x2a9820 rfeia r3! */
/* @0x2a9824 blx 0x50d84c <SrcVerts+0x6a890> */
/* @0x2a9828 b 0x14a7c44 <b2_toiTime+0xd4e7a0> */
/* @0x2a982c and r0, sp, r9, lsl #14 */
/* @0x2a9830 .word 0x1c0cea4c */
/* @0x2a9834 .word 0xf909fa48 */
/* @0x2a9838 streq lr, [r9, -r7, lsl #20] */
/* @0x2a983c andgt pc, r12, r4, lsl r8 */
/* @0x2a9840 .word 0x1c1cea4f */
/* @0x2a9844 .word 0xfc05fa0c */
/* @0x2a9848 streq lr, [r7, -r12, asr #20] */
/* @0x2a984c ldmdblt r5, {r0, r1, r2, r3, r12, sp, lr} */
/* @0x2a9850 strhs r3, [r4, #-0x101] */
/* @0x2a9854 stclo p0, c14, [r4, #-0] */
/* @0x2a9858 strb r3, [pc, r1, lsl #12] */
/* @0x2a985c ldmdbhi r6, {r0, r1, r2, r3, r11, r12, sp, lr} */
/* @0x2a9860 .word 0xf805fa47 */
/* @0x2a9864 stmdaeq pc, {r3, r12, sp, lr, pc} */
/* @0x2a9868 strhle r4, [r9, -r0] */
/* @0x2a986c streq pc, [r4], -r5, asr #3 */
/* @0x2a9870 .word 0xf606fa4c */
/* @0x2a9874 andvc r4, lr, lr, lsr r0 */
/* @0x2a9878 adcmi r8, pc, pc, lsl r9 */
/* @0x2a987c andvc r4, lr, lr, lsr r3 */
/* @0x2a9880 .word 0x3101b935 */
/* @0x2a9884 strlo r2, [r1], #-1284 */
/* @0x2a9888 mvnle r4, r4, lsl #5 */
/* @0x2a988c .word 0xbc07f000 */
/* @0x2a9890 ldrb r3, [r8, r4, lsl #26]! */
/* @0x2a9894 .word 0xb164180d */
/* @0x2a9898 .word 0xf00042a9 */
/* @0x2a989c .word 0xf8118400 */
/* @0x2a98a0 ldmdbhi r7, {r0, r8, r9, r11, sp, lr} */
/* @0x2a98a4 svclt #0xc42b7 */
/* @0x2a98a8 stcpl p9, c8, [r6, #120]! */
/* @0x2a98ac .word 0x6c01f801 */
/* @0x2a98b0 adcmi lr, r9, #63438848 */
/* @0x2a98b4 .word 0x83f3f000 */
/* @0x2a98b8 blmi 0x327904 */
/* @0x2a98bc adcmi r8, r6, #360448 */
/* @0x2a98c0 ldmdbhi r12, {r2, r8, r9, r10, r11, r12, sp, pc} */
/* @0x2a98c4 .word 0x4c01f801 */
/* @0x2a98c8 .word 0x9c14e7f3 */
/* @0x2a98cc .word 0xb3b43102 */
/* @0x2a98d0 addmi r2, r4, #0, #8 */
/* @0x2a98d4 .word 0x83e3f000 */
/* @0x2a98d8 .word 0x5c02f811 */
/* @0x2a98dc .word 0x6c01f811 */
/* @0x2a98e0 strhgt pc, [r8], -r2 */
/* @0x2a98e4 strhs lr, [r5, -r6, lsl #22] */
/* @0x2a98e8 ldrmi r11, [r12, #0x2bf]! */
/* @0x2a98ec ldmdbhi sp, {r0, r2, r8, r12, lr, pc} */
/* @0x2a98f0 .word 0xf8010a2d */
/* @0x2a98f4 ldmdbhi sp, {r1, r10, r11, r12, lr} */
/* @0x2a98f8 svcls #0x14e009 */
/* @0x2a98fc .word 0xf60bfa46 */
/* @0x2a9900 eorvs pc, r6, r7, asr r8 */
/* @0x2a9904 andspl pc, r5, r6, lsr r8 */
/* @0x2a9908 .word 0xf8010a2e */
/* @0x2a990c .word 0xf8016c02 */
/* @0x2a9910 strlo r5, [r1], #-3073 */
/* @0x2a9914 ldrb r3, [r12, r2, lsl #2] */
/* @0x2a9918 .word 0x6c02f811 */
/* @0x2a991c .word 0x5c01f811 */
/* @0x2a9920 strhs lr, [r6, #-0xb05] */
/* @0x2a9924 adclt r8, sp, #360448 */
/* @0x2a9928 smlatble r6, lr, r2, r4 */
/* @0x2a992c beq 0xe0bda8 <b2_toiTime+0x6b2904> */
/* @0x2a9930 .word 0x5c02f801 */
/* @0x2a9934 .word 0xf801891d */
/* @0x2a9938 strlo r5, [r1], #-3073 */
/* @0x2a993c addmi r3, r4, #-2147483648 */
/* @0x2a9940 .word 0xe3acd1ea */
/* @0x2a9944 bvc 0x2011158 <b2_toiTime+0x18b7cb4> */
/* @0x2a9948 mrsle r2, spsr */
/* @0x2a994c ldmdblt r4, {r0, r1, r9, r10, sp} */
/* @0x2a9950 strne pc, [r0], -r6, lsl #22 */
/* @0x2a9954 blx 0x461a1a <g_RomDisk+0x6a1fa> */
/* @0x2a9958 stclne p7, c1, [sp], {0} */
/* @0x2a995c .word 0xf00042b9 */
/* @0x2a9960 .word 0xf815839e */
/* @0x2a9964 rfeia r2! */
/* @0x2a9968 ldrmi r12, [r4, #0x2]! */
/* @0x2a996c .word 0xf891d112 */
/* @0x2a9970 rfeia r2! */
/* @0x2a9974 strbmi r12, [r0, #0x4]! */
/* @0x2a9978 .word 0xf891d10c */
/* @0x2a997c rfeia r2! */
/* @0x2a9980 strbmi r12, [r0, #0x6]! */
/* @0x2a9984 ldmdahi lr, {r1, r2, r8, r12, lr, pc} ^ */
/* @0x2a9988 .word 0x6c03f805 */
/* @0x2a998c umaalvc r8, lr, lr, r8 */
/* @0x2a9990 ldrd r8, r9, [r7], -lr */
/* @0x2a9994 .word 0xf8055da6 */
/* @0x2a9998 stmdavc lr, {r0, r1, r10, r11, sp, lr} ^ */
/* @0x2a999c subvc r5, lr, r6, lsr #27 */
/* @0x2a99a0 stcpl p8, c7, [r6, #568]! */
/* @0x2a99a4 strlo r7, [r3, #-0x8e] */
/* @0x2a99a8 ldrb r3, [r7, r3, lsl #2] */
/* @0x2a99ac ldmdahi r4, {r0, r2, r3, r11, r12, sp, lr} ^ */
/* @0x2a99b0 andle r4, r3, r5, lsr #5 */
/* @0x2a99b4 adcsmi r3, r1, #-1073741824 */
/* @0x2a99b8 cmn r0, #248, #2 */
/* @0x2a99bc ldmhi r4, {r0, r2, r3, r6, r11, r12, sp, lr} */
/* @0x2a99c0 mvnsle r4, r5, lsr #5 */
/* @0x2a99c4 ldmhi r4, {r0, r2, r3, r7, r11, r12, sp, lr} ^ */
/* @0x2a99c8 mvnsle r4, r5, lsr #5 */
/* @0x2a99cc andvc r8, r12, r12, asr r8 */
/* @0x2a99d0 umaalvc r8, r12, r12, r8 */
/* @0x2a99d4 ldrdvc r8, r9, [r12], r12 */
/* @0x2a99d8 svcls #0x14e7ec */
/* @0x2a99dc ldrtmi r11, [r12], -pc, lsl #18 */
/* @0x2a99e0 stcne p0, c14, [r12, #492] */
/* @0x2a99e4 addmi r2, r5, #0, #10 */
/* @0x2a99e8 cmphi r9, #0 */
/* @0x2a99ec .word 0x8c06f814 */
/* @0x2a99f0 mulge r2, r1, r8 */
/* @0x2a99f4 mulls r1, r1, r8 */
/* @0x2a99f8 bl 0x507e38 <SrcVerts+0x64e7c> */
/* @0x2a99fc .word 0xf8cd2708 */
/* @0x2a9a00 rfeia r2! */
/* @0x2a9a04 adcslt r10, pc, #2 */
/* @0x2a9a08 ldrmi r9, [r10, #0x604]! */
/* @0x2a9a0c mulgt r3, r1, r8 */
/* @0x2a9a10 .word 0xd125794e */
/* @0x2a9a14 bl 0x5d1624 <g_SWFlineaavertbuff+0x7e55c> */
/* @0x2a9a18 strls r2, [r1, -r7, lsl #14] */
/* @0x2a9a1c .word 0xa004f8dd */
/* @0x2a9a20 blx 0xa8bc84 <b2_toiTime+0x3327e0> */
/* @0x2a9a24 ldrbmi pc, [r7, #-0xa8a] */
/* @0x2a9a28 .word 0xf8ddd11a */
/* @0x2a9a2c ldmhi r7, {r4, sp, pc} ^ */
/* @0x2a9a30 bhs 0x564650 <g_SWFlineaavertbuff+0x11588> */
/* @0x2a9a34 andge pc, r4, sp, asr #17 */
/* @0x2a9a38 blx 0xfe5682bc <b2_toiTime+0xfffffffffde0ee18> */
/* @0x2a9a3c qaddle r4, r7, pc */
/* @0x2a9a40 beq 0x104bbc0 <b2_toiTime+0x8f271c> */
/* @0x2a9a44 .word 0x6c06f804 */
/* @0x2a9a48 subvc r8, lr, lr, asr r8 */
/* @0x2a9a4c beq 0x104bccc <b2_toiTime+0x8f2828> */
/* @0x2a9a50 ldmhi lr, {r1, r2, r3, r7, r12, sp, lr} */
/* @0x2a9a54 ldmhi lr, {r1, r2, r3, r6, r7, r12, sp, lr} ^ */
/* @0x2a9a58 .word 0x710e0a36 */
/* @0x2a9a5c .word 0xe02488de */
/* @0x2a9a60 blx 0x15116b8 <b2_toiTime+0xdb8214> */
/* @0x2a9a64 blx 0x15e7e98 <b2_toiTime+0xe8e9f4> */
/* @0x2a9a68 blx 0x1468a9c <b2_toiTime+0xd0f5f8> */
/* @0x2a9a6c .word 0xf857f60b */
/* @0x2a9a70 rfeda r9! */
/* @0x2a9a74 b 0x1689adc <b2_toiTime+0xf30638> */
/* @0x2a9a78 .word 0xf8042918 */
/* @0x2a9a7c .word 0xf8819c06 */
/* @0x2a9a80 .word 0xf8578001 */
/* @0x2a9a84 .word 0xf8ddc02c */
/* @0x2a9a88 rfeda r12! */
/* @0x2a9a8c .word 0xf8dd7018 */
/* @0x2a9a90 sbcvc r8, pc, r0, lsl r0 */
/* @0x2a9a94 .word 0x2c17ea4f */
/* @0x2a9a98 .word 0xf8819f14 */
/* @0x2a9a9c .word 0xf857c002 */
/* @0x2a9aa0 rfeda r6! */
/* @0x2a9aa4 beq 0x1081b0c <b2_toiTime+0x928668> */
/* @0x2a9aa8 mrsvc r7, spsr */
/* @0x2a9aac .word 0x31063501 */
/* @0x2a9ab0 ldr r3, [r8, r6, lsl #8] */
/* @0x2a9ab4 mulls r0, r1, r8 */
/* @0x2a9ab8 mulhi r1, r1, r8 */
/* @0x2a9abc mulgt r2, r1, r8 */
/* @0x2a9ac0 stmdahs r9, {r3, r8, r9, r11, sp, lr, pc} */
/* @0x2a9ac4 strhls pc, [r2], -r2 */
/* @0x2a9ac8 blx 0xa87e0c <b2_toiTime+0x32e968> */
/* @0x2a9acc stmdbvc lr, {r3, r7, r11, r12, sp, lr, pc} */
/* @0x2a9ad0 stmdbvc sp, {r0, r6, r7, r8, r10, lr} ^ */
/* @0x2a9ad4 strlo sp, [r1], #-4 */
/* @0x2a9ad8 addmi r3, r4, #-2147483647 */
/* @0x2a9adc sbcs sp, lr, #-2147483590 */
/* @0x2a9ae0 strhs lr, [r12, -r7, lsl #22] */
/* @0x2a9ae4 strhgt pc, [r4], -r2 */
/* @0x2a9ae8 ldrmi r11, [r12, #0x2bf]! */
/* @0x2a9aec bl 0x41e2c0 <g_RomDisk+0x26aa0> */
/* @0x2a9af0 ldmhi r6, {r1, r2, r8, r10, sp} ^ */
/* @0x2a9af4 adcmi r11, lr, #-805306358 */
/* @0x2a9af8 ldmdahi sp, {r0, r2, r3, r5, r6, r7, r8, r12, lr, pc} ^ */
/* @0x2a9afc andvc r0, sp, sp, lsr #20 */
/* @0x2a9b00 subvc r8, sp, sp, asr r8 */
/* @0x2a9b04 beq 0xe0bd80 <b2_toiTime+0x6b28dc> */
/* @0x2a9b08 ldmhi sp, {r0, r2, r3, r7, r12, sp, lr} */
/* @0x2a9b0c ldmhi sp, {r0, r2, r3, r6, r7, r12, sp, lr} ^ */
/* @0x2a9b10 .word 0x710d0a2d */
/* @0x2a9b14 ldrdvc r8, r9, [sp, #-141] */
/* @0x2a9b18 stcls p7, c14, [r3, #-884] */
/* @0x2a9b1c bhs 0x4c84cc <SrcVerts+0x25510> */
/* @0x2a9b20 stcne p1, c13, [pc], {88} */
/* @0x2a9b24 bls 0x755f64 <_ZN20CPhysicsJointFactory14ms_LastJointIDE+0x4c0> */
/* @0x2a9b28 shadd16mi r11, r12, r2 */
/* @0x2a9b2c eors r2, r12, r0, lsl #4 */
/* @0x2a9b30 rscsle r2, r10, r0, lsl #24 */
/* @0x2a9b34 addmi r2, r2, #0, #4 */
/* @0x2a9b38 adcshi pc, r1, #0 */
/* @0x2a9b3c .word 0xcc01f817 */
/* @0x2a9b40 svceq #0xfff1bc */
/* @0x2a9b44 .word 0xf817d104 */
/* @0x2a9b48 .word 0xf814cc02 */
/* @0x2a9b4c ands r12, lr, r12 */
/* @0x2a9b50 svceq #0xf1bc */
/* @0x2a9b54 rfeia r3! */
/* @0x2a9b58 ands r12, r8, r8 */
/* @0x2a9b5c .word 0xf1cc9d10 */
/* @0x2a9b60 rfeia r5! */
/* @0x2a9b64 blx 0x509b8e <SrcVerts+0x66bd2> */
/* @0x2a9b68 .word 0xf817f808 */
/* @0x2a9b6c .word 0xf8169c02 */
/* @0x2a9b70 .word 0xf1089009 */
/* @0x2a9b74 blx 0x4ebd7e <SrcVerts+0x48dc2> */
/* @0x2a9b78 .word 0xf8dd8c0c */
/* @0x2a9b7c blx 0xa89ca4 <b2_toiTime+0x330800> */
/* @0x2a9b80 bl 0x5e8db8 <g_SWFaavertbuff+0x15cf0> */
/* @0x2a9b84 .word 0xf3cc2c1c */
/* @0x2a9b88 .word 0xf8182c07 */
/* @0x2a9b8c .word 0xf801c00c */
/* @0x2a9b90 strlo r12, [r2, -r2] */
/* @0x2a9b94 strb r3, [lr, r1, lsl #4] */
/* @0x2a9b98 .word 0x5c01f814 */
/* @0x2a9b9c strdle r2, r3, [r7, -pc] */
/* @0x2a9ba0 .word 0x5c02f814 */
/* @0x2a9ba4 strlo r5, [r2], #-1165 */
/* @0x2a9ba8 addmi r3, r2, #268435456 */
/* @0x2a9bac rsbs sp, r6, #244, #2 */
/* @0x2a9bb0 ldmdbhi sp, {r0, r2, r3, r8, r11, r12, sp, pc} */
/* @0x2a9bb4 .word 0xf814e7f6 */
/* @0x2a9bb8 .word 0xf1c56c02 */
/* @0x2a9bbc .word 0x436e0cff */
/* @0x2a9bc0 stmdbhi pc!, {r4, r8, r10, r11, r12, pc} */
/* @0x2a9bc4 blx 0x5b75ce <g_SWFlineaavertbuff+0x64506> */
/* @0x2a9bc8 adclt r6, sp, #29360128 */
/* @0x2a9bcc ldrhs lr, [r5, #-0xb05] */
/* @0x2a9bd0 strb r1, [r7, sp, lsr #4]! */
/* @0x2a9bd4 tstlt r6, r4, lsl lr */
/* @0x2a9bd8 svceq #0xf1ba */
/* @0x2a9bdc strmi sp, [r10], -r4, lsl #2 */
/* @0x2a9be0 .word 0xf64f2500 */
/* @0x2a9be4 ldrsh r7, [r8], #-111 */
/* @0x2a9be8 svceq #0xf1b9 */
/* @0x2a9bec stcne p0, c13, [r10], {247} */
/* @0x2a9bf0 addmi r2, r5, #0, #10 */
/* @0x2a9bf4 subshi pc, r3, #0 */
/* @0x2a9bf8 stmvc r12, {r0, r1, r2, r3, r7, r11, r12, sp, lr} ^ */
/* @0x2a9bfc strhs lr, [r7], #-2820 */
/* @0x2a9c00 ldrbvc pc, [pc, pc, asr #12]! */
/* @0x2a9c04 adcsmi r11, r12, #164, #4 */
/* @0x2a9c08 stmdavc r12, {r0, r3, r8, r12, lr, pc} ^ */
/* @0x2a9c0c stmdavc pc, {r2, r4, r9, r10, r11, r12, pc} */
/* @0x2a9c10 vst1.16 {d15, d16}, [r11], r4 */
/* @0x2a9c14 eormi pc, r4, r6, asr r8 */
/* @0x2a9c18 andsmi pc, r7, r4, lsr r8 */
/* @0x2a9c1c stmdblt r12!, {r3, r5, sp, lr, pc} */
/* @0x2a9c20 beq 0xbcc098 <b2_toiTime+0x472bf4> */
/* @0x2a9c24 .word 0x4c02f802 */
/* @0x2a9c28 eor r8, r4, r12, lsl r9 */
/* @0x2a9c2c .word 0xf5c49e10 */
/* @0x2a9c30 .word 0x37ff477f */
/* @0x2a9c34 mulhi r0, r1, r8 */
/* @0x2a9c38 strhgt pc, [r8], -r6 */
/* @0x2a9c3c .word 0xf707fb0c */
/* @0x2a9c40 mulgt r1, r1, r8 */
/* @0x2a9c44 .word 0xfc0bfa4c */
/* @0x2a9c48 strmi pc, [r0, -r7, lsl #10] */
/* @0x2a9c4c eorgt pc, r12, r9, asr r8 */
/* @0x2a9c50 andsgt pc, r8, r12, lsr r8 */
/* @0x2a9c54 strvc pc, [r12], #-2820 */
/* @0x2a9c58 ldrmi lr, [r4], #-2820 */
/* @0x2a9c5c blx 0x1a6ccf4 <b2_toiTime+0x1313850> */
/* @0x2a9c60 beq 0xbe7e78 <b2_toiTime+0x48e9d4> */
/* @0x2a9c64 .word 0xf80bfa48 */
/* @0x2a9c68 eorvc pc, r8, r10, asr r8 */
/* @0x2a9c6c andsmi pc, r4, r7, lsr r8 */
/* @0x2a9c70 .word 0xf8020a27 */
/* @0x2a9c74 .word 0xf8027c02 */
/* @0x2a9c78 strlo r4, [r1, #-0xc01] */
/* @0x2a9c7c andlo r3, r2, #4, #2 */
/* @0x2a9c80 stmvc pc, {r0, r1, r2, r4, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a9c84 bl 0x3c7fbc <error_g0017+0x20c60> */
/* @0x2a9c88 adclt r2, r4, #117440512 */
/* @0x2a9c8c strhle r4, [r7, -r4] */
/* @0x2a9c90 andshi r8, r4, r12, lsl #16 */
/* @0x2a9c94 .word 0x31043501 */
/* @0x2a9c98 addmi r3, r5, #536870912 */
/* @0x2a9c9c ldrsh sp, [lr, #17]! */
/* @0x2a9ca0 ldmdbhi r12, {r2, r5, r8, r11, r12, sp, pc} */
/* @0x2a9ca4 andsvc r0, r4, r4, lsr #20 */
/* @0x2a9ca8 ands r8, r6, r12, lsl r9 */
/* @0x2a9cac mulgt r0, r1, r8 */
/* @0x2a9cb0 bl 0x487df4 <g_States+0x242c> */
/* @0x2a9cb4 adcslt r2, pc, #12, #14 */
/* @0x2a9cb8 .word 0xf5c44367 */
/* @0x2a9cbc .word 0xf104447f */
/* @0x2a9cc0 .word 0x9c1008ff */
/* @0x2a9cc4 strmi pc, [r0, -r7, lsl #10] */
/* @0x2a9cc8 strhgt pc, [r8], -r4 */
/* @0x2a9ccc strvc pc, [r8], #-2828 */
/* @0x2a9cd0 ldrmi lr, [r4], #-2820 */
/* @0x2a9cd4 beq 0xc6cd6c <b2_toiTime+0x5138c8> */
/* @0x2a9cd8 subsvc r7, r4, r7, lsl r0 */
/* @0x2a9cdc stcls p7, c14, [r3, #-872] */
/* @0x2a9ce0 bhs 0x4c8690 <SrcVerts+0x256d4> */
/* @0x2a9ce4 adcshi pc, r11, r0, asr #32 */
/* @0x2a9ce8 .word 0x0c03f101 */
/* @0x2a9cec svcls #0x12b10e */
/* @0x2a9cf0 .word 0xf04fb937 */
/* @0x2a9cf4 strbtmi r0, [r5], -r3, lsl #16 */
/* @0x2a9cf8 stmdane r0, {r3, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2a9cfc rsbs r4, r12, r10, lsl #12 */
/* @0x2a9d00 rscsle r2, r6, r0, lsl #24 */
/* @0x2a9d04 stmdbeq r3, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2a9d08 blx 0x4fb53a <SrcVerts+0x5857e> */
/* @0x2a9d0c strbmi r1, [r10, #-0x900] */
/* @0x2a9d10 bichi pc, r5, r0 */
/* @0x2a9d14 svchs #0xff78cf */
/* @0x2a9d18 stmdavc pc, {r0, r3, r8, r12, lr, pc} */
/* @0x2a9d1c .word 0xf80c5de7 */
/* @0x2a9d20 stmdavc pc, {r0, r1, r10, r11, r12, sp, lr} ^ */
/* @0x2a9d24 subsvc r5, r7, r7, ror #27 */
/* @0x2a9d28 stclpl p8, c7, [r7, #572]! */
/* @0x2a9d2c ldmdblt r7!, {r1, r4, r6, sp, lr, pc} */
/* @0x2a9d30 .word 0xf80c885f */
/* @0x2a9d34 ldmhi pc, {r0, r1, r10, r11, r12, sp, lr} */
/* @0x2a9d38 ldmhi pc, {r0, r1, r2, r4, r6, r12, sp, lr} ^ */
/* @0x2a9d3c ldcls p0, c14, [r0, #-296] */
/* @0x2a9d40 ldmeq pc!, {r0, r1, r2, r6, r7, r8, r12, sp, lr, pc} ^ */
/* @0x2a9d44 mullt r0, r1, r8 */
/* @0x2a9d48 .word 0xf888fa1f */
/* @0x2a9d4c strhge pc, [r2], -r5 */
/* @0x2a9d50 andlt pc, r11, r6, lsl r8 */
/* @0x2a9d54 blx 0x5511a6 <gp_ActiveMaskObjects+0xc4de> */
/* @0x2a9d58 .word 0xf10afa08 */
/* @0x2a9d5c blx 0x56c766 <g_SWFlineaavertbuff+0x1969e> */
/* @0x2a9d60 blx 0xa94584 <b2_toiTime+0x33b0e0> */
/* @0x2a9d64 bl 0x568794 <g_SWFlineaavertbuff+0x156cc> */
/* @0x2a9d68 vshll.u8 q9, d10, #0x2 */
/* @0x2a9d6c .word 0xf8152a07 */
/* @0x2a9d70 ldcls p0, c10, [r0, #-40] */
/* @0x2a9d74 .word 0xac03f80c */
/* @0x2a9d78 strhge pc, [r4], -r5 */
/* @0x2a9d7c mullt r1, r1, r8 */
/* @0x2a9d80 blx 0x5511d2 <gp_ActiveMaskObjects+0xc50a> */
/* @0x2a9d84 .word 0xf816fa08 */
/* @0x2a9d88 .word 0xf10ab00b */
/* @0x2a9d8c blx 0x56c796 <g_SWFlineaavertbuff+0x196ce> */
/* @0x2a9d90 blx 0xa945b4 <b2_toiTime+0x33b110> */
/* @0x2a9d94 bl 0x5687c4 <g_SWFlineaavertbuff+0x156fc> */
/* @0x2a9d98 vshll.u8 q9, d10, #0x2 */
/* @0x2a9d9c .word 0xf8152a07 */
/* @0x2a9da0 ldcls p0, c10, [r0, #-40] */
/* @0x2a9da4 andge pc, r1, r2, lsl #17 */
/* @0x2a9da8 strhge pc, [r6], -r5 */
/* @0x2a9dac .word 0xf808fb0a */
/* @0x2a9db0 mulge r2, r1, r8 */
/* @0x2a9db4 andge pc, r10, r6, lsl r8 */
/* @0x2a9db8 stmeq r0, {r3, r8, r12, sp, lr, pc} */
/* @0x2a9dbc stmdahi r7, {r1, r3, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2a9dc0 .word 0xa048f8dd */
/* @0x2a9dc4 .word 0xf888fa1f */
/* @0x2a9dc8 ldmdahs r8, {r3, r8, r9, r11, sp, lr, pc} */
/* @0x2a9dcc stmdahs r7, {r3, r6, r7, r8, r9, r12, sp, lr, pc} */
/* @0x2a9dd0 andvc pc, r8, r10, lsl r8 */
/* @0x2a9dd4 swplo r7, r7, [r4] */
/* @0x2a9dd8 .word 0xf10c3203 */
/* @0x2a9ddc ldr r0, [r6, r3, lsl #24] */
/* @0x2a9de0 ldclhs p8, c7, [pc], #816 */
/* @0x2a9de4 stmdavc r12, {r2, r3, r8, r12, lr, pc} */
/* @0x2a9de8 .word 0x4c03f805 */
/* @0x2a9dec subsvc r7, r4, r12, asr #16 */
/* @0x2a9df0 addsvc r7, r4, r12, lsl #17 */
/* @0x2a9df4 andlo r3, r3, #4, #2 */
/* @0x2a9df8 strbmi r3, [r2, #-0x503] */
/* @0x2a9dfc strd sp, lr, [lr, #-16] */
/* @0x2a9e00 strhgt pc, [r2], -r3 */
/* @0x2a9e04 .word 0xf805b92c */
/* @0x2a9e08 ldmhi r12, {r0, r1, r10, r11, lr, pc} */
/* @0x2a9e0c ldmhi r12, {r2, r4, r6, r12, sp, lr} ^ */
/* @0x2a9e10 stmdavc pc, {r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2a9e14 ldrbteq pc, [pc], r4, asr #3 */
/* @0x2a9e18 .word 0x4367b2b6 */
/* @0x2a9e1c blx 0x437c26 <g_RomDisk+0x40406> */
/* @0x2a9e20 adcslt r7, pc, #12, #14 */
/* @0x2a9e24 ldrhs lr, [r7, -r7, lsl #22] */
/* @0x2a9e28 .word 0xf805123f */
/* @0x2a9e2c stmdavc pc, {r0, r1, r10, r11, r12, sp, lr} ^ */
/* @0x2a9e30 strhgt pc, [r4], -r3 */
/* @0x2a9e34 strlo r4, [r0, r7, ror #6] */
/* @0x2a9e38 strvc pc, [r12, -r6, lsl #22] */
/* @0x2a9e3c bl 0x496940 <g_prim_v+0x6934> */
/* @0x2a9e40 eorsne r2, pc, #6029312 */
/* @0x2a9e44 stmvc pc, {r0, r1, r2, r4, r6, r12, sp, lr} */
/* @0x2a9e48 ldmhi pc, {r2, r3, r4, r5, r6, r8, r9, lr} ^ */
/* @0x2a9e4c blx 0x437056 <g_RomDisk+0x3f836> */
/* @0x2a9e50 adcslt r4, r6, #7340032 */
/* @0x2a9e54 ldrhs lr, [r6], -r6, lsl #22 */
/* @0x2a9e58 addsvc r1, r6, r6, lsr r2 */
/* @0x2a9e5c bls 0x7e3d8c <b2_toiTime+0x8a8e8> */
/* @0x2a9e60 .word 0xf1bab112 */
/* @0x2a9e64 .word 0xd1040f00 */
/* @0x2a9e68 strhs r4, [r0, #-0x60a] */
/* @0x2a9e6c ldclvc p6, c15, [pc], #316 */
/* @0x2a9e70 .word 0xf1b9e0bc */
/* @0x2a9e74 rscsle r0, r7, r0, lsl #30 */
/* @0x2a9e78 stmdaeq r6, {r0, r8, r12, sp, lr, pc} */
/* @0x2a9e7c strhs r4, [r0], #-1546 */
/* @0x2a9e80 .word 0x9c059405 */
/* @0x2a9e84 .word 0xf0004284 */
/* @0x2a9e88 stmibvc sp, {r1, r3, r8, pc} */
/* @0x2a9e8c bl 0x3c85c4 <error_g0017+0x21268> */
/* @0x2a9e90 .word 0xf64f2405 */
/* @0x2a9e94 adclt r7, r4, #1069547520 */
/* @0x2a9e98 smulwble r0, r12, r2 */
/* @0x2a9e9c cdpls p8, #0x1, c7, c4, c12, #0x2 */
/* @0x2a9ea0 blx 0x13c7edc <b2_toiTime+0xc6ea38> */
/* @0x2a9ea4 .word 0xf856f40b */
/* @0x2a9ea8 rfeda r4! */
/* @0x2a9eac beq 0xbf9f08 <b2_toiTime+0x4a0a64> */
/* @0x2a9eb0 .word 0x5c06f808 */
/* @0x2a9eb4 stmvc r12, {r2, r4, r6, r12, sp, lr} ^ */
/* @0x2a9eb8 blx 0x13c80f4 <b2_toiTime+0xc6ec50> */
/* @0x2a9ebc .word 0xf856f40b */
/* @0x2a9ec0 rfeda r4! */
/* @0x2a9ec4 sbcsvc r4, r4, r5, lsl r0 */
/* @0x2a9ec8 addsvc r0, r5, r5, lsr #20 */
/* @0x2a9ecc stmdbvc sp, {r2, r3, r6, r8, r11, r12, sp, lr} */
/* @0x2a9ed0 vst1.16 {d15, d16}, [r11], r4 */
/* @0x2a9ed4 eormi pc, r4, r6, asr r8 */
/* @0x2a9ed8 andsmi pc, r5, r4, lsr r8 */
/* @0x2a9edc ldmdblt r12!, {r1, r3, r5, r6, sp, lr, pc} ^ */
/* @0x2a9ee0 beq 0xbcc058 <b2_toiTime+0x472bb4> */
/* @0x2a9ee4 .word 0x4c06f808 */
/* @0x2a9ee8 subsvc r8, r4, r12, asr r8 */
/* @0x2a9eec beq 0xbcc164 <b2_toiTime+0x472cc0> */
/* @0x2a9ef0 ldmhi r12, {r2, r4, r7, r12, sp, lr} */
/* @0x2a9ef4 ldmhi r12, {r2, r4, r6, r7, r12, sp, lr} ^ */
/* @0x2a9ef8 tstvc r4, r4, lsr #20 */
/* @0x2a9efc ldrsb r8, [r11], #-140 */
/* @0x2a9f00 .word 0xf5c49f10 */
/* @0x2a9f04 ldrblo r4, [pc, #0x57f]! */
/* @0x2a9f08 mulgt r0, r1, r8 */
/* @0x2a9f0c stmdavc pc, {r1, r2, r3, r4, r5, r6, r11, pc} ^ */
/* @0x2a9f10 blx 0x147acd0 <b2_toiTime+0xd2182c> */
/* @0x2a9f14 .word 0xf859f70b */
/* @0x2a9f18 .word 0xf5067027 */
/* @0x2a9f1c rfeda r7! */
/* @0x2a9f20 blx 0x3c5f9a <error_g0017+0x1ec3e> */
/* @0x2a9f24 bl 0x443748 <g_RomDisk+0x4bf28> */
/* @0x2a9f28 ldceq p6, c4, [r6], #-88 */
/* @0x2a9f2c beq 0x1056b10 <b2_toiTime+0x8fd66c> */
/* @0x2a9f30 .word 0xf70bfa47 */
/* @0x2a9f34 eorvc pc, r7, r10, asr r8 */
/* @0x2a9f38 andsvs pc, r6, r7, lsr r8 */
/* @0x2a9f3c .word 0xf8080a37 */
/* @0x2a9f40 svcls #0x107c06 */
/* @0x2a9f44 .word 0xf8917056 */
/* @0x2a9f48 ldmhi lr!, {r1, lr, pc} */
/* @0x2a9f4c .word 0x436e78cf */
/* @0x2a9f50 .word 0xf70bfa47 */
/* @0x2a9f54 eorvc pc, r7, r9, asr r8 */
/* @0x2a9f58 strmi pc, [r0], -r6, lsl #10 */
/* @0x2a9f5c andsvc pc, r12, r7, lsr r8 */
/* @0x2a9f60 strvs pc, [r7], -r4, lsl #22 */
/* @0x2a9f64 ldrmi lr, [r6], -r6, lsl #22 */
/* @0x2a9f68 rscslt r0, r7, #13824 */
/* @0x2a9f6c blx 0x146c84c <b2_toiTime+0xd133a8> */
/* @0x2a9f70 .word 0xf85af70b */
/* @0x2a9f74 rfeda r7! */
/* @0x2a9f78 beq 0x1081fd8 <b2_toiTime+0x928b34> */
/* @0x2a9f7c svcls #0x107097 */
/* @0x2a9f80 ldmhi lr!, {r1, r2, r4, r6, r7, r12, sp, lr} ^ */
/* @0x2a9f84 cmnmi r5, #245760 */
/* @0x2a9f88 blx 0x14484c8 <b2_toiTime+0xcef024> */
/* @0x2a9f8c .word 0xf505f60b */
/* @0x2a9f90 .word 0xf8594500 */
/* @0x2a9f94 rfeda r6! */
/* @0x2a9f98 blx 0x3c1ffe <error_g0017+0x1aca2> */
/* @0x2a9f9c bl 0x3befbc <error_g0017+0x17c60> */
/* @0x2a9fa0 stceq p4, c4, [r4], #-80 */
/* @0x2a9fa4 beq 0xbd6b48 <b2_toiTime+0x47d6a4> */
/* @0x2a9fa8 .word 0xf70bfa47 */
/* @0x2a9fac eorpl pc, r7, r10, asr r8 */
/* @0x2a9fb0 andsmi pc, r4, r5, lsr r8 */
/* @0x2a9fb4 tstvc r5, r5, lsr #20 */
/* @0x2a9fb8 ldrsbgt pc, [r4], -sp */
/* @0x2a9fbc cmpvc r4, r8, lsl #2 */
/* @0x2a9fc0 stmdaeq r6, {r3, r8, r12, sp, lr, pc} */
/* @0x2a9fc4 .word 0x0c01f10c */
/* @0x2a9fc8 .word 0xf8cd3206 */
/* @0x2a9fcc smmla r8, r4, r0, r12 */
/* @0x2a9fd0 stmibvc r12, {r1, r2, r3, r7, r8, r11, r12, sp, lr} ^ */
/* @0x2a9fd4 strhs lr, [r6], #-2820 */
/* @0x2a9fd8 strbmi r11, [r4, #-0x2a4]! */
/* @0x2a9fdc stmdavs r12, {r0, r3, r8, r12, lr, pc} */
/* @0x2a9fe0 stmhi r12, {r2, r4, sp, lr} */
/* @0x2a9fe4 strlo r8, [r1, #-0x94] */
/* @0x2a9fe8 andlo r3, r6, #8, #2 */
/* @0x2a9fec mvnle r4, r5, lsl #5 */
/* @0x2a9ff0 ldmdahi pc, {r0, r2, r4, r6, sp, lr, pc} ^ */
/* @0x2a9ff4 beq 0x12985cc <b2_toiTime+0xb3f128> */
/* @0x2a9ff8 ldmdahi r12, {r0, r1, r2, r4, r12, sp, lr} ^ */
/* @0x2a9ffc ldmhi r12, {r2, r4, r6, r12, sp, lr} */
/* @0x2aa000 addsvc r0, r4, r4, lsr #20 */
/* @0x2aa004 smullsvc r8, r4, r12, r8 */
/* @0x2aa008 beq 0xbcc380 <b2_toiTime+0x472edc> */
/* @0x2aa00c ldmhi r12, {r2, r4, r8, r12, sp, lr} ^ */
/* @0x2aa010 ubfx r7, r4, #0x2, #0x9 */
/* @0x2aa014 mullt r0, r1, r8 */
/* @0x2aa018 mulge r1, r1, r8 */
/* @0x2aa01c mulls r2, r1, r8 */
/* @0x2aa020 bhs 0x5a4c50 <g_SWFlineaavertbuff+0x51b88> */
/* @0x2aa024 .word 0xf89178ce */
/* @0x2aa028 blx 0xa8a040 <b2_toiTime+0x330b9c> */
/* @0x2aa02c bl 0x468a5c <g_RomDisk+0x7123c> */
/* @0x2aa030 stmdbvc lr, {r0, r3, r8, r11, sp} ^ */
/* @0x2aa034 blx 0x3e8c64 <pfr_cmap_class_rec+0x120> */
/* @0x2aa038 stmdahs r8, {r1, r2, r8, r9, r11, sp, lr, pc} */
/* @0x2aa03c ldrbtmi pc, [pc], -r4, asr #11 */
/* @0x2aa040 .word 0xf989fa1f */
/* @0x2aa044 blx 0xa77c48 <b2_toiTime+0x31e7a4> */
/* @0x2aa048 .word 0xf50af888 */
/* @0x2aa04c blx 0x3bc856 <error_g0017+0x154fa> */
/* @0x2aa050 blx 0x4a847e <SrcVerts+0x54c2> */
/* @0x2aa054 .word 0xf509a706 */
/* @0x2aa058 blx 0x3bc462 <error_g0017+0x15106> */
/* @0x2aa05c bl 0x4a7084 <SrcVerts+0x40c8> */
/* @0x2aa060 .word 0xf5044717 */
/* @0x2aa064 ldceq p4, c4, [pc], #-0 */
/* @0x2aa068 b 0x16861cc <b2_toiTime+0xf2cd28> */
/* @0x2aa06c .word 0xf8822a17 */
/* @0x2aa070 ldmhi pc, {sp, pc} */
/* @0x2aa074 strls pc, [r6, -r7, lsl #22] */
/* @0x2aa078 ldrmi lr, [r7, -r7, lsl #22] */
/* @0x2aa07c sbcsvc r0, r7, pc, lsr r12 */
/* @0x2aa080 ldmdbhs r7, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2aa084 andls pc, r2, r2, lsl #17 */
/* @0x2aa088 strhhi pc, [r6], -r3 */
/* @0x2aa08c strmi pc, [r6], -r8, lsl #22 */
/* @0x2aa090 ldrmi lr, [r6], -r6, lsl #22 */
/* @0x2aa094 cmpvc r6, r6, lsr r12 */
/* @0x2aa098 tstvc r4, r4, lsr r10 */
/* @0x2aa09c stcls p7, c14, [r3, #-652] */
/* @0x2aa0a0 ldrbeq r7, [r10, -r11, lsr #20] */
/* @0x2aa0a4 .word 0xf023d514 */
/* @0x2aa0a8 eorvc r0, r11, #4, #6 */
/* @0x2aa0ac bvc 0x1d48b60 <b2_toiTime+0x15ef6bc> */
/* @0x2aa0b0 sbcslt r3, r11, #1024 */
/* @0x2aa0b4 cmpmi r3, #-1342177270 */
/* @0x2aa0b8 rscvc r11, r11, #-1342177267 */
/* @0x2aa0bc stmdble r2, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x2aa0c0 cmpmi r8, #14352384 */
/* @0x2aa0c4 cmpmi r8, #2 */
/* @0x2aa0c8 stmeq r0, {r0, r1, r2, r12, sp} ^ */
/* @0x2aa0cc rsbsvs r9, r0, r3, lsl #28 */
/* @0x2aa0d0 pop {r0, r1, r2, r12, sp, pc} */
/* @0x2aa0d4 push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2a90ad · png_do_gray_to_rgb · size=256 · insn=0 */

/* ── FUNC 0x2a91ad · png_do_rgb_to_gray · size=1166 · insn=0 */

/* ── FUNC 0x2a963d · png_build_grayscale_palette · size=68 · insn=0 */

/* ── FUNC 0x2a9681 · png_do_background · size=2646 · insn=0 */

/* ── FUNC 0x2aa0d6 · anon_2aa0d6 · size=708 · insn=177 */
/* @0x2aa0d6 svcmi #0xf0e92d */
/* @0x2aa0da vstrls s14, [r9, #-280] */
/* @0x2aa0de stmdavs r4, {r3, r9, r10, r11, sp} */
/* @0x2aa0e2 ldmdblt r10!, {r1, r11, r12, lr, pc} */
/* @0x2aa0e6 svchi #0xf0e8bd */
/* @0x2aa0ea .word 0xf0402e10 */
/* @0x2aa0ee blhs 0x2ca63e <_ZN7b2World8SolveTOIERK10b2TimeStep+0xb8a> */
/* @0x2aa0f2 mrshi pc, spsr */
/* @0x2aa0f6 svchs #0x67a07 */
/* @0x2aa0fa .word 0x814bf200 */
/* @0x2aa0fe .word 0xf017e8df */
/* @0x2aa102 smlalbteq r0, r9, r2, r0 */
/* @0x2aa106 mrseq r0, spsr */
/* @0x2aa10a swpbeq r0, r10, [r9] */
/* @0x2aa10e mcrhs p0, #0x0, r0, c8, c1, #0x2 */
/* @0x2aa112 andhs sp, r0, #1 */
/* @0x2aa116 movwhs lr, #0x3016 */
/* @0x2aa11a strne pc, [r4], #-2819 */
/* @0x2aa11e andle r4, pc, r1, lsr #5 */
/* @0x2aa122 mrslo r7, apsr */
/* @0x2aa126 .word 0xf8015cd3 */
/* @0x2aa12a .word 0xf8113c03 */
/* @0x2aa12e ldclpl p12, c3, [r3], {2} */
/* @0x2aa132 .word 0x3c02f801 */
/* @0x2aa136 .word 0x3c01f811 */
/* @0x2aa13a .word 0xf8015cd3 */
/* @0x2aa13e strb r3, [sp, r1, lsl #24]! */
/* @0x2aa142 svchi #0xf0e8bd */
/* @0x2aa146 eorle r4, r10, r2, lsr #5 */
/* @0x2aa14a andlo r7, r1, #72, #16 */
/* @0x2aa14e .word 0x3106780e */
/* @0x2aa152 .word 0xf8534128 */
/* @0x2aa156 rfeda r0! */
/* @0x2aa15a .word 0xf8010016 */
/* @0x2aa15e beq 0x42d17a <g_RomDisk+0x3595a> */
/* @0x2aa162 .word 0x0c03f811 */
/* @0x2aa166 .word 0x6c06f801 */
/* @0x2aa16a .word 0x6c04f811 */
/* @0x2aa16e .word 0xf8534128 */
/* @0x2aa172 rfeda r0! */
/* @0x2aa176 .word 0xf8010016 */
/* @0x2aa17a beq 0x42d18e <g_RomDisk+0x3596e> */
/* @0x2aa17e .word 0x0c01f811 */
/* @0x2aa182 .word 0x6c04f801 */
/* @0x2aa186 .word 0x6c02f811 */
/* @0x2aa18a .word 0xf8534128 */
/* @0x2aa18e rfeda r0! */
/* @0x2aa192 beq 0x42a1f2 <g_RomDisk+0x329d2> */
/* @0x2aa196 .word 0x0c01f801 */
/* @0x2aa19a .word 0x6c02f801 */
/* @0x2aa19e pop {r1, r4, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2aa1a2 mcrhs p15, #0x0, r8, c8, c0, #0x7 */
/* @0x2aa1a6 andhs sp, r0, #1 */
/* @0x2aa1aa movwhs lr, #0x15 */
/* @0x2aa1ae andsle r4, r0, r3, lsr #5 */
/* @0x2aa1b2 movwlo r7, #0x1808 */
/* @0x2aa1b6 .word 0x5c103104 */
/* @0x2aa1ba .word 0x0c04f801 */
/* @0x2aa1be .word 0x0c03f811 */
/* @0x2aa1c2 .word 0xf8015c10 */
/* @0x2aa1c6 .word 0xf8110c03 */
/* @0x2aa1ca .word 0x5c100c02 */
/* @0x2aa1ce .word 0x0c02f801 */
/* @0x2aa1d2 pop {r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2aa1d6 adcmi r8, r2, #240, #30 */
/* @0x2aa1da stmdavc r8, {r1, r3, r5, r12, lr, pc} ^ */
/* @0x2aa1de stmdavc lr, {r0, r9, r12, sp} */
/* @0x2aa1e2 .word 0x41283108 */
/* @0x2aa1e6 eoreq pc, r0, r3, asr r8 */
/* @0x2aa1ea andseq pc, r6, r0, lsr r8 */
/* @0x2aa1ee .word 0x0c07f801 */
/* @0x2aa1f2 .word 0xf8110a06 */
/* @0x2aa1f6 .word 0xf8010c05 */
/* @0x2aa1fa .word 0xf8116c08 */
/* @0x2aa1fe .word 0x41286c06 */
/* @0x2aa202 eoreq pc, r0, r3, asr r8 */
/* @0x2aa206 andseq pc, r6, r0, lsr r8 */
/* @0x2aa20a .word 0x0c05f801 */
/* @0x2aa20e .word 0xf8110a06 */
/* @0x2aa212 .word 0xf8010c03 */
/* @0x2aa216 .word 0xf8116c06 */
/* @0x2aa21a .word 0x41286c04 */
/* @0x2aa21e eoreq pc, r0, r3, asr r8 */
/* @0x2aa222 andseq pc, r6, r0, lsr r8 */
/* @0x2aa226 .word 0xf8010a06 */
/* @0x2aa22a .word 0xf8010c03 */
/* @0x2aa22e ldrb r6, [r2, r4, lsl #24] */
/* @0x2aa232 svchi #0xf0e8bd */
/* @0x2aa236 andle r2, r1, r8, lsl #28 */
/* @0x2aa23a and r2, sp, r0, lsl #4 */
/* @0x2aa23e adcmi r2, r3, #0, #6 */
/* @0x2aa242 .word 0x0102f101 */
/* @0x2aa246 .word 0xf811d006 */
/* @0x2aa24a movwlo r0, #0x1c02 */
/* @0x2aa24e .word 0xf8015c10 */
/* @0x2aa252 ldrb r0, [r4, r2, lsl #24]! */
/* @0x2aa256 svchi #0xf0e8bd */
/* @0x2aa25a .word 0xf10142a2 */
/* @0x2aa25e andle r0, pc, r4, lsl #2 */
/* @0x2aa262 .word 0x0c03f811 */
/* @0x2aa266 .word 0xf8113201 */
/* @0x2aa26a .word 0x41286c04 */
/* @0x2aa26e eoreq pc, r0, r3, asr r8 */
/* @0x2aa272 andseq pc, r6, r0, lsr r8 */
/* @0x2aa276 .word 0xf8010a06 */
/* @0x2aa27a .word 0xf8010c03 */
/* @0x2aa27e strb r6, [r11, r4, lsl #24]! */
/* @0x2aa282 svchi #0xf0e8bd */
/* @0x2aa286 andle r2, r4, r2, lsl #28 */
/* @0x2aa28a stmdahs r4, {r6, r9, r11, r12, sp, lr} */
/* @0x2aa28e movwhs sp, #0x15e */
/* @0x2aa292 strmi lr, [r10], r5, asr #32 */
/* @0x2aa296 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2aa29a rscsle r4, r5, #675282944 */
/* @0x2aa29e mulhi r0, r10, r8 */
/* @0x2aa2a2 stmdbeq r4, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x2aa2a6 stcleq p0, c15, [r0], {8} */
/* @0x2aa2aa ldreq pc, [r0, -r8]! */
/* @0x2aa2ae streq pc, [r12], -r8 */
/* @0x2aa2b2 stmdaeq r3, {r3, r12, sp, lr, pc} */
/* @0x2aa2b6 blne 0x4e4bfa <SrcVerts+0x41c3e> */
/* @0x2aa2ba blne 0xfe4e4bee <b2_toiTime+0xfffffffffdd8b74a> */
/* @0x2aa2be bleq 0x4e4bf2 <SrcVerts+0x41c36> */
/* @0x2aa2c2 stmeq r8, {r0, r1, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2aa2c6 blne 0xde4c0a <b2_toiTime+0x68b766> */
/* @0x2aa2ca bleq 0xfe9e4bfe <b2_toiTime+0xfffffffffe28b75a> */
/* @0x2aa2ce bleq 0x5e4c02 <g_SWFaavertbuff+0x11b3a> */
/* @0x2aa2d2 andhi pc, r8, r2, lsl r8 */
/* @0x2aa2d6 vldmiane r12, {s28, s29, s30, s31} */
/* @0x2aa2da andgt pc, r12, r2, lsl r8 */
/* @0x2aa2de ldceq p0, c15, [pc], #-176 */
/* @0x2aa2e2 vldmiane r8, {s28, s29, s30, s31} */
/* @0x2aa2e6 stmeq r7!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2aa2ea stmeq r7, {r3, r6, r9, r11, sp, lr, pc} */
/* @0x2aa2ee stmdaeq r7, {r3, r6, r9, r11, sp, lr, pc} */
/* @0x2aa2f2 ldrne lr, [r7, -r8, asr #20] */
/* @0x2aa2f6 ldmeq pc!, {r0, r1, r2, r4, r6, r7, r8, r10, r11, r12, lr} */
/* @0x2aa2fa ldreq pc, [r0, -r7]! */
/* @0x2aa2fe .word 0x0c07ea4c */
/* @0x2aa302 b 0x146a5e6 <b2_toiTime+0xd11142> */
/* @0x2aa306 teqmi r7, #1572864 */
/* @0x2aa30a ldreq lr, [r6], r7, asr #20 */
/* @0x2aa30e ldmdbeq pc!, {r0, r1, r2, r4, r7, r8, r10, r11, r12, lr} */
/* @0x2aa312 streq pc, [r12, -r7] */
/* @0x2aa316 streq lr, [r7], -r12, asr #20 */
/* @0x2aa31a blvs 0x32834a */
/* @0x2aa31e adcmi lr, r3, #188, #14 */
/* @0x2aa322 stmdavc sp, {r1, r4, r9, r12, lr, pc} */
/* @0x2aa326 .word 0xf0053302 */
/* @0x2aa32a .word 0xf00500f0 */
/* @0x2aa32e b 0x12ab772 <b2_toiTime+0xb522ce> */
/* @0x2aa332 b 0x13ee37a <b2_toiTime+0xc94ed6> */
/* @0x2aa336 .word 0x5c101505 */
/* @0x2aa33a .word 0xf0205d55 */
/* @0x2aa33e b 0x12aa382 <b2_toiTime+0xb50ede> */
/* @0x2aa342 .word 0xf8011015 */
/* @0x2aa346 strb r0, [r10, r1, lsl #22]! */
/* @0x2aa34a svchi #0xf0e8bd */
/* @0x2aa34e mrsle r2, apsr */
/* @0x2aa352 adcmi r4, r1, #12, #8 */
/* @0x2aa356 stmdavc r11, {r2, r12, lr, pc} */
/* @0x2aa35a .word 0xf8015cd3 */
/* @0x2aa35e ldrb r3, [r8, r1, lsl #22]! */
/* @0x2aa362 svchi #0xf0e8bd */
/* @0x2aa366 tstle r4, r0, lsl r8 */
/* @0x2aa36a adcmi r2, r2, #0, #4 */
/* @0x2aa36e .word 0x0102f101 */
/* @0x2aa372 .word 0xf811d00f */
/* @0x2aa376 andlo r0, r1, #256 */
/* @0x2aa37a .word 0x6c02f811 */
/* @0x2aa37e .word 0xf8534128 */
/* @0x2aa382 rfeda r0! */
/* @0x2aa386 beq 0x42a3e6 <g_RomDisk+0x32bc6> */
/* @0x2aa38a .word 0x0c01f801 */
/* @0x2aa38e .word 0x6c02f801 */
/* @0x2aa392 pop {r0, r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2aa396 push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */

/* ── FUNC 0x2aa0d7 · png_do_gamma · size=706 · insn=0 */

/* ── FUNC 0x2aa398 · anon_2aa398 · size=6292 · insn=1573 */
/* @0x2aa398 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x2aa39c stmdavs r4, {r0, r2, r9, r11, r12, sp, lr} */
/* @0x2aa3a0 .word 0xf0402d03 */
/* @0x2aa3a4 .word 0xf89080c9 */
/* @0x2aa3a8 .word 0xf1bcc009 */
/* @0x2aa3ac stmdale r9!, {r0, r1, r2, r8, r9, r10, r11} ^ */
/* @0x2aa3b0 svceq #0x2f1bc */
/* @0x2aa3b4 .word 0xf1bcd028 */
/* @0x2aa3b8 suble r0, r3, r4, lsl #30 */
/* @0x2aa3bc svceq #0x1f1bc */
/* @0x2aa3c0 .word 0xf104d15c */
/* @0x2aa3c4 stclne p9, c3, [r7, #1020]! */
/* @0x2aa3c8 beq 0x3e4d8c <error_g0017+0x3da30> */
/* @0x2aa3cc ldrbeq lr, [r9], r1, lsl #22 */
/* @0x2aa3d0 .word 0x43ff4489 */
/* @0x2aa3d4 ldrblo pc, [pc, #0x109]! */
/* @0x2aa3d8 streq pc, [r7, -r7] */
/* @0x2aa3dc ldrbmi r4, [r5, #-0x4ca] */
/* @0x2aa3e0 .word 0xf896d04c */
/* @0x2aa3e4 stclo p0, c9, [r1, #-0] */
/* @0x2aa3e8 .word 0xf907fa49 */
/* @0x2aa3ec stmdbeq r1, {r0, r3, r4, r12, sp, lr, pc} */
/* @0x2aa3f0 .word 0xf885bf14 */
/* @0x2aa3f4 .word 0xf885c002 */
/* @0x2aa3f8 svchs #0x79002 */
/* @0x2aa3fc .word 0xf106bf0a */
/* @0x2aa400 .word 0x370136ff */
/* @0x2aa404 strb r2, [r10, r0, lsl #14]! */
/* @0x2aa408 cdpne p12, #0x6, c1, c7, c5, #0x7 */
/* @0x2aa40c .word 0xf00543ed */
/* @0x2aa410 bl 0x2eb824 <FT_Done_Memory+0x1bb0> */
/* @0x2aa414 strmi r0, [pc], #-1687 */
/* @0x2aa418 bl 0xff3aa5d4 <b2_toiTime+0xfffffffffec51130> */
/* @0x2aa41c strbmi r0, [r7, #-0x807] */
/* @0x2aa420 .word 0xf896d02c */
/* @0x2aa424 stchs p0, c9, [r6, #-0] */
/* @0x2aa428 .word 0xf106bf08 */
/* @0x2aa42c blx 0x14f8030 <b2_toiTime+0xd9eb8c> */
/* @0x2aa430 svclt #0x8f905 */
/* @0x2aa434 .word 0xf0092500 */
/* @0x2aa438 svclt #0x180903 */
/* @0x2aa43c .word 0xf8073502 */
/* @0x2aa440 strb r9, [r12, r1, lsl #18]! */
/* @0x2aa444 .word 0xf0041e67 */
/* @0x2aa448 bl 0x2eb854 <FT_Done_Memory+0x1be0> */
/* @0x2aa44c strmi r0, [pc], #-1623 */
/* @0x2aa450 bl 0xff3aa70c <b2_toiTime+0xfffffffffec51268> */
/* @0x2aa454 strbmi r0, [r7, #-0x807] */
/* @0x2aa458 .word 0xf896d010 */
/* @0x2aa45c stchs p0, c9, [r4, #-0] */
/* @0x2aa460 .word 0xf106bf08 */
/* @0x2aa464 blx 0x14f8068 <b2_toiTime+0xd9ebc4> */
/* @0x2aa468 svclt #0x8f905 */
/* @0x2aa46c .word 0xf0092500 */
/* @0x2aa470 svclt #0x18090f */
/* @0x2aa474 .word 0xf8073504 */
/* @0x2aa478 strb r9, [r12, r1, lsl #18]! */
/* @0x2aa47c subvs r2, r4, r8, lsl #10 */
/* @0x2aa480 sbcvc r7, r5, #1342177284 */
/* @0x2aa484 vstrhs s14, [r8, #-276] */
/* @0x2aa488 mcrne p1, #0x3, sp, c7, c6, #0x2 */
/* @0x2aa48c adceq r11, r6, r3, ror r3 */
/* @0x2aa490 ldmeq pc!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^ */
/* @0x2aa494 ldrtmi r1, [r9], #-2445 */
/* @0x2aa498 bl 0xff3b98a8 <b2_toiTime+0xfffffffffec60404> */
/* @0x2aa49c strbmi r0, [r1, #-0xc01]! */
/* @0x2aa4a0 .word 0xf811d01b */
/* @0x2aa4a4 stclo p9, c7, [r4, #-4] */
/* @0x2aa4a8 adcmi r9, r7, #8, #24 */
/* @0x2aa4ac .word 0xf885bfae */
/* @0x2aa4b0 ldclpl p0, c8, [pc, #20] */
/* @0x2aa4b4 stmdavc pc, {r0, r1, r2, r3, r5, r6, r8, r12, sp, lr} ^ */
/* @0x2aa4b8 strbeq lr, [r7, -r7, lsl #22] */
/* @0x2aa4bc ldmvc pc!, {r0, r1, r2, r4, r10, lr} */
/* @0x2aa4c0 stmdavc pc, {r0, r1, r2, r3, r5, r8, r12, sp, lr} ^ */
/* @0x2aa4c4 strbeq lr, [r7, -r7, lsl #22] */
/* @0x2aa4c8 ldmdavc pc!, {r0, r1, r2, r4, r10, lr} ^ */
/* @0x2aa4cc stmdavc pc, {r0, r1, r2, r3, r5, r6, r7, r12, sp, lr} ^ */
/* @0x2aa4d0 strbeq lr, [r7, -r7, lsl #22] */
/* @0x2aa4d4 .word 0x70af5dd7 */
/* @0x2aa4d8 movwhs lr, #0x87e1 */
/* @0x2aa4dc subvc r6, r3, #70 */
/* @0x2aa4e0 sbcvc r2, r3, #32, #6 */
/* @0x2aa4e4 andvc r2, r3, #402653184 */
/* @0x2aa4e8 eor r2, r4, r4, lsl #6 */
/* @0x2aa4ec stmibne r11, {r0, r1, r8, r10, sp} ^ */
/* @0x2aa4f0 .word 0x43e44365 */
/* @0x2aa4f4 mcrne p4, #0x3, r4, c14, c12, #0x0 */
/* @0x2aa4f8 bllo 0x2fb5c4 <ps_hints_apply+0xa1c4> */
/* @0x2aa4fc andsle r4, r2, r3, lsr #5 */
/* @0x2aa500 stmdblo r3, {r1, r2, r3, r4, r6, r11, r12, sp, lr} */
/* @0x2aa504 strbeq lr, [r6], -r6, lsl #22 */
/* @0x2aa508 ldmvc r6!, {r1, r2, r4, r10, lr} */
/* @0x2aa50c ldmdavc lr, {r1, r2, r3, r6, r7, r12, sp, lr} ^ */
/* @0x2aa510 strbeq lr, [r6], -r6, lsl #22 */
/* @0x2aa514 ldmdavc r6!, {r1, r2, r4, r10, lr} ^ */
/* @0x2aa518 ldmdavc lr, {r1, r2, r3, r7, r12, sp, lr} ^ */
/* @0x2aa51c strbeq lr, [r6], -r6, lsl #22 */
/* @0x2aa520 umaalvc r5, lr, r6, sp */
/* @0x2aa524 movwhs lr, #0x87e9 */
/* @0x2aa528 tsths r8, #805306372 */
/* @0x2aa52c movwhs r7, #0x22c3 */
/* @0x2aa530 movwhs r7, #0x3203 */
/* @0x2aa534 addvc r6, r3, #69 */
/* @0x2aa538 .word 0x87f0e8bd */
/* @0x2aa53c svcmi #0xf7e92d */
/* @0x2aa540 stmdavs r3, {r2, r9, r11, r12, sp, lr} */
/* @0x2aa544 .word 0xf0402c00 */
/* @0x2aa548 ldrdlt r8, r9, [r10, -r7] */
/* @0x2aa54c and r8, r0, r4, lsl r9 */
/* @0x2aa550 bvc 0x13fbda8 <b2_toiTime+0xca2904> */
/* @0x2aa554 vadd.f32 d2, d0, d7 */
/* @0x2aa558 stchs p0, c8, [r2, #-520] */
/* @0x2aa55c stchs p0, c13, [r4, #-184] */
/* @0x2aa560 stchs p0, c13, [r1, #-344] */
/* @0x2aa564 .word 0xf004d177 */
/* @0x2aa568 .word 0xf04f0401 */
/* @0x2aa56c .word 0xf1030cff */
/* @0x2aa570 ldclne p8, c3, [lr, #1020] */
/* @0x2aa574 .word 0xf404fb0c */
/* @0x2aa578 ldrbeq lr, [r8, r1, lsl #22] */
/* @0x2aa57c strmi r4, [r8], #1014 */
/* @0x2aa580 streq pc, [r7], -r6 */
/* @0x2aa584 stmdbeq r3, {r0, r1, r2, r3, r5, r6, r9, r11, sp, lr, pc} */
/* @0x2aa588 ldrblo pc, [pc, #0x108]! */
/* @0x2aa58c strbtmi r4, [r1], r8, asr #9 */
/* @0x2aa590 strbmi r11, [r5, #-0x2a4] */
/* @0x2aa594 .word 0xf897d05f */
/* @0x2aa598 stclo p0, c12, [r1, #-0] */
/* @0x2aa59c .word 0xfc06fa4c */
/* @0x2aa5a0 .word 0x0c01f01c */
/* @0x2aa5a4 .word 0xf885bf14 */
/* @0x2aa5a8 .word 0xf8859002 */
/* @0x2aa5ac cdphs p0, #0x0, c12, c7, c2, #0x0 */
/* @0x2aa5b0 .word 0xf107bf0a */
/* @0x2aa5b4 .word 0x360137ff */
/* @0x2aa5b8 strb r2, [r10, r0, lsl #12]! */
/* @0x2aa5bc streq pc, [r3], #-4 */
/* @0x2aa5c0 mrcne p5, #0x2, r2, c14, c5, #0x2 */
/* @0x2aa5c4 ldclne p3, c4, [sp], {108} */
/* @0x2aa5c8 fldmiaxeq r6, {d14} */
/* @0x2aa5cc .word 0x43ed440e */
/* @0x2aa5d0 streq pc, [r3, #-0x5] */
/* @0x2aa5d4 stmdaeq r6, {r0, r1, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2aa5d8 strbmi r0, [r6, #-0x6d] */
/* @0x2aa5dc .word 0xf89cd03b */
/* @0x2aa5e0 stchs p0, c7, [r6, #-0] */
/* @0x2aa5e4 .word 0xf10cbf08 */
/* @0x2aa5e8 blx 0x14799ec <b2_toiTime+0xd20548> */
/* @0x2aa5ec svclt #0x8f705 */
/* @0x2aa5f0 .word 0xf0072500 */
/* @0x2aa5f4 svclt #0x180703 */
/* @0x2aa5f8 b 0x1677a08 <b2_toiTime+0xf1e564> */
/* @0x2aa5fc b 0x14f0a20 <b2_toiTime+0xd9757c> */
/* @0x2aa600 b 0x14ecc24 <b2_toiTime+0xd93780> */
/* @0x2aa604 b 0x14eca28 <b2_toiTime+0xd93584> */
/* @0x2aa608 .word 0xf8061787 */
/* @0x2aa60c strb r7, [r4, r1, lsl #18]! */
/* @0x2aa610 streq pc, [pc], #-4 */
/* @0x2aa614 .word 0xf0132511 */
/* @0x2aa618 blx 0x3ee226 */
/* @0x2aa61c .word 0xf103f404 */
/* @0x2aa620 svclt #0xc35ff */
/* @0x2aa624 strhs r2, [r4], -r0, lsl #12 */
/* @0x2aa628 ldrbeq lr, [r5, -r1, lsl #22] */
/* @0x2aa62c bl 0xff37b668 <b2_toiTime+0xfffffffffec221c4> */
/* @0x2aa630 strbmi r0, [r5, #-0x805] */
/* @0x2aa634 .word 0xf897d00f */
/* @0x2aa638 blx 0x15da640 <b2_toiTime+0xe8119c> */
/* @0x2aa63c .word 0xf00cfc06 */
/* @0x2aa640 b 0x15ad684 <b2_toiTime+0xe541e0> */
/* @0x2aa644 .word 0xf8051c0c */
/* @0x2aa648 tstlt r6, r1, lsl #18 */
/* @0x2aa64c strhs r3, [r0], -r1, lsl #30 */
/* @0x2aa650 strhs lr, [r4], -pc, ror #15 */
/* @0x2aa654 strhs lr, [r8, #-0x7ed] */
/* @0x2aa658 subvc r6, r5, #67 */
/* @0x2aa65c bhs 0x2c7178 <_ZNK6b2Body13ShouldCollideEPKS_+0x20> */
/* @0x2aa660 rscshi pc, r5, r0 */
/* @0x2aa664 bhs 0x4c8f74 <SrcVerts+0x25fb8> */
/* @0x2aa668 mrcne p1, #0x2, sp, c13, c6, #0x0 */
/* @0x2aa66c subeq lr, r3, #1024 */
/* @0x2aa670 rsclt r4, r4, #687865856 */
/* @0x2aa674 bne 0xff638e84 <b2_toiTime+0xfffffffffeedf9e0> */
/* @0x2aa678 .word 0xf04f27ff */
/* @0x2aa67c adcsmi r0, r1, #0, #24 */
/* @0x2aa680 .word 0xf811d01a */
/* @0x2aa684 adcmi r5, r5, #16384 */
/* @0x2aa688 shadd16mi r11, sp, r4 */
/* @0x2aa68c subsvc r4, r5, r5, ror #12 */
/* @0x2aa690 .word 0xf802784d */
/* @0x2aa694 ldrb r5, [r2, r2, lsl #18]! */
/* @0x2aa698 .word 0xd10d2a10 */
/* @0x2aa69c .word 0xf3c46845 */
/* @0x2aa6a0 rsclt r2, r4, #1792 */
/* @0x2aa6a4 stmdbne r10, {r0, r1, r2, r3, r4, r5, r6, r7, r9, r10, sp} ^ */
/* @0x2aa6a8 .word 0x0145eb01 */
/* @0x2aa6ac strhs r3, [r0, #-0xa03] */
/* @0x2aa6b0 strtmi r3, [pc], -r3, lsl #18 */
/* @0x2aa6b4 swple r4, sp, [r6] */
/* @0x2aa6b8 andvc r2, r2, #4, #4 */
/* @0x2aa6bc addvc r2, r2, #536870912 */
/* @0x2aa6c0 subseq r7, r2, r2, asr #20 */
/* @0x2aa6c4 .word 0xf892e07b */
/* @0x2aa6c8 strbmi r8, [r0, #0x1]! */
/* @0x2aa6cc .word 0xf892d106 */
/* @0x2aa6d0 strmi r8, [r0, #0x2]! */
/* @0x2aa6d4 addvc sp, pc, r2, lsl #2 */
/* @0x2aa6d8 and r7, r1, pc, asr #32 */
/* @0x2aa6dc subvc r7, lr, lr, lsl #1 */
/* @0x2aa6e0 mulhi r2, r2, r8 */
/* @0x2aa6e4 blo 0x337af0 */
/* @0x2aa6e8 .word 0xf8813904 */
/* @0x2aa6ec .word 0xf8928004 */
/* @0x2aa6f0 .word 0xf8818003 */
/* @0x2aa6f4 ldrb r8, [sp, r3] */
/* @0x2aa6f8 .word 0xf0402c02 */
/* @0x2aa6fc bhs 0x2ca9a4 <_ZN7b2World9DrawShapeEP9b2FixtureRK11b2TransformRK7b2Color+0x140> */
/* @0x2aa700 adchi pc, r5, r0 */
/* @0x2aa704 .word 0x2c087a44 */
/* @0x2aa708 ldmvc r5, {r0, r4, r5, r8, r12, lr, pc} */
/* @0x2aa70c ldmdbvc r6, {r0, r1, r10, sp} */
/* @0x2aa710 ldcleq p0, c15, [pc], #316 */
/* @0x2aa714 .word 0xf04f7997 */
/* @0x2aa718 stmdavs r2, {r11} ^ */
/* @0x2aa71c strmi r3, [r10], #-2561 */
/* @0x2aa720 orreq lr, r3, r1, lsl #22 */
/* @0x2aa724 blx 0x3b8b36 <error_g0017+0x117da> */
/* @0x2aa728 adcmi r2, r2, #318767104 */
/* @0x2aa72c .word 0xf812d041 */
/* @0x2aa730 strmi r9, [r9, #0xc02]! */
/* @0x2aa734 .word 0xf812d10a */
/* @0x2aa738 ldrmi r9, [r1, #0xc01]! */
/* @0x2aa73c .word 0xf892d106 */
/* @0x2aa740 ldrmi r9, [r9, #0x0]! */
/* @0x2aa744 .word 0xf881d102 */
/* @0x2aa748 and r8, r1, r1 */
/* @0x2aa74c andgt pc, r1, r1, lsl #17 */
/* @0x2aa750 mulls r0, r2, r8 */
/* @0x2aa754 blo 0x378b6c <_ZTS13C_UTF16String+0xfc18> */
/* @0x2aa758 andls pc, r4, r1, lsl #17 */
/* @0x2aa75c mulls r2, r2, r8 */
/* @0x2aa760 andls pc, r3, r1, lsl #17 */
/* @0x2aa764 mulls r1, r2, r8 */
/* @0x2aa768 andls pc, r2, r1, lsl #17 */
/* @0x2aa76c .word 0x2c10e7dd */
/* @0x2aa770 rfeia r2! */
/* @0x2aa774 ldrbhs r8, [pc, #0x2]! */
/* @0x2aa778 strhls pc, [r4], -r2 */
/* @0x2aa77c strhge pc, [r6], -r2 */
/* @0x2aa780 b 0x1684890 <b2_toiTime+0xf2b3ec> */
/* @0x2aa784 b 0x16737ec <b2_toiTime+0xf1a348> */
/* @0x2aa788 strls r2, [r1], #-1817 */
/* @0x2aa78c b 0x1678f98 <b2_toiTime+0xf1faf4> */
/* @0x2aa790 strmi r2, [r10], #-3098 */
/* @0x2aa794 biceq lr, r3, r1, lsl #22 */
/* @0x2aa798 blx 0x1a737a0 <b2_toiTime+0x131a2fc> */
/* @0x2aa79c blx 0x1aa89c4 <b2_toiTime+0x134f520> */
/* @0x2aa7a0 blx 0x1aa8dcc <b2_toiTime+0x134f928> */
/* @0x2aa7a4 stmdblo r3, {r1, r3, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2aa7a8 .word 0xf8cd4626 */
/* @0x2aa7ac addsmi r12, r12, #0 */
/* @0x2aa7b0 andhs sp, r6, #12, #2 */
/* @0x2aa7b4 andhs r7, r4, #536870912 */
/* @0x2aa7b8 bvc 0x13471c8 <b2_toiTime+0xbedd24> */
/* @0x2aa7bc sbcslt r0, r2, #146 */
/* @0x2aa7c0 bhs 0x4872d0 <g_States+0x1908> */
/* @0x2aa7c4 ldmeq r2, {r0, r1, r2, r3, r4, r5, r8, r11, r12, lr, pc} ^ */
/* @0x2aa7c8 eors r4, pc, r3, asr r3 */
/* @0x2aa7cc .word 0xbc05f812 */
/* @0x2aa7d0 .word 0xc004f8dd */
/* @0x2aa7d4 tstle r8, r3, ror #11 */
/* @0x2aa7d8 .word 0xbc04f812 */
/* @0x2aa7dc tstle r4, r3, asr #11 */
/* @0x2aa7e0 .word 0xbc03f812 */
/* @0x2aa7e4 ldrhle r4, [r0, -r11] */
/* @0x2aa7e8 .word 0xbc02f812 */
/* @0x2aa7ec smlabtle r12, r11, r5, r4 */
/* @0x2aa7f0 .word 0xbc01f812 */
/* @0x2aa7f4 .word 0xc000f8dd */
/* @0x2aa7f8 smlattle r6, r3, r5, r4 */
/* @0x2aa7fc mullt r0, r2, r8 */
/* @0x2aa800 ldrdle r4, r5, [r2, -r3] */
/* @0x2aa804 subvc r7, lr, lr, lsl #1 */
/* @0x2aa808 addvc lr, sp, r1 */
/* @0x2aa80c .word 0xf892704d */
/* @0x2aa810 strlo r11, [r1], #-0 */
/* @0x2aa814 stmdblo r8, {r1, r2, r9, r11, r12, sp} */
/* @0x2aa818 andlt pc, r8, r1, lsl #17 */
/* @0x2aa81c mullt r5, r2, r8 */
/* @0x2aa820 andlt pc, r7, r1, lsl #17 */
/* @0x2aa824 mullt r4, r2, r8 */
/* @0x2aa828 andlt pc, r6, r1, lsl #17 */
/* @0x2aa82c mullt r3, r2, r8 */
/* @0x2aa830 andlt pc, r5, r1, lsl #17 */
/* @0x2aa834 mullt r2, r2, r8 */
/* @0x2aa838 andlt pc, r4, r1, lsl #17 */
/* @0x2aa83c mullt r1, r2, r8 */
/* @0x2aa840 andlt pc, r3, r1, lsl #17 */
/* @0x2aa844 cmpmi r3, #46923776 */
/* @0x2aa848 ldmeq r11, {r0, r1, r2, r8, r9, r12, sp} ^ */
/* @0x2aa84c andlt r6, r3, r3, asr #32 */
/* @0x2aa850 svchi #0xf0e8bd */
/* @0x2aa854 bvc 0x41801c <g_RomDisk+0x207fc> */
/* @0x2aa858 stchs p8, c6, [r2, #-16] */
/* @0x2aa85c bhs 0x2ded08 <_ZN13b2DynamicTree7BalanceEi+0x224> */
/* @0x2aa860 bvc 0x139e9f0 <b2_toiTime+0xc4554c> */
/* @0x2aa864 cmple pc, r8, lsl #22 */
/* @0x2aa868 strmi r1, [r11], -sp, lsl #18 */
/* @0x2aa86c andsle r4, r0, r9, lsr #5 */
/* @0x2aa870 movwlo r7, #0x385e */
/* @0x2aa874 .word 0x7c03f813 */
/* @0x2aa878 ldrshtne r1, [pc], #6 */
/* @0x2aa87c b 0x142ae5c <b2_toiTime+0xcd19b8> */
/* @0x2aa880 .word 0xf8132687 */
/* @0x2aa884 b 0x1449890 <b2_toiTime+0xcf03ec> */
/* @0x2aa888 ldcpl p6, c0, [r6, #860] */
/* @0x2aa88c blvs 0x328898 */
/* @0x2aa890 movwhs lr, #0x37ec */
/* @0x2aa894 movwhs r7, #0x1203 */
/* @0x2aa898 bvc 0x13872ac <b2_toiTime+0xc2de08> */
/* @0x2aa89c sbcvc r2, r3, #7168 */
/* @0x2aa8a0 ldmeq r11, {r1, r8, r11, r12, lr, pc} ^ */
/* @0x2aa8a4 and r4, r2, r12, asr r3 */
/* @0x2aa8a8 strlo r4, [r7], #-860 */
/* @0x2aa8ac subvs r0, r4, r4, ror #17 */
/* @0x2aa8b0 stchs p13, c11, [r6, #-960] */
/* @0x2aa8b4 bhs 0x2ded64 <_ZN13b2DynamicTree7BalanceEi+0x280> */
/* @0x2aa8b8 bvc 0x139e998 <b2_toiTime+0xc454f4> */
/* @0x2aa8bc teqle r3, r8, lsl #22 */
/* @0x2aa8c0 movwhs r4, #0x60d */
/* @0x2aa8c4 andsle r4, r1, r3, lsr #5 */
/* @0x2aa8c8 strlo r7, [r4, #-0x86e] */
/* @0x2aa8cc .word 0xcc04f815 */
/* @0x2aa8d0 .word 0x7c02f815 */
/* @0x2aa8d4 b 0x166ecb4 <b2_toiTime+0xf15810> */
/* @0x2aa8d8 cmneq r6, r12, ror #25 */
/* @0x2aa8dc strhs lr, [r12], r6, asr #20 */
/* @0x2aa8e0 ldrbeq lr, [r7], r6, asr #20 */
/* @0x2aa8e4 strbpl r5, [lr], #3478 */
/* @0x2aa8e8 strb r3, [r11, r1, lsl #6]! */
/* @0x2aa8ec andvc r2, r2, #805306368 */
/* @0x2aa8f0 addvc r2, r2, #268435456 */
/* @0x2aa8f4 bhs 0x489204 <g_States+0x383c> */
/* @0x2aa8f8 stmdble r2, {r1, r6, r7, r9, r12, sp, lr} */
/* @0x2aa8fc cmpmi r3, #13762560 */
/* @0x2aa900 cmpmi r3, #2 */
/* @0x2aa904 ldmeq r11, {r0, r1, r2, r8, r9, r12, sp} ^ */
/* @0x2aa908 ldcllt p0, c6, [r0, #268]! */
/* @0x2aa90c mrsle r2, apsr */
/* @0x2aa910 bvc 0x1356e64 <b2_toiTime+0xbfd9c0> */
/* @0x2aa914 .word 0xd1072a08 */
/* @0x2aa918 adcmi r4, r1, #12, #8 */
/* @0x2aa91c stmdavc r10, {r2, r12, lr, pc} */
/* @0x2aa920 .word 0xf8015c9a */
/* @0x2aa924 ldrb r2, [r8, r1, lsl #22]! */
/* @0x2aa928 strdeq r11, r12, [r0], -r0 */
/* @0x2aa92c ldrblt r4, [r0, #-0xbd5]! */
/* @0x2aa930 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2aa934 .word 0x4604b096 */
/* @0x2aa938 sadd16mi r6, lr, r10 */
/* @0x2aa93c .word 0xf8d09215 */
/* @0x2aa940 ldmdblt r10!, {r4, r5, r7, r8, sp} ^ */
/* @0x2aa944 .word 0x31e8f890 */
/* @0x2aa948 bmi 0xff695d70 <b2_toiTime+0xfffffffffef3c8cc> */
/* @0x2aa94c qasxmi r2, r8, r2 */
/* @0x2aa950 ldrbtmi r9, [r10], #-768 */
/* @0x2aa954 .word 0x31a8f8d4 */
/* @0x2aa958 cdp p6, #0x3, c15, c6, c11, #0x0 */
/* @0x2aa95c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2aa960 stc2l p7, c15, [r4, #-1004]! */
/* @0x2aa964 ldrsblo pc, [r4, -r4]! */
/* @0x2aa968 strle r0, [r10, #-0x4d9]! */
/* @0x2aa96c .word 0x21ccf894 */
/* @0x2aa970 strbvc pc, [r2, #0x504]! */
/* @0x2aa974 tstle r5, r3, lsl #20 */
/* @0x2aa978 ldrsblo pc, [r8, #132] */
/* @0x2aa97c stmibmi r3, {r0, r1, r5, r8, r11, r12, sp, pc} ^ */
/* @0x2aa980 ldrbtmi r4, [r9], #-1568 */
/* @0x2aa984 ldc2l p7, c15, [r2, #-1004] */
/* @0x2aa988 ldrhlo pc, [lr, #132] */
/* @0x2aa98c .word 0xf8d44628 */
/* @0x2aa990 .word 0xf8d411b0 */
/* @0x2aa994 movwls r2, #0x1d8 */
/* @0x2aa998 .word 0xf8d43101 */
/* @0x2aa99c .word 0xf7ff324c */
/* @0x2aa9a0 .word 0xe00efcfb */
/* @0x2aa9a4 ldrsbne pc, [r0, r4]! */
/* @0x2aa9a8 rfeia r4! */
/* @0x2aa9ac ldrdlo r2, r3, [r1, -lr] */
/* @0x2aa9b0 orrseq r11, r10, r2, lsr #2 */
/* @0x2aa9b4 .word 0xf504d502 */
/* @0x2aa9b8 and r7, r0, r4, lsl r2 */
/* @0x2aa9bc .word 0xf7ff2200 */
/* @0x2aa9c0 .word 0xf8d4fdbd */
/* @0x2aa9c4 .word 0xf4122130 */
/* @0x2aa9c8 andle r0, r8, r0, lsl #5 */
/* @0x2aa9cc ldrsbne pc, [r0, r4]! */
/* @0x2aa9d0 rscvc pc, r2, r4, lsl #10 */
/* @0x2aa9d4 addeq pc, r0, #66 */
/* @0x2aa9d8 .word 0xf0043101 */
/* @0x2aa9dc .word 0xf8d4ffa9 */
/* @0x2aa9e0 .word 0xf4133134 */
/* @0x2aa9e4 eorle r0, r3, r0, asr #31 */
/* @0x2aa9e8 ldrsbhs pc, [r0, r4]! */
/* @0x2aa9ec .word 0xf5044620 */
/* @0x2aa9f0 andlo r7, r1, #-2147483592 */
/* @0x2aa9f4 blx 0xff9689f6 <b2_toiTime+0xffffffffff20f552> */
/* @0x2aa9f8 movwhs r11, #0x11d0 */
/* @0x2aa9fc sbcslo pc, r4, #132, #16 */
/* @0x2aaa00 ldrsblo pc, [r4, -r4]! */
/* @0x2aaa04 biceq pc, r0, #50331648 */
/* @0x2aaa08 svceq #0x80f5b3 */
/* @0x2aaa0c stmibmi r0!, {r2, r8, r12, lr, pc} */
/* @0x2aaa10 ldrbtmi r4, [r9], #-1568 */
/* @0x2aaa14 stc2 p7, c15, [lr, #-1004]! */
/* @0x2aaa18 ldrsblo pc, [r4, -r4]! */
/* @0x2aaa1c biceq pc, r0, #50331648 */
/* @0x2aaa20 svcne #0xf5b3 */
/* @0x2aaa24 ldmibmi r11, {r2, r8, r12, lr, pc} */
/* @0x2aaa28 ldrbtmi r4, [r9], #-1568 */
/* @0x2aaa2c ldc2l p7, c15, [lr], #1004 */
/* @0x2aaa30 ldrsblo pc, [r4, -r4]! */
/* @0x2aaa34 strle r0, [r10, #-0x45b] */
/* @0x2aaa38 .word 0x312cf8d4 */
/* @0x2aaa3c strle r0, [r6], #-1309 */
/* @0x2aaa40 ldrsbne pc, [r0, r4]! */
/* @0x2aaa44 rscvc pc, r2, r4, lsl #10 */
/* @0x2aaa48 .word 0xf7fe3101 */
/* @0x2aaa4c .word 0xf8d4fb2f */
/* @0x2aaa50 sasxeq r3, r8, r4 */
/* @0x2aaa54 rfeia r4! */
/* @0x2aaa58 ldmdblt r11, {r1, r2, r3, r4, r6, r7, r8, r12, sp} */
/* @0x2aaa5c .word 0x31eaf894 */
/* @0x2aaa60 strle r0, [r2, #-0x759]! */
/* @0x2aaa64 movwhs pc, #0x6204 */
/* @0x2aaa68 .word 0xf8d49300 */
/* @0x2aaa6c .word 0xf5043228 */
/* @0x2aaa70 .word 0xf8d470e2 */
/* @0x2aaa74 .word 0xf50411b0 */
/* @0x2aaa78 movwls r7, #0x1214 */
/* @0x2aaa7c .word 0xf8d43101 */
/* @0x2aaa80 movwls r3, #0x222c */
/* @0x2aaa84 eorslo pc, r0, #212, #16 */
/* @0x2aaa88 .word 0xf8d49303 */
/* @0x2aaa8c movwls r3, #0x4234 */
/* @0x2aaa90 eorslo pc, r8, #212, #16 */
/* @0x2aaa94 .word 0xf8d49305 */
/* @0x2aaa98 movwls r3, #0x623c */
/* @0x2aaa9c andslo pc, r12, #212, #16 */
/* @0x2aaaa0 .word 0xf5049307 */
/* @0x2aaaa4 .word 0xf7fe73fe */
/* @0x2aaaa8 .word 0xf8d4fdeb */
/* @0x2aaaac ldreq r3, [r10], #308 */
/* @0x2aaab0 sadd16eq sp, r11, r10 */
/* @0x2aaab4 rfeia r4! */
/* @0x2aaab8 stmiblt r11!, {r1, r2, r3, r4, r6, r7, r8, r12, sp} */
/* @0x2aaabc .word 0x31eaf894 */
/* @0x2aaac0 ldrle r0, [r1], #-1885 */
/* @0x2aaac4 .word 0x31eaf894 */
/* @0x2aaac8 andle r2, sp, r3, lsl #22 */
/* @0x2aaacc andslo pc, r12, #212, #16 */
/* @0x2aaad0 rscvc pc, r2, r4, lsl #10 */
/* @0x2aaad4 ldrsbne pc, [r0, r4]! */
/* @0x2aaad8 eorhs pc, r8, #212, #16 */
/* @0x2aaadc .word 0x31019300 */
/* @0x2aaae0 eorslo pc, r4, #212, #16 */
/* @0x2aaae4 blx 0xa8ae8 */
/* @0x2aaae8 ldrsblo pc, [r4, -r4]! */
/* @0x2aaaec strle r0, [r6, #-0x558] */
/* @0x2aaaf0 ldrsbne pc, [r0, r4]! */
/* @0x2aaaf4 rscvc pc, r2, r4, lsl #10 */
/* @0x2aaaf8 .word 0xf7fe3101 */
/* @0x2aaafc .word 0xf8d4f915 */
/* @0x2aab00 uasxeq r3, r9, r4 */
/* @0x2aab04 .word 0xf8d4d512 */
/* @0x2aab08 .word 0xf50411b0 */
/* @0x2aab0c .word 0xf8d470e2 */
/* @0x2aab10 strhlo r3, [r1, -r4] */
/* @0x2aab14 adcshs pc, r0, #212, #16 */
/* @0x2aab18 mrc2 p7, #0x4, apsr_nzcv, c12, c15, #0x7 */
/* @0x2aab1c .word 0x31c8f8d4 */
/* @0x2aab20 ldmdbmi sp, {r0, r1, r5, r8, r11, r12, sp, pc} ^ */
/* @0x2aab24 ldrbtmi r4, [r9], #-1568 */
/* @0x2aab28 stc2 p7, c15, [r0], {251} */
/* @0x2aab2c ldrsblo pc, [r4, -r4]! */
/* @0x2aab30 strle r0, [r6, #-0x69a] */
/* @0x2aab34 ldrsbne pc, [r0, r4]! */
/* @0x2aab38 rscvc pc, r2, r4, lsl #10 */
/* @0x2aab3c .word 0xf0043101 */
/* @0x2aab40 .word 0xf8d4fe8c */
/* @0x2aab44 .word 0x071b3134 */
/* @0x2aab48 .word 0xf8d4d508 */
/* @0x2aab4c .word 0xf50411b0 */
/* @0x2aab50 .word 0xf20470e2 */
/* @0x2aab54 .word 0x31012245 */
/* @0x2aab58 .word 0xf84bf7fe */
/* @0x2aab5c ldrsblo pc, [r4, -r4]! */
/* @0x2aab60 strle r0, [r6, #-0x75d] */
/* @0x2aab64 ldrsbne pc, [r0, r4]! */
/* @0x2aab68 rscvc pc, r2, r4, lsl #10 */
/* @0x2aab6c .word 0xf7fd3101 */
/* @0x2aab70 .word 0xf8d4ffde */
/* @0x2aab74 .word 0x07d83134 */
/* @0x2aab78 .word 0xf8d4d506 */
/* @0x2aab7c .word 0xf50411b0 */
/* @0x2aab80 smlattlo r1, r2, r0, r7 */
/* @0x2aab84 .word 0xffb0f004 */
/* @0x2aab88 ldrsblo pc, [r4, -r4]! */
/* @0x2aab8c strle r0, [r6, #-0x3d9] */
/* @0x2aab90 ldrsbne pc, [r0, r4]! */
/* @0x2aab94 rscvc pc, r2, r4, lsl #10 */
/* @0x2aab98 .word 0xf0043101 */
/* @0x2aab9c .word 0xf8d4fea3 */
/* @0x2aaba0 ldrbeq r3, [r10], #-308 */
/* @0x2aaba4 .word 0xf8d4d50a */
/* @0x2aaba8 ldreq r3, [r11, #-0x12c] */
/* @0x2aabac .word 0xf8d4d506 */
/* @0x2aabb0 .word 0xf50411b0 */
/* @0x2aabb4 smlattlo r1, r2, r0, r7 */
/* @0x2aabb8 blx 0x20e8bb8 <b2_toiTime+0x198f714> */
/* @0x2aabbc ldrsblo pc, [r4, -r4]! */
/* @0x2aabc0 strle r0, [r10, #-0x41d] */
/* @0x2aabc4 ldrsbne pc, [r0, r4]! */
/* @0x2aabc8 rscvc pc, r2, r4, lsl #10 */
/* @0x2aabcc ldrhhs pc, [r2, #132]! */
/* @0x2aabd0 .word 0xf8d43101 */
/* @0x2aabd4 .word 0xf7fe3130 */
/* @0x2aabd8 .word 0xf8d4f972 */
/* @0x2aabdc tsteq r8, #52, #2 */
/* @0x2aabe0 .word 0xf8d4d506 */
/* @0x2aabe4 .word 0xf50411b0 */
/* @0x2aabe8 smlattlo r1, r2, r0, r7 */
/* @0x2aabec .word 0xf925f7fe */
/* @0x2aabf0 ldrsblo pc, [r4, -r4]! */
/* @0x2aabf4 strle r0, [r6, #-0x399] */
/* @0x2aabf8 ldrsbne pc, [r0, r4]! */
/* @0x2aabfc rscvc pc, r2, r4, lsl #10 */
/* @0x2aac00 .word 0xf7fe3101 */
/* @0x2aac04 .word 0xf8d4f8a9 */
/* @0x2aac08 .word 0x06da3134 */
/* @0x2aac0c .word 0xf8d4d506 */
/* @0x2aac10 .word 0xf50411b0 */
/* @0x2aac14 smlattlo r1, r2, r0, r7 */
/* @0x2aac18 cdp2 p0, #0x4, c15, c13, c4, #0x0 */
/* @0x2aac1c ldrsblo pc, [r4, -r4]! */
/* @0x2aac20 strle r0, [r7, #-0x2db]! */
/* @0x2aac24 ldrsbpl pc, [r12, -r4] */
/* @0x2aac28 .word 0xf8d4b135 */
/* @0x2aac2c .word 0x462021b0 */
/* @0x2aac30 mvnvc pc, r4, lsl #10 */
/* @0x2aac34 strmi r3, [r8, r1, lsl #4]! */
/* @0x2aac38 .word 0x3128f894 */
/* @0x2aac3c .word 0xf884b10b */
/* @0x2aac40 .word 0xf89431cd */
/* @0x2aac44 .word 0xb10b3129 */
/* @0x2aac48 biclo pc, lr, r4, lsl #17 */
/* @0x2aac4c .word 0x21cef894 */
/* @0x2aac50 .word 0x31cdf894 */
/* @0x2aac54 .word 0xf8d44353 */
/* @0x2aac58 sbcslt r2, r11, #196, #2 */
/* @0x2aac5c biclo pc, pc, r4, lsl #17 */
/* @0x2aac60 stmdble r2, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x2aac64 cmpmi r10, #14352384 */
/* @0x2aac68 cmpmi r10, #2 */
/* @0x2aac6c ldmeq r2, {r0, r1, r2, r9, r12, sp} ^ */
/* @0x2aac70 bichs pc, r8, r4, asr #17 */
/* @0x2aac74 ldmdavs r3!, {r0, r2, r4, r9, r11, r12, pc} */
/* @0x2aac78 mulle r1, r10, r2 */
/* @0x2aac7c stc p6, c15, [r10], #44 */
/* @0x2aac80 ldcllt p0, c11, [r0, #-88]! */
/* @0x2aac84 andseq r3, r4, r4, lsr #32 */
/* @0x2aac88 strdeq r2, r3, [lr], -r1 */
/* @0x2aac8c andeq r2, lr, r6, ror #1 */
/* @0x2aac90 andeq r2, lr, r7, ror r0 */
/* @0x2aac94 andeq r2, lr, pc, asr r0 */
/* @0x2aac98 andeq r1, lr, r10, lsl #31 */
/* @0x2aac9c andeq r0, r0, r0 */
/* @0x2aaca0 push {r3, r8, r11, sp} */
/* @0x2aaca4 stc p15, c4, [sp, #-960]! */
/* @0x2aaca8 strmi r8, [r4], -lr, lsl #22 */
/* @0x2aacac bvs 0xfe5263f4 <b2_toiTime+0xfffffffffddccf50> */
/* @0x2aacb0 ldc p0, c11, [pc, #524] */
/* @0x2aacb4 .word 0xeeb79ba9 */
/* @0x2aacb8 .word 0xf2008b00 */
/* @0x2aacbc cdp p0, #0xb, c8, c7, c5, #0x5 */
/* @0x2aacc0 vcmpe.f32 s14, s13 */
/* @0x2aacc4 vsqrt.f64 d23, d9 */
/* @0x2aacc8 vstrle s30, [r8, #-64] */
/* @0x2aaccc bgt 0xfe4e6314 <b2_toiTime+0xfffffffffdd8ce70> */
/* @0x2aacd0 bgt 0xfe5e6570 <b2_toiTime+0xfffffffffde8d0cc> */
/* @0x2aacd4 bgt 0xff5e67b8 <b2_toiTime+0xfffffffffee8d314> */
/* @0x2aacd8 blgt 0x5e6700 <g_SWFaavertbuff+0x13638> */
/* @0x2aacdc cdp p0, #0xb, c14, c0, c1, #0x0 */
/* @0x2aace0 strtmi r12, [r0], -r8, asr #22 */
/* @0x2aace4 orrvc pc, r0, pc, asr #8 */
/* @0x2aace8 .word 0xffdaf7fb */
/* @0x2aacec cdp p5, #0xb, c2, c6, c0, #0x0 */
/* @0x2aacf0 vldr d14, [pc] */
/* @0x2aacf4 .word 0xf8c4bb9b */
/* @0x2aacf8 cdp p2, #0x0, c0, c6, c8, #0x1 */
/* @0x2aacfc .word 0xf8d45a10 */
/* @0x2aad00 mrrc p2, #0x2, r6, r3, c8 */
/* @0x2aad04 vldr d2, [pc, #112] */
/* @0x2aad08 .word 0xeeb8ab96 */
/* @0x2aad0c .word 0xee877bc6 */
/* @0x2aad10 .word 0xec516b0b */
/* @0x2aad14 .word 0xf60b0b16 */
/* @0x2aad18 mrc p13, #0x5, lr, c0, c6, #0x1 */
/* @0x2aad1c .word 0xeeb67b4e */
/* @0x2aad20 .word 0xec41db00 */
/* @0x2aad24 .word 0xee060b16 */
/* @0x2aad28 vmov.f64 d23, #-2.109375e-01 */
/* @0x2aad2c vnmla.f64 d6, d22, d7 */
/* @0x2aad30 ldrbpl r3, [r3, #-0xa90]! */
/* @0x2aad34 .word 0xf5b53501 */
/* @0x2aad38 bicsle r7, lr, r0, lsl #31 */
/* @0x2aad3c ldrsbhs pc, [r4, -r4]! */
/* @0x2aad40 andsmi r4, r3, r11, lsl #23 */
/* @0x2aad44 .word 0xf0002b00 */
/* @0x2aad48 ldc p2, c8, [r4, #16] */
/* @0x2aad4c .word 0xeeb7ba88 */
/* @0x2aad50 strtmi r11, [r9], -r11, asr #21 */
/* @0x2aad54 .word 0xf7fb4620 */
/* @0x2aad58 strhs pc, [r0, #-0xfa3] */
/* @0x2aad5c bllt 0x5a6784 <g_SWFlineaavertbuff+0x536bc> */
/* @0x2aad60 eorseq pc, r0, #196, #16 */
/* @0x2aad64 bpl 0x6e6584 <g_SWFvertbuff+0x134bc> */
/* @0x2aad68 eorsvs pc, r0, #212, #16 */
/* @0x2aad6c blhs 0x9a5ec0 <b2_toiTime+0x24ca1c> */
/* @0x2aad70 blvc 0xff466858 <b2_toiTime+0xfffffffffed0d3b4> */
/* @0x2aad74 blvs 0x566798 <g_SWFlineaavertbuff+0x136d0> */
/* @0x2aad78 bleq 0x865ec4 <b2_toiTime+0x10ca20> */
/* @0x2aad7c stc p6, c15, [r2, #-44] */
/* @0x2aad80 blvc 0x1626848 <b2_toiTime+0xecd3a4> */
/* @0x2aad84 bleq 0x865e90 <b2_toiTime+0x10c9ec> */
/* @0x2aad88 blvc 0x5665a8 <g_SWFlineaavertbuff+0x134e0> */
/* @0x2aad8c blvs 0xff4a6984 <b2_toiTime+0xfffffffffed4d4e0> */
/* @0x2aad90 blo 0xfe6e65f0 <b2_toiTime+0xfffffffffdf8d14c> */
/* @0x2aad94 strlo r5, [r1, #-0x573] */
/* @0x2aad98 svcvc #0x80f5b5 */
/* @0x2aad9c strtmi sp, [r9], -r2, ror #3 */
/* @0x2aada0 .word 0xf7fb4620 */
/* @0x2aada4 ldc p15, c15, [r4, #500] */
/* @0x2aada8 .word 0xeeb77a89 */
/* @0x2aadac strhs r7, [r0, #-0xac7] */
/* @0x2aadb0 blvc 0xff526888 <b2_toiTime+0xfffffffffedcd3e4> */
/* @0x2aadb4 blx 0x6e6980 <g_SWFvertbuff+0x138b8> */
/* @0x2aadb8 cdp p15, #0x8, c11, c8, c12, #0x6 */
/* @0x2aadbc vldr d8, [r4, #28] */
/* @0x2aadc0 .word 0xf8c48a88 */
/* @0x2aadc4 svclt #0xd8022c */
/* @0x2aadc8 bhi 0xff4e68ac <b2_toiTime+0xfffffffffed8d408> */
/* @0x2aadcc bpl 0x6e65ec <g_SWFvertbuff+0x13524> */
/* @0x2aadd0 eorvs pc, r12, #212, #16 */
/* @0x2aadd4 blhs 0x8e5f28 <b2_toiTime+0x18ca84> */
/* @0x2aadd8 blvc 0xff4668c0 <b2_toiTime+0xfffffffffed0d41c> */
/* @0x2aaddc blvs 0x566800 <g_SWFlineaavertbuff+0x13738> */
/* @0x2aade0 bleq 0x865f2c <b2_toiTime+0x10ca88> */
/* @0x2aade4 stcl p6, c15, [lr], {11} */
/* @0x2aade8 blvc 0x16268b0 <b2_toiTime+0xecd40c> */
/* @0x2aadec bleq 0x865ef8 <b2_toiTime+0x10ca54> */
/* @0x2aadf0 blvc 0x566610 <g_SWFlineaavertbuff+0x13548> */
/* @0x2aadf4 blvs 0xff4a69ec <b2_toiTime+0xfffffffffed4d548> */
/* @0x2aadf8 blo 0xfe6e6658 <b2_toiTime+0xfffffffffdf8d1b4> */
/* @0x2aadfc strlo r5, [r1, #-0x573] */
/* @0x2aae00 svcvc #0x80f5b5 */
/* @0x2aae04 .word 0xe1a4d1e2 */
/* @0x2aae08 .word 0x31eaf890 */
/* @0x2aae0c strle r0, [r11, #-0x79a] */
/* @0x2aae10 sublo pc, r0, #144, #16 */
/* @0x2aae14 subpl pc, r1, #144, #16 */
/* @0x2aae18 svclt #0xb8429d */
/* @0x2aae1c .word 0xf890461d */
/* @0x2aae20 adcmi r3, r11, #536870916 */
/* @0x2aae24 and sp, r1, r4, lsl #24 */
/* @0x2aae28 subpl pc, r3, #144, #16 */
/* @0x2aae2c and r11, r2, sp, lsl #18 */
/* @0x2aae30 .word 0xf1c5461d */
/* @0x2aae34 .word 0xf8d40510 */
/* @0x2aae38 ldrbeq r3, [r11, #-0x134] */
/* @0x2aae3c stchs p5, c13, [r4, #-4] */
/* @0x2aae40 stchs p13, c13, [r8, #-16] */
/* @0x2aae44 b 0xc21e5c <b2_toiTime+0x4c89b8> */
/* @0x2aae48 and r7, r2, r5, ror #11 */
/* @0x2aae4c and r2, r0, r5, lsl #10 */
/* @0x2aae50 cdp p5, #0xb, c2, c7, c8, #0x0 */
/* @0x2aae54 .word 0xf1c57ae6 */
/* @0x2aae58 strhs r0, [r1], -r8, lsl #18 */
/* @0x2aae5c andspl pc, r12, #196, #16 */
/* @0x2aae60 .word 0xf609fa06 */
/* @0x2aae64 blvc 0xff52693c <b2_toiTime+0xfffffffffedcd498> */
/* @0x2aae68 blx 0x6e6a34 <g_SWFvertbuff+0x1396c> */
/* @0x2aae6c ldc p13, c13, [r4, #32] */
/* @0x2aae70 vmul.f32 s20, s13, s16 */
/* @0x2aae74 .word 0xeeb7aa8a */
/* @0x2aae78 .word 0xee88aaca */
/* @0x2aae7c and r10, r1, r10, lsl #22 */
/* @0x2aae80 blge 0x2e6964 <FT_Stream_ReadAt+0x20> */
/* @0x2aae84 .word 0x462000b2 */
/* @0x2aae88 ldrmi r9, [r1], -r0, lsl #4 */
/* @0x2aae8c .word 0xff24f7fb */
/* @0x2aae90 ldrsbvc pc, [r4, -r4]! */
/* @0x2aae94 .word 0x6790f417 */
/* @0x2aae98 eorseq pc, r4, #196, #16 */
/* @0x2aae9c strhs sp, [r0, -r10, rrx] */
/* @0x2aaea0 .word 0xf44f4620 */
/* @0x2aaea4 .word 0xf8d47100 */
/* @0x2aaea8 .word 0xf7fb8234 */
/* @0x2aaeac .word 0xf848fef9 */
/* @0x2aaeb0 strlo r0, [r1, -r7, lsr #32] */
/* @0x2aaeb4 blle 0xfff7b998 <b2_toiTime+0xffffffffff8224f4> */
/* @0x2aaeb8 blge 0x5668e0 <g_SWFlineaavertbuff+0x13818> */
/* @0x2aaebc bleq 0x2a7000 <png_read_info+0x10> */
/* @0x2aaec0 b 0x1674ac8 <b2_toiTime+0xf1b624> */
/* @0x2aaec4 blx 0x15756e4 <b2_toiTime+0xe1c240> */
/* @0x2aaec8 ldrtmi pc, [r8], r5, lsl #22 */
/* @0x2aaecc blgt 0xc66550 <b2_toiTime+0x50d0ac> */
/* @0x2aaed0 bllt 0x2e69b0 <FT_Stream_TryRead+0x10> */
/* @0x2aaed4 bhi 0x6e66f4 <g_SWFvertbuff+0x1362c> */
/* @0x2aaed8 blhs 0x96602c <b2_toiTime+0x20cb88> */
/* @0x2aaedc blvc 0xff4669c4 <b2_toiTime+0xfffffffffed0d520> */
/* @0x2aaee0 blvc 0x5a67c4 <g_SWFlineaavertbuff+0x536fc> */
/* @0x2aaee4 blvs 0x5e6788 <g_SWFaavertbuff+0x136c0> */
/* @0x2aaee8 bleq 0x866034 <b2_toiTime+0x10cb90> */
/* @0x2aaeec mcrr p6, #0x0, pc, r10, c11 */
/* @0x2aaef0 andhs lr, r8, #72, #20 */
/* @0x2aaef4 bge 0xfe6e6714 <b2_toiTime+0xfffffffffdf8d270> */
/* @0x2aaef8 mrc p2, #0x5, r11, c8, c2, #0x4 */
/* @0x2aaefc .word 0xec417be6 */
/* @0x2aaf00 .word 0xee260b16 */
/* @0x2aaf04 vmov.f64 d7, #-1.796875e-01 */
/* @0x2aaf08 vnmla.f64 d7, d23, d7 */
/* @0x2aaf0c addsmi r3, pc, #16, #20 */
/* @0x2aaf10 .word 0xf8d4d80b */
/* @0x2aaf14 b 0x4777ec <g_RomDisk+0x7ffcc> */
/* @0x2aaf18 blx 0xc6af4c <b2_toiTime+0x511aa8> */
/* @0x2aaf1c strlo pc, [r1, -r9, lsl #2] */
/* @0x2aaf20 eorlo pc, r0, r3, asr r8 */
/* @0x2aaf24 andshs pc, r1, r3, lsr #16 */
/* @0x2aaf28 .word 0xf108e7ef */
/* @0x2aaf2c .word 0xf5b80801 */
/* @0x2aaf30 bicle r7, pc, r0, lsl #31 */
/* @0x2aaf34 rscsvc pc, pc, #82837504 */
/* @0x2aaf38 subsle r4, lr, #364904448 */
/* @0x2aaf3c eorslo pc, r4, #212, #16 */
/* @0x2aaf40 andeq lr, r11, r7, lsl #20 */
/* @0x2aaf44 .word 0xf109fa27 */
/* @0x2aaf48 .word 0xf8533701 */
/* @0x2aaf4c .word 0xf8233020 */
/* @0x2aaf50 .word 0xe7f12011 */
/* @0x2aaf54 andhi pc, r0, pc, lsr #7 */
/* @0x2aaf58 adcsge lr, r5, sp, lsl #27 */
/* @0x2aaf5c mrclo p6, #0x5, r12, c0, c7, #0x7 */
/* @0x2aaf60 andeq r0, r0, r0 */
/* @0x2aaf64 rsbmi lr, pc, r0 */
/* @0x2aaf68 andeq r0, r0, r0 */
/* @0x2aaf6c svclo #0x700000 */
/* @0x2aaf70 rsbeq r0, r0, r0, lsl #1 */
/* @0x2aaf74 blgt 0x2e6a54 <FT_Stream_GetUOffset+0x22> */
/* @0x2aaf78 ldrsbls pc, [r0, #143]! */
/* @0x2aaf7c bllt 0x20e6600 <b2_toiTime+0x198d15c> */
/* @0x2aaf80 bl 0x4fc36c <SrcVerts+0x593b0> */
/* @0x2aaf84 strtmi r0, [r0], -r5, lsl #19 */
/* @0x2aaf88 .word 0x7100f44f */
/* @0x2aaf8c eorshi pc, r4, #212, #16 */
/* @0x2aaf90 mcr2 p7, #0x4, pc, c6, c11, #0x7 */
/* @0x2aaf94 ldrsblo pc, [r8], -r9 */
/* @0x2aaf98 bleq 0xfe4a58dc <b2_toiTime+0xfffffffffdd4c438> */
/* @0x2aaf9c b 0x167bd90 <b2_toiTime+0xf228ec> */
/* @0x2aafa0 .word 0xf8481a13 */
/* @0x2aafa4 .word 0xf04f0027 */
/* @0x2aafa8 bl 0x52cfb0 <SrcVerts+0x89ff4> */
/* @0x2aafac .word 0xf8d42208 */
/* @0x2aafb0 mcr p2, #0x0, r3, c7, c4, #0x1 */
/* @0x2aafb4 .word 0xf8532a10 */
/* @0x2aafb8 cdp p0, #0xb, c3, c8, c11, #0x0 */
/* @0x2aafbc movwls r7, #0x1bc7 */
/* @0x2aafc0 blhs 0x966114 <b2_toiTime+0x20cc70> */
/* @0x2aafc4 blvs 0x5a69e8 <g_SWFlineaavertbuff+0x53920> */
/* @0x2aafc8 bleq 0x866114 <b2_toiTime+0x10cc70> */
/* @0x2aafcc bl 0xff968800 <b2_toiTime+0xffffffffff20f35c> */
/* @0x2aafd0 vmov.f32 s18, #2.125000e+00 */
/* @0x2aafd4 .word 0xec417b4c */
/* @0x2aafd8 .word 0xee060b16 */
/* @0x2aafdc vmov.f64 d23, #-2.109375e-01 */
/* @0x2aafe0 vnmla.f64 d6, d22, d7 */
/* @0x2aafe4 .word 0xf8223a90 */
/* @0x2aafe8 .word 0xf1083018 */
/* @0x2aafec .word 0xf5b80801 */
/* @0x2aaff0 bicsle r7, r10, r0, lsl #31 */
/* @0x2aaff4 adcsmi r3, r7, #262144 */
/* @0x2aaff8 .word 0xf8d4dbc5 */
/* @0x2aaffc blmi 0x19334d4 <b2_toiTime+0x11da030> */
/* @0x2ab000 blhs 0x2bb054 <jinit_1pass_quantizer+0x324> */
/* @0x2ab004 adchi pc, r5, r0 */
/* @0x2ab008 ble 0xfe4e6660 <b2_toiTime+0xfffffffffdd8d1bc> */
/* @0x2ab00c ble 0xff626af0 <b2_toiTime+0xfffffffffeecd64c> */
/* @0x2ab010 stmdbls r0, {r5, r9, r10, lr} */
/* @0x2ab014 mcr2 p7, #0x3, pc, c0, c11, #0x7 */
/* @0x2ab018 ldrsbls pc, [r4, #-143] */
/* @0x2ab01c ldc p7, c2, [pc] */
/* @0x2ab020 ldrbtmi r11, [r9], #2896 */
/* @0x2ab024 stmibeq r5, {r0, r3, r8, r9, r11, sp, lr, pc} */
/* @0x2ab028 blle 0x626a50 <g_SWFaavertbuff+0x53988> */
/* @0x2ab02c eorseq pc, r12, #196, #16 */
/* @0x2ab030 blgt 0x2e6b10 <FT_Stream_ReadUShort+0xc> */
/* @0x2ab034 .word 0xf44f4620 */
/* @0x2ab038 .word 0xf8d47100 */
/* @0x2ab03c .word 0xf7fb523c */
/* @0x2ab040 b 0x16aa904 <b2_toiTime+0xf51460> */
/* @0x2ab044 .word 0xf04f0b87 */
/* @0x2ab048 .word 0xf8450800 */
/* @0x2ab04c .word 0xf8d90027 */
/* @0x2ab050 blx 0x3ff0ba <g_RomDisk+0x789a> */
/* @0x2ab054 b 0x16aa078 <b2_toiTime+0xf50bd4> */
/* @0x2ab058 .word 0xf8d41a1c */
/* @0x2ab05c mrc p2, #0x5, r3, c6, c12, #0x1 */
/* @0x2ab060 vldr d14, [pc] */
/* @0x2ab064 .word 0xf853ab3f */
/* @0x2ab068 movwls r3, #0x100b */
/* @0x2ab06c movwhs lr, #0x8b0a */
/* @0x2ab070 blo 0x6e6894 <g_SWFvertbuff+0x137cc> */
/* @0x2ab074 blhs 0xa261c8 <b2_toiTime+0x2ccd24> */
/* @0x2ab078 blvc 0xff4a6b60 <b2_toiTime+0xfffffffffed4d6bc> */
/* @0x2ab07c blvs 0x5a6aa0 <g_SWFlineaavertbuff+0x539d8> */
/* @0x2ab080 bleq 0x8661cc <b2_toiTime+0x10cd28> */
/* @0x2ab084 bl 0x22688b8 <b2_toiTime+0x1b0f414> */
/* @0x2ab088 vmov.f32 s18, #2.125000e+00 */
/* @0x2ab08c .word 0xec417b4c */
/* @0x2ab090 .word 0xee060b16 */
/* @0x2ab094 vmov.f64 d23, #-2.109375e-01 */
/* @0x2ab098 vnmla.f64 d6, d22, d7 */
/* @0x2ab09c .word 0xf8223a90 */
/* @0x2ab0a0 .word 0xf1083018 */
/* @0x2ab0a4 .word 0xf5b80801 */
/* @0x2ab0a8 bicsle r7, r6, r0, lsl #31 */
/* @0x2ab0ac adcsmi r3, r7, #262144 */
/* @0x2ab0b0 vldr d13, [r4, #768] */
/* @0x2ab0b4 .word 0xeeb77a89 */
/* @0x2ab0b8 strtmi r7, [r0], -r7, asr #21 */
/* @0x2ab0bc .word 0xf04f9900 */
/* @0x2ab0c0 strbmi r0, [pc], -r0, lsl #18 */
/* @0x2ab0c4 blvc 0xff526b9c <b2_toiTime+0xfffffffffedcd6f8> */
/* @0x2ab0c8 blx 0x6e6c94 <g_SWFvertbuff+0x13bcc> */
/* @0x2ab0cc ldc p15, c11, [r4, #856] */
/* @0x2ab0d0 vdiv.f32 s16, s17, s16 */
/* @0x2ab0d4 vmov.f64 d8, #1.437500e+00 */
/* @0x2ab0d8 .word 0xf7fb8ac8 */
/* @0x2ab0dc .word 0xf8c4fdfd */
/* @0x2ab0e0 qasxmi r0, r0, r8 */
/* @0x2ab0e4 .word 0x7100f44f */
/* @0x2ab0e8 eorshi pc, r8, #212, #16 */
/* @0x2ab0ec ldc2l p7, c15, [r8, #1004] */
/* @0x2ab0f0 bleq 0xfe4a5a34 <b2_toiTime+0xfffffffffdd4c590> */
/* @0x2ab0f4 bne 0x925a38 <b2_toiTime+0x1cc594> */
/* @0x2ab0f8 eoreq pc, r7, r8, asr #16 */
/* @0x2ab0fc stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2ab100 eorslo pc, r8, #212, #16 */
/* @0x2ab104 andlo pc, r11, r3, asr r8 */
/* @0x2ab108 bl 0x54fd10 <gp_ActiveMaskObjects+0xb048> */
/* @0x2ab10c cdp p3, #0x0, c2, c7, c8, #0x0 */
/* @0x2ab110 vmov r3, r3, s0, s1 */
/* @0x2ab114 .word 0xeeb82b18 */
/* @0x2ab118 .word 0xee877bc7 */
/* @0x2ab11c .word 0xec516b0a */
/* @0x2ab120 .word 0xf60b0b16 */
/* @0x2ab124 bls 0x2e5dec <FT_Face_GetVariantsOfChar+0xe> */
/* @0x2ab128 blvc 0x1666bf0 <b2_toiTime+0xf0d74c> */
/* @0x2ab12c bleq 0x866238 <b2_toiTime+0x10cd94> */
/* @0x2ab130 blvc 0x566950 <g_SWFlineaavertbuff+0x13888> */
/* @0x2ab134 blvs 0xff4a6d2c <b2_toiTime+0xfffffffffed4d888> */
/* @0x2ab138 blo 0xfe6e6998 <b2_toiTime+0xfffffffffdf8d4f4> */
/* @0x2ab13c andslo pc, r8, r2, lsr #16 */
/* @0x2ab140 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2ab144 svcvc #0x80f5b8 */
/* @0x2ab148 .word 0x3701d1da */
/* @0x2ab14c adcsmi r4, r7, #-1459617792 */
/* @0x2ab150 andlt sp, r3, r7, asr #23 */
/* @0x2ab154 blhi 0x666450 <g_SWFlinevertbuff+0x13388> */
/* @0x2ab158 svchi #0xf0e8bd */
/* @0x2ab15c andhi pc, r0, pc, lsr #7 */
/* @0x2ab160 andeq r0, r0, r0 */
/* @0x2ab164 rscmi pc, pc, r0, ror #31 */
/* @0x2ab168 rsbeq r0, r0, r0, lsl #1 */
/* @0x2ab16c andeq r4, lr, r12, lsr #20 */
/* @0x2ab170 andeq r4, lr, r10, lsl #19 */
/* @0x2ab174 andhi pc, r0, pc, lsr #7 */
/* @0x2ab178 svcmi #0xf0e92d */
/* @0x2ab17c blhi 0x4e6638 <SrcVerts+0x4367c> */
/* @0x2ab180 .word 0xf8d04604 */
/* @0x2ab184 addlt r3, r3, r4, lsr r1 */
/* @0x2ab188 .word 0xa1eaf890 */
/* @0x2ab18c strle r0, [r9, #-0x5dd] */
/* @0x2ab190 svceq #0x2f01a */
/* @0x2ab194 .word 0xf8d0d106 */
/* @0x2ab198 vst4.8 {d18, d20, d22, d24}, [r2:128], r12 */
/* @0x2ab19c .word 0xf8c06200 */
/* @0x2ab1a0 ands r2, r6, r12, lsr #2 */
/* @0x2ab1a4 addmi pc, r3, #50331648 */
/* @0x2ab1a8 svcmi #0x81f5b2 */
/* @0x2ab1ac rfeia r4! */
/* @0x2ab1b0 rfeia r4! */
/* @0x2ab1b4 addsmi r1, r1, #0, #4 */
/* @0x2ab1b8 rfeia r4! */
/* @0x2ab1bc addmi r2, r10, #536870912 */
/* @0x2ab1c0 .word 0xf8d4d107 */
/* @0x2ab1c4 .word 0xf8a4112c */
/* @0x2ab1c8 vst1.8 {d18, d19, d20, d21}, [r1], r4 */
/* @0x2ab1cc .word 0xf8c46100 */
/* @0x2ab1d0 vst4.8 {d1, d3, d5, d7}, [r3:128], r12 */
/* @0x2ab1d4 .word 0xf5b25288 */
/* @0x2ab1d8 cmple r10, r8, lsl #31 */
/* @0x2ab1dc svceq #0x2f01a */
/* @0x2ab1e0 .word 0xf894d134 */
/* @0x2ab1e4 bhs 0x333998 */
/* @0x2ab1e8 bhs 0x3df20c <error_g0017+0x37eb0> */
/* @0x2ab1ec bhs 0x31f218 */
/* @0x2ab1f0 rfeia r4! */
/* @0x2ab1f4 mvnshs r2, r4, lsl #4 */
/* @0x2ab1f8 rfeia r4! */
/* @0x2ab1fc cmphs r5, r4, lsl #4 */
/* @0x2ab200 rfeia r4! */
/* @0x2ab204 tsths r1, r4, lsl #4 */
/* @0x2ab208 orrseq r4, r8, r10, asr #6 */
/* @0x2ab20c .word 0xf8a4b292 */
/* @0x2ab210 .word 0xf8a42204 */
/* @0x2ab214 .word 0xf8a42202 */
/* @0x2ab218 .word 0xf8a42200 */
/* @0x2ab21c ldrtle r2, [r8], #-510 */
/* @0x2ab220 subslo pc, r8, #180, #16 */
/* @0x2ab224 addslt r4, r11, #738197505 */
/* @0x2ab228 subslo pc, r8, #164, #16 */
/* @0x2ab22c subslo pc, r6, #164, #16 */
/* @0x2ab230 subslo pc, r4, #164, #16 */
/* @0x2ab234 subslo pc, r2, #164, #16 */
/* @0x2ab238 rfeia r4! */
/* @0x2ab23c .word 0xf8a43204 */
/* @0x2ab240 .word 0xf8a43202 */
/* @0x2ab244 .word 0xf8a43200 */
/* @0x2ab248 .word 0xe02231fe */
/* @0x2ab24c svceq #0x3f1ba */
/* @0x2ab250 .word 0xf894d11f */
/* @0x2ab254 .word 0xf8d411fc */
/* @0x2ab258 bl 0x2eb9c0 <FT_Done_Memory+0x1d4c> */
/* @0x2ab25c stmdane r2, {r0, r6, r8} ^ */
/* @0x2ab260 .word 0xf8a45c41 */
/* @0x2ab264 ldmdavc r1, {r1, r2, r3, r4, r5, r6, r7, r8, r12} ^ */
/* @0x2ab268 andne pc, r0, #164, #16 */
/* @0x2ab26c .word 0xf8a47892 */
/* @0x2ab270 tsteq r10, #536870912 */
/* @0x2ab274 .word 0xf013d50d */
/* @0x2ab278 .word 0xd10a7300 */
/* @0x2ab27c ldrhne pc, [lr, #132] */
/* @0x2ab280 ble 0x43bcb4 <g_RomDisk+0x44494> */
/* @0x2ab284 subhs pc, r12, #212, #16 */
/* @0x2ab288 bicmi r5, r0, #208, #24 */
/* @0x2ab28c movwlo r5, #0x14d0 */
/* @0x2ab290 .word 0xf504e7f6 */
/* @0x2ab294 .word 0xf1ba73fe */
/* @0x2ab298 blgt 0x36eeac <_ZTS13C_UTF16String+0x5f58> */
/* @0x2ab29c andeq pc, r6, #196, #16 */
/* @0x2ab2a0 andne pc, r10, #196, #16 */
/* @0x2ab2a4 .word 0xf8a4881b */
/* @0x2ab2a8 .word 0xd129320e */
/* @0x2ab2ac ldrhhs pc, [lr, #132] */
/* @0x2ab2b0 ldcl p3, c11, [r4, #200] */
/* @0x2ab2b4 vldr s14, [r4, #544] */
/* @0x2ab2b8 vmul.f32 s12, s13, s18 */
/* @0x2ab2bc .word 0xeeb76a27 */
/* @0x2ab2c0 vmov.f64 d7, #1.000000e+00 */
/* @0x2ab2c4 vsub.f32 s12, s13, s12 */
/* @0x2ab2c8 vldr d6, [pc, #284] */
/* @0x2ab2cc vabs.f64 d7, d17 */
/* @0x2ab2d0 vcmpe.f64 d6, d6 */
/* @0x2ab2d4 vsqrt.f64 d22, d7 */
/* @0x2ab2d8 ldrle pc, [r1, #-0xa10] */
/* @0x2ab2dc addsmi r2, r3, #0, #6 */
/* @0x2ab2e0 .word 0xf8d4da08 */
/* @0x2ab2e4 stclpl p2, c1, [r9], {76} */
/* @0x2ab2e8 sbclt r3, r9, #16384 */
/* @0x2ab2ec stmdble r7, {r0, r2, r3, r4, r5, r6, r7, r8, r11, sp} */
/* @0x2ab2f0 ldrb r3, [r4, r1, lsl #6]! */
/* @0x2ab2f4 ldrsblo pc, [r4, -r4]! */
/* @0x2ab2f8 movwpl pc, #0x423 */
/* @0x2ab2fc teqlo r4, r4, asr #17 */
/* @0x2ab300 ldrsbhs pc, [r4, -r4]! */
/* @0x2ab304 ldrsbmi r4, [r3], -r6 */
/* @0x2ab308 .word 0xf0002b00 */
/* @0x2ab30c ldcl p2, c8, [r4, #792] */
/* @0x2ab310 .word 0xeef57a88 */
/* @0x2ab314 vneg.f32 s15, s0 */
/* @0x2ab318 .word 0xf000fa10 */
/* @0x2ab31c .word 0x462082be */
/* @0x2ab320 .word 0x11ebf894 */
/* @0x2ab324 ldc2 p7, c15, [r12], #1020 */
/* @0x2ab328 ldrsbhs pc, [r4, -r4]! */
/* @0x2ab32c addeq pc, r0, #18 */
/* @0x2ab330 addhi pc, r9, #0 */
/* @0x2ab334 svceq #0x3f1ba */
/* @0x2ab338 .word 0x31f4f894 */
/* @0x2ab33c cmphi r12, r0, asr #32 */
/* @0x2ab340 ldrhne pc, [r12, #132] */
/* @0x2ab344 .word 0xf8d42b02 */
/* @0x2ab348 rfeia r4! */
/* @0x2ab34c strdls r2, r3, [r1, -lr] */
/* @0x2ab350 .word 0xf8d4d111 */
/* @0x2ab354 rfeia r4! */
/* @0x2ab358 rfeia r4! */
/* @0x2ab35c ldcpl p2, c1, [pc], {2} */
/* @0x2ab360 mrrcpl p12, #0x1, r5, sp, c14 */
/* @0x2ab364 eorslo pc, r0, #212, #16 */
/* @0x2ab368 andls pc, r2, r3, lsl r8 */
/* @0x2ab36c andhi pc, r0, r3, lsl r8 */
/* @0x2ab370 andgt pc, r1, r3, lsl r8 */
/* @0x2ab374 blhs 0x3236a4 */
/* @0x2ab378 blvc 0x2e6e5c <FT_Stream_ReadULong+0x98> */
/* @0x2ab37c blhs 0x39f3c4 <ft_standard_glyph_names+0x6d0> */
/* @0x2ab380 ldcl p1, c13, [r4, #84] */
/* @0x2ab384 vldr s12, [r4, #504] */
/* @0x2ab388 vmul.f32 s20, s13, s18 */
/* @0x2ab38c .word 0xeeb7aa8a */
/* @0x2ab390 vcvt.f64.f32 d11, s13 */
/* @0x2ab394 .word 0xee87aaca */
/* @0x2ab398 vdiv.f64 d11, d7, d11 */
/* @0x2ab39c and r10, r10, r10, lsl #22 */
/* @0x2ab3a0 blt 0xfe5269f8 <b2_toiTime+0xfffffffffddcd554> */
/* @0x2ab3a4 blge 0x14a6e6c <b2_toiTime+0xd4d9c8> */
/* @0x2ab3a8 blt 0xff5a6e8c <b2_toiTime+0xfffffffffee4d9e8> */
/* @0x2ab3ac cdp p0, #0xb, c14, c0, c3, #0x0 */
/* @0x2ab3b0 vmov.f64 d10, d7 */
/* @0x2ab3b4 vldr d11, [pc, #284] */
/* @0x2ab3b8 vldr d6, [pc, #664] */
/* @0x2ab3bc vadd.f64 d8, d26, d23 */
/* @0x2ab3c0 vmov.f64 d7, d7 */
/* @0x2ab3c4 vcmpe.f64 d7, d7 */
/* @0x2ab3c8 .word 0xeeb67bc6 */
/* @0x2ab3cc vmov.f64 d25, #4.000000e+00 */
/* @0x2ab3d0 strle pc, [r6, #-0xa10] */
/* @0x2ab3d4 .word 0x71fef894 */
/* @0x2ab3d8 andvs pc, r0, #148, #16 */
/* @0x2ab3dc andpl pc, r2, #148, #16 */
/* @0x2ab3e0 cdp p0, #0x0, c14, c6, c8, #0x2 */
/* @0x2ab3e4 vmov r2, r3, s0, s1 */
/* @0x2ab3e8 .word 0xeeb82b1a */
/* @0x2ab3ec .word 0xee877b46 */
/* @0x2ab3f0 .word 0xec516b08 */
/* @0x2ab3f4 .word 0xf60b0b16 */
/* @0x2ab3f8 cdp p9, #0xb, c14, c0, c6, #0x6 */
/* @0x2ab3fc .word 0xec537b49 */
/* @0x2ab400 vmov d10, r2, r1 */
/* @0x2ab404 rfeia r4! */
/* @0x2ab408 cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab40c vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab410 vmls.f64 d6, d23, d7 */
/* @0x2ab414 .word 0xeeb81a10 */
/* @0x2ab418 vnmla.f64 d7, d6, d7 */
/* @0x2ab41c .word 0xee877a90 */
/* @0x2ab420 rscslt r6, pc, #8, #22 */
/* @0x2ab424 bleq 0x866570 <b2_toiTime+0x10d0cc> */
/* @0x2ab428 stmib r12!, {r0, r1, r3, r9, r10, r12, sp, lr, pc} */
/* @0x2ab42c blvc 0x1526ef4 <b2_toiTime+0xdcda50> */
/* @0x2ab430 blhs 0x966584 <b2_toiTime+0x20d0e0> */
/* @0x2ab434 bleq 0x866540 <b2_toiTime+0x10d09c> */
/* @0x2ab438 andne pc, r2, #180, #16 */
/* @0x2ab43c blvc 0x4e6c5c <SrcVerts+0x43ca0> */
/* @0x2ab440 blvs 0xff4a7038 <b2_toiTime+0xfffffffffed4db94> */
/* @0x2ab444 bne 0x6e6c68 <g_SWFvertbuff+0x13ba0> */
/* @0x2ab448 blvc 0x14a6f30 <b2_toiTime+0xd4da8c> */
/* @0x2ab44c bvs 0xfe6e6cac <b2_toiTime+0xfffffffffdf8d808> */
/* @0x2ab450 blvs 0x4e6e74 <SrcVerts+0x43eb8> */
/* @0x2ab454 mrrc p2, #0xf, r11, r1, c6 */
/* @0x2ab458 .word 0xf60b0b16 */
/* @0x2ab45c mrc p9, #0x5, lr, c0, c4, #0x4 */
/* @0x2ab460 .word 0xec417b49 */
/* @0x2ab464 .word 0xee060b16 */
/* @0x2ab468 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab46c vnmla.f64 d6, d22, d7 */
/* @0x2ab470 rsclt r5, sp, #144, #20 */
/* @0x2ab474 ldrhne pc, [lr, #132]! */
/* @0x2ab478 blhs 0x9a65cc <b2_toiTime+0x24d128> */
/* @0x2ab47c bne 0x6e6ca0 <g_SWFvertbuff+0x13bd8> */
/* @0x2ab480 blvc 0x14a6f68 <b2_toiTime+0xd4dac4> */
/* @0x2ab484 blvs 0x4e6ea8 <SrcVerts+0x43eec> */
/* @0x2ab488 bleq 0x8665d4 <b2_toiTime+0x10d130> */
/* @0x2ab48c ldmdb r10!, {r0, r1, r3, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2ab490 blvc 0x1526f58 <b2_toiTime+0xdcdab4> */
/* @0x2ab494 blhs 0x9a65e8 <b2_toiTime+0x24d144> */
/* @0x2ab498 bleq 0x8665a4 <b2_toiTime+0x10d100> */
/* @0x2ab49c andne pc, r0, #180, #16 */
/* @0x2ab4a0 blvc 0x4e6cc0 <SrcVerts+0x43d04> */
/* @0x2ab4a4 blvs 0xff4a709c <b2_toiTime+0xfffffffffed4dbf8> */
/* @0x2ab4a8 bne 0x6e6ccc <g_SWFvertbuff+0x13c04> */
/* @0x2ab4ac blvc 0x14a6f94 <b2_toiTime+0xd4daf0> */
/* @0x2ab4b0 bls 0xfe6e6d10 <b2_toiTime+0xfffffffffdf8d86c> */
/* @0x2ab4b4 blvs 0x4e6ed8 <SrcVerts+0x43f1c> */
/* @0x2ab4b8 .word 0xf989fa5f */
/* @0x2ab4bc bleq 0x866608 <b2_toiTime+0x10d164> */
/* @0x2ab4c0 stmdb r0!, {r0, r1, r3, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2ab4c4 blvc 0x1526f8c <b2_toiTime+0xdcdae8> */
/* @0x2ab4c8 blhs 0x9a661c <b2_toiTime+0x24d178> */
/* @0x2ab4cc bleq 0x8665d8 <b2_toiTime+0x10d134> */
/* @0x2ab4d0 andne pc, r2, #180, #16 */
/* @0x2ab4d4 blvc 0x4e6cf4 <SrcVerts+0x43d38> */
/* @0x2ab4d8 blvs 0xff4a70d0 <b2_toiTime+0xfffffffffed4dc2c> */
/* @0x2ab4dc bne 0x6e6d00 <g_SWFvertbuff+0x13c38> */
/* @0x2ab4e0 blvc 0x14a6fc8 <b2_toiTime+0xd4db24> */
/* @0x2ab4e4 bhi 0xfe6e6d44 <b2_toiTime+0xfffffffffdf8d8a0> */
/* @0x2ab4e8 blvs 0x4e6f0c <SrcVerts+0x43f50> */
/* @0x2ab4ec .word 0xf888fa5f */
/* @0x2ab4f0 bleq 0x86663c <b2_toiTime+0x10d198> */
/* @0x2ab4f4 stmdb r6, {r0, r1, r3, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2ab4f8 bleq 0x8a6604 <b2_toiTime+0x14d160> */
/* @0x2ab4fc blls 0x4e6d20 <SrcVerts+0x43d64> */
/* @0x2ab500 blvc 0xff5270f8 <b2_toiTime+0xfffffffffedcdc54> */
/* @0x2ab504 bgt 0xfe6e6d68 <b2_toiTime+0xfffffffffdf8d8c4> */
/* @0x2ab508 stc2 p10, c15, [r12], {95} */
/* @0x2ab50c movweq pc, #0x110b */
/* @0x2ab510 stmdbls r1, {r9, sp} */
/* @0x2ab514 ble 0x1d3bf44 <b2_toiTime+0x15e2aa0> */
/* @0x2ab518 ldrhne pc, [lr, #132] */
/* @0x2ab51c ble 0x173bf4c <b2_toiTime+0xfe2aa8> */
/* @0x2ab520 subne pc, r12, #212, #16 */
/* @0x2ab524 ldmibhs pc!, {r0, r3, r7, r10, r11, r12, lr} ^ */
/* @0x2ab528 stmdblt r1!, {r0, r2, r3, r6, r12, lr, pc} */
/* @0x2ab52c .word 0x7c01f803 */
/* @0x2ab530 subsvc r7, sp, lr, lsl r0 */
/* @0x2ab534 .word 0xf8d4e058 */
/* @0x2ab538 .word 0xf8130230 */
/* @0x2ab53c .word 0xf810bc01 */
/* @0x2ab540 .word 0xf1c1b00b */
/* @0x2ab544 blx 0x2ab94a <png_init_read_transformations+0x7d2> */
/* @0x2ab548 blx 0x5a7576 <g_SWFlineaavertbuff+0x544ae> */
/* @0x2ab54c .word 0xf8d40101 */
/* @0x2ab550 .word 0xf893022c */
/* @0x2ab554 orrlo r11, r0, r0 */
/* @0x2ab558 bl 0x317f84 <__gxx_personality_v0+0x4> */
/* @0x2ab55c vorr.i32 d18, #0x91 */
/* @0x2ab560 mcrrpl p1, #0x0, r2, r1, c7 */
/* @0x2ab564 .word 0x1c01f803 */
/* @0x2ab568 subne pc, r12, #212, #16 */
/* @0x2ab56c .word 0xf8d45c88 */
/* @0x2ab570 .word 0xf8111230 */
/* @0x2ab574 .word 0xf1c0b00b */
/* @0x2ab578 blx 0x2ebd7e <FT_Done_Memory+0x210a> */
/* @0x2ab57c blx 0x5a79a6 <g_SWFlineaavertbuff+0x548de> */
/* @0x2ab580 .word 0xf8d41100 */
/* @0x2ab584 .word 0xf893022c */
/* @0x2ab588 orrlo r11, r0, r1 */
/* @0x2ab58c bl 0x317fb8 <__gxx_personality_v0+0x38> */
/* @0x2ab590 vorr.i32 d18, #0x91 */
/* @0x2ab594 mcrrpl p1, #0x0, r2, r1, c7 */
/* @0x2ab598 .word 0xf8d47019 */
/* @0x2ab59c stcpl p2, c1, [r8], {76} */
/* @0x2ab5a0 eorsne pc, r0, #212, #16 */
/* @0x2ab5a4 andlt pc, r11, r1, lsl r8 */
/* @0x2ab5a8 mvnseq pc, r0, asr #3 */
/* @0x2ab5ac .word 0xf10cfb01 */
/* @0x2ab5b0 .word 0x1100fb0b */
/* @0x2ab5b4 eoreq pc, r12, #212, #16 */
/* @0x2ab5b8 addlt r3, r9, #128, #2 */
/* @0x2ab5bc tsths r1, r1, lsl #22 */
/* @0x2ab5c0 smlabths r7, r1, r3, pc */
/* @0x2ab5c4 .word 0xf813e00e */
/* @0x2ab5c8 .word 0xf8d40c01 */
/* @0x2ab5cc .word 0x5c091228 */
/* @0x2ab5d0 .word 0xf8037818 */
/* @0x2ab5d4 .word 0xf8d41c01 */
/* @0x2ab5d8 .word 0x5c091228 */
/* @0x2ab5dc andsvc r7, r9, r8, asr r8 */
/* @0x2ab5e0 eorne pc, r8, #212, #16 */
/* @0x2ab5e4 subsvc r5, r9, r9, lsl #24 */
/* @0x2ab5e8 movwlo r3, #0x3201 */
/* @0x2ab5ec .word 0xf8d4e791 */
/* @0x2ab5f0 vld4.8 {d3, d5, d7, d9}, [r3:256], r4 */
/* @0x2ab5f4 .word 0xe1a75302 */
/* @0x2ab5f8 .word 0x21ebf894 */
/* @0x2ab5fc blhs 0x333a08 */
/* @0x2ab600 blls 0x2e70e4 <FT_Angle_Diff+0x4> */
/* @0x2ab604 vpmax.s8 d15, d2, d1 */
/* @0x2ab608 rscslo pc, pc, #-2147483648 */
/* @0x2ab60c bhs 0x6e6e2c <g_SWFvertbuff+0x13d64> */
/* @0x2ab610 blhi 0x14670f8 <b2_toiTime+0xd0dc54> */
/* @0x2ab614 blhs 0x39f63c <ft_standard_glyph_names+0x948> */
/* @0x2ab618 addmi sp, r11, #9 */
/* @0x2ab61c ldc p1, c13, [r4, #136] */
/* @0x2ab620 .word 0xeeb7aa89 */
/* @0x2ab624 eor r10, r4, r10, asr #21 */
/* @0x2ab628 bvc 0xfe4e6d80 <b2_toiTime+0xfffffffffdd8d8dc> */
/* @0x2ab62c ldcl p0, c14, [r4, #4] */
/* @0x2ab630 vldr s14, [r4, #504] */
/* @0x2ab634 vmul.f32 s14, s15, s18 */
/* @0x2ab638 .word 0xeeb77a87 */
/* @0x2ab63c vcvt.f64.f32 d10, s15 */
/* @0x2ab640 .word 0xee897ac7 */
/* @0x2ab644 vdiv.f64 d10, d9, d10 */
/* @0x2ab648 ands r9, r2, r7, lsl #22 */
/* @0x2ab64c andhi pc, r0, pc, lsr #7 */
/* @0x2ab650 ldmibls r9, {r1, r3, r4, r7, r8, r11, r12, pc} */
/* @0x2ab654 svclo #0xa99999 */
/* @0x2ab658 andeq r0, r0, r0 */
/* @0x2ab65c rsbmi lr, pc, r0 */
/* @0x2ab660 rsbeq r2, r0, r0 */
/* @0x2ab664 strtmi r4, [r0], -r2, ror #19 */
/* @0x2ab668 blge 0x1527130 <b2_toiTime+0xdcdc8c> */
/* @0x2ab66c .word 0xf7fa4479 */
/* @0x2ab670 rfeia r4! */
/* @0x2ab674 cdp p2, #0xb, c1, c6, c4, #0x0 */
/* @0x2ab678 .word 0xec53bb00 */
/* @0x2ab67c .word 0xee072b1a */
/* @0x2ab680 .word 0xeeb81a10 */
/* @0x2ab684 .word 0xee877b47 */
/* @0x2ab688 .word 0xec516b08 */
/* @0x2ab68c .word 0xf60b0b16 */
/* @0x2ab690 mrc p8, #0x5, lr, c0, c10, #0x3 */
/* @0x2ab694 .word 0xec417b4b */
/* @0x2ab698 rfeia r4! */
/* @0x2ab69c cdp p2, #0x0, c1, c6, c4, #0x0 */
/* @0x2ab6a0 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab6a4 vmls.f64 d6, d23, d7 */
/* @0x2ab6a8 .word 0xeeb81a10 */
/* @0x2ab6ac vnmla.f64 d7, d6, d7 */
/* @0x2ab6b0 .word 0xee873a90 */
/* @0x2ab6b4 .word 0xf8a46b08 */
/* @0x2ab6b8 mrrc p2, #0x0, r3, r3, c14 */
/* @0x2ab6bc vmov r2, r1, d9 */
/* @0x2ab6c0 .word 0xf60b0b16 */
/* @0x2ab6c4 cdp p8, #0xb, c14, c0, c0, #0x3 */
/* @0x2ab6c8 .word 0xec417b4b */
/* @0x2ab6cc rfeia r4! */
/* @0x2ab6d0 rfeia r4! */
/* @0x2ab6d4 cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab6d8 addmi r7, r1, #8, #22 */
/* @0x2ab6dc blvs 0xff4a72d4 <b2_toiTime+0xfffffffffed4de30> */
/* @0x2ab6e0 bhs 0xfe6e6f40 <b2_toiTime+0xfffffffffdf8da9c> */
/* @0x2ab6e4 .word 0xf8a4b292 */
/* @0x2ab6e8 .word 0xd1062204 */
/* @0x2ab6ec andlo pc, r2, #180, #16 */
/* @0x2ab6f0 smlabble r2, r11, r2, r4 */
/* @0x2ab6f4 .word 0xf0004293 */
/* @0x2ab6f8 mcr p0, #0x0, r8, c6, c9, #0x4 */
/* @0x2ab6fc vmov r0, r3, s0, s1 */
/* @0x2ab700 .word 0xeeb82b1a */
/* @0x2ab704 .word 0xee877b46 */
/* @0x2ab708 .word 0xec516b08 */
/* @0x2ab70c .word 0xf60b0b16 */
/* @0x2ab710 mrc p8, #0x5, lr, c0, c10, #0x1 */
/* @0x2ab714 .word 0xec417b4b */
/* @0x2ab718 rfeia r4! */
/* @0x2ab71c cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab720 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab724 vmls.f64 d6, d23, d7 */
/* @0x2ab728 .word 0xeeb81a10 */
/* @0x2ab72c vnmla.f64 d7, d6, d7 */
/* @0x2ab730 .word 0xee873a90 */
/* @0x2ab734 .word 0xf8a46b08 */
/* @0x2ab738 mrrc p2, #0x0, r3, r3, c8 */
/* @0x2ab73c vmov r2, r1, d10 */
/* @0x2ab740 .word 0xf60b0b16 */
/* @0x2ab744 cdp p8, #0xb, c14, c0, c0, #0x1 */
/* @0x2ab748 .word 0xec417b4b */
/* @0x2ab74c rfeia r4! */
/* @0x2ab750 cdp p2, #0x0, c1, c6, c2, #0x0 */
/* @0x2ab754 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab758 vmls.f64 d6, d23, d7 */
/* @0x2ab75c .word 0xeeb81a10 */
/* @0x2ab760 vnmla.f64 d7, d6, d7 */
/* @0x2ab764 .word 0xee873a90 */
/* @0x2ab768 .word 0xf8a46b08 */
/* @0x2ab76c mrrc p2, #0x0, r3, r3, c10 */
/* @0x2ab770 vmov r2, r1, d10 */
/* @0x2ab774 .word 0xf60b0b16 */
/* @0x2ab778 cdp p8, #0xb, c14, c0, c6, #0x0 */
/* @0x2ab77c .word 0xec417b4b */
/* @0x2ab780 rfeia r4! */
/* @0x2ab784 mcr p1, #0x0, r1, c6, c14, #0x7 */
/* @0x2ab788 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab78c vmls.f64 d6, d23, d7 */
/* @0x2ab790 .word 0xeeb81a10 */
/* @0x2ab794 vnmla.f64 d7, d6, d7 */
/* @0x2ab798 .word 0xee873a90 */
/* @0x2ab79c .word 0xf8a46b08 */
/* @0x2ab7a0 mrrc p2, #0x0, r3, r3, c12 */
/* @0x2ab7a4 vmov r2, r1, d9 */
/* @0x2ab7a8 .word 0xf60a0b16 */
/* @0x2ab7ac cdp p15, #0xb, c14, c0, c12, #0x7 */
/* @0x2ab7b0 .word 0xec417b4b */
/* @0x2ab7b4 rfeia r4! */
/* @0x2ab7b8 cdp p2, #0x0, c1, c6, c0, #0x0 */
/* @0x2ab7bc vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab7c0 vmls.f64 d6, d23, d7 */
/* @0x2ab7c4 .word 0xeeb81a10 */
/* @0x2ab7c8 vnmla.f64 d7, d6, d7 */
/* @0x2ab7cc .word 0xee873a90 */
/* @0x2ab7d0 .word 0xf8a46b08 */
/* @0x2ab7d4 mrrc p1, #0xf, r3, r3, c14 */
/* @0x2ab7d8 vmov r2, r1, d9 */
/* @0x2ab7dc .word 0xf60a0b16 */
/* @0x2ab7e0 mrc p15, #0x5, lr, c0, c2, #0x6 */
/* @0x2ab7e4 .word 0xec417b4b */
/* @0x2ab7e8 rfeia r4! */
/* @0x2ab7ec cdp p2, #0x0, c1, c6, c2, #0x0 */
/* @0x2ab7f0 vmov.f64 d23, #-1.875000e-01 */
/* @0x2ab7f4 vmls.f64 d6, d23, d7 */
/* @0x2ab7f8 .word 0xeeb81a10 */
/* @0x2ab7fc vnmla.f64 d7, d6, d7 */
/* @0x2ab800 .word 0xee873a90 */
/* @0x2ab804 .word 0xf8a46b08 */
/* @0x2ab808 mrrc p2, #0x0, r3, r3, c0 */
/* @0x2ab80c vmov r2, r1, d9 */
/* @0x2ab810 .word 0xf60a0b16 */
/* @0x2ab814 mcrr p15, #0xb, lr, r1, c8 */
/* @0x2ab818 .word 0xee070b17 */
/* @0x2ab81c vmov.f64 d27, #-1.875000e-01 */
/* @0x2ab820 vnmla.f64 d7, d23, d11 */
/* @0x2ab824 .word 0xf8a43a90 */
/* @0x2ab828 adds r3, r5, r2, lsl #4 */
/* @0x2ab82c andhs pc, lr, #180, #16 */
/* @0x2ab830 andlo pc, r2, #164, #16 */
/* @0x2ab834 andlo pc, r0, #164, #16 */
/* @0x2ab838 andhs pc, r12, #164, #16 */
/* @0x2ab83c andhs pc, r10, #164, #16 */
/* @0x2ab840 andhs pc, r8, #164, #16 */
/* @0x2ab844 .word 0xf1bae088 */
/* @0x2ab848 .word 0xf0400f03 */
/* @0x2ab84c rfeia r4! */
/* @0x2ab850 .word 0xf8d401dc */
/* @0x2ab854 addmi r3, r2, #216, #2 */
/* @0x2ab858 movweq pc, #0x3103 */
/* @0x2ab85c .word 0xf8d4da16 */
/* @0x2ab860 andlo r1, r1, #40, #4 */
/* @0x2ab864 .word 0x5c03f813 */
/* @0x2ab868 .word 0xf8135d49 */
/* @0x2ab86c .word 0xf8035c02 */
/* @0x2ab870 .word 0xf8d41c03 */
/* @0x2ab874 stclpl p2, c1, [r9, #-160] */
/* @0x2ab878 .word 0x5c01f813 */
/* @0x2ab87c .word 0x1c02f803 */
/* @0x2ab880 eorne pc, r8, #212, #16 */
/* @0x2ab884 .word 0xf8035d49 */
/* @0x2ab888 strb r1, [r4, r1, lsl #24]! */
/* @0x2ab88c ldrsblo pc, [r4, -r4]! */
/* @0x2ab890 movwpl pc, #0x423 */
/* @0x2ab894 teqlo r4, r4, asr #17 */
/* @0x2ab898 ssaxeq lr, r3, lr */
/* @0x2ab89c .word 0xf1bad55c */
/* @0x2ab8a0 cmple r9, r3, lsl #30 */
/* @0x2ab8a4 .word 0x11fef894 */
/* @0x2ab8a8 .word 0xf8942200 */
/* @0x2ab8ac .word 0xf8940200 */
/* @0x2ab8b0 rfeia r4! */
/* @0x2ab8b4 pkhtbmi r7, r12, lr, asr #3 */
/* @0x2ab8b8 ldrsblo pc, [r8, #132] */
/* @0x2ab8bc strtmi r4, [r9], r0, lsl #13 */
/* @0x2ab8c0 ble 0x11fc3b0 <b2_toiTime+0xaa2f0c> */
/* @0x2ab8c4 subvs pc, r12, #212, #16 */
/* @0x2ab8c8 ldmdblt lr, {r1, r2, r4, r5, r7, r10, r11, r12, lr} */
/* @0x2ab8cc subsvc r7, r8, r9, lsl r0 */
/* @0x2ab8d0 mlas r2, sp, r0, r7 */
/* @0x2ab8d4 ldrshtle r2, [r0], -pc */
/* @0x2ab8d8 mullt r0, r3, r8 */
/* @0x2ab8dc blx 0x46a512 <g_RomDisk+0x72cf2> */
/* @0x2ab8e0 ldrbteq pc, [pc], r6, asr #3 */
/* @0x2ab8e4 bleq 0xfe2e7d18 <b2_toiTime+0xfffffffffdb8e874> */
/* @0x2ab8e8 strlt pc, [r12], -r6, lsl #22 */
/* @0x2ab8ec bl 0x4583cc <g_RomDisk+0x60bac> */
/* @0x2ab8f0 eorsne r2, r6, #23068672 */
/* @0x2ab8f4 .word 0xf8d4701e */
/* @0x2ab8f8 .word 0xf816624c */
/* @0x2ab8fc ldmdavc lr, {r1, r12, sp, pc} ^ */
/* @0x2ab900 .word 0xf60bfb06 */
/* @0x2ab904 bleq 0x2a8038 <png_read_data+0x8> */
/* @0x2ab908 blx 0x579312 <g_SWFlineaavertbuff+0x2624a> */
/* @0x2ab90c adcslt r6, r6, #8, #12 */
/* @0x2ab910 ldrhs lr, [r6], -r6, lsl #22 */
/* @0x2ab914 subsvc r1, lr, r6, lsr r2 */
/* @0x2ab918 subvs pc, r12, #212, #16 */
/* @0x2ab91c andlt pc, r2, r6, lsl r8 */
/* @0x2ab920 blx 0x449ba2 <g_RomDisk+0x52382> */
/* @0x2ab924 .word 0xf1cbf60b */
/* @0x2ab928 .word 0x36800bff */
/* @0x2ab92c strvs pc, [r9], -r11, lsl #22 */
/* @0x2ab930 bl 0x458410 <g_RomDisk+0x60bf0> */
/* @0x2ab934 eorsne r2, r6, #23068672 */
/* @0x2ab938 andlo r7, r1, #158 */
/* @0x2ab93c ldr r3, [pc, r3, lsl #6]! */
/* @0x2ab940 ldrsblo pc, [r4, -r4]! */
/* @0x2ab944 orreq pc, r0, #35 */
/* @0x2ab948 teqlo r4, r4, asr #17 */
/* @0x2ab94c ldrsblo pc, [r0, -r4]! */
/* @0x2ab950 orreq pc, r0, #1124073472 */
/* @0x2ab954 teqlo r0, r4, asr #17 */
/* @0x2ab958 ldrsbhs pc, [r4, -r4]! */
/* @0x2ab95c movweq pc, #0x8241 */
/* @0x2ab960 blhs 0x4bb9b4 <SrcVerts+0x189f8> */
/* @0x2ab964 .word 0xf1bad13e */
/* @0x2ab968 teqle r11, r3, lsl #30 */
/* @0x2ab96c subhs pc, r0, #148, #16 */
/* @0x2ab970 .word 0xf8942300 */
/* @0x2ab974 .word 0xf8941241 */
/* @0x2ab978 .word 0xf1c20242 */
/* @0x2ab97c .word 0xf1c10208 */
/* @0x2ab980 rfeia r4! */
/* @0x2ab984 .word 0xf1c071dc */
/* @0x2ab988 bhs 0x4ab9b0 <SrcVerts+0x89f4> */
/* @0x2ab98c andhs r11, r0, #136, #30 */
/* @0x2ab990 svclt #0x882908 */
/* @0x2ab994 stmdahs r8, {r8, sp} */
/* @0x2ab998 andhs r11, r0, r8, lsl #31 */
/* @0x2ab99c adcsmi r11, sp, #-805306359 */
/* @0x2ab9a0 blx 0x560212 <g_SWFlineaavertbuff+0xd14a> */
/* @0x2ab9a4 .word 0xf8d4f503 */
/* @0x2ab9a8 movwlo r6, #0x11d8 */
/* @0x2ab9ac andgt pc, r5, r6, lsl r8 */
/* @0x2ab9b0 .word 0xfc02fa4c */
/* @0x2ab9b4 andgt pc, r5, r6, lsl #16 */
/* @0x2ab9b8 ldrsbvs pc, [r8, #132] */
/* @0x2ab9bc .word 0xf896442e */
/* @0x2ab9c0 blx 0x15db9cc <b2_toiTime+0xe82528> */
/* @0x2ab9c4 .word 0xf886fc01 */
/* @0x2ab9c8 .word 0xf8d4c001 */
/* @0x2ab9cc ldrtmi r6, [r5], #-472 */
/* @0x2ab9d0 smlatbmi r6, lr, r8, r7 */
/* @0x2ab9d4 strb r7, [r1, lr, lsr #1]! */
/* @0x2ab9d8 ldrsblo pc, [r4, -r4]! */
/* @0x2ab9dc movweq pc, #0x8023 */
/* @0x2ab9e0 teqlo r4, r4, asr #17 */
/* @0x2ab9e4 ldc p0, c11, [sp], #12 */
/* @0x2ab9e8 pop {r3, r8, r9, r11, pc} */
/* @0x2ab9ec svclt #0x8ff0 */
/* @0x2ab9f0 andeq r1, lr, r8, ror #8 */
/* @0x2ab9f4 andhi pc, r0, pc, lsr #7 */
/* @0x2ab9f8 bvc 0x3991c0 <ft_adobe_glyph_list+0x889c> */
/* @0x2ab9fc ldrle r0, [sp, #-0x79a]! */
/* @0x2aba00 bvc 0x12c5a10 <b2_toiTime+0xb6c56c> */
/* @0x2aba04 tstle r4, r8, lsl #16 */
/* @0x2aba08 andle r2, r3, r2, lsl #22 */
/* @0x2aba0c teqle r5, r6, lsl #22 */
/* @0x2aba10 and r2, r0, r4 */
/* @0x2aba14 movwhs r2, #0x3 */
/* @0x2aba18 mulle r9, r3, r2 */
/* @0x2aba1c movwlo r7, #0x184c */
/* @0x2aba20 strtmi r7, [r5], #-2061 */
/* @0x2aba24 stmvc sp, {r0, r2, r3, r12, sp, lr} */
/* @0x2aba28 addvc r4, r12, r12, lsr #8 */
/* @0x2aba2c ldrb r4, [r3, r1, lsl #8]! */
/* @0x2aba30 ldmdahs r0, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x2aba34 blhs 0x35fec4 <_ZTS12CDS_Priority+0x1f1c> */
/* @0x2aba38 blhs 0x45fa4c <g_RomDisk+0x6822c> */
/* @0x2aba3c andhs sp, r8, lr, lsl r1 */
/* @0x2aba40 andhs lr, r6, r0 */
/* @0x2aba44 addsmi r2, r3, #0, #6 */
/* @0x2aba48 stmvc lr, {r3, r4, r12, lr, pc} */
/* @0x2aba4c stmvc r12, {r0, r8, r9, r12, sp} ^ */
/* @0x2aba50 b 0x13c9a8c <b2_toiTime+0xc705e8> */
/* @0x2aba54 stmdavc r12, {r1, r2, r9, r10, sp} ^ */
/* @0x2aba58 b 0x13c9e9c <b2_toiTime+0xc709f8> */
/* @0x2aba5c stmdbvc r12, {r0, r2, r8, r10, sp} ^ */
/* @0x2aba60 b 0x13bcb3c <b2_toiTime+0xc63698> */
/* @0x2aba64 ldrtmi r2, [r4], #-1031 */
/* @0x2aba68 subvc r11, sp, sp, lsr #5 */
/* @0x2aba6c beq 0xe58504 <b2_toiTime+0x6ff060> */
/* @0x2aba70 andvc r7, lr, r12, asr #2 */
/* @0x2aba74 .word 0x710d0a25 */
/* @0x2aba78 strb r4, [r4, r1, lsl #8]! */
/* @0x2aba7c strdeq r11, r12, [r0], -r0 */
/* @0x2aba80 svcmi #0xf0e92d */
/* @0x2aba84 ldmdami r5!, {r2, r9, r10, lr} */
/* @0x2aba88 ldrmi r11, [r8], pc, lsl #1 */
/* @0x2aba8c blvc 0xfe9e8ea4 <b2_toiTime+0xfffffffffe28fa00> */
/* @0x2aba90 stmdavs r0, {r3, r4, r5, r6, r10, lr} */
/* @0x2aba94 .word 0xa060f8dd */
/* @0x2aba98 .word 0xf8c42500 */
/* @0x2aba9c stmdavs r3, {r3, r4, r5, r8, r12} */
/* @0x2abaa0 .word 0xf8c44681 */
/* @0x2abaa4 movwls r2, #0xd13c */
/* @0x2abaa8 ldrsblo pc, [r0, #-132]! */
/* @0x2abaac qaddhs r4, r8, r0 */
/* @0x2abab0 smlalbtlo pc, r4, r4, r8 */
/* @0x2abab4 ldrsblo pc, [r4, #-132]! */
/* @0x2abab8 smlalbtlo pc, r8, r4, r8 */
/* @0x2ababc svc #0x8ef60a */
/* @0x2abac0 ldrsbvc pc, [r4, #-132]! */
/* @0x2abac4 .word 0x3148f8d4 */
/* @0x2abac8 strmi r2, [r6], -r1, lsl #16 */
/* @0x2abacc bne 0x2a1b2c <_Z10BeginToEndv+0x320> */
/* @0x2abad0 ldcle p15, c2, [r0, #-0] */
/* @0x2abad4 svceq #0xf1b8 */
/* @0x2abad8 strmi sp, [r10, #0xc]! */
/* @0x2abadc bl 0xff421f0c <b2_toiTime+0xfffffffffecc8a68> */
/* @0x2abae0 bl 0x4ac310 <SrcVerts+0x9354> */
/* @0x2abae4 .word 0xf8d40005 */
/* @0x2abae8 adcsmi r1, r10, #112, #2 */
/* @0x2abaec ldrtmi r11, [r10], -r8, lsr #30 */
/* @0x2abaf0 stcl p6, c15, [r4, #-40]! */
/* @0x2abaf4 mcrhs p4, #0x0, r4, c0, c13, #0x1 */
/* @0x2abaf8 .word 0x2601d0d6 */
/* @0x2abafc ldrbmi r2, [r8], -r0, lsl #14 */
/* @0x2abb00 teqvc r12, r4, asr #17 */
/* @0x2abb04 b 0x9e9338 <b2_toiTime+0x28fe94> */
/* @0x2abb08 andsle r2, r10, r1, lsl #28 */
/* @0x2abb0c ldrsblo pc, [r0, #-132] */
/* @0x2abb10 ldclne p9, c11, [r3, #-812]! */
/* @0x2abb14 strlo sp, [r3], -r4 */
/* @0x2abb18 bmi 0x71fb34 <g_SWFvertbuff+0x4ca6c> */
/* @0x2abb1c and r4, r4, r10, ror r4 */
/* @0x2abb20 ldrbtmi r4, [r10], #-2576 */
/* @0x2abb24 bmi 0x6e3b30 <g_SWFvertbuff+0x10a68> */
/* @0x2abb28 teqhs r4, r10, ror r4 */
/* @0x2abb2c mvnsvc pc, #4, #10 */
/* @0x2abb30 .word 0xf60a4668 */
/* @0x2abb34 strtmi lr, [r0], -r10, asr #26 */
/* @0x2abb38 .word 0xf7fa4669 */
/* @0x2abb3c mulhs r0, r11, r12 */
/* @0x2abb40 strtmi lr, [r8], -r2 */
/* @0x2abb44 ldrtmi lr, [r8], -r0 */
/* @0x2abb48 .word 0xf8d99a0d */
/* @0x2abb4c addsmi r3, r10, #0 */
/* @0x2abb50 .word 0xf60ad001 */
/* @0x2abb54 andlt lr, pc, r0, asr #26 */
/* @0x2abb58 svchi #0xf0e8bd */
/* @0x2abb5c andseq r1, r4, r4, asr #29 */
/* @0x2abb60 andeq r1, lr, r8, lsr r0 */
/* @0x2abb64 ldrdeq r0, r1, [lr], -r0 */
/* @0x2abb68 strdeq r0, r1, [lr], -r12 */
/* @0x2abb6c stmdavc r11, {r4, r8, r10, r12, sp, pc} ^ */
/* @0x2abb70 ldreq r7, [r11], #-2058 */
/* @0x2abb74 movwvs lr, #0x2b03 */
/* @0x2abb78 ldrmi r7, [r3], #-2250 */
/* @0x2abb7c bl 0x789dac <b2_toiTime+0x30908> */
/* @0x2abb80 strle r2, [r3, #-0x402] */
/* @0x2abb84 ldrbtmi r4, [r9], #-2306 */
/* @0x2abb88 mrrc2 p7, #0xf, pc, r0, c10 */
/* @0x2abb8c ldclt p6, c4, [r0, #-128] */
/* @0x2abb90 strdeq r0, r1, [lr], -r11 */
/* @0x2abb94 .word 0x4605b5f8 */
/* @0x2abb98 .word 0x41f0f890 */
/* @0x2abb9c .word 0x2c07460e */
/* @0x2abba0 .word 0xf1c4d82e */
/* @0x2abba4 .word 0xf1040708 */
/* @0x2abba8 ldrtmi r0, [r1], #-288 */
/* @0x2abbac tsths r1, #32, #12 */
/* @0x2abbb0 .word 0xf8c0463a */
/* @0x2abbb4 .word 0xf7fc3334 */
/* @0x2abbb8 movwhs pc, #0x8a3b */
/* @0x2abbbc .word 0xf8854630 */
/* @0x2abbc0 qsub8mi r3, r1, r0 */
/* @0x2abbc4 .word 0xf7f9463a */
/* @0x2abbc8 orrlt pc, r8, r1, asr #30 */
/* @0x2abbcc stmdale r10, {r0, r1, r10, r11, sp} */
/* @0x2abbd0 qasxmi r4, r1, r0 */
/* @0x2abbd4 andeq pc, r4, #196, #2 */
/* @0x2abbd8 .word 0xff38f7f9 */
/* @0x2abbdc stmdbmi r9, {r3, r4, r8, r12, sp, pc} */
/* @0x2abbe0 ldrbtmi r4, [r9], #-1576 */
/* @0x2abbe4 stmdbmi r8, {r1, sp, lr, pc} */
/* @0x2abbe8 ldrbtmi r4, [r9], #-1576 */
/* @0x2abbec .word 0xfc1ef7fa */
/* @0x2abbf0 stmdale r5, {r1, r10, r11, sp} */
/* @0x2abbf4 .word 0x312cf8d5 */
/* @0x2abbf8 orrpl pc, r0, #1124073472 */
/* @0x2abbfc smlawtlo r12, r5, r8, pc */
/* @0x2abc00 svclt #0xbdf8 */
/* @0x2abc04 andeq r0, lr, r1, asr #31 */
/* @0x2abc08 andeq r0, lr, r8, asr #31 */
/* @0x2abc0c .word 0x460db570 */
/* @0x2abc10 .word 0x46064614 */
/* @0x2abc14 .word 0xf7fcb140 */
/* @0x2abc18 ldrtmi pc, [r0], -r11, lsl #20 */
/* @0x2abc1c strtmi r4, [r2], -r9, lsr #12 */
/* @0x2abc20 ldrhtmi lr, [r0], #-141 */
/* @0x2abc24 svclt #0x70f7f9 */
/* @0x2abc28 ldrlt r11, [r7, #-0xd70]! */

/* ── FUNC 0x2aa399 · png_do_expand_palette · size=420 · insn=0 */

/* ── FUNC 0x2aa53d · png_do_expand · size=792 · insn=0 */

/* ── FUNC 0x2aa855 · png_do_quantize · size=214 · insn=0 */

/* ── FUNC 0x2aa92d · png_do_read_transformations · size=880 · insn=0 */

/* ── FUNC 0x2aaca1 · png_build_gamma_table · size=1236 · insn=0 */

/* ── FUNC 0x2ab179 · png_init_read_transformations · size=2172 · insn=0 */

/* ── FUNC 0x2ab9f9 · png_do_read_intrapixel · size=134 · insn=0 */

/* ── FUNC 0x2abb6d · png_get_uint_31 · size=40 · insn=0 */

/* ── FUNC 0x2abb95 · png_read_sig · size=120 · insn=0 */

/* ── FUNC 0x2abc0d · png_crc_read · size=30 · insn=0 */
