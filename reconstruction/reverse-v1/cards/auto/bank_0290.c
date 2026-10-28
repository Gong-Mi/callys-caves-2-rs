/* libyoyo.so 覆盖卡组 0290
 * 函数 0x2e5dc3..0x2e64c8，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e5dc3 · FT_Face_GetVariantSelectors · size=28 · insn=0 */

/* ── FUNC 0x2e5ddf · FT_Face_GetVariantsOfChar · size=32 · insn=0 */

/* ── FUNC 0x2e5dff · FT_Face_GetCharsOfVariant · size=32 · insn=0 */

/* ── FUNC 0x2e5e1f · FT_Activate_Size · size=24 · insn=0 */

/* ── FUNC 0x2e5e37 · FT_Lookup_Renderer · size=50 · insn=0 */

/* ── FUNC 0x2e5e68 · anon_2e5e68 · size=208 · insn=52 */
/* @0x2e5e68 .word 0xf7ff2200 */
/* @0x2e5e6c andeq r11, r0, r4, ror #31 */
/* @0x2e5e70 mvnsmi lr, sp, lsr #18 */
/* @0x2e5e74 blmi 0x8776b4 <b2_toiTime+0x11e210> */
/* @0x2e5e78 stcvs p6, c4, [r9], {5} */
/* @0x2e5e7c strhs r4, [r0], #-1559 */
/* @0x2e5e80 mlale r0, r9, r2, r4 */
/* @0x2e5e84 strls r4, [r1], #-2835 */
/* @0x2e5e88 swple r4, r9, [r5] */
/* @0x2e5e8c ldrsblo pc, [r4], r5 */
/* @0x2e5e90 ldrsbeq pc, [r12], r0 */
/* @0x2e5e94 and r9, r2, r1, lsl #6 */
/* @0x2e5e98 .word 0xf7ffaa01 */
/* @0x2e5e9c .word 0xf10dffcc */
/* @0x2e5ea0 strhs r0, [r7], #-2052 */
/* @0x2e5ea4 blvs 0xff41248c <b2_toiTime+0xfffffffffecb8fe8> */
/* @0x2e5ea8 shasxmi r4, r10, r1 */
/* @0x2e5eac strmi r2, [r0, r0, lsl #6]! */
/* @0x2e5eb0 .word 0xb1404604 */
/* @0x2e5eb4 blhs 0x7d29c8 <b2_toiTime+0x79524> */
/* @0x2e5eb8 strtmi sp, [r8], -r5, lsl #2 */
/* @0x2e5ebc .word 0x46426cb1 */
/* @0x2e5ec0 .word 0xffb9f7ff */
/* @0x2e5ec4 strtmi lr, [r0], -lr, ror #15 */
/* @0x2e5ec8 pop {r1, r12, sp, pc} */
/* @0x2e5ecc svclt #0x81f0 */
/* @0x2e5ed0 rsbvs r7, r9, #1929379840 */
/* @0x2e5ed4 svcvs #0x75746c */
/* @0x2e5ed8 strmi r4, [r3], -r10, lsl #12 */
/* @0x2e5edc stmdavs r0, {r4, r5, r8, r12, sp, pc} ^ */
/* @0x2e5ee0 cdpvs p1, #0x0, c11, c1, c0, #0x1 */
/* @0x2e5ee4 ldrmi r6, [r9], -r8, asr #16 */
/* @0x2e5ee8 svclt #0xc2f7ff */
/* @0x2e5eec ldrbmi r2, [r0, -r6]! */
/* @0x2e5ef0 .word 0x460db5f8 */
/* @0x2e5ef4 .word 0xb1a1b198 */
/* @0x2e5ef8 .word 0xf1006907 */
/* @0x2e5efc bl 0x467754 <g_RomDisk+0x6ff34> */
/* @0x2e5f00 adcsmi r0, lr, #35389440 */
/* @0x2e5f04 .word 0xf856d209 */
/* @0x2e5f08 strtmi r4, [r9], -r4, lsl #22 */
/* @0x2e5f0c ldmvs r8, {r0, r1, r5, r11, sp, lr} */
/* @0x2e5f10 bl 0xf23658 <b2_toiTime+0x7ca1b4> */
/* @0x2e5f14 mvnsle r2, r0, lsl #16 */
/* @0x2e5f18 strhs lr, [r0], #-4 */
/* @0x2e5f1c strmi lr, [r4], -r2 */
/* @0x2e5f20 strmi lr, [r12], -r0 */
/* @0x2e5f24 ldcllt p6, c4, [r8, #128]! */
/* @0x2e5f28 .word 0xf7ffb508 */
/* @0x2e5f2c smlattlt r8, r1, pc, pc */
/* @0x2e5f30 ldmdbvs r8, {r0, r1, r11, sp, lr} ^ */
/* @0x2e5f34 ldrblt r11, [r8, #0xd08]! */

/* ── FUNC 0x2e5e69 · FT_Get_Renderer · size=6 · insn=0 */

/* ── FUNC 0x2e5e71 · FT_Render_Glyph_Internal · size=104 · insn=0 */

/* ── FUNC 0x2e5ed9 · FT_Render_Glyph · size=24 · insn=0 */

/* ── FUNC 0x2e5ef1 · FT_Get_Module · size=56 · insn=0 */

/* ── FUNC 0x2e5f29 · FT_Get_Module_Interface · size=14 · insn=0 */

/* ── FUNC 0x2e5f36 · anon_2e5f36 · size=180 · insn=45 */
/* @0x2e5f36 .word 0x460eb5f8 */
/* @0x2e5f3a .word 0x46044615 */
/* @0x2e5f3e andhs r11, r0, r8, lsl #18 */
/* @0x2e5f42 stmdavs r3, {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x2e5f46 .word 0xb1bb6a1b */
/* @0x2e5f4a .word 0xb1c54798 */
/* @0x2e5f4e stmdavs r3!, {r3, r4, r5, r7, r8, r11, r12, sp, pc} ^ */
/* @0x2e5f52 ldreq pc, [r4, #-0x103] */
/* @0x2e5f56 bl 0x4403da <g_RomDisk+0x48bba> */
/* @0x2e5f5a adcsmi r0, sp, #35389440 */
/* @0x2e5f5e .word 0xf855d2ef */
/* @0x2e5f62 adcmi r0, r0, #4, #22 */
/* @0x2e5f66 stmdavs r3, {r0, r3, r4, r5, r6, r7, r12, lr, pc} */
/* @0x2e5f6a blhs 0x3007de <TT_New_Context+0x5d6> */
/* @0x2e5f6e shsub8mi sp, r1, r5 */
/* @0x2e5f72 stmdahs r0, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e5f76 strd sp, lr, [r2], -r1 */
/* @0x2e5f7a mvnle r2, r0, lsl #20 */
/* @0x2e5f7e ldcllt p7, c14, [r8, #892]! */
/* @0x2e5f82 .word 0xf04fb513 */
/* @0x2e5f86 strhs r0, [r1], #-3584 */
/* @0x2e5f8a andsmi lr, r0, sp, lsl #17 */
/* @0x2e5f8e mrc2 p7, #0x3, apsr_nzcv, c7, c14, #0x7 */
/* @0x2e5f92 ldclt p0, c11, [r0, #-8] */
/* @0x2e5f96 strhs r11, [r0], #-1299 */
/* @0x2e5f9a strls r9, [r1], #-1024 */
/* @0x2e5f9e mcr2 p7, #0x3, pc, c15, c14, #0x7 */
/* @0x2e5fa2 ldclt p0, c11, [r0, #-8] */
/* @0x2e5fa6 strhs r11, [r1], #-1299 */
/* @0x2e5faa strls r9, [r1], #-1024 */
/* @0x2e5fae mcr2 p7, #0x3, pc, c7, c14, #0x7 */
/* @0x2e5fb2 ldclt p0, c11, [r0, #-8] */
/* @0x2e5fb6 .word 0xf8d0b130 */
/* @0x2e5fba movwlo r3, #0x10bc */
/* @0x2e5fbe adcslo pc, r12, r0, asr #17 */
/* @0x2e5fc2 ldrbmi r2, [r0, -r0]! */
/* @0x2e5fc6 ldrbmi r2, [r0, -r1, lsr #32]! */
/* @0x2e5fca tstlt r8, r0, lsr r5 */
/* @0x2e5fce stmvs r4, {r0, r2, r6, r11, sp, lr} */
/* @0x2e5fd2 and r6, r1, r0, asr #17 */
/* @0x2e5fd6 strmi r4, [r5], -r4, lsl #12 */
/* @0x2e5fda andvs r11, sp, r1, lsl #2 */
/* @0x2e5fde andsvs r11, r4, r2, lsl #2 */
/* @0x2e5fe2 andsvs r11, r8, r3, lsl #2 */
/* @0x2e5fe6 teqlt r0, r0, lsr sp */

/* ── FUNC 0x2e5f37 · ft_module_get_service · size=76 · insn=0 */

/* ── FUNC 0x2e5f83 · FT_Property_Set · size=20 · insn=0 */

/* ── FUNC 0x2e5f97 · FT_Property_Get · size=16 · insn=0 */

/* ── FUNC 0x2e5fa7 · ft_property_string_set · size=16 · insn=0 */

/* ── FUNC 0x2e5fb7 · FT_Reference_Library · size=20 · insn=0 */

/* ── FUNC 0x2e5fcb · FT_Library_Version · size=30 · insn=0 */

/* ── FUNC 0x2e5fe8 · anon_2e5fe8 · size=824 · insn=206 */
/* @0x2e5fe8 .word 0xb12ab130 */
/* @0x2e5fec svclt #0x9c2903 */
/* @0x2e5ff0 orreq lr, r1, r0, lsl #22 */
/* @0x2e5ff4 adchs pc, r12, r1, asr #17 */
/* @0x2e5ff8 andeq r4, r0, r0, ror r7 */
/* @0x2e5ffc stmdblt r8, {r3, r8, r10, r12, sp, pc} */
/* @0x2e6000 stclt p0, c2, [r8, #-0] */
/* @0x2e6004 ldrbtmi r4, [r9], #-2311 */
/* @0x2e6008 .word 0xff72f7ff */
/* @0x2e600c rscsle r2, r7, r0, lsl #16 */
/* @0x2e6010 andhs r4, r0, #81920 */
/* @0x2e6014 .word 0xf7ff4479 */
/* @0x2e6018 stmdahs r0, {r1, r2, r3, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e601c stmdavs r0, {r4, r5, r6, r7, r12, lr, pc} */
/* @0x2e6020 svclt #0xbd08 */
/* @0x2e6024 andeq r8, r10, r10, lsl r7 */
/* @0x2e6028 andeq r8, r10, r5, lsl r7 */
/* @0x2e602c .word 0x9c07b5f0 */
/* @0x2e6030 .word 0xf8d0b1e8 */
/* @0x2e6034 bicslt r5, r5, r4, lsl #1 */
/* @0x2e6038 svcmi #0xe6c86 */
/* @0x2e603c ldrhle r4, [r6, -lr] */
/* @0x2e6040 .word 0x0080f8d0 */
/* @0x2e6044 andsle r4, r2, #268435464 */
/* @0x2e6048 stmdane r8!, {r0, r3, r6, r8} ^ */
/* @0x2e604c andsvs r5, r1, r9, ror #16 */
/* @0x2e6050 andsvs r8, r10, r2, lsl #17 */
/* @0x2e6054 stmvs r2, {r0, r2, r8, r9, r11, r12, pc} */
/* @0x2e6058 blls 0x47e0c8 <targetStr+0x2e88> */
/* @0x2e605c andsvs r6, r10, r2, asr #17 */
/* @0x2e6060 tsteq r0, #0, #2 */
/* @0x2e6064 stm r4, {r0, r1, r2, r3, r8, r9, r11, lr, pc} */
/* @0x2e6068 andhs r0, r0, pc */
/* @0x2e606c strdhs r11, r12, [r6], -r0 */
/* @0x2e6070 svclt #0xbdf0 */
/* @0x2e6074 .word 0x636f6d70 */
/* @0x2e6078 svcmi #0xf0e92d */
/* @0x2e607c .word 0x460fb093 */
/* @0x2e6080 mulls r3, r1, r6 */
/* @0x2e6084 .word 0xf0002800 */
/* @0x2e6088 stmdbhs r0, {r3, r7, pc} */
/* @0x2e608c mrshi pc, spsr */
/* @0x2e6090 .word 0xf10d2300 */
/* @0x2e6094 stmdbvs sp, {r6, r11} */
/* @0x2e6098 movwls r6, #0x594e */
/* @0x2e609c andshi pc, r12, sp, asr #17 */
/* @0x2e60a0 .word 0xf8d0e06a */
/* @0x2e60a4 stmdage r10, {r2, pc} */
/* @0x2e60a8 bl 0x50a0b4 <SrcVerts+0x670f8> */
/* @0x2e60ac bl 0x4e73c0 <SrcVerts+0x44404> */
/* @0x2e60b0 bls 0x328fc0 */
/* @0x2e60b4 muleq r3, r4, r8 */
/* @0x2e60b8 andeq lr, r3, r2, lsl #17 */
/* @0x2e60bc .word 0xfc05fa00 */
/* @0x2e60c0 bl 0xff48c8f4 <b2_toiTime+0xfffffffffed33450> */
/* @0x2e60c4 stmdbls r4, {r2, r3, r10, r11} */
/* @0x2e60c8 eorgt pc, r8, sp, asr #17 */
/* @0x2e60cc blne 0xfe77637c <b2_toiTime+0xfffffffffe01ced8> */
/* @0x2e60d0 .word 0xf858920b */
/* @0x2e60d4 .word 0xf10d0031 */
/* @0x2e60d8 .word 0xf8db0820 */
/* @0x2e60dc .word 0xf8cd1004 */
/* @0x2e60e0 .word 0xf8dd8008 */
/* @0x2e60e4 adcmi r8, r8, r4 */
/* @0x2e60e8 blx 0x4648f4 <g_RomDisk+0x6d0d4> */
/* @0x2e60ec ldm r8, {r1, r2, r12, pc} */
/* @0x2e60f0 .word 0xf8dd0003 */
/* @0x2e60f4 stm r8, {r3, pc} */
/* @0x2e60f8 stmdals r3, {r0, r1} */
/* @0x2e60fc bl 0x340308 */
/* @0x2e6100 stclpl p8, c0, [r11], {3} */
/* @0x2e6104 movweq pc, #0x3003 */
/* @0x2e6108 suble r2, r6, r2, lsl #22 */
/* @0x2e610c suble r2, r6, r0, lsl #22 */
/* @0x2e6110 stmdage r10, {r0, r1, r3, r4, r5, r11, sp, lr} */
/* @0x2e6114 ldrmi r4, [r8, r9, asr #12] */
/* @0x2e6118 .word 0xf0402800 */
/* @0x2e611c stmdage r12, {r0, r2, r3, r4, r5, r6, r7, pc} */
/* @0x2e6120 ldrbmi r9, [r12, #-0x6] */
/* @0x2e6124 rscshi pc, r0, r0, lsl #1 */
/* @0x2e6128 mullo r1, r8, r8 */
/* @0x2e612c beq 0x522544 <SrcVerts+0x7f588> */
/* @0x2e6130 andeq pc, r1, #8, #2 */
/* @0x2e6134 movweq pc, #0x3013 */
/* @0x2e6138 stmvs r3!, {r0, r4, r6, r8, r12, lr, pc} */
/* @0x2e613c blne 0xfe9b63f0 <b2_toiTime+0xfffffffffe25cf4c> */
/* @0x2e6140 stmvs r3!, {r3, r8, r9, r12, pc} ^ */
/* @0x2e6144 streq pc, [r2], #-264 */
/* @0x2e6148 blne 0xfe9b63fc <b2_toiTime+0xfffffffffe25cf58> */
/* @0x2e614c ldrbmi r9, [r3], -r9, lsl #6 */
/* @0x2e6150 cmple r9, #381681664 */
/* @0x2e6154 stmdage r8, {r0, r1, r3, r4, r5, r7, r11, sp, lr} */
/* @0x2e6158 strbmi r10, [r10], -r10, lsl #18 */
/* @0x2e615c stmdahs r0, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x2e6160 sbcshi pc, r10, r0, asr #32 */
/* @0x2e6164 ldrsbhi pc, [r0], -sp */
/* @0x2e6168 movweq pc, #0x1108 */
/* @0x2e616c ldrsbhi pc, [r4], -sp */
/* @0x2e6170 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x2e6174 andshi pc, r4, sp, asr #17 */
/* @0x2e6178 .word 0xf8dd9803 */
/* @0x2e617c rfeib r0! */
/* @0x2e6180 ldrmi r2, [r0] */
/* @0x2e6184 sbchi pc, r5, r0, lsl #5 */
/* @0x2e6188 .word 0xf8dd9803 */
/* @0x2e618c stmvs r2, {r2, r4, pc} ^ */
/* @0x2e6190 andshs pc, r8, r2, lsr r9 */
/* @0x2e6194 andls r2, r4, #0, #20 */
/* @0x2e6198 andshs sp, r4, r3, lsl #21 */
/* @0x2e619c .word 0xf8dde0bc */
/* @0x2e61a0 blls 0x49e1e8 <TimingData+0x41d0> */
/* @0x2e61a4 andne pc, lr, r1, lsl r8 */
/* @0x2e61a8 bl 0xff46d010 <b2_toiTime+0xfffffffffed13b6c> */
/* @0x2e61ac .word 0xf001030a */
/* @0x2e61b0 stmdbhs r1, {r0, r1, r8} */
/* @0x2e61b4 andls sp, r10, r4, lsl #2 */
/* @0x2e61b8 bleq 0x52286c <SrcVerts+0x7f8b0> */
/* @0x2e61bc and r9, r10, r11, lsl #6 */
/* @0x2e61c0 ldrmi r4, [r10], #-1156 */
/* @0x2e61c4 vldmiavc r12, {d30, d31} */
/* @0x2e61c8 sbcsvc lr, r2, #2048 */
/* @0x2e61cc .word 0x016cea4f */
/* @0x2e61d0 qaddls r1, r2, r10 */
/* @0x2e61d4 .word 0x3c08920b */
/* @0x2e61d8 ldmlo pc!, {r3, r8, r12, sp, lr, pc} ^ */
/* @0x2e61dc blhs 0x360044 <_ZTS12CDS_Priority+0x209c> */
/* @0x2e61e0 stmvs r3!, {r0, r4, r6, r8, r12, lr, pc} */
/* @0x2e61e4 .word 0x4649a810 */
/* @0x2e61e8 blne 0xfe9b649c <b2_toiTime+0xfffffffffe25cff8> */
/* @0x2e61ec stmvs r3!, {r4, r8, r9, r12, pc} ^ */
/* @0x2e61f0 blne 0xfe9b64a4 <b2_toiTime+0xfffffffffe25d000> */
/* @0x2e61f4 ldmdavs r11!, {r0, r4, r8, r9, r12, pc} ^ */
/* @0x2e61f8 ldrmi r9, [r8, r0, lsl #4] */
/* @0x2e61fc stmdahs r0, {r9, r11, r12, pc} */
/* @0x2e6200 addhi pc, r10, r0, asr #32 */
/* @0x2e6204 .word 0xe07d4690 */
/* @0x2e6208 ssatmi r6, #0x1, r10, lsl #17 */
/* @0x2e620c mulne r0, r8, r8 */
/* @0x2e6210 .word 0x0c08f103 */
/* @0x2e6214 adcmi r3, r10, r1, lsl #8 */
/* @0x2e6218 mrseq pc, apsr */
/* @0x2e621c andls r1, lr, #149504 */
/* @0x2e6220 stmdbhs r1, {r0, r1, r3, r4, r6, r7, r11, sp, lr} */
/* @0x2e6224 blx 0x3b7db4 <error_g0017+0x10a58> */
/* @0x2e6228 bl 0xff4a2e44 <b2_toiTime+0xfffffffffed499a0> */
/* @0x2e622c movwls r0, #0xf303 */
/* @0x2e6230 ldmvs r11!, {r0, r1, r2, r8, r12, lr, pc} */
/* @0x2e6234 stmdbge lr, {r3, r11, sp, pc} */
/* @0x2e6238 ldrmi r4, [r8, r10, asr #12] */
/* @0x2e623c .word 0xd16b2800 */
/* @0x2e6240 stmdbhs r0, {r5, r6, sp, lr, pc} */
/* @0x2e6244 stmdbls r8, {r0, r3, r5, r7, r8, r12, lr, pc} */
/* @0x2e6248 strmi r10, [r10], #-2056 */
/* @0x2e624c bl 0x390694 <_ZTS11b2GearJoint+0xf4> */
/* @0x2e6250 ldrsbne r7, [r2], #-34 */
/* @0x2e6254 bls 0x54aa9c <gp_ActiveMaskObjects+0x5dd4> */
/* @0x2e6258 .word 0x464a4413 */
/* @0x2e625c bicsvc lr, r3, #3072 */
/* @0x2e6260 tstls r1, #91 */
/* @0x2e6264 .word 0xf8cd68bb */
/* @0x2e6268 ldrmi r12, [r8, r0] */
/* @0x2e626c .word 0xc000f8dd */
/* @0x2e6270 cmple r1, r0, lsl #16 */
/* @0x2e6274 .word 0xf8ddab0e */
/* @0x2e6278 ldm r3, {r3, pc} */
/* @0x2e627c strbtmi r0, [r3], -r3 */
/* @0x2e6280 andeq lr, r3, r8, lsl #17 */
/* @0x2e6284 .word 0xf104e764 */
/* @0x2e6288 ldrmi r0, [r11, #0x310] */
/* @0x2e628c .word 0xf898d385 */
/* @0x2e6290 .word 0xf0033002 */
/* @0x2e6294 blhs 0x366ea8 <_ZTS12CDS_Priority+0x8f00> */
/* @0x2e6298 svcge #0x7ff47f */
/* @0x2e629c .word 0xf10468a3 */
/* @0x2e62a0 ldrbmi r0, [r10, #0xa18] */
/* @0x2e62a4 blx 0x3d06e4 <error_g0017+0x29388> */
/* @0x2e62a8 bl 0xff4a2ec4 <b2_toiTime+0xfffffffffed49a20> */
/* @0x2e62ac movwls r0, #0xc303 */
/* @0x2e62b0 blx 0x3c0644 <error_g0017+0x192e8> */
/* @0x2e62b4 bl 0xff4a2ed0 <b2_toiTime+0xfffffffffed49a2c> */
/* @0x2e62b8 movwls r0, #0xd303 */
/* @0x2e62bc blx 0x3c0750 <error_g0017+0x193f4> */
/* @0x2e62c0 bl 0xff4a2edc <b2_toiTime+0xfffffffffed49a38> */
/* @0x2e62c4 movwls r0, #0xe303 */
/* @0x2e62c8 blx 0x3c085c <error_g0017+0x19500> */
/* @0x2e62cc bl 0xff4a2ee8 <b2_toiTime+0xfffffffffed49a44> */
/* @0x2e62d0 movwls r0, #0xf303 */
/* @0x2e62d4 stmibvs r3!, {r4, r11, r12, lr, pc} */
/* @0x2e62d8 bge 0x710310 <g_SWFvertbuff+0x3d248> */
/* @0x2e62dc blne 0xfe9b6590 <b2_toiTime+0xfffffffffe25d0ec> */
/* @0x2e62e0 stmibvs r3!, {r4, r8, r9, r12, pc} ^ */
/* @0x2e62e4 .word 0x40ab68fc */
/* @0x2e62e8 tstls r1, #158720 */
/* @0x2e62ec strmi r4, [r0, r11, asr #12]! */
/* @0x2e62f0 cpsie ai */
/* @0x2e62f4 and r0, r5, r3, lsl #16 */
/* @0x2e62f8 stmdage r12, {r2, r3, r4, r5, r6, r7, r11, sp, lr} */
/* @0x2e62fc strbmi r10, [r11], -r10, lsl #20 */
/* @0x2e6300 str r4, [r12, -r0, lsr #15]! */
/* @0x2e6304 smlsd r12, r4, r6, r4 */
/* @0x2e6308 stmdage r10, {r0, r1, r3, r4, r5, r6, r11, sp, lr} */
/* @0x2e630c ldrmi r4, [r8, r9, asr #12] */
/* @0x2e6310 andhs lr, r0, r5, lsr #14 */
/* @0x2e6314 andhs lr, r6, r0 */
/* @0x2e6318 pop {r0, r1, r4, r12, sp, pc} */
/* @0x2e631c ldrlt r8, [r0, #-0xff0]! */

/* ── FUNC 0x2e5fe9 · FT_Set_Debug_Hook · size=18 · insn=0 */

/* ── FUNC 0x2e5ffd · FT_Get_TrueType_Engine_Type · size=48 · insn=0 */

/* ── FUNC 0x2e602d · FT_Get_SubGlyph_Info · size=76 · insn=0 */

/* ── FUNC 0x2e6079 · FT_Outline_Decompose · size=678 · insn=0 */

/* ── FUNC 0x2e631e · anon_2e631e · size=80 · insn=20 */
/* @0x2e631e tstlt r0, #48, #10 */
/* @0x2e6322 strhne pc, [r2], -r0 */
/* @0x2e6326 strhmi pc, [r0], -r0 */
/* @0x2e632a .word 0xd1042900 */
/* @0x2e632e svclt #0x142c00 */
/* @0x2e6332 andhs r2, r0, r6 */
/* @0x2e6336 ldcle p13, c11, [r6, #-192] */
/* @0x2e633a ldcle p12, c2, [r4, #-0] */
/* @0x2e633e andhs r6, r0, #12910592 */
/* @0x2e6342 rscslo pc, pc, pc, asr #32 */
/* @0x2e6346 andslo pc, r2, r5, lsr r9 */
/* @0x2e634a stcle p2, c4, [r12, #-524] */
/* @0x2e634e ble 0x576d82 <g_SWFlineaavertbuff+0x23cba> */
/* @0x2e6352 adcmi r3, r2, #268435456 */
/* @0x2e6356 ldrmi sp, [r8], -r1, lsl #20 */
/* @0x2e635a mcrne p7, #0x2, lr, c8, c4, #0x7 */
/* @0x2e635e svclt #0x144283 */
/* @0x2e6362 andhs r2, r0, r6 */
/* @0x2e6366 andhs r11, r6, r0, lsr sp */
/* @0x2e636a ldrlt r11, [r8, #-0xd30]! */

/* ── FUNC 0x2e631f · FT_Outline_Check · size=78 · insn=0 */

/* ── FUNC 0x2e636c · anon_2e636c · size=232 · insn=58 */
/* @0x2e636c .word 0x460db538 */
/* @0x2e6370 .word 0xb3284604 */
/* @0x2e6374 stmdavs r2, {r0, r5, r8, r9, r12, sp, pc} */
/* @0x2e6378 addsmi r6, r10, #720896 */
/* @0x2e637c addmi sp, r8, #-2147483640 */
/* @0x2e6380 stmdahi r2, {r1, r5, r12, lr, pc} ^ */
/* @0x2e6384 andslt r11, r2, #-2147483626 */
/* @0x2e6388 stmdavs r1!, {r3, r6, r11, sp, lr} ^ */
/* @0x2e638c .word 0xf5d000d2 */
/* @0x2e6390 stmvs r8!, {r1, r2, r4, r8, r11, sp, lr, pc} */
/* @0x2e6394 rfeib r4! */
/* @0x2e6398 .word 0xf5d02002 */
/* @0x2e639c stmdahi r2!, {r4, r8, r11, sp, lr, pc} */
/* @0x2e63a0 andslt r11, r2, #-2147483638 */
/* @0x2e63a4 stmvs r1!, {r3, r5, r6, r7, r11, sp, lr} ^ */
/* @0x2e63a8 .word 0xf5d00052 */
/* @0x2e63ac stmdbvs r2!, {r3, r8, r11, sp, lr, pc} */
/* @0x2e63b0 .word 0xf022692b */
/* @0x2e63b4 .word 0xf0030201 */
/* @0x2e63b8 tstmi r3, #67108864 */
/* @0x2e63bc and r6, r3, r11, lsr #2 */
/* @0x2e63c0 ldclt p0, c2, [r8, #-80]! */
/* @0x2e63c4 ldclt p0, c2, [r8, #-24]! */
/* @0x2e63c8 ldclt p0, c2, [r8, #-0]! */
/* @0x2e63cc movtlt r11, #0x5f0 */
/* @0x2e63d0 stmdahi r3, {r0, r3, r4, r5, r8, r9, r12, sp, pc} ^ */
/* @0x2e63d4 stmdavs r4, {r0, r1, r3, r4, r5, r6, r7, r8, r12, sp, pc} ^ */
/* @0x2e63d8 .word 0xf104b21b */
/* @0x2e63dc bl 0x3e7804 <error_g0017+0x404a8> */
/* @0x2e63e0 ldm r4, {r0, r1, r6, r7, r8, r9, r10} */
/* @0x2e63e4 ldrmi r0, [r3], -r5 */
/* @0x2e63e8 adcmi r4, pc, #4, #12 */
/* @0x2e63ec streq pc, [r8], -r5, lsl #2 */
/* @0x2e63f0 .word 0xf856d914 */
/* @0x2e63f4 adcmi r5, r8, #8, #24 */
/* @0x2e63f8 strtmi r11, [r8], -r8, lsr #31 */
/* @0x2e63fc svclt #0xb842ac */
/* @0x2e6400 .word 0xf856462c */
/* @0x2e6404 adcmi r5, r10, #4, #24 */
/* @0x2e6408 strtmi r11, [r10], -r8, lsr #31 */
/* @0x2e640c svclt #0xb842ab */
/* @0x2e6410 ldrtmi r4, [r5], -r11, lsr #12 */
/* @0x2e6414 ldrmi lr, [r12], -r9, ror #15 */
/* @0x2e6418 sadd16mi r4, r8, r10 */
/* @0x2e641c andseq lr, r5, r1, lsl #17 */
/* @0x2e6420 ldcllt p0, c6, [r0, #812]! */
/* @0x2e6424 orrslt r11, r8, r0, lsr r5 */
/* @0x2e6428 strhs r6, [r0], #-2115 */
/* @0x2e642c strhpl pc, [r2], -r0 */
/* @0x2e6430 adcmi r3, r12, #8, #6 */
/* @0x2e6434 .word 0xf853da0c */
/* @0x2e6438 strlo r5, [r1], #-3080 */
/* @0x2e643c .word 0xf843440d */
/* @0x2e6440 .word 0xf8535c08 */
/* @0x2e6444 adclt r5, r4, #4, #24 */
/* @0x2e6448 .word 0xf8434415 */
/* @0x2e644c strb r5, [sp, r4, lsl #24]! */
/* @0x2e6450 push {r4, r5, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2e636d · FT_Outline_Copy · size=96 · insn=0 */

/* ── FUNC 0x2e63cd · FT_Outline_Get_CBox · size=88 · insn=0 */

/* ── FUNC 0x2e6425 · FT_Outline_Translate · size=46 · insn=0 */

/* ── FUNC 0x2e6452 · anon_2e6452 · size=120 · insn=30 */
/* @0x2e6452 mvnsmi lr, sp, lsr #18 */
/* @0x2e6456 orrslt r4, r8, #3145728 */
/* @0x2e645a ldrtmi r2, [r5], -r0, lsl #12 */
/* @0x2e645e strhhs pc, [r0], -r3 */
/* @0x2e6462 ble 0xd36ebe <b2_toiTime+0x5dda1a> */
/* @0x2e6466 ldmdavs r12, {r1, r3, r4, r6, r7, r11, sp, lr} ^ */
/* @0x2e646a andsvc pc, r5, r2, lsr r9 */
/* @0x2e646e sbceq lr, r6, #4, #22 */
/* @0x2e6472 strbeq lr, [r7], #2820 */
/* @0x2e6476 .word 0xf1a442a2 */
/* @0x2e647a .word 0xf1020408 */
/* @0x2e647e andle r0, r11, #8, #4 */
/* @0x2e6482 .word 0x0108f104 */
/* @0x2e6486 .word 0x1100e912 */
/* @0x2e648a stmdb r2, {r0, r1, r8, r11, lr, pc} */
/* @0x2e648e .word 0xf8c40003 */
/* @0x2e6492 .word 0xf8c48008 */
/* @0x2e6496 strb r12, [sp, r12]! */
/* @0x2e649a ldrmi r6, [r6], #-2202 */
/* @0x2e649e addsmi r4, r6, #973078528 */
/* @0x2e64a2 ldmdavc r1!, {r1, r2, r9, r12, lr, pc} */
/* @0x2e64a6 .word 0xf8067810 */
/* @0x2e64aa .word 0xf8020b01 */
/* @0x2e64ae ldrb r1, [r6, r1, lsl #18]! */
/* @0x2e64b2 ldclne p5, c3, [lr], #-4 */
/* @0x2e64b6 ldrb r11, [r1, sp, lsr #5] */
/* @0x2e64ba .word 0xf082691a */
/* @0x2e64be tstvs r10, r4, lsl #4 */
/* @0x2e64c2 ldrhhi lr, [r0, #141]! */
/* @0x2e64c6 ldrblt r0, [r7, #0x0]! */

/* ── FUNC 0x2e6453 · FT_Outline_Reverse · size=116 · insn=0 */

/* ── FUNC 0x2e64c8 · anon_2e64c8 · size=944 · insn=236 */
/* @0x2e64c8 ssub8mi r11, r6, r7 */
/* @0x2e64cc bicslt r4, r0, r5, lsl #12 */
/* @0x2e64d0 ldrdlt r11, r12, [r2, #25]! */
/* @0x2e64d4 ldrsblo pc, [r4], r5 */
/* @0x2e64d8 ldrhs r10, [r3], #-3842 */
/* @0x2e64dc ldrsbeq pc, [r12], r0 */
/* @0x2e64e0 .word 0xf8476051 */
/* @0x2e64e4 lsllt r3, r4, #26 */
/* @0x2e64e8 ldrtmi r6, [r1], -r3, lsl #23 */
/* @0x2e64ec ldrmi r6, [r8, r0, asr #22] */
/* @0x2e64f0 cmnlt r0, r4, lsl #12 */
/* @0x2e64f4 blhs 0x7d3008 <b2_toiTime+0x79b64> */
/* @0x2e64f8 strtmi sp, [r8], -r11, lsl #2 */
/* @0x2e64fc ldrtmi r4, [r10], -r6, lsl #18 */
/* @0x2e6500 ldc2 p7, c15, [r9], {255} */
/* @0x2e6504 eorhs lr, r1, pc, ror #15 */
/* @0x2e6508 andshs lr, r4, r4 */
/* @0x2e650c andhs lr, r6, r2 */
/* @0x2e6510 strtmi lr, [r0], -r0 */
/* @0x2e6514 ldcllt p0, c11, [r0, #12]! */
/* @0x2e6518 svcvs #0x75746c */
/* @0x2e651c addlt r11, sp, r0, lsl #10 */
/* @0x2e6520 movwhs r11, #0x172 */
/* @0x2e6524 ldcvc p3, c9, [r3], {2} */
/* @0x2e6528 blhs 0x38ad30 <bigtens_D2A+0x1200> */
/* @0x2e652c bllo 0x45a53c <g_RomDisk+0x62d1c> */
/* @0x2e6530 stmdale r1, {r0, r8, r9, r11, sp} */
/* @0x2e6534 movwls r2, #0x2301 */
/* @0x2e6538 .word 0xf7ff466a */
/* @0x2e653c and pc, r0, r5, asr #31 */
/* @0x2e6540 andlt r2, sp, r6 */
/* @0x2e6544 blx 0x4246c2 <g_RomDisk+0x2cea2> */
/* @0x2e6548 .word 0x460db5f8 */
/* @0x2e654c lslslt r4, r4, #12 */
/* @0x2e6550 stmdavs r9, {r0, r3, r5, r7, r8, r12, sp, pc} */
/* @0x2e6554 .word 0xf7fe6800 */
/* @0x2e6558 stmdavs r9!, {r0, r3, r4, r5, r6, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e655c stmdavs r0!, {r1, r2, r9, r10, lr} ^ */
/* @0x2e6560 ldc2l p7, c15, [r4], #-1016 */
/* @0x2e6564 strmi r6, [r6], #-2217 */
/* @0x2e6568 .word 0xf7fe6820 */
/* @0x2e656c stmvs r9!, {r0, r1, r2, r3, r5, r6, r10, r11, r12, sp, lr, pc} ^ */
/* @0x2e6570 stmdavs r0!, {r0, r1, r2, r9, r10, lr} ^ */
/* @0x2e6574 stc2l p7, c15, [r10], #-1016 */
/* @0x2e6578 ldrtmi r6, [r8], #-38 */
/* @0x2e657c ldcllt p0, c6, [r8, #384]! */
/* @0x2e6580 .word 0x460db570 */
/* @0x2e6584 .word 0xb161b168 */
/* @0x2e6588 strhvs pc, [r2], -r0 */
/* @0x2e658c bl 0x4006a4 <g_RomDisk+0x8e84> */
/* @0x2e6590 adcsmi r0, r4, #207618048 */
/* @0x2e6594 strtmi sp, [r0], -r5, lsl #4 */
/* @0x2e6598 .word 0xf7ff4629 */
/* @0x2e659c strlo pc, [r8], #-4053 */
/* @0x2e65a0 ldcllt p7, c14, [r0, #-988]! */
/* @0x2e65a4 svcmi #0xf0e92d */
/* @0x2e65a8 addlt r4, r7, r4, lsl #12 */
/* @0x2e65ac andhs r11, r0, r8, lsl #18 */
/* @0x2e65b0 rfeib r0! */
/* @0x2e65b4 blhs 0x2f25c4 <ps_hints_apply+0x11c4> */
/* @0x2e65b8 stmdbge r2, {r0, r3, r4, r5, r6, r7, r8, r10, r11, r12, lr, pc} */
/* @0x2e65bc .word 0xff06f7ff */
/* @0x2e65c0 stmdbls r4, {r1, r11, r12, pc} */
/* @0x2e65c4 suble r4, sp, r8, lsl #5 */
/* @0x2e65c8 bls 0x44d1dc <g_RomDisk+0x559bc> */
/* @0x2e65cc umaalle r4, r9, r3, r2 */
/* @0x2e65d0 vstmiavc r0!, {s29, s30, s31} */
/* @0x2e65d4 vstmiavc r0!, {d30, d31} */
/* @0x2e65d8 svclt #0xb82900 */
/* @0x2e65dc bl 0xff3b6f08 <b2_toiTime+0xfffffffffec5da64> */
/* @0x2e65e0 b 0x15e85f0 <b2_toiTime+0xe8f14c> */
/* @0x2e65e4 blx 0xff1e95f0 <b2_toiTime+0xfffffffffea9014c> */
/* @0x2e65e8 blx 0xff125820 <b2_toiTime+0xfffffffffe9cc37c> */
/* @0x2e65ec .word 0xf1ccf888 */
/* @0x2e65f0 .word 0xf1c80c11 */
/* @0x2e65f4 rfeib r4! */
/* @0x2e65f8 movwhs r0, #0x0 */
/* @0x2e65fc b 0xe0079c <b2_toiTime+0x6a72f8> */
/* @0x2e6600 b 0xd059b8 <b2_toiTime+0x5ac514> */
/* @0x2e6604 ldrmi r7, [r10], -r8, ror #17 */
/* @0x2e6608 andls r4, r1, r9, lsl r6 */
/* @0x2e660c addmi r9, r1, #65536 */
/* @0x2e6610 stmvs r0!, {r0, r2, r5, r9, r11, r12, lr, pc} ^ */
/* @0x2e6614 andseq pc, r1, r0, lsr r9 */
/* @0x2e6618 eorspl pc, r0, r6, asr r8 */
/* @0x2e661c strbeq lr, [r0, r6, lsl #22] */
/* @0x2e6620 blx 0x624f3c <g_SWFaavertbuff+0x51e74> */
/* @0x2e6624 blx 0x1440820 <b2_toiTime+0xce737c> */
/* @0x2e6628 bl 0x4a4a50 <SrcVerts+0x1a94> */
/* @0x2e662c addmi r0, r2, #813694976 */
/* @0x2e6630 streq pc, [r8, #-0x105] */
/* @0x2e6634 .word 0xf855dc10 */
/* @0x2e6638 andlo r7, r1, #8, #24 */
/* @0x2e663c blx 0x624f62 <g_SWFaavertbuff+0x51e9a> */
/* @0x2e6640 .word 0x7c04f855 */
/* @0x2e6644 blx 0x14b79b4 <b2_toiTime+0xd5e510> */
/* @0x2e6648 bl 0xff564270 <b2_toiTime+0xfffffffffee0adcc> */
/* @0x2e664c blx 0x568a72 <g_SWFlineaavertbuff+0x159aa> */
/* @0x2e6650 ldrtmi r3, [r9], r9, lsl #6 */
/* @0x2e6654 ubfx r4, r10, #0xd, #0xb */
/* @0x2e6658 .word 0x31011c42 */
/* @0x2e665c blhs 0x3205bc */
/* @0x2e6660 .word 0xd1a4dc02 */
/* @0x2e6664 and r2, r0, r2 */
/* @0x2e6668 andlt r2, r7, r1 */
/* @0x2e666c svchi #0xf0e8bd */
/* @0x2e6670 svcmi #0xf0e92d */
/* @0x2e6674 mulls r1, r1, r0 */
/* @0x2e6678 .word 0xf0002800 */
/* @0x2e667c bl 0x346a4c */
/* @0x2e6680 bl 0x382dcc <_ZTS13C_UTF16String+0x19e78> */
/* @0x2e6684 ldrdne r7, r8, [r9], #-34 */
/* @0x2e6688 rsbeq lr, r2, #323584 */
/* @0x2e668c andls r9, r6, #1073741826 */
/* @0x2e6690 stmdblt r10, {r1, r8, r12, lr, pc} */
/* @0x2e6694 rsc r2, r5, r0 */
/* @0x2e6698 .word 0xf7ff9801 */
/* @0x2e669c blls 0x3664b0 <_ZTS12CDS_Priority+0x8508> */
/* @0x2e66a0 andls r2, r10, r2, lsl #16 */
/* @0x2e66a4 rfeib r3! */
/* @0x2e66a8 .word 0x28000000 */
/* @0x2e66ac andhs r11, r6, r4, lsl pc */
/* @0x2e66b0 sbcs r2, r7, r0 */
/* @0x2e66b4 movwhs r6, #0x85e */
/* @0x2e66b8 movwls r9, #0x3302 */
/* @0x2e66bc movwls r10, #0xdb0e */
/* @0x2e66c0 rfeib r2! */
/* @0x2e66c4 bls 0x3b26cc <error_g0017+0xb370> */
/* @0x2e66c8 ble 0xffbb7138 <b2_toiTime+0xffffffffff45dc94> */
/* @0x2e66cc .word 0xf04f9a01 */
/* @0x2e66d0 stcls p9, c0, [r2, #-0] */
/* @0x2e66d4 strbmi r4, [r11], pc, asr #12 */
/* @0x2e66d8 ldmvs r3, {r3, r6, r7, r9, r10, lr} ^ */
/* @0x2e66dc .word 0xf8cd9a03 */
/* @0x2e66e0 .word 0xf8cd9030 */
/* @0x2e66e4 rfedb r3! */
/* @0x2e66e8 movwls r3, #0x7012 */
/* @0x2e66ec .word 0xf04f461c */
/* @0x2e66f0 movwls r3, #0x53ff */
/* @0x2e66f4 .word 0xf00042a5 */
/* @0x2e66f8 blls 0x4469b4 <g_RomDisk+0x4f194> */
/* @0x2e66fc .word 0xf000429c */
/* @0x2e6700 blls 0x4469ac <g_RomDisk+0x4f18c> */
/* @0x2e6704 mulsle r5, sp, r2 */
/* @0x2e6708 eorshs pc, r5, r6, asr r8 */
/* @0x2e670c sbceq lr, r5, r6, lsl #22 */
/* @0x2e6710 eorslo pc, r4, r6, asr r8 */
/* @0x2e6714 biceq lr, r4, r6, lsl #22 */
/* @0x2e6718 stmdavs r2, {r0, r1, r4, r6, r7, r9, r11, r12} ^ */
/* @0x2e671c stmdage lr, {r1, r2, r3, r8, r9, r12, pc} */
/* @0x2e6720 bne 0xff7c0854 <b2_toiTime+0xffffffffff0673b0> */
/* @0x2e6724 .word 0xf7fe930f */
/* @0x2e6728 strhls pc, [r4], -r6 */
/* @0x2e672c .word 0xf0002800 */
/* @0x2e6730 and r8, r5, r11, lsl #1 */
/* @0x2e6734 .word 0xf8cd9b0c */
/* @0x2e6738 movwls r9, #0xe03c */
/* @0x2e673c movwls r9, #0x4b0b */
/* @0x2e6740 svceq #0xf1b8 */
/* @0x2e6744 blls 0x45a934 <g_RomDisk+0x63114> */
/* @0x2e6748 ble 0x431350 <g_RomDisk+0x39b30> */
/* @0x2e674c .word 0xf8cd46b9 */
/* @0x2e6750 strls r11, [r5], #-48 */
/* @0x2e6754 eorhi pc, r12, sp, asr #17 */
/* @0x2e6758 ldrbmi r9, [r8], -lr, lsl #18 */
/* @0x2e675c blx 0x20a475e <b2_toiTime+0x194b2ba> */
/* @0x2e6760 strmi r9, [r2], pc, lsl #18 */
/* @0x2e6764 .word 0xf7fe4638 */
/* @0x2e6768 bmi 0x1325534 <b2_toiTime+0xbcc090> */
/* @0x2e676c addsmi r4, r0, #80, #8 */
/* @0x2e6770 .word 0xf500db46 */
/* @0x2e6774 stmdals lr, {r7, r9, r11, r12, sp} */
/* @0x2e6778 bl 0x5cd3bc <g_SWFlineaavertbuff+0x7a2f4> */
/* @0x2e677c andls r0, r8, #0, #4 */
/* @0x2e6780 ldrtmi r9, [r11], #-2570 */
/* @0x2e6784 subsmi r11, r11, #163840 */
/* @0x2e6788 bls 0x51e798 <SrcVerts+0x7b7dc> */
/* @0x2e678c andls r4, r8, #536870917 */
/* @0x2e6790 movwls r4, #0x639 */
/* @0x2e6794 blx 0x19a4796 <b2_toiTime+0x124b2f2> */
/* @0x2e6798 .word 0x46074659 */
/* @0x2e679c .word 0xf7fe980f */
/* @0x2e67a0 bls 0x5a54fc <g_SWFlineaavertbuff+0x52434> */
/* @0x2e67a4 bne 0x12cd3ac <b2_toiTime+0xb73f08> */
/* @0x2e67a8 rsbsmi r11, pc, #32768 */
/* @0x2e67ac ldrtmi r9, [r9], -r4, lsl #20 */
/* @0x2e67b0 strbmi r9, [r2, #-0x809] */
/* @0x2e67b4 .word 0x4690bfb8 */
/* @0x2e67b8 .word 0xf7fe9300 */
/* @0x2e67bc ldrbmi pc, [r1], -r7, asr #22 */
/* @0x2e67c0 strbmi r4, [r0], -r3, lsl #13 */
/* @0x2e67c4 blx 0x13a47c6 <b2_toiTime+0xc4b322> */
/* @0x2e67c8 strmi r9, [r3, #0xb00] */
/* @0x2e67cc svclt #0xd54618 */
/* @0x2e67d0 strbmi r9, [r1], -r9, lsl #18 */
/* @0x2e67d4 shsaxmi r4, r10, r2 */
/* @0x2e67d8 blx 0xfef247d8 <b2_toiTime+0xfffffffffe7cb334> */
/* @0x2e67dc .word 0x46834639 */
/* @0x2e67e0 .word 0xf7fe9806 */
/* @0x2e67e4 uasxmi pc, r1, r3 */
/* @0x2e67e8 strbmi r4, [r0], -r3, lsl #12 */
/* @0x2e67ec .word 0xf7fe9300 */
/* @0x2e67f0 blls 0x3254ac */
/* @0x2e67f4 stmdals r8, {r0, r1, r7, r9, lr} */
/* @0x2e67f8 stmdbls r6, {r0, r3, r10, r11, r12, lr, pc} */
/* @0x2e67fc and r4, r8, r2, asr r6 */
/* @0x2e6800 strmi r2, [r3], r0 */
/* @0x2e6804 ldrmi r9, [r11], #2825 */
/* @0x2e6808 ldrmi r9, [r8], #-2822 */
/* @0x2e680c strbmi lr, [r1], -r4 */
/* @0x2e6810 .word 0xf7fe463a */
/* @0x2e6814 .word 0xe7f5fa93 */
/* @0x2e6818 biceq lr, r4, #6144 */
/* @0x2e681c eorshs pc, r4, r6, asr r8 */
/* @0x2e6820 .word 0xf846445a */
/* @0x2e6824 ldmdavs r10, {r2, r4, r5, sp} ^ */
/* @0x2e6828 subsvs r4, r10, r2, lsl #8 */
/* @0x2e682c addsmi r9, r12, #7168 */
/* @0x2e6830 strlo r11, [r1], #-4020 */
/* @0x2e6834 adcmi r9, r12, #512 */
/* @0x2e6838 and sp, r0, lr, ror #3 */
/* @0x2e683c .word 0xf8dd462c */
/* @0x2e6840 svcls #0xfb038 */
/* @0x2e6844 ldrsbhi pc, [r0], -sp */
/* @0x2e6848 addsmi r9, sp, #7168 */
/* @0x2e684c strlo r11, [r1, #-0xfb4] */
/* @0x2e6850 strb r9, [pc, -r2, lsl #26] */
/* @0x2e6854 movwlo r9, #0x1b07 */
/* @0x2e6858 blls 0x3cb468 <error_g0017+0x2410c> */
/* @0x2e685c movwls r3, #0x3301 */
/* @0x2e6860 andshs lr, r4, lr, lsr #14 */
/* @0x2e6864 pop {r0, r4, r12, sp, pc} */
/* @0x2e6868 svclt #0x8ff0 */
/* @0x2e686c .word 0xffff1001 */
/* @0x2e6870 .word 0xf7ff460a */
/* @0x2e6874 ldrshlt r11, [r8, -sp]! */
