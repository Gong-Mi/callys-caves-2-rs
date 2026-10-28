/* libyoyo.so 覆盖卡组 0296
 * 函数 0x30a6d5..0x318d10，共 32 个；
 * 级别: 原始覆盖（锚点全挂，语义未钉）
 * 由 scripts/gen_cards.py 生成；锚点权威来源 asm/instructions.jsonl
 */

/* ── FUNC 0x30a6d5 · af_shaper_buf_destroy · size=6 · insn=0 */

/* ── FUNC 0x30a6da · anon_30a6da · size=41700 · insn=10425 */
/* @0x30a6da .word 0x43f8e92d */
/* @0x30a6de bvs 0x15dc14a <b2_toiTime+0xe82ca6> */
/* @0x30a6e2 ldmdavs r11, {r4, r7, r9, r10, lr} */
/* @0x30a6e6 .word 0xf8104604 */
/* @0x30a6ea stmdbhs r0!, {r0, r8, r9, r11, r12} */
/* @0x30a6ee ldmdbhs pc!, {r1, r3, r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x30a6f2 ldmdble r8, {r0, r2, r9, r10, lr} */
/* @0x30a6f6 stmdale r4, {r0, r1, r2, r3, r4, r6, r7, r8, r11, sp} */
/* @0x30a6fa tsteq pc, r1 */
/* @0x30a6fe stmdbne r2!, {r0, r8, r10, sp} ^ */
/* @0x30a702 stmibhs pc!, {r3, sp, lr, pc} ^ */
/* @0x30a706 .word 0xf001bf95 */
/* @0x30a70a .word 0xf001010f */
/* @0x30a70e strhs r0, [r2, #-0x107] */
/* @0x30a712 ldrb r2, [r4, r3, lsl #10]! */
/* @0x30a716 svcvs #0x1f814 */
/* @0x30a71a .word 0xf0064294 */
/* @0x30a71e b 0x148c022 <b2_toiTime+0xd32b7e> */
/* @0x30a722 mvnsle r1, r1, lsl #3 */
/* @0x30a726 strhs r4, [r0], #-1029 */
/* @0x30a72a strtmi r7, [lr], -pc, lsr #16 */
/* @0x30a72e .word 0xf0173501 */
/* @0x30a732 ldrsble r0, [r12], -pc */
/* @0x30a736 qsub16mi r2, r10, pc */
/* @0x30a73a ldmible r5!, {r2, r3, r4, r5, r9, r10, lr} ^ */
/* @0x30a73e stmdale r4, {r0, r1, r2, r3, r4, r6, r7, r8, r9, r10, r11, sp} */
/* @0x30a742 ldreq pc, [pc], #-7 */
/* @0x30a746 strmi r2, [r5], #-1 */
/* @0x30a74a svchs #0xefe008 */
/* @0x30a74e .word 0xf007bf95 */
/* @0x30a752 .word 0xf004040f */
/* @0x30a756 andhs r0, r2, r7, lsl #8 */
/* @0x30a75a ldrb r2, [r4, r3]! */
/* @0x30a75e bleq 0x3887ae <_ZTS13C_UTF16String+0x1f85a> */
/* @0x30a762 .word 0xf00042aa */
/* @0x30a766 b 0x130a86a <b2_toiTime+0xbb13c6> */
/* @0x30a76a mvnsle r1, r4, lsl #9 */
/* @0x30a76e ldrdlt lr, pc, [r4, -r12]! */
/* @0x30a772 andhs pc, r0, r8, asr #17 */
/* @0x30a776 andhs pc, r0, r9, asr #17 */
/* @0x30a77a ldrmi lr, [r8], -r7 */
/* @0x30a77e .word 0xf8eff7db */
/* @0x30a782 .word 0xf8c82301 */
/* @0x30a786 .word 0xf8c90000 */
/* @0x30a78a ldrtmi r3, [r0], -r0 */
/* @0x30a78e .word 0x83f8e8bd */
/* @0x30a792 bvs 0x13b7c7a <b2_toiTime+0xc5e7d6> */
/* @0x30a796 stmdavs sp, {r2, r10, r11, r12, pc} */
/* @0x30a79a .word 0xb1236810 */
/* @0x30a79e .word 0xf6404629 */
/* @0x30a7a2 .word 0xf7dd0203 */
/* @0x30a7a6 .word 0xb10cf8d4 */
/* @0x30a7aa eorvs r2, r3, r0, lsl #6 */
/* @0x30a7ae ldclt p6, c4, [r8, #-160]! */
/* @0x30a7b2 .word 0xe92d0000 */
/* @0x30a7b6 .word 0xf5ad4ff0 */
/* @0x30a7ba addslt r4, r11, r4, lsr #27 */
/* @0x30a7be svcge #0x1a4604 */
/* @0x30a7c2 .word 0x8064f8d1 */
/* @0x30a7c6 ldrbeq pc, [r4, #-0x1a7] */
/* @0x30a7ca .word 0xf640460e */
/* @0x30a7ce smlabths r0, r8, r2, r2 */
/* @0x30a7d2 .word 0xf04f4628 */
/* @0x30a7d6 .word 0xf5ab0b00 */
/* @0x30a7da .word 0xf504eeea */
/* @0x30a7de .word 0xf8c453e2 */
/* @0x30a7e2 shasxmi r11, r0, r4 */
/* @0x30a7e6 andslt pc, r4, r3, asr #17 */
/* @0x30a7ea blmi 0x20a487a <b2_toiTime+0x194b3d6> */
/* @0x30a7ee mrrchi p8, #0x4, pc, r4, c7 */
/* @0x30a7f2 ldrbtmi r6, [r11], #-2194 */
/* @0x30a7f6 .word 0xf853681b */
/* @0x30a7fa .word 0xf8d33022 */
/* @0x30a7fe .word 0xf7ff9010 */
/* @0x30a802 .word 0xf50dff5e */
/* @0x30a806 andslo r5, r12, #-268435444 */
/* @0x30a80a strmi r9, [r2], r3, lsl #4 */
/* @0x30a80e mullo r0, r9, r8 */
/* @0x30a812 .word 0x4648b1fb */
/* @0x30a816 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x30a81a blhs 0xb2882e <b2_toiTime+0x3cf38a> */
/* @0x30a81e .word 0xf50dd0f9 */
/* @0x30a822 ldrbmi r5, [r2], -pc, asr #7 */
/* @0x30a826 qadd16mi r3, r1, r12 */
/* @0x30a82a .word 0xff56f7ff */
/* @0x30a82e sbcpl pc, pc, #54525952 */
/* @0x30a832 ldmdavs r3, {r2, r3, r4, r9, r12, sp} */
/* @0x30a836 strmi r2, [r1], r1, lsl #22 */
/* @0x30a83a andhs sp, r0, #232, #16 */
/* @0x30a83e andlt pc, r0, sp, asr #17 */
/* @0x30a842 ldrbmi r4, [r1], -r0, lsr #12 */
/* @0x30a846 .word 0xf7ff4613 */
/* @0x30a84a strmi pc, [r0], r3, lsr #31 */
/* @0x30a84e sbcsle r2, sp, r0, lsl #16 */
/* @0x30a852 ldrmi lr, [r8], r0 */
/* @0x30a856 uasxmi r4, r1, r0 */
/* @0x30a85a .word 0xff3bf7ff */
/* @0x30a85e svceq #0xf1b8 */
/* @0x30a862 addhi pc, r8, r0 */
/* @0x30a866 .word 0x46414630 */
/* @0x30a86a .word 0xf7dc2201 */
/* @0x30a86e sxtab16mi pc, r2, r10, ror #24 */
/* @0x30a872 cmnle pc, r0, lsl #16 */
/* @0x30a876 ldrsblt pc, [r4], #-134 */
/* @0x30a87a strhtlo pc, [lr], #-155 */
/* @0x30a87e vldmdble r9!, {d18} */
/* @0x30a882 ldmpl r1, {r0, r2, r3, r8, r10, r12, sp, lr, pc} ^ */
/* @0x30a886 cpsie f */
/* @0x30a88a .word 0xf6430808 */
/* @0x30a88e .word 0xf1a8026c */
/* @0x30a892 strbmi r0, [r8], -r12, lsr #18 */
/* @0x30a896 cdp p5, #0x8, c15, c12, c11, #0x5 */
/* @0x30a89a .word 0xf8486aa3 */
/* @0x30a89e strtmi r6, [r8], -r8, lsr #24 */
/* @0x30a8a2 bls 0xff248bbe <b2_toiTime+0xfffffffffeaef71a> */
/* @0x30a8a6 .word 0x016cf10b */
/* @0x30a8aa .word 0x3c04f848 */
/* @0x30a8ae orrlo pc, r0, #1325400064 */
/* @0x30a8b2 bge 0xff048bce <b2_toiTime+0xfffffffffe8ef72a> */
/* @0x30a8b6 stclo p8, c15, [r4], #-288 */
/* @0x30a8ba stclo p8, c15, [r0], #-288 */
/* @0x30a8be mcr2 p7, #0x2, pc, c7, c12, #0x7 */
/* @0x30a8c2 cmple r7, r0, lsl #16 */
/* @0x30a8c6 ldrteq pc, [r8], -r4, lsl #2 */
/* @0x30a8ca ssatmi r3, #0x9, r8, asr #30 */
/* @0x30a8ce ldrbmi r4, [r9], -r3, lsl #13 */
/* @0x30a8d2 movwhs r4, #0x628 */
/* @0x30a8d6 .word 0xf7fd603b */
/* @0x30a8da .word 0xf1a6f8ae */
/* @0x30a8de strmi r0, [r1], -r12, lsl #20 */
/* @0x30a8e2 mrsle r2, spsr */
/* @0x30a8e6 strtmi r4, [r8], -r10, lsl #12 */
/* @0x30a8ea .word 0xf7fc465b */
/* @0x30a8ee .word 0xf8d8fd29 */
/* @0x30a8f2 .word 0xf8d82034 */
/* @0x30a8f6 .word 0x232c102c */
/* @0x30a8fa blx 0x3d2934 <error_g0017+0x2b5d8> */
/* @0x30a8fe addmi r2, r10, #1073741824 */
/* @0x30a902 .word 0xf8d2d222 */
/* @0x30a906 .word 0xf1bcc014 */
/* @0x30a90a andsle r0, r11, r0, lsl #30 */
/* @0x30a90e ldrsblo pc, [r4], -r12 */
/* @0x30a912 .word 0xd1174293 */
/* @0x30a916 ldmdble r5, {r2, r4, r7, r8, r10, lr} */
/* @0x30a91a strhlo pc, [r2], -r2 */
/* @0x30a91e strh pc, [r2], -r12 */
/* @0x30a922 vmlseq.f64 d14, d19, d14 */
/* @0x30a926 .word 0xf1be683b */
/* @0x30a92a svclt #0xb80f00 */
/* @0x30a92e cdpeq p1, #0x0, c15, c0, c14, #0x6 */
/* @0x30a932 stmdale r7, {r0, r1, r2, r3, r8, r9, r11, sp} */
/* @0x30a936 .word 0x0c01f103 */
/* @0x30a93a andgt pc, r0, r7, asr #17 */
/* @0x30a93e movwge pc, #0x3b00 */
/* @0x30a942 and pc, r12, r3, asr #17 */
/* @0x30a946 ldrb r3, [r10, r12, lsr #4] */
/* @0x30a94a .word 0x0028f8d9 */
/* @0x30a94e .word 0xf00e2164 */
/* @0x30a952 shsub16mi lr, r1, r10 */
/* @0x30a956 bleq 0x386d8a <_ZTS13C_UTF16String+0x1de36> */
/* @0x30a95a stmdapl r4, {r3, r9, r12, sp, lr, pc} ^ */
/* @0x30a95e ldrtmi r4, [r8], -r2, lsl #12 */
/* @0x30a962 blx 0xff70895c <b2_toiTime+0xfffffffffefaf4b8> */
/* @0x30a966 .word 0xf1bb683b */
/* @0x30a96a .word 0xf8460f02 */
/* @0x30a96e .word 0xf5063c04 */
/* @0x30a972 .word 0xd1ac56e1 */
/* @0x30a976 stmdbpl r1!, {r2, r8, r10, r12, sp, lr, pc} ^ */
/* @0x30a97a .word 0xf04f4626 */
/* @0x30a97e .word 0xf04f0832 */
/* @0x30a982 blvs 0x1fcd18a <b2_toiTime+0x1873ce6> */
/* @0x30a986 blvs 0xff0f6dba <b2_toiTime+0xfffffffffe99d916> */
/* @0x30a98a bvs 0xfed029aa <b2_toiTime+0xfffffffffe5a9506> */
/* @0x30a98e cmpmi r7, #69206016 */
/* @0x30a992 .word 0xf207bf48 */
/* @0x30a996 rscsne r7, pc, #66846720 */
/* @0x30a99a .word 0x21054638 */
/* @0x30a99e ldmib r8!, {r1, r2, r3, r12, sp, lr, pc} */
/* @0x30a9a2 rscsvc pc, r12, r6, asr #17 */
/* @0x30a9a6 smlabbge r0, r6, r8, pc */
/* @0x30a9aa rscseq pc, r8, r6, asr #17 */
/* @0x30a9ae strbtpl pc, [r1], r6, lsl #10 */
/* @0x30a9b2 mvnle r4, lr, asr #10 */
/* @0x30a9b6 .word 0xf7fd4628 */
/* @0x30a9ba .word 0xf50dff02 */
/* @0x30a9be andslt r4, r11, r4, lsr #27 */
/* @0x30a9c2 svchi #0xf0e8bd */
/* @0x30a9c6 mvnsvc r11, #0, #30 */
/* @0x30a9ca push {r1, r2, r3} */
/* @0x30a9ce .word 0x46074ff0 */
/* @0x30a9d2 rscslt r6, r3, r3, lsl #16 */
/* @0x30a9d6 strmi r4, [r8], r8, lsl #12 */
/* @0x30a9da blmi 0xfea24d5a <b2_toiTime+0xfffffffffe2cb8b6> */
/* @0x30a9de ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x30a9e2 strbeq lr, [r6], r3, lsl #22 */
/* @0x30a9e6 mcr2 p7, #0x3, pc, c11, c15, #0x7 */
/* @0x30a9ea strlo r9, [r8], -r5 */
/* @0x30a9ee .word 0x2c08f856 */
/* @0x30a9f2 msrmi CPSR_fc, #268435460 */
/* @0x30a9f6 .word 0xf000429a */
/* @0x30a9fa blmi 0xfe86ae8a <b2_toiTime+0xfffffffffe1119e6> */
/* @0x30a9fe strtmi r2, [r5], -r0, lsl #8 */
/* @0x30aa02 ldrbtmi r2, [r11], #-1 */
/* @0x30aa06 andls r6, r6, r11, lsl r8 */
/* @0x30aa0a movwls r1, #0x38d3 */
/* @0x30aa0e .word 0x3c04f836 */
/* @0x30aa12 stmdbge r11, {r0, r3, r4, r7, r8, r9, r10} */
/* @0x30aa16 .word 0xf507bf56 */
/* @0x30aa1a .word 0xf10759e2 */
/* @0x30aa1e .word 0xf109092c */
/* @0x30aa22 mrsls r0, apsr */
/* @0x30aa26 stmdavc r11, {r0, r1, r8, r11, r12, pc} */
/* @0x30aa2a .word 0xf0002b00 */
/* @0x30aa2e .word 0x460b80bb */
/* @0x30aa32 .word 0xf8134618 */
/* @0x30aa36 bhs 0xb15642 <b2_toiTime+0x3bc19e> */
/* @0x30aa3a bhs 0x223ee2a <b2_toiTime+0x1ae5986> */
/* @0x30aa3e andhs sp, r0, #-1073741824 */
/* @0x30aa42 andls r9, r6, #201326592 */
/* @0x30aa46 blge 0x604a06 <g_SWFaavertbuff+0x3193e> */
/* @0x30aa4a bls 0x45c336 <g_RomDisk+0x64b16> */
/* @0x30aa4e mcr2 p7, #0x2, pc, c4, c15, #0x7 */
/* @0x30aa52 blhs 0x371686 <_ZTS13C_UTF16String+0x8732> */
/* @0x30aa56 stmle r5!, {r0, r1, r12, pc} ^ */
/* @0x30aa5a stmdbls r5, {r8, r9, sp} */
/* @0x30aa5e ldrtmi r9, [r8], -r0, lsl #6 */
/* @0x30aa62 .word 0xf7ff461a */
/* @0x30aa66 .word 0x4601fe95 */
/* @0x30aa6a sbcsle r2, r11, r0, lsl #16 */
/* @0x30aa6e strbmi r2, [r0], -r1, lsl #4 */
/* @0x30aa72 ldc2l p7, c15, [r7, #-880]! */
/* @0x30aa76 ldrsblo pc, [r4], #-136 */
/* @0x30aa7a rfeia r3! */
/* @0x30aa7e rfeia r3! */
/* @0x30aa82 svcvs #0x9b206e */
/* @0x30aa86 movwls r9, #0x8104 */
/* @0x30aa8a bicle r2, r11, r0, lsl #16 */
/* @0x30aa8e bhs 0x3b72de <error_g0017+0xff82> */
/* @0x30aa92 strmi sp, [r3], -r8, asr #27 */
/* @0x30aa96 .word 0xf04f4686 */
/* @0x30aa9a .word 0x460231ff */
/* @0x30aa9e stc2 p10, c15, [r12], {15} */
/* @0x30aaa2 eorgt pc, r4, sp, asr #17 */
/* @0x30aaa6 strmi r9, [r6, #0x809] */
/* @0x30aaaa stmdals r8, {r1, r2, r3, r5, r6, r9, r11, r12, lr, pc} */
/* @0x30aaae andseq pc, lr, r0, lsr r9 */
/* @0x30aab2 mulls r2, r8, r2 */
/* @0x30aab6 rfeda r6! */
/* @0x30aaba .word 0xf00ccc04 */
/* @0x30aabe .word 0xf00c0b02 */
/* @0x30aac2 blx 0xacdace <b2_toiTime+0x37462a> */
/* @0x30aac6 blx 0xb098fa <b2_toiTime+0x3b0456> */
/* @0x30aaca .word 0xf1bbfc8c */
/* @0x30aace eorle r0, r7, r0, lsl #30 */
/* @0x30aad2 b 0x16f0aea <b2_toiTime+0xf97646> */
/* @0x30aad6 strmi r0, [r3], #3011 */
/* @0x30aada svceq #0xf1bc */
/* @0x30aade .word 0xf04fd019 */
/* @0x30aae2 stmdals r2, {r10, r11} */
/* @0x30aae6 mcrrle p2, #0x8, r4, r10, c3 */
/* @0x30aaea .word 0xf85b2900 */
/* @0x30aaee blle 0x372b26 <_ZTS13C_UTF16String+0x9bd2> */
/* @0x30aaf2 stcle p5, c4, [r1, #-584] */
/* @0x30aaf6 ssaxmi r4, r9, r2 */
/* @0x30aafa .word 0xf10c3301 */
/* @0x30aafe ldrb r0, [r0, r8, lsl #24]! */
/* @0x30ab02 .word 0xf85b2900 */
/* @0x30ab06 blle 0x532b3e <SrcVerts+0x8fb82> */
/* @0x30ab0a blle 0x49c15a <TimingData+0x2142> */
/* @0x30ab0e .word 0xf10c3301 */
/* @0x30ab12 stmdals r2, {r3, r10, r11} */
/* @0x30ab16 ldclle p2, c4, [r3, #524]! */
/* @0x30ab1a uasxmi lr, r2, r1 */
/* @0x30ab1e .word 0xe7f54619 */
/* @0x30ab22 b 0x16f0b3a <b2_toiTime+0xf97696> */
/* @0x30ab26 strmi r0, [r2], #2755 */
/* @0x30ab2a svceq #0xf1bc */
/* @0x30ab2e .word 0x46dcd01e */
/* @0x30ab32 addmi r9, r3, #131072 */
/* @0x30ab36 stmdbhs r0, {r0, r1, r5, r10, r11, r12, lr, pc} */
/* @0x30ab3a bl 0x5c1756 <g_SWFlineaavertbuff+0x6e68e> */
/* @0x30ab3e .word 0xf8db0b0c */
/* @0x30ab42 ldrmi r11, [r3, #0x4] */
/* @0x30ab46 bl 0x5c1f5a <g_SWFlineaavertbuff+0x6ee92> */
/* @0x30ab4a ldrmi r0, [r9], -r12, lsl #4 */
/* @0x30ab4e movwlo r6, #0x1852 */
/* @0x30ab52 .word 0x0c08f10c */
/* @0x30ab56 stmdbhs r0, {r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30ab5a bl 0x5c1792 <g_SWFlineaavertbuff+0x6e6ca> */
/* @0x30ab5e .word 0xf8db0b0c */
/* @0x30ab62 ldrmi r11, [r3, #0x4] */
/* @0x30ab66 movwlo sp, #0x1b06 */
/* @0x30ab6a .word 0x0c08f10c */
/* @0x30ab6e addmi r9, r3, #131072 */
/* @0x30ab72 strd sp, lr, [r4], -r1 */
/* @0x30ab76 andeq lr, r12, #10240 */
/* @0x30ab7a ldmdavs r2, {r0, r3, r4, r9, r10, lr} ^ */
/* @0x30ab7e stmdals r2, {r0, r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30ab82 cdpeq p1, #0x0, c15, c1, c14, #0x0 */
/* @0x30ab86 str r1, [sp, r3, asr #24] */
/* @0x30ab8a .word 0xb1219906 */
/* @0x30ab8e .word 0xf843ab0c */
/* @0x30ab92 strlo r2, [r1, #-0x25] */
/* @0x30ab96 ldmdage r2!, {r1, r2, r6, r8, r9, r10, sp, lr, pc} ^ */
/* @0x30ab9a orreq lr, r4, #0, #22 */
/* @0x30ab9e .word 0xf8433401 */
/* @0x30aba2 ldr r2, [pc, -r12, asr #25]! */
/* @0x30aba6 stchs p9, c11, [r0, #-80] */
/* @0x30abaa svcge #0x1ff43f */
/* @0x30abae beq 0xf46fea <b2_toiTime+0x7edb46> */
/* @0x30abb2 ldrbmi r4, [r1], -r8, lsr #12 */
/* @0x30abb6 blx 0xfe788bae <b2_toiTime+0xfffffffffe02f70a> */
/* @0x30abba qasxmi r10, r0, pc */
/* @0x30abbe blx 0xfe688bb6 <b2_toiTime+0xfffffffffdf2f712> */
/* @0x30abc2 ldrsbne pc, [r8], #137 */
/* @0x30abc6 blx 0x393440 <ft_adobe_glyph_list+0x2b1c> */
/* @0x30abca .word 0x31019201 */
/* @0x30abce sbcsne pc, r8, r9, asr #17 */
/* @0x30abd2 ldcne p2, c3, [r3, #-864] */
/* @0x30abd6 stmdaeq sp!, {r2, r3, r4, r8, r11, r12, sp, pc} ^ */
/* @0x30abda eorne pc, r5, r10, asr r8 */
/* @0x30abde stmdaeq r4!, {r1, r2, sp, lr, pc} ^ */
/* @0x30abe2 ldmdage r2!, {r0, r2, r3, r4, r5, r8, r11, r12, sp, pc} ^ */
/* @0x30abe6 streq lr, [r4], #2816 */
/* @0x30abea stclne p8, c15, [r12], {84} */
/* @0x30abee ldrsbvs r6, [r1], #-9 */
/* @0x30abf2 stmdaeq sp!, {r0, r3, sp, lr, pc} ^ */
/* @0x30abf6 eorne pc, r5, r10, asr r8 */
/* @0x30abfa ldmdbge r2!, {r0, r4, r6, sp, lr} ^ */
/* @0x30abfe streq lr, [r4], #2817 */
/* @0x30ac02 stclne p8, c15, [r12], {84} */
/* @0x30ac06 ldmvs r8, {r0, r3, r4, r6, r7, sp, lr} ^ */
/* @0x30ac0a addmi r6, r8, #5308416 */
/* @0x30ac0e rfeda r6! */
/* @0x30ac12 svclt #0xac5c04 */
/* @0x30ac16 strhs r2, [r1], #-1024 */
/* @0x30ac1a streq pc, [r1, #-0x5] */
/* @0x30ac1e andle r4, r5, r5, lsr #5 */
/* @0x30ac22 bl 0x35bc2e */
/* @0x30ac26 ldrdne r7, r8, [r9], #-17 */
/* @0x30ac2a ldrsbvs r6, [r1], #-9 */
/* @0x30ac2e orrsvs r2, r10, r0, lsl #4 */
/* @0x30ac32 .word 0x2c04f836 */
/* @0x30ac36 svclt #0x4407d2 */
/* @0x30ac3a orrsvs r2, r10, r2, lsl #4 */
/* @0x30ac3e .word 0x4640e6d5 */
/* @0x30ac42 .word 0xf7ff9905 */
/* @0x30ac46 rsbslt pc, r3, r6, asr #26 */
/* @0x30ac4a svchi #0xf0e8bd */
/* @0x30ac4e andsvc r11, r2, #0, #30 */
/* @0x30ac52 mvnsvc r0, lr */
/* @0x30ac56 push {r1, r2, r3} */
/* @0x30ac5a .word 0x460f4ff0 */
/* @0x30ac5e addlt r4, sp, sp, lsr #18 */
/* @0x30ac62 strmi r10, [r5], -r6, lsl #20 */
/* @0x30ac66 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x30ac6a ldrmi r9, [r0], r3, lsl #2 */
/* @0x30ac6e movwls r6, #0xb80b */
/* @0x30ac72 movwls r2, #0x4300 */
/* @0x30ac76 ldrbtmi r4, [r11], #-2856 */
/* @0x30ac7a ldreq pc, [r0], -r3, lsl #2 */
/* @0x30ac7e movwlo r6, #0x8818 */
/* @0x30ac82 .word 0x1c04f853 */
/* @0x30ac86 .word 0x461442b3 */
/* @0x30ac8a strtmi r12, [r2], -r3, lsl #8 */
/* @0x30ac8e ldmdavs r8, {r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x30ac92 ldmdbeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x30ac96 beq 0x7470d2 <g_SWFvertbuff+0x7400a> */
/* @0x30ac9a eorvs r4, r0, r3, asr #13 */
/* @0x30ac9e .word 0xf7ff4638 */
/* @0x30aca2 strhs pc, [r0], #-3342 */
/* @0x30aca6 strmi r4, [r6], -r0, lsr #13 */
/* @0x30acaa mullo r0, r11, r8 */
/* @0x30acae usub8mi r11, r8, r11 */
/* @0x30acb2 strtmi r4, [r9], -r11, asr #12 */
/* @0x30acb6 .word 0xf7ff4632 */
/* @0x30acba blls 0x48a0fe <prim_v+0x74a> */
/* @0x30acbe strmi r2, [r3], r1, lsl #22 */
/* @0x30acc2 strdhs sp, lr, [r0, -r2] */
/* @0x30acc6 .word 0x91004628 */
/* @0x30acca ldrtmi r2, [r1], -r0, lsl #4 */
/* @0x30acce .word 0xf7ff4653 */
/* @0x30acd2 stmdahs r0, {r0, r1, r2, r3, r4, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x30acd6 blls 0x43f07e <g_RomDisk+0x4785e> */
/* @0x30acda svceq #0xf1b8 */
/* @0x30acde adcmi sp, r3, #3 */
/* @0x30ace2 strhs sp, [r0], #-2 */
/* @0x30ace6 ldrmi lr, [r12], -r4 */
/* @0x30acea stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30acee strhs lr, [r1], #-2012 */
/* @0x30acf2 shasxmi r4, r8, r1 */
/* @0x30acf6 stc2l p7, c15, [sp], #1020 */
/* @0x30acfa bls 0x5f110e <g_SWFaavertbuff+0x1e046> */
/* @0x30acfe eormi pc, r0, r5, lsl #17 */
/* @0x30ad02 addsmi r6, r10, #720896 */
/* @0x30ad06 .word 0xf5abd001 */
/* @0x30ad0a andlt lr, sp, r4, ror #24 */
/* @0x30ad0e svchi #0xf0e8bd */
/* @0x30ad12 stclhs p15, c11, [lr], #0 */
/* @0x30ad16 movtmi r0, #0x500e */
/* @0x30ad1a ldrblt r0, [r0, #-0x8]! */
/* @0x30ad1e rfeia r1! */
/* @0x30ad22 strmi r3, [r12], -r4, asr #32 */
/* @0x30ad26 addvs r6, r3, #13184 */
/* @0x30ad2a stmdbmi r10, {r3, r9, r10, lr} */
/* @0x30ad2e stc2l p7, c15, [r1, #872]! */
/* @0x30ad32 qsaxmi r11, r8, r8 */
/* @0x30ad36 .word 0xf7ff4621 */
/* @0x30ad3a qasxmi pc, r8, r12 */
/* @0x30ad3e .word 0xf7ff4621 */
/* @0x30ad42 strtmi pc, [r8], -r4, asr #28 */
/* @0x30ad46 .word 0xf7ff4621 */
/* @0x30ad4a strtmi pc, [r0], -r6, lsl #31 */
/* @0x30ad4e .word 0xf7da4631 */
/* @0x30ad52 .word 0x2000ffd4 */
/* @0x30ad56 stmdbvs r3!, {r4, r5, r6, r8, r10, r11, r12, sp, pc} ^ */
/* @0x30ad5a ldrblt r7, [r0, #-0x56e]! */
/* @0x30ad5e rfeia r1! */
/* @0x30ad62 strmi r3, [r12], -r4, asr #32 */
/* @0x30ad66 addvs r6, r3, #13184 */
/* @0x30ad6a stmdbmi r10, {r3, r9, r10, lr} */
/* @0x30ad6e stc2l p7, c15, [r1, #872] */
/* @0x30ad72 movwhs r11, #0x110 */
/* @0x30ad76 and r6, r7, r3, ror #11 */
/* @0x30ad7a strtmi r4, [r1], -r8, lsr #12 */
/* @0x30ad7e ldc2 p7, c15, [r9, #-1020] */
/* @0x30ad82 strtmi r4, [r1], -r8, lsr #12 */
/* @0x30ad86 .word 0xff67f7ff */
/* @0x30ad8a ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x30ad8e .word 0xffb5f7da */
/* @0x30ad92 ldcllt p0, c2, [r0, #-0]! */
/* @0x30ad96 stmdbvs r3!, {r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x30ad9a push {r1, r2, r3, r5, r6, r8, r10, r12, sp, lr} */
/* @0x30ad9e .word 0xf5ad4ff0 */
/* @0x30ada2 addslt r4, pc, r3, asr #27 */
/* @0x30ada6 .word 0xf10d4604 */
/* @0x30adaa mcrvs p8, #0x2, r0, c15, c8, #0x3 */
/* @0x30adae strbeq pc, [r4, #-0x1a8]! */
/* @0x30adb2 .word 0xf640460e */
/* @0x30adb6 smlabths r0, r8, r2, r2 */
/* @0x30adba .word 0xf50d4628 */
/* @0x30adbe .word 0xf5ab5acf */
/* @0x30adc2 .word 0xf504ebf6 */
/* @0x30adc6 .word 0xf8485310 */
/* @0x30adca strhs r7, [r0, -r4, ror #24] */
/* @0x30adce ldrtmi r6, [r0], -r7, ror #6 */
/* @0x30add2 .word 0xf10a61df */
/* @0x30add6 stmdavs r2!, {r2, r3, r4, r9, r11} */
/* @0x30adda ldmvs r2, {r1, r2, r4, r5, r6, r8, r9, r11, lr} */
/* @0x30adde ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x30ade2 eorlo pc, r2, r3, asr r8 */
/* @0x30ade6 ldrsbls pc, [r0], -r3 */
/* @0x30adea stc2l p7, c15, [r9], #-1020 */
/* @0x30adee .word 0xf8994683 */
/* @0x30adf2 bicslt r7, r7, r0 */
/* @0x30adf6 .word 0xf1094648 */
/* @0x30adfa stmdavc r3, {r0, r8, r11} */
/* @0x30adfe rscsle r2, r9, r0, lsr #22 */
/* @0x30ae02 qsaxmi r4, r1, r3 */
/* @0x30ae06 .word 0xf7ff465a */
/* @0x30ae0a .word 0xf8dafc67 */
/* @0x30ae0e blhs 0x356e16 */
/* @0x30ae12 stmle r12!, {r0, r7, r9, r10, lr} ^ */
/* @0x30ae16 .word 0x21002200 */
/* @0x30ae1a .word 0x91004620 */
/* @0x30ae1e uadd16mi r4, r9, r3 */
/* @0x30ae22 ldc2 p7, c15, [r6], #1020 */
/* @0x30ae26 stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x30ae2a ldrtmi sp, [r0], -r1, ror #1 */
/* @0x30ae2e .word 0xf7ff4659 */
/* @0x30ae32 svchs #0xfc50 */
/* @0x30ae36 addshi pc, r1, r0 */
/* @0x30ae3a shasxmi r4, r9, r0 */
/* @0x30ae3e .word 0xf7dc2201 */
/* @0x30ae42 pkhbtmi pc, r1, r0, lsl #23 */
/* @0x30ae46 .word 0xf0402800 */
/* @0x30ae4a .word 0xf8d68088 */
/* @0x30ae4e rfeib r11! */
/* @0x30ae52 blhs 0x317012 <ft_lzwstate_io+0x5e> */
/* @0x30ae56 addhi pc, r1, r0, asr #6 */
/* @0x30ae5a ldrbpl pc, [r3, sp, lsl #10] */
/* @0x30ae5e ldrlo r4, [r8, -r9, asr #12] */
/* @0x30ae62 rscsvc pc, r12, #68, #4 */
/* @0x30ae66 beq 0x224750a <b2_toiTime+0x1aee066> */
/* @0x30ae6a .word 0xf5ab4650 */
/* @0x30ae6e bvs 0xfec05cf6 <b2_toiTime+0xfffffffffe4ac852> */
/* @0x30ae72 ldclvs p8, c15, [r8], #-284 */
/* @0x30ae76 .word 0xf8c54628 */
/* @0x30ae7a .word 0xf10baabc */
/* @0x30ae7e .word 0xf847016c */
/* @0x30ae82 .word 0xf44f3c54 */
/* @0x30ae86 .word 0xf8c53380 */
/* @0x30ae8a .word 0xf8479ab4 */
/* @0x30ae8e .word 0xf8473c74 */
/* @0x30ae92 .word 0xf7fc3c70 */
/* @0x30ae96 stmdahs r0, {r2, r3, r4, r6, r8, r9, r11, r12, sp, lr, pc} */
/* @0x30ae9a .word 0xf104d15f */
/* @0x30ae9e .word 0xf1a80738 */
/* @0x30aea2 strtmi r0, [r9], r8, ror #16 */
/* @0x30aea6 .word 0xf04f4606 */
/* @0x30aeaa .word 0x21000b2c */
/* @0x30aeae .word 0xf8c84628 */
/* @0x30aeb2 ldrtmi r1, [r1], -r0 */
/* @0x30aeb6 movweq pc, #0xc1a7 */
/* @0x30aeba .word 0xf7fc9303 */
/* @0x30aebe .word 0x4601fdbc */
/* @0x30aec2 mrsle r2, spsr */
/* @0x30aec6 strtmi r4, [r8], -r10, lsl #12 */
/* @0x30aeca .word 0xf7fc4633 */
/* @0x30aece .word 0xf8d9fa39 */
/* @0x30aed2 .word 0xf8d92034 */
/* @0x30aed6 andhs r1, r12, r12, lsr #32 */
/* @0x30aeda .word 0x2101fb0b */
/* @0x30aede blls 0x3af2ee <error_g0017+0x7f92> */
/* @0x30aee2 eorle r4, r3, #-1610612727 */
/* @0x30aee6 mvnslt r6, r3, asr r9 */
/* @0x30aeea addsmi r6, r1, #1458176 */
/* @0x30aeee addsmi sp, r3, #28, #2 */
/* @0x30aef2 rfeia r3! */
/* @0x30aef6 .word 0xf8d8e002 */
/* @0x30aefa rfeia r2! */
/* @0x30aefe blhs 0x6faf0e <g_SWFvertbuff+0x27e46> */
/* @0x30af02 mrrcne p8, #0x1, sp, r9, c2 */
/* @0x30af06 andne pc, r0, r8, asr #17 */
/* @0x30af0a blx 0x6f131e <g_SWFvertbuff+0x1e256> */
/* @0x30af0e blx 0x70a146 <g_SWFvertbuff+0x3707e> */
/* @0x30af12 bl 0xff6ca952 <b2_toiTime+0xfffffffffef714ae> */
/* @0x30af16 blx 0x30df50 <af_shaper_get_elem+0x37be> */
/* @0x30af1a .word 0xf1bc1303 */
/* @0x30af1e svclt #0xb80f00 */
/* @0x30af22 .word 0x0c00f1cc */
/* @0x30af26 andgt pc, r12, r3, asr #17 */
/* @0x30af2a ldrb r3, [r8, r12, lsr #4] */
/* @0x30af2e .word 0x0028f8da */
/* @0x30af32 .word 0xf00d2164 */
/* @0x30af36 ldrtmi lr, [r9], -r8, lsl #29 */
/* @0x30af3a vmax.s8 d3, d9, d1 */
/* @0x30af3e strmi r5, [r2], -r4, asr #18 */
/* @0x30af42 .word 0xf7fc4640 */
/* @0x30af46 .word 0xf8d8f8de */
/* @0x30af4a cdphs p0, #0x0, c3, c2, c0, #0x0 */
/* @0x30af4e .word 0x3c04f847 */
/* @0x30af52 strpl pc, [pc, -r7, lsl #10] */
/* @0x30af56 streq pc, [r8, -r7, lsl #2]! */
/* @0x30af5a .word 0xf504d1a7 */
/* @0x30af5e strtmi r4, [r6], -pc, lsl #19 */
/* @0x30af62 ldmdbeq r0, {r0, r3, r8, r12, sp, lr, pc} ^ */
/* @0x30af66 ldmdaeq r2!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30af6a beq 0x3470ae */
/* @0x30af6e .word 0xb10b6b73 */
/* @0x30af72 strh r6, [r6], -r7 */
/* @0x30af76 strbmi r6, [r1], -r7, lsr #21 */
/* @0x30af7a svclt #0x48434f */
/* @0x30af7e ldrbvc pc, [pc, r7, lsl #4]! */
/* @0x30af82 shsub8mi r1, r8, pc */
/* @0x30af86 .word 0xf00d2105 */
/* @0x30af8a .word 0xf8c6eec2 */
/* @0x30af8e .word 0xf88670fc */
/* @0x30af92 .word 0xf8c6a100 */
/* @0x30af96 .word 0xf50600f8 */
/* @0x30af9a strtlo r5, [r8], -pc, lsl #12 */
/* @0x30af9e mvnle r4, lr, asr #10 */
/* @0x30afa2 .word 0xf7fd4628 */
/* @0x30afa6 .word 0xf50dfc0c */
/* @0x30afaa andslt r4, pc, r3, asr #27 */
/* @0x30afae svchi #0xf0e8bd */
/* @0x30afb2 cdpvs p15, #0x0, c11, c6, c0, #0x0 */
/* @0x30afb6 push {r1, r2, r3} */
/* @0x30afba .word 0xf5ad4ff0 */
/* @0x30afbe stmdavs r3, {r0, r4, r8, r10, r11, r12, sp, lr} */
/* @0x30afc2 tstls r3, r11 */
/* @0x30afc6 ldmvs r12, {r1, r2, r3, r8, sp} ^ */
/* @0x30afca ssatlo pc, #0x19, pc, asr #17 */
/* @0x30afce ldrbtmi r6, [r11], #-2688 */
/* @0x30afd2 bl 0x3e5046 <error_g0017+0x3dcea> */
/* @0x30afd6 .word 0xf00d04c4 */
/* @0x30afda .word 0xf104ee36 */
/* @0x30afde andsls r0, r11, r8, lsl #22 */
/* @0x30afe2 .word 0xf7ff9813 */
/* @0x30afe6 andsls pc, r6, r12, ror #22 */
/* @0x30afea .word 0x2c08f85b */
/* @0x30afee msrmi CPSR_fc, #268435460 */
/* @0x30aff2 .word 0xf000429a */
/* @0x30aff6 .word 0xf8df82ea */
/* @0x30affa andhs r3, r0, r12, lsl #13 */
/* @0x30affe ldrbtmi r9, [r11], #-9 */
/* @0x30b002 andsls r6, r0, r11, lsl r8 */
/* @0x30b006 ldrdls r1, r2, [r8], -r3 */
/* @0x30b00a andls r9, sp, r4, lsl r3 */
/* @0x30b00e stmdavc r11, {r2, r4, r8, r11, r12, pc} */
/* @0x30b012 .word 0xf0002b00 */
/* @0x30b016 strmi r8, [r11], -r3, ror #4 */
/* @0x30b01a movwlo r4, #0x1618 */
/* @0x30b01e bhs 0xb2902e <b2_toiTime+0x3cfb8a> */
/* @0x30b022 stcge p0, c13, [r0], #-1000 */
/* @0x30b026 bls 0x8b145a <b2_toiTime+0x157fb6> */
/* @0x30b02a .word 0xf7ff4623 */
/* @0x30b02e stmdavs r3!, {r0, r2, r4, r6, r8, r9, r11, r12, sp, lr, pc} */
/* @0x30b032 blhs 0x32f08a */
/* @0x30b036 rfeda r11! */
/* @0x30b03a .word 0xf04f3c04 */
/* @0x30b03e .word 0xf8cd0900 */
/* @0x30b042 .word 0xf0139044 */
/* @0x30b046 .word 0xf8cd0f01 */
/* @0x30b04a svclt #0xc9054 */
/* @0x30b04e .word 0x4100f06f */
/* @0x30b052 .word 0x4100f04f */
/* @0x30b056 blls 0xb2f496 <b2_toiTime+0x3d5ff2> */
/* @0x30b05a .word 0x9044f8dd */
/* @0x30b05e .word 0xf0804599 */
/* @0x30b062 ldmdbls r6, {r0, r5, r9, pc} */
/* @0x30b066 stmdals r11, {r0, r1, r2, r3, r4, r10, r11, sp, pc} */
/* @0x30b06a strls r2, [r0], #-768 */
/* @0x30b06e .word 0xf7ff9a11 */
/* @0x30b072 strmi pc, [r1], -pc, lsl #23 */
/* @0x30b076 .word 0xf0002800 */
/* @0x30b07a andhs r8, r1, #-536870912 */
/* @0x30b07e .word 0xf7dc9813 */
/* @0x30b082 ldmdbls r3, {r4, r5, r6, r9, r11, r12, sp, lr, pc} */
/* @0x30b086 svcvs #0x516d4a */
/* @0x30b08a strhtls pc, [r12], #-130 */
/* @0x30b08e strhtlo pc, [lr], #-130 */
/* @0x30b092 .word 0x910a6f15 */
/* @0x30b096 ldrsbtge pc, [r8], #-130 */
/* @0x30b09a .word 0xf0402800 */
/* @0x30b09e andslt r8, r11, #252, #2 */
/* @0x30b0a2 .word 0xf3402b02 */
/* @0x30b0a6 stmdavs r4!, {r3, r4, r5, r6, r7, r8, pc} */
/* @0x30b0aa .word 0xf989fa0f */
/* @0x30b0ae .word 0xf04f4606 */
/* @0x30b0b2 strdls r3, r4, [r12], -pc */
/* @0x30b0b6 andls r9, r7, r2, lsl r4 */
/* @0x30b0ba blls 0x62f0da <g_SWFaavertbuff+0x5c012> */
/* @0x30b0be ble 0x1b1c5f2 <b2_toiTime+0x13c314e> */
/* @0x30b0c2 rfedb r10! */
/* @0x30b0c6 addmi r2, r2, #19 */
/* @0x30b0ca rfeda r11! */
/* @0x30b0ce b 0x16ea0e6 <b2_toiTime+0xf90c42> */
/* @0x30b0d2 strtmi r0, [lr], #3776 */
/* @0x30b0d6 .word 0xf0174604 */
/* @0x30b0da strbmi r0, [r3], -r3, lsl #14 */
/* @0x30b0de strhs sp, [r0, -pc, lsr #32] */
/* @0x30b0e2 ldcle p2, c4, [sp], #-592 */
/* @0x30b0e6 blle 0x455cee <g_RomDisk+0x5e4ce> */
/* @0x30b0ea .word 0x0c07eb0e */
/* @0x30b0ee .word 0xc004f8dc */
/* @0x30b0f2 stcle p5, c4, [r11, #-720] */
/* @0x30b0f6 movweq lr, #0x7b0e */
/* @0x30b0fa ldmdavs lr, {r1, r4, r8, r11, r12, pc} ^ */
/* @0x30b0fe ldrtmi r9, [r1], #-2832 */
/* @0x30b102 svclt #0xb8428b */
/* @0x30b106 tstls r0, #11534336 */
/* @0x30b10a and r4, r6, r3, lsr #12 */
/* @0x30b10e strmi r9, [r12], #2322 */
/* @0x30b112 strbmi r9, [r1, #-0x909]! */
/* @0x30b116 strbtmi r11, [r1], -r8, lsr #31 */
/* @0x30b11a strlo r9, [r1], #-265 */
/* @0x30b11e ldrb r3, [pc, r8, lsl #14] */
/* @0x30b122 ble 0x6d5d2a <g_SWFvertbuff+0x2c62> */
/* @0x30b126 movweq lr, #0x7b0e */
/* @0x30b12a ldmdavs lr, {r0, r3, r8, r11, r12, pc} ^ */
/* @0x30b12e ldrtmi r9, [r3], #-2834 */
/* @0x30b132 svclt #0xa84299 */
/* @0x30b136 qadd16mi r4, r3, r9 */
/* @0x30b13a strlo r9, [r1], #-265 */
/* @0x30b13e addsmi r3, r4, #8, #14 */
/* @0x30b142 and sp, sp, lr, ror #27 */
/* @0x30b146 .word 0x0c07eb0e */
/* @0x30b14a .word 0xc004f8dc */
/* @0x30b14e blle 0xffd5c826 <b2_toiTime+0xffffffffff603382> */
/* @0x30b152 strmi r9, [r12], #2322 */
/* @0x30b156 strbmi r9, [r1, #-0x910]! */
/* @0x30b15a .word 0x4661bfb8 */
/* @0x30b15e .word 0xe7ec9110 */
/* @0x30b162 strbmi r9, [r3, #-0x907] */
/* @0x30b166 sadd16mi r11, r1, r8 */
/* @0x30b16a stmdbls r6, {r0, r1, r2, r8, r12, pc} */
/* @0x30b16e .word 0x4601bf18 */
/* @0x30b172 and r9, r0, r6, lsl #2 */
/* @0x30b176 mrrcne p6, #0x4, r4, r0, c3 */
/* @0x30b17a ldrmi r9, [r8], r12, lsl #20 */
/* @0x30b17e andls r3, r12, #268435456 */
/* @0x30b182 .word 0xf1b8e79b */
/* @0x30b186 .word 0xf8cd0f00 */
/* @0x30b18a vmvn.i32 d24, #0xc */
/* @0x30b18e bls 0x5ab76e <g_SWFlineaavertbuff+0x586a6> */
/* @0x30b192 .word 0xf8554647 */
/* @0x30b196 andshs r9, r4, r8, lsr r0 */
/* @0x30b19a andlo pc, r8, r2, lsl r8 */
/* @0x30b19e movweq pc, #0x3003 */
/* @0x30b1a2 svclt #0xc2b01 */
/* @0x30b1a6 .word 0xf04f46c4 */
/* @0x30b1aa .word 0x46e23cff */
/* @0x30b1ae addsmi r9, pc, #6144 */
/* @0x30b1b2 .word 0xf107bfcc */
/* @0x30b1b6 blls 0x4d81ba <SrcVerts+0x351fe> */
/* @0x30b1ba sbceq lr, r3, #5120 */
/* @0x30b1be blne 0xfe56530a <b2_toiTime+0xfffffffffde0be66> */
/* @0x30b1c2 svclt #0xb82900 */
/* @0x30b1c6 stmdbhs r5, {r0, r3, r6, r9, lr} */
/* @0x30b1ca .word 0xf855dd09 */
/* @0x30b1ce movtmi r2, #0x1033 */
/* @0x30b1d2 andeq lr, r2, #205824 */
/* @0x30b1d6 svclt #0xb82a00 */
/* @0x30b1da addmi r4, r10, #536870917 */
/* @0x30b1de stmdbls r10, {r0, r1, r2, r3, r8, r10, r11, r12, lr, pc} */
/* @0x30b1e2 .word 0xf0025cca */
/* @0x30b1e6 bhs 0x34b9fa */
/* @0x30b1ea .word 0xf1bad104 */
/* @0x30b1ee ldrmi r0, [r12], r0, lsl #30 */
/* @0x30b1f2 .word 0x469abfb8 */
/* @0x30b1f6 andle r4, r1, r3, asr #10 */
/* @0x30b1fa bfc r4, #12, #12 */
/* @0x30b1fe strbmi r4, [r4], -r7, asr #12 */
/* @0x30b202 bls 0x4d365a <SrcVerts+0x3069e> */
/* @0x30b206 svclt #0xb44294 */
/* @0x30b20a blls 0x49239e <g_prim_v+0x2392> */
/* @0x30b20e sbceq lr, r3, #5120 */
/* @0x30b212 ldmdavs r2, {r3, r4, r9, r12, pc} ^ */
/* @0x30b216 b 0xfe392066 <b2_toiTime+0xfffffffffdc38bc2> */
/* @0x30b21a bl 0xfeb275aa <b2_toiTime+0xfffffffffe3ce106> */
/* @0x30b21e stmdahs r5, {r1, r5, r6, r7, r12, sp, lr} */
/* @0x30b222 .word 0xf855dd09 */
/* @0x30b226 movtmi r2, #0x8033 */
/* @0x30b22a andeq lr, r2, #205824 */
/* @0x30b22e svclt #0xb82a00 */
/* @0x30b232 addmi r4, r2, #536870917 */
/* @0x30b236 stmdals r10, {r0, r1, r2, r3, r8, r10, r11, r12, lr, pc} */
/* @0x30b23a .word 0xf0025cc2 */
/* @0x30b23e bhs 0x34ba52 */
/* @0x30b242 .word 0xf1bcd104 */
/* @0x30b246 ldrmi r0, [r10], r0, lsl #30 */
/* @0x30b24a .word 0x469cbfb8 */
/* @0x30b24e andle r4, r1, r3, asr #10 */
/* @0x30b252 bfi r4, r12, #12, #11 */
/* @0x30b256 rfeda r11! */
/* @0x30b25a andsls r2, r9, #4, #24 */
/* @0x30b25e .word 0xf14006d2 */
/* @0x30b262 blls 0x5eb5ee <g_SWFaavertbuff+0x18526> */
/* @0x30b266 bvs 0xfe9d36d2 <b2_toiTime+0xfffffffffe27a22e> */
/* @0x30b26a andsgt pc, r4, sp, asr #17 */
/* @0x30b26e movwls r4, #0xc618 */
/* @0x30b272 stcl p0, c15, [r10], #52 */
/* @0x30b276 eorshs pc, r4, r5, asr r8 */
/* @0x30b27a eorslo pc, r7, r5, asr r8 */
/* @0x30b27e ldrsbgt pc, [r4], -sp */
/* @0x30b282 blhs 0x311dd6 <af_shaper_get_elem+0x7644> */
/* @0x30b286 subsmi r11, r11, #184, #30 */
/* @0x30b28a andsls r4, r10, r3, lsl #5 */
/* @0x30b28e sbchi pc, r10, r0, lsl #5 */
/* @0x30b292 blne 0xffbb12b6 <b2_toiTime+0xffffffffff457e12> */
/* @0x30b296 andlo r9, r1, #98304 */
/* @0x30b29a addsmi r1, r10, #274432 */
/* @0x30b29e sbchi pc, r2, r0, lsl #5 */
/* @0x30b2a2 ldrmi r9, [r0, #0xa06] */
/* @0x30b2a6 cpsie aif */
/* @0x30b2aa .word 0xf8dd38ff */
/* @0x30b2ae .word 0xf855801c */
/* @0x30b2b2 strbmi r3, [r11, #-0x38] */
/* @0x30b2b6 blls 0x6ff6ca <g_SWFvertbuff+0x2c602> */
/* @0x30b2ba .word 0xd1f14598 */
/* @0x30b2be bls 0x703672 <g_SWFvertbuff+0x305aa> */
/* @0x30b2c2 .word 0xf0004590 */
/* @0x30b2c6 strbmi r8, [r11, #-0xe8] */
/* @0x30b2ca andeq pc, r0, #79 */
/* @0x30b2ce ldrmi r4, [r1], -r0, lsr #13 */
/* @0x30b2d2 movwhs r11, #0xfac */
/* @0x30b2d6 tstls sp, #67108864 */
/* @0x30b2da andls r9, r12, #12, #22 */
/* @0x30b2de tstls r12, #10158080 */
/* @0x30b2e2 ldmdblt r9!, {r0, r1, r5, r9, r10, lr} ^ */
/* @0x30b2e6 .word 0x9028f8dd */
/* @0x30b2ea andhs pc, r3, r9, lsl r8 */
/* @0x30b2ee andeq pc, r3, #2 */
/* @0x30b2f2 andle r2, r4, r1, lsl #20 */
/* @0x30b2f6 rscslo pc, pc, #79 */
/* @0x30b2fa andls r4, r12, #152, #12 */
/* @0x30b2fe ldrmi lr, [r10], -r2 */
/* @0x30b302 movwls r4, #0xc698 */
/* @0x30b306 sbceq lr, r8, pc, asr #20 */
/* @0x30b30a ldrsbls pc, [r12], -sp */
/* @0x30b30e strmi r9, [r1], -r3 */
/* @0x30b312 strbmi r4, [r11, #-0x429] */
/* @0x30b316 ldrsbtls pc, [r0], #-141 */
/* @0x30b31a .word 0xe004f8d1 */
/* @0x30b31e movwlo r11, #0x1fb4 */
/* @0x30b322 bl 0xff6b1f42 <b2_toiTime+0xfffffffffef58a9e> */
/* @0x30b326 stmdbhs r0, {r1, r2, r8} */
/* @0x30b32a submi r11, r9, #184, #30 */
/* @0x30b32e stclle p5, c4, [pc], #-292 */
/* @0x30b332 ldrdls r0, r1, [pc], -r8 */
/* @0x30b336 strtmi r4, [r9], #-1537 */
/* @0x30b33a bl 0xff6a5466 <b2_toiTime+0xfffffffffef4bfc2> */
/* @0x30b33e .word 0xf1b90901 */
/* @0x30b342 svclt #0xb80f00 */
/* @0x30b346 stmdbeq r0, {r0, r3, r6, r7, r8, r12, sp, lr, pc} */
/* @0x30b34a svceq #0x5f1b9 */
/* @0x30b34e stmdbls r3, {r2, r3, r8, r10, r11, r12, lr, pc} */
/* @0x30b352 eorseq pc, r3, r5, asr r8 */
/* @0x30b356 bne 0x1321502 <b2_toiTime+0xbc805e> */
/* @0x30b35a blx 0x3537b4 */
/* @0x30b35e stmdahs r0, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x30b362 submi r11, r0, #184, #30 */
/* @0x30b366 ldclle p2, c4, [r3, #-544] */
/* @0x30b36a stclpl p8, c9, [r0], {10} */
/* @0x30b36e mrseq pc, apsr */
/* @0x30b372 .word 0xd1042901 */
/* @0x30b376 ldrmi r9, [r10], -r12, lsl #18 */
/* @0x30b37a svclt #0xb82900 */
/* @0x30b37e stmdbls pc, {r2, r3, r8, r9, r12, pc} */
/* @0x30b382 stmdapl r9!, {r0, r1, r11, r12, pc} ^ */
/* @0x30b386 .word 0x91045828 */
/* @0x30b38a ldmdbls sp, {r3, r7, r9, lr} */
/* @0x30b38e svclt #0xac9017 */
/* @0x30b392 andhs r2, r1, r0 */
/* @0x30b396 teqle sp, r8, lsl #5 */
/* @0x30b39a stmdals r4, {r0, r1, r2, r4, r8, r11, r12, pc} */
/* @0x30b39e ldmdbls r10, {r6, r9, r11, r12} */
/* @0x30b3a2 stmdahs r0, {r0, r1, r2, r3, r12, pc} */
/* @0x30b3a6 submi r11, r0, #184, #30 */
/* @0x30b3aa blle 0xfdbdd2 <b2_toiTime+0x88292e> */
/* @0x30b3ae .word 0xf8dd2014 */
/* @0x30b3b2 blx 0x33b47c */
/* @0x30b3b6 ldrmi pc, [r2], r9, lsl #18 */
/* @0x30b3ba addsmi r9, r3, #28672 */
/* @0x30b3be mrrcne p15, #0xb, r11, r12, c4 */
/* @0x30b3c2 bl 0x4723e2 <g_RomDisk+0x7abc2> */
/* @0x30b3c6 ldmdavs r11, {r2, r6, r7, r8, r9} ^ */
/* @0x30b3ca movweq lr, #0x3bce */
/* @0x30b3ce svclt #0xb82b00 */
/* @0x30b3d2 blhs 0x45bd46 <g_RomDisk+0x64526> */
/* @0x30b3d6 bls 0x942812 <b2_toiTime+0x1e936e> */
/* @0x30b3da ldmdavs r3, {r0, r1, r2, r4, r11, r12, pc} */
/* @0x30b3de blhs 0x311c52 <af_shaper_get_elem+0x74c0> */
/* @0x30b3e2 subsmi r11, r11, #184, #30 */
/* @0x30b3e6 .word 0xdc04454b */
/* @0x30b3ea addsmi r9, r4, #24576 */
/* @0x30b3ee .word 0x3c01dd17 */
/* @0x30b3f2 bls 0x5c3452 <g_SWFlineaavertbuff+0x7038a> */
/* @0x30b3f6 .word 0xf0035d13 */
/* @0x30b3fa blhs 0x34c00e */
/* @0x30b3fe b 0x123f812 <b2_toiTime+0xae636e> */
/* @0x30b402 svclt #0x280c2c */
/* @0x30b406 adcsmi r4, r12, #164, #12 */
/* @0x30b40a andle r4, r9, r2, lsr #13 */
/* @0x30b40e ldrb r4, [r3, r3, lsr #12] */
/* @0x30b412 and r2, r0, r0, lsl #2 */
/* @0x30b416 adcsmi r2, r11, #1073741824 */
/* @0x30b41a svcge #0x63f47f */
/* @0x30b41e .word 0x9c07e002 */
/* @0x30b422 ldrbtmi r4, [r6], -r7, asr #12 */
/* @0x30b426 .word 0xf1bc9b12 */
/* @0x30b42a ldrmi r0, [lr], #-3840 */
/* @0x30b42e .word 0xf1badb0e */
/* @0x30b432 blle 0x5cf03a <g_SWFlineaavertbuff+0x7bf72> */
/* @0x30b436 eorshs pc, r10, r5, asr r8 */
/* @0x30b43a eorslo pc, r12, r5, asr r8 */
/* @0x30b43e .word 0x906cf8dd */
/* @0x30b442 blhs 0x311f96 <af_shaper_get_elem+0x7804> */
/* @0x30b446 subsmi r11, r11, #184, #30 */
/* @0x30b44a .word 0xdc16454b */
/* @0x30b44e vldrpl s19, [r3, #40] */
/* @0x30b452 movweq pc, #0x3003 */
/* @0x30b456 .word 0xd1072b01 */
/* @0x30b45a .word 0xf0025d12 */
/* @0x30b45e .word 0xf1120203 */
/* @0x30b462 svclt #0x1832ff */
/* @0x30b466 and r2, r0, r1, lsl #4 */
/* @0x30b46a .word 0xf0022201 */
/* @0x30b46e strdlt r0, r1, [r10, -pc]! */
/* @0x30b472 smmlaeq r11, r9, r11, r9 */
/* @0x30b476 movwhs sp, #0x140f */
/* @0x30b47a movwhs lr, #0x0 */
/* @0x30b47e .word 0x2c04f83b */
/* @0x30b482 strle r0, [r3, #-0x7d7] */
/* @0x30b486 addmi r9, r6, #917504 */
/* @0x30b48a and sp, r4, r3, lsl #24 */
/* @0x30b48e addmi r9, lr, #229376 */
/* @0x30b492 tstls r5, #4096 */
/* @0x30b496 .word 0xf8dd960e */
/* @0x30b49a .word 0xf1099044 */
/* @0x30b49e .word 0xf8cd0901 */
/* @0x30b4a2 ldrb r9, [r8, #0x44] */
/* @0x30b4a6 .word 0xf100980e */
/* @0x30b4aa bllo 0x35c0b2 */
/* @0x30b4ae .word 0xf63f3303 */
/* @0x30b4b2 ldmdbls r5, {r0, r2, r3, r5, r7, r8, r10, r11, sp, pc} */
/* @0x30b4b6 bls 0x5379e2 <obj_numb_event+0xa72> */
/* @0x30b4ba ldmdbvc r0, {r0, r2, r3, r8, r10, r12, sp, lr, pc} */
/* @0x30b4be orreq lr, r2, #9216 */
/* @0x30b4c2 andls r3, r8, #268435456 */
/* @0x30b4c6 stcleq p8, c15, [r12], {67} */
/* @0x30b4ca stmdals lr, {r5, r7, r8, r10, sp, lr, pc} */
/* @0x30b4ce .word 0xf8ddab2a */
/* @0x30b4d2 .word 0xf8439034 */
/* @0x30b4d6 .word 0xf1090029 */
/* @0x30b4da ldr r0, [r6, #0x1] */
/* @0x30b4de ldmdblt r2, {r0, r2, r3, r9, r11, r12, pc} */
/* @0x30b4e2 blhs 0x33210a */
/* @0x30b4e6 stcge p0, c13, [r10], #-440 */
/* @0x30b4ea ldmdbge sp, {r3, r11, r12, pc} ^ */
/* @0x30b4ee ldc2l p7, c15, [r5, #1004]! */
/* @0x30b4f2 strtmi r9, [r1], -sp, lsl #16 */
/* @0x30b4f6 ldc2l p7, c15, [r1, #1004]! */
/* @0x30b4fa eorhs r9, r4, #720896 */
/* @0x30b4fe tstpl r0, r0, lsl #10 */
/* @0x30b502 .word 0xf8d13114 */
/* @0x30b506 blx 0x38b870 <_pcre_ucp_gbtable+0x14> */
/* @0x30b50a andlo r1, r1, r0, lsl #4 */
/* @0x30b50e sbcseq pc, r8, r1, asr #17 */
/* @0x30b512 sbcslo r9, r8, #212992 */
/* @0x30b516 stmdblt r1, {r0, r1, r4, r8, r10, r11, r12} ^ */
/* @0x30b51a .word 0xf50d9808 */
/* @0x30b51e stmdaeq r1, {r4, r8, r11, r12, sp, lr} ^ */
/* @0x30b522 orreq lr, r1, r9, lsl #22 */
/* @0x30b526 stclne p8, c15, [r12], {81} */
/* @0x30b52a stmdals sp, {r0, r2, sp, lr, pc} */
/* @0x30b52e stmdals r8, {r0, r6, r11} */
/* @0x30b532 eorne pc, r1, r4, asr r8 */
/* @0x30b536 sbcsvs r11, r9, r0, lsl r9 */
/* @0x30b53a and r6, r9, r1, asr r0 */
/* @0x30b53e .word 0xf50d9808 */
/* @0x30b542 subsvs r7, r1, r0, lsl r9 */
/* @0x30b546 bl 0x54d652 <gp_ActiveMaskObjects+0x898a> */
/* @0x30b54a .word 0xf8510181 */
/* @0x30b54e sbcsvs r1, r9, r12, asr #25 */
/* @0x30b552 ldmdavs r1, {r3, r4, r6, r7, r11, sp, lr} ^ */
/* @0x30b556 andsle r4, r1, r8, lsl #5 */
/* @0x30b55a .word 0x4c04f83b */
/* @0x30b55e streq pc, [r3], #-20 */
/* @0x30b562 strhs r11, [r1], #-3864 */
/* @0x30b566 svclt #0xd44288 */
/* @0x30b56a strhs r2, [r1, #-0x500] */
/* @0x30b56e andle r4, r5, r12, lsr #5 */
/* @0x30b572 bl 0x35c57e */
/* @0x30b576 ldrdne r7, r8, [r9], #-17 */
/* @0x30b57a ldrsbvs r6, [r1], #-9 */
/* @0x30b57e andhs r9, r0, #16, #16 */
/* @0x30b582 andsvs r9, r10, #147456 */
/* @0x30b586 .word 0x61d96198 */
/* @0x30b58a .word 0x2c04f83b */
/* @0x30b58e svclt #0x4407d4 */
/* @0x30b592 andsvs r2, r10, #536870912 */
/* @0x30b596 .word 0x2c04f83b */
/* @0x30b59a strle r0, [r3, #-0x790] */
/* @0x30b59e .word 0xf0426a1a */
/* @0x30b5a2 andsvs r0, r10, #4, #4 */
/* @0x30b5a6 .word 0x2c04f83b */
/* @0x30b5aa strle r0, [r3, #-0x751] */
/* @0x30b5ae .word 0xf0426a1a */
/* @0x30b5b2 andsvs r0, r10, #8, #4 */
/* @0x30b5b6 .word 0x2c04f83b */
/* @0x30b5ba strle r0, [r3, #-0x712] */
/* @0x30b5be .word 0xf0426a1a */
/* @0x30b5c2 andsvs r0, r10, #16, #4 */
/* @0x30b5c6 bleq 0x5479fa <gp_ActiveMaskObjects+0x2d32> */
/* @0x30b5ca ldmdals r3, {r1, r2, r3, r8, r10, sp, lr, pc} */
/* @0x30b5ce .word 0xf7ff9916 */
/* @0x30b5d2 bls 0x6097da <g_SWFaavertbuff+0x36712> */
/* @0x30b5d6 ldrpl pc, [r0, #-0x502] */
/* @0x30b5da .word 0xf8d53514 */
/* @0x30b5de mcrhs p0, #0x0, r6, c0, c8, #0x6 */
/* @0x30b5e2 .word 0xf502d04a */
/* @0x30b5e6 .word 0xf10d5213 */
/* @0x30b5ea eorslo r0, r0, #128, #24 */
/* @0x30b5ee .word 0xf84c2300 */
/* @0x30b5f2 movwlo r2, #0x1023 */
/* @0x30b5f6 .word 0xf10242b3 */
/* @0x30b5fa mvnsle r0, r4, lsr #4 */
/* @0x30b5fe adcsmi r2, r2, #268435456 */
/* @0x30b602 bge 0xaffa12 <b2_toiTime+0x3a656e> */
/* @0x30b606 ands r2, lr, r0, lsl #6 */
/* @0x30b60a orreq lr, r2, #12, #22 */
/* @0x30b60e biclt r4, r4, r4, lsl r6 */
/* @0x30b612 .word 0x0c04f853 */
/* @0x30b616 bvs 0x35a22e */
/* @0x30b61a svceq #0x6f011 */
/* @0x30b61e svclt #0x186859 */
/* @0x30b622 .word 0x8000f8d0 */
/* @0x30b626 svclt #0x86a0f */
/* @0x30b62a .word 0x800cf8d0 */
/* @0x30b62e svceq #0x6f017 */
/* @0x30b632 stmdavs pc, {r2, r4, r8, r9, r10, r11, r12, sp, pc} */
/* @0x30b636 strbmi r6, [r7, #-0x8cf] */
/* @0x30b63a subsvs sp, r8, r3, lsl #20 */
/* @0x30b63e andsvs r3, r9, r1, lsl #24 */
/* @0x30b642 andlo lr, r1, #60030976 */
/* @0x30b646 .word 0xf8d5e7db */
/* @0x30b64a stmdblo r1, {r3, r4, r6, r7, r12} */
/* @0x30b64e andsle r4, r3, #-1342177272 */
/* @0x30b652 svcne #0x4f852 */
/* @0x30b656 bvs 0x518262 <SrcVerts+0x752a6> */
/* @0x30b65a svceq #0x6f010 */
/* @0x30b65e svclt #0x186850 */
/* @0x30b662 bvs 0x417a9a <g_RomDisk+0x2027a> */
/* @0x30b666 svceq #0x6f014 */
/* @0x30b66a svclt #0x18680c */
/* @0x30b66e stmdavs r0, {r2, r3, r12, sp} */
/* @0x30b672 svclt #0xc84284 */
/* @0x30b676 strb r6, [r6, r8]! */
/* @0x30b67a ldcvc p5, c15, [r1, #-52] */
/* @0x30b67e svchi #0xf0e8bd */
/* @0x30b682 stcvs p15, c11, [r0], #-0 */
/* @0x30b686 blvs 0xb6c6 */
/* @0x30b68a push {r1, r2, r3} */
/* @0x30b68e strdlt r4, r5, [sp], r0 */
/* @0x30b692 .word 0x460c4e3a */
/* @0x30b696 strmi r6, [r5], -r9, asr #27 */
/* @0x30b69a ldmdavs r6!, {r1, r2, r3, r4, r5, r6, r10, lr} */
/* @0x30b69e .word 0x91026833 */
/* @0x30b6a2 movwls r4, #0xb935 */
/* @0x30b6a6 strhlo pc, [r4], #-132 */
/* @0x30b6aa strtmi r6, [r0], -r3, lsl #5 */
/* @0x30b6ae .word 0xf921f7da */
/* @0x30b6b2 strmi r9, [r7], -r3, lsl #12 */
/* @0x30b6b6 mrsle r2, spsr */
/* @0x30b6ba strtmi r4, [r1], -r8, lsr #12 */
/* @0x30b6be blx 0x1e896c4 <b2_toiTime+0x1730220> */
/* @0x30b6c2 strtmi r4, [r1], -r8, lsr #12 */
/* @0x30b6c6 ldc2l p7, c15, [r7], #-1020 */
/* @0x30b6ca bge 0x49e386 <TimingData+0x436e> */
/* @0x30b6ce ldrbtmi r9, [r11], #-1796 */
/* @0x30b6d2 ldreq pc, [r0, -r3, lsl #2] */
/* @0x30b6d6 ldmdavs r8, {r4, r7, r9, r10, lr} */
/* @0x30b6da .word 0xf8533308 */
/* @0x30b6de adcsmi r1, r11, #4, #24 */
/* @0x30b6e2 .word 0xc6034616 */
/* @0x30b6e6 mvnsle r4, r2, lsr r6 */
/* @0x30b6ea .word 0xf10d6818 */
/* @0x30b6ee .word 0xf10d0b14 */
/* @0x30b6f2 .word 0x46c10a10 */
/* @0x30b6f6 qasxmi r6, r0, r0 */
/* @0x30b6fa .word 0xffe1f7fe */
/* @0x30b6fe ldrtmi r2, [r0], r0, lsl #12 */
/* @0x30b702 .word 0xf8994607 */
/* @0x30b706 mvnslt r3, r0 */
/* @0x30b70a ldrbmi r4, [r11], -r8, asr #12 */
/* @0x30b70e ldrtmi r4, [r10], -r9, lsr #12 */
/* @0x30b712 .word 0xffe2f7fe */
/* @0x30b716 blhs 0x372332 <_ZTS13C_UTF16String+0x93de> */
/* @0x30b71a ldmle r2!, {r0, r7, r9, r10, lr} ^ */
/* @0x30b71e strtmi r2, [r8], -r0, lsl #6 */
/* @0x30b722 ldrmi r9, [r10], -r0, lsl #6 */
/* @0x30b726 uasxmi r4, r3, r9 */
/* @0x30b72a rfeda r2! */
/* @0x30b72e rscle r2, r8, r0, lsl #16 */
/* @0x30b732 .word 0xf1b89b04 */
/* @0x30b736 andle r0, r3, r0, lsl #30 */
/* @0x30b73a strhle r4, [r2], -r3 */
/* @0x30b73e and r2, r4, r0, lsl #12 */
/* @0x30b742 .word 0xf04f461e */
/* @0x30b746 ldrb r0, [r12, r1, lsl #16] */
/* @0x30b74a strtmi r2, [r0], -r1, lsl #12 */
/* @0x30b74e .word 0xf7fe4639 */
/* @0x30b752 .word 0xf885ffc0 */
/* @0x30b756 stmdbls r2, {r5, sp, lr} */
/* @0x30b75a .word 0xf7da4620 */
/* @0x30b75e stmdbls r3, {r1, r2, r3, r6, r7, r9, r11, r12, sp, lr, pc} */
/* @0x30b762 andhs r9, r0, r11, lsl #20 */
/* @0x30b766 addsmi r6, r10, #720896 */
/* @0x30b76a .word 0xf5aad001 */
/* @0x30b76e andlt lr, sp, r2, lsr pc */
/* @0x30b772 svchi #0xf0e8bd */
/* @0x30b776 stmdbvs r3!, {r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x30b77a adcshs r7, r10, #461373440 */
/* @0x30b77e stmlo sp!, {r1, r2, r3} ^ */
/* @0x30b782 ldrblt r0, [r0, #0x8]! */
/* @0x30b786 stmdavc r3, {r4, r8, r9, r12, sp, pc} */
/* @0x30b78a ldmdbmi r0, {r0, r1, r3, r4, r5, r6, r7, r8, r12, sp, pc} */
/* @0x30b78e svclt #0x82b2d */
/* @0x30b792 .word 0xf04f3001 */
/* @0x30b796 ldrbtmi r0, [r9], #-1802 */
/* @0x30b79a ldrbtlo pc, [pc], #256 */
/* @0x30b79e andhs r11, r1, #12, #30 */
/* @0x30b7a2 andhs r2, r0, r0, lsl #4 */
/* @0x30b7a6 svclo #0x1f814 */
/* @0x30b7aa ldrbeq lr, [r3, #0xb01] */
/* @0x30b7ae umullvs pc, r0, r5, r8 */
/* @0x30b7b2 streq pc, [r7, #-0x3] */
/* @0x30b7b6 .word 0xf505fa46 */
/* @0x30b7ba strle r0, [r3, #-0x7ed] */
/* @0x30b7be blx 0x4e2af4 <SrcVerts+0x3fb38> */
/* @0x30b7c2 strb r3, [pc, r0]! */
/* @0x30b7c6 submi r11, r0, #-2147483644 */
/* @0x30b7ca ssub8mi r11, r8, r0 */
/* @0x30b7ce svcvc #0xb4bdf0 */
/* @0x30b7d2 ldrblt r0, [r0, #0x9]! */
/* @0x30b7d6 stmdavc r3, {r5, r8, r9, r12, sp, pc} */
/* @0x30b7da ldmdbmi r2, {r0, r1, r3, r8, r9, r12, sp, pc} */
/* @0x30b7de svclt #0x82b2d */
/* @0x30b7e2 .word 0xf04f3001 */
/* @0x30b7e6 ldrbtmi r0, [r9], #-1802 */
/* @0x30b7ea ldrbtlo pc, [pc], #256 */
/* @0x30b7ee andhs r11, r1, #12, #30 */
/* @0x30b7f2 andhs r2, r0, r0, lsl #4 */
/* @0x30b7f6 svclo #0x1f814 */
/* @0x30b7fa ldrbeq lr, [r3, #0xb01] */
/* @0x30b7fe umullvs pc, r0, r5, r8 */
/* @0x30b802 streq pc, [r7, #-0x3] */
/* @0x30b806 .word 0xf505fa46 */
/* @0x30b80a strle r0, [r4, #-0x7ed] */
/* @0x30b80e blx 0x4e2b44 <SrcVerts+0x3fb88> */
/* @0x30b812 addlt r3, r0, #0 */
/* @0x30b816 tstlt r10, lr, ror #15 */
/* @0x30b81a addlt r4, r0, #64, #4 */
/* @0x30b81e ldrmi lr, [r8], -r0 */
/* @0x30b822 ldcllt p2, c11, [r0, #0]! */
/* @0x30b826 svcvc #0x64bf00 */
/* @0x30b82a stmdavs r3, {r0, r3} ^ */
/* @0x30b82e addsmi r6, r3, #4849664 */
/* @0x30b832 svclt #0xd4db03 */
/* @0x30b836 andhs r2, r1, r0 */
/* @0x30b83a .word 0xf04f4770 */
/* @0x30b83e .word 0x477030ff */
/* @0x30b842 .word 0xf8d36803 */
/* @0x30b846 blvs 0x1793a7e <b2_toiTime+0x103a5da> */
/* @0x30b84a .word 0xf8d36102 */
/* @0x30b84e swpbvs r3, r0, [r3] */
/* @0x30b852 ldrbmi r2, [r0, -r0]! */
/* @0x30b856 .word 0x61432300 */
/* @0x30b85a ldrbmi r6, [r0, -r3, lsl #2]! */
/* @0x30b85e stmdbvs r4, {r4, r5, r6, r8, r10, r12, sp, pc} ^ */
/* @0x30b862 andhs r6, r0, r2, lsl #18 */
/* @0x30b866 andle r4, pc, #144, #4 */
/* @0x30b86a ldmdaeq r11, {r0, r1, r4, r11, r12} ^ */
/* @0x30b86e eorspl pc, r3, r4, asr r8 */
/* @0x30b872 strbeq lr, [r3], r4, lsl #22 */
/* @0x30b876 smlatble r3, r9, r2, r4 */
/* @0x30b87a strhlo r8, [r1], -r0 */
/* @0x30b87e ldcllt p2, c11, [r0, #-512]! */
/* @0x30b882 sasxmi r11, r10, r4 */
/* @0x30b886 ubfx r1, r8, #0x18, #0xe */
/* @0x30b88a ldcllt p0, c2, [r0, #-0]! */
/* @0x30b88e movwhs r11, #0x5f0 */
/* @0x30b892 stmdbvs r6, {r1, r3, r11, sp, lr} */
/* @0x30b896 andlo r6, r1, #68, #18 */
/* @0x30b89a adcmi r4, r11, #55574528 */
/* @0x30b89e stmne r8!, {r1, r2, r3, r9, r12, lr, pc} ^ */
/* @0x30b8a2 .word 0xf8540840 */
/* @0x30b8a6 bl 0x42796e <g_RomDisk+0x3014e> */
/* @0x30b8aa adcsmi r0, r10, #192, #24 */
/* @0x30b8ae rfeia r12! */
/* @0x30b8b2 and r0, r10, r4 */
/* @0x30b8b6 .word 0x4605bf34 */
/* @0x30b8ba strb r1, [lr, r3, asr #24]! */
/* @0x30b8be andle r4, r7, #805306379 */
/* @0x30b8c2 sbceq lr, r3, r4, lsl #22 */
/* @0x30b8c6 eorshs pc, r3, r4, asr r8 */
/* @0x30b8ca andlo r8, r1, r0, lsl #17 */
/* @0x30b8ce and r11, r1, r0, lsl #5 */
/* @0x30b8d2 ldrmi r2, [r0], -r0, lsl #4 */
/* @0x30b8d6 ldcllt p0, c6, [r0, #40]! */
/* @0x30b8da .word 0x3084f8d0 */
/* @0x30b8de .word 0xf8d0600b */
/* @0x30b8e2 andhs r3, r0, r8, lsl #1 */
/* @0x30b8e6 .word 0x47706013 */
/* @0x30b8ea .word 0x4604b538 */
/* @0x30b8ee .word 0xf8d06800 */
/* @0x30b8f2 .word 0xf7d9508c */
/* @0x30b8f6 .word 0xf06ffe16 */
/* @0x30b8fa andhs r0, r0, pc, lsr r2 */
/* @0x30b8fe orrseq r6, r11, r11, lsr #21 */
/* @0x30b902 bvs 0xffde3f96 <b2_toiTime+0xffffffffff68aaf2> */
/* @0x30b906 mvnvs r4, r3, asr r3 */
/* @0x30b90a orrseq r8, r11, r11, lsr #17 */
/* @0x30b90e ldclt p2, c6, [r8, #-396]! */
/* @0x30b912 .word 0x4605b5f8 */
/* @0x30b916 strmi r6, [r12], -r3, lsl #16 */
/* @0x30b91a bvs 0xae5b42 <b2_toiTime+0x38c69e> */
/* @0x30b91e .word 0x608cf8d3 */
/* @0x30b922 .word 0xb123690b */
/* @0x30b926 qdaddhs r4, r8, r8 */
/* @0x30b92a .word 0xf00d3024 */
/* @0x30b92e .word 0x3020e9f0 */
/* @0x30b932 orrne r6, r0, r3, lsr #16 */
/* @0x30b936 blhs 0x377d8a <_ZTS13C_UTF16String+0xee36> */
/* @0x30b93a ands sp, r2, r6 */
/* @0x30b93e .word 0x332068fb */
/* @0x30b942 svcne #0xa3ebb0 */
/* @0x30b946 and sp, r6, r5, lsl #2 */
/* @0x30b94a bvs 0xfffe641a <b2_toiTime+0xffffffffff88cf76> */
/* @0x30b94e addsmi r4, r8, #318767104 */
/* @0x30b952 andshs sp, r7, r1 */
/* @0x30b956 qsub8mi r11, r8, r8 */
/* @0x30b95a pop {r8, sp} */
/* @0x30b95e .word 0xf7ff40f8 */
/* @0x30b962 andhs r11, r7, r3, asr #31 */
/* @0x30b966 push {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x30b96a .word 0x460443f8 */
/* @0x30b96e .word 0xf8d5680d */
/* @0x30b972 stmdbvs r8!, {r2, r3, r7, r12, sp} */
/* @0x30b976 orrhs pc, r8, r3, lsl #10 */
/* @0x30b97a rfeia r1! */
/* @0x30b97e suble r9, sp, #134 */
/* @0x30b982 .word 0xf8d5b912 */
/* @0x30b986 and r2, r0, r4, lsr #1 */
/* @0x30b98a blvs 0xfe9da196 <b2_toiTime+0xfffffffffe280cf2> */
/* @0x30b98e blx 0x353e28 */
/* @0x30b992 ldmibhi r0, {r1, r9, r12, sp} */
/* @0x30b996 ldmdbhi r6, {r0, r4, r7, r8, r11, sp, lr} ^ */
/* @0x30b99a ldrhhi pc, [r0], -r2 */
/* @0x30b99e ldmibvs r3, {r0, r1, r2, r4, r7, r9, r11, pc} ^ */
/* @0x30b9a2 strvs r8, [r0, #-0x9d2]! */
/* @0x30b9a6 strbvs r4, [r3, #-0x620]! */
/* @0x30b9aa .word 0xf7db64e2 */
/* @0x30b9ae .word 0xf109fdd2 */
/* @0x30b9b2 stmdbhs r7, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r12, sp} */
/* @0x30b9b6 ldm pc, {r2, r4, r11, r12, lr, pc} ^ */
/* @0x30b9ba streq pc, [r4], -r1 */
/* @0x30b9be tstne r3, #77824 */
/* @0x30b9c2 movwhs r0, #0x1c13 */
/* @0x30b9c6 movwhs lr, #0x3000 */
/* @0x30b9ca subslo pc, lr, r4, lsl #17 */
/* @0x30b9ce movwhs lr, #0x4008 */
/* @0x30b9d2 movwhs lr, #0x27fa */
/* @0x30b9d6 subslo pc, lr, r4, lsl #17 */
/* @0x30b9da orrvc pc, r0, #1325400064 */
/* @0x30b9de subslo pc, r12, r4, lsr #17 */
/* @0x30b9e2 blx 0x6de62a <g_SWFvertbuff+0xb562> */
/* @0x30b9e6 .word 0x01b6f288 */
/* @0x30b9ea adcvs r6, r6, #102760448 */
/* @0x30b9ee strtvs r0, [r3], #402 */
/* @0x30b9f2 .word 0x66a3b23b */
/* @0x30b9f6 andseq pc, r8, r4, lsl #2 */
/* @0x30b9fa rsbvs r0, r3, #-1073741786 */
/* @0x30b9fe eorvs r6, r2, #2240 */
/* @0x30ba02 .word 0x61a3019b */
/* @0x30ba06 orrseq r6, r11, r3, ror #25 */
/* @0x30ba0a .word 0xf8d561e3 */
/* @0x30ba0e ldmhi r9, {r2, r3, r7, r12, sp} ^ */
/* @0x30ba12 .word 0xf7d90189 */
/* @0x30ba16 andhs pc, r0, r4, ror #26 */
/* @0x30ba1a .word 0x83f8e8bd */
/* @0x30ba1e pop {r1, r2, sp} */
/* @0x30ba22 ldrbtvc r8, [r3], #-1016 */
/* @0x30ba26 push {r0, r3, r5, r6, r9, sp, lr} */
/* @0x30ba2a .word 0x460447f0 */
/* @0x30ba2e .word 0xf0002800 */
/* @0x30ba32 .word 0xf50080be */
/* @0x30ba36 stmdavs r1!, {r3, r7, r9, r10, sp} */
/* @0x30ba3a .word 0xf8d62700 */
/* @0x30ba3e strtmi r5, [r8], -r8, lsl #1 */
/* @0x30ba42 ldc2l p7, c15, [r8], #-876 */
/* @0x30ba46 .word 0x0080f8d4 */
/* @0x30ba4a .word 0xb1486027 */
/* @0x30ba4e .word 0xf7db4629 */
/* @0x30ba52 strtmi pc, [r8], -r9, lsr #25 */
/* @0x30ba56 .word 0x1080f8d4 */
/* @0x30ba5a stc2l p7, c15, [r12], #-876 */
/* @0x30ba5e addvc pc, r0, r4, asr #17 */
/* @0x30ba62 strtmi r2, [r8], -r0, lsl #14 */
/* @0x30ba66 ldrtmi r6, [r9], r1, ror #26 */
/* @0x30ba6a stc2l p7, c15, [r4], #-876 */
/* @0x30ba6e stcvs p5, c6, [r3], #412 */
/* @0x30ba72 andsle r4, r0, #-268435447 */
/* @0x30ba76 b 0x16e6f0a <b2_toiTime+0xf8da66> */
/* @0x30ba7a strbmi r1, [r3], #-2055 */
/* @0x30ba7e bhs 0x365bee <_ZTS12CDS_Priority+0x7c46> */
/* @0x30ba82 ldmvs r9, {r0, r1, r2, r8, r12, lr, pc} ^ */
/* @0x30ba86 .word 0xf7db4628 */
/* @0x30ba8a stcvs p12, c15, [r3, #-340]! */
/* @0x30ba8e .word 0xf8c34443 */
/* @0x30ba92 strlo r9, [r1, -r12] */
/* @0x30ba96 strtmi lr, [r8], -r11, ror #15 */
/* @0x30ba9a .word 0xf7db6d21 */
/* @0x30ba9e blvs 0xfed0abd2 <b2_toiTime+0xfffffffffe5b172e> */
/* @0x30baa2 strvs r2, [r3, #-0x300]! */
/* @0x30baa6 .word 0x46994698 */
/* @0x30baaa strlo r6, [r4, -r3, ror #22]! */
/* @0x30baae andsle r4, r0, #152, #10 */
/* @0x30bab2 .word 0xf8574628 */
/* @0x30bab6 .word 0xf7db1c24 */
/* @0x30baba .word 0xf847fc3d */
/* @0x30babe strtmi r9, [r8], -r4, lsr #24 */
/* @0x30bac2 .word 0x1c0cf857 */
/* @0x30bac6 ldc2 p7, c15, [r6], #-876 */
/* @0x30baca stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x30bace .word 0x9c0cf847 */
/* @0x30bad2 stclvs p7, c14, [r7], #-936 */
/* @0x30bad6 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30bada stcvs p6, c4, [r3], #-808 */
/* @0x30bade strtmi r3, [r8], -r4, lsr #14 */
/* @0x30bae2 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30bae6 andle r4, pc, #641728512 */
/* @0x30baea stcne p8, c15, [r4], #-348 */
/* @0x30baee stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x30baf2 stc2 p7, c15, [r0], #-876 */
/* @0x30baf6 stcge p8, c15, [r4], #-284 */
/* @0x30bafa .word 0xf8574628 */
/* @0x30bafe .word 0xf7db1c0c */
/* @0x30bb02 .word 0xf847fc19 */
/* @0x30bb06 strb r10, [r8, r12, lsl #24]! */
/* @0x30bb0a strbmi r6, [r2], r1, lsr #23 */
/* @0x30bb0e .word 0xfc12f7db */
/* @0x30bb12 eorshi pc, r8, r4, asr #17 */
/* @0x30bb16 stclvs p6, c4, [r1], #-160 */
/* @0x30bb1a .word 0xfc0cf7db */
/* @0x30bb1e .word 0xf8c46ea7 */
/* @0x30bb22 svcvs #0x238044 */
/* @0x30bb26 strtmi r3, [r8], -r4, lsr #14 */
/* @0x30bb2a stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30bb2e andle r4, pc, #152, #10 */
/* @0x30bb32 stcne p8, c15, [r4], #-348 */
/* @0x30bb36 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x30bb3a blx 0x249ab0 <_Z15JS_Argument_PutP12YYObjectBaseP6RValuePKc+0xe4> */
/* @0x30bb3e stcge p8, c15, [r4], #-284 */
/* @0x30bb42 .word 0xf8574628 */
/* @0x30bb46 .word 0xf7db1c0c */
/* @0x30bb4a .word 0xf847fbf5 */
/* @0x30bb4e strb r10, [r8, r12, lsl #24]! */
/* @0x30bb52 strbmi r6, [pc], -r1, lsr #29 */
/* @0x30bb56 blx 0xffec9acc <b2_toiTime+0xffffffffff770628> */
/* @0x30bb5a rsbls pc, r8, r4, asr #17 */
/* @0x30bb5e addseq pc, r4, r6, lsl #2 */
/* @0x30bb62 .word 0xf7db4629 */
/* @0x30bb66 .word 0xf8d6fc1f */
/* @0x30bb6a strbmi r4, [r8], r12, lsl #1 */
/* @0x30bb6e .word 0xf8d63410 */
/* @0x30bb72 qadd8mi r3, r8, r0 */
/* @0x30bb76 andsle r4, r3, #-268435447 */
/* @0x30bb7a .word 0x1c10f854 */
/* @0x30bb7e blx 0xff9c9af4 <b2_toiTime+0xffffffffff270650> */
/* @0x30bb82 .word 0x3c0cf854 */
/* @0x30bb86 .word 0x8c10f844 */
/* @0x30bb8a .word 0xd1062b01 */
/* @0x30bb8e .word 0xf8544628 */
/* @0x30bb92 .word 0xf7db1c04 */
/* @0x30bb96 .word 0xf844fbcf */
/* @0x30bb9a strlo r8, [r1, -r4, lsl #24] */
/* @0x30bb9e .word 0xe7e63410 */
/* @0x30bba2 .word 0x108cf8d6 */
/* @0x30bba6 blx 0xff4c9b1c <b2_toiTime+0xfffffffffed70678> */
/* @0x30bbaa .word 0xf8c62300 */
/* @0x30bbae pop {r2, r3, r7, r12, sp} */
/* @0x30bbb2 ldrblt r8, [r0, #-0x7f0]! */
/* @0x30bbb6 orrlt r4, r0, #4, #12 */
/* @0x30bbba strhs r6, [r0, #-0xe46] */
/* @0x30bbbe .word 0x008cf8d0 */
/* @0x30bbc2 .word 0xff31f7ff */
/* @0x30bbc6 ldrsbne pc, [r0], r4 */
/* @0x30bbca .word 0xf7db4630 */
/* @0x30bbce .word 0x4630fbb3 */
/* @0x30bbd2 .word 0x1084f8d4 */
/* @0x30bbd6 addspl pc, r0, r4, asr #17 */
/* @0x30bbda blx 0xfee49b50 <b2_toiTime+0xfffffffffe6f06ac> */
/* @0x30bbde .word 0xf8d44630 */
/* @0x30bbe2 .word 0xf8c41088 */
/* @0x30bbe6 .word 0xf7db5084 */
/* @0x30bbea ldrtmi pc, [r0], -r5, lsr #23 */
/* @0x30bbee .word 0xf8c46961 */
/* @0x30bbf2 .word 0xf7db5088 */
/* @0x30bbf6 shadd8mi pc, r0, pc */
/* @0x30bbfa smultbvs r5, r1, r9 */
/* @0x30bbfe blx 0xfe9c9b74 <b2_toiTime+0xfffffffffe2706d0> */
/* @0x30bc02 bvs 0xb5d4ca <b2_toiTime+0x404026> */
/* @0x30bc06 .word 0xf7db61a5 */
/* @0x30bc0a eorvs pc, r5, #152576 */
/* @0x30bc0e .word 0xf8d44630 */
/* @0x30bc12 .word 0xf7db108c */
/* @0x30bc16 .word 0xf8c4fb8f */
/* @0x30bc1a ldcllt p0, c5, [r0, #-560]! */
/* @0x30bc1e addlt r11, r5, r0, lsr r5 */
/* @0x30bc22 movwhs r6, #0x842 */
/* @0x30bc26 movwls r4, #0x3604 */
/* @0x30bc2a ldmdble r12, {r0, r4, r7, r9, lr} */
/* @0x30bc2e strbmi pc, [r0, #-0x6f]! */
/* @0x30bc32 .word 0xf10242aa */
/* @0x30bc36 stmvs r0, {r0, r2, r8, r9} ^ */
/* @0x30bc3a cmpeq r2, #3072 */
/* @0x30bc3e movths sp, #0x102 */
/* @0x30bc42 ands r9, r0, r3, lsl #6 */
/* @0x30bc46 movwle r4, #0x2293 */
/* @0x30bc4a svclt #0x3842ab */
/* @0x30bc4e stmdavs r3!, {r0, r2, r3, r4, r9, r10, lr} */
/* @0x30bc52 movwls r2, #0x104 */
/* @0x30bc56 movwls r10, #0x1b03 */
/* @0x30bc5a .word 0xf7dc462b */
/* @0x30bc5e blls 0x40a4c2 <g_RomDisk+0x12ca2> */
/* @0x30bc62 stmdblt r3, {r5, sp, lr} */
/* @0x30bc66 stmdals r3, {r0, r2, r5, r6, sp, lr} */
/* @0x30bc6a ldclt p0, c11, [r0, #-20]! */
/* @0x30bc6e .word 0x4604b510 */
/* @0x30bc72 cmplt r0, r0, asr #17 */
/* @0x30bc76 .word 0xf7db6821 */
/* @0x30bc7a qaddhs pc, sp, r0 */
/* @0x30bc7e eorvs r4, r1, r0, lsr #12 */
/* @0x30bc82 pop {r4, r9, sp} */
/* @0x30bc86 .word 0xf00f4010 */
/* @0x30bc8a ldclt p15, c11, [r0, #-128] */
/* @0x30bc8e .word 0x4604b5f0 */
/* @0x30bc92 ldrmi r11, [r5], -r5, lsl #1 */
/* @0x30bc96 orrhs pc, r8, #0, #10 */
/* @0x30bc9a stcvs p14, c10, [r2, #16]! */
/* @0x30bc9e stclvs p6, c4, [r1, #-60]! */
/* @0x30bca2 .word 0x0088f8d3 */
/* @0x30bca6 .word 0xf8462300 */
/* @0x30bcaa mrrcne p13, #0x0, r3, r3, c4 */
/* @0x30bcae subeq lr, r2, sp, lsl #17 */
/* @0x30bcb2 .word 0x2101442b */
/* @0x30bcb6 .word 0xf9eaf7dc */
/* @0x30bcba strbvs r9, [r0, #-0xb03]! */
/* @0x30bcbe stcvs p9, c11, [r3, #396]! */
/* @0x30bcc2 ldrtmi r4, [r9], -r10, lsr #12 */
/* @0x30bcc6 ldrmi r4, [r8], -r3, lsl #8 */
/* @0x30bcca ldcl p5, c15, [r8], #-680 */
/* @0x30bcce strbpl r2, [r2, #-0x20a] */
/* @0x30bcd2 movwlo r6, #0x1da3 */
/* @0x30bcd6 strvs r4, [r5, #0x41d]! */
/* @0x30bcda andlt r9, r5, r3, lsl #16 */
/* @0x30bcde stmdami r1, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x30bce2 .word 0xf7d94478 */
/* @0x30bce6 ldmdb r2!, {r0, r2, r4, r5, r8, r9, r11, r12, sp, pc} */
/* @0x30bcea ldrblt r0, [r0, #-0xd]! */
/* @0x30bcee stmdavc r3, {r6, r7, r8, r12, sp, pc} */
/* @0x30bcf2 bmi 0x5f83a6 <g_SWFaavertbuff+0x252de> */
/* @0x30bcf6 strhs r1, [r10], -r1, asr #28 */
/* @0x30bcfa ldrbtmi r2, [r10], #-0 */
/* @0x30bcfe svclo #0x1f811 */
/* @0x30bd02 ldrbeq lr, [r3], #2818 */
/* @0x30bd06 umullpl pc, r0, r4, r8 */
/* @0x30bd0a streq pc, [r7], #-3 */
/* @0x30bd0e vst1.16 {d15, d16}, [r4], r5 */
/* @0x30bd12 strle r0, [r3, #-0x7e4] */
/* @0x30bd16 blx 0x4a306c <SrcVerts+0xb0> */
/* @0x30bd1a strb r3, [pc, r0]! */
/* @0x30bd1e ssub16mi r11, r8, r0 */
/* @0x30bd22 bvc 0x173b2ea <b2_toiTime+0xfe1e46> */
/* @0x30bd26 ldrblt r0, [r0, #-0x9]! */
/* @0x30bd2a stmdavc r3, {r3, r6, r7, r8, r12, sp, pc} */
/* @0x30bd2e bmi 0x638402 <g_SWFaavertbuff+0x6533a> */
/* @0x30bd32 strhs r1, [r10], -r1, asr #28 */
/* @0x30bd36 ldrbtmi r2, [r10], #-0 */
/* @0x30bd3a svclo #0x1f811 */
/* @0x30bd3e ldrbeq lr, [r3], #2818 */
/* @0x30bd42 umullpl pc, r0, r4, r8 */
/* @0x30bd46 streq pc, [r7], #-3 */
/* @0x30bd4a vst1.16 {d15, d16}, [r4], r5 */
/* @0x30bd4e strle r0, [r4, #-0x7e4] */
/* @0x30bd52 blx 0x4a30a8 <SrcVerts+0xec> */
/* @0x30bd56 addlt r3, r0, #0 */
/* @0x30bd5a ldcllt p7, c14, [r0, #-952]! */
/* @0x30bd5e ldcllt p6, c4, [r0, #-96]! */
/* @0x30bd62 bvc 0x83b96a <b2_toiTime+0xe24c6> */
/* @0x30bd66 push {r0, r3} */
/* @0x30bd6a ssub8mi r4, r6, r0 */
/* @0x30bd6e ldrmi r4, [pc], -r5, ror #20 */
/* @0x30bd72 strmi r11, [r4], -sp, lsl #1 */
/* @0x30bd76 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x30bd7a andls r4, r1, #13631488 */
/* @0x30bd7e movwls r6, #0xb813 */
/* @0x30bd82 addvs r2, r3, r0, lsl #6 */
/* @0x30bd86 .word 0xb1636843 */
/* @0x30bd8a bmi 0x1aa5d9e <b2_toiTime+0x134c8fa> */
/* @0x30bd8e adclo r4, r0, #2046820352 */
/* @0x30bd92 stmdavs r3, {r1, r3, r4, sp, lr} */
/* @0x30bd96 stmdavs r3, {r1, r3, r4, r6, sp, lr} */
/* @0x30bd9a stmdavs r3, {r1, r3, r4, r7, sp, lr} */
/* @0x30bd9e stmdavs r3, {r1, r3, r4, r6, r7, sp, lr} */
/* @0x30bda2 svchs #0x611a */
/* @0x30bda6 addshi pc, pc, r0 */
/* @0x30bdaa stmdahs r0, {r4, r5, r11, r12, sp, lr} */
/* @0x30bdae addshi pc, lr, r0 */
/* @0x30bdb2 .word 0xf0002d00 */
/* @0x30bdb6 stmdavc r11!, {r1, r3, r4, r7, pc} */
/* @0x30bdba .word 0xf0002b00 */
/* @0x30bdbe swphs r8, r6, [r0] */
/* @0x30bdc2 eorhs r10, r0, #196608 */
/* @0x30bdc6 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30bdca bl 0xfffc947a <b2_toiTime+0xffffffffff86ffd6> */
/* @0x30bdce andhs r4, r1, r9, lsr #12 */
/* @0x30bdd2 blhs 0x389e1e <bigtens_D2A+0x2ee> */
/* @0x30bdd6 bhs 0xdf8466 <b2_toiTime+0x69efc2> */
/* @0x30bdda stmdavc r11, {r0, r8, r12, lr, pc} */
/* @0x30bdde stcge p1, c11, [r12, #-396] */
/* @0x30bde2 bicseq lr, r2, #5120 */
/* @0x30bde6 andeq pc, r7, #2 */
/* @0x30bdea vpmax.s8 d15, d2, d0 */
/* @0x30bdee stcpl p8, c15, [r4], #-76 */
/* @0x30bdf2 .word 0xf803432a */
/* @0x30bdf6 and r2, r1, r4, lsr #24 */
/* @0x30bdfa stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30bdfe mvnle r2, r0, lsl #18 */
/* @0x30be02 .word 0xb108f8df */
/* @0x30be06 beq 0x506a26 <SrcVerts+0x63a6a> */
/* @0x30be0a ldrbtmi r2, [r11], #1792 */
/* @0x30be0e ldrbmi r4, [r6, #-0x6b8] */
/* @0x30be12 stmvs r1!, {r0, r2, r8, r9, r12, lr, pc} */
/* @0x30be16 ldrtmi r6, [r9], #-2147 */
/* @0x30be1a cmple r4, #-1879048183 */
/* @0x30be1e ldmdavc r2!, {r1, r2, r3, r6, sp, lr, pc} */
/* @0x30be22 rscsle r2, r6, r0, lsl #20 */
/* @0x30be26 stmdavc r10, {r0, r4, r5, r9, r10, lr} */
/* @0x30be2a .word 0x3101460d */
/* @0x30be2e stmvs r1!, {r1, r3, r5, r8, r11, r12, sp, pc} */
/* @0x30be32 stmdavs r2!, {r0, r1, r2, r3, r5, r9, r10, lr} ^ */
/* @0x30be36 .word 0xd1124291 */
/* @0x30be3a blge 0x643e6e <g_SWFaavertbuff+0x70da6> */
/* @0x30be3e sbcseq lr, r2, r3, lsl #22 */
/* @0x30be42 andeq pc, r7, #2 */
/* @0x30be46 stceq p8, c15, [r4], #-64 */
/* @0x30be4a .word 0xf202fa40 */
/* @0x30be4e strble r0, [r10, #0x7d2]! */
/* @0x30be52 strtmi lr, [r0], -sp, ror #15 */
/* @0x30be56 .word 0xf7ff3101 */
/* @0x30be5a stmdahs r0, {r0, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30be5e stmvs r2!, {r1, r2, r6, r8, r12, lr, pc} */
/* @0x30be62 stmdavs r1!, {r0, r2, r4, r5, r7, r9, lr} */
/* @0x30be66 andeq pc, r1, r2, lsl #2 */
/* @0x30be6a stmdale r1, {r5, r7, sp, lr} */
/* @0x30be6e strteq pc, [r0], r11, lsl #2 */
/* @0x30be72 eorvs pc, r2, r1, asr #16 */
/* @0x30be76 svceq #0xf1b9 */
/* @0x30be7a qadd16mi sp, r10, r2 */
/* @0x30be7e .word 0xf8124615 */
/* @0x30be82 orrslt r1, r1, r1, lsl #22 */
/* @0x30be86 bl 0x3f6abe <g_MP3UpdateVolume+0x17e2> */
/* @0x30be8a .word 0xf00100d1 */
/* @0x30be8e .word 0xf8100107 */
/* @0x30be92 blx 0x130ef2a <b2_toiTime+0xbb5a86> */
/* @0x30be96 strbeq pc, [r11, r1, lsl #2] */
/* @0x30be9a .word 0xf802d507 */
/* @0x30be9e strb r8, [sp, r1, lsl #24]! */
/* @0x30bea2 teqlt r2, r10, lsr #16 */
/* @0x30bea6 .word 0xf8873501 */
/* @0x30beaa adcsmi r9, sp, #0 */
/* @0x30beae stmdavc r10!, {r0, r8, r11, r12, lr, pc} */
/* @0x30beb2 strhs r11, [r0, -r10, lsl #2] */
/* @0x30beb6 strhs lr, [r1, -r0] */
/* @0x30beba str r4, [r8, lr, lsr #12]! */
/* @0x30bebe .word 0x31014620 */
/* @0x30bec2 mcr2 p7, #0x5, pc, c12, c15, #0x7 */
/* @0x30bec6 swpblt r11, r0, [r7] */
/* @0x30beca stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr} */
/* @0x30bece adcvs r1, r1, r9, asr r12 */
/* @0x30bed2 ldrbtmi r4, [r9], #-2319 */
/* @0x30bed6 .word 0xf84231a0 */
/* @0x30beda stmvs r2!, {r0, r1, r5, r12} */
/* @0x30bede stmdavs r3!, {sp} */
/* @0x30bee2 eoreq pc, r2, r3, asr #16 */
/* @0x30bee6 ldrtmi lr, [r8], -r2 */
/* @0x30beea andhs lr, r6, r0 */
/* @0x30beee bls 0x5f32fa <g_SWFaavertbuff+0x20232> */
/* @0x30bef2 addsmi r6, r10, #2818048 */
/* @0x30bef6 .word 0xf5aad001 */
/* @0x30befa andlt lr, sp, r12, ror #22 */
/* @0x30befe svchi #0xf0e8bd */
/* @0x30bf02 blne 0xffabbb0a <b2_toiTime+0xffffffffff362666> */
/* @0x30bf06 ldmibvc lr!, {r1, r2, r3} */
/* @0x30bf0a stmdbvc r0, {r0, r3} ^ */
/* @0x30bf0e ldmdavc r8!, {r0, r3} ^ */
/* @0x30bf12 ldrlt r0, [r0, #-0x9] */
/* @0x30bf16 cmnlt r8, r4, lsl #12 */
/* @0x30bf1a cmnlt r8, r0, lsl #25 */
/* @0x30bf1e stmdavc r8, {r0, r3, r5, r6, r8, r12, sp, pc} */
/* @0x30bf22 strmi r11, [r8], -r0, ror #2 */
/* @0x30bf26 .word 0x1080f8d4 */
/* @0x30bf2a blx 0x449e96 <g_RomDisk+0x52676> */
/* @0x30bf2e stmdavs r0, {r4, r5, r8, r12, sp, pc} */
/* @0x30bf32 bl 0x3e73c6 <error_g0017+0x4006a> */
/* @0x30bf36 ldclt p0, c1, [r0, #-0] */
/* @0x30bf3a .word 0x4608bd10 */
/* @0x30bf3e ldrlt r11, [r0, #-0xd10] */
/* @0x30bf42 .word 0xf8d04614 */
/* @0x30bf46 .word 0xf7ff008c */
/* @0x30bf4a cmplt r8, r4, ror #31 */
/* @0x30bf4e blhs 0x3a6062 <_ZTSPKDn+0x89a> */
/* @0x30bf52 blhs 0x3fff66 <g_RomDisk+0x8746> */
/* @0x30bf56 blhs 0x37ff62 <_ZTS13C_UTF16String+0x1700e> */
/* @0x30bf5a eorvs sp, r3, r4, lsl #2 */
/* @0x30bf5e andhs r6, r0, r3, asr #17 */
/* @0x30bf62 ldclt p0, c6, [r0, #-396] */
/* @0x30bf66 ldclt p0, c2, [r0, #-24] */
/* @0x30bf6a .word 0xe92d0000 */
/* @0x30bf6e ldrshlt r4, [pc], r0 */
/* @0x30bf72 .word 0x2100460d */
/* @0x30bf76 andls r9, pc, #13 */
/* @0x30bf7a .word 0xf8d59110 */
/* @0x30bf7e .word 0xf7da8064 */
/* @0x30bf82 .word 0x4606fc91 */
/* @0x30bf86 stmdahs r0, {r4, r12, pc} */
/* @0x30bf8a orrhi pc, r9, #64 */
/* @0x30bf8e andsls r10, r4, lr, lsl pc */
/* @0x30bf92 .word 0xf04f499c */
/* @0x30bf96 .word 0xf8470901 */
/* @0x30bf9a .word 0x46400d34 */
/* @0x30bf9e movwhs r4, #0x863a */
/* @0x30bfa2 .word 0xf8cd9707 */
/* @0x30bfa6 .word 0xf8cd9048 */
/* @0x30bfaa tstls r5, #76 */
/* @0x30bfae rfeia r10! */
/* @0x30bfb2 .word 0x46049f11 */
/* @0x30bfb6 .word 0xf0402f00 */
/* @0x30bfba stmdbls sp, {r0, r8, pc} */
/* @0x30bfbe subvs r10, r3, #18432 */
/* @0x30bfc2 .word 0x73fff647 */
/* @0x30bfc6 .word 0xf5008183 */
/* @0x30bfca stmdavs r11, {r3, r12, sp} ^ */
/* @0x30bfce strteq pc, [r8], -r0, lsl #2 */
/* @0x30bfd2 eorshi pc, r8, r0, asr #17 */
/* @0x30bfd6 andshs r4, r0, #59768832 */
/* @0x30bfda ldrtmi r6, [r0], -r3, asr #7 */
/* @0x30bfde b 0xffd4968e <b2_toiTime+0xffffffffff5f01ea> */
/* @0x30bfe2 .word 0xf8c69a0d */
/* @0x30bfe6 blge 0xaac01e <b2_toiTime+0x352b7a> */
/* @0x30bfea ldmibvs r2, {r0, r3, r6, r9, r10, lr} ^ */
/* @0x30bfee ldcvc p8, c15, [r0, #-268] */
/* @0x30bff2 andls r9, r11, #0, #14 */
/* @0x30bff6 movwls r4, #0x9610 */
/* @0x30bffa movwls r4, #0x163a */
/* @0x30bffe orrvs pc, r0, #1325400064 */
/* @0x30c002 .word 0xf844f7dc */
/* @0x30c006 .word 0x46069b1a */
/* @0x30c00a .word 0xd1482b00 */
/* @0x30c00e bmi 0x2277c8e <b2_toiTime+0x1b1e7ea> */
/* @0x30c012 .word 0x469a469c */
/* @0x30c016 movwls r4, #0xc47a */
/* @0x30c01a stchs p8, c15, [r0, #-284]! */
/* @0x30c01e blvc 0xfe349162 <b2_toiTime+0xfffffffffdbefcbe> */
/* @0x30c022 ldrmi r9, [pc], -r10, lsl #14 */
/* @0x30c026 strbmi r7, [r11], -r3 */
/* @0x30c02a orrvs pc, r0, pc, asr #8 */
/* @0x30c02e eorls pc, r0, sp, asr #17 */
/* @0x30c032 .word 0xb1639105 */
/* @0x30c036 bl 0x4b2c52 <SrcVerts+0xfc96> */
/* @0x30c03a stmdals sp, {r1, r3, r8} */
/* @0x30c03e andeq lr, r3, #206848 */
/* @0x30c042 stc2 p7, c15, [sp], #872 */
/* @0x30c046 ldrbmi r4, [r4], #1668 */
/* @0x30c04a beq 0x34818e */
/* @0x30c04e strbmi r9, [r7, #-0xc]! */
/* @0x30c052 .word 0x5df3da02 */
/* @0x30c056 andle r4, r1, r11, asr r5 */
/* @0x30c05a ldrh r4, [r1], -r9 */
/* @0x30c05e vst1.8 {d19}, [pc], r1 */
/* @0x30c062 ldrb r7, [r4, r0, lsl #23]! */
/* @0x30c066 andhs pc, r9, r6, lsl r8 */
/* @0x30c06a .word 0x0109eb06 */
/* @0x30c06e bhs 0x5b04ae <g_SWFlineaavertbuff+0x5d3e6> */
/* @0x30c072 .word 0xf0009206 */
/* @0x30c076 bhs 0x66ccea <g_SWFlinevertbuff+0x19c22> */
/* @0x30c07a tsthi r8, #0 */
/* @0x30c07e stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x30c082 blle 0xffedd80e <b2_toiTime+0xffffffffff78436a> */
/* @0x30c086 cmplt r3, r12, lsl #22 */
/* @0x30c08a .word 0xf0402f00 */
/* @0x30c08e blls 0x46cef6 <g_RomDisk+0x756d6> */
/* @0x30c092 mvnsvc pc, pc, asr #12 */
/* @0x30c096 vhsub.s8 d20, d16, d11 */
/* @0x30c09a movwhs r8, #0x637e */
/* @0x30c09e stmdals r11, {r1, r3, r4, r8, r9, r12, pc} */
/* @0x30c0a2 .word 0xf7db4631 */
/* @0x30c0a6 blls 0x9ca5ca <b2_toiTime+0x271126> */
/* @0x30c0aa blhs 0x330cf6 */
/* @0x30c0ae addshi pc, lr, r0, asr #32 */
/* @0x30c0b2 blhs 0x326946 */
/* @0x30c0b6 ldmibvs r10, {r0, r2, r3, r4, r6, r12, lr, pc} ^ */
/* @0x30c0ba svclt #0x1c2a08 */
/* @0x30c0be ldrhi r8, [r10], #-2202 */
/* @0x30c0c2 blvs 0x19a6956 <b2_toiTime+0x124d4b2> */
/* @0x30c0c6 ldrmi r6, [r1], #-3097 */
/* @0x30c0ca addmi r6, r10, #6422528 */
/* @0x30c0ce .word 0xf503d004 */
/* @0x30c0d2 andhs r2, r1, #136, #6 */
/* @0x30c0d6 addhs pc, r4, r3, lsr #17 */
/* @0x30c0da ldmdavs r11, {r0, r1, r5, r6, r9, r11, sp, lr} */
/* @0x30c0de suble r2, r8, r0, lsl #22 */
/* @0x30c0e2 blvs 0x19a6976 <b2_toiTime+0x124d4d2> */
/* @0x30c0e6 .word 0x6c1ab912 */
/* @0x30c0ea suble r2, r2, r0, lsl #20 */
/* @0x30c0ee stmibhi r2!, {r0, r5, r9, r11, pc} */
/* @0x30c0f2 andslt r11, r0, #-536870912 */
/* @0x30c0f6 ldmhi r8, {r1, r2, r4, r5, r9, r11, r12} */
/* @0x30c0fa andle r4, r7, r6, lsl #5 */
/* @0x30c0fe addshi r1, r10, r10, lsl #21 */
/* @0x30c102 andhs r6, r1, #143360 */
/* @0x30c106 orrhs pc, r8, #12582912 */
/* @0x30c10a addhs pc, r4, r3, lsr #17 */
/* @0x30c10e stmibhi r2!, {r0, r1, r5, r9, r11, sp, lr} */
/* @0x30c112 addmi r8, r10, #409600 */
/* @0x30c116 tsthi r10, r6 */
/* @0x30c11a bvs 0xbd4926 <b2_toiTime+0x47b482> */
/* @0x30c11e orrhs pc, r8, #12582912 */
/* @0x30c122 addhs pc, r4, r3, lsr #17 */
/* @0x30c126 bhi 0x1ba69ba <b2_toiTime+0x144d516> */
/* @0x30c12a addmi r8, r10, #2506752 */
/* @0x30c12e orrshi sp, r10, r6 */
/* @0x30c132 bvs 0xbd493e <b2_toiTime+0x47b49a> */
/* @0x30c136 orrhs pc, r8, #12582912 */
/* @0x30c13a addhs pc, r4, r3, lsr #17 */
/* @0x30c13e bhi 0xfeba69d2 <b2_toiTime+0xfffffffffe44d52e> */
/* @0x30c142 addmi r8, r10, #3555328 */
/* @0x30c146 bicshi sp, r10, r10 */
/* @0x30c14a bhi 0xfeba69de <b2_toiTime+0xfffffffffe44d53a> */
/* @0x30c14e cmphi r10, r2, asr r2 */
/* @0x30c152 andhs r6, r1, #143360 */
/* @0x30c156 orrhs pc, r8, #12582912 */
/* @0x30c15a addhs pc, r4, r3, lsr #17 */
/* @0x30c15e bvs 0xbeebea <b2_toiTime+0x495746> */
/* @0x30c162 andlt r8, lr, #401408 */
/* @0x30c166 blx 0x4ae4ce <SrcVerts+0xb512> */
/* @0x30c16a addmi pc, r6, #136314880 */
/* @0x30c16e ldmdane r2, {r2, r3, r4, r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x30c172 stmdavs r3!, {r1, r3, r4, r6, r7, pc} */
/* @0x30c176 strle r0, [r5, #-0x7de] */
/* @0x30c17a svclt #0x540698 */
/* @0x30c17e .word 0x23ba23b9 */
/* @0x30c182 eors r9, r3, r1, lsl r3 */
/* @0x30c186 .word 0xb1ae6a26 */
/* @0x30c18a orrhs pc, r8, #25165824 */
/* @0x30c18e .word 0xf8d36db2 */
/* @0x30c192 orrlt r0, r10, r8, lsl #1 */
/* @0x30c196 .word 0x21016d73 */
/* @0x30c19a movwls r9, #0xf07 */
/* @0x30c19e smlsdls r1, r3, r8, r1 */
/* @0x30c1a2 .word 0xff74f7db */
/* @0x30c1a6 blls 0x76576e <b2_toiTime+0xc2ca> */
/* @0x30c1aa bvs 0xbbadbe <b2_toiTime+0x46191a> */
/* @0x30c1ae ldcvs p13, c6, [r2, #324] */
/* @0x30c1b2 and r5, r1, r11, lsl #9 */
/* @0x30c1b6 tstls r1, #201326592 */
/* @0x30c1ba and r6, r0, r6, lsr #20 */
/* @0x30c1be .word 0xf504b178 */
/* @0x30c1c2 eorlo r3, r8, r8 */
/* @0x30c1c6 ldc2l p7, c15, [r2, #-1020] */
/* @0x30c1ca stmibvs r1!, {r6, r9, r10, lr} */
/* @0x30c1ce rfeia r2! */
/* @0x30c1d2 strbmi r2, [r0], -r0, lsl #6 */
/* @0x30c1d6 strtmi r6, [r1], -r3, lsr #3 */
/* @0x30c1da .word 0xf8acf7db */
/* @0x30c1de strmi lr, [r6], -r0 */
/* @0x30c1e2 sbcslt r9, r10, #17408 */
/* @0x30c1e6 bhs 0xfef30e2e <b2_toiTime+0xfffffffffe7d798a> */
/* @0x30c1ea subs sp, r10, #-1073741821 */
/* @0x30c1ee strhs r6, [r0], -r0, lsr #20 */
/* @0x30c1f2 .word 0xfc19f7ff */
/* @0x30c1f6 bvs 0xb5dafe <b2_toiTime+0x40465a> */
/* @0x30c1fa .word 0xf89cf7db */
/* @0x30c1fe ldrb r6, [lr, r6, lsr #4] */
/* @0x30c202 subhs r11, r0, r0, lsl #30 */
/* @0x30c206 ldrbne r0, [r3, #-0x2]! */
/* @0x30c20a blhs 0x30c212 <af_shaper_get_elem+0x1a80> */
/* @0x30c20e subhi pc, r7, #64 */
/* @0x30c212 .word 0xf8c59f0f */
/* @0x30c216 svchs #0x608c */
/* @0x30c21a adcslt sp, r11, #384 */
/* @0x30c21e strtmi r11, [r8], -r3, lsr #2 */
/* @0x30c222 stc2l p7, c15, [r7], {255} */
/* @0x30c226 sbcs r2, r3, #6 */
/* @0x30c22a movwhs r2, #0x101 */
/* @0x30c22e andeq lr, r10, r5, lsl #17 */
/* @0x30c232 stmvs r11!, {r4, r5, r9, r10, lr} */
/* @0x30c236 strne pc, [r8, #-0x8df] */
/* @0x30c23a orrseq pc, r2, #67 */
/* @0x30c23e ldrbtmi r6, [r9], #-171 */
/* @0x30c242 mcr2 p7, #0x3, pc, c7, c15, #0x7 */
/* @0x30c246 stmdavs r3, {r3, r4, r5, r6, r8, r12, sp, pc} ^ */
/* @0x30c24a .word 0xd10c2b01 */
/* @0x30c24e cmplt r3, r3, asr #17 */
/* @0x30c252 .word 0xf003781b */
/* @0x30c256 blhs 0x164d1da <b2_toiTime+0xef3d36> */
/* @0x30c25a blhs 0x1400266 <b2_toiTime+0xca6dc2> */
/* @0x30c25e stmvs r11!, {r0, r1, r8, r12, lr, pc} */
/* @0x30c262 movweq pc, #0x4043 */
/* @0x30c266 .word 0xf8df60ab */
/* @0x30c26a .word 0x463014d8 */
/* @0x30c26e .word 0xf7ff4479 */
/* @0x30c272 qdaddlt pc, r0, r8 */
/* @0x30c276 teqlt r9, r1, asr #17 */
/* @0x30c27a bge 0x71db82 <g_SWFvertbuff+0x4aaba> */
/* @0x30c27e blx 0xb4a1f8 <b2_toiTime+0x3f0d54> */
/* @0x30c282 .word 0x61689b10 */
/* @0x30c286 and r11, r10, #-1073741820 */
/* @0x30c28a .word 0x616b2300 */
/* @0x30c28e ldmdbeq r8, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x30c292 .word 0xf8d52700 */
/* @0x30c296 ldrtmi r4, [r9], -r12, lsl #1 */
/* @0x30c29a andshs r4, r0, #72, #12 */
/* @0x30c29e .word 0xf8d59711 */
/* @0x30c2a2 .word 0xf5aaa064 */
/* @0x30c2a6 .word 0xf8dfe984 */
/* @0x30c2aa qadd8mi r1, r0, r12 */
/* @0x30c2ae ldrbtmi r6, [r9], #-239 */
/* @0x30c2b2 mcr2 p7, #0x1, pc, c15, c15, #0x7 */
/* @0x30c2b6 stmdavs r3, {r3, r5, r6, r7, r8, r12, sp, pc} ^ */
/* @0x30c2ba tstle r10, r1, lsl #22 */
/* @0x30c2be biclt r6, r3, r3, asr #17 */
/* @0x30c2c2 .word 0xf003781b */
/* @0x30c2c6 blhs 0x16cd24a <b2_toiTime+0xf73da6> */
/* @0x30c2ca blhs 0x15802d6 <b2_toiTime+0xe26e32> */
/* @0x30c2ce stmvs r11!, {r0, r4, r8, r12, lr, pc} ^ */
/* @0x30c2d2 movweq pc, #0x1043 */
/* @0x30c2d6 stmvs r3, {r0, r1, r3, r5, r6, r7, sp, lr} ^ */
/* @0x30c2da .word 0xf003781b */
/* @0x30c2de blhs 0x16cd262 <b2_toiTime+0xf73dbe> */
/* @0x30c2e2 .word 0xf8dfd103 */
/* @0x30c2e6 ldrbtmi r3, [r11], #-1124 */
/* @0x30c2ea .word 0xf8dfe002 */
/* @0x30c2ee ldrbtmi r3, [r11], #-1120 */
/* @0x30c2f2 .word 0xf8df9318 */
/* @0x30c2f6 qsaxmi r1, r0, r12 */
/* @0x30c2fa .word 0xf7ff4479 */
/* @0x30c2fe orrlt pc, r8, r10, lsl #28 */
/* @0x30c302 blhs 0x366416 <_ZTS12CDS_Priority+0x846e> */
/* @0x30c306 stmvs r3, {r1, r2, r3, r8, r12, lr, pc} ^ */
/* @0x30c30a ldmdavc r11, {r0, r1, r5, r6, r8, r12, sp, pc} */
/* @0x30c30e bicseq pc, pc, #3 */
/* @0x30c312 .word 0xd1072b42 */
/* @0x30c316 .word 0xf04368eb */
/* @0x30c31a rscvs r0, r11, r2, lsl #6 */
/* @0x30c31e ldrtlo pc, [r8], #-2271 */
/* @0x30c322 tstls r7, #2063597568 */
/* @0x30c326 ldrtne pc, [r4], #-2271 */
/* @0x30c32a ldrbtmi r4, [r9], #-1568 */
/* @0x30c32e ldc2l p7, c15, [r1, #1020]! */
/* @0x30c332 stmdavs r3, {r3, r4, r6, r8, r12, sp, pc} ^ */
/* @0x30c336 .word 0xd1082b01 */
/* @0x30c33a teqlt r3, r3, asr #17 */
/* @0x30c33e .word 0xb122781a */
/* @0x30c342 sbcseq pc, pc, #2 */
/* @0x30c346 svclt #0x182a4e */
/* @0x30c34a .word 0xf8df9319 */
/* @0x30c34e qadd16mi r1, r0, r0 */
/* @0x30c352 .word 0xf7ff4479 */
/* @0x30c356 ldrsblt pc, [r8, #-222] */
/* @0x30c35a blhs 0x36646e <_ZTS12CDS_Priority+0x84c6> */
/* @0x30c35e stmvs r3, {r3, r8, r12, lr, pc} ^ */
/* @0x30c362 ldmdavc r10, {r0, r1, r4, r5, r8, r12, sp, pc} */
/* @0x30c366 .word 0xf002b122 */
/* @0x30c36a bhs 0x168ceee <b2_toiTime+0xf33a4a> */
/* @0x30c36e tstls r6, #24, #30 */
/* @0x30c372 svcge #0x1a2400 */
/* @0x30c376 strtmi r4, [r3], -r3, lsr #13 */
/* @0x30c37a andeq pc, r4, r9, asr r8 */
/* @0x30c37e teqlt r8, r3, ror #3 */
/* @0x30c382 .word 0xf5aa9304 */
/* @0x30c386 .word 0xf10be8d8 */
/* @0x30c38a mvnpl r0, r1, lsl #22 */
/* @0x30c38e blls 0x41d5a2 <g_RomDisk+0x25d82> */
/* @0x30c392 .word 0x2c103404 */
/* @0x30c396 .word 0xf1bbd1f0 */
/* @0x30c39a .word 0xd1060f00 */
/* @0x30c39e .word 0xf04f4bf1 */
/* @0x30c3a2 ldrbtmi r0, [r11], #-2824 */
/* @0x30c3a6 movwhs r9, #0x7316 */
/* @0x30c3aa uadd16mi r9, r0, r10 */
/* @0x30c3ae bls 0x4ddd1a <SrcVerts+0x3ad5e> */
/* @0x30c3b2 mrc2 p7, #0x5, apsr_nzcv, c8, c10, #0x6 */
/* @0x30c3b6 .word 0x46039c11 */
/* @0x30c3ba bllt 0x2024a62 <b2_toiTime+0x18cb5be> */
/* @0x30c3be beq 0xe88502 <b2_toiTime+0x72f05e> */
/* @0x30c3c2 bleq 0xb48506 <b2_toiTime+0x3ef062> */
/* @0x30c3c6 eorne pc, r4, r9, asr r8 */
/* @0x30c3ca eorgt pc, r4, r7, asr r8 */
/* @0x30c3ce stmibvs r10!, {r0, r3, r5, r6, r7, r8, r12, sp, pc} */
/* @0x30c3d2 svclt #0x1c4293 */
/* @0x30c3d6 andlt pc, r0, r3, lsl #17 */
/* @0x30c3da strbtmi r3, [r2], -r1, lsl #6 */
/* @0x30c3de andsgt pc, r0, sp, asr #17 */
/* @0x30c3e2 .word 0xf5aa4618 */
/* @0x30c3e6 .word 0xf8dde8ea */
/* @0x30c3ea .word 0x4603c010 */
/* @0x30c3ee tstlt r12, r4, lsl #9 */
/* @0x30c3f2 andle r2, r1, r3, lsl #24 */
/* @0x30c3f6 and r4, r8, r3, ror #12 */
/* @0x30c3fa rscsle r4, r11, r3, ror #10 */
/* @0x30c3fe blhs 0x38a452 <bigtens_D2A+0x922> */
/* @0x30c402 svclt #0x82a20 */
/* @0x30c406 .word 0xac01f803 */
/* @0x30c40a strlo lr, [r1], #-2038 */
/* @0x30c40e bicsle r2, r9, r4, lsl #24 */
/* @0x30c412 andsvc r2, r10, r0, lsl #4 */
/* @0x30c416 .word 0x9044f8dd */
/* @0x30c41a strtmi lr, [r1], r0 */
/* @0x30c41e subls pc, r0, sp, asr #17 */
/* @0x30c422 svceq #0xf1b9 */
/* @0x30c426 teqhi r11, r0, asr #32 */
/* @0x30c42a .word 0xf10d6b33 */
/* @0x30c42e .word 0xf8cd0a40 */
/* @0x30c432 strbmi r9, [r0], -r0 */
/* @0x30c436 .word 0xf8cd3301 */
/* @0x30c43a .word 0x612ba004 */
/* @0x30c43e movwhs r2, #0x1110 */
/* @0x30c442 mvnvs r4, r10, asr #12 */
/* @0x30c446 mcr2 p7, #0x1, pc, c2, c11, #0x6 */
/* @0x30c44a .word 0x46049b10 */
/* @0x30c44e blhs 0x324cf6 */
/* @0x30c452 .word 0x8125f040 */
/* @0x30c456 andshs r4, r0, #76546048 */
/* @0x30c45a stm r10!, {r1, r3, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x30c45e bvs 0xfefe702e <b2_toiTime+0xfffffffffe88db8a> */
/* @0x30c462 stmibmi r0, {r4, r5, r9, r10, lr} ^ */
/* @0x30c466 eorhi r4, r3, r3, lsl r4 */
/* @0x30c46a .word 0xf7ff4479 */
/* @0x30c46e tstlt r8, r2, asr sp */
/* @0x30c472 smlabths r10, r0, r8, r6 */
/* @0x30c476 and r3, r3, r5 */
/* @0x30c47a strheq pc, [r0], -r4 */
/* @0x30c47e subeq r2, r0, r3, lsl #2 */
/* @0x30c482 mcrr p0, #0x0, pc, r6, c12 */
/* @0x30c486 ldrbtmi r4, [r9], #-2489 */
/* @0x30c48a ldrtmi r8, [r0], -r0, rrx */
/* @0x30c48e stc2l p7, c15, [r1, #-1020] */
/* @0x30c492 stmvs r3, {r3, r4, r6, r8, r12, sp, pc} ^ */
/* @0x30c496 rschs pc, r1, pc, asr #8 */
/* @0x30c49a cmpmi r8, #2719744 */
/* @0x30c49e andmi pc, sp, r0, lsl #10 */
/* @0x30c4a2 .word 0xf00c3027 */
/* @0x30c4a6 rsbvs lr, r0, r4, lsr r12 */
/* @0x30c4aa rfeib r4! */
/* @0x30c4ae orrseq r3, r11, r2 */
/* @0x30c4b2 stmibmi lr!, {r0, r1, r5, r6, sp, lr} */
/* @0x30c4b6 ldrbtmi r4, [r9], #-1584 */
/* @0x30c4ba stc2 p7, c15, [r11, #-1020]! */
/* @0x30c4be rfeib r0! */
/* @0x30c4c2 orrseq r3, r11, r12 */
/* @0x30c4c6 stmibmi r10!, {r0, r1, r5, r6, r7, sp, lr} */
/* @0x30c4ca ldrbtmi r4, [r9], #-1584 */
/* @0x30c4ce stc2 p7, c15, [r1, #-1020]! */
/* @0x30c4d2 rfeia r0! */
/* @0x30c4d6 and r11, r0, r12 */
/* @0x30c4da stmibmi r6!, {r0, r1, r7, r9, r10, lr} */
/* @0x30c4de ldrbtmi r4, [r9], #-1584 */
/* @0x30c4e2 ldc2 p7, c15, [r7, #-1020] */
/* @0x30c4e6 rfeia r0! */
/* @0x30c4ea and r9, r0, r12 */
/* @0x30c4ee stmvs r3!, {r0, r7, r9, r10, lr} ^ */
/* @0x30c4f2 stmdavs r3!, {r0, r1, r3, r4, r5, r7, r8, r11, r12, sp, pc} ^ */
/* @0x30c4f6 svceq #0xf1b9 */
/* @0x30c4fa blx 0x70056a <g_SWFvertbuff+0x2d4a2> */
/* @0x30c4fe smlalbbhs pc, r8, r9, r0 */
/* @0x30c502 .word 0xf00c4358 */
/* @0x30c506 rscvs lr, r0, r4, lsl #24 */
/* @0x30c50a svceq #0xf1bb */
/* @0x30c50e stmvs r3!, {r0, r4, r12, lr, pc} ^ */
/* @0x30c512 .word 0xf08bfa0f */
/* @0x30c516 .word 0xf189fa0f */
/* @0x30c51a .word 0xf00c4358 */
/* @0x30c51e .word 0x60a0ebf8 */
/* @0x30c522 .word 0xf1bbe009 */
/* @0x30c526 andle r0, r4, r0, lsl #30 */
/* @0x30c52a svceq #0xf1b9 */
/* @0x30c52e and sp, r0, pc, ror #3 */
/* @0x30c532 stmvs r3!, {r0, r1, r5, r6, r7, sp, lr} ^ */
/* @0x30c536 blvs 0xff0247ca <b2_toiTime+0xfffffffffe8cb326> */
/* @0x30c53a strbmi r2, [r0], -r0, lsl #4 */
/* @0x30c53e streq lr, [r4], #-2189 */
/* @0x30c542 blvs 0xfd496a <b2_toiTime+0x87b4c6> */
/* @0x30c546 stc2 p7, c15, [r2, #876]! */
/* @0x30c54a .word 0xf8c59b10 */
/* @0x30c54e blhs 0x30c796 <af_shaper_get_elem+0x2004> */
/* @0x30c552 adchi pc, r5, r0, asr #32 */
/* @0x30c556 cdpeq p0, #0x2, c15, c4, c15, #0x2 */
/* @0x30c55a adclo pc, r4, r5, asr #17 */
/* @0x30c55e addsmi r6, r3, #51200 */
/* @0x30c562 blx 0x6c0dc0 <g_SWFlinevertbuff+0x6dcf8> */
/* @0x30c566 .word 0xf8d54203 */
/* @0x30c56a ldmdavs r0, {r4, r7, r12} ^ */
/* @0x30c56e eorseq pc, r3, r1, asr #16 */
/* @0x30c572 ldrsbne pc, [r0], r5 */
/* @0x30c576 biceq lr, r3, r1, lsl #22 */
/* @0x30c57a ldmdavs r1, {r0, r1, r3, r7, pc} ^ */
/* @0x30c57e addsmi r6, r1, #466944 */
/* @0x30c582 mrrcne p1, #0x0, sp, r10, c3 */
/* @0x30c586 .word 0xf8c5bf18 */
/* @0x30c58a movwlo r3, #0x10a4 */
/* @0x30c58e ldmdbmi r10!, {r1, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x30c592 ldrbtmi r4, [r9], #-1584 */
/* @0x30c596 ldc2 p7, c15, [sp], #1020 */
/* @0x30c59a ldrbtmi r4, [r9], #-2425 */
/* @0x30c59e ldrtmi r4, [r0], -r4, lsl #12 */
/* @0x30c5a2 ldc2 p7, c15, [r7], #1020 */
/* @0x30c5a6 rsble r2, r4, r0, lsl #24 */
/* @0x30c5aa rsble r2, r2, r0, lsl #16 */
/* @0x30c5ae blhs 0x366742 <_ZTS12CDS_Priority+0x879a> */
/* @0x30c5b2 stmdavs r3, {r0, r1, r2, r3, r4, r6, r8, r12, lr, pc} ^ */
/* @0x30c5b6 cmple r12, r1, lsl #22 */
/* @0x30c5ba blhs 0x32694e */
/* @0x30c5be stmvs r1, {r0, r3, r4, r6, r12, lr, pc} ^ */
/* @0x30c5c2 subsle r2, r6, r0, lsl #18 */
/* @0x30c5c6 ldrbmi r4, [r2], -r0, asr #12 */
/* @0x30c5ca .word 0xf97af7dc */
/* @0x30c5ce .word 0xf8c59b10 */
/* @0x30c5d2 blhs 0x30c7ea <af_shaper_get_elem+0x2058> */
/* @0x30c5d6 strbmi sp, [r0], -r3, ror #2 */
/* @0x30c5da ldrbmi r6, [r2], -r1, ror #17 */
/* @0x30c5de .word 0xf970f7dc */
/* @0x30c5e2 .word 0xf8c59b10 */
/* @0x30c5e6 blhs 0x30c80e <af_shaper_get_elem+0x207c> */
/* @0x30c5ea stmdavc r3, {r0, r3, r4, r6, r8, r12, lr, pc} */
/* @0x30c5ee bicseq pc, pc, #3 */
/* @0x30c5f2 .word 0xd1232b49 */
/* @0x30c5f6 .word 0xf0037843 */
/* @0x30c5fa blhs 0x17cd57e <b2_toiTime+0x10740da> */
/* @0x30c5fe stmvc r3, {r1, r2, r3, r4, r8, r12, lr, pc} */
/* @0x30c602 bicseq pc, pc, #3 */
/* @0x30c606 tstle r9, pc, asr #22 */
/* @0x30c60a ldmdbmi sp, {r2, r6, r7, r10, r11, r12} ^ */
/* @0x30c60e ldrbtmi r4, [r9], #-1568 */
/* @0x30c612 svc #0xb0f5a9 */
/* @0x30c616 ldmdbmi r11, {r7, r8, r12, sp, pc} ^ */
/* @0x30c61a ldrbtmi r4, [r9], #-1568 */
/* @0x30c61e svc #0xaaf5a9 */
/* @0x30c622 ldmdbmi r9, {r5, r6, r8, r11, r12, sp, pc} ^ */
/* @0x30c626 .word 0x0084f8d5 */
/* @0x30c62a .word 0xf5a94479 */
/* @0x30c62e .word 0xf1d0efa2 */
/* @0x30c632 svclt #0x380001 */
/* @0x30c636 and r2, r2, r0 */
/* @0x30c63a and r2, r0, r1 */
/* @0x30c63e movwhs r2, #0x0 */
/* @0x30c642 tstls r11, #109051904 */
/* @0x30c646 rsbslo pc, r0, sp, lsr #17 */
/* @0x30c64a rsbslo pc, r2, sp, lsr #17 */
/* @0x30c64e blmi 0x1178b36 <b2_toiTime+0xa1f692> */
/* @0x30c652 movwhs r9, #0x331b */
/* @0x30c656 rsbslo pc, r0, sp, lsr #17 */
/* @0x30c65a .word 0xf8ad2301 */
/* @0x30c65e stmdami r11, {r1, r4, r5, r6, r12, sp} ^ */
/* @0x30c662 ldrtmi r2, [r10], -r0, lsl #2 */
/* @0x30c666 ldrbtmi r4, [r8], #-1547 */
/* @0x30c66a .word 0xf7db3018 */
/* @0x30c66e andsls pc, r0, r3, lsl #29 */
/* @0x30c672 blmi 0xf846ce <b2_toiTime+0x82b22a> */
/* @0x30c676 stmdami r6, {r8, sp} ^ */
/* @0x30c67a ldrls r4, [r10, #-0x63a] */
/* @0x30c67e tstls r11, #120, #8 */
/* @0x30c682 movwhs r3, #0x7018 */
/* @0x30c686 rsbslo pc, r0, sp, lsr #17 */
/* @0x30c68a .word 0xf8ad460b */
/* @0x30c68e .word 0xf7db1072 */
/* @0x30c692 bvs 0x1e0c05e <b2_toiTime+0x16b2bba> */
/* @0x30c696 tstlt r3, r0, lsl r0 */
/* @0x30c69a ldmdavs r11, {r0, r1, r3, r5, r7, r9, r11, sp, lr} */
/* @0x30c69e ldmdals r0, {r0, r1, r3, r5, r6, r7, r8, r10, sp, lr} */
/* @0x30c6a2 qadd8mi lr, r8, r6 */
/* @0x30c6a6 blx 0xfe48a6aa <b2_toiTime+0xfffffffffdd31206> */
/* @0x30c6aa adds r2, r1, r2 */
/* @0x30c6ae .word 0xf04f990e */
/* @0x30c6b2 bl 0x48ceba <prim_v+0x3506> */
/* @0x30c6b6 andvc r0, r10, r7, lsl #22 */
/* @0x30c6ba blhs 0xbe3e8e <b2_toiTime+0x48a9ea> */
/* @0x30c6be blhs 0x9c06ca <b2_toiTime+0x267226> */
/* @0x30c6c2 svcls #0x8d10c */
/* @0x30c6c6 strlo r9, [r1, -r6, lsl #18] */
/* @0x30c6ca svcls #0xe9708 */
/* @0x30c6ce eorsvc r2, r9, r10, lsl #18 */
/* @0x30c6d2 streq pc, [r1, -r9, lsl #2] */
/* @0x30c6d6 .word 0xf04fd123 */
/* @0x30c6da ldrt r0, [r8], #2829 */
/* @0x30c6de ldclle p5, c4, [r0, #740]! */
/* @0x30c6e2 streq lr, [r9, -r7, asr #23] */
/* @0x30c6e6 andsgt pc, r0, sp, asr #17 */
/* @0x30c6ea ldrbmi r9, [r8], -r3, lsl #14 */
/* @0x30c6ee strls r4, [r0], #-1593 */
/* @0x30c6f2 blls 0x5b2f1a <g_SWFlineaavertbuff+0x5fe52> */
/* @0x30c6f6 .word 0x47b89f16 */
/* @0x30c6fa ldrsbgt pc, [r0], -sp */
/* @0x30c6fe andlo r9, r1, r10, lsl r0 */
/* @0x30c702 strls sp, [r0], #-265 */
/* @0x30c706 stmdbls r3, {r3, r4, r6, r9, r10, lr} */
/* @0x30c70a blls 0x5b2f32 <g_SWFlineaavertbuff+0x5fe6a> */
/* @0x30c70e .word 0x47b89f16 */
/* @0x30c712 ldrsbgt pc, [r0], -sp */
/* @0x30c716 blls 0x9b0786 <b2_toiTime+0x2572e2> */
/* @0x30c71a sbcsle r2, r2, r0, lsl #22 */
/* @0x30c71e stmdbls r6, {r0, r1, r2, r3, r4, r5, r7, r10, sp, lr, pc} */
/* @0x30c722 stmdbhs sp, {r8, r9, sp} */
/* @0x30c726 .word 0xf44fbf14 */
/* @0x30c72a .word 0xf04f7b80 */
/* @0x30c72e str r0, [r0], #2826 */
/* @0x30c732 bne 0x16bc33a <b2_toiTime+0xf62e96> */
/* @0x30c736 stmdbvs r3!, {r0} ^ */
/* @0x30c73a svcmi #0x42756e */
/* @0x30c73e svchs #0x414144 */
/* @0x30c742 strhs r0, [r6, #0x8]! */
/* @0x30c746 strhs r0, [r8, #-0x8]! */
/* @0x30c74a strbths r0, [r1], #8 */
/* @0x30c74e strbths r0, [r1], #8 */
/* @0x30c752 strbths r0, [r4], #8 */
/* @0x30c756 strbhs r0, [r8], #8 */
/* @0x30c75a strbhs r0, [r3], #8 */
/* @0x30c75e strths r0, [r11], #8 */
/* @0x30c762 strbths r0, [r8], #-8 */
/* @0x30c766 .word 0x23b60008 */
/* @0x30c76a .word 0x23a60008 */
/* @0x30c76e orrhs r0, r1, #8 */
/* @0x30c772 cmnhs r8, #8 */
/* @0x30c776 cmnhs r1, #8 */
/* @0x30c77a sbchs r0, r10, #8 */
/* @0x30c77e sbcshs r0, r3, #8 */
/* @0x30c782 rsbshs r0, r0, #8 */
/* @0x30c786 rsbhs r0, r10, #8 */
/* @0x30c78a rsbhs r0, r1, #8 */
/* @0x30c78e svcle #0xac0008 */
/* @0x30c792 svcle #0x96000d */
/* @0x30c796 bls 0x44c7d2 <g_RomDisk+0x54fb2> */
/* @0x30c79a blls 0x554ba6 <g_SWFlineaavertbuff+0x1ade> */
/* @0x30c79e b 0x16f1fa6 <b2_toiTime+0xf98b02> */
/* @0x30c7a2 stmdals r11, {r1, r6, r8, r11} */
/* @0x30c7a6 ldrmi r9, [r2], r1, lsl #6 */
/* @0x30c7aa .word 0xf7db464b */
/* @0x30c7ae blls 0x9cb972 <b2_toiTime+0x2724ce> */
/* @0x30c7b2 blhs 0x31dfd2 */
/* @0x30c7b6 ldclge p4, c15, [r3], #-508 */
/* @0x30c7ba andsls pc, r4, sp, asr #17 */
/* @0x30c7be bl 0xff5058ae <b2_toiTime+0xfffffffffedac40a> */
/* @0x30c7c2 ldmibne r1!, {r2, r3, r9, r11} ^ */
/* @0x30c7c6 smladxhs r0, r0, r6, r4 */
/* @0x30c7ca .word 0xf5a94652 */
/* @0x30c7ce ldrt lr, [r1], #-3938 */
/* @0x30c7d2 pop {r0, r1, r2, r3, r4, r12, sp, pc} */
/* @0x30c7d6 movwhs r8, #0xff0 */
/* @0x30c7da ldrblt r6, [r0, #0xb]! */
/* @0x30c7de stmvs r2, {r4, r8, r9, r12, sp, pc} */
/* @0x30c7e2 stmdavs r2, {r1, r3, r4, r5, r6, r7, r8, r12, sp, pc} */
/* @0x30c7e6 qadd16hs r4, r0, r12 */
/* @0x30c7ea stmvs r5, {r1, r4, r11, sp, lr} */
/* @0x30c7ee andsle r4, r0, #172, #4 */
/* @0x30c7f2 .word 0xf8556805 */
/* @0x30c7f6 bne 0x2e888e <FT_Get_Sfnt_LangTag+0xa6> */
/* @0x30c7fa ldrshlt r5, [r5, -sp] */
/* @0x30c7fe movwlo r5, #0x14d5 */
/* @0x30c802 stmvs r5, {r1, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30c806 ldrmi r3, [pc], -r1, lsl #8 */
/* @0x30c80a svclt #0x3c42ac */
/* @0x30c80e movwlo r5, #0x15d6 */
/* @0x30c812 stmdami r4, {r0, r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30c816 adclo r4, r0, r8, ror r4 */
/* @0x30c81a svclt #0x1c4282 */
/* @0x30c81e ldrbpl r2, [r0], #0 */
/* @0x30c822 ldrmi r6, [r0], -r11 */
/* @0x30c826 svcvs #0x36bdf0 */
/* @0x30c82a push {r0, r3} */
/* @0x30c82e .word 0x46044ff0 */
/* @0x30c832 .word 0xf500b089 */
/* @0x30c836 strmi r2, [sp], -r8, lsl #15 */
/* @0x30c83a .word 0xf8d44608 */
/* @0x30c83e .word 0xf04f1080 */
/* @0x30c842 ldrmi r0, [r6], -r0, lsl #18 */
/* @0x30c846 .word 0x8088f8d7 */
/* @0x30c84a andsls pc, r8, sp, asr #17 */
/* @0x30c84e ldc2l p7, c15, [r2, #-864]! */
/* @0x30c852 stmdavs r2, {r3, r4, r5, r8, r9, r12, sp, pc} */
/* @0x30c856 bl 0x3e7cea <error_g0017+0x4098e> */
/* @0x30c85a stmdavs r3!, {r1, r10, r12} ^ */
/* @0x30c85e andsle r2, r7, r2, lsl #22 */
/* @0x30c862 andsle r2, r10, r3, lsl #22 */
/* @0x30c866 .word 0xf0402b01 */
/* @0x30c86a strbmi r8, [r0], -r4, asr #2 */
/* @0x30c86e .word 0xf7da68e1 */
/* @0x30c872 .word 0xf8c4fd61 */
/* @0x30c876 cdphs p0, #0x0, c9, c0, c12, #0x0 */
/* @0x30c87a teqhi r11, r0 */
/* @0x30c87e blhs 0x32a952 */
/* @0x30c882 teqhi r7, r0 */
/* @0x30c886 ldrtmi r4, [r1], -r0, asr #12 */
/* @0x30c88a .word 0xf7dcaa06 */
/* @0x30c88e and pc, r2, r9, lsl r8 */
/* @0x30c892 .word 0xf7fe4630 */
/* @0x30c896 rscvs pc, r0, r6, ror pc */
/* @0x30c89a ldrtmi lr, [r0], -r11, lsr #2 */
/* @0x30c89e blx 0xc8a8a2 <b2_toiTime+0x5313fe> */
/* @0x30c8a2 .word 0xf107e7f9 */
/* @0x30c8a6 qadd8mi r0, r8, r4 */
/* @0x30c8aa .word 0xf7d84649 */
/* @0x30c8ae strmi pc, [r2], r3, asr #26 */
/* @0x30c8b2 .word 0xd1672800 */
/* @0x30c8b6 .word 0x2088f8d7 */
/* @0x30c8ba andls r4, r7, r9, asr #12 */
/* @0x30c8be andls r4, r3, #40, #12 */
/* @0x30c8c2 ldc2 p7, c15, [r8, #-864]! */
/* @0x30c8c6 cmple r3, r0, lsl #16 */
/* @0x30c8ca .word 0x308cf8d7 */
/* @0x30c8ce bleq 0xa48d0a <b2_toiTime+0x2ef866> */
/* @0x30c8d2 ldrsbhs pc, [r0], r7 */
/* @0x30c8d6 .word 0xf8cd2110 */
/* @0x30c8da movwls r11, #0x4 */
/* @0x30c8de stmdals r3, {r0, r1, r4, r6, r10, r11, r12} */
/* @0x30c8e2 blx 0xff84a858 <b2_toiTime+0xffffffffff0f13b4> */
/* @0x30c8e6 strmi r9, [r2], r7, lsl #22 */
/* @0x30c8ea addeq pc, r12, r7, asr #17 */
/* @0x30c8ee teqle pc, r0, lsl #22 */
/* @0x30c8f2 ldrsbhs pc, [r0], r7 */
/* @0x30c8f6 movwls r4, #0x2619 */
/* @0x30c8fa andls r0, r5, #-2147483644 */
/* @0x30c8fe andls r4, r4, #33554432 */
/* @0x30c902 andshs r4, r0, #16, #12 */
/* @0x30c906 cdp p5, #0x5, c15, c4, c9, #0x5 */
/* @0x30c90a .word 0xf5a94628 */
/* @0x30c90e blls 0x3c8166 <error_g0017+0x20e0a> */
/* @0x30c912 stm sp, {r0, r8, sp} */
/* @0x30c916 ldrmi r0, [r10], -r8, lsl #16 */
/* @0x30c91a .word 0x0c01f100 */
/* @0x30c91e .word 0xf8cd9803 */
/* @0x30c922 strbtmi r12, [r3], -r8 */
/* @0x30c926 blx 0xfefca89c <b2_toiTime+0xfffffffffe8713f8> */
/* @0x30c92a .word 0xf84a9b05 */
/* @0x30c92e .word 0xf8dd0003 */
/* @0x30c932 .word 0xf8ddb01c */
/* @0x30c936 .word 0xf1bbc008 */
/* @0x30c93a tstle r9, r0, lsl #30 */
/* @0x30c93e strtmi r4, [r9], -r2, ror #12 */
/* @0x30c942 cdp p5, #0x3, c15, c12, c9, #0x5 */
/* @0x30c946 movwhs r9, #0x1a04 */
/* @0x30c94a andlt pc, r8, r2, asr #17 */
/* @0x30c94e .word 0x464a6053 */
/* @0x30c952 .word 0xf8d79b05 */
/* @0x30c956 .word 0xf85a1090 */
/* @0x30c95a cmplo r3, r3 */
/* @0x30c95e .word 0xf7db9b03 */
/* @0x30c962 andls pc, r7, r2, lsr #28 */
/* @0x30c966 .word 0xf8d7b920 */
/* @0x30c96a movwlo r3, #0x1090 */
/* @0x30c96e addslo pc, r0, r7, asr #17 */
/* @0x30c972 movwls r9, #0x6b07 */
/* @0x30c976 .word 0xf0402b00 */
/* @0x30c97a .word 0x462880bc */
/* @0x30c97e .word 0xf7d84649 */
/* @0x30c982 pkhtbmi pc, r2, r9, asr #25 */
/* @0x30c986 stcvs p12, c6, [r3], #904 */
/* @0x30c98a .word 0xd120429a */
/* @0x30c98e ldmiblt r10!, {r1, r2, r8, r9, r11, sp, pc} */
/* @0x30c992 andeq lr, r12, sp, lsl #17 */
/* @0x30c996 tsths r0, r0, asr #12 */
/* @0x30c99a .word 0xf7db2301 */
/* @0x30c99e blls 0x4cb782 <SrcVerts+0x287c6> */
/* @0x30c9a2 blhs 0x325e2a */
/* @0x30c9a6 adchi pc, r5, r0, asr #32 */
/* @0x30c9aa smlatbhs r0, r0, r12, r6 */
/* @0x30c9ae andshs r6, r0, #2240 */
/* @0x30c9b2 andne lr, r0, r3, lsl #22 */
/* @0x30c9b6 ldcl p5, c15, [r12, #676]! */
/* @0x30c9ba movwlo r6, #0x1ca3 */
/* @0x30c9be and r6, r6, r3, lsr #9 */
/* @0x30c9c2 strbmi r6, [r0], -r1, lsr #26 */
/* @0x30c9c6 andeq lr, r10, sp, lsl #17 */
/* @0x30c9ca mrrcne p1, #0x1, r2, r3, c0 */
/* @0x30c9ce .word 0xf8dae7e5 */
/* @0x30c9d2 bhs 0x17949da <b2_toiTime+0x103b536> */
/* @0x30c9d6 .word 0xf504d907 */
/* @0x30c9da cps #0x8 */
/* @0x30c9de blo 0x17e13e6 <b2_toiTime+0x1087f42> */
/* @0x30c9e2 .word 0x308cf8d3 */
/* @0x30c9e6 blmi 0x19849f6 <b2_toiTime+0x122b552> */
/* @0x30c9ea movtlo r4, #0x47b */
/* @0x30c9ee movwne lr, #0x2b03 */
/* @0x30c9f2 .word 0xf8d46ce2 */
/* @0x30c9f6 b 0x16f4b3e <b2_toiTime+0xf9b69a> */
/* @0x30c9fa ldmdavs r10, {r1, r8, r11, r12} */
/* @0x30c9fe streq lr, [r9, -r10, lsl #22] */
/* @0x30ca02 andhs pc, r9, r10, asr #16 */
/* @0x30ca06 rsbsvs r6, r10, r10, asr r8 */
/* @0x30ca0a umlalsvs r6, r10, r10, r8 */
/* @0x30ca0e blhs 0x3a6b82 <_ZTSPKDn+0x13ba> */
/* @0x30ca12 blhs 0x400a5e <g_RomDisk+0x923e> */
/* @0x30ca16 blhs 0x380a6a <_ZTS13C_UTF16String+0x17b16> */
/* @0x30ca1a movwhs sp, #0x115 */
/* @0x30ca1e ldrshlt r6, [r6, r11] */
/* @0x30ca22 orrlt r7, r3, r3, lsr r8 */
/* @0x30ca26 ldrtmi r4, [r1], -r0, asr #12 */
/* @0x30ca2a .word 0xf7dbaa06 */
/* @0x30ca2e blls 0x4cc75a <SrcVerts+0x2979e> */
/* @0x30ca32 strdlt r6, r7, [r3, #-8] */
/* @0x30ca36 shsaxmi lr, r0, sp */
/* @0x30ca3a mcr2 p7, #0x5, pc, c3, c14, #0x7 */
/* @0x30ca3e ldrtmi lr, [r0], -r2 */
/* @0x30ca42 .word 0xf953f7ff */
/* @0x30ca46 stmdbmi r2, {r3, r4, r5, r6, r7, sp, lr} ^ */
/* @0x30ca4a andhs r4, r7, #40, #12 */
/* @0x30ca4e .word 0xf5a94479 */
/* @0x30ca52 stmdahs r0, {r1, r2, r6, r7, r8, r10, r11, sp, lr, pc} */
/* @0x30ca56 stmibvc r11!, {r0, r4, r6, r8, r12, lr, pc} ^ */
/* @0x30ca5a svceq #0xdff013 */
/* @0x30ca5e stclvs p1, c13, [r3], #40 */
/* @0x30ca62 ldmdbmi r12!, {r3, r5, r9, r10, lr} */
/* @0x30ca66 movwlo r2, #0x120c */
/* @0x30ca6a ldrbtmi r6, [r9], #-1251 */
/* @0x30ca6e ldc p5, c15, [r8, #676]! */
/* @0x30ca72 and r11, r5, r8, ror r9 */
/* @0x30ca76 rscsle r2, r2, sp, lsl #22 */
/* @0x30ca7a blhs 0x35b6a6 */
/* @0x30ca7e .word 0xe7eed83d */
/* @0x30ca82 .word 0xf0137b2b */
/* @0x30ca86 ldrdle r0, r1, [r4], #-255 */
/* @0x30ca8a suble r2, r2, sp, lsl #22 */
/* @0x30ca8e blhs 0x35b6ba */
/* @0x30ca92 ldmdbmi r1!, {r0, r1, r2, r3, r4, r5, r8, r11, r12, lr, pc} */
/* @0x30ca96 andhs r4, r11, #40, #12 */
/* @0x30ca9a .word 0xf5a94479 */
/* @0x30ca9e stmdblt r0, {r5, r7, r8, r10, r11, sp, lr, pc} ^ */
/* @0x30caa2 .word 0xf0137aeb */
/* @0x30caa6 ldrsbtle r0, [r7], -pc */
/* @0x30caaa eorsle r2, r5, sp, lsl #22 */
/* @0x30caae blhs 0x35b6da */
/* @0x30cab2 stmdbmi r10!, {r1, r4, r5, r8, r11, r12, lr, pc} */
/* @0x30cab6 andhs r4, r12, #40, #12 */
/* @0x30caba .word 0xf5a94479 */
/* @0x30cabe stmdblt r0, {r4, r7, r8, r10, r11, sp, lr, pc} ^ */
/* @0x30cac2 .word 0xf0137b2b */
/* @0x30cac6 .word 0xd02a0fdf */
/* @0x30caca eorle r2, r8, sp, lsl #22 */
/* @0x30cace blhs 0x35b6fa */
/* @0x30cad2 stmdbmi r3!, {r0, r2, r5, r8, r11, r12, lr, pc} */
/* @0x30cad6 andhs r4, r7, #40, #12 */
/* @0x30cada .word 0xf5a94479 */
/* @0x30cade stmdblt r0, {r7, r8, r10, r11, sp, lr, pc} ^ */
/* @0x30cae2 .word 0xf01379eb */
/* @0x30cae6 ldrsble r0, [sp], -pc */
/* @0x30caea andsle r2, r11, sp, lsl #22 */
/* @0x30caee blhs 0x35b71a */
/* @0x30caf2 stmdals r6, {r3, r4, r8, r11, r12, lr, pc} */
/* @0x30caf6 pop {r0, r3, r12, sp, pc} */
/* @0x30cafa .word 0xf85a8ff0 */
/* @0x30cafe strbmi r0, [r3], -r9 */
/* @0x30cb02 .word 0xf8d46ce1 */
/* @0x30cb06 .word 0xf7db2080 */
/* @0x30cb0a andls pc, r6, lr, asr #26 */
/* @0x30cb0e adcle r2, r6, r0, lsl #16 */
/* @0x30cb12 ldmvs r11!, {r0, r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x30cb16 strb r6, [r12, r3, ror #4]! */
/* @0x30cb1a adcvs r6, r3, #16449536 */
/* @0x30cb1e ldmvs r11!, {r0, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x30cb22 strb r6, [r6, r3, ror #5]! */
/* @0x30cb26 ldmdblt r3, {r0, r1, r3, r4, r5, r6, r7, r11, sp, lr} */
/* @0x30cb2a movwls r2, #0x6303 */
/* @0x30cb2e ldmdavc r11, {r0, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30cb32 bicseq pc, pc, #3 */
/* @0x30cb36 qaddle r2, r0, r1 */
/* @0x30cb3a and r2, r6, r8, lsl #6 */
/* @0x30cb3e .word 0xd1012b4d */
/* @0x30cb42 and r2, r2, r0, lsl r3 */
/* @0x30cb46 bicsle r2, r4, r3, asr #22 */
/* @0x30cb4a mvnvs r2, r0, lsr #6 */
/* @0x30cb4e stcle p7, c14, [r10], #-836 */
/* @0x30cb52 ldrhs r0, [r11, -sp]! */
/* @0x30cb56 strhs r0, [r5, -r8]! */
/* @0x30cb5a strhs r0, [r4, -r8] */
/* @0x30cb5e ldrbths r0, [r0], r8 */
/* @0x30cb62 strths r0, [r7], r8 */
/* @0x30cb66 ldrlt r0, [r0, #-0x8] */
/* @0x30cb6a stmvs r3, {r4, r5, r7, r8, r12, sp, pc} */
/* @0x30cb6e blhs 0x379202 <_ZTS13C_UTF16String+0x102ae> */
/* @0x30cb72 movwhs sp, #0x1910 */
/* @0x30cb76 addsmi r6, r3, #8519680 */
/* @0x30cb7a stmdavs r1, {r0, r3, r9, r12, lr, pc} */
/* @0x30cb7e addmi pc, r0, #-1073741824 */
/* @0x30cb82 .word 0xf8513a01 */
/* @0x30cb86 movwlo r4, #0x1023 */
/* @0x30cb8a eormi pc, r2, r1, asr #16 */
/* @0x30cb8e blo 0x386b5e <_ZTS13C_UTF16String+0x1dc0a> */
/* @0x30cb92 ldclt p0, c6, [r0, #-520] */
/* @0x30cb96 addvs r2, r3, r0, lsl #6 */
/* @0x30cb9a push {r4, r8, r10, r11, r12, sp, pc} */
/* @0x30cb9e .word 0x46884ff0 */
/* @0x30cba2 ldrmi r4, [r9], r12, lsl #29 */
/* @0x30cba6 adclt r4, r3, r12, lsl #19 */
/* @0x30cbaa ldmdavs r6!, {r1, r2, r3, r4, r5, r6, r10, lr} */
/* @0x30cbae ldrbtmi r2, [r9], #-525 */
/* @0x30cbb2 ldmdavs r3!, {r0, r2, r9, r10, lr} */
/* @0x30cbb6 stcls p6, c4, [r12], #-220 */
/* @0x30cbba .word 0xf5a99321 */
/* @0x30cbbe stmdblt r0, {r4, r8, r10, r11, sp, lr, pc} ^ */
/* @0x30cbc2 .word 0xf0127b6a */
/* @0x30cbc6 ldrsble r0, [lr], -pc */
/* @0x30cbca andsle r2, r12, sp, lsl #20 */
/* @0x30cbce bhs 0x35b3fa */
/* @0x30cbd2 stmibmi r1, {r0, r3, r4, r8, r11, r12, lr, pc} */
/* @0x30cbd6 andshs r4, r5, #40, #12 */
/* @0x30cbda .word 0xf5a94479 */
/* @0x30cbde stmdahs r0, {r8, r10, r11, sp, lr, pc} */
/* @0x30cbe2 stclvc p1, c13, [r10, #-372]! */
/* @0x30cbe6 bicseq pc, pc, #18 */
/* @0x30cbea bhs 0x680c06 <g_SWFlinevertbuff+0x2db3e> */
/* @0x30cbee blo 0x580c06 <g_SWFlineaavertbuff+0x2db3e> */
/* @0x30cbf2 ldmdale r4, {r0, r9, r11, sp} ^ */
/* @0x30cbf6 ldrmi lr, [r8], -r0 */
/* @0x30cbfa ldmdavs r11!, {r0, r5, r9, r11, r12, pc} */
/* @0x30cbfe .word 0xf000429a */
/* @0x30cc02 .word 0xf5a980e4 */
/* @0x30cc06 ldclmi p12, c14, [r5, #-920]! */
/* @0x30cc0a ldrbtmi r6, [sp], #-2592 */
/* @0x30cc0e .word 0xf7ff4629 */
/* @0x30cc12 stmiblt r8, {r7, r8, r11, r12, sp, lr, pc} ^ */
/* @0x30cc16 vmlage.f32 s12, s2, s7 */
/* @0x30cc1a shsub16mi r4, r0, r2 */
/* @0x30cc1e strhhs pc, [r12], -r3 */
/* @0x30cc22 addsvs r4, r10, #2030043136 */
/* @0x30cc26 rfeib r3! */
/* @0x30cc2a .word 0xf5a9200c */
/* @0x30cc2e bvs 0xb47e76 <b2_toiTime+0x3ee9d2> */
/* @0x30cc32 ldrtmi r4, [r2], -r9, lsr #12 */
/* @0x30cc36 ldc2l p7, c15, [r9, #1020]! */
/* @0x30cc3a bicsle r2, sp, r0, lsl #16 */
/* @0x30cc3e andhs r6, r1, #143360 */
/* @0x30cc42 orrhs pc, r8, #12582912 */
/* @0x30cc46 addhs pc, r4, r3, lsr #17 */
/* @0x30cc4a bvs 0xb201ee <b2_toiTime+0x3c6d4a> */
/* @0x30cc4e qsub16mi r4, r9, sp */
/* @0x30cc52 .word 0xf95ff7ff */
/* @0x30cc56 bvs 0xbfb37e <b2_toiTime+0x4a1eda> */
/* @0x30cc5a stmdbmi r3!, {r0, r9, r10, r11, sp, pc} ^ */
/* @0x30cc5e rfeib r3! */
/* @0x30cc62 ldrbtmi r2, [r9], #-14 */
/* @0x30cc66 bvs 0xbe57d6 <b2_toiTime+0x48c332> */
/* @0x30cc6a strhhs pc, [lr], -r3 */
/* @0x30cc6e ldcl p5, c15, [r0], #-676 */
/* @0x30cc72 strtmi r6, [r9], -r0, lsr #20 */
/* @0x30cc76 .word 0xf7ff4632 */
/* @0x30cc7a stmdahs r0, {r3, r4, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x30cc7e bvs 0xc01376 <b2_toiTime+0x4a7ed2> */
/* @0x30cc82 .word 0xf5032201 */
/* @0x30cc86 .word 0xf8a32388 */
/* @0x30cc8a stmdavs r3!, {r2, r7, sp} */
/* @0x30cc8e .word 0xf0232000 */
/* @0x30cc92 eorvs r0, r3, r0, lsl r3 */
/* @0x30cc96 ldrbtmi r4, [r11], #-2902 */
/* @0x30cc9a andlo pc, r0, r9, asr #17 */
/* @0x30cc9e ldmdbmi r4, {r2, r3, r5, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x30cca2 andhs r4, r7, #40, #12 */
/* @0x30cca6 .word 0xf5a94479 */
/* @0x30ccaa stmdblt r8!, {r1, r3, r4, r7, r10, r11, sp, lr, pc} ^ */
/* @0x30ccae .word 0xf01379eb */
/* @0x30ccb2 ldrsble r0, [sp], #-255 */
/* @0x30ccb6 andle r2, r2, sp, lsl #22 */
/* @0x30ccba blhs 0x35b8e6 */
/* @0x30ccbe movwhs sp, #0x804 */
/* @0x30ccc2 andeq pc, r8, #1073741825 */
/* @0x30ccc6 rsb r7, r1, r11, ror #3 */
/* @0x30ccca strtmi r6, [r11], -r1, lsr #20 */
/* @0x30ccce .word 0xf813461e */
/* @0x30ccd2 .word 0xb1222b01 */
/* @0x30ccd6 suble r2, pc, r0, lsr #20 */
/* @0x30ccda mvnsle r2, r9, lsl #20 */
/* @0x30ccde ldrtmi lr, [r2], r12, asr #32 */
/* @0x30cce2 ldmiblo pc!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^ */
/* @0x30cce6 movwhs r11, #0x90d */
/* @0x30ccea stmdavc r11!, {r0, r3, r4, sp, lr, pc} */
/* @0x30ccee rscsle r2, r10, r0, lsl #22 */
/* @0x30ccf2 blhs 0xfe54a0fe <b2_toiTime+0xfffffffffddf0c5a> */
/* @0x30ccf6 .word 0xf10b4628 */
/* @0x30ccfa .word 0xf7d80194 */
/* @0x30ccfe stmdahs r0, {r0, r1, r3, r4, r8, r9, r11, r12, sp, lr, pc} */
/* @0x30cd02 stmdavs r2, {r0, r4, r5, r6, r7, r12, lr, pc} */
/* @0x30cd06 stmdble r5, {r1, r4, r6, r9, r11, sp} */
/* @0x30cd0a addpl pc, r0, #-2147483648 */
/* @0x30cd0e .word 0x308cf8db */
/* @0x30cd12 and r3, r2, r3, asr r10 */
/* @0x30cd16 ldrbtmi r4, [r11], #-2872 */
/* @0x30cd1a bl 0x3d9a22 <error_g0017+0x326c6> */
/* @0x30cd1e .word 0xf1b91302 */
/* @0x30cd22 svclt #0x183fff */
/* @0x30cd26 andls pc, r0, r6, lsl #17 */
/* @0x30cd2a ldmdavs r11, {r0, r1, r4, r8, r12, sp, pc} ^ */
/* @0x30cd2e teqle r2, r1, lsl #22 */
/* @0x30cd32 bl 0x46ae02 <g_RomDisk+0x735e2> */
/* @0x30cd36 tstlt r10, r8, lsl #6 */
/* @0x30cd3a andhs r3, r0, #1048576 */
/* @0x30cd3e andhs pc, r0, r10, lsl #17 */
/* @0x30cd42 .word 0xf8164632 */
/* @0x30cd46 teqlt r1, r1, lsl #22 */
/* @0x30cd4a rscsle r2, r9, r0, lsr #18 */
/* @0x30cd4e rscsle r2, r7, r9, lsl #18 */
/* @0x30cd52 svclt #0x82922 */
/* @0x30cd56 andhs r4, r0, r2, lsr r6 */
/* @0x30cd5a ldmdble r7, {r0, r1, r4, r7, r9, lr} */
/* @0x30cd5e .word 0x1c01f813 */
/* @0x30cd62 .word 0xd1022920 */
/* @0x30cd66 stceq p8, c15, [r1, #-12] */
/* @0x30cd6a stmdbhs r9, {r1, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30cd6e strd sp, lr, [r8], -r10 */
/* @0x30cd72 .word 0xd1a42b00 */
/* @0x30cd76 and r1, r9, r10, ror #27 */
/* @0x30cd7a ldrmi r2, [r1], r0, lsl #6 */
/* @0x30cd7e .word 0x46b27033 */
/* @0x30cd82 stmdbhs r2!, {r4, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30cd86 .word 0x2100d102 */
/* @0x30cd8a .word 0x1c01f803 */
/* @0x30cd8e strtmi r6, [r9], -r0, lsr #20 */
/* @0x30cd92 stc2l p7, c15, [r11, #-1020] */
/* @0x30cd96 .word 0xf504e730 */
/* @0x30cd9a ldmdbmi r7, {r3, r8, r11, r12, sp} */
/* @0x30cd9e strteq pc, [r8], -r9, lsl #2 */
/* @0x30cda2 ldrbtmi r4, [r9], #-1578 */
/* @0x30cda6 ldrtmi r4, [r0], -r3, asr #12 */
/* @0x30cdaa .word 0xffddf7fe */
/* @0x30cdae .word 0xf47f2800 */
/* @0x30cdb2 .word 0xf8d9af23 */
/* @0x30cdb6 ldrtmi r3, [r0], -r8, lsr #32 */
/* @0x30cdba .word 0xf7ff681d */
/* @0x30cdbe .word 0x4630fed4 */
/* @0x30cdc2 .word 0xf7ff4669 */
/* @0x30cdc6 strmi pc, [r2], -r8, lsl #26 */
/* @0x30cdca eorlt lr, r3, r0, ror #15 */
/* @0x30cdce svchi #0xf0e8bd */
/* @0x30cdd2 stceq p15, c11, [r10, #0]! */
/* @0x30cdd6 strhs r0, [r7], -lr */
/* @0x30cdda strbhs r0, [pc, #0x8]! */
/* @0x30cdde ldrhs r0, [r2, #0x8] */
/* @0x30cde2 strhs r0, [r3, #0x8]! */
/* @0x30cde6 ldrbhs r0, [r12, #-0x8] */
/* @0x30cdea strbhs r0, [r1, #-0x8]! */
/* @0x30cdee .word 0x01650008 */
/* @0x30cdf2 strbths r0, [r3], #0 */
/* @0x30cdf6 ldmle r12!, {r3} ^ */
/* @0x30cdfa ldrths r0, [r11], #-13 */
/* @0x30cdfe stmdb sp!, {r3} */
/* @0x30ce02 strdlt r4, r5, [r5], r0 */
/* @0x30ce06 .word 0xf8df468a */
/* @0x30ce0a .word 0x9c0e1730 */
/* @0x30ce0e ldrbtmi r2, [r9], #-519 */
/* @0x30ce12 strmi r2, [r7], -r0, lsl #6 */
/* @0x30ce16 bvs 0xc71a2a <b2_toiTime+0x518586> */
/* @0x30ce1a blhs 0xfe54a236 <b2_toiTime+0xfffffffffddf0d92> */
/* @0x30ce1e .word 0x9088f8db */
/* @0x30ce22 bl 0xffaca4ce <b2_toiTime+0xffffffffff37102a> */
/* @0x30ce26 ldmibvc r11!, {r3, r7, r8, r11, r12, sp, pc} ^ */
/* @0x30ce2a svceq #0xdff013 */
/* @0x30ce2e blhs 0x680f62 <g_SWFlinevertbuff+0x2de9a> */
/* @0x30ce32 bllo 0x580e42 <g_SWFlineaavertbuff+0x2dd7a> */
/* @0x30ce36 stmdale r8, {r0, r8, r9, r11, sp} */
/* @0x30ce3a .word 0x0108f107 */
/* @0x30ce3e andeq pc, r8, #-2147483606 */
/* @0x30ce42 .word 0xf7fe4628 */
/* @0x30ce46 andls pc, r3, r3, lsr #30 */
/* @0x30ce4a .word 0xf8d4e02e */
/* @0x30ce4e .word 0xf0188000 */
/* @0x30ce52 eorsle r0, lr, r0, lsr #30 */
/* @0x30ce56 usatne pc, #0x8, pc, asr #17 */
/* @0x30ce5a andhs r4, r7, #56, #12 */
/* @0x30ce5e .word 0xf5a94479 */
/* @0x30ce62 stmdahs r0, {r1, r2, r3, r4, r5, r7, r8, r9, r11, sp, lr, pc} */
/* @0x30ce66 .word 0xf8dfd047 */
/* @0x30ce6a .word 0x463816d8 */
/* @0x30ce6e ldrbtmi r2, [r9], #-519 */
/* @0x30ce72 bl 0xff0ca51e <b2_toiTime+0xfffffffffe97107a> */
/* @0x30ce76 ldmibvc r11!, {r3, r4, r6, r8, r11, r12, sp, pc} ^ */
/* @0x30ce7a svceq #0xdff013 */
/* @0x30ce7e addshi pc, r2, r0 */
/* @0x30ce82 .word 0xf0002b0d */
/* @0x30ce86 bllo 0x56d0ca <g_SWFlineaavertbuff+0x1a002> */
/* @0x30ce8a .word 0xf2402b01 */
/* @0x30ce8e .word 0xf018808b */
/* @0x30ce92 .word 0xf0000640 */
/* @0x30ce96 stmibvs r3!, {r2, r3, r7, pc} ^ */
/* @0x30ce9a .word 0xf0403301 */
/* @0x30ce9e bvs 0x1bed0c6 <b2_toiTime+0x1493c22> */
/* @0x30cea2 blhs 0x327016 */
/* @0x30cea6 addhi pc, r3, r0, asr #32 */
/* @0x30ceaa .word 0xb1439b03 */
/* @0x30ceae ldrbeq r6, [lr], -r3, lsr #16 */
/* @0x30ceb2 strbmi sp, [r8], -r5, lsl #10 */
/* @0x30ceb6 .word 0xf7da69a1 */
/* @0x30ceba movwhs pc, #0xa3d */
/* @0x30cebe stmdals r3, {r0, r1, r5, r7, r8, sp, lr} */
/* @0x30cec2 pop {r0, r2, r12, sp, pc} */
/* @0x30cec6 blhs 0x330e8e */
/* @0x30ceca .word 0xf1aad1b6 */
/* @0x30cece ldclne p2, c0, [r9, #28]! */
/* @0x30ced2 .word 0xf8dfe7b6 */
/* @0x30ced6 shsub16mi r1, r8, r0 */
/* @0x30ceda ldrbtmi r2, [r9], #-517 */
/* @0x30cede bl 0xfe34a58a <b2_toiTime+0xfffffffffdbf10e6> */
/* @0x30cee2 ldmdbvc r11!, {r3, r4, r7, r8, r11, r12, sp, pc} ^ */
/* @0x30cee6 svceq #0xdff013 */
/* @0x30ceea blhs 0x680f3a <g_SWFlinevertbuff+0x2de72> */
/* @0x30ceee bllo 0x580f36 <g_SWFlineaavertbuff+0x2de6e> */
/* @0x30cef2 stmdale r10, {r0, r8, r9, r11, sp} */
/* @0x30cef6 ldmibvc r11!, {r2, r3, sp, lr, pc} ^ */
/* @0x30cefa svceq #0xdff013 */
/* @0x30cefe blhs 0x68103a <g_SWFlinevertbuff+0x2df72> */
/* @0x30cf02 bllo 0x581036 <g_SWFlineaavertbuff+0x2df6e> */
/* @0x30cf06 stmle lr!, {r0, r8, r9, r11, sp} */
/* @0x30cf0a .word 0x23b4e047 */
/* @0x30cf0e strb r9, [r11, r3, lsl #6] */
/* @0x30cf12 .word 0x1638f8df */
/* @0x30cf16 strlo pc, [r8], -r4, lsl #10 */
/* @0x30cf1a eoreq pc, r8, r6, lsl #2 */
/* @0x30cf1e ldrbtmi r4, [r9], #-1594 */
/* @0x30cf22 .word 0xf7fe4653 */
/* @0x30cf26 andls pc, r3, r0, lsr #30 */
/* @0x30cf2a .word 0xd1bd2800 */
/* @0x30cf2e ldmdavs r8, {r0, r1, r4, r5, r7, r9, r11, sp, lr} ^ */
/* @0x30cf32 mrc2 p7, #0x6, apsr_nzcv, c11, c14, #0x7 */
/* @0x30cf36 .word 0x63282114 */
/* @0x30cf3a rsbvs r4, r0, r7, lsl #12 */
/* @0x30cf3e .word 0xf00b6bf0 */
/* @0x30cf42 addmi lr, r7, #2080 */
/* @0x30cf46 .word 0x6328bf84 */
/* @0x30cf4a stmdavs r3!, {r5, r6, sp, lr} ^ */
/* @0x30cf4e movths r11, #0x90b */
/* @0x30cf52 stmdavs r3!, {r0, r1, r3, r5, r8, r9, sp, lr} ^ */
/* @0x30cf56 svcne #0x88f5b3 */
/* @0x30cf5a movwhs sp, #0x6301 */
/* @0x30cf5e andhs lr, r0, #56098816 */
/* @0x30cf62 andls r10, r0, #3072 */
/* @0x30cf66 movwls r4, #0x1648 */
/* @0x30cf6a blvs 0xdd5402 <b2_toiTime+0x67bf5e> */
/* @0x30cf6e .word 0xf88ef7db */
/* @0x30cf72 .word 0x63a89b03 */
/* @0x30cf76 orrsle r2, r7, r0, lsl #22 */
/* @0x30cf7a .word 0xf0436823 */
/* @0x30cf7e and r0, r10, r0, lsr #6 */
/* @0x30cf82 strblo pc, [r12, #0x8df] */
/* @0x30cf86 blvs 0xfed1581e <b2_toiTime+0xfffffffffe5bc37a> */
/* @0x30cf8a blvs 0x1d5e17e <b2_toiTime+0x1604cda> */
/* @0x30cf8e bl 0xfecca63a <b2_toiTime+0xfffffffffe571196> */
/* @0x30cf92 .word 0xf0236823 */
/* @0x30cf96 eorvs r0, r3, r1, lsl #6 */
/* @0x30cf9a .word 0xf418e786 */
/* @0x30cf9e rscle r6, pc, r12, ror pc */
/* @0x30cfa2 .word 0xe7b323ba */
/* @0x30cfa6 mvnvs r2, r0, lsl #6 */
/* @0x30cfaa cmnvs r12, #40, #8 */
/* @0x30cfae .word 0xf8dfe7f3 */
/* @0x30cfb2 ldrtmi r1, [r8], -r0, lsr #11 */
/* @0x30cfb6 ldrbtmi r2, [r9], #-521 */
/* @0x30cfba bl 0x7ca666 <b2_toiTime+0x711c2> */
/* @0x30cfbe bvc 0x21fb4c6 <b2_toiTime+0x1aa2022> */
/* @0x30cfc2 svceq #0xdff013 */
/* @0x30cfc6 blhs 0x681032 <g_SWFlinevertbuff+0x2df6a> */
/* @0x30cfca bllo 0x58102e <g_SWFlineaavertbuff+0x2df66> */
/* @0x30cfce ldmdble r4, {r0, r8, r9, r11, sp} */
/* @0x30cfd2 strne pc, [r4, #0x8df] */
/* @0x30cfd6 andhs r4, r8, #56, #12 */
/* @0x30cfda .word 0xf5a94479 */
/* @0x30cfde stmdahs r0, {r8, r9, r11, sp, lr, pc} */
/* @0x30cfe2 rschi pc, r5, r0, asr #32 */
/* @0x30cfe6 .word 0xf0137a3b */
/* @0x30cfea ldrdle r0, r1, [r3], #-255 */
/* @0x30cfee suble r2, r1, sp, lsl #22 */
/* @0x30cff2 blhs 0x35bc1e */
/* @0x30cff6 sbcshi pc, r11, r0, lsl #4 */
/* @0x30cffa .word 0xf418e03c */
/* @0x30cffe andle r6, r1, r12, ror r5 */
/* @0x30d002 .word 0xe78323b5 */
/* @0x30d006 stmibvs r1!, {r3, r6, r9, r10, lr} */
/* @0x30d00a strlo pc, [r8], -r4, lsl #10 */
/* @0x30d00e .word 0xf992f7da */
/* @0x30d012 .word 0xf8df3628 */
/* @0x30d016 .word 0x61a51544 */
/* @0x30d01a shasxmi r4, r0, r10 */
/* @0x30d01e usub16mi r4, r3, r9 */
/* @0x30d022 mcr2 p7, #0x5, pc, c1, c14, #0x7 */
/* @0x30d026 andls r4, r3, r5, lsl #12 */
/* @0x30d02a .word 0xf47f2800 */
/* @0x30d02e shasxmi r10, r0, sp */
/* @0x30d032 ldc2 p7, c15, [r9, #1020] */
/* @0x30d036 stmdbge r2, {r4, r5, r9, r10, lr} */
/* @0x30d03a blx 0xff68b040 <b2_toiTime+0xfffffffffef31b9c> */
/* @0x30d03e stmdahs r0, {r1, r2, r9, r10, lr} */
/* @0x30d042 subhi pc, lr, #0 */
/* @0x30d046 movwls r10, #0x1b03 */
/* @0x30d04a .word 0x21019b02 */
/* @0x30d04e strbmi r9, [r8], -r0, lsl #10 */
/* @0x30d052 strtmi r4, [r10], -r11, lsl #8 */
/* @0x30d056 .word 0xf81af7db */
/* @0x30d05a lslvs r9, r3, #22 */
/* @0x30d05e .word 0xf47f2b00 */
/* @0x30d062 bls 0x3b8cf6 <error_g0017+0x1199a> */
/* @0x30d066 andlo r4, r1, #51380224 */
/* @0x30d06a b 0xfed4a716 <b2_toiTime+0xfffffffffe5f1272> */
/* @0x30d06e .word 0xf0436823 */
/* @0x30d072 ldr r0, [r0, r0, asr #6] */
/* @0x30d076 sbcle r2, r3, r0, lsl #28 */
/* @0x30d07a strbtne pc, [r4], #2271 */
/* @0x30d07e strlo pc, [r8], -r4, lsl #10 */
/* @0x30d082 eoreq pc, r8, r6, lsl #2 */
/* @0x30d086 ldrbtmi r4, [r9], #-1594 */
/* @0x30d08a .word 0xf7fe4653 */
/* @0x30d08e andls pc, r3, r12, ror #28 */
/* @0x30d092 .word 0xf47f2800 */
/* @0x30d096 bvs 0xff0f8cc2 <b2_toiTime+0xfffffffffe99f81e> */
/* @0x30d09a .word 0xf7fe6878 */
/* @0x30d09e .word 0x1c42fb72 */
/* @0x30d0a2 mvnvs r11, lr, lsr #31 */
/* @0x30d0a6 .word 0x33fff04f */
/* @0x30d0aa stmibvs r3!, {r0, r1, r5, r6, r7, r8, sp, lr} ^ */
/* @0x30d0ae .word 0xd1063301 */
/* @0x30d0b2 blhs 0x3a7d86 <error_g0017+0xa2a> */
/* @0x30d0b6 ldmvs r8!, {r0, r1, r8, r11, r12, lr, pc} */
/* @0x30d0ba blx 0x1c0b0bc <b2_toiTime+0x14b1c18> */
/* @0x30d0be stmibvs r3!, {r5, r6, r7, r8, sp, lr} ^ */
/* @0x30d0c2 svclt #0xbc3301 */
/* @0x30d0c6 .word 0x33fff04f */
/* @0x30d0ca stmibvs r3!, {r0, r1, r5, r6, r7, r8, sp, lr} ^ */
/* @0x30d0ce svcne #0x88f5b3 */
/* @0x30d0d2 andhi pc, r6, #128, #4 */
/* @0x30d0d6 blle 0x897cde <b2_toiTime+0x13e83a> */
/* @0x30d0da .word 0xf003115a */
/* @0x30d0de bl 0x40dd62 <g_RomDisk+0x16542> */
/* @0x30d0e2 bvs 0xfe74daf2 <b2_toiTime+0xfffffffffdff464e> */
/* @0x30d0e6 .word 0xf003fa21 */
/* @0x30d0ea svceq #0x1f010 */
/* @0x30d0ee andeq pc, r1, pc, asr #32 */
/* @0x30d0f2 .word 0xf04fd005 */
/* @0x30d0f6 strdvs r3, r4, [r3, #63]! */
/* @0x30d0fa addeq pc, r4, r11, lsr #17 */
/* @0x30d0fe blx 0x345112 */
/* @0x30d102 tstmi r9, #201326592 */
/* @0x30d106 stmibvs r3!, {r0, r4, r7, r9, sp, lr} ^ */
/* @0x30d10a blle 0xb17d12 <b2_toiTime+0x3be86e> */
/* @0x30d10e blvs 0xde7ebe <b2_toiTime+0x68ea1a> */
/* @0x30d112 .word 0xd111429a */
/* @0x30d116 strbmi r6, [r8], -r11, lsr #23 */
/* @0x30d11a movwls r2, #0x124 */
/* @0x30d11e movwls r10, #0x1b03 */
/* @0x30d122 movteq pc, #0x102 */
/* @0x30d126 .word 0xffb2f7da */
/* @0x30d12a .word 0x63a89b03 */
/* @0x30d12e .word 0xf47f2b00 */
/* @0x30d132 blvs 0xdf8c26 <b2_toiTime+0x69f782> */
/* @0x30d136 .word 0x632b3340 */
/* @0x30d13a blvs 0xfeda7eee <b2_toiTime+0xfffffffffe64ea4a> */
/* @0x30d13e .word 0x63691c59 */
/* @0x30d142 movtmi r2, #0xb124 */
/* @0x30d146 ldmne r0, {r0, r5, r7, r8, r11, sp, lr} ^ */
/* @0x30d14a stmibvs r3!, {r0, r4, r6, r7, r12, lr} ^ */
/* @0x30d14e bvs 0x1c051da <b2_toiTime+0x14abd36> */
/* @0x30d152 movwlt r6, #0x385b */
/* @0x30d156 blvs 0xffde8206 <b2_toiTime+0xffffffffff68ed62> */
/* @0x30d15a .word 0xd110429a */
/* @0x30d15e strbmi r6, [r8], -r11, ror #24 */
/* @0x30d162 movwls r2, #0x124 */
/* @0x30d166 movwls r10, #0x1b03 */
/* @0x30d16a .word 0xf7da1d13 */
/* @0x30d16e blls 0x40cfb2 <g_RomDisk+0x15792> */
/* @0x30d172 blhs 0x32631a */
/* @0x30d176 mrcge p4, #0x4, apsr_nzcv, c8, c15, #0x3 */
/* @0x30d17a movwlo r6, #0x4beb */
/* @0x30d17e stcvs p3, c6, [r11], #-940 */
/* @0x30d182 stmibvs r1!, {r2, r5, r9, sp} */
/* @0x30d186 stclvs p3, c4, [r10], #-332 */
/* @0x30d18a ldrsbpl r1, [r1], #128 */
/* @0x30d18e mrrcne p12, #0x2, r6, r10, c11 */
/* @0x30d192 subvs r6, r3, r10, lsr #8 */
/* @0x30d196 strbmi lr, [r8], -r3 */
/* @0x30d19a .word 0xf7da69a1 */
/* @0x30d19e movwhs pc, #0x8cb */
/* @0x30d1a2 stmdavs r3!, {r0, r1, r5, r7, r8, sp, lr} */
/* @0x30d1a6 movtmi pc, #0x23 */
/* @0x30d1aa orreq pc, r0, #67 */
/* @0x30d1ae stmibvs r3!, {r0, r1, r4, r5, r6, r7, r9, r10, sp, lr, pc} ^ */
/* @0x30d1b2 .word 0xf04f3301 */
/* @0x30d1b6 .word 0xd1040324 */
/* @0x30d1ba stclvs p12, c6, [r10], #-184 */
/* @0x30d1be mcrlo p3, #0x1, r4, c4, c14, #0x2 */
/* @0x30d1c2 blvs 0x1ec51d6 <b2_toiTime+0x176bd32> */
/* @0x30d1c6 cmpmi lr, #174080 */
/* @0x30d1ca .word 0xf4183e24 */
/* @0x30d1ce ldrmi r6, [r6], #-3840 */
/* @0x30d1d2 stmvs r0!, {r2, r3, r5, r6, r12, lr, pc} */
/* @0x30d1d6 addsmi r8, r8, #3981312 */
/* @0x30d1da .word 0xf1b8d30a */
/* @0x30d1de .word 0xf6ff0f00 */
/* @0x30d1e2 .word 0xf048ae63 */
/* @0x30d1e6 eorvs r4, r3, r0, lsl #6 */
/* @0x30d1ea .word 0xf8ab2301 */
/* @0x30d1ee ldrb r3, [r11], -r4, lsl #1 */
/* @0x30d1f2 ldmibvs r2!, {r0, r1, r4, r5, r6, r7, r8, r11, sp, lr} */
/* @0x30d1f6 ldrsbeq r4, [r9], #-219 */
/* @0x30d1fa andhs pc, r3, #0, #22 */
/* @0x30d1fe movwhs r4, #0x47d */
/* @0x30d202 addmi r4, r11, #156, #12 */
/* @0x30d206 ldclpl p0, c13, [r8], #144 */
/* @0x30d20a ldmeq r0, {r0, r2, r8, r9, r11, sp, lr, pc} ^ */
/* @0x30d20e umlalge pc, r1, r8, r8 */
/* @0x30d212 stmdaeq r7, {r12, sp, lr, pc} */
/* @0x30d216 .word 0xf808fa4a */
/* @0x30d21a svceq #0x1f018 */
/* @0x30d21e .word 0xf892d00f */
/* @0x30d222 stcpl p0, c8, [r8], #-0 */
/* @0x30d226 andne lr, r8, r0, lsl #22 */
/* @0x30d22a mrrcne p0, #0x1, r7, r8, c0 */
/* @0x30d22e andle r4, r4, #136, #4 */
/* @0x30d232 svclt #0x4407db */
/* @0x30d236 andgt pc, r1, r2, lsl #17 */
/* @0x30d23a strmi r3, [r3], -r1, lsl #4 */
/* @0x30d23e stmdavs r0!, {r0, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30d242 strle r0, [r5], #-69 */
/* @0x30d246 addmi pc, r0, r0, asr #32 */
/* @0x30d24a andhs r6, r1, r0, lsr #32 */
/* @0x30d24e addeq pc, r4, r11, lsr #17 */
/* @0x30d252 ldmibhi r5!, {r5, r9, r11, sp, lr} */
/* @0x30d256 addhs pc, r8, r0, lsl #10 */
/* @0x30d25a strheq pc, [r6], r0 */
/* @0x30d25e movtmi r11, #0x5155 */
/* @0x30d262 ldmdavc r6, {r0, r6, r7, r11, lr} */
/* @0x30d266 .word 0xf0054478 */
/* @0x30d26a strmi r0, [r5], #-1287 */
/* @0x30d26e smulleq pc, r1, r5, r8 */
/* @0x30d272 andsvc r4, r0, r0, lsr r0 */
/* @0x30d276 tstle r5, r11, lsl #5 */
/* @0x30d27a bmi 0xff1e466e <b2_toiTime+0xfffffffffea8b1ca> */
/* @0x30d27e bl 0x39e46e <t1_expert_encoding+0x8c> */
/* @0x30d282 .word 0xf00302d3 */
/* @0x30d286 .word 0xf8920307 */
/* @0x30d28a blx 0x1395516 <b2_toiTime+0xc3c072> */
/* @0x30d28e ldrbeq pc, [r9, r3, lsl #6] */
/* @0x30d292 stmdavs r3!, {r3, r8, r10, r12, lr, pc} */
/* @0x30d296 strle r0, [r5], #-90 */
/* @0x30d29a orrmi pc, r0, #67 */
/* @0x30d29e movwhs r6, #0x1023 */
/* @0x30d2a2 addlo pc, r4, r11, lsr #17 */
/* @0x30d2a6 movwlo r6, #0x18a3 */
/* @0x30d2aa ldrb r6, [sp, #0xa3]! */
/* @0x30d2ae .word 0x463849b0 */
/* @0x30d2b2 ldrbtmi r2, [r9], #-518 */
/* @0x30d2b6 ldmib r4, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x30d2ba ldmibvc r11!, {r6, r8, r11, r12, sp, pc} */
/* @0x30d2be svceq #0xdff013 */
/* @0x30d2c2 blhs 0x68131e <g_SWFlinevertbuff+0x2e256> */
/* @0x30d2c6 bllo 0x58131a <g_SWFlineaavertbuff+0x2e252> */
/* @0x30d2ca ldmdble r0, {r0, r8, r9, r11, sp} */
/* @0x30d2ce ldrtmi r4, [r8], -r9, lsr #19 */
/* @0x30d2d2 ldrbtmi r2, [r9], #-518 */
/* @0x30d2d6 stmib r4, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x30d2da ldmibvc r11!, {r6, r8, r9, r11, r12, sp, pc} */
/* @0x30d2de svceq #0xdff013 */
/* @0x30d2e2 blhs 0x681366 <g_SWFlinevertbuff+0x2e29e> */
/* @0x30d2e6 bllo 0x581362 <g_SWFlineaavertbuff+0x2e29a> */
/* @0x30d2ea ldmdale pc, {r0, r8, r9, r11, sp} */
/* @0x30d2ee .word 0xf018e019 */
/* @0x30d2f2 andsle r0, r9, r0, lsl #31 */
/* @0x30d2f6 .word 0xf50449a0 */
/* @0x30d2fa .word 0xf1053508 */
/* @0x30d2fe ldrtmi r0, [r10], -r8, lsr #32 */
/* @0x30d302 usub16mi r4, r3, r9 */
/* @0x30d306 stc2 p7, c15, [pc, #-1016]! */
/* @0x30d30a stmdahs r0, {r0, r1, r12, pc} */
/* @0x30d30e stclge p4, c15, [r12, #508] */
/* @0x30d312 ldmdavs r8, {r0, r1, r3, r5, r7, r9, r11, sp, lr} ^ */
/* @0x30d316 stc2l p7, c15, [r9], #1016 */
/* @0x30d31a stmdavs r3!, {r4, r5, r8, pc} */
/* @0x30d31e orrvc pc, r0, #1124073472 */
/* @0x30d322 .word 0xf018e639 */
/* @0x30d326 tstle r5, r0, lsl #31 */
/* @0x30d32a strb r2, [pc, #0x3b6]! */
/* @0x30d32e shadd8mi r4, r8, r3 */
/* @0x30d332 ldrbtmi r2, [r9], #-515 */
/* @0x30d336 ldmdb r4, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x30d33a .word 0xf0402800 */
/* @0x30d33e ldmvc r11!, {r0, r6, r7, pc} ^ */
/* @0x30d342 svceq #0xdff013 */
/* @0x30d346 blhs 0x6813f2 <g_SWFlinevertbuff+0x2e32a> */
/* @0x30d34a bllo 0x5813ee <g_SWFlineaavertbuff+0x2e326> */
/* @0x30d34e .word 0xf2002b01 */
/* @0x30d352 strht r8, [r2], -r7 */
/* @0x30d356 .word 0xf504498a */
/* @0x30d35a .word 0xf1083808 */
/* @0x30d35e ldrtmi r0, [r10], -r8, lsr #32 */
/* @0x30d362 usub16mi r4, r3, r9 */
/* @0x30d366 ldc2l p7, c15, [pc], #1016 */
/* @0x30d36a stmdahs r0, {r0, r1, r12, pc} */
/* @0x30d36e ldcge p4, c15, [r12, #508] */
/* @0x30d372 .word 0x3028f8d8 */
/* @0x30d376 .word 0xf7fe6858 */
/* @0x30d37a ldrhhi pc, [r0, #-200]! */
/* @0x30d37e ldrbeq r6, [r11, #0x823] */
/* @0x30d382 stmdbvs r11!, {r0, r1, r2, r10, r12, lr, pc} ^ */
/* @0x30d386 stmdbvs r10!, {r7, r9, r12, sp, pc} */
/* @0x30d38a cmpmi r10, #1753088 */
/* @0x30d38e ldc2l p7, c15, [r5], {215} */
/* @0x30d392 stmdavs r3!, {r4, r5, r8, pc} */
/* @0x30d396 movwvc pc, #0x443 */
/* @0x30d39a .word 0xf018e5fd */
/* @0x30d39e sbcle r0, r3, r0, lsl #31 */
/* @0x30d3a2 .word 0xf5044978 */
/* @0x30d3a6 .word 0xf1083808 */
/* @0x30d3aa ldrtmi r0, [r10], -r8, lsr #32 */
/* @0x30d3ae usub16mi r4, r3, r9 */
/* @0x30d3b2 ldc2l p7, c15, [r9], {254} */
/* @0x30d3b6 stmdahs r0, {r0, r1, r12, pc} */
/* @0x30d3ba ldclge p4, c15, [r6, #-508]! */
/* @0x30d3be .word 0x3028f8d8 */
/* @0x30d3c2 .word 0xf7fe6858 */
/* @0x30d3c6 ldrhhi pc, [r0, r0]! */
/* @0x30d3ca .word 0x3028f8d8 */
/* @0x30d3ce .word 0xf7fe6898 */
/* @0x30d3d2 mvnshi pc, r10, lsr #25 */
/* @0x30d3d6 .word 0xf8d84607 */
/* @0x30d3da ldmvs r8, {r3, r5, r12, sp} ^ */
/* @0x30d3de .word 0xf9f9f7fe */
/* @0x30d3e2 .word 0xf8d88230 */
/* @0x30d3e6 ldmdbvs r8, {r3, r5, r12, sp} */
/* @0x30d3ea .word 0xf9f3f7fe */
/* @0x30d3ee addlt r8, r0, #112, #4 */
/* @0x30d3f2 submi r4, r0, #117440512 */
/* @0x30d3f6 adcslt r8, pc, #240, #4 */
/* @0x30d3fa rfeib r4! */
/* @0x30d3fe eorslt r3, pc, #18 */
/* @0x30d402 svclt #0xb8429f */
/* @0x30d406 rfeib r4! */
/* @0x30d40a rsbhi r3, r7, #20 */
/* @0x30d40e ldrhhs pc, [r6], -r6 */
/* @0x30d412 svclt #0xa8429a */
/* @0x30d416 adchi r4, r3, #19922944 */
/* @0x30d41a ldmibhi r3!, {r1, r4, r5, r9, r11, pc} */
/* @0x30d41e rfeib r4! */
/* @0x30d422 addslt r2, r11, #16 */
/* @0x30d426 andslt r8, r11, #805306382 */
/* @0x30d42a svclt #0xb84293 */
/* @0x30d42e eorhi r4, r3, #19922944 */
/* @0x30d432 strhlo pc, [r12], -r4 */
/* @0x30d436 ldrhhs pc, [r0], -r6 */
/* @0x30d43a svclt #0xb8429a */
/* @0x30d43e .word 0x81a34613 */
/* @0x30d442 strhlo pc, [lr], -r4 */
/* @0x30d446 ldrhhs pc, [r0], -r6 */
/* @0x30d44a svclt #0xa8429a */
/* @0x30d44e mvnhi r4, r3, lsl r6 */
/* @0x30d452 ldreq r6, [pc, #0x823] */
/* @0x30d456 ldmibhi r3!, {r2, r3, r4, r6, r8, r9, r10, r11, r12, sp, pc} */
/* @0x30d45a bvs 0x1beda2e <b2_toiTime+0x149458a> */
/* @0x30d45e cmplt r11, #1769472 */
/* @0x30d462 stmdbvs r10!, {r0, r1, r3, r5, r6, r8, r11, sp, lr} */
/* @0x30d466 ldmdbmi r3!, {r4, r5, r6, r8, r11, pc} */
/* @0x30d46a .word 0xf7d7435a */
/* @0x30d46e ldmdbhi r3!, {r1, r2, r5, r6, r10, r11, r12, sp, lr, pc} */
/* @0x30d472 addmi r11, r3, #128, #4 */
/* @0x30d476 teqhi r0, r0, lsr #32 */
/* @0x30d47a movwlo r6, #0x19e3 */
/* @0x30d47e stcvs p1, c13, [r11], #-28 */
/* @0x30d482 ldmdbeq r10, {r0, r8, r9, r11, r12, sp} ^ */
/* @0x30d486 streq lr, [r2, #0xb05] */
/* @0x30d48a strlo pc, [r8, #-0x505] */
/* @0x30d48e ldmdavs r3!, {r0, r1, sp, lr, pc} ^ */
/* @0x30d492 bl 0x451a02 <g_RomDisk+0x5a1e2> */
/* @0x30d496 andhs r0, r1, #545259520 */
/* @0x30d49a tsteq pc, #3 */
/* @0x30d49e vpmax.u8 d15, d3, d2 */
/* @0x30d4a2 .word 0x2084f8d5 */
/* @0x30d4a6 .word 0xf8c5431a */
/* @0x30d4aa stmdavs r3!, {r2, r7, sp} */
/* @0x30d4ae orrpl pc, r0, #1124073472 */
/* @0x30d4b2 movwhs r6, #0x1023 */
/* @0x30d4b6 addlo pc, r4, r11, lsr #17 */
/* @0x30d4ba vst2.8 {d22, d23}, [r3:128], r3 */
/* @0x30d4be strb r6, [r10, #-0x380]! */
/* @0x30d4c2 shasxmi r4, r8, r1 */
/* @0x30d4c6 ldrbtmi r2, [r9], #-518 */
/* @0x30d4ca stm r10, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x30d4ce ldmibvc r11!, {r6, r8, r11, r12, sp, pc} */
/* @0x30d4d2 svceq #0xdff013 */
/* @0x30d4d6 blhs 0x6814f6 <g_SWFlinevertbuff+0x2e42e> */
/* @0x30d4da bllo 0x5814f2 <g_SWFlineaavertbuff+0x2e42a> */
/* @0x30d4de stmdble r1, {r0, r8, r9, r11, sp} */
/* @0x30d4e2 ldr r2, [r3, #-0x303] */
/* @0x30d4e6 svcvs #0x80f418 */
/* @0x30d4ea .word 0x23b7d101 */
/* @0x30d4ee rfeia r11! */
/* @0x30d4f2 ldmibhi r3!, {r1, r2, r7, sp} */
/* @0x30d4f6 cmpmi r3, #3948544 */
/* @0x30d4fa rscsvc pc, pc, #82837504 */
/* @0x30d4fe sbcsne r3, r11, r7, lsl #6 */
/* @0x30d502 addsmi r6, r3, #-1073741764 */
/* @0x30d506 movtmi sp, #0xb802 */
/* @0x30d50a stmdble r1, {r0, r1, r4, r7, r9, lr} */
/* @0x30d50e ldrbt r2, [sp], #952 */
/* @0x30d512 andhs r8, r0, #855638016 */
/* @0x30d516 andls r10, r0, #49152 */
/* @0x30d51a strbmi r9, [r8], -r1, lsl #2 */
/* @0x30d51e .word 0xf7da2101 */
/* @0x30d522 blls 0x40cbfe <g_RomDisk+0x153de> */
/* @0x30d526 blhs 0x325bee */
/* @0x30d52a ldcge p4, c15, [lr], #508 */
/* @0x30d52e stmdavs r3!, {r0, r1, r5, r7, sp, lr} */
/* @0x30d532 movwvs pc, #0x443 */
/* @0x30d536 stmdbne r0, {r0, r1, r2, r3, r5, r8, r10, sp, lr, pc} ^ */
/* @0x30d53a cmnhs r9, #1 */
/* @0x30d53e orrhs r0, r10, #8 */
/* @0x30d542 orrshs r0, r1, #8 */
/* @0x30d546 movwhs r0, #0x6008 */
/* @0x30d54a adcshs r0, pc, #8 */
/* @0x30d54e ldm pc, {r3} */
/* @0x30d552 eorshs pc, r8, #1020 */
/* @0x30d556 eorhs r0, pc, #8 */
/* @0x30d55a bichs r0, r1, r8 */
/* @0x30d55e cmphs r7, r8 */
/* @0x30d562 strbvs r0, [lr, #-0x8] */
/* @0x30d566 strbtvs r0, [r6], #9 */
/* @0x30d56a strbvs r0, [lr], #9 */
/* @0x30d56e svcne #0x460009 */
/* @0x30d572 svcne #0x3e0008 */
/* @0x30d576 cdpne p0, #0xd, c0, c13, c8, #0x0 */
/* @0x30d57a cdpne p0, #0xe, c0, c5, c8, #0x0 */
/* @0x30d57e cdpne p0, #0x7, c0, c13, c8, #0x0 */
/* @0x30d582 cdpne p0, #0x3, c0, c1, c8, #0x0 */
/* @0x30d586 ldclne p0, c0, [r5, #-32] */
/* @0x30d58a stmdb sp!, {r3} */
/* @0x30d58e .word 0x469a4ff0 */
/* @0x30d592 blmi 0xff2798ce <b2_toiTime+0xfffffffffeb2042a> */
/* @0x30d596 strmi r10, [r3], r6, lsl #26 */
/* @0x30d59a ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x30d59e .word 0x460f9c56 */
/* @0x30d5a2 ldmdavs r10, {r0, r1, r8, r9, r12, pc} */
/* @0x30d5a6 subls r6, r11, #155648 */
/* @0x30d5aa eorvs r2, r10, r0, lsl #4 */
/* @0x30d5ae .word 0xf506b126 */
/* @0x30d5b2 .word 0xf8d32388 */
/* @0x30d5b6 and r9, r0, r8, lsl #1 */
/* @0x30d5ba ldmibmi r4!, {r0, r4, r5, r7, r9, r10, lr} */
/* @0x30d5be andhs r4, r7, #88, #12 */
/* @0x30d5c2 .word 0xf5a94479 */
/* @0x30d5c6 ldmdblt r0, {r2, r3, r11, sp, lr, pc} ^ */
/* @0x30d5ca mullo r7, r11, r8 */
/* @0x30d5ce svceq #0xdff013 */
/* @0x30d5d2 blhs 0x6816ae <g_SWFlinevertbuff+0x2e5e6> */
/* @0x30d5d6 .word 0xf1a3d033 */
/* @0x30d5da bhs 0x34de06 */
/* @0x30d5de .word 0xf8d4d92f */
/* @0x30d5e2 .word 0xf0188000 */
/* @0x30d5e6 tstle r5, r1, lsl #30 */
/* @0x30d5ea .word 0xf50449aa */
/* @0x30d5ee ldrbmi r3, [r8], -r8, lsl #14 */
/* @0x30d5f2 ldrbtmi r2, [r9], #-521 */
/* @0x30d5f6 .word 0xf5a86bbe */
/* @0x30d5fa stmdahs r0, {r1, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr, pc} */
/* @0x30d5fe .word 0xf89bd164 */
/* @0x30d602 .word 0xf0133009 */
/* @0x30d606 .word 0xd02e0fdf */
/* @0x30d60a eorle r2, r12, sp, lsl #22 */
/* @0x30d60e blhs 0x35c23a */
/* @0x30d612 eor sp, r8, r10, asr r8 */
/* @0x30d616 ldrbmi r4, [r8], -r0, lsr #19 */
/* @0x30d61a ldrbtmi r2, [r9], #-527 */
/* @0x30d61e svc #0xe0f5a8 */
/* @0x30d622 .word 0xf0402800 */
/* @0x30d626 .word 0xf89b80ad */
/* @0x30d62a .word 0xf013300f */
/* @0x30d62e .word 0xd06e0fdf */
/* @0x30d632 rsble r2, r12, sp, lsl #22 */
/* @0x30d636 blhs 0x35c262 */
/* @0x30d63a adchi pc, r2, r0, lsl #4 */
/* @0x30d63e bvs 0x1bc57e2 <b2_toiTime+0x146c33e> */
/* @0x30d642 bhs 0x327892 */
/* @0x30d646 mcrhs p0, #0x0, sp, c0, c7, #0x1 */
/* @0x30d64a ldmdblt r11, {r0, r2, r4, r5, r12, lr, pc} */
/* @0x30d64e .word 0xf10b1ffa */
/* @0x30d652 and r0, r3, r7, lsl #2 */
/* @0x30d656 .word 0x0108f10b */
/* @0x30d65a andeq pc, r8, #-1073741783 */
/* @0x30d65e .word 0xf7fe4630 */
/* @0x30d662 eorvs pc, r8, r5, lsl r11 */
/* @0x30d666 movwhs lr, #0x1027 */
/* @0x30d66a eorvs r4, r3, r0, lsr r6 */
/* @0x30d66e movwhs r4, #0x62a */
/* @0x30d672 eorvs r4, r3, #2179072 */
/* @0x30d676 ldc2l p7, c15, [r6, #-868] */
/* @0x30d67a stmiblt r3!, {r0, r1, r3, r5, r11, sp, lr} ^ */
/* @0x30d67e .word 0xf5006220 */
/* @0x30d682 blvs 0xff1958aa <b2_toiTime+0xfffffffffea3c406> */
/* @0x30d686 ldmeq r4, {r8, r12, sp, lr, pc} */
/* @0x30d68a .word 0xf8c04631 */
/* @0x30d68e strbmi r2, [r0], -r8, lsl #1 */
/* @0x30d692 .word 0xf7da63bb */
/* @0x30d696 eorvs pc, r8, r2, lsl lr */
/* @0x30d69a .word 0xf8dfb968 */
/* @0x30d69e .word 0x460791fc */
/* @0x30d6a2 bl 0x55ea8e <g_SWFlineaavertbuff+0xb9c6> */
/* @0x30d6a6 ldrtmi r1, [r9], -r7, lsl #6 */
/* @0x30d6aa .word 0x6c184642 */
/* @0x30d6ae .word 0xf7da4633 */
/* @0x30d6b2 eorvs pc, r8, r10, ror pc */
/* @0x30d6b6 stmdbls r3, {r3, r4, r6, r8, r12, sp, pc} */
/* @0x30d6ba stmdavs r8!, {r0, r1, r3, r6, r9, r11, r12, pc} */
/* @0x30d6be addsmi r6, r10, #720896 */
/* @0x30d6c2 eorhi pc, r1, #0 */
/* @0x30d6c6 svc #0x86f5a8 */
/* @0x30d6ca .word 0x602b23b0 */
/* @0x30d6ce .word 0x3701e7f3 */
/* @0x30d6d2 mvnle r2, r3, asr pc */
/* @0x30d6d6 tsths r8, r0, lsr r6 */
/* @0x30d6da bvs 0xcdef8a <b2_toiTime+0x585ae6> */
/* @0x30d6de stc2 p7, c15, [r2, #-868]! */
/* @0x30d6e2 .word 0xf8c7682b */
/* @0x30d6e6 blhs 0x30d8ee <af_shaper_get_elem+0x315c> */
/* @0x30d6ea bvs 0xc01e86 <b2_toiTime+0x4a89e2> */
/* @0x30d6ee .word 0xf8d34631 */
/* @0x30d6f2 .word 0xf7da0080 */
/* @0x30d6f6 eorvs pc, r8, r2, ror #27 */
/* @0x30d6fa bicsle r2, r12, r0, lsl #16 */
/* @0x30d6fe bvs 0xbe808e <b2_toiTime+0x48ebea> */
/* @0x30d702 ldrsbvs r6, [r10, #130] */
/* @0x30d706 rscslo pc, pc, #79 */
/* @0x30d70a subsvs r6, r10, #143360 */
/* @0x30d70e .word 0xf018e7d3 */
/* @0x30d712 rsbsle r0, lr, r8, lsl #30 */
/* @0x30d716 .word 0xf5044962 */
/* @0x30d71a .word 0xf1083808 */
/* @0x30d71e ldrbmi r0, [r10], -r8, lsr #32 */
/* @0x30d722 shsub16mi r4, r11, r9 */
/* @0x30d726 blx 0xb0b728 <b2_toiTime+0x3b2284> */
/* @0x30d72a eorvs r4, r8, r6, lsl #12 */
/* @0x30d72e bicle r2, r2, r0, lsl #16 */
/* @0x30d732 .word 0x3028f8d8 */
/* @0x30d736 ldmdavs r8, {r0, r1, r2, r5, r9, r11, sp, lr} ^ */
/* @0x30d73a blx 0xff90b73a <b2_toiTime+0xffffffffff1b2296> */
/* @0x30d73e .word 0x460364b8 */
/* @0x30d742 .word 0xf8d86060 */
/* @0x30d746 bvs 0xcd583e <b2_toiTime+0x57c39a> */
/* @0x30d74a svceq #0x92ebb0 */
/* @0x30d74e ldrtvs sp, [lr], #2306 */
/* @0x30d752 ldr r2, [r10, r6, lsl #6]! */
/* @0x30d756 strbmi r9, [r8], -r0, lsl #12 */
/* @0x30d75a tsths r0, r1, lsl #10 */
/* @0x30d75e .word 0xf7da4632 */
/* @0x30d762 stmdavs r11!, {r0, r2, r4, r7, r10, r11, r12, sp, lr, pc} */
/* @0x30d766 tstlt r3, r8, lsr r5 */
/* @0x30d76a ldrvs r6, [lr], #2595 */
/* @0x30d76e stmdavs r3!, {r0, r1, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30d772 tsteq r0, #67 */
/* @0x30d776 blmi 0x15a580a <b2_toiTime+0xe4c366> */
/* @0x30d77a .word 0xf8ca447b */
/* @0x30d77e ldr r3, [r10, r0] */
/* @0x30d782 ldrbmi r4, [r8], -r9, asr #18 */
/* @0x30d786 ldrbtmi r2, [r9], #-527 */
/* @0x30d78a svc #0x2af5a8 */
/* @0x30d78e .word 0xf89bb948 */
/* @0x30d792 .word 0xf013300f */
/* @0x30d796 ldrsbtle r0, [lr], -pc */
/* @0x30d79a eorsle r2, r12, sp, lsl #22 */
/* @0x30d79e blhs 0x35c3ca */
/* @0x30d7a2 stmdbmi r1, {r0, r3, r4, r5, r8, r11, r12, lr, pc} ^ */
/* @0x30d7a6 andhs r4, r4, #88, #12 */
/* @0x30d7aa .word 0xf5a84479 */
/* @0x30d7ae stmdblt r8, {r3, r4, r8, r9, r10, r11, sp, lr, pc} ^ */
/* @0x30d7b2 mullo r4, r11, r8 */
/* @0x30d7b6 svceq #0xdff013 */
/* @0x30d7ba blhs 0x6819be <g_SWFlinevertbuff+0x2e8f6> */
/* @0x30d7be bllo 0x5819ba <g_SWFlineaavertbuff+0x2e8f2> */
/* @0x30d7c2 ldmdble r10!, {r0, r8, r9, r11, sp} ^ */
/* @0x30d7c6 uasxmi r4, r8, r10 */
/* @0x30d7ca ldrbtmi r2, [r9], #-516 */
/* @0x30d7ce svc #0x8f5a8 */
/* @0x30d7d2 .word 0xf89bb960 */
/* @0x30d7d6 .word 0xf0133004 */
/* @0x30d7da .word 0xf0000fdf */
/* @0x30d7de blhs 0x66dc26 <g_SWFlinevertbuff+0x1ab5e> */
/* @0x30d7e2 mrshi pc, apsr */
/* @0x30d7e6 blhs 0x35c412 */
/* @0x30d7ea .word 0x8109f240 */
/* @0x30d7ee uasxmi r4, r8, r1 */
/* @0x30d7f2 ldrbtmi r2, [r9], #-517 */
/* @0x30d7f6 cdp p5, #0xf, c15, c4, c8, #0x5 */
/* @0x30d7fa .word 0xf0402800 */
/* @0x30d7fe .word 0xf89b8149 */
/* @0x30d802 .word 0xf0133005 */
/* @0x30d806 .word 0xf0400fdf */
/* @0x30d80a .word 0xf01880f3 */
/* @0x30d80e .word 0xf0400f08 */
/* @0x30d812 .word 0x23b38141 */
/* @0x30d816 .word 0xf018e759 */
/* @0x30d81a .word 0xd1010f04 */
/* @0x30d81e .word 0xe75423b2 */
/* @0x30d822 .word 0xf5044925 */
/* @0x30d826 .word 0xf1063608 */
/* @0x30d82a ldrbmi r0, [r10], -r8, lsr #32 */
/* @0x30d82e shsub16mi r4, r11, r9 */
/* @0x30d832 blx 0xfe98b832 <b2_toiTime+0xfffffffffe23238e> */
/* @0x30d836 stmdahs r0, {r3, r5, sp, lr} */
/* @0x30d83a svcge #0x3df47f */
/* @0x30d83e bvs 0xce8312 <b2_toiTime+0x58ee6e> */
/* @0x30d842 .word 0xf7fe6858 */
/* @0x30d846 adcshi pc, r8, r0, ror r10 */
/* @0x30d84a bvs 0xce831e <b2_toiTime+0x58ee7a> */
/* @0x30d84e .word 0xf7fe6898 */
/* @0x30d852 rscshi pc, r8, r10, ror #20 */
/* @0x30d856 bvs 0xce832a <b2_toiTime+0x58ee86> */
/* @0x30d85a .word 0xf7fd68d8 */
/* @0x30d85e ldrhhi pc, [r8, -r10]! */
/* @0x30d862 bvs 0xce8336 <b2_toiTime+0x58ee92> */
/* @0x30d866 .word 0xf7fd6918 */
/* @0x30d86a ldrhhi pc, [r8, #-244]! */
/* @0x30d86e ldmdbhi r9, {r0, r1, r5, r9, r11, sp, lr} ^ */
/* @0x30d872 strmi r8, [r10], #-2266 */
/* @0x30d876 bvs 0xbedee6 <b2_toiTime+0x494a42> */
/* @0x30d87a subsmi r8, r2, #1474560 */
/* @0x30d87e stmdavs r3!, {r1, r3, r4, r6, r7, r8, pc} */
/* @0x30d882 movweq pc, #0x8043 */
/* @0x30d886 adcmi lr, r12, r5, rrx */
/* @0x30d88a .word 0x03ba0004 */
/* @0x30d88e blne 0xff4cd8ce <b2_toiTime+0xfffffffffed7442a> */
/* @0x30d892 ldcne p0, c0, [r0], #-32 */
/* @0x30d896 .word 0x1c120008 */
/* @0x30d89a svcgt #0x720008 */
/* @0x30d89e bne 0xff24d8da <b2_toiTime+0xfffffffffeaf4436> */
/* @0x30d8a2 .word 0xf41f0008 */
/* @0x30d8a6 bne 0xff0cd8aa <b2_toiTime+0xfffffffffe974406> */
/* @0x30d8aa bne 0xfec0d8d2 <b2_toiTime+0xfffffffffe4b442e> */
/* @0x30d8ae bne 0xfe4cd8d6 <b2_toiTime+0xfffffffffdd74432> */
/* @0x30d8b2 stmibne lr!, {r3} ^ */
/* @0x30d8b6 ldmibne r1!, {r3} */
/* @0x30d8ba .word 0xf5040008 */
/* @0x30d8be ldmibmi r3, {r3, r11, r12, sp} */
/* @0x30d8c2 stmdaeq r8!, {r3, r8, r12, sp, lr, pc} */
/* @0x30d8c6 ldrbtmi r4, [r9], #-1626 */
/* @0x30d8ca .word 0x4640463b */
/* @0x30d8ce blx 0x160b8ce <b2_toiTime+0xeb242a> */
/* @0x30d8d2 eorvs r4, r8, r6, lsl #12 */
/* @0x30d8d6 .word 0xf47f2800 */
/* @0x30d8da svcge #0x5aeee */
/* @0x30d8de .word 0xf7ff4640 */
/* @0x30d8e2 strbmi pc, [r0], -r2, asr #18 */
/* @0x30d8e6 .word 0xf7fe4639 */
/* @0x30d8ea sxtab16mi pc, r2, r6, ror #24 */
/* @0x30d8ee .word 0xf0002800 */
/* @0x30d8f2 bvs 0xbedc36 <b2_toiTime+0x494792> */
/* @0x30d8f6 ldmdavs r9, {r3, r6, r9, r10, lr} */
/* @0x30d8fa ldc2 p7, c15, [r12, #-868] */
/* @0x30d8fe .word 0x21016a23 */
/* @0x30d902 ldrtmi r4, [r2], -r8, asr #12 */
/* @0x30d906 ldmdavs r11!, {r1, r2, r3, r4, sp, lr} */
/* @0x30d90a .word 0x8020f8d4 */
/* @0x30d90e strls r4, [r0], -r11, lsl #8 */
/* @0x30d912 .word 0xf7da9501 */
/* @0x30d916 .word 0xf8c8fbbb */
/* @0x30d91a .word 0xf8d50000 */
/* @0x30d91e .word 0xf1b88000 */
/* @0x30d922 .word 0xf47f0f00 */
/* @0x30d926 bvs 0xbf944e <b2_toiTime+0x49ffaa> */
/* @0x30d92a ldmdavs r10!, {r0, r4, r6, r9, r10, lr} */
/* @0x30d92e andlo r6, r1, #24, #16 */
/* @0x30d932 cdp p5, #0x4, c15, c4, c8, #0x5 */
/* @0x30d936 .word 0xf8d46a26 */
/* @0x30d93a stmdblt r6!, {r2, r5, sp, pc} ^ */
/* @0x30d93e stmdaeq r6, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30d942 andhi pc, r0, r5, asr #17 */
/* @0x30d946 svceq #0xf1b8 */
/* @0x30d94a mrcge p4, #0x5, apsr_nzcv, c5, c15, #0x3 */
/* @0x30d94e .word 0xf0436823 */
/* @0x30d952 eorvs r0, r3, r2, lsl #6 */
/* @0x30d956 ldmdavs r3!, {r0, r1, r2, r3, r5, r7, r9, r10, sp, lr, pc} */
/* @0x30d95a rscle r2, pc, r0, lsl #22 */
/* @0x30d95e blhs 0x32b9d2 */
/* @0x30d962 .word 0xf506d0ec */
/* @0x30d966 svcge #0x72388 */
/* @0x30d96a andshs r4, r0, #68157440 */
/* @0x30d96e .word 0x9088f8d3 */
/* @0x30d972 .word 0xf5a84638 */
/* @0x30d976 .word 0xf8c7ee1c */
/* @0x30d97a .word 0xf8da900c */
/* @0x30d97e .word 0xf8d6300c */
/* @0x30d982 mvnsvs r9, r0 */
/* @0x30d986 .word 0xf5a84648 */
/* @0x30d98a .word 0xf100edd6 */
/* @0x30d98e .word 0xf1b80801 */
/* @0x30d992 ldmle r3, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11} ^ */
/* @0x30d996 strbmi r10, [r2], -r11, lsl #22 */
/* @0x30d99a ldrmi r4, [r8], -r9, asr #12 */
/* @0x30d99e cdp p5, #0x0, c15, c14, c8, #0x5 */
/* @0x30d9a2 ldrbtmi r4, [r9], #-2396 */
/* @0x30d9a6 ldrtmi r4, [r8], -r3, lsl #12 */
/* @0x30d9aa .word 0x4643461a */
/* @0x30d9ae .word 0xf9dbf7fe */
/* @0x30d9b2 stmiblt r8, {r7, r9, r10, lr} ^ */
/* @0x30d9b6 blhs 0x6e7caa <g_SWFvertbuff+0x14be2> */
/* @0x30d9ba ldmdavs r11!, {r1, r2, r4, r8, r12, lr, pc} */
/* @0x30d9be ldmdavc r11, {r0, r1, r3, r4, r6, r7, r9, r11, sp, lr} */
/* @0x30d9c2 andle r2, pc, r0, asr r11 */
/* @0x30d9c6 blhs 0x14039de <b2_toiTime+0xcaa53a> */
/* @0x30d9ca blhs 0x16819f2 <b2_toiTime+0xf2854e> */
/* @0x30d9ce and sp, r11, r8 */
/* @0x30d9d2 andle r2, r5, sp, ror #22 */
/* @0x30d9d6 andle r2, r5, r0, ror r11 */
/* @0x30d9da .word 0xd1052b63 */
/* @0x30d9de and r2, r2, r0, lsr #6 */
/* @0x30d9e2 and r2, r0, r0, lsl r3 */
/* @0x30d9e6 mvnsvs r2, r8, lsl #6 */
/* @0x30d9ea .word 0xf7fe4638 */
/* @0x30d9ee .word 0xe7a7f93f */
/* @0x30d9f2 .word 0xf43f2b0d */
/* @0x30d9f6 bllo 0x579626 <g_SWFlineaavertbuff+0x2655e> */
/* @0x30d9fa stmdale r9, {r0, r8, r9, r11, sp} ^ */
/* @0x30d9fe .word 0xf018e705 */
/* @0x30da02 .word 0xd1010f02 */
/* @0x30da06 .word 0xe66023b1 */
/* @0x30da0a .word 0xf5044943 */
/* @0x30da0e .word 0xf1063608 */
/* @0x30da12 ldrbmi r0, [r10], -r8, lsr #32 */
/* @0x30da16 shsub16mi r4, r11, r9 */
/* @0x30da1a .word 0xf9a5f7fe */
/* @0x30da1e stmdahs r0, {r3, r5, sp, lr} */
/* @0x30da22 mcrge p4, #0x2, pc, c9, c15, #0x3 */
/* @0x30da26 bvs 0xce84fa <b2_toiTime+0x58f056> */
/* @0x30da2a .word 0xf7fe6858 */
/* @0x30da2e teqvs r8, lr, asr r9 */
/* @0x30da32 bvs 0xce8506 <b2_toiTime+0x58f062> */
/* @0x30da36 .word 0xf7fe6898 */
/* @0x30da3a cmnvs r8, r8, asr r9 */
/* @0x30da3e bvs 0xce8512 <b2_toiTime+0x58f06e> */
/* @0x30da42 .word 0xf7fe68d8 */
/* @0x30da46 .word 0x61b8f952 */
/* @0x30da4a bvs 0xce871e <b2_toiTime+0x58f27a> */
/* @0x30da4e tstle r6, r5, lsl #22 */
/* @0x30da52 ldmdbvs r8, {r0, r1, r4, r5, r7, r9, r11, sp, lr} */
/* @0x30da56 mrc2 p7, #0x5, apsr_nzcv, c13, c13, #0x7 */
/* @0x30da5a stmdahs r4, {r7, r9, r12, sp, pc} */
/* @0x30da5e .word 0xf507d903 */
/* @0x30da62 movwhs r2, #0x8788 */
/* @0x30da66 stmdahs r2, {r1, r2, r3, sp, lr, pc} */
/* @0x30da6a .word 0xf507d903 */
/* @0x30da6e movwhs r2, #0x4788 */
/* @0x30da72 .word 0xd104e008 */
/* @0x30da76 strhs pc, [r8, r7, lsl #10] */
/* @0x30da7a addeq pc, r6, r7, lsr #17 */
/* @0x30da7e .word 0xf507e004 */
/* @0x30da82 movwhs r2, #0x1788 */
/* @0x30da86 addlo pc, r6, r7, lsr #17 */
/* @0x30da8a .word 0xf0436823 */
/* @0x30da8e strb r0, [r0, -r4, lsl #6]! */
/* @0x30da92 ldr r2, [r10], -r3, lsl #6 */
/* @0x30da96 strhlo pc, [r12], -r6 */
/* @0x30da9a adcsvs r4, r3, #32, #30 */
/* @0x30da9e bvs 0xbdeca2 <b2_toiTime+0x4857fe> */
/* @0x30daa2 ldrtmi r10, [r9], -r11, lsl #28 */
/* @0x30daa6 rfeib r3! */
/* @0x30daaa .word 0xf5a8200c */
/* @0x30daae ldmdbmi r11, {r4, r6, r8, r10, r11, sp, lr, pc} */
/* @0x30dab2 ldrtmi r6, [r2], -r0, lsr #20 */
/* @0x30dab6 .word 0xf7fe4479 */
/* @0x30daba .word 0x6028feb8 */
/* @0x30dabe .word 0xf47f2800 */
/* @0x30dac2 bvs 0xbf92b2 <b2_toiTime+0x49fe0e> */
/* @0x30dac6 shasxmi r4, r0, r9 */
/* @0x30daca strhhs pc, [lr], -r3 */
/* @0x30dace bvs 0xbe663e <b2_toiTime+0x48d19a> */
/* @0x30dad2 strhhs pc, [lr], -r3 */
/* @0x30dad6 ldc p5, c15, [r12, #-672]! */
/* @0x30dada bvs 0xb1ff2a <b2_toiTime+0x3c6a86> */
/* @0x30dade ldrbtmi r4, [r9], #-1586 */
/* @0x30dae2 mcr2 p7, #0x5, pc, c3, c14, #0x7 */
/* @0x30dae6 stmdahs r0, {r3, r5, sp, lr} */
/* @0x30daea stclge p4, c15, [r5, #508]! */
/* @0x30daee andhs r6, r1, #143360 */
/* @0x30daf2 orrhs pc, r8, #12582912 */
/* @0x30daf6 addhs pc, r4, r3, lsr #17 */
/* @0x30dafa ldrbtmi r4, [r11], #-2827 */
/* @0x30dafe andlo pc, r0, r10, asr #17 */
/* @0x30db02 .word 0x33fff04f */
/* @0x30db06 sublt lr, sp, r1, ror #11 */
/* @0x30db0a svchi #0xf0e8bd */
/* @0x30db0e ldmdbne r7, {r8, r9, r10, r11, r12, sp, pc} */
/* @0x30db12 strb r0, [pc], -r8 */
/* @0x30db16 strbne r0, [r9, r7] */
/* @0x30db1a strne r0, [r7, -r8]! */
/* @0x30db1e strbtne r0, [r8], r8 */
/* @0x30db22 strbne r0, [r10], r8 */
/* @0x30db26 vhadd.u8 d0, d1, d8 */
/* @0x30db2a stmdavs r3, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30db2e adclo pc, r0, #13828096 */
/* @0x30db32 msrvc CPSR_sxc, #12582912 */
/* @0x30db36 andhs r6, r0, r3, lsl #2 */
/* @0x30db3a movwhs r4, #0x770 */
/* @0x30db3e ldrbmi r6, [r0, -r3, lsl #2]! */
/* @0x30db42 svclt #0x9a29ff */
/* @0x30db46 rfeda r3! */
/* @0x30db4a andhs r0, r0, r1, lsl r0 */
/* @0x30db4e stmdavs r10, {r4, r5, r6, r8, r9, r10, lr} */
/* @0x30db52 andvs r2, r11, r0, lsl #6 */
/* @0x30db56 stmdale sp, {r1, r2, r3, r4, r5, r6, r7, r9, r11, sp} */
/* @0x30db5a mrrcne p9, #0x0, r6, r3, c0 */
/* @0x30db5e subeq lr, r2, #0, #22 */
/* @0x30db62 svceq #0x2f832 */
/* @0x30db66 andvs r11, r11, r8, lsl #2 */
/* @0x30db6a movwlo r4, #0x1770 */
/* @0x30db6e svcvc #0x80f5b3 */
/* @0x30db72 .word 0x4770d1f6 */
/* @0x30db76 .word 0x47704618 */
/* @0x30db7a ldrlt r0, [r7, #-0x0]! */
/* @0x30db7e stmdavs r2, {r0, r9, r10, lr} */
/* @0x30db82 adclo pc, r0, #13762560 */
/* @0x30db86 .word 0xf8d36e50 */
/* @0x30db8a .word 0xf8d344a4 */
/* @0x30db8e mrslt r5, spsr */
/* @0x30db92 strhs r9, [r0], #-513 */
/* @0x30db96 ldmdbvs r10, {r10, r12, pc} ^ */
/* @0x30db9a stmdavs r12!, {r2, r8, r9, r11, lr} ^ */
/* @0x30db9e .word 0x47a0447b */
/* @0x30dba2 adchs lr, r3, r0 */
/* @0x30dba6 ldclt p0, c11, [r0, #-12]! */
/* @0x30dbaa ldmhs r1!, {r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x30dbae strlt r0, [r8, #-0x0] */
/* @0x30dbb2 .word 0xf8d36803 */
/* @0x30dbb6 .word 0xf8d332a0 */
/* @0x30dbba ldmvs r11, {r2, r3, r10, r11, r12, sp} */
/* @0x30dbbe stclt p7, c4, [r8, #-608] */
/* @0x30dbc2 stmdavs r3, {r3, r8, r10, r12, sp, pc} */
/* @0x30dbc6 adclo pc, r0, #13828096 */
/* @0x30dbca .word 0x3c0cf8d3 */
/* @0x30dbce .word 0x479868db */
/* @0x30dbd2 ldrlt r11, [r8, #-0xd08]! */
/* @0x30dbd6 .word 0xf8d0461c */
/* @0x30dbda strhs r3, [r0, #-0x21c] */
/* @0x30dbde rsbvs r6, r5, r5, lsr #32 */
/* @0x30dbe2 ldclvs p1, c11, [r11, #-76] */
/* @0x30dbe6 mlavs r0, r8, r7, r4 */
/* @0x30dbea ldclt p0, c2, [r8, #-0]! */
/* @0x30dbee vmlal.u8 q11, d16, d0 */
/* @0x30dbf2 ldrbmi r2, [r0, -r0, asr #32]! */
/* @0x30dbf6 adclo pc, r0, #208, #16 */
/* @0x30dbfa andvc r2, r10, r0, lsl #4 */
/* @0x30dbfe .word 0xf8d3b13b */
/* @0x30dc02 .word 0xf64f25e0 */
/* @0x30dc06 addsmi r7, r10, #-67108861 */
/* @0x30dc0a movwhs r11, #0x1f1c */
/* @0x30dc0e andhs r7, r0, r11 */
/* @0x30dc12 ldrlt r4, [r0, #-0x770] */
/* @0x30dc16 adclo pc, r0, #208, #16 */
/* @0x30dc1a .word 0xf8d3b173 */
/* @0x30dc1e .word 0xf64f05e0 */
/* @0x30dc22 adcmi r7, r0, #-16777216 */
/* @0x30dc26 ldmdbvs r8, {r1, r3, r12, lr, pc} ^ */
/* @0x30dc2a stmdale r7, {r0, r7, r9, lr} */
/* @0x30dc2e strtlo pc, [r4], #2259 */
/* @0x30dc32 andslo pc, r1, r3, lsr r8 */
/* @0x30dc36 andsvs r11, r3, r2, lsl #2 */
/* @0x30dc3a ldclt p0, c2, [r0, #-0] */
/* @0x30dc3e ldclt p0, c2, [r0, #-24] */
/* @0x30dc42 .word 0xf8d0b508 */
/* @0x30dc46 ldmvs r11, {r2, r5, r9, r12, sp} */
/* @0x30dc4a stclt p7, c4, [r8, #-608] */
/* @0x30dc4e .word 0xf8d0b508 */
/* @0x30dc52 ldmvs r11, {r2, r5, r9, r12, sp} ^ */
/* @0x30dc56 stclt p7, c4, [r8, #-608] */
/* @0x30dc5a .word 0xf8d0b508 */
/* @0x30dc5e ldmdbvs r11, {r2, r5, r9, r12, sp} */
/* @0x30dc62 stclt p7, c4, [r8, #-608] */
/* @0x30dc66 .word 0xf8d0b508 */
/* @0x30dc6a ldmdbvs r11, {r2, r5, r9, r12, sp} ^ */
/* @0x30dc6e stclt p7, c4, [r8, #-608] */
/* @0x30dc72 .word 0xf8d0b508 */
/* @0x30dc76 ldmibvs r11, {r2, r5, r9, r12, sp} */
/* @0x30dc7a stclt p7, c4, [r8, #-608] */
/* @0x30dc7e .word 0xf8d0b508 */
/* @0x30dc82 ldmdavs r11, {r3, r5, r9, r12, sp} */
/* @0x30dc86 stclt p7, c4, [r8, #-608] */
/* @0x30dc8a .word 0xf8d0b508 */
/* @0x30dc8e ldmibvs r11, {r3, r5, r9, r12, sp} ^ */
/* @0x30dc92 stclt p7, c4, [r8, #-608] */
/* @0x30dc96 stmdbvs r4, {r4, r5, r6, r7, r8, r10, r12, sp, pc} ^ */
/* @0x30dc9a umaaleq pc, r1, r0, r8 */
/* @0x30dc9e rfeib r4! */
/* @0x30dca2 addne r0, r9, #2 */
/* @0x30dca6 addsne r6, r2, #6619136 */
/* @0x30dcaa blhs 0x327f4a */
/* @0x30dcae movwhs r11, #0x2f0c */
/* @0x30dcb2 bl 0x4568be <g_RomDisk+0x5f09e> */
/* @0x30dcb6 .word 0xf84507c0 */
/* @0x30dcba rsbsvs r1, r10, r0, lsr r0 */
/* @0x30dcbe stmdahi r3!, {r0, r1, r4, r5, r10, r12, lr} ^ */
/* @0x30dcc2 rsbhi r3, r3, r1, lsl #6 */
/* @0x30dcc6 stmdavc r3, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x30dcca .word 0xd1082b1c */
/* @0x30dcce addsmi r1, r9, #49920 */
/* @0x30dcd2 stmdavc r2, {r4, r5, r8, r9, r12, lr, pc} ^ */
/* @0x30dcd6 b 0x13ebeea <b2_toiTime+0xc92a46> */
/* @0x30dcda andlt r2, r0, #2 */
/* @0x30dcde blhs 0xa5faa6 <b2_toiTime+0x306602> */
/* @0x30dce2 stclne p1, c13, [r3, #-52] */
/* @0x30dce6 .word 0xd3254299 */
/* @0x30dcea stmdavc r2, {r0, r1, r7, r11, r12, sp, lr} ^ */
/* @0x30dcee b 0x13ced62 <b2_toiTime+0xc758be> */
/* @0x30dcf2 stmdbvc r2, {r1, r8, r9, sp, lr} */
/* @0x30dcf6 tstmi r3, #192, #16 */
/* @0x30dcfa andhs lr, r0, r3, asr #20 */
/* @0x30dcfe blhs 0x9fac6 */
/* @0x30dd02 .word 0xf1a3dc02 */
/* @0x30dd06 ldrbmi r0, [r0, -r11, lsl #1]! */
/* @0x30dd0a .word 0xf1002bfa */
/* @0x30dd0e .word 0xdc080202 */
/* @0x30dd12 movwle r4, #0xf291 */
/* @0x30dd16 bl 0x32be1e */
/* @0x30dd1a .word 0xf5a02003 */
/* @0x30dd1e ldmlo r4, {r1, r2, r4, r5, r6, lr} */
/* @0x30dd22 addsmi r4, r1, #112, #14 */
/* @0x30dd26 .word 0xf1c3d306 */
/* @0x30dd2a stmdavc r2, {r0, r1, r3, r4, r5, r6, r7, r8, r9} ^ */
/* @0x30dd2e bne 0xfe90e5a2 <b2_toiTime+0xfffffffffe1b50fe> */
/* @0x30dd32 ldrbmi r3, [r0, -r12, ror #16]! */
/* @0x30dd36 ldrbmi r2, [r0, -r0]! */
/* @0x30dd3a .word 0x4603b5f0 */
/* @0x30dd3e movtlt r6, #0x880 */
/* @0x30dd42 tstlt r2, r10, lsl r8 */
/* @0x30dd46 andle r2, r2, r3, lsl #20 */
/* @0x30dd4a mcrrpl p0, #0x2, lr, r0, c2 */
/* @0x30dd4e ldmdbvs r10, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x30dd52 ldmdbvs r10, {r2, r3, r7, r9, r11, r12} ^ */
/* @0x30dd56 andle r4, r1, #148, #4 */
/* @0x30dd5a ldcllt p14, c7, [r0, #96]! */
/* @0x30dd5e stmdavc r2, {r2, r11, r12, sp, lr} ^ */
/* @0x30dd62 b 0x13a80e2 <b2_toiTime+0xc4ec3e> */
/* @0x30dd66 adcmi r2, r1, #4, #8 */
/* @0x30dd6a stcne p3, c13, [r2], {18} */
/* @0x30dd6e ldmdavc r7, {r1, r2, r10, lr} ^ */
/* @0x30dd72 ldmdavc r0, {r0, r2, r4, r7, r11, r12, sp, lr} */
/* @0x30dd76 strhs lr, [r7, #-0xa45] */
/* @0x30dd7a andle r4, r4, #-1879048182 */
/* @0x30dd7e blne 0xe261f6 <b2_toiTime+0x6ccd52> */
/* @0x30dd82 cmpvs r12, r8, lsl r6 */
/* @0x30dd86 andlo r11, r3, #240, #26 */
/* @0x30dd8a andle r4, r1, #536870923 */
/* @0x30dd8e strb r4, [lr, r12, lsr #12]! */
/* @0x30dd92 ldcllt p0, c2, [r0, #0]! */
/* @0x30dd96 .word 0x9c06b537 */
/* @0x30dd9a eorpl pc, r4, #208, #16 */
/* @0x30dd9e stmibvs r12!, {r10, r12, pc} ^ */
/* @0x30dda2 andlt r4, r3, r0, lsr #15 */
/* @0x30dda6 strlt r11, [r8, #-0xd30] */
/* @0x30ddaa eorlo pc, r4, #208, #16 */
/* @0x30ddae .word 0x47986a1b */
/* @0x30ddb2 blx 0xfe37d1dc <b2_toiTime+0xfffffffffdc23d38> */
/* @0x30ddb6 b 0x16da5be <b2_toiTime+0xf8111a> */
/* @0x30ddba .word 0xf50070e2 */
/* @0x30ddbe ldmdane r11, {lr} */
/* @0x30ddc2 andeq pc, r0, #-2147483632 */
/* @0x30ddc6 andsmi lr, r3, pc, asr #20 */
/* @0x30ddca andmi lr, r2, r0, asr #20 */
/* @0x30ddce .word 0xf8d04770 */
/* @0x30ddd2 andhs r3, r0, #156 */
/* @0x30ddd6 .word 0x4770625a */
/* @0x30ddda addlt r0, r4, r0 */
/* @0x30ddde blge 0x4165ea <g_RomDisk+0x1edca> */
/* @0x30dde2 .word 0xf88061c2 */
/* @0x30dde6 vst4.8 {d18, d19, d20, d21}, [pc:128], r0 */
/* @0x30ddea subvs r7, r2, #-1610612721 */
/* @0x30ddee sbcvc pc, r8, #1325400064 */
/* @0x30ddf2 vst1.32 {d22, d23, d24, d25}, [pc], r2 */
/* @0x30ddf6 sbcvs r7, r2, #-1610612729 */
/* @0x30ddfa andsne pc, r3, #64, #4 */
/* @0x30ddfe vcgt.s8 d22, d0, d2 */
/* @0x30de02 orrvs r6, r2, #-1073741792 */
/* @0x30de06 andsne pc, sp, #64, #12 */
/* @0x30de0a andhs r6, r0, #134217731 */
/* @0x30de0e bge 0x3e6e1e <error_g0017+0x3fac2> */
/* @0x30de12 stceq p8, c15, [r12, #-268] */
/* @0x30de16 stmvs r2, {r0, r1, r4, r6, lr} */
/* @0x30de1a subsmi r6, r3, r1, asr #6 */
/* @0x30de1e b 0xfe39128e <b2_toiTime+0xfffffffffdc37dea> */
/* @0x30de22 .word 0x40532293 */
/* @0x30de26 ble 0x358a2e */
/* @0x30de2a and r4, r1, r11, asr r2 */
/* @0x30de2e blmi 0x3bda56 <error_g0017+0x166fa> */
/* @0x30de32 andhs r6, r0, r3, asr #8 */
/* @0x30de36 ldrbmi r11, [r0, -r4]! */
/* @0x30de3a ldcgt p15, c11, [r5, #-0] */
/* @0x30de3e .word 0x4770075b */
/* @0x30de42 stmdavs r3, {r4, r8, r12, sp, pc} */
/* @0x30de46 andvs r11, r1, r3, lsl #18 */
/* @0x30de4a ldrlt r4, [r0, #-0x770] */
/* @0x30de4e stmdbvs r3, {r2, r9, r10, lr} ^ */
/* @0x30de52 movwle r4, #0x4299 */
/* @0x30de56 stmdavs r0, {r1, r7, r8, sp} ^ */
/* @0x30de5a .word 0xfff2f7ff */
/* @0x30de5e stmvs r0!, {r8, sp} */
/* @0x30de62 blx 0x3285f8 */
/* @0x30de66 ldclt p0, c3, [r0, #-4] */
/* @0x30de6a .word 0x4604b570 */
/* @0x30de6e .word 0xb10a6942 */
/* @0x30de72 stmdblt r11!, {r0, r1, r6, r8, r9, r11, r12, sp, lr} */
/* @0x30de76 stmdbvs r1!, {r3, r9, r10, lr} */
/* @0x30de7a ldrhtmi lr, [r0], #-141 */
/* @0x30de7e svclt #0x99f7ff */
/* @0x30de82 blo 0x368496 <_ZTS12CDS_Priority+0xa4ee> */
/* @0x30de86 addsmi r2, r3, #20, #10 */
/* @0x30de8a andshs sp, r4, r1, lsl #6 */
/* @0x30de8e mrrcne p0, #0x0, lr, r8, c13 */
/* @0x30de92 strmi pc, [r0], -r5, lsl #22 */
/* @0x30de96 adcsmi r6, r1, #483328 */
/* @0x30de9a .word 0x4603dbf7 */
/* @0x30de9e blx 0x347e74 */
/* @0x30dea2 bvs 0x179e6b6 <b2_toiTime+0x1045212> */
/* @0x30dea6 ble 0x39e8f2 <ft_sid_names+0x110> */
/* @0x30deaa blhs 0x31cab6 */
/* @0x30deae strdvs sp, lr, [r3, r7]! */
/* @0x30deb2 bvs 0x1b3c366 <b2_toiTime+0x13e2ec2> */
/* @0x30deb6 ble 0x39e8c2 <ft_sid_names+0xe0> */
/* @0x30deba stmdbvs r1!, {r3, r9, r11, r12} */
/* @0x30debe andshs lr, r4, #5 */
/* @0x30dec2 strmi pc, [r3], #-2818 */
/* @0x30dec6 bne 0x52884e <SrcVerts+0x85892> */
/* @0x30deca .word 0xf7ff6ae1 */
/* @0x30dece bvs 0xfec0dc9e <b2_toiTime+0xfffffffffe4b47fa> */
/* @0x30ded2 ldcllt p4, c4, [r0, #-96]! */
/* @0x30ded6 svcmi #0xf0e92d */
/* @0x30deda stmdavs r11, {r2, r9, r10, lr} */
/* @0x30dede ldrmi r11, [r7], -r5, lsl #1 */
/* @0x30dee2 ldmdavs r3, {r0, r1, r3, r5, r8, r12, sp, pc} */
/* @0x30dee6 .word 0xf0402b00 */
/* @0x30deea .word 0x460e80b5 */
/* @0x30deee ldrmi lr, [r6], -r0 */
/* @0x30def2 beq 0x34a036 */
/* @0x30def6 strhs r6, [r0, #-0x961] */
/* @0x30defa addmi r2, sp, #20 */
/* @0x30defe blx 0x341f2c */
/* @0x30df02 ldmvs r2!, {r0, r2, r8, r9, lr} */
/* @0x30df06 addsmi r6, r3, #372736 */
/* @0x30df0a strlo sp, [r1, #-0xa01] */
/* @0x30df0e addmi lr, sp, #64225280 */
/* @0x30df12 stmdavs r0!, {r0, r1, r8, r9, r12, lr, pc} ^ */
/* @0x30df16 stmiblt r11, {r0, r1, r8, r9, r11, r12, sp, lr} */
/* @0x30df1a addsmi lr, r3, #50 */
/* @0x30df1e adchi pc, r2, r0 */
/* @0x30df22 svceq #0xf1ba */
/* @0x30df26 ldmvs r10!, {r0, r1, r12, lr, pc} */
/* @0x30df2a vqsub.u8 d20, d16, d3 */
/* @0x30df2e tsths r4, #155 */
/* @0x30df32 movwmi pc, #0x5b03 */
/* @0x30df36 .word 0x071a69db */
/* @0x30df3a adds sp, r3, r11, ror #11 */
/* @0x30df3e .word 0x06db6833 */
/* @0x30df42 .word 0xf1bad41e */
/* @0x30df46 andsle r0, r7, r0, lsl #30 */
/* @0x30df4a ldmvs r9!, {r0, r1, r4, r5, r7, r11, sp, lr} */
/* @0x30df4e bl 0x35efba <_ZTS12CDS_Priority+0x1012> */
/* @0x30df52 ldrdne r7, r8, [r9], #-17 */
/* @0x30df56 .word 0xff88f7ff */
/* @0x30df5a stmdbvs r1!, {r0, r1, r4, r5, r7, r11, sp, lr} */
/* @0x30df5e ldmvs r8!, {r7, r9, r10, lr} */
/* @0x30df62 bl 0x314a6a <FT_Bitmap_Copy+0x92> */
/* @0x30df66 ldrdne r7, r8, [r0], #-0 */
/* @0x30df6a .word 0xff23f7ff */
/* @0x30df6e movweq lr, #0x8bc0 */
/* @0x30df72 rscsvs r4, r3, r0, asr #8 */
/* @0x30df76 strd r6, r7, [r3], -r8 */
/* @0x30df7a .word 0xf7ff68b1 */
/* @0x30df7e rscsvs pc, r0, r5, ror pc */
/* @0x30df82 mcrne p1, #0x3, r11, c10, c13, #0x1 */
/* @0x30df86 blx 0x3d6be0 <error_g0017+0x2f884> */
/* @0x30df8a ldmvs r3!, {r1, r9, lr} ^ */
/* @0x30df8e addsmi r6, r3, #598016 */
/* @0x30df92 .word 0xf8d4db68 */
/* @0x30df96 strbmi r12, [r5, #-0x14]! */
/* @0x30df9a tsths r4, #-268435456 */
/* @0x30df9e movwmi pc, #0x5b03 */
/* @0x30dfa2 svceq #0xf1ba */
/* @0x30dfa6 ldmvs r10!, {r2, r12, lr, pc} ^ */
/* @0x30dfaa addsmi r6, r10, #634880 */
/* @0x30dfae subs sp, r9, r8, lsl #26 */
/* @0x30dfb2 bvs 0xfe9e8382 <b2_toiTime+0xfffffffffe28eede> */
/* @0x30dfb6 stcle p2, c4, [r6, #-616] */
/* @0x30dfba .word 0xf1bae054 */
/* @0x30dfbe andle r0, r2, r0, lsl #30 */
/* @0x30dfc2 movweq pc, #0x110c */
/* @0x30dfc6 strbtmi lr, [r3], -r0 */
/* @0x30dfca stmdale r11, {r0, r1, r2, r3, r4, r5, r7, r8, r9, r11, sp} ^ */
/* @0x30dfce bl 0xff456826 <b2_toiTime+0xfffffffffecfd382> */
/* @0x30dfd2 mrsls r0, apsr */
/* @0x30dfd6 bleq 0x34a11a */
/* @0x30dfda .word 0x410cfb02 */
/* @0x30dfde andmi pc, r3, #2048 */
/* @0x30dfe2 andls r9, r2, #-1073741824 */
/* @0x30dfe6 .word 0xf1ab9a01 */
/* @0x30dfea blo 0x350c42 */
/* @0x30dfee andlo r9, r1, #268435456 */
/* @0x30dff2 .word 0xf8ddd012 */
/* @0x30dff6 .word 0xf8dd900c */
/* @0x30dffa ldrbmi r8, [r9], #8 */
/* @0x30dffe ldmdbeq r12, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x30e002 .word 0xf10844d8 */
/* @0x30e006 ldm r9!, {r4, r5, r11} */
/* @0x30e00a stm r8!, {r0, r1, r2, r3} */
/* @0x30e00e .word 0xf8d9000f */
/* @0x30e012 .word 0xf8c83000 */
/* @0x30e016 strb r3, [r5, r0]! */
/* @0x30e01a ldmdbeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30e01e stmdami r5, {r0, r3, r8, r9, r11, r12, sp, lr, pc} */
/* @0x30e022 .word 0xf108ce0f */
/* @0x30e026 stm r8!, {r2, r3, r4, r11} */
/* @0x30e02a ldmdavs r3!, {r0, r1, r2, r3} */
/* @0x30e02e andlo pc, r0, r8, asr #17 */
/* @0x30e032 movweq pc, #0x110c */
/* @0x30e036 .word 0xf1ba6163 */
/* @0x30e03a andsle r0, r3, r0, lsl #30 */
/* @0x30e03e svcgt #0xf3501 */
/* @0x30e042 strmi pc, [r5, #-0xb09] */
/* @0x30e046 strgt r3, [pc, #-0x51c] */
/* @0x30e04a eorvs r6, r11, r11, lsr r8 */
/* @0x30e04e movweq pc, #0x210c */
/* @0x30e052 and r6, r7, r3, ror #2 */
/* @0x30e056 stmvs r11, {r1, r4, r7, r11, sp, lr} */
/* @0x30e05a blle 0x3deaca <error_g0017+0x3776e> */
/* @0x30e05e .word 0xf04f460e */
/* @0x30e062 strb r0, [r7, -r1, lsl #20] */
/* @0x30e066 pop {r0, r2, r12, sp, pc} */
/* @0x30e06a push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x30e06e ssub8mi r4, r6, r8 */
/* @0x30e072 eorspl pc, r5, #0, #10 */
/* @0x30e076 strmi r4, [r9], r4, lsl #12 */
/* @0x30e07a blvs 0xff71f8e6 <b2_toiTime+0xfffffffffefc6442> */
/* @0x30e07e ldrpl pc, [r6, #-0x504]! */
/* @0x30e082 .word 0xf7ff9f08 */
/* @0x30e086 shadd8mi pc, r9, r6 */
/* @0x30e08a stmdavs r8!, {r7, r9, r10, lr} */
/* @0x30e08e mrc2 p7, #0x4, apsr_nzcv, c1, c15, #0x7 */
/* @0x30e092 strmi r4, [r0], #1593 */
/* @0x30e096 .word 0xf7ff4648 */
/* @0x30e09a stmdavs r3!, {r0, r1, r2, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30e09e strmi r4, [r7], -r1, asr #12 */
/* @0x30e0a2 .word 0xf7ff6c18 */
/* @0x30e0a6 stmdavs r2!, {r1, r2, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30e0aa .word 0x46814639 */
/* @0x30e0ae .word 0xf7ff6c90 */
/* @0x30e0b2 stmvs r11!, {r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30e0b6 strbmi r4, [r8], #-1601 */
/* @0x30e0ba eorsvs r4, r3, r3, lsl #8 */
/* @0x30e0be mrrcvs p8, #0x2, r6, r8, c3 */
/* @0x30e0c2 mrc2 p7, #0x3, apsr_nzcv, c7, c15, #0x7 */
/* @0x30e0c6 ldrtmi r6, [r9], -r3, lsr #16 */
/* @0x30e0ca ldclvs p6, c4, [r8], {128} */
/* @0x30e0ce mrc2 p7, #0x3, apsr_nzcv, c1, c15, #0x7 */
/* @0x30e0d2 strbmi r6, [r0], #-2283 */
/* @0x30e0d6 rsbsvs r4, r0, r8, lsl r4 */
/* @0x30e0da .word 0x83f8e8bd */
/* @0x30e0de .word 0x4604b510 */
/* @0x30e0e2 stmdbvs r1!, {r0, r1, r11, sp, lr} ^ */
/* @0x30e0e6 .word 0xf7d96e58 */
/* @0x30e0ea movwhs pc, #0x925 */
/* @0x30e0ee .word 0x61236163 */
/* @0x30e0f2 ldrblt r11, [r0, #-0xd10]! */
/* @0x30e0f6 cmplt r8, r4, lsl #12 */
/* @0x30e0fa strhs r6, [r0, #-0x806] */
/* @0x30e0fe ldrtmi r6, [r0], -r1, ror #29 */
/* @0x30e102 .word 0xf918f7d9 */
/* @0x30e106 ldrtmi r6, [r0], -r5, ror #13 */
/* @0x30e10a .word 0xf7d96f61 */
/* @0x30e10e .word 0x6765f913 */
/* @0x30e112 ldrlt r11, [r8, #-0xd70]! */
/* @0x30e116 strhs r4, [r0, #-0x604] */
/* @0x30e11a stmibvs r1!, {r11, sp, lr} ^ */
/* @0x30e11e smulttvs r5, r5, r0 */
/* @0x30e122 .word 0xf7d961a5 */
/* @0x30e126 mvnvs pc, r7, lsl #18 */
/* @0x30e12a push {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x30e12e .word 0x460441f0 */
/* @0x30e132 strmi r6, [lr], -r3, lsl #18 */
/* @0x30e136 ldrtmi r11, [r0], -r11, asr #18 */
/* @0x30e13a .word 0xf7d96921 */
/* @0x30e13e stmdavs r3!, {r0, r1, r3, r4, r5, r6, r7, r11, r12, sp, lr, pc} ^ */
/* @0x30e142 .word 0x61252500 */
/* @0x30e146 stmiblt r3, {r3, r5, r7, r9, r10, lr} ^ */
/* @0x30e14a strhs lr, [r0, #-0xf] */
/* @0x30e14e stmvs r3!, {r0, r1, r2, r3, r5, r9, r10, lr} ^ */
/* @0x30e152 rscsle r4, r0, #-805306359 */
/* @0x30e156 ldrtmi r6, [r0], -r3, lsr #18 */
/* @0x30e15a eorne pc, r5, r3, asr r8 */
/* @0x30e15e .word 0xf8eaf7d9 */
/* @0x30e162 .word 0xf8436923 */
/* @0x30e166 strlo r7, [r1, #-0x25] */
/* @0x30e16a shsub8mi lr, r0, r1 */
/* @0x30e16e .word 0xf7d96861 */
/* @0x30e172 movwhs pc, #0x8e1 */
/* @0x30e176 pop {r0, r1, r5, r6, sp, lr} */
/* @0x30e17a stmdavs r3!, {r4, r5, r6, r7, r8, pc} */
/* @0x30e17e rscsle r4, r4, #-805306359 */
/* @0x30e182 rsceq r6, pc, r3, ror #16 */
/* @0x30e186 strlo r4, [r1, #-0x630] */
/* @0x30e18a ldmdavs r9, {r0, r1, r3, r4, r5, r10, lr} ^ */
/* @0x30e18e .word 0xf8d2f7d9 */
/* @0x30e192 ldrmi r6, [pc], #-2147 */
/* @0x30e196 andhi pc, r4, r7, asr #17 */
/* @0x30e19a ldrlt lr, [r8, #-0x7ef]! */
/* @0x30e19e stmdavs r3, {r2, r9, r10, lr} ^ */
/* @0x30e1a2 adchs pc, r0, #13828096 */
/* @0x30e1a6 .word 0x5c08f8d2 */
/* @0x30e1aa mrcvs p1, #0x0, r11, c11, c13, #0x2 */
/* @0x30e1ae ldmdavs r8, {r1, r2, r8, r11, lr} ^ */
/* @0x30e1b2 .word 0xf7d74479 */
/* @0x30e1b6 .word 0xb120fe9c */
/* @0x30e1ba ldrmi r6, [r8, r11, lsr #17] */
/* @0x30e1be ldrsblo pc, [r12], r4 */
/* @0x30e1c2 andhs r6, r0, r8, asr r2 */
/* @0x30e1c6 stmibeq r4!, {r3, r4, r5, r8, r10, r11, r12, sp, pc} ^ */
/* @0x30e1ca ldrblt r0, [r0, #-0x8]! */
/* @0x30e1ce strmi r2, [r5], -r4, asr #5 */
/* @0x30e1d2 strmi r4, [r8], -r12, lsl #12 */
/* @0x30e1d6 .word 0xf5a82100 */
/* @0x30e1da strtmi lr, [r10], -r10, ror #19 */
/* @0x30e1de svcne #0xbcf812 */
/* @0x30e1e2 eorvc r2, r1, #0, #6 */
/* @0x30e1e6 andle r4, r7, #-1342177272 */
/* @0x30e1ea streq lr, [r3], r2, lsl #22 */
/* @0x30e1ee subeq lr, r3, r4, lsl #22 */
/* @0x30e1f2 ldmdavs r6!, {r0, r8, r9, r12, sp} ^ */
/* @0x30e1f6 ldrb r8, [r5, r6, lsl #3]! */
/* @0x30e1fa umlalshs pc, sp, r5, r8 */
/* @0x30e1fe .word 0x01bcf105 */
/* @0x30e202 rsbvc r2, r2, #0, #6 */
/* @0x30e206 andle r4, r7, #805306377 */
/* @0x30e20a streq lr, [r3], r1, lsl #22 */
/* @0x30e20e subeq lr, r3, r4, lsl #22 */
/* @0x30e212 blvs 0x9ae1e */
/* @0x30e216 ldrb r8, [r5, r6, lsl #10]! */
/* @0x30e21a umlalshs pc, lr, r5, r8 */
/* @0x30e21e .word 0x01bcf105 */
/* @0x30e222 adcvc r2, r2, #0, #6 */
/* @0x30e226 andle r4, r7, #805306377 */
/* @0x30e22a streq lr, [r3], r1, lsl #22 */
/* @0x30e22e subeq lr, r3, r4, lsl #22 */
/* @0x30e232 cdpvs p3, #0x7, c3, c6, c1, #0x0 */
/* @0x30e236 ldrb r8, [r5, r6, lsl #15]! */
/* @0x30e23a umlalshs pc, pc, r5, r8 */
/* @0x30e23e .word 0x01bcf105 */
/* @0x30e242 rscvc r2, r2, #0, #6 */
/* @0x30e246 andle r4, r9, #805306377 */
/* @0x30e24a streq lr, [r3], r1, lsl #22 */
/* @0x30e24e subeq lr, r3, r4, lsl #22 */
/* @0x30e252 .word 0xf8d63301 */
/* @0x30e256 .word 0xf8a0609c */
/* @0x30e25a ubfx r6, r8, #0x0, #0x14 */
/* @0x30e25e .word 0x3180f8d5 */
/* @0x30e262 .word 0x01bcf105 */
/* @0x30e266 .word 0xf8d566e3 */
/* @0x30e26a strvs r3, [r3, -r4, lsl #3]! */
/* @0x30e26e .word 0x3188f8d5 */
/* @0x30e272 .word 0xf8d56763 */
/* @0x30e276 .word 0xf8a4318c */
/* @0x30e27a .word 0xf8d53078 */
/* @0x30e27e .word 0xf8a43190 */
/* @0x30e282 movwhs r3, #0x7a */
/* @0x30e286 .word 0x2194f895 */
/* @0x30e28a rsbshs pc, r12, r4, lsl #17 */
/* @0x30e28e andle r4, r9, #805306377 */
/* @0x30e292 streq lr, [r3], r1, lsl #22 */
/* @0x30e296 subeq lr, r3, r4, lsl #22 */
/* @0x30e29a .word 0xf8d63301 */
/* @0x30e29e .word 0xf8a060dc */
/* @0x30e2a2 ldrb r6, [r3, r0, lsl #1]! */
/* @0x30e2a6 .word 0x2195f895 */
/* @0x30e2aa .word 0x01bcf105 */
/* @0x30e2ae .word 0xf8842300 */
/* @0x30e2b2 addsmi r2, r3, #125 */
/* @0x30e2b6 bl 0x382ae2 <_ZTS13C_UTF16String+0x19b8e> */
/* @0x30e2ba bl 0x40fcce <g_RomDisk+0x184ae> */
/* @0x30e2be movwlo r0, #0x1043 */
/* @0x30e2c2 ldrsbvs pc, [r0, -r6] */
/* @0x30e2c6 addsvs pc, r10, r0, lsr #17 */
/* @0x30e2ca .word 0xf895e7f3 */
/* @0x30e2ce .word 0xf8843200 */
/* @0x30e2d2 .word 0xf8d5307e */
/* @0x30e2d6 .word 0xf8c4320c */
/* @0x30e2da .word 0xf8d530b8 */
/* @0x30e2de rsbvs r3, r3, r8, lsl #4 */
/* @0x30e2e2 ldrblt r11, [r3, #-0xd70]! */
/* @0x30e2e6 strmi r10, [r4], -r1, lsl #26 */
/* @0x30e2ea stcvc p6, c4, [r2], #-56 */
/* @0x30e2ee stmdavs r0, {r0, r3, r5, r9, r10, lr} */
/* @0x30e2f2 blx 0x164c25c <b2_toiTime+0xef2db8> */
/* @0x30e2f6 stmdblt r0, {r1, r9, r10, lr} ^ */
/* @0x30e2fa ldrmi r7, [r3], -r1, lsr #24 */
/* @0x30e2fe ble 0x45ed26 <g_RomDisk+0x67506> */
/* @0x30e302 andlo r5, r1, r12, lsr #24 */
/* @0x30e306 movwhs lr, #0x3a44 */
/* @0x30e30a movwhs lr, #0x7f8 */
/* @0x30e30e eorsvs r4, r2, r8, lsl r6 */
/* @0x30e312 ldcllt p0, c11, [r0, #-8]! */
/* @0x30e316 svcmi #0xf7e92d */
/* @0x30e31a .word 0x460d469a */
/* @0x30e31e ldrmi r2, [r1], r0, lsl #6 */
/* @0x30e322 strmi r9, [r4], -r1, lsl #6 */
/* @0x30e326 rsble r2, r1, r0, lsl #16 */
/* @0x30e32a addmi r6, r10, #12713984 */
/* @0x30e32e stmibvs r3, {r1, r2, r3, r4, r6, r8, r11, r12, lr, pc} ^ */
/* @0x30e332 .word 0x8000f8d0 */
/* @0x30e336 stmvs r1, {r0, r1, r5, r8, r9, r11, r12, sp, pc} */
/* @0x30e33a strmi r6, [r11], #-2115 */
/* @0x30e33e strbmi r7, [r0], -r1, lsl #24 */
/* @0x30e342 .word 0x3105fb01 */
/* @0x30e346 blx 0xfeecc2ae <b2_toiTime+0xfffffffffe772e0a> */
/* @0x30e34a stmdahs r0, {r0, r12, pc} */
/* @0x30e34e .word 0xf10dd150 */
/* @0x30e352 strtmi r0, [r0], -r4, lsl #22 */
/* @0x30e356 .word 0xf7ff4659 */
/* @0x30e35a blls 0x38e272 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x22ce> */
/* @0x30e35e blhs 0x31fb82 */
/* @0x30e362 stmdblt r8!, {r1, r2, r6, r8, r12, lr, pc} */
/* @0x30e366 strmi r2, [r7], -r0 */
/* @0x30e36a stmvs r3!, {r2, r4, sp, lr, pc} ^ */
/* @0x30e36e andsle r4, r1, #-805306359 */
/* @0x30e372 ldrbmi r4, [r9], -r0, lsr #12 */
/* @0x30e376 .word 0xf7ff3501 */
/* @0x30e37a stmdahs r0, {r2, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30e37e strd sp, lr, [r9], -r5 */
/* @0x30e382 eorvc pc, r1, r3, asr r8 */
/* @0x30e386 rscle r2, sp, r0, lsl #30 */
/* @0x30e38a .word 0xf8533501 */
/* @0x30e38e stmdblt r8, {r0, r2, r5} */
/* @0x30e392 .word 0xd3f94295 */
/* @0x30e396 .word 0x2004f8d8 */
/* @0x30e39a andlo r6, r1, #1622016 */
/* @0x30e39e stmdale r2, {r4, r7, r9, lr} */
/* @0x30e3a2 addmi r1, r11, #69632 */
/* @0x30e3a6 bne 0xff7447ae <b2_toiTime+0xfffffffffefeb30a> */
/* @0x30e3aa adcsmi r11, r8, #-1073741771 */
/* @0x30e3ae blne 0xff4c4816 <b2_toiTime+0xfffffffffed6b372> */
/* @0x30e3b2 andvs pc, r0, r10, asr #17 */
/* @0x30e3b6 .word 0xb1236a23 */
/* @0x30e3ba ldrtmi r3, [r11], #-3841 */
/* @0x30e3be andlo pc, r0, r9, asr #17 */
/* @0x30e3c2 stmdbvs r1!, {r1, r2, r4, sp, lr, pc} ^ */
/* @0x30e3c6 stmdblo r1, {r6, r9, r10, lr} */
/* @0x30e3ca .word 0xf7d84439 */
/* @0x30e3ce andls pc, r1, r11, ror #20 */
/* @0x30e3d2 .word 0x4640b970 */
/* @0x30e3d6 .word 0x464a4631 */
/* @0x30e3da stc2l p7, c15, [r2, #-868]! */
/* @0x30e3de and r9, r7, r1 */
/* @0x30e3e2 .word 0xf8c92300 */
/* @0x30e3e6 .word 0xf8ca3000 */
/* @0x30e3ea and r3, r1, r0 */
/* @0x30e3ee movwls r2, #0x1306 */
/* @0x30e3f2 andlt r9, r3, r1, lsl #16 */
/* @0x30e3f6 svchi #0xf0e8bd */
/* @0x30e3fa .word 0xf890b510 */
/* @0x30e3fe stmdbvs r4, {r0, r6, r12, sp} ^ */
/* @0x30e402 stmdahi r2!, {r0, r1, r5, r8, r11, r12, sp, pc} */
/* @0x30e406 andlo r4, r1, #24, #12 */
/* @0x30e40a ldclt p0, c8, [r0, #-136] */
/* @0x30e40e rfeib r0! */
/* @0x30e412 rfeib r0! */
/* @0x30e416 ldrmi r2, [r10], #-20 */
/* @0x30e41a andlo r6, r1, #8585216 */
/* @0x30e41e stmdale r12, {r1, r3, r4, r7, r9, lr} */
/* @0x30e422 strhlo pc, [r0], -r4 */
/* @0x30e426 vstrle d2, [pc, #-0] */
/* @0x30e42a movwmi pc, #0x103 */
/* @0x30e42e stmdahi r1!, {r1, r5, r6, r7, r11, sp, lr} ^ */
/* @0x30e432 stmdblo r1, {r0, r8, r9, r11, r12, sp} */
/* @0x30e436 andsne pc, r3, r2, lsr #16 */
/* @0x30e43a .word 0x2100e006 */
/* @0x30e43e .word 0xf7d92201 */
/* @0x30e442 stmdahs r0, {r0, r5, r6, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30e446 ldclt p0, c13, [r0, #-944] */
/* @0x30e44a andhs r8, r0, r3, lsr #16 */
/* @0x30e44e eorhi r3, r3, r1, lsl #6 */
/* @0x30e452 push {r4, r8, r10, r11, r12, sp, pc} */
/* @0x30e456 ssub8mi r4, sp, r7 */
/* @0x30e45a .word 0xb10b9201 */
/* @0x30e45e eorvs r2, r11, r0, lsl #6 */
/* @0x30e462 subls pc, r0, #14614528 */
/* @0x30e466 ldrtmi r2, [r4], r0, lsl #12 */
/* @0x30e46a andhs r4, r4, #52, #12 */
/* @0x30e46e strls r2, [r0], -r10, lsl #14 */
/* @0x30e472 andlo r11, r1, r10, lsl r1 */
/* @0x30e476 .word 0xf0804288 */
/* @0x30e47a stmdavc r3, {r0, r1, r2, r8, pc} */
/* @0x30e47e .word 0xf1c24113 */
/* @0x30e482 .word 0xf0030204 */
/* @0x30e486 blhs 0x68f0ca <g_SWFlinevertbuff+0x3c002> */
/* @0x30e48a movwhs sp, #0x1102 */
/* @0x30e48e strb r9, [pc, r0, lsl #6]! */
/* @0x30e492 .word 0xdc0b2b09 */
/* @0x30e496 stcle p5, c4, [r2, #-304] */
/* @0x30e49a .word 0x0c01f10c */
/* @0x30e49e stmdblt r11, {r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x30e4a2 rscle r2, r5, r0, lsl #24 */
/* @0x30e4a6 blx 0x4dbcb4 <SrcVerts+0x38cf8> */
/* @0x30e4aa strb r3, [r1, r4, lsl #8]! */
/* @0x30e4ae .word 0xf04f2b0a */
/* @0x30e4b2 tstle r12, r0, lsl #14 */
/* @0x30e4b6 .word 0xa1ecf8df */
/* @0x30e4ba .word 0xb11a4699 */
/* @0x30e4be addmi r3, r8, #1 */
/* @0x30e4c2 rschi pc, r2, r0, lsl #1 */
/* @0x30e4c6 tstmi r3, r3, lsl #16 */
/* @0x30e4ca andeq pc, r4, #-2147483600 */
/* @0x30e4ce movweq pc, #0xf003 */
/* @0x30e4d2 .word 0xdc0c2b09 */
/* @0x30e4d6 ldmdblt r4, {r0, r1, r3, r4, r8, r11, r12, sp, pc} */
/* @0x30e4da ldcllo p1, c15, [pc], #48 */
/* @0x30e4de ldrbmi lr, [r4, #-0x7ed] */
/* @0x30e4e2 svchs #0x8dceb */
/* @0x30e4e6 strlo sp, [r1, -r9, ror #25] */
/* @0x30e4ea strlo pc, [r4], #-2825 */
/* @0x30e4ee blhs 0x64848a <g_SWFaavertbuff+0x753c2> */
/* @0x30e4f2 blhs 0x60250e <g_SWFaavertbuff+0x2f446> */
/* @0x30e4f6 .word 0xf04fbf08 */
/* @0x30e4fa teqle r1, r0, lsl #18 */
/* @0x30e4fe .word 0xf04fe001 */
/* @0x30e502 .word 0xf04f0901 */
/* @0x30e506 ldrbmi r0, [r3], -r0, lsl #20 */
/* @0x30e50a andlo r11, r1, r10, lsl r1 */
/* @0x30e50e .word 0xf0804288 */
/* @0x30e512 .word 0xf89080bb */
/* @0x30e516 blx 0x15fa51e <b2_toiTime+0xea107a> */
/* @0x30e51a .word 0xf1c2fb02 */
/* @0x30e51e .word 0xf00b0204 */
/* @0x30e522 .word 0xf1bb0b0f */
/* @0x30e526 .word 0xdc0a0f09 */
/* @0x30e52a svcvc #0x7af5b3 */
/* @0x30e52e .word 0xf04fdd02 */
/* @0x30e532 strb r0, [r9, r1, lsl #20]! */
/* @0x30e536 stmdaeq r10, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x30e53a movwlt pc, #0x3b08 */
/* @0x30e53e .word 0xf1b9e7e4 */
/* @0x30e542 andle r0, r0, r0, lsl #30 */
/* @0x30e546 .word 0x2c00425b */
/* @0x30e54a adchi pc, r3, r0 */
/* @0x30e54e svceq #0xf1ba */
/* @0x30e552 .word 0xf1b9d00a */
/* @0x30e556 svclt #0x140f00 */
/* @0x30e55a .word 0xf06f2000 */
/* @0x30e55e adds r4, r9, r0 */
/* @0x30e562 .word 0xf0002c00 */
/* @0x30e566 movwhs r8, #0x96 */
/* @0x30e56a ldrmi r9, [r4], #2561 */
/* @0x30e56e bl 0x3df702 <error_g0017+0x383a6> */
/* @0x30e572 stchs p9, c0, [r0, #-24] */
/* @0x30e576 ldrtmi sp, [lr], #-74 */
/* @0x30e57a bvc 0x30be9e <af_shaper_get_elem+0x170c> */
/* @0x30e57e stcle p14, c2, [r9], #-20 */
/* @0x30e582 stcle p5, c4, [r7, #-336] */
/* @0x30e586 .word 0x210a4620 */
/* @0x30e58a streq lr, [r9], -r6, asr #23 */
/* @0x30e58e ldc2 p7, c15, [r2], {214} */
/* @0x30e592 ands r3, sp, r1, lsl #12 */
/* @0x30e596 svceq #0xf1b9 */
/* @0x30e59a .word 0xf1b9dd17 */
/* @0x30e59e svclt #0xb40f05 */
/* @0x30e5a2 strhs r4, [r5, -pc, asr #12] */
/* @0x30e5a6 blhs 0x31549a <FT_Bitmap_Embolden+0x654> */
/* @0x30e5aa bmi 0x12c59ee <b2_toiTime+0xb6c54a> */
/* @0x30e5ae streq lr, [r9], -r7, asr #23 */
/* @0x30e5b2 .word 0xf852447a */
/* @0x30e5b6 cmpmi r12, #35 */
/* @0x30e5ba stcle p5, c4, [r8, #-336] */
/* @0x30e5be .word 0x210a4620 */
/* @0x30e5c2 bl 0xfecca5f2 <b2_toiTime+0xfffffffffe57114e> */
/* @0x30e5c6 strmi r3, [r4], -r1, lsl #12 */
/* @0x30e5ca bl 0xff4c65d6 <b2_toiTime+0xfffffffffed6d132> */
/* @0x30e5ce strteq r0, [r0], #-1545 */
/* @0x30e5d2 subs r6, pc, lr, lsr #32 */
/* @0x30e5d6 ldrsblt pc, [r4], #143 */
/* @0x30e5da qsub16mi r1, r0, r3 */
/* @0x30e5de .word 0xf85b44fb */
/* @0x30e5e2 ldrtmi r7, [r9], -r3, lsr #32 */
/* @0x30e5e6 bl 0xfe84a616 <b2_toiTime+0xfffffffffe0f1172> */
/* @0x30e5ea stcle p5, c4, [r8, #-320] */
/* @0x30e5ee strtmi r3, [r0], -r4, lsl #28 */
/* @0x30e5f2 eorne pc, r6, r11, asr r8 */
/* @0x30e5f6 streq pc, [r4], -r9, lsr #3 */
/* @0x30e5fa mrrc2 p7, #0xd, pc, r12, c6 */
/* @0x30e5fe strtmi lr, [r0], -r8, ror #15 */
/* @0x30e602 .word 0xf7d64639 */
/* @0x30e606 .word 0xf1a9fc57 */
/* @0x30e60a strb r0, [r1, r5, lsl #12]! */
/* @0x30e60e svceq #0x5f1b9 */
/* @0x30e612 .word 0xf119dc3c */
/* @0x30e616 blle 0x1052232 <b2_toiTime+0x8f8d8e> */
/* @0x30e61a svceq #0xf1b9 */
/* @0x30e61e streq lr, [r7, -r3, asr #23] */
/* @0x30e622 blmi 0xbc4e52 <b2_toiTime+0x46b9ae> */
/* @0x30e626 andeq pc, r0, #1073741874 */
/* @0x30e62a strbmi r4, [pc], #-1568 */
/* @0x30e62e .word 0xf853447b */
/* @0x30e632 .word 0xf00a1022 */
/* @0x30e636 strmi lr, [r4], -r12, ror #22 */
/* @0x30e63a .word 0xf6472f0a */
/* @0x30e63e strdle r7, r8, [r6, -pc] */
/* @0x30e642 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x30e646 bl 0x1c4a676 <b2_toiTime+0x14f11d2> */
/* @0x30e64a strmi r2, [r4], -r9, lsl #14 */
/* @0x30e64e svchs #0xe001 */
/* @0x30e652 blmi 0x905a92 <b2_toiTime+0x1ac5ee> */
/* @0x30e656 ldrbtmi r4, [r11], #-1568 */
/* @0x30e65a eorvs pc, r7, r3, asr r8 */
/* @0x30e65e .word 0xf00a4631 */
/* @0x30e662 adcmi lr, r8, #88064 */
/* @0x30e666 qadd16mi sp, r0, r0 */
/* @0x30e66a .word 0xf7d64631 */
/* @0x30e66e ands pc, r1, r3, lsr #24 */
/* @0x30e672 rsbsmi r4, pc, #69632 */
/* @0x30e676 .word 0xf852447a */
/* @0x30e67a movtmi r0, #0x4027 */
/* @0x30e67e .word 0xdc0542ac */
/* @0x30e682 and r0, r7, r0, lsr #8 */
/* @0x30e686 and r4, r5, r8, lsr #12 */
/* @0x30e68a and r2, r3, r0 */
/* @0x30e68e andmi pc, r0, pc, rrx */
/* @0x30e692 strtmi lr, [r0], -r0 */
/* @0x30e696 .word 0xb1039b00 */
/* @0x30e69a andlt r4, r3, r0, asr #4 */
/* @0x30e69e svchi #0xf0e8bd */
/* @0x30e6a2 stclgt p15, c11, [r11], {0} */
/* @0x30e6a6 rsbpl r0, r6, #204, #24 */
/* @0x30e6aa eorspl r0, r10, #9 */
/* @0x30e6ae mvnpl r0, r9 */
/* @0x30e6b2 bicpl r0, r0, r9 */
/* @0x30e6b6 movpl r0, r9 */
/* @0x30e6ba addlt r0, r2, r9 */
/* @0x30e6be svcmi #0xf0e92d */
/* @0x30e6c2 .word 0x4604b095 */
/* @0x30e6c6 tstls pc, #24117248 */
/* @0x30e6ca teqpl r7, #4, #10 */
/* @0x30e6ce ldmdavs lr!, {r1, r3, r7, r9, r10, lr} */
/* @0x30e6d2 .word 0xf89d6a5a */
/* @0x30e6d6 bhs 0x38e8ee <_ZTS7CBucketILj16384ELj262144ELb1EE+0x294a> */
/* @0x30e6da .word 0xf103bf0b */
/* @0x30e6de .word 0xf5040830 */
/* @0x30e6e2 .word 0xf1035838 */
/* @0x30e6e6 .word 0xf1030928 */
/* @0x30e6ea .word 0xf8d80938 */
/* @0x30e6ee andls r1, r6, r0 */
/* @0x30e6f2 strhle r4, [r5, -r1] */
/* @0x30e6f6 .word 0x2004f8d8 */
/* @0x30e6fa addsmi r6, r10, #8060928 */
/* @0x30e6fe sbchi pc, r7, r0 */
/* @0x30e702 .word 0x3004f8d9 */
/* @0x30e706 .word 0x2000f8d9 */
/* @0x30e70a ldrsbtlt pc, [r12], #-141 */
/* @0x30e70e andls r9, r7, #8, #6 */
/* @0x30e712 streq lr, [r11, #-0xbc6] */
/* @0x30e716 .word 0x3004f8d8 */
/* @0x30e71a bls 0x51bb62 <SrcVerts+0x78ba6> */
/* @0x30e71e bl 0xff392cda <b2_toiTime+0xfffffffffec39836> */
/* @0x30e722 ldmdavs r10!, {r0, r1, r10, r11} ^ */
/* @0x30e726 .word 0xf10c9b20 */
/* @0x30e72a andls r0, r9, #16, #24 */
/* @0x30e72e .word 0x1c6cea4f */
/* @0x30e732 bne 0xfe9f334e <b2_toiTime+0xfffffffffe299eaa> */
/* @0x30e736 tstlo r0, #28672 */
/* @0x30e73a andsgt pc, r0, sp, asr #17 */
/* @0x30e73e cmpne r11, r9, lsl #21 */
/* @0x30e742 andseq pc, r0, r1, lsl #2 */
/* @0x30e746 ldrmi r9, [r9], -r3, lsl #6 */
/* @0x30e74a .word 0xf7ff1140 */
/* @0x30e74e .word 0xf8ddfb32 */
/* @0x30e752 qadd16mi r12, r9, r0 */
/* @0x30e756 strbtmi r4, [r0], -r2, lsl #12 */
/* @0x30e75a .word 0xf7ff9204 */
/* @0x30e75e bls 0x44d40e <g_RomDisk+0x55bee> */
/* @0x30e762 bne 0x7b5376 <b2_toiTime+0x5bed2> */
/* @0x30e766 msrhi APSR_nzcvqg, r0 */
/* @0x30e76a ldrmi r9, [r9], -r7, lsl #16 */
/* @0x30e76e bne 0x10b2f86 <b2_toiTime+0x959ae2> */
/* @0x30e772 andseq pc, r0, r6, lsl #2 */
/* @0x30e776 .word 0xf7ff1140 */
/* @0x30e77a blls 0x58d3f2 <g_SWFlineaavertbuff+0x3a32a> */
/* @0x30e77e strmi r9, [r6], -r8, lsl #18 */
/* @0x30e782 andslo r1, r0, r8, asr r10 */
/* @0x30e786 .word 0x11404629 */
/* @0x30e78a blx 0x80c790 <b2_toiTime+0xb32ec> */
/* @0x30e78e ldrmi r9, [r1], -r4, lsl #20 */
/* @0x30e792 .word 0xf7d61a30 */
/* @0x30e796 .word 0xf8d9fb8f */
/* @0x30e79a .word 0xf8d86000 */
/* @0x30e79e blne 0xfe5527a6 <b2_toiTime+0xfffffffffddf9302> */
/* @0x30e7a2 .word 0xf7ff9003 */
/* @0x30e7a6 blls 0x40d3c6 <g_RomDisk+0x15ba6> */
/* @0x30e7aa .word 0x5004f8d9 */
/* @0x30e7ae .word 0x1004f8d8 */
/* @0x30e7b2 strmi r1, [r6], #-2889 */
/* @0x30e7b6 .word 0xf7ff4618 */
/* @0x30e7ba .word 0xf8d9fafc */
/* @0x30e7be .word 0xf8d83000 */
/* @0x30e7c2 addsmi r2, r3, #0 */
/* @0x30e7c6 teqpl r6, #4, #10 */
/* @0x30e7ca strmi r9, [r5], #-520 */
/* @0x30e7ce bne 0xfef42bf6 <b2_toiTime+0xfffffffffe7e9752> */
/* @0x30e7d2 blvs 0x19b4bfa <b2_toiTime+0x125b756> */
/* @0x30e7d6 svclt #0xb82800 */
/* @0x30e7da addsmi r4, r0, #64, #4 */
/* @0x30e7de .word 0x460ebfb8 */
/* @0x30e7e2 .word 0x2004f8d9 */
/* @0x30e7e6 .word 0x0004f8d8 */
/* @0x30e7ea smlabble r10, r2, r2, r4 */
/* @0x30e7ee .word 0x0c05ebc0 */
/* @0x30e7f2 .word 0xf1bc6b5a */
/* @0x30e7f6 svclt #0xb80f00 */
/* @0x30e7fa .word 0x0c00f1cc */
/* @0x30e7fe svclt #0xb84594 */
/* @0x30e802 .word 0xf8d74605 */
/* @0x30e806 ldrbmi r12, [r12] */
/* @0x30e80a bl 0xff602c3a <b2_toiTime+0xfffffffffeea9796> */
/* @0x30e80e blvs 0x1990c2e <b2_toiTime+0x123778a> */
/* @0x30e812 svceq #0xf1b9 */
/* @0x30e816 .word 0xf1c9bfb8 */
/* @0x30e81a ldrmi r0, [r1, #0x900] */
/* @0x30e81e .word 0x465ebfb8 */
/* @0x30e822 stmdbls r5, {r1, r3, r4, r5, r6, r11, sp, lr} */
/* @0x30e826 andls r4, r7, #-1610612728 */
/* @0x30e82a .word 0xf504d10d */
/* @0x30e82e bl 0xff364d0e <b2_toiTime+0xfffffffffec0b86a> */
/* @0x30e832 .word 0xf1bb0b05 */
/* @0x30e836 svclt #0xb80f00 */
/* @0x30e83a bleq 0x34af6e */
/* @0x30e83e ldrsbtls pc, [r4], -r9 */
/* @0x30e842 svclt #0xb845cb */
/* @0x30e846 stmdbls r8, {r0, r2, r3, r9, r10, lr} */
/* @0x30e84a strbtmi r6, [r1], #-2843 */
/* @0x30e84e bicsvc lr, r1, r1, lsl #22 */
/* @0x30e852 stmdbeq r1!, {r1, r2, r4, r5, r7, r8, r9, r11, sp, lr, pc} ^ */
/* @0x30e856 .word 0x0161ea4f */
/* @0x30e85a bl 0xff4be592 <b2_toiTime+0xfffffffffed650ee> */
/* @0x30e85e strbmi r0, [r9], -r1, lsl #2 */
/* @0x30e862 .word 0xdc164299 */
/* @0x30e866 ldrmi r9, [r0], #-2567 */
/* @0x30e86a sbcsvc lr, r0, r0, lsl #22 */
/* @0x30e86e strheq lr, [r0, #-181]! */
/* @0x30e872 rsbeq lr, r0, pc, asr #20 */
/* @0x30e876 bl 0xff47e5ae <b2_toiTime+0xfffffffffed2510a> */
/* @0x30e87a strmi r0, [r8], -r0 */
/* @0x30e87e .word 0xdc084298 */
/* @0x30e882 andvs pc, r0, r8, asr #17 */
/* @0x30e886 bleq 0x38a9ca <bigtens_D2A+0xe9a> */
/* @0x30e88a andpl pc, r4, r8, asr #17 */
/* @0x30e88e strhs lr, [r0, #-0x3] */
/* @0x30e892 .word 0xf04f462e */
/* @0x30e896 .word 0xf5040b00 */
/* @0x30e89a .word 0xf10d5c37 */
/* @0x30e89e .word 0xf10c082c */
/* @0x30e8a2 .word 0xf8dc0910 */
/* @0x30e8a6 ldm r9, {r2, r5, r12, sp} */
/* @0x30e8aa blhs 0x38e8be <_ZTS7CBucketILj16384ELj262144ELb1EE+0x291a> */
/* @0x30e8ae andeq lr, r3, r8, lsl #17 */
/* @0x30e8b2 blhs 0x44296e <g_RomDisk+0x4b14e> */
/* @0x30e8b6 tstls r3, #-2147483629 */
/* @0x30e8ba .word 0xf8dc4620 */
/* @0x30e8be uasxmi r3, r1, r4 */
/* @0x30e8c2 andeq pc, r8, #8, #2 */
/* @0x30e8c6 .word 0xf8dc9300 */
/* @0x30e8ca .word 0xf8cd3030 */
/* @0x30e8ce .word 0xf7ffc010 */
/* @0x30e8d2 .word 0xf8ddfbcc */
/* @0x30e8d6 qadd16mi r12, r0, r0 */
/* @0x30e8da cpsie f */
/* @0x30e8de .word 0xf8dc0210 */
/* @0x30e8e2 movwls r3, #0x3c */
/* @0x30e8e6 ldrsbtlo pc, [r8], -r12 */
/* @0x30e8ea blx 0xff30c8f0 <b2_toiTime+0xfffffffffebb344c> */
/* @0x30e8ee teqpl r8, #4, #10 */
/* @0x30e8f2 ldrbmi r4, [r1], -r0, lsr #12 */
/* @0x30e8f6 andls r6, r0, #5898240 */
/* @0x30e8fa andseq pc, r8, #8, #2 */
/* @0x30e8fe .word 0xf7ff681b */
/* @0x30e902 stmdavs r0!, {r2, r4, r5, r7, r8, r9, r11, r12, sp, lr, pc} ^ */
/* @0x30e906 stmvs r3, {r0, r6, r9, r10, lr} ^ */
/* @0x30e90a blge 0x760772 <b2_toiTime+0x72ce> */
/* @0x30e90e tstls r3, #30 */
/* @0x30e912 andeq pc, r8, #8, #2 */
/* @0x30e916 ldrsbtlo pc, [r4], -r12 */
/* @0x30e91a movwls r9, #0x806 */
/* @0x30e91e qadd16mi r11, r0, r8 */
/* @0x30e922 .word 0x7124f604 */
/* @0x30e926 strtmi lr, [r0], -r1 */
/* @0x30e92a .word 0xf8dc4651 */
/* @0x30e92e .word 0xf7ff3030 */
/* @0x30e932 blls 0x68d7aa <g_SWFlinevertbuff+0x3a6e2> */
/* @0x30e936 addsmi r9, r10, #45056 */
/* @0x30e93a blls 0x6c2d4e <g_SWFlinevertbuff+0x6fc86> */
/* @0x30e93e addsmi r9, r10, #12, #20 */
/* @0x30e942 stmdavs r0!, {r3, r12, lr, pc} ^ */
/* @0x30e946 stmdavs r3, {r0, r6, r9, r10, lr} ^ */
/* @0x30e94a blge 0x6607b2 <g_SWFlinevertbuff+0xd6ea> */
/* @0x30e94e muleq r3, r3, r8 */
/* @0x30e952 andeq lr, r3, r9, lsl #17 */
/* @0x30e956 svceq #0xf1bb */
/* @0x30e95a stmdbls r6, {r2, r12, lr, pc} */
/* @0x30e95e eorsvs r11, lr, r1, lsr #18 */
/* @0x30e962 eor r6, pc, sp, ror r0 */
/* @0x30e966 .word 0xb12a9a06 */
/* @0x30e96a qsub16mi r6, r0, r11 */
/* @0x30e96e .word 0x7124f604 */
/* @0x30e972 and r9, r3, r0, lsl #6 */
/* @0x30e976 qsub16mi r6, r0, r11 */
/* @0x30e97a movwls r4, #0x651 */
/* @0x30e97e andeq pc, r8, #8, #2 */
/* @0x30e982 .word 0xf7ff683b */
/* @0x30e986 .word 0xf504fb72 */
/* @0x30e98a stmdbls sp, {r0, r1, r2, r4, r5, r8, r9, r12, lr} */
/* @0x30e98e addsmi r6, r1, #425984 */
/* @0x30e992 ldmdbvs r10, {r0, r1, r8, r12, lr, pc} ^ */
/* @0x30e996 addsmi r9, r3, #14336 */
/* @0x30e99a ldm r9, {r1, r2, r3, r12, lr, pc} */
/* @0x30e99e movwhs r0, #0x2003 */
/* @0x30e9a2 stm r8, {r0, r1, r4, r8, r9, r12, pc} */
/* @0x30e9a6 strbmi r0, [r1], -r3 */
/* @0x30e9aa stmdavs r3, {r5, r6, r11, sp, lr} ^ */
/* @0x30e9ae blge 0x660816 <g_SWFlinevertbuff+0xd74e> */
/* @0x30e9b2 muleq r3, r3, r8 */
/* @0x30e9b6 andeq lr, r3, r9, lsl #17 */
/* @0x30e9ba svceq #0xf1bb */
/* @0x30e9be strb sp, [lr, r2] */
/* @0x30e9c2 .word 0xe7654615 */
/* @0x30e9c6 pop {r0, r2, r4, r12, sp, pc} */
/* @0x30e9ca strdlt r4, r5, [r2], -r0 */
/* @0x30e9ce ldrblt r4, [r0, #0x770]! */
/* @0x30e9d2 stmvs r6, {r0, r2, r7, r12, sp, pc} */
/* @0x30e9d6 strmi r4, [r4], -sp, lsl #12 */
/* @0x30e9da .word 0xf06f6807 */
/* @0x30e9de movwhs r4, #0x0 */
/* @0x30e9e2 movwls r4, #0x3631 */
/* @0x30e9e6 ldmdb r0!, {r1, r3, r12, sp, lr, pc} */
/* @0x30e9ea ldmdale r10, {r0, r2, r7, r9, lr} */
/* @0x30e9ee stmibvs r3!, {r1, r2, r3, r5, r6, r8, r9, lr} ^ */
/* @0x30e9f2 .word 0x21014638 */
/* @0x30e9f6 movwls r6, #0x9a2 */
/* @0x30e9fa movwls r10, #0x1b03 */
/* @0x30e9fe .word 0xf7d94633 */
/* @0x30ea02 svcls #0x3fb45 */
/* @0x30ea06 stmdblt r7!, {r5, r6, r7, r8, sp, lr} ^ */
/* @0x30ea0a rscvs r6, r5, r3, ror #18 */
/* @0x30ea0e .word 0x61a642ab */
/* @0x30ea12 stmdavs r0!, {r0, r2, r8, r11, r12, lr, pc} ^ */
/* @0x30ea16 .word 0xf7ff2182 */
/* @0x30ea1a .word 0x6165fa13 */
/* @0x30ea1e andhs lr, r1, r5 */
/* @0x30ea22 stmdavs r0!, {r2, sp, lr, pc} ^ */
/* @0x30ea26 .word 0xf7ff2140 */
/* @0x30ea2a andhs pc, r0, r11, lsl #20 */
/* @0x30ea2e ldcllt p0, c11, [r0, #20]! */
/* @0x30ea32 svcmi #0xf0e92d */
/* @0x30ea36 stmdavs r6, {r0, r2, r3, r7, r12, sp, pc} ^ */
/* @0x30ea3a movwls r4, #0x6604 */
/* @0x30ea3e movwhs r4, #0x615 */
/* @0x30ea42 ldmvs r7!, {r0, r1, r8, r12, pc} */
/* @0x30ea46 andvc r9, r3, r11, lsl #6 */
/* @0x30ea4a tstlt r10, r5, lsl #14 */
/* @0x30ea4e stclo p8, c15, [r12], #-728 */
/* @0x30ea52 .word 0xd133429a */
/* @0x30ea56 stclo p8, c15, [r4], #-856 */
/* @0x30ea5a addsmi r9, pc, #3, #30 */
/* @0x30ea5e .word 0xf8d6d22e */
/* @0x30ea62 .word 0x21013c28 */
/* @0x30ea66 bl 0x3e8ff6 <tt_cmap2_class_rec+0xa> */
/* @0x30ea6a strls r0, [r8, -r7, asr #15] */
/* @0x30ea6e addseq r9, r2, r3, lsl #30 */
/* @0x30ea72 .word 0xf8539805 */
/* @0x30ea76 svcge #0xb3037 */
/* @0x30ea7a .word 0xf1039701 */
/* @0x30ea7e stmibvs r3!, {r0, r11} */
/* @0x30ea82 movwls r9, #0x707 */
/* @0x30ea86 orreq lr, r8, #323584 */
/* @0x30ea8a blx 0x34c9f8 */
/* @0x30ea8e lslvs r9, r11, #20 */
/* @0x30ea92 .word 0xf0402a00 */
/* @0x30ea96 .word 0xf8c48085 */
/* @0x30ea9a .word 0x46928014 */
/* @0x30ea9e svcls #0x8e01a */
/* @0x30eaa2 orrmi pc, r0, #-2147483646 */
/* @0x30eaa6 .word 0xf8d63b01 */
/* @0x30eaaa .word 0xf8d60c30 */
/* @0x30eaae ldmdavs r9!, {r2, r4, r5, r10, r11, sp} ^ */
/* @0x30eab2 stmibeq r3, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x30eab6 eorlo pc, r3, r1, asr r8 */
/* @0x30eaba movwle r4, #0xe283 */
/* @0x30eabe movwls r2, #0xb303 */
/* @0x30eac2 .word 0xf1bae06e */
/* @0x30eac6 mvnle r0, r0, lsl #30 */
/* @0x30eaca vst2.32 {d22, d24}, [pc:128], r3 */
/* @0x30eace andsvs r3, r8, r0, lsl #1 */
/* @0x30ead2 beq 0x38af02 <bigtens_D2A+0x13d2> */
/* @0x30ead6 .word 0xd3f445c2 */
/* @0x30eada stmibvs r1!, {r0, r3, r6, sp, lr, pc} */
/* @0x30eade strbmi r11, [r9], #-2325 */
/* @0x30eae2 ldrb r6, [r5, sp, asr #32]! */
/* @0x30eae6 stmdbeq r4, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x30eaea bleq 0x34ac2e */
/* @0x30eaee addlo pc, r0, pc, asr #8 */
/* @0x30eaf2 addeq lr, r3, #2048 */
/* @0x30eaf6 andeq pc, r9, r1, asr #16 */
/* @0x30eafa .word 0x210c9209 */
/* @0x30eafe blx 0x37532c <_ZTS13C_UTF16String+0xc3d8> */
/* @0x30eb02 ldmdavs r0, {r0, r1, r3, r8, r9, r12, sp, lr, pc} */
/* @0x30eb06 stmpl r2, {r0, r6, r7, r11, r12} ^ */
/* @0x30eb0a addsmi r6, r10, #4915200 */
/* @0x30eb0e stmvs r9, {r0, r1, r2, r3, r4, r10, r11, r12, lr, pc} */
/* @0x30eb12 .word 0xdc1c428b */
/* @0x30eb16 ble 0x35931e */
/* @0x30eb1a .word 0xdc182900 */
/* @0x30eb1e svcls #0x6b1bb */
/* @0x30eb22 eoreq pc, r11, r7, asr r8 */
/* @0x30eb26 blle 0x71f56e <g_SWFvertbuff+0x4c4a6> */
/* @0x30eb2a .word 0xdc0e4288 */
/* @0x30eb2e mulle lr, r8, r2 */
/* @0x30eb32 bl 0xff33e9e6 <b2_toiTime+0xfffffffffebe5542> */
/* @0x30eb36 bl 0xff38eb42 <b2_toiTime+0xfffffffffec3569e> */
/* @0x30eb3a bl 0xff3cef4e <b2_toiTime+0xfffffffffec75aaa> */
/* @0x30eb3e bl 0xff38ef4a <b2_toiTime+0xfffffffffec35aa6> */
/* @0x30eb42 .word 0xf7d60000 */
/* @0x30eb46 .word 0x4601f9b7 */
/* @0x30eb4a .word 0x2100e003 */
/* @0x30eb4e vst4.8 {d30, d31, d0, d1}, [pc], r1 */
/* @0x30eb52 stmibvs r3!, {r7, r8, r12, sp} */
/* @0x30eb56 bleq 0x38af8a <_pcre_utt+0x2e> */
/* @0x30eb5a andeq pc, r9, r3, asr r8 */
/* @0x30eb5e .word 0xf7d69304 */
/* @0x30eb62 blls 0x44d13a <g_RomDisk+0x5591a> */
/* @0x30eb66 .word 0xf84345ab */
/* @0x30eb6a bicle r0, r6, r9 */
/* @0x30eb6e svcls #0x3e7b0 */
/* @0x30eb72 orrslt r6, r5, r7, lsr #1 */
/* @0x30eb76 adceq r6, lr, r3, lsr #18 */
/* @0x30eb7a stmdage r11, {r1, r5, r6, r7, r11, sp, lr} */
/* @0x30eb7e andls r2, r1, r1, lsl #2 */
/* @0x30eb82 ldrtmi r9, [r3], -r0, lsl #6 */
/* @0x30eb86 addseq r9, r2, r5, lsl #16 */
/* @0x30eb8a blx 0xfe34caf6 <b2_toiTime+0xfffffffffdbf3652> */
/* @0x30eb8e .word 0x61209b0b */
/* @0x30eb92 stmdbls r6, {r0, r1, r4, r5, r8, r11, r12, sp, pc} */
/* @0x30eb96 .word 0xf5a74632 */
/* @0x30eb9a movwhs lr, #0x1d10 */
/* @0x30eb9e eorvc r6, r3, r5, ror #1 */
/* @0x30eba2 andlt r9, sp, r11, lsl #16 */
/* @0x30eba6 svchi #0xf0e8bd */
/* @0x30ebaa .word 0x4604b538 */
/* @0x30ebae strmi r6, [sp], -r3, asr #18 */
/* @0x30ebb2 addsmi r6, r3, #12713984 */
/* @0x30ebb6 stmibvs r3!, {r0, r1, r3, r12, lr, pc} ^ */
/* @0x30ebba stmvs r2!, {r0, r3, r5, r9, r10, lr} */
/* @0x30ebbe blx 0x329148 */
/* @0x30ebc2 .word 0xf5a73002 */
/* @0x30ebc6 stmdbvs r3!, {r1, r3, r4, r5, r6, r7, r10, r11, sp, lr, pc} ^ */
/* @0x30ebca .word 0x61633301 */
/* @0x30ebce stmdbvs r1, {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x30ebd2 .word 0xf7ff4419 */
/* @0x30ebd6 stmdahs r0, {r2, r3, r4, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30ebda ldclt p1, c13, [r8, #-948]! */
/* @0x30ebde svcmi #0xf0e92d */
/* @0x30ebe2 stmdavs r2, {r1, r2, r4, r9, r10, lr} */
/* @0x30ebe6 strmi r11, [r4], -r9, lsl #1 */
/* @0x30ebea movwhs r9, #0x305 */
/* @0x30ebee ldrsbhi pc, [r12], -r2 */
/* @0x30ebf2 stmibvs r2, {r0, r1, r3, sp, lr} ^ */
/* @0x30ebf6 movwls r9, #0x6104 */
/* @0x30ebfa .word 0xf8d4b13a */
/* @0x30ebfe stmibvs r7!, {r2, r3, sp, pc} */
/* @0x30ec02 svceq #0xf1ba */
/* @0x30ec06 sbcshi pc, r8, r0 */
/* @0x30ec0a stmdavs r5, {r1, r2, r4, r5, r6, sp, lr, pc} */
/* @0x30ec0e andls r6, r7, #12779520 */
/* @0x30ec12 ldrsbge pc, [r12], -r5 */
/* @0x30ec16 rsble r2, r2, r0, lsl #22 */
/* @0x30ec1a bleq 0x38b02e <_pcre_utt+0xd2> */
/* @0x30ec1e blge 0x4edc42 <SrcVerts+0x4ac86> */
/* @0x30ec22 movwls r9, #0x1200 */
/* @0x30ec26 usaxmi r4, r11, r0 */
/* @0x30ec2a .word 0xf7d92104 */
/* @0x30ec2e blls 0x50d4f2 <SrcVerts+0x6a536> */
/* @0x30ec32 blhs 0x3273ba */
/* @0x30ec36 stmvs r1!, {r0, r1, r4, r6, r8, r12, lr, pc} */
/* @0x30ec3a stmdavs r3!, {r3, r5, r9, r10, lr} ^ */
/* @0x30ec3e .word 0xf7d74419 */
/* @0x30ec42 andls pc, r7, r1, lsr lr */
/* @0x30ec46 mrsle r2, spsr */
/* @0x30ec4a blx 0x50d880 <SrcVerts+0x6a8c4> */
/* @0x30ec4e ldrbmi r4, [r9], -r8, lsr #12 */
/* @0x30ec52 .word 0xf8e6f7d9 */
/* @0x30ec56 stmdahs r0, {r0, r1, r2, r12, pc} */
/* @0x30ec5a bvs 0xe03166 <b2_toiTime+0x6a9cc2> */
/* @0x30ec5e stmibvs r2!, {r1, r8, r9, r10, r11, sp} ^ */
/* @0x30ec62 mulle pc, r11, r4 */
/* @0x30ec66 andsle r2, r8, r3, lsl #30 */
/* @0x30ec6a .word 0xd1252f01 */
/* @0x30ec6e ssaxmi r4, r9, r11 */
/* @0x30ec72 stmdavc r9, {r2, r9, r12, lr, pc} */
/* @0x30ec76 .word 0xf8423301 */
/* @0x30ec7a ldrb r1, [r7, r4, lsl #22]! */
/* @0x30ec7e .word 0xf7d94628 */
/* @0x30ec82 eor pc, r12, r10, lsl r9 */
/* @0x30ec86 rscsle r4, r9, #381681664 */
/* @0x30ec8a movwlo r7, #0x2818 */
/* @0x30ec8e .word 0x1c01f813 */
/* @0x30ec92 .word 0x2100ea41 */
/* @0x30ec96 blne 0x44cda6 <g_RomDisk+0x55586> */
/* @0x30ec9a ldrbmi lr, [r11, #-0x7f4] */
/* @0x30ec9e ldmdavc r9, {r1, r2, r3, r5, r6, r7, r9, r12, lr, pc} ^ */
/* @0x30eca2 .word 0xf8133303 */
/* @0x30eca6 andeq r0, r9, #768 */
/* @0x30ecaa .word 0x4100ea41 */
/* @0x30ecae .word 0x0c01f813 */
/* @0x30ecb2 .word 0xf8424301 */
/* @0x30ecb6 ldrb r1, [r0, r4, lsl #22]! */
/* @0x30ecba sbcsle r4, pc, #381681664 */
/* @0x30ecbe movwlo r7, #0x4859 */
/* @0x30ecc2 .word 0x0c04f813 */
/* @0x30ecc6 b 0x134fcf2 <b2_toiTime+0xbf684e> */
/* @0x30ecca .word 0xf8136100 */
/* @0x30ecce movwmi r0, #0x1c01 */
/* @0x30ecd2 .word 0x0c02f813 */
/* @0x30ecd6 .word 0x2100ea41 */
/* @0x30ecda blne 0x44cdea <g_RomDisk+0x555ca> */
/* @0x30ecde blls 0x508c96 <SrcVerts+0x65cda> */
/* @0x30ece2 ldrbmi r11, [r0], -r11, lsr #2 */
/* @0x30ece6 .word 0xf7d869e1 */
/* @0x30ecea movwhs pc, #0xb25 */
/* @0x30ecee blls 0x4e7482 <SrcVerts+0x444c6> */
/* @0x30ecf2 blhs 0x333912 */
/* @0x30ecf6 subs sp, pc, r1, lsl #1 */
/* @0x30ecfa stcge p2, c2, [r6, #-0] */
/* @0x30ecfe strbmi r9, [r0], -r0, lsl #4 */
/* @0x30ed02 .word 0x21049501 */
/* @0x30ed06 movweq pc, #0x110a */
/* @0x30ed0a .word 0xf9c0f7d9 */
/* @0x30ed0e strmi r9, [r1], r6, lsl #20 */
/* @0x30ed12 cmple r1, r0, lsl #20 */
/* @0x30ed16 smlsdls r3, r7, r4, r4 */
/* @0x30ed1a strtmi r11, [r10], -r6, asr #2 */
/* @0x30ed1e ldrtmi r4, [r9], -r0, asr #12 */
/* @0x30ed22 blx 0x34cc8a */
/* @0x30ed26 strmi r9, [r2], r6, lsl #20 */
/* @0x30ed2a sub r11, r5, r10, lsl #2 */
/* @0x30ed2e bvs 0xbe07fe <b2_toiTime+0x48735a> */
/* @0x30ed32 strbmi r2, [sp], -r0, lsl #14 */
/* @0x30ed36 .word 0xf04f4639 */
/* @0x30ed3a vmlahs.f64 d0, d0, d1 */
/* @0x30ed3e uadd16mi r11, r2, r4 */
/* @0x30ed42 .word 0xf8c9461a */
/* @0x30ed46 stmvs r2!, {sp} ^ */
/* @0x30ed4a stmdale r11!, {r0, r1, r4, r7, r8, r10, lr} */
/* @0x30ed4e .word 0xf85269e2 */
/* @0x30ed52 .word 0xf102202b */
/* @0x30ed56 strmi r3, [r8, #0x8ff] */
/* @0x30ed5a stmibvs r2!, {r2, r8, r9, r12, lr, pc} */
/* @0x30ed5e svclt #0x284590 */
/* @0x30ed62 mul r0, r0, r6 */
/* @0x30ed66 ldmdblt lr, {r3, r7, r9, r10, lr} */
/* @0x30ed6a andeq lr, r8, #3072 */
/* @0x30ed6e ands r6, r4, r10, rrx */
/* @0x30ed72 bl 0x52039a <SrcVerts+0x7d3de> */
/* @0x30ed76 ldrbmi r0, [r2], #-519 */
/* @0x30ed7a andle r6, lr, r10, rrx */
/* @0x30ed7e ldrmi r6, [r9], #-2088 */
/* @0x30ed82 strlo r9, [r1, -r2, lsl #6] */
/* @0x30ed86 .word 0xf5a71a12 */
/* @0x30ed8a stmdavs r10!, {r3, r4, r10, r11, sp, lr, pc} ^ */
/* @0x30ed8e .word 0x0100f04f */
/* @0x30ed92 stmdavs r10!, {r0, r4, r12, sp, lr} ^ */
/* @0x30ed96 rsbvs r3, r10, r1, lsl #4 */
/* @0x30ed9a .word 0xf10b9b02 */
/* @0x30ed9e strlo r0, [r4, #-0xb01] */
/* @0x30eda2 ldrb r4, [r0, r1, asr #12] */
/* @0x30eda6 .word 0xf8c29a04 */
/* @0x30edaa .word 0xb10e9000 */
/* @0x30edae andge pc, r0, r6, asr #17 */
/* @0x30edb2 .word 0xb10b9b05 */
/* @0x30edb6 andsvs r9, r9, r3, lsl #18 */
/* @0x30edba andlt r9, r9, r6, lsl #16 */
/* @0x30edbe svchi #0xf0e8bd */
/* @0x30edc2 .word 0x4604b538 */
/* @0x30edc6 orrslt r6, r0, r0, lsl #16 */
/* @0x30edca stmibvs r5, {r1, r5, r9, r11, sp, lr} ^ */
/* @0x30edce .word 0xf104b11a */
/* @0x30edd2 .word 0xf7d90120 */
/* @0x30edd6 qadd16mi pc, r8, r9 */
/* @0x30edda .word 0xf7d869e1 */
/* @0x30edde smlatbhs r0, r11, r10, pc */
/* @0x30ede2 mvnvs r4, r0, lsr #12 */
/* @0x30ede6 pop {r2, r5, r9, sp} */
/* @0x30edea .word 0xf00c4038 */
/* @0x30edee ldclt p14, c11, [r8, #-440]! */
/* @0x30edf2 .word 0x4606b570 */
/* @0x30edf6 movwlt r4, #0x160c */
/* @0x30edfa andsvc pc, r8, r1, lsl #10 */
/* @0x30edfe .word 0xf7ff2500 */
/* @0x30ee02 .word 0x4630ffdf */
/* @0x30ee06 addne pc, r4, #212, #16 */
/* @0x30ee0a blx 0xfe84cd72 <b2_toiTime+0xfffffffffe0f38ce> */
/* @0x30ee0e .word 0xf8d44630 */
/* @0x30ee12 .word 0xf8c4123c */
/* @0x30ee16 .word 0xf7d85284 */
/* @0x30ee1a ldrtmi pc, [r0], -sp, lsl #21 */
/* @0x30ee1e subne pc, r4, #212, #16 */
/* @0x30ee22 eorspl pc, r12, #196, #16 */
/* @0x30ee26 blx 0xfe4ccd8e <b2_toiTime+0xfffffffffdd738ea> */
/* @0x30ee2a subpl pc, r4, #196, #16 */
/* @0x30ee2e .word 0xf8d44630 */
/* @0x30ee32 .word 0xf7d81250 */
/* @0x30ee36 .word 0xf8c4fa7f */
/* @0x30ee3a ldcllt p2, c5, [r0, #-320]! */
/* @0x30ee3e ldrlt r0, [r8, #-0x0]! */
/* @0x30ee42 stmdavs r3, {r2, r9, r10, lr} */
/* @0x30ee46 stmvs r2!, {r0, r2, r3, r9, r10, lr} ^ */
/* @0x30ee4a ldmdavs r8, {r0, r1, r3, r4, r9, r10, r11, sp, lr} ^ */
/* @0x30ee4e ldrbtmi r4, [r11], #-2831 */
/* @0x30ee52 addsmi r6, r10, #1769472 */
/* @0x30ee56 blmi 0x682eae <g_SWFlinevertbuff+0x2fde6> */
/* @0x30ee5a ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x30ee5e mulle pc, r10, r2 */
/* @0x30ee62 ldrbtmi r4, [r9], #-2316 */
/* @0x30ee66 .word 0xf843f7d7 */
/* @0x30ee6a andhs r4, r0, #180224 */
/* @0x30ee6e .word 0xf7d74479 */
/* @0x30ee72 .word 0xb140f861 */
/* @0x30ee76 .word 0xb12b6803 */
/* @0x30ee7a strtmi r4, [r9], -r0, lsr #12 */
/* @0x30ee7e ldclt p7, c4, [r8, #-608]! */
/* @0x30ee82 ldclt p0, c2, [r8, #-600]! */
/* @0x30ee86 ldclt p6, c4, [r8, #-96]! */
/* @0x30ee8a stchs p15, c11, [r8, #0]! */
/* @0x30ee8e stchs p0, c0, [r2, #56]! */
/* @0x30ee92 stc2l p0, c0, [r11, #-56] */
/* @0x30ee96 .word 0xf8a90007 */
/* @0x30ee9a ldrlt r0, [r8, #-0x7]! */
/* @0x30ee9e stmvs r3, {r2, r9, r10, lr} */
/* @0x30eea2 adcpl pc, r0, #208, #16 */
/* @0x30eea6 .word 0xf8d0071b */
/* @0x30eeaa ldrle r2, [r1, #-0x21c] */
/* @0x30eeae cdpvs p1, #0x0, c11, c3, c2, #0x4 */
/* @0x30eeb2 ldmdavs r8, {r0, r3, r8, r11, lr} ^ */
/* @0x30eeb6 .word 0xf7d74479 */
/* @0x30eeba stmdbmi r7, {r1, r3, r4, r11, r12, sp, lr, pc} */
/* @0x30eebe ldrbtmi r2, [r9], #-512 */
/* @0x30eec2 rfeda r8! */
/* @0x30eec6 stmdavs r3, {r5, r8, r12, sp, pc} */
/* @0x30eeca qadd16mi r11, r0, r3 */
/* @0x30eece ldclt p7, c4, [r8, #-608]! */
/* @0x30eed2 strbeq pc, [r4, #-0x8d5] */
/* @0x30eed6 ldc2l p13, c11, [r9], #224 */
/* @0x30eeda rfeda r7! */
/* @0x30eede ldrblt r0, [r8, #0x7]! */
/* @0x30eee2 .word 0xf8d04605 */
/* @0x30eee6 strmi r4, [lr], -r0, lsr #5 */
/* @0x30eeea blhs 0x3ae77e <error_g0017+0x7422> */
/* @0x30eeee mcrvs p1, #0x0, sp, c3, c4, #0x0 */
/* @0x30eef2 ldmdavs r8, {r5, r8, r11, lr} ^ */
/* @0x30eef6 .word 0xf7d64479 */
/* @0x30eefa ldmdbmi lr, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30eefe ldrbtmi r2, [r9], #-512 */
/* @0x30ef02 .word 0xf818f7d7 */
/* @0x30ef06 andhs r11, r0, r8, lsl #18 */
/* @0x30ef0a stmdavs r3, {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} ^ */
/* @0x30ef0e rscsle r2, r10, r0, lsl #22 */
/* @0x30ef12 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x30ef16 ldcllt p7, c4, [r8, #608]! */
/* @0x30ef1a andhs r4, r1, #24, #18 */
/* @0x30ef1e ldrbtmi r6, [r9], #-3584 */
/* @0x30ef22 .word 0xf808f7d7 */
/* @0x30ef26 stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x30ef2a strhs sp, [r0, #-0xed] */
/* @0x30ef2e addsmi r6, sp, #1622016 */
/* @0x30ef32 .word 0xf8d4d2e9 */
/* @0x30ef36 rfeda r3! */
/* @0x30ef3a .word 0xf5b00015 */
/* @0x30ef3e stmdble r11, {r0, r1, r6, r7, r8, r9, r10, r11, r12, sp, lr} */
/* @0x30ef42 strbhs pc, [r12, #-0x8d4] */
/* @0x30ef46 bicvc pc, r3, #1862270976 */
/* @0x30ef4a addsmi r1, r3, #12779520 */
/* @0x30ef4e .word 0xf8d4d20c */
/* @0x30ef52 .word 0xf8522550 */
/* @0x30ef56 and r1, r2, r3, lsr #32 */
/* @0x30ef5a .word 0x4790697a */
/* @0x30ef5e tstlt r9, r1, lsl #12 */
/* @0x30ef62 .word 0xf5a74630 */
/* @0x30ef66 .word 0xb108eb06 */
/* @0x30ef6a ldrb r3, [pc, r1, lsl #10] */
/* @0x30ef6e ldcllt p6, c4, [r8, #160]! */
/* @0x30ef72 ldc2 p15, c11, [r9], #0 */
/* @0x30ef76 .word 0xf7ec0007 */
/* @0x30ef7a .word 0xf9990007 */
/* @0x30ef7e push {r0, r1, r2} */
/* @0x30ef82 .word 0x460d43f7 */
/* @0x30ef86 .word 0xf8d14604 */
/* @0x30ef8a .word 0x4691801c */
/* @0x30ef8e eorhs r2, r4, #0, #2 */
/* @0x30ef92 .word 0xf5a7461f */
/* @0x30ef96 eorvs lr, r5, r12, lsl #22 */
/* @0x30ef9a cdpge p6, #0x0, c4, c1, c8, #0x1 */
/* @0x30ef9e stc2l p7, c15, [pc], {215} */
/* @0x30efa2 rsbvs r4, r0, r1, lsr r6 */
/* @0x30efa6 teqlt pc, r8, lsr #12 */
/* @0x30efaa .word 0xff0bf7d7 */
/* @0x30efae strmi r9, [r7], -r1, lsl #22 */
/* @0x30efb2 teqle sp, r0, lsl #22 */
/* @0x30efb6 and r2, r6, r5, lsl #6 */
/* @0x30efba stc2 p7, c15, [r3, #860]! */
/* @0x30efbe blhs 0x335bca */
/* @0x30efc2 .word 0x4607d136 */
/* @0x30efc6 adcvs r2, r3, r3, lsl #6 */
/* @0x30efca eorsle r2, r1, r0, lsl #30 */
/* @0x30efce ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x30efd2 ldc2l p7, c15, [r2, #-860]! */
/* @0x30efd6 bllt 0x19b57e2 <b2_toiTime+0x125c33e> */
/* @0x30efda cdpne p2, #0x5, c11, c10, c3, #0x6 */
/* @0x30efde ldmdale r6, {r0, r1, r9, r11, sp} */
/* @0x30efe2 strlo r6, [r1, -r7, ror #1] */
/* @0x30efe6 blx 0x4e9270 <SrcVerts+0x462b4> */
/* @0x30efea stmdavs r2!, {r0, r1, r8, r12, sp, lr, pc} ^ */
/* @0x30efee strmi r7, [r2], #-1059 */
/* @0x30eff2 strmi r4, [r10], #-1576 */
/* @0x30eff6 smulbtvs r2, r9, r10 */
/* @0x30effa ldc2 p7, c15, [r9], {215} */
/* @0x30effe ldmiblt r8!, {r0, r12, pc} */
/* @0x30f002 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x30f006 .word 0xf96df7ff */
/* @0x30f00a stmiblt r11, {r0, r8, r9, r11, r12, pc} */
/* @0x30f00e movwhs r11, #0x8910 */
/* @0x30f012 and r9, sp, r1, lsl #6 */
/* @0x30f016 strtmi r1, [r8], -r1, asr #28 */
/* @0x30f01a .word 0xf1b961a1 */
/* @0x30f01e andle r0, r4, r0, lsl #30 */
/* @0x30f022 eoreq pc, r0, #4, #2 */
/* @0x30f026 .word 0xff3cf7d8 */
/* @0x30f02a .word 0xf7d7e001 */
/* @0x30f02e andls pc, r1, r0, lsl #25 */
/* @0x30f032 .word 0xb12b9b01 */
/* @0x30f036 stmibvs r1!, {r6, r9, r10, lr} ^ */
/* @0x30f03a .word 0xf97cf7d8 */
/* @0x30f03e mvnvs r2, r0, lsl #6 */
/* @0x30f042 andlt r9, r3, r1, lsl #16 */
/* @0x30f046 mvnshi lr, #12386304 */
/* @0x30f04a .word 0xe92d0000 */
/* @0x30f04e .word 0x460541f0 */
/* @0x30f052 strmi r4, [r8], -pc, lsl #12 */
/* @0x30f056 addlt r4, r10, r0, asr r9 */
/* @0x30f05a sadd16mi r4, lr, r4 */
/* @0x30f05e .word 0xf5a74479 */
/* @0x30f062 stmdahs r0, {r3, r7, r9, r11, sp, lr, pc} */
/* @0x30f066 movwlt sp, #0xe14e */
/* @0x30f06a stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x30f06e andhs r4, r10, #6291456 */
/* @0x30f072 strbmi r4, [r1], -r0, lsr #12 */
/* @0x30f076 .word 0xf5a7af02 */
/* @0x30f07a blls 0x389c6a <bigtens_D2A+0x13a> */
/* @0x30f07e bhs 0xe2d0ee <b2_toiTime+0x6d3c4a> */
/* @0x30f082 ldrhle r5, [pc, #-24]! */
/* @0x30f086 .word 0xd07d429c */
/* @0x30f08a mrrcne p6, #0x0, r3, r12, c4 */
/* @0x30f08e mvnle r2, r12, lsl lr */
/* @0x30f092 strtmi r2, [r0], -r10, lsl #4 */
/* @0x30f096 .word 0xf5a74641 */
/* @0x30f09a blls 0x389c4a <bigtens_D2A+0x11a> */
/* @0x30f09e .word 0xf012781a */
/* @0x30f0a2 ldrdls r0, r1, [r9], -pc */
/* @0x30f0a6 addsmi sp, r12, #-2147483621 */
/* @0x30f0aa ldrtmi sp, [r12], -r12, rrx */
/* @0x30f0ae mulne r1, r4, r8 */
/* @0x30f0b2 stmdahs r0, {r1, r5, r7, r11, sp, lr} */
/* @0x30f0b6 stmdbvs r3!, {r0, r1, r2, r5, r6, r7, r11, sp, lr} */
/* @0x30f0ba stmibvs r1!, {r1, r2, r5, r6, r8, r11, sp, lr} */
/* @0x30f0be blle 0x1b69856 <b2_toiTime+0x14103b2> */
/* @0x30f0c2 blle 0x1ad98ca <b2_toiTime+0x1380426> */
/* @0x30f0c6 blle 0x1a59cce <b2_toiTime+0x130082a> */
/* @0x30f0ca blle 0x19d94d2 <b2_toiTime+0x128002e> */
/* @0x30f0ce mrrcle p2, #0x9, r4, r9, c0 */
/* @0x30f0d2 mrrcle p2, #0x9, r4, r7, c10 */
/* @0x30f0d6 mrrcle p2, #0x8, r4, r5, c11 */
/* @0x30f0da svcvc #0xfaf5bc */
/* @0x30f0de .word 0xf5b7d852 */
/* @0x30f0e2 stmdale pc, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr} ^ */
/* @0x30f0e6 svcvc #0xfaf5b6 */
/* @0x30f0ea .word 0xf5b4d84c */
/* @0x30f0ee stmdale r9, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr} ^ */
/* @0x30f0f2 .word 0xf8c56268 */
/* @0x30f0f6 rscvs r12, r10, #40 */
/* @0x30f0fa .word 0x636b632f */
/* @0x30f0fe .word 0x63e963ae */
/* @0x30f102 eors r6, sp, r12, lsr #8 */
/* @0x30f106 ldrtmi r4, [r8], -r5, lsr #18 */
/* @0x30f10a .word 0xf5a74479 */
/* @0x30f10e ldmdblt r8!, {r1, r4, r5, r9, r11, sp, lr, pc} ^ */
/* @0x30f112 stmdbmi r2!, {r1, r2, r3, r6, r8, r12, sp, pc} */
/* @0x30f116 ldrbtmi r4, [r9], #-1568 */
/* @0x30f11a b 0xe4c7be <b2_toiTime+0x6f331a> */
/* @0x30f11e teqle r1, r0, lsl #16 */
/* @0x30f122 mvnvs r2, r1, lsl #6 */
/* @0x30f126 stmdavs r3!, {r1, r4, r5, sp, lr, pc} */
/* @0x30f12a .word 0xd12d2b01 */
/* @0x30f12e eor r6, r7, r11, ror #3 */
/* @0x30f132 shadd16mi r4, r8, r12 */
/* @0x30f136 .word 0xf5a74479 */
/* @0x30f13a pkhbtmi lr, r0, r12, lsl #20 */
/* @0x30f13e cmplt r6, r8, ror r9 */
/* @0x30f142 strbmi r4, [r1], -r0, lsr #12 */
/* @0x30f146 .word 0xf5a7220a */
/* @0x30f14a ldmdblt r0, {r1, r4, r7, r9, r11, sp, lr, pc} */
/* @0x30f14e eoreq pc, r0, r5, lsl #17 */
/* @0x30f152 movwhs lr, #0x101d */
/* @0x30f156 stmdavc r3!, {sp, lr, pc} */
/* @0x30f15a eorlo pc, r0, r5, lsl #17 */
/* @0x30f15e ldmdbmi r1, {r4, sp, lr, pc} */
/* @0x30f162 ldrbtmi r4, [r9], #-1592 */
/* @0x30f166 b 0x4cc80a <SrcVerts+0x2984e> */
/* @0x30f16a ldmdblt r8!, {r0, r9, r10, lr} ^ */
/* @0x30f16e strtmi r11, [r0], -r6, lsr #2 */
/* @0x30f172 .word 0xf5a7220a */
/* @0x30f176 and lr, r0, r12, ror r10 */
/* @0x30f17a b 0xb29202 <b2_toiTime+0x3cfd5e> */
/* @0x30f17e strbtvs r7, [r8], #-224 */
/* @0x30f182 and r2, r4, r0 */
/* @0x30f186 and r2, r2, r6 */
/* @0x30f18a and r2, r0, r7 */
/* @0x30f18e andlt r2, r10, r12 */
/* @0x30f192 ldrhhi lr, [r0, #141]! */
/* @0x30f196 .word 0xff38bf00 */
/* @0x30f19a ldreq r0, [r7, #-0x7]! */
/* @0x30f19e ldreq r0, [r8, #-0x8]! */
/* @0x30f1a2 cdp2 p0, #0x7, c0, c5, c8, #0x0 */
/* @0x30f1a6 ldrbteq r0, [r2], #7 */
/* @0x30f1aa stmdb sp!, {r3} */
/* @0x30f1ae stmdahs r0, {r4, r5, r6, r7, r8, r9, r10, lr} */
/* @0x30f1b2 stmdahi r6, {r1, r6, r12, lr, pc} */
/* @0x30f1b6 blhs 0x37ba8a <_ZTS13C_UTF16String+0x12b36> */
/* @0x30f1ba .word 0xf103dd07 */
/* @0x30f1be stmvs r1, {r9, lr} ^ */
/* @0x30f1c2 rfedb r1! */
/* @0x30f1c6 andlo r2, r1, #18 */
/* @0x30f1ca andhs lr, r0, #0 */
/* @0x30f1ce eorslt r8, sp, #4653056 */
/* @0x30f1d2 ldcle p13, c2, [sp, #-4] */
/* @0x30f1d6 .word 0xf1056841 */
/* @0x30f1da .word 0x3c015400 */
/* @0x30f1de .word 0xc008f8d0 */
/* @0x30f1e2 stmibeq r2, {r0, r8, r9, r11, sp, lr, pc} ^ */
/* @0x30f1e6 eorsge pc, r2, r1, asr r8 */
/* @0x30f1ea stmeq r4, {r0, r8, r9, r11, sp, lr, pc} ^ */
/* @0x30f1ee eorsne pc, r4, r1, asr r8 */
/* @0x30f1f2 smlabble sp, r10, r5, r4 */
/* @0x30f1f6 .word 0x4004f8d9 */
/* @0x30f1fa .word 0x1004f8d8 */
/* @0x30f1fe smlabble r7, r12, r2, r4 */
/* @0x30f202 .word 0xf8154465 */
/* @0x30f206 stmdbhs r1, {r0, r10, r11, r12} */
/* @0x30f20a .word 0xf107bf04 */
/* @0x30f20e strdhi r3, r4, [r7], #-127 */
/* @0x30f212 vldrle d2, [r1, #-0] */
/* @0x30f216 andlt r8, r12, #4259840 */
/* @0x30f21a adcmi r3, r2, #256 */
/* @0x30f21e rscslo pc, pc, #1073741824 */
/* @0x30f222 cdplo p1, #0x0, c13, c1, c4, #0x0 */
/* @0x30f226 andhi r8, r6, r2, asr #32 */
/* @0x30f22a .word 0x87f0e8bd */
/* @0x30f22e movwmi pc, #0x103 */
/* @0x30f232 bllo 0x36953e <_ZTS13C_UTF16String+0x5ea> */
/* @0x30f236 andshs pc, r3, r1, lsr #16 */
/* @0x30f23a .word 0x87f0e8bd */
/* @0x30f23e stmibvs r4, {r4, r8, r10, r12, sp, pc} ^ */
/* @0x30f242 .word 0xf7ff6960 */
/* @0x30f246 movwhs pc, #0xfb2 */
/* @0x30f24a sublo pc, r0, r4, lsl #17 */
/* @0x30f24e strlt r11, [r8, #-0xd10] */
/* @0x30f252 stmvs r2, {r0, r1, r6, r7, r11, sp, lr} */
/* @0x30f256 andle r4, r3, #805306377 */
/* @0x30f25a sbcvs r1, r2, r10, asr r12 */
/* @0x30f25e stclt p8, c7, [r8, #-96] */
/* @0x30f262 cmphs r5, r0, lsl #16 */
/* @0x30f266 stc2l p7, c15, [r12, #1016]! */
/* @0x30f26a stclt p0, c2, [r8, #-0] */
/* @0x30f26e andeq pc, r8, #0, #2 */
/* @0x30f272 bgt 0xa3c6ba <b2_toiTime+0x2e3216> */
/* @0x30f276 sbceq lr, r4, #2048 */
/* @0x30f27a swple r4, r3, [r5] */
/* @0x30f27e orrhs r6, r2, r0, asr #16 */
/* @0x30f282 ldrhmi lr, [r0], -sp */
/* @0x30f286 ldcllt p7, c15, [r12, #1016] */
/* @0x30f28a andhs r6, r2, #25 */
/* @0x30f28e subsvs r6, r10, r3, asr #17 */
/* @0x30f292 movwlo r6, #0x88c3 */
/* @0x30f296 ldclt p0, c6, [r0, #-780] */
/* @0x30f29a andeq pc, r8, #0, #2 */
/* @0x30f29e bgt 0xa3c6e6 <b2_toiTime+0x2e3242> */
/* @0x30f2a2 sbceq lr, r4, #2048 */
/* @0x30f2a6 swple r4, r3, [r5] */
/* @0x30f2aa orrhs r6, r2, r0, asr #16 */
/* @0x30f2ae ldrhmi lr, [r0], -sp */
/* @0x30f2b2 stcllt p7, c15, [r6, #1016] */
/* @0x30f2b6 andhs r6, r0, #25 */
/* @0x30f2ba subsvs r6, r10, r3, asr #17 */
/* @0x30f2be movwlo r6, #0x88c3 */
/* @0x30f2c2 ldclt p0, c6, [r0, #-780] */
/* @0x30f2c6 stmvs r3, {r3, r8, r10, r12, sp, pc} ^ */
/* @0x30f2ca addsmi r6, r3, #8519680 */
/* @0x30f2ce stmdavs r0, {r1, r8, r12, lr, pc} ^ */
/* @0x30f2d2 and r2, r5, r1, lsr #3 */
/* @0x30f2d6 .word 0x2c04f853 */
/* @0x30f2da andle r2, r5, r2, lsl #20 */
/* @0x30f2de asrhs r6, r0, #16 */
/* @0x30f2e2 stc2 p7, c15, [lr, #1016]! */
/* @0x30f2e6 stclt p0, c2, [r8, #-0] */
/* @0x30f2ea andeq pc, r8, #-1073741784 */
/* @0x30f2ee .word 0xf85360c2 */
/* @0x30f2f2 stclt p12, c0, [r8, #-32] */
/* @0x30f2f6 stmvs r3, {r3, r8, r10, r12, sp, pc} ^ */
/* @0x30f2fa addsmi r6, r3, #8519680 */
/* @0x30f2fe stmdavs r0, {r0, r2, r8, r12, lr, pc} ^ */
/* @0x30f302 .word 0xf7fe21a1 */
/* @0x30f306 mulhs r0, sp, sp */
/* @0x30f30a .word 0xf1a3bd08 */
/* @0x30f30e sbcvs r0, r2, r8, lsl #4 */
/* @0x30f312 andeq lr, r5, r3, lsl r9 */
/* @0x30f316 andle r2, r3, r1, lsl #20 */
/* @0x30f31a .word 0xd10c2a02 */
/* @0x30f31e stclt p4, c0, [r8, #-0] */
/* @0x30f322 ble 0x41932a <g_RomDisk+0x21b0a> */
/* @0x30f326 andpl pc, r0, r0, asr #11 */
/* @0x30f32a submi r1, r0, #128, #6 */
/* @0x30f32e .word 0xf500bd08 */
/* @0x30f332 orrne r5, r0, #0 */
/* @0x30f336 stclt p13, c11, [r8, #-32] */
/* @0x30f33a stmvs r3, {r3, r8, r10, r12, sp, pc} */
/* @0x30f33e bne 0xff7a964e <b2_toiTime+0xffffffffff0501aa> */
/* @0x30f342 svceq #0xe2ebb1 */
/* @0x30f346 stmdavs r0, {r0, r2, r8, r9, r12, lr, pc} ^ */
/* @0x30f34a .word 0xf7fe2182 */
/* @0x30f34e andhs pc, r0, r9, ror sp */
/* @0x30f352 bl 0x3fe77a <g_RomDisk+0x6f5a> */
/* @0x30f356 .word 0xf85302c1 */
/* @0x30f35a ldmdavs r2, {r0, r4, r5} ^ */
/* @0x30f35e andle r2, r3, r1, lsl #20 */
/* @0x30f362 .word 0xd10c2a02 */
/* @0x30f366 stclt p4, c0, [r8, #-0] */
/* @0x30f36a ble 0x419372 <g_RomDisk+0x21b52> */
/* @0x30f36e andpl pc, r0, r0, asr #11 */
/* @0x30f372 submi r1, r0, #128, #6 */
/* @0x30f376 .word 0xf500bd08 */
/* @0x30f37a orrne r5, r0, #0 */
/* @0x30f37e stclt p13, c11, [r8, #-32] */
/* @0x30f382 .word 0x43f8e92d */
/* @0x30f386 stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x30f38a adchi pc, r11, r0 */
/* @0x30f38e andslo pc, r12, #208, #16 */
/* @0x30f392 .word 0x9064f8d0 */
/* @0x30f396 ldmvs r11, {r0, r1, r3, r8, r12, sp, pc} ^ */
/* @0x30f39a .word 0xf8d74798 */
/* @0x30f39e .word 0x2c0042a0 */
/* @0x30f3a2 addshi pc, r9, r0 */
/* @0x30f3a6 rsbeq pc, r12, r4, lsl #2 */
/* @0x30f3aa .word 0xf7ff68a5 */
/* @0x30f3ae .word 0xf504fd09 */
/* @0x30f3b2 .word 0xf7ff609b */
/* @0x30f3b6 .word 0xf104fd05 */
/* @0x30f3ba .word 0xf7ff0024 */
/* @0x30f3be vadd.f32 d15, d4, d1 */
/* @0x30f3c2 .word 0xf7ff40b4 */
/* @0x30f3c6 .word 0xf8d4fcfd */
/* @0x30f3ca .word 0xb1ab37e8 */
/* @0x30f3ce .word 0xf8d42600 */
/* @0x30f3d2 addsmi r3, lr, #232, #14 */
/* @0x30f3d6 bl 0x443bfe <g_RomDisk+0x4c3de> */
/* @0x30f3da strtmi r0, [r8], -r6, lsl #7 */
/* @0x30f3de .word 0xf8d33601 */
/* @0x30f3e2 .word 0xf7ff17ec */
/* @0x30f3e6 ldrb pc, [r2, r5, lsl #26]! */
/* @0x30f3ea .word 0xf8d44628 */
/* @0x30f3ee .word 0xf7d717ec */
/* @0x30f3f2 movwhs pc, #0xfa1 */
/* @0x30f3f6 strblo pc, [r12, r4, asr #17]! */
/* @0x30f3fa strhs r6, [r0], -r3, ror #16 */
/* @0x30f3fe addsvs pc, r0, r4, asr #17 */
/* @0x30f402 addsvs pc, r4, r4, asr #17 */
/* @0x30f406 addsvs pc, r8, r4, asr #17 */
/* @0x30f40a ldrsbhi pc, [r12], -r3 */
/* @0x30f40e strtne pc, [r8], #2260 */
/* @0x30f412 .word 0xf7d74640 */
/* @0x30f416 strbmi pc, [r0], -pc, lsl #31 */
/* @0x30f41a strtne pc, [r4], #2260 */
/* @0x30f41e strtvs pc, [r8], #2244 */
/* @0x30f422 strtvs pc, [r12], #2244 */
/* @0x30f426 .word 0xff86f7d7 */
/* @0x30f42a eormi pc, r4, r4, lsl #12 */
/* @0x30f42e .word 0xf8c44629 */
/* @0x30f432 .word 0xf8c464a4 */
/* @0x30f436 .word 0xf8c4649c */
/* @0x30f43a .word 0xf7fe64a0 */
/* @0x30f43e qsub16mi pc, r8, r6 */
/* @0x30f442 cmppl r12, r4, lsl #4 */
/* @0x30f446 ldc2l p7, c15, [r4], {255} */
/* @0x30f44a bllo 0x4d7a2 */
/* @0x30f44e tstlt r11, r0, ror #16 */
/* @0x30f452 mvnslo pc, r4, lsl #12 */
/* @0x30f456 ldc2l p7, c15, [r8], {216} */
/* @0x30f45a strtmi r2, [r8], -r0, lsl #12 */
/* @0x30f45e .word 0x1c10f8d4 */
/* @0x30f462 blvs 0x14d77a <_Z30F_PhysicsSetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x3e> */
/* @0x30f466 blvs 0xffe4d67e <b2_toiTime+0xffffffffff6f41da> */
/* @0x30f46a blvs 0xfff4d782 <b2_toiTime+0xffffffffff7f42de> */
/* @0x30f46e .word 0xff62f7d7 */
/* @0x30f472 .word 0xf8d44628 */
/* @0x30f476 .word 0xf8c41544 */
/* @0x30f47a .word 0xf7d76c10 */
/* @0x30f47e qsaxmi pc, r8, r11 */
/* @0x30f482 strbne pc, [r8, #-0x8d4] */
/* @0x30f486 strbvs pc, [r4, #-0x8c4] */
/* @0x30f48a .word 0xff54f7d7 */
/* @0x30f48e .word 0xf8d44628 */
/* @0x30f492 .word 0xf8c41550 */
/* @0x30f496 .word 0xf7d76548 */
/* @0x30f49a .word 0xf8c4ff4d */
/* @0x30f49e qsaxmi r6, r8, r0 */
/* @0x30f4a2 ldrbne pc, [r4, #-0x8d4] */
/* @0x30f4a6 .word 0xff46f7d7 */
/* @0x30f4aa stclo p8, c15, [r0], #-848 */
/* @0x30f4ae ldrbvs pc, [r4, #-0x8c4] */
/* @0x30f4b2 .word 0xf8d4b14b */
/* @0x30f4b6 .word 0x47980c1c */
/* @0x30f4ba .word 0xf8d44628 */
/* @0x30f4be .word 0xf7d71c1c */
/* @0x30f4c2 .word 0xf8c4ff39 */
/* @0x30f4c6 .word 0x46486c1c */
/* @0x30f4ca adcne pc, r0, #14090240 */
/* @0x30f4ce .word 0xff32f7d7 */
/* @0x30f4d2 .word 0xf8c72300 */
/* @0x30f4d6 ldrtmi r3, [r8], -r0, lsr #5 */
/* @0x30f4da stc2l p7, c15, [r5], #-1016 */
/* @0x30f4de .word 0xf8c72300 */
/* @0x30f4e2 pop {r3, r4, r5, r7, r9, r12, sp} */
/* @0x30f4e6 ldrlt r8, [r0, #-0x3f8] */
/* @0x30f4ea adclo pc, r0, #208, #16 */
/* @0x30f4ee .word 0xf8d34909 */
/* @0x30f4f2 ldrbtmi r4, [r9], #-3080 */
/* @0x30f4f6 ldmdavs r8, {r0, r1, r9, r10, r11, sp, lr} ^ */
/* @0x30f4fa ldc2l p7, c15, [r9], #856 */
/* @0x30f4fe teqlt r0, r3, lsl #12 */
/* @0x30f502 stmdavs r3!, {r2, r3, r4, r8, r12, sp, pc} */
/* @0x30f506 .word 0x4798b11b */
/* @0x30f50a qadd16mi r11, r0, r0 */
/* @0x30f50e sadd16mi r11, r8, r0 */
/* @0x30f512 .word 0xf6a2bd10 */
/* @0x30f516 push {r0, r1, r2} */
/* @0x30f51a .word 0x46044ff0 */
/* @0x30f51e addlt r6, r5, r1, asr #5 */
/* @0x30f522 .word 0xf7d56800 */
/* @0x30f526 stmdavs r0!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30f52a .word 0xffddf7ff */
/* @0x30f52e stmdahs r0, {r1, r2, r9, r10, lr} */
/* @0x30f532 stmdavs r3!, {r3, r4, r5, r12, lr, pc} */
/* @0x30f536 stmdbvs r1!, {r8, r9, r10, sp} */
/* @0x30f53a .word 0xf8d36962 */
/* @0x30f53e bvs 0xfebeffc6 <b2_toiTime+0xfffffffffe496b22> */
/* @0x30f542 strls pc, [r0, #0x8d8]! */
/* @0x30f546 .word 0xa000f8d3 */
/* @0x30f54a smladxls r0, r11, r6, r4 */
/* @0x30f54e .word 0xf8da6845 */
/* @0x30f552 strmi r0, [r8, r0]! */
/* @0x30f556 ubfxpl pc, r8, #0x11, #0x9 */
/* @0x30f55a stclo p3, c11, [r1, #-148] */
/* @0x30f55e bleq 0xfe489ea2 <b2_toiTime+0xfffffffffdd309fe> */
/* @0x30f562 movweq lr, #0xbb08 */
/* @0x30f566 ubfxlo pc, r3, #0x11, #0xd */
/* @0x30f56a ldrmi r6, [r9, #0xc5f]! */
/* @0x30f56e strbmi sp, [r9], -lr */
/* @0x30f572 stmdbvs r0!, {r1, r3, r4, r5, r9, r10, lr} */
/* @0x30f576 blx 0xffb8d4d4 <b2_toiTime+0xffffffffff434030> */
/* @0x30f57a .word 0x4649463a */
/* @0x30f57e stmdbvs r0!, {r0, r1, r9, r10, lr} ^ */
/* @0x30f582 .word 0xf7d59303 */
/* @0x30f586 blls 0x40e4f6 <g_RomDisk+0x16cd6> */
/* @0x30f58a and r4, r1, r2, lsl #12 */
/* @0x30f58e stmdbvs r2!, {r0, r1, r5, r8, r11, sp, lr} ^ */
/* @0x30f592 .word 0x010beb0a */
/* @0x30f596 andls r2, r0, r0 */
/* @0x30f59a ldrmi r6, [r9], -r8, asr #16 */
/* @0x30f59e movwhs r6, #0x877 */
/* @0x30f5a2 .word 0xe7d947b8 */
/* @0x30f5a6 andlt r2, r5, r0 */
/* @0x30f5aa svchi #0xf0e8bd */
/* @0x30f5ae ldrblt r4, [r8, #0x602]! */
/* @0x30f5b2 stmdavs r0, {r1, r4, r7, r9, r11, sp, lr} */
/* @0x30f5b6 mcrvs p8, #0x2, r6, c7, c4, #0x0 */
/* @0x30f5ba adcpl pc, r0, #208, #16 */
/* @0x30f5be .word 0xf7ffb1bc */
/* @0x30f5c2 .word 0x4606ff92 */
/* @0x30f5c6 ldrtmi r11, [r8], -r8, lsr #18 */
/* @0x30f5ca pop {r0, r5, r9, r10, lr} */
/* @0x30f5ce .word 0xf7d740f8 */
/* @0x30f5d2 stmvs r3, {r0, r4, r5, r7, r9, r10, r11, r12, sp, pc} */
/* @0x30f5d6 ldrmi r6, [r8, r0, lsr #16] */
/* @0x30f5da ubfxpl pc, r5, #0x11, #0x9 */
/* @0x30f5de rscsle r2, r2, r0, lsl #26 */
/* @0x30f5e2 ldmvs r3!, {r0, r8, r10, r11, r12, sp} */
/* @0x30f5e6 addeq lr, r5, #4, #22 */
/* @0x30f5ea .word 0x47986850 */
/* @0x30f5ee ldcllt p7, c14, [r8, #984]! */
/* @0x30f5f2 svcmi #0xf0e92d */
/* @0x30f5f6 stmdavs r0, {r2, r9, r10, lr} */
/* @0x30f5fa strmi r11, [sp], -r7, lsl #1 */
/* @0x30f5fe ldreq r6, [r11, r3, lsl #17] */
/* @0x30f602 .word 0xf8d0d50e */
/* @0x30f606 bge 0x45be7e <g_RomDisk+0x6465e> */
/* @0x30f60a .word 0x47986e9b */
/* @0x30f60e .word 0xf04fb118 */
/* @0x30f612 rscvs r3, r3, #-67108861 */
/* @0x30f616 strtmi lr, [r0], -r4 */
/* @0x30f61a .word 0xf7ff9905 */
/* @0x30f61e sub pc, r4, r12, ror pc */
/* @0x30f622 strtmi r6, [r9], -r0, lsr #16 */
/* @0x30f626 .word 0xffaff7d5 */
/* @0x30f62a .word 0xf7ff6820 */
/* @0x30f62e .word 0x4606ff5c */
/* @0x30f632 andhs r11, r0, r8, lsl #18 */
/* @0x30f636 stmdavs r3!, {r0, r3, r4, r5, sp, lr, pc} */
/* @0x30f63a stmdbvs r1!, {r8, r9, r10, sp} */
/* @0x30f63e .word 0xf8d36962 */
/* @0x30f642 bvs 0xfebf00ca <b2_toiTime+0xfffffffffe496c26> */
/* @0x30f646 strls pc, [r0, #0x8d8]! */
/* @0x30f64a .word 0xa000f8d3 */
/* @0x30f64e smladxls r0, r11, r6, r4 */
/* @0x30f652 .word 0xf8da6845 */
/* @0x30f656 strmi r0, [r8, r0]! */
/* @0x30f65a ubfxpl pc, r8, #0x11, #0x9 */
/* @0x30f65e rscle r2, r8, r0, lsl #26 */
/* @0x30f662 b 0x16dea6e <b2_toiTime+0xf855ca> */
/* @0x30f666 bl 0x512482 <SrcVerts+0x6f4c6> */
/* @0x30f66a .word 0xf8d3030b */
/* @0x30f66e mrrcvs p7, #0xe, r3, pc, c12 */
/* @0x30f672 strhle r4, [lr], -r9 */
/* @0x30f676 ldrtmi r4, [r10], -r9, asr #12 */
/* @0x30f67a .word 0xf7d56920 */
/* @0x30f67e shsaxmi pc, r10, lr */
/* @0x30f682 strmi r4, [r3], -r9, asr #12 */
/* @0x30f686 movwls r6, #0x3960 */
/* @0x30f68a blx 0x190d5e8 <b2_toiTime+0x11b4144> */
/* @0x30f68e strmi r9, [r2], -r3, lsl #22 */
/* @0x30f692 stmdbvs r3!, {r0, sp, lr, pc} */
/* @0x30f696 bl 0x5a9c26 <g_SWFlineaavertbuff+0x56b5e> */
/* @0x30f69a andhs r0, r0, r11, lsl #2 */
/* @0x30f69e stmdavs r8, {r12, pc} ^ */
/* @0x30f6a2 ldmdavs r7!, {r0, r3, r4, r9, r10, lr} ^ */
/* @0x30f6a6 ldrmi r2, [r8, r0, lsl #6]! */
/* @0x30f6aa ldrdlt lr, pc, [r7], -r8 */
/* @0x30f6ae svchi #0xf0e8bd */
/* @0x30f6b2 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x30f6b6 .word 0x4604b0b2 */
/* @0x30f6ba movwhs r6, #0x800 */
/* @0x30f6be .word 0xf7ff9300 */
/* @0x30f6c2 pkhbtmi pc, r0, r2, lsl #30 */
/* @0x30f6c6 eorsle r2, r7, r0, lsl #16 */
/* @0x30f6ca vadd.i8 d22, d0, d19 */
/* @0x30f6ce strbtmi r4, [r10], -r4, lsl #2 */
/* @0x30f6d2 .word 0xf8d36e58 */
/* @0x30f6d6 .word 0xf7d792a0 */
/* @0x30f6da blls 0x34eb76 */
/* @0x30f6de blhs 0x320f02 */
/* @0x30f6e2 cdpge p1, #0x0, c13, c1, c13, #0x1 */
/* @0x30f6e6 subspl pc, r12, r9, lsl #4 */
/* @0x30f6ea .word 0xf7fe4631 */
/* @0x30f6ee stmdavs r2!, {r1, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x30f6f2 .word 0x3000f8d8 */
/* @0x30f6f6 mrcvs p6, #0x2, r4, c0, c1, #0x1 */
/* @0x30f6fa .word 0x4798463a */
/* @0x30f6fe ldmiblt r0!, {r12, pc} ^ */
/* @0x30f702 ubfxpl pc, r9, #0x11, #0x9 */
/* @0x30f706 beq 0xfe48a32a <b2_toiTime+0xfffffffffdd30e86> */
/* @0x30f70a stclo p1, c11, [r1, #-660] */
/* @0x30f70e bl 0x560fda <g_SWFlineaavertbuff+0xdf12> */
/* @0x30f712 .word 0xf8d30385 */
/* @0x30f716 .word 0xf7fe07ec */
/* @0x30f71a stmdavs r2!, {r3, r4, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x30f71e .word 0x3000f8d8 */
/* @0x30f722 mrcvs p6, #0x2, r4, c0, c1, #0x1 */
/* @0x30f726 .word 0x47984652 */
/* @0x30f72a beq 0x44bdda <g_RomDisk+0x545ba> */
/* @0x30f72e stmdahs r0, {r12, pc} */
/* @0x30f732 and sp, r4, r10, ror #1 */
/* @0x30f736 andsvs r6, pc, r3, lsr #21 */
/* @0x30f73a .word 0x33fff04f */
/* @0x30f73e stmdals r0, {r0, r1, r5, r6, r7, r9, sp, lr} */
/* @0x30f742 pop {r1, r4, r5, r12, sp, pc} */
/* @0x30f746 push {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x30f74a .word 0x460d47f0 */
/* @0x30f74e swphs r4, r1, [r0] */
/* @0x30f752 .word 0x469a2214 */
/* @0x30f756 .word 0xf8dd4604 */
/* @0x30f75a .word 0xf89d8024 */
/* @0x30f75e .word 0xf5a66028 */
/* @0x30f762 strtmi lr, [r8], -r6, lsr #30 */
/* @0x30f766 .word 0xf7fe4649 */
/* @0x30f76a .word 0x4605fb70 */
/* @0x30f76e stmdavs pc!, {r7, r11, sp, lr} ^ */
/* @0x30f772 .word 0xf5131bc3 */
/* @0x30f776 smlatble r5, r8, pc, r1 */
/* @0x30f77a adcvs r11, r0, r6, lsl r1 */
/* @0x30f77e ands r2, r6, r1, lsl #6 */
/* @0x30f782 ands r2, r4, r0, lsl #6 */
/* @0x30f786 svcne #0xa0f513 */
/* @0x30f78a cdphs p1, #0x0, c13, c0, c4, #0x0 */
/* @0x30f78e .word 0x60a7d1f8 */
/* @0x30f792 and r2, r12, r2, lsl #6 */
/* @0x30f796 ble 0x41a39e <g_RomDisk+0x22b7e> */
/* @0x30f79a adcvs r11, r0, lr, lsl #2 */
/* @0x30f79e adcvs lr, r7, r3 */
/* @0x30f7a2 tstlt r6, r4 */
/* @0x30f7a6 movwhs r6, #0x40a7 */
/* @0x30f7aa adcvs lr, r0, r1 */
/* @0x30f7ae eorvs r2, r3, r8, lsl #6 */
/* @0x30f7b2 .word 0xf0166826 */
/* @0x30f7b6 andle r0, r5, r10, lsl #4 */
/* @0x30f7ba .word 0x1000f8da */
/* @0x30f7be bl 0x3e9a52 <t1_driver_class+0x17e> */
/* @0x30f7c2 adcvs r0, r3, r1, asr #6 */
/* @0x30f7c6 stmdals r8, {r0, r1, r5, r7, r11, sp, lr} */
/* @0x30f7ca andshi pc, r0, r4, asr #17 */
/* @0x30f7ce .word 0xf8c44418 */
/* @0x30f7d2 adcvs r9, r0, r4 */
/* @0x30f7d6 stmdavc r11!, {r1, r2, r3, r4, r6, r8, r12, sp, pc} */
/* @0x30f7da .word 0xb10ab14b */
/* @0x30f7de and r6, r0, r11, lsr #18 */
/* @0x30f7e2 .word 0xf04668eb */
/* @0x30f7e6 rscvs r0, r3, r0, lsl r6 */
/* @0x30f7ea pop {r1, r2, r5, sp, lr} */
/* @0x30f7ee .word 0x464187f0 */
/* @0x30f7f2 blx 0xffb0d7f2 <b2_toiTime+0xffffffffff3b434e> */
/* @0x30f7f6 pop {r5, r6, r7, sp, lr} */
/* @0x30f7fa ldrblt r8, [r3, #-0x7f0]! */
/* @0x30f7fe .word 0xf8d04616 */
/* @0x30f802 ldrmi r4, [sp], -r0, lsl #1 */
/* @0x30f806 .word 0xb14c6b64 */
/* @0x30f80a strbtmi r6, [r10], -r0, lsr #16 */
/* @0x30f80e stmdavs r0!, {r0, r1, r11, sp, lr} ^ */
/* @0x30f812 stmdbls r0, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x30f816 eorsvs r9, r1, r1, lsl #20 */
/* @0x30f81a and r6, r5, r10, lsr #32 */
/* @0x30f81e adceq pc, r0, #208, #16 */
/* @0x30f822 adcsmi pc, r4, r0, lsl #4 */
/* @0x30f826 ldc2l p7, c15, [r6, #-1016]! */
/* @0x30f82a ldcllt p0, c11, [r0, #-8]! */
/* @0x30f82e ldrblt r0, [r3, #-0x0]! */
/* @0x30f832 strmi r4, [r12], -r6, lsl #12 */
/* @0x30f836 sadd16mi r4, r5, r0 */
/* @0x30f83a andshs r2, r0, #0, #2 */
/* @0x30f83e cdp p5, #0xb, c15, c8, c6, #0x5 */
/* @0x30f842 .word 0xf8d06870 */
/* @0x30f846 blvs 0x199ba4e <b2_toiTime+0x12425aa> */
/* @0x30f84a ldclvs p9, c11, [r1], #744 */
/* @0x30f84e strtlo pc, [r4], #2257 */
/* @0x30f852 ldclhs p3, c11, [pc], #12 */
/* @0x30f856 mrcmi p8, #0x0, sp, c0, c14, #0x0 */
/* @0x30f85a ldrbtmi r6, [lr], #-2377 */
/* @0x30f85e strbeq lr, [r4], #-2822 */
/* @0x30f862 ldrmi r8, [r4], -r6, lsr #26 */
/* @0x30f866 andsle r4, r5, r12, lsl #5 */
/* @0x30f86a andshs pc, r4, r3, lsr r8 */
/* @0x30f86e strhle r4, [r2, -r2] */
/* @0x30f872 ble 0x39a87a <ft_adobe_glyph_list+0x9f56> */
/* @0x30f876 strlo lr, [r1], #-14 */
/* @0x30f87a qsub8mi lr, r1, r4 */
/* @0x30f87e blge 0x36122e <_ZTS12CDS_Priority+0x3286> */
/* @0x30f882 .word 0xffbbf7ff */
/* @0x30f886 blls 0x33dd6e */
/* @0x30f88a rsbvs r9, r11, r1, lsl #20 */
/* @0x30f88e rscvs r4, r11, r10, lsl r4 */
/* @0x30f892 and r6, r0, r10, lsr #1 */
/* @0x30f896 andlt r2, r2, r2, lsl r0 */
/* @0x30f89a svclo #0xbcbd70 */
/* @0x30f89e stmdavs r0, {r0, r3} */
/* @0x30f8a2 ldrhlo pc, [r6], -r0 */
/* @0x30f8a6 ldrhths pc, [r10], -r0 */
/* @0x30f8aa stmdavs r3, {r1, r3, r4, r10, lr} ^ */
/* @0x30f8ae addsmi r4, r10, #167772160 */
/* @0x30f8b2 andhs sp, r0, #32768 */
/* @0x30f8b6 stclt p7, c15, [r6], #-864 */
/* @0x30f8ba ldrbmi r2, [r0, -r0]! */
/* @0x30f8be .word 0x4605b5f8 */
/* @0x30f8c2 andlo r4, r12, lr, lsl #12 */
/* @0x30f8c6 ldrmi r2, [r7], -r1, lsl #2 */
/* @0x30f8ca .word 0xffe9f7ff */
/* @0x30f8ce stmdblt r8!, {r2, r9, r10, lr} */
/* @0x30f8d2 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x30f8d6 movwhs r4, #0x163a */
/* @0x30f8da .word 0xf9dcf7fe */
/* @0x30f8de ldcllt p6, c4, [r8, #128]! */
/* @0x30f8e2 .word 0xe92d0000 */
/* @0x30f8e6 .word 0x46814ff0 */
/* @0x30f8ea addslt r6, r1, r3, lsl #18 */
/* @0x30f8ee .word 0xf1036942 */
/* @0x30f8f2 bvs 0x40fd5a <g_RomDisk+0x1853a> */
/* @0x30f8f6 .word 0xf0c0428a */
/* @0x30f8fa stmdbmi r9!, {r0, r2, r6, r7, pc} ^ */
/* @0x30f8fe bleq 0x44bf92 <g_RomDisk+0x54772> */
/* @0x30f902 .word 0xf04f2600 */
/* @0x30f906 .word 0xf06f4700 */
/* @0x30f90a andhs r4, r1, #0, #20 */
/* @0x30f90e .word 0xf8844479 */
/* @0x30f912 .word 0x91032040 */
/* @0x30f916 svceq #0x4f85b */
/* @0x30f91a stmdaeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x30f91e blhs 0xaad932 <b2_toiTime+0x35448e> */
/* @0x30f922 .word 0xf8d9d107 */
/* @0x30f926 andhs r1, r0, #8 */
/* @0x30f92a movweq lr, #0x6b08 */
/* @0x30f92e ldc2 p7, c15, [r1, #1016] */
/* @0x30f932 .word 0xf8dbe049 */
/* @0x30f936 .word 0xf7fe1004 */
/* @0x30f93a .word 0xf647f9c6 */
/* @0x30f93e addsmi r7, r0, #-268435441 */
/* @0x30f942 ldcle p6, c4, [r12, #-20]! */
/* @0x30f946 addsmi r4, r8, #83968 */
/* @0x30f94a blmi 0x1786d8a <b2_toiTime+0x102d8e6> */
/* @0x30f94e stcle p2, c4, [sp, #-608] */
/* @0x30f952 addsmi r4, r8, #82944 */
/* @0x30f956 blmi 0x1746d8e <b2_toiTime+0xfed8ea> */
/* @0x30f95a stcle p2, c4, [r11, #-608] */
/* @0x30f95e addsmi r4, r8, #80, #22 */
/* @0x30f962 movwhs r11, #0xafcc */
/* @0x30f966 and r2, r6, r9, lsl #6 */
/* @0x30f96a and r2, r4, r5, lsl #6 */
/* @0x30f96e and r2, r2, r6, lsl #6 */
/* @0x30f972 and r2, r0, r7, lsl #6 */
/* @0x30f976 stmdbls r3, {r3, r8, r9, sp} */
/* @0x30f97a .word 0x0c05f1a3 */
/* @0x30f97e movwls r4, #0x628 */
/* @0x30f982 andgt pc, r8, sp, asr #17 */
/* @0x30f986 eorhs pc, r12, r1, asr r8 */
/* @0x30f98a andls r4, r1, #17825792 */
/* @0x30f98e stmib r0, {r0, r3, r12, sp, lr, pc} ^ */
/* @0x30f992 mvnsvc pc, r7, asr #12 */
/* @0x30f996 blls 0x3361a2 */
/* @0x30f99a .word 0xc008f8dd */
/* @0x30f99e stcle p2, c4, [r7, #-544] */
/* @0x30f9a2 bllo 0x4361b6 <g_RomDisk+0x3e996> */
/* @0x30f9a6 .word 0xf8484628 */
/* @0x30f9aa .word 0xf8523006 */
/* @0x30f9ae and r1, r3, r3, lsr #32 */
/* @0x30f9b2 ldrmi r4, [r1], -r8, lsr #12 */
/* @0x30f9b6 andgt pc, r6, r8, asr #16 */
/* @0x30f9ba blx 0x224d916 <b2_toiTime+0x1af4472> */
/* @0x30f9be streq lr, [r0], #-3 */
/* @0x30f9c2 .word 0xf8482300 */
/* @0x30f9c6 stcge p0, c3, [r4, #-24] */
/* @0x30f9ca teqlt r8, r0, ror r1 */
/* @0x30f9ce andlo pc, r6, r8, asr r8 */
/* @0x30f9d2 svclt #0xb8429f */
/* @0x30f9d6 ldrmi r4, [r10, #0x61f] */
/* @0x30f9da ldrmi r11, [r10], r8, lsr #31 */
/* @0x30f9de cdphs p6, #0x1, c3, c8, c4, #0x0 */
/* @0x30f9e2 .word 0xf107d198 */
/* @0x30f9e6 blhs 0x550612 <gp_ActiveMaskObjects+0xb94a> */
/* @0x30f9ea bl 0xff5c5a02 <b2_toiTime+0xfffffffffee6c55e> */
/* @0x30f9ee .word 0xf1ba0a07 */
/* @0x30f9f2 stmdble r11, {r0, r3, r8, r9, r10, r11} */
/* @0x30f9f6 vst4.8 {d18, d19, d20, d21}, [pc], r0 */
/* @0x30f9fa movvs r3, #128, #6 */
/* @0x30f9fe .word 0x63e36323 */
/* @0x30fa02 .word 0x63602301 */
/* @0x30fa06 strbtvs r6, [r0], #1184 */
/* @0x30fa0a eors r6, r12, r3, ror #8 */
/* @0x30fa0e ldrsbls pc, [r8], pc */
/* @0x30fa12 ldrbtmi r2, [r9], #1536 */
/* @0x30fa16 blhs 0x3260ca */
/* @0x30fa1a .word 0xf858d01d */
/* @0x30fa1e bl 0xff397a3e <b2_toiTime+0xfffffffffec3e59a> */
/* @0x30fa22 .word 0xf8590207 */
/* @0x30fa26 b 0x16d3ab6 <b2_toiTime+0xf7a612> */
/* @0x30fa2a ble 0x54fbb6 <gp_ActiveMaskObjects+0xaeee> */
/* @0x30fa2e andmi pc, r0, #0, #2 */
/* @0x30fa32 addsmi r3, r10, #268435456 */
/* @0x30fa36 bl 0xff33f98e <b2_toiTime+0xfffffffffebe64ea> */
/* @0x30fa3a .word 0xf04f0003 */
/* @0x30fa3e and r4, r7, r0 */
/* @0x30fa42 andmi pc, r0, #111 */
/* @0x30fa46 addsmi r1, r10, #73728 */
/* @0x30fa4a stmne r0, {r2, r3, r6, r7, r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x30fa4e andmi pc, r0, pc, rrx */
/* @0x30fa52 ldmdb lr, {r0, r3, r12, sp, lr, pc} ^ */
/* @0x30fa56 strlo r5, [r4], -r8, lsr #3 */
/* @0x30fa5a bicsle r2, r11, r8, lsl lr */
/* @0x30fa5e rsbsmi r9, pc, #4, #22 */
/* @0x30fa62 .word 0x63232000 */
/* @0x30fa66 .word 0x63a39b05 */
/* @0x30fa6a .word 0x63639b06 */
/* @0x30fa6e .word 0x63e39b07 */
/* @0x30fa72 strtvs r9, [r3], #2824 */
/* @0x30fa76 strbtvs r9, [r3], #2825 */
/* @0x30fa7a ldrbtmi r4, [r11], #-2828 */
/* @0x30fa7e eorlo pc, r7, r3, asr r8 */
/* @0x30fa82 and r6, r0, r3, ror #8 */
/* @0x30fa86 andslt r2, r1, r1, lsr #1 */
/* @0x30fa8a svchi #0xf0e8bd */
/* @0x30fa8e ldrhi r11, [pc], r0, lsl #30 */
/* @0x30fa92 eorsmi r0, pc, #1 */
/* @0x30fa96 ldrbtls r0, [pc], -pc */
/* @0x30fa9a smlals r0, pc, r8, r0 */
/* @0x30fa9e ldmibgt pc!, {r0, r2, r4, r5, r6, r7, r8, r10} ^ */
/* @0x30faa2 svclo #0xa3b9a */
/* @0x30faa6 cdplo p0, #0x0, c0, c4, c9, #0x0 */
/* @0x30faaa ldclo p0, c0, [r12, #36] */
/* @0x30faae ldrlt r0, [r0, #-0x9] */
/* @0x30fab2 strmi r4, [r8], -r3, lsl #12 */
/* @0x30fab6 ldrmi r7, [r4], -r9, lsl #16 */
/* @0x30faba sadd16mi r2, r9, lr */
/* @0x30fabe movwhs sp, #0x104 */
/* @0x30fac2 ldrhmi lr, [r0], -sp */
/* @0x30fac6 stcllt p7, c15, [r5], {254} */
/* @0x30faca .word 0xf8fdf7fe */
/* @0x30face blmi 0x57bf66 <g_SWFlineaavertbuff+0x28e9e> */
/* @0x30fad2 .word 0xf853447b */
/* @0x30fad6 cmpmi r8, #36 */
/* @0x30fada svcmi #0xf5b0 */
/* @0x30fade .word 0xf510da04 */
/* @0x30fae2 stcle p15, c4, [r4, #-0] */
/* @0x30fae6 ldclt p4, c0, [r0, #-0] */
/* @0x30faea andmi pc, r0, pc, rrx */
/* @0x30faee stmdami r0, {r4, r8, r10, r11, r12, sp, pc} */
/* @0x30faf2 andeq r11, r1, r0, lsl sp */
/* @0x30faf6 stcllo p0, c8, [r6, #-0] */
/* @0x30fafa stmvs r0, {r0, r3} */
/* @0x30fafe .word 0xf7ff2200 */
/* @0x30fb02 ldrblt r11, [r0, #-0xfd6]! */
/* @0x30fb06 stmdbvs r5, {r2, r9, r10, lr} */
/* @0x30fb0a .word 0xf1056943 */
/* @0x30fb0e bvs 0x490356 <g_prim_v+0x34a> */
/* @0x30fb12 tstle r12, #805306377 */
/* @0x30fb16 .word 0xf7ff6829 */
/* @0x30fb1a .word 0xf7d5fff0 */
/* @0x30fb1e ldrbvs pc, [r0, #-0x8fe]! */
/* @0x30fb22 stmdavs r9!, {r5, r9, r10, lr} ^ */
/* @0x30fb26 .word 0xffe9f7ff */
/* @0x30fb2a .word 0xf8f7f7d5 */
/* @0x30fb2e .word 0x462065b0 */
/* @0x30fb32 .word 0xf7ff68a9 */
/* @0x30fb36 pld [r5, r2, ror #31] */
/* @0x30fb3a ldrbvs pc, [r0, #0x8f0]! */
/* @0x30fb3e stmvs r9!, {r5, r9, r10, lr} ^ */
/* @0x30fb42 .word 0xffdbf7ff */
/* @0x30fb46 .word 0xf8e9f7d5 */
/* @0x30fb4a andhs r6, r0, r0, lsr r6 */
/* @0x30fb4e adchs r11, r1, r0, ror sp */
/* @0x30fb52 strlt r11, [r8, #-0xd70] */
/* @0x30fb56 stmdavc r10, {r0, r1, r9, r10, lr} */
/* @0x30fb5a .word 0xd1072a1e */
/* @0x30fb5e strmi r2, [r8], -r0, lsl #4 */
/* @0x30fb62 sadd16mi r6, r3, r9 */
/* @0x30fb66 ldc2l p7, c15, [r5], #-1016 */
/* @0x30fb6a stclt p4, c1, [r8, #-0] */
/* @0x30fb6e strdle r2, r3, [r10, -pc] */
/* @0x30fb72 stmdavc r11, {r3, r7, r11, r12, sp, lr} ^ */
/* @0x30fb76 b 0x131037e <b2_toiTime+0xbb6eda> */
/* @0x30fb7a stmvc r11, {r0, r1, lr} ^ */
/* @0x30fb7e addlo r4, r0, r8, lsl r3 */
/* @0x30fb82 andhs pc, pc, r0, asr #6 */
/* @0x30fb86 strmi r11, [r8], -r8, lsl #26 */
/* @0x30fb8a pop {r0, r3, r4, r11, sp, lr} */
/* @0x30fb8e .word 0xf7fe4008 */
/* @0x30fb92 ldrlt r11, [r8, #-0x89a]! */
/* @0x30fb96 stmdbvs r2, {r2, r9, r11, sp, lr} */
/* @0x30fb9a .word 0xf8d4b16c */
/* @0x30fb9e cmplt r3, r12, ror #2 */
/* @0x30fba2 eorpl pc, sp, #9633792 */
/* @0x30fba6 ldmdavs r1, {r0, r2, r3, r6, r8, r11, r12, sp, pc} */
/* @0x30fbaa .word 0xf7ff3008 */
/* @0x30fbae .word 0xf8c4ffd2 */
/* @0x30fbb2 strtmi r0, [r8], -r8, ror #2 */
/* @0x30fbb6 andhs r11, r3, r8, lsr sp */
/* @0x30fbba adchs r11, r0, r8, lsr sp */
/* @0x30fbbe ldrlt r11, [r0, #-0xd38] */
/* @0x30fbc2 stmdbvs r3, {r2, r9, r11, sp, lr} */
/* @0x30fbc6 ldmdavs r9, {r2, r7, r8, r12, sp, pc} */
/* @0x30fbca .word 0xf7ff3008 */
/* @0x30fbce .word 0xf240ffc2 */
/* @0x30fbd2 addsmi r2, r8, #67108864 */
/* @0x30fbd6 ldrmi r11, [r8], -r8, lsr #30 */
/* @0x30fbda adcseq pc, r8, r4, asr #17 */
/* @0x30fbde svcvc #0xf5b0 */
/* @0x30fbe2 .word 0xf8c4d804 */
/* @0x30fbe6 strh r3, [r1], -r8 */
/* @0x30fbea ldclt p0, c2, [r0, #-12] */
/* @0x30fbee ldclt p0, c2, [r0, #-0] */
/* @0x30fbf2 stmdbvs r4, {r4, r5, r6, r8, r10, r12, sp, pc} */
/* @0x30fbf6 .word 0xf1046943 */
/* @0x30fbfa bvs 0x450432 <g_RomDisk+0x58c12> */
/* @0x30fbfe tstle r5, #805306377 */
/* @0x30fc02 streq pc, [r8], -r0, lsl #2 */
/* @0x30fc06 ldrtmi r6, [r0], -r1, lsr #16 */
/* @0x30fc0a .word 0xffa3f7ff */
/* @0x30fc0e addeq pc, r4, r5, asr #17 */
/* @0x30fc12 stmdavs r1!, {r4, r5, r9, r10, lr} ^ */
/* @0x30fc16 .word 0xff9df7ff */
/* @0x30fc1a addeq pc, r8, r5, asr #17 */
/* @0x30fc1e stmvs r1!, {r4, r5, r9, r10, lr} */
/* @0x30fc22 .word 0xff97f7ff */
/* @0x30fc26 addeq pc, r12, r5, asr #17 */
/* @0x30fc2a ldcllt p0, c2, [r0, #-0]! */
/* @0x30fc2e ldcllt p0, c2, [r0, #-644]! */
/* @0x30fc32 .word 0x4604b538 */
/* @0x30fc36 stmdbvs r2, {r0, r1, r8, r11, sp, lr} ^ */
/* @0x30fc3a tsteq r4, r3, lsl #2 */
/* @0x30fc3e addmi r6, r10, #20480 */
/* @0x30fc42 ldmdavs r9, {r1, r2, r4, r8, r9, r12, lr, pc} */
/* @0x30fc46 .word 0xf7ff3008 */
/* @0x30fc4a cdpne p15, #0x8, c15, c3, c4, #0x4 */
/* @0x30fc4e ldmdale r1, {r1, r2, r3, r8, r9, r11, sp} */
/* @0x30fc52 .word 0xf8a5b280 */
/* @0x30fc56 stmdbvs r2!, {r4, r5, r7} ^ */
/* @0x30fc5a bne 0xff7ea0ee <b2_toiTime+0xffffffffff090c4a> */
/* @0x30fc5e bllo 0x413ed2 <g_RomDisk+0x1c6b2> */
/* @0x30fc62 adcslo pc, r2, r5, lsr #17 */
/* @0x30fc66 andhs r8, r0, r0, lsr #9 */
/* @0x30fc6a ldrhtlo pc, [r2], r5 */
/* @0x30fc6e ldclt p4, c8, [r8, #-908]! */
/* @0x30fc72 ldclt p0, c2, [r8, #-644]! */
/* @0x30fc76 ldclt p0, c2, [r8, #-12]! */
/* @0x30fc7a stmdbvs r4, {r4, r5, r6, r8, r10, r12, sp, pc} */
/* @0x30fc7e .word 0xf1046943 */
/* @0x30fc82 bvs 0x4504aa <g_RomDisk+0x58c8a> */
/* @0x30fc86 tstle r3, #805306377 */
/* @0x30fc8a streq pc, [r8], -r0, lsl #2 */
/* @0x30fc8e ldrtmi r6, [r0], -r1, lsr #16 */
/* @0x30fc92 .word 0xff5ff7ff */
/* @0x30fc96 ble 0x359c9e */
/* @0x30fc9a ldcllt p0, c2, [r0, #-12]! */
/* @0x30fc9e ldrtmi r6, [r0], -r8, lsr #15 */
/* @0x30fca2 .word 0xf7ff6861 */
/* @0x30fca6 stmdahs r0, {r1, r2, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30fcaa .word 0x6768dbf6 */
/* @0x30fcae ldcllt p0, c2, [r0, #-0]! */
/* @0x30fcb2 ldcllt p0, c2, [r0, #-644]! */
/* @0x30fcb6 .word 0x4604b538 */
/* @0x30fcba orrlt r7, r8, r0, lsl #16 */
/* @0x30fcbe addmi r6, sp, #10813440 */
/* @0x30fcc2 stmvs r5!, {r1, r2, r3, r8, r12, lr, pc} ^ */
/* @0x30fcc6 swple r4, r5, [r11] */
/* @0x30fcca ldrmi r11, [r8], -r5, asr #2 */
/* @0x30fcce adceq r6, r10, r1, lsr #18 */
/* @0x30fcd2 svc #0xb6f5a6 */
/* @0x30fcd6 svclt #0x183000 */
/* @0x30fcda ldclt p0, c2, [r8, #-4]! */
/* @0x30fcde ldclt p6, c4, [r8, #-160]! */
/* @0x30fce2 ldclt p0, c2, [r8, #-4]! */
/* @0x30fce6 svcmi #0xf0e92d */
/* @0x30fcea bvs 0x3e1506 <error_g0017+0x3a1aa> */
/* @0x30fcee stmdblt r11, {r0, r1, r3, r7, r12, sp, pc} */
/* @0x30fcf2 rsc r2, r11, r3 */
/* @0x30fcf6 .word 0x416cf8d3 */
/* @0x30fcfa rscsle r2, r9, r0, lsl #24 */
/* @0x30fcfe .word 0x8168f8d3 */
/* @0x30fd02 stmdbvc r11, {r2, r8, r10, r12, sp, lr, pc} */
/* @0x30fd06 subvc pc, r8, #212, #16 */
/* @0x30fd0a subvs pc, r12, #212, #16 */
/* @0x30fd0e strbmi r4, [r1], -r8, asr #12 */
/* @0x30fd12 shasxmi r4, r3, r10 */
/* @0x30fd16 .word 0xffcef7ff */
/* @0x30fd1a stmdbvs r11!, {r5, r6, r8, r11, r12, sp, pc} ^ */
/* @0x30fd1e stmdbeq r8, {r0, r2, r8, r12, sp, lr, pc} */
/* @0x30fd22 .word 0xf8534648 */
/* @0x30fd26 .word 0xf7ff1c04 */
/* @0x30fd2a stmibvs r11!, {r2, r4, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x30fd2e .word 0x46074298 */
/* @0x30fd32 ldrd sp, lr, [r8], -lr */
/* @0x30fd36 strbmi r4, [r1], -r8, asr #12 */
/* @0x30fd3a shasxmi r4, r3, r10 */
/* @0x30fd3e mrc2 p7, #0x3, apsr_nzcv, c8, c14, #0x7 */
/* @0x30fd42 rscle r2, r10, r0, lsl #16 */
/* @0x30fd46 .word 0xf8d4e0c2 */
/* @0x30fd4a ldmvs r8, {r4, r5, r9, r12, sp} */
/* @0x30fd4e movwls r2, #0x9300 */
/* @0x30fd52 sublo pc, r0, #212, #16 */
/* @0x30fd56 blx 0x50e96a <SrcVerts+0x6b9ae> */
/* @0x30fd5a .word 0xf1a3696b */
/* @0x30fd5e stmdbvs r11!, {r2, r10, r11} */
/* @0x30fd62 movweq lr, #0xcbc3 */
/* @0x30fd66 bleq 0xfec0a6aa <b2_toiTime+0xfffffffffe4b1206> */
/* @0x30fd6a stmdble r2, {r1, r3, r4, r6, r7, r8, r10, lr} */
/* @0x30fd6e movwls r2, #0x93a1 */
/* @0x30fd72 .word 0xf04fe0a8 */
/* @0x30fd76 .word 0xf8d40805 */
/* @0x30fd7a blx 0x51c6e4 <SrcVerts+0x79728> */
/* @0x30fd7e .word 0xf8d4f807 */
/* @0x30fd82 strbmi r2, [r3], #-604 */
/* @0x30fd86 stmdale pc, {r0, r1, r4, r7, r9, lr} */
/* @0x30fd8a bleq 0x60acba <g_SWFaavertbuff+0x37bf2> */
/* @0x30fd8e subslo pc, r8, #212, #16 */
/* @0x30fd92 andslt pc, r0, sp, asr #17 */
/* @0x30fd96 ldrtmi r4, [r10], #-1626 */
/* @0x30fd9a andls r4, r5, #1124073472 */
/* @0x30fd9e subslo pc, r8, #196, #16 */
/* @0x30fda2 .word 0xf04f4692 */
/* @0x30fda6 subs r0, r11, r0, lsl #16 */
/* @0x30fdaa subslo pc, r4, #212, #16 */
/* @0x30fdae .word 0xf8d42101 */
/* @0x30fdb2 movwls r6, #0x4250 */
/* @0x30fdb6 strls r10, [r0], -r9, lsl #22 */
/* @0x30fdba bl 0x5349c6 <_IO_KeyMap+0x2ee> */
/* @0x30fdbe .word 0xf7d80302 */
/* @0x30fdc2 blls 0x58e35e <g_SWFlineaavertbuff+0x3b296> */
/* @0x30fdc6 subseq pc, r0, #196, #16 */
/* @0x30fdca cmnle r11, r0, lsl #22 */
/* @0x30fdce subslo pc, r8, #212, #16 */
/* @0x30fdd2 .word 0xf8c44403 */
/* @0x30fdd6 .word 0xf8d43254 */
/* @0x30fdda strbmi r3, [r3], #-604 */
/* @0x30fdde subslo pc, r12, #196, #16 */
/* @0x30fde2 sbcsle r2, r1, r0, lsl #28 */
/* @0x30fde6 strhle r4, [pc], #32 */
/* @0x30fdea blne 0xfe32a29e <b2_toiTime+0xfffffffffdbd0dfa> */
/* @0x30fdee addsmi r6, r3, #1736704 */
/* @0x30fdf2 .word 0xf853d2ca */
/* @0x30fdf6 adcsmi r2, r2, #4, #22 */
/* @0x30fdfa stmdbls r4, {r3, r4, r5, r6, r7, r8, r9, r12, lr, pc} */
/* @0x30fdfe svclt #0x3c428a */
/* @0x30fe02 .word 0xf8431812 */
/* @0x30fe06 ldrb r2, [r1, r4, lsl #24]! */
/* @0x30fe0a subslo pc, r4, #212, #16 */
/* @0x30fe0e stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x30fe12 .word 0xf842468a */
/* @0x30fe16 .word 0xf8d4302b */
/* @0x30fe1a mrrcne p2, #0x5, r3, r10, c4 */
/* @0x30fe1e subshs pc, r4, #196, #16 */
/* @0x30fe22 rscslo pc, pc, #79 */
/* @0x30fe26 .word 0xf8d4701a */
/* @0x30fe2a mrrcne p2, #0x5, r3, r10, c4 */
/* @0x30fe2e subshs pc, r4, #196, #16 */
/* @0x30fe32 andsvc r0, r10, r2, lsr lr */
/* @0x30fe36 subslo pc, r4, #212, #16 */
/* @0x30fe3a .word 0xf8c41c5a */
/* @0x30fe3e vmov.i32 q9, #0xe400 */
/* @0x30fe42 andsvc r4, r10, r7, lsl #4 */
/* @0x30fe46 subslo pc, r4, #212, #16 */
/* @0x30fe4a .word 0xf8c41c5a */
/* @0x30fe4e vmov.i32 q9, #0xe400 */
/* @0x30fe52 andsvc r2, r10, r7, lsl #4 */
/* @0x30fe56 subslo pc, r4, #212, #16 */
/* @0x30fe5a .word 0xf8c41c5a */
/* @0x30fe5e andsvc r2, lr, r4, asr r2 */
/* @0x30fe62 stmdbvs r11!, {r3, r4, r5, r7, r8, r10, lr} */
/* @0x30fe66 .word 0xf8ddd02a */
/* @0x30fe6a .word 0x4648b010 */
/* @0x30fe6e subhs pc, r4, #212, #16 */
/* @0x30fe72 .word 0xf85344c3 */
/* @0x30fe76 andls r1, r6, #43 */
/* @0x30fe7a mcr2 p7, #0x3, pc, c11, c15, #0x7 */
/* @0x30fe7e .word 0x0c00f04f */
/* @0x30fe82 .word 0xf8d40406 */
/* @0x30fe86 .word 0xf10c2240 */
/* @0x30fe8a bl 0x610a96 <g_SWFaavertbuff+0x3d9ce> */
/* @0x30fe8e addsmi r0, r3, #-2147483646 */
/* @0x30fe92 adcsle r6, r9, #688128 */
/* @0x30fe96 .word 0xf8529806 */
/* @0x30fe9a bl 0x313f26 <af_shaper_get_elem+0x9794> */
/* @0x30fe9e .word 0xf8dc0c8c */
/* @0x30fea2 movwls r0, #0x3004 */
/* @0x30fea6 strbmi r9, [r8], -r7 */
/* @0x30feaa mrc2 p7, #0x2, apsr_nzcv, c3, c15, #0x7 */
/* @0x30feae stmdals r7, {r0, r10} */
/* @0x30feb2 .word 0xffcbf7d4 */
/* @0x30feb6 ldrmi r9, [r12], r3, lsl #22 */
/* @0x30feba strb r4, [r2, r6, lsl #8]! */
/* @0x30febe bl 0x3f66da <g_MP3UpdateVolume+0x13fe> */
/* @0x30fec2 smulbbvs r11, r2, r3 */
/* @0x30fec6 movwhs r9, #0x1809 */
/* @0x30feca eorlo pc, sp, #132, #16 */
/* @0x30fece pop {r0, r1, r3, r12, sp, pc} */
/* @0x30fed2 push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x30fed6 strdlt r4, r5, [r7], r0 */
/* @0x30feda ldrmi r4, [sp], -r12, lsl #12 */
/* @0x30fede umaalne pc, r4, sp, r8 */
/* @0x30fee2 blls 0x7b3efe <b2_toiTime+0x5aa5a> */
/* @0x30fee6 .word 0xf0002900 */
/* @0x30feea ldmvs r9, {r3, r7, pc} */
/* @0x30feee .word 0xb000f8d3 */
/* @0x30fef2 .word 0xa004f8d3 */
/* @0x30fef6 ldmibvs r9, {r1, r8, r12, pc} */
/* @0x30fefa .word 0x900cf8d3 */
/* @0x30fefe .word 0xf8d3691f */
/* @0x30ff02 ldmdals r0, {r2, r4, pc} */
/* @0x30ff06 ldrdls r6, r7, [r3, -r11] */
/* @0x30ff0a stmdbls r5, {r4, r10, lr} */
/* @0x30ff0e .word 0xf7fd9304 */
/* @0x30ff12 blx 0xff04fc5a <b2_toiTime+0xfffffffffe8f67b6> */
/* @0x30ff16 .word 0xf1c3f384 */
/* @0x30ff1a blx 0xfef10c1a <b2_toiTime+0xfffffffffe7b7776> */
/* @0x30ff1e strmi pc, [r6], -r0, lsl #5 */
/* @0x30ff22 blhs 0xe56996 <b2_toiTime+0x6fd4f2> */
/* @0x30ff26 bls 0x407336 <g_RomDisk+0xfb16> */
/* @0x30ff2a and r0, r3, r3, lsl r4 */
/* @0x30ff2e .word 0xf7fd4621 */
/* @0x30ff32 strmi pc, [r3], -r0, asr #30 */
/* @0x30ff36 andmi lr, r11, pc, asr #20 */
/* @0x30ff3a ble 0x3a094e <af_orya_uniranges+0x2> */
/* @0x30ff3e andmi lr, r10, pc, asr #20 */
/* @0x30ff42 bls 0x3c808e <error_g0017+0x20d32> */
/* @0x30ff46 .word 0x4c02ea4f */
/* @0x30ff4a ble 0xb214de <b2_toiTime+0x3c803a> */
/* @0x30ff4e bleq 0x3cae82 <error_g0017+0x23b26> */
/* @0x30ff52 .word 0xf8cd4621 */
/* @0x30ff56 .word 0xf7d4c004 */
/* @0x30ff5a .word 0xf8ddffad */
/* @0x30ff5e .word 0xf1bbc004 */
/* @0x30ff62 .word 0xd10a0f00 */
/* @0x30ff66 strbtmi r9, [r0], -r2, lsl #22 */
/* @0x30ff6a bl 0xff3e17f6 <b2_toiTime+0xfffffffffec88352> */
/* @0x30ff6e .word 0xf7d40a07 */
/* @0x30ff72 .word 0xf1baffa1 */
/* @0x30ff76 andsle r0, r1, r0, lsl #30 */
/* @0x30ff7a bne 0xf48016 <b2_toiTime+0x7eeb72> */
/* @0x30ff7e smlabteq r9, r10, r11, lr */
/* @0x30ff82 .word 0xf7d4465a */
/* @0x30ff86 .word 0x4606feda */
/* @0x30ff8a andmi lr, r10, pc, asr #20 */
/* @0x30ff8e bl 0xff008026 <b2_toiTime+0xfffffffffe8aeb82> */
/* @0x30ff92 blle 0xffce3bb6 <b2_toiTime+0xffffffffff58a712> */
/* @0x30ff96 bl 0xfeff67aa <b2_toiTime+0xfffffffffe89d306> */
/* @0x30ff9a ble 0xba3baa <b2_toiTime+0x44a706> */
/* @0x30ff9e ldrteq r9, [r8], #-2563 */
/* @0x30ffa2 bl 0xff4e182e <b2_toiTime+0xfffffffffed8838a> */
/* @0x30ffa6 .word 0xf7d40902 */
/* @0x30ffaa .word 0xf1b9ff85 */
/* @0x30ffae andsle r0, r8, r0, lsl #30 */
/* @0x30ffb2 bne 0xf36bca <b2_toiTime+0x7dd726> */
/* @0x30ffb6 bl 0xff5218e6 <b2_toiTime+0xfffffffffedc8442> */
/* @0x30ffba .word 0xf7d40103 */
/* @0x30ffbe .word 0x4606febe */
/* @0x30ffc2 andmi lr, r8, pc, asr #20 */
/* @0x30ffc6 bne 0xf47fee <b2_toiTime+0x7eeb4a> */
/* @0x30ffca smlabteq r8, r9, r11, lr */
/* @0x30ffce .word 0xf7d44652 */
/* @0x30ffd2 .word 0x4606feb4 */
/* @0x30ffd6 andmi lr, r9, pc, asr #20 */
/* @0x30ffda .word 0xf7d44621 */
/* @0x30ffde ldrtmi pc, [r0], #-3947 */
/* @0x30ffe2 bls 0x447ffa <g_RomDisk+0x507da> */
/* @0x30ffe6 qadd16mi r0, r1, r0 */
/* @0x30ffea .word 0xff64f7d4 */
/* @0x30ffee eorvs r9, r8, r5, lsl #22 */
/* @0x30fff2 subseq r6, r9, r8, lsr #16 */
/* @0x30fff6 .word 0xff5ef7d4 */
/* @0x30fffa blls 0x7280a2 <g_SWFvertbuff+0x54fda> */
/* @0x30fffe sbcsvc lr, r3, #3072 */
/* @0x310002 bl 0x3ea0b6 <t1_driver_class+0x7e2> */
/* @0x310006 eorvs r0, r11, r2, ror #6 */
/* @0x31000a pop {r0, r1, r2, r12, sp, pc} */
/* @0x31000e ldrblt r8, [r0, #-0xff0]! */
/* @0x310012 strmi r4, [lr], -r4, lsl #12 */
/* @0x310016 ldmdbmi r5, {r3, r9, r10, lr} */
/* @0x31001a ldrbtmi r4, [r9], #-1557 */
/* @0x31001e b 0xfedcd6be <b2_toiTime+0xfffffffffe67421a> */
/* @0x310022 bvs 0x1bfe62a <b2_toiTime+0x14a5186> */
/* @0x310026 bvs 0xfebe80da <b2_toiTime+0xfffffffffe48ec36> */
/* @0x31002a bvs 0xffbe81de <b2_toiTime+0xffffffffff48ed3a> */
/* @0x31002e blvs 0xbe82e2 <b2_toiTime+0x48ee3e> */
/* @0x310032 blvs 0x1be83e6 <b2_toiTime+0x148ef42> */
/* @0x310036 blvs 0xfebe84ea <b2_toiTime+0xfffffffffe48f046> */
/* @0x31003a blvs 0xffbe85ee <b2_toiTime+0xffffffffff48f14a> */
/* @0x31003e stcvs p1, c6, [r3], #-684 */
/* @0x310042 ldcllt p1, c6, [r0, #-940]! */
/* @0x310046 ldrtmi r4, [r0], -r11, lsl #18 */
/* @0x31004a .word 0xf5a64479 */
/* @0x31004e ldmdblt r0, {r1, r4, r7, r9, r11, sp, lr, pc} */
/* @0x310052 eorvs r6, r11, r3, ror #19 */
/* @0x310056 stmdbmi r7, {r4, r5, r6, r8, r10, r11, r12, sp, pc} */
/* @0x31005a ldrbtmi r4, [r9], #-1584 */
/* @0x31005e b 0xfe5cd6fe <b2_toiTime+0xfffffffffde7425a> */
/* @0x310062 .word 0xf894b918 */
/* @0x310066 eorvc r3, r11, r0, lsr #32 */
/* @0x31006a andhs r11, r12, r0, ror sp */
/* @0x31006e svc #0x7abd70 */
/* @0x310072 .word 0xf5f70007 */
/* @0x310076 svc #0x4f0007 */
/* @0x31007a ldrlt r0, [r8, #-0x7]! */
/* @0x31007e stmdami r11, {r2, r9, r10, lr} */
/* @0x310082 ldrbtmi r4, [r8], #-1549 */
/* @0x310086 .word 0xf964f7d5 */
/* @0x31008a cmnlt r4, r0, lsl #19 */
/* @0x31008e stmdblt r8, {r5, r6, r11, sp, lr} */
/* @0x310092 ldclt p0, c2, [r8, #-0]! */
/* @0x310096 ldrbtmi r4, [r9], #-2311 */
/* @0x31009a .word 0xff29f7d5 */
/* @0x31009e rscsle r2, r7, r0, lsl #16 */
/* @0x3100a2 strtmi r6, [r9], -r3, lsl #16 */
/* @0x3100a6 .word 0x47986a1b */
/* @0x3100aa qasxmi r11, r0, r8 */
/* @0x3100ae blge 0x1d3f596 <b2_toiTime+0x15e60f2> */
/* @0x3100b2 bl 0x8d00ee <b2_toiTime+0x176c4a> */
/* @0x3100b6 push {r0, r1, r2} */
/* @0x3100ba .word 0xf1004ff0 */
/* @0x3100be stmdbvs r3, {r3, r8, r11} */
/* @0x3100c2 strmi r11, [r4], -r5, lsl #1 */
/* @0x3100c6 ldrmi r4, [r0], sp, lsl #12 */
/* @0x3100ca blmi 0x1b285de <b2_toiTime+0x13cf13a> */
/* @0x3100ce ldrbtmi r6, [r11], #-97 */
/* @0x3100d2 rscvs r6, r1, r2, lsr #1 */
/* @0x3100d6 strbmi r9, [r5, #-0x303] */
/* @0x3100da stmdavc r11!, {r0, r3, r4, r9, r12, lr, pc} */
/* @0x3100de blhs 0x9aa56a <b2_toiTime+0x2510c6> */
/* @0x3100e2 stmibvs r0!, {r1, r5, r6, r8, r11, sp, lr} */
/* @0x3100e6 blhs 0xb065a2 <b2_toiTime+0x3ad0fe> */
/* @0x3100ea blhs 0x30419e <TT_New_Context+0x3f96> */
/* @0x3100ee bne 0x178419a <b2_toiTime+0x102acf6> */
/* @0x3100f2 svceq #0xa1ebb0 */
/* @0x3100f6 andhs sp, r6, r1, lsl #16 */
/* @0x3100fa blhs 0xac839a <b2_toiTime+0x36eef6> */
/* @0x3100fe .word 0x0104f102 */
/* @0x310102 andsvs r6, r5, r1, ror #2 */
/* @0x310106 stclne p1, c13, [r11], #-64 */
/* @0x31010a ldrmi r4, [sp], -r3, asr #10 */
/* @0x31010e andhs sp, r0, r1, lsl #2 */
/* @0x310112 .word 0xf813e09a */
/* @0x310116 ldmdbeq r1, {r0, r8, r9, r11, sp} */
/* @0x31011a .word 0xf000290f */
/* @0x31011e .word 0xf0028093 */
/* @0x310122 bhs 0x6d0966 <g_SWFlinevertbuff+0x7d89e> */
/* @0x310126 strd sp, lr, [sp], r0 */
/* @0x31012a .word 0xd1012b1c */
/* @0x31012e add r3, r9, r2, lsl #10 */
/* @0x310132 .word 0xd1012b1d */
/* @0x310136 add r3, r5, r4, lsl #10 */
/* @0x31013a .word 0xf2402bf6 */
/* @0x31013e strlo r8, [r1, #-0x83] */
/* @0x310142 bne 0x178834a <b2_toiTime+0x102eea6> */
/* @0x310146 addmi r1, r1, #137 */
/* @0x31014a blhs 0x644ca6 <g_SWFaavertbuff+0x71bde> */
/* @0x31014e .word 0xd1066015 */
/* @0x310152 strbmi r1, [r2, #-0xc6a] */
/* @0x310156 stmdavc r11!, {r0, r1, r2, r3, r6, r7, r9, r12, lr, pc} ^ */
/* @0x31015a vst1.8 {d20, d21, d22}, [r3:64], r5 */
/* @0x31015e stmibvs r2!, {r7, r8, r9, r12, sp, lr} ^ */
/* @0x310162 tstmi r3, #196608 */
/* @0x310166 rsbeq pc, r12, #0, #2 */
/* @0x31016a .word 0x0c1cf852 */
/* @0x31016e ldreq pc, [r12], -r2, lsr #3 */
/* @0x310172 stmdahs r0, {r0, r1, r2, r4, r9, r10, lr} */
/* @0x310176 .word 0xf857d061 */
/* @0x31017a andslo r7, r12, #24, #24 */
/* @0x31017e .word 0xd1f3429f */
/* @0x310182 stmdahs r6, {r0, r1, r2, r5, r9, r11, sp, lr} */
/* @0x310186 .word 0xa008f8d6 */
/* @0x31018a bleq 0x5cadae <g_SWFlineaavertbuff+0x77ce6> */
/* @0x31018e stmdbhs r0, {r0, r1, r3, r5, r12, lr, pc} */
/* @0x310192 stmdalo r1, {r0, r4, r5, r7, r12, lr, pc} */
/* @0x310196 stmdale r12, {r2, r11, sp} ^ */
/* @0x31019a .word 0xf000e8df */
/* @0x31019e movweq r0, #0xf903 */
/* @0x3101a2 stmdbvs r2!, {r0, r1} */
/* @0x3101a6 ldmdavs r1, {r3, r6, r9, r10, lr} */
/* @0x3101aa ldc2l p7, c15, [r3], {255} */
/* @0x3101ae stmdbvs r2!, {r0, r1, r3, sp, lr, pc} */
/* @0x3101b2 ldmdavs r1, {r5, r9, r10, lr} */
/* @0x3101b6 stc2 p7, c15, [r1], #1020 */
/* @0x3101ba stmdbvs r2!, {r0, r2, sp, lr, pc} */
/* @0x3101be ldmdavs r1, {r5, r7, r11, sp, lr} */
/* @0x3101c2 .word 0xf7ff2203 */
/* @0x3101c6 blvc 0xfcf39e <b2_toiTime+0x875efa> */
/* @0x3101ca andle r2, r6, r2, lsl #20 */
/* @0x3101ce andle r2, r7, r4, lsl #20 */
/* @0x3101d2 .word 0xd1052a01 */
/* @0x3101d6 andeq pc, r10, r7, lsl #16 */
/* @0x3101da .word 0xf827e02f */
/* @0x3101de eor r0, r12, r10 */
/* @0x3101e2 andeq pc, r10, r7, asr #16 */
/* @0x3101e6 ldmdbvs r2!, {r0, r3, r5, sp, lr, pc} ^ */
/* @0x3101ea addsmi r6, r1, #573440 */
/* @0x3101ee .word 0x460abf38 */
/* @0x3101f2 ldrbtpl r6, [r10], #-2481 */
/* @0x3101f6 movwlt r2, #0x2700 */
/* @0x3101fa blne 0x44e34e <g_RomDisk+0x56b2e> */
/* @0x3101fe andls r4, r2, #72, #12 */
/* @0x310202 .word 0xf7ff9301 */
/* @0x310206 blvc 0xf8f4a6 <b2_toiTime+0x836002> */
/* @0x31020a stmdbhs r2, {r1, r9, r11, r12, pc} */
/* @0x31020e strmi r9, [r7], #-2817 */
/* @0x310212 stmdbhs r4, {r1, r2, r12, lr, pc} */
/* @0x310216 stmdbhs r1, {r0, r1, r2, r12, lr, pc} */
/* @0x31021a .word 0xf88bd105 */
/* @0x31021e and r7, r4, r0 */
/* @0x310222 andvc pc, r0, r11, lsr #17 */
/* @0x310226 .word 0xf8cbe001 */
/* @0x31022a blvc 0xf6c232 <b2_toiTime+0x812d8e> */
/* @0x31022e strmi r3, [r11], #2561 */
/* @0x310232 ldmdbvs r3!, {r0, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x310236 ldrmi r4, [r8, r0, lsr #12] */
/* @0x31023a ldmdavs r3!, {r4, r5, r8, r11, r12, sp, pc} */
/* @0x31023e svclt #0x1c2b08 */
/* @0x310242 .word 0x61636923 */
/* @0x310246 strb r3, [r6, -r1, lsl #10] */
/* @0x31024a pop {r0, r2, r12, sp, pc} */
/* @0x31024e blge 0xa34216 <b2_toiTime+0x2dad72> */
/* @0x310252 push {r0, r2, r3} */
/* @0x310256 .word 0x460c4ff0 */
/* @0x31025a strmi r6, [r5], -r6, asr #16 */
/* @0x31025e eorseq pc, r0, #196, #16 */
/* @0x310262 svcvs #0x602100 */
/* @0x310266 sadd8mi r11, r7, r3 */
/* @0x31026a .word 0xf8844698 */
/* @0x31026e stmdahs r0, {r0, r2, r3, r5, r9, r12} */
/* @0x310272 addshi pc, pc, r0 */
/* @0x310276 stmdahs r0, {r5, r7, r8, r9, r10, r11, sp, lr} */
/* @0x31027a addshi pc, r11, r0 */
/* @0x31027e beq 0xff24c696 <b2_toiTime+0xfffffffffeaf31f2> */
/* @0x310282 adcsvc pc, r8, #1325400064 */
/* @0x310286 .word 0xf5a64650 */
/* @0x31028a movwhs lr, #0x7992 */
/* @0x31028e orrlo pc, r4, r4, asr #17 */
/* @0x310292 .word 0xf8c42301 */
/* @0x310296 .word 0xf04f3188 */
/* @0x31029a .word 0xf8c433ff */
/* @0x31029e .word 0xf6403208 */
/* @0x3102a2 .word 0xf8c4735c */
/* @0x3102a6 blmi 0x145caee <b2_toiTime+0xd0364a> */
/* @0x3102aa eormi pc, r8, #196, #16 */
/* @0x3102ae subvc pc, r8, #196, #16 */
/* @0x3102b2 orrlo pc, r0, r4, asr #17 */
/* @0x3102b6 subhi pc, r12, #196, #16 */
/* @0x3102ba mlalo r0, r5, r8, pc */
/* @0x3102be .word 0xf8d5b12b */
/* @0x3102c2 vst1.8 {d23, d24, d25}, [pc:64], r4 */
/* @0x3102c6 strlo r4, [r1, -r0, lsr #23] */
/* @0x3102ca strbhs lr, [r1, -r2]! */
/* @0x3102ce blpl 0x34d412 */
/* @0x3102d2 .word 0xf10d682b */
/* @0x3102d6 rfeia r4! */
/* @0x3102da strhhs r12, [r0, -r0] */
/* @0x3102de movwls r4, #0x5640 */
/* @0x3102e2 rfeia r4! */
/* @0x3102e6 .word 0xf8d230b2 */
/* @0x3102ea eorhs r9, r8, #0 */
/* @0x3102ee .word 0xf8cd9303 */
/* @0x3102f2 .word 0xf5a6c010 */
/* @0x3102f6 bls 0x48a86e <prim_v+0xeba> */
/* @0x3102fa blls 0x3d8712 <error_g0017+0x313b6> */
/* @0x3102fe .word 0xf8dd4648 */
/* @0x310302 .word 0xf8cdc010 */
/* @0x310306 .word 0xf04fa040 */
/* @0x31030a andls r0, r8, #0, #20 */
/* @0x31030e .word 0xf8ad4652 */
/* @0x310312 blge 0x4dc432 <SrcVerts+0x39476> */
/* @0x310316 andge pc, r0, sp, asr #17 */
/* @0x31031a ldrtmi r9, [r11], -r1, lsl #6 */
/* @0x31031e eorslt pc, r12, sp, asr #17 */
/* @0x310322 subgt pc, r4, sp, lsr #17 */
/* @0x310326 mrc2 p7, #0x5, apsr_nzcv, c2, c7, #0x6 */
/* @0x31032a strmi r9, [r1], -r7, lsl #22 */
/* @0x31032e .word 0xb12b900c */
/* @0x310332 .word 0xf7d64648 */
/* @0x310336 .word 0xf8cdffff */
/* @0x31033a and r10, r1, r0, lsr r0 */
/* @0x31033e andls r9, sp, lr, lsl #14 */
/* @0x310342 .word 0xb10b9b07 */
/* @0x310346 eor r2, r7, r0, lsl #10 */
/* @0x31034a ldrtmi r6, [r0], -r9, ror #17 */
/* @0x31034e ldrmi r6, [r9], #-3939 */
/* @0x310352 blx 0xfed4e2b2 <b2_toiTime+0xfffffffffe5f4e0e> */
/* @0x310356 ldmiblt r8!, {r0, r2, r9, r10, lr} ^ */
/* @0x31035a svcvs #0xa14630 */
/* @0x31035e stc2l p7, c15, [r0, #-860]! */
/* @0x310362 stmiblt r8, {r0, r2, r9, r10, lr} ^ */
/* @0x310366 bvs 0xf61c6e <b2_toiTime+0x8087ca> */
/* @0x31036a .word 0xf7ff6a72 */
/* @0x31036e strmi pc, [r5], -r4, lsr #29 */
/* @0x310372 .word 0xf7d74630 */
/* @0x310376 ldmdblt sp!, {r5, r7, r8, r10, r11, r12, sp, lr, pc} ^ */
/* @0x31037a umlalslo pc, r12, r4, r8 */
/* @0x31037e movweq pc, #0x1023 */
/* @0x310382 adcslo pc, r12, r4, lsl #17 */
/* @0x310386 andslo pc, r4, #212, #16 */
/* @0x31038a ble 0x35af92 */
/* @0x31038e and r4, r1, r11, asr r2 */
/* @0x310392 blmi 0x604afa <g_SWFaavertbuff+0x31a32> */
/* @0x310396 andslo pc, r4, #196, #16 */
/* @0x31039a subslo pc, r0, #212, #16 */
/* @0x31039e .word 0xf8c4990c */
/* @0x3103a2 movwhs r3, #0x254 */
/* @0x3103a6 subslo pc, r8, #196, #16 */
/* @0x3103aa ldmdavs r8, {r3, r8, r9, r11, r12, pc} */
/* @0x3103ae .word 0xffc2f7d6 */
/* @0x3103b2 strmi lr, [r5], -r0 */
/* @0x3103b6 andslt r4, r3, r8, lsr #12 */
/* @0x3103ba svchi #0xf0e8bd */
/* @0x3103be andge r11, r0, r0, lsl #30 */
/* @0x3103c2 ldmvs r1!, {r0, r1, r2, r5} */
/* @0x3103c6 push {r1, r2, r3, r4, r6, r7, r9, r11, r12, sp} */
/* @0x3103ca .word 0x46924ff0 */
/* @0x3103ce addlt r6, r7, pc, asr #17 */
/* @0x3103d2 strmi r6, [r6], -r10, lsl #17 */
/* @0x3103d6 ldrmi r4, [sp], -r12, lsl #12 */
/* @0x3103da .word 0xf8dd1abf */
/* @0x3103de rscsne r9, pc, r0, asr #32 */
/* @0x3103e2 stmdaeq r1, {r0, r1, r2, r4, r12, sp, lr, pc} */
/* @0x3103e6 .word 0xf899d00d */
/* @0x3103ea ldmdblt r1, {r12} ^ */
/* @0x3103ee .word 0xf7fe4620 */
/* @0x3103f2 ldmdavs r2!, {r0, r1, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3103f6 rsclo pc, r0, #13762560 */
/* @0x3103fa eorlo pc, r0, #13828096 */
/* @0x3103fe andmi lr, r3, r0, lsl #22 */
/* @0x310402 ldmdavs r3!, {r3, r5, sp, lr} */
/* @0x310406 eorsvs pc, r1, #9633792 */
/* @0x31040a .word 0xf10db9fe */
/* @0x31040e strbmi r0, [r5], -r4, lsl #22 */
/* @0x310412 adcsmi r4, sp, #176, #12 */
/* @0x310416 qadd16mi sp, r9, r7 */
/* @0x31041a .word 0xf7fe4620 */
/* @0x31041e stclne p15, c15, [r9], #-564 */
/* @0x310422 strmi r3, [r6], #-1282 */
/* @0x310426 strls r4, [r2], -r0, lsr #12 */
/* @0x31042a .word 0xff86f7fe */
/* @0x31042e .word 0xf88d4659 */
/* @0x310432 .word 0xf8cd8004 */
/* @0x310436 .word 0xf8cd8010 */
/* @0x31043a strmi r8, [r6], #-20 */
/* @0x31043e .word 0x96034650 */
/* @0x310442 blx 0xfefce444 <b2_toiTime+0xfffffffffe874fa0> */
/* @0x310446 stmvs r3!, {r0, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x31044a movwhs r6, #0x10e3 */
/* @0x31044e andlo pc, r0, r9, lsl #17 */
/* @0x310452 pop {r0, r1, r2, r12, sp, pc} */
/* @0x310456 strlt r8, [r8, #-0xff0] */
/* @0x31045a .word 0x73fff64f */
/* @0x31045e mulsle r5, r9, r2 */
/* @0x310462 svcvc #0xc3f5b1 */
/* @0x310466 vld2.8 {d29, d31}, [pc], r11 */
/* @0x31046a ldrmi r7, [r9], #-963 */
/* @0x31046e strblo pc, [r12, #-0x8d0] */
/* @0x310472 andle r4, r11, #-1879048183 */
/* @0x310476 ldrblo pc, [r0, #-0x8d0] */
/* @0x31047a eoreq pc, r1, r3, asr r8 */
/* @0x31047e .word 0xf8d0bd08 */
/* @0x310482 .word 0xb1200c0c */
/* @0x310486 strmi r6, [r8], -r3, asr #18 */
/* @0x31048a stclt p7, c4, [r8, #-608] */
/* @0x31048e stclt p0, c2, [r8, #-0] */
/* @0x310492 adceq pc, r0, #208, #16 */
/* @0x310496 strtlo pc, [r4], #2256 */
/* @0x31049a andsne pc, r1, r3, lsr r8 */
/* @0x31049e svclt #0xdbf7ff */
/* @0x3104a2 .word 0x460fb5f8 */
/* @0x3104a6 adcmi pc, r0, #208, #16 */
/* @0x3104aa sadd16mi r4, sp, r6 */
/* @0x3104ae .word 0xf8d4b31c */
/* @0x3104b2 .word 0xf64f15e0 */
/* @0x3104b6 addsmi r7, r9, #-67108861 */
/* @0x3104ba cmplt r7, pc, lsl r0 */
/* @0x3104be .word 0x3c14f8d4 */
/* @0x3104c2 strtmi r11, [r0], -r3, lsr #18 */
/* @0x3104c6 .word 0xffc7f7ff */
/* @0x3104ca .word 0x0c14f8c4 */
/* @0x3104ce .word 0x3c14f8d4 */
/* @0x3104d2 .word 0xb166603b */
/* @0x3104d6 .word 0x3c18f8d4 */
/* @0x3104da qasxmi r11, r0, r3 */
/* @0x3104de strbne pc, [r4, #0x8d4]! */
/* @0x3104e2 .word 0xffb9f7ff */
/* @0x3104e6 .word 0x0c18f8c4 */
/* @0x3104ea .word 0x3c18f8d4 */
/* @0x3104ee tstlt r5, r3, lsr r0 */
/* @0x3104f2 strblo pc, [r8, #0x8d4]! */
/* @0x3104f6 andhs r6, r0, r11, lsr #32 */
/* @0x3104fa strdhs r11, r12, [r6], -r8 */
/* @0x3104fe ldrblt r11, [r3, #-0xdf8]! */
/* @0x310502 .word 0xf8d02300 */
/* @0x310506 strmi r4, [sp], -r0, lsr #5 */
/* @0x31050a .word 0x2c009301 */
/* @0x31050e .word 0xf8d4d040 */
/* @0x310512 blhs 0x31f55a */
/* @0x310516 mcrvs p1, #0x2, sp, c0, c4, #0x1 */
/* @0x31051a bge 0x3589a2 */
/* @0x31051e mcr2 p7, #0x0, pc, c2, c6, #0x6 */
/* @0x310522 strmi r9, [r6], -r1, lsl #22 */
/* @0x310526 teqle r3, r0, lsl #22 */
/* @0x31052a ldrbne pc, [r12, #-0x8d4] */
/* @0x31052e .word 0xf7ff4620 */
/* @0x310532 mlasvs r0, r2, pc, pc */
/* @0x310536 .word 0xf8d44620 */
/* @0x31053a .word 0xf7ff1560 */
/* @0x31053e rsbsvs pc, r0, r12, lsl #31 */
/* @0x310542 .word 0xf8d44620 */
/* @0x310546 .word 0xf7ff1568 */
/* @0x31054a adcsvs pc, r0, r6, lsl #31 */
/* @0x31054e .word 0xf8d44620 */
/* @0x310552 .word 0xf7ff156c */
/* @0x310556 rscsvs pc, r0, r0, lsl #31 */
/* @0x31055a .word 0xf8d44620 */
/* @0x31055e .word 0xf7ff1570 */
/* @0x310562 teqvs r0, r10, ror pc */
/* @0x310566 ldrblo pc, [r8, #-0x8d4]! */
/* @0x31056a .word 0xf8946173 */
/* @0x31056e shsub16vc r3, r3, r4 */
/* @0x310572 ldrblo pc, [r12, #-0x8d4]! */
/* @0x310576 .word 0xf8d48373 */
/* @0x31057a .word 0x83b33580 */
/* @0x31057e .word 0x6c10f8c4 */
/* @0x310582 .word 0x4c10f8d4 */
/* @0x310586 strgt r12, [pc, #-0xc0f] */
/* @0x31058a muleq pc, r4, r8 */
/* @0x31058e andeq lr, pc, r5, lsl #17 */
/* @0x310592 andlt r9, r2, r1, lsl #16 */
/* @0x310596 push {r4, r5, r6, r8, r10, r11, r12, sp, pc} */
/* @0x31059a .word 0x460541f0 */
/* @0x31059e adceq pc, r0, #208, #16 */
/* @0x3105a2 pkhbtmi r4, r8, lr, lsl #12 */
/* @0x3105a6 mcrvc p6, #0x0, r4, c3, c7, #0x0 */
/* @0x3105aa tstle r8, r2, lsl #22 */
/* @0x3105ae ldmdbmi r6, {r0, r1, r3, r5, r9, r10, r11, sp, lr} */
/* @0x3105b2 ldrbtmi r6, [r9], #-2136 */
/* @0x3105b6 ldc2 p7, c15, [r11], {213} */
/* @0x3105ba andhs r4, r0, #344064 */
/* @0x3105be .word 0xf7d54479 */
/* @0x3105c2 ldmdblt r0, {r0, r3, r4, r5, r7, r10, r11, r12, sp, lr, pc} */
/* @0x3105c6 pop {r0, r1, r3, sp} */
/* @0x3105ca stmdavs r4, {r4, r5, r6, r7, r8, pc} */
/* @0x3105ce rscsle r2, r9, r0, lsl #24 */
/* @0x3105d2 strbmi r4, [r1], -r8, lsr #12 */
/* @0x3105d6 shasxmi r4, r3, r10 */
/* @0x3105da pop {r5, r7, r8, r9, r10, lr} */
/* @0x3105de .word 0xf8d081f0 */
/* @0x3105e2 blhs 0x31f61a */
/* @0x3105e6 .word 0xf8d0d0ee */
/* @0x3105ea rfeda r3! */
/* @0x3105ee .word 0xf7ff1011 */
/* @0x3105f2 .word 0x4601ff32 */
/* @0x3105f6 shasxmi r11, r8, r0 */
/* @0x3105fa .word 0xf7d84632 */
/* @0x3105fe andhs pc, r0, r3, ror r9 */
/* @0x310602 ldrhhi lr, [r0, #141]! */
/* @0x310606 ldrhhi lr, [r0, #141]! */
/* @0x31060a ldrb r11, [r11, #0xf00]! */
/* @0x31060e .word 0xe12e0007 */
/* @0x310612 push {r0, r1, r2} */
/* @0x310616 bne 0x19e15fe <b2_toiTime+0x128815a> */
/* @0x31061a svcls #0x99c08 */
/* @0x31061e stmdaeq r4, {r1, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x310622 cdpls p8, #0x0, c6, c10, c4, #0x0 */
/* @0x310626 smlalmi pc, r12, r4, r8 */
/* @0x31062a .word 0xf1c3b124 */
/* @0x31062e .word 0xf1c80c00 */
/* @0x310632 and r0, r1, r0, lsl #10 */
/* @0x310636 ldrmi r4, [r12], r5, asr #12 */
/* @0x31063a eorsvs r2, r4, r0, lsl #8 */
/* @0x31063e .word 0xf500603c */
/* @0x310642 .word 0xf8945436 */
/* @0x310646 .word 0xf1b99012 */
/* @0x31064a subsle r0, lr, r0, lsl #30 */
/* @0x31064e .word 0xf1bc6840 */
/* @0x310652 blx 0x7d425c <b2_toiTime+0x7adb8> */
/* @0x310656 blx 0x94d328 <b2_toiTime+0x1f3e84> */
/* @0x31065a stmdbvs r2, {r0, r4, r5, r11, r12, sp, lr, pc} */
/* @0x31065e movweq lr, #0x8bc3 */
/* @0x310662 .word 0x61034413 */
/* @0x310666 vstrhs d13, [r0, #-148] */
/* @0x31066a bl 0xff2472a6 <b2_toiTime+0xfffffffffeaede02> */
/* @0x31066e stcle p15, c0, [r2, #-276] */
/* @0x310672 eorsvs r2, r11, r0, lsl #6 */
/* @0x310676 bl 0xff08871e <b2_toiTime+0xfffffffffe92f27a> */
/* @0x31067a stcle p15, c0, [r1, #-304] */
/* @0x31067e and r6, sp, r3, lsr #21 */
/* @0x310682 eorslo pc, r3, r11, asr #4 */
/* @0x310686 .word 0xf06fe00e */
/* @0x31068a .word 0x436b0301 */
/* @0x31068e stclle p5, c4, [pc], #624 */
/* @0x310692 bl 0xff06104e <b2_toiTime+0xfffffffffe907baa> */
/* @0x310696 stcle p15, c0, [r4, #-304] */
/* @0x31069a subsmi r6, r11, #667648 */
/* @0x31069e bvs 0xffbe8792 <b2_toiTime+0xffffffffff48f2ee> */
/* @0x3106a2 ldmdami r10, {r1, r4, sp, lr, pc} */
/* @0x3106a6 .word 0xf7fd6aa1 */
/* @0x3106aa eorsvs pc, r8, r4, lsl #23 */
/* @0x3106ae sbcmi pc, sp, r4, asr #12 */
/* @0x3106b2 stchs p0, c14, [r0, #-156] */
/* @0x3106b6 andeq pc, r0, #204, #2 */
/* @0x3106ba bl 0xfefc730a <b2_toiTime+0xfffffffffe86de66> */
/* @0x3106be stcle p15, c0, [r6, #-276] */
/* @0x3106c2 eorsvs r2, r11, r0, lsl #6 */
/* @0x3106c6 subseq r6, r11, r3, ror #21 */
/* @0x3106ca pop {r0, r1, r4, r5, sp, lr} */
/* @0x3106ce .word 0xf06f83f8 */
/* @0x3106d2 blx 0x3d12e0 <error_g0017+0x29f84> */
/* @0x3106d6 strbmi pc, [r5, #-0xc0c]! */
/* @0x3106da .word 0xf24bdcd0 */
/* @0x3106de and r3, r11, r3, lsr r0 */
/* @0x3106e2 movweq pc, #0x106f */
/* @0x3106e6 .word 0xf105fb03 */
/* @0x3106ea stclle p2, c4, [r9], #552 */
/* @0x3106ee .word 0xfc0cfb03 */
/* @0x3106f2 strbmi r4, [r5, #-0x26d]! */
/* @0x3106f6 stmdami r5, {r4, r6, r7, r10, r11, r12, lr, pc} */
/* @0x3106fa .word 0xf7fd6aa1 */
/* @0x3106fe eorsvs pc, r8, r10, asr r11 */
/* @0x310702 bvs 0xffb6271a <b2_toiTime+0xffffffffff409276> */
/* @0x310706 blx 0x188e704 <b2_toiTime+0x1135260> */
/* @0x31070a pop {r4, r5, sp, lr} */
/* @0x31070e stclmi p3, c8, [lr], {248} */
/* @0x310712 teqlt r3, #1020 */
/* @0x310716 bhs 0x1b10722 <b2_toiTime+0x13b727e> */
/* @0x31071a .word 0x4604b570 */
/* @0x31071e stmdble r5, {r1, r2, r3, r9, r10, lr} */
/* @0x310722 tsths r2, r0, lsl #16 */
/* @0x310726 ldrhtmi lr, [r0], #-141 */
/* @0x31072a bllt 0xfe5ce726 <b2_toiTime+0xfffffffffde75282> */
/* @0x31072e ldrdvs r1, r2, [r2], r3 */
/* @0x310732 ldrdvs r0, r1, [r3], #139 */
/* @0x310736 .word 0x71032301 */
/* @0x31073a cmplt r2, r3, asr #2 */
/* @0x31073e stmvs r3!, {r8, r10, sp} ^ */
/* @0x310742 andle r4, r6, #-805306359 */
/* @0x310746 .word 0xf7fe4630 */
/* @0x31074a stmdbne r3!, {r1, r7, r8, r10, r11, r12, sp, lr, pc} ^ */
/* @0x31074e ldrvc r3, [r8], #-1281 */
/* @0x310752 ldcllt p7, c14, [r0, #-980]! */
/* @0x310756 mvnsmi lr, sp, lsr #18 */
/* @0x31075a stmibvs r4, {r1, r2, r9, r10, lr} ^ */
/* @0x31075e .word 0xf894460d */
/* @0x310762 ldmdblt r11!, {r6, r12, sp} ^ */
/* @0x310766 .word 0x8000f8d1 */
/* @0x31076a stmdavs pc, {r0, r8, r9, sp} ^ */
/* @0x31076e .word 0xf8844620 */
/* @0x310772 .word 0xf7fd3040 */
/* @0x310776 ldmdblt r8, {r0, r6, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x31077a strbmi r4, [r1], -r0, lsr #12 */
/* @0x31077e .word 0xf7ff463a */
/* @0x310782 stmdblt r8!, {r0, r2, r3, r4, r7, r11, r12, sp, lr, pc} */
/* @0x310786 stmvs r9!, {r5, r9, r10, lr} */
/* @0x31078a .word 0xf7ff68ea */
/* @0x31078e .word 0xb118f897 */
/* @0x310792 ldmdavs r10, {r0, r1, r4, r5, r7, r8, r11, sp, lr} */
/* @0x310796 andsvs r11, r8, r2, lsl #18 */
/* @0x31079a ldrhhi lr, [r0, #141]! */
/* @0x31079e mvnsmi lr, sp, lsr #18 */
/* @0x3107a2 stmibvs r5, {r0, r1, r2, r9, r10, lr} ^ */
/* @0x3107a6 .word 0xf895460c */
/* @0x3107aa stmiblt r11!, {r6, r12, sp} */
/* @0x3107ae .word 0x8000f8d1 */
/* @0x3107b2 stmdavs lr, {r0, r8, r9, sp} ^ */
/* @0x3107b6 .word 0xf8854628 */
/* @0x3107ba .word 0xf7fd3040 */
/* @0x3107be stmdblt r8!, {r0, r2, r3, r4, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3107c2 strbmi r4, [r1], -r8, lsr #12 */
/* @0x3107c6 .word 0xf7ff4632 */
/* @0x3107ca .word 0xb128f879 */
/* @0x3107ce ldmdavs r10, {r0, r1, r3, r4, r5, r7, r8, r11, sp, lr} */
/* @0x3107d2 andsvs r11, r8, r10, lsl r11 */
/* @0x3107d6 ldrhhi lr, [r0, #141]! */
/* @0x3107da andeq pc, r12, r5, lsl #2 */
/* @0x3107de .word 0xf7ff2103 */
/* @0x3107e2 .word 0x4606f85e */
/* @0x3107e6 ldmibvs r11!, {r3, r5, r8, r12, sp, pc} */
/* @0x3107ea ldmiblt r2!, {r1, r3, r4, r11, sp, lr} */
/* @0x3107ee pop {r3, r4, sp, lr} */
/* @0x3107f2 qsub8mi r8, r8, r0 */
/* @0x3107f6 stmvs r2!, {r0, r5, r7, r11, sp, lr} ^ */
/* @0x3107fa .word 0xf7fd4633 */
/* @0x3107fe strtmi pc, [r8], -r11, asr #20 */
/* @0x310802 ldrtmi r6, [r3], -r1, lsr #18 */
/* @0x310806 .word 0xf7fd6962 */
/* @0x31080a strtmi pc, [r8], -r5, asr #20 */
/* @0x31080e movwhs r6, #0x19a1 */
/* @0x310812 pop {r1, r5, r6, r7, r8, r11, sp, lr} */
/* @0x310816 .word 0xf7fd41f0 */
/* @0x31081a pop {r0, r2, r3, r4, r5, r9, r11, r12, sp, pc} */
/* @0x31081e ldrblt r8, [pc, #-0x1f0]! */
/* @0x310822 bvs 0x1be203a <b2_toiTime+0x1488b96> */
/* @0x310826 stmdblt r11, {r2, r5, r12, sp} */
/* @0x31082a ands r2, pc, r0, lsl #10 */
/* @0x31082e ldmibvs sp, {r0, r9, r10, r11, sp, pc} ^ */
/* @0x310832 ldrtmi r10, [r2], -r2, lsl #22 */
/* @0x310836 stc2l p7, c15, [lr, #-1012]! */
/* @0x31083a stmdahs r0, {r0, r1, r12, pc} */
/* @0x31083e stmdbls r2, {r2, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x310842 bge 0x3e20ea <error_g0017+0x3ad8e> */
/* @0x310846 .word 0xf7d63101 */
/* @0x31084a blls 0x40fa06 <g_RomDisk+0x181e6> */
/* @0x31084e ldmdblt r11!, {r0, r2, r9, r10, lr} */
/* @0x310852 tstlt r2, r2, lsl #20 */
/* @0x310856 .word 0xf5a59901 */
/* @0x31085a blls 0x3cc322 <error_g0017+0x24fc6> */
/* @0x31085e strbtpl r2, [r10], #512 */
/* @0x310862 ldmdblt r11, {r0, r1, r5, r6, r10, r11, sp, lr} */
/* @0x310866 ldrtmi r6, [r1], -r0, ror #20 */
/* @0x31086a blx 0xff6ce7ce <b2_toiTime+0xfffffffffef7532a> */
/* @0x31086e andlt r4, r4, r8, lsr #12 */
/* @0x310872 ldrlt r11, [r3, #-0xd70] */
/* @0x310876 .word 0x3080f8d0 */
/* @0x31087a qdaddlt r6, r11, r3 */
/* @0x31087e stm sp, {r0, r3, r11, sp, lr} */
/* @0x310882 strbtmi r0, [r9], -r6 */
/* @0x310886 ldmdavs r8, {r1, r3, r4, r11, sp, lr} ^ */
/* @0x31088a .word 0x47906852 */
/* @0x31088e .word 0xf8d0e008 */
/* @0x310892 .word 0xf8d332a0 */
/* @0x310896 ldmdblt r10, {r2, r4, r6, r7, r10, sp} */
/* @0x31089a ldrteq pc, [r4], #2259 */
/* @0x31089e blx 0xff04e802 <b2_toiTime+0xfffffffffe8f535e> */
/* @0x3108a2 ldclt p0, c11, [r0, #-8] */
/* @0x3108a6 .word 0xe92d0000 */
/* @0x3108aa ssub8mi r4, lr, r0 */
/* @0x3108ae strblo pc, [r0, #0x8df]! */
/* @0x3108b2 strmi r11, [r11], r9, lsr #1 */
/* @0x3108b6 ldrbtmi r4, [r11], #-1559 */
/* @0x3108ba .word 0xf89d681b */
/* @0x3108be strmi r1, [r4], -r12, asr #1 */
/* @0x3108c2 ldmdavs r10, {r0, r2, r11, sp, lr} */
/* @0x3108c6 tstls r3, #8, #2 */
/* @0x3108ca stmiblt r1, {r0, r1, r2, r5, r9, r12, pc} ^ */
/* @0x3108ce .word 0xa004f8d0 */
/* @0x3108d2 mullo r12, r10, r8 */
/* @0x3108d6 .word 0xf10db99b */
/* @0x3108da andshs r0, r12, #128, #16 */
/* @0x3108de .word 0x9000f8d6 */
/* @0x3108e2 .word 0xf5a54640 */
/* @0x3108e6 bls 0xfcc27e <b2_toiTime+0x872dda> */
/* @0x3108ea ldrbmi r2, [r0], -r1, lsl #6 */
/* @0x3108ee ldrbmi r9, [r9], -r1, lsl #6 */
/* @0x3108f2 strbmi r9, [r3], -r0, lsl #4 */
/* @0x3108f6 .word 0xf8cd463a */
/* @0x3108fa .word 0xf7ff9080 */
/* @0x3108fe ldmdbvc r3!, {r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x310902 ssatmi r11, #0x11, r3, asr #3 */
/* @0x310906 .word 0x61672700 */
/* @0x31090a stceq p1, c15, [r0], {13} */
/* @0x31090e ldm r8!, {r0, r1, r2, r5, r7, r8, sp, lr} */
/* @0x310912 stm r12!, {r0, r1, r2, r3} */
/* @0x310916 ldm r8, {r0, r1, r2, r3} */
/* @0x31091a .word 0xf10d0007 */
/* @0x31091e .word 0xf8db0880 */
/* @0x310922 .word 0xf8cd3014 */
/* @0x310926 movwls r8, #0xa034 */
/* @0x31092a andeq lr, r7, r12, lsl #17 */
/* @0x31092e stmdbls r10, {r0, r1, r4, r5, r7, r11, sp, lr} */
/* @0x310932 vqsub.s8 d4, d16, d9 */
/* @0x310936 eor r8, r11, r2, lsr #5 */
/* @0x31093a ldrsblo pc, [r4], -r11 */
/* @0x31093e ldrmi r6, [r3], #-2426 */
/* @0x310942 stmdble r4, {r5, r6, r8, r9, r11, sp} */
/* @0x310946 tsths r2, r0, lsr r8 */
/* @0x31094a blx 0x21ce946 <b2_toiTime+0x1a754a2> */
/* @0x31094e ldclne p0, c14, [r9, #108] */
/* @0x310952 adcsvs r2, r3, r1, lsl #4 */
/* @0x310956 teqvc r2, r9, asr #17 */
/* @0x31095a ldrshvc r6, [r2, #-1]! */
/* @0x31095e stmibne r8, {r0, r1, r3, r4, r7, r8, r12, sp, pc} */
/* @0x310962 .word 0x27ff4632 */
/* @0x310966 andle r4, r2, r2, lsl #5 */
/* @0x31096a andlo r7, r1, #385875968 */
/* @0x31096e stmdblo r1, {r1, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x310972 ldrtmi r4, [r1], #-603 */
/* @0x310976 rscslo pc, pc, #79 */
/* @0x31097a movweq pc, #0x7003 */
/* @0x31097e vpmax.u8 d15, d3, d2 */
/* @0x310982 andsmi r7, r3, r10, lsl #24 */
/* @0x310986 ldmdbvc r3!, {r0, r1, r3, r10, r12, sp, lr} */
/* @0x31098a .word 0xf0002b00 */
/* @0x31098e .word 0xe7b88276 */
/* @0x310992 smlalslo pc, r9, r5, r8 */
/* @0x310996 .word 0xf10db193 */
/* @0x31099a ldrtmi r0, [r9], -r12, ror #16 */
/* @0x31099e .word 0x46402214 */
/* @0x3109a2 cdp p5, #0x0, c15, c6, c5, #0x5 */
/* @0x3109a6 .word 0xf5054620 */
/* @0x3109aa .word 0x46427190 */
/* @0x3109ae blx 0xfe7ce9aa <b2_toiTime+0xfffffffffe075506> */
/* @0x3109b2 strbmi r4, [r1], -r0, lsr #12 */
/* @0x3109b6 addvc pc, r6, #20971520 */
/* @0x3109ba blx 0xfe64e9b6 <b2_toiTime+0xfffffffffdef5512> */
/* @0x3109be beq 0xfe34cb02 <b2_toiTime+0xfffffffffdbf365e> */
/* @0x3109c2 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x3109c6 streq lr, [r10, -sp, lsl #22] */
/* @0x3109ca stmeq r8!, {r0, r2, r8, r12, sp, lr, pc} ^ */
/* @0x3109ce .word 0xf8cd3710 */
/* @0x3109d2 smladxls r6, r8, r0, r8 */
/* @0x3109d6 stmdaeq r12!, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x3109da .word 0xf8cdaf16 */
/* @0x3109de strls r8, [pc, -r0, asr #32] */
/* @0x3109e2 ldrmi r9, [r9, #0xf0a]! */
/* @0x3109e6 rschi pc, r4, r0 */
/* @0x3109ea ldmdavc r11!, {r1, r2, r8, r9, r10, r11, r12, pc} */
/* @0x3109ee svceq #0x3ea1a */
/* @0x3109f2 sbchi pc, pc, r0 */
/* @0x3109f6 ldmdage r6, {r1, r4, r5, r8, r9, r10, r11, r12, pc} */
/* @0x3109fa ldrbmi r6, [r9], -r3, lsr #18 */
/* @0x3109fe strls r4, [r0, -r10, asr #12] */
/* @0x310a02 movwhs r9, #0x1301 */
/* @0x310a06 blls 0x6b5616 <g_SWFlinevertbuff+0x6254e> */
/* @0x310a0a mrc2 p7, #0x4, apsr_nzcv, c13, c14, #0x7 */
/* @0x310a0e ldrbmi r6, [r9], -r3, lsr #18 */
/* @0x310a12 strls r4, [r0, -r10, asr #12] */
/* @0x310a16 movwls r10, #0x181b */
/* @0x310a1a movwls r2, #0x2300 */
/* @0x310a1e .word 0xf7fe9b0e */
/* @0x310a22 ldmdbls r6, {r1, r4, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x310a26 smlabtls r9, r10, r6, r0 */
/* @0x310a2a adchi pc, r9, r0, lsl #2 */
/* @0x310a2e .word 0xf010981b */
/* @0x310a32 .word 0xf0400310 */
/* @0x310a36 svcls #0x1880a4 */
/* @0x310a3a ldrsbths pc, [r4], #133 */
/* @0x310a3e .word 0x1104f8d5 */
/* @0x310a42 .word 0xf105970b */
/* @0x310a46 andsls r0, r1, #240, #14 */
/* @0x310a4a ssatmi r9, #0x1d, sp, lsl #20 */
/* @0x310a4e svcls #0x9970c */
/* @0x310a52 .word 0xf0009205 */
/* @0x310a56 .word 0xf007020a */
/* @0x310a5a andsls r0, r4, #1310720 */
/* @0x310a5e bls 0x7766ba <b2_toiTime+0x1d216> */
/* @0x310a62 .word 0xf0004293 */
/* @0x310a66 .word 0xf8dd8096 */
/* @0x310a6a bl 0xff470b32 <b2_toiTime+0xfffffffffed1768e> */
/* @0x310a6e strbmi r0, [r2], #-524 */
/* @0x310a72 ldcvc p8, c15, [r12], {18} */
/* @0x310a76 eorsle r2, r7, r0, lsl #30 */
/* @0x310a7a svchs #0x9f15 */
/* @0x310a7e .word 0xf852d06d */
/* @0x310a82 bne 0x22efd3a <b2_toiTime+0x1b96896> */
/* @0x310a86 svcls #0xb46b8 */
/* @0x310a8a stclle p5, c4, [r6], #-736 */
/* @0x310a8e stchs p8, c15, [r8], #328 */
/* @0x310a92 ssatmi r1, #0x19, r7, asr #16 */
/* @0x310a96 strbmi r9, [r7, #-0xf0b] */
/* @0x310a9a .word 0xf895dc5f */
/* @0x310a9e strdlt r1, r2, [r9, -r8]! */
/* @0x310aa2 blx 0x3992fc <ft_adobe_glyph_list+0x89d8> */
/* @0x310aa6 .word 0xf8d35303 */
/* @0x310aaa ands r3, r10, r0, asr #2 */
/* @0x310aae bl 0xff376ee2 <b2_toiTime+0xfffffffffec1da3e> */
/* @0x310ab2 .word 0xf8d50c02 */
/* @0x310ab6 bls 0x954ebe <b2_toiTime+0x1fba1a> */
/* @0x310aba blle 0x6a20f2 <g_SWFlinevertbuff+0x4f02a> */
/* @0x310abe .word 0xf5022114 */
/* @0x310ac2 blx 0x3612cc <_ZTS12CDS_Priority+0x3324> */
/* @0x310ac6 .word 0x0c125303 */
/* @0x310aca .word 0xf8d30412 */
/* @0x310ace .word 0xf5a33140 */
/* @0x310ad2 addsmi r3, r10, #128, #6 */
/* @0x310ad6 .word 0x4613bfb8 */
/* @0x310ada .word 0xf502e003 */
/* @0x310ade .word 0x0c1b4300 */
/* @0x310ae2 bls 0x951b56 <b2_toiTime+0x1f86b2> */
/* @0x310ae6 mlas r12, r11, r10, r1 */
/* @0x310aea .word 0xb3b79f14 */
/* @0x310aee stcvc p8, c15, [r12], #328 */
/* @0x310af2 stmdaeq r7, {r0, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x310af6 svcls #0x59707 */
/* @0x310afa stcle p5, c4, [lr], #-736 */
/* @0x310afe stchs p8, c15, [r8], #328 */
/* @0x310b02 addsmi r4, r7, #167772160 */
/* @0x310b06 .word 0xf895dc29 */
/* @0x310b0a strdlt r2, r3, [r10, -r8]! */
/* @0x310b0e blx 0x399368 <ft_adobe_glyph_list+0x8a44> */
/* @0x310b12 .word 0xf8d35303 */
/* @0x310b16 ands r3, r11, r0, asr #2 */
/* @0x310b1a stmdbls r5, {r0, r1, r2, r9, r11, r12, pc} */
/* @0x310b1e stmdaeq r1, {r1, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x310b22 .word 0x2100f8d5 */
/* @0x310b26 bls 0xaa216e <b2_toiTime+0x348cca> */
/* @0x310b2a tsths r4, lr, lsl #22 */
/* @0x310b2e andmi pc, r0, #8388608 */
/* @0x310b32 movwpl pc, #0x3b01 */
/* @0x310b36 ldreq r0, [r2], #-3090 */
/* @0x310b3a .word 0x3140f8d3 */
/* @0x310b3e orrlo pc, r0, #12582912 */
/* @0x310b42 svclt #0xa8429a */
/* @0x310b46 and r4, r3, r3, lsl r6 */
/* @0x310b4a movwmi pc, #0x502 */
/* @0x310b4e ldreq r0, [r11], #-3099 */
/* @0x310b52 svcls #0x99a1e */
/* @0x310b56 .word 0xb15f1a9b */
/* @0x310b5a movwlo lr, #0x1003 */
/* @0x310b5e .word 0x0c14f10c */
/* @0x310b62 bls 0x98a95e <b2_toiTime+0x2314ba> */
/* @0x310b66 ldrmi r9, [r10], #-3849 */
/* @0x310b6a .word 0xf0479219 */
/* @0x310b6e andsls r0, r6, #16, #4 */
/* @0x310b72 bls 0xabd01a <b2_toiTime+0x363b76> */
/* @0x310b76 tstls lr, #318767104 */
/* @0x310b7a tsteq r0, #64 */
/* @0x310b7e qadd16mi r9, r0, r11 */
/* @0x310b82 bge 0x9fafe2 <b2_toiTime+0x2a1b3e> */
/* @0x310b86 .word 0xf9a6f7fd */
/* @0x310b8a ldmdavc r11!, {r1, r2, r8, r9, r10, r11, r12, pc} */
/* @0x310b8e movweq lr, #0xaa23 */
/* @0x310b92 .word 0xf009703b */
/* @0x310b96 blhs 0x4d17ba <SrcVerts+0x2e7fe> */
/* @0x310b9a svcls #0x6d105 */
/* @0x310b9e beq 0xfe34cce2 <b2_toiTime+0xfffffffffdbf383e> */
/* @0x310ba2 strls r3, [r6, -r1, lsl #14] */
/* @0x310ba6 b 0x1708bb2 <b2_toiTime+0xfaf70e> */
/* @0x310baa .word 0xf1090a5a */
/* @0x310bae ldr r0, [r7, -r1, lsl #18] */
/* @0x310bb2 ldmdblt pc, {r3, r8, r9, r10, r11, r12, pc} ^ */
/* @0x310bb6 stmeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x310bba .word 0x0108eb0d */
/* @0x310bbe .word 0xf101aa1b */
/* @0x310bc2 strblo r0, [r8, #0x910]! */
/* @0x310bc6 beq 0x194d002 <b2_toiTime+0x11f3b5e> */
/* @0x310bca sub r9, lr, r6, lsl #4 */
/* @0x310bce .word 0xb14b6963 */
/* @0x310bd2 bhs 0x32b562 */
/* @0x310bd6 bllo 0x387bf6 <_ZTS13C_UTF16String+0x1eca2> */
/* @0x310bda blx 0x399434 <ft_adobe_glyph_list+0x8b10> */
/* @0x310bde bvs 0x19e17f2 <b2_toiTime+0x128834e> */
/* @0x310be2 ble 0x145b7ea <b2_toiTime+0xd02346> */
/* @0x310be6 .word 0x2100af16 */
/* @0x310bea ldcge p2, c2, [r11, #-80] */
/* @0x310bee .word 0xf5a54638 */
/* @0x310bf2 teqhs r1, #56832 */
/* @0x310bf6 qadd16mi r9, r8, r6 */
/* @0x310bfa .word 0x21006923 */
/* @0x310bfe tstls r10, #20, #4 */
/* @0x310c02 ldcl p5, c15, [r6], {165} */
/* @0x310c06 ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x310c0a .word 0xf7fd462a */
/* @0x310c0e eor pc, pc, r3, ror #18 */
/* @0x310c12 mullo r0, r9, r8 */
/* @0x310c16 svceq #0x3ea18 */
/* @0x310c1a blls 0xfc4c92 <b2_toiTime+0x86b7ee> */
/* @0x310c1e usaxmi r4, r9, r0 */
/* @0x310c22 movwls r4, #0x63a */
/* @0x310c26 movwls r6, #0x1923 */
/* @0x310c2a movwls r2, #0x2301 */
/* @0x310c2e .word 0xf7fe462b */
/* @0x310c32 ldmdbls r2!, {r1, r3, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x310c36 ldmdage r11, {r0, r1, r5, r8, r11, sp, lr} */
/* @0x310c3a .word 0x9100463a */
/* @0x310c3e movwls r4, #0x1659 */
/* @0x310c42 movwls r2, #0x2300 */
/* @0x310c46 .word 0xf7fe462b */
/* @0x310c4a qsub16mi pc, r0, lr */
/* @0x310c4e bge 0x9e259a <b2_toiTime+0x2890f6> */
/* @0x310c52 .word 0xf940f7fd */
/* @0x310c56 movweq pc, #0x7007 */
/* @0x310c5a blhs 0x4de866 <SrcVerts+0x3b8aa> */
/* @0x310c5e .word 0xf109bf0a */
/* @0x310c62 b 0x16d306e <b2_toiTime+0xf79bca> */
/* @0x310c66 .word 0xf04f0858 */
/* @0x310c6a bls 0x592e72 <g_SWFlineaavertbuff+0x3fdaa> */
/* @0x310c6e .word 0xd1cf4297 */
/* @0x310c72 ldrhs r6, [r4, -r3, lsr #17] */
/* @0x310c76 cmpvs sp, r0, lsl #10 */
/* @0x310c7a movwls r10, #0x7b1b */
/* @0x310c7e addmi r6, r5, #96, #18 */
/* @0x310c82 adchi pc, sp, r0, lsl #1 */
/* @0x310c86 movwmi pc, #0x5b07 */
/* @0x310c8a .word 0xf01369db */
/* @0x310c8e svclt #0xc0f0c */
/* @0x310c92 beq 0x34cdd6 */
/* @0x310c96 beq 0x38cdda <_ZTS7CBucketILj16384ELj262144ELb1EE+0xe36> */
/* @0x310c9a svceq #0xf1ba */
/* @0x310c9e .word 0xf105d002 */
/* @0x310ca2 and r0, r0, r1, lsl #18 */
/* @0x310ca6 ldrbeq r4, [r11], r9, lsr #13 */
/* @0x310caa blx 0x505e5c <SrcVerts+0x62ea0> */
/* @0x310cae blx 0x4e18cc <SrcVerts+0x3e910> */
/* @0x310cb2 bvs 0xfe9614de <b2_toiTime+0xfffffffffe20803a> */
/* @0x310cb6 .word 0xc028f8d2 */
/* @0x310cba .word 0xf1c3b28b */
/* @0x310cbe .word 0xf8cd0800 */
/* @0x310cc2 blx 0xaf0d5a <b2_toiTime+0x3978b6> */
/* @0x310cc6 .word 0xf1c2f28c */
/* @0x310cca .word 0xf8cd0800 */
/* @0x310cce .word 0xb10b8018 */
/* @0x310cd2 orrlo pc, r0, #817889280 */
/* @0x310cd6 .word 0xf5c2b10a */
/* @0x310cda addsmi r3, r10, #128, #4 */
/* @0x310cde .word 0x4613bfb8 */
/* @0x310ce2 ldrsbhi pc, [r8], -sp */
/* @0x310ce6 stmdalo r1, {r0, r3, r9, r11, r12, pc} */
/* @0x310cea svclt #0xb84590 */
/* @0x310cee strmi r4, [r1, #0x690] */
/* @0x310cf2 .word 0xf109d209 */
/* @0x310cf6 ldrmi r0, [r12], #513 */
/* @0x310cfa .word 0x4c00f50c */
/* @0x310cfe andmi pc, r2, r7, lsl #22 */
/* @0x310d02 strbmi r6, [r0, #-0xa80]! */
/* @0x310d06 .word 0xb14ddb10 */
/* @0x310d0a strbmi r1, [r1], #-3690 */
/* @0x310d0e smlatbmi r0, r1, r5, pc */
/* @0x310d12 andmi pc, r2, #7168 */
/* @0x310d16 addmi r6, r10, #598016 */
/* @0x310d1a adchi pc, sp, r0, lsl #6 */
/* @0x310d1e andeq pc, r0, #200, #2 */
/* @0x310d22 svclt #0xb8429a */
/* @0x310d26 adc r4, r6, r3, asr #12 */
/* @0x310d2a cdpne p1, #0x6, c11, c8, c5, #0x2 */
/* @0x310d2e .word 0xf5a14441 */
/* @0x310d32 blx 0x4e113c <SrcVerts+0x3e180> */
/* @0x310d36 bvs 0xfe320d3e <b2_toiTime+0xfffffffffdbc789a> */
/* @0x310d3a .word 0xdc044288 */
/* @0x310d3e smlabteq r0, r8, r1, pc */
/* @0x310d42 blle 0x3a1776 <af_latn_ordn_style_class+0xe> */
/* @0x310d46 .word 0xf04fe00f */
/* @0x310d4a blx 0x4d2d54 <SrcVerts+0x2fd98> */
/* @0x310d4e ldmibvs r2, {r1, r9, lr} ^ */
/* @0x310d52 strle r0, [r8], #-1746 */
/* @0x310d56 ldmdbge r11, {r5, r7, r11, sp, lr} */
/* @0x310d5a movweq lr, #0x3bc8 */
/* @0x310d5e rsbls pc, r12, sp, asr #17 */
/* @0x310d62 .word 0xf7fd931c */
/* @0x310d66 blx 0x5109f4 <SrcVerts+0x6da38> */
/* @0x310d6a bvs 0xfe9a1986 <b2_toiTime+0xfffffffffe2484e2> */
/* @0x310d6e addsvs r4, r10, #1107296256 */
/* @0x310d72 svceq #0xf1ba */
/* @0x310d76 blx 0x504d90 <SrcVerts+0x61dd4> */
/* @0x310d7a bvs 0xfe9a19a6 <b2_toiTime+0xfffffffffe248502> */
/* @0x310d7e addsvs r4, r10, #1107296256 */
/* @0x310d82 .word 0xf105b19d */
/* @0x310d86 blx 0x4df18c <SrcVerts+0x3c1d0> */
/* @0x310d8a blx 0x4e15a8 <SrcVerts+0x3e5ec> */
/* @0x310d8e bvs 0x1762db6 <b2_toiTime+0x1009912> */
/* @0x310d92 .word 0x3024f8d8 */
/* @0x310d96 mulle r8, r9, r2 */
/* @0x310d9a bne 0xff56b7e2 <b2_toiTime+0xfffffffffee1233e> */
/* @0x310d9e .word 0x2028f8d8 */
/* @0x310da2 .word 0xf7d41a80 */
/* @0x310da6 .word 0xf8c8f887 */
/* @0x310daa .word 0xf1ba002c */
/* @0x310dae andsle r0, r4, r0, lsl #30 */
/* @0x310db2 andmi pc, r9, #7168 */
/* @0x310db6 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^ */
/* @0x310dba stmdbmi r9, {r0, r1, r2, r8, r9, r11, r12, sp, lr, pc} */
/* @0x310dbe .word 0xf8d96a51 */
/* @0x310dc2 addsmi r3, r9, #36 */
/* @0x310dc6 bvs 0xfe744dee <b2_toiTime+0xfffffffffdfeb94a> */
/* @0x310dca .word 0xf8d91ac9 */
/* @0x310dce bne 0xfe318e76 <b2_toiTime+0xfffffffffdbbf9d2> */
/* @0x310dd2 .word 0xf870f7d4 */
/* @0x310dd6 eoreq pc, r12, r9, asr #17 */
/* @0x310dda strlo r3, [r1, #-0x501] */
/* @0x310dde stmvs r3!, {r1, r2, r3, r6, r8, r9, r10, sp, lr, pc} */
/* @0x310de2 ldmdbvs sp, {r2, r4, r8, r9, r10, sp} ^ */
/* @0x310de6 stclo p3, c11, [r1, #-212] */
/* @0x310dea strtmi r6, [r9], -r0, lsr #17 */
/* @0x310dee .word 0xf82df7fd */
/* @0x310df2 stmdavs r3, {r0, r11, sp, lr} ^ */
/* @0x310df6 .word 0xfc01fb07 */
/* @0x310dfa stmdaeq r12, {r2, r8, r9, r11, sp, lr, pc} */
/* @0x310dfe .word 0x2028f8d8 */
/* @0x310e02 mcrrne p4, #0x1, r4, r10, c3 */
/* @0x310e06 ldmibmi pc!, {r0, r1, r8, r10, r12, sp, lr, pc} ^ */
/* @0x310e0a andmi pc, r2, #7168 */
/* @0x310e0e ldmdbeq pc!, {r0, r3, r8, r12, sp, lr, pc} ^ */
/* @0x310e12 ldrmi r6, [r1, #0xa92] */
/* @0x310e16 .word 0xf8c8dae6 */
/* @0x310e1a strbmi r3, [r3], -r8, lsr #32 */
/* @0x310e1e .word 0xf01369db */
/* @0x310e22 sbcsle r0, pc, r12, lsl #30 */
/* @0x310e26 stmdavs r2, {r0, r8, r11, r12, sp} ^ */
/* @0x310e2a .word 0x4101fb07 */
/* @0x310e2e ldrmi r6, [r3], #-2699 */
/* @0x310e32 ldrb r6, [r7, r11, lsl #5] */
/* @0x310e36 .word 0xb1279f08 */
/* @0x310e3a .word 0x73232301 */
/* @0x310e3e cmnvc r3, r0, lsl #6 */
/* @0x310e42 svcls #0x8e01b */
/* @0x310e46 .word 0xf04f4625 */
/* @0x310e4a stmdbvs r3!, {r0, r11} ^ */
/* @0x310e4e rscsle r4, r3, #-268435447 */
/* @0x310e52 ldreq r6, [r9], r11, ror #19 */
/* @0x310e56 ldrbmi sp, [r8], -r12, lsl #8 */
/* @0x310e5a .word 0xf7fc6a29 */
/* @0x310e5e stmibvs r11!, {r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x310e62 svceq #0xaf013 */
/* @0x310e66 .word 0xf8806aab */
/* @0x310e6a svclt #0x148000 */
/* @0x310e6e sbcvs r6, r3, r3, lsl #2 */
/* @0x310e72 ldrlo r3, [r4, #-0x701] */
/* @0x310e76 ldrmi lr, [r8], r9, ror #15 */
/* @0x310e7a svcls #0x13e775 */
/* @0x310e7e ldmdavs r11!, {r0, r1, r2, r5, r9, r11, r12, pc} */
/* @0x310e82 mulle r1, r10, r2 */
/* @0x310e86 bl 0xfecce522 <b2_toiTime+0xfffffffffe57507e> */
/* @0x310e8a pop {r0, r3, r5, r12, sp, pc} */
/* @0x310e8e ldrshle r8, [r12], r0 */
/* @0x310e92 ldrblt r0, [r7, #0xd]! */
/* @0x310e96 ldrtpl pc, [r6], #-1280 */
/* @0x310e9a strmi r4, [lr], -r5, lsl #12 */
/* @0x310e9e ldrmi r7, [r7], -r3, lsr #24 */
/* @0x310ea2 .word 0xf000b10b */
/* @0x310ea6 .word 0xf505f8cf */
/* @0x310eaa orrsvs r5, lr, r7, lsr r3 */
/* @0x310eae .word 0xf105609e */
/* @0x310eb2 bicsvs r0, pc, r8, lsl #12 */
/* @0x310eb6 movwhs r6, #0x10df */
/* @0x310eba stcvc p4, c7, [r11, #-908]! */
/* @0x310ebe stmibvs r3!, {r0, r1, r4, r8, r12, sp, pc} ^ */
/* @0x310ec2 qdaddlt r7, r11, r11 */
/* @0x310ec6 .word 0xf1046a23 */
/* @0x310eca shadd16mi r0, r0, r4 */
/* @0x310ece movwhs r9, #0x300 */
/* @0x310ed2 stmdbgt lr, {r0, r8, r9, r12, pc} */
/* @0x310ed6 stc2l p7, c15, [r7], #1020 */
/* @0x310eda eorvc pc, r4, r5, lsl #12 */
/* @0x310ede .word 0xf6404631 */
/* @0x310ee2 .word 0xf5a5721c */
/* @0x310ee6 andlt lr, r3, r10, ror #22 */
/* @0x310eea ldrblt r11, [r0, #0xdf0]! */
/* @0x310eee movwhs r11, #0x108f */
/* @0x310ef2 movwls r10, #0xdd02 */
/* @0x310ef6 teqpl r7, #0, #10 */
/* @0x310efa ldreq pc, [r0], -r3, lsl #2 */
/* @0x310efe stm r5, {r2, r9, r10, lr} */
/* @0x310f02 svcge #0x50006 */
/* @0x310f06 muleq r3, r6, r8 */
/* @0x310f0a stm r7, {r1, r5, r8, r10, r11, r12, sp, lr} */
/* @0x310f0e stmdblt r2!, {r0, r1} */
/* @0x310f12 ldmibvs r9, {r5, r9, r10, lr} */
/* @0x310f16 .word 0xf7ff69da */
/* @0x310f1a blls 0x410e12 <g_RomDisk+0x195f2> */
/* @0x310f1e .word 0xf1044620 */
/* @0x310f22 .word 0xf1070108 */
/* @0x310f26 movwls r0, #0x208 */
/* @0x310f2a .word 0xf7fd9b02 */
/* @0x310f2e stmdavs r0!, {r1, r2, r3, r4, r7, r11, r12, sp, lr, pc} ^ */
/* @0x310f32 .word 0xf5044639 */
/* @0x310f36 ldrtlo r5, [r8], #-1078 */
/* @0x310f3a ldrmi r6, [r8, r3, lsl #16] */
/* @0x310f3e ldm r3, {r0, r1, r2, r8, r9, r11, sp, pc} */
/* @0x310f42 stm r6, {r0, r1} */
/* @0x310f46 ldm r5, {r0, r1} */
/* @0x310f4a stm r4, {r0, r1} */
/* @0x310f4e andlt r0, pc, r3 */
/* @0x310f52 push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x310f56 .word 0xf5004ff0 */
/* @0x310f5a addlt r5, sp, r6, lsr r5 */
/* @0x310f5e stmibvs r11!, {r1, r2, r9, r10, lr} ^ */
/* @0x310f62 ldrmi r4, [r7], -r8, lsl #13 */
/* @0x310f66 teqlt r11, r11, asr r9 */
/* @0x310f6a mulslt r1, r5, r8 */
/* @0x310f6e bleq 0x38d6e2 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x173e> */
/* @0x310f72 .word 0xf04fbf38 */
/* @0x310f76 and r0, r0, r0, lsl #22 */
/* @0x310f7a .word 0xf506469b */
/* @0x310f7e blx 0x1ae6062 <b2_toiTime+0x138cbbe> */
/* @0x310f82 movwls pc, #0x538b */
/* @0x310f86 strbmi r6, [r1, #-0x8a1] */
/* @0x310f8a stmvs r3!, {r0, r2, r8, r12, lr, pc} ^ */
/* @0x310f8e strhle r4, [r2, -r11] */
/* @0x310f92 blhs 0x337bae */
/* @0x310f96 smlsdls r0, r3, r0, sp */
/* @0x310f9a ldrtmi r10, [r0], -r6, lsl #22 */
/* @0x310f9e blge 0x4f5baa <SrcVerts+0x52bee> */
/* @0x310fa2 strbmi r9, [r3], -r2, lsl #6 */
/* @0x310fa6 .word 0xf7ff68e2 */
/* @0x310faa bls 0x4cfc82 <SrcVerts+0x2ccc6> */
/* @0x310fae .word 0xf10d68a3 */
/* @0x310fb2 stmvs r1!, {r5, r8, r9, r11} ^ */
/* @0x310fb6 beq 0x3cbbde <error_g0017+0x24882> */
/* @0x310fba movwls r4, #0x8413 */
/* @0x310fbe ldrmi r9, [r9], #-2823 */
/* @0x310fc2 stmdbeq r3, {r0, r1, r2, r8, r9, r11, sp, lr, pc} */
/* @0x310fc6 smlattls r9, r11, r12, r7 */
/* @0x310fca ldrtmi r11, [r0], -r3, ror #2 */
/* @0x310fce muleq r6, r11, r8 */
/* @0x310fd2 .word 0xff8bf7ff */
/* @0x310fd6 strbtvc r2, [r11], #768 */
/* @0x310fda strtvc r2, [r11], #-769 */
/* @0x310fde andge pc, r0, r4, asr #17 */
/* @0x310fe2 andls pc, r4, r4, asr #17 */
/* @0x310fe6 mlalo r0, r4, r8, pc */
/* @0x310fea movwhs r11, #0x153 */
/* @0x310fee andls pc, r0, sp, asr #17 */
/* @0x310ff2 ldrtmi r9, [r0], -r1, lsl #6 */
/* @0x310ff6 .word 0xf1064653 */
/* @0x310ffa ldrbmi r0, [r10], -r8, lsl #2 */
/* @0x310ffe blx 0x1a8effc <b2_toiTime+0x1335b58> */
/* @0x311002 muleq r3, r11, r8 */
/* @0x311006 .word 0xf8842301 */
/* @0x31100a movwhs r3, #0x2020 */
/* @0x31100e .word 0xf1046263 */
/* @0x311012 stm r3, {r3, r5, r8, r9} */
/* @0x311016 blls 0x45102a <g_RomDisk+0x5980a> */
/* @0x31101a eorsge pc, r0, r4, asr #17 */
/* @0x31101e eorsls pc, r4, r4, asr #17 */
/* @0x311022 bvs 0xdfd576 <b2_toiTime+0x6a40d2> */
/* @0x311026 tsteq r4, r5, lsl #2 */
/* @0x31102a andeq pc, r8, r6, lsl #2 */
/* @0x31102e movwhs r9, #0x300 */
/* @0x311032 stmdbgt lr, {r0, r8, r9, r12, pc} */
/* @0x311036 ldc2 p7, c15, [r7], #-1020 */
/* @0x31103a andhi pc, r8, r4, asr #17 */
/* @0x31103e andlt r6, sp, r7, ror #1 */
/* @0x311042 svchi #0xf0e8bd */
/* @0x311046 .word 0xf500b5f7 */
/* @0x31104a .word 0xf5005437 */
/* @0x31104e smladxhs r1, r6, r5, r5 */
/* @0x311052 strbtvc r4, [pc], #-1542 */
/* @0x311056 stmibvs r2!, {r0, r5, r7, r8, r11, sp, lr} ^ */
/* @0x31105a .word 0xff7bf7ff */
/* @0x31105e mlalo r0, r4, r8, pc */
/* @0x311062 smlsdls r1, r3, r1, r11 */
/* @0x311066 stmdavs r3!, {r4, r5, r9, r10, lr} ^ */
/* @0x31106a .word 0x0108f106 */
/* @0x31106e eorseq pc, r8, #1073741825 */
/* @0x311072 stmdavs r3!, {r8, r9, r12, pc} */
/* @0x311076 blx 0xb8f074 <b2_toiTime+0x435bd0> */
/* @0x31107a strbtvc r2, [r11], #769 */
/* @0x31107e strtvc r2, [r11], #-768 */
/* @0x311082 .word 0xf884746b */
/* @0x311086 andlt r3, r3, r0, lsr #32 */
/* @0x31108a push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x31108e .word 0xf5004ff0 */
/* @0x311092 addlt r5, pc, r7, lsr r4 */
/* @0x311096 ldrmi r4, [r7], -r8, lsl #13 */
/* @0x31109a andls r4, r0, #162529280 */
/* @0x31109e movwls r10, #0x1b06 */
/* @0x3110a2 movwls r10, #0x2b07 */
/* @0x3110a6 stmvs r1!, {r0, r1, r6, r9, r10, lr} */
/* @0x3110aa stmvs r2!, {r0, r2, r9, r10, lr} ^ */
/* @0x3110ae .word 0xf7ff9e18 */
/* @0x3110b2 bls 0x9cfb7a <b2_toiTime+0x2766d6> */
/* @0x3110b6 blge 0x522a22 <SrcVerts+0x7fa66> */
/* @0x3110ba movwls r4, #0x1628 */
/* @0x3110be andls r10, r0, #9216 */
/* @0x3110c2 movwls r4, #0x2632 */
/* @0x3110c6 .word 0xf7ff9b19 */
/* @0x3110ca blne 0xfff8fb62 <b2_toiTime+0xffffffffff8366be> */
/* @0x3110ce andeq lr, r11, #200, #22 */
/* @0x3110d2 blx 0x76b288 <b2_toiTime+0x11de4> */
/* @0x3110d6 .word 0xf8ddf138 */
/* @0x3110da blx 0x7b5274 <b2_toiTime+0x5bdd0> */
/* @0x3110de bne 0xfe58d9c2 <b2_toiTime+0xfffffffffde3451e> */
/* @0x3110e2 strmi r6, [r10], #-2330 */
/* @0x3110e6 bls 0x4a9556 <SrcVerts+0x659a> */
/* @0x3110ea stmvs r1!, {r0, r1, r5, r7, r11, sp, lr} ^ */
/* @0x3110ee ldrmi r4, [r3], #-1168 */
/* @0x3110f2 movwls r9, #0xaa08 */
/* @0x3110f6 ldrmi r9, [r3], #2823 */
/* @0x3110fa bls 0x9a2346 <b2_toiTime+0x248ea2> */
/* @0x3110fe ldrmi r4, [pc], #-1049 */
/* @0x311102 .word 0x910b9b09 */
/* @0x311106 bl 0x4a2176 <m_CurrentMatrix+0x6> */
/* @0x31110a .word 0xf5050a03 */
/* @0x31110e andls r5, r5, #-671088640 */
/* @0x311112 ldclvc p14, c10, [r10], {10} */
/* @0x311116 ldm r6, {r1, r3, r5, r6, r8, r12, sp, pc} */
/* @0x31111a strtmi r0, [r8], -r6 */
/* @0x31111e .word 0xf7ff9304 */
/* @0x311122 blls 0x450cba <g_RomDisk+0x5949a> */
/* @0x311126 ldrbvc r2, [r10], #512 */
/* @0x31112a ldrvc r2, [r10], #-513 */
/* @0x31112e andhi pc, r0, r4, asr #17 */
/* @0x311132 .word 0xf5056067 */
/* @0x311136 .word 0xf8935337 */
/* @0x31113a .word 0xb1633020 */
/* @0x31113e strls r2, [r0, -r0, lsl #6] */
/* @0x311142 strtmi r9, [r8], -r1, lsl #6 */
/* @0x311146 .word 0xf1054643 */
/* @0x31114a ldrtmi r0, [r2], -r8, lsl #2 */
/* @0x31114e eorshi pc, r0, sp, asr #17 */
/* @0x311152 .word 0xf7fd970d */
/* @0x311156 ldm r6, {r1, r4, r5, r7, r9, r11, r12, sp, lr, pc} */
/* @0x31115a movwhs r0, #0x1003 */
/* @0x31115e eorlo pc, r0, r4, lsl #17 */
/* @0x311162 rsbvs r2, r3, #4, #6 */
/* @0x311166 msreq APSR_nzcvq, #4, #2 */
/* @0x31116a stm r3, {r0, r2, r9, r11, r12, pc} */
/* @0x31116e .word 0xf5050003 */
/* @0x311172 .word 0xf8c45338 */
/* @0x311176 .word 0x63678030 */
/* @0x31117a eorslt pc, r8, r4, asr #17 */
/* @0x31117e eorsge pc, r12, r4, asr #17 */
/* @0x311182 .word 0xf505605a */
/* @0x311186 .word 0xf8c35236 */
/* @0x31118a ldmibvs r3, {r12, pc} ^ */
/* @0x31118e qdaddlt r7, r9, r9 */
/* @0x311192 .word 0xf1056a11 */
/* @0x311196 .word 0x91000008 */
/* @0x31119a mrsls r2, apsr */
/* @0x31119e ldmibvs r2, {r0, r4, r6, r8, r11, sp, lr} */
/* @0x3111a2 blx 0xfe38f1a8 <b2_toiTime+0xfffffffffdc35d04> */
/* @0x3111a6 .word 0xf5059b19 */
/* @0x3111aa bls 0x9a668e <b2_toiTime+0x24d1ea> */
/* @0x3111ae rscvs r6, r10, r11, lsr #1 */
/* @0x3111b2 pop {r0, r1, r2, r3, r12, sp, pc} */
/* @0x3111b6 push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x3111ba ldrshlt r4, [r9], r0 */
/* @0x3111be stmdavs r11, {r1, r3, r4, r7, r9, r10, lr} */
/* @0x3111c2 .word 0x9088f8dd */
/* @0x3111c6 strmi r2, [r7], -r0, lsl #10 */
/* @0x3111ca movwls r4, #0xa688 */
/* @0x3111ce ldmdavs r3, {r2, r3, r5, r9, r10, lr} */
/* @0x3111d2 .word 0xf8994616 */
/* @0x3111d6 movwls r11, #0xb009 */
/* @0x3111da bleq 0x38d94e <_ZTS7CBucketILj16384ELj262144ELb1EE+0x19aa> */
/* @0x3111de svclt #0x38ab0a */
/* @0x3111e2 bleq 0x34d326 */
/* @0x3111e6 svceq #0xf1bb */
/* @0x3111ea andhs r11, r10, #12, #30 */
/* @0x3111ee andls r2, r8, #-1879048192 */
/* @0x3111f2 eorgt pc, r5, r3, asr r8 */
/* @0x3111f6 addeq lr, r5, #3072 */
/* @0x3111fa andne pc, r5, r9, lsl r8 */
/* @0x3111fe andgt pc, r8, r2, asr #17 */
/* @0x311202 stclne p1, c11, [r1], #-516 */
/* @0x311206 .word 0x91094638 */
/* @0x31120a andls r4, r5, #34603008 */
/* @0x31120e .word 0xf8cd9306 */
/* @0x311212 .word 0xf7fec01c */
/* @0x311216 bls 0x48f462 <prim_v+0x5aae> */
/* @0x31121a ldrsbgt pc, [r12], -sp */
/* @0x31121e strbtmi r9, [r0], #-3081 */
/* @0x311222 blls 0x4a946a <SrcVerts+0x64ae> */
/* @0x311226 strlo r9, [r1, #-0xa08] */
/* @0x31122a blle 0xffb61c86 <b2_toiTime+0xffffffffff4087e2> */
/* @0x31122e .word 0xf1bb4621 */
/* @0x311232 andle r0, r1, r0, lsl #30 */
/* @0x311236 tstls r5, #3342336 */
/* @0x31123a umulllo pc, r12, sp, r8 */
/* @0x31123e .word 0xf8ddb30b */
/* @0x311242 shsaxmi r9, r8, r0 */
/* @0x311246 .word 0x3000f8d8 */
/* @0x31124a ldcls p6, c4, [r5, #-132] */
/* @0x31124e movweq lr, #0x9bc3 */
/* @0x311252 rscvc lr, r3, #536576 */
/* @0x311256 rscvc lr, r3, #165888 */
/* @0x31125a andls r6, r5, #3342336 */
/* @0x31125e b 0xfe3d7e12 <b2_toiTime+0xfffffffffdc7e96e> */
/* @0x311262 bl 0xfedf01f6 <b2_toiTime+0xfffffffffe696d52> */
/* @0x311266 .word 0xf7fe7be3 */
/* @0x31126a bls 0x48f40e <prim_v+0x5a5a> */
/* @0x31126e stcle p5, c4, [r2, #-360] */
/* @0x311272 andsls r4, r6, r8, asr #8 */
/* @0x311276 .word 0xf8d8e01e */
/* @0x31127a strmi r3, [r5], #-0 */
/* @0x31127e tstls r6, #96468992 */
/* @0x311282 .word 0xf899e01a */
/* @0x311286 teqlt r11, r10 */
/* @0x31128a ldcls p6, c4, [r4, #-224] */
/* @0x31128e .word 0xf854f7fe */
/* @0x311292 strtmi r3, [r8], #-1025 */
/* @0x311296 and r9, r2, r6, lsl r0 */
/* @0x31129a .word 0x3000f8d8 */
/* @0x31129e .word 0xf8999316 */
/* @0x3112a2 teqlt r11, r11 */
/* @0x3112a6 qasxmi r4, r1, r8 */
/* @0x3112aa .word 0xf7fe9d15 */
/* @0x3112ae strtmi pc, [r8], #-2117 */
/* @0x3112b2 and r9, r1, r7, lsl r0 */
/* @0x3112b6 tstls r7, #3342336 */
/* @0x3112ba stmdbge r12, {r0, r1, r2, r3, r8, r9, r11, r12, pc} */
/* @0x3112be movwls r4, #0x650 */
/* @0x3112c2 movwls r9, #0x1b10 */
/* @0x3112c6 movwls r9, #0x2b11 */
/* @0x3112ca .word 0xf7ffc90e */
/* @0x3112ce ldmdbge r2, {r1, r2, r3, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3112d2 uadd16mi r9, r0, r6 */
/* @0x3112d6 blls 0x87833a <b2_toiTime+0x11ee96> */
/* @0x3112da stm sp, {r1, r10, r12, pc} */
/* @0x3112de stmdbgt lr, {r3, r5} */
/* @0x3112e2 mrc2 p7, #0x6, apsr_nzcv, c3, c15, #0x7 */
/* @0x3112e6 ldrhtvs r6, [r11], #139 */
/* @0x3112ea andpl pc, r0, r8, asr #17 */
/* @0x3112ee andslt r6, r9, r4, lsr r0 */
/* @0x3112f2 svchi #0xf0e8bd */
/* @0x3112f6 .word 0xe92d0000 */
/* @0x3112fa ldrshlt r4, [r3], r0 */
/* @0x3112fe .word 0x4607461d */
/* @0x311302 ldrsbthi pc, [r4], #-141 */
/* @0x311306 strmi r2, [r12], -r0, lsl #6 */
/* @0x31130a .word 0xf5b89205 */
/* @0x31130e cdpls p15, #0x1, c5, c15, c0, #0x2 */
/* @0x311312 andle r9, r4, r6, lsl #6 */
/* @0x311316 strhmi pc, [r0, r8] */
/* @0x31131a .word 0x414b424b */
/* @0x31131e movwhs lr, #0x1000 */
/* @0x311322 ldmibeq pc!, {r0, r1, r12, sp, lr, pc} ^ */
/* @0x311326 andhs pc, r1, #64, #4 */
/* @0x31132a svclt #0x82b00 */
/* @0x31132e blls 0xa99cb6 <b2_toiTime+0x340812> */
/* @0x311332 .word 0x21009203 */
/* @0x311336 .word 0xf8d32228 */
/* @0x31133a blge 0x539342 <obj_numb_event+0x23d2> */
/* @0x31133e ldrmi r9, [r8], -r4, lsl #6 */
/* @0x311342 .word 0xb000f8da */
/* @0x311346 ldmdb r4!, {r0, r2, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x31134a eorshi pc, r12, sp, asr #17 */
/* @0x31134e stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x311352 eorge pc, r0, sp, asr #17 */
/* @0x311356 blls 0x3d976e <error_g0017+0x32412> */
/* @0x31135a beq 0xa4d796 <b2_toiTime+0x2f42f2> */
/* @0x31135e andhi pc, r0, sp, asr #17 */
/* @0x311362 .word 0xf8cd4658 */
/* @0x311366 strbmi r10, [r2], -r4 */
/* @0x31136a .word 0xf7d69710 */
/* @0x31136e blls 0x510db2 <SrcVerts+0x6ddf6> */
/* @0x311372 andls r4, r12, r1, lsl #12 */
/* @0x311376 ldrbmi r11, [r8], -r11, lsr #2 */
/* @0x31137a .word 0xffdcf7d5 */
/* @0x31137e eorshi pc, r0, sp, asr #17 */
/* @0x311382 blls 0x409392 <g_RomDisk+0x11b72> */
/* @0x311386 movwls r9, #0xe00d */
/* @0x31138a ldrsblt pc, [r12], -sp */
/* @0x31138e svceq #0xf1bb */
/* @0x311392 adcshi pc, sp, r0, asr #32 */
/* @0x311396 uasxmi r4, r9, r8 */
/* @0x31139a .word 0xf5a522bc */
/* @0x31139e blmi 0x1b4b7c6 <b2_toiTime+0x13f2322> */
/* @0x3113a2 vst1.8 {d22, d23, d24, d25}, [pc:256], r11 */
/* @0x3113a6 rsbsvs r1, r11, #72, #6 */
/* @0x3113aa rscsvs r2, r11, #134217728 */
/* @0x3113ae orrlo pc, r0, #1325400064 */
/* @0x3113b2 .word 0x63fb633b */
/* @0x3113b6 tsths r0, #536870916 */
/* @0x3113ba addslo pc, r12, r7, asr #17 */
/* @0x3113be .word 0x73fff64f */
/* @0x3113c2 mlasvs r11, r8, r6, r4 */
/* @0x3113c6 adcsvs r6, r11, r11, ror r0 */
/* @0x3113ca ldrshvs r6, [r11, -r11]! */
/* @0x3113ce .word 0xf8c7617b */
/* @0x3113d2 .word 0xf8c73080 */
/* @0x3113d6 .word 0xf8c73084 */
/* @0x3113da .word 0xf8c73088 */
/* @0x3113de vhadd.s8 d19, d16, d28 */
/* @0x3113e2 .word 0xf1b92301 */
/* @0x3113e6 svclt #0x80f00 */
/* @0x3113ea .word 0xf8c72330 */
/* @0x3113ee stmvs r3!, {r3, r4, r5, r7, r12, sp} ^ */
/* @0x3113f2 strtmi r11, [r0], -r3, asr #2 */
/* @0x3113f6 bge 0x4b7812 <SrcVerts+0x14856> */
/* @0x3113fa .word 0xf7fc4653 */
/* @0x3113fe strmi pc, [r3], r11, lsl #31 */
/* @0x311402 ands r11, r0, r0, asr #19 */
/* @0x311406 stmdbvs r1!, {r3, r5, r9, r10, lr} ^ */
/* @0x31140a blx 0x164f366 <b2_toiTime+0xef5ec2> */
/* @0x31140e stmdahs r0, {r0, r1, r7, r9, r10, lr} */
/* @0x311412 qsub16mi sp, r8, sp */
/* @0x311416 bge 0x4abaa2 <SrcVerts+0x8ae6> */
/* @0x31141a stc2l p7, c15, [r2, #-856] */
/* @0x31141e stmdahs r0, {r0, r1, r7, r9, r10, lr} */
/* @0x311422 stmibvs r3!, {r0, r2, r4, r5, r6, r8, r12, lr, pc} */
/* @0x311426 stmdbls r6, {r0, r1, r2, r8, r9, r12, pc} */
/* @0x31142a bls 0x4fb452 <SrcVerts+0x58496> */
/* @0x31142e .word 0xf7fe440a */
/* @0x311432 strmi pc, [r3], r2, asr #28 */
/* @0x311436 tstlt r11, r3, ror #17 */
/* @0x31143a stmdblt r11!, {r0, r1, r5, r9, r11, sp, lr} */
/* @0x31143e and r6, r0, r0, lsr #16 */
/* @0x311442 stmdbge r6, {r3, r5, r9, r10, lr} */
/* @0x311446 stc2l p7, c15, [r0], #856 */
/* @0x31144a svceq #0xf1bb */
/* @0x31144e .word 0xf8d7d15f */
/* @0x311452 strbmi r3, [r3, #-0x84] */
/* @0x311456 ldmdals lr, {r0, r1, r3, r4, r6, r8, r12, lr, pc} */
/* @0x31145a uasxmi r4, r10, r9 */
/* @0x31145e .word 0xf7fe465b */
/* @0x311462 stmdahs r0, {r3, r4, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x311466 .word 0xf1b9d152 */
/* @0x31146a teqle r2, r0, lsl #30 */
/* @0x31146e .word 0x3080f8d6 */
/* @0x311472 .word 0x1c5a6bdb */
/* @0x311476 mrcvs p1, #0x1, sp, c2, c6, #0x0 */
/* @0x31147a .word 0xf8c76c53 */
/* @0x31147e mrrcvs p2, #0x8, r3, r3, c8 */
/* @0x311482 .word 0xf8d7b93b */
/* @0x311486 bllt 0xbddeae <b2_toiTime+0x484a0a> */
/* @0x31148a andslo pc, r4, #14090240 */
/* @0x31148e addlo pc, r8, #13041664 */
/* @0x311492 b 0xfe409516 <b2_toiTime+0xfffffffffdcb0072> */
/* @0x311496 b 0xfe3de1aa <b2_toiTime+0xfffffffffdc84d06> */
/* @0x31149a b 0xfe7e21ee <b2_toiTime+0xfffffffffe088d4a> */
/* @0x31149e ldrbtle r1, [r8], #835 */
/* @0x3114a2 ubfx r6, r3, #0x8, #0xf */
/* @0x3114a6 addlo pc, r8, #13041664 */
/* @0x3114aa .word 0x3080f8d6 */
/* @0x3114ae blhs 0x32c422 */
/* @0x3114b2 .word 0xf8d6d0e7 */
/* @0x3114b6 blvs 0xff99d6be <b2_toiTime+0xffffffffff24421a> */
/* @0x3114ba sublo lr, r2, #532480 */
/* @0x3114be subsmi lr, r2, #532480 */
/* @0x3114c2 subne lr, r2, #532480 */
/* @0x3114c6 .word 0xf8d663da */
/* @0x3114ca blvs 0xff9dd6d2 <b2_toiTime+0xffffffffff28422e> */
/* @0x3114ce blle 0xfff1c0d6 <b2_toiTime+0xffffffffff7c2c32> */
/* @0x3114d2 .word 0xf8d7e7d7 */
/* @0x3114d6 bicslt r3, r3, r8, lsl r2 */
/* @0x3114da qsub16mi r6, r8, r9 */
/* @0x3114de ldrmi r9, [r9], #-2588 */
/* @0x3114e2 .word 0xf7d54411 */
/* @0x3114e6 pkhtbmi pc, r3, pc, asr #19 */
/* @0x3114ea .word 0xf507b988 */
/* @0x3114ee qadd16mi r7, r9, r8 */
/* @0x3114f2 strbmi r2, [r11], -r1, lsl #4 */
/* @0x3114f6 .word 0xf7fd4620 */
/* @0x3114fa strmi pc, [r3], r2, asr #26 */
/* @0x3114fe qasxmi r11, r0, r8 */
/* @0x311502 .word 0x7121f507 */
/* @0x311506 usaxmi r4, r11, r10 */
/* @0x31150a blx 0x1d4f508 <b2_toiTime+0x15f6064> */
/* @0x31150e blls 0x522f22 <SrcVerts+0x7ff66> */
/* @0x311512 ldmdavs r8, {r2, r3, r8, r11, r12, pc} */
/* @0x311516 .word 0xff0ef7d5 */
/* @0x31151a andslt r4, r3, r8, asr r6 */
/* @0x31151e svchi #0xf0e8bd */
/* @0x311522 andeq r11, r0, r0, lsl #30 */
/* @0x311526 push {r2, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x31152a ssub8mi r4, pc, r0 */
/* @0x31152e strmi r6, [r10], r11, lsl #28 */
/* @0x311532 ldrhtlt r4, [r1], pc */
/* @0x311536 .word 0xf8d34605 */
/* @0x31153a ldrbtmi r11, [r9], #-4 */
/* @0x31153e .word 0xf8dd9209 */
/* @0x311542 ldrbmi r8, [r8], -r8, ror #1 */
/* @0x311546 stc2l p7, c15, [pc], #848 */
/* @0x31154a stmdahs r0, {r2, r3, r12, pc} */
/* @0x31154e ldrhi pc, [r2], -r0 */
/* @0x311552 andhs r4, r1, #184, #18 */
/* @0x311556 .word 0x0060f8da */
/* @0x31155a .word 0xf7d44479 */
/* @0x31155e ldmibmi r5!, {r0, r1, r3, r5, r6, r7, r10, r11, r12, sp, lr, pc} */
/* @0x311562 andsls r4, r2, r9, ror r4 */
/* @0x311566 .word 0xf7d44658 */
/* @0x31156a .word 0x2100fcde */
/* @0x31156e qadd16mi r9, r8, r6 */
/* @0x311572 .word 0xf998f7d5 */
/* @0x311576 andsls r4, r11, r4, lsl #12 */
/* @0x31157a .word 0xf0412800 */
/* @0x31157e cdpls p0, #0x0, c8, c12, c12, #0x5 */
/* @0x311582 .word 0xf8cd463b */
/* @0x311586 strtmi r8, [r8], -r0 */
/* @0x31158a bls 0x562ed6 <g_SWFlineaavertbuff+0xfe0e> */
/* @0x31158e .word 0x47b06876 */
/* @0x311592 andsls r4, r11, r3, lsl #12 */
/* @0x311596 mrsle r2, spsr */
/* @0x31159a ldrsbhs pc, [r4], r10 */
/* @0x31159e addmi r4, r10, #160, #18 */
/* @0x3115a2 movwhs sp, #0x2002 */
/* @0x3115a6 stcllt p0, c15, [r7, #0]! */
/* @0x3115aa cdphs p14, #0x0, c9, c0, c9, #0x0 */
/* @0x3115ae addshi pc, r5, r1, asr #5 */
/* @0x3115b2 andmi pc, r4, #14286848 */
/* @0x3115b6 ldmibmi r10, {r4, r6, r9, r10, lr} */
/* @0x3115ba strmi r4, [r0, r10, lsr #12]! */
/* @0x3115be ldmdblt r0!, {r0, r1, r3, r4, r12, pc} ^ */
/* @0x3115c2 strtmi r9, [r8], -r12, lsl #28 */
/* @0x3115c6 andhi pc, r0, sp, asr #17 */
/* @0x3115ca bls 0x562f16 <g_SWFlineaavertbuff+0xfe4e> */
/* @0x3115ce ldmvs r4!, {r0, r1, r3, r4, r5, r9, r10, lr} */
/* @0x3115d2 andsls r4, r11, r0, lsr #15 */
/* @0x3115d6 .word 0xf0412800 */
/* @0x3115da andls r8, r7, lr, ror r0 */
/* @0x3115de cdpls p0, #0x0, c14, c12, c10, #0x0 */
/* @0x3115e2 qsaxmi r4, r9, r0 */
/* @0x3115e6 .word 0x47986a33 */
/* @0x3115ea stmdahs r0, {r0, r1, r3, r4, r12, pc} */
/* @0x3115ee rsbshi pc, r3, r1, asr #32 */
/* @0x3115f2 strls r2, [r7], -r1, lsl #12 */
/* @0x3115f6 andmi pc, r4, #14286848 */
/* @0x3115fa stmibmi r10, {r4, r6, r9, r10, lr} */
/* @0x3115fe movwhs r4, #0x62a */
/* @0x311602 andsls r4, r11, r0, lsr #15 */
/* @0x311606 movwhs r11, #0x1920 */
/* @0x31160a adcslo pc, r4, #9043968 */
/* @0x31160e mul r1, r9, r6 */
/* @0x311612 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x311616 stmhs lr, {r6, r7, r9, r12, sp, pc} */
/* @0x31161a .word 0xf8dad107 */
/* @0x31161e ldrbmi r4, [r0], -r4, lsl #4 */
/* @0x311622 strtmi r4, [r10], -r2, lsl #19 */
/* @0x311626 strmi r2, [r0, r0, lsl #6]! */
/* @0x31162a blls 0x9f569e <b2_toiTime+0x29c1fa> */
/* @0x31162e .word 0xf0412b00 */
/* @0x311632 .word 0x26018052 */
/* @0x311636 and r9, r11, r1, lsl r6 */
/* @0x31163a strtmi r4, [r1], -r8, lsr #12 */
/* @0x31163e rfedb r2! */
/* @0x311642 stmdahs r0, {r0, r1, r3, r4, r12, pc} */
/* @0x311646 subhi pc, r7, r1, asr #32 */
/* @0x31164a strhs r4, [r1], -r1, lsl #13 */
/* @0x31164e .word 0x96079011 */
/* @0x311652 .word 0x6064f8da */
/* @0x311656 teqmi r8, r0, asr #12 */
/* @0x31165a shadd16mi r10, r0, r11 */
/* @0x31165e .word 0xf7d5960d */
/* @0x311662 svcls #0x1bfd61 */
/* @0x311666 svchs #0x4604 */
/* @0x31166a eorshi pc, r5, r1, asr #32 */
/* @0x31166e adceq pc, r0, #13238272 */
/* @0x311672 stmibvs lr!, {r0, r3, r4, r5, r9, r10, lr} ^ */
/* @0x311676 eorsmi pc, r8, #64, #12 */
/* @0x31167a mrcge p6, #0x0, r9, c14, c3, #0x0 */
/* @0x31167e svc #0x98f5a4 */
/* @0x311682 eorhs r4, r4, #59768832 */
/* @0x311686 .word 0x960e4630 */
/* @0x31168a svc #0x92f5a4 */
/* @0x31168e .word 0xf7d54628 */
/* @0x311692 mrcls p9, #0x0, apsr_nzcv, c3, c6, #0x2 */
/* @0x311696 strtmi r4, [r2], -r9, ror #18 */
/* @0x31169a andlt pc, r0, r4, asr #17 */
/* @0x31169e rsbvs r4, r5, r9, ror r4 */
/* @0x3116a2 .word 0xf50160a6 */
/* @0x3116a6 .word 0xf884710a */
/* @0x3116aa andls r9, r10, r0, lsr #32 */
/* @0x3116ae strtmi r6, [r8], -r0, ror #1 */
/* @0x3116b2 .word 0xfc0ff7d6 */
/* @0x3116b6 stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x3116ba ldrhi pc, [r8, #-0x40]! */
/* @0x3116be svceq #0xf1b9 */
/* @0x3116c2 cdpvc p0, #0x2, c13, c3, c14, #0x0 */
/* @0x3116c6 cmple r5, r2, lsl #22 */
/* @0x3116ca blhs 0x43115e <g_RomDisk+0x3993e> */
/* @0x3116ce qsaxmi sp, r8, r2 */
/* @0x3116d2 .word 0xf7d5a91c */
/* @0x3116d6 blls 0xa4ff36 <b2_toiTime+0x2f6a92> */
/* @0x3116da orrslt r6, r3, r0, ror #3 */
/* @0x3116de stclt p0, c15, [r6, #-0]! */
/* @0x3116e2 ldmdbge r12, {r3, r5, r9, r10, lr} */
/* @0x3116e6 .word 0xf9e8f7d5 */
/* @0x3116ea blhs 0x338362 */
/* @0x3116ee ldrhi pc, [lr, #-0x40] */
/* @0x3116f2 blhs 0x370f86 <_ZTS13C_UTF16String+0x8032> */
/* @0x3116f6 mcrvc p1, #0x5, sp, c3, c14, #0x1 */
/* @0x3116fa ldmdble r11!, {r0, r1, r8, r9, r11, sp} */
/* @0x3116fe stmdahs r4, {r6, r7, r9, r12, sp, pc} */
/* @0x311702 mcrvc p8, #0x5, sp, c1, c8, #0x1 */
/* @0x311706 cdpls p6, #0x0, c4, c10, c8, #0x1 */
/* @0x31170a .word 0xf7d54431 */
/* @0x31170e strmi pc, [r1], -r11, asr #17 */
/* @0x311712 bllt 0x193578a <b2_toiTime+0x11dc2e6> */
/* @0x311716 svceq #0xf1b9 */
/* @0x31171a eorhs sp, r4, #31 */
/* @0x31171e addsvs pc, r11, r4, lsl #10 */
/* @0x311722 svc #0x46f5a4 */
/* @0x311726 .word 0xf7d54628 */
/* @0x31172a stmibvs r1!, {r1, r3, r8, r11, r12, sp, lr, pc} ^ */
/* @0x31172e ldrbtne pc, [r0], #2244 */
/* @0x311732 strbteq pc, [r12], #2244 */
/* @0x311736 .word 0xf7d54628 */
/* @0x31173a ldrshls pc, [r12], -r10 */
/* @0x31173e .word 0xf0402800 */
/* @0x311742 andhs r8, r1, #-184549376 */
/* @0x311746 rsbeq pc, r12, r4, lsl #2 */
/* @0x31174a ldrmi r4, [r3], -r9, lsr #12 */
/* @0x31174e .word 0xfc17f7fd */
/* @0x311752 stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x311756 .word 0xf000d04f */
/* @0x31175a .word 0xf104bce9 */
/* @0x31175e strtmi r0, [r9], -r4, lsr #32 */
/* @0x311762 strbmi r4, [r11], -r10, asr #12 */
/* @0x311766 .word 0xfc0bf7fd */
/* @0x31176a .word 0xb128901c */
/* @0x31176e cdphs p14, #0x0, c9, c0, c7, #0x0 */
/* @0x311772 ldrbhi pc, [r12], #0 */
/* @0x311776 rsbs r2, pc, #134217728 */
/* @0x31177a blhs 0x36c40e <_ZTS13C_UTF16String+0x34ba> */
/* @0x31177e blvs 0xffbc7ba6 <b2_toiTime+0xffffffffff46e702> */
/* @0x311782 andle r4, r5, #-1610612727 */
/* @0x311786 cdphs p14, #0x0, c9, c0, c7, #0x0 */
/* @0x31178a movwhs r11, #0x3f0c */
/* @0x31178e rsbs r2, r3, #134217728 */
/* @0x311792 .word 0xf5042200 */
/* @0x311796 sadd8mi r6, r3, r11 */
/* @0x31179a .word 0xf7fd4629 */
/* @0x31179e .word 0x4603fbf0 */
/* @0x3117a2 stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x3117a6 strbhi pc, [r2], #64 */
/* @0x3117aa qadd16mi r10, r9, lr */
/* @0x3117ae .word 0xf7fd2201 */
/* @0x3117b2 strmi pc, [r3], -r6, ror #23 */
/* @0x3117b6 stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x3117ba ldrthi pc, [r8], #64 */
/* @0x3117be rsbeq pc, r12, r4, lsl #2 */
/* @0x3117c2 andhs r4, r1, #42991616 */
/* @0x3117c6 blx 0xffa0f7c4 <b2_toiTime+0xffffffffff2b6320> */
/* @0x3117ca stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x3117ce strthi pc, [lr], #64 */
/* @0x3117d2 .word 0xf504a81e */
/* @0x3117d6 vrhadd.s8 d6, d20, d26 */
/* @0x3117da .word 0xf5045254 */
/* @0x3117de .word 0xf7fd63ab */
/* @0x3117e2 ldrshls pc, [r12], -sp */
/* @0x3117e6 .word 0xf0402800 */
/* @0x3117ea blvs 0xbb2a76 <b2_toiTime+0x4595d2> */
/* @0x3117ee strbtlo pc, [r4], #2260 */
/* @0x3117f2 vqsub.s8 d4, d16, d10 */
/* @0x3117f6 blls 0xb720fe <b2_toiTime+0x418c5a> */
/* @0x3117fa .word 0xf8c49e07 */
/* @0x3117fe blvs 0xbded36 <b2_toiTime+0x485892> */
/* @0x311802 cdpls p1, #0x0, c11, c9, c14, #0x7 */
/* @0x311806 .word 0x9610b2b6 */
/* @0x31180a cdphs p14, #0x0, c9, c0, c9, #0x0 */
/* @0x31180e cdpls p13, #0x1, c13, c0, c4, #0x0 */
/* @0x311812 movwle r4, #0x129e */
/* @0x311816 eor r2, pc, #402653184 */
/* @0x31181a .word 0x61236b23 */
/* @0x31181e strbpl lr, [pc], #-20 */
/* @0x311822 qdsubvs r4, r4, r4 */
/* @0x311826 ldrtmi r6, [r2], -r5, ror #16 */
/* @0x31182a strtmi r4, [r0], -r6, asr #6 */
/* @0x31182e ldrbtle r4, [r3], -r6, asr #6 */
/* @0x311832 cmple pc, #7 */
/* @0x311836 ldrtle r0, [r4], -r7 */
/* @0x31183a cmnhs r10, r7 */
/* @0x31183e blhs 0x35186a */
/* @0x311842 andshi pc, r9, #0, #4 */
/* @0x311846 ldrls r9, [r0], -r7, lsl #28 */
/* @0x31184a cdphs p14, #0x0, c9, c0, c9, #0x0 */
/* @0x31184e strbthi pc, [lr], #-704 */
/* @0x311852 .word 0xf1b99e0a */
/* @0x311856 svclt #0xc0f00 */
/* @0x31185a orrpl pc, r0, #1325400064 */
/* @0x31185e movtpl pc, #0x44f */
/* @0x311862 vshl.s8 d9, d2, d4 */
/* @0x311866 movwls r5, #0x105c */
/* @0x31186a orrsvs pc, r11, r4, lsl #10 */
/* @0x31186e strtmi r9, [r11], -r0, lsl #12 */
/* @0x311872 andge pc, r12, sp, asr #17 */
/* @0x311876 .word 0xf7ff9a10 */
/* @0x31187a andsls pc, r12, lr, lsr sp */
/* @0x31187e .word 0xf0402800 */
/* @0x311882 .word 0xf8d48455 */
/* @0x311886 strtmi r1, [r8], -r12, asr #11 */
/* @0x31188a .word 0xf7d54431 */
/* @0x31188e strmi pc, [r2], -r11, lsl #16 */
/* @0x311892 stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x311896 strbhi pc, [r10], #-64 */
/* @0x31189a adcsmi pc, r4, r4, lsl #4 */
/* @0x31189e strbmi r4, [r11], -r9, lsr #12 */
/* @0x3118a2 blx 0x1e8f8a0 <b2_toiTime+0x17363fc> */
/* @0x3118a6 stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x3118aa strbhi pc, [r0], #-64 */
/* @0x3118ae strbhs pc, [r0, #0x8d4]! */
/* @0x3118b2 .word 0x73fff64f */
/* @0x3118b6 swple r4, r10, [r3] */
/* @0x3118ba svceq #0xf1b9 */
/* @0x3118be bicshi pc, r6, r0 */
/* @0x3118c2 strtmi pc, [r4], -r4, lsl #12 */
/* @0x3118c6 stmibvs lr!, {r0, r1, r2, r4, r9, r10, r12, pc} ^ */
/* @0x3118ca .word 0x1610f8d4 */
/* @0x3118ce strhs r9, [r3], -r8, lsl #12 */
/* @0x3118d2 stmdbhs r0, {r0, r1, r2, r5, r9, r10, r12, pc} */
/* @0x3118d6 tsthi sp, r0 */
/* @0x3118da strtmi r9, [r8], -r10, lsl #20 */
/* @0x3118de .word 0xf7d44411 */
/* @0x3118e2 eorls pc, r7, r1, ror #31 */
/* @0x3118e6 .word 0x2600b110 */
/* @0x3118ea tst r5, r11, lsl #12 */
/* @0x3118ee .word 0x21024628 */
/* @0x3118f2 .word 0xf81df7d5 */
/* @0x3118f6 stmdahs r0, {r0, r1, r2, r5, r12, pc} */
/* @0x3118fa qsub8mi sp, r8, r5 */
/* @0x3118fe bleq 0xfea4dd3a <b2_toiTime+0xfffffffffe2f4896> */
/* @0x311902 .word 0xf81df7d5 */
/* @0x311906 andsls r4, r4, r9, asr r6 */
/* @0x31190a .word 0xf7d54628 */
/* @0x31190e blls 0xd0fcfe <b2_toiTime+0x5b685a> */
/* @0x311912 mvnle r2, r0, lsl #22 */
/* @0x311916 andle r2, r2, r1, lsl #16 */
/* @0x31191a movwls r9, #0xb627 */
/* @0x31191e qsub8mi lr, r8, r12 */
/* @0x311922 .word 0xf7d54659 */
/* @0x311926 blls 0xd10266 <b2_toiTime+0x5b6dc2> */
/* @0x31192a blhs 0x32314a */
/* @0x31192e .word 0x4628d1db */
/* @0x311932 .word 0xf7d54659 */
/* @0x311936 .word 0xf8c4f8e6 */
/* @0x31193a strmi r0, [r3], -r4, lsr #24 */
/* @0x31193e bhs 0x3381e2 */
/* @0x311942 stm sp, {r0, r4, r6, r7, r8, r12, lr, pc} */
/* @0x311946 .word 0x21040804 */
/* @0x31194a .word 0xf7d69808 */
/* @0x31194e svcls #0x27fb9f */
/* @0x311952 svchs #0x900b */
/* @0x311956 rschi pc, r0, r0, asr #32 */
/* @0x31195a stclo p8, c15, [r4], #-848 */
/* @0x31195e addsmi r4, pc, #40, #12 */
/* @0x311962 ldrbmi sp, [r9], -r11, lsl #4 */
/* @0x311966 blx 0xe8f8c2 <b2_toiTime+0x73641e> */
/* @0x31196a .word 0xf841990b */
/* @0x31196e blls 0xcd1a12 <b2_toiTime+0x57856e> */
/* @0x311972 .word 0xf0402b00 */
/* @0x311976 .word 0x370180d1 */
/* @0x31197a ldmdbls r4, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x31197e .word 0xf7d44431 */
/* @0x311982 mlals r7, r1, pc, pc */
/* @0x311986 .word 0xf0402800 */
/* @0x31198a strtmi r8, [r8], -r7, asr #1 */
/* @0x31198e .word 0xf7d54659 */
/* @0x311992 .word 0xf8a4f8b8 */
/* @0x311996 blls 0xcd4a4e <b2_toiTime+0x57b5aa> */
/* @0x31199a .word 0xf0402b00 */
/* @0x31199e .word 0x462880bd */
/* @0x3119a2 .word 0xf7d54659 */
/* @0x3119a6 .word 0xf8c4f8ae */
/* @0x3119aa .word 0x46030c30 */
/* @0x3119ae bhs 0x338252 */
/* @0x3119b2 adcshi pc, r2, r0, asr #32 */
/* @0x3119b6 stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc} */
/* @0x3119ba stmdals r8, {r2, r8, sp} */
/* @0x3119be blx 0x1ccf920 <b2_toiTime+0x157647c> */
/* @0x3119c2 ldceq p8, c15, [r4], #-784 */
/* @0x3119c6 cdphs p14, #0x0, c9, c0, c7, #0x1 */
/* @0x3119ca adchi pc, r6, r0, asr #32 */
/* @0x3119ce ldclo p8, c15, [r0], #-848 */
/* @0x3119d2 suble r4, sp, #-536870903 */
/* @0x3119d6 ldcvc p8, c15, [r4], #-848 */
/* @0x3119da rfeia r4! */
/* @0x3119de bl 0x4e0a96 <SrcVerts+0x3dada> */
/* @0x3119e2 stm sp, {r1, r2, r7, r9} */
/* @0x3119e6 andsls r0, r8, #131072 */
/* @0x3119ea stmdals r8, {r2, r3, r8, sp} */
/* @0x3119ee .word 0xf7d62200 */
/* @0x3119f2 .word 0xf847fb4d */
/* @0x3119f6 svcls #0x270026 */
/* @0x3119fa .word 0xf0402f00 */
/* @0x3119fe rfeia r4! */
/* @0x311a02 addsmi r3, pc, #44, #24 */
/* @0x311a06 blls 0x9462d6 <b2_toiTime+0x1ece32> */
/* @0x311a0a blx 0x39a244 <ft_adobe_glyph_list+0x9920> */
/* @0x311a0e strtmi pc, [r8], -r7, lsl #16 */
/* @0x311a12 uadd16mi r6, r9, r11 */
/* @0x311a16 strbmi r9, [r3], #-789 */
/* @0x311a1a .word 0xf7d5930f */
/* @0x311a1e blls 0xd0fbee <b2_toiTime+0x5b674a> */
/* @0x311a22 andsls r11, r9, r0, lsl #5 */
/* @0x311a26 cmnle r7, r0, lsl #22 */
/* @0x311a2a ldrbmi r4, [r9], -r8, lsr #12 */
/* @0x311a2e .word 0xf869f7d5 */
/* @0x311a32 addlt r9, r2, #39936 */
/* @0x311a36 .word 0xd16f2b00 */
/* @0x311a3a ldrbmi r4, [r9], -r8, lsr #12 */
/* @0x311a3e .word 0xf7d59205 */
/* @0x311a42 blls 0xd0fbca <b2_toiTime+0x5b6726> */
/* @0x311a46 addlt r9, r0, #20480 */
/* @0x311a4a .word 0xd1652b00 */
/* @0x311a4e andslt r9, r2, #409600 */
/* @0x311a52 addseq r3, r2, r1, lsl #14 */
/* @0x311a56 ldmdbls r5, {r0, r1, r3, r9, r12, sp, pc} */
/* @0x311a5a .word 0xf841009b */
/* @0x311a5e blls 0x6dda86 <g_SWFvertbuff+0xa9be> */
/* @0x311a62 andlt r6, r3, #90 */
/* @0x311a66 addseq r9, r11, pc, lsl #20 */
/* @0x311a6a bfi r6, r3, #1, #8 */
/* @0x311a6e str r3, [sp, r1, lsl #12]! */
/* @0x311a72 stmdals r8, {r9, sp} */
/* @0x311a76 stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc} */
/* @0x311a7a .word 0xf8d42108 */
/* @0x311a7e .word 0xf7d63c24 */
/* @0x311a82 .word 0xf8c4fb05 */
/* @0x311a86 cdpls p12, #0x2, c0, c7, c8, #0x1 */
/* @0x311a8a .word 0xd1452e00 */
/* @0x311a8e stclo p8, c15, [r4], #-848 */
/* @0x311a92 eorsle r4, pc, #-536870903 */
/* @0x311a96 stclo p8, c15, [r8], #-848 */
/* @0x311a9a bls 0x5e3342 <g_SWFaavertbuff+0x1027a> */
/* @0x311a9e stmeq r6, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^ */
/* @0x311aa2 ldrmi r9, [pc], -pc, lsl #6 */
/* @0x311aa6 eorne pc, r6, r2, asr r8 */
/* @0x311aaa blls 0x822bce <b2_toiTime+0xc972a> */
/* @0x311aae .word 0xf7d44419 */
/* @0x311ab2 .word 0x9027fef9 */
/* @0x311ab6 .word 0xd12f2800 */
/* @0x311aba .word 0x21044628 */
/* @0x311abe .word 0xff37f7d4 */
/* @0x311ac2 bllt 0x1535b66 <b2_toiTime+0xddc6c2> */
/* @0x311ac6 ldrbmi r4, [r9], -r8, lsr #12 */
/* @0x311aca .word 0xf81bf7d5 */
/* @0x311ace .word 0xf8429a0f */
/* @0x311ad2 strmi r0, [r3], -r8 */
/* @0x311ad6 ldmiblt r10!, {r0, r1, r2, r5, r9, r11, r12, pc} ^ */
/* @0x311ada stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc} */
/* @0x311ade stmdals r8, {r2, r8, sp} */
/* @0x311ae2 blx 0xff84fa42 <b2_toiTime+0xffffffffff0f659e> */
/* @0x311ae6 blls 0xce9cce <b2_toiTime+0x59082a> */
/* @0x311aea .word 0x4698b9b3 */
/* @0x311aee ldrmi r6, [r8, #0x83b] */
/* @0x311af2 ldmdavs r11!, {r0, r2, r3, r9, r12, lr, pc} ^ */
/* @0x311af6 ldrbmi r4, [r9], -r8, lsr #12 */
/* @0x311afa .word 0xf7d59305 */
/* @0x311afe blls 0x48fb0e <SurfaceStack+0x362> */
/* @0x311b02 eoreq pc, r8, r3, asr #16 */
/* @0x311b06 ldmdblt r11!, {r0, r1, r2, r5, r8, r9, r11, r12, pc} */
/* @0x311b0a stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x311b0e strlo lr, [r1], -lr, ror #15 */
/* @0x311b12 strhls lr, [r11, -r12] */
/* @0x311b16 .word 0x93272300 */
/* @0x311b1a stmdbls r11, {r3, r11, r12, pc} */
/* @0x311b1e .word 0xfc0af7d5 */
/* @0x311b22 tstlt r11, r7, lsr #22 */
/* @0x311b26 stmdbls r8, {r0, r1, r2, r4, r11, r12, pc} */
/* @0x311b2a blx 0x30fb22 <af_shaper_get_elem+0x5390> */
/* @0x311b2e tstls r12, #39936 */
/* @0x311b32 .word 0xf0402b00 */
/* @0x311b36 .word 0xf8d482fb */
/* @0x311b3a strtmi r1, [r8], -r0, lsl #12 */
/* @0x311b3e ldrtmi r9, [r1], #-3594 */
/* @0x311b42 mrc2 p7, #0x5, apsr_nzcv, c0, c4, #0x6 */
/* @0x311b46 andsls r4, r12, r2, lsl #12 */
/* @0x311b4a .word 0xf0402800 */
/* @0x311b4e cdpge p2, #0x2, c8, c7, c15, #0x7 */
/* @0x311b52 strbmi r4, [r11], -r9, lsr #12 */
/* @0x311b56 .word 0xf7fd4630 */
/* @0x311b5a .word 0x4602fa12 */
/* @0x311b5e stmdahs r0, {r2, r3, r4, r12, pc} */
/* @0x311b62 rschi pc, r4, #64 */
/* @0x311b66 .word 0xf5b39b2a */
/* @0x311b6a ldmdale r9!, {r7, r8, r9, r10, r11, r12, sp, lr} ^ */
/* @0x311b6e strblo pc, [r8, r4, asr #17]! */
/* @0x311b72 andls r10, r0, r12, lsl r9 */
/* @0x311b76 vst4.8 {d25, d27, d29, d31}, [pc], r1 */
/* @0x311b7a ldmdals r3, {r0, r1, r5, r8, r12, sp, lr} */
/* @0x311b7e blx 0xfe4cfade <b2_toiTime+0xfffffffffdd7663a> */
/* @0x311b82 blhs 0x3387fa */
/* @0x311b86 bls 0xdc613e <b2_toiTime+0x66cc9a> */
/* @0x311b8a .word 0x7123f44f */
/* @0x311b8e mulle r7, r3, r2 */
/* @0x311b92 vmlaeq.f64 d15, d3, d1 */
/* @0x311b96 streq lr, [r3, r4, lsl #22] */
/* @0x311b9a .word 0xf8c73301 */
/* @0x311b9e ldrb lr, [r5, r12, ror #15]! */
/* @0x311ba2 blls 0xd9b7aa <b2_toiTime+0x642306> */
/* @0x311ba6 andsle r4, r7, #-268435447 */
/* @0x311baa bl 0x437fda <g_RomDisk+0x407ba> */
/* @0x311bae ldrtmi r0, [r10], -r7, lsl #7 */
/* @0x311bb2 ubfxeq pc, r3, #0x11, #0xd */
/* @0x311bb6 svceq #0xf1b9 */
/* @0x311bba .word 0xf44fbf0c */
/* @0x311bbe vst2.32 {d21, d22, d23, d24}, [pc], r0 */
/* @0x311bc2 stm sp, {r7, r8, r9, lr} */
/* @0x311bc6 shadd16mi r0, r1, r10 */
/* @0x311bca .word 0xf7ff462b */
/* @0x311bce mulsls r12, r4, r11 */
/* @0x311bd2 mrsle r2, spsr */
/* @0x311bd6 strb r3, [r4, r1, lsl #14]! */
/* @0x311bda svceq #0xf1b9 */
/* @0x311bde blhs 0x385bea <_ZTS13C_UTF16String+0x1cc96> */
/* @0x311be2 .word 0xf8d4d93e */
/* @0x311be6 strtmi r1, [r8], -r4, lsl #12 */
/* @0x311bea .word 0xf8d49a0a */
/* @0x311bee ldrmi r7, [r1], #-1216 */
/* @0x311bf2 mrc2 p7, #0x2, apsr_nzcv, c8, c4, #0x6 */
/* @0x311bf6 bllt 0xfe535c72 <b2_toiTime+0xfffffffffdddc7ce> */
/* @0x311bfa bleq 0x204e036 <b2_toiTime+0x18f4b92> */
/* @0x311bfe ldrbmi r4, [r9], -r8, lsr #12 */
/* @0x311c02 .word 0xff5af7d4 */
/* @0x311c06 blx 0x1af8882 <b2_toiTime+0x139f3de> */
/* @0x311c0a bllt 0x120fe12 <b2_toiTime+0xab696e> */
/* @0x311c0e blhi 0xffe4fe26 <b2_toiTime+0xffffffffff6f6982> */
/* @0x311c12 .word 0x3c00f8c4 */
/* @0x311c16 svceq #0xf1b8 */
/* @0x311c1a .word 0xf1b8d003 */
/* @0x311c1e andle r0, r3, r3, lsl #30 */
/* @0x311c22 .word 0xf8c4e01a */
/* @0x311c26 strd r7, r8, [lr], -r8 */
/* @0x311c2a ldrbmi r4, [r9], -r8, lsr #12 */
/* @0x311c2e .word 0xff69f7d4 */
/* @0x311c32 ldmiblt r11, {r0, r2, r3, r4, r8, r9, r11, r12, pc} */
/* @0x311c36 .word 0xf8cdb910 */
/* @0x311c3a and r8, pc, r4, ror r0 */
/* @0x311c3e .word 0xf000fb08 */
/* @0x311c42 .word 0xf8c43002 */
/* @0x311c46 qsub8mi r0, r8, r8 */
/* @0x311c4a blne 0x14ffa2 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x3a> */
/* @0x311c4e rscslo pc, r4, #4, #12 */
/* @0x311c52 .word 0xf926f7d6 */
/* @0x311c56 and r9, r1, sp, lsl r0 */
/* @0x311c5a tstls sp, #201326592 */
/* @0x311c5e tstls r12, #29696 */
/* @0x311c62 .word 0xf7fd4630 */
/* @0x311c66 blls 0xa4ff22 <b2_toiTime+0x2f6a7e> */
/* @0x311c6a subs r11, pc, #-1073741820 */
/* @0x311c6e strbls pc, [r8, r4, asr #17]! */
/* @0x311c72 strblo pc, [r12, #0x8d4] */
/* @0x311c76 movwhs r11, #0x3913 */
/* @0x311c7a subs r9, r7, #28, #6 */
/* @0x311c7e strblo pc, [r0], #2260 */
/* @0x311c82 .word 0xf1042200 */
/* @0x311c86 .word 0xf504006c */
/* @0x311c8a smultbvs r3, r9, r1 */
/* @0x311c8e .word 0xf7fc4613 */
/* @0x311c92 andsls pc, r12, r5, lsr #31 */
/* @0x311c96 .word 0xf0402800 */
/* @0x311c9a .word 0xf1b98249 */
/* @0x311c9e andle r0, r6, r0, lsl #30 */
/* @0x311ca2 ldmdbls r0, {r5, r9, r10, lr} */
/* @0x311ca6 ldc2 p7, c15, [r11, #1016]! */
/* @0x311caa strbeq pc, [r4, #-0x8c4] */
/* @0x311cae stmdbvs r6!, {r1, r2, r3, r4, r5, r9, sp, lr, pc} ^ */
/* @0x311cb2 rscsle r2, r5, r0, lsl #28 */
/* @0x311cb6 strblo pc, [r0, #0x8d4]! */
/* @0x311cba rscsvc pc, pc, #82837504 */
/* @0x311cbe vmla.i8 d9, d4, d7 */
/* @0x311cc2 stmibvs pc!, {r2, r3, r4, r7, r8, r9, r11, lr} ^ */
/* @0x311cc6 svclt #0x84293 */
/* @0x311cca sbclt r2, r11, #0, #2 */
/* @0x311cce strbne pc, [r4, #0x8d4] */
/* @0x311cd2 stmdbhs r2, {r0, r1, r3, r8, r9, r12, pc} */
/* @0x311cd6 addsls pc, r12, sp, asr #17 */
/* @0x311cda addhi pc, r9, r0, asr #4 */
/* @0x311cde strtmi r9, [r8], -r10, lsl #22 */
/* @0x311ce2 .word 0xf8c44419 */
/* @0x311ce6 .word 0xf7d414a0 */
/* @0x311cea .word 0x9027fddd */
/* @0x311cee .word 0xf0402800 */
/* @0x311cf2 .word 0xf10d80d3 */
/* @0x311cf6 qadd8mi r0, r8, r12 */
/* @0x311cfa .word 0xf7d44641 */
/* @0x311cfe sbclt pc, r0, #3536 */
/* @0x311d02 ldreq pc, [r12], #2244 */
/* @0x311d06 blhs 0x3389aa */
/* @0x311d0a sbchi pc, r6, r0, asr #32 */
/* @0x311d0e .word 0xf8cd4633 */
/* @0x311d12 .word 0xf8cd9000 */
/* @0x311d16 ldrtmi r8, [r8], -r4 */
/* @0x311d1a strbmi r2, [r10], -r2, lsl #2 */
/* @0x311d1e rfeib r6! */
/* @0x311d22 strteq pc, [r4], #2244 */
/* @0x311d26 blhs 0x3389ca */
/* @0x311d2a adcshi pc, r6, r0, asr #32 */
/* @0x311d2e andls pc, r0, r0, lsr #17 */
/* @0x311d32 ldrlo pc, [r12], #2260 */
/* @0x311d36 blhs 0x3be1ca <error_g0017+0x16e6e> */
/* @0x311d3a .word 0xf04fd861 */
/* @0x311d3e sub r0, r7, r1, lsl #18 */
/* @0x311d42 .word 0x4100f106 */
/* @0x311d46 stmdblo r1, {r3, r5, r9, r10, lr} */
/* @0x311d4a .word 0xf7d60049 */
/* @0x311d4e eorls pc, r7, r9, ror #16 */
/* @0x311d52 .word 0xf0402800 */
/* @0x311d56 .word 0xf04f80a1 */
/* @0x311d5a ldrmi r0, [r0, #0x801]! */
/* @0x311d5e strtmi sp, [r8], -r9 */
/* @0x311d62 strtls pc, [r4], #2260 */
/* @0x311d66 mcr2 p7, #0x2, pc, c4, c4, #0x6 */
/* @0x311d6a andseq pc, r8, r9, lsr #16 */
/* @0x311d6e stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x311d72 qsub8mi lr, r8, r3 */
/* @0x311d76 .word 0xf89ff7d6 */
/* @0x311d7a strtmi lr, [r8], -r6, lsl #1 */
/* @0x311d7e .word 0xf7d44641 */
/* @0x311d82 blls 0xd1188a <b2_toiTime+0x5b83e6> */
/* @0x311d86 blhs 0x335dae */
/* @0x311d8a addhi pc, r6, r0, asr #32 */
/* @0x311d8e ldrlo pc, [r12], #2260 */
/* @0x311d92 strbmi r4, [r1], -r8, lsr #12 */
/* @0x311d96 tstle lr, r2, lsl #22 */
/* @0x311d9a mrc2 p7, #0x5, apsr_nzcv, c3, c4, #0x6 */
/* @0x311d9e blhs 0x338a42 */
/* @0x311da2 .word 0xf5c0d17a */
/* @0x311da6 bls 0x522baa <SrcVerts+0x7fbee> */
/* @0x311daa bl 0xff55edae <b2_toiTime+0xfffffffffee0590a> */
/* @0x311dae addsmi r0, r3, #6, #28 */
/* @0x311db2 movweq pc, #0x4f */
/* @0x311db6 .word 0xf5c2bf3c */
/* @0x311dba rscslo r4, pc, pc, ror r0 */
/* @0x311dbe .word 0xc020f8dd */
/* @0x311dc2 bl 0x3e3396 <error_g0017+0x3c03a> */
/* @0x311dc6 ldrmi r0, [r12], #265 */
/* @0x311dca stc2 p10, c15, [r12], {31} */
/* @0x311dce strmi sp, [r9], r7, lsl #2 */
/* @0x311dd2 bicsle r4, r2, #742391808 */
/* @0x311dd6 .word 0xf7d4e058 */
/* @0x311dda sbclt pc, r0, #1776 */
/* @0x311dde addmi lr, r3, #58195968 */
/* @0x311de2 .word 0xf8d4d8f5 */
/* @0x311de6 movwlo r2, #0x14a4 */
/* @0x311dea andsgt pc, r1, r2, lsr #16 */
/* @0x311dee stmdbhs r1, {r1, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x311df2 strtne pc, [r0], #2244 */
/* @0x311df6 stmdbhs r2, {r0, r1, r3, r4, r12, lr, pc} */
/* @0x311dfa cdphs p0, #0xe, c13, c5, c15, #0x1 */
/* @0x311dfe movwhs sp, #0x3902 */
/* @0x311e02 sub r9, r9, r7, lsr #6 */
/* @0x311e06 .word 0xf8cdab27 */
/* @0x311e0a movwls r9, #0x1000 */
/* @0x311e0e shasxmi r4, r3, r8 */
/* @0x311e12 strbmi r2, [r10], -r2, lsl #2 */
/* @0x311e16 rfedb r10! */
/* @0x311e1a strteq pc, [r4], #2244 */
/* @0x311e1e blhs 0x338ac2 */
/* @0x311e22 .word 0xf8dfd13a */
/* @0x311e26 ldrbtmi r1, [r9], #-2276 */
/* @0x311e2a mrsvc pc, apsr */
/* @0x311e2e cdphs p0, #0xa, c14, c6, c9, #0x1 */
/* @0x311e32 blge 0xd081ce <b2_toiTime+0x5aed2a> */
/* @0x311e36 andls pc, r0, sp, asr #17 */
/* @0x311e3a ldrtmi r9, [r8], -r1, lsl #6 */
/* @0x311e3e .word 0x21024633 */
/* @0x311e42 .word 0xf7d6464a */
/* @0x311e46 .word 0xf8c4f923 */
/* @0x311e4a blls 0xcd30e2 <b2_toiTime+0x579c3e> */
/* @0x311e4e .word 0xf8dfbb23 */
/* @0x311e52 ldrbtmi r1, [r9], #-2248 */
/* @0x311e56 .word 0x4106f201 */
/* @0x311e5a mrchs p0, #0x2, lr, c7, c3, #0x0 */
/* @0x311e5e blge 0xd081a2 <b2_toiTime+0x5aecfe> */
/* @0x311e62 andls pc, r0, sp, asr #17 */
/* @0x311e66 ldrtmi r9, [r8], -r1, lsl #6 */
/* @0x311e6a .word 0x464a4633 */
/* @0x311e6e .word 0xf90ef7d6 */
/* @0x311e72 strteq pc, [r4], #2244 */
/* @0x311e76 ldmdblt r11!, {r0, r1, r2, r5, r8, r9, r11, r12, pc} ^ */
/* @0x311e7a stmne r4!, {r0, r1, r2, r3, r4, r6, r7, r11, r12, sp, lr, pc} */
/* @0x311e7e .word 0xf2014479 */
/* @0x311e82 rsbseq r5, r2, r2, asr r1 */
/* @0x311e86 bl 0xfe9cf51e <b2_toiTime+0xfffffffffe27607a> */
/* @0x311e8a .word 0xb12b9b0b */
/* @0x311e8e shsaxmi r4, r1, r8 */
/* @0x311e92 .word 0xf5a7463a */
/* @0x311e96 eorls pc, r7, r6, ror #20 */
/* @0x311e9a .word 0xb1a39b27 */
/* @0x311e9e .word 0xf8d44638 */
/* @0x311ea2 strhs r1, [r0], -r4, lsr #9 */
/* @0x311ea6 blx 0x14cfe02 <b2_toiTime+0xd7695e> */
/* @0x311eaa strtvs pc, [r4], #2244 */
/* @0x311eae .word 0xf8d44638 */
/* @0x311eb2 .word 0xf7d514a8 */
/* @0x311eb6 .word 0xf8c4fa3f */
/* @0x311eba .word 0xf8c464a8 */
/* @0x311ebe .word 0xf8c4649c */
/* @0x311ec2 .word 0xf8c464a0 */
/* @0x311ec6 bls 0xceb15e <b2_toiTime+0x591cba> */
/* @0x311eca bhs 0x336742 */
/* @0x311ece .word 0x812ef040 */
/* @0x311ed2 strblo pc, [r0, #0x8d4]! */
/* @0x311ed6 ldrbtvc pc, [pc], pc, asr #12 */
/* @0x311eda .word 0xf47f42b3 */
/* @0x311ede .word 0xf8d4aee1 */
/* @0x311ee2 .word 0xf8d434a4 */
/* @0x311ee6 .word 0xf8d49014 */
/* @0x311eea blhs 0x317612 <ft_lzwstate_io+0x65e> */
/* @0x311eee adchi pc, sp, r0 */
/* @0x311ef2 .word 0xf1044610 */
/* @0x311ef6 movwls r0, #0x8390 */
/* @0x311efa ldrmi r9, [r3], #-2824 */
/* @0x311efe .word 0xf5b23202 */
/* @0x311f02 orrshi r7, r8, r0, lsl #30 */
/* @0x311f06 andeq pc, r12, #10682368 */
/* @0x311f0a stmdbhs r1, {r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x311f0e sbcshi pc, r3, r0, asr #4 */
/* @0x311f12 strtmi r9, [r8], -r10, lsl #28 */
/* @0x311f16 .word 0xf8c44431 */
/* @0x311f1a .word 0xf7d41094 */
/* @0x311f1e eorls pc, r7, r3, asr #25 */
/* @0x311f22 .word 0xf0402800 */
/* @0x311f26 mcrge p0, #0x1, r8, c7, c14, #0x7 */
/* @0x311f2a ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x311f2e stc2l p7, c15, [r4, #848] */
/* @0x311f32 .word 0xf8c4b2c0 */
/* @0x311f36 blls 0xcd217e <b2_toiTime+0x578cda> */
/* @0x311f3a .word 0xf0402b00 */
/* @0x311f3e qsub8mi r8, r8, r2 */
/* @0x311f42 .word 0xf7d44631 */
/* @0x311f46 bls 0xd11632 <b2_toiTime+0x5b818e> */
/* @0x311f4a bhs 0x33ea6e */
/* @0x311f4e rschi pc, r9, r0, asr #32 */
/* @0x311f52 ldrsblo pc, [r0], r4 */
/* @0x311f56 ldmdaeq pc!, {r0, r1, r4, r12, sp, lr, pc} ^ */
/* @0x311f5a .word 0xf1b8d006 */
/* @0x311f5e cmnle r4, r1, lsl #30 */
/* @0x311f62 addshs pc, r8, r4, asr #17 */
/* @0x311f66 .word 0xe0524694 */
/* @0x311f6a qsub16mi r1, r8, r11 */
/* @0x311f6e addslo pc, r8, r4, asr #17 */
/* @0x311f72 .word 0xf7d54639 */
/* @0x311f76 eorls pc, r7, r5, asr pc */
/* @0x311f7a .word 0xf0402800 */
/* @0x311f7e bvs 0xd322ce <b2_toiTime+0x5d8e2a> */
/* @0x311f82 adcsmi r2, r11, #67108864 */
/* @0x311f86 stmne r2, {r4, r11, r12, lr, pc} ^ */
/* @0x311f8a .word 0xf812454b */
/* @0x311f8e andle r2, r9, #256 */
/* @0x311f92 subeq lr, r2, #4, #22 */
/* @0x311f96 addslo pc, r12, #10616832 */
/* @0x311f9a strtne pc, [r4], #2260 */
/* @0x311f9e andsne pc, r3, r1, lsr r8 */
/* @0x311fa2 addsne pc, r12, r2, lsr #17 */
/* @0x311fa6 strb r3, [r12, r1, lsl #6]! */
/* @0x311faa .word 0xf7d54628 */
/* @0x311fae sub pc, pc, r4, lsl #31 */
/* @0x311fb2 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x311fb6 andsgt pc, r4, sp, asr #17 */
/* @0x311fba ldc2l p7, c15, [lr, #-848]! */
/* @0x311fbe blx 0x1af8c62 <b2_toiTime+0x139f7be> */
/* @0x311fc2 blhs 0x350dca */
/* @0x311fc6 adchi pc, sp, r0, asr #32 */
/* @0x311fca ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x311fce ldc2l p7, c15, [r4, #-848]! */
/* @0x311fd2 .word 0xf8dd9a27 */
/* @0x311fd6 sbclt r12, r0, #20 */
/* @0x311fda .word 0xf0402a00 */
/* @0x311fde .word 0xf06f80a2 */
/* @0x311fe2 .word 0xf8d44100 */
/* @0x311fe6 blx 0x35e250 <_ZTS12CDS_Priority+0x2a8> */
/* @0x311fea andlo r11, r1, r8, lsl #28 */
/* @0x311fee blls 0x522a56 <SrcVerts+0x7fa9a> */
/* @0x311ff2 subeq lr, r8, #323584 */
/* @0x311ff6 .word 0xf8c4bf88 */
/* @0x311ffa bl 0x3d2262 <error_g0017+0x2af06> */
/* @0x311ffe strbmi r0, [r3], -lr, asr #28 */
/* @0x312002 bl 0xff3e320a <b2_toiTime+0xfffffffffec89d66> */
/* @0x312006 strbmi r0, [r3, #-0xb0b] */
/* @0x31200a .word 0xf10cd304 */
/* @0x31200e ldrmi r0, [r12, #0xc01]! */
/* @0x312012 ands sp, r0, lr, asr #7 */
/* @0x312016 andle r4, r11, #314572800 */
/* @0x31201a .word 0x0103eb0b */
/* @0x31201e stmdale r7, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r11, sp} */
/* @0x312022 andeq lr, r2, lr, lsl #22 */
/* @0x312026 andlo pc, r12, #160, #16 */
/* @0x31202a strtne pc, [r4], #2260 */
/* @0x31202e orrhi r5, r1, r9, lsl #21 */
/* @0x312032 andlo r3, r2, #67108864 */
/* @0x312036 .word 0xf8d4e7e7 */
/* @0x31203a .word 0xf5b33098 */
/* @0x31203e stmdble r7, {r7, r8, r9, r10, r11, r12, sp, lr} */
/* @0x312042 orrvc pc, r0, #1325400064 */
/* @0x312046 addslo pc, r8, r4, asr #17 */
/* @0x31204a movwhs lr, #0x3002 */
/* @0x31204e rsb r9, r8, r7, lsr #6 */
/* @0x312052 ldrsblo pc, [r0], r4 */
/* @0x312056 strble r0, [r4, #-0x619]! */
/* @0x31205a ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x31205e stc2 p7, c15, [r12, #-848]! */
/* @0x312062 sbclt r9, r7, #39936 */
/* @0x312066 cmple r12, r0, lsl #22 */
/* @0x31206a ldrmi r4, [r8, #0x698]! */
/* @0x31206e qsaxmi sp, r8, r9 */
/* @0x312072 .word 0xf7d44631 */
/* @0x312076 blls 0xd11502 <b2_toiTime+0x5b805e> */
/* @0x31207a blx 0xfe350a00 <b2_toiTime+0xfffffffffdbf755c> */
/* @0x31207e cmple r0, r0, lsl #22 */
/* @0x312082 ldrtmi r4, [r1], -r8, lsr #12 */
/* @0x312086 ldc2 p7, c15, [sp, #-848]! */
/* @0x31208a blhs 0x338d2e */
/* @0x31208e bl 0x4465ba <g_RomDisk+0x4ed9a> */
/* @0x312092 .word 0xf8a2024b */
/* @0x312096 strbmi r0, [r11, #-0x9c] */
/* @0x31209a .word 0xf8d4d00a */
/* @0x31209e rfeda r1! */
/* @0x3120a2 addmi r1, r1, #19 */
/* @0x3120a6 .word 0xf8a2d102 */
/* @0x3120aa mul r1, r12, r2 */
/* @0x3120ae ldrb r3, [r2, r1, lsl #6]! */
/* @0x3120b2 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x3120b6 .word 0xf104e7d9 */
/* @0x3120ba mulle r4, r12, r0 */
/* @0x3120be .word 0x1664f8df */
/* @0x3120c2 .word 0x31284479 */
/* @0x3120c6 .word 0xf8dfe004 */
/* @0x3120ca ldrbtmi r1, [r9], #-1628 */
/* @0x3120ce bicvs pc, r0, r1, lsl #10 */
/* @0x3120d2 b 0x204f76a <b2_toiTime+0x18f62c6> */
/* @0x3120d6 ldrbmi r2, [r8], -r0, lsl #6 */
/* @0x3120da addslo pc, r8, r4, asr #17 */
/* @0x3120de stmibvs r10!, {r0, r3, r6, r9, r10, lr} ^ */
/* @0x3120e2 rfedb pc! */
/* @0x3120e6 stmiblt r0!, {r0, r1, r2, r5, r12, pc} ^ */
/* @0x3120ea orrseq pc, r12, #4, #2 */
/* @0x3120ee vhsub.s8 d18, d0, d1 */
/* @0x3120f2 rfeda r3! */
/* @0x3120f6 .word 0xb1691b02 */
/* @0x3120fa strtpl pc, [r12], #2260 */
/* @0x3120fe stmdale r9, {r0, r3, r5, r7, r9, lr} */
/* @0x312102 strtpl pc, [r8], #2260 */
/* @0x312106 andsne pc, r1, r5, lsr r8 */
/* @0x31210a .word 0xf8a3b121 */
/* @0x31210e .word 0xf8c411fe */
/* @0x312112 mul r3, r8, r0 */
/* @0x312116 mvnseq pc, r3, lsr #17 */
/* @0x31211a .word 0x0c02f823 */
/* @0x31211e adcsmi r3, r2, #268435456 */
/* @0x312122 blls 0xd068c6 <b2_toiTime+0x5ad422> */
/* @0x312126 blhs 0x336d9e */
/* @0x31212a ldcge p4, c15, [r10, #252]! */
/* @0x31212e .word 0xf7fca81e */
/* @0x312132 ldmdals r12, {r0, r1, r2, r6, r9, r10, r11, r12, sp, lr, pc} */
/* @0x312136 stmdahs r0, {r0, r1, r3, r4, r12, pc} */
/* @0x31213a sbchi pc, sp, #64 */
/* @0x31213e cdphs p14, #0x0, c9, c0, c9, #0x0 */
/* @0x312142 stmdbvs r3!, {r0, r1, r9, r11, r12, lr, pc} */
/* @0x312146 andlo pc, r0, r10, asr #17 */
/* @0x31214a mrcls p2, #0x0, lr, c6, c8, #0x6 */
/* @0x31214e .word 0x6c08f8c4 */
/* @0x312152 .word 0xf8c49e12 */
/* @0x312156 cdpls p12, #0x0, c6, c9, c12, #0x0 */
/* @0x31215a .word 0xf8cab2b3 */
/* @0x31215e stmdbvs r3!, {r2, r12, sp} ^ */
/* @0x312162 ldrbtvc pc, [pc], pc, asr #12 */
/* @0x312166 andslo pc, r0, r10, asr #17 */
/* @0x31216a strblo pc, [r0, #0x8d4]! */
/* @0x31216e strhle r4, [r4, -r3] */
/* @0x312172 ldmdblt r1, {r1, r4, r8, r11, r12, pc} */
/* @0x312176 tstls r11, #738197504 */
/* @0x31217a .word 0xf8dae2ad */
/* @0x31217e .word 0xf8da3008 */
/* @0x312182 ldrbeq r7, [r10, #0x224] */
/* @0x312186 svchs #0xd53d */
/* @0x31218a bls 0x58627e <g_SWFlineaavertbuff+0x331b6> */
/* @0x31218e stmdami r2!, {r0, r1, r2, r3, r4, r6, r9, r11, sp, lr, pc} */
/* @0x312192 .word 0x2100d037 */
/* @0x312196 uasxmi r6, r0, r11 */
/* @0x31219a .word 0x46014798 */
/* @0x31219e stmdahs r0, {r0, r1, r3, r4, r12, pc} */
/* @0x3121a2 addshi pc, r9, #64 */
/* @0x3121a6 movwls r10, #0xb1e */
/* @0x3121aa .word 0x460b69fd */
/* @0x3121ae .word 0x460a4650 */
/* @0x3121b2 blls 0xaa405a <b2_toiTime+0x34abb6> */
/* @0x3121b6 .word 0xb325691d */
/* @0x3121ba stmdbls r12, {r2, r3, r8, r9, sp} */
/* @0x3121be .word 0xf808fb03 */
/* @0x3121c2 svcvs #0x4b4650 */
/* @0x3121c6 stmdaeq r12, {r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x3121ca andeq lr, r8, #5120 */
/* @0x3121ce bge 0xcf441a <b2_toiTime+0x59af76> */
/* @0x3121d2 mulsls r11, r8, r7 */
/* @0x3121d6 .word 0xf0402800 */
/* @0x3121da .word 0xf8da827e */
/* @0x3121de tstlt r1, r8, lsl r0 */
/* @0x3121e2 .word 0xf7d5980d */
/* @0x3121e6 blls 0xd1048a <b2_toiTime+0x5b6fe6> */
/* @0x3121ea bls 0xaa3b32 <b2_toiTime+0x34a68e> */
/* @0x3121ee andslo pc, r8, r10, asr #17 */
/* @0x3121f2 ldmdavs r1, {r0, r1, r3, r4, r5, r6, r8, r11, sp, lr} */
/* @0x3121f6 andhs pc, r8, r5, asr r8 */
/* @0x3121fa mulsls r11, r8, r7 */
/* @0x3121fe .word 0xf0402800 */
/* @0x312202 .word 0xf894826a */
/* @0x312206 stmdblt r3, {r2, r3, r4, r7, r8, r10, r12, sp} ^ */
/* @0x31220a ldmdblt r2, {r0, r1, r2, r9, r11, r12, pc} */
/* @0x31220e strhlo pc, [r4], #-138 */
/* @0x312212 vst4.8 {d30, d31, d0, d1}, [pc], r1 */
/* @0x312216 .word 0xf8c4737a */
/* @0x31221a .word 0xf8d435a0 */
/* @0x31221e stmdblt sp, {r3, r4, r7, r8, r10, r12, lr} */
/* @0x312222 ldrpl pc, [r4, #0x8d4] */
/* @0x312226 svclt #0xb82d00 */
/* @0x31222a .word 0xf5b5426d */
/* @0x31222e eorsle r3, r0, r0, lsl #31 */
/* @0x312232 .word 0xf8d44629 */
/* @0x312236 .word 0xf7d205a0 */
/* @0x31223a qasxmi pc, r9, sp */
/* @0x31223e streq pc, [r0, #0x8c4]! */
/* @0x312242 streq pc, [r12, #0x8d4] */
/* @0x312246 mrc2 p7, #0x1, apsr_nzcv, c6, c2, #0x6 */
/* @0x31224a .word 0xf8c44629 */
/* @0x31224e .word 0xf8d4058c */
/* @0x312252 .word 0xf7d20594 */
/* @0x312256 strtmi pc, [r9], -pc, lsr #28 */
/* @0x31225a ldreq pc, [r4, #0x8c4] */
/* @0x31225e ldreq pc, [r0, #0x8d4] */
/* @0x312262 mcr2 p7, #0x1, pc, c8, c2, #0x6 */
/* @0x312266 .word 0xf8c44629 */
/* @0x31226a .word 0xf8d40590 */
/* @0x31226e .word 0xf7d20598 */
/* @0x312272 strtmi pc, [r9], -r1, lsr #28 */
/* @0x312276 ldreq pc, [r8, #0x8c4] */
/* @0x31227a streq pc, [r4, #0x8d4]! */
/* @0x31227e mrc2 p7, #0x0, apsr_nzcv, c10, c2, #0x6 */
/* @0x312282 .word 0xf8c44629 */
/* @0x312286 .word 0xf8d405a4 */
/* @0x31228a .word 0xf7d205a8 */
/* @0x31228e .word 0xf8c4fe13 */
/* @0x312292 rfeib r4! */
/* @0x312296 vrshl.s8 d3, d22, d20 */
/* @0x31229a .word 0xf8d4588c */
/* @0x31229e .word 0xf8c497e8 */
/* @0x3122a2 rfeib r4! */
/* @0x3122a6 .word 0xf8c435aa */
/* @0x3122aa .word 0xf1b935a8 */
/* @0x3122ae rsbsle r0, r0, r0, lsl #30 */
/* @0x3122b2 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^ */
/* @0x3122b6 orreq lr, r9, #4, #22 */
/* @0x3122ba ubfxpl pc, r3, #0x11, #0xd */
/* @0x3122be umaallo pc, r0, r5, r8 */
/* @0x3122c2 .word 0xf894b313 */
/* @0x3122c6 orrlt r3, r11, #156, #10 */
/* @0x3122ca strlo pc, [r0, #0x8d4]! */
/* @0x3122ce stmdble r6, {r0, r8, r9, r11, sp} */
/* @0x3122d2 svchs #0x16c6f */
/* @0x3122d6 addsmi sp, pc, #49152 */
/* @0x3122da ldrmi r11, [pc], -r8, lsr #30 */
/* @0x3122de strhs lr, [r1, -r0] */
/* @0x3122e2 .word 0xf1054640 */
/* @0x3122e6 shasxmi r0, r10, r0 */
/* @0x3122ea mrc2 p7, #0x3, apsr_nzcv, c0, c2, #0x6 */
/* @0x3122ee subeq pc, r8, r5, lsl #2 */
/* @0x3122f2 ldrtmi r4, [r10], -r1, asr #12 */
/* @0x3122f6 mcr2 p7, #0x5, pc, c11, c2, #0x6 */
/* @0x3122fa .word 0xf8d46c68 */
/* @0x3122fe ldrtmi r1, [r10], -r0, lsr #11 */
/* @0x312302 ldc2 p7, c15, [r11, #-840] */
/* @0x312306 ands r6, r1, r8, ror #8 */
/* @0x31230a orrpl pc, r12, #4, #4 */
/* @0x31230e ldreq pc, [r0, -r5, lsl #2]! */
/* @0x312312 stm r7, {r0, r1, r2, r3, r8, r9, r11, lr, pc} */
/* @0x312316 vhadd.s8 d0, d4, d15 */
/* @0x31231a .word 0xf10552a4 */
/* @0x31231e ldm r2, {r3, r6, r8, r9} */
/* @0x312322 stm r3, {r0, r1} */
/* @0x312326 .word 0xf8d40003 */
/* @0x31232a strbtvs r3, [r11], #-1440 */
/* @0x31232e stmdblt r7, {r0, r1, r2, r3, r5, r6, r7, r8, r9, r11, sp, lr} */
/* @0x312332 svchs #0x6baf */
/* @0x312336 rsbsmi r11, pc, #184, #30 */
/* @0x31233a svclo #0x80f5b7 */
/* @0x31233e ldrtmi sp, [r9], -r2, lsr #32 */
/* @0x312342 .word 0xf7d26c68 */
/* @0x312346 .word 0x4639fdb7 */
/* @0x31234a blvs 0xd2b4f2 <b2_toiTime+0x5d204e> */
/* @0x31234e ldc2 p7, c15, [r2, #840]! */
/* @0x312352 .word 0x63284639 */
/* @0x312356 .word 0xf7d26ba8 */
/* @0x31235a ldrtmi pc, [r9], -sp, lsr #27 */
/* @0x31235e blvs 0x1d2b206 <b2_toiTime+0x15d1d62> */
/* @0x312362 stc2 p7, c15, [r8, #840]! */
/* @0x312366 .word 0x63684639 */
/* @0x31236a .word 0xf7d26be8 */
/* @0x31236e ldrtmi pc, [r9], -r3, lsr #27 */
/* @0x312372 stcvs p3, c6, [r8], #928 */
/* @0x312376 ldc2 p7, c15, [lr, #840] */
/* @0x31237a strtvs r4, [r8], #1593 */
/* @0x31237e .word 0xf7d26ce8 */
/* @0x312382 strbtvs pc, [r8], #3481 */
/* @0x312386 strhlo pc, [r10], #-149 */
/* @0x31238a rfeib r5! */
/* @0x31238e strbtvs r3, [r11], #78 */
/* @0x312392 blls 0x50c1c6 <SrcVerts+0x6920a> */
/* @0x312396 .word 0xf0002b00 */
/* @0x31239a stmdbvs r3!, {r0, r3, r5, r8, pc} */
/* @0x31239e .word 0xf8ca210a */
/* @0x3123a2 .word 0xf8d43000 */
/* @0x3123a6 adcsmi r3, r3, #224, #10 */
/* @0x3123aa .word 0xf8d4bf16 */
/* @0x3123ae .word 0xf8d434ac */
/* @0x3123b2 movwlo r3, #0x14c0 */
/* @0x3123b6 andslo pc, r0, r10, asr #17 */
/* @0x3123ba ldrlo pc, [r2, #0x9b4]! */
/* @0x3123be eorslo pc, r4, r10, asr #17 */
/* @0x3123c2 ldrpl pc, [r6, #0x9b4]! */
/* @0x3123c6 eorspl pc, r8, r10, asr #17 */
/* @0x3123ca .word 0xf885fa1f */
/* @0x3123ce ldrlo pc, [r8, #0x8d4]! */
/* @0x3123d2 cmnmi pc, #12582912 */
/* @0x3123d6 ldrne r3, [r11], #-1023 */
/* @0x3123da eorslo pc, r12, r10, asr #17 */
/* @0x3123de ldrvc pc, [r12, #0x8d4]! */
/* @0x3123e2 .word 0xf507230c */
/* @0x3123e6 .word 0x37ff477f */
/* @0x3123ea .word 0xf8ca143f */
/* @0x3123ee .word 0xf8d47040 */
/* @0x3123f2 blx 0xad3a7a <b2_toiTime+0x37a5d6> */
/* @0x3123f6 .word 0xf8aaf987 */
/* @0x3123fa .word 0xf8aa8048 */
/* @0x3123fe blx 0x6f651e <g_SWFvertbuff+0x23456> */
/* @0x312402 .word 0xf8aaf888 */
/* @0x312406 addlt r0, r0, #68 */
/* @0x31240a .word 0xf989fa0f */
/* @0x31240e .word 0xf0064358 */
/* @0x312412 bl 0xff54d612 <b2_toiTime+0xfffffffffedf416e> */
/* @0x312416 bls 0x554442 <g_SWFlineaavertbuff+0x137a> */
/* @0x31241a addlt r11, r0, #268435465 */
/* @0x31241e strbmi r11, [r3, #-0x203] */
/* @0x312422 .word 0xf8aabfae */
/* @0x312426 bl 0xff452556 <b2_toiTime+0xfffffffffecf90b2> */
/* @0x31242a .word 0xf8aa0507 */
/* @0x31242e rfeib r4! */
/* @0x312432 qsub16mi r3, r0, lr */
/* @0x312436 subslo pc, r0, r10, lsr #17 */
/* @0x31243a strlo pc, [r2, #0x9b4] */
/* @0x31243e subslo pc, r2, r10, lsr #17 */
/* @0x312442 .word 0xf9edf7fe */
/* @0x312446 andseq pc, r4, r10, asr #17 */
/* @0x31244a rsble r2, r12, r0, lsl #16 */
/* @0x31244e strbne pc, [r8, #-0x8d4]! */
/* @0x312452 .word 0xf7fe4620 */
/* @0x312456 .word 0xf8daf800 */
/* @0x31245a .word 0x46075014 */
/* @0x31245e .word 0xf5a44628 */
/* @0x312462 andlo lr, r1, r10, ror #16 */
/* @0x312466 ldcle p8, c2, [r8, #-24] */
/* @0x31246a blhs 0xdf0b1e <b2_toiTime+0x69767a> */
/* @0x31246e andhs sp, r1, #1073741829 */
/* @0x312472 stclpl p3, c2, [r9], #0 */
/* @0x312476 stmdblo r1, {r0, r8, r9, r12, sp} ^ */
/* @0x31247a svclt #0x882919 */
/* @0x31247e blhs 0x49ac86 <TimingData+0xc6e> */
/* @0x312482 ldrshlt sp, [r2, #-23] */
/* @0x312486 stmdane r10!, {r0, r1, r3, r5, r6, r7, r8, r10, r11, r12} */
/* @0x31248a mulle r4, r3, r2 */
/* @0x31248e blne 0x3904e2 <_ZTS15b2QueryCallback+0xaa> */
/* @0x312492 .word 0x1c08f803 */
/* @0x312496 stmdalo r7, {r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x31249a .word 0xf8d4e7e4 */
/* @0x31249e stmdblt r9, {r2, r3, r5, r6, r8, r10, r12} */
/* @0x3124a2 subs r11, r9, pc, lsr #18 */
/* @0x3124a6 .word 0xf7fd4620 */
/* @0x3124aa ldmdblt r0, {r1, r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3124ae ldmdblt sp, {r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x3124b2 svchs #0xe052 */
/* @0x3124b6 .word 0x4605d050 */
/* @0x3124ba blhs 0x3305ae */
/* @0x3124be stmdavc r10!, {r2, r3, r6, r12, lr, pc} */
/* @0x3124c2 swple r4, r3, [r1] */
/* @0x3124c6 and r3, r3, r1, lsl #10 */
/* @0x3124ca andle r2, r1, r0, lsr #22 */
/* @0x3124ce .word 0xd1012b2d */
/* @0x3124d2 ldrb r3, [r1, r1, lsl #14]! */
/* @0x3124d6 andle r2, r1, r0, lsr #20 */
/* @0x3124da .word 0xd1012a2d */
/* @0x3124de strb r3, [r11, r1, lsl #10]! */
/* @0x3124e2 teqle r9, r0, lsl #20 */
/* @0x3124e6 bge 0xce3dd2 <b2_toiTime+0x58a92e> */
/* @0x3124ea .word 0xf7d6980d */
/* @0x3124ee .word 0xf8daf9e9 */
/* @0x3124f2 .word 0x46075014 */
/* @0x3124f6 .word 0xf5a44628 */
/* @0x3124fa pkhbtmi lr, r0, lr, lsl #16 */
/* @0x3124fe .word 0xf5a44638 */
/* @0x312502 strmi lr, [r0, #0x81a] */
/* @0x312506 stcle p6, c4, [r3, #-12]! */
/* @0x31250a andeq lr, r8, r5, lsl #22 */
/* @0x31250e andhs r1, r1, #16318464 */
/* @0x312512 vqsub.u8 d4, d16, d10 */
/* @0x312516 .word 0xf81080e3 */
/* @0x31251a .word 0xf811cd01 */
/* @0x31251e ldrbmi lr, [r4, #0xd01]! */
/* @0x312522 andlo sp, r1, #-2147483643 */
/* @0x312526 .word 0xf8d4e7f4 */
/* @0x31252a strtmi r1, [r0], -r8, lsl #12 */
/* @0x31252e .word 0xff93f7fd */
/* @0x312532 orrlt r4, r8, r1, lsl #12 */
/* @0x312536 bge 0xcf8572 <b2_toiTime+0x59f0ce> */
/* @0x31253a .word 0xf9c2f7d6 */
/* @0x31253e andseq pc, r4, r10, asr #17 */
/* @0x312542 stclpl p0, c14, [r10], #40 */
/* @0x312546 .word 0xf0402a2d */
/* @0x31254a bllo 0x372882 <_ZTS13C_UTF16String+0x992e> */
/* @0x31254e vldmiale r8!, {d18} */
/* @0x312552 .word 0xf8cab117 */
/* @0x312556 and r7, r7, r8, lsl r0 */
/* @0x31255a bge 0xce4b32 <b2_toiTime+0x58b68e> */
/* @0x31255e ldrbtmi r9, [r9], #-2061 */
/* @0x312562 .word 0xf9aef7d6 */
/* @0x312566 andseq pc, r8, r10, asr #17 */
/* @0x31256a .word 0xf6409911 */
/* @0x31256e .word 0xf6400219 */
/* @0x312572 stmdbhs r0, {r0, r4, r8, r9} */
/* @0x312576 sadd16mi r11, r3, r8 */
/* @0x31257a ldrbhs pc, [r4, #-0x894]! */
/* @0x31257e .word 0xf043b10a */
/* @0x312582 .word 0xf8da0304 */
/* @0x312586 strtmi r2, [r0], -r8 */
/* @0x31258a .word 0xf8ca4313 */
/* @0x31258e .word 0xf8d43008 */
/* @0x312592 .word 0xf8d45578 */
/* @0x312596 strlo r1, [r0, #-0x570] */
/* @0x31259a strhs r11, [r1, #-0xf18] */
/* @0x31259e .word 0xff5bf7fd */
/* @0x3125a2 .word 0xb1604607 */
/* @0x3125a6 ldrbtmi r4, [r9], #-2402 */
/* @0x3125aa svc #0xe4f5a3 */
/* @0x3125ae stmdbmi r0!, {r3, r5, r8, r12, sp, pc} ^ */
/* @0x3125b2 ldrbtmi r4, [r9], #-1592 */
/* @0x3125b6 svc #0xdef5a3 */
/* @0x3125ba .word 0xf045b908 */
/* @0x3125be streq r0, [r11, r2, lsl #10]! */
/* @0x3125c2 .word 0xf8dad412 */
/* @0x3125c6 cmnlt pc, r8, lsl r0 */
/* @0x3125ca shsaxmi r4, r8, r11 */
/* @0x3125ce ldrbtmi r2, [r9], #-516 */
/* @0x3125d2 stmda r6, {r2, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x3125d6 ldmdbmi r8, {r4, r5, r8, r12, sp, pc} ^ */
/* @0x3125da andhs r4, r5, #56, #12 */
/* @0x3125de .word 0xf5a34479 */
/* @0x3125e2 stmdblt r8, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr, pc} */
/* @0x3125e6 streq pc, [r2, #-0x45] */
/* @0x3125ea andpl pc, r12, r10, asr #17 */
/* @0x3125ee strblo pc, [r0, #0x8d4]! */
/* @0x3125f2 strhle r4, [r5, -r3] */
/* @0x3125f6 .word 0x3008f8da */
/* @0x3125fa movwvc pc, #0x443 */
/* @0x3125fe andlo pc, r8, r10, asr #17 */
/* @0x312602 strblo pc, [r0, #0x8d4]! */
/* @0x312606 strhle r4, [r7], -r3 */
/* @0x31260a .word 0xb12a9a07 */
/* @0x31260e .word 0x3008f8da */
/* @0x312612 orrpl pc, r0, #1124073472 */
/* @0x312616 andlo pc, r8, r10, asr #17 */
/* @0x31261a .word 0x5024f8da */
/* @0x31261e ldmdami r8!, {r8, r9, sp} */
/* @0x312622 andle r4, r10, r11, lsr #5 */
/* @0x312626 .word 0x2028f8da */
/* @0x31262a eorhs pc, r3, r2, asr r8 */
/* @0x31262e addmi r6, r1, #9502720 */
/* @0x312632 ldmdbhi r2, {r1, r2, r3, r5, r12, lr, pc} */
/* @0x312636 movwlo r11, #0x1362 */
/* @0x31263a blls 0x50c60a <SrcVerts+0x6964e> */
/* @0x31263e .word 0xf8d4b11b */
/* @0x312642 adcsmi r3, r3, #224, #10 */
/* @0x312646 movwhs sp, #0x3147 */
/* @0x31264a adclo pc, r4, sp, lsr #17 */
/* @0x31264e .word 0xf8ad2301 */
/* @0x312652 blmi 0xe1e8f2 <b2_toiTime+0x6c544e> */
/* @0x312656 ldmdami r9!, {r8, sp} */
/* @0x31265a .word 0xf8cdaa27 */
/* @0x31265e .word 0x9328a09c */
/* @0x312662 stmdavs r0, {r3, r4, r5, r6, r10, lr} */
/* @0x312666 .word 0xf7d5460b */
/* @0x31266a tstlt r0, r5, lsl #29 */
/* @0x31266e blhs 0xfebff182 <b2_toiTime+0xfffffffffe4a5cde> */
/* @0x312672 movwhs sp, #0x130 */
/* @0x312676 .word 0xf8da931b */
/* @0x31267a stmdblt r11, {r2, r3, r4, r6, r12, sp} ^ */
/* @0x31267e .word 0x3024f8da */
/* @0x312682 mulle r5, sp, r2 */
/* @0x312686 .word 0x3028f8da */
/* @0x31268a eorlo pc, r5, r3, asr r8 */
/* @0x31268e subslo pc, r12, r10, asr #17 */
/* @0x312692 ldrsblo pc, [r8], r4 */
/* @0x312696 movwhs r11, #0x71fb */
/* @0x31269a addsge pc, r12, sp, asr #17 */
/* @0x31269e adclo pc, r4, sp, lsr #17 */
/* @0x3126a2 ldrsblo pc, [r4], r4 */
/* @0x3126a6 .word 0xf8adb91b */
/* @0x3126aa blmi 0x91e94a <b2_toiTime+0x1c54a6> */
/* @0x3126ae blhs 0x38a6da <bigtens_D2A+0xbaa> */
/* @0x3126b2 .word 0xf8add103 */
/* @0x3126b6 blmi 0x89e956 <b2_toiTime+0x1454b2> */
/* @0x3126ba movwhs lr, #0x2003 */
/* @0x3126be adclo pc, r6, sp, lsr #17 */
/* @0x3126c2 ldmdami pc, {r0, r2, r4, r8, r9, r11, lr} */
/* @0x3126c6 .word 0x93282100 */
/* @0x3126ca ldrbtmi r10, [r8], #-2599 */
/* @0x3126ce strmi r6, [r11], -r0, lsl #16 */
/* @0x3126d2 mrc2 p7, #0x2, apsr_nzcv, c0, c5, #0x6 */
/* @0x3126d6 ldmdals r11, {r0, r1, r3, r4, r12, pc} */
/* @0x3126da and lr, pc, r0, lsl r0 */
/* @0x3126de movweq lr, #0x8bc3 */
/* @0x3126e2 bhs 0xb4c3b6 <b2_toiTime+0x3f2f12> */
/* @0x3126e6 svcge #0x31f43f */
/* @0x3126ea .word 0xf43f2a5f */
/* @0x3126ee bhs 0xdfe3ae <b2_toiTime+0x6a4f0a> */
/* @0x3126f2 svcge #0x2bf43f */
/* @0x3126f6 andhs r4, r0, #721420288 */
/* @0x3126fa .word 0xe729705a */
/* @0x3126fe pop {r0, r4, r5, r12, sp, pc} */
/* @0x312702 strdeq r8, r9, [r3], -r0 */
/* @0x312706 stmdbvs r3!, {r0} ^ */
/* @0x31270a ldmibne r0!, {r1, r2, r3, r5, r6, r8, r10, r12, sp, lr} ^ */
/* @0x31270e svcmi #0x420009 */
/* @0x312712 submi r4, r5, #68, #2 */
/* @0x312716 submi r4, r3, #68, #2 */
/* @0x31271a stmibne r4, {r2, r6, r8, lr} ^ */
/* @0x31271e ldmibne r10, {r0, r3} */
/* @0x312722 ldrbne r0, [r6, -r9] */
/* @0x312726 strbne r0, [r12, -r9] */
/* @0x31272a adcgt r0, r12, #9 */
/* @0x31272e subgt r0, r2, #7 */
/* @0x312732 strbtgt r0, [r4], r7 */
/* @0x312736 andsgt r0, r10, #7 */
/* @0x31273a ldrtgt r0, [r10], r7 */
/* @0x31273e .word 0xf59a0007 */
/* @0x312742 .word 0xf52c000d */
/* @0x312746 push {r0, r2, r3} */
/* @0x31274a .word 0xf5ad4ff0 */
/* @0x31274e addlt r5, r7, r11, ror sp */
/* @0x312752 ldrgt pc, [r12, #0x8df] */
/* @0x312756 ldrbpl pc, [r12, #-0x50d]! */
/* @0x31275a strlo r10, [r12, #-0xc36] */
/* @0x31275e .word 0xf50d910b */
/* @0x312762 ldrbtmi r5, [r12], #380 */
/* @0x312766 .word 0xc000f8dc */
/* @0x31276a strmi r6, [r3], sp, lsr #16 */
/* @0x31276e strhs r7, [r10, -r9, lsl #16] */
/* @0x312772 mcrge p3, #0x1, r9, c6, c7, #0x0 */
/* @0x312776 .word 0xf8d09510 */
/* @0x31277a .word 0xf8dc50b0 */
/* @0x31277e tstls r11, r0 */
/* @0x312782 cmnpl r11, sp, lsl #10 */
/* @0x312786 stcne p5, c9, [r5, #-36] */
/* @0x31278a tstlo r4, pc, lsl #10 */
/* @0x31278e andvs r6, r11, r5, asr #22 */
/* @0x312792 .word 0xf8d02100 */
/* @0x312796 ldrls r8, [r4, #-0x0] */
/* @0x31279a andsls r9, r10, #576 */
/* @0x31279e .word 0xf8d52280 */
/* @0x3127a2 ldcge p2, c3, [lr, #-896]! */
/* @0x3127a6 qadd16mi r9, r8, r12 */
/* @0x3127aa eorlo pc, r0, #13828096 */
/* @0x3127ae .word 0xf50d9311 */
/* @0x3127b2 movwlo r5, #0x837c */
/* @0x3127b6 .word 0xf8cd681b */
/* @0x3127ba movwls r12, #0xa010 */
/* @0x3127be cdp p5, #0xf, c15, c8, c3, #0x5 */
/* @0x3127c2 tsths r0, #960 */
/* @0x3127c6 .word 0xf1a49a0f */
/* @0x3127ca .word 0x93280120 */
/* @0x3127ce .word 0xf8442314 */
/* @0x3127d2 adcvs r3, r3, r8, lsl r12 */
/* @0x3127d6 cmnpl r10, #54525952 */
/* @0x3127da strls r3, [r7, #-0x31c]! */
/* @0x3127de tstls r3, r0, lsl #10 */
/* @0x3127e2 .word 0x2c1cf844 */
/* @0x3127e6 rsbvs r4, r2, r9, lsr #12 */
/* @0x3127ea andshs r4, r12, #24, #12 */
/* @0x3127ee strls r9, [r10, -r9, lsr #10]! */
/* @0x3127f2 strls r9, [r12, #-0x52b]! */
/* @0x3127f6 .word 0xf844952d */
/* @0x3127fa .word 0xf8445c14 */
/* @0x3127fe .word 0xf8447c10 */
/* @0x312802 .word 0xf8445c0c */
/* @0x312806 .word 0xf8445c08 */
/* @0x31280a rscvs r5, r5, r4, lsl #24 */
/* @0x31280e .word 0x61656127 */
/* @0x312812 mvnvs r6, r5, lsr #3 */
/* @0x312816 .word 0xf8cd931d */
/* @0x31281a .word 0xf8448098 */
/* @0x31281e .word 0xf8c48c20 */
/* @0x312822 .word 0xf5a38000 */
/* @0x312826 .word 0xf50deec4 */
/* @0x31282a stmdbls pc, {r2, r7, r8, r9, r12, lr} */
/* @0x31282e .word 0xf50d3318 */
/* @0x312832 .word 0xf1a3527a */
/* @0x312836 andslo r0, r12, #4, #20 */
/* @0x31283a qadd16mi r6, r9, r1 */
/* @0x31283e andvs pc, r8, #69206016 */
/* @0x312842 movwls r4, #0x7650 */
/* @0x312846 cdp p5, #0xb, c15, c4, c3, #0x5 */
/* @0x31284a orrpl pc, r4, sp, lsl #10 */
/* @0x31284e ldmdbpl r5!, {r1, r3, r8, r10, r12, sp, lr, pc} */
/* @0x312852 bls 0x99ecaa <b2_toiTime+0x245806> */
/* @0x312856 andlt pc, r0, r1, asr #17 */
/* @0x31285a tsteq r12, #1073741826 */
/* @0x31285e .word 0xf8c9990f */
/* @0x312862 .word 0xf50a702c */
/* @0x312866 .word 0xf8ca57f2 */
/* @0x31286a .word 0xf6402004 */
/* @0x31286e movwls r7, #0x821c */
/* @0x312872 movwhs r4, #0x8638 */
/* @0x312876 eorne pc, r0, r9, asr #17 */
/* @0x31287a eorlo pc, r4, r9, asr #17 */
/* @0x31287e .word 0xf8c94629 */
/* @0x312882 .word 0xf5a3801c */
/* @0x312886 .word 0xf89bee94 */
/* @0x31288a bls 0x81eb72 <b2_toiTime+0xc56ce> */
/* @0x31288e rscspl pc, sp, sp, lsl #10 */
/* @0x312892 andslo r9, r8, r8, lsl #18 */
/* @0x312896 teqvs r10, r11, ror r3 */
/* @0x31289a andsvc pc, r12, #64, #12 */
/* @0x31289e .word 0x462960b9 */
/* @0x3128a2 andlt pc, r0, r7, asr #17 */
/* @0x3128a6 movwls r6, #0x507f */
/* @0x3128aa cdp p5, #0x8, c15, c2, c3, #0x5 */
/* @0x3128ae blls 0x479106 <g_RomDisk+0x818e6> */
/* @0x3128b2 .word 0xf8ca9908 */
/* @0x3128b6 .word 0xf50d2f34 */
/* @0x3128ba andslo r5, r8, #132, #4 */
/* @0x3128be svclo #0x31f88a */
/* @0x3128c2 svcne #0x2cf8ca */
/* @0x3128c6 qadd16mi r1, r9, r0 */
/* @0x3128ca svclt #0x24f8ca */
/* @0x3128ce svcvc #0x28f8ca */
/* @0x3128d2 andsvc pc, r12, #64, #12 */
/* @0x3128d6 .word 0xf5a39305 */
/* @0x3128da blls 0x48e28a <prim_v+0x48d6> */
/* @0x3128de .word 0xf8db9d14 */
/* @0x3128e2 .word 0xf88a2030 */
/* @0x3128e6 blls 0x51e942 <SrcVerts+0x7b986> */
/* @0x3128ea andspl pc, r8, r10, asr #17 */
/* @0x3128ee andlt pc, r8, r10, asr #17 */
/* @0x3128f2 andslo pc, r0, r10, asr #17 */
/* @0x3128f6 .word 0x3028f8db */
/* @0x3128fa andvc pc, r12, r10, asr #17 */
/* @0x3128fe eorslo pc, r12, r9, asr #17 */
/* @0x312902 teqpl r6, #41943040 */
/* @0x312906 eoreq lr, r4, r3, lsl #17 */
/* @0x31290a andeq pc, r8, #-1073741824 */
/* @0x31290e orrsvs r9, r12, r7, lsl sp */
/* @0x312912 muleq r3, r5, r8 */
/* @0x312916 stm r2, {r1, r3, r8, r10, r11, r12, pc} */
/* @0x31291a .word 0xf50d0003 */
/* @0x31291e andslo r5, r12, #-1610612729 */
/* @0x312922 .word 0xf10b61da */
/* @0x312926 subsvs r0, r10, #240, #4 */
/* @0x31292a umlalshs pc, r9, r11, r8 */
/* @0x31292e cmpvs r9, lr, lsr #18 */
/* @0x312932 .word 0x10e4f8db */
/* @0x312936 .word 0xf8db749a */
/* @0x31293a addsvs r2, r9, #232 */
/* @0x31293e svclt #0xb82900 */
/* @0x312942 andsvs r4, sp, #-1879048188 */
/* @0x312946 bhs 0x32b4b6 */
/* @0x31294a subsmi r11, r2, #184, #30 */
/* @0x31294e svclt #0xa84291 */
/* @0x312952 subseq r4, r2, r10, lsl #12 */
/* @0x312956 .word 0xf641631a */
/* @0x31295a cmpvs r10, #-1610612727 */
/* @0x31295e ldrbvc r2, [r10], #513 */
/* @0x312962 mullo r8, r11, r8 */
/* @0x312966 svclt #0x183300 */
/* @0x31296a .word 0xf8062301 */
/* @0x31296e stcls p12, c3, [r9, #-20] */
/* @0x312972 rsclo pc, r0, #13959168 */
/* @0x312976 .word 0xf8d39d10 */
/* @0x31297a ldreq r3, [r11], #-540 */
/* @0x31297e .word 0xf8dd602b */
/* @0x312982 .word 0xf89bc010 */
/* @0x312986 .word 0xf8cd3008 */
/* @0x31298a smlawblt r11, r0, r0, r12 */
/* @0x31298e stclvs p13, c9, [r11], #36 */
/* @0x312992 .word 0x3614f8d3 */
/* @0x312996 and r9, r1, r5, lsl r3 */
/* @0x31299a ldrls r2, [r5, #-0x530] */
/* @0x31299e strbmi r10, [r0], -r6, ror #26 */
/* @0x3129a2 smulwbeq r0, r5, r1 */
/* @0x3129a6 qaddls r10, lr, r8 */
/* @0x3129aa .word 0x26002114 */
/* @0x3129ae stcvs p8, c15, [r0], #-276 */
/* @0x3129b2 blx 0xff15090c <b2_toiTime+0xfffffffffe9f7468> */
/* @0x3129b6 stclo p8, c15, [r0], #-340 */
/* @0x3129ba ldmdblt r11, {r2, r9, r10, lr} */
/* @0x3129be .word 0xf8c09a0f */
/* @0x3129c2 subvs r8, r2, r0 */
/* @0x3129c6 .word 0x9600ab5e */
/* @0x3129ca strbmi r9, [r0], -r1, lsl #6 */
/* @0x3129ce .word 0x21089b15 */
/* @0x3129d2 .word 0xf7d52200 */
/* @0x3129d6 adcvs pc, r0, r11, asr r11 */
/* @0x3129da stclo p8, c15, [r0], #-340 */
/* @0x3129de .word 0x4640b13b */
/* @0x3129e2 .word 0xf7d44621 */
/* @0x3129e6 strhs pc, [r0, #-0xca7] */
/* @0x3129ea .word 0xf0009512 */
/* @0x3129ee ldcls p15, c11, [r5, #-776] */
/* @0x3129f2 ldrls r6, [r2], #-224 */
/* @0x3129f6 .word 0x2c006125 */
/* @0x3129fa ldrhi pc, [r11, r0]! */
/* @0x3129fe fstmdbxge r6!, {d9, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28} */
/* @0x312a02 blhs 0x737e32 <g_SWFvertbuff+0x64d6a> */
/* @0x312a06 tsths r1, #32768 */
/* @0x312a0a and r9, r5, r11, lsr #6 */
/* @0x312a0e tsths r1, r6, lsr #16 */
/* @0x312a12 .word 0xffddf7fb */
/* @0x312a16 mvnsle r2, r0, lsl #16 */
/* @0x312a1a strls r9, [r7, #-0xd2d] */
/* @0x312a1e ldm r5, {r0, r1, r3, r8, r10, r11, r12, pc} */
/* @0x312a22 stcls p0, c0, [r7, #-60] */
/* @0x312a26 andeq lr, pc, r5, lsl #17 */
/* @0x312a2a .word 0x5004f8db */
/* @0x312a2e teqle r5, r0, lsl #26 */
/* @0x312a32 ldmdbls r1, {r4, r5, r7, r8, r9, r11, lr} */
/* @0x312a36 bmi 0xfee23c2a <b2_toiTime+0xfffffffffe6ca786> */
/* @0x312a3a msreq APSR_g, #3145728 */
/* @0x312a3e blmi 0xfee776ca <b2_toiTime+0xfffffffffe71e226> */
/* @0x312a42 strls r0, [r11, #-0x409] */
/* @0x312a46 ldreq pc, [r3, #0x10d] */
/* @0x312a4a ldrbtmi r9, [r11], #-1297 */
/* @0x312a4e .word 0xf6034dab */
/* @0x312a52 tstls r6, r8, lsl r3 */
/* @0x312a56 andsls r4, r9, #2097152000 */
/* @0x312a5a strls r9, [r3, #-0x322]! */
/* @0x312a5e blls 0x64aaa2 <g_SWFaavertbuff+0x779da> */
/* @0x312a62 blne 0x1a6ccf2 <b2_toiTime+0x131384e> */
/* @0x312a66 bne 0xfe9acdfa <b2_toiTime+0xfffffffffe253956> */
/* @0x312a6a svceq #0xe2ebb5 */
/* @0x312a6e rschi pc, r4, r0, asr #4 */
/* @0x312a72 .word 0x21a16860 */
/* @0x312a76 .word 0xf9e4f7fb */
/* @0x312a7a .word 0xf88b2301 */
/* @0x312a7e stcls p0, c3, [r7, #-372] */
/* @0x312a82 stmvs r11!, {r1, r3, r5, r6, r7, r11, sp, lr} */
/* @0x312a86 movwle r4, #0xc29a */
/* @0x312a8a stchs p13, c9, [r0, #-44] */
/* @0x312a8e .word 0xf04fbf0c */
/* @0x312a92 .word 0xf04f080e */
/* @0x312a96 .word 0xf8db080b */
/* @0x312a9a .word 0xb1a33004 */
/* @0x312a9e .word 0xf0002500 */
/* @0x312aa2 stmdals r7, {r0, r3, r5, r6, r8, r9, r10, r11, r12, sp, pc} */
/* @0x312aa6 blx 0xff810aa0 <b2_toiTime+0xffffffffff0b75fc> */
/* @0x312aaa .word 0xf880fa5f */
/* @0x312aae svceq #0xbf1b8 */
/* @0x312ab2 .word 0xf1b8d002 */
/* @0x312ab6 mvnle r0, lr, lsl #30 */
/* @0x312aba mullo r8, r11, r8 */
/* @0x312abe svclt #0x182b00 */
/* @0x312ac2 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x312ac6 ldcls p7, c14, [r9, #-924] */
/* @0x312aca ldrls r3, [r9, #-0xd01] */
/* @0x312ace strhi pc, [r4], #0 */
/* @0x312ad2 svceq #0x1ff1b8 */
/* @0x312ad6 strhi pc, [r4, -r0, lsl #4] */
/* @0x312ada .word 0xf018e8df */
/* @0x312ade adcseq r0, r2, r7, asr #14 */
/* @0x312ae2 sbceq r0, r1, r7, asr #14 */
/* @0x312ae6 ldrsbeq r0, [r1, -r10] */
/* @0x312aea teqeq r12, r12, lsr r1 */
/* @0x312aee strbeq r0, [r7, -r9, ror #2] */
/* @0x312af2 eoreq r0, r3, #-2147483593 */
/* @0x312af6 strbeq r0, [r7, -pc, lsr #4] */
/* @0x312afa eoreq r0, r0, r11, ror #7 */
/* @0x312afe smlaldxeq r0, r7, r4, r0 */
/* @0x312b02 streq r0, [r0], #178 */
/* @0x312b06 ldrbeq r0, [lr], #1152 */
/* @0x312b0a sbceq r0, r1, r0, lsl r5 */
/* @0x312b0e ldreq r0, [sp, #-0x169]! */
/* @0x312b12 .word 0x060405b1 */
/* @0x312b16 ldrsheq r0, [lr, #102] */
/* @0x312b1a usaxeq r0, r7, r7 */
/* @0x312b1e mullo r8, r11, r8 */
/* @0x312b22 .word 0xf0002b00 */
/* @0x312b26 .word 0xf89b8722 */
/* @0x312b2a blhs 0x31eca6 */
/* @0x312b2e ldrbhi pc, [r4], #-64 */
/* @0x312b32 .word 0xf7fc4620 */
/* @0x312b36 stmdahs r0, {r0, r1, r2, r6, r7, r8, r9, r11, r12, sp, lr, pc} */
/* @0x312b3a ldrhi pc, [r7, -r0, asr #5] */
/* @0x312b3e rsbseq pc, r8, r11, asr #17 */
/* @0x312b42 svclt #0x13f000 */
/* @0x312b46 mullo r8, r11, r8 */
/* @0x312b4a .word 0xf0002b00 */
/* @0x312b4e .word 0xf8db870e */
/* @0x312b52 blhs 0x31ecda */
/* @0x312b56 strbhi pc, [r0], #-0 */
/* @0x312b5a ldrsbtvc pc, [r8], #-139 */
/* @0x312b5e ldmdaeq r12, {r0, r1, r3, r8, r12, sp, lr, pc} ^ */
/* @0x312b62 ldrsbtvs pc, [r12], #-139 */
/* @0x312b66 .word 0x5080f8db */
/* @0x312b6a ldrtmi r4, [r9], -r0, asr #12 */
/* @0x312b6e qasxmi r4, r11, r2 */
/* @0x312b72 .word 0xf8a0f7fd */
/* @0x312b76 strtmi r11, [r0], -r8, lsr #19 */
/* @0x312b7a blx 0xfec50b74 <b2_toiTime+0xfffffffffe4f76d0> */
/* @0x312b7e adcmi r9, r8, #1344 */
/* @0x312b82 vmax.s8 d4, d0, d6 */
/* @0x312b86 .word 0xf8db8429 */
/* @0x312b8a stmvs r2!, {r4, r5, r6, r12, lr} ^ */
/* @0x312b8e movtmi r6, #0x58a3 */
/* @0x312b92 bl 0xff4596e6 <b2_toiTime+0xfffffffffed00242> */
/* @0x312b96 movwls r0, #0xd3e3 */
/* @0x312b9a ldrmi r9, [r9], r12, lsl #10 */
/* @0x312b9e strmi r2, [r1], #1280 */
/* @0x312ba2 qadd16mi lr, r11, r5 */
/* @0x312ba6 ldrtmi r4, [r9], -r0, asr #12 */
/* @0x312baa .word 0xf7fb4632 */
/* @0x312bae strmi pc, [r5], -r1, asr #30 */
/* @0x312bb2 rscle r2, r0, r0, lsl #16 */
/* @0x312bb6 cdplt p0, #0xd, c15, c14, c0, #0x0 */
/* @0x312bba stmvs r1!, {r1, r5, r7, r11, sp, lr} ^ */
/* @0x312bbe bl 0xff0d95ea <b2_toiTime+0xfffffffffe980146> */
/* @0x312bc2 ldmdble r1!, {r0, r5, r6, r7, r8, r9, r10, r11} */
/* @0x312bc6 orrhs r6, r2, r0, ror #16 */
/* @0x312bca rfedb r10! */
/* @0x312bce adcsmi r3, r5, #4194304 */
/* @0x312bd2 svcge #0x45f43f */
/* @0x312bd6 strtmi r9, [r0], -sp, lsl #30 */
/* @0x312bda ldrsbths pc, [r4], #-139 */
/* @0x312bde stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x312be2 ldrtmi r4, [r9], -pc, lsr #8 */
/* @0x312be6 .word 0xf7fc920e */
/* @0x312bea strmi pc, [r3], -r7, lsr #23 */
/* @0x312bee ldrsbths pc, [r0], #-139 */
/* @0x312bf2 rscle r4, r1, #144, #10 */
/* @0x312bf6 strtmi r9, [r0], -lr, lsl #18 */
/* @0x312bfa .word 0x0c01f109 */
/* @0x312bfe eorhs pc, r8, r1, asr r8 */
/* @0x312c02 movwls r4, #0x5649 */
/* @0x312c06 stmdaeq r1, {r3, r8, r12, sp, lr, pc} */
/* @0x312c0a andsgt pc, r0, sp, asr #17 */
/* @0x312c0e .word 0xf7fc9206 */
/* @0x312c12 bls 0x4d1a66 <SrcVerts+0x2eaaa> */
/* @0x312c16 ldrmi r4, [r0], -r1, lsl #12 */
/* @0x312c1a .word 0xf8cbf7fb */
/* @0x312c1e ldrsbgt pc, [r0], -sp */
/* @0x312c22 strbtmi r9, [r1], r5, lsl #22 */
/* @0x312c26 strb r4, [r1, r3, lsl #8]! */
/* @0x312c2a eorslo pc, r7, r2, asr #16 */
/* @0x312c2e stmvs r3!, {r9, sp} */
/* @0x312c32 strbeq lr, [r7, r3, lsl #22] */
/* @0x312c36 .word 0xe7c9607a */
/* @0x312c3a blne 0x19d2ff6 <b2_toiTime+0x1279b52> */
/* @0x312c3e ldr r6, [r11, -r3, ror #1] */
/* @0x312c42 ldrbpl pc, [r10, #-0x50d]! */
/* @0x312c46 stmdavc r11!, {r5, r8, r10, r12, sp} */
/* @0x312c4a .word 0xf0402b00 */
/* @0x312c4e .word 0xf10d868e */
/* @0x312c52 .word 0xf10b0393 */
/* @0x312c56 movwls r0, #0xb0 */
/* @0x312c5a bge 0xea44e6 <b2_toiTime+0x74b042> */
/* @0x312c5e .word 0xf50de00d */
/* @0x312c62 eorlo r5, r0, #-1610612729 */
/* @0x312c66 blhs 0x330cba */
/* @0x312c6a ldrbthi pc, [pc], -r0, asr #32 */
/* @0x312c6e adcseq pc, r0, r11, lsl #2 */
/* @0x312c72 qasxmi r10, r1, r6 */
/* @0x312c76 orrseq pc, r3, #1073741827 */
/* @0x312c7a blls 0x737882 <g_SWFvertbuff+0x647ba> */
/* @0x312c7e blx 0xfec10c7c <b2_toiTime+0xfffffffffe4b77d8> */
/* @0x312c82 ldrsbtlo pc, [r0], r11 */
/* @0x312c86 eorslo pc, r1, #9633792 */
/* @0x312c8a .word 0xf0002b00 */
/* @0x312c8e str r8, [r5, -lr, ror #12] */
/* @0x312c92 stmvs r3!, {r1, r5, r6, r7, r11, sp, lr} */
/* @0x312c96 blhs 0x6d97ea <g_SWFvertbuff+0x6722> */
/* @0x312c9a .word 0xf89dd909 */
/* @0x312c9e ldmdblt r1!, {r0, r1, r4, r7, r12} */
/* @0x312ca2 .word 0xf7fc4620 */
/* @0x312ca6 vldrls d15, [r6, #-292] */
/* @0x312caa ldcls p4, c4, [r0, #-160] */
/* @0x312cae movwhs r6, #0x1028 */
/* @0x312cb2 addslo pc, r3, sp, lsl #17 */
/* @0x312cb6 ldrsbtlo pc, [r0], r11 */
/* @0x312cba eorslo pc, r1, #9633792 */
/* @0x312cbe .word 0xf47f2b00 */
/* @0x312cc2 .word 0xf50daeed */
/* @0x312cc6 qsub16mi r5, r0, r12 */
/* @0x312cca stmdavs sp, {r3, r8, r12, sp} */
/* @0x312cce blx 0x7d0cc8 <b2_toiTime+0x77824> */
/* @0x312cd2 cmnpl r12, #54525952 */
/* @0x312cd6 stmdane r10!, {r3, r8, r9, r12, sp} */
/* @0x312cda ldrbpl pc, [r12, #-0x50d]! */
/* @0x312cde andsvs r3, r10, r4, lsl #10 */
/* @0x312ce2 stmdavs r9!, {r4, r6, r9, r10, lr} */
/* @0x312ce6 ldclt p0, c15, [r4], #-0 */
/* @0x312cea stchs p15, c11, [r0, #-0] */
/* @0x312cee mvnslt r0, r1, lsr r1 */
/* @0x312cf2 stcleq p0, c0, [r2, #52]! */
/* @0x312cf6 stcleq p0, c0, [r12, #36] */
/* @0x312cfa stcleq p0, c0, [r2, #36] */
/* @0x312cfe stmvs r6!, {r0, r3} ^ */
/* @0x312d02 stmvs r3!, {r8, r10, sp} */
/* @0x312d06 ldrshtne r1, [r6], #166 */
/* @0x312d0a .word 0xf08042b5 */
/* @0x312d0e .word 0xf50d862e */
/* @0x312d12 qsub16mi r5, r0, r12 */
/* @0x312d16 stmdavs pc, {r2, r8, r12, sp} */
/* @0x312d1a .word 0xf7fc4629 */
/* @0x312d1e .word 0xf50dfb0d */
/* @0x312d22 andlo r5, r4, #124, #4 */
/* @0x312d26 cmnpl r12, #54525952 */
/* @0x312d2a stclne p3, c3, [r9], #-32 */
/* @0x312d2e ldrtmi r3, [r8], #-1282 */
/* @0x312d32 qadd16mi r6, r0, r0 */
/* @0x312d36 .word 0xf7fc681f */
/* @0x312d3a .word 0xf50dfaff */
/* @0x312d3e .word 0xf50d517c */
/* @0x312d42 .word 0x3108537c */
/* @0x312d46 ldmdane r10!, {r2, r8, r9, r12, sp} */
/* @0x312d4a andvs r4, r10, r0, asr r6 */
/* @0x312d4e .word 0xf7fe6819 */
/* @0x312d52 ldrb pc, [r9, r0, lsl #18] */
/* @0x312d56 .word 0xf1b868e5 */
/* @0x312d5a stmvs r3!, {r1, r2, r8, r9, r10} */
/* @0x312d5e cmnmi lr, lr, ror r2 */
/* @0x312d62 bne 0xffe5c96a <b2_toiTime+0xffffffffff7034c6> */
/* @0x312d66 adcmi r1, pc, #237 */
/* @0x312d6a ldrbhi pc, [pc, #0x0]! */
/* @0x312d6e ldrtmi r4, [r9], -r0, lsr #12 */
/* @0x312d72 blx 0xffbd0d6a <b2_toiTime+0xffffffffff4778c6> */
/* @0x312d76 .word 0xf50db136 */
/* @0x312d7a .word 0x3104517c */
/* @0x312d7e ldrmi r6, [r8], #-2059 */
/* @0x312d82 and r6, r5, r8 */
/* @0x312d86 rsbspl pc, r12, #54525952 */
/* @0x312d8a ldmdavs r3, {r3, r9, r12, sp} */
/* @0x312d8e andsvs r4, r0, r8, lsl r4 */
/* @0x312d92 cmnpl r12, #54525952 */
/* @0x312d96 movwlo r4, #0x4650 */
/* @0x312d9a streq pc, [r1], -r6, lsl #1 */
/* @0x312d9e .word 0xf50d6819 */
/* @0x312da2 movwlo r5, #0x837c */
/* @0x312da6 ldmdavs r10, {r0, r8, r9, r10, r12, sp} */
/* @0x312daa .word 0xf8d3f7fe */
/* @0x312dae stmvs r2!, {r0, r1, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x312db2 stmvs r3!, {r8, r10, sp} */
/* @0x312db6 ldrsbne r1, [r11], #163 */
/* @0x312dba bls 0x6779f6 <g_SWFlinevertbuff+0x2492e> */
/* @0x312dbe .word 0x0c06f105 */
/* @0x312dc2 stmdale r2, {r2, r4, r7, r8, r10, lr} ^ */
/* @0x312dc6 strtmi r4, [r0], -r9, lsr #12 */
/* @0x312dca andsgt pc, r0, sp, asr #17 */
/* @0x312dce blx 0xff050dc6 <b2_toiTime+0xfffffffffe8f7922> */
/* @0x312dd2 cmnpl r12, sp, lsl #10 */
/* @0x312dd6 stmdavs r11, {r2, r8, r12, sp} */
/* @0x312dda stmne r3, {r0, r3, r5, r6, r10, r11, r12} ^ */
/* @0x312dde movwls r4, #0xc620 */
/* @0x312de2 blx 0xfedd0dda <b2_toiTime+0xfffffffffe677936> */
/* @0x312de6 rsbspl pc, r12, #54525952 */
/* @0x312dea andlo r1, r8, #43264 */
/* @0x312dee bl 0x32ce42 */
/* @0x312df2 strtmi r0, [r0], -r3, lsl #18 */
/* @0x312df6 blx 0xfeb50dee <b2_toiTime+0xfffffffffe3f794a> */
/* @0x312dfa stclne p15, c9, [r9], #48 */
/* @0x312dfe strtmi r4, [r0], -r7, lsl #8 */
/* @0x312e02 blx 0xfe9d0dfa <b2_toiTime+0xfffffffffe277956> */
/* @0x312e06 bl 0x31a2b2 <_Unwind_VRS_Pop+0xf6> */
/* @0x312e0a strtmi r0, [r0], -r9, lsl #6 */
/* @0x312e0e .word 0xf7fc9305 */
/* @0x312e12 vstmdbne r9!, {s31} */
/* @0x312e16 strtmi r1, [r0], -r6, asr #19 */
/* @0x312e1a blx 0xfe6d0e12 <b2_toiTime+0xfffffffffdf7796e> */
/* @0x312e1e stmdbls r12, {r0, r2, r8, r9, r11, r12, pc} */
/* @0x312e22 stm sp, {r1, r3, r6, r9, r10, lr} */
/* @0x312e26 stmne r5, {r3, r6} ^ */
/* @0x312e2a strls r4, [r2, #-0x63b] */
/* @0x312e2e .word 0xf7fe4650 */
/* @0x312e32 .word 0xf50df92c */
/* @0x312e36 .word 0xf50d537c */
/* @0x312e3a movwlo r5, #0x417c */
/* @0x312e3e andsvs r3, lr, r8, lsl #2 */
/* @0x312e42 .word 0xf8dd600d */
/* @0x312e46 uqadd16mi r12, r5, r0 */
/* @0x312e4a .word 0xf1b8e7b7 */
/* @0x312e4e .word 0xf0400f18 */
/* @0x312e52 .word 0xf50d858c */
/* @0x312e56 qsub16mi r5, r9, r12 */
/* @0x312e5a strtmi r3, [r0], -r4, lsl #6 */
/* @0x312e5e .word 0xf7fc681e */
/* @0x312e62 .word 0xf50dfa6b */
/* @0x312e66 .word 0xf50d517c */
/* @0x312e6a .word 0x3104527c */
/* @0x312e6e ldrtmi r3, [r0], #-520 */
/* @0x312e72 stclne p0, c6, [r9], #-32 */
/* @0x312e76 ldmdavs r6, {r5, r9, r10, lr} */
/* @0x312e7a blx 0x1ad0e72 <b2_toiTime+0x13779ce> */
/* @0x312e7e ldrbpl pc, [r12, #-0x50d]! */
/* @0x312e82 cmnpl r12, #54525952 */
/* @0x312e86 movwlo r3, #0x8504 */
/* @0x312e8a ldmdane r2!, {r0, r3, r5, r11, sp, lr} */
/* @0x312e8e andsvs r4, r10, r0, asr r6 */
/* @0x312e92 .word 0xf85ff7fe */
/* @0x312e96 stcllt p0, c15, [r9, #-0]! */
/* @0x312e9a ldchs p13, c9, [r0, #-44] */
/* @0x312e9e addshi pc, r12, #0, #6 */
/* @0x312ea2 stmdage r6!, {r0, r8, r10, r12, sp} */
/* @0x312ea6 .word 0xf7fa4629 */
/* @0x312eaa .word 0x9007ffd0 */
/* @0x312eae .word 0xf7fc4620 */
/* @0x312eb2 .word 0xf1b8fa09 */
/* @0x312eb6 .word 0xf04f0f1d */
/* @0x312eba .word 0xf04f0100 */
/* @0x312ebe .word 0x46060210 */
/* @0x312ec2 tstle r4, r7, lsl #16 */
/* @0x312ec6 bl 0x205055a <b2_toiTime+0x18f70b6> */
/* @0x312eca .word 0xf8d19909 */
/* @0x312ece ldrmi r3, [lr], #-708 */
/* @0x312ed2 adcslo pc, r12, #13697024 */
/* @0x312ed6 .word 0xf080429e */
/* @0x312eda .word 0xf8d1827f */
/* @0x312ede bls 0x4dfa16 <SrcVerts+0x3ca5a> */
/* @0x312ee2 eorlo pc, r6, r3, asr r8 */
/* @0x312ee6 ldrsbvs r6, [r3], #-3 */
/* @0x312eea sbclo pc, r12, #13697024 */
/* @0x312eee .word 0xf5a3e013 */
/* @0x312ef2 stmdbls r9, {r1, r2, r3, r4, r6, r8, r9, r11, sp, lr, pc} */
/* @0x312ef6 sbclo pc, r0, #13697024 */
/* @0x312efa .word 0xf8d1441e */
/* @0x312efe addsmi r3, lr, #184, #4 */
/* @0x312f02 rsbhi pc, r10, #128 */
/* @0x312f06 sbclo pc, r8, #13697024 */
/* @0x312f0a .word 0xf8539a07 */
/* @0x312f0e sbcsvs r3, r3, r6, lsr #32 */
/* @0x312f12 .word 0xf8d16053 */
/* @0x312f16 bl 0x3dfa3e <error_g0017+0x386e2> */
/* @0x312f1a ldmdavs r3!, {r1, r2, r7, r9, r10} ^ */
/* @0x312f1e addsvs r9, r3, r11, lsl #10 */
/* @0x312f22 stcls p5, c14, [r11, #-692] */
/* @0x312f26 .word 0xf0002d00 */
/* @0x312f2a stclo p2, c8, [r1, #-348] */
/* @0x312f2e strls r10, [r11, #-0x826] */
/* @0x312f32 .word 0xf7fa4629 */
/* @0x312f36 andls pc, r7, r10, lsl #31 */
/* @0x312f3a stmdals r7, {r0, r5, r7, r8, r10, sp, lr, pc} */
/* @0x312f3e .word 0xf987f7fc */
/* @0x312f42 cdpne p2, #0x4, c11, c3, c0, #0x6 */
/* @0x312f46 ldmdale r2, {r2, r5, r8, r9, r11, sp} ^ */
/* @0x312f4a .word 0xf013e8df */
/* @0x312f4e streq r0, [pc, #-0x50f] */
/* @0x312f52 subseq r0, r1, r1, asr r0 */
/* @0x312f56 streq r0, [pc, #-0x51] */
/* @0x312f5a streq r0, [pc, #-0x50f] */
/* @0x312f5e subseq r0, r1, r1, asr r0 */
/* @0x312f62 subseq r0, r1, r1, asr r0 */
/* @0x312f66 subseq r0, r1, pc, lsl #10 */
/* @0x312f6a streq r0, [pc, #-0x51] */
/* @0x312f6e subseq r0, r1, pc, lsl #10 */
/* @0x312f72 subseq r0, r1, pc, lsl #10 */
/* @0x312f76 subseq r0, r1, r1, asr r0 */
/* @0x312f7a subseq r0, r1, r1, asr r0 */
/* @0x312f7e subseq r0, r1, pc, lsl #10 */
/* @0x312f82 subseq r0, r1, r1, asr r0 */
/* @0x312f86 subseq r0, r1, r1, asr r0 */
/* @0x312f8a streq r0, [pc, #-0x50f] */
/* @0x312f8e eoreq r0, r5, pc, lsl #10 */
/* @0x312f92 eorseq r0, lr, r12, lsr #32 */
/* @0x312f96 .word 0xf8df004d */
/* @0x312f9a ldrbtmi r3, [r11], #-2616 */
/* @0x312f9e movwvs pc, #0x503 */
/* @0x312fa2 ands r9, r3, r0, lsl #6 */
/* @0x312fa6 .word 0xf50d9d23 */
/* @0x312faa .word 0xf50d517c */
/* @0x312fae qsub16mi r5, r0, r12 */
/* @0x312fb2 movweq pc, #0xc605 */
/* @0x312fb6 movwls r3, #0x104 */
/* @0x312fba movwhs r3, #0x208 */
/* @0x312fbe ldrbmi r9, [r3], -r1, lsl #6 */
/* @0x312fc2 .word 0xf8f9f7fe */
/* @0x312fc6 ldcllt p0, c15, [r1], {0} */
/* @0x312fca strls r9, [r0, #-0xd22] */
/* @0x312fce .word 0xf50d2300 */
/* @0x312fd2 .word 0xf50d517c */
/* @0x312fd6 movwls r5, #0x127c */
/* @0x312fda .word 0x31044620 */
/* @0x312fde ldrbmi r3, [r3], -r8, lsl #4 */
/* @0x312fe2 .word 0xf8e9f7fe */
/* @0x312fe6 stcls p5, c14, [r1, #-300]! */
/* @0x312fea strls r2, [r0, #-0x301] */
/* @0x312fee .word 0xf89be7ef */
/* @0x312ff2 blhs 0x31f01a */
/* @0x312ff6 ldrthi pc, [r9], #64 */
/* @0x312ffa vadd.i8 d2, d0, d21 */
/* @0x312ffe stmdalo r3, {r1, r2, r4, r5, r7, r10, pc} */
/* @0x313002 vtst.8 d2, d0, d11 */
/* @0x313006 ldm pc, {r1, r4, r5, r7, r10, pc} ^ */
/* @0x31300a andseq pc, r12, r0, lsl r0 */
/* @0x31300e eorseq r0, r4, r6, lsr #32 */
/* @0x313012 ldrteq r0, [r0], #1200 */
/* @0x313016 ldrhteq r0, [r12], -r0 */
/* @0x31301a subeq r0, sp, r4, asr #32 */
/* @0x31301e ldrteq r0, [r0], #86 */
/* @0x313022 rsbeq r0, r6, r1, rrx */
/* @0x313026 ldrteq r0, [r0], #1200 */
/* @0x31302a ldrteq r0, [r0], #115 */
/* @0x31302e addeq r0, r5, r7, ror r0 */
/* @0x313032 umlaleq r0, r6, r2, r0 */
/* @0x313036 ldrteq r0, [r0], #183 */
/* @0x31303a sbcseq r0, r5, r2, asr #1 */
/* @0x31303e .word 0x00eb00dc */
/* @0x313042 strtmi r0, [r0], -r5, lsl #2 */
/* @0x313046 .word 0xf956f7fc */
/* @0x31304a strtmi r4, [r0], -r5, lsl #12 */
/* @0x31304e .word 0xf952f7fc */
/* @0x313052 strmi r11, [r1], -r8, asr #18 */
/* @0x313056 strtmi lr, [r0], -r9, asr #32 */
/* @0x31305a .word 0xf94cf7fc */
/* @0x31305e strtmi r4, [r0], -r5, lsl #12 */
/* @0x313062 .word 0xf948f7fc */
/* @0x313066 stcne p9, c11, [r9], #-96 */
/* @0x31306a .word 0x2101bf18 */
/* @0x31306e .word 0x2101e03d */
/* @0x313072 qasxmi lr, r0, r11 */
/* @0x313076 rfedb lr! */
/* @0x31307a .word 0x0101f1d0 */
/* @0x31307e .word 0x2100bf38 */
/* @0x313082 qasxmi lr, r0, r3 */
/* @0x313086 rfedb r6! */
/* @0x31308a mvnvc lr, r0, lsl #21 */
/* @0x31308e mvnvc lr, r1, lsr #23 */
/* @0x313092 .word 0x4620e0be */
/* @0x313096 .word 0xf92ef7fc */
/* @0x31309a strtmi r4, [r0], -r5, lsl #12 */
/* @0x31309e .word 0xf92af7fc */
/* @0x3130a2 adcs r1, r5, r1, asr #18 */
/* @0x3130a6 .word 0xf7fc4620 */
/* @0x3130aa strmi pc, [r5], -r5, lsr #18 */
/* @0x3130ae .word 0xf7fc4620 */
/* @0x3130b2 blne 0x139153e <b2_toiTime+0xc3809a> */
/* @0x3130b6 strtmi lr, [r0], -r12, lsr #1 */
/* @0x3130ba .word 0xf91cf7fc */
/* @0x3130be strtmi r4, [r0], -r5, lsl #12 */
/* @0x3130c2 .word 0xf918f7fc */
/* @0x3130c6 .word 0xf7d14629 */
/* @0x3130ca .word 0xe0a0fef5 */
/* @0x3130ce .word 0xf7fc4620 */
/* @0x3130d2 submi pc, r1, #278528 */
/* @0x3130d6 qadd8mi lr, r0, r12 */
/* @0x3130da .word 0xf90cf7fc */
/* @0x3130de strtmi r4, [r0], -r5, lsl #12 */
/* @0x3130e2 .word 0xf908f7fc */
/* @0x3130e6 submi r1, r1, #64, #22 */
/* @0x3130ea strtmi r4, [r0], -r1, asr #2 */
/* @0x3130ee .word 0xbc1ef000 */
/* @0x3130f2 .word 0xf7fc4620 */
/* @0x3130f6 strb pc, [r2], #2303 */
/* @0x3130fa .word 0xf7fc4620 */
/* @0x3130fe strmi pc, [r5], -r3, ror #17 */
/* @0x313102 .word 0xf7fc4620 */
/* @0x313106 ldchs p8, c15, [pc, #-988] */
/* @0x31310a ldcge p6, c15, [r9], #252 */
/* @0x31310e .word 0xf843ab3e */
/* @0x313112 ldrt r0, [r4], #37 */
/* @0x313116 .word 0xf7fc4620 */
/* @0x31311a ldmdahs pc, {r0, r2, r4, r6, r7, r11, r12, sp, lr, pc} */
/* @0x31311e .word 0xf63f4603 */
/* @0x313122 ldcge p12, c10, [lr, #-696]! */
/* @0x313126 .word 0xf8554620 */
/* @0x31312a .word 0xf0001023 */
/* @0x31312e qadd16mi r11, r0, r10 */
/* @0x313132 .word 0xf8e0f7fc */
/* @0x313136 strtmi r4, [r0], -r6, lsl #12 */
/* @0x31313a .word 0xf8dcf7fc */
/* @0x31313e strtmi r4, [r0], -r7, lsl #12 */
/* @0x313142 .word 0xf8d8f7fc */
/* @0x313146 strtmi r4, [r0], -r5, lsl #12 */
/* @0x31314a .word 0xf8d4f7fc */
/* @0x31314e svclt #0xcc42b7 */
/* @0x313152 strmi r4, [r1], -r9, lsr #12 */
/* @0x313156 stcls p0, c14, [r9, #-368] */
/* @0x31315a .word 0xf8d54620 */
/* @0x31315e .word 0xf8d332e0 */
/* @0x313162 b 0xfe357b8a <b2_toiTime+0xfffffffffdbfe6e6> */
/* @0x313166 addlt r3, r9, #268435460 */
/* @0x31316a b 0xfe39f576 <b2_toiTime+0xfffffffffdc460d2> */
/* @0x31316e b 0xfe3a3abe <b2_toiTime+0xfffffffffdc4a61a> */
/* @0x313172 .word 0xf8c31242 */
/* @0x313176 .word 0xe3f42288 */
/* @0x31317a .word 0xf7fc4620 */
/* @0x31317e .word 0x4605f8bb */
/* @0x313182 .word 0xf7fc4620 */
/* @0x313186 .word 0x4629f8b7 */
/* @0x31318a mrc2 p7, #0x0, apsr_nzcv, c3, c10, #0x7 */
/* @0x31318e qasxmi lr, r0, pc */
/* @0x313192 rfeia r0! */
/* @0x313196 stcle p14, c1, [r11, #-24] */
/* @0x31319a qasxmi r4, r9, r5 */
/* @0x31319e .word 0xf7d14630 */
/* @0x3131a2 strtmi pc, [r8], #-3721 */
/* @0x3131a6 subne r1, r9, r1, asr #24 */
/* @0x3131aa eorsle r4, r1, r9, lsr #5 */
/* @0x3131ae ldrb r4, [r4, sp, lsl #12]! */
/* @0x3131b2 eor r2, sp, r0, lsl #2 */
/* @0x3131b6 .word 0xf7fc4620 */
/* @0x3131ba .word 0x4605f89d */
/* @0x3131be strtmi r4, [r9], -r0, lsr #12 */
/* @0x3131c2 strtmi lr, [r0], -r9 */
/* @0x3131c6 .word 0xf896f7fc */
/* @0x3131ca strtmi r4, [r0], -r6, lsl #12 */
/* @0x3131ce .word 0xf892f7fc */
/* @0x3131d2 .word 0x46054631 */
/* @0x3131d6 .word 0xf7fc4620 */
/* @0x3131da qsaxmi pc, r0, pc */
/* @0x3131de bic r4, r0, #42991616 */
/* @0x3131e2 .word 0xf7fc4620 */
/* @0x3131e6 stmvs r1!, {r0, r1, r2, r3, r5, r6, r11, r12, sp, lr, pc} ^ */
/* @0x3131ea bne 0xff56d47e <b2_toiTime+0xfffffffffee13fda> */
/* @0x3131ee .word 0xf43f10c9 */
/* @0x3131f2 stmdahs r0, {r1, r2, r6, r10, r11, sp, pc} */
/* @0x3131f6 stmdblo r1, {r0, r9, r11, r12, lr, pc} */
/* @0x3131fa addmi lr, r8, #6 */
/* @0x3131fe .word 0xf101bf3a */
/* @0x313202 bl 0xff31fa06 <b2_toiTime+0xfffffffffebc6562> */
/* @0x313206 .word 0x21000101 */
/* @0x31320a .word 0xf7fc4620 */
/* @0x31320e .word 0x4601f895 */
/* @0x313212 .word 0xe3a64620 */
/* @0x313216 .word 0xf7fc4620 */
/* @0x31321a .word 0x4606f855 */
/* @0x31321e .word 0xf7fc4620 */
/* @0x313222 stmdahs r1, {r0, r4, r6, r11, r12, sp, lr, pc} */
/* @0x313226 .word 0xf77f4605 */
/* @0x31322a stmvs r2!, {r1, r3, r5, r10, r11, sp, pc} ^ */
/* @0x31322e bne 0xff7ed4c2 <b2_toiTime+0xffffffffff09401e> */
/* @0x313232 svceq #0xe3ebb0 */
/* @0x313236 stmdavs r0!, {r2, r8, r11, r12, lr, pc} ^ */
/* @0x31323a .word 0xf7fa2182 */
/* @0x31323e ldr pc, [lr], #-3585 */
/* @0x313242 ble 0x45ea4a <g_RomDisk+0x6722a> */
/* @0x313246 qsub16mi r4, r9, r0 */
/* @0x31324a ldcl p0, c15, [r0, #20] */
/* @0x31324e and r4, r3, r9, asr #4 */
/* @0x313252 qasxmi r4, r9, r0 */
/* @0x313256 stcl p0, c15, [r10, #20] */
/* @0x31325a .word 0xf43f2900 */
/* @0x31325e andhs r10, r0, r0, lsl r12 */
/* @0x313262 .word 0x33fff04f */
/* @0x313266 strmi r2, [r7], -r2, lsl #12 */
/* @0x31326a ldrmi r4, [lr, #0x69e] */
/* @0x31326e smlatble r7, r2, r8, r6 */
/* @0x313272 movweq pc, #0x110e */
/* @0x313276 strbeq lr, [r3], r2, lsl #22 */
/* @0x31327a eorseq pc, r3, r2, asr r8 */
/* @0x31327e ldmdavs r6!, {r1, r2, r3, r4, r7, r9, r10, lr} ^ */
/* @0x313282 adcmi r4, r11, #184549376 */
/* @0x313286 blne 0x1a09e92 <b2_toiTime+0x12b09ee> */
/* @0x31328a blhs 0x34b29a */
/* @0x31328e ldmdbne r11, {r3, r4, r5, r7, r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x313292 bl 0x3a0e9e <af_latn_uniranges+0xea> */
/* @0x313296 adcmi r0, pc, #49920 */
/* @0x31329a eorshi pc, r3, r2, asr r8 */
/* @0x31329e .word 0x9004f8dc */
/* @0x3132a2 eorseq pc, r3, r2, asr #16 */
/* @0x3132a6 andvs pc, r4, r12, asr #17 */
/* @0x3132aa blge 0xffd903ae <b2_toiTime+0xffffffffff636f0a> */
/* @0x3132ae strbmi r4, [r0], -lr, asr #12 */
/* @0x3132b2 stmvs r2!, {r0, r1, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x3132b6 bne 0xff7ed54a <b2_toiTime+0xffffffffff0940a6> */
/* @0x3132ba .word 0xf02310db */
/* @0x3132be blhs 0x353ed6 */
/* @0x3132c2 .word 0xf89dd109 */
/* @0x3132c6 ldmdblt r1!, {r0, r1, r4, r7, r12} */
/* @0x3132ca .word 0xf7fc4620 */
/* @0x3132ce ldcls p8, c15, [r6, #-212] */
/* @0x3132d2 ldcls p4, c4, [r0, #-160] */
/* @0x3132d6 movwhs r6, #0x1028 */
/* @0x3132da addslo pc, r3, sp, lsl #17 */
/* @0x3132de ldrsbtlo pc, [r0], r11 */
/* @0x3132e2 eorslo pc, r1, #9633792 */
/* @0x3132e6 .word 0xf47f2b00 */
/* @0x3132ea .word 0xf50aabd9 */
/* @0x3132ee .word 0x7c1b5336 */
/* @0x3132f2 uadd16mi r11, r0, r3 */
/* @0x3132f6 mcr2 p7, #0x5, pc, c6, c13, #0x7 */
/* @0x3132fa mullo r8, r11, r8 */
/* @0x3132fe .word 0xf47f2b00 */
/* @0x313302 stmvs r2!, {r0, r2, r3, r6, r7, r8, r9, r11, sp, pc} ^ */
/* @0x313306 bne 0xff7ed59a <b2_toiTime+0xffffffffff0940f6> */
/* @0x31330a .word 0xf67f2b0f */
/* @0x31330e vldrls d10, [r11, #-796] */
/* @0x313312 .word 0xd1612d00 */
/* @0x313316 cdpge p6, #0x6, c4, c6, c0, #0x1 */
/* @0x31331a .word 0xffd4f7fb */
/* @0x31331e strtmi r4, [r0], -r5, lsl #12 */
/* @0x313322 .word 0xffd0f7fb */
/* @0x313326 strtmi r4, [r0], -r7, lsl #12 */
/* @0x31332a .word 0xffe4f7fb */
/* @0x31332e cmnpl r12, sp, lsl #10 */
/* @0x313332 andvs r3, r8, r8, lsl #2 */
/* @0x313336 .word 0xf7fb4620 */
/* @0x31333a .word 0xf50dffdd */
/* @0x31333e andlo r5, r4, #124, #4 */
/* @0x313342 andsvs r4, r0, r9, lsr #12 */
/* @0x313346 stmdals r9, {r1, r2, r3, r4, r6, r9, r11, sp, pc} */
/* @0x31334a blx 0x1f91342 <b2_toiTime+0x1837e9e> */
/* @0x31334e stmdahs r0, {r0, r2, r9, r10, lr} */
/* @0x313352 tsthi r0, #64 */
/* @0x313356 ldrbpl pc, [r12, #-0x50d]! */
/* @0x31335a cmnpl r12, sp, lsl #10 */
/* @0x31335e .word 0xf04f3504 */
/* @0x313362 .word 0xf8cd0901 */
/* @0x313366 .word 0x31089000 */
/* @0x31336a ldrbmi r6, [r8], -r11, lsr #16 */
/* @0x31336e .word 0xf10d9a1a */
/* @0x313372 mrrcge p8, #0x9, r0, pc, c4 */
/* @0x313376 stmdavs r11, {r0, r8, r9, r12, pc} */
/* @0x31337a .word 0xf8cda95e */
/* @0x31337e movwls r8, #0x200c */
/* @0x313382 .word 0xf7ff9b17 */
/* @0x313386 stcls p9, c15, [r9, #-896] */
/* @0x31338a .word 0x3c1cf856 */
/* @0x31338e .word 0xf8564621 */
/* @0x313392 stmdavs r8!, {r3, r4, r10, r11, sp} ^ */
/* @0x313396 .word 0xf7fd1ad2 */
/* @0x31339a stmdals r9, {r2, r3, r5, r6, r9, r11, r12, sp, lr, pc} */
/* @0x31339e bge 0x1aa4c8a <b2_toiTime+0x134b7e6> */
/* @0x3133a2 blx 0x149139a <b2_toiTime+0xd37ef6> */
/* @0x3133a6 stmdahs r0, {r0, r2, r9, r10, lr} */
/* @0x3133aa rschi pc, r4, #64 */
/* @0x3133ae uadd16mi r9, r8, r11 */
/* @0x3133b2 blls 0x8f9c22 <b2_toiTime+0x1a077e> */
/* @0x3133b6 .word 0x91029101 */
/* @0x3133ba .word 0xf8cda95e */
/* @0x3133be .word 0xf8cd9000 */
/* @0x3133c2 .word 0xf7ff800c */
/* @0x3133c6 stmdbls r9, {r6, r7, r8, r11, r12, sp, lr, pc} */
/* @0x3133ca blls 0x1af9d52 <b2_toiTime+0x13a08ae> */
/* @0x3133ce strtmi r6, [r1], -r8, asr #16 */
/* @0x3133d2 .word 0xf7fd1ad2 */
/* @0x3133d6 sbc pc, sp, #319488 */
/* @0x3133da sbc r2, r11, #75497472 */
/* @0x3133de stmvs r3!, {r1, r5, r6, r7, r11, sp, lr} */
/* @0x3133e2 blhs 0x6d9f36 <g_SWFvertbuff+0x6e6e> */
/* @0x3133e6 .word 0xf50dd906 */
/* @0x3133ea eorlo r5, r0, #-1610612729 */
/* @0x3133ee blhs 0x331442 */
/* @0x3133f2 adcshi pc, r11, #64 */
/* @0x3133f6 .word 0xf10dad36 */
/* @0x3133fa .word 0xf10b0393 */
/* @0x3133fe movwls r0, #0xb0 */
/* @0x313402 blls 0x724c8e <g_SWFvertbuff+0x51bc6> */
/* @0x313406 .word 0xf7fc462a */
/* @0x31340a .word 0xf8dbffde */
/* @0x31340e .word 0xf89330b0 */
/* @0x313412 svchs #0x7231 */
/* @0x313416 blge 0x13d061a <b2_toiTime+0xc77176> */
/* @0x31341a svceq #0x13f1b8 */
/* @0x31341e stmdbvs r10!, {r0, r3, r8, r12, lr, pc} ^ */
/* @0x313422 rsbspl pc, r10, sp, lsl #10 */
/* @0x313426 andslo r9, r12, r3, lsr r11 */
/* @0x31342a ldrmi r9, [r10], #-2311 */
/* @0x31342e .word 0xf973f7fd */
/* @0x313432 shadd8mi lr, r9, r11 */
/* @0x313436 .word 0xf640a85e */
/* @0x31343a .word 0xf50d721c */
/* @0x31343e .word 0xf5a3587a */
/* @0x313442 .word 0xf89be8b6 */
/* @0x313446 bls 0x81f72e <b2_toiTime+0xc628a> */
/* @0x31344a ldmdaeq r8!, {r3, r8, r12, sp, lr, pc} */
/* @0x31344e .word 0xf8cd4639 */
/* @0x313452 .word 0xf88db178 */
/* @0x313456 strbmi r3, [r0], -r5, lsl #3 */
/* @0x31345a .word 0xf50a9262 */
/* @0x31345e andshs r5, r12, #-939524093 */
/* @0x313462 .word 0xf50a935f */
/* @0x313466 tstlo r12, #-738197504 */
/* @0x31346a .word 0xf5a39360 */
/* @0x31346e blls 0x70d6f6 <g_SWFvertbuff+0x3a62e> */
/* @0x313472 cmnpl r10, sp, lsl #10 */
/* @0x313476 bls 0xfeda36 <b2_toiTime+0x894592> */
/* @0x31347a .word 0x46403138 */
/* @0x31347e ldrtmi r6, [r2], #-11 */
/* @0x313482 .word 0xf7fd9907 */
/* @0x313486 strls pc, [r0, -r8, asr #18] */
/* @0x31348a ldmdage lr, {r0, r8, r9, r10, r12, pc} ^ */
/* @0x31348e strtmi r10, [r10], -lr, lsr #18 */
/* @0x313492 .word 0xf7fd4643 */
/* @0x313496 rsb pc, r8, #8, #20 */
/* @0x31349a stmvs r3!, {r1, r5, r6, r7, r11, sp, lr} */
/* @0x31349e blhs 0x8d9ff2 <b2_toiTime+0x180b4e> */
/* @0x3134a2 .word 0xf89dd909 */
/* @0x3134a6 ldmdblt r1!, {r0, r1, r4, r7, r12} */
/* @0x3134aa .word 0xf7fb4620 */
/* @0x3134ae ldcls p15, c15, [r6, #-276] */
/* @0x3134b2 ldcls p4, c4, [r0, #-160] */
/* @0x3134b6 movwhs r6, #0x1028 */
/* @0x3134ba addslo pc, r3, sp, lsl #17 */
/* @0x3134be ldrsbtlo pc, [r0], r11 */
/* @0x3134c2 eorslo pc, r1, #9633792 */
/* @0x3134c6 .word 0xf47f2b00 */
/* @0x3134ca .word 0xf50daae9 */
/* @0x3134ce qsub16mi r5, r0, r12 */
/* @0x3134d2 stmdavs sp, {r3, r8, r12, sp} */
/* @0x3134d6 .word 0xff0ef7fb */
/* @0x3134da rsbspl pc, r12, #54525952 */
/* @0x3134de cmnpl r12, #54525952 */
/* @0x3134e2 movwlo r3, #0x4208 */
/* @0x3134e6 andsvs r4, r0, r8, lsr #8 */
/* @0x3134ea ldmdavs sp, {r5, r9, r10, lr} */
/* @0x3134ee .word 0xff02f7fb */
/* @0x3134f2 .word 0xf50d1829 */
/* @0x3134f6 strlo r5, [r4, #-0x57c] */
/* @0x3134fa eor r6, r4, r9, lsr #32 */
/* @0x3134fe stmvs r3!, {r1, r5, r6, r7, r11, sp, lr} */
/* @0x313502 blhs 0x6da056 <g_SWFvertbuff+0x6f8e> */
/* @0x313506 .word 0xf89dd909 */
/* @0x31350a ldmdblt r1!, {r0, r1, r4, r7, r12} */
/* @0x31350e .word 0xf7fb4620 */
/* @0x313512 ldcls p15, c15, [r6, #-76] */
/* @0x313516 ldcls p4, c4, [r0, #-160] */
/* @0x31351a movwhs r6, #0x1028 */
/* @0x31351e addslo pc, r3, sp, lsl #17 */
/* @0x313522 ldrsbtlo pc, [r0], r11 */
/* @0x313526 eorslo pc, r1, #9633792 */
/* @0x31352a .word 0xf47f2b00 */
/* @0x31352e .word 0xf50daab7 */
/* @0x313532 qsub16mi r5, r0, r12 */
/* @0x313536 stmdavs sp, {r2, r8, r12, sp} */
/* @0x31353a mrc2 p7, #0x6, apsr_nzcv, c12, c11, #0x7 */
/* @0x31353e rsbspl pc, r12, #54525952 */
/* @0x313542 stmdane r9!, {r2, r9, r12, sp} */
/* @0x313546 .word 0xf50d6011 */
/* @0x31354a usub16mi r5, r0, r12 */
/* @0x31354e ldmdavs r10, {r3, r8, r9, r12, sp} */
/* @0x313552 ldc2 p7, c15, [pc], {253} */
/* @0x313556 stmvs r6!, {r0, r3, r9, sp, lr, pc} ^ */
/* @0x31355a stmvs r3!, {r8, r10, sp} */
/* @0x31355e ldrshtne r1, [r6], #166 */
/* @0x313562 adcsmi r1, r3, #10944 */
/* @0x313566 .word 0xf50dd222 */
/* @0x31356a qsub16mi r5, r0, r12 */
/* @0x31356e stmdavs pc, {r2, r8, r12, sp} */
/* @0x313572 .word 0xf7fb4629 */
/* @0x313576 .word 0xf50dfee1 */
/* @0x31357a andlo r5, r4, #124, #4 */
/* @0x31357e cmnpl r12, #54525952 */
/* @0x313582 stclne p3, c3, [r9], #-32 */
/* @0x313586 ldrtmi r3, [r8], #-1282 */
/* @0x31358a qadd16mi r6, r0, r0 */
/* @0x31358e .word 0xf7fb681f */
/* @0x313592 .word 0xf50dfed3 */
/* @0x313596 .word 0xf50d517c */
/* @0x31359a .word 0x3108537c */
/* @0x31359e ldmdane r10!, {r2, r8, r9, r12, sp} */
/* @0x3135a2 andvs r4, r10, r0, asr r6 */
/* @0x3135a6 .word 0xf7fd6819 */
/* @0x3135aa .word 0xe7d9fcd4 */
/* @0x3135ae .word 0xf08042b5 */
/* @0x3135b2 .word 0x462981dc */
/* @0x3135b6 .word 0xf7fb4620 */
/* @0x3135ba .word 0xf50dfebf */
/* @0x3135be .word 0x3104517c */
/* @0x3135c2 stclne p8, c6, [r9], #-44 */
/* @0x3135c6 strtmi r1, [r0], -r3, asr #17 */
/* @0x3135ca .word 0xf7fb930c */
/* @0x3135ce .word 0xf50dfeb5 */
/* @0x3135d2 stcne p2, c5, [r9], #496 */
/* @0x3135d6 ldmdavs r3, {r3, r9, r12, sp} */
/* @0x3135da stmdbeq r3, {r8, r9, r11, sp, lr, pc} */
/* @0x3135de .word 0xf7fb4620 */
/* @0x3135e2 .word 0xf8ddfeab */
/* @0x3135e6 stclne p0, c8, [r9], #192 */
/* @0x3135ea strtmi r4, [r0], -r0, lsl #9 */
/* @0x3135ee mcr2 p7, #0x5, pc, c4, c11, #0x7 */
/* @0x3135f2 bl 0x31aa9e <__gnu_unwind_execute+0x362> */
/* @0x3135f6 strtmi r0, [r0], -r9, lsl #6 */
/* @0x3135fa .word 0xf7fb9305 */
/* @0x3135fe stclne p14, c15, [r9, #-628]! */
/* @0x313602 bl 0x320a22 */
/* @0x313606 strtmi r0, [r0], -r8, lsl #14 */
/* @0x31360a mrc2 p7, #0x4, apsr_nzcv, c6, c11, #0x7 */
/* @0x31360e stmdbls r12, {r0, r2, r8, r9, r11, r12, pc} */
/* @0x313612 bl 0x324f42 */
/* @0x313616 ldrbmi r0, [r0], -r3, lsl #24 */
/* @0x31361a addne lr, r8, sp, lsl #17 */
/* @0x31361e .word 0xf8cd4643 */
/* @0x313622 .word 0xf7fdc010 */
/* @0x313626 .word 0xf50dfd32 */
/* @0x31362a .word 0xf50d537c */
/* @0x31362e movwlo r5, #0x417c */
/* @0x313632 andsvs r3, pc, r8, lsl #2 */
/* @0x313636 ldrsbgt pc, [r0], -sp */
/* @0x31363a andgt pc, r0, r1, asr #17 */
/* @0x31363e stmvs r5!, {r1, r2, r4, r5, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x313642 bne 0xffe6d8d6 <b2_toiTime+0xffffffffff714432> */
/* @0x313646 .word 0xf02510ed */
/* @0x31364a blne 0xffe5525a <b2_toiTime+0xffffffffff6fbdb6> */
/* @0x31364e .word 0xf08042bd */
/* @0x313652 blne 0x21f3c8a <b2_toiTime+0x1a9a7e6> */
/* @0x313656 strle r0, [r11, #-0x7d9] */
/* @0x31365a strtmi r4, [r0], -r9, lsr #12 */
/* @0x31365e mcr2 p7, #0x3, pc, c12, c11, #0x7 */
/* @0x313662 rsbspl pc, r12, #54525952 */
/* @0x313666 strlo r3, [r1, #-0x204] */
/* @0x31366a bl 0x32d6be */
/* @0x31366e and r0, r4, r3, lsl #18 */
/* @0x313672 cmnpl r12, #54525952 */
/* @0x313676 .word 0xf8d33304 */
/* @0x31367a strtmi r9, [r9], -r0 */
/* @0x31367e .word 0xf7fb4620 */
/* @0x313682 .word 0xf50dfe5b */
/* @0x313686 .word 0x3108517c */
/* @0x31368a stclne p8, c6, [r9], #-44 */
/* @0x31368e stmdaeq r3, {r8, r9, r11, sp, lr, pc} */
/* @0x313692 .word 0xf7fb4620 */
/* @0x313696 stcne p14, c15, [r9], #324 */
/* @0x31369a streq lr, [r9], -r0, lsl #22 */
/* @0x31369e .word 0xf7fb4620 */
/* @0x3136a2 stclne p14, c15, [r9], #300 */
/* @0x3136a6 bl 0x320abe */
/* @0x3136aa strtmi r0, [r0], -r8, lsl #6 */
/* @0x3136ae .word 0xf7fb9305 */
/* @0x3136b2 blls 0x492fc6 <g_prim_v+0x2fba> */
/* @0x3136b6 strbmi r4, [r9], -r2, asr #12 */
/* @0x3136ba .word 0x0c03eb00 */
/* @0x3136be stm sp, {r4, r6, r9, r10, lr} */
/* @0x3136c2 ldrtmi r1, [r3], -r8, asr #32 */
/* @0x3136c6 andsgt pc, r0, sp, asr #17 */
/* @0x3136ca ldc2l p7, c15, [pc], {253} */
/* @0x3136ce rsbspl pc, r12, #54525952 */
/* @0x3136d2 cmnpl r12, #54525952 */
/* @0x3136d6 movwlo r3, #0x8204 */
/* @0x3136da .word 0xf8dd6016 */
/* @0x3136de .word 0xf8c3c010 */
/* @0x3136e2 ldr r12, [r3, r0]! */
/* @0x3136e6 stmvs r3!, {r0, r2, r5, r6, r7, r11, sp, lr} */
/* @0x3136ea rscne r1, sp, sp, ror #21 */
/* @0x3136ee streq pc, [r2, -r5, lsr #32] */
/* @0x3136f2 adcsmi r1, sp, #242688 */
/* @0x3136f6 teqhi r9, r0, lsl #1 */
/* @0x3136fa .word 0x07da1b7b */
/* @0x3136fe strtmi sp, [r9], -r11, lsl #10 */
/* @0x313702 .word 0xf7fb4620 */
/* @0x313706 .word 0xf50dfe19 */
/* @0x31370a .word 0x3108517c */
/* @0x31370e stmdavs r11, {r0, r8, r10, r12, sp} */
/* @0x313712 stmdbeq r3, {r8, r9, r11, sp, lr, pc} */
/* @0x313716 .word 0xf50de004 */
/* @0x31371a andlo r5, r8, #124, #4 */
/* @0x31371e .word 0x9000f8d2 */
/* @0x313722 strtmi r4, [r0], -r9, lsr #12 */
/* @0x313726 mcr2 p7, #0x0, pc, c8, c11, #0x7 */
/* @0x31372a cmnpl r12, sp, lsl #10 */
/* @0x31372e stmdavs r11, {r2, r8, r12, sp} */
/* @0x313732 bl 0x31a8de <__gnu_unwind_execute+0x1a2> */
/* @0x313736 strtmi r0, [r0], -r3, lsl #16 */
/* @0x31373a ldc2l p7, c15, [lr, #1004]! */
/* @0x31373e bl 0x31a9ea <__gnu_unwind_execute+0x2ae> */
/* @0x313742 strtmi r0, [r0], -r8, lsl #6 */
/* @0x313746 .word 0xf7fb9305 */
/* @0x31374a stclne p13, c15, [r9], #988 */
/* @0x31374e bl 0x320b66 */
/* @0x313752 strtmi r0, [r0], -r9, lsl #12 */
/* @0x313756 ldc2l p7, c15, [r0, #1004]! */
/* @0x31375a strbmi r9, [r10], -r5, lsl #22 */
/* @0x31375e strbmi r9, [r1], -r2, lsl #12 */
/* @0x313762 .word 0x0c03eb00 */
/* @0x313766 stm sp, {r4, r6, r9, r10, lr} */
/* @0x31376a .word 0xf8cd1040 */
/* @0x31376e .word 0xf7fdc010 */
/* @0x313772 .word 0xf8ddfc8c */
/* @0x313776 .word 0xf50dc010 */
/* @0x31377a .word 0xf50d527c */
/* @0x31377e andlo r5, r4, #124, #6 */
/* @0x313782 .word 0xf8c23308 */
/* @0x313786 andsvs r12, lr, r0 */
/* @0x31378a stmvs r3!, {r0, r1, r4, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x31378e bne 0xffe6db2a <b2_toiTime+0xffffffffff714686> */
/* @0x313792 tsteq pc, #184, #2 */
/* @0x313796 stmdaeq r0, {r0, r1, r4, r6, r7, r8, r12, sp, lr, pc} */
/* @0x31379a strbeq lr, [r5, #0xa4f]! */
/* @0x31379e stmdaeq r3, {r3, r4, r6, r8, r9, r11, sp, lr, pc} */
/* @0x3137a2 .word 0x0102f025 */
/* @0x3137a6 bne 0x1e77c0e <b2_toiTime+0x171e76a> */
/* @0x3137aa addmi r9, sp, #24, #18 */
/* @0x3137ae sbcshi pc, sp, r0, lsl #1 */
/* @0x3137b2 vstmiane r10!, {d25, d26, d27, d28, d29, d30, d31} */
/* @0x3137b6 stmdbeq r1, {r0, r2, r8, r12, sp, lr, pc} */
/* @0x3137ba blne 0x19f7ffa <b2_toiTime+0x129eb56> */
/* @0x3137be stcne p13, c1, [pc], #168 */
/* @0x3137c2 andsls r9, pc, #2013265920 */
/* @0x3137c6 svceq #0xf1b8 */
/* @0x3137ca strtmi sp, [r9], -r11, lsr #32 */
/* @0x3137ce .word 0xf7fb4620 */
/* @0x3137d2 .word 0xf50dfdb3 */
/* @0x3137d6 .word 0xf50d517c */
/* @0x3137da .word 0x3104527c */
/* @0x3137de stmdavs r11, {r3, r9, r12, sp} */
/* @0x3137e2 ldmdavs r2, {r0, r3, r6, r9, r10, lr} */
/* @0x3137e6 stmne r3, {r0, r2, r3, r9, r12, pc} ^ */
/* @0x3137ea movwls r4, #0xc620 */
/* @0x3137ee stc2 p7, c15, [r4, #1004]! */
/* @0x3137f2 ldrtmi r9, [r9], -r12, lsl #28 */
/* @0x3137f6 strtmi r4, [r0], -r6, lsl #8 */
/* @0x3137fa ldc2 p7, c15, [lr, #1004] */
/* @0x3137fe stmdbls lr, {r0, r2, r3, r8, r9, r10, r11, r12, pc} */
/* @0x313802 strtmi r4, [r0], -r7, lsl #8 */
/* @0x313806 ldc2 p7, c15, [r8, #1004] */
/* @0x31380a blhs 0x47a48a <_ZN2VM13m_breakpointsE+0x256> */
/* @0x31380e andls r4, lr, r8, lsr r4 */
/* @0x313812 qasxmi sp, r0, r9 */
/* @0x313816 .word 0xf7fb991f */
/* @0x31381a strbmi pc, [sp], -pc, lsl #27 */
/* @0x31381e .word 0x0c06eb00 */
/* @0x313822 .word 0xf50de032 */
/* @0x313826 qsub16mi r5, r9, r12 */
/* @0x31382a strtmi r3, [r0], -r4, lsl #4 */
/* @0x31382e andls r6, r12, #1179648 */
/* @0x313832 stc2 p7, c15, [r2, #1004] */
/* @0x313836 cmnpl r12, sp, lsl #10 */
/* @0x31383a stmdavs r11, {r3, r8, r12, sp} */
/* @0x31383e stmne r3, {r0, r3, r6, r9, r10, lr} ^ */
/* @0x313842 movwls r4, #0xd620 */
/* @0x313846 ldc2l p7, c15, [r8, #-1004]! */
/* @0x31384a ldrtmi r9, [r9], -r12, lsl #28 */
/* @0x31384e strtmi r4, [r0], -r6, lsl #8 */
/* @0x313852 ldc2l p7, c15, [r2, #-1004]! */
/* @0x313856 stmdbls lr, {r0, r2, r3, r8, r9, r10, r11, r12, pc} */
/* @0x31385a strtmi r4, [r0], -r7, lsl #8 */
/* @0x31385e stc2l p7, c15, [r12, #-1004]! */
/* @0x313862 bhs 0x47a0e2 <szLine+0x3ce> */
/* @0x313866 .word 0x0c06eb00 */
/* @0x31386a qadd16mi sp, r0, r1 */
/* @0x31386e .word 0xf8cd991f */
/* @0x313872 .word 0xf7fbc010 */
/* @0x313876 strbmi pc, [sp], -r1, ror #26 */
/* @0x31387a stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x31387e ldrsbgt pc, [r0], -sp */
/* @0x313882 andls r4, lr, r8, lsr r4 */
/* @0x313886 ldrtmi lr, [r4], r6 */
/* @0x31388a stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x31388e .word 0xf04fe002 */
/* @0x313892 strls r0, [lr, -r1, lsl #16] */
/* @0x313896 ldrbmi r9, [r0], -lr, lsl #22 */
/* @0x31389a addne lr, r0, sp, lsl #17 */
/* @0x31389e stmdbls r12, {r2, r8, r10, r12, sp} */
/* @0x3138a2 ldrtmi r9, [r3], -r2, lsl #6 */
/* @0x3138a6 .word 0xf8cd9a0d */
/* @0x3138aa .word 0xf7fdc010 */
/* @0x3138ae .word 0xf8ddfbee */
/* @0x3138b2 .word 0xf50dc010 */
/* @0x3138b6 .word 0xf50d517c */
/* @0x3138ba bls 0x6a86b2 <g_SWFlinevertbuff+0x555ea> */
/* @0x3138be movwlo r3, #0x8104 */
/* @0x3138c2 andgt pc, r0, r1, asr #17 */
/* @0x3138c6 .word 0xe76f601a */
/* @0x3138ca .word 0xf7fb9807 */
/* @0x3138ce strmi pc, [r5], -r0, asr #25 */
/* @0x3138d2 .word 0xf7fb9807 */
/* @0x3138d6 b 0x1352bce <b2_toiTime+0xbf972a> */
/* @0x3138da strtmi r2, [r0], -r5, lsl #2 */
/* @0x3138de eor r11, r5, r9, lsl #4 */
/* @0x3138e2 svceq #0xf6f1b8 */
/* @0x3138e6 strtmi sp, [r0], -r3, lsl #16 */
/* @0x3138ea orreq pc, r11, r8, lsr #3 */
/* @0x3138ee .word 0xf1b8e01e */
/* @0x3138f2 stmdale r11, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11} */
/* @0x3138f6 .word 0xf1a89807 */
/* @0x3138fa .word 0xf7fb08f7 */
/* @0x3138fe b 0x1712ba6 <b2_toiTime+0xfb9702> */
/* @0x313902 bl 0x51d92a <SrcVerts+0x7a96e> */
/* @0x313906 strtmi r0, [r0], -r0, lsl #2 */
/* @0x31390a and r3, pc, r12, ror #2 */
/* @0x31390e svceq #0xfff1b8 */
/* @0x313912 stmdals r7, {r4, r12, lr, pc} */
/* @0x313916 ldmeq r11!, {r3, r5, r7, r8, r12, sp, lr, pc} ^ */
/* @0x31391a ldc2 p7, c15, [r9], {251} */
/* @0x31391e .word 0x016bf06f */
/* @0x313922 stmdahs r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x313926 strtmi r4, [r0], -r0, lsl #9 */
/* @0x31392a smlabteq r1, r8, r11, lr */
/* @0x31392e ldc2 p7, c15, [lr], {251} */
/* @0x313932 stmlt r5!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc} */
/* @0x313936 .word 0xf7fb9807 */
/* @0x31393a strmi pc, [r6], -r10, lsl #25 */
/* @0x31393e .word 0xf7fb9807 */
/* @0x313942 strmi pc, [r7], -r6, lsl #25 */
/* @0x313946 .word 0xf7fb9807 */
/* @0x31394a ldrteq pc, [pc], #-3202 */
/* @0x31394e strvs lr, [r6], -r7, asr #20 */
/* @0x313952 stmdals r7, {r0, r2, r9, r10, lr} */
/* @0x313956 ldc2l p7, c15, [r11], #-1004 */
/* @0x31395a .word 0x0100ea46 */
/* @0x31395e b 0x13651e6 <b2_toiTime+0xc0bd42> */
/* @0x313962 .word 0xf7fb2105 */
/* @0x313966 .word 0xf7fffc99 */
/* @0x31396a stmvs r3!, {r1, r3, r7, r11, r12, sp, pc} */
/* @0x31396e .word 0xf7ff60e3 */
/* @0x313972 strbhs r11, [r0, #-0x886] */
/* @0x313976 stmdals pc, {r0, r3, r5, r9, r10, lr} */
/* @0x31397a blx 0x1bd196a <b2_toiTime+0x14784c6> */
/* @0x31397e eorspl pc, r5, r10, lsl #10 */
/* @0x313982 .word 0xf7fa301c */
/* @0x313986 ldmdage r6!, {r1, r2, r6, r7, r8, r9, r11, r12, sp, lr, pc} */
/* @0x31398a blx 0xff41197c <b2_toiTime+0xfffffffffecb84d8> */
/* @0x31398e .word 0xf7faa82e */
/* @0x313992 stmdage r6!, {r6, r7, r8, r9, r11, r12, sp, lr, pc} */
/* @0x313996 blx 0xff291988 <b2_toiTime+0xfffffffffeb384e4> */
/* @0x31399a cmplt r5, r2, lsl sp */
/* @0x31399e stmvs r9!, {r2, r3, r5, r11, sp, lr} */
/* @0x3139a2 .word 0xf7d34620 */
/* @0x3139a6 movwhs pc, #0xcc7 */
/* @0x3139aa adcvs r4, r11, r0, lsr #12 */
/* @0x3139ae .word 0xf7d39912 */
/* @0x3139b2 .word 0xf50dfcc1 */
/* @0x3139b6 stcls p1, c5, [r0, #-492]! */
/* @0x3139ba stmdavs r10, {r2, r4, r8, r12, sp} */
/* @0x3139be addsmi r6, r10, #2818048 */
/* @0x3139c2 .word 0xf5a2d001 */
/* @0x3139c6 .word 0xf50dee06 */
/* @0x3139ca andlt r5, r7, r11, ror sp */
/* @0x3139ce svchi #0xf0e8bd */
/* @0x3139d2 ldmdaeq r12!, {r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x3139d6 push {r0, r3} */
/* @0x3139da ldrshlt r4, [r11], r0 */
/* @0x3139de strmi r2, [r5], -r0, lsl #6 */
/* @0x3139e2 strmi r9, [pc], -r10, lsl #6 */
/* @0x3139e6 ldrmi r6, [r1], r3, asr #25 */
/* @0x3139ea .word 0xf8d36806 */
/* @0x3139ee bllt 0x2026a66 <b2_toiTime+0x18cd5c2> */
/* @0x3139f2 .word 0x27c0f8df */
/* @0x3139f6 .word 0x7109f44f */
/* @0x3139fa .word 0xf8c3447a */
/* @0x3139fe bge 0x59ea86 <g_SWFlineaavertbuff+0x4b9be> */
/* @0x313a02 ldrtmi r6, [r0], -r4, asr #25 */
/* @0x313a06 blx 0xfe6d195c <b2_toiTime+0xfffffffffdf784b8> */
/* @0x313a0a .word 0xf8c4990a */
/* @0x313a0e stmdbhs r0, {r2, r3, r4, r10, r11} */
/* @0x313a12 bichi pc, r1, #64 */
/* @0x313a16 eorhs r6, r0, #60160 */
/* @0x313a1a .word 0x4c1cf8d3 */
/* @0x313a1e .word 0xf8404620 */
/* @0x313a22 .word 0xf5a26b90 */
/* @0x313a26 stcne p13, c14, [r3, #-784]! */
/* @0x313a2a adclo pc, r8, r4, asr #17 */
/* @0x313a2e .word 0x3788f8df */
/* @0x313a32 adcvs pc, r4, r4, asr #17 */
/* @0x313a36 .word 0xf8c4447b */
/* @0x313a3a .word 0xf8df3090 */
/* @0x313a3e ldrbtmi r3, [r11], #-1916 */
/* @0x313a42 addslo pc, r4, r4, asr #17 */
/* @0x313a46 .word 0x3778f8df */
/* @0x313a4a .word 0xf8c4447b */
/* @0x313a4e .word 0xf8c4309c */
/* @0x313a52 strhhs r5, [r0, -r0] */
/* @0x313a56 adcpl pc, r12, r4, asr #17 */
/* @0x313a5a .word 0xf8d52210 */
/* @0x313a5e .word 0xf8d88004 */
/* @0x313a62 .word 0xf8d83080 */
/* @0x313a66 .word 0xf8936060 */
/* @0x313a6a blge 0x73fb52 <g_SWFvertbuff+0x6ca8a> */
/* @0x313a6e mlage r0, r6, r8, pc */
/* @0x313a72 movwls r4, #0x6618 */
/* @0x313a76 ldc p5, c15, [r12, #648] */
/* @0x313a7a .word 0x97119713 */
/* @0x313a7e .word 0xf10d444f */
/* @0x313a82 andshs r0, r8, #80, #18 */
/* @0x313a86 ldrls r2, [r2, -r0, lsl #2] */
/* @0x313a8a .word 0xf5a24648 */
/* @0x313a8e stmvs r11!, {r4, r7, r8, r10, r11, sp, lr, pc} */
/* @0x313a92 umlalhs pc, r0, r3, r8 */
/* @0x313a96 umlaleq pc, r1, r3, r8 */
/* @0x313a9a .word 0xf8d3b192 */
/* @0x313a9e .word 0xf8d310a4 */
/* @0x313aa2 .word 0xf11130a8 */
/* @0x313aa6 svclt #0x480720 */
/* @0x313aaa ldrbeq pc, [pc, -r1, lsl #2] */
/* @0x313aae .word 0x0120f113 */
/* @0x313ab2 .word 0xf103bf48 */
/* @0x313ab6 .word 0x11bf015f */
/* @0x313aba orrne r9, r9, r4, lsl r7 */
/* @0x313abe and r9, r3, r7, lsl r1 */
/* @0x313ac2 orrvs pc, r0, #1325400064 */
/* @0x313ac6 tstls r7, #20, #6 */
/* @0x313aca adcslo pc, r4, #152, #16 */
/* @0x313ace stmdblt r10, {r0, r1, r5, r9, r12, sp, lr} */
/* @0x313ad2 and r6, r1, r2, ror #1 */
/* @0x313ad6 rscvs r2, r3, r1, lsl #6 */
/* @0x313ada .word 0xf1bbb160 */
/* @0x313ade andle r0, r5, r0, lsl #30 */
/* @0x313ae2 svceq #0x80f01b */
/* @0x313ae6 .word 0xf1bad006 */
/* @0x313aea .word 0xd1030f00 */
/* @0x313aee .word 0xf04368e3 */
/* @0x313af2 rscvs r0, r3, r2, lsl #6 */
/* @0x313af6 .word 0xf8c46a73 */
/* @0x313afa bvs 0xfefdfdf2 <b2_toiTime+0xfffffffffe88694e> */
/* @0x313afe sbclo pc, r0, r4, asr #17 */
/* @0x313b02 .word 0xf8c46af3 */
/* @0x313b06 blvs 0xfdfe1e <b2_toiTime+0x88697a> */
/* @0x313b0a sbclo pc, r8, r4, asr #17 */
/* @0x313b0e .word 0xf8c46b73 */
/* @0x313b12 blvs 0xfefdfe4a <b2_toiTime+0xfffffffffe8869a6> */
/* @0x313b16 sbcslo pc, r0, r4, asr #17 */
/* @0x313b1a .word 0xf8c46bf3 */
/* @0x313b1e ldcvs p0, c3, [r3], #-848 */
/* @0x313b22 sbcslo pc, r8, r4, asr #17 */
/* @0x313b26 rfeia r3! */
/* @0x313b2a .word 0xf8c41044 */
/* @0x313b2e stmiblt r0, {r2, r7, r12} ^ */
/* @0x313b32 strhs r9, [r0, #-0xb18] */
/* @0x313b36 ldrsbtvc pc, [r0], r4 */
/* @0x313b3a movwls r9, #0xe50b */
/* @0x313b3e .word 0xf8d49b19 */
/* @0x313b42 .word 0xf8d48088 */
/* @0x313b46 movwls r10, #0xf08c */
/* @0x313b4a .word 0xf8d76065 */
/* @0x313b4e .word 0xf8d462e0 */
/* @0x313b52 strls r3, [r12, #-0xb4] */
/* @0x313b56 strls r4, [sp, #-0x2b3] */
/* @0x313b5a .word 0xf8c4d01a */
/* @0x313b5e strhs r6, [r1, #-0xb4] */
/* @0x313b62 mrcls p0, #0x0, lr, c4, c6, #0x0 */
/* @0x313b66 vcge.f32 d18, d0, d0 */
/* @0x313b6a ldcls p3, c8, [r7, #-124] */
/* @0x313b6e vpadd.f32 d18, d0, d0 */
/* @0x313b72 .word 0xf5b1831b */
/* @0x313b76 blle 0x36777e <_ZTS12CDS_Priority+0x97d6> */
/* @0x313b7a tst r6, #164 */
/* @0x313b7e rscsvs pc, r10, pc, asr #32 */
/* @0x313b82 .word 0xf7d10409 */
/* @0x313b86 addmi pc, r6, #2473984 */
/* @0x313b8a addmi sp, r5, #62976 */
/* @0x313b8e .word 0xe7cfdcf4 */
/* @0x313b92 .word 0xf8d36cfb */
/* @0x313b96 blhs 0x322c2e */
/* @0x313b9a andhs sp, r0, #48 */
/* @0x313b9e ldmdavs r8!, {r9, r12, pc} ^ */
/* @0x313ba2 blge 0x67dfda <g_SWFlinevertbuff+0x2af12> */
/* @0x313ba6 .word 0xf8f6f7fa */
/* @0x313baa stmdahs r0, {r5, r6, sp, lr} */
/* @0x313bae adcshi pc, r2, #64 */
/* @0x313bb2 ldrsbtgt pc, [r0], -sp */
/* @0x313bb6 andvc pc, r11, r6, lsl #10 */
/* @0x313bba ldrsbtlt pc, [r4], -sp */
/* @0x313bbe eorne pc, r4, #14024704 */
/* @0x313bc2 .word 0xf8cd4662 */
/* @0x313bc6 uadd16mi r12, r11, r0 */
/* @0x313bca .word 0xf874f7fc */
/* @0x313bce ldrsbgt pc, [r0], -sp */
/* @0x313bd2 ldclvs p1, c11, [r8], #192 */
/* @0x313bd6 uqasxmi r4, r2, r1 */
/* @0x313bda .word 0xf7fc465b */
/* @0x313bde strhs pc, [r1, #-0xb3a] */
/* @0x313be2 eorslo pc, r0, #14024704 */
/* @0x313be6 movwhs r6, #0x623 */
/* @0x313bea subslo pc, sp, r4, lsl #17 */
/* @0x313bee eorlo pc, r4, #14024704 */
/* @0x313bf2 blls 0x62da86 <g_SWFaavertbuff+0x5a9be> */
/* @0x313bf6 blls 0x66db8a <g_SWFlinevertbuff+0x1aac2> */
/* @0x313bfa addlo pc, r0, r4, asr #17 */
/* @0x313bfe .word 0xf104687b */
/* @0x313c02 .word 0xf8d40610 */
/* @0x313c06 strbmi r12, [r8], -r12 */
/* @0x313c0a ldrtmi r6, [r1], -r2, lsr #27 */
/* @0x313c0e blx 0x1aef282 <b2_toiTime+0x1395dde> */
/* @0x313c12 ldmibhi r11, {r2, r3, r7, r8, r9, r11, r12, sp, lr, pc} ^ */
/* @0x313c16 addsmi r0, r10, #452984832 */
/* @0x313c1a andseq pc, r0, #79 */
/* @0x313c1e strvs r11, [r3, #0xf18]! */
/* @0x313c22 movweq pc, #0x100b */
/* @0x313c26 adcslo pc, r8, r4, lsl #17 */
/* @0x313c2a strhs r11, [r1, #-0xf18] */
/* @0x313c2e andsgt pc, r0, sp, asr #17 */
/* @0x313c32 stmda r6, {r0, r1, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x313c36 ldrsbgt pc, [r0], -sp */
/* @0x313c3a .word 0x464db1f0 */
/* @0x313c3e cdpeq p0, #0x0, c15, c0, c15, #0x2 */
/* @0x313c42 strgt r12, [pc], -pc, lsl #26 */
/* @0x313c46 muleq r3, r5, r8 */
/* @0x313c4a andeq lr, r3, r6, lsl #17 */
/* @0x313c4e strteq pc, [r8], -r4, lsl #2 */
/* @0x313c52 strheq lr, [pc], -r9 */
/* @0x313c56 eor pc, r4, r4, asr #17 */
/* @0x313c5a eor pc, r0, r4, asr #17 */
/* @0x313c5e vst1.8 {d28, d29, d30}, [pc] */
/* @0x313c62 ldm r5, {r7, r8, r9, r12, sp} */
/* @0x313c66 strhs r0, [r1, #-0x3] */
/* @0x313c6a andeq lr, r3, r6, lsl #17 */
/* @0x313c6e strtvs r6, [r3], #-1251 */
/* @0x313c72 sub pc, r8, r4, asr #17 */
/* @0x313c76 sub pc, r4, r4, asr #17 */
/* @0x313c7a umlalslo pc, r10, r4, r8 */
/* @0x313c7e .word 0x0c02f00c */
/* @0x313c82 andle r4, r4, r3, ror #10 */
/* @0x313c86 bleq 0x3cfcba <error_g0017+0x2895e> */
/* @0x313c8a adcslt pc, r10, r4, lsl #17 */
/* @0x313c8e stchs p0, c14, [r0, #-8] */
/* @0x313c92 subhi pc, r0, #0 */
/* @0x313c96 .word 0x6084f8d4 */
/* @0x313c9a rsbsvc pc, r10, pc, asr #32 */
/* @0x313c9e cdphs p13, #0x0, c6, c0, c3, #0x5 */
/* @0x313ca2 .word 0xf44fbf08 */
/* @0x313ca6 .word 0xf5b3767a */
/* @0x313caa svclt #0xac2f80 */
/* @0x313cae vst1.32 {d20, d21, d22}, [pc:64], r9 */
/* @0x313cb2 ldrtmi r2, [r1], -r0, lsl #19 */
/* @0x313cb6 stmda r12!, {r0, r2, r12, sp, lr, pc} */
/* @0x313cba rsclo pc, r0, #14090240 */
/* @0x313cbe ldrsblo pc, [r0, r3] */
/* @0x313cc2 .word 0xf8c4041b */
/* @0x313cc6 blhs 0x32003e */
/* @0x313cca .word 0xdc064605 */
/* @0x313cce addseq pc, r6, pc, asr #8 */
/* @0x313cd2 .word 0xf7d14629 */
/* @0x313cd6 .word 0xf8c4f8ef */
/* @0x313cda .word 0xf1b800dc */
/* @0x313cde ldcle p15, c0, [r12, #-0] */
/* @0x313ce2 .word 0x46490436 */
/* @0x313ce6 .word 0xf7d14630 */
/* @0x313cea strmi pc, [r0, #0x8e5] */
/* @0x313cee ldrtmi sp, [r0], -r4, lsl #24 */
/* @0x313cf2 .word 0xf7d14649 */
/* @0x313cf6 pkhtbmi pc, r0, pc, asr #17 */
/* @0x313cfa .word 0xf8c42300 */
/* @0x313cfe .word 0xf1b830e4 */
/* @0x313d02 eorle r0, r1, r0, lsl #30 */
/* @0x313d06 orrhs pc, lr, #64, #4 */
/* @0x313d0a ldcle p2, c4, [sp, #-628] */
/* @0x313d0e ldmvc r8, {r3, r8, r9, r11, sp, lr, pc} ^ */
/* @0x313d12 .word 0x0368ea4f */
/* @0x313d16 rsclo pc, r4, r4, asr #17 */
/* @0x313d1a .word 0xf894e016 */
/* @0x313d1e strhhs r3, [r0, -r10] */
/* @0x313d22 ldrsbhs pc, [r12], #132 */
/* @0x313d26 rscne pc, r4, r4, asr #17 */
/* @0x313d2a .word 0xf240b173 */
/* @0x313d2e addmi r2, r5, #142 */
/* @0x313d32 stm sp, {r1, r3, r8, r10, r11, r12, lr, pc} */
/* @0x313d36 strtmi r0, [r8], -r10 */
/* @0x313d3a .word 0x03bcf104 */
/* @0x313d3e movwls r4, #0x2649 */
/* @0x313d42 .word 0x03e4f104 */
/* @0x313d46 .word 0xf8c5f7fc */
/* @0x313d4a rsclo pc, r0, #14090240 */
/* @0x313d4e .word 0x318cf8d3 */
/* @0x313d52 bhs 0x314dc2 <FT_GlyphSlot_Own_Bitmap+0x2> */
/* @0x313d56 .word 0xf8d4dd07 */
/* @0x313d5a bl 0xfef9c0d2 <b2_toiTime+0xfffffffffe842c2e> */
/* @0x313d5e stcle p15, c4, [r2, #-268] */
/* @0x313d62 addseq pc, r6, pc, asr #8 */
/* @0x313d66 vst4.8 {d30, d31, d0, d1}, [pc], r1 */
/* @0x313d6a .word 0x462900dc */
/* @0x313d6e .word 0xf8a2f7d1 */
/* @0x313d72 .word 0xf8942100 */
/* @0x313d76 .word 0xf8c430ba */
/* @0x313d7a .word 0xf8c410e8 */
/* @0x313d7e .word 0xf8d400e0 */
/* @0x313d82 .word 0xf1ba20e0 */
/* @0x313d86 .word 0xd1000f00 */
/* @0x313d8a .word 0xf240b17b */
/* @0x313d8e addmi r2, sp, #-2147483613 */
/* @0x313d92 movwls sp, #0x1d0b */
/* @0x313d96 .word 0xf1044628 */
/* @0x313d9a .word 0xf8cd03bc */
/* @0x313d9e movwls r10, #0x2000 */
/* @0x313da2 .word 0xf1044649 */
/* @0x313da6 .word 0xf7fc03e8 */
/* @0x313daa .word 0xf8d4f894 */
/* @0x313dae ldmdblt r3, {r2, r5, r6, r7, r12, sp} */
/* @0x313db2 .word 0x30e8f8d4 */
/* @0x313db6 movwhs r11, #0x1103 */
/* @0x313dba .word 0xf8842100 */
/* @0x313dbe .word 0xf88430b9 */
/* @0x313dc2 .word 0xf44f10ec */
/* @0x313dc6 .word 0xf104729a */
/* @0x313dca .word 0xf8d400f0 */
/* @0x313dce .word 0xf5a250b0 */
/* @0x313dd2 blvs 0x1c0ed92 <b2_toiTime+0x14b58ee> */
/* @0x313dd6 cmnvc r10, pc, asr #32 */
/* @0x313dda rscslo pc, r0, r4, asr #17 */
/* @0x313dde rsclo pc, r0, #13959168 */
/* @0x313de2 .word 0x0180f8d3 */
/* @0x313de6 .word 0xf866f7d1 */
/* @0x313dea rscseq pc, r12, r4, asr #17 */
/* @0x313dee rsclo pc, r0, #13959168 */
/* @0x313df2 .word 0x3184f8d3 */
/* @0x313df6 .word 0xf8c4041b */
/* @0x313dfa .word 0xf8d53100 */
/* @0x313dfe .word 0xf8d332e0 */
/* @0x313e02 ldreq r3, [r11], #-392 */
/* @0x313e06 smlabtlo r4, r4, r8, pc */
/* @0x313e0a rscpl pc, r0, #13959168 */
/* @0x313e0e biceq pc, r0, r5, lsl #2 */
/* @0x313e12 ldmibeq r8!, {r0, r2, r8, r12, sp, lr, pc} ^ */
/* @0x313e16 umlalslo pc, lr, r5, r8 */
/* @0x313e1a umlalsvc pc, sp, r5, r8 */
/* @0x313e1e umlalseq pc, r12, r5, r8 */
/* @0x313e22 .word 0xf8959305 */
/* @0x313e26 .word 0x970730bf */
/* @0x313e2a ldrvc pc, [r0, r5, lsl #10] */
/* @0x313e2e movwls r9, #0x9708 */
/* @0x313e32 andlo pc, r12, #13959168 */
/* @0x313e36 .word 0xd1022b01 */
/* @0x313e3a stmdahs r4, {r3, r4, r5, r6, r7, r8, r12, sp, pc} */
/* @0x313e3e andhs sp, r0, #5 */
/* @0x313e42 ldmdaeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x313e46 .word 0x46944616 */
/* @0x313e4a .word 0xf8d5e05f */
/* @0x313e4e ldreq r3, [r11], #-192 */
/* @0x313e52 svceq #0xf0f513 */
/* @0x313e56 .word 0xf8d5daf3 */
/* @0x313e5a ldreq r3, [r11], #-196 */
/* @0x313e5e svceq #0xf0f513 */
/* @0x313e62 .word 0xf8d5daed */
/* @0x313e66 ldreq r3, [r11], #-200 */
/* @0x313e6a svcvc #0x5cf1b3 */
/* @0x313e6e .word 0xf8d5dde7 */
/* @0x313e72 ldreq r3, [r11], #-204 */
/* @0x313e76 svcvc #0x5cf1b3 */
/* @0x313e7a .word 0xf46fdde1 */
/* @0x313e7e .word 0xf8d400f0 */
/* @0x313e82 .word 0xf8c410f0 */
/* @0x313e86 .word 0xf7f90128 */
/* @0x313e8a .word 0xf8d4ff94 */
/* @0x313e8e teqhs r1, #240 */
/* @0x313e92 smlawtlo r0, r4, r8, pc */
/* @0x313e96 teqne r0, r4, asr #17 */
/* @0x313e9a andmi pc, r0, r0, lsl #10 */
/* @0x313e9e streq r0, [r0], #-3072 */
/* @0x313ea2 andmi pc, r0, r0, lsr #11 */
/* @0x313ea6 smlawteq r12, r4, r8, pc */
/* @0x313eaa .word 0x00e8f8d4 */
/* @0x313eae cps #0x0 */
/* @0x313eb2 andlo r7, r1, r12, asr r0 */
/* @0x313eb6 tsteq r4, r4, asr #17 */
/* @0x313eba .word 0xff7bf7f9 */
/* @0x313ebe ldrsbtlo pc, [r0], #132 */
/* @0x313ec2 tstlo r12, r4, asr #17 */
/* @0x313ec6 .word 0xf8c42332 */
/* @0x313eca movwhs r3, #0x110c */
/* @0x313ece rscslo pc, r9, r4, lsl #17 */
/* @0x313ed2 andmi pc, r0, r0, lsl #10 */
/* @0x313ed6 streq r0, [r0], #-3072 */
/* @0x313eda andmi pc, r0, r0, lsl #10 */
/* @0x313ede tsteq r8, r4, asr #17 */
/* @0x313ee2 .word 0xf8d4e118 */
/* @0x313ee6 stmdavs pc, {r2, r4, r5, r6, r7, sp, lr, pc} */
/* @0x313eea movwmi pc, #0xeb08 */
/* @0x313eee .word 0xf8c3043f */
/* @0x313ef2 stmdavs pc, {r2, r4, r5, r8, r12, sp, lr} ^ */
/* @0x313ef6 bmi 0x50e83a <SrcVerts+0x6b87e> */
/* @0x313efa ldrsbvc pc, [r4, -r3]! */
/* @0x313efe teqge r8, r3, asr #17 */
/* @0x313f02 .word 0x0707ebba */
/* @0x313f06 andlo sp, r2, #4, #10 */
/* @0x313f0a addmi r3, r2, #8, #2 */
/* @0x313f0e ands sp, sp, r9, ror #7 */
/* @0x313f12 svclt #0xb842be */
/* @0x313f16 bhs 0x325816 */
/* @0x313f1a teqhi pc, r0 */
/* @0x313f1e .word 0x70e8f8d4 */
/* @0x313f22 smlalbbgt pc, r4, r3, r8 */
/* @0x313f26 bleq 0x150e86a <b2_toiTime+0xdb53c6> */
/* @0x313f2a streq lr, [r11, -r10, lsl #22] */
/* @0x313f2e teqvc r8, r3, asr #17 */
/* @0x313f32 ldrsbvc pc, [r4, -r3]! */
/* @0x313f36 .word 0xf8c3445f */
/* @0x313f3a .word 0xf8d37134 */
/* @0x313f3e .word 0xf8c37134 */
/* @0x313f42 .word 0xf10e713c */
/* @0x313f46 .word 0xf8c40301 */
/* @0x313f4a .word 0xe7dc30f4 */
/* @0x313f4e andhs r4, r0, r10, asr #12 */
/* @0x313f52 cdpeq p0, #0x1, c15, c4, c15, #0x2 */
/* @0x313f56 .word 0x0c01f04f */
/* @0x313f5a addsmi r9, r8, #7168 */
/* @0x313f5e .word 0xf8d4d21f */
/* @0x313f62 ldmdavs r1, {r2, r4, r5, r6, r7, pc} */
/* @0x313f66 movwmi pc, #0x8b0e */
/* @0x313f6a .word 0xf8c30409 */
/* @0x313f6e ldmdavs r1, {r2, r4, r5, r8, r12} ^ */
/* @0x313f72 ldrsbvc pc, [r4, -r3]! */
/* @0x313f76 .word 0xf8c30409 */
/* @0x313f7a blne 0xff558462 <b2_toiTime+0xfffffffffedfefbe> */
/* @0x313f7e addmi sp, lr, #12, #8 */
/* @0x313f82 .word 0x460ebfb8 */
/* @0x313f86 ldrsbne pc, [r8, -r3]! */
/* @0x313f8a smlalbbgt pc, r4, r3, r8 */
/* @0x313f8e streq pc, [r1, -r8, lsl #2] */
/* @0x313f92 teqne r12, r3, asr #17 */
/* @0x313f96 rscsvc pc, r4, r4, asr #17 */
/* @0x313f9a andlo r3, r8, #2 */
/* @0x313f9e .word 0xf8d4e7dc */
/* @0x313fa2 .word 0xf44f10f0 */
/* @0x313fa6 .word 0xf7d03080 */
/* @0x313faa .word 0xf104ff85 */
/* @0x313fae .word 0xf8d408f0 */
/* @0x313fb2 strdhs r9, r10, [r0, -r4] */
/* @0x313fb6 strbmi r4, [r9, #-0x6c6] */
/* @0x313fba bl 0xff448132 <b2_toiTime+0xfffffffffeceec8e> */
/* @0x313fbe strbmi r0, [r2], #-526 */
/* @0x313fc2 ldclo p8, c15, [r12], {18} */
/* @0x313fc6 stcgt p8, c15, [r4], #328 */
/* @0x313fca .word 0xf06fb923 */
/* @0x313fce .word 0xf04f4b00 */
/* @0x313fd2 sub r0, r0, r2, lsl #20 */
/* @0x313fd6 bmi 0x35019a */
/* @0x313fda blls 0x55dbe2 <g_SWFlineaavertbuff+0xab1a> */
/* @0x313fde andsle r4, r4, #-268435447 */
/* @0x313fe2 orreq lr, r7, #5120 */
/* @0x313fe6 ldrsblo pc, [r12, #-131] */
/* @0x313fea blmi 0x40e92e <g_RomDisk+0x1710e> */
/* @0x313fee movweq lr, #0xcbcb */
/* @0x313ff2 svclt #0xb82b00 */
/* @0x313ff6 ldrbmi r4, [r3, #-0x25b] */
/* @0x313ffa addmi sp, r3, #20480 */
/* @0x313ffe .word 0xf842da03 */
/* @0x314002 tstlt r11, r4, lsr #25 */
/* @0x314006 .word 0x3702469a */
/* @0x31400a ldrbmi lr, [r3], -r7, ror #15 */
/* @0x31400e svchs #0x19f05 */
/* @0x314012 .word 0xf8d5d92c */
/* @0x314016 ldrteq r7, [pc], #-292 */
/* @0x31401a .word 0x0c0cebc7 */
/* @0x31401e svceq #0xf1bc */
/* @0x314022 .word 0xf1ccbfb8 */
/* @0x314026 ldrmi r0, [r12, #0xc00] */
/* @0x31402a strmi sp, [r4, #0xa20] */
/* @0x31402e .word 0xf842da1e */
/* @0x314032 ands r7, r11, r4, lsr #25 */
/* @0x314036 .word 0xf8579f08 */
/* @0x31403a .word 0xf8d4302a */
/* @0x31403e rsbseq r7, pc, r8, ror #1 */
/* @0x314042 movwmi lr, #0x3b07 */
/* @0x314046 streq lr, [r12, -r3, asr #23] */
/* @0x31404a svclt #0xb82f00 */
/* @0x31404e ldrbmi r4, [pc, #-0x27f] */
/* @0x314052 .word 0xf10adb05 */
/* @0x314056 blls 0x456866 <g_RomDisk+0x5f046> */
/* @0x31405a .word 0xd3eb459a */
/* @0x31405e addmi lr, r7, #6 */
/* @0x314062 .word 0xf842daf7 */
/* @0x314066 smlatblt pc, r4, r12, r3 */
/* @0x31406a .word 0xe7f246bb */
/* @0x31406e .word 0xf10e3101 */
/* @0x314072 .word 0xe7a00e14 */
/* @0x314076 vst4.16 {d27, d29, d31, d1}, [pc:256], lr */
/* @0x31407a ldrtmi r3, [r1], -r0, lsl #1 */
/* @0x31407e ldrsbtpl pc, [r12], #132 */
/* @0x314082 .word 0xff18f7d0 */
/* @0x314086 stcle p2, c4, [r6, #-532] */
/* @0x31408a addlo pc, r0, pc, asr #8 */
/* @0x31408e .word 0xf7d04631 */
/* @0x314092 .word 0xf8c4ff11 */
/* @0x314096 .word 0xf8d400fc */
/* @0x31409a .word 0xf8d410f0 */
/* @0x31409e addsmi r2, r1, #252 */
/* @0x3140a2 movwhs sp, #0x1a11 */
/* @0x3140a6 addsne pc, r10, r9, asr #12 */
/* @0x3140aa rscslo pc, r8, r4, lsl #17 */
/* @0x3140ae mcr2 p7, #0x2, pc, c5, c0, #0x6 */
/* @0x3140b2 .word 0x73fff647 */
/* @0x3140b6 andsmi pc, r9, r0, asr #11 */
/* @0x3140ba addsmi r3, r8, #154 */
/* @0x3140be .word 0xf8c4bfd4 */
/* @0x3140c2 .word 0xf8c40108 */
/* @0x3140c6 .word 0xf8943108 */
/* @0x3140ca ldrhlt r3, [r3, -r10] */
/* @0x3140ce .word 0xf8c42300 */
/* @0x3140d2 .word 0xf5043108 */
/* @0x3140d6 strhs r7, [r0], -r2, lsr #11 */
/* @0x3140da ldrsbtlo pc, [r4], #132 */
/* @0x3140de andsle r4, r9, #-536870903 */
/* @0x3140e2 .word 0xf855782b */
/* @0x3140e6 .word 0xf8d40c08 */
/* @0x3140ea strdlt r1, r2, [r11, -r0]! */
/* @0x3140ee mcr2 p7, #0x3, pc, c1, c9, #0x7 */
/* @0x3140f2 .word 0x3108f8d4 */
/* @0x3140f6 and r1, r4, r0, asr #21 */
/* @0x3140fa mrc2 p7, #0x2, apsr_nzcv, c11, c9, #0x7 */
/* @0x3140fe .word 0x3108f8d4 */
/* @0x314102 .word 0xf5004418 */
/* @0x314106 strlo r4, [r1], -r0, lsl #6 */
/* @0x31410a .word 0x0c1b3514 */
/* @0x31410e .word 0xf845041b */
/* @0x314112 .word 0xe7e13c18 */
/* @0x314116 bllt 0x1e6e2b2 <b2_toiTime+0x1714e0e> */
/* @0x31411a umlalsvs pc, r9, r4, r8 */
/* @0x31411e .word 0xf10daf0e */
/* @0x314122 .word 0xf884082c */
/* @0x314126 .word 0xf8d450ec */
/* @0x31412a .word 0xf8c430ac */
/* @0x31412e ldmvs r8, {r5, r7, r12, lr} ^ */
/* @0x314132 .word 0xf8c3f7d1 */
/* @0x314136 addseq pc, r0, #4, #2 */
/* @0x31413a strtmi r9, [r0], -r0, lsl #10 */
/* @0x31413e ldmdbge r0, {r0, r8, r10, r12, pc} */
/* @0x314142 ldrtmi r9, [r11], -r2, lsl #10 */
/* @0x314146 andhi pc, r12, sp, asr #17 */
/* @0x31414a blx 0x29214a <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x30a> */
/* @0x31414e stmiblt r10, {r1, r5, r6, r11, sp, lr} */
/* @0x314152 .word 0xf8d4b146 */
/* @0x314156 blhs 0x3203de */
/* @0x31415a movwhs sp, #0x1a04 */
/* @0x31415e .word 0xf8844616 */
/* @0x314162 strb r3, [r0, r12, ror #1]! */
/* @0x314166 .word 0x50acf8d4 */
/* @0x31416a .word 0xf7fb6968 */
/* @0x31416e stmvs r8!, {r1, r2, r3, r4, r11, r12, sp, lr, pc} ^ */
/* @0x314172 .word 0xf8c1f7d1 */
/* @0x314176 .word 0x21001d20 */
/* @0x31417a .word 0xf7f99d0b */
/* @0x31417e stmdavs r0!, {r0, r5, r6, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x314182 .word 0xf8d4b938 */
/* @0x314186 .word 0xf50530ac */
/* @0x31418a strtne r4, [sp], #-1280 */
/* @0x31418e eorpl pc, r8, #12779520 */
/* @0x314192 andhs lr, r3, r11 */
/* @0x314196 subhs lr, r0, r9 */
/* @0x31419a .word 0xf04fe007 */
/* @0x31419e .word 0xf8830701 */
/* @0x3141a2 .word 0xf8d37144 */
/* @0x3141a6 .word 0xe6ca7138 */
/* @0x3141aa andslt r2, r11, r4, lsr #32 */
/* @0x3141ae svchi #0xf0e8bd */
/* @0x3141b2 ldrbtge r11, [r7], r0, lsl #30 */
/* @0x3141b6 stmdalt r5, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3141ba ldcgt p15, c15, [r3, #-1020] */
/* @0x3141be ldclgt p15, c15, [r1, #-1020] */
/* @0x3141c2 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3141c6 ssub8mi r4, r6, r0 */
/* @0x3141ca ldrmi r6, [r11], r5, asr #16 */
/* @0x3141ce .word 0x73fff64f */
/* @0x3141d2 stclvc p5, c15, [pc, #-692] */
/* @0x3141d6 strmi r4, [r8], r4, lsl #12 */
/* @0x3141da adcvc pc, r0, #13959168 */
/* @0x3141de strbhs pc, [r0, #0x8d7]! */
/* @0x3141e2 mulle sp, r10, r2 */
/* @0x3141e6 strtlo pc, [r8], #2263 */
/* @0x3141ea qdsublt r11, r3, r6 */
/* @0x3141ee strths pc, [r12], #2263 */
/* @0x3141f2 stmdble r1, {r1, r2, r4, r7, r9, lr} */
/* @0x3141f6 cmp r2, #6 */
/* @0x3141fa andsvs pc, r6, r3, lsr r8 */
/* @0x3141fe .word 0xe7f9b91e */
/* @0x314202 addsmi r6, lr, #2015232 */
/* @0x314206 .word 0xf41bd2f6 */
/* @0x31420a .word 0xf44f6f80 */
/* @0x31420e svclt #0x183380 */
/* @0x314212 bleq 0x410346 <g_RomDisk+0x18b26> */
/* @0x314216 adclo pc, r4, r4, asr #17 */
/* @0x31421a adclo pc, r8, r4, asr #17 */
/* @0x31421e svceq #0xf1b8 */
/* @0x314222 addshi pc, r3, r0 */
/* @0x314226 ldrsblo pc, [r0], -r8 */
/* @0x31422a adclo pc, r4, r4, asr #17 */
/* @0x31422e ldrsblo pc, [r4], -r8 */
/* @0x314232 adclo pc, r8, r4, asr #17 */
/* @0x314236 .word 0x2000f8d8 */
/* @0x31423a .word 0x102cf8d8 */
/* @0x31423e andslo pc, r12, #13762560 */
/* @0x314242 mcrrne p14, #0x9, r6, r10, c0 */
/* @0x314246 addhi pc, r1, r0 */
/* @0x31424a bhs 0x32faba */
/* @0x31424e .word 0xf01bd07d */
/* @0x314252 cmnle r10, r8, lsl #30 */
/* @0x314256 .word 0xf1049000 */
/* @0x31425a .word 0xf10d024c */
/* @0x31425e andls r0, r1, #84, #18 */
/* @0x314262 andls pc, r8, sp, asr #17 */
/* @0x314266 .word 0xf8d34628 */
/* @0x31426a ldrtmi r12, [r2], -r8, asr #32 */
/* @0x31426e ubfxmi r4, r11, #0xc, #0x1 */
/* @0x314272 .word 0xd16a2800 */
/* @0x314276 strhlo pc, [r2], -r9 */
/* @0x31427a svceq #0x10f01b */
/* @0x31427e strhhs pc, [r4], -r9 */
/* @0x314282 stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x314286 rsbeq pc, lr, r4, lsr #17 */
/* @0x31428a orrne lr, r3, #323584 */
/* @0x31428e rfeia r9! */
/* @0x314292 .word 0xf8a43000 */
/* @0x314296 rfeib r9! */
/* @0x31429a b 0x16d42ca <b2_toiTime+0xf7ae26> */
/* @0x31429e mvnvs r1, r3, lsl #7 */
/* @0x3142a2 orrne lr, r2, #323584 */
/* @0x3142a6 rfeib r9! */
/* @0x3142aa svclt #0x143006 */
/* @0x3142ae strbtvs r6, [r2], -r0, ror #12 */
/* @0x3142b2 b 0x16e5b82 <b2_toiTime+0xf8c6de> */
/* @0x3142b6 rsbvs r1, r1, #-1073741792 */
/* @0x3142ba strhne pc, [r8], -r9 */
/* @0x3142be strtvs r11, [r3], r8, lsl #30 */
/* @0x3142c2 orrne lr, r1, pc, asr #20 */
/* @0x3142c6 b 0x16ecd52 <b2_toiTime+0xf938ae> */
/* @0x3142ca rscvs r1, r1, #128, #2 */
/* @0x3142ce strhne pc, [r12], -r9 */
/* @0x3142d2 b 0x16e5b7a <b2_toiTime+0xf8c6d6> */
/* @0x3142d6 .word 0x63271781 */
/* @0x3142da strhvc pc, [lr], -r9 */
/* @0x3142de ssatvs r11, #0x2, r8, lsl #30 */
/* @0x3142e2 .word 0x01bf2100 */
/* @0x3142e6 svcmi #0xa86367 */
/* @0x3142ea svcge #0xd64a7 */
/* @0x3142ee andslo pc, r12, #13959168 */
/* @0x3142f2 .word 0xf8d39700 */
/* @0x3142f6 .word 0x4643c070 */
/* @0x3142fa ldmdahi r11!, {r5, r6, r7, r8, r9, r10, lr} */
/* @0x3142fe .word 0xf89563a3 */
/* @0x314302 .word 0xb1233124 */
/* @0x314306 strhlo pc, [r10, #-133] */
/* @0x31430a svclt #0x183300 */
/* @0x31430e cmplt r11, r1, lsl #6 */
/* @0x314312 andslo pc, r12, #13959168 */
/* @0x314316 strls r4, [r0, -r8, lsr #12] */
/* @0x31431a ldrtmi r2, [r2], -r1, lsl #2 */
/* @0x31431e ldrsbtgt pc, [r0], #-131 */
/* @0x314322 strbmi r4, [r0, r3, asr #12]! */
/* @0x314326 and r8, lr, r11, lsr r8 */
/* @0x31432a ldrhlo pc, [r4, #-133]! */
/* @0x31432e rscsvc pc, pc, #82837504 */
/* @0x314332 svclt #0x194293 */
/* @0x314336 ldrhhs pc, [r10, r5]! */
/* @0x31433a ldrhlo pc, [r12, r5]! */
/* @0x31433e ldrhhs pc, [r12], #149 */
/* @0x314342 ldrhlo pc, [lr], #149 */
/* @0x314346 .word 0x63e31ad3 */
/* @0x31434a .word 0xf41be196 */
/* @0x31434e .word 0xf47f4f80 */
/* @0x314352 .word 0xf8d7af51 */
/* @0x314356 .word 0xf1bee7e8 */
/* @0x31435a eorsle r0, r5, r0, lsl #30 */
/* @0x31435e .word 0xf6074631 */
/* @0x314362 .word 0xf7f930ec */
/* @0x314366 .word 0xf8d7fce9 */
/* @0x31436a .word 0xf10d37e8 */
/* @0x31436e .word 0xf8d70c34 */
/* @0x314372 addsmi r10, r8, #160, #10 */
/* @0x314376 .word 0xf103bf24 */
/* @0x31437a sbclt r3, r0, #255 */
/* @0x31437e addeq lr, r0, r7, lsl #22 */
/* @0x314382 ubfx pc, r0, #0x11, #0xd */
/* @0x314386 teqeq r0, #-2147483645 */
/* @0x31438a .word 0x9044f8de */
/* @0x31438e strbmi r12, [r10, #0xb0f] */
/* @0x314392 andeq lr, pc, r12, lsl #17 */
/* @0x314396 .word 0x3048f8de */
/* @0x31439a .word 0x204cf8de */
/* @0x31439e andls r9, r6, #8, #6 */
/* @0x3143a2 ldrbmi sp, [r1], -r2, lsr #32 */
/* @0x3143a6 .word 0xf8d4464a */
/* @0x3143aa .word 0xf7d000a4 */
/* @0x3143ae ldrbmi pc, [r1], -r6, asr #25 */
/* @0x3143b2 .word 0xf8c4464a */
/* @0x3143b6 .word 0xf8d400a4 */
/* @0x3143ba .word 0xf7d000a8 */
/* @0x3143be movwhs pc, #0x1cbe */
/* @0x3143c2 .word 0xf8c49309 */
/* @0x3143c6 ands r0, r1, r8, lsr #1 */
/* @0x3143ca orrpl pc, r12, #1879048192 */
/* @0x3143ce ldceq p1, c15, [r4], #-52 */
/* @0x3143d2 eor pc, r4, sp, asr #17 */
/* @0x3143d6 stm r12, {r0, r1, r2, r3, r8, r9, r11, lr, pc} */
/* @0x3143da .word 0xf8d7000f */
/* @0x3143de .word 0xf8d725a4 */
/* @0x3143e2 andls r3, r8, #168, #10 */
/* @0x3143e6 and r9, r1, r6, lsl #6 */
/* @0x3143ea andls r2, r9, #0, #4 */
/* @0x3143ee movweq pc, #0x208b */
/* @0x3143f2 ldmdbeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x3143f6 movteq pc, #0x3c3 */
/* @0x3143fa .word 0xf00b9307 */
/* @0x3143fe bls 0x4d500a <SrcVerts+0x3204e> */
/* @0x314402 .word 0xf083930b */
/* @0x314406 .word 0xf8840301 */
/* @0x31440a .word 0xf04f30a1 */
/* @0x31440e blmi 0x1ad6c16 <b2_toiTime+0x137d772> */
/* @0x314412 .word 0xf8844651 */
/* @0x314416 strbmi r2, [r8], -r0, lsr #1 */
/* @0x31441a rsbge pc, lr, r4, lsr #17 */
/* @0x31441e andmi pc, r3, #738197507 */
/* @0x314422 .word 0xf8a464a3 */
/* @0x314426 .word 0xf8d5a06c */
/* @0x31442a andls r12, r10, #160, #4 */
/* @0x31442e eorsvc pc, r9, #1325400064 */
/* @0x314432 .word 0xf8cd9304 */
/* @0x314436 .word 0xf5a2c014 */
/* @0x31443a .word 0xf8c9e8ba */
/* @0x31443e andhs r5, r1, #4 */
/* @0x314442 andmi pc, r8, r9, asr #17 */
/* @0x314446 subhs pc, r1, r9, lsl #17 */
/* @0x31444a .word 0xf8c96e6a */
/* @0x31444e .word 0xf8d42000 */
/* @0x314452 ldmdavs r0, {r2, r3, r4, r7, sp} */
/* @0x314456 andseq pc, r4, #0, #2 */
/* @0x31445a andshs pc, r0, r9, asr #17 */
/* @0x31445e andeq pc, r12, r9, asr #17 */
/* @0x314462 eorseq pc, r8, #0, #2 */
/* @0x314466 andshs pc, r4, r9, asr #17 */
/* @0x31446a .word 0xff27f7d0 */
/* @0x31446e .word 0xf8c99b07 */
/* @0x314472 .word 0xf8c9a048 */
/* @0x314476 .word 0xf8dda044 */
/* @0x31447a cmnlt r3, r4, lsl r0 */
/* @0x31447e svceq #0xf1b8 */
/* @0x314482 .word 0xf8d8d00b */
/* @0x314486 ldmdavs r11, {r3, r5, r12, sp} */
/* @0x31448a ldmdavs r11, {r0, r1, r3, r4, r5, r8, r12, sp, pc} */
/* @0x31448e sublo pc, r8, r9, asr #17 */
/* @0x314492 ldrsblo pc, [r12], r4 */
/* @0x314496 .word 0xf8c96a5b */
/* @0x31449a movwhs r3, #0x44 */
/* @0x31449e adcgt pc, r0, sp, asr #17 */
/* @0x3144a2 tstls r12, #1811939328 */
/* @0x3144a6 tstls lr, #1946157056 */
/* @0x3144aa .word 0x9320931f */
/* @0x3144ae ldrsbths pc, [r8], #-140 */
/* @0x3144b2 .word 0xf8dc92c4 */
/* @0x3144b6 bicls r1, r8, r8, asr #10 */
/* @0x3144ba strne pc, [r8, #0x8dc] */
/* @0x3144be andle r2, r12, r1, lsl #18 */
/* @0x3144c2 svcvs #0x9bf5b2 */
/* @0x3144c6 vcgt.s8 d29, d0, d8 */
/* @0x3144ca .word 0xf248436b */
/* @0x3144ce addmi r4, r10, #-1073741798 */
/* @0x3144d2 .word 0xf44fbf88 */
/* @0x3144d6 and r4, r0, r0, lsl #6 */
/* @0x3144da bicls r2, r6, #-1409286143 */
/* @0x3144de svcvc #0x80f41b */
/* @0x3144e2 .word 0xf10d9b0a */
/* @0x3144e6 qsaxmi r0, r8, r4 */
/* @0x3144ea bge 0x625db6 <g_SWFaavertbuff+0x52cee> */
/* @0x3144ee svclt #0x1c93cb */
/* @0x3144f2 .word 0xf88a2301 */
/* @0x3144f6 movwhs r3, #0x231 */
/* @0x3144fa sublo pc, r2, r10, lsl #17 */
/* @0x3144fe .word 0xf7fbab11 */
/* @0x314502 sxtab16mi pc, r1, r12, ror #16 */
/* @0x314506 .word 0xf0402800 */
/* @0x31450a .word 0xf8da80bb */
/* @0x31450e .word 0xf8d33004 */
/* @0x314512 .word 0xf8d992a0 */
/* @0x314516 ldmdblt r3, {r3, r5, r6, r7, r8, r9, r10, r12, sp} */
/* @0x31451a cmppl r12, #-1879048192 */
/* @0x31451e .word 0xf609e01b */
/* @0x314522 ldrtmi r3, [r1], -r12, ror #1 */
/* @0x314526 .word 0xfc08f7f9 */
/* @0x31452a ubfxlo pc, r9, #0x11, #0x9 */
/* @0x31452e .word 0xf0804298 */
/* @0x314532 bl 0x5747ce <g_SWFlineaavertbuff+0x21706> */
/* @0x314536 .word 0xf8da0380 */
/* @0x31453a .word 0xf8d32044 */
/* @0x31453e cmplt r2, r12, ror #15 */
/* @0x314542 svceq #0xf1b8 */
/* @0x314546 .word 0xf8d8d007 */
/* @0x31454a ldmdavs r2, {r3, r5, sp} */
/* @0x31454e addeq lr, r0, r2, lsl #22 */
/* @0x314552 .word 0xf8ca6842 */
/* @0x314556 .word 0xf8d32048 */
/* @0x31455a bicls r1, r3, r12, ror #4 */
/* @0x31455e addhs pc, r4, #13828096 */
/* @0x314562 bls 0xd39086 <b2_toiTime+0x5dfbe2> */
/* @0x314566 strhs pc, [r8, #0x8d2] */
/* @0x31456a andle r2, r11, r1, lsl #20 */
/* @0x31456e svcvs #0x9bf5b1 */
/* @0x314572 vcgt.s8 d29, d0, d15 */
/* @0x314576 .word 0xf248426b */
/* @0x31457a addmi r4, r1, #107 */
/* @0x31457e .word 0xf44fbf88 */
/* @0x314582 and r4, r7, r0, lsl #4 */
/* @0x314586 and r2, r5, r0, lsl #4 */
/* @0x31458a ldrbtvc r11, [r3], #-3840 */
/* @0x31458e strbtvc r6, [r12], #-617 */
/* @0x314592 rsbhs r6, r11, #468 */
/* @0x314596 .word 0xf10d92c5 */
/* @0x31459a .word 0xf8d30c54 */
/* @0x31459e .word 0xf10d221c */
/* @0x3145a2 strbtmi r0, [r0], -r4, asr #20 */
/* @0x3145a6 addsls r9, pc, #12, #18 */
/* @0x3145aa eorhs pc, r0, #13828096 */
/* @0x3145ae blge 0x6394ea <g_SWFaavertbuff+0x66422> */
/* @0x3145b2 .word 0xf8da92a0 */
/* @0x3145b6 movwls r2, #0x4000 */
/* @0x3145ba andsgt pc, r4, sp, asr #17 */
/* @0x3145be blx 0x6125c2 <g_SWFaavertbuff+0x3f4fa> */
/* @0x3145c2 .word 0xf8dd9b04 */
/* @0x3145c6 sbclt r12, r2, #20 */
/* @0x3145ca bhs 0xfec25fd6 <b2_toiTime+0xfffffffffe4ccb32> */
/* @0x3145ce .word 0xf04fd10e */
/* @0x3145d2 ldmdavs r9, {r9} */
/* @0x3145d6 adchs pc, r0, r4, lsl #17 */
/* @0x3145da .word 0xf8da4660 */
/* @0x3145de .word 0xf7ff2000 */
/* @0x3145e2 movwhs pc, #0x19fa */
/* @0x3145e6 movwls r2, #0x9200 */
/* @0x3145ea strmi r9, [r1], r7, lsl #4 */
/* @0x3145ee stmdbge r12, {r3, r5, r9, r10, lr} */
/* @0x3145f2 .word 0x2000f8da */
/* @0x3145f6 rfedb sp! */
/* @0x3145fa svceq #0xf1b9 */
/* @0x3145fe .word 0xf8d5d140 */
/* @0x314602 blvs 0x19e080a <b2_toiTime+0x1287366> */
/* @0x314606 .word 0xf8c4b123 */
/* @0x31460a .word 0xf8c49088 */
/* @0x31460e and r9, lr, r12, lsl #1 */
/* @0x314612 ldrblo pc, [r0], #2263 */
/* @0x314616 .word 0xf853b15b */
/* @0x31461a .word 0xf8d73026 */
/* @0x31461e bllo 0x35d976 <_ZTS7CFontGM+0x103e> */
/* @0x314622 .word 0xf8c44413 */
/* @0x314626 .word 0xf8da3088 */
/* @0x31462a .word 0xf8c43000 */
/* @0x31462e blge 0x860866 <b2_toiTime+0x1073c2> */
/* @0x314632 swpblt r6, pc, [r7] */
/* @0x314636 ldrsbgt pc, [r0], -r3 */
/* @0x31463a ldm r12!, {r2, r3, r5, r6, r8, r9, r10, r12, sp} */
/* @0x31463e strgt r0, [pc, -pc] */
/* @0x314642 .word 0x3000f8dc */
/* @0x314646 .word 0xf8d5603b */
/* @0x31464a blvs 0x19e0852 <b2_toiTime+0x12873ae> */
/* @0x31464e .word 0xf41bb9d3 */
/* @0x314652 eorsle r6, r10, r0, lsl #3 */
/* @0x314656 .word 0xf8d49b1d */
/* @0x31465a eorvs r5, r3, #156 */
/* @0x31465e adcvs r9, r3, #162816 */
/* @0x314662 .word 0xf105ab0d */
/* @0x314666 blgt 0x6d569e <g_SWFvertbuff+0x25d6> */
/* @0x31466a andeq lr, pc, r4, lsl #17 */
/* @0x31466e bls 0x4bb296 <SrcVerts+0x182da> */
/* @0x314672 movwhs r6, #0x11eb */
/* @0x314676 eorvc r6, r11, #-1610612734 */
/* @0x31467a tst r0, r0 */
/* @0x31467e stmdbeq r3, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x314682 .word 0xe10c4648 */
/* @0x314686 ldmvs r2, {r1, r3, r4, r11, sp, lr} */
/* @0x31468a rscle r2, r0, r0, lsl #20 */
/* @0x31468e svcge #0x119a1d */
/* @0x314692 subls pc, r8, sp, asr #17 */
/* @0x314696 .word 0xf10d4631 */
/* @0x31469a andsls r0, r1, #84, #20 */
/* @0x31469e andsls r9, r3, #126976 */
/* @0x3146a2 andsls r9, r4, #32, #20 */
/* @0x3146a6 ldmdavs r8, {r1, r3, r4, r11, sp, lr} ^ */
/* @0x3146aa .word 0xf8d2463b */
/* @0x3146ae andhs r12, r0, #8 */
/* @0x3146b2 ldmdavs r11!, {r5, r6, r7, r8, r9, r10, lr} */
/* @0x3146b6 eorlo pc, r0, r10, asr #17 */
/* @0x3146ba .word 0xf8ca68bb */
/* @0x3146be ldmvs r11!, {r3, r5, r12, sp} ^ */
/* @0x3146c2 eorlo pc, r12, r10, asr #17 */
/* @0x3146c6 sbcle r2, r2, r0, lsl #16 */
/* @0x3146ca rfeia r5! */
/* @0x3146ce ldrshlt r3, [r11, r10]! */
/* @0x3146d2 eorsne pc, r0, sp, lsr #17 */
/* @0x3146d6 .word 0xf8adaf0c */
/* @0x3146da .word 0xf10d1044 */
/* @0x3146de .word 0xf8d50944 */
/* @0x3146e2 shadd16mi r3, r2, r12 */
/* @0x3146e6 andls pc, r0, sp, asr #17 */
/* @0x3146ea .word 0xf8d34628 */
/* @0x3146ee shsub16mi r12, r11, r0 */
/* @0x3146f2 rfeia r9! */
/* @0x3146f6 rfeib r7! */
/* @0x3146fa adcvs r2, r3, #0 */
/* @0x3146fe and r6, r1, r2, lsr #4 */
/* @0x314702 adcvs r9, r3, #162816 */
/* @0x314706 andhs r6, r0, #-1946157054 */
/* @0x31470a ldrsblo pc, [r12], r4 */
/* @0x31470e .word 0xf895721a */
/* @0x314712 .word 0xb1233124 */
/* @0x314716 strhlo pc, [r10, #-133] */
/* @0x31471a svclt #0x181a9b */
/* @0x31471e .word 0xf0032301 */
/* @0x314722 ldrshlt r0, [r3, pc]! */
/* @0x314726 .word 0xf8ad2300 */
/* @0x31472a .word 0xf8ad3030 */
/* @0x31472e .word 0xf10d3044 */
/* @0x314732 .word 0xf8d50930 */
/* @0x314736 svcge #0x11321c */
/* @0x31473a strls r4, [r0, -r8, lsr #12] */
/* @0x31473e ldrtmi r2, [r2], -r1, lsl #2 */
/* @0x314742 ldrsbtgt pc, [r0], #-131 */
/* @0x314746 strbmi r4, [r0, r11, asr #12]! */
/* @0x31474a strhlo pc, [r0], -r9 */
/* @0x31474e ldmdahi r11!, {r0, r1, r5, r8, r9, sp, lr} */
/* @0x314752 rfeia r5! */
/* @0x314756 .word 0xf64f3174 */
/* @0x31475a addsmi r7, r3, #-268435441 */
/* @0x31475e rfeib r5! */
/* @0x314762 rfeib r5! */
/* @0x314766 rfeib r5! */
/* @0x31476a rfeib r5! */
/* @0x31476e bne 0xff7e0aee <b2_toiTime+0xffffffffff08764a> */
/* @0x314772 blvs 0x1bed506 <b2_toiTime+0x1494062> */
/* @0x314776 blmi 0x15ed70a <b2_toiTime+0xe94266> */
/* @0x31477a movwhs r6, #0x4a3 */
/* @0x31477e .word 0xf1b867e3 */
/* @0x314782 andle r0, r6, r0, lsl #30 */
/* @0x314786 strhlo pc, [lr], -r8 */
/* @0x31478a svclt #0x9c2b17 */
/* @0x31478e orrvc pc, r0, #1325400064 */
/* @0x314792 svcvs #0xe367e3 */
/* @0x314796 .word 0xf043ad0d */
/* @0x31479a strbvs r0, [r3, r4, lsl #6]! */
/* @0x31479e .word 0xf5b3682b */
/* @0x3147a2 smlabble r7, r0, pc, r3 */
/* @0x3147a6 .word 0xf5b368eb */
/* @0x3147aa smlabble r3, r0, pc, r3 */
/* @0x3147ae stmdblt r11, {r0, r1, r3, r5, r6, r11, sp, lr} */
/* @0x3147b2 cmnlt r3, r11, lsr #17 */
/* @0x3147b6 rsbeq pc, r12, r4, lsl #2 */
/* @0x3147ba .word 0xf7d14629 */
/* @0x3147be stmdavs r9!, {r5, r6, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3147c2 .word 0xf7d06aa0 */
/* @0x3147c6 stmvs r9!, {r1, r6, r8, r9, r11, r12, sp, lr, pc} ^ */
/* @0x3147ca blvs 0x1b2d252 <b2_toiTime+0x13d3dae> */
/* @0x3147ce blx 0x1292718 <b2_toiTime+0xb39274> */
/* @0x3147d2 bls 0x52d55a <SrcVerts+0x8a59e> */
/* @0x3147d6 blls 0x4c2c06 <SrcVerts+0x1fc4a> */
/* @0x3147da bls 0x4c0d8e <SrcVerts+0x1ddd2> */
/* @0x3147de rsbeq pc, r12, r4, lsl #2 */
/* @0x3147e2 .word 0xf7d19908 */
/* @0x3147e6 bvs 0xfec14066 <b2_toiTime+0xfffffffffe4babc2> */
/* @0x3147ea ldrmi r9, [r3], #-2568 */
/* @0x3147ee adcvs r9, r3, #24576 */
/* @0x3147f2 ldrmi r6, [r3], #-2915 */
/* @0x3147f6 blls 0x5ed58a <g_SWFaavertbuff+0x1a4c2> */
/* @0x3147fa bls 0x580c2e <g_SWFlineaavertbuff+0x2db66> */
/* @0x3147fe blls 0x50156e <SrcVerts+0x5e5b2> */
/* @0x314802 .word 0xf8d46f25 */
/* @0x314806 .word 0xf8d480a4 */
/* @0x31480a smultblt r3, r8, r0 */
/* @0x31480e cmplt r3, r6, lsr #22 */
/* @0x314812 bvs 0xfeb2611e <b2_toiTime+0xfffffffffe3ccc7a> */
/* @0x314816 blx 0x992760 <b2_toiTime+0x2392bc> */
/* @0x31481a adcvs r4, r0, #59768832 */
/* @0x31481e .word 0xf7d06b60 */
/* @0x314822 msrvs SPSR, #20, #22 */
/* @0x314826 rfeib r4! */
/* @0x31482a strhs r9, [r0], -lr, rrx */
/* @0x31482e movweq lr, #0x9bc6 */
/* @0x314832 blhs 0x321c5a */
/* @0x314836 strbmi sp, [r1], -r12, ror #27 */
/* @0x31483a .word 0x0c08f855 */
/* @0x31483e blx 0x492788 <g_prim_v+0x277c> */
/* @0x314842 .word 0x36014639 */
/* @0x314846 .word 0x0c08f845 */
/* @0x31484a .word 0x0c04f855 */
/* @0x31484e blx 0x292796 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x136> */
/* @0x314852 .word 0x0c04f845 */
/* @0x314856 ldcge p7, c14, [r1, #-936] */
/* @0x31485a rsbeq pc, r12, r4, lsl #2 */
/* @0x31485e .word 0xf7d14629 */
/* @0x314862 stmdavs r11!, {r2, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x314866 stmdavs r9!, {r1, r3, r5, r7, r11, sp, lr} ^ */
/* @0x31486a ldrdvs r1, r2, [r2, r2]! */
/* @0x31486e eorvs r6, r3, #15335424 */
/* @0x314872 mvnvs r1, r1, asr r10 */
/* @0x314876 .word 0xf1ba6262 */
/* @0x31487a andle r0, r6, r0, lsl #30 */
/* @0x31487e bl 0x3af30e <error_g0017+0x7fb2> */
/* @0x314882 bl 0xfebf13d2 <b2_toiTime+0xfffffffffe497f2e> */
/* @0x314886 rscvs r0, r3, #-2013265919 */
/* @0x31488a .word 0xf01be6f6 */
/* @0x31488e .word 0xf43f0f10 */
/* @0x314892 .word 0xf104aef3 */
/* @0x314896 blvs 0x1b548fe <b2_toiTime+0x13fb45a> */
/* @0x31489a mcr2 p7, #0x1, pc, c1, c0, #0x6 */
/* @0x31489e .word 0xf50de6ec */
/* @0x3148a2 pop {r0, r1, r2, r3, r6, r8, r10, r11, r12, sp, lr} */
/* @0x3148a6 strbtvc r8, [r12], #-4080 */
/* @0x3148aa ldrlt r6, [r0, #-0xf75]! */
/* @0x3148ae stmdblt r9, {r3, r4, r5, r6, r8, r12, sp, pc} */
/* @0x3148b2 movweq pc, #0x3043 */
/* @0x3148b6 strle r0, [r5], #-2012 */
/* @0x3148ba stmdavs sp, {r0, r3, r5, r8, r12, sp, pc} */
/* @0x3148be adcmi r6, r5, #68, #16 */
/* @0x3148c2 and sp, r0, r7, lsl #2 */
/* @0x3148c6 pop {r8, sp} */
/* @0x3148ca .word 0xf7ff4030 */
/* @0x3148ce eorhs r11, r5, r10, ror r12 */
/* @0x3148d2 eorhs r11, r3, r0, lsr sp */
/* @0x3148d6 push {r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x3148da .word 0x469147ff */
/* @0x3148de strmi r6, [r4], -r2, lsl #17 */
/* @0x3148e2 ldrsbhi pc, [r4], #-128 */
/* @0x3148e6 ldreq r4, [r0, -lr, lsl #12] */
/* @0x3148ea strble r9, [r7, #-0xf0c] */
/* @0x3148ee svceq #0x10f013 */
/* @0x3148f2 adcshs pc, r12, #148, #16 */
/* @0x3148f6 ldmdblt r10, {r5, r12, lr, pc} */
/* @0x3148fa sbchs pc, r0, #212, #16 */
/* @0x3148fe ldrle r0, [r11, #-0x6d1]! */
/* @0x314902 .word 0x2124f894 */
/* @0x314906 eorsle r2, r9, r0, lsl #20 */
/* @0x31490a beq 0x650d46 <g_SWFaavertbuff+0x7dc7e> */
/* @0x31490e stmdaeq lr, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x314912 strbmi r2, [sp, #-0x500] */
/* @0x314916 .word 0xf8d4d04d */
/* @0x31491a uadd16mi r2, r3, r12 */
/* @0x31491e andhi pc, r0, sp, asr #17 */
/* @0x314922 .word 0x21014620 */
/* @0x314926 ldrsbtgt pc, [r0], #-130 */
/* @0x31492a strbmi r1, [r0, r10, lsr #19]! */
/* @0x31492e strhlo pc, [lr], -sp */
/* @0x314932 eorlo pc, r5, r7, asr #16 */
/* @0x314936 strb r3, [r12, r1, lsl #10]! */
/* @0x31493a .word 0xf8d4b91a */
/* @0x31493e ldreq r2, [r2, r0, asr #5] */
/* @0x314942 rfeia r4! */
/* @0x314946 strdlt r2, r3, [r10, #10] */
/* @0x31494a beq 0x650d86 <g_SWFaavertbuff+0x7dcbe> */
/* @0x31494e stmdaeq lr, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x314952 strbmi r2, [sp, #-0x500] */
/* @0x314956 .word 0xf8d4d02d */
/* @0x31495a uadd16mi r2, r3, r12 */
/* @0x31495e andhi pc, r0, sp, asr #17 */
/* @0x314962 .word 0x21004620 */
/* @0x314966 ldrsbtgt pc, [r0], #-130 */
/* @0x31496a strbmi r1, [r0, r10, lsr #19]! */
/* @0x31496e strhlo pc, [lr], -sp */
/* @0x314972 eorlo pc, r5, r7, asr #16 */
/* @0x314976 strb r3, [r12, r1, lsl #10]! */
/* @0x31497a ands r2, r11, r7 */
/* @0x31497e bvc 0xfe351a92 <b2_toiTime+0xfffffffffdbf85ee> */
/* @0x314982 .word 0x463544b1 */
/* @0x314986 .word 0xf00a3f04 */
/* @0x31498a strbmi r0, [sp, #-0x610] */
/* @0x31498e .word 0x4640d011 */
/* @0x314992 strtmi r6, [r10], -r1, lsr #27 */
/* @0x314996 .word 0xf7ff4653 */
/* @0x31499a ldmdblt r8, {r3, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x31499e ldrsbths pc, [r8], -r8 */
/* @0x3149a2 .word 0xf8d83501 */
/* @0x3149a6 mcrhs p0, #0x0, r3, c0, c12, #0x1 */
/* @0x3149aa sadd16mi r11, r10, r8 */
/* @0x3149ae svchs #0x4f847 */
/* @0x3149b2 andhs lr, r0, r11, ror #15 */
/* @0x3149b6 pop {r2, r12, sp, pc} */
/* @0x3149ba strlt r8, [r8, #-0x7f0] */

/* ── FUNC 0x30a6db · af_shaper_get_cluster · size=184 · insn=0 */

/* ── FUNC 0x30a793 · af_shaper_get_elem · size=32 · insn=0 */

/* ── FUNC 0x3149bc · anon_3149bc · size=16 · insn=4 */
/* @0x3149bc tstlt r8, r8, lsl #10 */
/* @0x3149c0 andshs r2, r8, #0, #2 */
/* @0x3149c4 ldcl p5, c15, [r4, #644]! */
/* @0x3149c8 strlt r11, [r8, #-0xd08] */

/* ── FUNC 0x3149bd · FT_Bitmap_Init · size=14 · insn=0 */

/* ── FUNC 0x3149ca · anon_3149ca · size=16 · insn=4 */
/* @0x3149ca tstlt r8, r8, lsl #10 */
/* @0x3149ce andshs r2, r8, #0, #2 */
/* @0x3149d2 stcl p5, c15, [lr, #644]! */
/* @0x3149d6 push {r3, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x3149cb · FT_Bitmap_New · size=14 · insn=0 */

/* ── FUNC 0x3149d8 · anon_3149d8 · size=1136 · insn=284 */
/* @0x3149d8 svcmi #0xf0e92d */
/* @0x3149dc movwhs r11, #0x85 */
/* @0x3149e0 ldrmi r4, [r4], -sp, lsl #12 */
/* @0x3149e4 stmdahs r0, {r0, r1, r8, r9, r12, pc} */
/* @0x3149e8 stmdbhs r0, {r2, r3, r5, r6, r12, lr, pc} */
/* @0x3149ec bhs 0x348ba4 */
/* @0x3149f0 addsmi sp, r1, #106 */
/* @0x3149f4 andhs sp, r0, r1, lsl #2 */
/* @0x3149f8 stmvs pc, {r0, r1, r2, r5, r6, sp, lr, pc} */
/* @0x3149fc .word 0xf8d16892 */
/* @0x314a00 svchs #0xc00c */
/* @0x314a04 .word 0xf04fbfac */
/* @0x314a08 .word 0xf04f0901 */
/* @0x314a0c bhs 0x323210 */
/* @0x314a10 .word 0xf04fbfac */
/* @0x314a14 .word 0xf04f0801 */
/* @0x314a18 .word 0xf1bc38ff */
/* @0x314a1c .word 0xd10b0f00 */
/* @0x314a20 strtmi r12, [r6], -pc, lsl #26 */
/* @0x314a24 strgt r4, [pc], -r1, asr #11 */
/* @0x314a28 muleq r3, r5, r8 */
/* @0x314a2c andeq lr, r3, r6, lsl #17 */
/* @0x314a30 rsbsmi sp, pc, #225 */
/* @0x314a34 ldrb r6, [lr, r7, lsr #1] */
/* @0x314a38 b 0xfe4eea6c <b2_toiTime+0xfffffffffdd955c8> */
/* @0x314a3c bl 0xfedb35e0 <b2_toiTime+0xfffffffffe65a13c> */
/* @0x314a40 stmdavs r0, {r0, r1, r2, r5, r6, r7, r9, r11, r12, sp, lr} */
/* @0x314a44 blx 0x5d365a <g_SWFaavertbuff+0x592> */
/* @0x314a48 cmnlt r3, r3, ror #17 */
/* @0x314a4c bhs 0x32ead8 */
/* @0x314a50 subsmi r11, r2, #184, #30 */
/* @0x314a54 ldrbmi r4, [r10, #-0x34a] */
/* @0x314a58 movwls sp, #0xc */
/* @0x314a5c blge 0x3dce68 <error_g0017+0x35b0c> */
/* @0x314a60 ldrbmi r9, [r11], -r1, lsl #6 */
/* @0x314a64 blx 0xff8529b8 <b2_toiTime+0xffffffffff0f9514> */
/* @0x314a68 ldrbmi lr, [r9], -r3 */
/* @0x314a6c .word 0xf7d2aa03 */
/* @0x314a70 rscvs pc, r0, r7, asr #22 */
/* @0x314a74 bllt 0x9fb688 <b2_toiTime+0x2a21e4> */
/* @0x314a78 strtmi r4, [r6], -pc, lsr #12 */
/* @0x314a7c strbmi r12, [r1, #0xf0f] */
/* @0x314a80 .word 0xc00cf8d4 */
/* @0x314a84 ldm r7, {r0, r1, r2, r3, r9, r10, lr, pc} */
/* @0x314a88 stm r6, {r0, r1} */
/* @0x314a8c .word 0xf8c40003 */
/* @0x314a90 stmvs r9!, {r2, r3, lr, pc} ^ */
/* @0x314a94 strbtmi sp, [r0], -r4, lsl #2 */
/* @0x314a98 .word 0xf5a1465a */
/* @0x314a9c mul pc, r0, sp */
/* @0x314aa0 strmi r6, [sp], -r4, lsr #16 */
/* @0x314aa4 blx 0x3dc43a <error_g0017+0x350de> */
/* @0x314aa8 mrslt r12, spsr */
/* @0x314aac strtmi r4, [r9], -r0, ror #12 */
/* @0x314ab0 ldrbmi r4, [r5], #-1618 */
/* @0x314ab4 stc p5, c15, [r2, #644] */
/* @0x314ab8 bl 0xff5a3ac4 <b2_toiTime+0xfffffffffee4a620> */
/* @0x314abc ldrb r0, [r4, r0, lsl #24]! */
/* @0x314ac0 and r9, r2, r3, lsl #16 */
/* @0x314ac4 and r2, r0, r1, lsr #32 */
/* @0x314ac8 andlt r2, r5, r6 */
/* @0x314acc svchi #0xf0e8bd */
/* @0x314ad0 svcmi #0xf0e92d */
/* @0x314ad4 strmi r11, [r12], -r9, lsl #1 */
/* @0x314ad8 .word 0x21004615 */
/* @0x314adc swpls r4, r11, [r7] */
/* @0x314ae0 .word 0xf0002800 */
/* @0x314ae4 stmdblt r12, {r0, r3, r5, r6, r8, pc} */
/* @0x314ae8 .word 0xe1662006 */
/* @0x314aec rscsle r2, r11, r0, lsl #20 */
/* @0x314af0 .word 0xf8d07ca3 */
/* @0x314af4 bllo 0x374afc <_ZTS13C_UTF16String+0xbba8> */
/* @0x314af8 ldmdale sp!, {r1, r2, r8, r9, r11, sp} */
/* @0x314afc ldrvc r2, [r3], #770 */
/* @0x314b00 .word 0xf1bb6827 */
/* @0x314b04 .word 0xf8d20f00 */
/* @0x314b08 .word 0xf8d29000 */
/* @0x314b0c andsvs r10, r7, r8 */
/* @0x314b10 subsvs r6, r3, r3, ror #16 */
/* @0x314b14 stcle p8, c6, [r6, #-408] */
/* @0x314b18 uasxmi r4, r9, r0 */
/* @0x314b1c stmdb r6!, {r2, r12, sp, lr, pc} ^ */
/* @0x314b20 bl 0xff380f4c <b2_toiTime+0xfffffffffec27aa8> */
/* @0x314b24 strmi r0, [lr], #-267 */
/* @0x314b28 stcle p14, c2, [r6, #-0] */
/* @0x314b2c rscslo pc, pc, pc, asr #32 */
/* @0x314b30 .word 0xf0044631 */
/* @0x314b34 addmi lr, r7, #9043968 */
/* @0x314b38 .word 0xf1bad8d6 */
/* @0x314b3c svclt #0xb80f00 */
/* @0x314b40 beq 0x351270 */
/* @0x314b44 .word 0xf306fb07 */
/* @0x314b48 .word 0xf20afb09 */
/* @0x314b4c stmdale r4, {r0, r1, r4, r7, r9, lr} */
/* @0x314b50 blhs 0x32ee04 */
/* @0x314b54 rsbsmi sp, r6, #57344 */
/* @0x314b58 stmvs r9!, {r2, r3, sp, lr, pc} ^ */
/* @0x314b5c .word 0x91004640 */
/* @0x314b60 mrsls r10, apsr */
/* @0x314b64 .word 0xf7d32101 */
/* @0x314b68 rscvs pc, r8, r3, asr r10 */
/* @0x314b6c stmdahs r0, {r0, r1, r2, r11, r12, pc} */
/* @0x314b70 smulwt r2, lr, r0 */
/* @0x314b74 and r6, r1, lr, lsr #1 */
/* @0x314b78 movwls r2, #0x7306 */
/* @0x314b7c stmvs r7!, {r0, r1, r5, r7, r11, sp, lr} ^ */
/* @0x314b80 stmvs lr!, {r8, r9, r11, sp} ^ */
/* @0x314b84 stmdavs r2!, {r0, r1, r9, r11, r12, lr, pc} */
/* @0x314b88 blx 0x3a3396 <af_blue_strings+0x1072> */
/* @0x314b8c stmvs r11!, {r0, r1, r4, r8, r9, r10, r12, sp, lr} */
/* @0x314b90 ble 0x3df798 <error_g0017+0x3843c> */
/* @0x314b94 blo 0x36ec44 <_ZTS13C_UTF16String+0x5cf0> */
/* @0x314b98 ldrvs pc, [r3], -r2, lsl #22 */
/* @0x314b9c bllo 0x373e30 <_ZTS13C_UTF16String+0xaedc> */
/* @0x314ba0 .word 0xf2002b06 */
/* @0x314ba4 ldm pc, {r0, r1, r2, r8, pc} ^ */
/* @0x314ba8 .word 0x4c04f003 */
/* @0x314bac .word 0x4c4c9a63 */
/* @0x314bb0 movwhs r0, #0x20c0 */
/* @0x314bb4 stmdavs r0!, {r0, r1, r3, r5, r9, pc} */
/* @0x314bb8 .word 0xf0002800 */
/* @0x314bbc stmdavs r3!, {r0, r1, r3, r4, r5, r6, r7, pc} ^ */
/* @0x314bc0 b 0x16dcfc8 <b2_toiTime+0xf83b24> */
/* @0x314bc4 .word 0x46330cd3 */
/* @0x314bc8 eorle r4, r3, r1, ror #10 */
/* @0x314bcc movwlo r5, #0x8c7a */
/* @0x314bd0 b 0x16e0fdc <b2_toiTime+0xf87b38> */
/* @0x314bd4 .word 0xf80318d2 */
/* @0x314bd8 vmull.u8 q12, d2, d8 */
/* @0x314bdc .word 0xf8031880 */
/* @0x314be0 vmull.u8 q12, d2, d7 */
/* @0x314be4 .word 0xf8031840 */
/* @0x314be8 vmull.u8 q12, d2, d6 */
/* @0x314bec .word 0xf8031800 */
/* @0x314bf0 vmull.u8 q12, d2, d5 */
/* @0x314bf4 .word 0xf80308c0 */
/* @0x314bf8 vmull.u8 q12, d2, d4 */
/* @0x314bfc .word 0xf8030880 */
/* @0x314c00 vmull.u8 q12, d2, d3 */
/* @0x314c04 .word 0xf0020840 */
/* @0x314c08 .word 0xf8030201 */
/* @0x314c0c .word 0xf8038c02 */
/* @0x314c10 ldrb r2, [r9, r1, lsl #24] */
/* @0x314c14 bl 0x4aeda4 <SrcVerts+0xbde8> */
/* @0x314c18 .word 0xf01203c1 */
/* @0x314c1c andle r0, r10, r7, lsl #24 */
/* @0x314c20 bl 0x3ebe10 <_ZTV13CGesturePinch+0x10> */
/* @0x314c24 vaddw.u8 q8, q1, d12 */
/* @0x314c28 .word 0xf8031cc0 */
/* @0x314c2c addmi r12, r11, #1024 */
/* @0x314c30 subeq lr, r2, #323584 */
/* @0x314c34 stmvs r3!, {r0, r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x314c38 ldrmi r3, [pc], #-2049 */
/* @0x314c3c ldrmi r6, [lr], #-2219 */
/* @0x314c40 .word 0xf8d4e7ba */
/* @0x314c44 vst4.8 {d25, d26, d27, d28}, [pc], r4 */
/* @0x314c48 eorhi r7, r11, #128, #6 */
/* @0x314c4c .word 0x8000f8d4 */
/* @0x314c50 svceq #0xf1b8 */
/* @0x314c54 adchi pc, lr, r0 */
/* @0x314c58 shasxmi r4, r9, r0 */
/* @0x314c5c .word 0xf108464a */
/* @0x314c60 .word 0xf5a138ff */
/* @0x314c64 stmvs r3!, {r2, r3, r5, r7, r10, r11, sp, lr, pc} */
/* @0x314c68 stmvs r11!, {r0, r1, r2, r3, r4, r10, lr} */
/* @0x314c6c .word 0xe7ef441e */
/* @0x314c70 eorhi r2, r11, #4, #6 */
/* @0x314c74 stmdahs r0, {r5, r11, sp, lr} */
/* @0x314c78 addshi pc, r12, r0 */
/* @0x314c7c ldrtmi r6, [r2], -r3, ror #16 */
/* @0x314c80 vldmiaeq r3, {s28, s29, s30, s31} */
/* @0x314c84 strbmi r2, [r3, #-0x300]! */
/* @0x314c88 ldclpl p0, c13, [r9], #76 */
/* @0x314c8c movwlo r3, #0x1204 */
/* @0x314c90 ldmne r1, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x314c94 .word 0x8c04f802 */
/* @0x314c98 stmdane r1, {r0, r6, r7, r8, r9, r12, sp, lr, pc} */
/* @0x314c9c .word 0x8c03f802 */
/* @0x314ca0 stmeq r1, {r0, r6, r7, r8, r9, r12, sp, lr, pc} */
/* @0x314ca4 mrseq pc, apsr */
/* @0x314ca8 .word 0x8c02f802 */
/* @0x314cac .word 0x1c01f802 */
/* @0x314cb0 stmdavs r1!, {r0, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x314cb4 addeq lr, r3, #6144 */
/* @0x314cb8 .word 0x0103f011 */
/* @0x314cbc ldclpl p0, c13, [r11], #36 */
/* @0x314cc0 vmov.i32 d20, #0xb10000 */
/* @0x314cc4 .word 0xf8021c81 */
/* @0x314cc8 addmi r12, r10, #1024 */
/* @0x314ccc orreq lr, r3, #323584 */
/* @0x314cd0 stmvs r3!, {r0, r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} */
/* @0x314cd4 ldrmi r3, [pc], #-2049 */
/* @0x314cd8 ldrmi r6, [lr], #-2219 */
/* @0x314cdc tsths r0, #53215232 */
/* @0x314ce0 stmdavs r1!, {r0, r1, r3, r5, r9, pc} */
/* @0x314ce4 rsble r2, r5, r0, lsl #18 */
/* @0x314ce8 ldrtmi r6, [r2], -r3, ror #16 */
/* @0x314cec .word 0x0c53ea4f */
/* @0x314cf0 strbmi r2, [r3, #-0x300]! */
/* @0x314cf4 andeq pc, r2, #-2147483648 */
/* @0x314cf8 ldclpl p0, c13, [r8], #40 */
/* @0x314cfc b 0x16e1908 <b2_toiTime+0xf88464> */
/* @0x314d00 .word 0xf0001810 */
/* @0x314d04 .word 0xf802000f */
/* @0x314d08 .word 0xf8028c02 */
/* @0x314d0c ldrb r0, [r0, r1, lsl #24]! */
/* @0x314d10 ldrbeq r6, [r2, r2, ror #16] */
/* @0x314d14 ldclpl p5, c13, [r10], #12 */
/* @0x314d18 .word 0xf8060912 */
/* @0x314d1c stmvs r3!, {r0, r1, r4, sp} */
/* @0x314d20 ldrmi r3, [pc], #-2305 */
/* @0x314d24 ldrmi r6, [lr], #-2219 */
/* @0x314d28 vst1.64 {d30}, [pc:64], r12 */
/* @0x314d2c eorhi r7, r11, #128, #6 */
/* @0x314d30 .word 0xa000f8d4 */
/* @0x314d34 rsbvs pc, sp, #805306372 */
/* @0x314d38 svceq #0xf1ba */
/* @0x314d3c stmdavs r1!, {r1, r3, r4, r5, r12, lr, pc} ^ */
/* @0x314d40 .word 0x46b846b3 */
/* @0x314d44 .word 0x0c01eb06 */
/* @0x314d48 eorle r4, r12, r3, ror #11 */
/* @0x314d4c mulls r3, r8, r8 */
/* @0x314d50 svceq #0xf1b9 */
/* @0x314d54 .word 0xf898d022 */
/* @0x314d58 vhadd.s8 d16, d1, d0 */
/* @0x314d5c .word 0xf898237c */
/* @0x314d60 .word 0xf898e001 */
/* @0x314d64 blx 0x718d76 <g_SWFvertbuff+0x45cae> */
/* @0x314d68 andls pc, r4, #0 */
/* @0x314d6c .word 0xfe0efb1e */
/* @0x314d70 andsgt pc, r4, sp, asr #17 */
/* @0x314d74 .word 0xf101fb11 */
/* @0x314d78 .word 0xf24b4358 */
/* @0x314d7c blx 0x3f19e2 */
/* @0x314d80 blx 0x3985c2 <ft_adobe_glyph_list+0x7c9e> */
/* @0x314d84 strbmi lr, [r9], -r1 */
/* @0x314d88 .word 0xf0030c00 */
/* @0x314d8c bls 0x450b0c <g_RomDisk+0x592ec> */
/* @0x314d90 ldrsbgt pc, [r4], -sp */
/* @0x314d94 andeq lr, r9, r0, asr #23 */
/* @0x314d98 .word 0xf980fa5f */
/* @0x314d9c blls 0x392dd0 <ft_adobe_glyph_list+0x24ac> */
/* @0x314da0 stmdaeq r4, {r3, r8, r12, sp, lr, pc} */
/* @0x314da4 stmvs r1!, {r4, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x314da8 blo 0x3111d8 <af_shaper_get_elem+0x6a46> */
/* @0x314dac stmvs r9!, {r0, r1, r2, r3, r10, lr} */
/* @0x314db0 strb r4, [r1, lr, lsl #8] */
/* @0x314db4 and r9, r0, r7, lsl #16 */
/* @0x314db8 andlt r2, r9, r1, lsr #32 */
/* @0x314dbc svchi #0xf0e8bd */
/* @0x314dc0 .word 0x4606b5f0 */
/* @0x314dc4 tstlt r8, #135 */
/* @0x314dc8 bmi 0x7effdc <b2_toiTime+0x96b38> */
/* @0x314dcc .word 0xd1204293 */
/* @0x314dd0 ldrsblo pc, [r12], r0 */
/* @0x314dd4 .word 0x07db685b */
/* @0x314dd8 .word 0xf106d41b */
/* @0x314ddc strbtmi r0, [r8], -r12, asr #8 */
/* @0x314de0 stc2l p7, c15, [r12, #1020]! */
/* @0x314de4 qasxmi r6, r1, r0 */
/* @0x314de8 .word 0xf7ff466a */
/* @0x314dec .word 0x4607fdf5 */
/* @0x314df0 strbtmi r11, [sp], -r0, ror #18 */
/* @0x314df4 strgt r12, [pc], #-3343 */
/* @0x314df8 muleq r3, r5, r8 */
/* @0x314dfc andeq lr, r3, r4, lsl #17 */
/* @0x314e00 ldrsblo pc, [r12], r6 */
/* @0x314e04 .word 0xf042685a */
/* @0x314e08 subsvs r0, r10, r1, lsl #4 */
/* @0x314e0c and r4, r1, r8, lsr r6 */
/* @0x314e10 andhs lr, r0, r0 */
/* @0x314e14 ldcllt p0, c11, [r0, #28]! */
/* @0x314e18 rsbvs r7, r9, #1929379840 */
/* @0x314e1c .word 0x460cb538 */
/* @0x314e20 cmnlt r1, r8, ror #2 */
/* @0x314e24 stmdavs r0, {r8, r10, sp} */
/* @0x314e28 .word 0xf7d268c9 */
/* @0x314e2c rscvs pc, r5, r4, lsl #21 */
/* @0x314e30 strtmi r4, [r9], -r0, lsr #12 */
/* @0x314e34 .word 0xf5a12218 */
/* @0x314e38 .word 0x4628ebbc */
/* @0x314e3c eorhs r11, r1, r8, lsr sp */
/* @0x314e40 andhs r11, r6, r8, lsr sp */
/* @0x314e44 push {r3, r4, r5, r8, r10, r11, r12, sp, pc} */

/* ── FUNC 0x3149d9 · FT_Bitmap_Copy · size=248 · insn=0 */

/* ── FUNC 0x314ad1 · FT_Bitmap_Convert · size=752 · insn=0 */

/* ── FUNC 0x314dc1 · FT_GlyphSlot_Own_Bitmap · size=92 · insn=0 */

/* ── FUNC 0x314e1d · FT_Bitmap_Done · size=42 · insn=0 */

/* ── FUNC 0x314e46 · anon_314e46 · size=7292 · insn=1823 */
/* @0x314e46 svcmi #0xf0e92d */
/* @0x314e4a addlt r4, pc, r12, lsl #12 */
/* @0x314e4e stmdahs r0, {r0, r7, r9, r10, lr} */
/* @0x314e52 orrshi pc, r1, r0 */
/* @0x314e56 .word 0xf0002900 */
/* @0x314e5a stmvs r9, {r1, r4, r7, r8, pc} ^ */
/* @0x314e5e .word 0xf0002900 */
/* @0x314e62 cps #0xe */
/* @0x314e66 .word 0x33200520 */
/* @0x314e6a b 0x16d9526 <b2_toiTime+0xf80082> */
/* @0x314e6e vstrhs d1, [r0, #-652] */
/* @0x314e72 .word 0xf1bbd103 */
/* @0x314e76 .word 0xd1020f00 */
/* @0x314e7a vbic.i32 q15, #0xf */
/* @0x314e7e .word 0xf1bb8180 */
/* @0x314e82 .word 0xf2c00f00 */
/* @0x314e86 stcvc p1, c8, [r3], #496 */
/* @0x314e8a blhs 0x4a3a96 <SrcVerts+0xada> */
/* @0x314e8e ldm pc, {r0, r1, r3, r5, r11, r12, lr, pc} ^ */
/* @0x314e92 eoreq pc, r0, r3, lsl r0 */
/* @0x314e96 andeq r0, r7, r10, lsr #32 */
/* @0x314e9a eoreq r0, r4, r7 */
/* @0x314e9e cmneq r8, r7, lsr #32 */
/* @0x314ea2 ldrtmi r10, [r8], -r8, lsl #30 */
/* @0x314ea6 stc2 p7, c15, [r9, #1020] */
/* @0x314eaa strtmi r4, [r1], -r8, asr #12 */
/* @0x314eae movwhs r4, #0x163a */
/* @0x314eb2 mcr2 p7, #0x0, pc, c13, c15, #0x7 */
/* @0x314eb6 .word 0xf0402800 */
/* @0x314eba strtmi r8, [r1], -r5, ror #2 */
/* @0x314ebe .word 0xf7ff4648 */
/* @0x314ec2 svcgt #0xfffac */
/* @0x314ec6 strgt r4, [pc], -r6, lsr #12 */
/* @0x314eca muleq r3, r7, r8 */
/* @0x314ece andeq lr, r3, r6, lsl #17 */
/* @0x314ed2 stchs p0, c14, [r8, #-36] */
/* @0x314ed6 strhs r11, [r8, #-0xfa8] */
/* @0x314eda movwhs lr, #0x3005 */
/* @0x314ede and r4, r2, sp, asr r3 */
/* @0x314ee2 blx 0x3ddaf8 <error_g0017+0x3679c> */
/* @0x314ee6 .word 0xf8d9fb0b */
/* @0x314eea stcvc p0, c6, [r3], #0 */
/* @0x314eee bllo 0x36f192 <_ZTS13C_UTF16String+0x623e> */
/* @0x314ef2 ldm r4, {r1, r2, r9, r10, r12, pc} */
/* @0x314ef6 svchs #0x600 */
/* @0x314efa rsbsmi r11, pc, #184, #30 */
/* @0x314efe .word 0xf2002b05 */
/* @0x314f02 ldm pc, {r1, r3, r4, r5, r7, pc} ^ */
/* @0x314f06 stmdane r3, {r0, r1, r12, sp, lr, pc} */
/* @0x314f0a ldmdane r8, {r1, r3, r8, r12} */
/* @0x314f0e streq pc, [r7], -r10, lsl #2 */
/* @0x314f12 stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x314f16 ldmeq r6!, {r1, r2, r3, r5, r10, lr} ^ */
/* @0x314f1a .word 0xf10ae011 */
/* @0x314f1e .word 0xf04f0603 */
/* @0x314f22 strtmi r0, [lr], #-2050 */
/* @0x314f26 strh r0, [r10], -r6 */
/* @0x314f2a streq pc, [r1], -r10, lsl #2 */
/* @0x314f2e stmdaeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x314f32 ldmdaeq r6!, {r1, r2, r3, r5, r10, lr} ^ */
/* @0x314f36 bl 0x48cf4a <prim_v+0x3596> */
/* @0x314f3a .word 0xf04f060a */
/* @0x314f3e .word 0xf1bb0808 */
/* @0x314f42 teqle r3, r0, lsl #30 */
/* @0x314f46 ldcle p2, c4, [r1], #-760 */
/* @0x314f4a streq lr, [r10], -r5, lsl #22 */
/* @0x314f4e .word 0xf608fb06 */
/* @0x314f52 svceq #0xc7ebb6 */
/* @0x314f56 addhi pc, r7, r0, lsl #1 */
/* @0x314f5a .word 0xf00668e3 */
/* @0x314f5e vst1.8 {d16, d17}, [pc], r7 */
/* @0x314f62 bl 0x3e7166 <error_g0017+0x3fe0a> */
/* @0x314f66 bl 0x3d6ac6 <error_g0017+0x2f76a> */
/* @0x314f6a blx 0xd17f8e <b2_toiTime+0x5beaea> */
/* @0x314f6e strlo pc, [r1], -r10, lsl #16 */
/* @0x314f72 .word 0xf1b91e70 */
/* @0x314f76 rsbsle r0, r6, r0, lsl #30 */
/* @0x314f7a svceq #0xf1ba */
/* @0x314f7e .word 0xf816d006 */
/* @0x314f82 ldrtmi r3, [r0], -r1, lsl #24 */
/* @0x314f86 movweq lr, #0x8a03 */
/* @0x314f8a .word 0x3c01f806 */
/* @0x314f8e andle r4, r8, #96, #10 */
/* @0x314f92 andeq lr, r12, #192, #22 */
/* @0x314f96 .word 0xf8cd2100 */
/* @0x314f9a .word 0xf5a1c010 */
/* @0x314f9e .word 0xf8ddeb08 */
/* @0x314fa2 .word 0xf109c010 */
/* @0x314fa6 ldrtmi r3, [r12], #2559 */
/* @0x314faa .word 0xe7e1443e */
/* @0x314fae blge 0x51d7b6 <SrcVerts+0x7a7fa> */
/* @0x314fb2 .word 0x0109eb0b */
/* @0x314fb6 andls r9, r0, #67108864 */
/* @0x314fba stmdals r6, {r0, r1, r4, r5, r9, r10, lr} */
/* @0x314fbe .word 0xf827f7d3 */
/* @0x314fc2 stmdals r8, {r0, r7, r9, r10, lr} */
/* @0x314fc6 .word 0xf0402800 */
/* @0x314fca stmvs r3!, {r0, r2, r3, r4, r6, r7, pc} */
/* @0x314fce blx 0x553bfe <g_SWFlineaavertbuff+0xb36> */
/* @0x314fd2 .word 0xf10a2b00 */
/* @0x314fd6 vstmdble r11!, {s0, s1, s2, s3, s4, s5, s6} */
/* @0x314fda .word 0x0c09ebc6 */
/* @0x314fde beq 0xff9cf922 <b2_toiTime+0xffffffffff27647e> */
/* @0x314fe2 .word 0xf8cd4680 */
/* @0x314fe6 blx 0x5fd060 <g_SWFaavertbuff+0x29f98> */
/* @0x314fea strmi r12, [r2], -r6, lsl #24 */
/* @0x314fee stmdavs r1!, {r1, r7, r9, r10, lr} */
/* @0x314ff2 ldrtmi r1, [r0], #2515 */
/* @0x314ff6 andsle r4, r0, #578813952 */
/* @0x314ffa bl 0x62f386 <g_SWFaavertbuff+0x5c2be> */
/* @0x314ffe movwls r0, #0x5008 */
/* @0x315002 beq 0x391432 <ft_adobe_glyph_list+0xb0e> */
/* @0x315006 bls 0x4e6052 <SrcVerts+0x43096> */
/* @0x31500a andsgt pc, r0, sp, asr #17 */
/* @0x31500e b 0xff8d269a <b2_toiTime+0xffffffffff1791f6> */
/* @0x315012 .word 0xf8dd9b05 */
/* @0x315016 sadd16mi r12, r10, r0 */
/* @0x31501a stmdals r6, {r0, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x31501e .word 0xf7d268e1 */
/* @0x315022 stmvs r3!, {r0, r3, r7, r8, r11, r12, sp, lr, pc} */
/* @0x315026 andls pc, r12, r4, asr #17 */
/* @0x31502a ble 0x9dfc32 <b2_toiTime+0x28678e> */
/* @0x31502e ands r4, r9, r6, ror r2 */
/* @0x315032 vldmiaeq r10, {s29, s30, s31} */
/* @0x315036 strmi r4, [r2], -r11, asr #12 */
/* @0x31503a stmdavs r1!, {r1, r7, r9, r10, lr} */
/* @0x31503e stmdaeq r7, {r1, r8, r9, r11, sp, lr, pc} */
/* @0x315042 rscle r4, r10, #578813952 */
/* @0x315046 ldrmi r6, [r8], -r1, ror #17 */
/* @0x31504a andsgt pc, r0, sp, asr #17 */
/* @0x31504e beq 0x39147e <ft_adobe_glyph_list+0xb5a> */
/* @0x315052 uqadd16mi r4, r2, r1 */
/* @0x315056 b 0xfefd26e2 <b2_toiTime+0xfffffffffe87923e> */
/* @0x31505a .word 0xf8dd4642 */
/* @0x31505e .word 0x4603c010 */
/* @0x315062 .word 0xe7ea4433 */
/* @0x315066 stmvs r2!, {r1, r2, r5, r7, sp, lr} */
/* @0x31506a stmvs r1!, {sp} ^ */
/* @0x31506e vstrle s4, [r4, #-0] */
/* @0x315072 .word 0x1102fb0b */
/* @0x315076 andshs lr, r2, r6 */
/* @0x31507a stmdavs r3!, {r2, r7, sp, lr, pc} */
/* @0x31507e bllo 0x3659ce <_ZTS12CDS_Priority+0x7a26> */
/* @0x315082 .word 0x1102fb03 */
/* @0x315086 .word 0x0c00f04f */
/* @0x31508a ldrmi r6, [r12, #0x823] */
/* @0x31508e cdpne p2, #0x5, c13, c7, c13, #0x3 */
/* @0x315092 ldclne p8, c1, [lr], #-556 */
/* @0x315096 .word 0xf813d050 */
/* @0x31509a bl 0x3700a6 <_ZTS13C_UTF16String+0x7152> */
/* @0x31509e .word 0xf8cd0807 */
/* @0x3150a2 .word 0x9606801c */
/* @0x3150a6 adcmi r2, lr, #1048576 */
/* @0x3150aa .word 0xf894dc43 */
/* @0x3150ae .word 0xf1b88012 */
/* @0x3150b2 tstle r7, r1, lsl #30 */
/* @0x3150b6 ldrsbls pc, [r8], -sp */
/* @0x3150ba .word 0xf806fa49 */
/* @0x3150be .word 0x9c01f813 */
/* @0x3150c2 stmdaeq r9, {r3, r6, r9, r11, sp, lr, pc} */
/* @0x3150c6 .word 0xf888fa5f */
/* @0x3150ca .word 0x8c01f803 */
/* @0x3150ce .word 0xf813b37f */
/* @0x3150d2 .word 0xf1c6ac02 */
/* @0x3150d6 blx 0x5974fe <g_SWFlineaavertbuff+0x44436> */
/* @0x3150da b 0x1553506 <b2_toiTime+0xdfa062> */
/* @0x3150de .word 0xf8030909 */
/* @0x3150e2 eor r9, r4, r1, lsl #24 */
/* @0x3150e6 stmdaeq r7, {r1, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x3150ea svceq #0xf1b8 */
/* @0x3150ee .word 0xf813db21 */
/* @0x3150f2 .word 0xf1c6ac01 */
/* @0x3150f6 rfeia r4! */
/* @0x3150fa .word 0xf8cd8010 */
/* @0x3150fe .word 0xf8dda00c */
/* @0x315102 .word 0xf81aa01c */
/* @0x315106 .word 0xf8dd9009 */
/* @0x31510a ldrbmi r10, [r1], #12 */
/* @0x31510e .word 0xdc0445c8 */
/* @0x315112 ldmlo pc!, {r3, r8, r12, sp, lr, pc} ^ */
/* @0x315116 .word 0x8c01f803 */
/* @0x31511a blx 0x1b0d14e <b2_toiTime+0x13b3caa> */
/* @0x31511e .word 0xf803f989 */
/* @0x315122 rfeia r4! */
/* @0x315126 .word 0xf1088010 */
/* @0x31512a strbmi r3, [r1, #0x8ff] */
/* @0x31512e strlo sp, [r1], -r1 */
/* @0x315132 svclo #0x1e7b9 */
/* @0x315136 str r3, [r12, r1, lsl #22]! */
/* @0x31513a ldrbmi r2, [lr, #-0x601] */
/* @0x31513e .word 0xdc1068a3 */
/* @0x315142 ldrne pc, [r6, -r3, lsl #22] */
/* @0x315146 addsmi r2, r3, #0, #6 */
/* @0x31514a .word 0xf811da09 */
/* @0x31514e .word 0xf8179003 */
/* @0x315152 b 0x1575166 <b2_toiTime+0xe1bcc2> */
/* @0x315156 .word 0xf8070808 */
/* @0x31515a movwlo r8, #0x1003 */
/* @0x31515e .word 0x3601e7f3 */
/* @0x315162 ldrmi lr, [r9], #-2027 */
/* @0x315166 .word 0x0c01f10c */
/* @0x31516a stmdavs r2!, {r1, r2, r3, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x31516e eorvs r4, r3, r11, asr r4 */
/* @0x315172 rsbvs r4, r5, r5, lsl r4 */
/* @0x315176 eorhs lr, r1, r6 */
/* @0x31517a ldrbmi lr, [r8], -r4 */
/* @0x31517e andhs lr, r6, r2 */
/* @0x315182 andhs lr, r0, r0 */
/* @0x315186 pop {r0, r1, r2, r3, r12, sp, pc} */
/* @0x31518a push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x31518e ldrshtlt r4, [pc], r0 */
/* @0x315192 stclls p6, c4, [r10, #-24] */
/* @0x315196 strmi r9, [r10], -r9, lsl #4 */
/* @0x31519a movwhs r9, #0x30c */
/* @0x31519e tstls pc, #2013265920 */
/* @0x3151a2 .word 0x93219320 */
/* @0x3151a6 .word 0x93239322 */
/* @0x3151aa .word 0x93259324 */
/* @0x3151ae .word 0x93279326 */
/* @0x3151b2 .word 0x93299328 */
/* @0x3151b6 .word 0x932b932a */
/* @0x3151ba .word 0x932d932c */
/* @0x3151be blmi 0x45331e <g_RomDisk+0x5bafe> */
/* @0x3151c2 blo 0x37fec2 <_ZTS13C_UTF16String+0x16f6e> */
/* @0x3151c6 streq lr, [r4], #2819 */
/* @0x3151ca stclo p8, c15, [r0], {84} */
/* @0x3151ce movweq pc, #0x1103 */
/* @0x3151d2 stclo p8, c15, [r0], {68} */
/* @0x3151d6 blls 0xac99a6 <b2_toiTime+0x370502> */
/* @0x3151da smlabble r4, r11, r2, r4 */
/* @0x3151de ldrmi r9, [r0], -r9, asr #24 */
/* @0x3151e2 eorvs r6, r10, r2, lsr #32 */
/* @0x3151e6 stmdavs r10!, {r0, r5, r6, r8, sp, lr, pc} */
/* @0x3151ea strhs r10, [r1], #-3614 */
/* @0x3151ee eorlo pc, r4, r6, asr r8 */
/* @0x3151f2 strlo r11, [r1], #-2323 */
/* @0x3151f6 mvnsle r2, r0, lsl r12 */
/* @0x3151fa movwhs r4, #0xf6a2 */
/* @0x3151fe svclt #0x3842a2 */
/* @0x315202 andls r4, r2, #35651584 */
/* @0x315206 eorhs pc, r3, r6, asr r8 */
/* @0x31520a bllo 0x38363a <_ZTS13C_UTF16String+0x1a6e6> */
/* @0x31520e svcls #0x2d1fa */
/* @0x315212 svclt #0x28429f */
/* @0x315216 eorvs r4, pc, pc, lsl r6 */
/* @0x31521a strls r2, [r2, -r1, lsl #10] */
/* @0x31521e strtmi r4, [r7], -r5, lsr #1 */
/* @0x315222 andle r4, r9, #-268435447 */
/* @0x315226 eorhs pc, r7, r6, asr r8 */
/* @0x31522a strle r1, [r2, #-0xaad] */
/* @0x31522e andeq pc, r2, pc, rrx */
/* @0x315232 smladxlo r1, r11, r1, lr */
/* @0x315236 ldrb r0, [r3, sp, rrx]! */
/* @0x31523a ldmeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x31523e streq lr, [r3, r8, lsl #22] */
/* @0x315242 stchs p8, c15, [r0], {87} */
/* @0x315246 andls r1, r6, #696320 */
/* @0x31524a .word 0xf847d4f0 */
/* @0x31524e .word 0xf10d5c80 */
/* @0x315252 .word 0x270008b8 */
/* @0x315256 ssatmi r4, #0x1d, r10, lsl #12 */
/* @0x31525a blo 0x37af1e <_ZTS13C_UTF16String+0x11fca> */
/* @0x31525e streq pc, [r4, -r7, lsl #2] */
/* @0x315262 ldmibpl r5!, {r1, r2, r12, lr, pc} ^ */
/* @0x315266 bl 0x52651e <SrcVerts+0x83562> */
/* @0x31526a .word 0xf8c50507 */
/* @0x31526e ldrb r12, [r4, r4]! */
/* @0x315272 .word 0xf8504615 */
/* @0x315276 .word 0xb1677025 */
/* @0x31527a ldmibeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x31527e fstmiaxeq r7, {d14, d15, d16, d17} */
/* @0x315282 .word 0xf85c9f4d */
/* @0x315286 .word 0xf1099c40 */
/* @0x31528a .word 0xf84c0801 */
/* @0x31528e .word 0xf8478c40 */
/* @0x315292 strlo r5, [r1, #-0x29] */
/* @0x315296 .word 0xd3ec428d */
/* @0x31529a ldmeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc} ^ */
/* @0x31529e bl 0x53c6ae <obj_has_event+0x1b3e> */
/* @0x3152a2 svcls #0x4d0183 */
/* @0x3152a6 andhs r4, r0, sp, ror #4 */
/* @0x3152aa mcrrne p8, #0x5, pc, r0, c1 */
/* @0x3152ae streq lr, [r4], r6, lsl #22 */
/* @0x3152b2 strls r4, [r4], -r3, lsl #13 */
/* @0x3152b6 .word 0xf04f4680 */
/* @0x3152ba bl 0x4e2ebe <SrcVerts+0x3ff02> */
/* @0x3152be smlabbls r10, r1, r1, r0 */
/* @0x3152c2 eorls r4, lr, r9, lsr #12 */
/* @0x3152c6 andls r9, pc, r7, lsl #10 */
/* @0x3152ca vqrshl.u8 d4, d10, d16 */
/* @0x3152ce .word 0x9c0480e5 */
/* @0x3152d2 bl 0xff59e6de <b2_toiTime+0xfffffffffee4523a> */
/* @0x3152d6 strls r0, [sp, -r3, lsl #14] */
/* @0x3152da strls r6, [r1], #-2084 */
/* @0x3152de ldrbtlo pc, [pc], #266 */
/* @0x3152e2 vst1.8 {d15, d16}, [r4], r5 */
/* @0x3152e6 stcls p4, c9, [r1, #-44] */
/* @0x3152ea stclo p15, c9, [r1, #-4] */
/* @0x3152ee svchs #0x9508 */
/* @0x3152f2 sbchi pc, r12, r0 */
/* @0x3152f6 strmi r9, [r12], #-3074 */
/* @0x3152fa streq lr, [r10], #-3012 */
/* @0x3152fe .word 0x9008f8dd */
/* @0x315302 .word 0xf8cd4489 */
/* @0x315306 strbmi r9, [r10, #0x14] */
/* @0x31530a .word 0xf04fdd65 */
/* @0x31530e stcls p8, c0, [r1, #-4] */
/* @0x315312 blx 0x453b3c <g_RomDisk+0x5c31c> */
/* @0x315316 .word 0x0c01f106 */
/* @0x31531a ldmdble pc, {r0, r1, r3, r5, r7, r8, r10, lr} */
/* @0x31531e ldrsbthi pc, [r4], -sp */
/* @0x315322 strtmi r9, [r0], #3842 */
/* @0x315326 svclt #0x2845b8 */
/* @0x31532a strbmi r4, [r4, #-0x6b8] */
/* @0x31532e .word 0xf8ddd216 */
/* @0x315332 stcls p0, c9, [r4, #-128] */
/* @0x315336 bleq 0x610262 <g_SWFaavertbuff+0x3d19a> */
/* @0x31533a bllo 0x31176e <af_shaper_get_elem+0x6fdc> */
/* @0x31533e strtmi r9, [r5], -r3, lsl #10 */
/* @0x315342 strbmi r3, [r5, #-0x501] */
/* @0x315346 svcls #0x3d20b */
/* @0x31534a bleq 0x160fc8e <b2_toiTime+0xeb67ea> */
/* @0x31534e svcls #0x4f857 */
/* @0x315352 strls r4, [r3, -r11, asr #11] */
/* @0x315356 bl 0xff58b76a <b2_toiTime+0xfffffffffee322c6> */
/* @0x31535a ldrb r0, [r1, r11, lsl #22]! */
/* @0x31535e svcls #0x4c4625 */
/* @0x315362 stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x315366 blx 0x493b90 <g_prim_v+0x3b84> */
/* @0x31536a .word 0x8000f8d7 */
/* @0x31536e stmdbeq r8, {r0, r1, r3, r8, r9, r11, sp, lr, pc} */
/* @0x315372 svcvs #0xb4f5b9 */
/* @0x315376 svcge #0x5af63f */
/* @0x31537a bl 0x4fd0ae <SrcVerts+0x5a0f2> */
/* @0x31537e svcge #0x3e08c8 */
/* @0x315382 streq lr, [r12, r7, lsl #22] */
/* @0x315386 .word 0xf8479703 */
/* @0x31538a svcls #0x4c8cbc */
/* @0x31538e andls pc, r0, r7, asr #17 */
/* @0x315392 svceq #0xf1bc */
/* @0x315396 svcge #0x3ed017 */
/* @0x31539a bl 0x4fb3ae <SrcVerts+0x583f2> */
/* @0x31539e blx 0xb96dbe <b2_toiTime+0x43d91a> */
/* @0x3153a2 .word 0xf856f101 */
/* @0x3153a6 .word 0xf8406cbc */
/* @0x3153aa bl 0xff4a04b2 <b2_toiTime+0xfffffffffed4700e> */
/* @0x3153ae bl 0x4953d6 <g_prim_v+0x53ca> */
/* @0x3153b2 .word 0xf80609c1 */
/* @0x3153b6 bl 0xff369482 <b2_toiTime+0xfffffffffec0ffde> */
/* @0x3153ba stmdbls r2, {r5, r6, r7} */
/* @0x3153be andeq pc, r4, r9, asr #17 */
/* @0x3153c2 andne pc, r1, r9, lsl #17 */
/* @0x3153c6 stclls p0, c14, [r9, #-8] */
/* @0x3153ca andhi pc, r0, r5, asr #17 */
/* @0x3153ce strbtmi r9, [r6], -r7, lsl #30 */
/* @0x3153d2 ldrtmi r9, [r12], #-2309 */
/* @0x3153d6 mcrrls p7, #0x9, lr, sp, c2 */
/* @0x3153da stmdbeq r10, {r0, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x3153de blx 0x1afc80e <b2_toiTime+0x13a336a> */
/* @0x3153e2 .word 0xf8cdf989 */
/* @0x3153e6 adcmi r9, r12, #12 */
/* @0x3153ea stmdavs r0!, {r0, r2, r3, r4, r9, r12, lr, pc} */
/* @0x3153ee adcsmi r9, r8, #9, #30 */
/* @0x3153f2 strlo sp, [r4], #-520 */
/* @0x3153f6 svclt #0x8c28ff */
/* @0x3153fa stmdbeq r0!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^ */
/* @0x3153fe stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x315402 ands r9, r2, sp, asr #8 */
/* @0x315406 .word 0x9024f8dd */
/* @0x31540a bl 0xff57c532 <b2_toiTime+0xfffffffffee2308e> */
/* @0x31540e stclls p0, c0, [sp, #-0] */
/* @0x315412 eorvc pc, r0, r4, asr r8 */
/* @0x315416 strbls r3, [sp, #-0x504] */
/* @0x31541a blx 0x1ae3162 <b2_toiTime+0x1389cbe> */
/* @0x31541e svcls #0xcf987 */
/* @0x315422 eoreq pc, r0, r7, asr r8 */
/* @0x315426 .word 0xf04fe001 */
/* @0x31542a blx 0xb97b32 <b2_toiTime+0x43e68e> */
/* @0x31542e strhs pc, [r1], #-1281 */
/* @0x315432 .word 0x0c0aebc1 */
/* @0x315436 .word 0xfc0cfa04 */
/* @0x31543a strbeq lr, [r5], #2824 */
/* @0x31543e strbeq lr, [r12, pc, asr #20] */
/* @0x315442 ldrbmi r9, [sp, #-0x705] */
/* @0x315446 svcls #0x3d208 */
/* @0x31544a .word 0xf8844465 */
/* @0x31544e rsbvs r9, r0, r0 */
/* @0x315452 svcls #0x57067 */
/* @0x315456 .word 0xe7f4443c */
/* @0x31545a andsmi r9, r5, #704 */
/* @0x31545e streq lr, [r5], #-2690 */
/* @0x315462 andle r4, r1, r2, lsr #12 */
/* @0x315466 ldrb r0, [r8, sp, ror #16]! */
/* @0x31546a stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x31546e blx 0x58092e <g_SWFlineaavertbuff+0x2d866> */
/* @0x315472 svclo #0x1f701 */
/* @0x315476 eorpl pc, r6, r5, asr r8 */
/* @0x31547a adcmi r4, pc, #39 */
/* @0x31547e stcls p0, c13, [r2, #-12] */
/* @0x315482 blne 0x1564c8e <b2_toiTime+0xe0b7ea> */
/* @0x315486 .word 0x9c08e7f0 */
/* @0x31548a str r9, [r12, -r1, lsl #8]! */
/* @0x31548e .word 0xf10a9c04 */
/* @0x315492 strlo r0, [r4], #-2561 */
/* @0x315496 ldr r9, [r7, -r4, lsl #8] */
/* @0x31549a .word 0xb12d9d06 */
/* @0x31549e svclt #0x142b01 */
/* @0x3154a2 andeq pc, r4, pc, rrx */
/* @0x3154a6 and r2, r0, r0 */
/* @0x3154aa eorslt r9, pc, r6, lsl #16 */
/* @0x3154ae svchi #0xf0e8bd */
/* @0x3154b2 mvnsmi lr, sp, lsr #18 */
/* @0x3154b6 addlt r4, r5, #24117248 */
/* @0x3154ba strmi r0, [r12], -r6, lsl #24 */
/* @0x3154be rsble r2, r5, r0, lsl #18 */
/* @0x3154c2 ldmpl r0!, {r0, r6, r9, r12, sp, lr, pc} */
/* @0x3154c6 subsle r2, sp, r0, lsl #30 */
/* @0x3154ca svclt #0x344547 */
/* @0x3154ce .word 0x4643463b */
/* @0x3154d2 blhs 0x6dc0d6 <g_SWFvertbuff+0x900e> */
/* @0x3154d6 stmdavc r2!, {r0, r6, r8, r10, r11, r12, lr, pc} */
/* @0x3154da ldrlo r3, [r0], #-2832 */
/* @0x3154de .word 0xf8144415 */
/* @0x3154e2 strtmi r2, [lr], #-3087 */
/* @0x3154e6 .word 0xf8144415 */
/* @0x3154ea strtmi r2, [lr], #-3086 */
/* @0x3154ee .word 0xf8144415 */
/* @0x3154f2 strtmi r2, [lr], #-3085 */
/* @0x3154f6 .word 0xf8144415 */
/* @0x3154fa strtmi r2, [lr], #-3084 */
/* @0x3154fe .word 0xf8144415 */
/* @0x315502 strtmi r2, [lr], #-3083 */
/* @0x315506 .word 0xf8144415 */
/* @0x31550a strtmi r2, [lr], #-3082 */
/* @0x31550e .word 0xf8144415 */
/* @0x315512 strtmi r2, [lr], #-3081 */
/* @0x315516 .word 0xf8144415 */
/* @0x31551a strtmi r2, [lr], #-3080 */
/* @0x31551e .word 0xf8144415 */
/* @0x315522 strtmi r2, [lr], #-3079 */
/* @0x315526 .word 0xf8144415 */
/* @0x31552a strtmi r2, [lr], #-3078 */
/* @0x31552e .word 0xf8144415 */
/* @0x315532 strtmi r2, [lr], #-3077 */
/* @0x315536 .word 0xf8144415 */
/* @0x31553a strtmi r2, [lr], #-3076 */
/* @0x31553e .word 0xf8144415 */
/* @0x315542 strtmi r2, [lr], #-3075 */
/* @0x315546 .word 0xf8144415 */
/* @0x31554a strtmi r2, [lr], #-3074 */
/* @0x31554e .word 0xf8144415 */
/* @0x315552 strtmi r2, [lr], #-3073 */
/* @0x315556 strtmi r4, [lr], #-1045 */
/* @0x31555a ldrhlt lr, [r3, -r11]! */
/* @0x31555e .word 0xf8144423 */
/* @0x315562 addsmi r2, r12, #1024 */
/* @0x315566 strtmi r4, [lr], #-1045 */
/* @0x31556a qsub8mi sp, r8, r9 */
/* @0x31556e mvnsvc pc, pc, asr #12 */
/* @0x315572 bl 0xff2d1586 <b2_toiTime+0xfffffffffeb780e2> */
/* @0x315576 .word 0x460d4630 */
/* @0x31557a mvnsvc pc, pc, asr #12 */
/* @0x31557e bl 0xff151592 <b2_toiTime+0xfffffffffe9f80ee> */
/* @0x315582 ldr r4, [pc, lr, lsl #12] */
/* @0x315586 andmi lr, r6, r5, asr #20 */
/* @0x31558a ldrhhi lr, [r0, #141]! */
/* @0x31558e pop {r0, sp} */
/* @0x315592 .word 0xf7d181f0 */
/* @0x315596 .word 0xf7d1becf */
/* @0x31559a strlt r11, [r7, #-0xecd] */
/* @0x31559e bge 0x3662ea <_ZTS12CDS_Priority+0x8342> */
/* @0x3155a2 stc2l p7, c15, [r0, #836] */
/* @0x3155a6 .word 0xf85db003 */
/* @0x3155aa .word 0xf7fffb04 */
/* @0x3155ae ldrlt r11, [r7, #-0xff6]! */
/* @0x3155b2 strmi r2, [r4], -r0, lsl #2 */
/* @0x3155b6 .word 0xf976f7d1 */
/* @0x3155ba stmdahs r0, {r12, pc} */
/* @0x3155be qsaxmi sp, r0, r4 */
/* @0x3155c2 andhs r10, r4, #16384 */
/* @0x3155c6 .word 0xf9e2f7d1 */
/* @0x3155ca stmdahs r0, {r12, pc} */
/* @0x3155ce .word 0xf89dd14c */
/* @0x3155d2 blhs 0xae15ea <b2_toiTime+0x388146> */
/* @0x3155d6 .word 0xf89dd10c */
/* @0x3155da blhs 0xfe5e15f6 <b2_toiTime+0xfffffffffde88152> */
/* @0x3155de .word 0xf89dd108 */
/* @0x3155e2 blhs 0x521602 <SrcVerts+0x7e646> */
/* @0x3155e6 .word 0xf89dd104 */
/* @0x3155ea .word 0xf0133007 */
/* @0x3155ee andle r0, r2, r0, ror #31 */
/* @0x3155f2 movwls r2, #0x303 */
/* @0x3155f6 qasxmi lr, r0, r8 */
/* @0x3155fa .word 0xf7d12106 */
/* @0x3155fe .word 0xf89df998 */
/* @0x315602 andls r3, r0, r7 */
/* @0x315606 strle r0, [r4], #-1880 */
/* @0x31560a mullo r7, sp, r8 */
/* @0x31560e strle r0, [lr], #-1817 */
/* @0x315612 uqadd16mi lr, r9, r5 */
/* @0x315616 .word 0xf7d14620 */
/* @0x31561a blls 0x354432 */
/* @0x31561e bllt 0x9e6e2a <b2_toiTime+0x28d986> */
/* @0x315622 .word 0xf7d14620 */
/* @0x315626 andls pc, r0, r4, lsl #19 */
/* @0x31562a rscle r2, sp, r0, lsl #16 */
/* @0x31562e qadd16mi lr, r0, r12 */
/* @0x315632 .word 0xf7d14669 */
/* @0x315636 blls 0x353f42 */
/* @0x31563a stmdahs r0, {r0, r1, r4, r5, r7, r8, r11, r12, sp, pc} */
/* @0x31563e .word 0xf89dd1f7 */
/* @0x315642 ldrbeq r3, [r10], r7 */
/* @0x315646 strtmi sp, [r0], -r7, lsl #10 */
/* @0x31564a .word 0xf7d14669 */
/* @0x31564e blls 0x353f2a */
/* @0x315652 stmdahs r0, {r0, r1, r4, r6, r8, r11, r12, sp, pc} */
/* @0x315656 .word 0xf89dd1f7 */
/* @0x31565a ldreq r3, [r11, r7] */
/* @0x31565e strtmi sp, [r0], -r4, lsl #10 */
/* @0x315662 .word 0xf7d12102 */
/* @0x315666 andls pc, r0, r4, ror #18 */
/* @0x31566a andlt r9, r3, r0, lsl #16 */
/* @0x31566e push {r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x315672 .word 0x460443f8 */
/* @0x315676 strmi r6, [sp], -r7, asr #22 */
/* @0x31567a ldrsbthi pc, [r0], -r0 */
/* @0x31567e stmdbvs r11, {r1, r2, r4, r9, r10, lr} */
/* @0x315682 .word 0xf8d145b8 */
/* @0x315686 svclt #0x88900c */
/* @0x31568a bl 0xff5301ae <b2_toiTime+0xfffffffffedd6d0a> */
/* @0x31568e addsmi r0, pc, #1835008 */
/* @0x315692 ldrmi r11, [pc], -r8, lsr #30 */
/* @0x315696 .word 0xf112b11f */
/* @0x31569a svclt #0x80f05 */
/* @0x31569e blne 0xff9deea6 <b2_toiTime+0xffffffffff285a02> */
/* @0x3156a2 stmdbvs r11!, {r0, r1, r3, r5, r8, sp, lr} ^ */
/* @0x3156a6 .word 0x616b443b */
/* @0x3156aa smulwblt r11, r3, r11 */
/* @0x3156ae strbmi r6, [r1], -r0, ror #23 */
/* @0x3156b2 .word 0x4798463a */
/* @0x3156b6 .word 0x632863e0 */
/* @0x3156ba ldrtmi r4, [r10], -r8, asr #12 */
/* @0x3156be ldrtmi r4, [r9], #1601 */
/* @0x3156c2 svc #0x7cf5a0 */
/* @0x3156c6 strbmi r6, [r7], #-2787 */
/* @0x3156ca .word 0xd126429f */
/* @0x3156ce .word 0x8028f8d4 */
/* @0x3156d2 adcsmi r6, r11, #101376 */
/* @0x3156d6 .word 0xf8c4bf08 */
/* @0x3156da blvs 0x1cf57b2 <b2_toiTime+0x159c30e> */
/* @0x3156de bl 0xff52fb92 <b2_toiTime+0xfffffffffedd66ee> */
/* @0x3156e2 addsmi r0, pc, #1835008 */
/* @0x3156e6 ldrmi r11, [pc], -r8, lsr #30 */
/* @0x3156ea .word 0xf116b11f */
/* @0x3156ee svclt #0x80f05 */
/* @0x3156f2 blne 0xff9deefa <b2_toiTime+0xffffffffff285a56> */
/* @0x3156f6 stmdbvs r11!, {r0, r1, r3, r5, r8, sp, lr} ^ */
/* @0x3156fa .word 0x616b443b */
/* @0x3156fe smulwblt r11, r3, r11 */
/* @0x315702 strbmi r6, [r1], -r0, ror #23 */
/* @0x315706 .word 0x4798463a */
/* @0x31570a .word 0x632863e0 */
/* @0x31570e ldrtmi r4, [r10], -r8, asr #12 */
/* @0x315712 ldrtmi r4, [r9], #1601 */
/* @0x315716 svc #0x52f5a0 */
/* @0x31571a .word 0xf8c54447 */
/* @0x31571e ldrtmi r9, [r0], -r12 */
/* @0x315722 pop {r0, r1, r2, r5, r8, r9, sp, lr} */
/* @0x315726 ldrlt r8, [r8, #-0x3f8]! */
/* @0x31572a strmi r4, [sp], -r4, lsl #12 */
/* @0x31572e blvs 0xff401b5e <b2_toiTime+0xfffffffffeca86ba> */
/* @0x315732 stmdavs r3!, {r0, r1, r4, sp, lr} */
/* @0x315736 blhs 0x36434e <_ZTS12CDS_Priority+0x63a6> */
/* @0x31573a bvs 0x1e0b74e <b2_toiTime+0x16b22aa> */
/* @0x31573e stmvs r1!, {r3, r5, r7, r9, r11, sp, lr} ^ */
/* @0x315742 stmdavs r3!, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x315746 .word 0xd1032b06 */
/* @0x31574a bvs 0xfed300fe <b2_toiTime+0xfffffffffe5d6c5a> */
/* @0x31574e ldrmi r6, [r8, r1, ror #16] */
/* @0x315752 andhs r6, r0, r3, lsr #21 */
/* @0x315756 mvnvs r6, r0, lsr #32 */
/* @0x31575a .word 0x63236363 */
/* @0x31575e eorvs r6, r0, #166912 */
/* @0x315762 strmi r11, [r1], -r3, lsr #2 */
/* @0x315766 ldrmi r4, [r8, r2, lsl #12] */
/* @0x31576a .word 0x632863e0 */
/* @0x31576e ldrlt r11, [r8, #-0xd38]! */
/* @0x315772 mvnlt r4, r4, lsl #12 */
/* @0x315776 bicslt r6, r11, r3, asr #19 */
/* @0x31577a biclt r6, r10, r2, asr #20 */
/* @0x31577e orrlt r6, r5, sp, asr r9 */
/* @0x315782 strtmi r2, [r8], -r0, lsl #4 */
/* @0x315786 .word 0xf7ff4621 */
/* @0x31578a bvs 0x1c156ca <b2_toiTime+0x14bc226> */
/* @0x31578e bvs 0xfed70216 <b2_toiTime+0xfffffffffe616d72> */
/* @0x315792 bvs 0x1be75fa <b2_toiTime+0x148e156> */
/* @0x315796 bvs 0x1d7021e <b2_toiTime+0x1616d7a> */
/* @0x31579a bvs 0x1be7602 <b2_toiTime+0x148e15e> */
/* @0x31579e strtmi r6, [r9], -r0, lsr #21 */
/* @0x3157a2 bvs 0xfeb2760a <b2_toiTime+0xfffffffffe3ce166> */
/* @0x3157a6 stmibvs r1!, {r0, r1, r5, r6, r9, r11, sp, lr} ^ */
/* @0x3157aa mulhs r0, r8, r7 */
/* @0x3157ae ldclt p1, c6, [r8, #-896]! */
/* @0x3157b2 andeq pc, r1, pc, rrx */
/* @0x3157b6 ldrblt r11, [r8, #0xd38]! */
/* @0x3157ba stmvs r4, {r1, r2, r9, r10, lr} ^ */
/* @0x3157be orrslt r6, r12, r7, asr #19 */
/* @0x3157c2 andeq pc, r12, r4, lsl #2 */
/* @0x3157c6 .word 0xf7ff2500 */
/* @0x3157ca rscvs pc, r5, #840 */
/* @0x3157ce ldrtmi r6, [r8], -r5, lsr #6 */
/* @0x3157d2 strtmi r6, [r1], -r5, ror #6 */
/* @0x3157d6 .word 0x61a560e5 */
/* @0x3157da mvnvs r6, r5, lsr #2 */
/* @0x3157de eorvs r6, r5, r5, lsr #1 */
/* @0x3157e2 .word 0xf7d16065 */
/* @0x3157e6 rscsvs pc, r5, r7, lsr #27 */
/* @0x3157ea stmdblt r4!, {r2, r4, r5, r6, r8, r11, sp, lr} */
/* @0x3157ee ldmdavs r1!, {r3, r4, r5, r9, r10, lr} */
/* @0x3157f2 stc2 p7, c15, [r0, #836]! */
/* @0x3157f6 ldcllt p0, c6, [r8, #208]! */
/* @0x3157fa .word 0x4601b510 */
/* @0x3157fe stmibvs r3, {r4, r7, r8, r12, sp, pc} ^ */
/* @0x315802 strhs r11, [r0], #-387 */
/* @0x315806 addvs r6, r4, r4, asr #2 */
/* @0x31580a ldmvs r10, {r2, r7, r8, sp, lr} ^ */
/* @0x31580e svclt #0x1442a2 */
/* @0x315812 strtmi r2, [r2], -r7, lsl #4 */
/* @0x315816 stmibvs r3, {r1, r3, r4, sp, lr} ^ */
/* @0x31581a ldmdbvs r8, {r1, r5, r9, r10, lr} ^ */
/* @0x31581e .word 0xff83f7ff */
/* @0x315822 ldclt p6, c4, [r0, #-128] */
/* @0x315826 andeq pc, r1, pc, rrx */
/* @0x31582a push {r4, r8, r10, r11, r12, sp, pc} */
/* @0x31582e .word 0x460d47f0 */
/* @0x315832 stmdahs r0, {r2, r9, r10, lr} */
/* @0x315836 movwhs sp, #0x72 */
/* @0x31583a bvs 0x3ede4e */
/* @0x31583e bmi 0x1203cb2 <b2_toiTime+0xaaa80e> */
/* @0x315842 ldrbtmi r6, [r10], #-643 */
/* @0x315846 bvs 0x1bee056 <b2_toiTime+0x1494bb2> */
/* @0x31584a blmi 0x1183c9e <b2_toiTime+0xa2a7fa> */
/* @0x31584e rsbvs r4, r3, #2063597568 */
/* @0x315852 .word 0x21016a23 */
/* @0x315856 andshs r6, r8, #160, #20 */
/* @0x31585a .word 0x61e04798 */
/* @0x31585e rsble r2, r1, r0, lsl #16 */
/* @0x315862 .word 0x61432300 */
/* @0x315866 addsmi r6, sp, #3702784 */
/* @0x31586a ble 0x3edbbe */
/* @0x31586e rsbmi r6, sp, #3719168 */
/* @0x315872 sbcsvs r2, r10, r1, lsl #4 */
/* @0x315876 movweq pc, #0x81a5 */
/* @0x31587a stmdble r3, {r0, r1, r2, r8, r9, r11, sp} */
/* @0x31587e .word 0xf7ff4620 */
/* @0x315882 sub pc, r11, r6, ror pc */
/* @0x315886 tstvs sp, r3, ror #19 */
/* @0x31588a ldmvs r11!, {r0, r1, r2, r5, r6, r7, r8, r11, sp, lr} ^ */
/* @0x31588e .word 0xf8dfb91b */
/* @0x315892 ldrbtmi r8, [r8], #164 */
/* @0x315896 .word 0xf04fe001 */
/* @0x31589a strhs r0, [r1], -r0, lsl #16 */
/* @0x31589e bvs 0xfeb30132 <b2_toiTime+0xfffffffffe3d6c8e> */
/* @0x3158a2 subhs r4, r0, #51380224 */
/* @0x3158a6 .word 0xf905fa06 */
/* @0x3158aa .word 0x46054798 */
/* @0x3158ae eorle r2, r10, r0, lsl #16 */
/* @0x3158b2 .word 0x21086a23 */
/* @0x3158b6 vst1.32 {d22, d23}, [pc:128], r0 */
/* @0x3158ba .word 0x479862b4 */
/* @0x3158be rsbvs r4, r8, #136314880 */
/* @0x3158c2 strtmi r11, [r9], -r8, lsr #18 */
/* @0x3158c6 bvs 0xfeb3025a <b2_toiTime+0xfffffffffe3d6db6> */
/* @0x3158ca .word 0x47984655 */
/* @0x3158ce shadd16mi lr, r1, r11 */
/* @0x3158d2 bvs 0xfeb30166 <b2_toiTime+0xfffffffffe3d6cc2> */
/* @0x3158d6 ldrmi r4, [r8, r10, asr #12] */
/* @0x3158da adcvs r4, r8, #6291456 */
/* @0x3158de bvs 0x1d83e06 <b2_toiTime+0x162a962> */
/* @0x3158e2 bvs 0xfeb30276 <b2_toiTime+0xfffffffffe3d6dd2> */
/* @0x3158e6 qadd8mi r4, r9, r8 */
/* @0x3158ea ldrtmi r6, [r5], -r3, ror #20 */
/* @0x3158ee ldrmi r6, [r8, r0, lsr #21] */
/* @0x3158f2 strbmi lr, [lr], #-9 */
/* @0x3158f6 rscvs r2, lr, #0, #4 */
/* @0x3158fa .word 0xf8c54628 */
/* @0x3158fe qasxmi r8, r1, r8 */
/* @0x315902 .word 0xf7ff602a */
/* @0x315906 cmnvs sp, r0, lsl pc */
/* @0x31590a ldmdblt r5, {r5, r9, r10, lr} */
/* @0x31590e .word 0xff2ff7ff */
/* @0x315912 .word 0xf7ffe008 */
/* @0x315916 andhs pc, r0, r1, ror pc */
/* @0x31591a .word 0x87f0e8bd */
/* @0x31591e andeq pc, r1, pc, rrx */
/* @0x315922 .word 0x87f0e8bd */
/* @0x315926 andeq pc, r3, pc, rrx */
/* @0x31592a .word 0x87f0e8bd */
/* @0x31592e stc2l p15, c11, [r5, #-0]! */
/* @0x315932 stc2l p15, c15, [r7, #-1020] */
/* @0x315936 .word 0xfc1bffff */
/* @0x31593a push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x31593e .word 0x46044ff0 */
/* @0x315942 stmdahs r0, {r0, r1, r3, r4, r7, r12, sp, pc} */
/* @0x315946 strbhi pc, [r10, r0]! */
/* @0x31594a blhs 0x33005e */
/* @0x31594e strbhi pc, [r6, r0]! */
/* @0x315952 blhs 0x32f966 */
/* @0x315956 strbhi pc, [r2, r0]! */
/* @0x31595a bhs 0xff153cde <b2_toiTime+0xfffffffffe9fa83a> */
/* @0x31595e .word 0xf8df2904 */
/* @0x315962 .word 0xf06f1ab4 */
/* @0x315966 ldrbtmi r0, [r10], #-1796 */
/* @0x31596a andhs r11, r0, r4, lsl pc */
/* @0x31596e andeq pc, r4, pc, rrx */
/* @0x315972 orrseq pc, r8, #-2147483648 */
/* @0x315976 .word 0xf8df9312 */
/* @0x31597a ldrbtmi r3, [r9], #-2720 */
/* @0x31597e ldrbtmi r9, [r11], #-9 */
/* @0x315982 bllo 0x139dce <_Z13F_FileWriteLnR6RValueP9CInstanceS2_iPS_+0x3a> */
/* @0x315986 tstls r3, #-536870912 */
/* @0x31598a ldmdavs r10, {r0, r1, r5, r6, r7, r8, r11, sp, lr} */
/* @0x31598e vpmax.s8 d2, d0, d13 */
/* @0x315992 ldm pc, {r0, r2, r6, r7, r8, r9, r10, pc} ^ */
/* @0x315996 andseq pc, r2, r2, lsl r0 */
/* @0x31599a rsbeq r0, r1, r11, lsr r0 */
/* @0x31599e addeq r0, r11, r5, ror r0 */
/* @0x3159a2 adcseq r0, r10, r1, lsr #1 */
/* @0x3159a6 strbeq r0, [r5, -r5, asr #1]! */
/* @0x3159aa .word 0x078d0778 */
/* @0x3159ae strbeq r0, [r6, r2, lsr #15] */
/* @0x3159b2 .word 0xf06f000e */
/* @0x3159b6 .word 0xf0000002 */
/* @0x3159ba stmdavs r2!, {r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, sp, pc} ^ */
/* @0x3159be .word 0xf0002a00 */
/* @0x3159c2 blo 0x37789a <_ZTS13C_UTF16String+0xe946> */
/* @0x3159c6 stmvs r2!, {r1, r5, r6, sp, lr} */
/* @0x3159ca adcvs r3, r2, r1, lsl #4 */
/* @0x3159ce mrrcne p8, #0x2, r6, r1, c2 */
/* @0x3159d2 ldmdavc r2, {r0, r5, sp, lr} */
/* @0x3159d6 .word 0xf002605a */
/* @0x3159da bhs 0x51621e <SrcVerts+0x73262> */
/* @0x3159de andle r6, r5, r3, ror #19 */
/* @0x3159e2 andsvs r2, r10, sp, lsl #4 */
/* @0x3159e6 blo 0x1153d6a <b2_toiTime+0x9fa8c6> */
/* @0x3159ea eor r4, r9, r11, ror r4 */
/* @0x3159ee ldmdbeq r2, {r1, r3, r4, r6, r11, sp, lr} */
/* @0x3159f2 .word 0x0108f102 */
/* @0x3159f6 addsmi r6, r1, #425984 */
/* @0x3159fa andhs sp, sp, #81920 */
/* @0x3159fe .word 0xf8df601a */
/* @0x315a02 ldrbtmi r3, [r11], #-2592 */
/* @0x315a06 svcls #0x9e01c */
/* @0x315a0a andsvs r2, r10, r1, lsl #4 */
/* @0x315a0e blhs 0x32fba2 */
/* @0x315a12 strhi pc, [r11, r0] */
/* @0x315a16 rsbvs r3, r3, r1, lsl #22 */
/* @0x315a1a tsths pc, r3, lsr #17 */
/* @0x315a1e movwlo r6, #0x19e5 */
/* @0x315a22 stmdavs r3!, {r0, r1, r5, r7, sp, lr} */
/* @0x315a26 eorvs r1, r2, r10, asr r12 */
/* @0x315a2a ldmdavc lr, {r3, r5, r6, r11, sp, lr} */
/* @0x315a2e andhs lr, r0, r6, lsl #22 */
/* @0x315a32 ldmdb lr, {r0, r1, r12, sp, lr, pc} ^ */
/* @0x315a36 movwhs r11, #0xd139 */
/* @0x315a3a .word 0xf8df602b */
/* @0x315a3e ldrbtmi r3, [r11], #-2536 */
/* @0x315a42 .word 0xf00061a3 */
/* @0x315a46 ldrteq r11, [r2], r2, ror #30 */
/* @0x315a4a movwhs sp, #0x7403 */
/* @0x315a4e .word 0xf000602b */
/* @0x315a52 svcls #0x9bf5f */
/* @0x315a56 eorvs r2, r11, r2, lsl #6 */
/* @0x315a5a blhs 0x32fbee */
/* @0x315a5e strbhi pc, [r5, -r0]! */
/* @0x315a62 rsbvs r3, r3, r1, lsl #22 */
/* @0x315a66 stmibvs r2!, {r0, r1, r5, r7, r11, sp, lr} ^ */
/* @0x315a6a adcvs r3, r3, r1, lsl #6 */
/* @0x315a6e svcls #0x96823 */
/* @0x315a72 eorvs r1, r1, r9, asr r12 */
/* @0x315a76 sadd16eq r7, r11, r11 */
/* @0x315a7a stmibvs r3!, {r0, r1, r4, r7, sp, lr} ^ */
/* @0x315a7e andsvs r2, r10, r3, lsl #4 */
/* @0x315a82 blhs 0x32fc16 */
/* @0x315a86 ldrbhi pc, [r1, -r0] */
/* @0x315a8a rsbvs r3, r3, r1, lsl #22 */
/* @0x315a8e stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr} */
/* @0x315a92 adcvs r3, r3, r1, lsl #6 */
/* @0x315a96 mrrcne p9, #0xe, r6, r0, c3 */
/* @0x315a9a ldmvs r9, {r0, r3, r8, r9, r10, r11, r12, pc} */
/* @0x315a9e ldmdavc r2, {r5, sp, lr} */
/* @0x315aa2 andmi lr, r2, #1024 */
/* @0x315aa6 stmibvs r3!, {r1, r3, r4, r7, sp, lr} ^ */
/* @0x315aaa andsvs r2, r10, r4, lsl #4 */
/* @0x315aae blhs 0x32fc42 */
/* @0x315ab2 ldrhi pc, [r11, -r0]! */
/* @0x315ab6 rsbvs r3, r3, r1, lsl #22 */
/* @0x315aba stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr} */
/* @0x315abe adcvs r3, r3, r1, lsl #6 */
/* @0x315ac2 mrrcne p9, #0xe, r6, r0, c3 */
/* @0x315ac6 ldmvs r9, {r0, r3, r8, r9, r10, r11, r12, pc} */
/* @0x315aca ldmdavc r2, {r5, sp, lr} */
/* @0x315ace andhs lr, r2, #1024 */
/* @0x315ad2 stmibvs r3!, {r1, r3, r4, r7, sp, lr} ^ */
/* @0x315ad6 andsvs r2, r10, r5, lsl #4 */
/* @0x315ada blhs 0x32fc6e */
/* @0x315ade strhi pc, [r5, -r0]! */
/* @0x315ae2 rsbvs r3, r3, r1, lsl #22 */
/* @0x315ae6 stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr} */
/* @0x315aea adcvs r3, r3, r1, lsl #6 */
/* @0x315aee mrrcne p9, #0xe, r6, r0, c3 */
/* @0x315af2 mlavs r0, r9, r8, r6 */
/* @0x315af6 ldmdavc r2, {r1, sp} */
/* @0x315afa addsvs r4, r10, r10, lsl #8 */
/* @0x315afe ldmvs r10, {r0, r1, r5, r6, r7, r8, r11, sp, lr} */
/* @0x315b02 andhs r6, r6, #-2013265920 */
/* @0x315b06 .word 0xf000601a */
/* @0x315b0a andhs r11, sp, #38, #30 */
/* @0x315b0e .word 0xf8df601a */
/* @0x315b12 andhs r3, r0, #24, #18 */
/* @0x315b16 .word 0x61a3447b */
/* @0x315b1a subsvs r6, r10, r3, ror #19 */
/* @0x315b1e cdplt p0, #0xf, c15, c14, c0, #0x0 */
/* @0x315b22 stmdavs r2!, {r0, r2, r3, r4, r6, r8, r11, sp, lr} ^ */
/* @0x315b26 .word 0xa000f8d4 */
/* @0x315b2a blvs 0xdf08ea <b2_toiTime+0x697446> */
/* @0x315b2e addsmi r9, lr, #8, #4 */
/* @0x315b32 .word 0xb020f8d5 */
/* @0x315b36 ldrsbls pc, [r12], -r5 */
/* @0x315b3a bl 0xff4ca376 <b2_toiTime+0xfffffffffed70ed2> */
/* @0x315b3e .word 0xf1080803 */
/* @0x315b42 .word 0xf8df38ff */
/* @0x315b46 .word 0xf8df38e8 */
/* @0x315b4a ldrbtmi lr, [r11], #-2280 */
/* @0x315b4e ldrbtmi r9, [lr], #783 */
/* @0x315b52 sub pc, r0, sp, asr #17 */
/* @0x315b56 bvs 0xffe0dbe6 <b2_toiTime+0xffffffffff6b4742> */
/* @0x315b5a stmdaeq r3, {r1, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x315b5e .word 0xf1b8e7f1 */
/* @0x315b62 .word 0xf0000f00 */
/* @0x315b66 stmdbls r8, {r0, r6, r7, pc} */
/* @0x315b6a stmdavs pc!, {r4, r5, r9, r10, lr} ^ */
/* @0x315b6e svclt #0x3842b9 */
/* @0x315b72 ldrbmi r4, [r1], -pc, lsl #12 */
/* @0x315b76 svclt #0x284547 */
/* @0x315b7a ldrtmi r4, [r10], #1607 */
/* @0x315b7e shasxmi r4, r10, lr */
/* @0x315b82 stmdaeq r8, {r0, r1, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x315b86 ldc p5, c15, [r10, #-640] */
/* @0x315b8a stmdavs r11!, {r3, r9, r11, r12, pc} ^ */
/* @0x315b8e andls r1, r8, #215040 */
/* @0x315b92 .word 0x606f1bdf */
/* @0x315b96 .word 0xf0002f00 */
/* @0x315b9a .word 0x270080f0 */
/* @0x315b9e blhs 0x56fc52 <g_SWFlineaavertbuff+0x1cb8a> */
/* @0x315ba2 strthi pc, [r11], -r0, lsl #4 */
/* @0x315ba6 .word 0xf013e8df */
/* @0x315baa rsbseq r0, r1, r9, lsl r0 */
/* @0x315bae smlalseq r0, sp, r7, r0 */
/* @0x315bb2 biceq r0, r5, r12, lsr #2 */
/* @0x315bb6 strbeq r0, [r3, #0x358]! */
/* @0x315bba ldreq r0, [r5], -r2, lsl #12 */
/* @0x315bbe bhs 0x33c3e6 */
/* @0x315bc2 bichi pc, r7, r0 */
/* @0x315bc6 bllo 0x393c36 <ft_adobe_glyph_list+0x3312> */
/* @0x315bca blo 0x35f7d2 <_ZTS12CDS_Priority+0x182a> */
/* @0x315bce blx 0x3fa3f6 <g_RomDisk+0x2bd6> */
/* @0x315bd2 .word 0xf109f309 */
/* @0x315bd6 b 0x15d7ffe <b2_toiTime+0xe7eb5a> */
/* @0x315bda .word 0xf1b90b03 */
/* @0x315bde stmible sp!, {r1, r8, r9, r10, r11} ^ */
/* @0x315be2 smlalbteq pc, r1, r11, r3 */
/* @0x315be6 movweq pc, #0x100b */
/* @0x315bea .word 0x61ab2902 */
/* @0x315bee stmdbhs r3, {r1, r3, r5, r12, lr, pc} */
/* @0x315bf2 stmdbhs r1, {r1, r2, r3, r5, r12, lr, pc} */
/* @0x315bf6 .word 0xf1a9d00b */
/* @0x315bfa b 0x16d640e <b2_toiTime+0xf7cf6a> */
/* @0x315bfe .word 0xf00201db */
/* @0x315c02 blx 0xb56826 <b2_toiTime+0x3fd382> */
/* @0x315c06 bl 0xff41481a <b2_toiTime+0xfffffffffecbb376> */
/* @0x315c0a movwhs r0, #0x1902 */
/* @0x315c0e bvs 0xc0defe <b2_toiTime+0x4b4a5a> */
/* @0x315c12 bvs 0xfeb1e48a <b2_toiTime+0xfffffffffe3c4fe6> */
/* @0x315c16 .word 0xb1584798 */
/* @0x315c1a movwhs r9, #0x913 */
/* @0x315c1e movwhs r6, #0x9003 */
/* @0x315c22 movwhs r7, #0x5403 */
/* @0x315c26 .word 0xf8df7443 */
/* @0x315c2a orrvs r3, r1, r12, lsl #16 */
/* @0x315c2e .word 0x6143447b */
/* @0x315c32 stmdahs r0, {r3, r5, r6, sp, lr} */
/* @0x315c36 ldrbthi pc, [r11], -r0 */
/* @0x315c3a bleq 0xffa1057e <b2_toiTime+0xffffffffff2b70da> */
/* @0x315c3e stmdbeq r3, {r0, r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x315c42 adds r2, pc, r6, lsl #6 */
/* @0x315c46 bleq 0xffa1058a <b2_toiTime+0xffffffffff2b70e6> */
/* @0x315c4a stmdbeq r3, {r0, r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x315c4e adds r2, r9, r3, lsl #6 */
/* @0x315c52 eorvs r2, r11, r9, lsl #6 */
/* @0x315c56 ubfxlo pc, pc, #0x11, #0x5 */
/* @0x315c5a .word 0x61a3447b */
/* @0x315c5e bicseq lr, r11, #323584 */
/* @0x315c62 .word 0xf1a9622b */
/* @0x315c66 mvnvs r0, r3, lsl #6 */
/* @0x315c6a ldclt p0, c15, [r7, #0]! */
/* @0x315c6e stmdahs r0, {r3, r11, r12, pc} */
/* @0x315c72 msrhi SPSR_f, r0 */
/* @0x315c76 bllo 0x393ce6 <ft_adobe_glyph_list+0x33c2> */
/* @0x315c7a stmdalo r1, {r8, r9, r10, sp} */
/* @0x315c7e blx 0x3f9ca6 <g_RomDisk+0x2486> */
/* @0x315c82 .word 0xf109f309 */
/* @0x315c86 b 0x15d80ae <b2_toiTime+0xe7ec0a> */
/* @0x315c8a .word 0xf1b90b03 */
/* @0x315c8e stmible sp!, {r0, r1, r2, r3, r4, r8, r9, r10, r11} ^ */
/* @0x315c92 movweq lr, #0xba6f */
/* @0x315c96 .word 0xf28bfa1f */
/* @0x315c9a addsmi r0, r3, #6912 */
/* @0x315c9e bls 0x549cda <gp_ActiveMaskObjects+0x5012> */
/* @0x315ca2 eorvs r2, r11, r9, lsl #6 */
/* @0x315ca6 .word 0x3798f8df */
/* @0x315caa .word 0x61a3447b */
/* @0x315cae eorlt pc, r0, r5, asr #17 */
/* @0x315cb2 andsls pc, r12, r5, asr #17 */
/* @0x315cb6 .word 0xf0006062 */
/* @0x315cba mlsvs r11, r2, sp, r11 */
/* @0x315cbe stmibvs r11!, {r0, r1, r3, r5, r8, r11, r12, sp, pc} */
/* @0x315cc2 svclt #0x142b00 */
/* @0x315cc6 movwhs r2, #0x307 */
/* @0x315cca movwhs lr, #0x2000 */
/* @0x315cce stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x315cd2 strbmi r6, [r11], r11, lsr #32 */
/* @0x315cd6 blls 0x54fa66 <gp_ActiveMaskObjects+0xad9e> */
/* @0x315cda .word 0xf47f2b00 */
/* @0x315cde .word 0xf8c5af40 */
/* @0x315ce2 .word 0xf8c5b020 */
/* @0x315ce6 teq r9, r12, lsl r0 */
/* @0x315cea addsmi r6, lr, #962560 */
/* @0x315cee blvs 0xdca136 <b2_toiTime+0x670c92> */
/* @0x315cf2 addsmi r6, r10, #700416 */
/* @0x315cf6 addsmi sp, r3, #12 */
/* @0x315cfa bl 0xff4059da <b2_toiTime+0xfffffffffecac536> */
/* @0x315cfe bl 0xff3d7d0e <b2_toiTime+0xfffffffffec7e86a> */
/* @0x315d02 .word 0xf1080806 */
/* @0x315d06 ssub8mi r3, lr, pc */
/* @0x315d0a svceq #0xf1b8 */
/* @0x315d0e svcge #0x2bf47f */
/* @0x315d12 strtmi r6, [r1], -lr, ror #6 */
/* @0x315d16 qasxmi r4, r8, r10 */
/* @0x315d1a stc2 p7, c15, [r9], #1020 */
/* @0x315d1e blvs 0xd70ade <b2_toiTime+0x61763a> */
/* @0x315d22 addmi r6, lr, #962560 */
/* @0x315d26 bl 0xff4c5a06 <b2_toiTime+0xfffffffffed6c562> */
/* @0x315d2a bl 0xff497d36 <b2_toiTime+0xfffffffffed3e892> */
/* @0x315d2e .word 0xf1080803 */
/* @0x315d32 addsmi r3, lr, #16711680 */
/* @0x315d36 .word 0xd10b4602 */
/* @0x315d3a addsmi r6, r9, #700416 */
/* @0x315d3e addmi sp, r11, #8 */
/* @0x315d42 bl 0xff405a22 <b2_toiTime+0xfffffffffecac57e> */
/* @0x315d46 bl 0xff3d7d52 <b2_toiTime+0xfffffffffec7e8ae> */
/* @0x315d4a .word 0xf1080806 */
/* @0x315d4e ssub8mi r3, lr, pc */
/* @0x315d52 svceq #0xf1b8 */
/* @0x315d56 svcge #0x7f47f */
/* @0x315d5a eorlt pc, r0, r5, asr #17 */
/* @0x315d5e andsls pc, r12, r5, asr #17 */
/* @0x315d62 stmdals r8, {r0, r1, r5, r11, sp, lr} */
/* @0x315d66 smlabteq r10, r3, r11, lr */
/* @0x315d6a .word 0xf8c468a3 */
/* @0x315d6e rsbvs r10, r0, r0 */
/* @0x315d72 adcvs r4, r3, r11, lsl #8 */
/* @0x315d76 .word 0xf000636e */
/* @0x315d7a stmibvs r11!, {r2, r4, r8, r10, r11, r12, sp, pc} */
/* @0x315d7e svclt #0x142b00 */
/* @0x315d82 movwhs r2, #0x307 */
/* @0x315d86 str r6, [r9, -r11, lsr #32] */
/* @0x315d8a cmnlt r3, r8, lsl #22 */
/* @0x315d8e movwls r3, #0x8b01 */
/* @0x315d92 bllo 0x393e02 <ft_adobe_glyph_list+0x34de> */
/* @0x315d96 blx 0x3df99e <error_g0017+0x38642> */
/* @0x315d9a .word 0xf109f309 */
/* @0x315d9e b 0x15d81c6 <b2_toiTime+0xe7ed22> */
/* @0x315da2 .word 0xf1b90b03 */
/* @0x315da6 stmible pc!, {r0, r2, r3, r8, r9, r10, r11} ^ */
/* @0x315daa stmdals r8, {r1, r2, sp, lr, pc} */
/* @0x315dae eorlt pc, r0, r5, asr #17 */
/* @0x315db2 andsls pc, r12, r5, asr #17 */
/* @0x315db6 sbcs r6, r2, r0, rrx */
/* @0x315dba tsteq pc, r11 */
/* @0x315dbe andeq pc, sp, #738197507 */
/* @0x315dc2 rsbvs r2, r10, sp, lsl r9 */
/* @0x315dc6 movwhs sp, #0x9905 */
/* @0x315dca .word 0xf8df602b */
/* @0x315dce ldrbtmi r3, [r11], #-1652 */
/* @0x315dd2 .word 0xf3c2e0ff */
/* @0x315dd6 bhs 0xa5a6ee <b2_toiTime+0x30124a> */
/* @0x315dda .word 0xf501d8f5 */
/* @0x315dde bvs 0xbf23ea <b2_toiTime+0x498f46> */
/* @0x315de2 bvs 0xfeb26e2e <b2_toiTime+0xfffffffffe3cd98a> */
/* @0x315de6 ldrmi r2, [r8, r4, lsl #4] */
/* @0x315dea stmdahs r0, {r3, r5, r6, r7, sp, lr} */
/* @0x315dee ldrhi pc, [pc] */
/* @0x315df2 bllo 0xfea10736 <b2_toiTime+0xfffffffffe2b7292> */
/* @0x315df6 stmdbeq lr, {r0, r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x315dfa adcvs r2, r11, r0, lsl #6 */
/* @0x315dfe eorvs r2, r11, r4, lsl #6 */
/* @0x315e02 .word 0x1644f8df */
/* @0x315e06 stmdavs r10!, {r0, r3, r4, r5, r6, r10, lr} ^ */
/* @0x315e0a beq 0xfe7b00be <b2_toiTime+0xfffffffffe056c1a> */
/* @0x315e0e addsmi r3, r3, #4, #4 */
/* @0x315e12 .word 0xf1b9d221 */
/* @0x315e16 stmdale pc, {r1, r8, r9, r10, r11} */
/* @0x315e1a stmdahs r0, {r3, r11, r12, pc} */
/* @0x315e1e addshi pc, r2, r0 */
/* @0x315e22 blhs 0x393e92 <ft_adobe_glyph_list+0x356e> */
/* @0x315e26 strhs r3, [r0, -r1, lsl #16] */
/* @0x315e2a blx 0x3b9e52 <error_g0017+0x12af6> */
/* @0x315e2e .word 0xf109f209 */
/* @0x315e32 b 0x15d825a <b2_toiTime+0xe7edb6> */
/* @0x315e36 strb r0, [r12, r2, lsl #22]! */
/* @0x315e3a bl 0x35cfa2 <_ZTS7CFontGM+0x66a> */
/* @0x315e3e stmvs r10!, {r0, r1, r7, r8, r9} ^ */
/* @0x315e42 stmdbeq r3, {r0, r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x315e46 umlalvs r6, r8, r11, r8 */
/* @0x315e4a andeq pc, r7, r11 */
/* @0x315e4e bleq 0xffa10792 <b2_toiTime+0xffffffffff2b72ee> */
/* @0x315e52 eoreq pc, r3, r2, asr #16 */
/* @0x315e56 .word 0xf8dfe7d7 */
/* @0x315e5a strdhs r2, r3, [r0, -r0] */
/* @0x315e5e stmvs r11!, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x315e62 blhs 0x7b020a <b2_toiTime+0x56d66> */
/* @0x315e66 stmdale r8, {r1, r3, r12, pc} */
/* @0x315e6a bl 0x39cfd2 <ft_adobe_glyph_list+0xc6ae> */
/* @0x315e6e adcvs r0, r8, r3, lsl #7 */
/* @0x315e72 stmdals r10, {r0, r1, r3, r4, r7, r11, sp, lr} */
/* @0x315e76 eorne pc, r3, r0, asr #16 */
/* @0x315e7a qsub8mi lr, r11, r1 */
/* @0x315e7e .word 0xf8432207 */
/* @0x315e82 .word 0xf04f2f10 */
/* @0x315e86 movwls r0, #0xcc00 */
/* @0x315e8a tsteq r4, #1073741825 */
/* @0x315e8e tsths r3, sp, lsl #6 */
/* @0x315e92 andhs r6, r4, #438272 */
/* @0x315e96 rsbgt pc, r4, sp, asr #17 */
/* @0x315e9a movwls r6, #0xbaa0 */
/* @0x315e9e andsgt pc, r8, sp, asr #17 */
/* @0x315ea2 ldrmi r6, [r8, r3, lsr #20] */
/* @0x315ea6 ldrsbgt pc, [r8], -sp */
/* @0x315eaa stmdahs r0, {r7, r9, r10, lr} */
/* @0x315eae blls 0x689f62 <g_SWFlinevertbuff+0x36e9a> */
/* @0x315eb2 andls r2, r5, r3, lsl r1 */
/* @0x315eb6 .word 0xf8cd460a */
/* @0x315eba movwls r12, #0x1000 */
/* @0x315ebe stmdals r10, {r2, r3, r8, r9, r11, r12, pc} */
/* @0x315ec2 blls 0x5faad2 <g_SWFaavertbuff+0x27a0a> */
/* @0x315ec6 blge 0x97aada <b2_toiTime+0x221636> */
/* @0x315eca strbtmi r9, [r3], -r4, lsl #6 */
/* @0x315ece .word 0xf95df7ff */
/* @0x315ed2 strmi r1, [r2], -r3, asr #25 */
/* @0x315ed6 .word 0xf8dfd104 */
/* @0x315eda ldrbtmi r3, [r11], #-1396 */
/* @0x315ede and r6, r9, r3, lsr #3 */
/* @0x315ee2 andle r3, r1, r5 */
/* @0x315ee6 stmdblt r11!, {r0, r1, r3, r5, r8, r11, sp, lr} */
/* @0x315eea strblo pc, [r8, #-0x8df]! */
/* @0x315eee andeq pc, r2, #111 */
/* @0x315ef2 .word 0x61a3447b */
/* @0x315ef6 strbmi r6, [r1], -r3, ror #20 */
/* @0x315efa andls r6, r7, #160, #20 */
/* @0x315efe bls 0x4e7d66 <SrcVerts+0x44daa> */
/* @0x315f02 .word 0xb19a4690 */
/* @0x315f06 .word 0xf06fe002 */
/* @0x315f0a and r0, r8, r3, lsl #16 */
/* @0x315f0e svceq #0x3f112 */
/* @0x315f12 bvs 0x1c0a32e <b2_toiTime+0x14b0e8a> */
/* @0x315f16 stmvs r9!, {r5, r7, r9, r11, sp, lr} ^ */
/* @0x315f1a movwhs r4, #0x9798 */
/* @0x315f1e stmdals r8, {r0, r1, r3, r5, sp, lr} */
/* @0x315f22 eorlt pc, r0, r5, asr #17 */
/* @0x315f26 andsls pc, r12, r5, asr #17 */
/* @0x315f2a .word 0xe1676060 */
/* @0x315f2e adcvs r2, r10, r5, lsl #6 */
/* @0x315f32 .word 0xf8df602b */
/* @0x315f36 .word 0xf8df1520 */
/* @0x315f3a ldrbtmi r2, [r9], #-1312 */
/* @0x315f3e ldrbtmi r9, [r10], #-267 */
/* @0x315f42 rsbs r9, r6, r12, lsl #4 */
/* @0x315f46 .word 0xf8c59908 */
/* @0x315f4a .word 0xf8c5b020 */
/* @0x315f4e rsbvs r9, r1, r12, lsl r0 */
/* @0x315f52 blls 0x54df6e <gp_ActiveMaskObjects+0x92a6> */
/* @0x315f56 eorlt pc, r0, r5, asr #17 */
/* @0x315f5a andsls pc, r12, r5, asr #17 */
/* @0x315f5e stmdavs r3!, {r0, r1, r5, r6, sp, lr} */
/* @0x315f62 .word 0xf8c44628 */
/* @0x315f66 strtmi r10, [r1], -r0 */
/* @0x315f6a andeq lr, r10, #199680 */
/* @0x315f6e ldrmi r6, [r3], #-2211 */
/* @0x315f72 adcvs r4, r3, r10, lsr r6 */
/* @0x315f76 .word 0xf000636e */
/* @0x315f7a stmdbls sp, {r0, r1, r4, r6, r10, r11, r12, sp, pc} */
/* @0x315f7e svclt #0x142912 */
/* @0x315f82 mrshs r3, apsr */
/* @0x315f86 vmlaeq.f64 d14, d0, d1 */
/* @0x315f8a .word 0xf04fbf14 */
/* @0x315f8e .word 0xf04f0803 */
/* @0x315f92 ldrbmi r0, [r1, #0x80b]! */
/* @0x315f96 bls 0x64ad1a <g_SWFaavertbuff+0x77c52> */
/* @0x315f9a .word 0xfc00fa2b */
/* @0x315f9e andeq lr, r9, r0, asr #23 */
/* @0x315fa2 vdiveq.f64 d14, d1, d2 */
/* @0x315fa6 stmdbeq r0, {r0, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x315faa blx 0xe3bfda <b2_toiTime+0x6e2b36> */
/* @0x315fae .word 0xf8defb01 */
/* @0x315fb2 b 0x64e10a <g_SWFaavertbuff+0x7b042> */
/* @0x315fb6 strbmi r0, [r6], #3598 */
/* @0x315fba .word 0x0103eb0e */
/* @0x315fbe ldmdble r10, {r0, r7, r9, lr} ^ */
/* @0x315fc2 bvs 0xfeb30956 <b2_toiTime+0xfffffffffe3d74b2> */
/* @0x315fc6 ldrmi r6, [r8, r9, ror #17] */
/* @0x315fca eorvs r2, r11, r9, lsl #6 */
/* @0x315fce ldrlo pc, [r0], #2271 */
/* @0x315fd2 stmdbls r8, {r0, r1, r3, r4, r5, r6, r10, lr} */
/* @0x315fd6 .word 0xf8c561a3 */
/* @0x315fda .word 0xf8c5b020 */
/* @0x315fde rsbvs r9, r1, r12, lsl r0 */
/* @0x315fe2 stmdals r8, {r0, r2, r3, r4, r5, r6, r7, r8, r9, sp, lr, pc} */
/* @0x315fe6 adcle r2, sp, r0, lsl #16 */
/* @0x315fea blne 0x39405a <ft_adobe_glyph_list+0x3736> */
/* @0x315fee stmdalo r1, {r8, r9, r10, sp} */
/* @0x315ff2 blx 0x37a01a <_ZTS13C_UTF16String+0x110c6> */
/* @0x315ff6 .word 0xf109f109 */
/* @0x315ffa b 0x15d8422 <b2_toiTime+0xe7ef7e> */
/* @0x315ffe ldrmi r0, [r1, #0xb01] */
/* @0x316002 .word 0xf8ddd3ef */
/* @0x316006 bl 0x6ce0be <g_SWFlinevertbuff+0x7aff6> */
/* @0x31600a ldclvs p2, c0, [r1, #-520] */
/* @0x31600e b 0x5f05be <g_SWFaavertbuff+0x1d4f6> */
/* @0x316012 bl 0x39641e <ft_adobe_glyph_list+0x5afa> */
/* @0x316016 ldmdavc r0, {r0, r6, r7, r9} ^ */
/* @0x31601a bhs 0x6f016a <g_SWFvertbuff+0x1d0a2> */
/* @0x31601e stmle r12!, {r0, r2, r3, r9, r12, pc} */
/* @0x316022 blx 0xdf03ce <b2_toiTime+0x696f2a> */
/* @0x316026 bl 0xff354c2e <b2_toiTime+0xfffffffffebfb78a> */
/* @0x31602a mrrcne p9, #0x0, r0, r8, c9 */
/* @0x31602e .word 0xf84160a8 */
/* @0x316032 stmdavs r9!, {r0, r1, r5, sp} ^ */
/* @0x316036 .word 0xf00168ab */
/* @0x31603a vmov.i32 d16, #0x9f00 */
/* @0x31603e .word 0x910d1144 */
/* @0x316042 orrvc pc, r1, r2, lsl #10 */
/* @0x316046 ldrsbt pc, [r4], -sp */
/* @0x31604a .word 0xf8cd448e */
/* @0x31604e ldrbmi lr, [r3, #-0x28]! */
/* @0x316052 stmdbvs r10!, {r3, r5, r9, r12, lr, pc} */
/* @0x316056 bls 0x54ffaa <gp_ActiveMaskObjects+0xb2e2> */
/* @0x31605a .word 0xf43f2a00 */
/* @0x31605e .word 0xf81aaf7a */
/* @0x316062 blo 0x374c6e <_ZTS13C_UTF16String+0xbd1a> */
/* @0x316066 blx 0x4fa88e <SrcVerts+0x578d2> */
/* @0x31606a .word 0xf109f709 */
/* @0x31606e b 0x15d8496 <b2_toiTime+0xe7eff2> */
/* @0x316072 strhs r0, [r0, -r7, lsl #22] */
/* @0x316076 bls 0x68feb2 <g_SWFlinevertbuff+0x3cdea> */
/* @0x31607a .word 0xd1082a10 */
/* @0x31607e addsle r2, pc, r0, lsl #22 */
/* @0x316082 addmi pc, r0, r3, lsl #2 */
/* @0x316086 stmdalo r1, {r1, r3, r5, r6, r7, r11, sp, lr} */
/* @0x31608a eoreq pc, r0, r2, asr r8 */
/* @0x31608e andhs lr, r0, r0 */
/* @0x316092 stmvs r10!, {r0, r1, r3, r4, r7} ^ */
/* @0x316096 mcreq p1, #0x0, pc, c1, c14, #0x5 */
/* @0x31609a .word 0xf10350d0 */
/* @0x31609e mvnsle r0, r4, lsl #6 */
/* @0x3160a2 strb r6, [r6, r9, lsr #1] */
/* @0x3160a6 smlatths r9, r8, r8, r6 */
/* @0x3160aa .word 0x21069115 */
/* @0x3160ae movwhs r9, #0x116 */
/* @0x3160b2 .word 0xf2026a69 */
/* @0x3160b6 .word 0x616b1201 */
/* @0x3160ba andhs r9, r4, #-1610612736 */
/* @0x3160be .word 0x910c900b */
/* @0x3160c2 orrsvc pc, r0, pc, asr #8 */
/* @0x3160c6 bvs 0xfeb3ad32 <b2_toiTime+0xfffffffffe3e188e> */
/* @0x3160ca ldrmi r6, [r8, r3, lsr #20] */
/* @0x3160ce stmdahs r0, {r7, r9, r10, lr} */
/* @0x3160d2 bls 0x6ca2d6 <g_SWFlinevertbuff+0x7720e> */
/* @0x3160d6 stcleq p1, c15, [r4], #-52 */
/* @0x3160da .word 0xf5029005 */
/* @0x3160de movwls r7, #0x38a */
/* @0x3160e2 movwls r10, #0x1b17 */
/* @0x3160e6 movwls r10, #0x2b15 */
/* @0x3160ea .word 0xf2409b0c */
/* @0x3160ee .word 0xf8cd1201 */
/* @0x3160f2 stmdals r11, {r4, lr, pc} */
/* @0x3160f6 stmdbls r10, {r0, r1, r8, r9, r12, pc} */
/* @0x3160fa .word 0xf8cd9b12 */
/* @0x3160fe .word 0xf7ffc018 */
/* @0x316102 .word 0xf8ddf844 */
/* @0x316106 .word 0x4602c018 */
/* @0x31610a blls 0x884552 <b2_toiTime+0x12b0ae> */
/* @0x31610e ands r11, r4, r3, asr #2 */
/* @0x316112 smlabtle r3, r1, r12, r1 */
/* @0x316116 ldrbtmi r4, [r11], #-3027 */
/* @0x31611a and r6, r6, r3, lsr #3 */
/* @0x31611e andle r1, r4, r3, lsl #26 */
/* @0x316122 .word 0xf06f4bd1 */
/* @0x316126 ldrbtmi r0, [r11], #-514 */
/* @0x31612a bvs 0x1bee7be <b2_toiTime+0x149531a> */
/* @0x31612e bvs 0xfeb27a3a <b2_toiTime+0xfffffffffe3ce596> */
/* @0x316132 ldrmi r9, [r8, r7, lsl #4] */
/* @0x316136 ldrmi r9, [r0], r7, lsl #20 */
/* @0x31613a .word 0xf8dde04e */
/* @0x31613e stmdals r12, {r3, r4, r5, sp, lr, pc} */
/* @0x316142 movwvc pc, #0x250e */
/* @0x316146 blge 0x93ad4e <b2_toiTime+0x1e18aa> */
/* @0x31614a blge 0x8bad56 <b2_toiTime+0x1618b2> */
/* @0x31614e blls 0x5bad5e <g_SWFlineaavertbuff+0x67c96> */
/* @0x316152 .word 0xf8dd990b */
/* @0x316156 andls lr, r3, r4, lsr r0 */
/* @0x31615a addeq lr, r3, r1, lsl #22 */
/* @0x31615e mrseq pc, apsr */
/* @0x316162 ldrsbt pc, [r8], -sp */
/* @0x316166 andsgt pc, r0, sp, asr #17 */
/* @0x31616a bicvc pc, r8, #58720256 */
/* @0x31616e andshi pc, r4, sp, asr #17 */
/* @0x316172 .word 0xf80bf7ff */
/* @0x316176 strmi r6, [r4], r3, ror #20 */
/* @0x31617a bls 0x8c4662 <b2_toiTime+0x16b1be> */
/* @0x31617e stmdals r10, {r1, r3, r4, r8, r9, r11, r12, sp, pc} */
/* @0x316182 .word 0x1101f240 */
/* @0x316186 tstle r0, r8, lsl #5 */
/* @0x31618a .word 0xf110e01d */
/* @0x31618e .word 0xd1030f03 */
/* @0x316192 ldrbtmi r4, [r10], #-2742 */
/* @0x316196 and r6, sp, r2, lsr #3 */
/* @0x31619a svceq #0x5f110 */
/* @0x31619e bmi 0xff00a5ae <b2_toiTime+0xfffffffffe8b110a> */
/* @0x3161a2 and r4, r4, r10, ror r4 */
/* @0x3161a6 svceq #0x4f110 */
/* @0x3161aa bmi 0xfef8a1c2 <b2_toiTime+0xfffffffffe830d1e> */
/* @0x3161ae .word 0xf06f447a */
/* @0x3161b2 .word 0x61a20c02 */
/* @0x3161b6 strbmi r6, [r1], -r0, lsr #21 */
/* @0x3161ba andsgt pc, r8, sp, asr #17 */
/* @0x3161be .word 0xf8dd4798 */
/* @0x3161c2 usatmi r12, #0x0, r8 */
/* @0x3161c6 strbmi lr, [r1], -r8 */
/* @0x3161ca ldrmi r6, [r8, r0, lsr #21] */
/* @0x3161ce stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x3161d2 .word 0xf06fe021 */
/* @0x3161d6 and r0, r11, r3, lsl #16 */
/* @0x3161da svceq #0xf1b8 */
/* @0x3161de .word 0xf118d01b */
/* @0x3161e2 .word 0xd1050f03 */
/* @0x3161e6 bvs 0xfeb30b7a <b2_toiTime+0xfffffffffe3d76d6> */
/* @0x3161ea ldrmi r6, [r8, r9, ror #17] */
/* @0x3161ee eorvs r2, r11, r9, lsl #6 */
/* @0x3161f2 .word 0xf8c59a08 */
/* @0x3161f6 .word 0xf8c5b020 */
/* @0x3161fa rsbvs r9, r2, r12, lsl r0 */
/* @0x3161fe strtmi r6, [r8], -r3, lsr #16 */
/* @0x316202 andge pc, r0, r4, asr #17 */
/* @0x316206 bl 0xff3e7a92 <b2_toiTime+0xfffffffffec8e5ee> */
/* @0x31620a stmvs r3!, {r1, r3, r9} */
/* @0x31620e .word 0x46424413 */
/* @0x316212 .word 0x636e60a3 */
/* @0x316216 blls 0x88ee2e <b2_toiTime+0x13598a> */
/* @0x31621a bvs 0xfeb1e626 <b2_toiTime+0xfffffffffe3c5182> */
/* @0x31621e movwls r2, #0xa21c */
/* @0x316222 movwls r9, #0xdb16 */
/* @0x316226 movwls r9, #0xbb17 */
/* @0x31622a movwls r9, #0xcb18 */
/* @0x31622e ldrmi r6, [r8, r3, lsr #20] */
/* @0x316232 .word 0xf0002800 */
/* @0x316236 blls 0x5b702e <g_SWFlineaavertbuff+0x63f66> */
/* @0x31623a andhi pc, r0, r0, asr #17 */
/* @0x31623e blls 0x673252 <g_SWFlinevertbuff+0x2018a> */
/* @0x316242 blls 0x5f3356 <g_SWFaavertbuff+0x2028e> */
/* @0x316246 blls 0x62e75a <g_SWFaavertbuff+0x5b692> */
/* @0x31624a rsbvs r6, r8, r3, lsl #3 */
/* @0x31624e bvs 0x1bf05fa <b2_toiTime+0x1497156> */
/* @0x316252 ldrmi r6, [r8, r0, lsr #21] */
/* @0x316256 eorvs r2, r11, r6, lsl #6 */
/* @0x31625a eorlt pc, r0, r5, asr #17 */
/* @0x31625e andsls pc, r12, r5, asr #17 */
/* @0x316262 stmdals r8, {r0, r1, r5, r11, sp, lr} */
/* @0x316266 andeq lr, r10, #199680 */
/* @0x31626a .word 0xf8c468a3 */
/* @0x31626e rsbvs r10, r0, r0 */
/* @0x316272 adcvs r4, r3, r3, lsl r4 */
/* @0x316276 .word 0x636e6b29 */
/* @0x31627a stmdavs r11!, {r1, r2, r3, r7, r9, lr} ^ */
/* @0x31627e andne lr, r0, #148, #16 */
/* @0x316282 .word 0xa020f8d5 */
/* @0x316286 ldrsbhi pc, [r12], -r5 */
/* @0x31628a blne 0xfe58aaa6 <b2_toiTime+0xfffffffffde31602> */
/* @0x31628e bmi 0x216469a <b2_toiTime+0x1a0b1f6> */
/* @0x316292 andls r4, r8, #2046820352 */
/* @0x316296 bvs 0xffd8e2c6 <b2_toiTime+0xffffffffff634e22> */
/* @0x31629a ldrb r1, [r8, r9, lsl #23]! */
/* @0x31629e svceq #0x40f010 */
/* @0x3162a2 sbcsvs sp, r8, lr, asr #2 */
/* @0x3162a6 bl 0x3b03ee <error_g0017+0x9092> */
/* @0x3162aa addsvs r0, r10, r0, asr #5 */
/* @0x3162ae bhs 0x57031e <g_SWFlineaavertbuff+0x1d256> */
/* @0x3162b2 eorhi pc, r4, #0, #4 */
/* @0x3162b6 .word 0xf012e8df */
/* @0x3162ba andseq r0, r0, r10 */
/* @0x3162be rsbseq r0, r4, sp, asr #32 */
/* @0x3162c2 tsteq r10, r11, lsr #1 */
/* @0x3162c6 biceq r0, sp, r9, ror r1 */
/* @0x3162ca andeq r0, lr, #-1073741762 */
/* @0x3162ce sbcsvs r7, r10, r10, lsl r12 */
/* @0x3162d2 addsvs r6, r10, r10, asr r9 */
/* @0x3162d6 andsvs r2, r10, r1, lsl #4 */
/* @0x3162da ldrmi r6, [r0, #0x8da] */
/* @0x3162de .word 0xf1bcd20f */
/* @0x3162e2 .word 0xf0000f00 */
/* @0x3162e6 .word 0xf81980d0 */
/* @0x3162ea .word 0xf10c0b01 */
/* @0x3162ee .word 0x27003cff */
/* @0x3162f2 .word 0xf008fa00 */
/* @0x3162f6 stmdaeq r8, {r3, r8, r12, sp, lr, pc} */
/* @0x3162fa beq 0x350c2a */
/* @0x3162fe ldmdami lr, {r0, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x316302 bl 0x3274ea */
/* @0x316306 ldmvs r8, {r1, r7, r9} */
/* @0x31630a b 0x5b185a <g_SWFlineaavertbuff+0x5e792> */
/* @0x31630e bl 0x319b1e <__gnu_Unwind_ForcedUnwind+0xe> */
/* @0x316312 .word 0xf81002ce */
/* @0x316316 .word 0xf892003e */
/* @0x31631a blx 0xdc2326 <b2_toiTime+0x668e82> */
/* @0x31631e bl 0xff614b52 <b2_toiTime+0xfffffffffeebb6ae> */
/* @0x316322 ldmdblt r8, {r3, r11} */
/* @0x316326 addsvs r6, r10, r2, asr r8 */
/* @0x31632a teq r12, r6, lsl #4 */
/* @0x31632e svceq #0x10f010 */
/* @0x316332 .word 0xf000d0b4 */
/* @0x316336 addsvs r0, r8, pc */
/* @0x31633a subsvs r6, r10, r2, asr r8 */
/* @0x31633e teq r2, r2, lsl #4 */
/* @0x316342 strle r0, [r1, #-0x682] */
/* @0x316346 .word 0xe12e2207 */
/* @0x31634a andsvs r2, r10, r9, lsl #4 */
/* @0x31634e ldrbtmi r4, [r11], #-2892 */
/* @0x316352 ldmvs r10, {r0, r1, r3, r4, r6, sp, lr, pc} */
/* @0x316356 andle r4, pc, #144, #10 */
/* @0x31635a svceq #0xf1bc */
/* @0x31635e addshi pc, r3, r0 */
/* @0x316362 bleq 0x3943ce <ft_adobe_glyph_list+0x3aaa> */
/* @0x316366 ldcllo p1, c15, [pc], #48 */
/* @0x31636a blx 0x31ff72 */
/* @0x31636e .word 0xf108f008 */
/* @0x316372 b 0x159839a <b2_toiTime+0xe3eef6> */
/* @0x316376 strb r0, [sp, r0, lsl #20]! */
/* @0x31637a .word 0xe020f8dd */
/* @0x31637e stmdaeq r8, {r1, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x316382 addeq lr, r2, lr, lsl #22 */
/* @0x316386 b 0x5b188e <g_SWFlineaavertbuff+0x5e7c6> */
/* @0x31638a blx 0xd99b92 <b2_toiTime+0x6406ee> */
/* @0x31638e .word 0x7c5afa02 */
/* @0x316392 sbcsvs r6, r10, r8, asr r8 */
/* @0x316396 ldmibvs r10, {r4, r5, r6, r10, lr} */
/* @0x31639a addsvs r6, r10, r8, asr r0 */
/* @0x31639e andsvs r2, r10, r3, lsl #4 */
/* @0x3163a2 ldrmi r6, [r0, #0x8da] */
/* @0x3163a6 .word 0xf1bcd20e */
/* @0x3163aa rsble r0, r12, r0, lsl #30 */
/* @0x3163ae bleq 0x39441a <ft_adobe_glyph_list+0x3af6> */
/* @0x3163b2 ldcllo p1, c15, [pc], #48 */
/* @0x3163b6 blx 0x31ffbe */
/* @0x3163ba .word 0xf108f008 */
/* @0x3163be b 0x15983e6 <b2_toiTime+0xe3ef42> */
/* @0x3163c2 strb r0, [lr, r0, lsl #20]! */
/* @0x3163c6 bl 0x33c40e */
/* @0x3163ca ldmvs r8, {r1, r7, r9} */
/* @0x3163ce b 0x5b191e <g_SWFlineaavertbuff+0x5e856> */
/* @0x3163d2 bl 0x319be2 <_Unwind_DeleteException+0x1e> */
/* @0x3163d6 .word 0xf81002ce */
/* @0x3163da .word 0xf892003e */
/* @0x3163de .word 0xf010b001 */
/* @0x3163e2 blx 0xd9a02a <b2_toiTime+0x640b86> */
/* @0x3163e6 bl 0xff614c1a <b2_toiTime+0xfffffffffeebb776> */
/* @0x3163ea andle r0, r6, r8, lsl #16 */
/* @0x3163ee andeq pc, pc, r0 */
/* @0x3163f2 ldmdavs r2, {r3, r4, r7, sp, lr} ^ */
/* @0x3163f6 andhs r6, r4, #218 */
/* @0x3163fa .word 0xf010e0d5 */
/* @0x3163fe .word 0xf43f0f40 */
/* @0x316402 andhs r10, r9, #80, #30 */
/* @0x316406 blmi 0xaae476 <b2_toiTime+0x354fd2> */
/* @0x31640a .word 0x61a3447b */
/* @0x31640e ldmvs r10, {r1, r5, r6, r8, sp, lr, pc} */
/* @0x316412 .word 0xf7d8e05a */
/* @0x316416 cdpls p0, #0xc, c0, c5, c8, #0x0 */
/* @0x31641a .word 0xf7c00007 */
/* @0x31641e ldclls p0, c0, [r12], #-32 */
/* @0x316422 ldclls p0, c0, [sp], #-28 */
/* @0x316426 mrrcls p0, #0x0, r0, r5, c7 */
/* @0x31642a blls 0xfe89644e <b2_toiTime+0xfffffffffe13cfaa> */
/* @0x31642e .word 0xf5f40007 */
/* @0x316432 .word 0xf5f00008 */
/* @0x316436 ldr r0, [r10], #-8 */
/* @0x31643a bls 0x1b96462 <b2_toiTime+0x143cfbe> */
/* @0x31643e bls 0xc56462 <b2_toiTime+0x4fcfbe> */
/* @0x316442 ldmdbls r12, {r0, r1, r2} */
/* @0x316446 .word 0xf33a0007 */
/* @0x31644a vaddl.s32 q8, d2, d8 */
/* @0x31644e ldmdals r4!, {r3} */
/* @0x316452 stmdals r6, {r0, r1, r2} ^ */
/* @0x316456 vhadd.s8 d0, d4, d7 */
/* @0x31645a vhadd.s8 d0, d0, d8 */
/* @0x31645e strls r0, [r10, r8] */
/* @0x316462 ldrbls r0, [lr], -r7 */
/* @0x316466 ldrbtls r0, [r1], -r7 */
/* @0x31646a strtls r0, [r4], -r7 */
/* @0x31646e ldrtls r0, [r3], -r7 */
/* @0x316472 strbls r0, [r0], -r7 */
/* @0x316476 cdp p0, #0xa, c0, c14, c7, #0x0 */
/* @0x31647a cdp p0, #0x3, c0, c14, c8, #0x0 */
/* @0x31647e ldrtls r0, [pc], #8 */
/* @0x316482 strtls r0, [r1], #-7 */
/* @0x316486 .word 0xf8c50007 */
/* @0x31648a strtmi r10, [r8], -r0, lsr #32 */
/* @0x31648e andshi pc, r12, r5, asr #17 */
/* @0x316492 stmdavs r3!, {r0, r5, r9, r10, lr} */
/* @0x316496 andgt pc, r4, r4, asr #17 */
/* @0x31649a andeq lr, r9, #199680 */
/* @0x31649e .word 0xf8c468a3 */
/* @0x3164a2 ldrmi r9, [r3], #-0 */
/* @0x3164a6 adcvs r4, r3, r10, lsr r6 */
/* @0x3164aa teq r10, lr, ror #6 */
/* @0x3164ae svceq #0xf1bc */
/* @0x3164b2 .word 0xf819d0e9 */
/* @0x3164b6 .word 0xf10c0b01 */
/* @0x3164ba .word 0x27003cff */
/* @0x3164be .word 0xf008fa00 */
/* @0x3164c2 stmdaeq r8, {r3, r8, r12, sp, lr, pc} */
/* @0x3164c6 beq 0x350df6 */
/* @0x3164ca .word 0xd3ef4590 */
/* @0x3164ce ldrsbt pc, [r12], -sp */
/* @0x3164d2 stmdaeq r8, {r1, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x3164d6 addeq lr, r2, lr, lsl #22 */
/* @0x3164da b 0x5b19e2 <g_SWFlineaavertbuff+0x5e91a> */
/* @0x3164de ldmvs r8, {r9, r10, r11} ^ */
/* @0x3164e2 blx 0x3d4d92 <error_g0017+0x2da36> */
/* @0x3164e6 ldrbtmi r2, [r0], #-517 */
/* @0x3164ea sbcsvs r6, r8, r10, lsl r0 */
/* @0x3164ee bl 0xff3b085e <b2_toiTime+0xfffffffffec573ba> */
/* @0x3164f2 bvs 0xfed99112 <b2_toiTime+0xfffffffffe63fc6e> */
/* @0x3164f6 andsle r4, r6, #616562688 */
/* @0x3164fa bne 0xfe3310a2 <b2_toiTime+0xfffffffffdbd7bfe> */
/* @0x3164fe ldrb r4, [r9, r3, lsl #9]! */
/* @0x316502 .word 0xf89bb1a9 */
/* @0x316506 .word 0xf10b0000 */
/* @0x31650a .word 0xf1060201 */
/* @0x31650e stmdblo r1, {r0, r9, r10, r11} */
/* @0x316512 eorsvc r2, r0, r0, lsl #14 */
/* @0x316516 bvs 0xffd27ef6 <b2_toiTime+0xffffffffff5cea52> */
/* @0x31651a ldmdavs r8, {r1, r7, r9, lr} ^ */
/* @0x31651e bvs 0xfedc6146 <b2_toiTime+0xfffffffffe66cca2> */
/* @0x316522 subsvs r3, r8, r1, lsl #16 */
/* @0x316526 ldmdavs r10, {r0, r1, r4, r7, r9, r10, lr} ^ */
/* @0x31652a mvnle r2, r0, lsl #20 */
/* @0x31652e bvs 0xffdce622 <b2_toiTime+0xffffffffff67517e> */
/* @0x316532 swple r4, r6, [lr] */
/* @0x316536 bvs 0xfedb11e2 <b2_toiTime+0xfffffffffe657d3e> */
/* @0x31653a mulle r10, r1, r2 */
/* @0x31653e svclt #0x36428a */
/* @0x316542 smlabteq r1, r2, r11, lr */
/* @0x316546 smlabteq r6, r2, r11, lr */
/* @0x31654a mvnslo pc, r1, lsl #2 */
/* @0x31654e stmdbhs r0, {r1, r2, r4, r9, r10, lr} */
/* @0x316552 .word 0x636ed1d7 */
/* @0x316556 ldrtmi r4, [r10], -r1, lsr #12 */
/* @0x31655a movwls r4, #0x7628 */
/* @0x31655e andsgt pc, r8, sp, asr #17 */
/* @0x316562 .word 0xf885f7ff */
/* @0x316566 blvs 0xef1326 <b2_toiTime+0x797e82> */
/* @0x31656a adcsmi r9, lr, #7168 */
/* @0x31656e ldrsbgt pc, [r8], -sp */
/* @0x316572 bl 0xff4c625a <b2_toiTime+0xfffffffffed6cdb6> */
/* @0x316576 strmi r0, [r2], -r7, lsl #2 */
/* @0x31657a svclt #0x346ae8 */
/* @0x31657e mvnslo pc, r1, lsl #2 */
/* @0x316582 smlabteq r0, r6, r11, lr */
/* @0x316586 smlabble r11, r6, r2, r4 */
/* @0x31658a addmi r6, r7, #168, #20 */
/* @0x31658e adcsmi sp, r8, #8 */
/* @0x316592 bl 0xff346272 <b2_toiTime+0xfffffffffebecdce> */
/* @0x316596 bl 0xff3169ba <b2_toiTime+0xfffffffffebbd516> */
/* @0x31659a .word 0xf1010106 */
/* @0x31659e .word 0x460631ff */
/* @0x3165a2 .word 0xd1ae2900 */
/* @0x3165a6 andsvs lr, r10, sp, lsr r0 */
/* @0x3165aa stmdbhs r0, {r7, r9, r10, sp, lr, pc} */
/* @0x3165ae bvs 0xffdcaada <b2_toiTime+0xffffffffff671636> */
/* @0x3165b2 swple r4, r6, [lr] */
/* @0x3165b6 bvs 0xfedb1262 <b2_toiTime+0xfffffffffe657dbe> */
/* @0x3165ba mulle r10, r1, r2 */
/* @0x3165be svclt #0x36428a */
/* @0x3165c2 smlabteq r1, r2, r11, lr */
/* @0x3165c6 smlabteq r6, r2, r11, lr */
/* @0x3165ca mvnslo pc, r1, lsl #2 */
/* @0x3165ce stmdbhs r0, {r1, r2, r4, r9, r10, lr} */
/* @0x3165d2 .word 0x636ed137 */
/* @0x3165d6 ldrtmi r4, [r10], -r1, lsr #12 */
/* @0x3165da movwls r4, #0x7628 */
/* @0x3165de andsgt pc, r8, sp, asr #17 */
/* @0x3165e2 .word 0xf845f7ff */
/* @0x3165e6 blvs 0xef13a6 <b2_toiTime+0x797f02> */
/* @0x3165ea adcsmi r9, lr, #7168 */
/* @0x3165ee ldrsbgt pc, [r8], -sp */
/* @0x3165f2 bl 0xff4c62da <b2_toiTime+0xfffffffffed6ce36> */
/* @0x3165f6 strmi r0, [r2], -r7, lsl #2 */
/* @0x3165fa svclt #0x346ae8 */
/* @0x3165fe mvnslo pc, r1, lsl #2 */
/* @0x316602 smlabteq r0, r6, r11, lr */
/* @0x316606 smlabble r11, r6, r2, r4 */
/* @0x31660a addmi r6, r7, #168, #20 */
/* @0x31660e adcsmi sp, r8, #8 */
/* @0x316612 bl 0xff3462f2 <b2_toiTime+0xfffffffffebece4e> */
/* @0x316616 bl 0xff316a3a <b2_toiTime+0xfffffffffebbd596> */
/* @0x31661a .word 0xf1010106 */
/* @0x31661e .word 0x460631ff */
/* @0x316622 .word 0xf8c5b979 */
/* @0x316626 .word 0xf8c5a020 */
/* @0x31662a stmdavs r3!, {r2, r3, r4, pc} */
/* @0x31662e andgt pc, r4, r4, asr #17 */
/* @0x316632 smlabteq r9, r3, r11, lr */
/* @0x316636 .word 0xf8c468a3 */
/* @0x31663a strmi r9, [r11], #-0 */
/* @0x31663e .word 0x636e60a3 */
/* @0x316642 ldmvs r10, {r4, r5, sp, lr, pc} */
/* @0x316646 stmdblo r1, {r8, r9, r10, sp} */
/* @0x31664a .word 0xf8063601 */
/* @0x31664e andsvs r2, pc, r1, lsl #24 */
/* @0x316652 .word 0xf1b8e62c */
/* @0x316656 stmdble r5, {r0, r1, r2, r8, r9, r10, r11} */
/* @0x31665a stmdaeq r8, {r3, r5, r7, r8, r12, sp, lr, pc} */
/* @0x31665e .word 0x0c01f10c */
/* @0x316662 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^ */
/* @0x316666 strtmi r6, [r1], -lr, ror #6 */
/* @0x31666a qasxmi r4, r8, r10 */
/* @0x31666e .word 0xf8cd9307 */
/* @0x316672 .word 0xf7fec018 */
/* @0x316676 blvs 0x1d9666e <b2_toiTime+0x163d1ca> */
/* @0x31667a blls 0x4f133a <SrcVerts+0x4e37e> */
/* @0x31667e .word 0xf8dd428e */
/* @0x316682 .word 0x4602c018 */
/* @0x316686 .word 0xf8c5d011 */
/* @0x31668a .word 0xf8c5a020 */
/* @0x31668e stmdavs r3!, {r2, r3, r4, pc} */
/* @0x316692 andgt pc, r4, r4, asr #17 */
/* @0x316696 andeq lr, r9, r3, asr #23 */
/* @0x31669a .word 0xf8c468a3 */
/* @0x31669e strmi r9, [r3], #-0 */
/* @0x3166a2 .word 0x636960a3 */
/* @0x3166a6 strtmi r4, [r1], -r8, lsr #12 */
/* @0x3166aa andhs lr, r8, #59 */
/* @0x3166ae .word 0xf8c5601a */
/* @0x3166b2 strtmi r10, [r8], -r0, lsr #32 */
/* @0x3166b6 andshi pc, r12, r5, asr #17 */
/* @0x3166ba stmdavs r3!, {r0, r5, r9, r10, lr} */
/* @0x3166be andgt pc, r4, r4, asr #17 */
/* @0x3166c2 andeq lr, r9, #199680 */
/* @0x3166c6 .word 0xf8c468a3 */
/* @0x3166ca ldrmi r9, [r3], #-0 */
/* @0x3166ce adcvs r2, r3, r1, lsl #4 */
/* @0x3166d2 eor r6, r6, lr, ror #6 */
/* @0x3166d6 eorge pc, r0, r5, asr #17 */
/* @0x3166da .word 0xf8c54628 */
/* @0x3166de qadd16mi r8, r1, r12 */
/* @0x3166e2 .word 0xf8c46823 */
/* @0x3166e6 bl 0xff4066fe <b2_toiTime+0xfffffffffecad25a> */
/* @0x3166ea stmvs r3!, {r0, r3, r9} */
/* @0x3166ee andls pc, r0, r4, asr #17 */
/* @0x3166f2 .word 0xf06f4413 */
/* @0x3166f6 adcvs r0, r3, r2, lsl #4 */
/* @0x3166fa ands r6, r2, lr, ror #6 */
/* @0x3166fe eorge pc, r0, r5, asr #17 */
/* @0x316702 .word 0xf8c54628 */
/* @0x316706 qadd16mi r8, r1, r12 */
/* @0x31670a .word 0xf8c46823 */
/* @0x31670e bl 0xff406726 <b2_toiTime+0xfffffffffecad282> */
/* @0x316712 stmvs r3!, {r0, r3, r9} */
/* @0x316716 andls pc, r0, r4, asr #17 */
/* @0x31671a .word 0xf06f4413 */
/* @0x31671e adcvs r0, r3, r1, lsl #4 */
/* @0x316722 .word 0xf7fe636e */
/* @0x316726 stmdahs r1, {r2, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x31672a teqle r10, r2, lsl #12 */
/* @0x31672e bvs 0xfeb310c2 <b2_toiTime+0xfffffffffe3d7c1e> */
/* @0x316732 ldrmi r6, [r8, r9, ror #16] */
/* @0x316736 blvs 0x1eb13ea <b2_toiTime+0x1757f46> */
/* @0x31673a addsmi r6, lr, #96, #16 */
/* @0x31673e svclt #0x3869af */
/* @0x316742 stmdaeq r3, {r1, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x316746 .word 0xa000f8d4 */
/* @0x31674a bvs 0xffe06402 <b2_toiTime+0xffffffffff6acf5e> */
/* @0x31674e ldmlo pc!, {r3, r8, r12, sp, lr, pc} ^ */
/* @0x316752 .word 0xf8d59008 */
/* @0x316756 svclt #0x28b020 */
/* @0x31675a stmdaeq r3, {r1, r2, r6, r7, r8, r9, r11, sp, lr, pc} */
/* @0x31675e ldrsbls pc, [r12], -r5 */
/* @0x316762 eorvs r11, pc, r7, lsl r9 */
/* @0x316766 blt 0x9d476a <b2_toiTime+0x27b2c6> */
/* @0x31676a movwhs r2, #0x7700 */
/* @0x31676e .word 0x636e602b */
/* @0x316772 qasxmi r4, r8, r10 */
/* @0x316776 .word 0xf7fe4621 */
/* @0x31677a blvs 0x1e1656a <b2_toiTime+0x16bd0c6> */
/* @0x31677e addsmi r6, lr, #47104 */
/* @0x316782 andsle r4, r1, r2, lsl #12 */
/* @0x316786 .word 0xf8c59908 */
/* @0x31678a .word 0xf8c5b020 */
/* @0x31678e rsbvs r9, r1, r12, lsl r0 */
/* @0x316792 .word 0xf8c46821 */
/* @0x316796 bl 0xff37e79e <b2_toiTime+0xfffffffffec252fa> */
/* @0x31679a stmvs r1!, {r1, r3} */
/* @0x31679e adcvs r4, r1, r1, lsl #8 */
/* @0x3167a2 strtmi r6, [r8], -r11, ror #6 */
/* @0x3167a6 eors r4, r11, r1, lsr #12 */
/* @0x3167aa eorvs r2, r11, r8, lsl #6 */
/* @0x3167ae strtmi r9, [r8], -r8, lsl #20 */
/* @0x3167b2 eorlt pc, r0, r5, asr #17 */
/* @0x3167b6 .word 0xf8c54621 */
/* @0x3167ba stmdavs r3!, {r2, r3, r4, r12, pc} */
/* @0x3167be bl 0xff3ee94e <b2_toiTime+0xfffffffffec954aa> */
/* @0x3167c2 stmvs r3!, {r1, r3, r9} */
/* @0x3167c6 andge pc, r0, r4, asr #17 */
/* @0x3167ca andhs r4, r1, #318767104 */
/* @0x3167ce .word 0x636e60a3 */
/* @0x3167d2 .word 0xf8c5e026 */
/* @0x3167d6 .word 0xf8c5b020 */
/* @0x3167da blls 0x53a852 <obj_numb_event+0x38e2> */
/* @0x3167de stmdavs r3!, {r0, r1, r5, r6, sp, lr} */
/* @0x3167e2 .word 0xf8c44628 */
/* @0x3167e6 strtmi r10, [r1], -r0 */
/* @0x3167ea andeq lr, r10, #199680 */
/* @0x3167ee ldrmi r6, [r3], #-2211 */
/* @0x3167f2 andeq pc, r2, #111 */
/* @0x3167f6 .word 0x636e60a3 */
/* @0x3167fa .word 0xf8c5e012 */
/* @0x3167fe strtmi r11, [r1], -r0, lsr #32 */
/* @0x316802 andsls pc, r12, r5, asr #17 */
/* @0x316806 stmdals r8, {r0, r1, r5, r11, sp, lr} */
/* @0x31680a andeq lr, r10, #199680 */
/* @0x31680e .word 0xf8c468a3 */
/* @0x316812 rsbvs r10, r0, r0 */
/* @0x316816 qadd16mi r4, r8, r3 */
/* @0x31681a andeq pc, r1, #111 */
/* @0x31681e .word 0x636e60a3 */
/* @0x316822 .word 0xff25f7fe */
/* @0x316826 strmi r1, [r7], -r3, asr #25 */
/* @0x31682a stmibvs r3!, {r0, r1, r2, r8, r12, lr, pc} ^ */
/* @0x31682e andsvs r2, r10, sp, lsl #4 */
/* @0x316832 stmibvs r3!, {r9, sp} ^ */
/* @0x316836 .word 0xf7ff605a */
/* @0x31683a stmdahs r0, {r0, r1, r2, r5, r7, r11, r12, sp, pc} */
/* @0x31683e stmdahs r1, {r0, r1, r4, r5, r6, r12, lr, pc} */
/* @0x316842 stmibvs r2!, {r0, r1, r4, r5, r6, r8, r12, lr, pc} ^ */
/* @0x316846 andlo r4, r4, #34603008 */
/* @0x31684a .word 0xf7fe6910 */
/* @0x31684e stmibvs r3!, {r2, r3, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x316852 ldrsblt r6, [r2, -r10] */
/* @0x316856 andsvs r2, r10, r12, lsl #4 */
/* @0x31685a svcls #0x9e05a */
/* @0x31685e andsvs r2, r10, r8, lsl #4 */
/* @0x316862 blhs 0x3309f6 */
/* @0x316866 bllo 0x38a9f2 <bigtens_D2A+0xec2> */
/* @0x31686a stmvs r3!, {r0, r1, r5, r6, sp, lr} */
/* @0x31686e movwlo r6, #0x19e2 */
/* @0x316872 stmdavs r3!, {r0, r1, r5, r7, sp, lr} */
/* @0x316876 mrrcne p15, #0x0, r9, r9, c9 */
/* @0x31687a ldmdavc r11, {r0, r5, sp, lr} */
/* @0x31687e addsvs r0, r3, r11, lsl r6 */
/* @0x316882 andhs r6, r9, #3719168 */
/* @0x316886 stmdavs r3!, {r1, r3, r4, sp, lr} ^ */
/* @0x31688a suble r2, lr, r0, lsl #22 */
/* @0x31688e rsbvs r3, r3, r1, lsl #22 */
/* @0x316892 stmdavs r2!, {r0, r1, r5, r7, r11, sp, lr} */
/* @0x316896 adcvs r3, r3, r1, lsl #6 */
/* @0x31689a mrrcne p9, #0xe, r6, r0, c3 */
/* @0x31689e ldmvs r9, {r0, r3, r8, r9, r10, r11, r12, pc} */
/* @0x3168a2 ldmdavc r2, {r5, sp, lr} */
/* @0x3168a6 andmi lr, r2, #1024 */
/* @0x3168aa stmibvs r3!, {r1, r3, r4, r7, sp, lr} ^ */
/* @0x3168ae andsvs r2, r10, r10, lsl #4 */
/* @0x3168b2 blhs 0x330a46 */
/* @0x3168b6 bllo 0x38a9a2 <bigtens_D2A+0xe72> */
/* @0x3168ba stmvs r3!, {r0, r1, r5, r6, sp, lr} */
/* @0x3168be movwlo r6, #0x1822 */
/* @0x3168c2 stmibvs r3!, {r0, r1, r5, r7, sp, lr} ^ */
/* @0x3168c6 svcls #0x91c50 */
/* @0x3168ca mlavs r0, r9, r8, r6 */
/* @0x3168ce bl 0x37491e <_ZTS13C_UTF16String+0xb9ca> */
/* @0x3168d2 addsvs r2, r10, r2, lsl #4 */
/* @0x3168d6 andhs r6, r11, #3719168 */
/* @0x3168da stmdavs r3!, {r1, r3, r4, sp, lr} ^ */
/* @0x3168de bllo 0x383592 <_ZTS13C_UTF16String+0x1a63e> */
/* @0x3168e2 stmvs r3!, {r0, r1, r5, r6, sp, lr} */
/* @0x3168e6 movwlo r6, #0x1822 */
/* @0x3168ea stmibvs r3!, {r0, r1, r5, r7, sp, lr} ^ */
/* @0x3168ee ldmvs r9, {r4, r6, r10, r11, r12} */
/* @0x3168f2 ldmdavc r2, {r5, sp, lr} */
/* @0x3168f6 addsvs r4, r10, r10, lsl #8 */
/* @0x3168fa ldmdavs r9, {r0, r1, r5, r6, r7, r8, r11, sp, lr} ^ */
/* @0x3168fe addsmi r6, r1, #10092544 */
/* @0x316902 ldmdbls r1, {r0, r3, r12, lr, pc} */
/* @0x316906 andsvs r2, r10, sp, lsl #4 */
/* @0x31690a stmibvs r3!, {r0, r5, r7, r8, sp, lr} ^ */
/* @0x31690e subsvs r2, r10, r5, lsl #4 */
/* @0x316912 .word 0xf7ff9f09 */
/* @0x316916 andhs r11, r12, #3735552 */
/* @0x31691a and r6, r2, r10, lsl r0 */
/* @0x31691e andeq pc, r1, pc, rrx */
/* @0x316922 andhs lr, r1, r9, lsl r0 */
/* @0x316926 stmdals r9, {r0, r1, r2, r4, sp, lr, pc} */
/* @0x31692a shadd16mi lr, r8, r5 */
/* @0x31692e bls 0x54e982 <gp_ActiveMaskObjects+0x9cba> */
/* @0x316932 .word 0xf8c54628 */
/* @0x316936 strtmi r11, [r1], -r0, lsr #32 */
/* @0x31693a andsls pc, r12, r5, asr #17 */
/* @0x31693e rsbvs r6, r2, r3, lsr #16 */
/* @0x316942 andeq lr, r10, #199680 */
/* @0x316946 .word 0xf8c468a3 */
/* @0x31694a ldrmi r10, [r3], #-0 */
/* @0x31694e andeq pc, r3, #111 */
/* @0x316952 .word 0x636e60a3 */
/* @0x316956 andslt lr, r11, r4, ror #14 */
/* @0x31695a svchi #0xf0e8bd */
/* @0x31695e push {r8, r9, r10, r11, r12, sp, pc} */
/* @0x316962 .word 0xf50043f8 */
/* @0x316966 .word 0xf1005501 */
/* @0x31696a .word 0xf100090c */
/* @0x31696e .word 0xf5000848 */
/* @0x316972 strmi r5, [r4], -r2, lsl #7 */
/* @0x316976 rscvs r3, r11, r8, lsl #6 */
/* @0x31697a vst4.32 {d22, d24, d26, d28}, [pc], r3 */
/* @0x31697e bicvs r5, r3, r0, lsl #7 */
/* @0x316982 blhs 0x331116 */
/* @0x316986 stmdbvs r3!, {r1, r2, r3, r5, r12, lr, pc} */
/* @0x31698a stmdavs r6!, {r0, r1, r3, r8, r9, r11, r12, sp, pc} */
/* @0x31698e .word 0xb1476977 */
/* @0x316992 ldmvs r1!, {r4, r5, r9, r10, lr} */
/* @0x316996 vst1.16 {d20, d21, d22}, [pc], r2 */
/* @0x31699a ldrmi r5, [r8, r0, lsl #7]! */
/* @0x31699e teqlt r0, #7340032 */
/* @0x3169a2 ldmvs r3!, {r0, r1, r2, r3, sp, lr, pc} */
/* @0x3169a6 bne 0x2f0b8a <FT_Done_Memory+0x6f16> */
/* @0x3169aa svcpl #0x80f5b7 */
/* @0x3169ae mvnslt sp, r1, lsl #16 */
/* @0x3169b2 vst4.8 {d30, d31, d0, d1}, [pc], r1 */
/* @0x3169b6 ldmdavs r1!, {r7, r8, r9, r10, r12, lr} */
/* @0x3169ba ldrtmi r4, [r10], -r0, asr #12 */
/* @0x3169be .word 0xf59f4419 */
/* @0x3169c2 ldmvs r3!, {r2, r3, r4, r5, r6, r7, r8, r10, r11, sp, lr, pc} */
/* @0x3169c6 adcsvs r4, r3, r11, lsr r4 */
/* @0x3169ca andhi pc, r12, r4, asr #17 */
/* @0x3169ce strbmi r6, [r8], -r7, lsr #2 */
/* @0x3169d2 .word 0xf7fe2100 */
/* @0x3169d6 stmdahs r1, {r1, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3169da stmibvs r3!, {r0, r1, r2, r8, r12, lr, pc} */
/* @0x3169de addsmi r6, r3, #15335424 */
/* @0x3169e2 andle r6, r6, r11, lsr #2 */
/* @0x3169e6 ldm sp!, {sp} */
/* @0x3169ea stmdahs r0, {r3, r4, r5, r6, r7, r8, r9, pc} */
/* @0x3169ee stmvs r11!, {r3, r6, r7, r12, lr, pc} ^ */
/* @0x3169f2 subshs r6, r5, r11, lsr #2 */
/* @0x3169f6 .word 0x83f8e8bd */
/* @0x3169fa ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x3169fe strpl pc, [r1], #-1280 */
/* @0x316a02 .word 0x46054698 */
/* @0x316a06 strmi r6, [r9], r3, lsr #17 */
/* @0x316a0a .word 0xf1044692 */
/* @0x316a0e addsmi r0, r9, #8, #14 */
/* @0x316a12 stmdavs r0, {r3, r4, r9, r12, lr, pc} */
/* @0x316a16 .word 0xf7cf6c69 */
/* @0x316a1a strmi pc, [r6], -r5, asr #30 */
/* @0x316a1e .word 0xf04fb110 */
/* @0x316a22 sub r0, r6, r0, lsl #18 */
/* @0x316a26 andeq pc, r12, r5, lsl #2 */
/* @0x316a2a mcr2 p7, #0x7, pc, c6, c14, #0x7 */
/* @0x316a2e movteq pc, #0x8105 */
/* @0x316a32 .word 0xf50560eb */
/* @0x316a36 smlawbvs lr, r2, r3, r5 */
/* @0x316a3a mvnvs r3, r8, lsl #6 */
/* @0x316a3e smulwbvs r7, r11, r1 */
/* @0x316a42 adcvs r6, r6, r7, ror #1 */
/* @0x316a46 ldrmi r6, [r1, #0x8a6]! */
/* @0x316a4a bl 0xff4ccea2 <b2_toiTime+0xfffffffffed739fe> */
/* @0x316a4e stmvs r2!, {r0, r3, r9, r10} ^ */
/* @0x316a52 bne 0xfe9f0ee6 <b2_toiTime+0xfffffffffe297a42> */
/* @0x316a56 svclt #0x38429e */
/* @0x316a5a ldrmi r4, [r10], #-1587 */
/* @0x316a5e ldmdavs r10!, {r1, r5, r6, r7, sp, lr} */
/* @0x316a62 ldrmi r1, [r10], #-2806 */
/* @0x316a66 andle r6, r5, r10, lsr r0 */
/* @0x316a6a .word 0xf7ff4628 */
/* @0x316a6e stmdahs r0, {r3, r4, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x316a72 ldrb sp, [r4, sp, ror #1] */
/* @0x316a76 svceq #0xf1b8 */
/* @0x316a7a .word 0xf04fd0d1 */
/* @0x316a7e stmvs r1!, {r8, r11} ^ */
/* @0x316a82 stmdbvs r6!, {r4, r6, r9, r10, lr} */
/* @0x316a86 ldrmi r1, [r0, #0xa76]! */
/* @0x316a8a .word 0x4646bf38 */
/* @0x316a8e ldrtmi r4, [r1], #1202 */
/* @0x316a92 .word 0xf59f4632 */
/* @0x316a96 stmvs r3!, {r1, r4, r7, r8, r10, r11, sp, lr, pc} ^ */
/* @0x316a9a stmdaeq r6, {r3, r4, r5, r7, r8, r9, r11, sp, lr, pc} */
/* @0x316a9e rscvs r4, r3, r3, lsr r4 */
/* @0x316aa2 ldrtmi r6, [r3], #-2107 */
/* @0x316aa6 andle r6, r4, r11, lsr r0 */
/* @0x316aaa .word 0xf7ff4628 */
/* @0x316aae stmdahs r0, {r3, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x316ab2 strbmi sp, [r8], -r5, ror #1 */
/* @0x316ab6 .word 0x87f0e8bd */
/* @0x316aba .word 0xf7ff68c0 */
/* @0x316abe push {r0, r2, r3, r4, r7, r8, r9, r10, r11, r12, sp, pc} */

/* ── FUNC 0x314e47 · FT_Bitmap_Embolden · size=838 · insn=0 */

/* ── FUNC 0x316ac0 · anon_316ac0 · size=900 · insn=225 */
/* @0x316ac0 ldrbmi lr, [r3, sp, lsr #18]! */
/* @0x316ac4 strmi r4, [r5], -lr, lsl #12 */
/* @0x316ac8 ldmdblt r1, {r8, r12, sp, pc} */
/* @0x316acc movwls r2, #0x328 */
/* @0x316ad0 .word 0x4608e0b4 */
/* @0x316ad4 ldrsbhi pc, [r12], -r1 */
/* @0x316ad8 stc2l p7, c15, [r10, #-1016]! */
/* @0x316adc andls r4, r0, r1, lsl #12 */
/* @0x316ae0 .word 0xf0402800 */
/* @0x316ae4 eorhs r8, r8, #171 */
/* @0x316ae8 .word 0xf59f4628 */
/* @0x316aec strbtmi lr, [r10], -r2, ror #26 */
/* @0x316af0 andshi pc, r12, r5, asr #17 */
/* @0x316af4 vmax.s8 q10, q1, q0 */
/* @0x316af8 .word 0xf7d00154 */
/* @0x316afc bls 0x355708 */
/* @0x316b00 bhs 0x328318 */
/* @0x316b04 subvs sp, r5, r6, lsr r1 */
/* @0x316b08 stmibvs r11!, {r1, r2, sp, lr} ^ */
/* @0x316b0c .word 0xf5006083 */
/* @0x316b10 .word 0xf1035301 */
/* @0x316b14 ldrtmi r0, [r0], -r8, lsl #2 */
/* @0x316b18 sbcsvs r6, r9, r9, lsl r1 */
/* @0x316b1c .word 0xf7fe609a */
/* @0x316b20 strmi pc, [r7], -r7, asr #26 */
/* @0x316b24 shsub8mi r11, r0, r0 */
/* @0x316b28 .word 0xff0af7cf */
/* @0x316b2c .word 0xf06f4b45 */
/* @0x316b30 ldrbtmi r0, [r11], #-270 */
/* @0x316b34 blmi 0x142f6c8 <b2_toiTime+0xcd6224> */
/* @0x316b38 .word 0x6323447b */
/* @0x316b3c strtmi r6, [r0], -r0, ror #8 */
/* @0x316b40 strdvs r6, r7, [r7, -r3]! */
/* @0x316b44 .word 0xf5046363 */
/* @0x316b48 movwlo r5, #0x8382 */
/* @0x316b4c svclo #0xcf840 */
/* @0x316b50 mcr2 p7, #0x3, pc, c12, c14, #0x7 */
/* @0x316b54 stmvs r7!, {r3, r5, r8, r11, r12, sp, pc} ^ */
/* @0x316b58 svclt #0xc2f00 */
/* @0x316b5c strhs r2, [r0, -r3, lsl #14] */
/* @0x316b60 strhs lr, [r3, -r0] */
/* @0x316b64 .word 0xb1279700 */
/* @0x316b68 strtmi r4, [r1], -r0, asr #12 */
/* @0x316b6c blx 0xffc14ab6 <b2_toiTime+0xffffffffff4bb612> */
/* @0x316b70 rscvs lr, r12, r4, rrx */
/* @0x316b74 shsub16mi r6, r0, r1 */
/* @0x316b78 .word 0xa008f8d6 */
/* @0x316b7c .word 0xf7cf3904 */
/* @0x316b80 stmdblt r8!, {r1, r4, r7, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x316b84 ldrtmi r10, [r0], -r1, lsl #18 */
/* @0x316b88 .word 0xf9aef7d0 */
/* @0x316b8c ldrbmi r9, [r1], -r1, lsl #30 */
/* @0x316b90 svclt #0xc2f00 */
/* @0x316b94 strhs r4, [r0, -r7, lsl #12] */
/* @0x316b98 .word 0xf7cf4630 */
/* @0x316b9c and pc, r0, r4, lsl #29 */
/* @0x316ba0 cdpne p7, #0x7, c2, c10, c0, #0x0 */
/* @0x316ba4 .word 0x73fef649 */
/* @0x316ba8 ldmdale r8!, {r1, r3, r4, r7, r9, lr} */
/* @0x316bac ldrtmi r4, [r9], -r0, asr #12 */
/* @0x316bb0 .word 0xf7d0466a */
/* @0x316bb4 .word 0x9e00fab8 */
/* @0x316bb8 cdphs p6, #0x0, c4, c0, c1, #0x4 */
/* @0x316bbc strtmi sp, [r0], -r12, lsr #2 */
/* @0x316bc0 .word 0x464a4631 */
/* @0x316bc4 .word 0xf7ff463b */
/* @0x316bc8 adcsmi pc, r8, #24, #30 */
/* @0x316bcc .word 0xf104d11a */
/* @0x316bd0 .word 0xf7fe000c */
/* @0x316bd4 rscvs pc, r6, #13120 */
/* @0x316bd8 strbmi r6, [r0], -r6, lsr #6 */
/* @0x316bdc strtmi r6, [r1], -r6, ror #6 */
/* @0x316be0 .word 0x61a660e6 */
/* @0x316be4 mvnvs r6, r6, lsr #2 */
/* @0x316be8 eorvs r6, r6, r6, lsr #1 */
/* @0x316bec .word 0xf7d06066 */
/* @0x316bf0 blmi 0x8d5a80 <b2_toiTime+0x17c5dc> */
/* @0x316bf4 rsbvs r6, pc, lr, ror #1 */
/* @0x316bf8 adcvs r4, lr, r11, ror r4 */
/* @0x316bfc andls pc, r0, r5, asr #17 */
/* @0x316c00 ands r6, r10, lr, ror #2 */
/* @0x316c04 qasxmi r4, r0, r1 */
/* @0x316c08 shasxmi r4, r3, r2 */
/* @0x316c0c mrc2 p7, #0x7, apsr_nzcv, c5, c15, #0x7 */
/* @0x316c10 strbmi r4, [r9], -r0, asr #12 */
/* @0x316c14 blx 0xfe714b5e <b2_toiTime+0xfffffffffdfbb6ba> */
/* @0x316c18 movwls r2, #0x300 */
/* @0x316c1c mrslt lr, apsr */
/* @0x316c20 and r6, r2, pc, rrx */
/* @0x316c24 movwmi pc, #0x6f */
/* @0x316c28 movwhs r6, #0x6b */
/* @0x316c2c eorvs r6, r11, r11, lsr #1 */
/* @0x316c30 ldrbtmi r4, [r11], #-2823 */
/* @0x316c34 blmi 0x4ef1e8 <SrcVerts+0x4c22c> */
/* @0x316c38 .word 0x61ab447b */
/* @0x316c3c andlt r9, r2, r0, lsl #16 */
/* @0x316c40 .word 0x87f0e8bd */
/* @0x316c44 .word 0xffffea67 */
/* @0x316c48 .word 0xffffea59 */
/* @0x316c4c .word 0xffffebbd */
/* @0x316c50 .word 0xfffffe85 */
/* @0x316c54 .word 0xffffeb7d */
/* @0x316c58 ssub16mi r11, r6, r0 */
/* @0x316c5c stmdblt r8, {r1, r2, r3, r7, r12, sp, pc} */
/* @0x316c60 eors r2, r4, r6 */
/* @0x316c64 rscsle r2, r11, r0, lsl #20 */
/* @0x316c68 rscsle r2, r9, r0, lsl #18 */
/* @0x316c6c blls 0x7bb874 <b2_toiTime+0x623d0> */
/* @0x316c70 mrshs r9, apsr */
/* @0x316c74 strbtmi r9, [r8], -r10 */
/* @0x316c78 ldmdavs r3, {r0, r8, r9, r12, pc} */
/* @0x316c7c blmi 0x87b894 <b2_toiTime+0x1223f0> */
/* @0x316c80 movwls r4, #0x847b */
/* @0x316c84 ldrbtmi r4, [r11], #-2836 */
/* @0x316c88 .word 0xf7fe9309 */
/* @0x316c8c stmdahs r0, {r0, r1, r2, r3, r6, r7, r8, r10, r11, r12, sp, lr, pc} */
/* @0x316c90 strbtmi sp, [r8], -r6, ror #3 */
/* @0x316c94 .word 0xf7fe2104 */
/* @0x316c98 stmdahs r1, {r0, r4, r6, r9, r10, r11, r12, sp, lr, pc} */
/* @0x316c9c andle r4, r5, r4, lsl #12 */
/* @0x316ca0 .word 0xf7fe4668 */
/* @0x316ca4 ldmdblt r12!, {r0, r2, r5, r6, r8, r10, r11, r12, sp, lr, pc} */
/* @0x316ca8 ands r2, r0, r10 */
/* @0x316cac strbtmi r9, [r8], -r5, lsl #22 */
/* @0x316cb0 .word 0xf7fe6033 */
/* @0x316cb4 .word 0x4604fd5d */
/* @0x316cb8 andle r1, r7, r2, lsr #26 */
/* @0x316cbc rscsle r1, r3, r3, ror #26 */
/* @0x316cc0 svceq #0x3f114 */
/* @0x316cc4 andhs r11, r8, r12, lsl #30 */
/* @0x316cc8 and r2, r0, r0 */
/* @0x316ccc andlt r2, lr, r0, asr #32 */
/* @0x316cd0 svclt #0xbd70 */
/* @0x316cd4 .word 0xffffe919 */
/* @0x316cd8 .word 0xffffe90b */
/* @0x316cdc .word 0x4604b570 */
/* @0x316ce0 mlahs r0, r0, r8, pc */
/* @0x316ce4 stmibvs r3, {r0, r2, r6, r8, r9, r11, sp, lr} */
/* @0x316ce8 blvs 0xfe331c74 <b2_toiTime+0xfffffffffdbd87d0> */
/* @0x316cec stmibvs r6!, {r1, r5, r8, r11, r12, sp, pc} ^ */
/* @0x316cf0 andle r4, r1, #805306379 */
/* @0x316cf4 teqle r8, #136, #4 */
/* @0x316cf8 movwle r4, #0xe288 */
/* @0x316cfc .word 0x63653501 */
/* @0x316d00 ldmdale r8, {r4, r8, r10, r11, sp} ^ */
/* @0x316d04 addsmi r6, sp, #667648 */
/* @0x316d08 movwhs sp, #0x1204 */
/* @0x316d0c .word 0xf5a340ab */
/* @0x316d10 and r7, r1, r0, lsl #7 */
/* @0x316d14 movwlo r6, #0x1b23 */
/* @0x316d18 teqlt r10, r3, ror #7 */
/* @0x316d1c orrvc pc, r0, #1325400064 */
/* @0x316d20 .word 0x63e32509 */
/* @0x316d24 .word 0x63652300 */
/* @0x316d28 eorlo pc, r0, r4, lsl #17 */
/* @0x316d2c cdphs p8, #0x0, c6, c0, c6, #0x3 */
/* @0x316d30 blvs 0x1bcb23c <b2_toiTime+0x1471d98> */
/* @0x316d34 .word 0x0108f104 */
/* @0x316d38 .word 0x00a4f8d4 */
/* @0x316d3c cdp2 p7, #0x3, c15, c0, c15, #0x6 */
/* @0x316d40 bvs 0x1bf1ad0 <b2_toiTime+0x149862c> */
/* @0x316d44 addsmi r6, r0, #-2147483607 */
/* @0x316d48 rsbvs r4, r3, #50331648 */
/* @0x316d4c movwhs r11, #0xf2c */
/* @0x316d50 rsbvs r2, r3, r1, lsl #6 */
/* @0x316d54 addsmi r0, r3, #195 */
/* @0x316d58 strexhvs r11, r8, [r3] */
/* @0x316d5c .word 0xf1c2d92b */
/* @0x316d60 ldrmi r0, [r3], #-513 */
/* @0x316d64 teqlt r0, #-1073741768 */
/* @0x316d68 ldmdbne r10, {r0, r1, r4, r5, r9, r10, lr} ^ */
/* @0x316d6c ldmeq r10, {r1, r5, r7, r8, sp, lr} ^ */
/* @0x316d70 movweq pc, #0x7003 */
/* @0x316d74 .word 0x0108f102 */
/* @0x316d78 ldrmi r4, [r4], #-1057 */
/* @0x316d7c andeq pc, r8, #-1073741776 */
/* @0x316d80 bne 0xfee75608 <b2_toiTime+0xfffffffffe71c164> */
/* @0x316d84 blx 0x13221a8 <b2_toiTime+0xbc8d04> */
/* @0x316d88 stmdale r1, {r0, r1, r12, sp, lr, pc} */
/* @0x316d8c and r1, r7, r12, asr #24 */
/* @0x316d90 stmdavc r9, {r2, r3, r7, r10, r11, r12} ^ */
/* @0x316d94 blx 0x3661bc <_ZTS12CDS_Priority+0x8214> */
/* @0x316d98 tstmi r0, #536870912 */
/* @0x316d9c andseq pc, r0, #-1073741776 */
/* @0x316da0 movwhs r11, #0x115d */
/* @0x316da4 .word 0xf505fa03 */
/* @0x316da8 stclo p8, c7, [r1, #-140] */
/* @0x316dac blx 0x466e28 <g_RomDisk+0x6f608> */
/* @0x316db0 tstmi r0, #536870912 */
/* @0x316db4 .word 0xf04fbd70 */
/* @0x316db8 ldcllt p0, c3, [r0, #-1020]! */
/* @0x316dbc .word 0x4604b530 */
/* @0x316dc0 addlt r6, r5, r2, lsl #28 */
/* @0x316dc4 addsmi r6, r3, #12480 */
/* @0x316dc8 stcvs p3, c13, [r3, #140]! */
/* @0x316dcc .word 0x0164f104 */
/* @0x316dd0 .word 0xf8d01d15 */
/* @0x316dd4 addmi r0, r11, #168 */
/* @0x316dd8 ldrbeq lr, [r2, #-0xb05] */
/* @0x316ddc andhs r11, r0, #4, #30 */
/* @0x316de0 .word 0xf5b565a2 */
/* @0x316de4 stmdble r4, {r7, r8, r9, r10, r11, r12, sp} */
/* @0x316de8 svclo #0x80f5b2 */
/* @0x316dec vst4.8 {d29, d30, d31, d0}, [pc], lr */
/* @0x316df0 stcvs p5, c3, [r3, #512]! */
/* @0x316df4 movwls r2, #0x101 */
/* @0x316df8 movwls r10, #0x1b03 */
/* @0x316dfc .word 0xf7d1462b */
/* @0x316e00 strvs pc, [r0, #0x946]! */
/* @0x316e04 stmdblt r8, {r0, r1, r11, r12, pc} */
/* @0x316e08 and r6, r3, r5, lsr #12 */
/* @0x316e0c rscslo pc, pc, pc, asr #32 */
/* @0x316e10 andhs lr, r0, r0 */
/* @0x316e14 ldclt p0, c11, [r0, #-20]! */
/* @0x316e18 andhs r11, r2, #29360128 */
/* @0x316e1c .word 0xf7cfa901 */
/* @0x316e20 ldmdblt r8, {r1, r2, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc} ^ */
/* @0x316e24 mullo r4, sp, r8 */
/* @0x316e28 .word 0xd1062b1f */
/* @0x316e2c muleq r5, sp, r8 */
/* @0x316e30 svclt #0x14289d */
/* @0x316e34 andhs r2, r0, r3 */
/* @0x316e38 andhs lr, r3, r0 */
/* @0x316e3c .word 0xf85db003 */
/* @0x316e40 movwhs pc, #0xb04 */

/* ── FUNC 0x316ac1 · FT_Stream_OpenGzip · size=408 · insn=0 */

/* ── FUNC 0x316c59 · FT_Gzip_Uncompress · size=132 · insn=0 */

/* ── FUNC 0x316e42 · anon_316e42 · size=80 · insn=20 */
/* @0x316e42 andhs r2, r9, #0, #6 */
/* @0x316e46 orrvs r6, r3, r3, asr #32 */
/* @0x316e4a .word 0xf88061c3 */
/* @0x316e4e subvs r3, r3, #32 */
/* @0x316e52 movtvs r6, #0x25c3 */
/* @0x316e56 ldrbmi r6, [r0, -r3]! */
/* @0x316e5a adchs r11, r12, #56, #10 */
/* @0x316e5e strmi r4, [sp], -r4, lsl #12 */
/* @0x316e62 .word 0xf59f2100 */
/* @0x316e66 .word 0xf8c4eba4 */
/* @0x316e6a stmibvs r11!, {r2, r5, r7, r12, lr} ^ */
/* @0x316e6e .word 0xf8c44620 */
/* @0x316e72 movwhs r3, #0xa8 */
/* @0x316e76 strvs r6, [r3, #-0x4e3]! */
/* @0x316e7a .word 0xf1046563 */
/* @0x316e7e strvs r0, [r3, #0x364]! */
/* @0x316e82 strtvs r2, [r3], -r0, asr #6 */
/* @0x316e86 ldrhtmi lr, [r8], -sp */
/* @0x316e8a svclt #0xdaf7ff */
/* @0x316e8e .word 0xe92d0000 */

/* ── FUNC 0x316e43 · ft_lzwstate_reset · size=24 · insn=0 */

/* ── FUNC 0x316e5b · ft_lzwstate_init · size=52 · insn=0 */

/* ── FUNC 0x316e90 · anon_316e90 · size=7608 · insn=1902 */
/* @0x316e90 mvnsmi lr, sp, lsr #18 */
/* @0x316e94 strmi r4, [r4], -sp, lsl #12 */
/* @0x316e98 ldmdblt r1, {r8, r12, sp, pc} */
/* @0x316e9c movwls r2, #0x1328 */
/* @0x316ea0 .word 0xf8d1e04f */
/* @0x316ea4 .word 0x4608801c */
/* @0x316ea8 .word 0xf7cf2100 */
/* @0x316eac .word 0x4607fcfc */
/* @0x316eb0 qadd16mi r11, r8, r8 */
/* @0x316eb4 .word 0xffb0f7ff */
/* @0x316eb8 strls r4, [r1, -r7, lsl #12] */
/* @0x316ebc .word 0xd1402f00 */
/* @0x316ec0 eorhs r4, r8, #59768832 */
/* @0x316ec4 .word 0xf59f4620 */
/* @0x316ec8 .word 0xf8c4eb74 */
/* @0x316ecc .word 0x4640801c */
/* @0x316ed0 biceq pc, r4, r1, asr #4 */
/* @0x316ed4 .word 0xf7d0aa01 */
/* @0x316ed8 blls 0x395378 <ft_adobe_glyph_list+0x4a54> */
/* @0x316edc bllt 0xbe86fc <b2_toiTime+0x48f258> */
/* @0x316ee0 .word 0xf5006044 */
/* @0x316ee4 andvs r5, r5, r6, lsl #3 */
/* @0x316ee8 addvs r6, r3, r3, ror #19 */
/* @0x316eec orrpl pc, r5, #0, #10 */
/* @0x316ef0 andseq pc, r8, #-1073741824 */
/* @0x316ef4 andvs r4, r10, r8, lsr #12 */
/* @0x316ef8 orrsvs r4, pc, r9, lsr r6 */
/* @0x316efc .word 0xf7cf61da */
/* @0x316f00 .word 0x4607fcd2 */
/* @0x316f04 strtmi r11, [r8], -r8, asr #18 */
/* @0x316f08 .word 0xff86f7ff */
/* @0x316f0c stmdblt r0!, {r0, r1, r2, r9, r10, lr} */
/* @0x316f10 andeq pc, r12, r6, lsl #2 */
/* @0x316f14 .word 0xf7ff4629 */
/* @0x316f18 strls pc, [r1, -r0, lsr #31] */
/* @0x316f1c strbmi r11, [r0], -r7, lsr #2 */
/* @0x316f20 .word 0xf7d04631 */
/* @0x316f24 and pc, r12, r8, lsl #20 */
/* @0x316f28 .word 0xf06f60e6 */
/* @0x316f2c rsbvs r4, r3, r0, lsl #6 */
/* @0x316f30 adcvs r2, r3, r0, lsl #6 */
/* @0x316f34 blmi 0x46efc8 <g_RomDisk+0x777a8> */
/* @0x316f38 .word 0x6163447b */
/* @0x316f3c ldrbtmi r4, [r11], #-2820 */
/* @0x316f40 stmdals r1, {r0, r1, r5, r7, r8, sp, lr} */
/* @0x316f44 pop {r1, r12, sp, pc} */
/* @0x316f48 svclt #0x81f0 */
/* @0x316f4c ldrdeq r0, r1, [r0], -r3 */
/* @0x316f50 andeq r0, r0, sp, asr #32 */
/* @0x316f54 .word 0x4604b538 */
/* @0x316f58 .word 0x50a8f8d0 */
/* @0x316f5c .word 0xff71f7ff */
/* @0x316f60 .word 0xf1046da1 */
/* @0x316f64 addsmi r0, r9, #100, #6 */
/* @0x316f68 strtmi sp, [r8], -r4 */
/* @0x316f6c .word 0xf9e3f7d0 */
/* @0x316f70 strvs r2, [r3, #0x300]! */
/* @0x316f74 stclvs p6, c4, [r1], #160 */
/* @0x316f78 .word 0xf9ddf7d0 */
/* @0x316f7c strtmi r2, [r0], -r0, lsl #2 */
/* @0x316f80 strvs r6, [r1, #-0x4e1]! */
/* @0x316f84 pop {r2, r3, r5, r7, r9, sp} */
/* @0x316f88 .word 0xf0044038 */
/* @0x316f8c ldrblt r11, [r8, #0xd9f]! */
/* @0x316f90 stmvs r4, {r1, r2, r9, r10, lr} ^ */
/* @0x316f94 smulbtlt r4, r7, r9 */
/* @0x316f98 andeq pc, r12, r4, lsl #2 */
/* @0x316f9c .word 0xf7ff2500 */
/* @0x316fa0 .word 0x60a5ffd9 */
/* @0x316fa4 ldrtmi r6, [r8], -r5, lsr #32 */
/* @0x316fa8 strtmi r6, [r1], -r5, rrx */
/* @0x316fac .word 0xf9c3f7d0 */
/* @0x316fb0 ldcllt p0, c6, [r8, #980]! */
/* @0x316fb4 svcmi #0xf0e92d */
/* @0x316fb8 addlt r4, r7, r4, lsl #12 */
/* @0x316fbc mcrrvs p6, #0x8, r4, r6, c11 */
/* @0x316fc0 .word 0x6c074692 */
/* @0x316fc4 .word 0x8048f8d0 */
/* @0x316fc8 .word 0xf0002a00 */
/* @0x316fcc stmdavs r3, {r0, r4, r8, pc} */
/* @0x316fd0 .word 0xf0002b01 */
/* @0x316fd4 movwle r8, #0x40c6 */
/* @0x316fd8 .word 0xf0402b02 */
/* @0x316fdc strhs r8, [r0, #-0x10b] */
/* @0x316fe0 .word 0xf8d0e06f */
/* @0x316fe4 smlatbhs r2, r4, r0, r0 */
/* @0x316fe8 mrrc2 p7, #0xc, pc, sp, c15 */
/* @0x316fec teqle r12, r0, lsl #16 */
/* @0x316ff0 .word 0x00a4f8d4 */
/* @0x316ff4 andhs r10, r1, #81920 */
/* @0x316ff8 ldc2l p7, c15, [r2], {207} */
/* @0x316ffc teqle r4, r1, lsl #16 */
/* @0x317000 mulshs r4, sp, r8 */
/* @0x317004 tsteq pc, #2 */
/* @0x317008 rsbseq pc, pc, #34 */
/* @0x31700c blx 0x321c54 */
/* @0x317010 sbcslt pc, r2, #3 */
/* @0x317014 orrvc pc, r0, r0, lsr #11 */
/* @0x317018 rscvs r6, r2, #805306378 */
/* @0x31701c stmdale r4!, {r0, r5, r8, r9, sp, lr} */
/* @0x317020 .word 0xf04f3200 */
/* @0x317024 .word 0x63610109 */
/* @0x317028 andhs r11, r1, #24, #30 */
/* @0x31702c svclt #0x98428b */
/* @0x317030 .word 0x63a238ff */
/* @0x317034 .word 0xf44fbf88 */
/* @0x317038 mvnvs r7, #128 */
/* @0x31703c .word 0xf7ff4620 */
/* @0x317040 ldmhs pc!, {r0, r2, r3, r6, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x317044 .word 0xf1bbd80f */
/* @0x317048 andle r0, r1, r0, lsl #30 */
/* @0x31704c andeq pc, r0, r11, lsl #17 */
/* @0x317050 svceq #0x1f1ba */
/* @0x317054 streq pc, [r1, #-0x4f] */
/* @0x317058 eorvs sp, r5, r9, lsl #18 */
/* @0x31705c strmi r4, [r6], -r7, lsl #12 */
/* @0x317060 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x317064 .word 0xf04fe07f */
/* @0x317068 strhs r0, [r0, #-0x800] */
/* @0x31706c strmi lr, [r7], -r5, asr #1 */
/* @0x317070 .word 0xf04f4606 */
/* @0x317074 sbc r0, r2, r0, lsl #16 */
/* @0x317078 blhs 0x331c0c */
/* @0x31707c .word 0x2600d075 */
/* @0x317080 ldrtmi r2, [r7], -r1, lsl #6 */
/* @0x317084 .word 0xf88463a2 */
/* @0x317088 strtmi r3, [r0], -r0, lsr #32 */
/* @0x31708c .word 0xf7ff9203 */
/* @0x317090 bls 0x41692c <g_RomDisk+0x1f10c> */
/* @0x317094 vmlal.s8 q9, d0, d0 */
/* @0x317098 .word 0xf5b080af */
/* @0x31709c strmi r7, [r0], r0, lsl #31 */
/* @0x3170a0 ldmhs pc!, {r1, r3, r5, r6, r7, r12, lr, pc} ^ */
/* @0x3170a4 .word 0x4606bf98 */
/* @0x3170a8 stclvs p8, c13, [r2, #380]! */
/* @0x3170ac addsmi r6, r10, #560 */
/* @0x3170b0 addshi pc, r7, r0, lsl #1 */
/* @0x3170b4 stcvs p13, c6, [r2, #908]! */
/* @0x3170b8 strbvs r1, [r1, #0xc59]! */
/* @0x3170bc movwhs r5, #0x24d6 */
/* @0x3170c0 stclvs p0, c6, [r3, #140]! */
/* @0x3170c4 bllo 0x383658 <_ZTS13C_UTF16String+0x1a704> */
/* @0x3170c8 .word 0xf1bb65e3 */
/* @0x3170cc andle r0, r3, r0, lsl #30 */
/* @0x3170d0 ldclpl p13, c6, [r3], {162} */
/* @0x3170d4 andlo pc, r5, r11, lsl #16 */
/* @0x3170d8 ldrbmi r3, [r5, #-0x501] */
/* @0x3170dc strd sp, lr, [lr], r1 */
/* @0x3170e0 blvs 0xbb1f74 <b2_toiTime+0x458ad0> */
/* @0x3170e4 eorsle r4, r7, #805306377 */
/* @0x3170e8 ldrsbls pc, [r4], #-132 */
/* @0x3170ec andle r4, r10, #314572800 */
/* @0x3170f0 vstmiavs r3!, {d22, d23, d24, d25, d26, d27, d28, d29, d30, d31} */
/* @0x3170f4 andsvc pc, r2, r3, lsr #16 */
/* @0x3170f8 fstmdbxvs r2!, {d6, d7, d8, d9, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28, d29, d30, d31} */
/* @0x3170fc blvs 0xfebec45c <b2_toiTime+0xfffffffffe492fb8> */
/* @0x317100 .word 0x63a33301 */
/* @0x317104 .word 0xf8d4e028 */
/* @0x317108 .word 0xf1b900a8 */
/* @0x31710c andle r0, r2, r0, lsl #30 */
/* @0x317110 fldmiaxeq r9, {d14, d15, d16, d17} */
/* @0x317114 vst4.8 {d30, d31, d0, d1}, [pc], r1 */
/* @0x317118 stclvs p12, c7, [r3], #0 */
/* @0x31711c strbmi r2, [r10], -r3, lsl #2 */
/* @0x317120 andgt pc, r12, sp, asr #17 */
/* @0x317124 blge 0x47bd2c <targetStr+0xaec> */
/* @0x317128 strbtmi r9, [r3], -r1, lsl #6 */
/* @0x31712c .word 0xffaff7d0 */
/* @0x317130 .word 0xf8dd9b05 */
/* @0x317134 strmi r12, [r1], -r12 */
/* @0x317138 blhs 0x3304c0 */
/* @0x31713c bl 0x34b6b8 */
/* @0x317140 bl 0x357278 */
/* @0x317144 strvs r0, [r0, #-0x149]! */
/* @0x317148 .word 0xf59f464a */
/* @0x31714c .word 0xf8ddeaa4 */
/* @0x317150 .word 0xf8c4c00c */
/* @0x317154 .word 0xe7cbc054 */
/* @0x317158 strbmi r2, [r1], r1, lsl #6 */
/* @0x31715c strbmi r6, [r7], -r3, lsr #32 */
/* @0x317160 strbmi lr, [r1], r1 */
/* @0x317164 andhs r2, r0, #0, #10 */
/* @0x317168 blvs 0xfec10fac <b2_toiTime+0xfffffffffe4b7b08> */
/* @0x31716c addvc pc, r0, #160, #10 */
/* @0x317170 tstle r1, #-1610612727 */
/* @0x317174 stclvs p8, c13, [r2, #260]! */
/* @0x317178 addsmi r6, r10, #560 */
/* @0x31717c stclvs p2, c13, [r3, #24]! */
/* @0x317180 stcvs p6, c4, [r2, #740]! */
/* @0x317184 strbvs r1, [r1, #0xc59]! */
/* @0x317188 ldrsb r5, [lr], -r6 */
/* @0x31718c .word 0xf7ff4620 */
/* @0x317190 stmdahs r0, {r0, r2, r4, r9, r10, r11, r12, sp, lr, pc} */
/* @0x317194 ldrsht sp, [r0], -r3 */
/* @0x317198 ands r4, r6, r1, lsl #13 */
/* @0x31719c .word 0xb3636ce3 */
/* @0x3171a0 cdpvs p13, #0x2, c6, c3, c2, #0x7 */
/* @0x3171a4 andsle r4, r4, #-1610612727 */
/* @0x3171a8 stcvs p13, c6, [r2, #908]! */
/* @0x3171ac strbvs r1, [r1, #0xc59]! */
/* @0x3171b0 strbmi r6, [r9], #-3361 */
/* @0x3171b4 stmdbmi r0, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x3171b8 orrvc pc, r0, r1, lsr #11 */
/* @0x3171bc stmibvc r0, {r0, r3, r5, r7, r8, r10, r12, sp, lr, pc} */
/* @0x3171c0 ldrbpl r7, [r1], #2057 */
/* @0x3171c4 rfeda r3! */
/* @0x3171c8 .word 0xf1b99019 */
/* @0x3171cc stmle r5!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11} ^ */
/* @0x3171d0 strtmi lr, [r0], -r5 */
/* @0x3171d4 ldc2l p7, c15, [r2, #1020]! */
/* @0x3171d8 ble 0xffc611e0 <b2_toiTime+0xffffffffff507d3c> */
/* @0x3171dc strbmi lr, [lr], -sp */
/* @0x3171e0 strtmi lr, [r0], -r3, ror #14 */
/* @0x3171e4 stc2l p7, c15, [r10, #1020]! */
/* @0x3171e8 .word 0xf6bf2800 */
/* @0x3171ec and r10, r4, r3, ror #30 */
/* @0x3171f0 and r4, r4, r5, lsl r6 */
/* @0x3171f4 and r2, r2, r0, lsl #10 */
/* @0x3171f8 movwhs r4, #0x36c8 */
/* @0x3171fc strtmi r6, [r8], -r3, lsr #32 */
/* @0x317200 strbtvs r6, [r6], #-1063 */
/* @0x317204 subhi pc, r8, r4, asr #17 */
/* @0x317208 pop {r0, r1, r2, r12, sp, pc} */
/* @0x31720c push {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x317210 .word 0x46984ff7 */
/* @0x317214 strmi r6, [pc], -r5, asr #17 */
/* @0x317218 .word 0xf5059201 */
/* @0x31721c .word 0xf1045485 */
/* @0x317220 stmibvs r3!, {r3, r4, r9, r10} */
/* @0x317224 andsle r4, lr, #-1879048183 */
/* @0x317228 bne 0x19319b8 <b2_toiTime+0x11d8514> */
/* @0x31722c .word 0x01b8f105 */
/* @0x317230 addmi r1, r8, #331776 */
/* @0x317234 bne 0x20d24c <_ZN8CDS_Grid7ShuffleEv+0x4b4> */
/* @0x317238 ldrmi r6, [r10], #-423 */
/* @0x31723c ands r6, r2, r2, ror #3 */
/* @0x317240 .word 0x21006828 */
/* @0x317244 blx 0xf1518a <b2_toiTime+0x7bbce6> */
/* @0x317248 tstlt r0, r1, lsl #13 */
/* @0x31724c beq 0x353390 */
/* @0x317250 .word 0xf105e060 */
/* @0x317254 .word 0xf7ff000c */
/* @0x317258 .word 0xf505fdf4 */
/* @0x31725c andsvs r5, lr, r6, lsl #7 */
/* @0x317260 .word 0xf8c461e6 */
/* @0x317264 stmibvs r2!, {r3, r4, r12, pc} */
/* @0x317268 stmdale r10, {r0, r1, r2, r4, r7, r9, lr} */
/* @0x31726c svceq #0xf1b8 */
/* @0x317270 .word 0xf505d0ec */
/* @0x317274 .word 0xf1055b86 */
/* @0x317278 .word 0xf04f09b8 */
/* @0x31727c strlo r0, [r12, #-0xa00] */
/* @0x317280 .word 0xf505e032 */
/* @0x317284 stmibvs r1!, {r1, r2, r7, r8, r9, r12, lr} ^ */
/* @0x317288 .word 0xf1051abf */
/* @0x31728c ldmdavs r11, {r2, r3, r9, r11} */
/* @0x317290 blvc 0x314b98 <FT_Bitmap_Convert+0xc8> */
/* @0x317294 addsmi r1, pc, #372736 */
/* @0x317298 shasxmi r11, r11, r8 */
/* @0x31729c ldrmi r1, [r9], #-2815 */
/* @0x3172a0 mvnvs r4, r10, lsl r4 */
/* @0x3172a4 svchs #0x61a2 */
/* @0x3172a8 ldrbmi sp, [pc, #-0xe0] */
/* @0x3172ac ssatmi r11, #0x1a, r4, lsl #31 */
/* @0x3172b0 stmibpl r0, {r0, r1, r2, r3, r6, r10, r12, sp, lr, pc} */
/* @0x3172b4 qaddhs r4, r0, r0 */
/* @0x3172b8 .word 0xf7ff464a */
/* @0x3172bc strbmi pc, [r8, #-0xe7b] */
/* @0x3172c0 ldmdavs r3!, {r2, r6, r7, r8, r9, r12, lr, pc} */
/* @0x3172c4 streq lr, [r7, -r9, asr #23] */
/* @0x3172c8 eorsvs r4, r3, r11, asr #8 */
/* @0x3172cc .word 0xf44fe7eb */
/* @0x3172d0 .word 0xf8c45280 */
/* @0x3172d4 qadd16mi r9, r8, r12 */
/* @0x3172d8 .word 0xf7ff4649 */
/* @0x3172dc stmibvs r2!, {r0, r1, r3, r5, r6, r9, r10, r11, r12, sp, lr, pc} ^ */
/* @0x3172e0 .word 0xf8cb4402 */
/* @0x3172e4 movlt r2, r0 */
/* @0x3172e8 .word 0xf8db69e1 */
/* @0x3172ec stmdals r1, {r12, sp, lr} */
/* @0x3172f0 ldrmi r1, [r8, #0xa7f]! */
/* @0x3172f4 .word 0x4647bf38 */
/* @0x3172f8 ldrtmi r4, [r10], #1104 */
/* @0x3172fc .word 0xf59f463a */
/* @0x317300 stmibvs r2!, {r1, r2, r3, r4, r6, r8, r11, sp, lr, pc} ^ */
/* @0x317304 stmdaeq r7, {r3, r4, r5, r7, r8, r9, r11, sp, lr, pc} */
/* @0x317308 mvnvs r4, r10, lsr r4 */
/* @0x31730c ldrtmi r6, [r10], #-2098 */
/* @0x317310 bicsle r6, r12, r2, lsr r0 */
/* @0x317314 andlt r4, r3, r0, asr r6 */
/* @0x317318 svchi #0xf0e8bd */
/* @0x31731c ldrbmi r2, [r0, -r0]! */
/* @0x317320 ldrlt r4, [r0, #-0xb04] */
/* @0x317324 .word 0x4604447b */
/* @0x317328 andvs r3, r3, r8, lsl #6 */
/* @0x31732c rfeia r2! */
/* @0x317330 ldclt p6, c4, [r0, #-128] */
/* @0x317334 andeq r5, sp, r8, lsr sp */
/* @0x317338 .word 0x4604b510 */
/* @0x31733c .word 0xfff0f7ff */
/* @0x317340 .word 0xf7654620 */
/* @0x317344 strtmi lr, [r0], -r6, asr #30 */
/* @0x317348 svclt #0xbd10 */
/* @0x31734c .word 0x460cb570 */
/* @0x317350 sadd16mi r4, lr, r5 */
/* @0x317354 .word 0xf808f001 */
/* @0x317358 movwhs r11, #0x1130 */
/* @0x31735c stmdavs r10!, {r2, r4, r5, r6, sp, lr} */
/* @0x317360 eorsvs r4, r3, r8, lsl r6 */
/* @0x317364 adcsvs r7, r2, r3, lsr r4 */
/* @0x317368 svclt #0xbd70 */
/* @0x31736c svclt #0xeef7ff */
/* @0x317370 andhs r11, r1, #56, #10 */
/* @0x317374 strmi r2, [r4], -r0, lsl #6 */
/* @0x317378 subvs r6, r3, r3 */
/* @0x31737c sbcvs r6, r3, r3, lsl #1 */
/* @0x317380 cmplt r9, r2, lsl #8 */
/* @0x317384 strmi r4, [r8], -r6, lsl #26 */
/* @0x317388 ldrbtmi r4, [sp], #-2566 */
/* @0x31738c ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x317390 .word 0xf0004629 */
/* @0x317394 qaddlt pc, r7, r8 */
/* @0x317398 rscvs r6, r3, r3, lsl #17 */
/* @0x31739c ldclt p6, c4, [r8, #-128]! */
/* @0x3173a0 strdeq r5, r6, [sp], -r2 */
/* @0x3173a4 andeq r10, sp, r4, ror r8 */
/* @0x3173a8 mvnsmi lr, sp, lsr #18 */
/* @0x3173ac strmi r11, [r4], -r6, lsl #1 */
/* @0x3173b0 ldrmi r4, [r6], -pc, lsl #12 */
/* @0x3173b4 .word 0xffd8f000 */
/* @0x3173b8 andhs r4, r1, r5, lsl #12 */
/* @0x3173bc ldrtmi r11, [r8], -r5, lsl #22 */
/* @0x3173c0 ldmdbmi r1, {r0, r1, r2, r4, r5, r6, r7, r8, r12, sp, pc} */
/* @0x3173c4 bmi 0x768cac <b2_toiTime+0xf808> */
/* @0x3173c8 ldrbtmi r4, [r9], #-1579 */
/* @0x3173cc ldrbtmi r6, [r10], #-2057 */
/* @0x3173d0 blx 0x11533da <b2_toiTime+0x9f9f36> */
/* @0x3173d4 .word 0xf1b84680 */
/* @0x3173d8 andsle r0, r1, r0, lsl #30 */
/* @0x3173dc stmdage r1, {r0, r5, r9, r10, lr} */
/* @0x3173e0 .word 0xffc6f7ff */
/* @0x3173e4 .word 0x7000f8d8 */
/* @0x3173e8 strtmi r10, [r1], -r1, lsl #22 */
/* @0x3173ec ldrtmi r4, [r2], -r0, asr #12 */
/* @0x3173f0 .word 0x47a0693c */
/* @0x3173f4 stmdahs r1, {r0, r11, r12, pc} */
/* @0x3173f8 blls 0x407028 <g_RomDisk+0xf808> */
/* @0x3173fc eorsvs r4, r3, r8, lsr #12 */
/* @0x317400 pop {r1, r2, r12, sp, pc} */
/* @0x317404 svclt #0x81f0 */
/* @0x317408 andeq r10, sp, r10, lsr r8 */
/* @0x31740c andeq r5, sp, lr, lsr #25 */
/* @0x317410 .word 0x4605b570 */
/* @0x317414 .word 0x4c08b170 */
/* @0x317418 .word 0xf104447c */
/* @0x31741c ldrtmi r0, [r0], -r12, lsl #12 */
/* @0x317420 mrrc p5, #0x9, pc, r0, c15 */
/* @0x317424 ldrtmi r6, [r0], -r3, ror #18 */
/* @0x317428 .word 0x6165602b */
/* @0x31742c ldrhtmi lr, [r0], #-141 */
/* @0x317430 bllt 0xfe853448 <b2_toiTime+0xfffffffffe0f9fa4> */
/* @0x317434 svclt #0xbd70 */
/* @0x317438 umaaleq r2, r4, r0, r0 */
/* @0x31743c .word 0x4605b538 */
/* @0x317440 ldrbtmi r4, [r12], #-3089 */
/* @0x317444 andeq pc, r12, r4, lsl #2 */
/* @0x317448 ldc p5, c15, [r12], #-636 */
/* @0x31744c cmplt r3, r3, lsr #18 */
/* @0x317450 ldrmi r6, [r8], -r2, lsr #17 */
/* @0x317454 orrpl pc, r0, pc, asr #8 */
/* @0x317458 .word 0x6123589b */
/* @0x31745c ldc p5, c15, [r4, #636] */
/* @0x317460 blhs 0x3318f4 */
/* @0x317464 .word 0x4c09d1f4 */
/* @0x317468 strlo r4, [r12], #-1148 */
/* @0x31746c .word 0xf59f4620 */
/* @0x317470 qasxmi lr, r0, r0 */
/* @0x317474 .word 0xec0ef59f */
/* @0x317478 ldrbtmi r4, [r8], #-2053 */
/* @0x31747c .word 0xf59f6800 */
/* @0x317480 strtmi lr, [r8], -r10, lsl #27 */
/* @0x317484 svclt #0xbd38 */
/* @0x317488 subeq r2, r4, r6, rrx */
/* @0x31748c subeq r2, r4, r0, asr #32 */
/* @0x317490 subeq r2, r4, r6, asr #32 */
/* @0x317494 ldrlt r4, [r0, #-0xb04] */
/* @0x317498 .word 0x4604447b */
/* @0x31749c andvs r3, r3, r8, lsl #6 */
/* @0x3174a0 .word 0xff16f000 */
/* @0x3174a4 ldclt p6, c4, [r0, #-128] */
/* @0x3174a8 strdeq r5, r6, [sp], -r4 */
/* @0x3174ac .word 0x4604b510 */
/* @0x3174b0 .word 0xfff0f7ff */
/* @0x3174b4 .word 0xf7654620 */
/* @0x3174b8 strtmi lr, [r0], -r12, lsl #29 */
/* @0x3174bc svclt #0xbd10 */
/* @0x3174c0 strlt r4, [r8, #-0x802] */
/* @0x3174c4 .word 0xf0004478 */
/* @0x3174c8 svclt #0xfb09 */
/* @0x3174cc andeq r4, r4, r8, lsr pc */
/* @0x3174d0 strlt r4, [r8, #-0x802] */
/* @0x3174d4 .word 0xf0004478 */
/* @0x3174d8 svclt #0xfb01 */
/* @0x3174dc andeq r4, r4, r8, asr #30 */
/* @0x3174e0 ldrlt r4, [r0, #-0x833]! */
/* @0x3174e4 stmdavs r0, {r3, r4, r5, r6, r10, lr} */
/* @0x3174e8 .word 0xf59fb083 */
/* @0x3174ec strmi lr, [r4], -r2, lsr #24 */
/* @0x3174f0 qadd16mi r11, r0, r0 */
/* @0x3174f4 ldclt p0, c11, [r0, #-12]! */
/* @0x3174f8 ldrbtmi r4, [r8], #-2094 */
/* @0x3174fc .word 0xf59f300c */
/* @0x317500 blmi 0xe92490 <b2_toiTime+0x738fec> */
/* @0x317504 ldmdbvs r12, {r0, r1, r3, r4, r5, r6, r10, lr} ^ */
/* @0x317508 ldmdavs r10, {r2, r4, r5, r7, r8, r12, sp, pc} */
/* @0x31750c strtmi r4, [r0], -r11, lsr #22 */
/* @0x317510 ldrbtmi r6, [r11], #-2081 */
/* @0x317514 qaddhs r6, r9, r0 */
/* @0x317518 stmda r10, {r0, r1, r2, r3, r4, r7, r8, r10, r12, sp, lr, pc} ^ */
/* @0x31751c ldrbtmi r4, [r8], #-2088 */
/* @0x317520 .word 0xf59f300c */
/* @0x317524 .word 0x2c00ebd6 */
/* @0x317528 stmdami r6!, {r2, r3, r4, r5, r12, lr, pc} */
/* @0x31752c ldrbtmi r4, [r8], #-1569 */
/* @0x317530 .word 0xf59f6800 */
/* @0x317534 ldrb lr, [r12, r4, lsl #24] */
/* @0x317538 .word 0x33fff04f */
/* @0x31753c movwls r4, #0x620 */
/* @0x317540 orrpl pc, r0, pc, asr #8 */
/* @0x317544 .word 0x23222203 */
/* @0x317548 .word 0xf59f9401 */
/* @0x31754c mcrrne p13, #0x2, lr, r3, c10 */
/* @0x317550 ldmdbmi sp, {r2, r5, r6, r7, r12, lr, pc} */
/* @0x317554 stmdbvs r10, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x317558 stmdavs r12, {r0, r1, r3, r7, r11, sp, lr} ^ */
/* @0x31755c smlabtvs r8, r2, r0, r5 */
/* @0x317560 .word 0xf851b174 */
/* @0x317564 movwhs r2, #0xb14 */
/* @0x317568 andvs r3, r8, r1, lsl #6 */
/* @0x31756c strmi r4, [r1], -r3, lsr #5 */
/* @0x317570 mvnsle r4, r0, lsl r4 */
/* @0x317574 andhs r4, r0, r5, lsl r11 */
/* @0x317578 ldrbtmi r6, [r11], #-8 */
/* @0x31757c .word 0xe7c5695c */
/* @0x317580 blhs 0x8556cc <b2_toiTime+0xfc228> */
/* @0x317584 blmi 0x7d1564 <b2_toiTime+0x780c0> */
/* @0x317588 strmi r4, [sp], -r4, lsl #12 */
/* @0x31758c .word 0xf103447b */
/* @0x317590 .word 0xf59f000c */
/* @0x317594 qadd8mi lr, r0, lr */
/* @0x317598 .word 0x31014629 */
/* @0x31759c .word 0xf001d006 */
/* @0x3175a0 ldrb pc, [r10, r1, lsl #16]! */
/* @0x3175a4 ldrbtmi r4, [r8], #-2059 */
/* @0x3175a8 blx 0xfe9535b0 <b2_toiTime+0xfffffffffe1fa10c> */
/* @0x3175ac .word 0xf88cf001 */
/* @0x3175b0 ldrdeq r1, r2, [r4], #-252 */
/* @0x3175b4 subeq r1, r4, lr, lsr #31 */
/* @0x3175b8 subeq r1, r4, r4, lsr #31 */
/* @0x3175bc umaaleq r1, r4, r6, pc */
/* @0x3175c0 subeq r1, r4, r10, lsl #31 */
/* @0x3175c4 umaaleq r1, r4, r2, pc */
/* @0x3175c8 subeq r1, r4, r4, asr pc */
/* @0x3175cc subeq r1, r4, lr, lsr #30 */
/* @0x3175d0 subeq r1, r4, r12, lsl pc */
/* @0x3175d4 muleq r4, r10, lr */
/* @0x3175d8 .word 0x4604b570 */
/* @0x3175dc .word 0xff80f7ff */
/* @0x3175e0 ldreq pc, [r8, #-0x104]! */
/* @0x3175e4 .word 0xf0004606 */
/* @0x3175e8 rscvs pc, r0, sp, lsr lr */
/* @0x3175ec cdp2 p0, #0x0, c15, c2, c0, #0x0 */
/* @0x3175f0 movwlo r6, #0x1873 */
/* @0x3175f4 strtmi r6, [r8], -r0, lsr #2 */
/* @0x3175f8 .word 0xf0036073 */
/* @0x3175fc strtmi lr, [r8], -r0, lsl #16 */
/* @0x317600 blx 0xfe9d3608 <b2_toiTime+0xfffffffffe27a164> */
/* @0x317604 strlt r4, [r8, #-0x806] */
/* @0x317608 stmdavs r0, {r3, r4, r5, r6, r10, lr} */
/* @0x31760c bl 0xfe754c90 <b2_toiTime+0xfffffffffdffb7ec> */
/* @0x317610 mrslo r11, apsr */
/* @0x317614 .word 0xf000d001 */
/* @0x317618 .word 0xf001ffc5 */
/* @0x31761c svclt #0xf855 */
/* @0x317620 strheq r1, [r4], #-232 */
/* @0x317624 addslo r11, r0, r0, lsl r5 */
/* @0x317628 svc #0x8cf59e */
/* @0x31762c teqlt r0, r4, lsl #12 */
/* @0x317630 addshs r2, r0, #0, #2 */
/* @0x317634 svc #0xbcf59e */
/* @0x317638 addseq pc, r0, r4, lsl #2 */
/* @0x31763c stmdami r5, {r4, r8, r10, r11, r12, sp, pc} */
/* @0x317640 .word 0xf0004478 */
/* @0x317644 .word 0x3101fa4b */
/* @0x317648 .word 0xf000d001 */
/* @0x31764c .word 0xf001ffab */
/* @0x317650 svclt #0xf83b */
/* @0x317654 andeq r4, r4, r8, lsr lr */
/* @0x317658 .word 0x4604b538 */
/* @0x31765c stclo p8, c15, [r8], {80} */
/* @0x317660 ldrmi r11, [r8, r3, lsl #2] */
/* @0x317664 addseq pc, r0, r4, lsr #3 */
/* @0x317668 ldrhtmi lr, [r8], -sp */
/* @0x31766c blt 0xcd3684 <b2_toiTime+0x57a1e0> */
/* @0x317670 .word 0xf856f000 */
/* @0x317674 ldrbtmi r4, [r8], #-2055 */
/* @0x317678 blx 0xf53680 <b2_toiTime+0x7fa1dc> */
/* @0x31767c strmi r4, [r5], -r12, lsl #12 */
/* @0x317680 .word 0xf88af000 */
/* @0x317684 andle r3, r1, r1, lsl #8 */
/* @0x317688 .word 0xff8cf000 */
/* @0x31768c .word 0xf0014628 */
/* @0x317690 svclt #0xf81b */
/* @0x317694 andeq r4, r4, lr, lsr #28 */
/* @0x317698 subseq pc, r8, r1, lsl #2 */
/* @0x31769c svclt #0xdcf7ff */
/* @0x3176a0 .word 0x4603b5d0 */
/* @0x3176a4 ldmib r7, {r3, r8, r9, r10, sp, pc} ^ */
/* @0x3176a8 .word 0xf1a06700 */
/* @0x3176ac .word 0x4c080090 */
/* @0x3176b0 stcne p8, c15, [r12], {67} */
/* @0x3176b4 stmdb r3, {r2, r3, r4, r5, r6, r10, lr} ^ */
/* @0x3176b8 .word 0xf8436716 */
/* @0x3176bc .word 0xf8432c88 */
/* @0x3176c0 .word 0xf7ff4c50 */
/* @0x3176c4 svclt #0xff89 */
/* @0x3176c8 .word 0x432b2b00 */
/* @0x3176cc strbmi r5, [lr, -r3, asr #10] */
/* @0x3176d0 .word 0xffffffe1 */
/* @0x3176d4 andhi pc, r0, pc, lsr #7 */
/* @0x3176d8 .word 0xf7ffb538 */
/* @0x3176dc stmdavs r1, {r0, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3176e0 strge r11, [r11, #-0x191] */
/* @0x3176e4 strmi lr, [r0, #-0x9d5] */
/* @0x3176e8 movwhs lr, #0xe9d1 */
/* @0x3176ec rsbmi r4, r11, r2, rrx */
/* @0x3176f0 streq lr, [r3], #-2642 */
/* @0x3176f4 movwhs sp, #0x4 */
/* @0x3176f8 strmi r6, [r8], -r3 */
/* @0x3176fc .word 0xff6cf7ff */
/* @0x317700 subsmi r6, r11, #2277376 */
/* @0x317704 ldrb r6, [r8, r11, lsl #3]! */
/* @0x317708 ldrbtmi r4, [r8], #-2051 */
/* @0x31770c .word 0xf9e6f000 */
/* @0x317710 .word 0x432b2b00 */
/* @0x317714 strbmi r5, [lr, -r3, asr #10] */
/* @0x317718 strheq r4, [r4], -lr */
/* @0x31771c andhi pc, r0, pc, lsr #7 */
/* @0x317720 .word 0x4606b570 */
/* @0x317724 mrc2 p7, #0x6, apsr_nzcv, c12, c15, #0x7 */
/* @0x317728 strmi lr, [r0, #-0x9d6] */
/* @0x31772c ldmib r3, {r1, r2, r4, r8, r9, sp, pc} ^ */
/* @0x317730 rsbmi r2, r2, r0, lsl #6 */
/* @0x317734 b 0x17a78e8 <b2_toiTime+0x104e444> */
/* @0x317738 stmdavs r1, {r0, r1, r8} */
/* @0x31773c ldmiblt r1!, {r12, lr, pc} */
/* @0x317740 stclo p8, c15, [r0], #-344 */
/* @0x317744 eorseq pc, r8, #-2147483607 */
/* @0x317748 svclt #0xb42b00 */
/* @0x31774c movweq pc, #0x11c3 */
/* @0x317750 .word 0xf8463301 */
/* @0x317754 .word 0xf8563c20 */
/* @0x317758 addmi r3, r10, #4, #24 */
/* @0x31775c .word 0xf846bf1c */
/* @0x317760 andvs r1, r2, r4, lsr #24 */
/* @0x317764 blo 0x371874 <_ZTS13C_UTF16String+0x8920> */
/* @0x317768 ldrmi r6, [r8], -r2, asr #32 */
/* @0x31776c stmdami r8, {r4, r5, r6, r8, r10, r11, r12, sp, pc} */
/* @0x317770 .word 0xf0004478 */
/* @0x317774 strhlo pc, [r1, -r3] */
/* @0x317778 .word 0xf000d001 */
/* @0x31777c .word 0xf000ff13 */
/* @0x317780 svclt #0xffa3 */
/* @0x317784 andhi pc, r0, pc, lsr #7 */
/* @0x317788 .word 0x432b2b00 */
/* @0x31778c strbmi r5, [lr, -r3, asr #10] */
/* @0x317790 muleq r4, r0, sp */
/* @0x317794 andhi pc, r0, pc, lsr #7 */
/* @0x317798 .word 0xf7ffb538 */
/* @0x31779c stmdavs r1, {r0, r1, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3177a0 ldmib r1, {r0, r7, r8, r12, sp, pc} ^ */
/* @0x3177a4 tstge r8, #58720256 */
/* @0x3177a8 movwhs lr, #0x9d3 */
/* @0x3177ac rsbmi r4, r11, r2, rrx */
/* @0x3177b0 streq lr, [r3], #-2642 */
/* @0x3177b4 teqlo r8, r7 */
/* @0x3177b8 andvs r2, r3, r0, lsl #6 */
/* @0x3177bc .word 0xf0024608 */
/* @0x3177c0 vldmdblt r8!, {s28, s29} */
/* @0x3177c4 stmibvs r11, {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x3177c8 blle 0x4623d0 <g_RomDisk+0x6abb0> */
/* @0x3177cc andle r3, r8, r1, lsl #22 */
/* @0x3177d0 andle r1, lr, r10, asr r12 */
/* @0x3177d4 ldclt p1, c6, [r8, #-556]! */
/* @0x3177d8 mvnsle r3, r1, lsl #6 */
/* @0x3177dc andvs r6, r2, r10, asr #18 */
/* @0x3177e0 stmdbvs r11, {r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x3177e4 mulvs r3, r0, r1 */
/* @0x3177e8 pop {r3, r9, r10, lr} */
/* @0x3177ec .word 0xf7ff4038 */
/* @0x3177f0 stmdami r7, {r0, r1, r4, r5, r8, r9, r10, r11, r12, sp, pc} */
/* @0x3177f4 .word 0xf0004478 */
/* @0x3177f8 .word 0x3101f971 */
/* @0x3177fc .word 0xf000d001 */
/* @0x317800 .word 0xf000fed1 */
/* @0x317804 svclt #0xff61 */
/* @0x317808 .word 0x432b2b00 */
/* @0x31780c strbmi r5, [lr, -r3, asr #10] */
/* @0x317810 andeq r4, r4, r12, lsr #26 */
/* @0x317814 andhi pc, r0, pc, lsr #7 */
/* @0x317818 .word 0x0c04f850 */
/* @0x31781c svclt #0x4770 */
/* @0x317820 .word 0xf7ffb508 */
/* @0x317824 qsublt pc, sp, r0 */
/* @0x317828 .word 0xf1d06840 */
/* @0x31782c svclt #0x380001 */
/* @0x317830 stclt p0, c2, [r8, #-0] */
/* @0x317834 orrlt r11, r0, r0, lsl r4 */
/* @0x317838 orrseq pc, r0, #160, #2 */
/* @0x31783c rscslo pc, pc, #79 */
/* @0x317840 svchi #0x5ff3bf */
/* @0x317844 svcne #0xe853 */
/* @0x317848 stmda r3, {r0, r4, r10, lr} ^ */
/* @0x31784c .word 0xf0941400 */
/* @0x317850 mvnsle r0, r0, lsl #30 */
/* @0x317854 svchi #0x5ff3bf */
/* @0x317858 .word 0xbc10b109 */
/* @0x31785c .word 0xbc104770 */
/* @0x317860 mrclt p7, #0x7, apsr_nzcv, c10, c15, #0x7 */
/* @0x317864 ldmlo r0, {r3, r5, r6, r8, r12, sp, pc} */
/* @0x317868 .word 0xf3bf2301 */
/* @0x31786c ldmda r0, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^ */
/* @0x317870 ldrmi r2, [r10], #-3840 */
/* @0x317874 .word 0x2100e840 */
/* @0x317878 svceq #0xf091 */
/* @0x31787c .word 0xf3bfd1f7 */
/* @0x317880 .word 0x47708f5f */
/* @0x317884 svclt #0x4770 */
/* @0x317888 ldrbmi r2, [r0, -r0]! */
/* @0x31788c svcmi #0xf8e92d */
/* @0x317890 strmi r4, [sp], -r7, lsl #12 */
/* @0x317894 .word 0x46994692 */
/* @0x317898 strtmi r4, [r8], -r9, asr #12 */
/* @0x31789c stc2l p0, c15, [r4, #-0]! */
/* @0x3178a0 strtmi r4, [r8], -r4, lsl #12 */
/* @0x3178a4 mrsle r2, spsr */
/* @0x3178a8 ldmvs r11, {r0, r1, r3, r5, r11, sp, lr} ^ */
/* @0x3178ac stmdahs r1, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x3178b0 stmdahs r2, {r1, r2, r3, r4, r5, r12, lr, pc} */
/* @0x3178b4 ldmdblt r8, {r0, r4, r12, lr, pc} */
/* @0x3178b8 ldrtmi r4, [r8], -r7, lsl #12 */
/* @0x3178bc svchi #0xf8e8bd */
/* @0x3178c0 .word 0x21ad4826 */
/* @0x3178c4 strtmi r4, [r7], -r6, lsr #20 */
/* @0x3178c8 ldrbtmi r4, [r8], #-2854 */
/* @0x3178cc ldrbtmi r4, [r11], #-1146 */
/* @0x3178d0 bl 0x1e54f54 <b2_toiTime+0x16fbab0> */
/* @0x3178d4 pop {r3, r4, r5, r9, r10, lr} */
/* @0x3178d8 stmvs r10!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} ^ */
/* @0x3178dc .word 0xb000f8d7 */
/* @0x3178e0 eorsle r2, r8, r0, lsl #20 */
/* @0x3178e4 strtmi r4, [r0], lr, lsr #12 */
/* @0x3178e8 biceq lr, r4, #5120 */
/* @0x3178ec .word 0x0799695b */
/* @0x3178f0 andsne sp, r8, #79691776 */
/* @0x3178f4 ldmdbvs r1!, {r1, r3, r4, r6, r7, r8, r9, r10} */
/* @0x3178f8 svclt #0x48464b */
/* @0x3178fc andeq pc, r0, r11, asr r8 */
/* @0x317900 ldmdane r8!, {r1, r4, r6, r9, r10, lr} */
/* @0x317904 .word 0xffc2f7ff */
/* @0x317908 sbcsle r1, r5, r3, asr #24 */
/* @0x31790c .word 0xf1b8b120 */
/* @0x317910 andle r0, r10, r0, lsl #30 */
/* @0x317914 smlabble sp, r0, r5, r4 */
/* @0x317918 strlo r6, [r1], #-2282 */
/* @0x31791c adcmi r3, r2, #8, #12 */
/* @0x317920 strbmi sp, [r7], -r2, ror #17 */
/* @0x317924 pop {r3, r4, r5, r9, r10, lr} */
/* @0x317928 stmvs r10!, {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc} ^ */
/* @0x31792c ldrb r4, [r4, r0, lsl #13]! */
/* @0x317930 ldr r6, [r1, sp, lsr #17]! */
/* @0x317934 ldrblo pc, [pc, pc, asr #32]! */
/* @0x317938 .word 0xf1dae7bf */
/* @0x31793c svclt #0x380301 */
/* @0x317940 ldrmi r2, [r10, #0x300]! */
/* @0x317944 .word 0x469abf14 */
/* @0x317948 beq 0x393a5c <ft_adobe_glyph_list+0x3138> */
/* @0x31794c svceq #0xf1ba */
/* @0x317950 strhs r11, [r0, -r8, lsl #30] */
/* @0x317954 .word 0x4617e7b1 */
/* @0x317958 svclt #0xe7af */
/* @0x31795c andeq r4, r4, lr, lsr #25 */
/* @0x317960 andeq sp, r8, r12, lsr r11 */
/* @0x317964 andeq r10, r1, r2, lsr #24 */
/* @0x317968 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x31796c strmi r4, [r0], lr, lsl #12 */
/* @0x317970 shadd8mi r6, r0, r1 */
/* @0x317974 ldmdbvs r5, {r2, r4, r9, r10, lr} */
/* @0x317978 ldc2l p0, c15, [r6], #0 */
/* @0x31797c .word 0xf8c4b108 */
/* @0x317980 stmdavs r3!, {r4, pc} */
/* @0x317984 mlasle r8, r8, r5, r4 */
/* @0x317988 shasxmi r6, r0, r3 */
/* @0x31798c .word 0x479868db */
/* @0x317990 suble r2, r11, r1, lsl #16 */
/* @0x317994 andle r2, sp, r2, lsl #16 */
/* @0x317998 stmdami r7!, {r3, r6, r8, r12, sp, pc} */
/* @0x31799c .word 0x1105f240 */
/* @0x3179a0 blmi 0xcea240 <b2_toiTime+0x590d9c> */
/* @0x3179a4 ldrbtmi r4, [r10], #-1144 */
/* @0x3179a8 .word 0xf59f447b */
/* @0x3179ac .word 0x6125eb00 */
/* @0x3179b0 .word 0x87f0e8bd */
/* @0x3179b4 .word 0xf8d868f1 */
/* @0x3179b8 stmdbhs r0, {sp, pc} */
/* @0x3179bc .word 0x2700d0f7 */
/* @0x3179c0 bl 0x4a948c <SrcVerts+0x64d0> */
/* @0x3179c4 strlo r0, [r1, -r7, asr #7] */
/* @0x3179c8 ldmdbvs r11, {r1, r5, r9, r10, lr} ^ */
/* @0x3179cc svceq #0x2f013 */
/* @0x3179d0 eorhs lr, r3, pc, asr #20 */
/* @0x3179d4 ldrbeq sp, [r11, r12] */
/* @0x3179d8 ldrsbne pc, [r0], -r9 */
/* @0x3179dc .word 0xf85abf48 */
/* @0x3179e0 strbmi r0, [r0], #-0 */
/* @0x3179e4 .word 0xffc0f7ff */
/* @0x3179e8 movwlo r6, #0x1963 */
/* @0x3179ec ldmvs r1!, {r0, r1, r2, r3, r4, r6, r7, r12, lr, pc} ^ */
/* @0x3179f0 .word 0xf109428f */
/* @0x3179f4 .word 0xd3e40908 */
/* @0x3179f8 stmdbvs r3!, {r0, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x3179fc sbcle r2, r3, r0, lsl #22 */
/* @0x317a00 ldrtmi r6, [r0], -r1, ror #16 */
/* @0x317a04 ldc2 p0, c15, [r0], #0 */
/* @0x317a08 adcsle r2, sp, r0, lsl #16 */
/* @0x317a0c .word 0xb1426962 */
/* @0x317a10 .word 0x61256923 */
/* @0x317a14 svclt #0x1c429a */
/* @0x317a18 .word 0x33fff04f */
/* @0x317a1c pop {r0, r1, r5, r6, r8, sp, lr} */
/* @0x317a20 stmdbvs r3!, {r4, r5, r6, r7, r8, r9, r10, pc} */
/* @0x317a24 .word 0x61636125 */
/* @0x317a28 .word 0x87f0e8bd */
/* @0x317a2c .word 0x464068b1 */
/* @0x317a30 .word 0xf7ff4622 */
/* @0x317a34 .word 0xe7baff99 */
/* @0x317a38 ldrdeq r4, r5, [r4], -r4 */
/* @0x317a3c strdeq sp, lr, [r8], -r10 */
/* @0x317a40 andeq r10, r1, r8, asr #22 */
/* @0x317a44 ldrbmi lr, [r0, sp, lsr #18]! */
/* @0x317a48 stmdavs r0, {r2, r9, r10, lr} */
/* @0x317a4c ldrmi r4, [r7], -r10, lsl #13 */
/* @0x317a50 ldrmi r11, [lr], -r6, lsl #1 */
/* @0x317a54 .word 0xf8502200 */
/* @0x317a58 ldrtmi r1, [r11], -r8, lsl #24 */
/* @0x317a5c stmdaeq r1, {r2, r8, r9, r11, sp, lr, pc} */
/* @0x317a60 strbmi r5, [r0], -r1, ror #16 */
/* @0x317a64 .word 0x9c04f851 */
/* @0x317a68 .word 0xf7ff4649 */
/* @0x317a6c strmi pc, [r5], -pc, lsl #30 */
/* @0x317a70 eorle r2, r9, r0, lsl #26 */
/* @0x317a74 ldrhle r1, [r10], -r1 */
/* @0x317a78 bl 0xff49ec28 <b2_toiTime+0xfffffffffed45784> */
/* @0x317a7c svclt #0x180004 */
/* @0x317a80 cdphs p2, #0x0, c2, c0, c1, #0x0 */
/* @0x317a84 movwhs r11, #0xfb4 */
/* @0x317a88 movweq pc, #0x1002 */
/* @0x317a8c stm sp, {r0, r1, r5, r6, r7, r8, r11, r12, sp, pc} */
/* @0x317a90 smladls r2, r0, r4, r0 */
/* @0x317a94 movwls r9, #0x4603 */
/* @0x317a98 biclt r9, r2, r5, lsl #6 */
/* @0x317a9c ldrtmi r4, [r9], -r8, lsr #12 */
/* @0x317aa0 .word 0xf7ff466a */
/* @0x317aa4 stmdals r5, {r0, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x317aa8 movwlo r1, #0x3e43 */
/* @0x317aac andhs sp, r0, r12, lsl #18 */
/* @0x317ab0 andle r1, r9, r10, ror #24 */
/* @0x317ab4 strbmi r4, [r9], -r0, asr #12 */
/* @0x317ab8 ldrbmi r4, [r3], -r2, lsr #12 */
/* @0x317abc mcr2 p7, #0x7, pc, c6, c15, #0x7 */
/* @0x317ac0 svclt #0xc4284 */
/* @0x317ac4 andhs r4, r0, r8, lsr #12 */
/* @0x317ac8 pop {r1, r2, r12, sp, pc} */
/* @0x317acc .word 0x464087f0 */
/* @0x317ad0 strbtmi r4, [r10], -r9, asr #12 */
/* @0x317ad4 .word 0xff48f7ff */
/* @0x317ad8 svclt #0xe7e5 */
/* @0x317adc .word 0x4602b538 */
/* @0x317ae0 .word 0x46054b10 */
/* @0x317ae4 ldrbtmi r4, [r11], #-2320 */
/* @0x317ae8 .word 0xf103681b */
/* @0x317aec ldrbtmi r0, [r9], #-168 */
/* @0x317af0 mrc p5, #0x6, apsr_nzcv, c8, c14, #0x4 */
/* @0x317af4 .word 0x2100480d */
/* @0x317af8 .word 0xf59e4478 */
/* @0x317afc .word 0x4604ed12 */
/* @0x317b00 stmdbmi r11, {r3, r5, r6, r8, r12, sp, pc} */
/* @0x317b04 .word 0xf59e4479 */
/* @0x317b08 strmi lr, [r3], -r6, lsl #26 */
/* @0x317b0c stmdbmi r9, {r5, r8, r12, sp, pc} */
/* @0x317b10 strtmi r2, [r10], -r7 */
/* @0x317b14 .word 0x47984479 */
/* @0x317b18 .word 0xf59e4620 */
/* @0x317b1c .word 0xf000ed08 */
/* @0x317b20 svclt #0xfb97 */
/* @0x317b24 andeq r9, sp, r2, ror #18 */
/* @0x317b28 ldrdeq r4, r5, [r4], -r10 */
/* @0x317b2c andeq r4, r4, r4, ror #21 */
/* @0x317b30 andeq r4, r4, r4, ror #21 */
/* @0x317b34 andeq r4, r4, r8, ror #21 */
/* @0x317b38 .word 0xf7ffb508 */
/* @0x317b3c .word 0xf000fdf1 */
/* @0x317b40 svclt #0xfb87 */
/* @0x317b44 mrslt r6, apsr */
/* @0x317b48 sadd16mi r5, r8, r11 */
/* @0x317b4c svclt #0x4770 */
/* @0x317b50 teqlt r10, r8, lsl #10 */
/* @0x317b54 addeq lr, r0, r2, lsr #23 */
/* @0x317b58 mrslt r6, apsr */
/* @0x317b5c stclt p8, c5, [r8, #-768] */
/* @0x317b60 stclt p6, c4, [r8, #-96] */
/* @0x317b64 .word 0xf7ff9802 */
/* @0x317b68 svclt #0xffe7 */
/* @0x317b6c ldrblt r4, [r0, #-0x3c0]! */
/* @0x317b70 bl 0x3c3d80 <error_g0017+0x1ca24> */
/* @0x317b74 stcls p0, c0, [r6, #-512] */
/* @0x317b78 .word 0x9c071f06 */
/* @0x317b7c ands r11, r0, r2, asr #18 */
/* @0x317b80 qadd8mi r5, r9, r8 */
/* @0x317b84 bge 0x37cb90 <_ZTS13C_UTF16String+0x13c3c> */
/* @0x317b88 ldmvs r11, {r0, r1, r11, sp, lr} */
/* @0x317b8c ldmdblt r0!, {r3, r4, r7, r8, r9, r10, lr} */
/* @0x317b90 svclo #0x4f856 */
/* @0x317b94 mvnsle r2, r0, lsl #22 */
/* @0x317b98 andlt r2, r2, r1 */
/* @0x317b9c andhs r11, r0, r0, ror sp */
/* @0x317ba0 stmdals r8, {r0, r1, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x317ba4 .word 0xffc8f7ff */
/* @0x317ba8 svcmi #0xf0e92d */
/* @0x317bac .word 0x4606b093 */
/* @0x317bb0 andhs r2, r0, r0, lsl #8 */
/* @0x317bb4 andls r2, r6, #0, #10 */
/* @0x317bb8 stmib r6, {r0, r1, r9, sp} ^ */
/* @0x317bbc .word 0xf0114500 */
/* @0x317bc0 adcsvs r0, r0, r1, lsl #10 */
/* @0x317bc4 smlalsvs r4, r0, r8, r6 */
/* @0x317bc8 .word 0x91056130 */
/* @0x317bcc .word 0x61b26170 */
/* @0x317bd0 strls r9, [r9, #-0xc1c] */
/* @0x317bd4 sbcshi pc, sp, r0 */
/* @0x317bd8 svceq #0xef011 */
/* @0x317bdc sbcshi pc, r6, r0, asr #32 */
/* @0x317be0 .word 0xf0024620 */
/* @0x317be4 mulls r12, r2, pc */
/* @0x317be8 .word 0xf0002800 */
/* @0x317bec movwhs r8, #0xde */
/* @0x317bf0 rscsvs r2, r0, pc, lsl #4 */
/* @0x317bf4 ldrmi r4, [r9], -r0, lsr #12 */
/* @0x317bf8 strls r10, [r0, #-0xd11] */
/* @0x317bfc svc #0xf2f001 */
/* @0x317c00 qadd16mi r9, r0, r1 */
/* @0x317c04 .word 0xf023ac12 */
/* @0x317c08 .word 0xf0020a01 */
/* @0x317c0c blls 0x6539ec <g_SWFlinevertbuff+0x924> */
/* @0x317c10 blo 0x314040 <af_shaper_get_elem+0x98ae> */
/* @0x317c14 blne 0x395c68 <ft_adobe_glyph_list+0x5344> */
/* @0x317c18 ldclo p8, c15, [r8, #-272] */
/* @0x317c1c bl 0xff329438 <b2_toiTime+0xfffffffffebcff94> */
/* @0x317c20 strtmi r0, [r0], -r10, lsl #20 */
/* @0x317c24 cdp2 p0, #0x0, c15, c6, c0, #0x0 */
/* @0x317c28 strmi r9, [r2], -r12, lsl #22 */
/* @0x317c2c svclt #0x82800 */
/* @0x317c30 .word 0xf813462a */
/* @0x317c34 andls r5, r7, #1024 */
/* @0x317c38 strls r2, [r10, #-0xdff] */
/* @0x317c3c .word 0xf000930c */
/* @0x317c40 .word 0x462080bd */
/* @0x317c44 stc2l p0, c15, [r4] */
/* @0x317c48 ldmdane r8, {r2, r3, r8, r9, r11, r12, pc} */
/* @0x317c4c .word 0xf8139008 */
/* @0x317c50 strtmi r5, [r0], -r1, lsl #22 */
/* @0x317c54 movwls r10, #0xcc12 */
/* @0x317c58 ldc2 p0, c15, [r10, #0]! */
/* @0x317c5c .word 0xf8449b0c */
/* @0x317c60 ldmdane pc, {r2, r4, r8, r10, r11, r12, sp} */
/* @0x317c64 ldmdble r4, {r0, r1, r2, r3, r4, r7, r9, lr} */
/* @0x317c68 strtmi r4, [r0], -r9, lsr #12 */
/* @0x317c6c stc2l p0, c15, [r2, #0]! */
/* @0x317c70 strmi r4, [r1], r9, lsr #12 */
/* @0x317c74 .word 0xf0004620 */
/* @0x317c78 .word 0x4629fddd */
/* @0x317c7c strtmi r4, [r0], -r3, lsl #13 */
/* @0x317c80 ldc2l p0, c15, [r8] */
/* @0x317c84 strtmi r9, [r0], -r4 */
/* @0x317c88 stc2 p0, c15, [r2, #0]! */
/* @0x317c8c .word 0xf08045ca */
/* @0x317c90 strbmi r8, [r0], -pc, lsl #1 */
/* @0x317c94 .word 0xff50f7ff */
/* @0x317c98 stmdbhs r0, {r2, r8, r11, r12, pc} */
/* @0x317c9c addhi pc, r5, r0 */
/* @0x317ca0 stcls p12, c9, [r4, #-28] */
/* @0x317ca4 strls r1, [r11], #-2404 */
/* @0x317ca8 .word 0xf0002800 */
/* @0x317cac stcls p0, c8, [r5, #-552] */
/* @0x317cb0 beq 0x15540ec <b2_toiTime+0xdfac48> */
/* @0x317cb4 stmdalo r1, {r0, r2, r10, r11, r12, pc} */
/* @0x317cb8 streq pc, [r6, #-0x5] */
/* @0x317cbc .word 0xf004183f */
/* @0x317cc0 .word 0xf8dd0405 */
/* @0x317cc4 strls r11, [r4, #-0x28] */
/* @0x317cc8 .word 0xf84a9407 */
/* @0x317ccc .word 0x960a7d10 */
/* @0x317cd0 strtmi lr, [r9], -r1, asr #32 */
/* @0x317cd4 ldrbmi r9, [r11], -r8, lsl #20 */
/* @0x317cd8 andhi pc, r0, sp, asr #17 */
/* @0x317cdc .word 0xff38f7ff */
/* @0x317ce0 stmdahs r0, {r1, r2, r9, r10, lr} */
/* @0x317ce4 stmdbls r6, {r0, r1, r3, r4, r5, r6, r12, lr, pc} */
/* @0x317ce8 .word 0xf858b351 */
/* @0x317cec .word 0xf1089c34 */
/* @0x317cf0 movwls r0, #0xf358 */
/* @0x317cf4 andeq pc, r1, #1073741878 */
/* @0x317cf8 andhs r11, r0, #56, #30 */
/* @0x317cfc svclt #0x142b00 */
/* @0x317d00 .word 0xf0424613 */
/* @0x317d04 blhs 0x318910 <__cxa_call_unexpected+0x248> */
/* @0x317d08 ldmdbmi r2, {r0, r1, r6, r7, r8, r12, lr, pc} ^ */
/* @0x317d0c bmi 0x17a9634 <b2_toiTime+0x1050190> */
/* @0x317d10 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x317d14 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x317d18 mrc2 p7, #0x4, apsr_nzcv, c4, c15, #0x7 */
/* @0x317d1c .word 0xf8d8b110 */
/* @0x317d20 movwls r3, #0xf058 */
/* @0x317d24 shasxmi r6, r0, r3 */
/* @0x317d28 bge 0x6e9654 <g_SWFvertbuff+0x1658c> */
/* @0x317d2c .word 0x4798689b */
/* @0x317d30 bls 0x5841f8 <g_SWFlineaavertbuff+0x31130> */
/* @0x317d34 .word 0xf0402a00 */
/* @0x317d38 stcls p0, c8, [r5, #-520] */
/* @0x317d3c strle r0, [r8, #0x72b]! */
/* @0x317d40 ldmdage r2, {r1, r2, r3, r8, r9, r11, r12, pc} */
/* @0x317d44 stclo p8, c15, [r8, #-256] */
/* @0x317d48 ldc2l p0, c15, [r4, #-0] */
/* @0x317d4c eorle r2, r11, r0, lsl #16 */
/* @0x317d50 ldmdane pc!, {r1, r2, r3, r8, r9, r10, r11, r12, pc} */
/* @0x317d54 ldrbmi r9, [r0], -lr, lsl #14 */
/* @0x317d58 stc2l p0, c15, [r12, #-0] */
/* @0x317d5c movwhs r2, #0x200 */
/* @0x317d60 strmi r1, [r4], -r5, asr #15 */
/* @0x317d64 .word 0x41ab42a2 */
/* @0x317d68 b 0x184ec3c <b2_toiTime+0x10f5798> */
/* @0x317d6c teqle r10, r5, lsl #2 */
/* @0x317d70 stmdbhs r2, {r2, r8, r11, r12, pc} */
/* @0x317d74 cdpls p1, #0x0, c13, c10, c4, #0x7 */
/* @0x317d78 cmpeq r8, #8, #2 */
/* @0x317d7c strmi lr, [r0, #-0x9c6] */
/* @0x317d80 cmnvs r3, r11, lsl #24 */
/* @0x317d84 adcsvs r2, r7, r6, lsl #6 */
/* @0x317d88 .word 0x61b36134 */
/* @0x317d8c pop {r0, r1, r4, r12, sp, pc} */
/* @0x317d90 stcls p15, c8, [r5, #-960] */
/* @0x317d94 ldrble r0, [r9, #0x7aa]! */
/* @0x317d98 movweq pc, #0xc005 */
/* @0x317d9c .word 0xf47f2b0c */
/* @0x317da0 movwhs r10, #0x2f1f */
/* @0x317da4 .word 0xe7f161b3 */
/* @0x317da8 movwhs r9, #0x8e0a */
/* @0x317dac .word 0xe7ed61b3 */
/* @0x317db0 strbmi r4, [r10, #0x4d9] */
/* @0x317db4 svcge #0x70f4ff */
/* @0x317db8 ldrb r9, [r3, -sp, lsl #22] */
/* @0x317dbc strls r2, [r8, #-0x500] */
/* @0x317dc0 .word 0x9c05e745 */
/* @0x317dc4 movweq pc, #0x6004 */
/* @0x317dc8 mvnle r2, r2, lsl #22 */
/* @0x317dcc movwhs r9, #0xc0b */
/* @0x317dd0 stmib r6, {r9, sp} ^ */
/* @0x317dd4 movwhs r2, #0x6300 */
/* @0x317dd8 ldrhvs r6, [r4, -r3]! */
/* @0x317ddc stmdbls r7, {r1, r2, r4, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x317de0 adcle r2, r10, r0, lsl #18 */
/* @0x317de4 bls 0x4d1d08 <SrcVerts+0x2ed4c> */
/* @0x317de8 rscsle r2, r8, r0, lsl #20 */
/* @0x317dec svceq #0x58f118 */
/* @0x317df0 ldcvs p8, c15, [r4], #-352 */
/* @0x317df4 ldmdbeq r8, {r3, r8, r12, sp, lr, pc} ^ */
/* @0x317df8 movwhs r11, #0xf14 */
/* @0x317dfc cdphs p3, #0x0, c2, c0, c1, #0x0 */
/* @0x317e00 .word 0xf043bf08 */
/* @0x317e04 blhs 0x318a10 <__cxa_call_unexpected+0x348> */
/* @0x317e08 svcge #0x43f47f */
/* @0x317e0c bls 0x5296b8 <SrcVerts+0x866fc> */
/* @0x317e10 stm sp, {r0, r1, r3, r4, r6, r9, r10, lr} */
/* @0x317e14 .word 0xf8cd0240 */
/* @0x317e18 .word 0xf7ff8008 */
/* @0x317e1c stmdahs r0, {r0, r1, r2, r5, r7, r9, r10, r11, r12, sp, lr, pc} */
/* @0x317e20 blls 0x58c060 <g_SWFlineaavertbuff+0x38f98> */
/* @0x317e24 addle r2, r8, r0, lsl #22 */
/* @0x317e28 movwhs r9, #0x6e0a */
/* @0x317e2c strmi lr, [r0, #-0x9c6] */
/* @0x317e30 adcsvs r9, r7, r11, lsl #24 */
/* @0x317e34 andsls pc, r4, r6, asr #17 */
/* @0x317e38 .word 0x61b36134 */
/* @0x317e3c cdpls p7, #0x0, c14, c10, c6, #0x5 */
/* @0x317e40 stmib r6, {r0, r1, r2, r3, r8, r9, r11, r12, pc} ^ */
/* @0x317e44 .word 0x9c0b4500 */
/* @0x317e48 movwhs r6, #0x6173 */
/* @0x317e4c ldrhvs r6, [r4, -r7]! */
/* @0x317e50 .word 0xe79b61b3 */
/* @0x317e54 strdeq r9, r10, [sp], -r4 */
/* @0x317e58 strdeq r9, r10, [sp], -r8 */
/* @0x317e5c .word 0x460db5f0 */
/* @0x317e60 smlabbhs r0, r5, r0, r11 */
/* @0x317e64 ldrmi r10, [r6], -r4, lsl #24 */
/* @0x317e68 strmi r4, [r10], -r7, lsl #12 */
/* @0x317e6c strtmi r4, [r8], -r11, lsl #12 */
/* @0x317e70 stcvc p8, c15, [r4, #-272] */
/* @0x317e74 .word 0xf0019400 */
/* @0x317e78 ldmdavs r7!, {r3, r4, r5, r6, r7, r9, r10, r11, sp, lr, pc} */
/* @0x317e7c andhs r2, r1, #0, #2 */
/* @0x317e80 strmi r4, [r11], -r8, lsr #12 */
/* @0x317e84 strls r9, [r3, -r0, lsl #8] */
/* @0x317e88 cdp p0, #0xe, c15, c14, c1, #0x0 */
/* @0x317e8c andhs r2, pc, #0, #2 */
/* @0x317e90 ldmdbvs r6!, {r3, r5, r9, r10, lr} */
/* @0x317e94 strls r4, [r0], #-1547 */
/* @0x317e98 cdp p0, #0xa, c15, c4, c1, #0x0 */
/* @0x317e9c .word 0x21009b03 */
/* @0x317ea0 .word 0xf0034628 */
/* @0x317ea4 andhs r0, pc, #67108864 */
/* @0x317ea8 .word 0x460b431e */
/* @0x317eac strls r9, [r3], -r0, lsl #8 */
/* @0x317eb0 cdp p0, #0xd, c15, c10, c1, #0x0 */
/* @0x317eb4 ldcllt p0, c11, [r0, #20]! */
/* @0x317eb8 .word 0xf002b508 */
/* @0x317ebc stmdahs r0, {r1, r2, r3, r4, r5, r6, r7, r8, r10, r11, sp, lr, pc} */
/* @0x317ec0 andhs r11, r8, r12, lsl #30 */
/* @0x317ec4 stclt p0, c2, [r8, #-36] */
/* @0x317ec8 .word 0x4604b570 */
/* @0x317ecc .word 0x21004608 */
/* @0x317ed0 ldrmi r11, [r5], -r4, lsl #1 */
/* @0x317ed4 andhs r4, sp, #11534336 */
/* @0x317ed8 strls r10, [r0], -r3, lsl #28 */
/* @0x317edc cdp p0, #0x8, c15, c2, c1, #0x0 */
/* @0x317ee0 stmdavs r10!, {r0, r3, r5, r6, r8, r11, sp, lr} */
/* @0x317ee4 rsbvs r6, r1, #704512 */
/* @0x317ee8 adcvs r9, r2, #49152 */
/* @0x317eec eorvs r6, r1, #-1946157056 */
/* @0x317ef0 ldcllt p0, c11, [r0, #-16]! */
/* @0x317ef4 blvs 0x3f2904 <MAX_TEXTURE_SIZE+0x5c> */
/* @0x317ef8 bvs 0x1444f40 <b2_toiTime+0xceba9c> */
/* @0x317efc andhs r6, r0, #10 */
/* @0x317f00 mrsvs r6, spsr */
/* @0x317f04 .word 0xbc10604a */
/* @0x317f08 svclt #0x4770 */
/* @0x317f0c bllt 0xfe653f14 <b2_toiTime+0xfffffffffdefaa70> */
/* @0x317f10 .word 0x460db5f0 */
/* @0x317f14 ldrmi r11, [r7], -r3, lsl #1 */
/* @0x317f18 .word 0xf7ff4604 */
/* @0x317f1c qsub8mi pc, r8, r7 */
/* @0x317f20 .word 0xf002ae02 */
/* @0x317f24 .word 0x4603edf2 */
/* @0x317f28 .word 0xf8139001 */
/* @0x317f2c .word 0xf8461b01 */
/* @0x317f30 ldrtmi r3, [r0], -r4, lsl #26 */
/* @0x317f34 ldc2l p0, c15, [lr], #-0 */
/* @0x317f38 .word 0xf0024628 */
/* @0x317f3c blls 0x3936bc <ft_adobe_glyph_list+0x2d98> */
/* @0x317f40 .word 0xf8132000 */
/* @0x317f44 bhs 0x2e2b50 <_ZN15b2ContactSolver24SolveVelocityConstraintsEv+0x25c> */
/* @0x317f48 andle r9, r4, r1, lsl #6 */
/* @0x317f4c .word 0xf0004630 */
/* @0x317f50 blls 0x397054 <ft_adobe_glyph_list+0x6730> */
/* @0x317f54 ldmdavs r10!, {r3, r4, r11, r12} */
/* @0x317f58 .word 0xf85043d2 */
/* @0x317f5c bl 0x323fec */
/* @0x317f60 teqlt r3, r2, lsl #1 */
/* @0x317f64 strmi r2, [r2], -r0, lsl #6 */
/* @0x317f68 svcne #0x4f852 */
/* @0x317f6c stmdbhs r0, {r0, r8, r9, r12, sp} */
/* @0x317f70 adcvs sp, r3, #-2147483586 */
/* @0x317f74 .word 0x63602304 */
/* @0x317f78 andlt r6, r3, r3, lsr #6 */
/* @0x317f7c svclt #0xbdf0 */
/* @0x317f80 andeq pc, r3, r0 */
/* @0x317f84 push {r0, r11, sp} */
/* @0x317f88 .word 0x460c43f0 */
/* @0x317f8c ldrmi r11, [r6], -sp, lsl #1 */
/* @0x317f90 stmdbhi r0, {r0, r4, r6, r7, r8, r11, sp, lr, pc} */
/* @0x317f94 eorsle sp, lr, #86 */
/* @0x317f98 strhs r10, [r1, #-0xf03] */
/* @0x317f9c ldrtmi r2, [r0], -r0, lsl #2 */
/* @0x317fa0 strls r2, [r3], #-524 */
/* @0x317fa4 strls r4, [r0, -r11, lsl #12] */
/* @0x317fa8 cdp p0, #0x5, c15, c14, c1, #0x0 */
/* @0x317fac suble r2, r7, r0, lsl #28 */
/* @0x317fb0 ldmib r3, {r0, r1, r3, r6, r8, r9, sp, pc} ^ */
/* @0x317fb4 b 0xfe3a0bbc <b2_toiTime+0xfffffffffdc47718> */
/* @0x317fb8 b 0xfe3d87e0 <b2_toiTime+0xfffffffffdc7f33c> */
/* @0x317fbc b 0x1798be8 <b2_toiTime+0x103f744> */
/* @0x317fc0 svclt #0x140103 */
/* @0x317fc4 strhs r2, [r1, -r0, lsl #14] */
/* @0x317fc8 strtle r0, [r10], #-2025 */
/* @0x317fcc ldrle r0, [r7, #-0x7aa]! */
/* @0x317fd0 ldrble r0, [pc, #-0x76b] */
/* @0x317fd4 rsbsle r2, r1, r0, lsl #30 */
/* @0x317fd8 andeq lr, r7, r4, lsl r9 */
/* @0x317fdc ldmdaeq r0, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x317fe0 .word 0x3c14f854 */
/* @0x317fe4 .word 0x5c10f854 */
/* @0x317fe8 strtmi r9, [r0], -r7 */
/* @0x317fec strbmi r9, [r1], -r8, lsl #2 */
/* @0x317ff0 movwls r1, #0x47df */
/* @0x317ff4 strls r9, [r6, #-0x705] */
/* @0x317ff8 .word 0xf7ff9209 */
/* @0x317ffc qsub16mi pc, r0, r11 */
/* @0x318000 .word 0x46424631 */
/* @0x318004 .word 0xff2af7ff */
/* @0x318008 ldrtmi r4, [r1], -r0, lsr #12 */
/* @0x31800c .word 0xf7ff4642 */
/* @0x318010 andhs pc, r7, pc, ror pc */
/* @0x318014 stmdahs r2, {r1, sp, lr, pc} */
/* @0x318018 andhs sp, r9, sp */
/* @0x31801c pop {r0, r2, r3, r12, sp, pc} */
/* @0x318020 qsub8mi r8, r9, r0 */
/* @0x318024 qasxmi r4, r3, r10 */
/* @0x318028 strls r10, [r0], -r4, lsl #16 */
/* @0x31802c ldc2 p7, c15, [r12, #1020]! */
/* @0x318030 stchs p13, c9, [r6, #-40] */
/* @0x318034 qadd16mi sp, r0, r5 */
/* @0x318038 .word 0xf7ff4631 */
/* @0x31803c .word 0xe7edff3d */
/* @0x318040 strb r2, [r11, r3]! */
/* @0x318044 ldrmi r2, [r0], -r0, lsl #2 */
/* @0x318048 bvs 0xc60884 <b2_toiTime+0x5073e0> */
/* @0x31804c svcge #0x3460b */
/* @0x318050 .word 0xf0019700 */
/* @0x318054 blls 0x41377c <g_RomDisk+0x1bf5c> */
/* @0x318058 svclt #0xc429d */
/* @0x31805c strhs r2, [r2, #-0x506] */
/* @0x318060 qadd8mi lr, r8, r12 */
/* @0x318064 sbcsle r2, r9, r0, lsl #30 */
/* @0x318068 strtmi r9, [r0], -r4, lsl #22 */
/* @0x31806c bge 0x429938 <g_RomDisk+0x32118> */
/* @0x318070 .word 0x3c14f844 */
/* @0x318074 .word 0xf8449b06 */
/* @0x318078 blls 0x4e70c0 <SrcVerts+0x44104> */
/* @0x31807c .word 0x3c0cf844 */
/* @0x318080 .word 0xf8449b08 */
/* @0x318084 blls 0x5670ac <g_SWFlineaavertbuff+0x13fe4> */
/* @0x318088 .word 0x3c04f844 */
/* @0x31808c .word 0xff1cf7ff */
/* @0x318090 strb r4, [r3, r8, lsr #12] */
/* @0x318094 strtmi r4, [r9], -r3, lsr #12 */
/* @0x318098 stmdage r4, {r1, r3, r4, r5, r9, r10, lr} */
/* @0x31809c .word 0xf7ff9600 */
/* @0x3180a0 blls 0x5d76b4 <g_SWFaavertbuff+0x45ec> */
/* @0x3180a4 bicle r2, r6, r6, lsl #22 */
/* @0x3180a8 bge 0x429974 <g_RomDisk+0x32154> */
/* @0x3180ac .word 0xf7ff4620 */
/* @0x3180b0 .word 0x4620fed5 */
/* @0x3180b4 .word 0xff2af7ff */
/* @0x3180b8 str r2, [pc, r7]! */
/* @0x3180bc ldmdaeq r0, {r0, r2, r3, r8, r12, sp, lr, pc} */
/* @0x3180c0 strtmi r4, [r9], -r3, lsr #12 */
/* @0x3180c4 .word 0x4640463a */
/* @0x3180c8 .word 0xf7ff9600 */
/* @0x3180cc blls 0x5d7688 <g_SWFaavertbuff+0x45c0> */
/* @0x3180d0 addsle r2, r4, r6, lsl #22 */
/* @0x3180d4 .word 0xf7ff4620 */
/* @0x3180d8 svclt #0xfd2f */
/* @0x3180dc andhi pc, r0, pc, lsr #7 */
/* @0x3180e0 .word 0x432b2b00 */
/* @0x3180e4 strbmi r5, [lr, -r3, asr #10] */
/* @0x3180e8 ldrlt r4, [r0, #-0xb04] */
/* @0x3180ec .word 0x4604447b */
/* @0x3180f0 andvs r3, r3, r8, lsl #6 */
/* @0x3180f4 stc2l p0, c15, [r8], #0 */
/* @0x3180f8 ldclt p6, c4, [r0, #-128] */
/* @0x3180fc ldrdeq r4, r5, [sp], -r0 */
/* @0x318100 .word 0x4604b510 */
/* @0x318104 .word 0xfff0f7ff */
/* @0x318108 .word 0xf7654620 */
/* @0x31810c strtmi lr, [r0], -r2, ror #16 */
/* @0x318110 svclt #0xbd10 */
/* @0x318114 .word 0xf013b538 */
/* @0x318118 strmi r0, [sp], -r1, lsl #6 */
/* @0x31811c svclt #0x89c04 */
/* @0x318120 .word 0xd1004618 */
/* @0x318124 stmdbmi sp, {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x318128 ldrbtmi r6, [r9], #-2240 */
/* @0x31812c .word 0xf0006809 */
/* @0x318130 stmdahs r0, {r0, r1, r3, r4, r8, r11, r12, sp, lr, pc} */
/* @0x318134 stmvs r8!, {r1, r2, r4, r5, r6, r7, r12, lr, pc} ^ */
/* @0x318138 stmdbmi r9, {r3, r5, r6, r8, r12, sp, pc} */
/* @0x31813c bmi 0x560d44 <g_SWFlineaavertbuff+0xdc7c> */
/* @0x318140 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x318144 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x318148 ldc2l p7, c15, [r12], #-1020 */
/* @0x31814c movwhs r11, #0x118 */
/* @0x318150 eorvc r2, r3, r1 */
/* @0x318154 andhs r11, r1, r8, lsr sp */
/* @0x318158 ldclt p0, c7, [r8, #-128]! */
/* @0x31815c andeq r9, sp, r6, ror #21 */
/* @0x318160 andeq r9, sp, r4, asr #21 */
/* @0x318164 ldrdeq r9, r10, [sp], -r0 */
/* @0x318168 ldrbmi r2, [r0, -r1]! */
/* @0x31816c ldrlt r4, [r0, #-0xb04] */
/* @0x318170 .word 0x4604447b */
/* @0x318174 andvs r3, r3, r8, lsl #6 */
/* @0x318178 .word 0xf8d2f7ff */
/* @0x31817c ldclt p6, c4, [r0, #-128] */
/* @0x318180 andeq r4, sp, r12, ror #30 */
/* @0x318184 .word 0x4604b510 */
/* @0x318188 .word 0xfff0f7ff */
/* @0x31818c .word 0xf7654620 */
/* @0x318190 strtmi lr, [r0], -r0, lsr #16 */
/* @0x318194 svclt #0xbd10 */
/* @0x318198 .word 0x4607b5f8 */
/* @0x31819c ldrmi r4, [r5], -lr, lsl #12 */
/* @0x3181a0 .word 0xf7ff461c */
/* @0x3181a4 .word 0xb108f8d3 */
/* @0x3181a8 ldcllt p0, c2, [r8, #4]! */
/* @0x3181ac .word 0x462368b8 */
/* @0x3181b0 qasxmi r4, r10, r1 */
/* @0x3181b4 stmdbvs r4!, {r2, r11, sp, lr} */
/* @0x3181b8 ldcllt p7, c4, [r8, #640]! */
/* @0x3181bc .word 0xf64cb508 */
/* @0x3181c0 .word 0xf6cd23b1 */
/* @0x3181c4 andhs r6, r0, #-1275068414 */
/* @0x3181c8 .word 0xf59e701a */
/* @0x3181cc svclt #0xed5e */
/* @0x3181d0 tstlt r0, r8, lsl #10 */
/* @0x3181d4 .word 0xf7ff4780 */
/* @0x3181d8 stmdami r5, {r0, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3181dc .word 0x47804478 */
/* @0x3181e0 .word 0xf7ffe7f9 */
/* @0x3181e4 .word 0xf7fffa9d */
/* @0x3181e8 .word 0xf7fffad7 */
/* @0x3181ec svclt #0xffe7 */
/* @0x3181f0 .word 0xffffffdd */
/* @0x3181f4 andhs r4, r0, #9216 */
/* @0x3181f8 .word 0xf3bf447b */
/* @0x3181fc ldmda r3, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^ */
/* @0x318200 bl 0x31be08 */
/* @0x318204 stmda r3, {r1, r8} ^ */
/* @0x318208 .word 0xf0901000 */
/* @0x31820c mvnsle r0, r0, lsl #30 */
/* @0x318210 andeq lr, r2, r1, lsr #23 */
/* @0x318214 svchi #0x5ff3bf */
/* @0x318218 svclt #0x4770 */
/* @0x31821c andseq r1, r6, r8, lsl #17 */
/* @0x318220 .word 0xb1684602 */
/* @0x318224 ldrbtmi r4, [r11], #-2824 */
/* @0x318228 svceq #0xe853 */
/* @0x31822c .word 0x2100e843 */
/* @0x318230 svceq #0xf091 */
/* @0x318234 .word 0xf3bfd1f8 */
/* @0x318238 .word 0xf3bf8f5f */
/* @0x31823c .word 0x47708f5f */
/* @0x318240 ldrbtmi r4, [r10], #-2562 */
/* @0x318244 svclt #0xe7ee */
/* @0x318248 andseq r1, r6, r10, asr r8 */
/* @0x31824c .word 0xffffff77 */
/* @0x318250 .word 0xf7ffb508 */
/* @0x318254 .word 0xf7ffffcf */
/* @0x318258 svclt #0xffbb */
/* @0x31825c .word 0xf7ffb508 */
/* @0x318260 svclt #0xfff7 */
/* @0x318264 andhs r4, r0, #9216 */
/* @0x318268 .word 0xf3bf447b */
/* @0x31826c ldmda r3, {r0, r1, r2, r3, r4, r6, r8, r9, r10, r11, pc} ^ */
/* @0x318270 bl 0x31be78 */
/* @0x318274 stmda r3, {r1, r8} ^ */
/* @0x318278 .word 0xf0901000 */
/* @0x31827c mvnsle r0, r0, lsl #30 */
/* @0x318280 andeq lr, r2, r1, lsr #23 */
/* @0x318284 svchi #0x5ff3bf */
/* @0x318288 svclt #0x4770 */
/* @0x31828c andseq r1, r6, r4, lsl r8 */
/* @0x318290 .word 0xb1684602 */
/* @0x318294 ldrbtmi r4, [r11], #-2824 */
/* @0x318298 svceq #0xe853 */
/* @0x31829c .word 0x2100e843 */
/* @0x3182a0 svceq #0xf091 */
/* @0x3182a4 .word 0xf3bfd1f8 */
/* @0x3182a8 .word 0xf3bf8f5f */
/* @0x3182ac .word 0x47708f5f */
/* @0x3182b0 ldrbtmi r4, [r10], #-2562 */
/* @0x3182b4 svclt #0xe7ee */
/* @0x3182b8 andseq r1, r6, r6, ror #15 */
/* @0x3182bc .word 0xffffff07 */
/* @0x3182c0 .word 0xf7ffb508 */
/* @0x3182c4 smlabtlt r0, pc, pc, pc */
/* @0x3182c8 .word 0xf7ff4780 */
/* @0x3182cc svclt #0xffc1 */
/* @0x3182d0 ldrbtmi r4, [r11], #-2818 */
/* @0x3182d4 andvs r3, r3, r8, lsl #6 */
/* @0x3182d8 svclt #0x4770 */
/* @0x3182dc andeq r4, sp, r2, asr lr */
/* @0x3182e0 ldrbtmi r4, [r8], #-2049 */
/* @0x3182e4 svclt #0x4770 */
/* @0x3182e8 andeq r4, r4, r2, lsr #6 */
/* @0x3182ec ldrbtmi r4, [r8], #-2049 */
/* @0x3182f0 svclt #0x4770 */
/* @0x3182f4 andeq r4, r4, r6, lsr #6 */
/* @0x3182f8 ldrlt r4, [r0, #-0xb04] */
/* @0x3182fc .word 0x4604447b */
/* @0x318300 andvs r3, r3, r8, lsl #6 */
/* @0x318304 svc #0x64f764 */
/* @0x318308 ldclt p6, c4, [r0, #-128] */
/* @0x31830c andeq r4, sp, r8, lsr #28 */
/* @0x318310 ldrlt r4, [r0, #-0xb04] */
/* @0x318314 .word 0x4604447b */
/* @0x318318 andvs r3, r3, r8, lsl #6 */
/* @0x31831c blx 0x1954326 <b2_toiTime+0x11fae82> */
/* @0x318320 ldclt p6, c4, [r0, #-128] */
/* @0x318324 strdeq r4, r5, [sp], -r8 */
/* @0x318328 .word 0x4604b510 */
/* @0x31832c .word 0xfff0f7ff */
/* @0x318330 .word 0xf7644620 */
/* @0x318334 strtmi lr, [r0], -lr, asr #30 */
/* @0x318338 svclt #0xbd10 */
/* @0x31833c ldrlt r4, [r0, #-0xb04] */
/* @0x318340 .word 0x4604447b */
/* @0x318344 andvs r3, r3, r8, lsl #6 */
/* @0x318348 blx 0x13d4352 <b2_toiTime+0xc7aeae> */
/* @0x31834c ldclt p6, c4, [r0, #-128] */
/* @0x318350 andeq r4, sp, r4, lsl #28 */
/* @0x318354 .word 0x4604b510 */
/* @0x318358 .word 0xfff0f7ff */
/* @0x31835c .word 0xf7644620 */
/* @0x318360 qasxmi lr, r0, r8 */
/* @0x318364 svclt #0xbd10 */
/* @0x318368 stmdavs r0, {r3, r8, r10, r12, sp, pc} ^ */
/* @0x31836c .word 0xf59e6849 */
/* @0x318370 .word 0xf1d0e902 */
/* @0x318374 svclt #0x380001 */
/* @0x318378 stclt p0, c2, [r8, #-0] */
/* @0x31837c .word 0xf7ffb508 */
/* @0x318380 .word 0xf080fff3 */
/* @0x318384 sbclt r0, r0, #1 */
/* @0x318388 svclt #0xbd08 */
/* @0x31838c stmdavs r0, {r3, r8, r10, r12, sp, pc} ^ */
/* @0x318390 .word 0xf59e6849 */
/* @0x318394 svceq #0xc0e8f0 */
/* @0x318398 svclt #0xbd08 */
/* @0x31839c .word 0x4604b510 */
/* @0x3183a0 blx 0x15d43aa <b2_toiTime+0xe7af06> */
/* @0x3183a4 strtmi r4, [r0], -r2, lsl #22 */
/* @0x3183a8 movwlo r4, #0x847b */
/* @0x3183ac ldclt p0, c6, [r0, #-140] */
/* @0x3183b0 muleq sp, r12, sp */
/* @0x3183b4 .word 0x4604b510 */
/* @0x3183b8 blx 0x12d43c2 <b2_toiTime+0xb7af1e> */
/* @0x3183bc strtmi r4, [r0], -r2, lsl #22 */
/* @0x3183c0 movwlo r4, #0x847b */
/* @0x3183c4 ldclt p0, c6, [r0, #-140] */
/* @0x3183c8 andeq r4, sp, r12, asr #26 */
/* @0x3183cc ldrbmi r2, [r0, -r2]! */
/* @0x3183d0 ldrlt r4, [r0, #-0xb04] */
/* @0x3183d4 .word 0x4604447b */
/* @0x3183d8 andvs r3, r3, r8, lsl #6 */
/* @0x3183dc .word 0xffa0f7fe */
/* @0x3183e0 ldclt p6, c4, [r0, #-128] */
/* @0x3183e4 andeq r4, sp, r0, lsr #27 */
/* @0x3183e8 .word 0x4604b510 */
/* @0x3183ec .word 0xfff0f7ff */
/* @0x3183f0 .word 0xf7644620 */
/* @0x3183f4 strtmi lr, [r0], -lr, ror #29 */
/* @0x3183f8 svclt #0xbd10 */
/* @0x3183fc svcmi #0xf0e92d */
/* @0x318400 strmi r11, [r5], -sp, lsl #1 */
/* @0x318404 swpls r4, r3, [r1] */
/* @0x318408 .word 0xf7fe461e */
/* @0x31840c stmdahs r0, {r0, r1, r2, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318410 addshi pc, r0, r0, asr #32 */
/* @0x318414 movwls r6, #0x28eb */
/* @0x318418 rsbsle r2, r1, r0, lsl #22 */
/* @0x31841c ssatmi r4, #0x9, r8, asr #22 */
/* @0x318420 strtmi r4, [pc], -r4, lsl #12 */
/* @0x318424 blmi 0x18fd038 <b2_toiTime+0x11a3b94> */
/* @0x318428 blmi 0x18fd040 <b2_toiTime+0x11a3b9c> */
/* @0x31842c blls 0x3fd048 <g_RomDisk+0x5828> */
/* @0x318430 movwls r4, #0x347b */
/* @0x318434 ldrbtmi r9, [r11], #-2820 */
/* @0x318438 blls 0x47d050 <targetStr+0x1e10> */
/* @0x31843c movwls r4, #0x547b */
/* @0x318440 ldrtmi r10, [r9], -r7, lsl #16 */
/* @0x318444 .word 0xff94f7fe */
/* @0x318448 sbceq lr, r4, #7168 */
/* @0x31844c .word 0x3000f8db */
/* @0x318450 .word 0xf8d86952 */
/* @0x318454 movwls r0, #0x6010 */
/* @0x318458 beq 0x394468 <ft_adobe_glyph_list+0x3b44> */
/* @0x31845c stmdbeq r0, {r1, r6, r7, r8, r9, r12, sp, lr, pc} ^ */
/* @0x318460 andsne r11, r2, #-1073741810 */
/* @0x318464 svceq #0xf1ba */
/* @0x318468 ldmdavs r9, {r0, r12, lr, pc} */
/* @0x31846c ldmne r11, {r1, r3, r7, r11, r12, lr} */
/* @0x318470 .word 0xf1b99306 */
/* @0x318474 .word 0xd1020f00 */
/* @0x318478 .word 0x07da68f3 */
/* @0x31847c stmdavs r5, {r1, r3, r4, r5, r8, r10, r12, lr, pc} */
/* @0x318480 stmdbls r1, {r1, r2, r9, r11, sp, pc} */
/* @0x318484 pushvs {r0, r1, r2, r8, r9, r11, sp, pc} */
/* @0x318488 stmdahs r0, {r3, r5, r7, r8, r9, r10, lr} */
/* @0x31848c .word 0xf1b9d032 */
/* @0x318490 .word 0xd1010f00 */
/* @0x318494 movwls r2, #0x7302 */
/* @0x318498 svceq #0xf1ba */
/* @0x31849c ldmdavs r1!, {r0, r2, r4, r5, r8, r12, lr, pc} ^ */
/* @0x3184a0 andsle r2, r12, r0, lsl #18 */
/* @0x3184a4 stmdahs r0, {r3, r11, r12, pc} */
/* @0x3184a8 .word 0xf7ffd050 */
/* @0x3184ac stmiblt r0, {r0, r1, r2, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3184b0 blhs 0x332784 */
/* @0x3184b4 ldmdavs r0!, {r0, r2, r3, r5, r12, lr, pc} ^ */
/* @0x3184b8 .word 0xf7ff9908 */
/* @0x3184bc stmdahs r0, {r0, r2, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x3184c0 ldmvs r3!, {r1, r3, r4, r5, r12, lr, pc} */
/* @0x3184c4 suble r2, sp, r0, lsl #22 */
/* @0x3184c8 bhs 0x33ecf4 */
/* @0x3184cc addsmi sp, r3, #74 */
/* @0x3184d0 andhs sp, r1, r0, lsl r0 */
/* @0x3184d4 eorsvs r2, r3, r2, lsl #6 */
/* @0x3184d8 pop {r0, r2, r3, r12, sp, pc} */
/* @0x3184dc blls 0x53c4a4 <obj_has_event+0x1934> */
/* @0x3184e0 eorsle r2, r3, r0, lsl #22 */
/* @0x3184e4 shadd16mi r2, r0, r1 */
/* @0x3184e8 .word 0xf59ea907 */
/* @0x3184ec ldmdavs r0!, {r3, r5, r6, r11, sp, lr, pc} */
/* @0x3184f0 suble r2, r0, r1, lsl #16 */
/* @0x3184f4 strlo r9, [r1], #-2818 */
/* @0x3184f8 stmdaeq r8, {r3, r8, r12, sp, lr, pc} */
/* @0x3184fc orrsle r4, pc, r3, lsr #5 */
/* @0x318500 andlo r6, r0, r0, lsr r8 */
/* @0x318504 andhs r11, r1, r8, lsl pc */
/* @0x318508 movwhs lr, #0x7e6 */
/* @0x31850c eorlo pc, r12, sp, lsl #17 */
/* @0x318510 blls 0x59242c <g_SWFlineaavertbuff+0x3f364> */
/* @0x318514 bicle r2, lr, r0, lsl #22 */
/* @0x318518 blhs 0x3375ec */
/* @0x31851c .word 0xf89dd1d9 */
/* @0x318520 blhs 0x3245d8 */
/* @0x318524 ldmdavs r0!, {r0, r2, r4, r6, r7, r8, r12, lr, pc} ^ */
/* @0x318528 .word 0xf7ff9908 */
/* @0x31852c stmdahs r0, {r0, r2, r3, r4, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318530 strb sp, [lr, r1, asr #1] */
/* @0x318534 strb r2, [pc, r1] */
/* @0x318538 orrhs r4, r10, r4, lsl r8 */
/* @0x31853c blmi 0x86ad94 <b2_toiTime+0x1118f0> */
/* @0x318540 ldrbtmi r4, [r10], #-1144 */
/* @0x318544 .word 0xf59e447b */
/* @0x318548 .word 0xe7baed32 */
/* @0x31854c .word 0x216f4812 */
/* @0x318550 blmi 0x7eada0 <b2_toiTime+0x918fc> */
/* @0x318554 ldrbtmi r4, [r10], #-1144 */
/* @0x318558 .word 0xf59e447b */
/* @0x31855c stmdals r8, {r3, r5, r8, r10, r11, sp, lr, pc} */
/* @0x318560 .word 0xe7a26871 */
/* @0x318564 orrhs r9, pc, r4, lsl #20 */
/* @0x318568 stmdals r3, {r0, r2, r8, r9, r11, r12, pc} */
/* @0x31856c ldc p5, c15, [lr, #-632] */
/* @0x318570 bls 0x572844 <g_SWFlineaavertbuff+0x1f77c> */
/* @0x318574 ldmvs r11!, {r0, r1, r3, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x318578 ldrtle r0, [r11], #2011 */
/* @0x31857c svclt #0xe7ac */
/* @0x318580 strdeq r4, r5, [r4], -r4 */
/* @0x318584 andeq sp, r8, lr, ror #2 */
/* @0x318588 andeq r4, r4, r8, lsr #5 */
/* @0x31858c andeq r4, r4, r4, ror #1 */
/* @0x318590 andeq sp, r8, r2, rrx */
/* @0x318594 andeq r4, r4, r4, ror r1 */
/* @0x318598 ldrdeq r4, r5, [r4], -r0 */
/* @0x31859c andeq sp, r8, lr, asr #32 */
/* @0x3185a0 andeq r4, r4, r4, lsr #2 */
/* @0x3185a4 .word 0xf000b41e */
/* @0x3185a8 .word 0xbc1ef867 */
/* @0x3185ac ldmda r8!, {r1, r12, sp, lr, pc} */
/* @0x3185b0 bl 0x1dd5c30 <b2_toiTime+0x167c78c> */
/* @0x3185b4 strdlt r11, r12, [r3], r0 */
/* @0x3185b8 ldcmi p8, c15, [r4], #-320 */
/* @0x3185bc subseq pc, r8, #0, #2 */
/* @0x3185c0 strmi r4, [lr], -r5, lsl #12 */
/* @0x3185c4 andls r4, r1, #32505856 */
/* @0x3185c8 eorle r2, r4, r0, lsl #24 */
/* @0x3185cc qadd16mi r4, r0, r4 */
/* @0x3185d0 movwhs r4, #0xa14 */
/* @0x3185d4 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x3185d8 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x3185dc blx 0xfd65e0 <b2_toiTime+0x87d13c> */
/* @0x3185e0 stcvs p1, c11, [r11, #800]! */
/* @0x3185e4 movwls r2, #0x1502 */
/* @0x3185e8 movweq pc, #0x11d4 */
/* @0x3185ec movwhs r11, #0xf38 */
/* @0x3185f0 svclt #0x82e00 */
/* @0x3185f4 movweq pc, #0x1043 */
/* @0x3185f8 strhs r11, [r0, #-0x11b] */
/* @0x3185fc andlt r4, r3, r8, lsr #12 */
/* @0x318600 ldmdavs r3!, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} */
/* @0x318604 qasxmi r4, r1, r0 */
/* @0x318608 ldmvs r11, {r0, r9, r11, sp, pc} */
/* @0x31860c .word 0xb1204798 */
/* @0x318610 eorsvs r9, r11, r1, lsl #22 */
/* @0x318614 strhs lr, [r1, #-0x7f2] */
/* @0x318618 strmi lr, [r5], -r6, ror #15 */
/* @0x31861c svclt #0xe7ee */
/* @0x318620 andeq r9, sp, r4, asr #12 */
/* @0x318624 andeq r9, sp, r4, lsr r6 */
/* @0x318628 .word 0x4606b570 */
/* @0x31862c .word 0xff58f7fe */
/* @0x318630 strmi lr, [r0, #-0x9d6] */
/* @0x318634 teqeq r8, r6, lsr #3 */
/* @0x318638 ldmib r3, {r0, r2, r3, r8, r9, sp, pc} ^ */
/* @0x31863c rsbmi r2, r2, r0, lsl #6 */
/* @0x318640 b 0x17a87f4 <b2_toiTime+0x104f350> */
/* @0x318644 svclt #0x180403 */
/* @0x318648 andle r6, r1, r1, lsl #1 */
/* @0x31864c ldcllt p0, c2, [r0, #-4]! */
/* @0x318650 .word 0x3c18f856 */
/* @0x318654 .word 0xf8463301 */
/* @0x318658 blhs 0x3676c0 <_ZTS12CDS_Priority+0x9718> */
/* @0x31865c stmvs r3, {r1, r8, r9, r10, r11, r12, sp, pc} */
/* @0x318660 .word 0x3c1cf846 */
/* @0x318664 andhs r6, r1, r1, lsl #1 */
/* @0x318668 svclt #0xbd70 */
/* @0x31866c andhi pc, r0, pc, lsr #7 */
/* @0x318670 .word 0x432b2b00 */
/* @0x318674 strbmi r5, [lr, -r3, asr #10] */
/* @0x318678 .word 0xf7feb538 */
/* @0x31867c stmvs r1, {r0, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318680 ldmib r1, {r0, r3, r6, r7, r8, r12, sp, pc} ^ */
/* @0x318684 movwge r4, #0xe50e */
/* @0x318688 movwhs lr, #0x9d3 */
/* @0x31868c rsbmi r4, r11, r2, rrx */
/* @0x318690 streq lr, [r3], #-2642 */
/* @0x318694 movwhs sp, #0x4 */
/* @0x318698 .word 0xf1016083 */
/* @0x31869c ldclt p0, c0, [r8, #-224]! */
/* @0x3186a0 bllo 0x372ed4 <_ZTS13C_UTF16String+0x9f80> */
/* @0x3186a4 blhs 0x330ed8 */
/* @0x3186a8 stmibvs r10, {r0, r1, r2, r4, r5, r6, r7, r8, r12, lr, pc} ^ */
/* @0x3186ac .word 0xf1016082 */
/* @0x3186b0 bicvs r0, r11, r8, lsr r0 */
/* @0x3186b4 .word 0xf7ffbd38 */
/* @0x3186b8 svclt #0xfdcb */
/* @0x3186bc andhi pc, r0, pc, lsr #7 */
/* @0x3186c0 .word 0x432b2b00 */
/* @0x3186c4 strbmi r5, [lr, -r3, asr #10] */
/* @0x3186c8 svcmi #0xf0e92d */
/* @0x3186cc teqge r10, #4, #12 */
/* @0x3186d0 movwhs lr, #0x9d3 */
/* @0x3186d4 ldmib r0, {r0, r1, r7, r12, sp, pc} ^ */
/* @0x3186d8 cdpmi p1, #0x3, c0, c9, c0, #0x0 */
/* @0x3186dc submi r4, r11, r2, asr #32 */
/* @0x3186e0 qaddeq lr, r2, r3 */
/* @0x3186e4 qsub16mi r4, r0, lr */
/* @0x3186e8 .word 0xf7ffd003 */
/* @0x3186ec .word 0xf7fff819 */
/* @0x3186f0 .word 0xf8d4fde7 */
/* @0x3186f4 blvs 0xc7879c <b2_toiTime+0x51f2f8> */
/* @0x3186f8 .word 0xf7ff6b67 */
/* @0x3186fc .word 0xf854f811 */
/* @0x318700 ldrmi r3, [r8, r12, lsr #24] */
/* @0x318704 stc2 p7, c15, [r4, #1020]! */
/* @0x318708 .word 0xf80af7ff */
/* @0x31870c stc2 p7, c15, [r0, #1020]! */
/* @0x318710 .word 0xf806f7ff */
/* @0x318714 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc} */
/* @0x318718 bleq 0x4147b4 <g_RomDisk+0x1cf94> */
/* @0x31871c strbmi r4, [r1, #0x6ca] */
/* @0x318720 ldrtmi sp, [r8], -r10, lsr #32 */
/* @0x318724 blx 0x6d6728 <g_SWFvertbuff+0x3660> */
/* @0x318728 .word 0xf7fe4605 */
/* @0x31872c .word 0x4629fed9 */
/* @0x318730 stmdavs r3, {r9, sp} */
/* @0x318734 eorseq pc, r8, r3, lsl #2 */
/* @0x318738 movwls r3, #0x390 */
/* @0x31873c .word 0xf7ff466b */
/* @0x318740 ldmiblt r8, {r0, r3, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc} */
/* @0x318744 stmdavs r11!, {r0, r1, r2, r3, r4, r9, r11, lr} */
/* @0x318748 strtmi r9, [r8], -r1 */
/* @0x31874c bge 0x36ea18 <_ZTS13C_UTF16String+0x5ac4> */
/* @0x318750 .word 0x4798689b */
/* @0x318754 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc} */
/* @0x318758 svclt #0x182800 */
/* @0x31875c beq 0x3948a0 <ft_adobe_glyph_list+0x3f7c> */
/* @0x318760 .word 0xe7dc445f */
/* @0x318764 .word 0xf818f7ff */
/* @0x318768 .word 0xff1cf7ff */
/* @0x31876c .word 0xffb4f7fe */
/* @0x318770 .word 0xf812f7ff */
/* @0x318774 .word 0xff16f7ff */
/* @0x318778 svceq #0xf1ba */
/* @0x31877c .word 0xf7ffd010 */
/* @0x318780 .word 0xf7fff80b */
/* @0x318784 andhs pc, r4, r9, lsl #16 */
/* @0x318788 .word 0xff4cf7fe */
/* @0x31878c .word 0xf0004604 */
/* @0x318790 blmi 0x656d04 <g_SWFlinevertbuff+0x3c3c> */
/* @0x318794 ldmpl r1!, {r5, r9, r10, lr} ^ */
/* @0x318798 ldmpl r2!, {r0, r1, r3, r8, r9, r11, lr} ^ */
/* @0x31879c .word 0xff80f7fe */
/* @0x3187a0 stclo p8, c15, [r8], #-336 */
/* @0x3187a4 .word 0xf59e4798 */
/* @0x3187a8 .word 0xf7feea70 */
/* @0x3187ac .word 0xf59effb9 */
/* @0x3187b0 .word 0xf7feea6c */
/* @0x3187b4 .word 0xe7dbfff1 */
/* @0x3187b8 .word 0x432b2b00 */
/* @0x3187bc strbmi r5, [lr, -r3, asr #10] */
/* @0x3187c0 andeq r9, sp, r0, ror r5 */
/* @0x3187c4 .word 0xffffffc8 */
/* @0x3187c8 .word 0xffffffcc */
/* @0x3187cc andhi pc, r0, pc, lsr #7 */
/* @0x3187d0 movwhs r11, #0x430 */
/* @0x3187d4 ldrmi r6, [r9], -r4, lsl #16 */
/* @0x3187d8 blhs 0x396830 <ft_adobe_glyph_list+0x5f0c> */
/* @0x3187dc ldrbeq pc, [pc, #-0x2]! */
/* @0x3187e0 movwlo r4, #0x709d */
/* @0x3187e4 b 0x135a034 <b2_toiTime+0xc00b90> */
/* @0x3187e8 ldrbtle r0, [r5], #261 */
/* @0x3187ec strmi r6, [r8], -r4 */
/* @0x3187f0 .word 0x4770bc30 */
/* @0x3187f4 movwhs r11, #0x430 */
/* @0x3187f8 ldrmi r6, [r9], -r4, lsl #16 */
/* @0x3187fc blhs 0x396854 <ft_adobe_glyph_list+0x5f30> */
/* @0x318800 ldrbeq pc, [pc, #-0x2]! */
/* @0x318804 movwlo r4, #0x709d */
/* @0x318808 svceq #0x80f012 */
/* @0x31880c .word 0x0105ea41 */
/* @0x318810 blhs 0xb0cfe8 <b2_toiTime+0x3b3b44> */
/* @0x318814 svclt #0x8c6004 */
/* @0x318818 strhs r2, [r1, #-0x500] */
/* @0x31881c ldrne lr, [r2, #0xa15] */
/* @0x318820 .word 0xf04fd004 */
/* @0x318824 blx 0x7a5428 <b2_toiTime+0x4bf84> */
/* @0x318828 tstmi r9, #201326592 */
/* @0x31882c ldclt p6, c4, [r0], #-32 */
/* @0x318830 svclt #0x4770 */
/* @0x318834 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r11, sp} */
/* @0x318838 .word 0x46064ff0 */
/* @0x31883c strmi r11, [sp], -r9, lsl #1 */
/* @0x318840 sbchi pc, r3, r0 */
/* @0x318844 .word 0xf0016804 */
/* @0x318848 strls r0, [r7], #-783 */
/* @0x31884c ldmdale r10, {r2, r3, r8, r9, r11, sp} */
/* @0x318850 .word 0xf003e8df */
/* @0x318854 ldrbeq r6, [sp, -r7, lsl #30]! */
/* @0x318858 ldmdbne r9, {r0, r2, r3, r5, r8, r11, r12} */
/* @0x31885c .word 0x07676319 */
/* @0x318860 stmvc r0!, {r0, r2, r7} */
/* @0x318864 stmdavc r1!, {r1, r5, r8, r10, r11, r12} ^ */
/* @0x318868 .word 0xf8947823 */
/* @0x31886c streq r10, [r0], #-3 */
/* @0x318870 andhs lr, r1, r0, asr #20 */
/* @0x318874 tstmi r8, #1879048192 */
/* @0x318878 andvs lr, r10, r0, asr #20 */
/* @0x31887c cmneq r0, #21 */
/* @0x318880 blhs 0x74c8b4 <g_SWFvertbuff+0x797ec> */
/* @0x318884 .word 0xf59ed001 */
/* @0x318888 stmdblt r0!, {r9, r11, sp, lr, pc} */
/* @0x31888c eorsvs r9, r3, r7, lsl #22 */
/* @0x318890 pop {r0, r3, r12, sp, pc} */
/* @0x318894 ldmdavs r3!, {r4, r5, r6, r7, r8, r9, r10, r11, pc} */
/* @0x318898 stmibeq sp!, {r3, r4, r11, r12} ^ */
/* @0x31889c svclt #0xc2800 */
/* @0x3188a0 .word 0xf0052500 */
/* @0x3188a4 stchs p5, c0, [r0, #-4] */
/* @0x3188a8 stmdavs r0, {r4, r5, r6, r7, r12, lr, pc} */
/* @0x3188ac stmdbvc r0!, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc} */
/* @0x3188b0 stmdavc r2!, {r0, r5, r11, r12, sp, lr} ^ */
/* @0x3188b4 andls r7, r5, r3, lsr #17 */
/* @0x3188b8 b 0x16f6f40 <b2_toiTime+0xf9da9c> */
/* @0x3188bc .word 0x91022802 */
/* @0x3188c0 mrsls r2, apsr */
/* @0x3188c4 bmi 0x413208 <g_RomDisk+0x1b9e8> */
/* @0x3188c8 b 0x153c8d4 <b2_toiTime+0xde3430> */
/* @0x3188cc ldmib sp, {r1, r3, r9} ^ */
/* @0x3188d0 movwhs r0, #0x102 */
/* @0x3188d4 mulgt r3, r4, r8 */
/* @0x3188d8 b 0x13bd4f0 <b2_toiTime+0xc6404c> */
/* @0x3188dc stmdbvc r7!, {r9, r11} ^ */
/* @0x3188e0 movwhs lr, #0x49dd */
/* @0x3188e4 stmdavs r12, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x3188e8 b 0x15be8f4 <b2_toiTime+0xe65450> */
/* @0x3188ec eorseq r0, pc, #8, #20 */
/* @0x3188f0 andls r9, r2, #786432 */
/* @0x3188f4 stmdbmi r0, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x3188f8 andeq lr, r2, r10, asr #20 */
/* @0x3188fc movwhs lr, #0x29dd */
/* @0x318900 .word 0xf8942300 */
/* @0x318904 strlo r12, [r8], #-7 */
/* @0x318908 .word 0x46984310 */
/* @0x31890c .word 0x469a4318 */
/* @0x318910 blvs 0x653254 <g_SWFlinevertbuff+0x18c> */
/* @0x318914 strls r4, [r7], #-792 */
/* @0x318918 stmdage r7, {r4, r5, r7, r8, r9, r10, sp, lr, pc} */
/* @0x31891c .word 0xff6af7ff */
/* @0x318920 stmdavc r0!, {r2, r3, r5, r7, r8, r9, r10, sp, lr, pc} ^ */
/* @0x318924 bllo 0x3d697c <error_g0017+0x2f620> */
/* @0x318928 andhs lr, r0, r3, asr #20 */
/* @0x31892c andlt r9, r0, #117440512 */
/* @0x318930 movwhs lr, #0x7a4 */
/* @0x318934 .word 0xf8144618 */
/* @0x318938 .word 0xf0022b01 */
/* @0x31893c addsmi r0, r9, pc, ror r1 */
/* @0x318940 ldreq r3, [r2], -r7, lsl #6 */
/* @0x318944 andeq lr, r1, r0, asr #20 */
/* @0x318948 strls sp, [r7], #-1269 */
/* @0x31894c qadd8mi lr, r3, r6 */
/* @0x318950 .word 0xf8137860 */
/* @0x318954 b 0x13a3564 <b2_toiTime+0xc4a0c0> */
/* @0x318958 movwls r2, #0x7000 */
/* @0x31895c stmdbvc r0!, {r1, r2, r3, r7, r8, r9, r10, sp, lr, pc} */
/* @0x318960 stmdavc r2!, {r0, r5, r11, r12, sp, lr} ^ */
/* @0x318964 andls r7, r5, r3, lsr #17 */
/* @0x318968 b 0x16f6ff0 <b2_toiTime+0xf9db4c> */
/* @0x31896c .word 0x91022802 */
/* @0x318970 mrsls r2, apsr */
/* @0x318974 bmi 0x4132b8 <g_RomDisk+0x1ba98> */
/* @0x318978 b 0x153c984 <b2_toiTime+0xde34e0> */
/* @0x31897c ldmib sp, {r1, r3, r9} ^ */
/* @0x318980 movwhs r0, #0x102 */
/* @0x318984 mulgt r3, r4, r8 */
/* @0x318988 b 0x13bd5a0 <b2_toiTime+0xc640fc> */
/* @0x31898c stmdbvc r7!, {r9, r11} ^ */
/* @0x318990 movwhs lr, #0x49dd */
/* @0x318994 stmdavs r12, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x318998 b 0x15be9a4 <b2_toiTime+0xe65500> */
/* @0x31899c eorseq r0, pc, #8, #20 */
/* @0x3189a0 andls r9, r2, #786432 */
/* @0x3189a4 stmdbmi r0, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} */
/* @0x3189a8 andeq lr, r2, r10, asr #20 */
/* @0x3189ac movwhs lr, #0x29dd */
/* @0x3189b0 .word 0xf8942300 */
/* @0x3189b4 strlo r12, [r8], #-7 */
/* @0x3189b8 .word 0x46984310 */
/* @0x3189bc .word 0x469a4318 */
/* @0x3189c0 blvs 0x653304 <g_SWFlinevertbuff+0x23c> */
/* @0x3189c4 strls r4, [r7], #-792 */
/* @0x3189c8 andhs lr, r0, r8, asr r7 */
/* @0x3189cc svclt #0xe760 */
/* @0x3189d0 ldrbtmi r4, [r11], #-2818 */
/* @0x3189d4 andvs r3, r3, r8, lsl #6 */
/* @0x3189d8 svclt #0x4770 */
/* @0x3189dc andeq r4, sp, r2, lsl #16 */
/* @0x3189e0 ldrbtmi r4, [r8], #-2049 */
/* @0x3189e4 svclt #0x4770 */
/* @0x3189e8 andeq r3, r4, r2, lsr sp */
/* @0x3189ec ldrbtmi r4, [r11], #-2818 */
/* @0x3189f0 andvs r3, r3, r8, lsl #6 */
/* @0x3189f4 svclt #0x4770 */
/* @0x3189f8 andeq r4, sp, r6, ror #15 */
/* @0x3189fc ldrbtmi r4, [r8], #-2049 */
/* @0x318a00 svclt #0x4770 */
/* @0x318a04 andeq r3, r4, r6, lsr #26 */
/* @0x318a08 ldrlt r4, [r0, #-0xb04] */
/* @0x318a0c .word 0x4604447b */
/* @0x318a10 andvs r3, r3, r8, lsl #6 */
/* @0x318a14 bl 0xffa567ac <b2_toiTime+0xffffffffff2fd308> */
/* @0x318a18 ldclt p6, c4, [r0, #-128] */
/* @0x318a1c andeq r4, sp, r8, asr #15 */
/* @0x318a20 ldrlt r4, [r0, #-0xb04] */
/* @0x318a24 .word 0x4604447b */
/* @0x318a28 andvs r3, r3, r8, lsl #6 */
/* @0x318a2c bl 0xff7567c4 <b2_toiTime+0xfffffffffeffd320> */
/* @0x318a30 ldclt p6, c4, [r0, #-128] */
/* @0x318a34 strheq r4, [sp], -r0 */
/* @0x318a38 ldrbtmi r4, [r11], #-2818 */
/* @0x318a3c andvs r3, r3, r8, lsl #6 */
/* @0x318a40 svclt #0x4770 */
/* @0x318a44 muleq sp, r10, r7 */
/* @0x318a48 ldrbtmi r4, [r11], #-2818 */
/* @0x318a4c andvs r3, r3, r8, lsl #6 */
/* @0x318a50 svclt #0x4770 */
/* @0x318a54 andeq r4, sp, r2, ror #14 */
/* @0x318a58 .word 0xf7feb508 */
/* @0x318a5c stmdavs r0, {r0, r6, r8, r10, r11, r12, sp, lr, pc} ^ */
/* @0x318a60 svclt #0x183000 */
/* @0x318a64 stclt p0, c2, [r8, #-4] */
/* @0x318a68 ldrbmi r2, [r0, -r0]! */
/* @0x318a6c ldrlt r4, [r0, #-0xb04] */
/* @0x318a70 .word 0x4604447b */
/* @0x318a74 andvs r3, r3, r8, lsl #6 */
/* @0x318a78 stc2 p7, c15, [r12, #-1016] */
/* @0x318a7c ldclt p6, c4, [r0, #-128] */
/* @0x318a80 andeq r4, sp, r12, ror r7 */
/* @0x318a84 .word 0x4604b510 */
/* @0x318a88 .word 0xfff0f7ff */
/* @0x318a8c .word 0xf7644620 */
/* @0x318a90 strtmi lr, [r0], -r0, lsr #23 */
/* @0x318a94 svclt #0xbd10 */
/* @0x318a98 stcllt p7, c15, [r6], #-1020 */
/* @0x318a9c ldrlt r4, [r0, #-0xb04] */
/* @0x318aa0 .word 0x4604447b */
/* @0x318aa4 andvs r3, r3, r8, lsl #6 */
/* @0x318aa8 ldc2l p7, c15, [r4], #1016 */
/* @0x318aac ldclt p6, c4, [r0, #-128] */
/* @0x318ab0 andeq r4, sp, r12, lsl #22 */
/* @0x318ab4 .word 0x4604b510 */
/* @0x318ab8 .word 0xfff0f7ff */
/* @0x318abc .word 0xf7644620 */
/* @0x318ac0 strtmi lr, [r0], -r8, lsl #23 */
/* @0x318ac4 svclt #0xbd10 */
/* @0x318ac8 ldrlt r4, [r0, #-0xb04] */
/* @0x318acc .word 0x4604447b */
/* @0x318ad0 andvs r3, r3, r8, lsl #6 */
/* @0x318ad4 ldc2l p7, c15, [lr], {254} */
/* @0x318ad8 ldclt p6, c4, [r0, #-128] */
/* @0x318adc andeq r4, sp, r8, lsl #22 */
/* @0x318ae0 .word 0x4604b510 */
/* @0x318ae4 .word 0xfff0f7ff */
/* @0x318ae8 .word 0xf7644620 */
/* @0x318aec qsub16mi lr, r0, r2 */
/* @0x318af0 svclt #0xbd10 */
/* @0x318af4 movwhs r11, #0x1538 */
/* @0x318af8 strmi r6, [r12], -r5, lsl #16 */
/* @0x318afc strmi r6, [r8, sp, ror #17]! */
/* @0x318b00 andhs r11, r1, r8, lsl #2 */
/* @0x318b04 stmdbmi r4, {r3, r4, r5, r8, r10, r11, r12, sp, pc} */
/* @0x318b08 ldrbtmi r4, [r9], #-1568 */
/* @0x318b0c pop {r0, r3, r11, sp, lr} */
/* @0x318b10 .word 0xf7ff4038 */
/* @0x318b14 svclt #0xbc29 */
/* @0x318b18 andeq r9, sp, r10, lsl r1 */
/* @0x318b1c mvnsmi lr, sp, lsr #18 */
/* @0x318b20 stmdavs r7, {r2, r7, r12, sp, pc} */
/* @0x318b24 .word 0xf10d4698 */
/* @0x318b28 movwls r0, #0x30f */
/* @0x318b2c strmi r4, [r4], -r3, asr #12 */
/* @0x318b30 .word 0x460e693f */
/* @0x318b34 .word 0x47b84615 */
/* @0x318b38 .word 0xf89d4603 */
/* @0x318b3c stmiblt r3, {r0, r1, r2, r3} */
/* @0x318b40 orrlt r6, r12, r4, ror #17 */
/* @0x318b44 strtmi r4, [r0], -r12, lsl #18 */
/* @0x318b48 ldrbtmi r4, [r9], #-2572 */
/* @0x318b4c ldrbtmi r6, [r10], #-2057 */
/* @0x318b50 .word 0xff78f7fe */
/* @0x318b54 stmdavs r4, {r6, r8, r12, sp, pc} */
/* @0x318b58 ldmvs r1!, {r1, r3, r5, r9, r10, lr} ^ */
/* @0x318b5c stmvs r4!, {r0, r1, r6, r9, r10, lr} ^ */
/* @0x318b60 andlt r4, r4, r0, lsr #15 */
/* @0x318b64 ldrhhi lr, [r0, #141]! */
/* @0x318b68 strtmi r6, [r0], -r3, lsr #16 */
/* @0x318b6c qsub8mi r6, r10, r1 */
/* @0x318b70 .word 0x4798689b */
/* @0x318b74 svclt #0xe7f5 */
/* @0x318b78 strheq r9, [sp], -r10 */
/* @0x318b7c andeq r4, sp, r6, lsr #21 */
/* @0x318b80 mvnsmi lr, sp, lsr #18 */
/* @0x318b84 strmi r4, [r12], -r5, lsl #12 */
/* @0x318b88 .word 0x46984616 */
/* @0x318b8c blx 0xffe56b92 <b2_toiTime+0xffffffffff6fd6ee> */
/* @0x318b90 stmdahs r0, {r0, r1, r2, r9, r10, lr} */
/* @0x318b94 stmdavs r11!, {r1, r2, r5, r8, r12, lr, pc} */
/* @0x318b98 .word 0x0c04f853 */
/* @0x318b9c eorle r2, r9, r0, lsl #24 */
/* @0x318ba0 .word 0xf8536823 */
/* @0x318ba4 .word 0xf7ff1c04 */
/* @0x318ba8 stmiblt r0, {r0, r3, r5, r6, r7, r8, r9, r11, r12, sp, lr, pc} ^ */
/* @0x318bac stmvs r7!, {r0, r1, r3, r5, r7, r11, sp, lr} */
/* @0x318bb0 andeq lr, r3, #225280 */
/* @0x318bb4 .word 0xf1b8d114 */
/* @0x318bb8 andsle r0, r6, r1, lsl #30 */
/* @0x318bbc svceq #0x4f018 */
/* @0x318bc0 streq pc, [r1, -r8, lsr #32] */
/* @0x318bc4 bfieq sp, r3, #2, #26 */
/* @0x318bc8 svclt #0x584628 */
/* @0x318bcc streq pc, [r4, -r7, asr #32] */
/* @0x318bd0 ldrtmi r4, [r2], -r1, lsr #12 */
/* @0x318bd4 pop {r0, r1, r3, r4, r5, r9, r10, lr} */
/* @0x318bd8 .word 0xf7ff41f0 */
/* @0x318bdc shadd8mi r11, r8, pc */
/* @0x318be0 ldrhhi lr, [r0, #141]! */
/* @0x318be4 pop {r0, sp} */
/* @0x318be8 .word 0x270381f0 */
/* @0x318bec ldrmi lr, [r0], -r11, ror #15 */
/* @0x318bf0 ldrhhi lr, [r0, #141]! */
/* @0x318bf4 .word 0xf814f000 */
/* @0x318bf8 andhs r11, r4, r0, lsl r5 */
/* @0x318bfc ldc2 p7, c15, [r2, #-1016] */
/* @0x318c00 .word 0xf7ff4604 */
/* @0x318c04 stmdbmi r4, {r0, r1, r3, r6, r7, r8, r9, r11, r12, sp, lr, pc} */
/* @0x318c08 bmi 0x42a490 <g_RomDisk+0x32c70> */
/* @0x318c0c stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x318c10 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x318c14 stc2l p7, c15, [r4, #-1016] */
/* @0x318c18 andeq r9, sp, r12, lsl r0 */
/* @0x318c1c andeq r9, sp, r12, lsl r0 */
/* @0x318c20 andhs r11, r4, r0, lsl r5 */
/* @0x318c24 ldc2l p7, c15, [lr], #1016 */
/* @0x318c28 .word 0xf7ff4604 */
/* @0x318c2c stmdbmi r4, {r0, r1, r6, r7, r8, r9, r11, r12, sp, lr, pc} */
/* @0x318c30 bmi 0x42a4b8 <g_RomDisk+0x32c98> */
/* @0x318c34 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr} */
/* @0x318c38 ldmdavs r2, {r1, r3, r4, r5, r6, r10, lr} */
/* @0x318c3c ldc2 p7, c15, [r0, #-1016]! */
/* @0x318c40 strdeq r8, r9, [sp], -r12 */
/* @0x318c44 strdeq r8, r9, [sp], -r12 */

/* ── FUNC 0x316e91 · FT_Stream_OpenLZW · size=196 · insn=0 */

/* ── FUNC 0x316f55 · ft_lzwstate_done · size=58 · insn=0 */

/* ── FUNC 0x316fb5 · ft_lzwstate_io · size=602 · insn=0 */

/* ── FUNC 0x317f81 · __gxx_personality_v0 · size=360 · insn=0 */

/* ── FUNC 0x3185b5 · __cxa_type_match · size=116 · insn=0 */

/* ── FUNC 0x318629 · __cxa_begin_cleanup · size=80 · insn=0 */

/* ── FUNC 0x3186c9 · __cxa_call_unexpected · size=260 · insn=0 */

/* ── FUNC 0x318c48 · __udivsi3 · size=168 · insn=42 */
/* @0x318c48 subs r2, r1, #1 */
/* @0x318c4c bxeq lr */
/* @0x318c50 blo 0x318ce4 <__udivsi3+0x9c> */
/* @0x318c54 cmp r0, r1 */
/* @0x318c58 bls 0x318cc8 <__udivsi3+0x80> */
/* @0x318c5c tst r1, r2 */
/* @0x318c60 beq 0x318cd4 <__udivsi3+0x8c> */
/* @0x318c64 clz r3, r1 */
/* @0x318c68 clz r2, r0 */
/* @0x318c6c sub r2, r3, r2 */
/* @0x318c70 mov r3, #1 */
/* @0x318c74 lsl r1, r1, r2 */
/* @0x318c78 lsl r3, r3, r2 */
/* @0x318c7c mov r2, #0 */
/* @0x318c80 cmp r0, r1 */
/* @0x318c84 subhs r0, r0, r1 */
/* @0x318c88 orrhs r2, r2, r3 */
/* @0x318c8c cmp r0, r1, lsr #1 */
/* @0x318c90 subhs r0, r0, r1, lsr #1 */
/* @0x318c94 orrhs r2, r2, r3, lsr #1 */
/* @0x318c98 cmp r0, r1, lsr #2 */
/* @0x318c9c subhs r0, r0, r1, lsr #2 */
/* @0x318ca0 orrhs r2, r2, r3, lsr #2 */
/* @0x318ca4 cmp r0, r1, lsr #3 */
/* @0x318ca8 subhs r0, r0, r1, lsr #3 */
/* @0x318cac orrhs r2, r2, r3, lsr #3 */
/* @0x318cb0 cmp r0, #0 */
/* @0x318cb4 lsrsne r3, r3, #4 */
/* @0x318cb8 lsrne r1, r1, #4 */
/* @0x318cbc bne 0x318c80 <__udivsi3+0x38> */
/* @0x318cc0 mov r0, r2 */
/* @0x318cc4 bx lr */
/* @0x318cc8 moveq r0, #1 */
/* @0x318ccc movne r0, #0 */
/* @0x318cd0 bx lr */
/* @0x318cd4 clz r2, r1 */
/* @0x318cd8 rsb r2, r2, #31 */
/* @0x318cdc lsr r0, r0, r2 */
/* @0x318ce0 bx lr */
/* @0x318ce4 cmp r0, #0 */
/* @0x318ce8 mvnne r0, #0 */
/* @0x318cec b 0x319458 <__aeabi_ldiv0> */

/* ── FUNC 0x318cf0 · __aeabi_uidivmod · size=32 · insn=8 */
/* @0x318cf0 cmp r1, #0 */
/* @0x318cf4 beq 0x318ce4 <__udivsi3+0x9c> */
/* @0x318cf8 push {r0, r1, lr} */
/* @0x318cfc bl 0x318c48 <__udivsi3> */
/* @0x318d00 pop {r1, r2, lr} */
/* @0x318d04 mul r3, r2, r0 */
/* @0x318d08 sub r1, r1, r3 */
/* @0x318d0c bx lr */

/* ── FUNC 0x318d10 · __divsi3 · size=220 · insn=55 */
/* @0x318d10 cmp r1, #0 */
/* @0x318d14 beq 0x318ddc <__divsi3+0xcc> */
/* @0x318d18 eor r12, r0, r1 */
/* @0x318d1c rsbmi r1, r1, #0 */
/* @0x318d20 subs r2, r1, #1 */
/* @0x318d24 beq 0x318da8 <__divsi3+0x98> */
/* @0x318d28 movs r3, r0 */
/* @0x318d2c rsbmi r3, r0, #0 */
/* @0x318d30 cmp r3, r1 */
/* @0x318d34 bls 0x318db4 <__divsi3+0xa4> */
/* @0x318d38 tst r1, r2 */
/* @0x318d3c beq 0x318dc4 <__divsi3+0xb4> */
/* @0x318d40 clz r2, r1 */
/* @0x318d44 clz r0, r3 */
/* @0x318d48 sub r0, r2, r0 */
/* @0x318d4c mov r2, #1 */
/* @0x318d50 lsl r1, r1, r0 */
/* @0x318d54 lsl r2, r2, r0 */
/* @0x318d58 mov r0, #0 */
/* @0x318d5c cmp r3, r1 */
/* @0x318d60 subhs r3, r3, r1 */
/* @0x318d64 orrhs r0, r0, r2 */
/* @0x318d68 cmp r3, r1, lsr #1 */
/* @0x318d6c subhs r3, r3, r1, lsr #1 */
/* @0x318d70 orrhs r0, r0, r2, lsr #1 */
/* @0x318d74 cmp r3, r1, lsr #2 */
/* @0x318d78 subhs r3, r3, r1, lsr #2 */
/* @0x318d7c orrhs r0, r0, r2, lsr #2 */
/* @0x318d80 cmp r3, r1, lsr #3 */
/* @0x318d84 subhs r3, r3, r1, lsr #3 */
/* @0x318d88 orrhs r0, r0, r2, lsr #3 */
/* @0x318d8c cmp r3, #0 */
/* @0x318d90 lsrsne r2, r2, #4 */
/* @0x318d94 lsrne r1, r1, #4 */
/* @0x318d98 bne 0x318d5c <__divsi3+0x4c> */
/* @0x318d9c cmp r12, #0 */
/* @0x318da0 rsbmi r0, r0, #0 */
/* @0x318da4 bx lr */
/* @0x318da8 teq r12, r0 */
/* @0x318dac rsbmi r0, r0, #0 */
/* @0x318db0 bx lr */
/* @0x318db4 movlo r0, #0 */
/* @0x318db8 asreq r0, r12, #31 */
/* @0x318dbc orreq r0, r0, #1 */
/* @0x318dc0 bx lr */
/* @0x318dc4 clz r2, r1 */
/* @0x318dc8 rsb r2, r2, #31 */
/* @0x318dcc cmp r12, #0 */
/* @0x318dd0 lsr r0, r3, r2 */
/* @0x318dd4 rsbmi r0, r0, #0 */
/* @0x318dd8 bx lr */
/* @0x318ddc cmp r0, #0 */
/* @0x318de0 mvngt r0, #-2147483648 */
/* @0x318de4 movlt r0, #-2147483648 */
/* @0x318de8 b 0x319458 <__aeabi_ldiv0> */
