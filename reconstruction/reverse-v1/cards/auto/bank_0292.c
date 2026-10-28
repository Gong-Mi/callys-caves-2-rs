/* libyoyo.so 覆盖卡组 0292
 * 函数 0x2e6d25..0x2e738d，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e6d25 · FT_Stream_ReadUShortLE · size=76 · insn=0 */

/* ── FUNC 0x2e6d71 · FT_Stream_ReadUOffset · size=84 · insn=0 */

/* ── FUNC 0x2e6dc5 · FT_Stream_ReadULong · size=88 · insn=0 */

/* ── FUNC 0x2e6ee9 · FT_Stream_ReadULongLE · size=88 · insn=0 */

/* ── FUNC 0x2e6f41 · FT_Atan2 · size=32 · insn=0 */

/* ── FUNC 0x2e6f61 · FT_Vector_Unit · size=40 · insn=0 */

/* ── FUNC 0x2e6f89 · FT_Cos · size=18 · insn=0 */

/* ── FUNC 0x2e6f9a · anon_2e6f9a · size=20 · insn=5 */
/* @0x2e6f9a strmi r11, [r1], -r7, lsl #10 */
/* @0x2e6f9e .word 0xf7ff4668 */
/* @0x2e6fa2 stmdals r1, {r1, r2, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e6fa6 .word 0xf85db003 */
/* @0x2e6faa strlt pc, [r7, #-0xb04] */

/* ── FUNC 0x2e6f9b · FT_Sin · size=18 · insn=0 */

/* ── FUNC 0x2e6fac · anon_2e6fac · size=208 · insn=52 */
/* @0x2e6fac strmi r11, [r1], -r7, lsl #10 */
/* @0x2e6fb0 .word 0xf7ff4668 */
/* @0x2e6fb4 stmdals r1, {r0, r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e6fb8 .word 0xf7fd9900 */
/* @0x2e6fbc andlt pc, r3, r12, ror pc */
/* @0x2e6fc0 blx 0x42513e <g_RomDisk+0x2d91e> */
/* @0x2e6fc4 .word 0x460fb5f7 */
/* @0x2e6fc8 cmplt r8, #4, #12 */
/* @0x2e6fcc stmdagt r3, {r0, r4, r6, r8, r9, r12, sp, pc} */
/* @0x2e6fd0 andeq lr, r3, sp, lsl #17 */
/* @0x2e6fd4 .word 0xb329b900 */
/* @0x2e6fd8 .word 0xf7fd4668 */
/* @0x2e6fdc shsub8mi pc, r9, pc */
/* @0x2e6fe0 strbtmi r4, [r8], -r5, lsl #12 */
/* @0x2e6fe4 stc2l p7, c15, [lr, #-1012]! */
/* @0x2e6fe8 .word 0xf7fd9800 */
/* @0x2e6fec .word 0x4606fd3e */
/* @0x2e6ff0 .word 0xf7fd9801 */
/* @0x2e6ff4 stchs p13, c15, [r0, #-232] */
/* @0x2e6ff8 cdpne p13, #0x6, c13, c11, c14, #0x0 */
/* @0x2e6ffc blx 0x36f808 <_ZTS13C_UTF16String+0x68b4> */
/* @0x2e7000 ldmne r2!, {r0, r1, r8, r9, r12, sp, lr, pc} ^ */
/* @0x2e7004 bl 0x378018 <_ZTS13C_UTF16String+0xf0c4> */
/* @0x2e7008 bl 0x3c4ba8 <error_g0017+0x1d84c> */
/* @0x2e700c smulwtmi lr, r0, r0 */
/* @0x2e7010 .word 0xf505fa40 */
/* @0x2e7014 and r6, r4, r6, lsr #32 */
/* @0x2e7018 adcmi r4, lr, sp, ror #4 */
/* @0x2e701c .word 0xf505fa00 */
/* @0x2e7020 rsbvs r6, r5, r6, lsr #32 */
/* @0x2e7024 ldcllt p0, c11, [r0, #12]! */
/* @0x2e7028 .word 0xb320b537 */
/* @0x2e702c stm sp, {r0, r1, r11, lr, pc} */
/* @0x2e7030 strmi r0, [r3], -r3 */
/* @0x2e7034 ldmdblt r11, {r3, r9, r10, lr} */
/* @0x2e7038 svclt #0xb82800 */
/* @0x2e703c ands r4, r10, r0, asr #4 */
/* @0x2e7040 b 0xfe3d54cc <b2_toiTime+0xfffffffffdc7c028> */
/* @0x2e7044 bl 0xfeb033d8 <b2_toiTime+0xfffffffffe3a9f34> */
/* @0x2e7048 ands r7, r4, r3, ror #1 */
/* @0x2e704c .word 0xf7fd4668 */
/* @0x2e7050 strmi pc, [r5], -r5, asr #27 */
/* @0x2e7054 .word 0xf7fd4668 */
/* @0x2e7058 stmdals r0, {r0, r1, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x2e705c stc2 p7, c15, [r5, #-1012] */
/* @0x2e7060 stcle p13, c2, [r6, #-0] */
/* @0x2e7064 andhs r1, r1, #1712 */
/* @0x2e7068 vpmax.u8 d15, d3, d2 */
/* @0x2e706c .word 0x41284418 */
/* @0x2e7070 rsbmi lr, sp, #1 */
/* @0x2e7074 andlt r4, r3, r8, lsr #1 */
/* @0x2e7078 strlt r11, [r7, #-0xd30] */

/* ── FUNC 0x2e6fad · FT_Tan · size=24 · insn=0 */

/* ── FUNC 0x2e6fc5 · FT_Vector_Rotate · size=100 · insn=0 */

/* ── FUNC 0x2e7029 · FT_Vector_Length · size=82 · insn=0 */

/* ── FUNC 0x2e707a · anon_2e707a · size=20 · insn=5 */
/* @0x2e707a stm sp, {r0, r1, r2, r8, r10, r12, sp, pc} */
/* @0x2e707e strbtmi r0, [r8], -r3 */
/* @0x2e7082 .word 0xffd1f7ff */
/* @0x2e7086 .word 0xf85db003 */
/* @0x2e708a ldrblt pc, [r7, #0xb04]! */

/* ── FUNC 0x2e707b · FT_Hypot · size=18 · insn=0 */

/* ── FUNC 0x2e708c · anon_2e708c · size=68 · insn=17 */
/* @0x2e708c .word 0x460eb5f7 */
/* @0x2e7090 bicslt r4, r0, r7, lsl r6 */
/* @0x2e7094 biclt r11, r2, r9, asr #3 */
/* @0x2e7098 stm sp, {r0, r1, r11, lr, pc} */
/* @0x2e709c stmdblt r0, {r0, r1} */
/* @0x2e70a0 uqadd8mi r11, r8, r9 */
/* @0x2e70a4 ldc2 p7, c15, [r10, #1012] */
/* @0x2e70a8 strbtmi r4, [r8], -r5, lsl #12 */
/* @0x2e70ac stc2l p7, c15, [r4, #-1012] */
/* @0x2e70b0 .word 0xf7fd9800 */
/* @0x2e70b4 blls 0x366424 <_ZTS12CDS_Priority+0x847c> */
/* @0x2e70b8 svclt #0xb62d00 */
/* @0x2e70bc blx 0x12f7a78 <b2_toiTime+0xb9e5d4> */
/* @0x2e70c0 blx 0x3244dc */
/* @0x2e70c4 eorsvs pc, r5, r5, lsl #10 */
/* @0x2e70c8 andlt r6, r3, r11, lsr r0 */
/* @0x2e70cc strdlt r11, r12, [r8, -r0]! */

/* ── FUNC 0x2e708d · FT_Vector_Polarize · size=66 · insn=0 */

/* ── FUNC 0x2e70ce · anon_2e70ce · size=20 · insn=5 */
/* @0x2e70ce andvs r11, r1, r8, lsr #2 */
/* @0x2e70d2 subvs r2, r1, r0, lsl #2 */
/* @0x2e70d6 .word 0xf7ff4611 */
/* @0x2e70da .word 0x4770bf74 */
/* @0x2e70de blmi 0x4670e6 <g_RomDisk+0x6f8c6> */

/* ── FUNC 0x2e70cf · FT_Vector_From_Polar · size=16 · insn=0 */

/* ── FUNC 0x2e70e0 · anon_2e70e0 · size=72 · insn=18 */
/* @0x2e70e0 bne 0x4f9d00 <SrcVerts+0x56d44> */
/* @0x2e70e4 ble 0x377b4c <_ZTS13C_UTF16String+0xebf8> */
/* @0x2e70e8 adcsvc pc, r4, r0, lsl #2 */
/* @0x2e70ec .word 0xf5b0e7fa */
/* @0x2e70f0 stcle p15, c0, [r2, #-208] */
/* @0x2e70f4 adcsvc pc, r4, r0, lsr #3 */
/* @0x2e70f8 .word 0x4770e7f9 */
/* @0x2e70fc .word 0xff4c0001 */
/* @0x2e7100 sadd16mi r11, r4, r0 */
/* @0x2e7104 strmi r1, [r3], -r10, lsl #28 */
/* @0x2e7108 stmdavs r3, {r1, r2, r8, r10, r11, r12, lr, pc} ^ */
/* @0x2e710c stmdahs r0, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e7110 movths r11, #0xf0c */
/* @0x2e7114 and r2, r4, r0, lsl #6 */
/* @0x2e7118 ldrmi r11, [r0], -r11, lsl #30 */
/* @0x2e711c strmi r2, [r3], -r0 */
/* @0x2e7120 eorvs r2, r3, r6, lsl #6 */
/* @0x2e7124 ldrblt r11, [r3, #-0xd10]! */

/* ── FUNC 0x2e70e1 · FT_Angle_Diff · size=32 · insn=0 */

/* ── FUNC 0x2e7101 · ft_mem_qalloc · size=38 · insn=0 */

/* ── FUNC 0x2e7126 · anon_2e7126 · size=40 · insn=10 */
/* @0x2e7126 ssub16mi r11, r5, r3 */
/* @0x2e712a strmi r10, [r12], -r1, lsl #20 */
/* @0x2e712e .word 0xffe7f7ff */
/* @0x2e7132 strmi r9, [r6], -r1, lsl #18 */
/* @0x2e7136 .word 0x2c00b921 */
/* @0x2e713a strtmi sp, [r2], -r2, lsl #26 */
/* @0x2e713e b 0x1124882 <b2_toiTime+0x9cb3de> */
/* @0x2e7142 ldrtmi r9, [r0], -r1, lsl #22 */
/* @0x2e7146 andlt r6, r2, r11, lsr #32 */
/* @0x2e714a ldrlt r11, [r7, #-0xd70]! */

/* ── FUNC 0x2e7127 · ft_mem_alloc · size=38 · insn=0 */

/* ── FUNC 0x2e714c · anon_2e714c · size=492 · insn=123 */
/* @0x2e714c .word 0x460cb537 */
/* @0x2e7150 .word 0x2160aa01 */
/* @0x2e7154 .word 0xf7ff4605 */
/* @0x2e7158 blls 0x3670f8 <_ZTS12CDS_Priority+0x9150> */
/* @0x2e715c andvs r11, r5, r11, lsl #18 */
/* @0x2e7160 stmdals r1, {r5, sp, lr} */
/* @0x2e7164 ldclt p0, c11, [r0, #-12]! */
/* @0x2e7168 .word 0x43f7e92d */
/* @0x2e716c strmi r10, [r4], -r2, lsl #28 */
/* @0x2e7170 ldrmi r4, [r7], -r8, lsl #12 */
/* @0x2e7174 .word 0xf04f460d */
/* @0x2e7178 .word 0xf8460900 */
/* @0x2e717c .word 0xf5cf9d04 */
/* @0x2e7180 pkhtbmi lr, r0, r12, asr #19 */
/* @0x2e7184 .word 0xf5cf4638 */
/* @0x2e7188 .word 0x4632e9d8 */
/* @0x2e718c .word 0x0100eb08 */
/* @0x2e7190 .word 0x31014620 */
/* @0x2e7194 .word 0xffc7f7ff */
/* @0x2e7198 .word 0x8004f8dd */
/* @0x2e719c .word 0xf1b84604 */
/* @0x2e71a0 tstle lr, r0, lsl #30 */
/* @0x2e71a4 .word 0x212f4628 */
/* @0x2e71a8 bl 0x1aa48ec <b2_toiTime+0x134b448> */
/* @0x2e71ac .word 0xb1684606 */
/* @0x2e71b0 stmdbeq r0, {r0, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2e71b4 strtmi r4, [r0], -r9, lsr #12 */
/* @0x2e71b8 andeq pc, r1, #1073741826 */
/* @0x2e71bc ldmib r4, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e71c0 movweq lr, #0x9b04 */
/* @0x2e71c4 .word 0xf8831c75 */
/* @0x2e71c8 and r8, r0, r1 */
/* @0x2e71cc ldrtmi r7, [r9], -r0, lsr #32 */
/* @0x2e71d0 .word 0xf5cf4620 */
/* @0x2e71d4 strtmi lr, [r0], -r10, lsr #20 */
/* @0x2e71d8 .word 0xf5cf4629 */
/* @0x2e71dc strtmi lr, [r0], -r6, lsr #20 */
/* @0x2e71e0 strbmi lr, [r8], -r0 */
/* @0x2e71e4 pop {r0, r1, r12, sp, pc} */
/* @0x2e71e8 strdeq r8, r9, [r0], -r0 */
/* @0x2e71ec bmi 0x4b8a38 <SrcVerts+0x15a7c> */
/* @0x2e71f0 ldrbtmi r11, [r10], #-1296 */
/* @0x2e71f4 ldrmi r6, [r12], -r0, lsl #16 */
/* @0x2e71f8 .word 0xffb6f7ff */
/* @0x2e71fc blls 0x393684 <ft_adobe_glyph_list+0x2d60> */
/* @0x2e7200 andhs r6, r0, r0, lsr #32 */
/* @0x2e7204 ldclt p0, c6, [r0, #-96] */
/* @0x2e7208 ldclt p0, c2, [r0, #-256] */
/* @0x2e720c andeq r7, r10, r7, asr #10 */
/* @0x2e7210 bmi 0x4b8a5c <SrcVerts+0x15aa0> */
/* @0x2e7214 ldrbtmi r11, [r10], #-1296 */
/* @0x2e7218 ldrmi r6, [r12], -r0, lsl #16 */
/* @0x2e721c .word 0xffa4f7ff */
/* @0x2e7220 blls 0x3936a8 <ft_adobe_glyph_list+0x2d84> */
/* @0x2e7224 andhs r6, r0, r0, lsr #32 */
/* @0x2e7228 ldclt p0, c6, [r0, #-96] */
/* @0x2e722c ldclt p0, c2, [r0, #-256] */
/* @0x2e7230 andeq r7, r10, lr, lsr #10 */
/* @0x2e7234 mvnsmi lr, sp, lsr #18 */
/* @0x2e7238 ldrmi r4, [r0], -r5, lsl #12 */
/* @0x2e723c sadd8mi r4, r7, r8 */
/* @0x2e7240 ldmdb r10!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e7244 .word 0x46044b10 */
/* @0x2e7248 stmdavs r8!, {r2, r3, r4, r7, r9, lr} */
/* @0x2e724c stcne p12, c13, [r1, #88]! */
/* @0x2e7250 .word 0xf7ffaa01 */
/* @0x2e7254 stcls p15, c15, [r1, #-416] */
/* @0x2e7258 stmiblt sp, {r1, r2, r9, r10, lr} */
/* @0x2e725c qasxmi r4, r2, r9 */
/* @0x2e7260 stmib r12!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} */
/* @0x2e7264 ldmdbne r3!, {r0, r3, r9, r11, lr} */
/* @0x2e7268 ldmdavs r1, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x2e726c .word 0x51318892 */
/* @0x2e7270 blls 0x5074e0 <SrcVerts+0x64524> */
/* @0x2e7274 andvs pc, r0, r8, asr #17 */
/* @0x2e7278 and r6, r1, sp, lsl r0 */
/* @0x2e727c and r2, r0, r10 */
/* @0x2e7280 andlt r4, r2, r8, lsr #12 */
/* @0x2e7284 ldrhhi lr, [r0, #141]! */
/* @0x2e7288 svcvc #0xfffff9 */
/* @0x2e728c andeq r7, r10, r10, ror #9 */
/* @0x2e7290 .word 0x4606b5f7 */
/* @0x2e7294 sadd16mi r4, pc, r0 */
/* @0x2e7298 .word 0xf5cf4615 */
/* @0x2e729c blmi 0x8217dc <b2_toiTime+0xc8338> */
/* @0x2e72a0 addsmi r4, r12, #4, #12 */
/* @0x2e72a4 .word 0xdc1d6830 */
/* @0x2e72a8 .word 0xf104aa01 */
/* @0x2e72ac .word 0xf7ff0112 */
/* @0x2e72b0 bls 0x366fa0 <_ZTS12CDS_Priority+0x8ff8> */
/* @0x2e72b4 ldmiblt r10!, {r1, r2, r9, r10, lr} */
/* @0x2e72b8 strtmi r4, [r2], -r9, lsr #12 */
/* @0x2e72bc ldmdb lr!, {r0, r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e72c0 ldrtmi r4, [r4], #-2316 */
/* @0x2e72c4 .word 0xf1014479 */
/* @0x2e72c8 .word 0xf8510310 */
/* @0x2e72cc addsmi r2, r9, #4, #22 */
/* @0x2e72d0 blhs 0x4253e8 <g_RomDisk+0x2dbc8> */
/* @0x2e72d4 stmdahi r11, {r0, r3, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x2e72d8 eorhi r2, r3, r0 */
/* @0x2e72dc eorsvs r9, lr, r8, lsl #22 */
/* @0x2e72e0 and r6, r2, r8, lsl r0 */
/* @0x2e72e4 and r2, r0, r10 */
/* @0x2e72e8 andlt r4, r3, r0, lsl r6 */
/* @0x2e72ec svclt #0xbdf0 */
/* @0x2e72f0 svcvc #0xffffed */
/* @0x2e72f4 muleq r10, r4, r4 */
/* @0x2e72f8 .word 0x460cb537 */
/* @0x2e72fc .word 0xb1a84605 */
/* @0x2e7300 bichs r11, r0, r1, lsr #3 */
/* @0x2e7304 .word 0xf7ffaa01 */
/* @0x2e7308 blls 0x366f48 <_ZTS12CDS_Priority+0x8fa0> */
/* @0x2e730c andhs r11, r2, #2146304 */
/* @0x2e7310 subvs r6, r2, r5 */
/* @0x2e7314 .word 0xf8c02208 */
/* @0x2e7318 addvs r3, r2, r8, lsr #1 */
/* @0x2e731c .word 0xf8c02201 */
/* @0x2e7320 sbcvs r3, r3, r4, lsr #1 */
/* @0x2e7324 adcshs pc, r12, r0, asr #17 */
/* @0x2e7328 and r6, r1, r0, lsr #32 */
/* @0x2e732c and r2, r0, r6 */
/* @0x2e7330 andlt r4, r3, r8, lsl r6 */
/* @0x2e7334 strlt r11, [r8, #-0xd30] */

/* ── FUNC 0x2e714d · FT_GlyphLoader_New · size=28 · insn=0 */

/* ── FUNC 0x2e72f9 · FT_New_Library · size=62 · insn=0 */

/* ── FUNC 0x2e7336 · anon_2e7336 · size=12 · insn=3 */
/* @0x2e7336 mrslt r11, apsr */
/* @0x2e733a ldrmi r6, [r8, r3, lsl #17] */
/* @0x2e733e ldrblt r11, [r0, #-0xd08]! */

/* ── FUNC 0x2e7337 · ft_mem_free · size=10 · insn=0 */

/* ── FUNC 0x2e7340 · anon_2e7340 · size=104 · insn=26 */
/* @0x2e7340 .word 0x4604b570 */
/* @0x2e7344 strhs r6, [r0, #-0x806] */
/* @0x2e7348 ldrtmi r6, [r0], -r1, lsr #19 */
/* @0x2e734c .word 0xfff3f7ff */
/* @0x2e7350 stmibvs r1!, {r4, r5, r9, r10, lr} ^ */
/* @0x2e7354 .word 0xf7ff61a5 */
/* @0x2e7358 ldrtmi pc, [r0], -lr, ror #31 */
/* @0x2e735c mvnvs r6, r1, lsr #20 */
/* @0x2e7360 .word 0xffe9f7ff */
/* @0x2e7364 bvs 0xfeb38c2c <b2_toiTime+0xfffffffffe3df788> */
/* @0x2e7368 .word 0xf7ff6225 */
/* @0x2e736c ldrtmi pc, [r0], -r4, ror #31 */
/* @0x2e7370 blvs 0x1b3fe0c <b2_toiTime+0x13e6968> */
/* @0x2e7374 .word 0xffdff7ff */
/* @0x2e7378 rscvs r6, r5, #-1811939327 */
/* @0x2e737c rsbvs r4, r5, r0, lsr #12 */
/* @0x2e7380 rscvs r6, r5, r5, lsr #1 */
/* @0x2e7384 ldrhtmi lr, [r0], #-141 */
/* @0x2e7388 svclt #0x98f7fd */
/* @0x2e738c .word 0x4604b538 */
/* @0x2e7390 stmdavs r5, {r6, r8, r12, sp, pc} */
/* @0x2e7394 .word 0xffd4f7ff */
/* @0x2e7398 strtmi r4, [r8], -r1, lsr #12 */
/* @0x2e739c ldrhtmi lr, [r8], -sp */
/* @0x2e73a0 svclt #0xc9f7ff */
/* @0x2e73a4 push {r3, r4, r5, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2e7341 · FT_GlyphLoader_Reset · size=76 · insn=0 */

/* ── FUNC 0x2e738d · FT_GlyphLoader_Done · size=26 · insn=0 */
