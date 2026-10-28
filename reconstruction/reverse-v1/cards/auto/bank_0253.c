/* libyoyo.so 覆盖卡组 0253
 * 函数 0x2a603c..0x2a66c1，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2a603c · anon_2a603c · size=1300 · insn=325 */
/* @0x2a603c .word 0x0c04b570 */
/* @0x2a6040 addlt r0, r0, #3328 */
/* @0x2a6044 blx 0x312a72 <af_shaper_get_elem+0x82e0> */
/* @0x2a6048 msrmi SPSR_f, #0, #12 */
/* @0x2a604c andeq pc, r4, r1, lsl #22 */
/* @0x2a6050 bl 0x2b6e08 <jinit_master_decompress+0x730> */
/* @0x2a6054 adcslt r4, r6, #22 */
/* @0x2a6058 ldrmi lr, [r0], #-2820 */
/* @0x2a605c strmi lr, [r0], -r6, asr #20 */
/* @0x2a6060 andsvs r6, lr, r4, lsl r0 */
/* @0x2a6064 andeq r11, r0, r0, ror sp */
/* @0x2a6068 svcmi #0xf0e92d */
/* @0x2a606c strmi r11, [r8], r5, lsl #1 */
/* @0x2a6070 sadd8mi r4, lr, r1 */
/* @0x2a6074 .word 0xf8dd9f0e */
/* @0x2a6078 .word 0x4604b03c */
/* @0x2a607c .word 0xa048f8dd */
/* @0x2a6080 .word 0xf0002800 */
/* @0x2a6084 stmdbhs r0, {r0, r7, pc} */
/* @0x2a6088 bhs 0x2dccd4 <_Z25b2CollidePolygonAndCircleP10b2ManifoldPK14b2PolygonShapeRK11b2TransformPK13b2CircleShapeS6_+0x204> */
/* @0x2a608c blhs 0x2dd4d0 <_ZN12b2EPCollider7CollideEP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS7_+0x170> */
/* @0x2a6090 svchs #0xdb0d */
/* @0x2a6094 .word 0xf1bbdb0b */
/* @0x2a6098 blle 0x4a9ca0 <SrcVerts+0x6ce4> */
/* @0x2a609c bhs 0x2cc8e4 <_ZN15b2DistanceJoint24SolveVelocityConstraintsERK12b2SolverData+0x8> */
/* @0x2a60a0 blls 0x71ccbc <g_SWFvertbuff+0x49bf4> */
/* @0x2a60a4 blle 0x330cac */
/* @0x2a60a8 svceq #0xf1ba */
/* @0x2a60ac ldmdbmi r9!, {r1, r2, r9, r11, r12, lr, pc} */
/* @0x2a60b0 strhs r4, [r0, #-0x620] */
/* @0x2a60b4 .word 0xf0004479 */
/* @0x2a60b8 .word 0xe000f9dd */
/* @0x2a60bc .word 0xf06f2501 */
/* @0x2a60c0 ldrmi r4, [r8, #0x300] */
/* @0x2a60c4 ldrmi sp, [r9, #0xf] */
/* @0x2a60c8 addsmi sp, lr, #13 */
/* @0x2a60cc addsmi sp, pc, #11 */
/* @0x2a60d0 ldrmi sp, [r11, #0x9] */
/* @0x2a60d4 bls 0x6da0f8 <g_SWFvertbuff+0x7030> */
/* @0x2a60d8 mulle r4, r10, r2 */
/* @0x2a60dc addsmi r9, r10, #69632 */
/* @0x2a60e0 ldrmi sp, [r10, #0x1] */
/* @0x2a60e4 stmdbmi r12!, {r0, r2, r8, r12, lr, pc} */
/* @0x2a60e8 strhs r4, [r0, #-0x620] */
/* @0x2a60ec .word 0xf0004479 */
/* @0x2a60f0 .word 0xf5c9f9c1 */
/* @0x2a60f4 adclo r3, r0, #805306380 */
/* @0x2a60f8 ble 0x3f7608 <global_builtin_vars+0x164> */
/* @0x2a60fc strtmi r4, [r0], -r7, lsr #18 */
/* @0x2a6100 ldrbtmi r2, [r9], #-1280 */
/* @0x2a6104 rfeib r6! */
/* @0x2a6108 biclo pc, r3, #834666496 */
/* @0x2a610c adcsmi r3, r3, #160, #6 */
/* @0x2a6110 stmdbmi r3!, {r0, r2, r9, r11, r12, lr, pc} */
/* @0x2a6114 strhs r4, [r0, #-0x620] */
/* @0x2a6118 .word 0xf0004479 */
/* @0x2a611c bls 0x6e47d0 <g_SWFvertbuff+0x11708> */
/* @0x2a6120 biclo pc, r3, #813694976 */
/* @0x2a6124 ldrbmi r3, [r11, #-0x3a0] */
/* @0x2a6128 ldmdbmi lr, {r0, r2, r9, r11, r12, lr, pc} */
/* @0x2a612c strhs r4, [r0, #-0x620] */
/* @0x2a6130 .word 0xf0004479 */
/* @0x2a6134 .word 0xf5caf99f */
/* @0x2a6138 bls 0x6f304c <g_SWFvertbuff+0x1ff84> */
/* @0x2a613c addsmi r3, r3, #160, #6 */
/* @0x2a6140 ldmdbmi r9, {r0, r2, r9, r11, r12, lr, pc} */
/* @0x2a6144 strhs r4, [r0, #-0x620] */
/* @0x2a6148 .word 0xf0004479 */
/* @0x2a614c bl 0xff4647a0 <b2_toiTime+0xfffffffffed0b2fc> */
/* @0x2a6150 bl 0xff466184 <b2_toiTime+0xfffffffffed0cce0> */
/* @0x2a6154 strbtmi r0, [r10], -r10, lsl #2 */
/* @0x2a6158 .word 0xf7ffab01 */
/* @0x2a615c blls 0x6e5f20 <g_SWFvertbuff+0x12e58> */
/* @0x2a6160 blne 0xff8cc9ac <b2_toiTime+0xffffffffff173508> */
/* @0x2a6164 blne 0xfe710d78 <b2_toiTime+0xfffffffffdfb78d4> */
/* @0x2a6168 .word 0xf7ffaa02 */
/* @0x2a616c blls 0x365f10 <_ZTS12CDS_Priority+0x7f68> */
/* @0x2a6170 addsmi r9, r10, #0, #20 */
/* @0x2a6174 blls 0x39a5a4 <ft_adobe_glyph_list+0x9c80> */
/* @0x2a6178 addsmi r9, r10, #4096 */
/* @0x2a617c stmdbmi r11, {r1, r2, r8, r12, lr, pc} */
/* @0x2a6180 ldrbtmi r4, [r9], #-1568 */
/* @0x2a6184 .word 0xf976f000 */
/* @0x2a6188 and r2, r0, r0 */
/* @0x2a618c andlt r4, r5, r8, lsr #12 */
/* @0x2a6190 svchi #0xf0e8bd */
/* @0x2a6194 strdeq r6, r7, [lr], -r0 */
/* @0x2a6198 andeq r6, lr, r12, ror #5 */
/* @0x2a619c andeq r6, lr, r4, lsl r3 */
/* @0x2a61a0 andeq r6, lr, r7, lsl r3 */
/* @0x2a61a4 andeq r6, lr, r6, lsl r3 */
/* @0x2a61a8 andeq r6, lr, r7, lsl r3 */
/* @0x2a61ac strdeq r6, r7, [lr], -r5 */
/* @0x2a61b0 svcmi #0xf7e92d */
/* @0x2a61b4 blls 0x637a30 <g_SWFaavertbuff+0x64968> */
/* @0x2a61b8 stmdaeq r0, {r0, r4, r5, r7, r8, r12, sp, lr, pc} */
/* @0x2a61bc ldrmi r4, [r7], -r4, lsl #12 */
/* @0x2a61c0 .word 0xf8dd9e0c */
/* @0x2a61c4 movwls r11, #0x1034 */
/* @0x2a61c8 ldrsbtls pc, [r12], -sp */
/* @0x2a61cc stmdbmi r2!, {r1, r8, r12, lr, pc} ^ */
/* @0x2a61d0 and r4, r4, r9, ror r4 */
/* @0x2a61d4 beq 0x2e2318 <_ZN15b2ContactSolverC2EP18b2ContactSolverDef+0x288> */
/* @0x2a61d8 stmdbmi r0!, {r0, r2, r9, r11, r12, lr, pc} ^ */
/* @0x2a61dc .word 0xf0004479 */
/* @0x2a61e0 .word 0xf04ff949 */
/* @0x2a61e4 .word 0xf1080a01 */
/* @0x2a61e8 bmi 0x18e660c <b2_toiTime+0x118d168> */
/* @0x2a61ec .word 0x0107f021 */
/* @0x2a61f0 stmdble r6, {r0, r4, r7, r9, lr} */
/* @0x2a61f4 qsaxmi r4, r0, r10 */
/* @0x2a61f8 beq 0x32233c */
/* @0x2a61fc .word 0xf0004479 */
/* @0x2a6200 .word 0xf8d4f939 */
/* @0x2a6204 ldrmi r2, [r0, #0x308] */
/* @0x2a6208 bmi 0x175c218 <b2_toiTime+0x1002d74> */
/* @0x2a620c stmdble r6, {r4, r7, r8, r10, lr} */
/* @0x2a6210 qsaxmi r4, r0, r4 */
/* @0x2a6214 beq 0x322358 */
/* @0x2a6218 .word 0xf0004479 */
/* @0x2a621c svchs #0xf92b */
/* @0x2a6220 ldmdbmi r1, {r0, r1, r8, r12, lr, pc} ^ */
/* @0x2a6224 ldrbtmi r4, [r9], #-1568 */
/* @0x2a6228 ble 0x45e23c <g_RomDisk+0x66a1c> */
/* @0x2a622c strtmi r4, [r0], -pc, asr #18 */
/* @0x2a6230 .word 0xf0004479 */
/* @0x2a6234 .word 0xf04ff91f */
/* @0x2a6238 .word 0xf8d40a01 */
/* @0x2a623c addsmi r2, r7, #12, #6 */
/* @0x2a6240 bmi 0x13dc250 <b2_toiTime+0xc82dac> */
/* @0x2a6244 stmdble r6, {r0, r1, r2, r4, r7, r9, lr} */
/* @0x2a6248 strtmi r4, [r0], -r9, asr #18 */
/* @0x2a624c beq 0x322390 */
/* @0x2a6250 .word 0xf0004479 */
/* @0x2a6254 cdpne p9, #0x6, c15, c10, c15, #0x0 */
/* @0x2a6258 stmdble r12, {r0, r9, r11, sp} */
/* @0x2a625c andle r2, r10, r4, lsl #26 */
/* @0x2a6260 andle r2, r8, r8, lsl #26 */
/* @0x2a6264 andle r2, r6, r0, lsl sp */
/* @0x2a6268 strtmi r4, [r0], -r2, asr #18 */
/* @0x2a626c beq 0x3223b0 */
/* @0x2a6270 .word 0xf0004479 */
/* @0x2a6274 .word 0xf026f8ff */
/* @0x2a6278 svchs #0x10704 */
/* @0x2a627c cdphs p0, #0x0, c13, c6, c1, #0x0 */
/* @0x2a6280 ldmdbmi sp!, {r1, r2, r8, r11, r12, lr, pc} */
/* @0x2a6284 .word 0xf04f4620 */
/* @0x2a6288 ldrbtmi r0, [r9], #-2561 */
/* @0x2a628c .word 0xf8f2f000 */
/* @0x2a6290 .word 0xd1022e03 */
/* @0x2a6294 .word 0xdc062d08 */
/* @0x2a6298 svchs #0x2e00c */
/* @0x2a629c cdphs p0, #0x0, c13, c4, c1, #0x0 */
/* @0x2a62a0 stchs p1, c13, [r7, #-32] */
/* @0x2a62a4 ldmdbmi r5!, {r1, r2, r10, r11, r12, lr, pc} */
/* @0x2a62a8 .word 0xf04f4620 */
/* @0x2a62ac ldrbtmi r0, [r9], #-2561 */
/* @0x2a62b0 .word 0xf8e0f000 */
/* @0x2a62b4 svceq #0x1f1bb */
/* @0x2a62b8 ldmdbmi r1!, {r1, r2, r8, r10, r11, r12, lr, pc} */
/* @0x2a62bc .word 0xf04f4620 */
/* @0x2a62c0 ldrbtmi r0, [r9], #-2561 */
/* @0x2a62c4 .word 0xf8d6f000 */
/* @0x2a62c8 teqlt r3, r1, lsl #22 */
/* @0x2a62cc strtmi r4, [r0], -sp, lsr #18 */
/* @0x2a62d0 beq 0x322414 */
/* @0x2a62d4 .word 0xf0004479 */
/* @0x2a62d8 .word 0xf8d4f8cd */
/* @0x2a62dc ldrbeq r2, [r0], #300 */
/* @0x2a62e0 .word 0xf8d4d507 */
/* @0x2a62e4 ldrdlt r2, r3, [r2, -r12]! */
/* @0x2a62e8 strtmi r4, [r0], -r7, lsr #18 */
/* @0x2a62ec .word 0xf0004479 */
/* @0x2a62f0 .word 0xf1b9f8c1 */
/* @0x2a62f4 andsle r0, sp, r0, lsl #30 */
/* @0x2a62f8 sbcshs pc, r12, #212, #16 */
/* @0x2a62fc strle r0, [r8, #-0x751] */
/* @0x2a6300 svceq #0x40f1b9 */
/* @0x2a6304 .word 0xf8d4d105 */
/* @0x2a6308 ldrbeq r2, [r2], #300 */
/* @0x2a630c svchs #0x2d401 */
/* @0x2a6310 ldmdbmi lr, {r1, r2, r12, lr, pc} */
/* @0x2a6314 .word 0xf04f4620 */
/* @0x2a6318 ldrbtmi r0, [r9], #-2561 */
/* @0x2a631c .word 0xf8aaf000 */
/* @0x2a6320 .word 0x212cf8d4 */
/* @0x2a6324 strle r0, [r5, #-0x4d3] */
/* @0x2a6328 qadd16mi r4, r0, r9 */
/* @0x2a632c .word 0xf0004479 */
/* @0x2a6330 and pc, r2, r1, lsr #17 */
/* @0x2a6334 svceq #0xf1ba */
/* @0x2a6338 ldmdbmi r6, {r0, r1, r2, r12, lr, pc} */
/* @0x2a633c ldrbtmi r4, [r9], #-1568 */
/* @0x2a6340 pop {r0, r1, r12, sp, pc} */
/* @0x2a6344 .word 0xf0004ff0 */
/* @0x2a6348 andlt r11, r3, r1, ror r8 */
/* @0x2a634c svchi #0xf0e8bd */
/* @0x2a6350 svcne #0xfffff8 */
/* @0x2a6354 andeq r4, pc, r0, asr #4 */
/* @0x2a6358 andeq r6, lr, r0, ror #5 */
/* @0x2a635c strdeq r6, r7, [lr], -r0 */
/* @0x2a6360 andeq r6, lr, r12, ror #5 */
/* @0x2a6364 strdeq r6, r7, [lr], -pc */
/* @0x2a6368 andeq r6, lr, r8, lsl r3 */
/* @0x2a636c andeq r6, lr, r11, lsr #6 */
/* @0x2a6370 andeq r6, lr, r8, lsr #6 */
/* @0x2a6374 andeq r6, lr, r0, lsr r3 */
/* @0x2a6378 andeq r6, lr, r0, lsr r3 */
/* @0x2a637c andeq r6, lr, r7, lsr #6 */
/* @0x2a6380 andeq r6, lr, r4, asr #6 */
/* @0x2a6384 andeq r6, lr, r3, asr r3 */
/* @0x2a6388 andeq r6, lr, lr, asr r3 */
/* @0x2a638c andeq r6, lr, r1, ror #6 */
/* @0x2a6390 andeq r6, lr, sp, ror #6 */
/* @0x2a6394 andeq r6, lr, r9, ror r3 */
/* @0x2a6398 mvnsmi lr, #737280 */
/* @0x2a639c cdpmi p4, #0x2, c2, c2, c0, #0x0 */
/* @0x2a63a0 .word 0xf04f4623 */
/* @0x2a63a4 .word 0xf04f0c5b */
/* @0x2a63a8 ldrbtmi r0, [lr], #-2141 */
/* @0x2a63ac stmdbne r5, {r0, r10, r12, sp} */
/* @0x2a63b0 .word 0x51dff895 */
/* @0x2a63b4 strbeq pc, [r1, -r5, lsr #3] */
/* @0x2a63b8 stmdale r3, {r0, r3, r4, r5, r8, r9, r10, r11, sp} */
/* @0x2a63bc ldrbeq pc, [r11, -r5, lsr #3] */
/* @0x2a63c0 ldmdale r2, {r0, r2, r8, r9, r10, r11, sp} */
/* @0x2a63c4 ldmdbne r5, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2a63c8 streq pc, [pc, #-0x5] */
/* @0x2a63cc .word 0xf80118cf */
/* @0x2a63d0 .word 0xf816c003 */
/* @0x2a63d4 ldclpl p0, c9, [r5, #-36]! */
/* @0x2a63d8 andls pc, r1, r7, lsl #17 */
/* @0x2a63dc stmdbeq r3, {r0, r1, r8, r12, sp, lr, pc} */
/* @0x2a63e0 movwlo r7, #0x40bd */
/* @0x2a63e4 andhi pc, r9, r1, lsl #16 */
/* @0x2a63e8 strbpl lr, [sp], #1 */
/* @0x2a63ec .word 0x2c043301 */
/* @0x2a63f0 ldmdblt r2, {r2, r3, r4, r6, r7, r8, r12, lr, pc} */
/* @0x2a63f4 pop {r1, r3, r6, r7, r10, r12, lr} */
/* @0x2a63f8 stmne r12, {r4, r5, r6, r7, r8, r9, pc} ^ */
/* @0x2a63fc strhs r2, [r0, #-0x3a]! */
/* @0x2a6400 ldcne p4, c5, [r8], {200} */
/* @0x2a6404 .word 0xf1037065 */
/* @0x2a6408 bne 0xff767914 <b2_toiTime+0xffffffffff00e470> */
/* @0x2a640c .word 0xf814181c */
/* @0x2a6410 .word 0xb12c4c02 */
/* @0x2a6414 stmdane r10, {r0, r12, sp} */
/* @0x2a6418 .word 0xf80242a8 */
/* @0x2a641c mvnsle r4, r1, lsl #24 */
/* @0x2a6420 strpl r2, [r11], #-768 */
/* @0x2a6424 mvnshi lr, #12386304 */
/* @0x2a6428 andeq r9, lr, lr, asr #10 */
/* @0x2a642c .word 0x460eb570 */
/* @0x2a6430 tstlt r8, r4, lsl #12 */
/* @0x2a6434 .word 0x3104f8d0 */
/* @0x2a6438 ldrmi r11, [r8, r3, lsl #2] */
/* @0x2a643c ldrtmi r4, [r2], -r11, lsl #16 */
/* @0x2a6440 ldrbtmi r4, [r8], #-2315 */
/* @0x2a6444 .word 0xf1006800 */
/* @0x2a6448 ldrbtmi r0, [r9], #-1448 */
/* @0x2a644c .word 0xf6104628 */
/* @0x2a6450 andhs lr, r10, r10, lsr #20 */
/* @0x2a6454 .word 0xf6104629 */
/* @0x2a6458 .word 0xb12cea2c */
/* @0x2a645c .word 0x3100f8d4 */
/* @0x2a6460 qadd16mi r11, r0, r3 */
/* @0x2a6464 ldrmi r2, [r8, r1, lsl #2] */
/* @0x2a6468 .word 0xec0ef610 */
/* @0x2a646c andseq r11, r4, r6 */
/* @0x2a6470 andeq r6, lr, pc, ror r2 */
/* @0x2a6474 .word 0x460ab510 */
/* @0x2a6478 stmdavc r11, {r4, r6, r8, r12, sp, pc} */
/* @0x2a647c tstle r9, r3, lsr #22 */
/* @0x2a6480 ldclpl p3, c2, [r1], {1} */
/* @0x2a6484 andsle r2, r6, r0, lsr #18 */
/* @0x2a6488 blhs 0x673094 <g_SWFlinevertbuff+0x1ffcc> */
/* @0x2a648c ldrsh sp, [r2], -r9 */
/* @0x2a6490 stmdbmi r12, {r0, r1, r9, r10, lr} */
/* @0x2a6494 ldrbtmi r4, [r9], #-1050 */
/* @0x2a6498 .word 0xf1016809 */
/* @0x2a649c stmdbmi r10, {r3, r5, r7, r10} */
/* @0x2a64a0 ldrbtmi r4, [r9], #-1568 */
/* @0x2a64a4 ldmib lr!, {r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a64a8 andhs r4, r10, r1, lsr #12 */
/* @0x2a64ac ldrhmi lr, [r0], -sp */
/* @0x2a64b0 bllt 0x9e268c <b2_toiTime+0x2891e8> */
/* @0x2a64b4 .word 0xf8d02300 */
/* @0x2a64b8 .word 0x2c004108 */
/* @0x2a64bc ldmne r1, {r0, r3, r5, r6, r7, r12, lr, pc} ^ */
/* @0x2a64c0 ldclt p7, c4, [r0, #-640] */
/* @0x2a64c4 ldrheq r10, [r4], -r2 */
/* @0x2a64c8 andeq r6, lr, r8, lsr r2 */
/* @0x2a64cc strmi r4, [r10], -r12, lsl #22 */
/* @0x2a64d0 ldrbtmi r11, [r11], #-1392 */
/* @0x2a64d4 addslt r6, r6, r11, lsl r8 */
/* @0x2a64d8 ldmdavs r12, {r1, r2, r9, r10, lr} */
/* @0x2a64dc ldrls r4, [r5], #-1565 */
/* @0x2a64e0 strbtmi r11, [r9], -r0, lsr #2 */
/* @0x2a64e4 .word 0xff58f7ff */
/* @0x2a64e8 uqasxmi r4, r9, r0 */
/* @0x2a64ec .word 0xff9ef7ff */
/* @0x2a64f0 stmdavs r11!, {r0, r2, r4, r9, r11, r12, pc} */
/* @0x2a64f4 mulle r1, r10, r2 */
/* @0x2a64f8 stmda r12!, {r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a64fc ldcllt p0, c11, [r0, #-88]! */
/* @0x2a6500 andseq r7, r4, r2, lsl #9 */
/* @0x2a6504 strmi r4, [r10], -r12, lsl #22 */
/* @0x2a6508 ldrbtmi r11, [r11], #-1392 */
/* @0x2a650c addslt r6, r6, r11, lsl r8 */
/* @0x2a6510 ldmdavs r12, {r1, r2, r9, r10, lr} */
/* @0x2a6514 ldrls r4, [r5], #-1565 */
/* @0x2a6518 strbtmi r11, [r9], -r0, lsr #2 */
/* @0x2a651c .word 0xff3cf7ff */
/* @0x2a6520 uqasxmi r4, r9, r0 */
/* @0x2a6524 .word 0xffa6f7ff */
/* @0x2a6528 stmdavs r11!, {r0, r2, r4, r9, r11, r12, pc} */
/* @0x2a652c mulle r1, r10, r2 */
/* @0x2a6530 ldmda r0, {r4, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2a6534 ldcllt p0, c11, [r0, #-88]! */
/* @0x2a6538 andseq r7, r4, r10, asr #8 */
/* @0x2a653c .word 0xf5b2b130 */
/* @0x2a6540 smlabble r2, r0, pc, r7 */
/* @0x2a6544 smlabtne r0, r0, r8, pc */
/* @0x2a6548 andhs r4, r0, r0, ror r7 */
/* @0x2a654c .word 0xb1284770 */

/* ── FUNC 0x2a603d · png_64bit_product · size=42 · insn=0 */

/* ── FUNC 0x2a6069 · png_check_cHRM_fixed · size=328 · insn=0 */

/* ── FUNC 0x2a61b1 · png_check_IHDR · size=488 · insn=0 */

/* ── FUNC 0x2a642d · png_error · size=72 · insn=0 */

/* ── FUNC 0x2a6475 · png_warning · size=88 · insn=0 */

/* ── FUNC 0x2a64cd · png_chunk_error · size=56 · insn=0 */

/* ── FUNC 0x2a6505 · png_chunk_warning · size=56 · insn=0 */

/* ── FUNC 0x2a653d · png_set_longjmp_fn · size=18 · insn=0 */

/* ── FUNC 0x2a654e · anon_2a654e · size=40 · insn=10 */
/* @0x2a654e .word 0xf8c0b128 */
/* @0x2a6552 .word 0xf8c0110c */
/* @0x2a6556 .word 0xf8c02104 */
/* @0x2a655a ldrbmi r3, [r0, -r8, lsl #2]! */
/* @0x2a655e .word 0xf8d0b108 */
/* @0x2a6562 ldrbmi r0, [r0, -r12, lsl #2]! */
/* @0x2a6566 tstlt r1, r0, lsr #2 */
/* @0x2a656a andsmi r6, r0, r8, lsl #17 */
/* @0x2a656e .word 0x46084770 */
/* @0x2a6572 tstlt r8, r0, ror r7 */

/* ── FUNC 0x2a654f · png_set_error_fn · size=16 · insn=0 */

/* ── FUNC 0x2a655f · png_get_error_ptr · size=8 · insn=0 */

/* ── FUNC 0x2a6567 · png_get_valid · size=14 · insn=0 */

/* ── FUNC 0x2a6574 · anon_2a6574 · size=28 · insn=7 */
/* @0x2a6574 .word 0xb109b118 */
/* @0x2a6578 ldrbmi r6, [r0, -r8, asr #17]! */
/* @0x2a657c ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a6580 tstlt r1, r0, lsr #2 */
/* @0x2a6584 ldrsbteq pc, [r8], #129 */
/* @0x2a6588 .word 0x46084770 */
/* @0x2a658c tstlt r8, r0, ror r7 */

/* ── FUNC 0x2a6575 · png_get_rowbytes · size=12 · insn=0 */

/* ── FUNC 0x2a6581 · png_get_rows · size=14 · insn=0 */

/* ── FUNC 0x2a658e · anon_2a658e · size=192 · insn=48 */
/* @0x2a658e .word 0xb109b118 */
/* @0x2a6592 ldrbmi r6, [r0, -r8, lsl #16]! */
/* @0x2a6596 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a659a .word 0xb109b118 */
/* @0x2a659e ldrbmi r6, [r0, -r8, asr #16]! */
/* @0x2a65a2 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a65a6 .word 0xb109b118 */
/* @0x2a65aa ldrbmi r7, [r0, -r8, lsl #28]! */
/* @0x2a65ae ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a65b2 .word 0xb109b118 */
/* @0x2a65b6 ldrbmi r7, [r0, -r8, asr #28]! */
/* @0x2a65ba ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a65be .word 0xb109b118 */
/* @0x2a65c2 ldrbmi r7, [r0, -r8, asr #29]! */
/* @0x2a65c6 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a65ca .word 0xb109b118 */
/* @0x2a65ce ldrbmi r7, [r0, -r8, lsl #30]! */
/* @0x2a65d2 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a65d6 .word 0xb109b118 */
/* @0x2a65da ldrbmi r7, [r0, -r8, lsl #29]! */
/* @0x2a65de ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a65e2 .word 0xb149b168 */
/* @0x2a65e6 .word 0xf0106888 */
/* @0x2a65ea andle r0, r8, r0, lsl #1 */
/* @0x2a65ee .word 0x3078f891 */
/* @0x2a65f2 .word 0xd1032b01 */
/* @0x2a65f6 ldrbmi r6, [r0, -r8, lsl #30]! */
/* @0x2a65fa ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a65fe ldrbmi r2, [r0, -r0]! */
/* @0x2a6602 .word 0xb149b168 */
/* @0x2a6606 .word 0xf0106888 */
/* @0x2a660a andle r0, r8, r0, lsl #1 */
/* @0x2a660e .word 0x3078f891 */
/* @0x2a6612 .word 0xd1032b01 */
/* @0x2a6616 ldrbmi r6, [r0, -r8, asr #30]! */
/* @0x2a661a ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a661e ldrbmi r2, [r0, -r0]! */
/* @0x2a6622 smulbblt r9, r8, r1 */
/* @0x2a6626 .word 0xf0106888 */
/* @0x2a662a andle r0, r12, r0, lsl #1 */
/* @0x2a662e .word 0x3078f891 */
/* @0x2a6632 .word 0xd1072b01 */
/* @0x2a6636 svcvs #0x486f0b */
/* @0x2a663a svclt #0x184283 */
/* @0x2a663e ldrbmi r2, [r0, -r0]! */
/* @0x2a6642 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a6646 ldrbmi r2, [r0, -r0]! */
/* @0x2a664a orrlt r0, r0, r0 */

/* ── FUNC 0x2a658f · png_get_image_width · size=12 · insn=0 */

/* ── FUNC 0x2a659b · png_get_image_height · size=12 · insn=0 */

/* ── FUNC 0x2a65a7 · png_get_bit_depth · size=12 · insn=0 */

/* ── FUNC 0x2a65b3 · png_get_color_type · size=12 · insn=0 */

/* ── FUNC 0x2a65bf · png_get_filter_type · size=12 · insn=0 */

/* ── FUNC 0x2a65cb · png_get_interlace_type · size=12 · insn=0 */

/* ── FUNC 0x2a65d7 · png_get_compression_type · size=12 · insn=0 */

/* ── FUNC 0x2a65e3 · png_get_x_pixels_per_meter · size=32 · insn=0 */

/* ── FUNC 0x2a6603 · png_get_y_pixels_per_meter · size=32 · insn=0 */

/* ── FUNC 0x2a6623 · png_get_pixels_per_meter · size=40 · insn=0 */

/* ── FUNC 0x2a664c · anon_2a664c · size=148 · insn=37 */
/* @0x2a664c cmnlt r9, r0, lsl #3 */
/* @0x2a6650 ldreq r6, [r11], -r11, lsl #17 */
/* @0x2a6654 svcvs #0xbd50c */
/* @0x2a6658 mcr p1, #0x0, r11, c6, c3, #0x2 */
/* @0x2a665c vldr s7, [r1, #576] */
/* @0x2a6660 vmrs r7, fpexc */
/* @0x2a6664 vcvt.f32.u32 s14, s15 */
/* @0x2a6668 .word 0xeec77a66 */
/* @0x2a666c and r7, r1, r7, lsl #21 */
/* @0x2a6670 bvc 0x361df4 <_ZTS12CDS_Priority+0x3e4c> */
/* @0x2a6674 beq 0xfe6e1ed8 <b2_toiTime+0xfffffffffdf88a34> */
/* @0x2a6678 svclt #0x4770 */
/* @0x2a667c andeq r0, r0, r0 */
/* @0x2a6680 .word 0xb149b168 */
/* @0x2a6684 .word 0xf4106888 */
/* @0x2a6688 andle r7, r8, r0, lsl #1 */
/* @0x2a668c mlslo r12, r1, r8, pc */
/* @0x2a6690 .word 0xd1032b01 */
/* @0x2a6694 ldrbmi r6, [r0, -r8, asr #28]! */
/* @0x2a6698 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a669c ldrbmi r2, [r0, -r0]! */
/* @0x2a66a0 .word 0xb149b168 */
/* @0x2a66a4 .word 0xf4106888 */
/* @0x2a66a8 andle r7, r8, r0, lsl #1 */
/* @0x2a66ac mlslo r12, r1, r8, pc */
/* @0x2a66b0 .word 0xd1032b01 */
/* @0x2a66b4 ldrbmi r6, [r0, -r8, lsl #29]! */
/* @0x2a66b8 ldrbmi r4, [r0, -r8, lsl #12]! */
/* @0x2a66bc ldrbmi r2, [r0, -r0]! */
/* @0x2a66c0 .word 0xb141b160 */
/* @0x2a66c4 .word 0xf4106888 */
/* @0x2a66c8 andle r7, r7, r0, lsl #1 */
/* @0x2a66cc mlslo r12, r1, r8, pc */
/* @0x2a66d0 mcrvs p9, #0x2, r11, c8, c11, #0x0 */
/* @0x2a66d4 .word 0x46084770 */
/* @0x2a66d8 andhs r4, r0, r0, ror r7 */
/* @0x2a66dc .word 0xb1604770 */

/* ── FUNC 0x2a664d · png_get_pixel_aspect_ratio · size=52 · insn=0 */

/* ── FUNC 0x2a6681 · png_get_x_offset_microns · size=32 · insn=0 */

/* ── FUNC 0x2a66a1 · png_get_y_offset_microns · size=32 · insn=0 */

/* ── FUNC 0x2a66c1 · png_get_x_offset_pixels · size=30 · insn=0 */
