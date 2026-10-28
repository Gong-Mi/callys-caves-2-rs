/* libyoyo.so 覆盖卡组 0288
 * 函数 0x2e4eb7..0x2e54e1，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e4eb7 · FT_DivFix · size=88 · insn=0 */

/* ── FUNC 0x2e4f0f · FT_Matrix_Multiply · size=110 · insn=0 */

/* ── FUNC 0x2e4f7c · anon_2e4f7c · size=84 · insn=21 */
/* @0x2e4f7c .word 0x4604b570 */
/* @0x2e4f80 andhs r11, r6, r8, lsl #18 */
/* @0x2e4f84 stmvs r1!, {r4, r5, r6, r8, r10, r11, r12, sp, pc} ^ */
/* @0x2e4f88 .word 0xf7ff6800 */
/* @0x2e4f8c stmvs r1!, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2e4f90 stmdavs r0!, {r0, r2, r9, r10, lr} ^ */
/* @0x2e4f94 .word 0xff5af7ff */
/* @0x2e4f98 rscsle r1, r2, sp, lsr #20 */
/* @0x2e4f9c stmdavs r0!, {r0, r3, r5, r9, r10, lr} ^ */
/* @0x2e4fa0 .word 0xff89f7ff */
/* @0x2e4fa4 submi r4, r0, #42991616 */
/* @0x2e4fa8 stmvs r0!, {r5, r6, sp, lr} */
/* @0x2e4fac .word 0xff83f7ff */
/* @0x2e4fb0 stmdavs r6!, {r0, r3, r5, r9, r10, lr} */
/* @0x2e4fb4 adcvs r4, r0, r0, asr #4 */
/* @0x2e4fb8 .word 0xf7ff68e0 */
/* @0x2e4fbc qsub16mi pc, r9, r12 */
/* @0x2e4fc0 ldrtmi r6, [r0], -r0, lsr #32 */
/* @0x2e4fc4 .word 0xff77f7ff */
/* @0x2e4fc8 andhs r6, r0, r0, ror #1 */
/* @0x2e4fcc push {r4, r5, r6, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2e4f7d · FT_Matrix_Invert · size=82 · insn=0 */

/* ── FUNC 0x2e4fce · anon_2e4fce · size=132 · insn=33 */
/* @0x2e4fce ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x2e4fd2 strmi r4, [r5], -r12, lsl #12 */
/* @0x2e4fd6 eorsle r2, r8, r0, lsl #16 */
/* @0x2e4fda eorsle r2, r6, r0, lsl #18 */
/* @0x2e4fde stmdavs r9, {r1, r2, r4, r10} */
/* @0x2e4fe2 ldrtmi r6, [r2], -r0, lsl #16 */
/* @0x2e4fe6 mcr2 p7, #0x5, pc, c9, c15, #0x7 */
/* @0x2e4fea ldrtmi r6, [r2], -r1, lsr #17 */
/* @0x2e4fee stmdavs r8!, {r0, r7, r9, r10, lr} ^ */
/* @0x2e4ff2 mcr2 p7, #0x5, pc, c3, c15, #0x7 */
/* @0x2e4ff6 ldrtmi r6, [r2], -r1, ror #16 */
/* @0x2e4ffa stmdavs r8!, {r0, r7, r10, lr} */
/* @0x2e4ffe mrc2 p7, #0x4, apsr_nzcv, c13, c15, #0x7 */
/* @0x2e5002 ldrtmi r6, [r2], -r1, ror #17 */
/* @0x2e5006 stmdavs r8!, {r7, r9, r10, lr} ^ */
/* @0x2e500a mrc2 p7, #0x4, apsr_nzcv, c7, c15, #0x7 */
/* @0x2e500e ldrtmi r6, [r2], -r1, lsr #16 */
/* @0x2e5012 stmvs r8!, {r7, r10, lr} */
/* @0x2e5016 mrc2 p7, #0x4, apsr_nzcv, c1, c15, #0x7 */
/* @0x2e501a ldrtmi r6, [r2], -r1, lsr #17 */
/* @0x2e501e stmvs r8!, {r0, r1, r2, r9, r10, lr} ^ */
/* @0x2e5022 mcr2 p7, #0x4, pc, c11, c15, #0x7 */
/* @0x2e5026 ldrtmi r6, [r2], -r1, ror #16 */
/* @0x2e502a stmvs r8!, {r0, r1, r2, r10, lr} */
/* @0x2e502e mcr2 p7, #0x4, pc, c5, c15, #0x7 */
/* @0x2e5032 ldrtmi r6, [r2], -r1, ror #17 */
/* @0x2e5036 stmvs r8!, {r1, r7, r9, r10, lr} ^ */
/* @0x2e503a mrc2 p7, #0x3, apsr_nzcv, c15, c15, #0x7 */
/* @0x2e503e andls pc, r0, r4, asr #17 */
/* @0x2e5042 andhi pc, r4, r4, asr #17 */
/* @0x2e5046 ldrbmi r6, [r0], #-167 */
/* @0x2e504a pop {r5, r6, r7, sp, lr} */
/* @0x2e504e push {r4, r5, r6, r7, r8, r9, r10, pc} */

/* ── FUNC 0x2e4fcf · FT_Matrix_Multiply_Scaled · size=130 · insn=0 */

/* ── FUNC 0x2e5050 · anon_2e5050 · size=72 · insn=18 */
/* @0x2e5050 mvnsmi lr, sp, lsr #18 */
/* @0x2e5054 strmi r4, [r4], -sp, lsl #12 */
/* @0x2e5058 ldrsblt r11, [r1, #24] */
/* @0x2e505c stmdavs r9, {r1, r2, r4, r10} */
/* @0x2e5060 ldrtmi r6, [r2], -r0, lsl #16 */
/* @0x2e5064 mcr2 p7, #0x3, pc, c10, c15, #0x7 */
/* @0x2e5068 ldrtmi r6, [r2], -r9, ror #16 */
/* @0x2e506c stmdavs r0!, {r0, r1, r2, r9, r10, lr} ^ */
/* @0x2e5070 mcr2 p7, #0x3, pc, c4, c15, #0x7 */
/* @0x2e5074 ldrtmi r6, [r2], -r9, lsr #17 */
/* @0x2e5078 stmdavs r0!, {r0, r1, r2, r10, lr} */
/* @0x2e507c mrc2 p7, #0x2, apsr_nzcv, c14, c15, #0x7 */
/* @0x2e5080 ldrtmi r6, [r2], -r9, ror #17 */
/* @0x2e5084 stmdavs r0!, {r7, r9, r10, lr} ^ */
/* @0x2e5088 mrc2 p7, #0x2, apsr_nzcv, c8, c15, #0x7 */
/* @0x2e508c strbmi r6, [r0], #-39 */
/* @0x2e5090 pop {r5, r6, sp, lr} */
/* @0x2e5094 push {r4, r5, r6, r7, r8, pc} */

/* ── FUNC 0x2e5051 · FT_Vector_Transform_Scaled · size=70 · insn=0 */

/* ── FUNC 0x2e5096 · anon_2e5096 · size=304 · insn=76 */
/* @0x2e5096 svcmi #0xf0e92d */
/* @0x2e509a muleq r12, r0, r8 */
/* @0x2e509e svclt #0xba2a00 */
/* @0x2e50a2 .word 0xf04f4252 */
/* @0x2e50a6 .word 0xf04f38ff */
/* @0x2e50aa blhs 0x2e70b6 <FT_Vector_Polarize+0x2a> */
/* @0x2e50ae subsmi r11, r11, #744 */
/* @0x2e50b2 ldcllo p0, c15, [pc], #316 */
/* @0x2e50b6 .word 0x0c01f04f */
/* @0x2e50ba blhs 0x31356a <af_shaper_get_elem+0x8dd8> */
/* @0x2e50be b 0x16d92ba <b2_toiTime+0xf7fe16> */
/* @0x2e50c2 subvs r4, r2, r12, lsl #4 */
/* @0x2e50c6 stmdblt r11!, {r0, r3, r4, r5, r6, sp, lr, pc} */
/* @0x2e50ca movwmi lr, #0x8a4f */
/* @0x2e50ce ldrmi r6, [r0], -r3 */
/* @0x2e50d2 svchi #0xf0e8bd */
/* @0x2e50d6 .word 0xf04f429a */
/* @0x2e50da svclt #0x8c31aa */
/* @0x2e50de ldrbeq lr, [r3], #-2818 */
/* @0x2e50e2 ldrbeq lr, [r2], #-2819 */
/* @0x2e50e6 .word 0xf584fab4 */
/* @0x2e50ea addmi r4, r12, #233 */
/* @0x2e50ee .word 0x210fbf34 */
/* @0x2e50f2 bne 0x1d2d53a <b2_toiTime+0x15d4096> */
/* @0x2e50f6 stcle p9, c2, [r8, #-0] */
/* @0x2e50fa addmi r4, r11, r10, lsl #1 */
/* @0x2e50fe svclt #0x8c429a */
/* @0x2e5102 ldrbeq lr, [r3], -r2, lsl #22 */
/* @0x2e5106 ldrbeq lr, [r2], -r3, lsl #22 */
/* @0x2e510a submi lr, lr, #4 */
/* @0x2e510e ldrshtmi r4, [r3], #2 */
/* @0x2e5112 .word 0xf606fa24 */
/* @0x2e5116 strlo pc, [r0], r6, asr #11 */
/* @0x2e511a .word 0xf502fb06 */
/* @0x2e511e stmiblo r0, {r1, r2, r8, r10, r12, sp, lr, pc} */
/* @0x2e5122 .word 0xf403fb06 */
/* @0x2e5126 stmdbhs r9!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2e512a strmi lr, [r5, #-0xb02]! */
/* @0x2e512e blmi 0xc1fd42 <b2_toiTime+0x4c689e> */
/* @0x2e5132 .word 0xf705fb05 */
/* @0x2e5136 strvc pc, [r11, -r11, lsl #22] */
/* @0x2e513a svclt #0xb82f00 */
/* @0x2e513e ldrbne pc, [pc, r7, lsl #4]! */
/* @0x2e5142 bhs 0x1cdfa86 <b2_toiTime+0x15865e2> */
/* @0x2e5146 .word 0xf1ca464f */
/* @0x2e514a ldrbmi r0, [r4], -r0, lsl #20 */
/* @0x2e514e svclt #0x48437c */
/* @0x2e5152 ldrbmi pc, [pc, -r4, lsl #10]! */
/* @0x2e5156 svclt #0x4846a1 */
/* @0x2e515a ldmibeq pc!, {r0, r1, r2, r8, r12, sp, lr, pc} ^ */
/* @0x2e515e strmi lr, [r9, -pc, asr #20]! */
/* @0x2e5162 ldrtmi r2, [lr], #-3840 */
/* @0x2e5166 .word 0x436adcd8 */
/* @0x2e516a svclo #0xfff1b8 */
/* @0x2e516e movwhs pc, #0xbb03 */
/* @0x2e5172 rsbmi r11, lr, #12, #30 */
/* @0x2e5176 .word 0xf1bc462e */
/* @0x2e517a strdvs r3, r4, [r6], -pc */
/* @0x2e517e .word 0xf1cbbf0c */
/* @0x2e5182 ldrbmi r0, [lr], -r0, lsl #12 */
/* @0x2e5186 svclt #0xb82b00 */
/* @0x2e518a cmnmi pc, #12582912 */
/* @0x2e518e svclt #0xb86046 */
/* @0x2e5192 stmdbhs r0, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r12, sp} */
/* @0x2e5196 .word 0x4323ea4f */
/* @0x2e519a orrlo pc, r0, #12582912 */
/* @0x2e519e cdpne p13, #0x4, c13, c10, c8, #0x0 */
/* @0x2e51a2 blx 0x2ed1ae <FT_Done_Memory+0x353a> */
/* @0x2e51a6 ldrmi pc, [r3], #-514 */
/* @0x2e51aa .word 0xf001fa23 */
/* @0x2e51ae svchi #0xf0e8bd */
/* @0x2e51b2 blx 0x3b5ade <error_g0017+0xe782> */
/* @0x2e51b6 pop {r0, r12, sp, lr, pc} */
/* @0x2e51ba ssub8mi r8, r8, r0 */
/* @0x2e51be svchi #0xf0e8bd */
/* @0x2e51c2 ldrblt r0, [pc, #-0x0]! */

/* ── FUNC 0x2e5097 · FT_Vector_NormLen · size=300 · insn=0 */

/* ── FUNC 0x2e51c4 · anon_2e51c4 · size=372 · insn=93 */
/* @0x2e51c4 .word 0x460db57f */
/* @0x2e51c8 b 0xfe2f6a20 <b2_toiTime+0xfffffffffdb9d57c> */
/* @0x2e51cc bl 0xfeb41954 <b2_toiTime+0xfffffffffe3e84b0> */
/* @0x2e51d0 b 0xfe3c1958 <b2_toiTime+0xfffffffffdc684b4> */
/* @0x2e51d4 bl 0xfeb81d68 <b2_toiTime+0xfffffffffe4288c4> */
/* @0x2e51d8 ldrmi r7, [r1], #-739 */
/* @0x2e51dc addsmi r4, r1, #102400 */
/* @0x2e51e0 b 0xfe45b234 <b2_toiTime+0xfffffffffdd01d90> */
/* @0x2e51e4 bl 0xfec82d80 <b2_toiTime+0xfffffffffe5298dc> */
/* @0x2e51e8 b 0xfe402d84 <b2_toiTime+0xfffffffffdca98e0> */
/* @0x2e51ec bl 0xfeb41984 <b2_toiTime+0xfffffffffe3e84e0> */
/* @0x2e51f0 ldrtmi r7, [r1], #-484 */
/* @0x2e51f4 stmdale r8, {r0, r4, r7, r9, lr} */
/* @0x2e51f8 .word 0x436c4358 */
/* @0x2e51fc .word 0xdc1e42a0 */
/* @0x2e5200 andhs r11, r0, r12, lsr #31 */
/* @0x2e5204 andeq pc, r0, pc, rrx */
/* @0x2e5208 sadd16mi lr, r9, r10 */
/* @0x2e520c .word 0xf7ff466a */
/* @0x2e5210 bge 0x3a400c <af_blue_strings+0x1ce8> */
/* @0x2e5214 strtmi r4, [r1], -r8, lsr #12 */
/* @0x2e5218 blx 0x212321e <b2_toiTime+0x19c9d7a> */
/* @0x2e521c bls 0x34be30 */
/* @0x2e5220 stmdale r12, {r1, r3, r4, r7, r9, lr} */
/* @0x2e5224 blls 0x399e4c <ft_adobe_glyph_list+0x9528> */
/* @0x2e5228 addsmi r9, r10, #0, #20 */
/* @0x2e522c svclt #0x2cd807 */
/* @0x2e5230 .word 0xf06f2000 */
/* @0x2e5234 and r0, r3, r0 */
/* @0x2e5238 rscslo pc, pc, pc, asr #32 */
/* @0x2e523c andhs lr, r1, r0 */
/* @0x2e5240 ldcllt p0, c11, [r0, #-16]! */
/* @0x2e5244 .word 0x0001ffff */
/* @0x2e5248 stmne r6, {r4, r5, r6, r8, r10, r12, sp, pc} */
/* @0x2e524c stmdahs r0, {r0, r2, r3, r6, r7, r11, r12} */
/* @0x2e5250 submi r11, r0, #184, #30 */
/* @0x2e5254 svclt #0xb82900 */
/* @0x2e5258 strhs r4, [r3], #-585 */
/* @0x2e525c svclt #0xcc4288 */
/* @0x2e5260 .word 0x43604361 */
/* @0x2e5264 streq pc, [r3], #-79 */
/* @0x2e5268 bl 0x3151a0 <FT_Bitmap_Embolden+0x35a> */
/* @0x2e526c bl 0x3259f8 */
/* @0x2e5270 bhs 0x2e59f8 <FT_Face_Properties> */
/* @0x2e5274 subsmi r11, r2, #184, #30 */
/* @0x2e5278 svclt #0xb82b00 */
/* @0x2e527c andhs r4, r3, r11, asr r2 */
/* @0x2e5280 svclt #0xcb429a */
/* @0x2e5284 movtmi r4, #0x2343 */
/* @0x2e5288 .word 0x03e3eb02 */
/* @0x2e528c .word 0x03e2eb03 */
/* @0x2e5290 svclt #0xb82e00 */
/* @0x2e5294 stchs p2, c4, [r0, #-472] */
/* @0x2e5298 rsbmi r11, sp, #184, #30 */
/* @0x2e529c adcmi r4, lr, #184549376 */
/* @0x2e52a0 .word 0x436cbfcb */
/* @0x2e52a4 bl 0x47607c <g_RomDisk+0x7e85c> */
/* @0x2e52a8 bl 0x426640 <g_RomDisk+0x2ee20> */
/* @0x2e52ac blne 0x9a6644 <b2_toiTime+0x24d1a0> */
/* @0x2e52b0 svcne #0x24ebb3 */
/* @0x2e52b4 andhs r11, r0, r12, lsr #31 */
/* @0x2e52b8 ldcllt p0, c2, [r0, #-4]! */
/* @0x2e52bc .word 0xf100b530 */
/* @0x2e52c0 movwhs r0, #0x514 */
/* @0x2e52c4 ldrteq pc, [r8], #-256 */
/* @0x2e52c8 addhi r8, r3, #805306380 */
/* @0x2e52cc stcgt p3, c6, [pc, #-12] */
/* @0x2e52d0 stcgt p4, c12, [pc, #-60] */
/* @0x2e52d4 stmdavs r11!, {r0, r1, r2, r3, r10, lr, pc} */
/* @0x2e52d8 ldclt p0, c6, [r0, #-140]! */
/* @0x2e52dc strbhi r2, [r3, -r0, lsl #6] */
/* @0x2e52e0 .word 0x4604b510 */
/* @0x2e52e4 strbvs r8, [r3, #-0x703] */
/* @0x2e52e8 blx 0xe232ee <b2_toiTime+0x6c9e4a> */
/* @0x2e52ec blvs 0x1bbff7c <b2_toiTime+0x1466ad8> */
/* @0x2e52f0 movtne lr, #0x2b03 */
/* @0x2e52f4 ldclt p5, c6, [r0, #-652] */
/* @0x2e52f8 bicslt r11, r8, r0, lsr r5 */
/* @0x2e52fc svchi #0x418ac2 */
/* @0x2e5300 ldrmi r8, [r1], #-3843 */
/* @0x2e5304 bhi 0xfe345e10 <b2_toiTime+0xfffffffffdbec96c> */
/* @0x2e5308 strmi r11, [r11], #-540 */
/* @0x2e530c addhi r6, r3, #1024 */
/* @0x2e5310 strmi r6, [r11], #-3395 */
/* @0x2e5314 movwhs r6, #0x303 */
/* @0x2e5318 ble 0x4b5dac <SrcVerts+0x12df0> */
/* @0x2e531c rfeda r1! */
/* @0x2e5320 ldrmi r5, [r5], #-19 */
/* @0x2e5324 andspl pc, r3, r1, lsr #16 */
/* @0x2e5328 ldrb r3, [r5, r1, lsl #6]! */
/* @0x2e532c ldrhtmi lr, [r0], -sp */
/* @0x2e5330 svclt #0xd4f7ff */
/* @0x2e5334 strlt r11, [r8, #-0xd30] */

/* ── FUNC 0x2e51c5 · ft_corner_orientation · size=132 · insn=0 */

/* ── FUNC 0x2e5249 · ft_corner_is_flat · size=116 · insn=0 */

/* ── FUNC 0x2e52bd · FT_GlyphLoader_Rewind · size=32 · insn=0 */

/* ── FUNC 0x2e52dd · FT_GlyphLoader_Prepare · size=28 · insn=0 */

/* ── FUNC 0x2e52f9 · FT_GlyphLoader_Add · size=62 · insn=0 */

/* ── FUNC 0x2e5336 · anon_2e5336 · size=16 · insn=4 */
/* @0x2e5336 .word 0xf7ffb508 */
/* @0x2e533a stmdavs r0, {r1, r2, r3, r4, r5, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2e533e andlo r11, r4, r0, lsl #2 */
/* @0x2e5342 strlt r11, [r8, #-0xd08] */

/* ── FUNC 0x2e5337 · ft_hash_str_lookup · size=14 · insn=0 */

/* ── FUNC 0x2e5344 · anon_2e5344 · size=16 · insn=4 */
/* @0x2e5344 .word 0xf7ffb508 */
/* @0x2e5348 stmdavs r0, {r0, r1, r2, r4, r5, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2e534c andlo r11, r4, r0, lsl #2 */
/* @0x2e5350 ldrlt r11, [r8, #-0xd08]! */

/* ── FUNC 0x2e5345 · ft_hash_num_lookup · size=14 · insn=0 */

/* ── FUNC 0x2e5352 · anon_2e5352 · size=40 · insn=10 */
/* @0x2e5352 .word 0x460db538 */
/* @0x2e5356 cmplt r8, r4, lsl #12 */
/* @0x2e535a stmdavs r0!, {r0, r3, r4, r6, r8, r12, sp, pc} */
/* @0x2e535e qasxmi r11, r9, r8 */
/* @0x2e5362 stmdb r8, {r0, r4, r6, r7, r8, r10, r12, sp, lr, pc} */
/* @0x2e5366 stmdavs r0!, {r3, r8, r11, r12, sp, pc} ^ */
/* @0x2e536a strlo r11, [r8], #-3384 */
/* @0x2e536e ldclt p7, c14, [r8, #-980]! */
/* @0x2e5372 .word 0x4608bd38 */
/* @0x2e5376 .word 0xf8c0bd38 */

/* ── FUNC 0x2e5353 · ft_service_list_lookup · size=38 · insn=0 */

/* ── FUNC 0x2e5378 · anon_2e5378 · size=28 · insn=7 */
/* @0x2e5378 smlabtne r0, r0, r8, pc */
/* @0x2e537c smlabths r4, r0, r8, pc */
/* @0x2e5380 smlabtlo r8, r0, r8, pc */
/* @0x2e5384 .word 0xf8c02300 */
/* @0x2e5388 ldrbmi r3, [r0, -r12, lsl #2]! */
/* @0x2e538c rscslo pc, pc, pc, asr #32 */
/* @0x2e5390 .word 0xf8c04770 */

/* ── FUNC 0x2e5379 · ft_validator_init · size=20 · insn=0 */

/* ── FUNC 0x2e538d · ft_validator_run · size=6 · insn=0 */

/* ── FUNC 0x2e5392 · anon_2e5392 · size=128 · insn=32 */
/* @0x2e5392 smlabtne r12, r0, r8, pc */
/* @0x2e5396 strlt r2, [r8, #-0x101] */
/* @0x2e539a ldcl p5, c15, [r0, #836]! */
/* @0x2e539e .word 0x460db570 */
/* @0x2e53a2 stmdahs r0, {r1, r2, r4, r9, r10, lr} */
/* @0x2e53a6 .word 0xf8d0d032 */
/* @0x2e53aa movwhs r4, #0x80 */
/* @0x2e53ae ldmdblt r9!, {r0, r1, r5, r7, r8, sp, lr} */
/* @0x2e53b2 orrlo pc, r0, #1325400064 */
/* @0x2e53b6 stm r4, {r0, r5, r7, sp, lr} */
/* @0x2e53ba strtmi r0, [r5], -r8, lsr #32 */
/* @0x2e53be and r6, r2, r3, ror #1 */
/* @0x2e53c2 stm r4, {r0, r1, r2, r3, r8, r11, lr, pc} */
/* @0x2e53c6 stmvs r10!, {r0, r1, r2, r3} */
/* @0x2e53ca tstmi r3, #7012352 */
/* @0x2e53ce stmdavs r11!, {r0, r1, r2, r8, r12, lr, pc} */
/* @0x2e53d2 svclo #0x80f5b3 */
/* @0x2e53d6 stmvs r11!, {r0, r1, r8, r12, lr, pc} ^ */
/* @0x2e53da svclo #0x80f5b3 */
/* @0x2e53de stmibvs r3!, {r0, r1, r12, lr, pc} */
/* @0x2e53e2 movweq pc, #0x1043 */
/* @0x2e53e6 .word 0xf10461a3 */
/* @0x2e53ea ldmdblt lr, {r4, r8, r9} */
/* @0x2e53ee .word 0x61666126 */
/* @0x2e53f2 and r4, r3, lr, lsl r6 */
/* @0x2e53f6 muleq r3, r6, r8 */
/* @0x2e53fa andeq lr, r3, r3, lsl #17 */
/* @0x2e53fe ldmdavs r3!, {r1, r4, r5, r6, r11, sp, lr} */
/* @0x2e5402 andle r4, r3, r3, lsl r3 */
/* @0x2e5406 .word 0xf04369a3 */
/* @0x2e540a .word 0x61a30302 */
/* @0x2e540e teqlt r0, r0, ror sp */

/* ── FUNC 0x2e5393 · ft_validator_error · size=12 · insn=0 */

/* ── FUNC 0x2e539f · FT_Set_Transform · size=114 · insn=0 */

/* ── FUNC 0x2e5410 · anon_2e5410 · size=748 · insn=187 */
/* @0x2e5410 .word 0xf8d0b130 */
/* @0x2e5414 andhs r3, r0, r0, lsl #1 */
/* @0x2e5418 andlo r6, r1, #6656 */
/* @0x2e541c .word 0x4770641a */
/* @0x2e5420 ldrbmi r2, [r0, -r3, lsr #32]! */
/* @0x2e5424 .word 0x43f8e92d */
/* @0x2e5428 stmvs r3, {r0, r1, r2, r3, r4, r9, r10, lr} */
/* @0x2e542c strmi r4, [r12], -r6, lsl #12 */
/* @0x2e5430 .word 0x079b4690 */
/* @0x2e5434 stmdavs r11, {r0, r1, r3, r6, r8, r10, r12, lr, pc} */
/* @0x2e5438 .word 0xd14b2b00 */
/* @0x2e543c .word 0xf8d168c8 */
/* @0x2e5440 teqlt r8, r4 */
/* @0x2e5444 .word 0xf000fb09 */
/* @0x2e5448 eorlo r2, r4, r8, asr #2 */
/* @0x2e544c stcl p0, c15, [r0], #-204 */
/* @0x2e5450 and r4, r0, r5, lsl #12 */
/* @0x2e5454 stmdbvs r0!, {r0, r2, r3, r6, r9, r10, lr} */
/* @0x2e5458 smulwblt r8, r4, r8 */
/* @0x2e545c .word 0x21484360 */
/* @0x2e5460 .word 0xf0333024 */
/* @0x2e5464 and lr, r0, r6, asr r12 */
/* @0x2e5468 .word 0xf1b94620 */
/* @0x2e546c andle r0, r3, r0, lsl #30 */
/* @0x2e5470 svclt #0x82c00 */
/* @0x2e5474 and r4, r2, r8, lsr #12 */
/* @0x2e5478 svclt #0x182c00 */
/* @0x2e547c strlo r4, [r0, #-0x605]! */
/* @0x2e5480 ldreq pc, [pc, #-0x35]! */
/* @0x2e5484 .word 0xf100d029 */
/* @0x2e5488 .word 0xf0310120 */
/* @0x2e548c eorle r0, r4, pc, lsr r4 */
/* @0x2e5490 strdhs r6, r7, [r0, -r0] */
/* @0x2e5494 ble 0xaf5ea0 <b2_toiTime+0x39c9fc> */
/* @0x2e5498 bl 0x3bfd6c <error_g0017+0x18a10> */
/* @0x2e549c ldmvs r10, {r0, r8, r9, r12} ^ */
/* @0x2e54a0 .word 0xf0223220 */
/* @0x2e54a4 addsmi r0, r4, #-268435453 */
/* @0x2e54a8 ldmvs r11, {r0, r1, r2, r3, r8, r12, lr, pc} */
/* @0x2e54ac .word 0xf0233320 */
/* @0x2e54b0 addsmi r0, sp, #-67108864 */
/* @0x2e54b4 .word 0xb12fd102 */
/* @0x2e54b8 and r6, r3, r9, lsr r0 */
/* @0x2e54bc svceq #0xf1b8 */
/* @0x2e54c0 ldrb sp, [r8, r3]! */
/* @0x2e54c4 ldm sp!, {sp} */
/* @0x2e54c8 strdlo r8, r9, [r1, -r8] */
/* @0x2e54cc eorhs lr, r3, r2, ror #15 */
/* @0x2e54d0 .word 0x83f8e8bd */
/* @0x2e54d4 pop {r0, r1, r2, sp} */
/* @0x2e54d8 ldrshhs r8, [r7], -r8 */
/* @0x2e54dc .word 0x83f8e8bd */
/* @0x2e54e0 .word 0x4604b538 */
/* @0x2e54e4 stmdavs r5, {r0, r1, r6, r7, r11, sp, lr} ^ */
/* @0x2e54e8 ble 0x3b00f0 <error_g0017+0x8d94> */
/* @0x2e54ec svclt #0xb8429d */
/* @0x2e54f0 and r4, r2, sp, lsl r6 */
/* @0x2e54f4 bl 0xff3d515c <b2_toiTime+0xfffffffffec7bcb8> */
/* @0x2e54f8 stmdblt r9!, {r0, r2, r8, r10} */
/* @0x2e54fc .word 0x210a200c */
/* @0x2e5500 .word 0xf0334368 */
/* @0x2e5504 strmi lr, [r1], -r6, lsl #24 */
/* @0x2e5508 blne 0x163f99c <b2_toiTime+0xee64f8> */
/* @0x2e550c bl 0x43f79c <g_RomDisk+0x47f7c> */
/* @0x2e5510 ldrdvs r7, r8, [r1, #85]! */
/* @0x2e5514 bicsvc lr, r3, #3072 */
/* @0x2e5518 .word 0x61a5106d */
/* @0x2e551c rsbeq lr, r3, #165888 */
/* @0x2e5520 ldclt p1, c6, [r8, #-392]! */
/* @0x2e5524 .word 0x0109b570 */
/* @0x2e5528 strmi r6, [r6], -r2, lsl #20 */
/* @0x2e552c ldmdane r5, {r2, r7, r8, r10, r11, sp, lr} ^ */
/* @0x2e5530 .word 0x332068ab */
/* @0x2e5534 .word 0x81a3119b */
/* @0x2e5538 .word 0x332068eb */
/* @0x2e553c .word 0x81e3119b */
/* @0x2e5540 .word 0xf0136883 */
/* @0x2e5544 andsle r0, r2, r1, lsl #6 */
/* @0x2e5548 strhne pc, [r4], #-134 */
/* @0x2e554c .word 0xf7ff68a8 */
/* @0x2e5550 strhvs pc, [r0, -r2]! */
/* @0x2e5554 strhne pc, [r4], #-134 */
/* @0x2e5558 .word 0xf7ff68e8 */
/* @0x2e555c .word 0xf104fcac */
/* @0x2e5560 .word 0x6160010c */
/* @0x2e5564 pop {r4, r5, r9, r10, lr} */
/* @0x2e5568 .word 0xf7ff4070 */
/* @0x2e556c .word 0xf44fbc7d */
/* @0x2e5570 smlawbvs r0, r0, r0, r3 */
/* @0x2e5574 stmvs r8!, {r5, r6, r8, sp, lr} ^ */
/* @0x2e5578 rorvs r6, r3, #3 */
/* @0x2e557c orrseq r5, r11, r3, asr lr */
/* @0x2e5580 stmvs r11!, {r0, r1, r5, r9, sp, lr} */
/* @0x2e5584 ldcllt p2, c6, [r0, #-396]! */
/* @0x2e5588 svcmi #0xf7e92d */
/* @0x2e558c stmvs r1, {r0, r1, r2, r3, r9, r10, lr} */
/* @0x2e5590 stcvs p6, c4, [r4, #20] */
/* @0x2e5594 .word 0x0101f011 */
/* @0x2e5598 bleq 0x6219b0 <g_SWFaavertbuff+0x4e8e8> */
/* @0x2e559c addshi pc, lr, r0 */
/* @0x2e55a0 muleq r12, r7, r8 */
/* @0x2e55a4 vpmax.s8 d2, d0, d4 */
/* @0x2e55a8 ldm pc, {r2, r5, r7, pc} ^ */
/* @0x2e55ac streq pc, [r3], -r2 */
/* @0x2e55b0 eoreq r1, r0, lr, lsl #14 */
/* @0x2e55b4 strhls pc, [r4], #-133 */
/* @0x2e55b8 rfeib r5! */
/* @0x2e55bc rfeib r5! */
/* @0x2e55c0 bl 0xff36d6e8 <b2_toiTime+0xfffffffffec14244> */
/* @0x2e55c4 strbmi r0, [r10], r9, lsl #18 */
/* @0x2e55c8 blvs 0xffd5d640 <b2_toiTime+0xffffffffff60419c> */
/* @0x2e55cc bl 0xff38037c <b2_toiTime+0xfffffffffec26ed8> */
/* @0x2e55d0 stcvs p9, c0, [r9], #-4 */
/* @0x2e55d4 bl 0xff380484 <b2_toiTime+0xfffffffffec26fe0> */
/* @0x2e55d8 ands r0, r3, r1, lsl #20 */
/* @0x2e55dc strhge pc, [r6], #-149 */
/* @0x2e55e0 strhhs pc, [r8], #-149 */
/* @0x2e55e4 strhls pc, [r12], #-149 */
/* @0x2e55e8 beq 0x5a04f8 <g_SWFlineaavertbuff+0x4d430> */
/* @0x2e55ec .word 0x6123e00a */
/* @0x2e55f0 strhvs r6, [r6, #-142]! */
/* @0x2e55f4 .word 0x6126b913 */
/* @0x2e55f8 subs r4, r0, lr, lsl r6 */
/* @0x2e55fc .word 0xd14d2e00 */
/* @0x2e5600 sub r6, r12, r3, ror #2 */
/* @0x2e5604 svceq #0xf1b9 */
/* @0x2e5608 .word 0xf1c9bfb8 */
/* @0x2e560c ldmvs r8!, {r8, r11} ^ */
/* @0x2e5610 svceq #0xf1ba */
/* @0x2e5614 .word 0xf1cabfb8 */
/* @0x2e5618 .word 0xb1400a00 */
/* @0x2e561c qdaddhs r4, r8, r8 */
/* @0x2e5620 eorlo r9, r4, r1, lsl #6 */
/* @0x2e5624 bl 0x20216f8 <b2_toiTime+0x18c8254> */
/* @0x2e5628 strmi r9, [r0], r1, lsl #22 */
/* @0x2e562c ldrmi lr, [r8], r0 */
/* @0x2e5630 ldmvs lr!, {r3, r4, r5, r8, r11, sp, lr} */
/* @0x2e5634 cmnmi r0, #56, #2 */
/* @0x2e5638 movwls r2, #0x1148 */
/* @0x2e563c .word 0xf0333024 */
/* @0x2e5640 blls 0x3603e8 <_ZTS12CDS_Priority+0x2440> */
/* @0x2e5644 mvnlt r4, r6, lsl #12 */
/* @0x2e5648 strbmi r4, [r9], -r0, asr #12 */
/* @0x2e564c ldc2 p7, c15, [r3], #-1020 */
/* @0x2e5650 ldmvs r11!, {r5, r8, sp, lr} */
/* @0x2e5654 ldrtmi r11, [r0], -r11, ror #2 */
/* @0x2e5658 .word 0xf7ff4651 */
/* @0x2e565c .word 0x6160fc2c */
/* @0x2e5660 blhs 0x3bf754 <error_g0017+0x183f8> */
/* @0x2e5664 stmdbvs r3!, {r2, r3, r4, r8, r12, lr, pc} */
/* @0x2e5668 svclt #0xd44298 */
/* @0x2e566c .word 0x61636120 */
/* @0x2e5670 .word 0x6160e016 */
/* @0x2e5674 .word 0x46404651 */
/* @0x2e5678 .word 0xf7ff464a */
/* @0x2e567c .word 0x4606fb5f */
/* @0x2e5680 ldrbmi lr, [r1], -lr */
/* @0x2e5684 .word 0xf7ff4630 */
/* @0x2e5688 .word 0x4649fc16 */
/* @0x2e568c qdsubvs r4, r2, r0 */
/* @0x2e5690 ldrtmi r6, [r0], -r0, lsr #2 */
/* @0x2e5694 blx 0x17a369a <b2_toiTime+0x104a1f6> */
/* @0x2e5698 and r4, r1, r0, lsl #13 */
/* @0x2e569c ldrtmi r2, [r0], r0, lsl #12 */
/* @0x2e56a0 cmplt r11, r11, lsr r8 */
/* @0x2e56a4 rfeia r5! */
/* @0x2e56a8 .word 0xf7ff0044 */
/* @0x2e56ac stmdbvs r1!, {r0, r1, r2, r3, r6, r7, r8, r9, r11, r12, sp, lr, pc} ^ */
/* @0x2e56b0 rfeia r5! */
/* @0x2e56b4 .word 0xf7ff0044 */
/* @0x2e56b8 strmi pc, [r6], -r9, asr #23 */
/* @0x2e56bc stmdaeq r0!, {r3, r8, r12, sp, lr, pc} */
/* @0x2e56c0 strtmi r3, [r8], -r0, lsr #12 */
/* @0x2e56c4 b 0x16b7030 <b2_toiTime+0xf5db8c> */
/* @0x2e56c8 .word 0x11b618a8 */
/* @0x2e56cc andhi pc, r12, r4, lsr #17 */
/* @0x2e56d0 andlt r8, r3, r6, ror #3 */
/* @0x2e56d4 svcmi #0xf0e8bd */
/* @0x2e56d8 bllt 0xff4a36dc <b2_toiTime+0xfffffffffed4a238> */
/* @0x2e56dc andshs r4, r12, #88, #12 */
/* @0x2e56e0 svc #0x66f5d0 */
/* @0x2e56e4 orrlo pc, r0, #1325400064 */
/* @0x2e56e8 .word 0x61636123 */
/* @0x2e56ec pop {r0, r1, r12, sp, pc} */
/* @0x2e56f0 .word 0xf04f8ff0 */
/* @0x2e56f4 strbmi r0, [r10], r0, lsl #18 */
/* @0x2e56f8 ldrlt lr, [r0, #-0x789] */

/* ── FUNC 0x2e5411 · FT_Reference_Face · size=20 · insn=0 */

/* ── FUNC 0x2e5425 · FT_Match_Size · size=188 · insn=0 */

/* ── FUNC 0x2e54e1 · ft_synthesize_vertical_metrics · size=68 · insn=0 */
