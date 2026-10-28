/* libyoyo.so 覆盖卡组 0294
 * 函数 0x2e808e..0x2e89db，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x2e808e · anon_2e808e · size=68 · insn=17 */
/* @0x2e808e mvnsmi lr, sp, lsr #18 */
/* @0x2e8092 strhs r10, [r0, -r4, lsl #26] */
/* @0x2e8096 .word 0xf845460e */
/* @0x2e809a ldrmi r7, [r4], -r4, lsl #26 */
/* @0x2e809e ldrmi r9, [r8], r10, lsl #30 */
/* @0x2e80a2 strls r9, [r0, -r1, lsl #10] */
/* @0x2e80a6 .word 0xffb3f7ff */
/* @0x2e80aa strmi r9, [r5], -r3, lsl #18 */
/* @0x2e80ae strmi r11, [r0, #0x941]! */
/* @0x2e80b2 bl 0xff41f4d2 <b2_toiTime+0xfffffffffecc602e> */
/* @0x2e80b6 blx 0x4688e0 <g_RomDisk+0x710c0> */
/* @0x2e80ba cmnmi r2, #4 */
/* @0x2e80be b 0x21257fe <b2_toiTime+0x19cc35a> */
/* @0x2e80c2 strtmi r9, [r8], -r3, lsl #20 */
/* @0x2e80c6 andsvs r9, r10, r11, lsl #22 */
/* @0x2e80ca pop {r2, r12, sp, pc} */
/* @0x2e80ce ldrlt r8, [pc, #-0x1f0] */

/* ── FUNC 0x2e808f · ft_mem_realloc · size=66 · insn=0 */

/* ── FUNC 0x2e80d0 · anon_2e80d0 · size=56 · insn=14 */
/* @0x2e80d0 .word 0x4604b51f */
/* @0x2e80d4 andhs r6, r0, #4390912 */
/* @0x2e80d8 andls r10, r0, #49152 */
/* @0x2e80dc .word 0x21089101 */
/* @0x2e80e0 stmdavs r0, {r0, r1, r3, r4, r6} */
/* @0x2e80e4 .word 0xffd3f7ff */
/* @0x2e80e8 adcvs r9, r0, #3072 */
/* @0x2e80ec movwhs r11, #0x1943 */
/* @0x2e80f0 stmdavs r3!, {r0, r1, r5, r10, r12, sp, lr} ^ */
/* @0x2e80f4 sbceq lr, r3, r0, lsl #22 */
/* @0x2e80f8 strtmi r6, [r0], -r0, ror #5 */
/* @0x2e80fc stc2 p7, c15, [r2], #-1008 */
/* @0x2e8100 andlt r9, r4, r3, lsl #16 */
/* @0x2e8104 push {r4, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2e80d1 · FT_GlyphLoader_CreateExtra · size=54 · insn=0 */

/* ── FUNC 0x2e8106 · anon_2e8106 · size=368 · insn=92 */
/* @0x2e8106 mvnsmi lr, #737280 */
/* @0x2e810a rfeib r0! */
/* @0x2e810e addlt r5, r5, r10, lsr r0 */
/* @0x2e8112 ldrhhs pc, [r6], -r0 */
/* @0x2e8116 stmdavs r6, {r8, r9, sp} ^ */
/* @0x2e811a ldrmi r4, [r5], #-1540 */
/* @0x2e811e strtmi r6, [r9], #-2055 */
/* @0x2e8122 adcsmi r9, r1, #201326592 */
/* @0x2e8126 stclne p9, c13, [sp, #252] */
/* @0x2e812a streq pc, [r7, #-0x25] */
/* @0x2e812e svcmi #0xf5b5 */
/* @0x2e8132 andhs sp, r10, r1, lsl #6 */
/* @0x2e8136 stmibvs r3, {r0, r1, r2, r3, r4, r6, sp, lr, pc} */
/* @0x2e813a stmdaeq r12, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2e813e .word 0xf8cd4638 */
/* @0x2e8142 .word 0x21088004 */
/* @0x2e8146 movwls r4, #0x632 */
/* @0x2e814a .word 0xf7ff462b */
/* @0x2e814e blls 0x3e7fd2 <error_g0017+0x40c76> */
/* @0x2e8152 blhs 0x3007da <TT_New_Context+0x5d2> */
/* @0x2e8156 stmibvs r3!, {r0, r3, r6, r8, r12, lr, pc} ^ */
/* @0x2e815a .word 0x21014638 */
/* @0x2e815e stm sp, {r1, r4, r5, r9, r10, lr} */
/* @0x2e8162 strtmi r0, [r11], -r8, lsl #2 */
/* @0x2e8166 .word 0xff92f7ff */
/* @0x2e816a mvnvs r9, r3, lsl #22 */
/* @0x2e816e teqle r12, r0, lsl #22 */
/* @0x2e8172 .word 0xb1b37c23 */
/* @0x2e8176 smlatbhs r8, r3, r10, r6 */
/* @0x2e817a rsbseq r4, r2, r8, lsr r6 */
/* @0x2e817e smlabbeq r8, sp, r8, lr */
/* @0x2e8182 .word 0xf7ff006b */
/* @0x2e8186 blls 0x3e7f9a <error_g0017+0x40c3e> */
/* @0x2e818a adcvs r4, r0, #1048576 */
/* @0x2e818e b 0x16d6f42 <b2_toiTime+0xf7da9e> */
/* @0x2e8192 rscseq r0, r2, r5, asr #17 */
/* @0x2e8196 ldrmi r4, [r1], #-1088 */
/* @0x2e819a b 0x22258da <b2_toiTime+0x1acc436> */
/* @0x2e819e strbmi r6, [r3], #-2723 */
/* @0x2e81a2 movwhs r6, #0x12e3 */
/* @0x2e81a6 rfeib r4! */
/* @0x2e81aa rfeib r4! */
/* @0x2e81ae stmvs r2!, {r2, r4, r12} */
/* @0x2e81b2 strtmi r4, [r9], #1037 */
/* @0x2e81b6 ldmdble r4, {r0, r4, r7, r8, r10, lr} */
/* @0x2e81ba stmdbeq r3, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x2e81be streq pc, [r3, #-0x29] */
/* @0x2e81c2 svcmi #0xf5b5 */
/* @0x2e81c6 bvs 0xbdcca2 <b2_toiTime+0x4837fe> */
/* @0x2e81ca .word 0x21024638 */
/* @0x2e81ce blge 0x3ccdd6 <error_g0017+0x25a7a> */
/* @0x2e81d2 strtmi r9, [r11], -r1, lsl #6 */
/* @0x2e81d6 .word 0xff5af7ff */
/* @0x2e81da eorvs r9, r0, #3072 */
/* @0x2e81de adcvs r11, r5, r11, lsr #18 */
/* @0x2e81e2 tstlt r3, r0 */
/* @0x2e81e6 .word 0xf7fc4620 */
/* @0x2e81ea blls 0x3e70a2 <error_g0017+0x3fd46> */
/* @0x2e81ee qadd16mi r11, r0, r3 */
/* @0x2e81f2 .word 0xf8a5f7ff */
/* @0x2e81f6 andlt r9, r5, r3, lsl #16 */
/* @0x2e81fa mvnshi lr, #12386304 */
/* @0x2e81fe svcmi #0xf8e92d */
/* @0x2e8202 rfeia r1! */
/* @0x2e8206 .word 0x4604a016 */
/* @0x2e820a ldrhls pc, [r4], -r1 */
/* @0x2e820e .word 0xf78afa0f */
/* @0x2e8212 blx 0xfe566a58 <b2_toiTime+0xfffffffffde0d5b4> */
/* @0x2e8216 uasxmi r4, r10, r9 */
/* @0x2e821a .word 0xff74f7ff */
/* @0x2e821e bllt 0xcf9c26 <b2_toiTime+0x5a0782> */
/* @0x2e8222 stmibvs r9!, {r1, r2, r3, r4, r5, r6, r7} */
/* @0x2e8226 ldrtmi r6, [r2], -r0, lsr #19 */
/* @0x2e822a stmib r8, {r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e822e ldrtmi r6, [r10], -r9, ror #19 */
/* @0x2e8232 .word 0xf5ce69e0 */
/* @0x2e8236 bvs 0xb22946 <b2_toiTime+0x3c94a2> */
/* @0x2e823a b 0x16c2ae6 <b2_toiTime+0xf69642> */
/* @0x2e823e .word 0xf5ce024b */
/* @0x2e8242 stcvc p9, c14, [r3], #-752 */
/* @0x2e8246 stcvc p1, c11, [r11], #-364 */
/* @0x2e824a bvs 0xfed5477e <b2_toiTime+0xfffffffffe5fb2da> */
/* @0x2e824e bvs 0xfeaf9b1e <b2_toiTime+0xfffffffffe3a067a> */
/* @0x2e8252 ldmib r4!, {r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} */
/* @0x2e8256 bvs 0xffd42dde <b2_toiTime+0xffffffffff5e993a> */
/* @0x2e825a .word 0xf5ce4632 */
/* @0x2e825e .word 0xf8a4e9ae */
/* @0x2e8262 qadd16mi r10, r0, r6 */
/* @0x2e8266 andsls pc, r4, r4, lsr #17 */
/* @0x2e826a blx 0x1de6264 <b2_toiTime+0x168cdc0> */
/* @0x2e826e pop {r6, r9, r10, lr} */
/* @0x2e8272 ldrlt r8, [r0, #-0xff8]! */

/* ── FUNC 0x2e8107 · FT_GlyphLoader_CheckPoints · size=248 · insn=0 */

/* ── FUNC 0x2e81ff · FT_GlyphLoader_CopyPoints · size=118 · insn=0 */

/* ── FUNC 0x2e8274 · anon_2e8274 · size=260 · insn=65 */
/* @0x2e8274 addlt r11, r5, r0, lsr r5 */
/* @0x2e8278 movwhs r4, #0x604 */
/* @0x2e827c movwls r6, #0x3d65 */
/* @0x2e8280 stmvs r2!, {r0, r1, r5, r8, r9, r11, sp, lr} ^ */
/* @0x2e8284 stmdavs r0, {r0, r1, r3, r5, r10, lr} */
/* @0x2e8288 addsmi r4, r1, #419430400 */
/* @0x2e828c blvs 0x1bde6dc <b2_toiTime+0x1485238> */
/* @0x2e8290 .word 0xf0251c4d */
/* @0x2e8294 .word 0x21200501 */
/* @0x2e8298 blge 0x3ccea0 <error_g0017+0x25b44> */
/* @0x2e829c strtmi r9, [r11], -r1, lsl #6 */
/* @0x2e82a0 mrc2 p7, #0x7, apsr_nzcv, c5, c15, #0x7 */
/* @0x2e82a4 .word 0x63609b03 */
/* @0x2e82a8 blvs 0xbd673c <b2_toiTime+0x47d298> */
/* @0x2e82ac bl 0x300648 <TT_New_Context+0x440> */
/* @0x2e82b0 strvs r1, [r0, #0x43]! */
/* @0x2e82b4 andlt r9, r5, r3, lsl #16 */
/* @0x2e82b8 andeq r11, r0, r0, lsr sp */
/* @0x2e82bc .word 0x4604b51f */
/* @0x2e82c0 subshs r2, r0, #-1006632957 */
/* @0x2e82c4 andeq lr, r12, r0, lsl #17 */
/* @0x2e82c8 addvs r2, r2, r0, lsl #4 */
/* @0x2e82cc andls r4, r0, #8, #16 */
/* @0x2e82d0 rscvs r4, r0, r8, ror r4 */
/* @0x2e82d4 ldrbtmi r4, [r8], #-2055 */
/* @0x2e82d8 stmdage r3, {r5, r8, sp, lr} */
/* @0x2e82dc strmi r9, [r8], -r1 */
/* @0x2e82e0 .word 0xf7ff2104 */
/* @0x2e82e4 .word 0x6160fed4 */
/* @0x2e82e8 andlt r9, r4, r3, lsl #16 */
/* @0x2e82ec svclt #0xbd10 */
/* @0x2e82f0 .word 0xffffc6a1 */
/* @0x2e82f4 .word 0xffffc945 */
/* @0x2e82f8 .word 0x4606b5f0 */
/* @0x2e82fc stmdahs r0, {r0, r2, r7, r12, sp, pc} */
/* @0x2e8300 stmdavs r4, {r0, r1, r2, r4, r5, r12, lr, pc} */
/* @0x2e8304 cdpvs p5, #0x6, c2, c0, c0, #0x0 */
/* @0x2e8308 addsmi r6, r5, #401408 */
/* @0x2e830c bvs 0xfebdebd8 <b2_toiTime+0xfffffffffe485734> */
/* @0x2e8310 eorne pc, r5, r3, asr r8 */
/* @0x2e8314 strhle r4, [r10, -r1]! */
/* @0x2e8318 orrmi pc, r0, r2, lsl #2 */
/* @0x2e831c .word 0xf8533901 */
/* @0x2e8320 .word 0x21047021 */
/* @0x2e8324 blge 0x3ccf2c <error_g0017+0x25bd0> */
/* @0x2e8328 cdpne p3, #0x5, c9, c3, c1, #0x0 */
/* @0x2e832c mcr2 p7, #0x5, pc, c15, c15, #0x7 */
/* @0x2e8330 adcvs r9, r0, #3072 */
/* @0x2e8334 stclne p9, c11, [r11], #-940 */
/* @0x2e8338 bvs 0x1b685f4 <b2_toiTime+0x140f150> */
/* @0x2e833c cps #0x13 */
/* @0x2e8340 ble 0x574f44 <g_SWFlineaavertbuff+0x21e7c> */
/* @0x2e8344 bvs 0xfeb78d98 <b2_toiTime+0xfffffffffe41f8f4> */
/* @0x2e8348 movweq pc, #0x1103 */
/* @0x2e834c ldmdbne r1, {r0, r1, r2, r4, r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x2e8350 stmdavs r9, {r0, r1, r2, r4, r6, r8, r12, lr} ^ */
/* @0x2e8354 strlo r5, [r4, #-0x151] */
/* @0x2e8358 stclvs p7, c14, [r3, #956]! */
/* @0x2e835c rsbvs r4, r2, #48, #12 */
/* @0x2e8360 svclt #0x442b3 */
/* @0x2e8364 strbvs r2, [r3, #0x300]! */
/* @0x2e8368 blx 0x12636e <_Z16F_ShowMessageExtR6RValueP9CInstanceS2_iPS_+0x1e> */
/* @0x2e836c strlo lr, [r1, #-0x1] */
/* @0x2e8370 andlt lr, r5, r11, asr #15 */
/* @0x2e8374 push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x2e8275 · FT_GlyphLoader_CheckSubGlyphs · size=70 · insn=0 */

/* ── FUNC 0x2e82bd · ft_hash_str_init · size=60 · insn=0 */

/* ── FUNC 0x2e82f9 · FT_CMap_Done · size=126 · insn=0 */

/* ── FUNC 0x2e8376 · anon_2e8376 · size=320 · insn=80 */
/* @0x2e8376 svcmi #0xf0e92d */
/* @0x2e837a ldrmi r11, [r8], r5, lsl #1 */
/* @0x2e837e movwhs r4, #0x68b */
/* @0x2e8382 movwls r4, #0x3616 */
/* @0x2e8386 stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x2e838a bhs 0x31c47a */
/* @0x2e838e ldmdavs r5, {r3, r4, r5, r12, lr, pc} */
/* @0x2e8392 eorsle r2, r5, r0, lsl #26 */
/* @0x2e8396 .word 0x9064f8d5 */
/* @0x2e839a beq 0x6247d6 <g_SWFaavertbuff+0x5170e> */
/* @0x2e839e uasxmi r6, r2, r9 */
/* @0x2e83a2 .word 0xf7fe4648 */
/* @0x2e83a6 blls 0x3e7eaa <error_g0017+0x40b4e> */
/* @0x2e83aa bllt 0x7b9bc2 <b2_toiTime+0x6071e> */
/* @0x2e83ae muleq r7, r6, r8 */
/* @0x2e83b2 stm r4, {r0, r1, r2, r5, r6, r7, sp, lr} */
/* @0x2e83b6 ldmdavs r11!, {r0, r1, r2} ^ */
/* @0x2e83ba bvs 0xfedd69ee <b2_toiTime+0xfffffffffe67d54a> */
/* @0x2e83be bvs 0x1d79ce6 <b2_toiTime+0x1620842> */
/* @0x2e83c2 stm sp, {r2, r8, sp} */
/* @0x2e83c6 mrrcne p4, #0x0, r0, r3, c8 */
/* @0x2e83ca mcr2 p7, #0x3, pc, c0, c15, #0x7 */
/* @0x2e83ce adcvs r9, r8, #3072 */
/* @0x2e83d2 bvs 0x1dd6946 <b2_toiTime+0x167d4a2> */
/* @0x2e83d6 rsbvs r1, r10, #23040 */
/* @0x2e83da eormi pc, r3, r0, asr #16 */
/* @0x2e83de strtmi lr, [r0], -r9 */
/* @0x2e83e2 .word 0x47984659 */
/* @0x2e83e6 stmdahs r0, {r0, r1, r12, pc} */
/* @0x2e83ea strtmi sp, [r0], -r7, ror #1 */
/* @0x2e83ee .word 0xf7ff2400 */
/* @0x2e83f2 .word 0xf1b8fbb4 */
/* @0x2e83f6 andle r0, r1, r0, lsl #30 */
/* @0x2e83fa andmi pc, r0, r8, asr #17 */
/* @0x2e83fe and r9, r0, r3, lsl #16 */
/* @0x2e8402 andlt r2, r5, r6 */
/* @0x2e8406 svchi #0xf0e8bd */
/* @0x2e840a mvnsmi lr, sp, lsr #18 */
/* @0x2e840e strmi r4, [lr], -r5, lsl #12 */
/* @0x2e8412 sadd16mi r4, r12, r7 */
/* @0x2e8416 andhs r11, r6, r11, lsl #18 */
/* @0x2e841a stmdahs r0, {r0, r6, sp, lr, pc} */
/* @0x2e841e ssub8mi sp, r8, r11 */
/* @0x2e8422 andshs r2, r4, #0, #2 */
/* @0x2e8426 stm r4, {r1, r2, r3, r6, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x2e842a blle 0xffff4032 <b2_toiTime+0xffffffffff89ab8e> */
/* @0x2e842e ldmle r2!, {r0, r1, r2, r4, r5, r7, r9, lr} ^ */
/* @0x2e8432 svcmi #0xf5b6 */
/* @0x2e8436 andhs sp, r0, #536870915 */
/* @0x2e843a stmdaeq r12, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2e843e strtmi r9, [r8], -r0, lsl #4 */
/* @0x2e8442 andhi pc, r4, sp, asr #17 */
/* @0x2e8446 ldrtmi r2, [r3], -r8, lsl #2 */
/* @0x2e844a mcr2 p7, #0x1, pc, c0, c15, #0x7 */
/* @0x2e844e rsbvs r9, r0, r3, lsl #20 */
/* @0x2e8452 stm sp, {r1, r4, r6, r7, r8, r11, r12, sp, pc} */
/* @0x2e8456 strtmi r0, [r8], -r4, lsl #2 */
/* @0x2e845a ldrtmi r2, [r3], -r1, lsl #2 */
/* @0x2e845e mrc2 p7, #0x0, apsr_nzcv, c6, c15, #0x7 */
/* @0x2e8462 adcvs r9, r0, r3, lsl #20 */
/* @0x2e8466 stm sp, {r1, r7, r8, r11, r12, sp, pc} */
/* @0x2e846a strtmi r0, [r8], -r4, lsl #2 */
/* @0x2e846e ldrtmi r2, [r11], -r2, lsl #2 */
/* @0x2e8472 mcr2 p7, #0x0, pc, c12, c15, #0x7 */
/* @0x2e8476 stmdals r3, {r5, r6, r7, sp, lr} */
/* @0x2e847a stmdbvs r3!, {r4, r5, r8, r11, r12, sp, pc} */
/* @0x2e847e .word 0xf0438066 */
/* @0x2e8482 eorhi r0, r7, r1, lsl #6 */
/* @0x2e8486 and r6, r10, r3, lsr #2 */
/* @0x2e848a strtmi r6, [r8], -r3, lsr #18 */
/* @0x2e848e .word 0xf0434621 */
/* @0x2e8492 .word 0x61230301 */
/* @0x2e8496 ldc2 p7, c15, [r0], {255} */
/* @0x2e849a and r9, r0, r3, lsl #16 */
/* @0x2e849e andlt r2, r4, r10 */
/* @0x2e84a2 ldrhhi lr, [r0, #141]! */
/* @0x2e84a6 stmdavs r0, {r4, r8, r12, sp, pc} */
/* @0x2e84aa svclt #0xaef7ff */
/* @0x2e84ae ldrbmi r2, [r0, -r1, lsr #32]! */
/* @0x2e84b2 ldrlt r0, [pc, #-0x0] */

/* ── FUNC 0x2e8377 · FT_CMap_New · size=148 · insn=0 */

/* ── FUNC 0x2e840b · FT_Outline_New_Internal · size=156 · insn=0 */

/* ── FUNC 0x2e84a7 · FT_Outline_New · size=12 · insn=0 */

/* ── FUNC 0x2e84b4 · anon_2e84b4 · size=1040 · insn=260 */
/* @0x2e84b4 .word 0x4604b51f */
/* @0x2e84b8 subshs r2, r0, #-1006632957 */
/* @0x2e84bc andeq lr, r12, r0, lsl #17 */
/* @0x2e84c0 addvs r2, r2, r0, lsl #4 */
/* @0x2e84c4 andls r4, r0, #8, #16 */
/* @0x2e84c8 rscvs r4, r0, r8, ror r4 */
/* @0x2e84cc ldrbtmi r4, [r8], #-2055 */
/* @0x2e84d0 stmdage r3, {r5, r8, sp, lr} */
/* @0x2e84d4 strmi r9, [r8], -r1 */
/* @0x2e84d8 .word 0xf7ff2104 */
/* @0x2e84dc .word 0x6160fdd8 */
/* @0x2e84e0 andlt r9, r4, r3, lsl #16 */
/* @0x2e84e4 svclt #0xbd10 */
/* @0x2e84e8 .word 0xffffc4bf */
/* @0x2e84ec .word 0xffffc4db */
/* @0x2e84f0 ldrbmi lr, [pc, sp, lsr #18]! */
/* @0x2e84f4 ldrmi r4, [r1], -pc, lsl #12 */
/* @0x2e84f8 pkhbtmi r4, r1, lr, lsl #12 */
/* @0x2e84fc .word 0xf7fc4614 */
/* @0x2e8500 movwhs pc, #0xa5b */
/* @0x2e8504 stmdavs r3, {r1, r8, r9, r12, pc} */
/* @0x2e8508 blhs 0x2f9f10 <ps_hints_apply+0x8b10> */
/* @0x2e850c .word 0x2108d147 */
/* @0x2e8510 bl 0x639dd8 <g_SWFaavertbuff+0x66d10> */
/* @0x2e8514 .word 0xf7fe0201 */
/* @0x2e8518 stcls p14, c15, [r2, #-24] */
/* @0x2e851c teqle pc, r0, lsl #26 */
/* @0x2e8520 andeq pc, r0, r8, asr #17 */
/* @0x2e8524 andls pc, r0, r0, asr #17 */
/* @0x2e8528 stmvs r2!, {r0, r1, r2, r6, sp, lr} */
/* @0x2e852c addsmi r6, r10, #2293760 */
/* @0x2e8530 stmvs r3!, {r0, r1, r9, r12, lr, pc} */
/* @0x2e8534 adcvs r3, r3, r1, lsl #6 */
/* @0x2e8538 .word 0xf8d4e032 */
/* @0x2e853c .word 0xf10d9004 */
/* @0x2e8540 .word 0x21030a10 */
/* @0x2e8544 ldrsbhi pc, [r4], -r4 */
/* @0x2e8548 stcpl p8, c15, [r4, #-296] */
/* @0x2e854c strbeq lr, [r9, -pc, asr #20] */
/* @0x2e8550 ldrtmi r6, [r8], -r7, rrx */
/* @0x2e8554 bl 0x212461c <b2_toiTime+0x19cb178> */
/* @0x2e8558 strteq lr, [r0], #-2189 */
/* @0x2e855c .word 0x2104462a */
/* @0x2e8560 eorvs r4, r0, r11, lsr r6 */
/* @0x2e8564 .word 0xf7ff4630 */
/* @0x2e8568 stcls p13, c15, [r3, #-584] */
/* @0x2e856c ldmiblt r5, {r5, r6, r8, sp, lr} */
/* @0x2e8570 strbmi r4, [sp, #-0x647] */
/* @0x2e8574 .word 0xf857d00b */
/* @0x2e8578 teqlt r3, r4, lsl #22 */
/* @0x2e857c qadd16mi r6, r1, r8 */
/* @0x2e8580 blx 0x9a6578 <b2_toiTime+0x24d0d4> */
/* @0x2e8584 .word 0x3c04f857 */
/* @0x2e8588 strlo r6, [r1, #-0x3] */
/* @0x2e858c shsub8mi lr, r0, r1 */
/* @0x2e8590 .word 0xf7fe4641 */
/* @0x2e8594 blls 0x3e80dc <error_g0017+0x40d80> */
/* @0x2e8598 stmdblt r11, {r1, r8, r9, r12, pc} */
/* @0x2e859c subsvs lr, pc, r9, asr #15 */
/* @0x2e85a0 andlt r9, r4, r2, lsl #16 */
/* @0x2e85a4 .word 0x87f0e8bd */
/* @0x2e85a8 .word 0xf7ffb508 */
/* @0x2e85ac stclt p15, c15, [r8, #-644] */
/* @0x2e85b0 .word 0xf7ffb508 */
/* @0x2e85b4 stclt p15, c15, [r8, #-628] */
/* @0x2e85b8 svcmi #0xf0e92d */
/* @0x2e85bc .word 0xf8d0b087 */
/* @0x2e85c0 strmi r8, [r12], -r0 */
/* @0x2e85c4 ldrmi r4, [r1], -r8, lsl #12 */
/* @0x2e85c8 movwls r4, #0x3692 */
/* @0x2e85cc .word 0xf7fe9e13 */
/* @0x2e85d0 andls pc, r5, r10, ror #18 */
/* @0x2e85d4 .word 0xf0402800 */
/* @0x2e85d8 stcge p0, c8, [r5, #-704] */
/* @0x2e85dc strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e85e0 blx 0xfe7265e0 <b2_toiTime+0xfffffffffdfcd13c> */
/* @0x2e85e4 svchs #0x9f05 */
/* @0x2e85e8 adchi pc, r6, r0, asr #32 */
/* @0x2e85ec .word 0xf980fa0f */
/* @0x2e85f0 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x2e85f4 svcvs #0x7ff5b9 */
/* @0x2e85f8 andhs sp, r8, r1, lsr #22 */
/* @0x2e85fc qadd8mi lr, r0, sp */
/* @0x2e8600 .word 0xf7fe4629 */
/* @0x2e8604 blls 0x467588 <g_RomDisk+0x6fd68> */
/* @0x2e8608 blhs 0x2fa01c <ps_hints_apply+0x8c1c> */
/* @0x2e860c addshi pc, r0, r0, asr #32 */
/* @0x2e8610 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e8614 blx 0x20a6614 <b2_toiTime+0x194d170> */
/* @0x2e8618 strmi r9, [r3], -r5, lsl #20 */
/* @0x2e861c .word 0xf0402a00 */
/* @0x2e8620 strtmi r8, [r9], -r7, lsl #1 */
/* @0x2e8624 movwls r4, #0x2620 */
/* @0x2e8628 blx 0x1e26628 <b2_toiTime+0x16cd184> */
/* @0x2e862c blls 0x38ee48 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x2ea4> */
/* @0x2e8630 bhs 0x2f9e3c <ps_hints_apply+0x8a3c> */
/* @0x2e8634 bls 0x71cc2c <g_SWFvertbuff+0x49b64> */
/* @0x2e8638 mulle r3, r3, r5 */
/* @0x2e863c strbmi r3, [pc, #-0x701] */
/* @0x2e8640 ldrsbt sp, [r7], #-189 */
/* @0x2e8644 mrrcne p2, #0x1, r11, r10, c11 */
/* @0x2e8648 .word 0xf6406032 */
/* @0x2e864c addsmi r2, r3, #1610612746 */
/* @0x2e8650 .word 0x4620d8d3 */
/* @0x2e8654 .word 0xf181fa0a */
/* @0x2e8658 .word 0xf925f7fe */
/* @0x2e865c andls r4, r5, r2, lsl #12 */
/* @0x2e8660 .word 0xd16a2800 */
/* @0x2e8664 eoreq lr, r4, sp, lsl #17 */
/* @0x2e8668 .word 0x21084640 */
/* @0x2e866c .word 0xf7ff6833 */
/* @0x2e8670 strmi pc, [r1], lr, lsl #26 */
/* @0x2e8674 stmdahs r0, {r0, r2, r11, r12, pc} */
/* @0x2e8678 .word 0x464fd15f */
/* @0x2e867c ldmdavs r1!, {r1, r7, r9, r10, lr} */
/* @0x2e8680 ble 0xe79cb0 <b2_toiTime+0x72080c> */
/* @0x2e8684 strtmi r4, [r9], -r0, lsr #12 */
/* @0x2e8688 blx 0x1226688 <b2_toiTime+0xacd1e4> */
/* @0x2e868c blls 0x448774 <g_RomDisk+0x50f54> */
/* @0x2e8690 .word 0xd1492b00 */
/* @0x2e8694 .word 0x21024620 */
/* @0x2e8698 .word 0xf94af7fe */
/* @0x2e869c stmdahs r0, {r0, r2, r12, pc} */
/* @0x2e86a0 strtmi sp, [r0], -r2, asr #2 */
/* @0x2e86a4 .word 0xf7fe4629 */
/* @0x2e86a8 blls 0x4674e4 <g_RomDisk+0x6fcc4> */
/* @0x2e86ac blhs 0x2fa0c0 <ps_hints_apply+0x8cc0> */
/* @0x2e86b0 qasxmi sp, r0, r10 */
/* @0x2e86b4 .word 0xf7fe2104 */
/* @0x2e86b8 andls pc, r5, r11, lsr r9 */
/* @0x2e86bc rfeib r7! */
/* @0x2e86c0 blhs 0x2f46c8 <ps_hints_apply+0x32c8> */
/* @0x2e86c4 .word 0xf1bbdb04 */
/* @0x2e86c8 .word 0xf1070f00 */
/* @0x2e86cc ble 0x32a2f4 */
/* @0x2e86d0 eor r2, r8, r8, lsl #6 */
/* @0x2e86d4 cmnmi pc, #43 */
/* @0x2e86d8 beq 0x364b08 <_ZTS12CDS_Priority+0x6b60> */
/* @0x2e86dc .word 0x3c04f847 */
/* @0x2e86e0 .word 0xf89de7cd */
/* @0x2e86e4 .word 0xb12b3044 */
/* @0x2e86e8 .word 0x46484b15 */
/* @0x2e86ec ldrbtmi r2, [r11], #-520 */
/* @0x2e86f0 svc #0xf4f5cd */
/* @0x2e86f4 strbmi r2, [r0], -r0, lsl #4 */
/* @0x2e86f8 eoreq lr, r4, sp, lsl #17 */
/* @0x2e86fc ldmdavs r3!, {r2, r8, sp} */
/* @0x2e8700 stc2l p7, c15, [r5], {255} */
/* @0x2e8704 ldmdblt r11!, {r0, r2, r8, r9, r11, r12, pc} ^ */
/* @0x2e8708 addsmi r6, r3, #3276800 */
/* @0x2e870c bl 0x55ef34 <g_SWFlineaavertbuff+0xbe6c> */
/* @0x2e8710 stmdbls r3, {r0, r1, r6, r7, r9} */
/* @0x2e8714 strmi r6, [r10], #-2130 */
/* @0x2e8718 eorhs pc, r3, r0, asr #16 */
/* @0x2e871c ldrb r3, [r3, r1, lsl #6]! */
/* @0x2e8720 andsvs r9, r8, r2, lsl r11 */
/* @0x2e8724 movwls r2, #0x5300 */
/* @0x2e8728 strbmi r4, [r9], -r0, asr #12 */
/* @0x2e872c mcr2 p7, #0x0, pc, c3, c14, #0x7 */
/* @0x2e8730 and r9, r2, r5, lsl #16 */
/* @0x2e8734 and r2, r0, r1 */
/* @0x2e8738 andlt r4, r7, r8, lsr r6 */
/* @0x2e873c svchi #0xf0e8bd */
/* @0x2e8740 .word 0xffffc35f */
/* @0x2e8744 mvnsmi lr, #737280 */
/* @0x2e8748 movwhs r11, #0x6085 */
/* @0x2e874c movwls r4, #0x3615 */
/* @0x2e8750 suble r2, r5, r0, lsl #20 */
/* @0x2e8754 suble r2, r3, r0, lsl #16 */
/* @0x2e8758 ldreq r6, [r11, -r3, lsl #17] */
/* @0x2e875c rfeia r0! */
/* @0x2e8760 addsmi r3, r9, #84, #2 */
/* @0x2e8764 .word 0x2714d23c */
/* @0x2e8768 .word 0x8164f8d0 */
/* @0x2e876c bl 0x4f94b0 <SrcVerts+0x564f4> */
/* @0x2e8770 stmdbhi r3!, {r0, r1, r2, r10} */
/* @0x2e8774 stmdbvs r2!, {r0, r1, r3, r5, r8, r9, r12, sp, pc} */
/* @0x2e8778 .word 0xf8d0bb1a */
/* @0x2e877c stmdbge r3, {r2, r5, r6, r12, pc} */
/* @0x2e8780 smlabbls r1, r6, lr, r6 */
/* @0x2e8784 andls r2, r0, #1073741824 */
/* @0x2e8788 .word 0xf7ff4648 */
/* @0x2e878c blls 0x3e7994 <error_g0017+0x40638> */
/* @0x2e8790 teqlt r11, r0, lsr #2 */
/* @0x2e8794 stmdbvs r1!, {r3, r6, r9, r10, lr} */
/* @0x2e8798 stc2l p7, c15, [sp, #1016] */
/* @0x2e879c .word 0x61232300 */
/* @0x2e87a0 and r8, lr, r3, lsr #2 */
/* @0x2e87a4 stmvs r1!, {r4, r5, r9, r10, lr} ^ */
/* @0x2e87a8 .word 0xf87df7fe */
/* @0x2e87ac stmdahs r0, {r0, r1, r12, pc} */
/* @0x2e87b0 shsub8mi sp, r0, r0 */
/* @0x2e87b4 stmdbhi r2!, {r0, r5, r8, r11, sp, lr} */
/* @0x2e87b8 .word 0xf8e9f7fe */
/* @0x2e87bc stmdahs r0, {r0, r1, r12, pc} */
/* @0x2e87c0 rfeda r8! */
/* @0x2e87c4 eorhi r3, r11, r7 */
/* @0x2e87c8 rsbhi r8, r11, r3, ror #16 */
/* @0x2e87cc adchi r8, r11, r3, lsr #17 */
/* @0x2e87d0 rschi r8, r11, r3, ror #17 */
/* @0x2e87d4 adcvs r6, r11, r3, lsr #18 */
/* @0x2e87d8 rscvs r8, r11, r3, lsr #18 */
/* @0x2e87dc movwls r2, #0x3300 */
/* @0x2e87e0 andlt r9, r5, r3, lsl #16 */
/* @0x2e87e4 mvnshi lr, #12386304 */
/* @0x2e87e8 mvnsmi lr, #737280 */
/* @0x2e87ec strmi r11, [r11], -r5, lsl #1 */
/* @0x2e87f0 .word 0x21064605 */
/* @0x2e87f4 swpls r4, r0, [r3] */
/* @0x2e87f8 suble r2, r7, r0, lsl #20 */
/* @0x2e87fc suble r2, r5, r0, lsl #16 */
/* @0x2e8800 ldreq r6, [r2, -r2, lsl #17] */
/* @0x2e8804 rfeia r0! */
/* @0x2e8808 stmdbhs r1, {r3, r4, r6, r8, r12} */
/* @0x2e880c .word 0xf5b3d140 */
/* @0x2e8810 ldmdble r11!, {r8, r9, r10, r11, lr} */
/* @0x2e8814 .word 0x2168f8d5 */
/* @0x2e8818 andmi pc, r0, r3, lsr #11 */
/* @0x2e881c eorsle r4, r5, #144, #4 */
/* @0x2e8820 .word 0xf8d5260c */
/* @0x2e8824 cmpmi lr, #108, #2 */
/* @0x2e8828 strbhs pc, [r0], r6, lsr #11 */
/* @0x2e882c blpl 0xff1aef24 <b2_toiTime+0xfffffffffea55a80> */
/* @0x2e8830 stmvs r2!, {r0, r1, r5, r8, r9, r12, sp, pc} */
/* @0x2e8834 .word 0xf8d5bb12 */
/* @0x2e8838 stmdage r3, {r2, r5, r6, r12, pc} */
/* @0x2e883c andls r6, r1, sp, lsr #29 */
/* @0x2e8840 strbmi r9, [r8], -r0, lsl #4 */
/* @0x2e8844 stc2 p7, c15, [r3], #-1020 */
/* @0x2e8848 adcvs r9, r0, r3, lsl #22 */
/* @0x2e884c .word 0x4648b13b */
/* @0x2e8850 .word 0xf7fe68a1 */
/* @0x2e8854 movwhs pc, #0xd70 */
/* @0x2e8858 .word 0x53bb60a3 */
/* @0x2e885c strtmi lr, [r8], -lr */
/* @0x2e8860 .word 0xf7fe6861 */
/* @0x2e8864 andls pc, r3, r0, lsr #16 */
/* @0x2e8868 mvnsle r2, r0, lsl #16 */
/* @0x2e886c stmvs r1!, {r3, r5, r9, r10, lr} */
/* @0x2e8870 .word 0xf7fe5bba */
/* @0x2e8874 andls pc, r3, r12, lsl #17 */
/* @0x2e8878 mvnle r2, r0, lsl #16 */
/* @0x2e887c .word 0xf8c868a3 */
/* @0x2e8880 blpl 0xff1b4888 <b2_toiTime+0xfffffffffea5b3e4> */
/* @0x2e8884 andlo pc, r4, r8, asr #17 */
/* @0x2e8888 movwls r2, #0x3300 */
/* @0x2e888c and r9, r0, r3, lsl #16 */
/* @0x2e8890 andlt r2, r5, r8 */
/* @0x2e8894 mvnshi lr, #12386304 */
/* @0x2e8898 .word 0x460db5f7 */
/* @0x2e889c sadd16mi r4, r1, r4 */
/* @0x2e88a0 ldrmi r10, [lr], -r1, lsl #20 */
/* @0x2e88a4 stc2 p7, c15, [r12], #-1016 */
/* @0x2e88a8 strmi r9, [r7], -r1, lsl #20 */
/* @0x2e88ac tstlt sp, r2, lsr #18 */
/* @0x2e88b0 strtmi r4, [r2], -r9, lsr #12 */
/* @0x2e88b4 cdp p5, #0x8, c15, c2, c13, #0x6 */
/* @0x2e88b8 ldrtmi r9, [r8], -r1, lsl #22 */
/* @0x2e88bc andlt r6, r3, r3, lsr r0 */
/* @0x2e88c0 ldrblt r11, [r0, #-0xdf0]! */

/* ── FUNC 0x2e84b5 · ft_hash_num_init · size=60 · insn=0 */

/* ── FUNC 0x2e85a9 · ft_hash_str_insert · size=8 · insn=0 */

/* ── FUNC 0x2e85b1 · ft_hash_num_insert · size=8 · insn=0 */

/* ── FUNC 0x2e85b9 · FT_Raccess_Get_DataOffsets · size=396 · insn=0 */

/* ── FUNC 0x2e8745 · FT_Get_Sfnt_Name · size=164 · insn=0 */

/* ── FUNC 0x2e87e9 · FT_Get_Sfnt_LangTag · size=176 · insn=0 */

/* ── FUNC 0x2e8899 · ft_mem_dup · size=42 · insn=0 */

/* ── FUNC 0x2e88c2 · anon_2e88c2 · size=96 · insn=24 */
/* @0x2e88c2 .word 0x4606b570 */
/* @0x2e88c6 .word 0x460c4615 */
/* @0x2e88ca strmi r11, [r8], -r1, lsr #2 */
/* @0x2e88ce cdp p5, #0x3, c15, c4, c13, #0x6 */
/* @0x2e88d2 and r1, r0, r2, asr #24 */
/* @0x2e88d6 ldrtmi r4, [r0], -r10, lsl #12 */
/* @0x2e88da strtmi r4, [r11], -r1, lsr #12 */
/* @0x2e88de ldrhtmi lr, [r0], #-141 */
/* @0x2e88e2 svclt #0xd9f7ff */
/* @0x2e88e6 ldrlt r4, [r0, #-0x402] */
/* @0x2e88ea .word 0x460c1a13 */
/* @0x2e88ee stmdale r6, {r0, r8, r9, r11, sp} */
/* @0x2e88f2 andvc r2, r3, r0, lsl #6 */
/* @0x2e88f6 bne 0xff30697e <b2_toiTime+0xfffffffffebad4da> */
/* @0x2e88fa andhs r11, r1, r8, lsl pc */
/* @0x2e88fe .word 0xf811bd10 */
/* @0x2e8902 blhs 0x2f750e <ps_hints_apply+0x610e> */
/* @0x2e8906 .word 0xf800d0f4 */
/* @0x2e890a strb r3, [sp, r1, lsl #22]! */
/* @0x2e890e stmdavs r0, {r4, r5, r8, r12, sp, pc} */
/* @0x2e8912 stmvs r3, {r5, r8, r12, sp, pc} */
/* @0x2e8916 andle r4, r1, r11, lsl #5 */
/* @0x2e891a ldrb r6, [r9, r0, asr #16]! */
/* @0x2e891e .word 0xb1484770 */

/* ── FUNC 0x2e88c3 · ft_mem_strdup · size=36 · insn=0 */

/* ── FUNC 0x2e88e7 · ft_mem_strcpyn · size=40 · insn=0 */

/* ── FUNC 0x2e890f · FT_List_Find · size=18 · insn=0 */

/* ── FUNC 0x2e8920 · anon_2e8920 · size=188 · insn=47 */
/* @0x2e8920 .word 0xb141b148 */
/* @0x2e8924 andhs r6, r0, #4390912 */
/* @0x2e8928 andvs r6, r11, r10, asr #32 */
/* @0x2e892c subsvs r11, r9, r11, lsl #2 */
/* @0x2e8930 andvs lr, r1, r0 */
/* @0x2e8934 ldrbmi r6, [r0, -r1, asr #32]! */
/* @0x2e8938 ldrbmi lr, [r3, sp, lsr #18]! */
/* @0x2e893c strmi r4, [r5], -r8, lsl #13 */
/* @0x2e8940 suble r2, r2, r0, lsl #16 */
/* @0x2e8944 suble r2, r2, r0, lsl #18 */
/* @0x2e8948 blhs 0x30415c <TT_New_Context+0x3f54> */
/* @0x2e894c strhs sp, [r0, -r1, asr #32] */
/* @0x2e8950 cdpvs p0, #0x0, c6, c3, c15, #0x0 */
/* @0x2e8954 stmdbeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x2e8958 strbmi r6, [r10], -r6, asr #28 */
/* @0x2e895c .word 0xa00cf8d3 */
/* @0x2e8960 .word 0xf8da4630 */
/* @0x2e8964 .word 0xf7fe1028 */
/* @0x2e8968 blls 0x3678e8 <_ZTS12CDS_Priority+0x9940> */
/* @0x2e896c bllt 0x3ba184 <error_g0017+0x12e28> */
/* @0x2e8970 .word 0x210c4630 */
/* @0x2e8974 .word 0xf7fe464a */
/* @0x2e8978 blls 0x3678d8 <_ZTS12CDS_Priority+0x9930> */
/* @0x2e897c stmiblt r3, {r0, r1, r2, r9, r10, lr} ^ */
/* @0x2e8980 ldrtmi r6, [r0], -r5, lsr #32 */
/* @0x2e8984 strbmi r2, [r10], -r4, lsr #2 */
/* @0x2e8988 blx 0xff66698a <b2_toiTime+0xfffffffffef0d4e6> */
/* @0x2e898c stmiblt r3, {r0, r8, r9, r11, r12, pc} */
/* @0x2e8990 .word 0xf8da62a0 */
/* @0x2e8994 tstlt r3, r8, lsr r0 */
/* @0x2e8998 ldrmi r4, [r8, r0, lsr #12] */
/* @0x2e899c blls 0x34c9a8 */
/* @0x2e89a0 .word 0xf8c8b93b */
/* @0x2e89a4 .word 0xf1054000 */
/* @0x2e89a8 adcsvs r0, r12, r12, rrx */
/* @0x2e89ac .word 0xf7ff4639 */
/* @0x2e89b0 blls 0x368894 <_ZTS12CDS_Priority+0xa8ec> */
/* @0x2e89b4 shasxmi r11, r0, r11 */
/* @0x2e89b8 .word 0xf7fe4639 */
/* @0x2e89bc .word 0x4630fcbc */
/* @0x2e89c0 .word 0xf7fe4621 */
/* @0x2e89c4 stmdals r1, {r3, r4, r5, r7, r10, r11, r12, sp, lr, pc} */
/* @0x2e89c8 eorhs lr, r3, r4 */
/* @0x2e89cc andhs lr, r6, r2 */
/* @0x2e89d0 eorhs lr, r2, r0 */
/* @0x2e89d4 pop {r1, r12, sp, pc} */
/* @0x2e89d8 strdlt r8, r9, [r8, #-112] */

/* ── FUNC 0x2e8921 · FT_List_Add · size=24 · insn=0 */

/* ── FUNC 0x2e8939 · FT_New_Size · size=162 · insn=0 */

/* ── FUNC 0x2e89da · anon_2e89da · size=52 · insn=13 */
/* @0x2e89da .word 0xb141b148 */
/* @0x2e89de andhs r6, r0, #196608 */
/* @0x2e89e2 subvs r6, r11, r10 */
/* @0x2e89e6 subvs r11, r1, r11, lsl #18 */
/* @0x2e89ea andsvs lr, r9, r0 */
/* @0x2e89ee ldrbmi r6, [r0, -r1]! */
/* @0x2e89f2 qdaddlt r11, r0, r9 */
/* @0x2e89f6 stmdavs r10, {r0, r1, r3, r11, sp, lr} ^ */
/* @0x2e89fa subsvs r11, r10, r11, lsl #2 */
/* @0x2e89fe andvs lr, r2, r0 */
/* @0x2e8a02 andsvs r11, r3, r10, lsl #2 */
/* @0x2e8a06 subvs r4, r3, r0, ror r7 */
/* @0x2e8a0a push {r4, r5, r6, r8, r9, r10, lr} */

/* ── FUNC 0x2e89db · FT_List_Insert · size=24 · insn=0 */
