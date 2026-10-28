/* libyoyo.so 覆盖卡组 0258
 * 函数 0x2abc2a..0x2ae25d，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2abc2a · anon_2abc2a · size=108 · insn=27 */
/* @0x2abc2a .word 0x4604b537 */
/* @0x2abc2e .word 0x31e0f890 */
/* @0x2abc32 ldrsbpl pc, [r0, -r0]! */
/* @0x2abc36 svceq #0x20f013 */
/* @0x2abc3a vst4.8 {d13, d14, d15, d16}, [r5], r6 */
/* @0x2abc3e .word 0xf5b57540 */
/* @0x2abc42 svclt #0x187540 */
/* @0x2abc46 and r2, r3, r1, lsl #10 */
/* @0x2abc4a strvs pc, [r0, #-0x485] */
/* @0x2abc4e strbhs pc, [r0, #0x3c5] */
/* @0x2abc52 strtmi r2, [r0], -r1, lsl #7 */
/* @0x2abc56 teqlo r4, #196, #16 */
/* @0x2abc5a andhs r10, r4, #16384 */
/* @0x2abc5e .word 0xf9e7f7fc */
/* @0x2abc62 .word 0xf89db19d */
/* @0x2abc66 .word 0xf89d0005 */
/* @0x2abc6a .word 0xf89d3004 */
/* @0x2abc6e streq r5, [r0], #-6 */
/* @0x2abc72 andvs lr, r3, r0, lsl #22 */
/* @0x2abc76 mullo r7, sp, r8 */
/* @0x2abc7a .word 0xf8d44418 */
/* @0x2abc7e bl 0x2b83d6 <jinit_phuff_decoder+0x3fa> */
/* @0x2abc82 bne 0xff2b3c9e <b2_toiTime+0xfffffffffeb5a7fa> */
/* @0x2abc86 andhs r11, r1, r8, lsl pc */
/* @0x2abc8a strtmi lr, [r8], -r0 */
/* @0x2abc8e ldclt p0, c11, [r0, #-12]! */
/* @0x2abc92 ldrblt r0, [r0, #-0x0]! */

/* ── FUNC 0x2abc2b · png_crc_error · size=104 · insn=0 */

/* ── FUNC 0x2abc94 · anon_2abc94 · size=11896 · insn=2974 */
/* @0x2abc94 .word 0x4604b570 */
/* @0x2abc98 ldrsbvs pc, [r4, #-128]! */
/* @0x2abc9c adcsmi r4, r5, #13631488 */
/* @0x2abca0 strtmi sp, [r0], -r8, lsl #18 */
/* @0x2abca4 ldrsbne pc, [r0, #-132]! */
/* @0x2abca8 ldrsbhs pc, [r4, #-132]! */
/* @0x2abcac .word 0xf7ff1bad */
/* @0x2abcb0 ldrb pc, [r4, sp, lsr #31]! */
/* @0x2abcb4 strtmi r11, [r0], -sp, lsr #2 */
/* @0x2abcb8 ldrsbne pc, [r0, #-132]! */
/* @0x2abcbc .word 0xf7ff462a */
/* @0x2abcc0 strtmi pc, [r0], -r5, lsr #31 */
/* @0x2abcc4 .word 0xffb1f7ff */
/* @0x2abcc8 .word 0xf894b1c0 */
/* @0x2abccc .word 0xf01331e0 */
/* @0x2abcd0 .word 0xf8d40f20 */
/* @0x2abcd4 andle r3, r2, r0, lsr r1 */
/* @0x2abcd8 strle r0, [r9], #-1434 */
/* @0x2abcdc ldrbeq lr, [r11, #-0x1] */
/* @0x2abce0 stmdbmi r7, {r1, r2, r8, r10, r12, lr, pc} */
/* @0x2abce4 ldrbtmi r4, [r9], #-1568 */
/* @0x2abce8 .word 0xfc0cf7fa */
/* @0x2abcec ldcllt p0, c2, [r0, #-4]! */
/* @0x2abcf0 strtmi r4, [r0], -r4, lsl #18 */
/* @0x2abcf4 .word 0xf7fa4479 */
/* @0x2abcf8 andhs pc, r0, r9, ror #23 */
/* @0x2abcfc svclt #0xbd70 */
/* @0x2abd00 andeq r0, lr, r6, asr #7 */
/* @0x2abd04 strheq r0, [lr], -r8 */
/* @0x2abd08 svcmi #0xf0e92d */
/* @0x2abd0c blmi 0x153d588 <b2_toiTime+0xde40e4> */
/* @0x2abd10 addslt r4, r1, lr, lsl #12 */
/* @0x2abd14 ldrbtmi r4, [r11], #-661 */
/* @0x2abd18 .word 0x4604681b */
/* @0x2abd1c .word 0x8068f8dd */
/* @0x2abd20 .word 0x469a6819 */
/* @0x2abd24 stmdble r5, {r0, r1, r2, r3, r8, r12, pc} */
/* @0x2abd28 strhs r4, [r0, #-0x944] */
/* @0x2abd2c .word 0xf7fa4479 */
/* @0x2abd30 subs pc, pc, r1, lsr #23 */
/* @0x2abd34 cmple r1, r0, lsl #28 */
/* @0x2abd38 teqne r0, #208, #16 */
/* @0x2abd3c stmdbeq r2, {r0, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2abd40 .word 0x96004633 */
/* @0x2abd44 strbmi r4, [r10], -r9, lsr #8 */
/* @0x2abd48 mrc2 p7, #0x4, apsr_nzcv, c10, c15, #0x7 */
/* @0x2abd4c strmi r1, [r6], -r11, ror #25 */
/* @0x2abd50 .word 0xf06fd80b */
/* @0x2abd54 blne 0x196c960 <b2_toiTime+0x12134bc> */
/* @0x2abd58 andle r4, r6, #152, #4 */
/* @0x2abd5c .word 0x31a0f8d4 */
/* @0x2abd60 stmdbne r2, {r0, r1, r3, r4, r5, r8, r12, sp, pc} ^ */
/* @0x2abd64 addsmi r3, r10, #1024 */
/* @0x2abd68 ldmdbmi r5!, {r0, r1, r8, r9, r12, lr, pc} */
/* @0x2abd6c ldrbtmi r4, [r9], #-1568 */
/* @0x2abd70 mcrhs p0, #0x0, lr, c0, c14, #0x1 */
/* @0x2abd74 bl 0x45fe74 <g_RomDisk+0x68654> */
/* @0x2abd78 strtmi r0, [r0], -r5, lsl #22 */
/* @0x2abd7c mrseq pc, apsr */
/* @0x2abd80 .word 0xffc9f7fa */
/* @0x2abd84 .word 0xb3284607 */
/* @0x2abd88 teqne r0, #212, #16 */
/* @0x2abd8c .word 0xf60a462a */
/* @0x2abd90 .word 0xf8d4ec16 */
/* @0x2abd94 ldmdbne r11!, {r4, r5, r8, r9, r12} ^ */
/* @0x2abd98 strtmi r9, [r0], -r0, lsl #12 */
/* @0x2abd9c strbmi r4, [r10], -r9, lsr #8 */
/* @0x2abda0 mcr2 p7, #0x3, pc, c14, c15, #0x7 */
/* @0x2abda4 .word 0xf8072300 */
/* @0x2abda8 adcsmi r3, r0, #11 */
/* @0x2abdac .word 0xd1084620 */
/* @0x2abdb0 teqne r0, #212, #16 */
/* @0x2abdb4 .word 0xffa2f7fa */
/* @0x2abdb8 teqvc r0, #196, #16 */
/* @0x2abdbc andlt pc, r0, r8, asr #17 */
/* @0x2abdc0 stmdbmi r0!, {r0, r1, r2, r3, r5, sp, lr, pc} */
/* @0x2abdc4 .word 0xf7fa4479 */
/* @0x2abdc8 qsaxmi pc, r0, r5 */
/* @0x2abdcc .word 0xf7fa4639 */
/* @0x2abdd0 mul pc, r5, pc */
/* @0x2abdd4 qadd16mi r4, r0, r12 */
/* @0x2abdd8 and r4, r9, r9, ror r4 */
/* @0x2abddc bmi 0x9979ec <b2_toiTime+0x23e548> */
/* @0x2abde0 shasxmi r2, r3, r2 */
/* @0x2abde4 ldrbtmi r4, [r10], #-1592 */
/* @0x2abde8 bl 0xffe69618 <b2_toiTime+0xffffffffff710174> */
/* @0x2abdec ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2abdf0 blx 0x12e9de2 <b2_toiTime+0xb9093e> */
/* @0x2abdf4 stclne p6, c4, [r9], #-128 */
/* @0x2abdf8 .word 0xff8df7fa */
/* @0x2abdfc cmnlt r0, r6, lsl #12 */
/* @0x2abe00 .word 0xf8d4b125 */
/* @0x2abe04 qasxmi r1, r10, r0 */
/* @0x2abe08 bl 0xff8e9638 <b2_toiTime+0xffffffffff190194> */
/* @0x2abe0c .word 0xf8d44620 */
/* @0x2abe10 .word 0xf7fa1330 */
/* @0x2abe14 .word 0xf8c4ff73 */
/* @0x2abe18 movwhs r6, #0x330 */
/* @0x2abe1c .word 0xf8c85573 */
/* @0x2abe20 bls 0x67fe28 <g_SWFlinevertbuff+0x2cd60> */
/* @0x2abe24 .word 0x3000f8da */
/* @0x2abe28 mulle r1, r10, r2 */
/* @0x2abe2c bl 0xff76965c <b2_toiTime+0xffffffffff0101b8> */
/* @0x2abe30 pop {r0, r4, r12, sp, pc} */
/* @0x2abe34 svclt #0x8ff0 */
/* @0x2abe38 andseq r1, r4, lr, lsr r12 */
/* @0x2abe3c andeq r0, lr, sp, lsr #29 */
/* @0x2abe40 andeq r0, lr, pc, ror lr */
/* @0x2abe44 andeq r0, lr, r3, asr lr */
/* @0x2abe48 andeq r0, lr, r7, asr lr */
/* @0x2abe4c andeq r0, lr, pc, ror #28 */
/* @0x2abe50 push {r0, r6, r8, r9, r11, lr} */
/* @0x2abe54 ldrbtmi r4, [r11], #-1008 */
/* @0x2abe58 pkhbtmi r6, r8, r11, lsl #16 */
/* @0x2abe5c .word 0x112cf8d0 */
/* @0x2abe60 ldmdavs r10, {r0, r2, r4, r9, r10, lr} */
/* @0x2abe64 .word 0xf011b08d */
/* @0x2abe68 strmi r0, [r4], -r1, lsl #30 */
/* @0x2abe6c andls r4, r11, #160432128 */
/* @0x2abe70 ldmdbmi r10!, {r0, r1, r12, lr, pc} */
/* @0x2abe74 .word 0xf7fa4479 */
/* @0x2abe78 vstrhs s30, [sp, #-868] */
/* @0x2abe7c ldmdbmi r8!, {r2, r12, lr, pc} */
/* @0x2abe80 ldrbtmi r4, [r9], #-1568 */
/* @0x2abe84 blx 0xff769e74 <b2_toiTime+0xffffffffff0109d0> */
/* @0x2abe88 .word 0x312cf8d4 */
/* @0x2abe8c andhs r10, sp, #7, #28 */
/* @0x2abe90 .word 0xf0434620 */
/* @0x2abe94 ldrtmi r0, [r1], -r1, lsl #6 */
/* @0x2abe98 smlawtlo r12, r4, r8, pc */
/* @0x2abe9c mrc2 p7, #0x5, apsr_nzcv, c6, c15, #0x7 */
/* @0x2abea0 strtmi r2, [r0], -r0, lsl #2 */
/* @0x2abea4 mrc2 p7, #0x7, apsr_nzcv, c6, c15, #0x7 */
/* @0x2abea8 qasxmi r4, r0, r1 */
/* @0x2abeac mrc2 p7, #0x2, apsr_nzcv, c14, c15, #0x7 */
/* @0x2abeb0 .word 0x46051d31 */
/* @0x2abeb4 .word 0xf7ff4620 */
/* @0x2abeb8 .word 0xf89dfe59 */
/* @0x2abebc .word 0xf89d7024 */
/* @0x2abec0 .word 0xf89d2025 */
/* @0x2abec4 .word 0xf89d1027 */
/* @0x2abec8 .word 0xf8c4e028 */
/* @0x2abecc .word 0xf884518c */
/* @0x2abed0 .word 0xf88471eb */
/* @0x2abed4 .word 0xf884e1e7 */
/* @0x2abed8 .word 0xf88421ea */
/* @0x2abedc strmi r1, [r3], -r4, ror #5 */
/* @0x2abee0 mlaeq r6, sp, r8, pc */
/* @0x2abee4 orrslo pc, r0, r4, asr #17 */
/* @0x2abee8 movweq pc, #0x4884 */
/* @0x2abeec stmdale lr, {r1, r2, r9, r11, sp} */
/* @0x2abef0 .word 0xf002e8df */
/* @0x2abef4 streq r0, [r6], #-3332 */
/* @0x2abef8 andeq r0, r10, r8, lsl #26 */
/* @0x2abefc and r2, r4, r1, lsl #12 */
/* @0x2abf00 and r2, r2, r3, lsl #12 */
/* @0x2abf04 and r2, r0, r2, lsl #12 */
/* @0x2abf08 .word 0xf8842604 */
/* @0x2abf0c .word 0xf89461ee */
/* @0x2abf10 cmnmi lr, #-2147483589 */
/* @0x2abf14 .word 0xf884b2f6 */
/* @0x2abf18 cdphs p1, #0x0, c6, c7, c13, #0x7 */
/* @0x2abf1c ldmeq r6!, {r1, r8, r11, r12, lr, pc} ^ */
/* @0x2abf20 and r4, r2, lr, ror #6 */
/* @0x2abf24 strlo r4, [r7], -lr, ror #6 */
/* @0x2abf28 andls r0, r1, #16121856 */
/* @0x2abf2c andls r4, r3, r10, lsr #12 */
/* @0x2abf30 .word 0x91044620 */
/* @0x2abf34 .word 0xf8c44641 */
/* @0x2abf38 .word 0x9700619c */
/* @0x2abf3c and pc, r8, sp, asr #17 */
/* @0x2abf40 stc2 p0, c15, [r0, #8]! */
/* @0x2abf44 .word 0xf8d99a0b */
/* @0x2abf48 addsmi r3, r10, #0 */
/* @0x2abf4c .word 0xf60ad001 */
/* @0x2abf50 andlt lr, sp, r2, asr #22 */
/* @0x2abf54 mvnshi lr, #12386304 */
/* @0x2abf58 ldrsheq r1, [r4], -lr */
/* @0x2abf5c andeq r0, lr, r2, lsl #28 */
/* @0x2abf60 andeq r0, lr, r6, lsl #28 */
/* @0x2abf64 svcmi #0xf0e92d */
/* @0x2abf68 .word 0xf8d04615 */
/* @0x2abf6c .word 0xf5ad312c */
/* @0x2abf70 strmi r7, [r4], -r3, asr #26 */
/* @0x2abf74 ldrbeq r4, [r10, lr, lsl #12] */
/* @0x2abf78 stmdbmi r11, {r1, r10, r12, lr, pc} ^ */
/* @0x2abf7c and r4, r8, r9, ror r4 */
/* @0x2abf80 strle r0, [r2, #-0x75f] */
/* @0x2abf84 ldrbtmi r4, [r9], #-2377 */
/* @0x2abf88 .word 0x0799e012 */
/* @0x2abf8c stmdbmi r8, {r0, r1, r8, r10, r12, lr, pc} ^ */
/* @0x2abf90 .word 0xf7fa4479 */
/* @0x2abf94 .word 0xf894fa4b */
/* @0x2abf98 .word 0xf8d471ea */
/* @0x2abf9c ldreq r3, [r10, r12, lsr #2]! */
/* @0x2abfa0 movweq pc, #0x2043 */
/* @0x2abfa4 smlawtlo r12, r4, r8, pc */
/* @0x2abfa8 stmdbmi r2, {r0, r3, r10, r12, lr, pc} ^ */
/* @0x2abfac ldrbtmi r4, [r9], #-1568 */
/* @0x2abfb0 blx 0x1ae9fa0 <b2_toiTime+0x1390afc> */
/* @0x2abfb4 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2abfb8 mcr2 p7, #0x3, pc, c12, c15, #0x7 */
/* @0x2abfbc .word 0xf5b5e06f */
/* @0x2abfc0 stmdale r4, {r6, r8, r9, r10, r11, r12, sp, lr} */
/* @0x2abfc4 .word 0x21034628 */
/* @0x2abfc8 cdp p0, #0x9, c15, c2, c12, #0x3 */
/* @0x2abfcc svchs #0x3b149 */
/* @0x2abfd0 andle r4, r2, r0, lsr #12 */
/* @0x2abfd4 ldrbtmi r4, [r9], #-2360 */
/* @0x2abfd8 ldmdbmi r8!, {r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2abfdc .word 0xf7fa4479 */
/* @0x2abfe0 strtmi pc, [r8], -r5, lsr #20 */
/* @0x2abfe4 .word 0xf06c2103 */
/* @0x2abfe8 .word 0xf894ee94 */
/* @0x2abfec .word 0xf10d31ea */
/* @0x2abff0 .word 0xf10d0b08 */
/* @0x2abff4 blhs 0x36e40c <_ZTS13C_UTF16String+0x54b8> */
/* @0x2abff8 streq pc, [r3, -r11, lsl #2] */
/* @0x2abffc beq 0x2e8140 <FT_GlyphLoader_CheckPoints+0x3a> */
/* @0x2ac000 .word 0xf894bf05 */
/* @0x2ac004 .word 0xf04f31eb */
/* @0x2ac008 vst2.8 {d16, d17}, [pc], r1 */
/* @0x2ac00c blx 0x4ca214 <SrcVerts+0x27258> */
/* @0x2ac010 strmi pc, [r0, #0x803] */
/* @0x2ac014 strmi r11, [r0], r8, lsr #31 */
/* @0x2ac018 .word 0xf10745c2 */
/* @0x2ac01c strtmi r0, [r0], -r3, lsl #14 */
/* @0x2ac020 .word 0x4649da12 */
/* @0x2ac024 .word 0xf7ff2203 */
/* @0x2ac028 .word 0xf899fdf1 */
/* @0x2ac02c .word 0xf10a3000 */
/* @0x2ac030 .word 0xf8070a01 */
/* @0x2ac034 .word 0xf8993c06 */
/* @0x2ac038 .word 0xf8073001 */
/* @0x2ac03c .word 0xf8993c05 */
/* @0x2ac040 .word 0xf8073002 */
/* @0x2ac044 strb r3, [r7, r4, lsl #24]! */
/* @0x2ac048 .word 0x0102f06f */
/* @0x2ac04c .word 0x5108fb01 */
/* @0x2ac050 mcr2 p7, #0x1, pc, c0, c15, #0x7 */
/* @0x2ac054 strtmi r4, [r0], -r3, asr #12 */
/* @0x2ac058 uasxmi r4, r10, r1 */
/* @0x2ac05c cdp2 p0, #0x1, c15, c2, c2, #0x0 */
/* @0x2ac060 .word 0x31eaf894 */
/* @0x2ac064 tstle r10, r3, lsl #22 */
/* @0x2ac068 ldmvs r3!, {r1, r2, r3, r6, r7, r8, r12, sp, pc} */
/* @0x2ac06c ldrle r0, [r6, #-0x6db] */
/* @0x2ac070 ldrhlo pc, [lr, #132] */
/* @0x2ac074 .word 0xf888fa1f */
/* @0x2ac078 stmdble r6, {r0, r1, r6, r8, r10, lr} */
/* @0x2ac07c qadd16mi r4, r0, r0 */
/* @0x2ac080 .word 0xf7fa4479 */
/* @0x2ac084 .word 0xf8a4f9f7 */
/* @0x2ac088 bhi 0xfff8c808 <b2_toiTime+0xffffffffff833364> */
/* @0x2ac08c stmdble r6, {r0, r1, r6, r8, r10, lr} */
/* @0x2ac090 strtmi r4, [r0], -r12, lsl #18 */
/* @0x2ac094 .word 0xf7fa4479 */
/* @0x2ac098 .word 0xf8a6f9ed */
/* @0x2ac09c .word 0xf50d8016 */
/* @0x2ac0a0 pop {r0, r1, r6, r8, r10, r11, r12, sp, lr} */
/* @0x2ac0a4 svclt #0x8ff0 */
/* @0x2ac0a8 andeq r0, lr, pc, lsl sp */
/* @0x2ac0ac andeq r0, lr, lr, lsr #26 */
/* @0x2ac0b0 andeq r0, lr, r12, lsr sp */
/* @0x2ac0b4 andeq r0, lr, r3, lsr sp */
/* @0x2ac0b8 andeq r0, lr, r0, lsr sp */
/* @0x2ac0bc andeq r0, lr, r10, lsr #26 */
/* @0x2ac0c0 muleq lr, r12, r12 */
/* @0x2ac0c4 andeq r0, lr, pc, lsr #25 */
/* @0x2ac0c8 .word 0x4604b538 */
/* @0x2ac0cc .word 0x312cf8d0 */
/* @0x2ac0d0 .word 0xf0034615 */
/* @0x2ac0d4 blhs 0x3eccf0 <af_shaw_script_class> */
/* @0x2ac0d8 stmdbmi r11, {r0, r1, r12, lr, pc} */
/* @0x2ac0dc .word 0xf7fa4479 */
/* @0x2ac0e0 .word 0xf8d4f9a5 */
/* @0x2ac0e4 .word 0xf043312c */
/* @0x2ac0e8 .word 0xf8c40318 */
/* @0x2ac0ec .word 0xb125312c */
/* @0x2ac0f0 strtmi r4, [r0], -r6, lsl #18 */
/* @0x2ac0f4 .word 0xf7fa4479 */
/* @0x2ac0f8 .word 0x4620f9bd */
/* @0x2ac0fc pop {r0, r3, r5, r9, r10, lr} */
/* @0x2ac100 .word 0xf7ff4038 */
/* @0x2ac104 svclt #0xbdc7 */
/* @0x2ac108 muleq lr, r3, r12 */
/* @0x2ac10c andeq r0, lr, r12, lsl #25 */
/* @0x2ac110 ssub16mi r11, r6, r3 */
/* @0x2ac114 .word 0x312cf8d0 */
/* @0x2ac118 strmi r4, [sp], -r4, lsl #12 */
/* @0x2ac11c strle r0, [r4], #-2010 */
/* @0x2ac120 ldrbtmi r4, [r9], #-2364 */
/* @0x2ac124 .word 0xf982f7fa */
/* @0x2ac128 ldrbeq lr, [r9, -r10] */
/* @0x2ac12c ldmdbmi r10!, {r1, r8, r10, r12, lr, pc} */
/* @0x2ac130 and r4, pc, r9, ror r4 */
/* @0x2ac134 strle r0, [r3, #-0x79a] */
/* @0x2ac138 ldrbtmi r4, [r9], #-2360 */
/* @0x2ac13c .word 0xf99af7fa */
/* @0x2ac140 cmnlt r5, r0, lsr #12 */
/* @0x2ac144 .word 0xf64068aa */
/* @0x2ac148 andsmi r0, r3, r1, lsl #6 */
/* @0x2ac14c .word 0xd1082b01 */
/* @0x2ac150 ldrbtmi r4, [r9], #-2355 */
/* @0x2ac154 .word 0xf98ef7fa */
/* @0x2ac158 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2ac15c ldc2 p7, c15, [r10, #1020] */
/* @0x2ac160 mcrhs p0, #0x0, lr, c4, c3, #0x2 */
/* @0x2ac164 stmdbmi pc!, {r1, r12, lr, pc} */
/* @0x2ac168 .word 0xe7f34479 */
/* @0x2ac16c ldrtmi r10, [r2], -r1, lsl #18 */
/* @0x2ac170 stc2l p7, c15, [r12, #-1020] */
/* @0x2ac174 .word 0x21004620 */
/* @0x2ac178 stc2 p7, c15, [r12, #1020] */
/* @0x2ac17c mrsle r2, spsr */
/* @0x2ac180 mulvs r5, sp, r8 */
/* @0x2ac184 mullo r4, sp, r8 */
/* @0x2ac188 bl 0x42d268 <g_RomDisk+0x35a48> */
/* @0x2ac18c .word 0xf89d6603 */
/* @0x2ac190 ldrmi r3, [lr], #-7 */
/* @0x2ac194 mullo r6, sp, r8 */
/* @0x2ac198 .word 0x2603eb16 */
/* @0x2ac19c stmdbmi r2!, {r0, r2, r8, r12, lr, pc} */
/* @0x2ac1a0 ldrbtmi r4, [r9], #-1568 */
/* @0x2ac1a4 .word 0xf966f7fa */
/* @0x2ac1a8 .word 0xb1bde02f */
/* @0x2ac1ac ldreq r6, [r11, #-0x8ab] */
/* @0x2ac1b0 .word 0xf5a6d514 */
/* @0x2ac1b4 bllo 0xff4bce78 <b2_toiTime+0xfffffffffed639d4> */
/* @0x2ac1b8 svcvc #0x7af5b3 */
/* @0x2ac1bc ldmdbmi r11, {r1, r2, r3, r8, r11, r12, lr, pc} */
/* @0x2ac1c0 ldrbtmi r4, [r9], #-1568 */
/* @0x2ac1c4 .word 0xf956f7fa */
/* @0x2ac1c8 ldmdbmi r10, {r0, r3, r4, r11, lr} */
/* @0x2ac1cc ldrbtmi r4, [r8], #-1586 */
/* @0x2ac1d0 ldrbtmi r6, [r9], #-2048 */
/* @0x2ac1d4 .word 0xf60a30a8 */
/* @0x2ac1d8 ands lr, r6, r6, ror #22 */
/* @0x2ac1dc bvs 0x6e79fc <g_SWFvertbuff+0x14934> */
/* @0x2ac1e0 bvc 0x5a7964 <g_SWFlineaavertbuff+0x5489c> */
/* @0x2ac1e4 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2ac1e8 bvc 0xff467cd0 <b2_toiTime+0xfffffffffed0e82c> */
/* @0x2ac1ec bvc 0xca7d10 <b2_toiTime+0x54e86c> */
/* @0x2ac1f0 bvs 0xffca7cd4 <b2_toiTime+0xffffffffff54e830> */
/* @0x2ac1f4 bvc 0xfe4e790c <b2_toiTime+0xfffffffffdd8e468> */
/* @0x2ac1f8 blhs 0x86734c <b2_toiTime+0x10dea8> */
/* @0x2ac1fc blx 0x21e820e <b2_toiTime+0x1a8ed6a> */
/* @0x2ac200 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2ac204 .word 0xf0024632 */
/* @0x2ac208 strhlt pc, [r2], -pc */
/* @0x2ac20c svclt #0xbd70 */
/* @0x2ac210 strbmi r5, [r3, r0] */
/* @0x2ac214 andeq r0, lr, r10, ror r12 */
/* @0x2ac218 andeq r0, lr, r5, lsl #25 */
/* @0x2ac21c muleq lr, r3, r12 */
/* @0x2ac220 muleq lr, r3, r12 */
/* @0x2ac224 muleq lr, r2, r12 */
/* @0x2ac228 andeq r0, lr, r4, ror r12 */
/* @0x2ac22c andeq r0, lr, r5, ror r12 */
/* @0x2ac230 andseq r5, r4, r10, ror r2 */
/* @0x2ac234 muleq lr, sp, r12 */
/* @0x2ac238 movwhs r11, #0x573 */
/* @0x2ac23c andlo pc, r7, sp, lsl #17 */
/* @0x2ac240 .word 0xf88d4615 */
/* @0x2ac244 strmi r3, [r4], -r6 */
/* @0x2ac248 andlo pc, r5, sp, lsl #17 */
/* @0x2ac24c .word 0xf88d460e */
/* @0x2ac250 .word 0xf8d03004 */
/* @0x2ac254 ldrbeq r3, [r10, r12, lsr #2] */
/* @0x2ac258 stmdbmi lr!, {r2, r10, r12, lr, pc} */
/* @0x2ac25c .word 0xf7fa4479 */
/* @0x2ac260 and pc, r10, r5, ror #17 */
/* @0x2ac264 strle r0, [r2, #-0x759] */
/* @0x2ac268 ldrbtmi r4, [r9], #-2347 */
/* @0x2ac26c ldreq lr, [r10, r12] */
/* @0x2ac270 stmdbmi r10!, {r0, r1, r8, r10, r12, lr, pc} */
/* @0x2ac274 .word 0xf7fa4479 */
/* @0x2ac278 .word 0xb166f8fd */
/* @0x2ac27c .word 0x079b68b3 */
/* @0x2ac280 stmdbmi r7!, {r0, r3, r8, r10, r12, lr, pc} */
/* @0x2ac284 ldrbtmi r4, [r9], #-1568 */
/* @0x2ac288 .word 0xf8f4f7fa */
/* @0x2ac28c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2ac290 stc2 p7, c15, [r0, #-1020] */
/* @0x2ac294 .word 0xf894e03c */
/* @0x2ac298 strtmi r3, [r0], -r10, ror #3 */
/* @0x2ac29c svclt #0x182b03 */
/* @0x2ac2a0 .word 0x31eef894 */
/* @0x2ac2a4 swple r4, sp, [r1] */
/* @0x2ac2a8 stmdble r2, {r2, r8, r10, r11, sp} */
/* @0x2ac2ac ldrbtmi r4, [r9], #-2333 */
/* @0x2ac2b0 stmdbge r1, {r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2ac2b4 .word 0xf7ff462a */
/* @0x2ac2b8 strtmi pc, [r0], -r9, lsr #25 */
/* @0x2ac2bc .word 0xf7ff2100 */
/* @0x2ac2c0 bllt 0xceb66c <b2_toiTime+0x5921c8> */
/* @0x2ac2c4 .word 0x31eaf894 */
/* @0x2ac2c8 mulhs r5, sp, r8 */
/* @0x2ac2cc svceq #0x2f013 */
/* @0x2ac2d0 mullo r4, sp, r8 */
/* @0x2ac2d4 .word 0xf884d00c */
/* @0x2ac2d8 .word 0xf89d3240 */
/* @0x2ac2dc .word 0xf8843006 */
/* @0x2ac2e0 .word 0xf8842241 */
/* @0x2ac2e4 .word 0xf89d3242 */
/* @0x2ac2e8 .word 0xf8843007 */
/* @0x2ac2ec and r3, r9, r4, asr #4 */
/* @0x2ac2f0 sublo pc, r3, #132, #16 */
/* @0x2ac2f4 sublo pc, r0, #132, #16 */
/* @0x2ac2f8 sublo pc, r1, #132, #16 */
/* @0x2ac2fc sublo pc, r2, #132, #16 */
/* @0x2ac300 subhs pc, r4, #132, #16 */
/* @0x2ac304 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2ac308 andsvc pc, r0, #4, #10 */
/* @0x2ac30c stc2 p0, c15, [r6, #-8] */
/* @0x2ac310 ldcllt p0, c11, [r0, #-8]! */
/* @0x2ac314 andeq r0, lr, r7, lsr #24 */
/* @0x2ac318 andeq r0, lr, r2, lsr r12 */
/* @0x2ac31c andeq r0, lr, r0, asr #24 */
/* @0x2ac320 andeq r0, lr, r6, asr #24 */
/* @0x2ac324 andeq r0, lr, r3, lsr r12 */
/* @0x2ac328 push {r4, r6, r7, r8, r9, r11, lr} */
/* @0x2ac32c stc p15, c4, [sp, #-960]! */
/* @0x2ac330 ldrbtmi r8, [r11], #-2824 */
/* @0x2ac334 sadd16mi r6, r6, r11 */
/* @0x2ac338 ldmdavs r10, {r0, r2, r3, r4, r7, r12, sp, pc} */
/* @0x2ac33c strmi r4, [sp], -r4, lsl #12 */
/* @0x2ac340 andsls r9, r11, #1140850688 */
/* @0x2ac344 .word 0x212cf8d0 */
/* @0x2ac348 svceq #0x1f012 */
/* @0x2ac34c stmibmi r8, {r2, r8, r12, lr, pc} ^ */
/* @0x2ac350 .word 0xf7fa4479 */
/* @0x2ac354 and pc, r10, r11, ror #16 */
/* @0x2ac358 strle r0, [r2, #-0x751] */
/* @0x2ac35c ldrbtmi r4, [r9], #-2501 */
/* @0x2ac360 .word 0x0792e014 */
/* @0x2ac364 stmibmi r4, {r0, r1, r8, r10, r12, lr, pc} ^ */
/* @0x2ac368 .word 0xf7fa4479 */
/* @0x2ac36c strtmi pc, [r0], -r3, lsl #17 */
/* @0x2ac370 stmvs r10!, {r0, r2, r6, r8, r12, sp, pc} */
/* @0x2ac374 movweq pc, #0x4640 */
/* @0x2ac378 blhs 0x3bc3cc <error_g0017+0x15070> */
/* @0x2ac37c ldmibmi pc!, {r1, r8, r12, lr, pc} */
/* @0x2ac380 and r4, r3, r9, ror r4 */
/* @0x2ac384 andle r2, r8, r0, lsr #28 */
/* @0x2ac388 ldrbtmi r4, [r9], #-2493 */
/* @0x2ac38c .word 0xf872f7fa */
/* @0x2ac390 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2ac394 ldc2l p7, c15, [lr], #-1020 */
/* @0x2ac398 ldmdbge r3, {r0, r3, r4, r6, r8, sp, lr, pc} */
/* @0x2ac39c .word 0xf7ff4632 */
/* @0x2ac3a0 qasxmi pc, r0, r5 */
/* @0x2ac3a4 .word 0xf7ff2100 */
/* @0x2ac3a8 stmdahs r0, {r0, r2, r4, r5, r6, r10, r11, r12, sp, lr, pc} */
/* @0x2ac3ac .word 0x814ff040 */
/* @0x2ac3b0 umaalvc pc, sp, sp, r8 */
/* @0x2ac3b4 bvc 0xfede7b38 <b2_toiTime+0xfffffffffe68e694> */
/* @0x2ac3b8 umaallo pc, r12, sp, r8 */
/* @0x2ac3bc .word 0x6051f89d */
/* @0x2ac3c0 .word 0xf89d043f */
/* @0x2ac3c4 bl 0x49c520 <TimingData+0x2508> */
/* @0x2ac3c8 .word 0xf89d6703 */
/* @0x2ac3cc ldrteq r3, [r6], #-79 */
/* @0x2ac3d0 .word 0xb059f89d */
/* @0x2ac3d4 .word 0xf89d441f */
/* @0x2ac3d8 b 0x1678518 <b2_toiTime+0xf1f074> */
/* @0x2ac3dc .word 0xf89d4c0c */
/* @0x2ac3e0 b 0x169455c <b2_toiTime+0xf3b0b8> */
/* @0x2ac3e4 .word 0xf89d4b0b */
/* @0x2ac3e8 bl 0x490574 <g_prim_v+0x568> */
/* @0x2ac3ec .word 0xf89d2703 */
/* @0x2ac3f0 b 0x1678538 <b2_toiTime+0xf1f094> */
/* @0x2ac3f4 .word 0xf89d4a0a */
/* @0x2ac3f8 b 0x168c594 <b2_toiTime+0xf330f0> */
/* @0x2ac3fc cdp p9, #0x0, c4, c7, c9, #0x0 */
/* @0x2ac400 bl 0x44ac48 <g_RomDisk+0x53428> */
/* @0x2ac404 .word 0xf89d6603 */
/* @0x2ac408 b 0x167855c <b2_toiTime+0xf1f0b8> */
/* @0x2ac40c cdp p8, #0xf, c4, c8, c8, #0x0 */
/* @0x2ac410 ldrmi r8, [lr], #-2759 */
/* @0x2ac414 .word 0x3052f89d */
/* @0x2ac418 mlshs r8, sp, r8, pc */
/* @0x2ac41c strhs lr, [r3], -r6, lsl #22 */
/* @0x2ac420 .word 0x3054f89d */
/* @0x2ac424 bvs 0x6e7c48 <g_SWFvertbuff+0x14b80> */
/* @0x2ac428 .word 0x6c03eb0c */
/* @0x2ac42c .word 0x3057f89d */
/* @0x2ac430 blt 0xff4a8018 <b2_toiTime+0xfffffffffed4eb74> */
/* @0x2ac434 .word 0xf89d449c */
/* @0x2ac438 bl 0x5b8598 <g_SWFlineaavertbuff+0x654d0> */
/* @0x2ac43c .word 0xf89d2c03 */
/* @0x2ac440 mcr p0, #0x0, r3, c7, c8, #0x2 */
/* @0x2ac444 bl 0x59ec8c <g_SWFlineaavertbuff+0x4bbc4> */
/* @0x2ac448 .word 0xf89d6b03 */
/* @0x2ac44c mrc p0, #0x5, r3, c8, c11, #0x2 */
/* @0x2ac450 ldrmi r11, [r11], #2759 */
/* @0x2ac454 .word 0x305af89d */
/* @0x2ac458 blhs 0x3a708c <_ZTSPKDn+0x18c4> */
/* @0x2ac45c .word 0x305cf89d */
/* @0x2ac460 blt 0x6e7c84 <g_SWFvertbuff+0x14bbc> */
/* @0x2ac464 bvs 0x3a7094 <_ZTSPKDn+0x18cc> */
/* @0x2ac468 .word 0x305ff89d */
/* @0x2ac46c bge 0xff4a8054 <b2_toiTime+0xfffffffffed4ebb0> */
/* @0x2ac470 .word 0xf89d449a */
/* @0x2ac474 bl 0x5385f4 <obj_numb_event+0x1684> */
/* @0x2ac478 .word 0xf89d2a03 */
/* @0x2ac47c cdp p0, #0x0, c3, c7, c0, #0x3 */
/* @0x2ac480 bl 0x516cc8 <SrcVerts+0x73d0c> */
/* @0x2ac484 .word 0xf89d6903 */
/* @0x2ac488 cdp p0, #0xf, c3, c8, c3, #0x3 */
/* @0x2ac48c ldrmi r9, [r9], #2759 */
/* @0x2ac490 mlslo r2, sp, r8, pc */
/* @0x2ac494 stmdbhs r3, {r0, r3, r8, r9, r11, sp, lr, pc} */
/* @0x2ac498 mlslo r4, sp, r8, pc */
/* @0x2ac49c bls 0x6e7cc0 <g_SWFvertbuff+0x14bf8> */
/* @0x2ac4a0 stmdavs r3, {r3, r8, r9, r11, sp, lr, pc} */
/* @0x2ac4a4 mlslo r7, sp, r8, pc */
/* @0x2ac4a8 bge 0xff4a7f90 <b2_toiTime+0xfffffffffed4eaec> */
/* @0x2ac4ac .word 0xf89d4498 */
/* @0x2ac4b0 bl 0x4b8650 <SrcVerts+0x15694> */
/* @0x2ac4b4 .word 0xf89d2803 */
/* @0x2ac4b8 cdp p0, #0x0, c3, c7, c9, #0x3 */
/* @0x2ac4bc ldreq r8, [r11], #-2576 */
/* @0x2ac4c0 bhi 0xfeca7fe8 <b2_toiTime+0xfffffffffe54eb44> */
/* @0x2ac4c4 movwvs lr, #0x2b03 */
/* @0x2ac4c8 mlshs r11, sp, r8, pc */
/* @0x2ac4cc .word 0xf89d4413 */
/* @0x2ac4d0 bl 0x374680 <_ZTS13C_UTF16String+0xb72c> */
/* @0x2ac4d4 andsls r2, r0, #536870912 */
/* @0x2ac4d8 bls 0xff4a7fc0 <b2_toiTime+0xfffffffffed4eb1c> */
/* @0x2ac4dc bhs 0x6e7d00 <g_SWFvertbuff+0x14c38> */
/* @0x2ac4e0 bhi 0xff4a7fc8 <b2_toiTime+0xfffffffffed4eb24> */
/* @0x2ac4e4 blt 0xfeca8018 <b2_toiTime+0xfffffffffe54eb74> */
/* @0x2ac4e8 blt 0xca7f1c <b2_toiTime+0x54ea78> */
/* @0x2ac4ec bge 0xfeca801c <b2_toiTime+0xfffffffffe54eb78> */
/* @0x2ac4f0 bls 0xfeca801c <b2_toiTime+0xfffffffffe54eb78> */
/* @0x2ac4f4 bge 0xca7f24 <b2_toiTime+0x54ea80> */
/* @0x2ac4f8 bls 0xca7f24 <b2_toiTime+0x54ea80> */
/* @0x2ac4fc bhi 0xca7f24 <b2_toiTime+0x54ea80> */
/* @0x2ac500 rsble r2, r10, r0, lsl #26 */
/* @0x2ac504 ldreq r6, [r11, #-0x8ab] */
/* @0x2ac508 .word 0xf5a7d567 */
/* @0x2ac50c svclo #0x3e47ec */
/* @0x2ac510 svcvs #0xfaf5b7 */
/* @0x2ac514 .word 0xf5a6d82c */
/* @0x2ac518 mrclo p6, #0x0, r4, c12, c9, #0x7 */
/* @0x2ac51c svcvs #0xfaf5b6 */
/* @0x2ac520 .word 0xf5acd826 */
/* @0x2ac524 .word 0xf1ac4c76 */
/* @0x2ac528 .word 0xf5bc0c18 */
/* @0x2ac52c ldmdale pc, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac530 blmi 0x169be4 <_Z22GR_D3D_Screenshot_Partiiii+0xb0> */
/* @0x2ac534 svcvs #0xfaf5bb */
/* @0x2ac538 .word 0xf5aad81a */
/* @0x2ac53c .word 0xf1aa4ae2 */
/* @0x2ac540 .word 0xf5ba0a48 */
/* @0x2ac544 ldmdale r3, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac548 stmdbmi r6!, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2ac54c ldmdbeq r8!, {r0, r3, r5, r7, r8, r12, sp, lr, pc} ^ */
/* @0x2ac550 svcvs #0xfaf5b9 */
/* @0x2ac554 .word 0xf5a8d80c */
/* @0x2ac558 .word 0xf1a8585a */
/* @0x2ac55c .word 0xf5b80830 */
/* @0x2ac560 stmdale r5, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac564 orrspl pc, r12, #679477248 */
/* @0x2ac568 .word 0xf5b33b08 */
/* @0x2ac56c stmdble lr!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} ^ */
/* @0x2ac570 strtmi r4, [r0], -r4, asr #18 */
/* @0x2ac574 .word 0xf7f94479 */
/* @0x2ac578 mrc p15, #0x5, apsr_nzcv, c7, c13, #0x3 */
/* @0x2ac57c stmdami r2, {r3, r5, r6, r7, r9, r11, r12, sp, lr} ^ */
/* @0x2ac580 ldrbtmi r4, [r8], #-2370 */
/* @0x2ac584 .word 0xf1006800 */
/* @0x2ac588 ldrbtmi r0, [r9], #-1192 */
/* @0x2ac58c cdp p6, #0xb, c4, c7, c0, #0x1 */
/* @0x2ac590 .word 0xec531aeb */
/* @0x2ac594 .word 0xeeb72b17 */
/* @0x2ac598 vstr s4, [sp, #812] */
/* @0x2ac59c vmov.f64 d1, #1.000000e+00 */
/* @0x2ac5a0 vstr s6, [sp, #936] */
/* @0x2ac5a4 vstr d2, [sp, #8] */
/* @0x2ac5a8 .word 0xf60a3b04 */
/* @0x2ac5ac mrc p9, #0x5, lr, c7, c12, #0x3 */
/* @0x2ac5b0 ldmdbmi r7!, {r3, r6, r7, r9, r11, r12, sp, lr} */
/* @0x2ac5b4 ldrbtmi r4, [r9], #-1568 */
/* @0x2ac5b8 bpl 0xff56809c <b2_toiTime+0xfffffffffee0ebf8> */
/* @0x2ac5bc blvc 0x3e7bf8 <error_g0017+0x4089c> */
/* @0x2ac5c0 bvs 0xff5280a4 <b2_toiTime+0xfffffffffedcec00> */
/* @0x2ac5c4 blpl 0x2e7c00 <FT_Done_GlyphSlot+0xe6> */
/* @0x2ac5c8 bvc 0xffd280ac <b2_toiTime+0xffffffffff5cec08> */
/* @0x2ac5cc blvs 0x367c08 <_ZTS12CDS_Priority+0x9c60> */
/* @0x2ac5d0 blhs 0x8a7724 <b2_toiTime+0x14e280> */
/* @0x2ac5d4 stmdb r6!, {r1, r3, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2ac5d8 mrc p0, #0x5, lr, c7, c9, #0x1 */
/* @0x2ac5dc strtmi r7, [r0], -r8, asr #21 */
/* @0x2ac5e0 .word 0xf8cd4629 */
/* @0x2ac5e4 mrc p0, #0x5, r12, c7, c12, #0x1 */
/* @0x2ac5e8 vstr s2, [sp, #940] */
/* @0x2ac5ec vmov.f64 d7, #1.750000e+00 */
/* @0x2ac5f0 vstr s4, [sp, #812] */
/* @0x2ac5f4 vmov.f64 d1, #1.000000e+00 */
/* @0x2ac5f8 vstr s6, [sp, #936] */
/* @0x2ac5fc vmov.f64 d2, #1.125000e+00 */
/* @0x2ac600 vstr s8, [sp, #932] */
/* @0x2ac604 vmov.f64 d3, #1.250000e+00 */
/* @0x2ac608 vstr s10, [sp, #808] */
/* @0x2ac60c vmov.f64 d4, #1.375000e+00 */
/* @0x2ac610 vstr s12, [sp, #804] */
/* @0x2ac614 vmov.f64 d5, #1.500000e+00 */
/* @0x2ac618 vstr s14, [sp, #928] */
/* @0x2ac61c .word 0xec536b0a */
/* @0x2ac620 .word 0xf0022b17 */
/* @0x2ac624 ldmdbls r0, {r0, r3, r4, r6, r11, r12, sp, lr, pc} */
/* @0x2ac628 ldrsbtgt pc, [r12], -sp */
/* @0x2ac62c .word 0xf8cd4620 */
/* @0x2ac630 ldrtmi r11, [r10], -r4 */
/* @0x2ac634 ldrtmi r9, [r3], -r5, lsl #2 */
/* @0x2ac638 andgt pc, r0, sp, asr #17 */
/* @0x2ac63c .word 0xf8cd4629 */
/* @0x2ac640 .word 0xf8cda008 */
/* @0x2ac644 .word 0xf8cd900c */
/* @0x2ac648 .word 0xf0028010 */
/* @0x2ac64c ldmdbls r1, {r0, r3, r6, r7, r11, r12, sp, lr, pc} */
/* @0x2ac650 stmdavs r11, {r0, r1, r3, r4, r9, r11, r12, pc} */
/* @0x2ac654 mulle r1, r10, r2 */
/* @0x2ac658 svc #0xbcf609 */
/* @0x2ac65c ldc p0, c11, [sp], #116 */
/* @0x2ac660 pop {r3, r8, r9, r11, pc} */
/* @0x2ac664 svclt #0x8ff0 */
/* @0x2ac668 strbmi r5, [r3, r0] */
/* @0x2ac66c andseq r1, r4, r2, lsr #12 */
/* @0x2ac670 andeq r0, lr, sp, lsr #23 */
/* @0x2ac674 strheq r0, [lr], -r8 */
/* @0x2ac678 andeq r0, lr, r6, asr #23 */
/* @0x2ac67c andeq r0, lr, r7, asr #23 */
/* @0x2ac680 ldrdeq r0, r1, [lr], -r2 */
/* @0x2ac684 andeq r0, lr, r4, lsl #20 */
/* @0x2ac688 andseq r4, r4, r6, asr #29 */
/* @0x2ac68c andeq r0, lr, r6, lsr #20 */
/* @0x2ac690 andeq r0, lr, r6, lsl r10 */
/* @0x2ac694 .word 0x460cb573 */
/* @0x2ac698 .word 0x312cf8d0 */
/* @0x2ac69c ldrmi r4, [r6], -r5, lsl #12 */
/* @0x2ac6a0 strle r0, [r4], #-2009 */
/* @0x2ac6a4 ldrbtmi r4, [r9], #-2385 */
/* @0x2ac6a8 mcr2 p7, #0x6, pc, c0, c9, #0x7 */
/* @0x2ac6ac ldrbeq lr, [r10, -r10] */
/* @0x2ac6b0 stmdbmi pc, {r1, r8, r10, r12, lr, pc} ^ */
/* @0x2ac6b4 ands r4, r1, r9, ror r4 */
/* @0x2ac6b8 strle r0, [r3, #-0x79b] */
/* @0x2ac6bc ldrbtmi r4, [r9], #-2381 */
/* @0x2ac6c0 mrc2 p7, #0x6, apsr_nzcv, c8, c9, #0x7 */
/* @0x2ac6c4 .word 0xb12c4628 */
/* @0x2ac6c8 ldreq r6, [r9, #-0x8a3] */
/* @0x2ac6cc stmdbmi r10, {r1, r8, r10, r12, lr, pc} ^ */
/* @0x2ac6d0 and r4, r3, r9, ror r4 */
/* @0x2ac6d4 andle r2, r8, r1, lsl #28 */
/* @0x2ac6d8 ldrbtmi r4, [r9], #-2376 */
/* @0x2ac6dc mcr2 p7, #0x6, pc, c10, c9, #0x7 */
/* @0x2ac6e0 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x2ac6e4 blx 0xff86a6e8 <b2_toiTime+0xffffffffff111244> */
/* @0x2ac6e8 stmdbge r1, {r0, r2, r3, r4, r5, r6, sp, lr, pc} */
/* @0x2ac6ec .word 0xf7ff4632 */
/* @0x2ac6f0 strtmi pc, [r8], -sp, lsl #21 */
/* @0x2ac6f4 .word 0xf7ff2100 */
/* @0x2ac6f8 stmdahs r0, {r0, r2, r3, r6, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2ac6fc .word 0xf89dd173 */
/* @0x2ac700 cdphs p0, #0x0, c6, c3, c4, #0x0 */
/* @0x2ac704 ldmdbmi lr!, {r0, r2, r8, r10, r11, r12, lr, pc} */
/* @0x2ac708 ldrbtmi r4, [r9], #-1576 */
/* @0x2ac70c mrc2 p7, #0x5, apsr_nzcv, c2, c9, #0x7 */
/* @0x2ac710 .word 0x2c00e069 */
/* @0x2ac714 stmvs r3!, {r0, r1, r3, r4, r6, r12, lr, pc} */
/* @0x2ac718 ldrle r0, [r6, #-0x7da] */
/* @0x2ac71c ldrsbtlo pc, [r12], #132 */
/* @0x2ac720 msrmi CPSR_fsxc, #683671552 */
/* @0x2ac724 .word 0xf5b33bc8 */
/* @0x2ac728 stmdble lr, {r1, r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr} */
/* @0x2ac72c qasxmi r4, r8, r5 */
/* @0x2ac730 .word 0xf7f94479 */
/* @0x2ac734 ldmdami r4!, {r0, r1, r2, r3, r4, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2ac738 ldrbtmi r4, [r8], #-2356 */
/* @0x2ac73c .word 0xf8d56800 */
/* @0x2ac740 adclo r2, r8, r0, ror #5 */
/* @0x2ac744 .word 0xf60a4479 */
/* @0x2ac748 stmvs r3!, {r1, r2, r3, r5, r7, r11, sp, lr, pc} */
/* @0x2ac74c ldrle r0, [lr, #-0x75b]! */
/* @0x2ac750 .word 0x3100f8d4 */
/* @0x2ac754 .word 0x43ecf5a3 */
/* @0x2ac758 .word 0xf5b33b3e */
/* @0x2ac75c ldmdale r12!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac760 .word 0x3104f8d4 */
/* @0x2ac764 .word 0x43f9f5a3 */
/* @0x2ac768 .word 0xf5b33b1c */
/* @0x2ac76c ldmdale r4!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac770 .word 0x3108f8d4 */
/* @0x2ac774 cmnmi r6, #683671552 */
/* @0x2ac778 .word 0xf5b33b18 */
/* @0x2ac77c stmdale r12!, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr} */
/* @0x2ac780 .word 0x310cf8d4 */
/* @0x2ac784 .word 0x43faf5a3 */
/* @0x2ac788 svcvs #0xfaf5b3 */
/* @0x2ac78c .word 0xf8d4d825 */
/* @0x2ac790 .word 0xf5a33110 */
/* @0x2ac794 bllo 0x14bd724 <b2_toiTime+0xd64280> */
/* @0x2ac798 svcvs #0xfaf5b3 */
/* @0x2ac79c .word 0xf8d4d81d */
/* @0x2ac7a0 .word 0xf5a33114 */
/* @0x2ac7a4 bllo 0x20bd544 <b2_toiTime+0x19640a0> */
/* @0x2ac7a8 svcvs #0xfaf5b3 */
/* @0x2ac7ac .word 0xf8d4d815 */
/* @0x2ac7b0 .word 0xf5a33118 */
/* @0x2ac7b4 bllo 0xec1524 <b2_toiTime+0x768080> */
/* @0x2ac7b8 svcvs #0xfaf5b3 */
/* @0x2ac7bc .word 0xf8d4d80d */
/* @0x2ac7c0 .word 0xf5a3311c */
/* @0x2ac7c4 bllo 0x4c163c <SrcVerts+0x1e680> */
/* @0x2ac7c8 svcvs #0xfaf5b3 */
/* @0x2ac7cc strtmi sp, [r8], -r5, lsl #16 */
/* @0x2ac7d0 ldrtmi r4, [r2], -r1, lsr #12 */
/* @0x2ac7d4 blx 0xff0e87e4 <b2_toiTime+0xfffffffffe98f340> */
/* @0x2ac7d8 stmdbmi sp, {r0, r2, sp, lr, pc} */
/* @0x2ac7dc ldrbtmi r4, [r9], #-1576 */
/* @0x2ac7e0 mcr2 p7, #0x2, pc, c8, c9, #0x7 */
/* @0x2ac7e4 strdlt lr, pc, [r2], -r3 */
/* @0x2ac7e8 svclt #0xbd70 */
/* @0x2ac7ec andeq r0, lr, r2, asr #18 */
/* @0x2ac7f0 andeq r0, lr, sp, asr #18 */
/* @0x2ac7f4 andeq r0, lr, r11, asr r9 */
/* @0x2ac7f8 andeq r0, lr, r1, ror #18 */
/* @0x2ac7fc andeq r0, lr, r12, ror #18 */
/* @0x2ac800 andeq r0, lr, r8, asr r9 */
/* @0x2ac804 andeq r0, lr, r7, lsl #14 */
/* @0x2ac808 andseq r4, r4, lr, lsl #26 */
/* @0x2ac80c andeq r0, lr, r2, lsr r9 */
/* @0x2ac810 muleq lr, r10, r7 */
/* @0x2ac814 push {r1, r3, r5, r6, r8, r9, r11, lr} */
/* @0x2ac818 ldrbtmi r4, [r11], #-1008 */
/* @0x2ac81c sadd16mi r6, r5, r11 */
/* @0x2ac820 ldmdavs r10, {r0, r1, r4, r7, r12, sp, pc} */
/* @0x2ac824 strmi r4, [pc], -r4, lsl #12 */
/* @0x2ac828 andsls r4, r1, #152, #12 */
/* @0x2ac82c .word 0x212cf8d0 */
/* @0x2ac830 svceq #0x1f012 */
/* @0x2ac834 stmdbmi r3!, {r2, r8, r12, lr, pc} ^ */
/* @0x2ac838 .word 0xf7f94479 */
/* @0x2ac83c .word 0xe00afdf7 */
/* @0x2ac840 strle r0, [r2, #-0x751] */
/* @0x2ac844 ldrbtmi r4, [r9], #-2400 */
/* @0x2ac848 ldreq lr, [r2, r12] */
/* @0x2ac84c ldmdbmi pc, {r0, r1, r8, r10, r12, lr, pc} ^ */
/* @0x2ac850 .word 0xf7f94479 */
/* @0x2ac854 strtmi pc, [r0], -pc, lsl #28 */
/* @0x2ac858 ldmvs r11!, {r0, r1, r2, r3, r4, r6, r8, r12, sp, pc} */
/* @0x2ac85c strle r0, [r8, #-0x4db] */
/* @0x2ac860 ldrbtmi r4, [r9], #-2395 */
/* @0x2ac864 mcr2 p7, #0x0, pc, c6, c9, #0x7 */
/* @0x2ac868 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2ac86c blx 0x76a870 <b2_toiTime+0x113cc> */
/* @0x2ac870 .word 0xf8d4e09b */
/* @0x2ac874 .word 0xf7fa1330 */
/* @0x2ac878 .word 0x1c69fa41 */
/* @0x2ac87c .word 0xf7fa4620 */
/* @0x2ac880 strtmi pc, [r10], -pc, lsl #20 */
/* @0x2ac884 .word 0xf8c44601 */
/* @0x2ac888 qasxmi r0, r0, r0 */
/* @0x2ac88c rfeib lr! */
/* @0x2ac890 .word 0x21004620 */
/* @0x2ac894 .word 0xf9fef7ff */
/* @0x2ac898 cmnle lr, r0, lsl #16 */
/* @0x2ac89c teqlo r0, #212, #16 */
/* @0x2ac8a0 .word 0xf8d45558 */
/* @0x2ac8a4 .word 0x460a1330 */
/* @0x2ac8a8 andlo r4, r1, #19922944 */
/* @0x2ac8ac stmdahs r0, {r3, r4, r11, r12, sp, lr} */
/* @0x2ac8b0 strdlt sp, lr, [r5, -r10]! */
/* @0x2ac8b4 mcrne p6, #0x3, r4, c10, c0, #0x0 */
/* @0x2ac8b8 addsmi r4, r0, #167772160 */
/* @0x2ac8bc strtmi sp, [r0], -r9, lsl #6 */
/* @0x2ac8c0 blx 0x9ea8b0 <b2_toiTime+0x29140c> */
/* @0x2ac8c4 movwhs r4, #0x943 */
/* @0x2ac8c8 .word 0xf8c44620 */
/* @0x2ac8cc ldrbtmi r3, [r9], #-816 */
/* @0x2ac8d0 ldcne p0, c14, [lr], {88} */
/* @0x2ac8d4 qsublt r7, r11, r3 */
/* @0x2ac8d8 qasxmi r4, r0, pc */
/* @0x2ac8dc .word 0xf7f94479 */
/* @0x2ac8e0 .word 0xf8d4fdc9 */
/* @0x2ac8e4 qasxmi r3, r10, r0 */
/* @0x2ac8e8 .word 0x21004620 */
/* @0x2ac8ec blge 0x3734cc <_ZTS13C_UTF16String+0xa578> */
/* @0x2ac8f0 ldrtmi r9, [r3], -r0, lsl #6 */
/* @0x2ac8f4 blx 0x4ea8f8 <SrcVerts+0x4793c> */
/* @0x2ac8f8 adcmi r9, lr, #3, #26 */
/* @0x2ac8fc blne 0xfee2290c <b2_toiTime+0xfffffffffe6c9468> */
/* @0x2ac900 stmdale r11, {r0, r1, r8, r10, r11, sp} */
/* @0x2ac904 .word 0xf8d44620 */
/* @0x2ac908 .word 0xf7fa1330 */
/* @0x2ac90c ldmdbmi r3!, {r0, r1, r2, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2ac910 strtmi r2, [r0], -r0, lsl #6 */
/* @0x2ac914 teqlo r0, #196, #16 */
/* @0x2ac918 eors r4, r3, r9, ror r4 */
/* @0x2ac91c teqhs r0, #212, #16 */
/* @0x2ac920 ldcpl p9, c1, [r3, #580] */
/* @0x2ac924 mulls r1, r1, r8 */
/* @0x2ac928 stmdbmi r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2ac92c stmdbvs r3, {r0, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2ac930 b 0x150ac64 <b2_toiTime+0xdb17c0> */
/* @0x2ac934 stmvc r11, {r0, r1, r8, r11} */
/* @0x2ac938 stmdbhs r3, {r0, r3, r6, r9, r11, sp, lr, pc} */
/* @0x2ac93c .word 0xd32445a9 */
/* @0x2ac940 ldrmi sp, [r1], -r4, lsr #18 */
/* @0x2ac944 .word 0xf7fa4620 */
/* @0x2ac948 stmdbmi r5!, {r0, r3, r4, r6, r7, r8, r11, r12, sp, lr, pc} */
/* @0x2ac94c strtmi r2, [r0], -r0, lsl #6 */
/* @0x2ac950 teqlo r0, #196, #16 */
/* @0x2ac954 .word 0xf7f94479 */
/* @0x2ac958 cdpge p13, #0x0, c15, c4, c13, #0x4 */
/* @0x2ac95c strbmi r4, [r11], -r1, lsr #20 */
/* @0x2ac960 shasxmi r2, r0, r2 */
/* @0x2ac964 .word 0xf609447a */
/* @0x2ac968 qasxmi lr, r0, r0 */
/* @0x2ac96c .word 0xf7f94631 */
/* @0x2ac970 bmi 0xa2bf7c <b2_toiTime+0x2d2ad8> */
/* @0x2ac974 shasxmi r2, r0, r2 */
/* @0x2ac978 qsub16mi r4, r11, r10 */
/* @0x2ac97c cdp p6, #0x2, c15, c4, c9, #0x0 */
/* @0x2ac980 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2ac984 ldc2l p7, c15, [r6, #-996]! */
/* @0x2ac988 strbmi lr, [sp], -pc */
/* @0x2ac98c eoreq lr, r2, sp, lsl #17 */
/* @0x2ac990 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2ac994 .word 0xf0022300 */
/* @0x2ac998 qsaxmi pc, r0, r7 */
/* @0x2ac99c teqne r0, #212, #16 */
/* @0x2ac9a0 .word 0xf9acf7fa */
/* @0x2ac9a4 .word 0xf8c42300 */
/* @0x2ac9a8 bls 0x6f9670 <g_SWFvertbuff+0x265a8> */
/* @0x2ac9ac .word 0x3000f8d8 */
/* @0x2ac9b0 mulle r1, r10, r2 */
/* @0x2ac9b4 cdp p6, #0x0, c15, c14, c9, #0x0 */
/* @0x2ac9b8 pop {r0, r1, r4, r12, sp, pc} */
/* @0x2ac9bc svclt #0x83f0 */
/* @0x2ac9c0 andseq r1, r4, r10, lsr r1 */
/* @0x2ac9c4 andeq r0, lr, r11, asr r8 */
/* @0x2ac9c8 andeq r0, lr, r6, ror #16 */
/* @0x2ac9cc andeq r0, lr, r4, ror r8 */
/* @0x2ac9d0 andeq r0, lr, r10, ror r8 */
/* @0x2ac9d4 andeq r0, lr, r3, lsr #16 */
/* @0x2ac9d8 andeq r0, lr, r10, lsr #16 */
/* @0x2ac9dc andeq r0, lr, lr, lsl r8 */
/* @0x2ac9e0 andeq r0, lr, sp, lsl #16 */
/* @0x2ac9e4 andeq r0, lr, sp, lsl r8 */
/* @0x2ac9e8 andeq r0, lr, r5, lsr #16 */
/* @0x2ac9ec svcmi #0xf0e92d */
/* @0x2ac9f0 .word 0xf8d04604 */
/* @0x2ac9f4 addlt r3, r5, r0, lsl r3 */
/* @0x2ac9f8 ldrmi r4, [r6], -r8, lsl #13 */
/* @0x2ac9fc blhs 0x318ff0 <__aeabi_dadd+0x1d8> */
/* @0x2aca00 bllo 0x320a2c */
/* @0x2aca04 tstlo r0, #192, #16 */
/* @0x2aca08 .word 0xd1082b01 */
/* @0x2aca0c ldrbtmi r4, [r9], #-2416 */
/* @0x2aca10 ldc2 p7, c15, [r0, #-996]! */
/* @0x2aca14 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2aca18 rfedb r12! */
/* @0x2aca1c .word 0xf8d4e0d2 */
/* @0x2aca20 ldrbeq r3, [r10, r12, lsr #2] */
/* @0x2aca24 stmdbmi r11!, {r0, r2, r10, r12, lr, pc} ^ */
/* @0x2aca28 ldrbtmi r4, [r9], #-1568 */
/* @0x2aca2c ldc2l p7, c15, [lr], #996 */
/* @0x2aca30 ldrbeq lr, [r11, -r5] */
/* @0x2aca34 stmdbmi r8!, {r0, r1, r8, r10, r12, lr, pc} ^ */
/* @0x2aca38 ldrbtmi r4, [r9], #-1568 */
/* @0x2aca3c strtmi lr, [r0], -r8, ror #15 */
/* @0x2aca40 teqne r0, #212, #16 */
/* @0x2aca44 .word 0xf95af7fa */
/* @0x2aca48 qsub16mi r1, r0, r1 */
/* @0x2aca4c .word 0xf928f7fa */
/* @0x2aca50 .word 0x46014632 */
/* @0x2aca54 teqeq r0, #196, #16 */
/* @0x2aca58 .word 0xf7ff4620 */
/* @0x2aca5c .word 0x4620f8d7 */
/* @0x2aca60 .word 0xf7ff2100 */
/* @0x2aca64 .word 0xb140f917 */
/* @0x2aca68 .word 0xf8d44620 */
/* @0x2aca6c .word 0xf7fa1330 */
/* @0x2aca70 movwhs pc, #0x945 */
/* @0x2aca74 teqlo r0, #196, #16 */
/* @0x2aca78 .word 0xf8d4e0a4 */
/* @0x2aca7c ldrpl r3, [r8, #0x330] */
/* @0x2aca80 teqvc r0, #212, #16 */
/* @0x2aca84 sasxmi r4, r3, r10 */
/* @0x2aca88 .word 0xf8933201 */
/* @0x2aca8c .word 0xf1b99000 */
/* @0x2aca90 mvnsle r0, r0, lsl #30 */
/* @0x2aca94 ldrmi r2, [r1], -r1, lsl #28 */
/* @0x2aca98 cdpne p9, #0xb, c13, c2, c3, #0x0 */
/* @0x2aca9c addsmi r4, r1, #973078528 */
/* @0x2acaa0 strtmi sp, [r0], -r10, lsl #18 */
/* @0x2acaa4 .word 0xf7fa4639 */
/* @0x2acaa8 stmdbmi r12, {r0, r3, r5, r8, r11, r12, sp, lr, pc} ^ */
/* @0x2acaac strtmi r2, [r0], -r0, lsl #6 */
/* @0x2acab0 teqlo r0, #196, #16 */
/* @0x2acab4 eors r4, r7, r9, ror r4 */
/* @0x2acab8 mulge r1, r3, r8 */
/* @0x2acabc bl 0xff3f3d38 <b2_toiTime+0xfffffffffec9a894> */
/* @0x2acac0 ldrtmi r0, [r3], #2823 */
/* @0x2acac4 andge pc, r4, sp, lsl #17 */
/* @0x2acac8 svceq #0x8f1ba */
/* @0x2acacc .word 0xf04fbf14 */
/* @0x2acad0 .word 0xf04f0a0a */
/* @0x2acad4 ldrbmi r0, [r8], -r6, lsl #20 */
/* @0x2acad8 .word 0xf06c4651 */
/* @0x2acadc strmi lr, [lr], -r8, lsl #19 */
/* @0x2acae0 strtmi r11, [r0], -r9, asr #2 */
/* @0x2acae4 .word 0xf7fa4639 */
/* @0x2acae8 ldmdbmi sp!, {r0, r3, r8, r11, r12, sp, lr, pc} */
/* @0x2acaec teqls r0, #196, #16 */
/* @0x2acaf0 ldrbtmi r4, [r9], #-1568 */
/* @0x2acaf4 uadd16mi lr, r1, r8 */
/* @0x2acaf8 .word 0xf06c4658 */
/* @0x2acafc bmi 0xfa6f2c <b2_toiTime+0x84da88> */
/* @0x2acb00 .word 0x46014290 */
/* @0x2acb04 stmdble r3, {r0, r1, r12, pc} */
/* @0x2acb08 qasxmi r4, r0, r6 */
/* @0x2acb0c and r4, r11, r9, ror r4 */
/* @0x2acb10 strtmi r2, [r0], -r10, lsl #14 */
/* @0x2acb14 .word 0xf7fa4379 */
/* @0x2acb18 .word 0x9002f8fe */
/* @0x2acb1c ldrtmi r11, [r2], -r8, lsl #2 */
/* @0x2acb20 ldmdbmi r1!, {r1, r2, r3, r4, sp, lr, pc} */
/* @0x2acb24 ldrbtmi r4, [r9], #-1568 */
/* @0x2acb28 stc2 p7, c15, [r4], #996 */
/* @0x2acb2c .word 0xf89de04a */
/* @0x2acb30 blx 0x484b4a <g_AccelX+0x8e> */
/* @0x2acb34 stmdals r2, {r1, r8, r12, sp, lr, pc} */
/* @0x2acb38 stmdavc lr!, {r3, r9, r10, r11, sp} */
/* @0x2acb3c movweq lr, #0x1b00 */
/* @0x2acb40 subpl sp, r6, #-2147483644 */
/* @0x2acb44 stmdavc r9!, {r3, r5, r8, r10, r11, r12} ^ */
/* @0x2acb48 stmvc r9!, {r0, r3, r4, r6, pc} */
/* @0x2acb4c stmvc r9!, {r0, r3, r4, r7, pc} ^ */
/* @0x2acb50 stmdavc r5, {r0, r3, r4, r6, r7, pc} */
/* @0x2acb54 stmdavc r1, {r0, r9, r12, sp} ^ */
/* @0x2acb58 .word 0x2105eb01 */
/* @0x2acb5c tsthi r9, r5, lsl #25 */
/* @0x2acb60 addsmi r9, r10, #3072 */
/* @0x2acb64 ands sp, r6, r3, ror #23 */
/* @0x2acb68 mul r1, r5, r8 */
/* @0x2acb6c strhs lr, [r6], -lr, lsl #22 */
/* @0x2acb70 stmvc r8!, {r1, r2, r6, r9, r12, lr} */
/* @0x2acb74 bl 0x30af20 <af_shaper_get_elem+0x78e> */
/* @0x2acb78 subshi r2, r9, r0, lsl #2 */
/* @0x2acb7c stmdbvc r9!, {r3, r5, r8, r11, r12, sp, lr} ^ */
/* @0x2acb80 .word 0x2100eb01 */
/* @0x2acb84 stmibvc r8!, {r0, r3, r4, r7, pc} */
/* @0x2acb88 bl 0x30b334 <af_shaper_get_elem+0xba2> */
/* @0x2acb8c .word 0xf1052100 */
/* @0x2acb90 sbcshi r0, r9, r8 */
/* @0x2acb94 .word 0xf8d4e7dd */
/* @0x2acb98 bge 0x3b9860 <error_g0017+0x12504> */
/* @0x2acb9c strbmi r4, [r1], -r0, lsr #12 */
/* @0x2acba0 ldclo p8, c15, [r0, #-264] */
/* @0x2acba4 strbtmi r2, [r10], -r1, lsl #6 */
/* @0x2acba8 blx 0xee8bba <b2_toiTime+0x78f716> */
/* @0x2acbac .word 0xf8d44620 */
/* @0x2acbb0 .word 0xf7fa1330 */
/* @0x2acbb4 movwhs pc, #0x8a3 */
/* @0x2acbb8 .word 0xf8c44620 */
/* @0x2acbbc stmdbls r2, {r4, r5, r8, r9, r12, sp} */
/* @0x2acbc0 .word 0xf89cf7fa */
/* @0x2acbc4 pop {r0, r2, r12, sp, pc} */
/* @0x2acbc8 svclt #0x8ff0 */
/* @0x2acbcc ldmibne r9, {r0, r3, r4, r7, r8, r11, r12, pc} */
/* @0x2acbd0 andeq r0, lr, r11, lsr #15 */
/* @0x2acbd4 strheq r0, [lr], -r0 */
/* @0x2acbd8 strheq r0, [lr], -r9 */
/* @0x2acbdc andeq r0, lr, r7, asr r7 */
/* @0x2acbe0 andeq r0, lr, lr, lsr #14 */
/* @0x2acbe4 andeq r0, lr, lr, lsr #14 */
/* @0x2acbe8 andeq r0, lr, r8, lsr #14 */
/* @0x2acbec push {r1, r4, r6, r8, r9, r11, lr} */
/* @0x2acbf0 ldrbtmi r4, [r11], #-496 */
/* @0x2acbf4 sadd16mi r6, r5, r11 */
/* @0x2acbf8 ldmdavs r10, {r1, r2, r6, r7, r12, sp, pc} */
/* @0x2acbfc strmi r4, [pc], -r4, lsl #12 */
/* @0x2acc00 subls r4, r5, #152, #12 */
/* @0x2acc04 .word 0x212cf8d0 */
/* @0x2acc08 svceq #0x1f012 */
/* @0x2acc0c stmdbmi r11, {r2, r8, r12, lr, pc} ^ */
/* @0x2acc10 .word 0xf7f94479 */
/* @0x2acc14 and pc, r11, r11, lsl #24 */
/* @0x2acc18 strle r0, [r2, #-0x751] */
/* @0x2acc1c ldrbtmi r4, [r9], #-2376 */
/* @0x2acc20 .word 0xb12fe065 */
/* @0x2acc24 .word 0x06da68bb */
/* @0x2acc28 stmdbmi r6, {r1, r8, r10, r12, lr, pc} ^ */
/* @0x2acc2c subs r4, lr, r9, ror r4 */
/* @0x2acc30 .word 0x21eaf894 */
/* @0x2acc34 stchs p9, c11, [r2, #-648] */
/* @0x2acc38 andle r4, r2, r0, lsr #12 */
/* @0x2acc3c ldrbtmi r4, [r9], #-2370 */
/* @0x2acc40 mcrge p0, #0x0, lr, c3, c5, #0x2 */
/* @0x2acc44 ldrtmi r4, [r1], -r10, lsr #12 */
/* @0x2acc48 .word 0xffe0f7fe */
/* @0x2acc4c movwhs r7, #0x1832 */
/* @0x2acc50 bicslo pc, lr, r4, lsr #17 */
/* @0x2acc54 bl 0x38ae28 <bigtens_D2A+0x12f8> */
/* @0x2acc58 .word 0xf8a42302 */
/* @0x2acc5c sub r3, sp, r8, asr r2 */
/* @0x2acc60 .word 0xd1202a02 */
/* @0x2acc64 strtmi r2, [r0], -r6, lsl #26 */
/* @0x2acc68 ldmdbmi r8!, {r1, r12, lr, pc} */
/* @0x2acc6c eors r4, lr, r9, ror r4 */
/* @0x2acc70 strtmi r10, [r10], -r3, lsl #28 */
/* @0x2acc74 .word 0xf7fe4631 */
/* @0x2acc78 ldmdavc r2!, {r0, r3, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2acc7c .word 0xf8a42301 */
/* @0x2acc80 ldmdavc r3!, {r1, r2, r3, r4, r6, r7, r8, r12, sp} ^ */
/* @0x2acc84 movwhs lr, #0x2b03 */
/* @0x2acc88 .word 0xf8a478b2 */
/* @0x2acc8c ldmvc r3!, {r1, r4, r6, r9, r12, sp} ^ */
/* @0x2acc90 movwhs lr, #0x2b03 */
/* @0x2acc94 .word 0xf8a47932 */
/* @0x2acc98 ldmdbvc r3!, {r2, r4, r6, r9, r12, sp} ^ */
/* @0x2acc9c movwhs lr, #0x2b03 */
/* @0x2acca0 subslo pc, r6, #164, #16 */
/* @0x2acca4 bhs 0x3a4d54 <af_blue_strings+0x2a30> */
/* @0x2acca8 .word 0xf8d4d11e */
/* @0x2accac ldreq r3, [r11, r12, lsr #2] */
/* @0x2accb0 stmdbmi r7!, {r2, r10, r12, lr, pc} */
/* @0x2accb4 ldrbtmi r4, [r9], #-1568 */
/* @0x2accb8 blx 0xff9eaca6 <b2_toiTime+0xffffffffff291802> */
/* @0x2accbc ldrhlo pc, [r12, #132] */
/* @0x2accc0 addsmi r4, sp, #32, #12 */
/* @0x2accc4 .word 0xf5b5d802 */
/* @0x2accc8 stmdble r2, {r7, r8, r9, r10, r11, r12, sp, lr} */
/* @0x2acccc ldrbtmi r4, [r9], #-2337 */
/* @0x2accd0 ldmdblt r5, {r0, r2, r3, sp, lr, pc} */
/* @0x2accd4 ldrbtmi r4, [r9], #-2336 */
/* @0x2accd8 stmdbge r5, {r0, r3, sp, lr, pc} */
/* @0x2accdc .word 0xf7fe462a */
/* @0x2acce0 .word 0xf8a4ff95 */
/* @0x2acce4 ldrd r5, r6, [r9], -lr */
/* @0x2acce8 qadd16mi r4, r0, r12 */
/* @0x2accec .word 0xf7f94479 */
/* @0x2accf0 strtmi pc, [r0], -r1, asr #23 */
/* @0x2accf4 .word 0xf7fe4629 */
/* @0x2accf8 ands pc, r2, sp, asr #31 */
/* @0x2accfc .word 0x21004620 */
/* @0x2acd00 .word 0xffc8f7fe */
/* @0x2acd04 movwhs r11, #0x118 */
/* @0x2acd08 bicslo pc, lr, r4, lsr #17 */
/* @0x2acd0c .word 0xf504e009 */
/* @0x2acd10 rfeia r4! */
/* @0x2acd14 andls r3, r0, #-2147483593 */
/* @0x2acd18 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2acd1c .word 0xf002aa05 */
/* @0x2acd20 bls 0x142b57c <b2_toiTime+0xcd20d8> */
/* @0x2acd24 .word 0x3000f8d8 */
/* @0x2acd28 mulle r1, r10, r2 */
/* @0x2acd2c mrrc p6, #0x0, pc, r2, c9 */
/* @0x2acd30 pop {r1, r2, r6, r12, sp, pc} */
/* @0x2acd34 svclt #0x81f0 */
/* @0x2acd38 andseq r0, r4, r2, ror #26 */
/* @0x2acd3c andeq r0, lr, r2, ror #12 */
/* @0x2acd40 andeq r0, lr, sp, ror #12 */
/* @0x2acd44 andeq r0, lr, r7, ror r6 */
/* @0x2acd48 andeq r0, lr, r10, ror r6 */
/* @0x2acd4c andeq r0, lr, r12, asr #12 */
/* @0x2acd50 andeq r0, lr, lr, lsl r6 */
/* @0x2acd54 andeq r0, lr, r10, ror #11 */
/* @0x2acd58 andeq r0, lr, r7, lsl r6 */
/* @0x2acd5c andeq r0, lr, r8, lsl r6 */
/* @0x2acd60 ssub16mi r11, r5, r3 */
/* @0x2acd64 .word 0x312cf8d0 */
/* @0x2acd68 strmi r4, [lr], -r4, lsl #12 */
/* @0x2acd6c strle r0, [r4], #-2010 */
/* @0x2acd70 ldrbtmi r4, [r9], #-2371 */
/* @0x2acd74 blx 0x196ad62 <b2_toiTime+0x12118be> */
/* @0x2acd78 smmlaeq r9, r5, r0, lr */
/* @0x2acd7c stmdbmi r1, {r1, r8, r10, r12, lr, pc} ^ */
/* @0x2acd80 eor r4, r0, r9, ror r4 */
/* @0x2acd84 .word 0x21eaf890 */
/* @0x2acd88 .word 0xd1042a03 */
/* @0x2acd8c strle r0, [r2], #-1946 */
/* @0x2acd90 ldrbtmi r4, [r9], #-2365 */
/* @0x2acd94 teqlt r6, r7, lsl r0 */
/* @0x2acd98 .word 0x069b68b3 */
/* @0x2acd9c ldmdbmi r11!, {r0, r1, r8, r10, r12, lr, pc} */
/* @0x2acda0 ldrbtmi r4, [r9], #-1568 */
/* @0x2acda4 .word 0xf894e00f */
/* @0x2acda8 blhs 0x379558 <_ZTS13C_UTF16String+0x10604> */
/* @0x2acdac .word 0xf013d005 */
/* @0x2acdb0 svclt #0xc0f02 */
/* @0x2acdb4 movwhs r2, #0x6302 */
/* @0x2acdb8 movwhs lr, #0x1000 */
/* @0x2acdbc qadd8mi r4, r0, sp */
/* @0x2acdc0 ldmdbmi r3!, {r3, r12, lr, pc} */
/* @0x2acdc4 .word 0xf7f94479 */
/* @0x2acdc8 qsaxmi pc, r0, r5 */
/* @0x2acdcc .word 0xf7fe4629 */
/* @0x2acdd0 subs pc, r3, r1, ror #30 */
/* @0x2acdd4 strtmi r4, [r10], -r9, ror #12 */
/* @0x2acdd8 .word 0xff18f7fe */
/* @0x2acddc .word 0x21004620 */
/* @0x2acde0 .word 0xff58f7fe */
/* @0x2acde4 mrsle r2, spsr */
/* @0x2acde8 .word 0x21eaf894 */
/* @0x2acdec mullo r0, sp, r8 */
/* @0x2acdf0 tstle r10, r3, lsl #20 */
/* @0x2acdf4 mvnslo pc, r4, lsl #17 */
/* @0x2acdf8 eorsle r2, r9, r0, lsl #28 */
/* @0x2acdfc .word 0xb3ba8ab2 */
/* @0x2ace00 movwle r4, #0x5293 */
/* @0x2ace04 strtmi r4, [r0], -r3, lsr #18 */
/* @0x2ace08 .word 0xf7f94479 */
/* @0x2ace0c eors pc, r5, r3, lsr r11 */
/* @0x2ace10 ldrsbne pc, [r8, #132] */
/* @0x2ace14 movteq lr, #0x3b03 */
/* @0x2ace18 stclpl p8, c1, [r11], {202} */
/* @0x2ace1c mvnslo pc, r4, lsr #17 */
/* @0x2ace20 .word 0xf8a47853 */
/* @0x2ace24 ldmvc r3, {r9, r12, sp} */
/* @0x2ace28 .word 0xf012e020 */
/* @0x2ace2c .word 0xf89d0f02 */
/* @0x2ace30 bl 0x334e3c */
/* @0x2ace34 .word 0xd1092303 */
/* @0x2ace38 .word 0xf8a4b29b */
/* @0x2ace3c .word 0xf8a43204 */
/* @0x2ace40 .word 0xf8a43202 */
/* @0x2ace44 .word 0xf8a43200 */
/* @0x2ace48 ldrsh r3, [r1], -lr */
/* @0x2ace4c mulhs r2, sp, r8 */
/* @0x2ace50 mvnslo pc, r4, lsr #17 */
/* @0x2ace54 mullo r3, sp, r8 */
/* @0x2ace58 movwhs lr, #0x2b03 */
/* @0x2ace5c mulhs r4, sp, r8 */
/* @0x2ace60 andlo pc, r0, #164, #16 */
/* @0x2ace64 mullo r5, sp, r8 */
/* @0x2ace68 movwhs lr, #0x2b03 */
/* @0x2ace6c andlo pc, r2, #164, #16 */
/* @0x2ace70 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2ace74 rscsvc pc, lr, #4, #10 */
/* @0x2ace78 .word 0xfc1cf001 */
/* @0x2ace7c ldcllt p0, c11, [r0, #-8]! */
/* @0x2ace80 strheq r0, [lr], -r12 */
/* @0x2ace84 andeq r0, lr, r7, asr #11 */
/* @0x2ace88 andeq r0, lr, sp, asr #11 */
/* @0x2ace8c ldrdeq r0, r1, [lr], -r6 */
/* @0x2ace90 andeq r0, lr, r9, asr #11 */
/* @0x2ace94 andeq r0, lr, r1, lsr #11 */
/* @0x2ace98 mvnsmi lr, #737280 */
/* @0x2ace9c .word 0xf8d04604 */
/* @0x2acea0 .word 0xf5ad312c */
/* @0x2acea4 strmi r7, [pc], -r3, lsl #26 */
/* @0x2acea8 bfieq r4, r5, #12, #19 */
/* @0x2aceac stmdbmi r5!, {r2, r10, r12, lr, pc} */
/* @0x2aceb0 .word 0xf7f94479 */
/* @0x2aceb4 ldrh pc, [r6], -r11 */
/* @0x2aceb8 strle r0, [r2, #-0x759] */
/* @0x2acebc ldrbtmi r4, [r9], #-2338 */
/* @0x2acec0 ldreq lr, [r10, r3] */
/* @0x2acec4 stmdbmi r1!, {r3, r10, r12, lr, pc} */
/* @0x2acec8 .word 0xf7f94479 */
/* @0x2acecc .word 0x4620fad3 */
/* @0x2aced0 .word 0xf7fe4629 */
/* @0x2aced4 ldrsbt pc, [r0], -pc */
/* @0x2aced8 ldmvs r11!, {r0, r1, r2, r3, r5, r8, r12, sp, pc} */
/* @0x2acedc strle r0, [r2, #-0x65b] */
/* @0x2acee0 ldrbtmi r4, [r9], #-2331 */
/* @0x2acee4 .word 0xf5b5e7f1 */
/* @0x2acee8 stmdale r4, {r8, r9, r10, r11, r12, sp, lr} */
/* @0x2aceec ldrhlo pc, [r12, #132] */
/* @0x2acef0 svceq #0x43ebb5 */
/* @0x2acef4 ldmdbmi r7, {r0, r1, r12, lr, pc} */
/* @0x2acef8 ldrbtmi r4, [r9], #-1568 */
/* @0x2acefc b 0x16a6e98 <b2_toiTime+0xf4d9f4> */
/* @0x2acf00 .word 0xf10d0955 */
/* @0x2acf04 stcge p8, c0, [r1, #-32] */
/* @0x2acf08 strbmi r2, [lr, #-0x600] */
/* @0x2acf0c andle r4, r11, r0, lsr #12 */
/* @0x2acf10 strtmi r2, [r9], -r2, lsl #4 */
/* @0x2acf14 mrc2 p7, #0x3, apsr_nzcv, c10, c14, #0x7 */
/* @0x2acf18 stmdavc r11!, {r1, r3, r5, r11, r12, sp, lr} ^ */
/* @0x2acf1c movwhs lr, #0x2b03 */
/* @0x2acf20 andslo pc, r6, r8, lsr #16 */
/* @0x2acf24 ldrb r3, [r0, r1, lsl #12]! */
/* @0x2acf28 .word 0xf7fe2100 */
/* @0x2acf2c stmdblt r0!, {r0, r1, r4, r5, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x2acf30 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2acf34 .word 0xf001aa02 */
/* @0x2acf38 .word 0xf50dfd67 */
/* @0x2acf3c pop {r0, r1, r8, r10, r11, r12, sp, lr} */
/* @0x2acf40 svclt #0x83f0 */
/* @0x2acf44 andeq r0, lr, r10, lsl r5 */
/* @0x2acf48 andeq r0, lr, r5, lsr #10 */
/* @0x2acf4c andeq r0, lr, r3, lsr r5 */
/* @0x2acf50 andeq r0, lr, r2, lsr r5 */
/* @0x2acf54 andeq r0, lr, pc, lsr #10 */
/* @0x2acf58 ldrblt r4, [r0, #0xb30]! */
/* @0x2acf5c ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2acf60 addlt r4, r7, r5, lsl r6 */
/* @0x2acf64 .word 0x4604681a */
/* @0x2acf68 ldrmi r4, [pc], -lr, lsl #12 */
/* @0x2acf6c .word 0xf8d09205 */
/* @0x2acf70 .word 0xf012212c */
/* @0x2acf74 .word 0xd1040f01 */
/* @0x2acf78 ldrbtmi r4, [r9], #-2345 */
/* @0x2acf7c blx 0x186af68 <b2_toiTime+0x1111ac4> */
/* @0x2acf80 smmlaeq r2, r1, r0, lr */
/* @0x2acf84 stmdbmi r7!, {r1, r8, r10, r12, lr, pc} */
/* @0x2acf88 and r4, r5, r9, ror r4 */
/* @0x2acf8c stmvs r10, {r0, r3, r4, r6, r8, r12, sp, pc} */
/* @0x2acf90 strle r0, [r8, #-0x613] */
/* @0x2acf94 ldrbtmi r4, [r9], #-2340 */
/* @0x2acf98 blx 0x1deaf84 <b2_toiTime+0x1691ae0> */
/* @0x2acf9c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2acfa0 mrc2 p7, #0x3, apsr_nzcv, c8, c14, #0x7 */
/* @0x2acfa4 stchs p0, c14, [r9, #-196] */
/* @0x2acfa8 andle r4, r2, r0, lsr #12 */
/* @0x2acfac ldrbtmi r4, [r9], #-2335 */
/* @0x2acfb0 stmdbge r2, {r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2acfb4 .word 0xf7fe462a */
/* @0x2acfb8 strtmi pc, [r0], -r9, lsr #28 */
/* @0x2acfbc .word 0xf7fe2100 */
/* @0x2acfc0 bllt 0x6ec96c <g_SWFvertbuff+0x198a4> */
/* @0x2acfc4 mulhs r9, sp, r8 */
/* @0x2acfc8 .word 0xf89d4620 */
/* @0x2acfcc .word 0xf89d3008 */
/* @0x2acfd0 ldreq r1, [r2], #-12 */
/* @0x2acfd4 mul r10, sp, r8 */
/* @0x2acfd8 andvs lr, r3, #2048 */
/* @0x2acfdc mullo r11, sp, r8 */
/* @0x2acfe0 mulpl lr, sp, r8 */
/* @0x2acfe4 .word 0xf89d441a */
/* @0x2acfe8 bl 0x339024 */
/* @0x2acfec ldreq r2, [r11], #-526 */
/* @0x2acff0 movwvs lr, #0x1b03 */
/* @0x2acff4 mulne pc, sp, r8 */
/* @0x2acff8 .word 0xf89d440b */
/* @0x2acffc bl 0x371044 <_ZTS13C_UTF16String+0x80f0> */
/* @0x2ad000 .word 0x91002305 */
/* @0x2ad004 .word 0xf0014631 */
/* @0x2ad008 bls 0x42c8d0 <g_RomDisk+0x350b0> */
/* @0x2ad00c addsmi r6, r10, #3866624 */
/* @0x2ad010 .word 0xf609d001 */
/* @0x2ad014 andlt lr, r7, r0, ror #21 */
/* @0x2ad018 svclt #0xbdf0 */
/* @0x2ad01c ldrsheq r0, [r4], -r8 */
/* @0x2ad020 andeq r0, lr, r11, asr #9 */
/* @0x2ad024 ldrdeq r0, r1, [lr], -r6 */
/* @0x2ad028 andeq r0, lr, r0, ror #9 */
/* @0x2ad02c ldrdeq r0, r1, [lr], -sp */
/* @0x2ad030 ldrblt r4, [r0, #0xb38]! */
/* @0x2ad034 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2ad038 addlt r4, r7, r5, lsl r6 */
/* @0x2ad03c .word 0x4604681a */
/* @0x2ad040 ldrmi r4, [pc], -lr, lsl #12 */
/* @0x2ad044 .word 0xf8d09205 */
/* @0x2ad048 .word 0xf012212c */
/* @0x2ad04c .word 0xd1040f01 */
/* @0x2ad050 ldrbtmi r4, [r9], #-2353 */
/* @0x2ad054 .word 0xf9eaf7f9 */
/* @0x2ad058 smmlaeq r2, r1, r0, lr */
/* @0x2ad05c stmdbmi pc!, {r1, r8, r10, r12, lr, pc} */
/* @0x2ad060 and r4, r5, r9, ror r4 */
/* @0x2ad064 stmvs r11, {r0, r3, r4, r6, r8, r12, sp, pc} */
/* @0x2ad068 strle r0, [r8, #-0x5db] */
/* @0x2ad06c ldrbtmi r4, [r9], #-2348 */
/* @0x2ad070 blx 0x2eb05c <FT_Done_Memory+0x13e8> */
/* @0x2ad074 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2ad078 mcr2 p7, #0x0, pc, c12, c14, #0x7 */
/* @0x2ad07c stchs p0, c14, [r9, #-260] */
/* @0x2ad080 andle r4, r2, r0, lsr #12 */
/* @0x2ad084 ldrbtmi r4, [r9], #-2343 */
/* @0x2ad088 stmdbge r2, {r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2ad08c .word 0xf7fe462a */
/* @0x2ad090 .word 0x4620fdbd */
/* @0x2ad094 .word 0xf7fe2100 */
/* @0x2ad098 bllt 0xfe6ec894 <b2_toiTime+0xfffffffffdf933f0> */
/* @0x2ad09c mulhs r8, sp, r8 */
/* @0x2ad0a0 muleq r9, sp, r8 */
/* @0x2ad0a4 svceq #0x80f012 */
/* @0x2ad0a8 mulne r11, sp, r8 */
/* @0x2ad0ac andvs lr, r2, #323584 */
/* @0x2ad0b0 mullo r10, sp, r8 */
/* @0x2ad0b4 andmi lr, r0, #2048 */
/* @0x2ad0b8 bl 0x33e0e8 */
/* @0x2ad0bc andle r2, r3, r3, lsl #4 */
/* @0x2ad0c0 .word 0xf0224252 */
/* @0x2ad0c4 subsmi r4, r2, #0, #4 */
/* @0x2ad0c8 mullo r12, sp, r8 */
/* @0x2ad0cc mulpl sp, sp, r8 */
/* @0x2ad0d0 svceq #0x80f013 */
/* @0x2ad0d4 muleq pc, sp, r8 */
/* @0x2ad0d8 movwvs lr, #0x3a4f */
/* @0x2ad0dc mulne lr, sp, r8 */
/* @0x2ad0e0 movwmi lr, #0x5b03 */
/* @0x2ad0e4 bl 0x37e0f8 <_ZTS13C_UTF16String+0x151a4> */
/* @0x2ad0e8 andle r2, r3, r1, lsl #6 */
/* @0x2ad0ec .word 0xf023425b */
/* @0x2ad0f0 subsmi r4, r11, #0, #6 */
/* @0x2ad0f4 mulsne r0, sp, r8 */
/* @0x2ad0f8 .word 0x91004620 */
/* @0x2ad0fc .word 0xf0014631 */
/* @0x2ad100 bls 0x42c518 <g_RomDisk+0x34cf8> */
/* @0x2ad104 addsmi r6, r10, #3866624 */
/* @0x2ad108 .word 0xf609d001 */
/* @0x2ad10c andlt lr, r7, r4, ror #20 */
/* @0x2ad110 svclt #0xbdf0 */
/* @0x2ad114 andseq r0, r4, r0, lsr #18 */
/* @0x2ad118 andeq r0, lr, r5, asr r4 */
/* @0x2ad11c andeq r0, lr, r0, ror #8 */
/* @0x2ad120 andeq r0, lr, r10, ror #8 */
/* @0x2ad124 andeq r0, lr, r7, ror #8 */
/* @0x2ad128 svcmi #0xf0e92d */
/* @0x2ad12c .word 0xf8d04688 */
/* @0x2ad130 addlt r3, r11, r12, lsr #2 */
/* @0x2ad134 ldrmi r4, [r6], -r4, lsl #12 */
/* @0x2ad138 strle r0, [r4], #-2009 */
/* @0x2ad13c ldrbtmi r4, [r9], #-2427 */
/* @0x2ad140 .word 0xf974f7f9 */
/* @0x2ad144 smmlaeq r10, r6, r0, lr */
/* @0x2ad148 ldmdbmi r9!, {r1, r8, r10, r12, lr, pc} ^ */
/* @0x2ad14c and r4, r8, r9, ror r4 */
/* @0x2ad150 svceq #0xf1b8 */
/* @0x2ad154 .word 0xf8d8d00e */
/* @0x2ad158 ldrbeq r3, [r11, #-0x8] */
/* @0x2ad15c ldmdbmi r5!, {r1, r3, r8, r10, r12, lr, pc} ^ */
/* @0x2ad160 .word 0xf7f94479 */
/* @0x2ad164 strtmi pc, [r0], -r7, lsl #19 */
/* @0x2ad168 andlt r4, r11, r1, lsr r6 */
/* @0x2ad16c svcmi #0xf0e8bd */
/* @0x2ad170 ldclt p7, c15, [r0, #1016] */
/* @0x2ad174 .word 0xf8d44620 */
/* @0x2ad178 .word 0xf7f91330 */
/* @0x2ad17c ldclne p13, c15, [r1], #-764 */
/* @0x2ad180 .word 0xf7f94620 */
/* @0x2ad184 strmi pc, [r1], -r8, asr #27 */
/* @0x2ad188 teqeq r0, #196, #16 */
/* @0x2ad18c ldmdblt r1, {r5, r9, r10, lr} */
/* @0x2ad190 ldrbtmi r4, [r9], #-2409 */
/* @0x2ad194 shadd8mi lr, r2, r5 */
/* @0x2ad198 ldc2 p7, c15, [r8, #-1016]! */
/* @0x2ad19c .word 0x21004620 */
/* @0x2ad1a0 ldc2l p7, c15, [r8, #-1016]! */
/* @0x2ad1a4 cmple pc, r0, lsl #16 */
/* @0x2ad1a8 teqlo r0, #212, #16 */
/* @0x2ad1ac .word 0xf8d45598 */
/* @0x2ad1b0 sasxmi r3, r10, r0 */
/* @0x2ad1b4 andlo r4, r1, #22020096 */
/* @0x2ad1b8 stmdbhs r0, {r0, r3, r5, r11, r12, sp, lr} */
/* @0x2ad1bc mcrhs p1, #0x0, sp, c11, c10, #0x7 */
/* @0x2ad1c0 beq 0x467dd4 <g_RomDisk+0x705b4> */
/* @0x2ad1c4 bl 0xff4235d8 <b2_toiTime+0xfffffffffecca134> */
/* @0x2ad1c8 blhs 0x5addf8 <g_SWFlineaavertbuff+0x5ad30> */
/* @0x2ad1cc ldmdbmi r11, {r0, r1, r10, r11, r12, lr, pc} ^ */
/* @0x2ad1d0 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad1d4 stmdavc r9!, {r1, r2, r6, sp, lr, pc} ^ */
/* @0x2ad1d8 mulls r2, r5, r8 */
/* @0x2ad1dc svceq #0x80f011 */
/* @0x2ad1e0 b 0x168b690 <b2_toiTime+0xf321ec> */
/* @0x2ad1e4 stmvc r11!, {r0, r8, sp, lr} ^ */
/* @0x2ad1e8 stmdbmi r9, {r0, r8, r9, r11, sp, lr, pc} */
/* @0x2ad1ec bl 0x4fe438 <SrcVerts+0x5b47c> */
/* @0x2ad1f0 andle r2, r5, r3, lsl #18 */
/* @0x2ad1f4 stmdbeq r0, {r0, r3, r6, r7, r8, r12, sp, lr, pc} */
/* @0x2ad1f8 stmdbmi r0, {r0, r3, r5, r12, sp, lr, pc} */
/* @0x2ad1fc stmdbeq r0, {r0, r3, r6, r7, r8, r12, sp, lr, pc} */
/* @0x2ad200 .word 0xf8957969 */
/* @0x2ad204 .word 0xf011b006 */
/* @0x2ad208 bvc 0xd31010 <b2_toiTime+0x5d7b6c> */
/* @0x2ad20c .word 0x6101ea4f */
/* @0x2ad210 bl 0x30b9c4 <af_shaper_get_elem+0x1232> */
/* @0x2ad214 ldrmi r4, [r3], #2827 */
/* @0x2ad218 bl 0x5a1244 <g_SWFlineaavertbuff+0x4e17c> */
/* @0x2ad21c .word 0xf1cb2b03 */
/* @0x2ad220 .word 0xf02b0b00 */
/* @0x2ad224 .word 0xf1cb4b00 */
/* @0x2ad228 andls r0, r9, #0, #4 */
/* @0x2ad22c bl 0x5a523c <g_SWFlineaavertbuff+0x52174> */
/* @0x2ad230 movwls r2, #0x9303 */
/* @0x2ad234 mullt r9, r5, r8 */
/* @0x2ad238 .word 0xf1bb7aae */
/* @0x2ad23c .word 0xd1010f00 */
/* @0x2ad240 and r2, r11, r2, lsl #28 */
/* @0x2ad244 svceq #0x1f1bb */
/* @0x2ad248 .word 0xf1bbd002 */
/* @0x2ad24c .word 0xd1010f02 */
/* @0x2ad250 and r2, r3, r3, lsl #28 */
/* @0x2ad254 svceq #0x3f1bb */
/* @0x2ad258 mcrhs p1, #0x0, sp, c4, c1, #0x0 */
/* @0x2ad25c ldmdbmi r8!, {r0, r2, r4, r12, lr, pc} */
/* @0x2ad260 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad264 .word 0xf906f7f9 */
/* @0x2ad268 .word 0xf8d44620 */
/* @0x2ad26c .word 0xf7f91330 */
/* @0x2ad270 movwhs pc, #0xd45 */
/* @0x2ad274 teqlo r0, #196, #16 */
/* @0x2ad278 pop {r0, r1, r3, r12, sp, pc} */
/* @0x2ad27c stmdble r4, {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ad280 qasxmi r4, r0, r0 */
/* @0x2ad284 .word 0xf7f94479 */
/* @0x2ad288 .word 0xf105f8f5 */
/* @0x2ad28c ldrmi r0, [r9], -r11, lsl #6 */
/* @0x2ad290 .word 0x3101460d */
/* @0x2ad294 bhs 0x2cb344 <_ZN7b2World4DumpEv+0x124> */
/* @0x2ad298 qsub8mi sp, r0, r10 */
/* @0x2ad29c andls r0, r7, #177 */
/* @0x2ad2a0 .word 0xf7f99308 */
/* @0x2ad2a4 bls 0x4ac78c <SrcVerts+0x97d0> */
/* @0x2ad2a8 strmi r9, [r7], -r8, lsl #22 */
/* @0x2ad2ac .word 0x4620b9b0 */
/* @0x2ad2b0 teqne r0, #212, #16 */
/* @0x2ad2b4 stc2 p7, c15, [r2, #-996]! */
/* @0x2ad2b8 strtmi r4, [r0], -r3, lsr #18 */
/* @0x2ad2bc teqvc r0, #196, #16 */
/* @0x2ad2c0 andlt r4, r11, r9, ror r4 */
/* @0x2ad2c4 svcmi #0xf0e8bd */
/* @0x2ad2c8 ldmlt r4, {r0, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2ad2cc .word 0x460d4551 */
/* @0x2ad2d0 stmdavc r8!, {r3, r4, r11, r12, lr, pc} */
/* @0x2ad2d4 stmdahs r0, {r0, r8, r12, sp} */
/* @0x2ad2d8 andlo sp, r1, #248, #2 */
/* @0x2ad2dc ble 0x37ddac <_ZTS13C_UTF16String+0x14e58> */
/* @0x2ad2e0 .word 0xf8471c69 */
/* @0x2ad2e4 ldrb r1, [r1, r2, lsr #32]! */
/* @0x2ad2e8 strtmi r9, [r0], -r9, lsl #20 */
/* @0x2ad2ec strbmi r9, [r1], -r3, lsl #6 */
/* @0x2ad2f0 strbmi r9, [r11], -r2, lsl #12 */
/* @0x2ad2f4 stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc} */
/* @0x2ad2f8 .word 0xf8d49704 */
/* @0x2ad2fc .word 0xf0012330 */
/* @0x2ad300 and pc, r4, r1, lsl r12 */
/* @0x2ad304 qadd16mi r4, r0, r1 */
/* @0x2ad308 .word 0xf7f94479 */
/* @0x2ad30c .word 0x4620f8b3 */
/* @0x2ad310 teqne r0, #212, #16 */
/* @0x2ad314 ldc2l p7, c15, [r2], #996 */
/* @0x2ad318 strtmi r2, [r0], -r0, lsl #6 */
/* @0x2ad31c teqlo r0, #196, #16 */
/* @0x2ad320 andlt r4, r11, r9, lsr r6 */
/* @0x2ad324 svcmi #0xf0e8bd */
/* @0x2ad328 stcllt p7, c15, [r8], #996 */
/* @0x2ad32c andeq r0, lr, r11, asr #7 */
/* @0x2ad330 ldrdeq r0, r1, [lr], -r6 */
/* @0x2ad334 ldrdeq r0, r1, [lr], -r10 */
/* @0x2ad338 strheq r0, [lr], -sp */
/* @0x2ad33c muleq lr, r8, r3 */
/* @0x2ad340 andeq r0, lr, r10, lsl r3 */
/* @0x2ad344 andeq r0, lr, r2, lsr #6 */
/* @0x2ad348 andeq r0, lr, r0, lsl r3 */
/* @0x2ad34c andeq r0, lr, r2, ror #4 */
/* @0x2ad350 mvnsmi lr, #737280 */
/* @0x2ad354 blhi 0x368810 <_ZTS12CDS_Priority+0xa868> */
/* @0x2ad358 .word 0xf8d0460e */
/* @0x2ad35c addlt r3, r7, r12, lsr #2 */
/* @0x2ad360 ldrmi r4, [r5], -r4, lsl #12 */
/* @0x2ad364 strle r0, [r4], #-2009 */
/* @0x2ad368 ldrbtmi r4, [r9], #-2384 */
/* @0x2ad36c .word 0xf85ef7f9 */
/* @0x2ad370 smmlaeq r10, r7, r0, lr */
/* @0x2ad374 stmdbmi lr, {r1, r8, r10, r12, lr, pc} ^ */
/* @0x2ad378 and r4, r5, r9, ror r4 */
/* @0x2ad37c ldmvs r3!, {r1, r2, r3, r4, r6, r8, r12, sp, pc} */
/* @0x2ad380 strle r0, [r8, #-0x45b] */
/* @0x2ad384 ldrbtmi r4, [r9], #-2379 */
/* @0x2ad388 .word 0xf874f7f9 */
/* @0x2ad38c strtmi r4, [r9], -r0, lsr #12 */
/* @0x2ad390 stc2 p7, c15, [r0], {254} */
/* @0x2ad394 stchs p0, c14, [r3, #-532] */
/* @0x2ad398 stmdbmi r7, {r0, r1, r11, r12, lr, pc} ^ */
/* @0x2ad39c ldrbtmi r4, [r9], #-1568 */
/* @0x2ad3a0 stclne p7, c14, [r9], #-968 */
/* @0x2ad3a4 .word 0xf7f94620 */
/* @0x2ad3a8 .word 0x4601fcb6 */
/* @0x2ad3ac teqeq r0, #196, #16 */
/* @0x2ad3b0 ldmdblt r1, {r5, r9, r10, lr} */
/* @0x2ad3b4 ldrbtmi r4, [r9], #-2369 */
/* @0x2ad3b8 strtmi lr, [r10], -r6, ror #15 */
/* @0x2ad3bc stc2 p7, c15, [r6], #-1016 */
/* @0x2ad3c0 .word 0x21004620 */
/* @0x2ad3c4 stc2l p7, c15, [r6], #-1016 */
/* @0x2ad3c8 stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x2ad3cc .word 0xf8d4d150 */
/* @0x2ad3d0 .word 0xf10d3330 */
/* @0x2ad3d4 .word 0x46490914 */
/* @0x2ad3d8 .word 0xf8d45558 */
/* @0x2ad3dc andlo r0, r1, r0, lsr r3 */
/* @0x2ad3e0 ldmdb r10!, {r0, r3, r9, r10, r12, sp, lr, pc} */
/* @0x2ad3e4 ldmdavc r11, {r0, r2, r8, r9, r11, r12, pc} */
/* @0x2ad3e8 bleq 0x8e84f4 <b2_toiTime+0x18f050> */
/* @0x2ad3ec ldmdbmi r4!, {r0, r1, r3, r4, r8, r12, sp, pc} */
/* @0x2ad3f0 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad3f4 .word 0xf8d4e01e */
/* @0x2ad3f8 mrrcne p3, #0x3, r2, r3, c0 */
/* @0x2ad3fc movwlo r4, #0x1619 */
/* @0x2ad400 svchs #0x780f */
/* @0x2ad404 strtmi sp, [r10], #-506 */
/* @0x2ad408 addsmi r4, r3, #152, #12 */
/* @0x2ad40c pushmi {r0, r1, r8, r11, r12, lr, pc} */
/* @0x2ad410 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad414 ldrmi lr, [r8], -lr */
/* @0x2ad418 .word 0xf6094649 */
/* @0x2ad41c blls 0x42789c <g_RomDisk+0x3007c> */
/* @0x2ad420 mulls r0, r3, r8 */
/* @0x2ad424 bleq 0x8a8530 <b2_toiTime+0x14f08c> */
/* @0x2ad428 svceq #0xf1b9 */
/* @0x2ad42c stmdbmi r6!, {r2, r3, r12, lr, pc} */
/* @0x2ad430 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad434 .word 0xf81ef7f9 */
/* @0x2ad438 .word 0xf8d44620 */
/* @0x2ad43c .word 0xf7f91330 */
/* @0x2ad440 .word 0xf8c4fc5d */
/* @0x2ad444 eor r7, r12, r0, lsr r3 */
/* @0x2ad448 teqlo r0, #212, #16 */
/* @0x2ad44c strmi r4, [r8, #0x41d]! */
/* @0x2ad450 cdp p8, #0xb, c13, c5, c9, #0x0 */
/* @0x2ad454 vsqrt.f64 d24, d0 */
/* @0x2ad458 stmdble r4, {r4, r9, r11, r12, sp, lr, pc} */
/* @0x2ad45c blvc 0xff2e8f38 <b2_toiTime+0xfffffffffeb8fa94> */
/* @0x2ad460 blx 0x6e902c <g_SWFvertbuff+0x15f64> */
/* @0x2ad464 ldmdbmi r9, {r0, r2, r3, r11, r12, lr, pc} */
/* @0x2ad468 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad46c .word 0xf802f7f9 */
/* @0x2ad470 .word 0xf8d44620 */
/* @0x2ad474 .word 0xf7f91330 */
/* @0x2ad478 movwhs pc, #0xc41 */
/* @0x2ad47c teqlo r0, #196, #16 */
/* @0x2ad480 ldmdavc r10, {r0, r1, r2, r3, sp, lr, pc} */
/* @0x2ad484 blhi 0x2e8ac0 <FT_Set_Renderer+0x24> */
/* @0x2ad488 smlabteq r2, sp, r9, lr */
/* @0x2ad48c ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x2ad490 blx 0xff96949e <b2_toiTime+0xffffffffff20fffa> */
/* @0x2ad494 .word 0xf8d44620 */
/* @0x2ad498 .word 0xf7f91330 */
/* @0x2ad49c .word 0xf8c4fc2f */
/* @0x2ad4a0 andlt r9, r7, r0, lsr r3 */
/* @0x2ad4a4 blhi 0x3687a0 <_ZTS12CDS_Priority+0xa7f8> */
/* @0x2ad4a8 mvnshi lr, #12386304 */
/* @0x2ad4ac andeq r0, lr, r0, lsl #5 */
/* @0x2ad4b0 andeq r0, lr, r11, lsl #5 */
/* @0x2ad4b4 muleq lr, r5, r2 */
/* @0x2ad4b8 muleq lr, r2, r2 */
/* @0x2ad4bc andeq r0, lr, pc, lsl #5 */
/* @0x2ad4c0 andeq r0, lr, sp, ror r2 */
/* @0x2ad4c4 andeq r0, lr, r2, lsl #5 */
/* @0x2ad4c8 andeq r0, lr, r7, ror r2 */
/* @0x2ad4cc andeq r0, lr, r5, ror #4 */
/* @0x2ad4d0 .word 0x4604b57f */
/* @0x2ad4d4 .word 0x312cf8d0 */
/* @0x2ad4d8 ldrmi r4, [r5], -lr, lsl #12 */
/* @0x2ad4dc strle r0, [r4], #-2011 */
/* @0x2ad4e0 ldrbtmi r4, [r9], #-2341 */
/* @0x2ad4e4 .word 0xffa2f7f8 */
/* @0x2ad4e8 .word 0xb129e006 */
/* @0x2ad4ec ldreq r6, [r9, #0x88b] */
/* @0x2ad4f0 stmdbmi r2!, {r1, r8, r10, r12, lr, pc} */
/* @0x2ad4f4 and r4, r12, r9, ror r4 */
/* @0x2ad4f8 .word 0x312cf8d4 */
/* @0x2ad4fc ldrbeq r4, [r10, -r0, lsr #12] */
/* @0x2ad500 .word 0xf043bf44 */
/* @0x2ad504 .word 0xf8c40308 */
/* @0x2ad508 stchs p1, c3, [r7, #-176] */
/* @0x2ad50c ldmdbmi r12, {r3, r12, lr, pc} */
/* @0x2ad510 .word 0xf7f84479 */
/* @0x2ad514 strtmi pc, [r0], -pc, lsr #31 */
/* @0x2ad518 .word 0xf7fe4629 */
/* @0x2ad51c .word 0xe029fbbb */
/* @0x2ad520 strtmi r4, [r10], -r9, ror #12 */
/* @0x2ad524 blx 0x1f6b526 <b2_toiTime+0x1812082> */
/* @0x2ad528 .word 0x21004620 */
/* @0x2ad52c blx 0xfef6b52e <b2_toiTime+0xfffffffffe81208a> */
/* @0x2ad530 .word 0xf89dbb00 */
/* @0x2ad534 strtmi r3, [r0], -r6 */
/* @0x2ad538 mulhs r0, sp, r8 */
/* @0x2ad53c .word 0xf88d4631 */
/* @0x2ad540 .word 0xf89d300e */
/* @0x2ad544 .word 0xf88d3005 */
/* @0x2ad548 .word 0xf89d300d */
/* @0x2ad54c .word 0xf88d3004 */
/* @0x2ad550 .word 0xf89d300c */
/* @0x2ad554 .word 0xf88d3003 */
/* @0x2ad558 .word 0xf89d300b */
/* @0x2ad55c .word 0xf88d3002 */
/* @0x2ad560 .word 0xf89d300a */
/* @0x2ad564 bl 0x379570 <_ZTS13C_UTF16String+0x1061c> */
/* @0x2ad568 bge 0x3b6178 <error_g0017+0xee1c> */
/* @0x2ad56c stclo p8, c15, [r8, #-136] */
/* @0x2ad570 stc2l p0, c15, [r6, #4] */
/* @0x2ad574 ldcllt p0, c11, [r0, #-16]! */
/* @0x2ad578 strdeq r0, r1, [lr], -pc */
/* @0x2ad57c andeq r0, lr, r5, lsl #4 */
/* @0x2ad580 strdeq r0, r1, [lr], -lr */
/* @0x2ad584 .word 0x43f8e92d */
/* @0x2ad588 .word 0xf8d04604 */
/* @0x2ad58c pkhbtmi r3, r9, r0, lsl #6 */
/* @0x2ad590 orrlt r4, r3, r5, lsl r6 */
/* @0x2ad594 andle r2, r9, r1, lsl #22 */
/* @0x2ad598 .word 0xf8c03b01 */
/* @0x2ad59c blhs 0x2fa1e4 <ps_hints_apply+0x8de4> */
/* @0x2ad5a0 stmdbmi r5, {r0, r3, r8, r12, lr, pc} ^ */
/* @0x2ad5a4 .word 0xf7f84479 */
/* @0x2ad5a8 strtmi pc, [r0], -r5, ror #30 */
/* @0x2ad5ac pop {r0, r3, r5, r9, r10, lr} */
/* @0x2ad5b0 .word 0xf7fe43f8 */
/* @0x2ad5b4 .word 0xf8d4bb6f */
/* @0x2ad5b8 ldrbeq r3, [r9, r12, lsr #2] */
/* @0x2ad5bc ldmdbmi pc!, {r2, r10, r12, lr, pc} */
/* @0x2ad5c0 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad5c4 .word 0xff32f7f8 */
/* @0x2ad5c8 .word 0x312cf8d4 */
/* @0x2ad5cc .word 0xf8d44620 */
/* @0x2ad5d0 smmlareq r10, r0, r3, r1 */
/* @0x2ad5d4 .word 0xf043bf44 */
/* @0x2ad5d8 .word 0xf8c40308 */
/* @0x2ad5dc .word 0xf7f9312c */
/* @0x2ad5e0 .word 0x1c69fb8d */
/* @0x2ad5e4 .word 0xf7f94620 */
/* @0x2ad5e8 .word 0x4601fb96 */
/* @0x2ad5ec teqeq r0, #196, #16 */
/* @0x2ad5f0 ldmdblt r1, {r5, r9, r10, lr} */
/* @0x2ad5f4 ldrbtmi r4, [r9], #-2354 */
/* @0x2ad5f8 qsaxmi lr, r10, r7 */
/* @0x2ad5fc blx 0x46b5fe <g_RomDisk+0x73dde> */
/* @0x2ad600 .word 0x21004620 */
/* @0x2ad604 blx 0x146b606 <b2_toiTime+0xd12162> */
/* @0x2ad608 strtmi r11, [r0], -r8, asr #2 */
/* @0x2ad60c teqne r0, #212, #16 */
/* @0x2ad610 blx 0x1feb5fe <b2_toiTime+0x189215a> */
/* @0x2ad614 .word 0xf8c42300 */
/* @0x2ad618 pop {r4, r5, r8, r9, r12, sp} */
/* @0x2ad61c .word 0xf8d483f8 */
/* @0x2ad620 bl 0x4ce2e8 <SrcVerts+0x2b32c> */
/* @0x2ad624 strbmi r0, [r3], -r5, lsl #4 */
/* @0x2ad628 andeq pc, r5, r8, lsl #16 */
/* @0x2ad62c movwlo r4, #0x161f */
/* @0x2ad630 mcrhs p8, #0x0, r7, c0, c14, #0x1 */
/* @0x2ad634 qsub8mi sp, r0, r10 */
/* @0x2ad638 addsmi r2, r7, #28, #2 */
/* @0x2ad63c ldrmi r11, [r7], -r12, lsl #30 */
/* @0x2ad640 .word 0xf7f9461f */
/* @0x2ad644 strmi pc, [r5], -r8, ror #22 */
/* @0x2ad648 ldmdbmi lr, {r3, r5, r6, r8, r11, r12, sp, pc} */
/* @0x2ad64c ldrbtmi r4, [r9], #-1568 */
/* @0x2ad650 .word 0xff10f7f8 */
/* @0x2ad654 .word 0xf8d44620 */
/* @0x2ad658 .word 0xf7f91330 */
/* @0x2ad65c .word 0xf8c4fb4f */
/* @0x2ad660 pop {r4, r5, r8, r9, r12, lr} */
/* @0x2ad664 .word 0xf04f83f8 */
/* @0x2ad668 strdvs r3, r4, [r7], pc */
/* @0x2ad66c smlabbeq r8, r0, r8, lr */
/* @0x2ad670 orrvs r6, r6, r6, asr #2 */
/* @0x2ad674 ldrtmi r6, [r8], -r6, lsl #2 */
/* @0x2ad678 svc #0x5ef608 */
/* @0x2ad67c strtmi r4, [r10], -r9, asr #12 */
/* @0x2ad680 rscvs r2, r8, r1, lsl #6 */
/* @0x2ad684 .word 0xf0014620 */
/* @0x2ad688 .word 0xf8d4fc37 */
/* @0x2ad68c .word 0x46071330 */
/* @0x2ad690 .word 0xf7f94620 */
/* @0x2ad694 .word 0xf8c4fb33 */
/* @0x2ad698 qasxmi r6, r0, r0 */
/* @0x2ad69c .word 0xf7f94629 */
/* @0x2ad6a0 teqlt r7, sp, lsr #22 */
/* @0x2ad6a4 strtmi r4, [r0], -r8, lsl #18 */
/* @0x2ad6a8 pop {r0, r3, r4, r5, r6, r10, lr} */
/* @0x2ad6ac .word 0xf7f843f8 */
/* @0x2ad6b0 pop {r0, r5, r6, r7, r9, r10, r11, r12, sp, pc} */
/* @0x2ad6b4 svclt #0x83f8 */
/* @0x2ad6b8 andeq r0, lr, r6, lsl #3 */
/* @0x2ad6bc andeq r0, lr, r9, lsl #3 */
/* @0x2ad6c0 andeq r0, lr, lr, ror #2 */
/* @0x2ad6c4 andeq r0, lr, r6, lsr r1 */
/* @0x2ad6c8 andeq r0, lr, r4, lsl #2 */
/* @0x2ad6cc mvnsmi lr, sp, lsr #18 */
/* @0x2ad6d0 .word 0xf8d04604 */
/* @0x2ad6d4 .word 0x460f3310 */
/* @0x2ad6d8 cmnlt r11, r5, lsl r6 */
/* @0x2ad6dc andle r2, r9, r1, lsl #22 */
/* @0x2ad6e0 .word 0xf8c03b01 */
/* @0x2ad6e4 blhs 0x2fa32c <ps_hints_apply+0x8f2c> */
/* @0x2ad6e8 ldmdbmi r2, {r3, r8, r12, lr, pc} ^ */
/* @0x2ad6ec .word 0xf7f84479 */
/* @0x2ad6f0 strtmi pc, [r0], -r1, asr #29 */
/* @0x2ad6f4 .word 0xf7fe4629 */
/* @0x2ad6f8 adds pc, r7, sp, asr #21 */
/* @0x2ad6fc .word 0x312cf8d4 */
/* @0x2ad700 strle r0, [r4], #-2009 */
/* @0x2ad704 strtmi r4, [r0], -r12, asr #18 */
/* @0x2ad708 .word 0xf7f84479 */
/* @0x2ad70c .word 0xf8d4fe8f */
/* @0x2ad710 strtmi r3, [r0], -r12, lsr #2 */
/* @0x2ad714 teqne r0, #212, #16 */
/* @0x2ad718 svclt #0x44075a */
/* @0x2ad71c movweq pc, #0x8043 */
/* @0x2ad720 smlawtlo r12, r4, r8, pc */
/* @0x2ad724 blx 0xffd6b710 <b2_toiTime+0xffffffffff61226c> */
/* @0x2ad728 strtmi r1, [r0], -r9, ror #24 */
/* @0x2ad72c blx 0xfffab718 <b2_toiTime+0xffffffffff852274> */
/* @0x2ad730 .word 0xf8c44601 */
/* @0x2ad734 qasxmi r0, r0, r0 */
/* @0x2ad738 stmdbmi r0, {r0, r5, r8, r11, r12, sp, pc} ^ */
/* @0x2ad73c .word 0xf7f84479 */
/* @0x2ad740 .word 0xe073fe99 */
/* @0x2ad744 .word 0xf7fe462a */
/* @0x2ad748 strtmi pc, [r0], -r1, ror #20 */
/* @0x2ad74c .word 0xf7fe2100 */
/* @0x2ad750 stmiblt r8!, {r0, r5, r7, r9, r11, r12, sp, lr, pc} */
/* @0x2ad754 teqlo r0, #212, #16 */
/* @0x2ad758 .word 0xf8d45558 */
/* @0x2ad75c sasxmi r3, r10, r0 */
/* @0x2ad760 andlo r4, r1, #23068672 */
/* @0x2ad764 stmdbhs r0, {r0, r4, r5, r11, r12, sp, lr} */
/* @0x2ad768 stchs p1, c13, [r1, #-1000] */
/* @0x2ad76c cdpne p9, #0xa, c13, c10, c3, #0x0 */
/* @0x2ad770 addsmi r4, lr, #318767104 */
/* @0x2ad774 ldmdbmi r2!, {r0, r2, r3, r8, r9, r12, lr, pc} */
/* @0x2ad778 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad77c mrc2 p7, #0x3, apsr_nzcv, c10, c8, #0x7 */
/* @0x2ad780 .word 0xf8d44620 */
/* @0x2ad784 .word 0xf7f91330 */
/* @0x2ad788 movwhs pc, #0xab9 */
/* @0x2ad78c teqlo r0, #196, #16 */
/* @0x2ad790 ldmdavc r3!, {r2, r3, r6, sp, lr, pc} ^ */
/* @0x2ad794 stmdbmi r11!, {r0, r1, r5, r8, r12, sp, pc} */
/* @0x2ad798 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad79c mcr2 p7, #0x3, pc, c10, c8, #0x7 */
/* @0x2ad7a0 teqlo r0, #212, #16 */
/* @0x2ad7a4 strtmi r3, [r10], -r2, lsl #12 */
/* @0x2ad7a8 bl 0xff37f030 <b2_toiTime+0xfffffffffec25b8c> */
/* @0x2ad7ac .word 0x21000806 */
/* @0x2ad7b0 movwls r10, #0xb03 */
/* @0x2ad7b4 .word 0xf7fe4643 */
/* @0x2ad7b8 strtmi pc, [r0], -r7, lsr #21 */
/* @0x2ad7bc .word 0xf7f9211c */
/* @0x2ad7c0 strmi pc, [r5], -r10, lsr #21 */
/* @0x2ad7c4 stmdbmi r0!, {r5, r6, r8, r11, r12, sp, pc} */
/* @0x2ad7c8 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad7cc mrc2 p7, #0x2, apsr_nzcv, c2, c8, #0x7 */
/* @0x2ad7d0 .word 0xf8d44620 */
/* @0x2ad7d4 .word 0xf7f91330 */
/* @0x2ad7d8 .word 0xf8c4fa91 */
/* @0x2ad7dc eor r5, r5, r0, lsr r3 */
/* @0x2ad7e0 andvs r2, r6, r0, lsl #12 */
/* @0x2ad7e4 teqlo r0, #212, #16 */
/* @0x2ad7e8 .word 0x61464639 */
/* @0x2ad7ec orrvs r4, r6, r10, lsr #12 */
/* @0x2ad7f0 .word 0x61066043 */
/* @0x2ad7f4 teqlo r0, #212, #16 */
/* @0x2ad7f8 addvs r4, r3, r3, asr #8 */
/* @0x2ad7fc sbcvs r9, r3, r3, lsl #22 */
/* @0x2ad800 strtmi r2, [r0], -r1, lsl #6 */
/* @0x2ad804 blx 0x20e9812 <b2_toiTime+0x199036e> */
/* @0x2ad808 strmi r4, [r7], -r9, lsr #12 */
/* @0x2ad80c .word 0xf7f94620 */
/* @0x2ad810 qsub16mi pc, r0, r5 */
/* @0x2ad814 teqne r0, #212, #16 */
/* @0x2ad818 blx 0x1eeb804 <b2_toiTime+0x1792360> */
/* @0x2ad81c teqvs r0, #196, #16 */
/* @0x2ad820 stmdbmi r10, {r0, r1, r2, r5, r8, r12, sp, pc} */
/* @0x2ad824 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad828 mcr2 p7, #0x0, pc, c0, c8, #0x7 */
/* @0x2ad82c pop {r2, r12, sp, pc} */
/* @0x2ad830 svclt #0x81f0 */
/* @0x2ad834 andeq r0, lr, r10, ror #1 */
/* @0x2ad838 andeq r0, lr, pc, ror #1 */
/* @0x2ad83c ldrdeq r0, r1, [lr], -r4 */
/* @0x2ad840 strheq r0, [lr], -r10 */
/* @0x2ad844 andeq r0, lr, pc, lsr #1 */
/* @0x2ad848 andeq r0, lr, r6, lsr #1 */
/* @0x2ad84c andeq r0, lr, r2, ror r0 */
/* @0x2ad850 svcmi #0xf0e92d */
/* @0x2ad854 .word 0xf8d04604 */
/* @0x2ad858 addlt r3, r5, r0, lsl r3 */
/* @0x2ad85c ldrmi r4, [r5], -r10, lsl #13 */
/* @0x2ad860 blhs 0x319e54 <__gnu_Unwind_Backtrace+0x164> */
/* @0x2ad864 bllo 0x321890 */
/* @0x2ad868 tstlo r0, #192, #16 */
/* @0x2ad86c .word 0xd1082b01 */
/* @0x2ad870 ldrbtmi r4, [r9], #-2409 */
/* @0x2ad874 ldc2l p7, c15, [lr, #992]! */
/* @0x2ad878 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2ad87c blx 0x56b87c <g_SWFlineaavertbuff+0x187b4> */
/* @0x2ad880 .word 0xf8d4e0c6 */
/* @0x2ad884 ldrbeq r3, [r9, r12, lsr #2] */
/* @0x2ad888 stmdbmi r4!, {r2, r10, r12, lr, pc} ^ */
/* @0x2ad88c ldrbtmi r4, [r9], #-1568 */
/* @0x2ad890 stc2l p7, c15, [r12, #992] */
/* @0x2ad894 .word 0x312cf8d4 */
/* @0x2ad898 .word 0xf8d44620 */
/* @0x2ad89c smmlareq r10, r0, r3, r1 */
/* @0x2ad8a0 .word 0xf043bf44 */
/* @0x2ad8a4 .word 0xf8c40308 */
/* @0x2ad8a8 .word 0xf7f9312c */
/* @0x2ad8ac .word 0x1c69fa27 */
/* @0x2ad8b0 .word 0xf7f94620 */
/* @0x2ad8b4 .word 0x4601fa30 */
/* @0x2ad8b8 teqeq r0, #196, #16 */
/* @0x2ad8bc stmdblt r1!, {r5, r9, r10, lr} */
/* @0x2ad8c0 ldrbtmi r4, [r9], #-2391 */
/* @0x2ad8c4 ldc2l p7, c15, [r6, #992] */
/* @0x2ad8c8 strtmi lr, [r10], -r2, lsr #1 */
/* @0x2ad8cc .word 0xf99ef7fe */
/* @0x2ad8d0 .word 0x21004620 */
/* @0x2ad8d4 .word 0xf9def7fe */
/* @0x2ad8d8 .word 0xf8d4b9b0 */
/* @0x2ad8dc ldrbpl r3, [r8, #-0x330] */
/* @0x2ad8e0 teqlt r0, #212, #16 */
/* @0x2ad8e4 ssaxmi r4, r3, r10 */
/* @0x2ad8e8 ldmdavc r9, {r0, r9, r12, sp} */
/* @0x2ad8ec mvnsle r2, r0, lsl #18 */
/* @0x2ad8f0 stmdble r4, {r1, r8, r10, r11, sp} */
/* @0x2ad8f4 mcrne p6, #0x7, r4, c10, c1, #0x0 */
/* @0x2ad8f8 addsmi r4, r1, #1509949440 */
/* @0x2ad8fc stmdbmi r9, {r0, r2, r3, r8, r9, r12, lr, pc} ^ */
/* @0x2ad900 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad904 ldc2 p7, c15, [r6, #992]! */
/* @0x2ad908 .word 0xf8d44620 */
/* @0x2ad90c .word 0xf7f91330 */
/* @0x2ad910 movwhs pc, #0x9f5 */
/* @0x2ad914 teqlo r0, #196, #16 */
/* @0x2ad918 .word 0xf103e07a */
/* @0x2ad91c .word 0xf8930803 */
/* @0x2ad920 ldmvc r9, {r0, r12, pc} */
/* @0x2ad924 ldrmi r4, [pc], -r3, asr #12 */
/* @0x2ad928 ldmdavc r10!, {r0, r8, r9, r12, sp} */
/* @0x2ad92c mvnsle r2, r0, lsl #20 */
/* @0x2ad930 andeq lr, r5, #11264 */
/* @0x2ad934 addsmi r4, r3, #32505856 */
/* @0x2ad938 ldrmi sp, [r8], -r1, ror #5 */
/* @0x2ad93c stmdavc r6, {r0, r8, r9, r12, sp} */
/* @0x2ad940 mvnsle r2, r0, lsl #28 */
/* @0x2ad944 movwle r4, #0xc293 */
/* @0x2ad948 qasxmi r4, r0, r7 */
/* @0x2ad94c .word 0xf7f84479 */
/* @0x2ad950 qadd8mi pc, r0, r1 */
/* @0x2ad954 teqne r0, #212, #16 */
/* @0x2ad958 .word 0xf9d0f7f9 */
/* @0x2ad95c teqvs r0, #196, #16 */
/* @0x2ad960 bl 0xff5a5ac0 <b2_toiTime+0xfffffffffee4c61c> */
/* @0x2ad964 .word 0xf1b90603 */
/* @0x2ad968 andle r0, r7, r0, lsl #30 */
/* @0x2ad96c strtmi r10, [r0], -r3, lsl #22 */
/* @0x2ad970 strtmi r9, [r10], -r0, lsl #6 */
/* @0x2ad974 .word 0xf7fe4633 */
/* @0x2ad978 and pc, r4, r7, asr #19 */
/* @0x2ad97c andeq lr, r6, r11, lsl #22 */
/* @0x2ad980 ldcl p6, c15, [r10, #32] */
/* @0x2ad984 strtmi r9, [r0], -r3 */
/* @0x2ad988 .word 0xf7f9211c */
/* @0x2ad98c strmi pc, [r5], -r4, asr #19 */
/* @0x2ad990 stmdbmi r6!, {r5, r6, r8, r11, r12, sp, pc} */
/* @0x2ad994 ldrbtmi r4, [r9], #-1568 */
/* @0x2ad998 stc2l p7, c15, [r12, #-992]! */
/* @0x2ad99c .word 0xf8d44620 */
/* @0x2ad9a0 .word 0xf7f91330 */
/* @0x2ad9a4 .word 0xf8c4f9ab */
/* @0x2ad9a8 eors r5, r1, r0, lsr r3 */
/* @0x2ad9ac movweq pc, #0x1109 */
/* @0x2ad9b0 .word 0xf8d46003 */
/* @0x2ad9b4 bl 0xff57a67c <b2_toiTime+0xfffffffffee211d8> */
/* @0x2ad9b8 bl 0xff56f5dc <b2_toiTime+0xfffffffffee16138> */
/* @0x2ad9bc strtmi r0, [r10], -r8, lsl #16 */
/* @0x2ad9c0 orrvs r4, r3, r11, lsr r4 */
/* @0x2ad9c4 teqlo r0, #212, #16 */
/* @0x2ad9c8 sbcvs r2, r7, r0, lsl #14 */
/* @0x2ad9cc strbmi r4, [r3], #-1617 */
/* @0x2ad9d0 blls 0x385ee4 <_ZTS13C_UTF16String+0x1cf90> */
/* @0x2ad9d4 .word 0xf8d46103 */
/* @0x2ad9d8 subvs r3, r3, r0, lsr r3 */
/* @0x2ad9dc teqlo r0, #212, #16 */
/* @0x2ad9e0 movwhs r4, #0x141e */
/* @0x2ad9e4 strtmi r6, [r0], -r6, lsl #1 */
/* @0x2ad9e8 blx 0xfe4699f4 <b2_toiTime+0xfffffffffdd10550> */
/* @0x2ad9ec strmi r4, [r6], -r9, lsr #12 */
/* @0x2ad9f0 .word 0xf7f94620 */
/* @0x2ad9f4 strtmi pc, [r0], -r3, lsl #19 */
/* @0x2ad9f8 teqne r0, #212, #16 */
/* @0x2ad9fc .word 0xf97ef7f9 */
/* @0x2ada00 teqvc r0, #196, #16 */
/* @0x2ada04 stmdbmi r10, {r1, r2, r5, r8, r12, sp, pc} */
/* @0x2ada08 ldrbtmi r4, [r9], #-1568 */
/* @0x2ada0c stc2 p7, c15, [lr, #-992] */
/* @0x2ada10 pop {r0, r2, r12, sp, pc} */
/* @0x2ada14 svclt #0x8ff0 */
/* @0x2ada18 andeq r0, lr, lr, asr #32 */
/* @0x2ada1c andeq r0, lr, r3, asr r0 */
/* @0x2ada20 andeq r0, lr, r8, lsr r0 */
/* @0x2ada24 andeq r0, lr, r8, lsl r0 */
/* @0x2ada28 andeq pc, sp, r3, ror #31 */
/* @0x2ada2c andeq pc, sp, lr, lsr #31 */
/* @0x2ada30 andeq pc, sp, r2, ror #30 */
/* @0x2ada34 mvnsmi lr, sp, lsr #18 */
/* @0x2ada38 .word 0xf8d04604 */
/* @0x2ada3c .word 0x460f3310 */
/* @0x2ada40 .word 0xb1634615 */
/* @0x2ada44 .word 0xf0002b01 */
/* @0x2ada48 bllo 0x30dc60 <af_shaper_get_elem+0x34ce> */
/* @0x2ada4c tstlo r0, #192, #16 */
/* @0x2ada50 .word 0xd1042b01 */
/* @0x2ada54 ldrbtmi r4, [r9], #-2370 */
/* @0x2ada58 stc2 p7, c15, [r12, #-992] */
/* @0x2ada5c .word 0xf8d4e078 */
/* @0x2ada60 ldrbeq r6, [r0, -r12, lsr #2]! */
/* @0x2ada64 blmi 0x12a2eb0 <b2_toiTime+0xb49a0c> */
/* @0x2ada68 andhs r4, r4, #110100480 */
/* @0x2ada6c ldmdavs r8, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x2ada70 andls r7, r0, r11, lsl r9 */
/* @0x2ada74 rscsvc pc, r0, r4, lsl #10 */
/* @0x2ada78 andlo pc, r4, sp, lsl #17 */
/* @0x2ada7c stm r0!, {r0, r3, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2ada80 .word 0xf046b118 */
/* @0x2ada84 .word 0xf8c40608 */
/* @0x2ada88 .word 0xf894612c */
/* @0x2ada8c ldreq r3, [r9], r0, ror #3 */
/* @0x2ada90 strtmi sp, [r0], -lr, lsl #8 */
/* @0x2ada94 mvnsvc pc, r4, lsl #10 */
/* @0x2ada98 blx 0xfebeba80 <b2_toiTime+0xfffffffffe4925dc> */
/* @0x2ada9c andle r2, r7, r3, lsl #16 */
/* @0x2adaa0 sbclo pc, r8, #212, #16 */
/* @0x2adaa4 ldmdbmi r0!, {r0, r1, r5, r8, r11, r12, sp, pc} */
/* @0x2adaa8 ldrbtmi r4, [r9], #-1568 */
/* @0x2adaac stc2 p7, c15, [lr, #-992] */
/* @0x2adab0 ldrsblo pc, [r0, -r4]! */
/* @0x2adab4 strle r0, [r3], #-1050 */
/* @0x2adab8 sbclo pc, r8, #212, #16 */
/* @0x2adabc suble r2, r7, r0, lsl #22 */
/* @0x2adac0 ldmvc r0!, {r2, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2adac4 .word 0x3000f8d8 */
/* @0x2adac8 strbvc pc, [r5], -r4, lsl #10 */
/* @0x2adacc .word 0x5320f8c4 */
/* @0x2adad0 tstlo r4, #196, #16 */
/* @0x2adad4 .word 0xf8842300 */
/* @0x2adad8 ldmdblt r5, {r3, r4, r8, r9, r12, sp} */
/* @0x2adadc tstpl r12, #196, #16 */
/* @0x2adae0 strtmi lr, [r9], -r10 */
/* @0x2adae4 .word 0xf7f94620 */
/* @0x2adae8 .word 0x462af8db */
/* @0x2adaec .word 0xf8c44601 */
/* @0x2adaf0 qadd16mi r0, r0, r12 */
/* @0x2adaf4 .word 0xf88af7fe */
/* @0x2adaf8 sbclo pc, r8, #212, #16 */
/* @0x2adafc bicslt r4, r3, r0, lsr #12 */
/* @0x2adb00 .word 0x47984631 */
/* @0x2adb04 ble 0x3f7b0c <g_RomDisk+0x2ec> */
/* @0x2adb08 qadd16mi r4, r0, r8 */
/* @0x2adb0c .word 0xf7f84479 */
/* @0x2adb10 ldrsb pc, [r5], -sp */
/* @0x2adb14 .word 0xf894d114 */
/* @0x2adb18 ldreq r3, [r11], r0, ror #3 */
/* @0x2adb1c strtmi sp, [r0], -r10, lsl #8 */
/* @0x2adb20 .word 0xf7f84641 */
/* @0x2adb24 stmdahs r3, {r0, r1, r2, r3, r4, r6, r9, r11, r12, sp, lr, pc} */
/* @0x2adb28 ldmdbmi r1, {r2, r12, lr, pc} */
/* @0x2adb2c ldrbtmi r4, [r9], #-1568 */
/* @0x2adb30 stc2l p7, c15, [r12], {248} */
/* @0x2adb34 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2adb38 movwhs r4, #0x1632 */
/* @0x2adb3c .word 0xfc00f001 */
/* @0x2adb40 .word 0xf8d44620 */
/* @0x2adb44 .word 0xf7f9131c */
/* @0x2adb48 strhs pc, [r0, #-0x8d9] */
/* @0x2adb4c tstpl r12, #196, #16 */
/* @0x2adb50 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2adb54 pop {r1, r12, sp, pc} */
/* @0x2adb58 .word 0xf7fe41f0 */
/* @0x2adb5c svclt #0xb89b */
/* @0x2adb60 andeq pc, sp, lr, lsr pc */
/* @0x2adb64 andeq r1, lr, r12, ror pc */
/* @0x2adb68 andeq pc, sp, r4, lsl pc */
/* @0x2adb6c andeq pc, sp, r9, asr #29 */
/* @0x2adb70 muleq sp, r0, lr */
/* @0x2adb74 .word 0xf1a3780b */
/* @0x2adb78 bhs 0x10ee484 <b2_toiTime+0x994fe0> */
/* @0x2adb7c bllo 0x19a3bec <b2_toiTime+0x124a748> */
/* @0x2adb80 ldmdble r7, {r0, r2, r8, r9, r11, sp} */
/* @0x2adb84 .word 0xf1a3784b */
/* @0x2adb88 bhs 0x10ee494 <b2_toiTime+0x994ff0> */
/* @0x2adb8c bllo 0x19a3bdc <b2_toiTime+0x124a738> */
/* @0x2adb90 stmdble pc, {r0, r2, r8, r9, r11, sp} */
/* @0x2adb94 .word 0xf1a3788b */
/* @0x2adb98 bhs 0x10ee4a4 <b2_toiTime+0x995000> */
/* @0x2adb9c bllo 0x19a3bcc <b2_toiTime+0x124a728> */
/* @0x2adba0 stmdble r7, {r0, r2, r8, r9, r11, sp} */
/* @0x2adba4 .word 0xf1a378cb */
/* @0x2adba8 bhs 0x10ee4b4 <b2_toiTime+0x995010> */
/* @0x2adbac bllo 0x19a3bbc <b2_toiTime+0x124a718> */
/* @0x2adbb0 stmdale r3, {r0, r2, r8, r9, r11, sp} */
/* @0x2adbb4 ldrbtmi r4, [r9], #-2306 */
/* @0x2adbb8 stclt p7, c15, [r8], {248} */
/* @0x2adbbc svclt #0x4770 */
/* @0x2adbc0 andeq pc, sp, r3, lsr lr */
/* @0x2adbc4 mvnsmi lr, sp, lsr #18 */
/* @0x2adbc8 ldcmi p14, c10, [r8, #-4] */
/* @0x2adbcc andhs r4, r8, #4, #12 */
/* @0x2adbd0 ldrbtmi r4, [sp], #-1585 */
/* @0x2adbd4 .word 0xf504682d */
/* @0x2adbd8 stmdavs r11!, {r4, r5, r6, r7, r8, r9, r10, r12, sp, lr} */
/* @0x2adbdc .word 0x23219303 */
/* @0x2adbe0 teqlo r4, #192, #16 */
/* @0x2adbe4 blx 0xbebbd4 <b2_toiTime+0x492730> */
/* @0x2adbe8 qasxmi r4, r0, r1 */
/* @0x2adbec .word 0xffbef7fd */
/* @0x2adbf0 ldmdavs r0!, {r7, r9, r10, lr} ^ */
/* @0x2adbf4 mvneq pc, r4, asr #17 */
/* @0x2adbf8 .word 0xf7f74620 */
/* @0x2adbfc andhs pc, r4, #492 */
/* @0x2adc00 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2adc04 .word 0xff80f7f7 */
/* @0x2adc08 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2adc0c .word 0xffb2f7ff */
/* @0x2adc10 bls 0x37691c <_ZTS13C_UTF16String+0xd9c8> */
/* @0x2adc14 .word 0xf8c44640 */
/* @0x2adc18 stmdavs r11!, {r2, r4, r5, r8, r9, r12, sp} */
/* @0x2adc1c mulle r1, r10, r2 */
/* @0x2adc20 ldcl p6, c15, [r8], {8} */
/* @0x2adc24 pop {r2, r12, sp, pc} */
/* @0x2adc28 svclt #0x81f0 */
/* @0x2adc2c andseq pc, r3, r2, lsl #27 */
/* @0x2adc30 .word 0x460b2aff */
/* @0x2adc34 svcmi #0xf7e92d */
/* @0x2adc38 .word 0xf8d04615 */
/* @0x2adc3c .word 0xf89011b0 */
/* @0x2adc40 .word 0xf8d021cf */
/* @0x2adc44 smlabble pc, r12, r1, r4 */
/* @0x2adc48 .word 0xf1012a07 */
/* @0x2adc4c stmdble r2, {r0, r8} */
/* @0x2adc50 .word 0x436208d2 */
/* @0x2adc54 .word 0x4362e002 */
/* @0x2adc58 ldmeq r2, {r0, r1, r2, r9, r12, sp} ^ */
/* @0x2adc5c andlt r4, r3, r8, lsl r6 */
/* @0x2adc60 svcmi #0xf0e8bd */
/* @0x2adc64 svclt #0x52f06d */
/* @0x2adc68 suble r2, r6, r2, lsl #20 */
/* @0x2adc6c .word 0xf0002a04 */
/* @0x2adc70 bhs 0x30de88 <af_shaper_get_elem+0x36f6> */
/* @0x2adc74 adcshi pc, r6, r0, asr #32 */
/* @0x2adc78 ldrsbhs pc, [r4, -r0]! */
/* @0x2adc7c strhs r3, [r0], -r1, lsl #2 */
/* @0x2adc80 ldmdavc pc!, {r0, r1, r2, r6, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2adc84 addlo pc, r0, #33554432 */
/* @0x2adc88 svclt #0xc2a00 */
/* @0x2adc8c strhs r2, [r0, -r7, lsl #14] */
/* @0x2adc90 .word 0xf04fbf0c */
/* @0x2adc94 .word 0xf04f0c00 */
/* @0x2adc98 svclt #0xc0c07 */
/* @0x2adc9c rscslo pc, pc, #79 */
/* @0x2adca0 andls r2, r1, #268435456 */
/* @0x2adca4 addhs r4, r0, #56, #12 */
/* @0x2adca8 .word 0xf00042a6 */
/* @0x2adcac eormi r8, r10, #179 */
/* @0x2adcb0 .word 0xf891d013 */
/* @0x2adcb4 .word 0xf1c09000 */
/* @0x2adcb8 .word 0xf8930b07 */
/* @0x2adcbc blx 0x14d5cc4 <b2_toiTime+0xd7c820> */
/* @0x2adcc0 blx 0x152c8f4 <b2_toiTime+0xdd3450> */
/* @0x2adcc4 b 0x5ac0cc <g_SWFlineaavertbuff+0x59004> */
/* @0x2adcc8 .word 0xf0090a0a */
/* @0x2adccc blx 0x4f00d8 <SrcVerts+0x4d11c> */
/* @0x2adcd0 b 0x152c0d8 <b2_toiTime+0xdd2c34> */
/* @0x2adcd4 .word 0xf883090a */
/* @0x2adcd8 strbmi r9, [r0, #-0x0]! */
/* @0x2adcdc mrslo sp, apsr */
/* @0x2adce0 ldrtmi r3, [r8], -r1, lsl #6 */
/* @0x2adce4 .word 0xf8dde002 */
/* @0x2adce8 strbmi r9, [r8], #-4 */
/* @0x2adcec .word 0xf1062a01 */
/* @0x2adcf0 svclt #0x140601 */
/* @0x2adcf4 addhs r1, r0, #82 */
/* @0x2adcf8 .word 0xf8d0e7d6 */
/* @0x2adcfc .word 0x31012134 */
/* @0x2add00 addhs r2, r0, r0, lsl #12 */
/* @0x2add04 addlo pc, r0, #33554432 */
/* @0x2add08 ldmdavc pc!, {r0, r1, r6, r9, r10, r12, sp, lr, pc} */
/* @0x2add0c svclt #0xc2a00 */
/* @0x2add10 strhs r2, [r0, -r6, lsl #14] */
/* @0x2add14 .word 0xf06fbf0c */
/* @0x2add18 .word 0xf04f0c01 */
/* @0x2add1c svclt #0xc0c02 */
/* @0x2add20 beq 0x2e9e64 <FT_Done_Memory+0x1f0> */
/* @0x2add24 beq 0x469e68 <g_RomDisk+0x72648> */
/* @0x2add28 andge pc, r4, sp, asr #17 */
/* @0x2add2c adcmi r4, r6, #60817408 */
/* @0x2add30 eormi sp, r8, #112 */
/* @0x2add34 .word 0xf891d013 */
/* @0x2add38 .word 0xf1c29000 */
/* @0x2add3c .word 0xf8930b06 */
/* @0x2add40 blx 0x14d5d48 <b2_toiTime+0xd7c8a4> */
/* @0x2add44 blx 0x152c978 <b2_toiTime+0xdd34d4> */
/* @0x2add48 b 0x5ac158 <g_SWFlineaavertbuff+0x59090> */
/* @0x2add4c .word 0xf0090a0a */
/* @0x2add50 blx 0x4f0164 <SrcVerts+0x4d1a8> */
/* @0x2add54 b 0x152c164 <b2_toiTime+0xdd2cc0> */
/* @0x2add58 .word 0xf883090a */
/* @0x2add5c .word 0xf8dd9000 */
/* @0x2add60 strlo r9, [r1], -r4 */
/* @0x2add64 svclt #0x3454a */
/* @0x2add68 movwlo r3, #0x1101 */
/* @0x2add6c strbtmi r4, [r2], #-1594 */
/* @0x2add70 svclt #0x142801 */
/* @0x2add74 addhs r1, r0, r0, asr #32 */
/* @0x2add78 .word 0xf8d0e7d9 */
/* @0x2add7c .word 0x31010134 */
/* @0x2add80 strhs r2, [r0], r0, lsl #14 */
/* @0x2add84 stmlo r0, {r4, r10, r12, sp, lr, pc} */
/* @0x2add88 .word 0x4694bf1d */
/* @0x2add8c strbtmi r2, [r0], r0, lsl #4 */
/* @0x2add90 .word 0x0c03f06f */
/* @0x2add94 adcmi r4, r7, #16, #12 */
/* @0x2add98 eormi sp, lr, #60 */
/* @0x2add9c .word 0xf891d015 */
/* @0x2adda0 .word 0xf6409000 */
/* @0x2adda4 .word 0xf1c07a0f */
/* @0x2adda8 blx 0x15309c0 <b2_toiTime+0xdd751c> */
/* @0x2addac .word 0xf893fb0b */
/* @0x2addb0 blx 0x1515db8 <b2_toiTime+0xdbc914> */
/* @0x2addb4 .word 0xf009f900 */
/* @0x2addb8 b 0x5701fc <g_SWFlineaavertbuff+0x1d134> */
/* @0x2addbc blx 0x4f05ec <SrcVerts+0x4d630> */
/* @0x2addc0 b 0x152c1c8 <b2_toiTime+0xdd2d24> */
/* @0x2addc4 .word 0xf883090a */
/* @0x2addc8 strbmi r9, [r0, #-0x0] */
/* @0x2addcc streq pc, [r1, -r7, lsl #2] */
/* @0x2addd0 .word 0x3101bf03 */
/* @0x2addd4 ldrmi r3, [r0], -r1, lsl #6 */
/* @0x2addd8 cdphs p4, #0x0, c4, c1, c0, #0x3 */
/* @0x2adddc rsbsne r11, r6, r4, lsl pc */
/* @0x2adde0 ldrb r2, [r8, r0, lsl #13] */
/* @0x2adde4 stmdaeq r1, {r0, r8, r12, sp, lr, pc} */
/* @0x2adde8 ldmibeq r2, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^ */
/* @0x2addec strhs r2, [r0, -r0, lsl #13] */
/* @0x2addf0 andle r4, pc, r7, lsr #5 */
/* @0x2addf4 andle r4, r5, lr, lsr #4 */
/* @0x2addf8 .word 0x46414618 */
/* @0x2addfc .word 0xf608464a */
/* @0x2ade00 .word 0x4603ebde */
/* @0x2ade04 strbmi r2, [r8], #3585 */
/* @0x2ade08 svclt #0x14444b */
/* @0x2ade0c sxtab16hs r0, r0, r6, ror #16 */
/* @0x2ade10 strb r3, [sp, r1, lsl #14]! */
/* @0x2ade14 pop {r0, r1, r12, sp, pc} */
/* @0x2ade18 strdeq r8, r9, [r0], -r0 */
/* @0x2ade1c svcmi #0xf0e92d */
/* @0x2ade20 .word 0xf8dfb08f */
/* @0x2ade24 .word 0x4604a31c */
/* @0x2ade28 tstgt r8, #14614528 */
/* @0x2ade2c stmibvc r2!, {r8, r10, r12, sp, lr, pc} ^ */
/* @0x2ade30 .word 0xf8da44fa */
/* @0x2ade34 .word 0xf8d0a000 */
/* @0x2ade38 ldrbtmi r6, [r12], #432 */
/* @0x2ade3c .word 0x81e8f890 */
/* @0x2ade40 .word 0x3000f8da */
/* @0x2ade44 .word 0x0c08f10c */
/* @0x2ade48 ldrsbvc pc, [r4, -r0]! */
/* @0x2ade4c strlo r10, [r1], -r4, lsl #26 */
/* @0x2ade50 andge pc, r12, sp, asr #17 */
/* @0x2ade54 ldm r12!, {r0, r2, r3, r8, r9, r12, pc} */
/* @0x2ade58 strgt r0, [pc, #-0xf] */
/* @0x2ade5c muleq r7, r12, r8 */
/* @0x2ade60 andeq lr, r7, r5, lsl #17 */
/* @0x2ade64 msrhi SPSR_x, r0 */
/* @0x2ade68 svceq #0xf1b9 */
/* @0x2ade6c cmphi lr, r0 */
/* @0x2ade70 .word 0xf8d4a90e */
/* @0x2ade74 bl 0x2f658c <ps_hints_apply+0x518c> */
/* @0x2ade78 .word 0xf8940388 */
/* @0x2ade7c cdpne p1, #0x5, c8, c1, c15, #0x6 */
/* @0x2ade80 stclo p8, c15, [r8], #-332 */
/* @0x2ade84 svceq #0x2f1b8 */
/* @0x2ade88 .word 0xf503fb02 */
/* @0x2ade8c .word 0xf1059302 */
/* @0x2ade90 .word 0xd06930ff */
/* @0x2ade94 svceq #0x4f1b8 */
/* @0x2ade98 adcshi pc, pc, r0 */
/* @0x2ade9c svceq #0x1f1b8 */
/* @0x2adea0 tsthi r9, r0, asr #32 */
/* @0x2adea4 stclo p4, c15, [r0], {23} */
/* @0x2adea8 bicseq lr, r1, r6, lsl #22 */
/* @0x2adeac sbcseq lr, r0, r6, lsl #22 */
/* @0x2adeb0 movweq pc, #0x7105 */
/* @0x2adeb4 streq pc, [r7], -r2, lsl #2 */
/* @0x2adeb8 andhs sp, r0, #10 */
/* @0x2adebc streq pc, [r7], -r6 */
/* @0x2adec0 movweq pc, #0x7003 */
/* @0x2adec4 ldmlo pc!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^ */
/* @0x2adec8 .word 0xf04f9200 */
/* @0x2adecc and r0, r9, r7, lsl #24 */
/* @0x2aded0 bicsmi r4, r11, #-671088637 */
/* @0x2aded4 streq pc, [r7], -r6 */
/* @0x2aded8 movweq pc, #0x7003 */
/* @0x2adedc beq 0x4aa020 <SrcVerts+0x7064> */
/* @0x2adee0 andge pc, r0, sp, asr #17 */
/* @0x2adee4 .word 0xf8d42700 */
/* @0x2adee8 addsmi r2, r7, #196, #2 */
/* @0x2adeec .word 0xf891d232 */
/* @0x2adef0 blx 0x1511ef8 <b2_toiTime+0xdb8a54> */
/* @0x2adef4 .word 0xf009f906 */
/* @0x2adef8 .word 0xf8cd0901 */
/* @0x2adefc .word 0xf04f9004 */
/* @0x2adf00 bls 0x330308 */
/* @0x2adf04 ble 0x97f550 <b2_toiTime+0x2260ac> */
/* @0x2adf08 mulge r0, r0, r8 */
/* @0x2adf0c bleq 0x4aa620 <SrcVerts+0x7664> */
/* @0x2adf10 rsbsvc pc, pc, #74448896 */
/* @0x2adf14 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x2adf18 blx 0x5ac82a <g_SWFlineaavertbuff+0x59762> */
/* @0x2adf1c andeq lr, r10, #45056 */
/* @0x2adf20 .word 0xb004f8dd */
/* @0x2adf24 blx 0x3ac758 <error_g0017+0x53fc> */
/* @0x2adf28 beq 0x568838 <g_SWFlineaavertbuff+0x15770> */
/* @0x2adf2c .word 0xf8809a00 */
/* @0x2adf30 addsmi r10, r3, #0 */
/* @0x2adf34 .word 0xf100bf0a */
/* @0x2adf38 strbmi r3, [r3], #-255 */
/* @0x2adf3c strb r4, [r0, r3, ror #12]! */
/* @0x2adf40 .word 0xa000f8dd */
/* @0x2adf44 ldrbmi r3, [r6, #-0x701] */
/* @0x2adf48 .word 0xf101bf0a */
/* @0x2adf4c strbmi r3, [r6], #-511 */
/* @0x2adf50 strb r4, [r8, r6, ror #12] */
/* @0x2adf54 .word 0x31cff894 */
/* @0x2adf58 bicpl pc, r4, r4, asr #17 */
/* @0x2adf5c .word 0xf2402b07 */
/* @0x2adf60 ldmeq r11, {r5, r6, r7, pc} ^ */
/* @0x2adf64 sbcs r4, pc, sp, asr r3 */
/* @0x2adf68 stclo p4, c15, [r0], {23} */
/* @0x2adf6c orrseq lr, r1, r6, lsl #22 */
/* @0x2adf70 addseq lr, r0, r6, lsl #22 */
/* @0x2adf74 .word 0xf1029100 */
/* @0x2adf78 .word 0xf1050203 */
/* @0x2adf7c andle r0, r12, r3, lsl #6 */
/* @0x2adf80 andeq pc, r3, #2 */
/* @0x2adf84 movweq pc, #0x3003 */
/* @0x2adf88 stmdaeq r1, {r0, r1, r2, r3, r5, r6, r12, sp, lr, pc} */
/* @0x2adf8c stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x2adf90 subseq r0, r11, r6, asr r0 */
/* @0x2adf94 .word 0x0c06f04f */
/* @0x2adf98 bicsmi lr, r2, #9 */
/* @0x2adf9c .word 0xf00243db */
/* @0x2adfa0 .word 0xf0030603 */
/* @0x2adfa4 .word 0xf04f0303 */
/* @0x2adfa8 rsbseq r0, r6, r6, lsl #18 */
/* @0x2adfac smlsdhs r0, r11, r0, r0 */
/* @0x2adfb0 .word 0x21c4f8d4 */
/* @0x2adfb4 sbcle r4, sp, #1879048201 */
/* @0x2adfb8 stmdavc r10, {r8, r11, r12, pc} */
/* @0x2adfbc .word 0xf0024132 */
/* @0x2adfc0 andls r0, r1, #805306368 */
/* @0x2adfc4 stmdbls r2, {r9, sp} */
/* @0x2adfc8 ble 0x9be9f8 <b2_toiTime+0x265554> */
/* @0x2adfcc bleq 0x46a6e0 <g_RomDisk+0x72ec0> */
/* @0x2adfd0 bvc 0x12ab8e4 <b2_toiTime+0xb52440> */
/* @0x2adfd4 blx 0x5ac906 <g_SWFlineaavertbuff+0x5983e> */
/* @0x2adfd8 mulge r0, r0, r8 */
/* @0x2adfdc .word 0xf102454b */
/* @0x2adfe0 b 0x56e7ec <g_SWFlineaavertbuff+0x1b724> */
/* @0x2adfe4 .word 0xf8dd010a */
/* @0x2adfe8 blx 0x59a000 <g_SWFlineaavertbuff+0x46f38> */
/* @0x2adfec svclt #0x8fa03 */
/* @0x2adff0 b 0x12ff984 <b2_toiTime+0xba64e0> */
/* @0x2adff4 svclt #0x180a0a */
/* @0x2adff8 .word 0xf8804443 */
/* @0x2adffc svclt #0x8a000 */
/* @0x2ae000 rscslo pc, pc, r0, lsl #2 */
/* @0x2ae004 strbmi lr, [lr, #-0x7df] */
/* @0x2ae008 bls 0x2e2420 <_ZN15b2ContactSolver29InitializeVelocityConstraintsEv+0x88> */
/* @0x2ae00c blo 0x2ff9ac <TT_RunIns+0x2bb8> */
/* @0x2ae010 and r9, r0, r0, lsl #4 */
/* @0x2ae014 strlo r4, [r1, -r6, asr #8] */
/* @0x2ae018 .word 0xf417e7ca */
/* @0x2ae01c bl 0x43be24 <g_RomDisk+0x44604> */
/* @0x2ae020 bl 0x42e56c <g_RomDisk+0x36d4c> */
/* @0x2ae024 qaddls r0, r0, r0 */
/* @0x2ae028 andeq pc, r1, #-2147483648 */
/* @0x2ae02c movweq pc, #0x1105 */
/* @0x2ae030 .word 0xf002d00a */
/* @0x2ae034 .word 0xf0030201 */
/* @0x2ae038 .word 0xf04f0301 */
/* @0x2ae03c addseq r0, r6, r0, lsl #18 */
/* @0x2ae040 .word 0xf06f009b */
/* @0x2ae044 and r0, sp, r3, lsl #4 */
/* @0x2ae048 svceq #0x1f012 */
/* @0x2ae04c svclt #0x1446c1 */
/* @0x2ae050 strhs r2, [r4], -r0, lsl #12 */
/* @0x2ae054 movweq pc, #0x1013 */
/* @0x2ae058 svclt #0x154642 */
/* @0x2ae05c .word 0x469846b8 */
/* @0x2ae060 ldrmi r4, [r3], -r3, asr #12 */
/* @0x2ae064 .word 0x0c00f04f */
/* @0x2ae068 .word 0x71c4f8d4 */
/* @0x2ae06c .word 0xf4bf45bc */
/* @0x2ae070 stmdbls r0, {r0, r4, r5, r6, r8, r9, r10, r11, sp, pc} */
/* @0x2ae074 teqmi r7, pc, lsl #16 */
/* @0x2ae078 streq pc, [pc, -r7] */
/* @0x2ae07c strhs r9, [r0, -r1, lsl #14] */
/* @0x2ae080 addmi r9, pc, #32768 */
/* @0x2ae084 .word 0xf1c3da1c */
/* @0x2ae088 .word 0xf6400b04 */
/* @0x2ae08c blx 0x154c8d0 <b2_toiTime+0xdf342c> */
/* @0x2ae090 .word 0xf890fb0b */
/* @0x2ae094 strbmi r10, [r11, #-0x0] */
/* @0x2ae098 streq pc, [r1, -r7, lsl #2] */
/* @0x2ae09c .word 0x010aea0b */
/* @0x2ae0a0 .word 0xb004f8dd */
/* @0x2ae0a4 blx 0x3ac8d8 <error_g0017+0x557c> */
/* @0x2ae0a8 strbmi r11, [r3], -r8, lsl #30 */
/* @0x2ae0ac beq 0x5689b8 <g_SWFlineaavertbuff+0x158f0> */
/* @0x2ae0b0 ldmne r11, {r3, r4, r8, r9, r10, r11, r12, sp, pc} */
/* @0x2ae0b4 andge pc, r0, r0, lsl #17 */
/* @0x2ae0b8 .word 0xf100bf08 */
/* @0x2ae0bc .word 0xe7df30ff */
/* @0x2ae0c0 .word 0xd104454e */
/* @0x2ae0c4 strbmi r9, [r6], -r0, lsl #18 */
/* @0x2ae0c8 .word 0x91003901 */
/* @0x2ae0cc ldrmi lr, [r6], #-0 */
/* @0x2ae0d0 .word 0x0c01f10c */
/* @0x2ae0d4 b 0x16a7ffc <b2_toiTime+0xf4eb58> */
/* @0x2ae0d8 .word 0xf10d08d8 */
/* @0x2ae0dc strhs r0, [r0, -r12, lsr #20] */
/* @0x2ae0e0 stmdbvs r8, {r0, r8, r9, r11, r12, sp, lr, pc} */
/* @0x2ae0e4 strvs pc, [r0], -r8, lsl #22 */
/* @0x2ae0e8 .word 0x31c4f8d4 */
/* @0x2ae0ec .word 0xf4bf429f */
/* @0x2ae0f0 uasxmi r10, r0, r1 */
/* @0x2ae0f4 strbmi r4, [r2], -r9, asr #12 */
/* @0x2ae0f8 bleq 0x2ea23c <FT_Done_Memory+0x5c8> */
/* @0x2ae0fc b 0x1a6b924 <b2_toiTime+0x1312480> */
/* @0x2ae100 ldrmi r9, [r11, #0xb02] */
/* @0x2ae104 ldrtmi sp, [r0], -r9, lsl #20 */
/* @0x2ae108 .word 0x46424651 */
/* @0x2ae10c streq lr, [r6], -r8, asr #23 */
/* @0x2ae110 b 0x17eb938 <b2_toiTime+0x1092494> */
/* @0x2ae114 bleq 0x32a548 */
/* @0x2ae118 bl 0xff4e80e8 <b2_toiTime+0xfffffffffed8ec44> */
/* @0x2ae11c strlo r0, [r1, -r9, lsl #18] */
/* @0x2ae120 cmpmi sp, #59244544 */
/* @0x2ae124 stmeq sp!, {r0, r1, r2, r8, r10, r12, sp} ^ */
/* @0x2ae128 bicpl pc, r8, r4, asr #17 */
/* @0x2ae12c bls 0x614540 <g_SWFaavertbuff+0x41478> */
/* @0x2ae130 addsmi r6, r10, #720896 */
/* @0x2ae134 .word 0xf608d001 */
/* @0x2ae138 andlt lr, pc, lr, asr #20 */
/* @0x2ae13c svchi #0xf0e8bd */
/* @0x2ae140 andseq pc, r3, r4, lsr #22 */
/* @0x2ae144 andeq r1, lr, lr, lsr #23 */
/* @0x2ae148 svcmi #0xf8e92d */
/* @0x2ae14c bls 0x53f9a4 <obj_has_event+0x4e34> */
/* @0x2ae150 ldmdale r8!, {r2, r9, r11, sp} ^ */
/* @0x2ae154 .word 0xf002e8df */
/* @0x2ae158 tsths r5, sp, ror r3 */
/* @0x2ae15c bvc 0xff56e264 <b2_toiTime+0xfffffffffee14dc0> */
/* @0x2ae160 movwlo r6, #0x7848 */
/* @0x2ae164 stmne r2!, {r0, r1, r3, r4, r6, r7, r12} ^ */
/* @0x2ae168 strmi r4, [r10], #-601 */
/* @0x2ae16c addmi r4, r3, #12, #8 */
/* @0x2ae170 stclpl p2, c13, [r5], #20 */
/* @0x2ae174 strtmi r5, [r9], #-3281 */
/* @0x2ae178 movwlo r5, #0x14d1 */
/* @0x2ae17c pop {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2ae180 stmdavs r9, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} ^ */
/* @0x2ae184 addmi r2, r10, #0, #4 */
/* @0x2ae188 ldcpl p0, c13, [sp], {5} */
/* @0x2ae18c strtmi r5, [r8], #-3232 */
/* @0x2ae190 andlo r5, r1, #160, #8 */
/* @0x2ae194 pop {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2ae198 bvc 0xff4d2180 <b2_toiTime+0xfffffffffed78cdc> */
/* @0x2ae19c stmdavs sp, {r9, sp} ^ */
/* @0x2ae1a0 sbcne r3, r0, r7 */
/* @0x2ae1a4 addmi r1, r2, #184320 */
/* @0x2ae1a8 ldcpl p0, c13, [lr], {6} */
/* @0x2ae1ac bl 0x305438 <TT_New_Context+0x5230> */
/* @0x2ae1b0 strtpl r0, [r1], #342 */
/* @0x2ae1b4 ldrb r3, [r6, r1, lsl #4]! */
/* @0x2ae1b8 ldrmi r1, [r10], #-2208 */
/* @0x2ae1bc adcmi r2, r9, #0, #2 */
/* @0x2ae1c0 mrrcpl p0, #0x0, sp, r6, c8 */
/* @0x2ae1c4 ldrtmi r5, [r3], #-3171 */
/* @0x2ae1c8 bl 0x4452e8 <g_RomDisk+0x4dac8> */
/* @0x2ae1cc strbpl r0, [r3], #-851 */
/* @0x2ae1d0 ldrb r3, [r4, r1, lsl #2]! */
/* @0x2ae1d4 svchi #0xf8e8bd */
/* @0x2ae1d8 stmdavs r10, {r3, r6, r7, r9, r11, r12, sp, lr} ^ */
/* @0x2ae1dc sbcne r3, r0, r7 */
/* @0x2ae1e0 stmdbeq r2, {r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x2ae1e4 addmi r2, r2, #0, #4 */
/* @0x2ae1e8 ldcpl p0, c13, [sp], {5} */
/* @0x2ae1ec strtmi r5, [r9], #-3233 */
/* @0x2ae1f0 andlo r5, r1, #-1593835520 */
/* @0x2ae1f4 stmne r5!, {r0, r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2ae1f8 beq 0x368e0c <_ZTS12CDS_Priority+0xae64> */
/* @0x2ae1fc strbmi r2, [r10, #-0x200] */
/* @0x2ae200 ldcpl p0, c13, [r8], {31} */
/* @0x2ae204 .word 0xf81a5ca1 */
/* @0x2ae208 bne 0x686218 <g_SWFlinevertbuff+0x33150> */
/* @0x2ae20c bleq 0x469114 <g_RomDisk+0x718f4> */
/* @0x2ae210 vstmiavc r7!, {s29, s30, s31} */
/* @0x2ae214 vstmiavc r7!, {d30, d31} */
/* @0x2ae218 stmvc r11!, {r0, r1, r3, r7, r9, r11, sp, lr, pc} ^ */
/* @0x2ae21c stmvc r11!, {r3, r5, r7, r8, r9, r11, sp, lr, pc} ^ */
/* @0x2ae220 svchs #0x445f */
/* @0x2ae224 rsbsmi r11, pc, #184, #30 */
/* @0x2ae228 .word 0xdc0145e0 */
/* @0x2ae22c stcle p5, c4, [r3, #-736] */
/* @0x2ae230 svclt #0xcc45bc */
/* @0x2ae234 ldrtmi r4, [r1], -r1, lsl #12 */
/* @0x2ae238 strmi r5, [r1], #-3240 */
/* @0x2ae23c andlo r5, r1, #-1459617792 */
/* @0x2ae240 pop {r0, r2, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x2ae244 stmdbmi r4, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x2ae248 .word 0xf7f84479 */
/* @0x2ae24c movwhs pc, #0x913 */
/* @0x2ae250 pop {r0, r1, r5, r12, sp, lr} */
/* @0x2ae254 svclt #0x8ff8 */
/* @0x2ae258 strheq pc, [sp], -r4 */
/* @0x2ae25c .word 0x4604b5f0 */
/* @0x2ae260 adclt r4, r1, r5, lsl #29 */
/* @0x2ae264 ldrbtmi r10, [lr], #-3332 */
/* @0x2ae268 streq pc, [r4, -r6, lsl #2]! */
/* @0x2ae26c strgt r12, [pc, #-0xf0f] */
/* @0x2ae270 muleq r7, r7, r8 */
/* @0x2ae274 streq pc, [r8, -r6, lsl #2] */
/* @0x2ae278 andeq lr, r7, r5, lsl #17 */
/* @0x2ae27c svcgt #0xfad0b */
/* @0x2ae280 ldm r7, {r0, r1, r2, r3, r8, r10, lr, pc} */
/* @0x2ae284 .word 0xf1060007 */
/* @0x2ae288 ldrblo r0, [r12], -r0, asr #14 */
/* @0x2ae28c andeq lr, r7, r5, lsl #17 */
/* @0x2ae290 svcgt #0xfad12 */
/* @0x2ae294 ldm r7, {r0, r1, r2, r3, r8, r10, lr, pc} */
/* @0x2ae298 stm r5, {r0, r1, r2} */
/* @0x2ae29c ldcge p0, c0, [r9, #-28] */
/* @0x2ae2a0 strgt r12, [pc, #-0xe0f] */
/* @0x2ae2a4 muleq r7, r6, r8 */
/* @0x2ae2a8 .word 0x31a8f8d4 */
/* @0x2ae2ac .word 0xf8c43301 */
/* @0x2ae2b0 stm r5, {r3, r5, r7, r8, r12, sp} */
/* @0x2ae2b4 .word 0xf8d40007 */
/* @0x2ae2b8 addsmi r2, r3, #148, #2 */
/* @0x2ae2bc sbcshi pc, r10, r0, asr #1 */
/* @0x2ae2c0 .word 0x31e7f894 */
/* @0x2ae2c4 eorsle r2, r12, r0, lsl #22 */
/* @0x2ae2c8 ldrsbhs pc, [r12, r4] */
/* @0x2ae2cc .word 0xf8d42100 */
/* @0x2ae2d0 .word 0xf8c401ac */
/* @0x2ae2d4 andlo r1, r1, #168, #2 */
/* @0x2ae2d8 stmdb r10!, {r3, r9, r10, r12, sp, lr, pc} ^ */
/* @0x2ae2dc .word 0x51e8f894 */
/* @0x2ae2e0 rsclt r3, sp, #4194304 */
/* @0x2ae2e4 stmdble r2, {r1, r2, r8, r10, r11, sp} */
/* @0x2ae2e8 mvnpl pc, r4, lsl #17 */
/* @0x2ae2ec blge 0xae6398 <b2_toiTime+0x38cef4> */
/* @0x2ae2f0 streq lr, [r5], r3, lsl #22 */
/* @0x2ae2f4 .word 0x318cf8d4 */
/* @0x2ae2f8 mrrcne p8, #0x5, pc, r4, c6 */
/* @0x2ae2fc ldmdane r8, {r0, r8, r9, r11, r12, sp} ^ */
/* @0x2ae300 ldcllo p8, c15, [r0], #-344 */
/* @0x2ae304 .word 0xf06a1ac0 */
/* @0x2ae308 .word 0xf8d4eca0 */
/* @0x2ae30c .word 0x079a3134 */
/* @0x2ae310 .word 0xf8c44607 */
/* @0x2ae314 .word 0xf10001a4 */
/* @0x2ae318 .word 0xf8d480ab */
/* @0x2ae31c .word 0xf8563190 */
/* @0x2ae320 bllo 0x2f5398 <ps_hints_apply+0x3f98> */
/* @0x2ae324 ldchs p8, c15, [r8], #-344 */
/* @0x2ae328 bne 0xfe2b4490 <b2_toiTime+0xfffffffffdb5afec> */
/* @0x2ae32c stc p0, c15, [r12], {106} */
/* @0x2ae330 sbcslt r1, r11, #27392 */
/* @0x2ae334 orrseq pc, r4, r4, asr #17 */
/* @0x2ae338 .word 0xf0402f00 */
/* @0x2ae33c sadd8mi r8, sp, r9 */
/* @0x2ae340 .word 0xf8d4e7d0 */
/* @0x2ae344 .word 0x069b3130 */
/* @0x2ae348 blmi 0x15e3540 <b2_toiTime+0xe8a09c> */
/* @0x2ae34c ldrbtmi r10, [r11], #-3330 */
/* @0x2ae350 ldmdbvc r11, {r3, r4, r11, sp, lr} */
/* @0x2ae354 .word 0xf88d9002 */
/* @0x2ae358 .word 0xf10d300c */
/* @0x2ae35c .word 0xf8c40307 */
/* @0x2ae360 movwhs r3, #0x1144 */
/* @0x2ae364 smlalbtlo pc, r8, r4, r8 */
/* @0x2ae368 ldrsblo pc, [r12, -r4]! */
/* @0x2ae36c svcmi #0x44bb9b */
/* @0x2ae370 .word 0xf504447f */
/* @0x2ae374 .word 0xf8d476f0 */
/* @0x2ae378 stmiblt r3!, {r4, r6, r7, r8, r12, sp} */
/* @0x2ae37c qadd16mi r4, r0, r9 */
/* @0x2ae380 stc2 p7, c15, [r8], {253} */
/* @0x2ae384 .word 0xf7ff4620 */
/* @0x2ae388 qadd16mi pc, r9, sp */
/* @0x2ae38c .word 0xf8c42204 */
/* @0x2ae390 .word 0x463001d0 */
/* @0x2ae394 mrrc p6, #0x0, pc, r4, c8 */
/* @0x2ae398 rscle r2, r12, r0, lsl #16 */
/* @0x2ae39c ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x2ae3a0 .word 0xf844f7f8 */
/* @0x2ae3a4 .word 0xf8d4e7e5 */
/* @0x2ae3a8 qsub16mi r2, r0, r4 */
/* @0x2ae3ac ldrsbne pc, [r0, #-132]! */
/* @0x2ae3b0 .word 0xf8c4429a */
/* @0x2ae3b4 .word 0xf8c4213c */
/* @0x2ae3b8 svclt #0x881138 */
/* @0x2ae3bc teqlo r12, r4, asr #17 */
/* @0x2ae3c0 ldrsbhs pc, [r12, -r4]! */
/* @0x2ae3c4 stc2 p7, c15, [r2], #-1012 */
/* @0x2ae3c8 ldrsbhs pc, [r0, #132] */
/* @0x2ae3cc ldrsblo pc, [r12, -r4]! */
/* @0x2ae3d0 .word 0xf8c41ad3 */
/* @0x2ae3d4 .word 0xf50431d0 */
/* @0x2ae3d8 swphs r7, r12, [r1] */
/* @0x2ae3dc b 0x26bc04 <pcre_compile+0x2c7c> */
/* @0x2ae3e0 .word 0xd10c2801 */
/* @0x2ae3e4 .word 0x3148f8d4 */
/* @0x2ae3e8 .word 0xf8d4b12b */
/* @0x2ae3ec ldmdblt r3, {r2, r3, r4, r5, r8, r12, sp} */
/* @0x2ae3f0 ldrsblo pc, [r0, #132] */
/* @0x2ae3f4 stmdbmi r3!, {r0, r1, r3, r4, r5, r7, r8, r12, sp, pc} */
/* @0x2ae3f8 ldrbtmi r4, [r9], #-1568 */
/* @0x2ae3fc .word 0xb148e011 */
/* @0x2ae400 ldrsblo pc, [r0, #-132] */
/* @0x2ae404 stmdbmi r0!, {r0, r1, r4, r8, r11, r12, sp, pc} */
/* @0x2ae408 and r4, r0, r9, ror r4 */
/* @0x2ae40c qadd16mi r4, r0, r9 */
/* @0x2ae410 .word 0xf80cf7f8 */
/* @0x2ae414 .word 0x3148f8d4 */
/* @0x2ae418 .word 0xd1a52b00 */
/* @0x2ae41c qadd16mi r4, r0, r11 */
/* @0x2ae420 .word 0xf7f84479 */
/* @0x2ae424 .word 0xf8d4f827 */
/* @0x2ae428 .word 0xf043312c */
/* @0x2ae42c .word 0xf8c40308 */
/* @0x2ae430 .word 0xf8d4312c */
/* @0x2ae434 .word 0xf0433130 */
/* @0x2ae438 .word 0xf8c40320 */
/* @0x2ae43c movwhs r3, #0x130 */
/* @0x2ae440 smlalbtlo pc, r8, r4, r8 */
/* @0x2ae444 ldrsblo pc, [r0, #132] */
/* @0x2ae448 .word 0xf8d4b913 */
/* @0x2ae44c .word 0xb123313c */
/* @0x2ae450 strtmi r4, [r0], -pc, lsl #18 */
/* @0x2ae454 .word 0xf7f84479 */
/* @0x2ae458 .word 0xf504f80d */
/* @0x2ae45c .word 0xf608709c */
/* @0x2ae460 .word 0xf8d4ed70 */
/* @0x2ae464 .word 0xf043312c */
/* @0x2ae468 .word 0xf8c40308 */
/* @0x2ae46c and r3, r1, r12, lsr #2 */
/* @0x2ae470 mvnpl pc, r4, lsl #17 */
/* @0x2ae474 ldcllt p0, c11, [r0, #132]! */
/* @0x2ae478 andeq r1, lr, r2, lsl #15 */
/* @0x2ae47c muleq lr, r10, r6 */
/* @0x2ae480 andeq lr, sp, r4, lsl r5 */
/* @0x2ae484 andeq lr, sp, r0, lsr #9 */
/* @0x2ae488 andeq pc, sp, r6, lsl r6 */
/* @0x2ae48c andeq lr, sp, r10, ror r4 */
/* @0x2ae490 .word 0x000df5de */
/* @0x2ae494 .word 0x4604b5f0 */
/* @0x2ae498 addlt r4, pc, r4, lsl #29 */
/* @0x2ae49c uqsub16mi r4, sp, lr */
/* @0x2ae4a0 streq pc, [r4, -r6, lsl #2]! */
/* @0x2ae4a4 svcgt #0xf3608 */
/* @0x2ae4a8 ldm r7, {r0, r1, r2, r3, r8, r10, lr, pc} */
/* @0x2ae4ac stm r5, {r0, r1, r2} */
/* @0x2ae4b0 stcge p0, c0, [r7, #-28] */
/* @0x2ae4b4 strgt r12, [pc, #-0xe0f] */
/* @0x2ae4b8 ldm r6, {r8, r9, sp} */
/* @0x2ae4bc .word 0xf8c40007 */
/* @0x2ae4c0 stm r5, {r2, r3, r4, r5, r8, r12, sp} */
/* @0x2ae4c4 strtmi r0, [r0], -r7 */
/* @0x2ae4c8 mrc2 p7, #0x2, apsr_nzcv, c6, c12, #0x7 */
/* @0x2ae4cc .word 0x21e7f894 */
/* @0x2ae4d0 ldrsbpl pc, [r4, -r4]! */
/* @0x2ae4d4 ldrsblo pc, [r0, r4] */
/* @0x2ae4d8 .word 0x618cf8d4 */
/* @0x2ae4dc streq r11, [r10, r2, asr #3]! */
/* @0x2ae4e0 svclt #0x58aa0e */
/* @0x2ae4e4 .word 0xf1063307 */
/* @0x2ae4e8 svclt #0x5830ff */
/* @0x2ae4ec .word 0xf8c408db */
/* @0x2ae4f0 .word 0xf8943194 */
/* @0x2ae4f4 bl 0x33ac9c */
/* @0x2ae4f8 .word 0xf8530383 */
/* @0x2ae4fc .word 0xf8531c1c */
/* @0x2ae500 strmi r3, [r8], #-3128 */
/* @0x2ae504 .word 0xf06a1ac0 */
/* @0x2ae508 .word 0xf8c4eba0 */
/* @0x2ae50c and r0, r3, r4, lsr #3 */
/* @0x2ae510 orrslo pc, r4, r4, asr #17 */
/* @0x2ae514 .word 0x61a4f8c4 */
/* @0x2ae518 .word 0xf894076f */
/* @0x2ae51c strle r0, [r4, #-0x1ed] */
/* @0x2ae520 .word 0x31ebf894 */
/* @0x2ae524 svclt #0x982b07 */
/* @0x2ae528 .word 0xf4152008 */
/* @0x2ae52c andsle r5, r12, r0, lsl #15 */
/* @0x2ae530 .word 0x31eaf894 */
/* @0x2ae534 .word 0xd1062b03 */
/* @0x2ae538 ldrheq pc, [lr, #132] */
/* @0x2ae53c svclt #0xc2800 */
/* @0x2ae540 eorhs r2, r0, r8, lsl r0 */
/* @0x2ae544 ldmdblt r11!, {r0, r4, sp, lr, pc} */
/* @0x2ae548 ldrhlo pc, [lr, #132] */
/* @0x2ae54c svclt #0xb82808 */
/* @0x2ae550 cmplt r3, r8 */
/* @0x2ae554 and r0, r8, r0, asr #32 */
/* @0x2ae558 .word 0xd1062b02 */
/* @0x2ae55c ldrhlo pc, [lr, #132] */
/* @0x2ae560 addeq r11, r0, r11, lsl r1 */
/* @0x2ae564 .word 0xf06a2103 */
/* @0x2ae568 .word 0xf415ebd4 */
/* @0x2ae56c andsle r4, r1, r0, lsl #4 */
/* @0x2ae570 .word 0x31eaf894 */
/* @0x2ae574 andle r2, r12, r3, lsl #22 */
/* @0x2ae578 stmdahs r8, {r0, r1, r5, r8, r11, r12, sp, pc} */
/* @0x2ae57c eorhs r11, r0, r12, asr #31 */
/* @0x2ae580 and r2, r7, r0, lsl r0 */
/* @0x2ae584 .word 0xd1052b02 */
/* @0x2ae588 svclt #0xcc2820 */
/* @0x2ae58c eorhs r2, r0, r0, asr #32 */
/* @0x2ae590 eorhs lr, r0, r0 */
/* @0x2ae594 ldrle r0, [r8, #-0x469] */
/* @0x2ae598 ldrhlo pc, [lr, #132] */
/* @0x2ae59c stmdblt r7!, {r0, r1, r8, r12, sp, pc} */
/* @0x2ae5a0 .word 0xf894b91a */
/* @0x2ae5a4 blhs 0x3bad54 <error_g0017+0x139f8> */
/* @0x2ae5a8 ldmdahs r0, {r2, r8, r12, lr, pc} */
/* @0x2ae5ac subhs r11, r0, r12, asr #31 */
/* @0x2ae5b0 and r2, r10, r0, lsr #32 */
/* @0x2ae5b4 .word 0xdc042808 */
/* @0x2ae5b8 svclt #0x142b06 */
/* @0x2ae5bc eorhs r2, r0, r8, lsl r0 */
/* @0x2ae5c0 blhs 0x4665d4 <g_RomDisk+0x6edb4> */
/* @0x2ae5c4 eorshs r11, r0, r4, lsl pc */
/* @0x2ae5c8 rsceq r2, r11, #64 */
/* @0x2ae5cc .word 0xf894d508 */
/* @0x2ae5d0 .word 0xf8942128 */
/* @0x2ae5d4 blx 0x73aa82 <g_SWFvertbuff+0x679ba> */
/* @0x2ae5d8 addsmi pc, r8, #201326592 */
/* @0x2ae5dc .word 0x4618bfb8 */
/* @0x2ae5e0 stmdahs r7, {r0, r1, r2, r9, r10, r12, sp} */
/* @0x2ae5e4 streq pc, [r7], -r6, lsr #32 */
/* @0x2ae5e8 stmeq r5, {r3, r6, r7, r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x2ae5ec msrlo APSR_nzcvq, #212, #16 */
/* @0x2ae5f0 blx 0x45e55a <g_RomDisk+0x66d3a> */
/* @0x2ae5f4 .word 0xf100f500 */
/* @0x2ae5f8 svclt #0xcc0007 */
/* @0x2ae5fc stmeq sp!, {r0, r2, r4, r5, r6, r8, r9, lr} ^ */
/* @0x2ae600 bl 0x3fba0c <g_RomDisk+0x41ec> */
/* @0x2ae604 ldrlo r0, [r0, #-0x5e0]! */
/* @0x2ae608 ldmdble sp, {r0, r2, r3, r4, r7, r9, lr} */
/* @0x2ae60c .word 0xf8d44620 */
/* @0x2ae610 .word 0xf7f812f4 */
/* @0x2ae614 .word 0xf894fb73 */
/* @0x2ae618 strtmi r3, [r0], -r7, ror #3 */
/* @0x2ae61c tstlt r3, r9, lsr #12 */
/* @0x2ae620 blx 0x196c60a <b2_toiTime+0x1213166> */
/* @0x2ae624 .word 0xf7f8e001 */
/* @0x2ae628 .word 0xf8c4fb3b */
/* @0x2ae62c .word 0xf8d402f4 */
/* @0x2ae630 .word 0xf8c432f4 */
/* @0x2ae634 .word 0xf1035328 */
/* @0x2ae638 .word 0xf002020f */
/* @0x2ae63c .word 0xf1c2020f */
/* @0x2ae640 ldrmi r0, [r3], #-544 */
/* @0x2ae644 asrslo pc, r4, #17 */
/* @0x2ae648 ldrsblo pc, [r12, r4] */
/* @0x2ae64c .word 0xd1043301 */
/* @0x2ae650 qadd16mi r4, r0, r7 */
/* @0x2ae654 .word 0xf7f74479 */
/* @0x2ae658 .word 0xf8d4fee9 */
/* @0x2ae65c mrrcne p1, #0x9, r3, r10, c12 */
/* @0x2ae660 msrlo APSR_nzcvqg, #212, #16 */
/* @0x2ae664 ldmdble r1, {r1, r3, r4, r7, r9, lr} */
/* @0x2ae668 .word 0xf8d44620 */
/* @0x2ae66c .word 0xf7f811ac */
/* @0x2ae670 .word 0xf8d4fb45 */
/* @0x2ae674 qadd8mi r1, r0, r12 */
/* @0x2ae678 .word 0xf7f83101 */
/* @0x2ae67c .word 0xf8d4fb11 */
/* @0x2ae680 movwlo r3, #0x119c */
/* @0x2ae684 msrlo APSR_nzcvqg, #196, #16 */
/* @0x2ae688 .word 0x01acf8c4 */
/* @0x2ae68c ldrsbhs pc, [r12, r4] */
/* @0x2ae690 .word 0xf8d42100 */
/* @0x2ae694 andlo r0, r1, #172, #2 */
/* @0x2ae698 svc #0x8af607 */
/* @0x2ae69c ldrsblo pc, [r0, -r4]! */
/* @0x2ae6a0 movteq pc, #0x43 */
/* @0x2ae6a4 teqlo r0, r4, asr #17 */
/* @0x2ae6a8 ldcllt p0, c11, [r0, #60]! */
/* @0x2ae6ac andeq r1, lr, r12, asr #10 */
/* @0x2ae6b0 .word 0x000df3f5 */
/* @0x2ae6b4 .word 0xb161b168 */
/* @0x2ae6b8 .word 0xf8c16813 */
/* @0x2ae6bc ldmdavs r3, {r1, r3, r4, r6, r12, sp} ^ */
/* @0x2ae6c0 subslo pc, lr, r1, asr #17 */
/* @0x2ae6c4 .word 0xf8a18913 */
/* @0x2ae6c8 stmvs r11, {r1, r5, r6, r12, sp} */
/* @0x2ae6cc hinteq #0x43 */
/* @0x2ae6d0 ldrbmi r6, [r0, -r11, lsl #1]! */
/* @0x2ae6d4 andeq r0, r0, r0 */
/* @0x2ae6d8 blhi 0x469b94 <g_RomDisk+0x72374> */
/* @0x2ae6dc blhs 0x9297f0 <b2_toiTime+0x1d034c> */
/* @0x2ae6e0 blhi 0x469d5c <g_RomDisk+0x7253c> */
/* @0x2ae6e4 bleq 0x4e9d60 <SrcVerts+0x46da4> */
/* @0x2ae6e8 blne 0x569d64 <g_SWFlineaavertbuff+0x16c9c> */
/* @0x2ae6ec blhs 0x5e9d68 <g_SWFaavertbuff+0x16ca0> */
/* @0x2ae6f0 bllo 0x669d6c <g_SWFlinevertbuff+0x16ca4> */
/* @0x2ae6f4 blmi 0x6e9d70 <g_SWFvertbuff+0x16ca8> */
/* @0x2ae6f8 blpl 0x769d74 <b2_toiTime+0x108d0> */
/* @0x2ae6fc rsble r2, r7, r0, lsl #16 */
/* @0x2ae700 rsble r2, r5, r0, lsl #18 */
/* @0x2ae704 blvc 0xff52a2e8 <b2_toiTime+0xfffffffffedd0e44> */
/* @0x2ae708 blvs 0xfa9d8c <b2_toiTime+0x8508e8> */
/* @0x2ae70c .word 0xf043688b */
/* @0x2ae710 addvs r0, r11, r4, lsl #6 */
/* @0x2ae714 bvc 0xae9e20 <b2_toiTime+0x39097c> */
/* @0x2ae718 blvc 0xff4ea2fc <b2_toiTime+0xfffffffffed90e58> */
/* @0x2ae71c bvc 0xb29e28 <b2_toiTime+0x3d0984> */
/* @0x2ae720 blvc 0xff2ea304 <b2_toiTime+0xfffffffffeb90e60> */
/* @0x2ae724 bvc 0xb69e30 <b2_toiTime+0x41098c> */
/* @0x2ae728 blvc 0xff32a30c <b2_toiTime+0xfffffffffebd0e68> */
/* @0x2ae72c bvc 0xba9e38 <b2_toiTime+0x450994> */
/* @0x2ae730 blvc 0xff36a314 <b2_toiTime+0xfffffffffec10e70> */
/* @0x2ae734 bvc 0xbe9e40 <b2_toiTime+0x49099c> */
/* @0x2ae738 blvc 0xff3aa31c <b2_toiTime+0xfffffffffec50e78> */
/* @0x2ae73c bvc 0xc29e48 <b2_toiTime+0x4d09a4> */
/* @0x2ae740 blvc 0xff3ea324 <b2_toiTime+0xfffffffffec90e80> */
/* @0x2ae744 bvc 0xc69e50 <b2_toiTime+0x5109ac> */
/* @0x2ae748 blvc 0xff42a32c <b2_toiTime+0xfffffffffecd0e88> */
/* @0x2ae74c bvc 0xca9e58 <b2_toiTime+0x5509b4> */
/* @0x2ae750 blvc 0x2ea230 <FT_Done_Memory+0x5bc> */
/* @0x2ae754 blge 0x14aa21c <b2_toiTime+0xd50d78> */
/* @0x2ae758 blge 0x469f84 <g_RomDisk+0x72764> */
/* @0x2ae75c blls 0xff56a258 <b2_toiTime+0xfffffffffee10db4> */
/* @0x2ae760 blge 0x14aa228 <b2_toiTime+0xd50d84> */
/* @0x2ae764 bls 0x12e9d70 <b2_toiTime+0xb908cc> */
/* @0x2ae768 blge 0x469f70 <g_RomDisk+0x72750> */
/* @0x2ae76c bleq 0xff56a268 <b2_toiTime+0xfffffffffee10dc4> */
/* @0x2ae770 beq 0x1369d7c <b2_toiTime+0xc108d8> */
/* @0x2ae774 bleq 0x14aa23c <b2_toiTime+0xd50d98> */
/* @0x2ae778 bleq 0x469f84 <g_RomDisk+0x72764> */
/* @0x2ae77c blne 0xff2ea278 <b2_toiTime+0xfffffffffeb90dd4> */
/* @0x2ae780 bne 0x13a9d8c <b2_toiTime+0xc508e8> */
/* @0x2ae784 blne 0x14aa24c <b2_toiTime+0xd50da8> */
/* @0x2ae788 blne 0x469f98 <g_RomDisk+0x72778> */
/* @0x2ae78c blhs 0xff32a288 <b2_toiTime+0xfffffffffebd0de4> */
/* @0x2ae790 bhs 0x13e9d9c <b2_toiTime+0xc908f8> */
/* @0x2ae794 blhs 0x14aa25c <b2_toiTime+0xd50db8> */
/* @0x2ae798 blhs 0x469fac <g_RomDisk+0x7278c> */
/* @0x2ae79c bllo 0xff36a298 <b2_toiTime+0xfffffffffec10df4> */
/* @0x2ae7a0 blls 0x14aa268 <b2_toiTime+0xd50dc4> */
/* @0x2ae7a4 blo 0x1429db0 <b2_toiTime+0xcd090c> */
/* @0x2ae7a8 bllo 0x14aa270 <b2_toiTime+0xd50dcc> */
/* @0x2ae7ac blls 0x469fd4 <g_RomDisk+0x727b4> */
/* @0x2ae7b0 bllo 0x469fc8 <g_RomDisk+0x727a8> */
/* @0x2ae7b4 blvc 0x469fd0 <g_RomDisk+0x727b0> */
/* @0x2ae7b8 blhi 0xff52a2b4 <b2_toiTime+0xfffffffffedd0e10> */
/* @0x2ae7bc blmi 0xff3aa2b8 <b2_toiTime+0xfffffffffec50e14> */
/* @0x2ae7c0 bhi 0x1329dcc <b2_toiTime+0xbd0928> */
/* @0x2ae7c4 blvc 0xff4aa2c0 <b2_toiTime+0xfffffffffed50e1c> */
/* @0x2ae7c8 bmi 0x1469dd4 <b2_toiTime+0xd10930> */
/* @0x2ae7cc bvc 0x14a9dd8 <b2_toiTime+0xd50934> */
/* @0x2ae7d0 blhi 0x469acc <g_RomDisk+0x722ac> */
/* @0x2ae7d4 svclt #0x4770 */
/* @0x2ae7d8 andeq r0, r0, r0 */
/* @0x2ae7dc rscsmi r6, r8, r0, lsl #20 */
/* @0x2ae7e0 cdpmi p9, #0xf, c14, c0, c13, #0x1 */
/* @0x2ae7e4 strmi r11, [r12], -r6, lsl #1 */
/* @0x2ae7e8 .word 0x469a4693 */
/* @0x2ae7ec ldrsbtls pc, [r8], -sp */
/* @0x2ae7f0 cdpls p15, #0x1, c9, c0, c15, #0x0 */
/* @0x2ae7f4 stmdahs r0, {r0, r4, r8, r10, r11, r12, pc} */
/* @0x2ae7f8 stmdbhs r0, {r0, r1, r2, r4, r5, r6, r12, lr, pc} */
/* @0x2ae7fc blls 0x7629d8 <b2_toiTime+0x9534> */
/* @0x2ae800 smladls r0, r1, r6, r4 */
/* @0x2ae804 .word 0x96014652 */
/* @0x2ae808 blls 0x79341c <b2_toiTime+0x39f78> */
/* @0x2ae80c movwls r9, #0x4502 */
/* @0x2ae810 .word 0xf7f7464b */
/* @0x2ae814 stmdahs r0, {r0, r3, r5, r10, r11, r12, sp, lr, pc} */
/* @0x2ae818 cdp p0, #0x0, c13, c5, c7, #0x3 */
/* @0x2ae81c vldr s22, [pc, #576] */
/* @0x2ae820 blls 0x74d4f8 <g_SWFvertbuff+0x7a430> */
/* @0x2ae824 blvs 0xffc2a30c <b2_toiTime+0xffffffffff4d0e68> */
/* @0x2ae828 smlabtlt r0, r4, r8, pc */
/* @0x2ae82c bge 0xfe6ea048 <b2_toiTime+0xfffffffffdf90ba4> */
/* @0x2ae830 smlabtge r4, r4, r8, pc */
/* @0x2ae834 tstlo r8, r4, asr #17 */
/* @0x2ae838 .word 0xf8c49b13 */
/* @0x2ae83c .word 0xf8c49108 */
/* @0x2ae840 .word 0xf8c4710c */
/* @0x2ae844 mcr p1, #0x4, r3, c6, c12, #0x0 */
/* @0x2ae848 .word 0xf8c46b07 */
/* @0x2ae84c .word 0xf8c46110 */
/* @0x2ae850 mrc p1, #0x5, r5, c7, c4, #0x0 */
/* @0x2ae854 vstr d6, [r4, #792] */
/* @0x2ae858 .word 0xeeb86a20 */
/* @0x2ae85c vmls.f64 d6, d21, d21 */
/* @0x2ae860 .word 0xee869a90 */
/* @0x2ae864 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae868 vstr d6, [r4, #792] */
/* @0x2ae86c .word 0xeeb86a21 */
/* @0x2ae870 vmls.f64 d6, d21, d21 */
/* @0x2ae874 .word 0xee867a90 */
/* @0x2ae878 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae87c vstr d6, [r4, #792] */
/* @0x2ae880 .word 0xeeb86a22 */
/* @0x2ae884 vmls.f64 d6, d21, d21 */
/* @0x2ae888 .word 0xee866a90 */
/* @0x2ae88c vmov.f64 d6, #1.437500e+00 */
/* @0x2ae890 vstr d6, [r4, #792] */
/* @0x2ae894 .word 0xeeb86a23 */
/* @0x2ae898 vmls.f64 d6, d21, d21 */
/* @0x2ae89c .word 0xee865a90 */
/* @0x2ae8a0 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae8a4 vstr d6, [r4, #792] */
/* @0x2ae8a8 .word 0xeeb86a24 */
/* @0x2ae8ac vldr d22, [sp, #916] */
/* @0x2ae8b0 .word 0xee865a12 */
/* @0x2ae8b4 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae8b8 vstr d6, [r4, #792] */
/* @0x2ae8bc .word 0xeeb86a25 */
/* @0x2ae8c0 vmls.f64 d6, d21, d21 */
/* @0x2ae8c4 stmvs r3!, {r4, r7, r9, r11, r12, sp} */
/* @0x2ae8c8 movweq pc, #0x4043 */
/* @0x2ae8cc cdp p0, #0x8, c6, c6, c3, #0x5 */
/* @0x2ae8d0 vmov.f64 d6, #1.437500e+00 */
/* @0x2ae8d4 vstr d6, [r4, #792] */
/* @0x2ae8d8 .word 0xeeb86a26 */
/* @0x2ae8dc .word 0xee866be5 */
/* @0x2ae8e0 vmov.f64 d7, #1.437500e+00 */
/* @0x2ae8e4 vstr d7, [r4, #796] */
/* @0x2ae8e8 andlt r7, r6, r7, lsr #20 */
/* @0x2ae8ec mrchi p8, #0x7, lr, c0, c13, #0x5 */
/* @0x2ae8f0 andeq r0, r0, r0 */
/* @0x2ae8f4 rscsmi r6, r8, r0, lsl #20 */
/* @0x2ae8f8 stc p5, c11, [sp, #-224]! */
/* @0x2ae8fc strmi r8, [r12], -r2, lsl #22 */
/* @0x2ae900 blhs 0x8a9a14 <b2_toiTime+0x150570> */
/* @0x2ae904 .word 0xb3684605 */
/* @0x2ae908 ldc p3, c11, [pc, #388] */
/* @0x2ae90c .word 0xeeb48b19 */
/* @0x2ae910 vsqrt.f64 d23, d8 */
/* @0x2ae914 vstrle s30, [r5, #-64] */
/* @0x2ae918 ldrbtmi r4, [r9], #-2329 */
/* @0x2ae91c stc2 p7, c15, [r10, #988]! */
/* @0x2ae920 blvc 0x14ea3e8 <b2_toiTime+0xd90f44> */
/* @0x2ae924 blpl 0x7e9fa8 <b2_toiTime+0x90b04> */
/* @0x2ae928 cdp p8, #0xf, c6, c7, c3, #0x5 */
/* @0x2ae92c .word 0xf0436bc7 */
/* @0x2ae930 adcvs r0, r3, r1, lsl #6 */
/* @0x2ae934 bvs 0x56a04c <g_SWFlineaavertbuff+0x16f84> */
/* @0x2ae938 blvs 0x2ea418 <FT_Done_Memory+0x7a4> */
/* @0x2ae93c blvs 0x42a160 <g_RomDisk+0x32940> */
/* @0x2ae940 blvs 0xff46a43c <b2_toiTime+0xfffffffffed10f98> */
/* @0x2ae944 blvc 0x12ea420 <b2_toiTime+0xb90f7c> */
/* @0x2ae948 bvs 0x12a9f60 <b2_toiTime+0xb50abc> */
/* @0x2ae94c blx 0x6ea518 <g_SWFvertbuff+0x17450> */
/* @0x2ae950 ldc p1, c13, [sp], #32 */
/* @0x2ae954 strtmi r8, [r8], -r2, lsl #22 */
/* @0x2ae958 ldrbtmi r4, [r9], #-2314 */
/* @0x2ae95c ldrhtmi lr, [r8], -sp */
/* @0x2ae960 stclt p7, c15, [r8, #988] */
/* @0x2ae964 blhi 0x369c60 <_ZTS13C_UTF16String+0xd0c> */
/* @0x2ae968 svclt #0xbd38 */
/* @0x2ae96c andhi pc, r0, pc, lsr #7 */
/* @0x2ae970 cdpne p1, #0xb, c5, c8, c12, #0x7 */
/* @0x2ae974 ldrhmi pc, [r4], #133 */
/* @0x2ae978 andeq r0, r0, r0 */
/* @0x2ae97c rscsmi r6, r8, r0, lsl #20 */
/* @0x2ae980 andeq pc, sp, r12, asr r1 */
/* @0x2ae984 andeq pc, sp, r7, lsr r1 */
/* @0x2ae988 .word 0x460db570 */
/* @0x2ae98c .word 0x46064614 */
/* @0x2ae990 movtlt r11, #0x9350 */
/* @0x2ae994 movwmi pc, #0x6f */
/* @0x2ae998 swple r4, r10, [r4] */
/* @0x2ae99c ldrbtmi r4, [r9], #-2326 */
/* @0x2ae9a0 stc2l p7, c15, [r8, #-988]! */
/* @0x2ae9a4 bhs 0x2e69c4 <FT_Stream_TryRead+0x24> */
/* @0x2ae9a8 ldmdbmi r4, {r2, r9, r11, r12, lr, pc} */
/* @0x2ae9ac ldrbtmi r2, [r9], #-1024 */
/* @0x2ae9b0 stc2l p7, c15, [r0, #-988]! */
/* @0x2ae9b4 bmi 0xfe6ea1d8 <b2_toiTime+0xfffffffffdf90d34> */
/* @0x2ae9b8 .word 0xf8c568ab */
/* @0x2ae9bc mrc p0, #0x5, r4, c8, c12, #0x7 */
/* @0x2ae9c0 vldr d6, [pc, #924] */
/* @0x2ae9c4 .word 0xf0437b0b */
/* @0x2ae9c8 adcvs r0, r11, r1, lsl #6 */
/* @0x2ae9cc blvc 0x4aa3ec <SrcVerts+0x7430> */
/* @0x2ae9d0 blvc 0xff4aa4b4 <b2_toiTime+0xfffffffffed51010> */
/* @0x2ae9d4 bvc 0x569ff0 <g_SWFlineaavertbuff+0x16f28> */
/* @0x2ae9d8 stmdbmi r9, {r2, r4, r5, r8, r11, r12, sp, pc} */
/* @0x2ae9dc pop {r4, r5, r9, r10, lr} */
/* @0x2ae9e0 ldrbtmi r4, [r9], #-112 */
/* @0x2ae9e4 stcllt p7, c15, [r6, #-988] */
/* @0x2ae9e8 svclt #0xbd70 */
/* @0x2ae9ec andhi pc, r0, pc, lsr #7 */
/* @0x2ae9f0 andeq r0, r0, r0 */
/* @0x2ae9f4 rscsmi r6, r8, r0, lsl #20 */
/* @0x2ae9f8 .word 0x000df0d8 */
/* @0x2ae9fc .word 0x000df0f3 */
/* @0x2aea00 andeq pc, sp, pc, lsr #1 */
/* @0x2aea04 andhi pc, r0, pc, lsr #7 */
/* @0x2aea08 .word 0x460cb570 */
/* @0x2aea0c .word 0x46054616 */
/* @0x2aea10 orrslt r11, r1, #152, #6 */
/* @0x2aea14 bllo 0x311448 <af_shaper_get_elem+0x6cb6> */
/* @0x2aea18 blhs 0x29b48c <_Z15Debug_GetArraysP15Buffer_StandardS0_+0xcc> */
/* @0x2aea1c ldmdbmi r7, {r1, r8, r11, r12, lr, pc} */
/* @0x2aea20 ands r4, r0, r9, ror r4 */
/* @0x2aea24 movwhs r2, #0x208 */
/* @0x2aea28 .word 0xf8caf7f7 */
/* @0x2aea2c .word 0xf44f4628 */
/* @0x2aea30 .word 0xf7f87100 */
/* @0x2aea34 .word 0xf8c5f970 */
/* @0x2aea38 strhlt r0, [r8, -r8] */
/* @0x2aea3c and r2, r6, r0, lsl #6 */
/* @0x2aea40 strtmi r4, [r8], -pc, lsl #18 */
/* @0x2aea44 pop {r0, r3, r4, r5, r6, r10, lr} */
/* @0x2aea48 .word 0xf7f74070 */
/* @0x2aea4c bhi 0xfeb5dea0 <b2_toiTime+0xfffffffffe4049fc> */
/* @0x2aea50 adcsne pc, r8, #13959168 */
/* @0x2aea54 ble 0x3ff4a8 <g_RomDisk+0x7c88> */
/* @0x2aea58 andshs pc, r3, r6, lsr r8 */
/* @0x2aea5c andshs pc, r3, r1, lsr #16 */
/* @0x2aea60 ldrb r3, [r4, r1, lsl #6]! */
/* @0x2aea64 strbvs r6, [r1, r3, lsr #17]! */
/* @0x2aea68 movteq pc, #0x43 */
/* @0x2aea6c .word 0xf8d460a3 */
/* @0x2aea70 .word 0xf04330b8 */
/* @0x2aea74 .word 0xf8c40308 */
/* @0x2aea78 ldcllt p0, c3, [r0, #-736]! */
/* @0x2aea7c andeq pc, sp, r0, lsr #1 */
/* @0x2aea80 andeq pc, sp, r10, lsr #1 */
/* @0x2aea84 strdlt r11, r12, [r5], r0 */
/* @0x2aea88 ldrmi r4, [r5], -r12, lsl #12 */
/* @0x2aea8c .word 0xf8dd9e0a */
/* @0x2aea90 svcls #0xcc02c */
/* @0x2aea94 bls 0x654ed0 <g_SWFlinevertbuff+0x1e08> */
/* @0x2aea98 eorsle r2, r4, r0, lsl #16 */
/* @0x2aea9c eorsle r2, r2, r0, lsl #24 */
/* @0x2aeaa0 .word 0xf8846063 */
/* @0x2aeaa4 blx 0x1a9eb10 <b2_toiTime+0x134566c> */
/* @0x2aeaa8 strtvc pc, [r1], r12, lsl #25 */
/* @0x2aeaac strbtvc r11, [r2], r9, asr #5 */
/* @0x2aeab0 .word 0x7727b2d2 */
/* @0x2aeab4 strdls r11, r12, [r2, -pc] */
/* @0x2aeab8 andls r4, r3, #42991616 */
/* @0x2aeabc eorvs r4, r5, r10, lsl r6 */
/* @0x2aeac0 qsub8vc r11, r6, r3 */
/* @0x2aeac4 andgt pc, r0, sp, asr #17 */
/* @0x2aeac8 .word 0xf7f79701 */
/* @0x2aeacc .word 0x7e63fb71 */
/* @0x2aead0 .word 0xd1012b03 */
/* @0x2aead4 and r2, r2, r1, lsl #4 */
/* @0x2aead8 ldrble r0, [r11, #0x79a]! */
/* @0x2aeadc ldrbeq r2, [r11, -r3, lsl #4] */
/* @0x2aeae0 strle r7, [r2, #-0x762] */
/* @0x2aeae4 movwlo r7, #0x1f63 */
/* @0x2aeae8 cdpvc p7, #0x2, c7, c2, c3, #0x3 */
/* @0x2aeaec cmpmi r3, #396 */
/* @0x2aeaf0 sbfxvc r11, r11, #0x5, #0x4 */
/* @0x2aeaf4 stmdble r2, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x2aeaf8 cmpmi sp, #14352384 */
/* @0x2aeafc cmpmi sp, #2 */
/* @0x2aeb00 stmeq sp!, {r0, r1, r2, r8, r10, r12, sp} ^ */
/* @0x2aeb04 andlt r6, r5, r5, ror #1 */
/* @0x2aeb08 strdlt r11, r12, [r8, #-208] */

/* ── FUNC 0x2abc95 · png_crc_finish · size=116 · insn=0 */

/* ── FUNC 0x2abd09 · png_decompress_chunk · size=328 · insn=0 */

/* ── FUNC 0x2abe51 · png_handle_IHDR · size=276 · insn=0 */

/* ── FUNC 0x2abf65 · png_handle_PLTE · size=356 · insn=0 */

/* ── FUNC 0x2ac0c9 · png_handle_IEND · size=72 · insn=0 */

/* ── FUNC 0x2ac111 · png_handle_gAMA · size=296 · insn=0 */

/* ── FUNC 0x2ac239 · png_handle_sBIT · size=240 · insn=0 */

/* ── FUNC 0x2ac329 · png_handle_cHRM · size=876 · insn=0 */

/* ── FUNC 0x2ac695 · png_handle_sRGB · size=384 · insn=0 */

/* ── FUNC 0x2ac815 · png_handle_iCCP · size=472 · insn=0 */

/* ── FUNC 0x2ac9ed · png_handle_sPLT · size=512 · insn=0 */

/* ── FUNC 0x2acbed · png_handle_tRNS · size=372 · insn=0 */

/* ── FUNC 0x2acd61 · png_handle_bKGD · size=312 · insn=0 */

/* ── FUNC 0x2ace99 · png_handle_hIST · size=192 · insn=0 */

/* ── FUNC 0x2acf59 · png_handle_pHYs · size=216 · insn=0 */

/* ── FUNC 0x2ad031 · png_handle_oFFs · size=248 · insn=0 */

/* ── FUNC 0x2ad129 · png_handle_pCAL · size=552 · insn=0 */

/* ── FUNC 0x2ad351 · png_handle_sCAL · size=384 · insn=0 */

/* ── FUNC 0x2ad4d1 · png_handle_tIME · size=180 · insn=0 */

/* ── FUNC 0x2ad585 · png_handle_tEXt · size=328 · insn=0 */

/* ── FUNC 0x2ad6cd · png_handle_zTXt · size=388 · insn=0 */

/* ── FUNC 0x2ad851 · png_handle_iTXt · size=484 · insn=0 */

/* ── FUNC 0x2ada35 · png_handle_unknown · size=320 · insn=0 */

/* ── FUNC 0x2adb75 · png_check_chunk_name · size=80 · insn=0 */

/* ── FUNC 0x2adbc5 · png_read_chunk_header · size=108 · insn=0 */

/* ── FUNC 0x2adc31 · png_combine_row · size=490 · insn=0 */

/* ── FUNC 0x2ade1d · png_do_read_interlace · size=812 · insn=0 */

/* ── FUNC 0x2ae149 · png_read_filter_row · size=276 · insn=0 */

/* ── FUNC 0x2ae25d · png_read_finish_row · size=568 · insn=0 */
