/* cally 逆向卡：All_23 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 2 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/2 anon_30a7b2  0x30a7b2  size 41480  7205 条（0x30a7b2..0x3149ba）｜其中 3165 条已由别的卡落锚，本节不再重复
 * @func 0x30a7b2 0x3149ba  size 41480  7205 条
 * 部分覆盖: 本节 7205/10370 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0x20a487a / 0xb2882e / 0xff248bbe / 0x3d2934 / 0x386d8a / 0xff70895c / 0x1fcd18a / 0xff0f6dba
 * 字段偏移 top8: 0xc×8 / 0x6×8 / 0x18×7 / 0xa×6 / 0x1×5 / 0x4×4 / 0xe×3 / 0x8×3
 * VFP 指令 65 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x30a7b2 .word 0xe92d0000
 *   @0x30a7b6 .word 0xf5ad4ff0
 *   @0x30a7ba addslt r4, r11, r4, lsr #27
 *   @0x30a7be svcge #0x1a4604
 *   @0x30a7c2 .word 0x8064f8d1
 *   @0x30a7c6 ldrbeq pc, [r4, #-0x1a7]
 *   @0x30a7ca .word 0xf640460e
 *   @0x30a7ce smlabths r0, r8, r2, r2
 *   @0x30a7d2 .word 0xf04f4628
 *   @0x30a7d6 .word 0xf5ab0b00
 *   @0x30a7da .word 0xf504eeea
 *   @0x30a7de .word 0xf8c453e2
 *   @0x30a7e2 shasxmi r11, r0, r4
 *   @0x30a7e6 andslt pc, r4, r3, asr #17
 *   @0x30a7ea blmi 0x20a487a <b2_toiTime+0x194b3d6>
 *   @0x30a7ee mrrchi p8, #0x4, pc, r4, c7
 *   @0x30a7f2 ldrbtmi r6, [r11], #-2194
 *   @0x30a7f6 .word 0xf853681b
 *   @0x30a7fa .word 0xf8d33022
 *   @0x30a7fe .word 0xf7ff9010
 *   @0x30a802 .word 0xf50dff5e
 *   @0x30a806 andslo r5, r12, #-268435444
 *   @0x30a80a strmi r9, [r2], r3, lsl #4
 *   @0x30a80e mullo r0, r9, r8
 *   @0x30a812 .word 0x4648b1fb
 *   @0x30a816 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x30a81a blhs 0xb2882e <b2_toiTime+0x3cf38a>
 *   @0x30a81e .word 0xf50dd0f9
 *   @0x30a822 ldrbmi r5, [r2], -pc, asr #7
 *   @0x30a826 qadd16mi r3, r1, r12
 *   @0x30a82a .word 0xff56f7ff
 *   @0x30a82e sbcpl pc, pc, #54525952
 *   @0x30a832 ldmdavs r3, {r2, r3, r4, r9, r12, sp}
 *   @0x30a836 strmi r2, [r1], r1, lsl #22
 *   @0x30a83a andhs sp, r0, #232, #16
 *   @0x30a83e andlt pc, r0, sp, asr #17
 *   @0x30a842 ldrbmi r4, [r1], -r0, lsr #12
 *   @0x30a846 .word 0xf7ff4613
 *   @0x30a84a strmi pc, [r0], r3, lsr #31
 *   @0x30a84e sbcsle r2, sp, r0, lsl #16
 *   @0x30a852 ldrmi lr, [r8], r0
 *   @0x30a856 uasxmi r4, r1, r0
 *   @0x30a85a .word 0xff3bf7ff
 *   @0x30a85e svceq #0xf1b8
 *   @0x30a862 addhi pc, r8, r0
 *   @0x30a866 .word 0x46414630
 *   @0x30a86a .word 0xf7dc2201
 *   @0x30a86e sxtab16mi pc, r2, r10, ror #24
 *   @0x30a872 cmnle pc, r0, lsl #16
 *   @0x30a876 ldrsblt pc, [r4], #-134
 *   @0x30a87a strhtlo pc, [lr], #-155
 *   @0x30a87e vldmdble r9!, {d18}
 *   @0x30a882 ldmpl r1, {r0, r2, r3, r8, r10, r12, sp, lr, pc} ^
 *   @0x30a886 cpsie f
 *   @0x30a88a .word 0xf6430808
 *   @0x30a88e .word 0xf1a8026c
 *   @0x30a892 strbmi r0, [r8], -r12, lsr #18
 *   @0x30a896 cdp p5, #0x8, c15, c12, c11, #0x5
 *   @0x30a89a .word 0xf8486aa3
 *   @0x30a89e strtmi r6, [r8], -r8, lsr #24
 *   @0x30a8a2 bls 0xff248bbe <b2_toiTime+0xfffffffffeaef71a>
 *   @0x30a8a6 .word 0x016cf10b
 *   @0x30a8aa .word 0x3c04f848
 *   @0x30a8ae orrlo pc, r0, #1325400064
 *   @0x30a8b2 bge 0xff048bce <b2_toiTime+0xfffffffffe8ef72a>
 *   @0x30a8b6 stclo p8, c15, [r4], #-288
 *   @0x30a8ba stclo p8, c15, [r0], #-288
 *   @0x30a8be mcr2 p7, #0x2, pc, c7, c12, #0x7
 *   @0x30a8c2 cmple r7, r0, lsl #16
 *   @0x30a8c6 ldrteq pc, [r8], -r4, lsl #2
 *   @0x30a8ca ssatmi r3, #0x9, r8, asr #30
 *   @0x30a8ce ldrbmi r4, [r9], -r3, lsl #13
 *   @0x30a8d2 movwhs r4, #0x628
 *   @0x30a8d6 .word 0xf7fd603b
 *   @0x30a8da .word 0xf1a6f8ae
 *   @0x30a8de strmi r0, [r1], -r12, lsl #20
 *   @0x30a8e2 mrsle r2, spsr
 *   @0x30a8e6 strtmi r4, [r8], -r10, lsl #12
 *   @0x30a8ea .word 0xf7fc465b
 *   @0x30a8ee .word 0xf8d8fd29
 *   @0x30a8f2 .word 0xf8d82034
 *   @0x30a8f6 .word 0x232c102c
 *   @0x30a8fa blx 0x3d2934 <error_g0017+0x2b5d8>
 *   @0x30a8fe addmi r2, r10, #1073741824
 *   @0x30a902 .word 0xf8d2d222
 *   @0x30a906 .word 0xf1bcc014
 *   @0x30a90a andsle r0, r11, r0, lsl #30
 *   @0x30a90e ldrsblo pc, [r4], -r12
 *   @0x30a912 .word 0xd1174293
 *   @0x30a916 ldmdble r5, {r2, r4, r7, r8, r10, lr}
 *   @0x30a91a strhlo pc, [r2], -r2
 *   @0x30a91e strh pc, [r2], -r12
 *   @0x30a922 vmlseq.f64 d14, d19, d14
 *   @0x30a926 .word 0xf1be683b
 *   @0x30a92a svclt #0xb80f00
 *   @0x30a92e cdpeq p1, #0x0, c15, c0, c14, #0x6
 *   @0x30a932 stmdale r7, {r0, r1, r2, r3, r8, r9, r11, sp}
 *   @0x30a936 .word 0x0c01f103
 *   @0x30a93a andgt pc, r0, r7, asr #17
 *   @0x30a93e movwge pc, #0x3b00
 *   @0x30a942 and pc, r12, r3, asr #17
 *   @0x30a946 ldrb r3, [r10, r12, lsr #4]
 *   @0x30a94a .word 0x0028f8d9
 *   @0x30a94e .word 0xf00e2164
 *   @0x30a952 shsub16mi lr, r1, r10
 *   @0x30a956 bleq 0x386d8a <_ZTS13C_UTF16String+0x1de36>
 *   @0x30a95a stmdapl r4, {r3, r9, r12, sp, lr, pc} ^
 *   @0x30a95e ldrtmi r4, [r8], -r2, lsl #12
 *   @0x30a962 blx 0xff70895c <b2_toiTime+0xfffffffffefaf4b8>
 *   @0x30a966 .word 0xf1bb683b
 *   @0x30a96a .word 0xf8460f02
 *   @0x30a96e .word 0xf5063c04
 *   @0x30a972 .word 0xd1ac56e1
 *   @0x30a976 stmdbpl r1!, {r2, r8, r10, r12, sp, lr, pc} ^
 *   @0x30a97a .word 0xf04f4626
 *   @0x30a97e .word 0xf04f0832
 *   @0x30a982 blvs 0x1fcd18a <b2_toiTime+0x1873ce6>
 *   @0x30a986 blvs 0xff0f6dba <b2_toiTime+0xfffffffffe99d916>
 *   @0x30a98a bvs 0xfed029aa <b2_toiTime+0xfffffffffe5a9506>
 *   @0x30a98e cmpmi r7, #69206016
 *   @0x30a992 .word 0xf207bf48
 *   @0x30a996 rscsne r7, pc, #66846720
 *   @0x30a99a .word 0x21054638
 *   @0x30a99e ldmib r8!, {r1, r2, r3, r12, sp, lr, pc}
 *   @0x30a9a2 rscsvc pc, r12, r6, asr #17
 *   @0x30a9a6 smlabbge r0, r6, r8, pc
 *   @0x30a9aa rscseq pc, r8, r6, asr #17
 *   @0x30a9ae strbtpl pc, [r1], r6, lsl #10
 *   @0x30a9b2 mvnle r4, lr, asr #10
 *   @0x30a9b6 .word 0xf7fd4628
 *   @0x30a9ba .word 0xf50dff02
 *   @0x30a9be andslt r4, r11, r4, lsr #27
 *   @0x30a9c2 svchi #0xf0e8bd
 *   @0x30a9c6 mvnsvc r11, #0, #30
 *   @0x30a9ca push {r1, r2, r3}
 *   @0x30a9ce .word 0x46074ff0
 *   @0x30a9d2 rscslt r6, r3, r3, lsl #16
 *   @0x30a9d6 strmi r4, [r8], r8, lsl #12
 *   @0x30a9da blmi 0xfea24d5a <b2_toiTime+0xfffffffffe2cb8b6>
 *   @0x30a9de ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x30a9e2 strbeq lr, [r6], r3, lsl #22
 *   @0x30a9e6 mcr2 p7, #0x3, pc, c11, c15, #0x7
 *   @0x30a9ea strlo r9, [r8], -r5
 *   @0x30a9ee .word 0x2c08f856
 *   @0x30a9f2 msrmi CPSR_fc, #268435460
 *   @0x30a9f6 .word 0xf000429a
 *   @0x30a9fa blmi 0xfe86ae8a <b2_toiTime+0xfffffffffe1119e6>
 *   @0x30a9fe strtmi r2, [r5], -r0, lsl #8
 *   @0x30aa02 ldrbtmi r2, [r11], #-1
 *   @0x30aa06 andls r6, r6, r11, lsl r8
 *   @0x30aa0a movwls r1, #0x38d3
 *   @0x30aa0e .word 0x3c04f836
 *   @0x30aa12 stmdbge r11, {r0, r3, r4, r7, r8, r9, r10}
 *   @0x30aa16 .word 0xf507bf56
 *   @0x30aa1a .word 0xf10759e2
 *   @0x30aa1e .word 0xf109092c
 *   @0x30aa22 mrsls r0, apsr
 *   @0x30aa26 stmdavc r11, {r0, r1, r8, r11, r12, pc}
 *   @0x30aa2a .word 0xf0002b00
 *   @0x30aa2e .word 0x460b80bb
 *   @0x30aa32 .word 0xf8134618
 *   @0x30aa36 bhs 0xb15642 <b2_toiTime+0x3bc19e>
 *   @0x30aa3a bhs 0x223ee2a <b2_toiTime+0x1ae5986>
 *   @0x30aa3e andhs sp, r0, #-1073741824
 *   @0x30aa42 andls r9, r6, #201326592
 *   @0x30aa46 blge 0x604a06 <g_SWFaavertbuff+0x3193e>
 *   @0x30aa4a bls 0x45c336 <g_RomDisk+0x64b16>
 *   @0x30aa4e mcr2 p7, #0x2, pc, c4, c15, #0x7
 *   @0x30aa52 blhs 0x371686 <_ZTS13C_UTF16String+0x8732>
 *   @0x30aa56 stmle r5!, {r0, r1, r12, pc} ^
 *   @0x30aa5a stmdbls r5, {r8, r9, sp}
 *   @0x30aa5e ldrtmi r9, [r8], -r0, lsl #6
 *   @0x30aa62 .word 0xf7ff461a
 *   @0x30aa66 .word 0x4601fe95
 *   @0x30aa6a sbcsle r2, r11, r0, lsl #16
 *   @0x30aa6e strbmi r2, [r0], -r1, lsl #4
 *   @0x30aa72 ldc2l p7, c15, [r7, #-880]!
 *   @0x30aa76 ldrsblo pc, [r4], #-136
 *   @0x30aa7a rfeia r3!
 *   @0x30aa7e rfeia r3!
 *   @0x30aa82 svcvs #0x9b206e
 *   @0x30aa86 movwls r9, #0x8104
 *   @0x30aa8a bicle r2, r11, r0, lsl #16
 *   @0x30aa8e bhs 0x3b72de <error_g0017+0xff82>
 *   @0x30aa92 strmi sp, [r3], -r8, asr #27
 *   @0x30aa96 .word 0xf04f4686
 *   @0x30aa9a .word 0x460231ff
 *   @0x30aa9e stc2 p10, c15, [r12], {15}
 *   @0x30aaa2 eorgt pc, r4, sp, asr #17
 *   @0x30aaa6 strmi r9, [r6, #0x809]
 *   @0x30aaaa stmdals r8, {r1, r2, r3, r5, r6, r9, r11, r12, lr, pc}
 *   @0x30aaae andseq pc, lr, r0, lsr r9
 *   @0x30aab2 mulls r2, r8, r2
 *   @0x30aab6 rfeda r6!
 *   @0x30aaba .word 0xf00ccc04
 *   @0x30aabe .word 0xf00c0b02
 *   @0x30aac2 blx 0xacdace <b2_toiTime+0x37462a>
 *   @0x30aac6 blx 0xb098fa <b2_toiTime+0x3b0456>
 *   @0x30aaca .word 0xf1bbfc8c
 *   @0x30aace eorle r0, r7, r0, lsl #30
 *   @0x30aad2 b 0x16f0aea <b2_toiTime+0xf97646>
 *   @0x30aad6 strmi r0, [r3], #3011
 *   @0x30aada svceq #0xf1bc
 *   @0x30aade .word 0xf04fd019
 *   @0x30aae2 stmdals r2, {r10, r11}
 *   @0x30aae6 mcrrle p2, #0x8, r4, r10, c3
 *   @0x30aaea .word 0xf85b2900
 *   @0x30aaee blle 0x372b26 <_ZTS13C_UTF16String+0x9bd2>
 *   @0x30aaf2 stcle p5, c4, [r1, #-584]
 *   @0x30aaf6 ssaxmi r4, r9, r2
 *   @0x30aafa .word 0xf10c3301
 *   @0x30aafe ldrb r0, [r0, r8, lsl #24]!
 *   @0x30ab02 .word 0xf85b2900
 *   @0x30ab06 blle 0x532b3e <SrcVerts+0x8fb82>
 *   @0x30ab0a blle 0x49c15a <TimingData+0x2142>
 *   @0x30ab0e .word 0xf10c3301
 *   @0x30ab12 stmdals r2, {r3, r10, r11}
 *   @0x30ab16 ldclle p2, c4, [r3, #524]!
 *   @0x30ab1a uasxmi lr, r2, r1
 *   @0x30ab1e .word 0xe7f54619
 *   @0x30ab22 b 0x16f0b3a <b2_toiTime+0xf97696>
 *   @0x30ab26 strmi r0, [r2], #2755
 *   @0x30ab2a svceq #0xf1bc
 *   @0x30ab2e .word 0x46dcd01e
 *   @0x30ab32 addmi r9, r3, #131072
 *   @0x30ab36 stmdbhs r0, {r0, r1, r5, r10, r11, r12, lr, pc}
 *   @0x30ab3a bl 0x5c1756 <g_SWFlineaavertbuff+0x6e68e>
 *   @0x30ab3e .word 0xf8db0b0c
 *   @0x30ab42 ldrmi r11, [r3, #0x4]
 *   @0x30ab46 bl 0x5c1f5a <g_SWFlineaavertbuff+0x6ee92>
 *   @0x30ab4a ldrmi r0, [r9], -r12, lsl #4
 *   @0x30ab4e movwlo r6, #0x1852
 *   @0x30ab52 .word 0x0c08f10c
 *   @0x30ab56 stmdbhs r0, {r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30ab5a bl 0x5c1792 <g_SWFlineaavertbuff+0x6e6ca>
 *   @0x30ab5e .word 0xf8db0b0c
 *   @0x30ab62 ldrmi r11, [r3, #0x4]
 *   @0x30ab66 movwlo sp, #0x1b06
 *   @0x30ab6a .word 0x0c08f10c
 *   @0x30ab6e addmi r9, r3, #131072
 *   @0x30ab72 strd sp, lr, [r4], -r1
 *   @0x30ab76 andeq lr, r12, #10240
 *   @0x30ab7a ldmdavs r2, {r0, r3, r4, r9, r10, lr} ^
 *   @0x30ab7e stmdals r2, {r0, r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30ab82 cdpeq p1, #0x0, c15, c1, c14, #0x0
 *   @0x30ab86 str r1, [sp, r3, asr #24]
 *   @0x30ab8a .word 0xb1219906
 *   @0x30ab8e .word 0xf843ab0c
 *   @0x30ab92 strlo r2, [r1, #-0x25]
 *   @0x30ab96 ldmdage r2!, {r1, r2, r6, r8, r9, r10, sp, lr, pc} ^
 *   @0x30ab9a orreq lr, r4, #0, #22
 *   @0x30ab9e .word 0xf8433401
 *   @0x30aba2 ldr r2, [pc, -r12, asr #25]!
 *   @0x30aba6 stchs p9, c11, [r0, #-80]
 *   @0x30abaa svcge #0x1ff43f
 *   @0x30abae beq 0xf46fea <b2_toiTime+0x7edb46>
 *   @0x30abb2 ldrbmi r4, [r1], -r8, lsr #12
 *   @0x30abb6 blx 0xfe788bae <b2_toiTime+0xfffffffffe02f70a>
 *   @0x30abba qasxmi r10, r0, pc
 *   @0x30abbe blx 0xfe688bb6 <b2_toiTime+0xfffffffffdf2f712>
 *   @0x30abc2 ldrsbne pc, [r8], #137
 *   @0x30abc6 blx 0x393440 <ft_adobe_glyph_list+0x2b1c>
 *   @0x30abca .word 0x31019201
 *   @0x30abce sbcsne pc, r8, r9, asr #17
 *   @0x30abd2 ldcne p2, c3, [r3, #-864]
 *   @0x30abd6 stmdaeq sp!, {r2, r3, r4, r8, r11, r12, sp, pc} ^
 *   @0x30abda eorne pc, r5, r10, asr r8
 *   @0x30abde stmdaeq r4!, {r1, r2, sp, lr, pc} ^
 *   @0x30abe2 ldmdage r2!, {r0, r2, r3, r4, r5, r8, r11, r12, sp, pc} ^
 *   @0x30abe6 streq lr, [r4], #2816
 *   @0x30abea stclne p8, c15, [r12], {84}
 *   @0x30abee ldrsbvs r6, [r1], #-9
 *   @0x30abf2 stmdaeq sp!, {r0, r3, sp, lr, pc} ^
 *   @0x30abf6 eorne pc, r5, r10, asr r8
 *   @0x30abfa ldmdbge r2!, {r0, r4, r6, sp, lr} ^
 *   @0x30abfe streq lr, [r4], #2817
 *   @0x30ac02 stclne p8, c15, [r12], {84}
 *   @0x30ac06 ldmvs r8, {r0, r3, r4, r6, r7, sp, lr} ^
 *   @0x30ac0a addmi r6, r8, #5308416
 *   @0x30ac0e rfeda r6!
 *   @0x30ac12 svclt #0xac5c04
 *   @0x30ac16 strhs r2, [r1], #-1024
 *   @0x30ac1a streq pc, [r1, #-0x5]
 *   @0x30ac1e andle r4, r5, r5, lsr #5
 *   @0x30ac22 bl 0x35bc2e
 *   @0x30ac26 ldrdne r7, r8, [r9], #-17
 *   @0x30ac2a ldrsbvs r6, [r1], #-9
 *   @0x30ac2e orrsvs r2, r10, r0, lsl #4
 *   @0x30ac32 .word 0x2c04f836
 *   @0x30ac36 svclt #0x4407d2
 *   @0x30ac3a orrsvs r2, r10, r2, lsl #4
 *   @0x30ac3e .word 0x4640e6d5
 *   @0x30ac42 .word 0xf7ff9905
 *   @0x30ac46 rsbslt pc, r3, r6, asr #26
 *   @0x30ac4a svchi #0xf0e8bd
 *   @0x30ac4e andsvc r11, r2, #0, #30
 *   @0x30ac52 mvnsvc r0, lr
 *   @0x30ac56 push {r1, r2, r3}
 *   @0x30ac5a .word 0x460f4ff0
 *   @0x30ac5e addlt r4, sp, sp, lsr #18
 *   @0x30ac62 strmi r10, [r5], -r6, lsl #20
 *   @0x30ac66 stmdavs r9, {r0, r3, r4, r5, r6, r10, lr}
 *   @0x30ac6a ldrmi r9, [r0], r3, lsl #2
 *   @0x30ac6e movwls r6, #0xb80b
 *   @0x30ac72 movwls r2, #0x4300
 *   @0x30ac76 ldrbtmi r4, [r11], #-2856
 *   @0x30ac7a ldreq pc, [r0], -r3, lsl #2
 *   @0x30ac7e movwlo r6, #0x8818
 *   @0x30ac82 .word 0x1c04f853
 *   @0x30ac86 .word 0x461442b3
 *   @0x30ac8a strtmi r12, [r2], -r3, lsl #8
 *   @0x30ac8e ldmdavs r8, {r1, r2, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x30ac92 ldmdbeq r4, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x30ac96 beq 0x7470d2 <g_SWFvertbuff+0x7400a>
 *   @0x30ac9a eorvs r4, r0, r3, asr #13
 *   @0x30ac9e .word 0xf7ff4638
 *   @0x30aca2 strhs pc, [r0], #-3342
 *   @0x30aca6 strmi r4, [r6], -r0, lsr #13
 *   @0x30acaa mullo r0, r11, r8
 *   @0x30acae usub8mi r11, r8, r11
 *   @0x30acb2 strtmi r4, [r9], -r11, asr #12
 *   @0x30acb6 .word 0xf7ff4632
 *   @0x30acba blls 0x48a0fe <prim_v+0x74a>
 *   @0x30acbe strmi r2, [r3], r1, lsl #22
 *   @0x30acc2 strdhs sp, lr, [r0, -r2]
 *   @0x30acc6 .word 0x91004628
 *   @0x30acca ldrtmi r2, [r1], -r0, lsl #4
 *   @0x30acce .word 0xf7ff4653
 *   @0x30acd2 stmdahs r0, {r0, r1, r2, r3, r4, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x30acd6 blls 0x43f07e <g_RomDisk+0x4785e>
 *   @0x30acda svceq #0xf1b8
 *   @0x30acde adcmi sp, r3, #3
 *   @0x30ace2 strhs sp, [r0], #-2
 *   @0x30ace6 ldrmi lr, [r12], -r4
 *   @0x30acea stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30acee strhs lr, [r1], #-2012
 *   @0x30acf2 shasxmi r4, r8, r1
 *   @0x30acf6 stc2l p7, c15, [sp], #1020
 *   @0x30acfa bls 0x5f110e <g_SWFaavertbuff+0x1e046>
 *   @0x30acfe eormi pc, r0, r5, lsl #17
 *   @0x30ad02 addsmi r6, r10, #720896
 *   @0x30ad06 .word 0xf5abd001
 *   @0x30ad0a andlt lr, sp, r4, ror #24
 *   @0x30ad0e svchi #0xf0e8bd
 *   @0x30ad12 stclhs p15, c11, [lr], #0
 *   @0x30ad16 movtmi r0, #0x500e
 *   @0x30ad1a ldrblt r0, [r0, #-0x8]!
 *   @0x30ad1e rfeia r1!
 *   @0x30ad22 strmi r3, [r12], -r4, asr #32
 *   @0x30ad26 addvs r6, r3, #13184
 *   @0x30ad2a stmdbmi r10, {r3, r9, r10, lr}
 *   @0x30ad2e stc2l p7, c15, [r1, #872]!
 *   @0x30ad32 qsaxmi r11, r8, r8
 *   @0x30ad36 .word 0xf7ff4621
 *   @0x30ad3a qasxmi pc, r8, r12
 *   @0x30ad3e .word 0xf7ff4621
 *   @0x30ad42 strtmi pc, [r8], -r4, asr #28
 *   @0x30ad46 .word 0xf7ff4621
 *   @0x30ad4a strtmi pc, [r0], -r6, lsl #31
 *   @0x30ad4e .word 0xf7da4631
 *   @0x30ad52 .word 0x2000ffd4
 *   @0x30ad56 stmdbvs r3!, {r4, r5, r6, r8, r10, r11, r12, sp, pc} ^
 *   @0x30ad5a ldrblt r7, [r0, #-0x56e]!
 *   @0x30ad5e rfeia r1!
 *   @0x30ad62 strmi r3, [r12], -r4, asr #32
 *   @0x30ad66 addvs r6, r3, #13184
 *   @0x30ad6a stmdbmi r10, {r3, r9, r10, lr}
 *   @0x30ad6e stc2l p7, c15, [r1, #872]
 *   @0x30ad72 movwhs r11, #0x110
 *   @0x30ad76 and r6, r7, r3, ror #11
 *   @0x30ad7a strtmi r4, [r1], -r8, lsr #12
 *   @0x30ad7e ldc2 p7, c15, [r9, #-1020]
 *   @0x30ad82 strtmi r4, [r1], -r8, lsr #12
 *   @0x30ad86 .word 0xff67f7ff
 *   @0x30ad8a ldrtmi r4, [r1], -r0, lsr #12
 *   @0x30ad8e .word 0xffb5f7da
 *   @0x30ad92 ldcllt p0, c2, [r0, #-0]!
 *   @0x30ad96 stmdbvs r3!, {r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x30df0e addmi lr, sp, #64225280
 *   @0x30df12 stmdavs r0!, {r0, r1, r8, r9, r12, lr, pc} ^
 *   @0x30df16 stmiblt r11, {r0, r1, r8, r9, r11, r12, sp, lr}
 *   @0x30df1a addsmi lr, r3, #50
 *   @0x30df1e adchi pc, r2, r0
 *   @0x30df22 svceq #0xf1ba
 *   @0x30df26 ldmvs r10!, {r0, r1, r12, lr, pc}
 *   @0x30df2a vqsub.u8 d20, d16, d3
 *   @0x30df2e tsths r4, #155
 *   @0x30df32 movwmi pc, #0x5b03
 *   @0x30df36 .word 0x071a69db
 *   @0x30df3a adds sp, r3, r11, ror #11
 *   @0x30df3e .word 0x06db6833
 *   @0x30df42 .word 0xf1bad41e
 *   @0x30df46 andsle r0, r7, r0, lsl #30
 *   @0x30df4a ldmvs r9!, {r0, r1, r4, r5, r7, r11, sp, lr}
 *   @0x30df4e bl 0x35efba <_ZTS12CDS_Priority+0x1012>
 *   @0x30df52 ldrdne r7, r8, [r9], #-17
 *   @0x30df56 .word 0xff88f7ff
 *   @0x30df5a stmdbvs r1!, {r0, r1, r4, r5, r7, r11, sp, lr}
 *   @0x30df5e ldmvs r8!, {r7, r9, r10, lr}
 *   @0x30df62 bl 0x314a6a <FT_Bitmap_Copy+0x92>
 *   @0x30df66 ldrdne r7, r8, [r0], #-0
 *   @0x30df6a .word 0xff23f7ff
 *   @0x30df6e movweq lr, #0x8bc0
 *   @0x30df72 rscsvs r4, r3, r0, asr #8
 *   @0x30df76 strd r6, r7, [r3], -r8
 *   @0x30df7a .word 0xf7ff68b1
 *   @0x30df7e rscsvs pc, r0, r5, ror pc
 *   @0x30df82 mcrne p1, #0x3, r11, c10, c13, #0x1
 *   @0x30df86 blx 0x3d6be0 <error_g0017+0x2f884>
 *   @0x30df8a ldmvs r3!, {r1, r9, lr} ^
 *   @0x30df8e addsmi r6, r3, #598016
 *   @0x30df92 .word 0xf8d4db68
 *   @0x30df96 strbmi r12, [r5, #-0x14]!
 *   @0x30df9a tsths r4, #-268435456
 *   @0x30df9e movwmi pc, #0x5b03
 *   @0x30dfa2 svceq #0xf1ba
 *   @0x30dfa6 ldmvs r10!, {r2, r12, lr, pc} ^
 *   @0x30dfaa addsmi r6, r10, #634880
 *   @0x30dfae subs sp, r9, r8, lsl #26
 *   @0x30dfb2 bvs 0xfe9e8382 <b2_toiTime+0xfffffffffe28eede>
 *   @0x30dfb6 stcle p2, c4, [r6, #-616]
 *   @0x30dfba .word 0xf1bae054
 *   @0x30dfbe andle r0, r2, r0, lsl #30
 *   @0x30dfc2 movweq pc, #0x110c
 *   @0x30dfc6 strbtmi lr, [r3], -r0
 *   @0x30dfca stmdale r11, {r0, r1, r2, r3, r4, r5, r7, r8, r9, r11, sp} ^
 *   @0x30dfce bl 0xff456826 <b2_toiTime+0xfffffffffecfd382>
 *   @0x30dfd2 mrsls r0, apsr
 *   @0x30dfd6 bleq 0x34a11a
 *   @0x30dfda .word 0x410cfb02
 *   @0x30dfde andmi pc, r3, #2048
 *   @0x30dfe2 andls r9, r2, #-1073741824
 *   @0x30dfe6 .word 0xf1ab9a01
 *   @0x30dfea blo 0x350c42
 *   @0x30dfee andlo r9, r1, #268435456
 *   @0x30dff2 .word 0xf8ddd012
 *   @0x30dff6 .word 0xf8dd900c
 *   @0x30dffa ldrbmi r8, [r9], #8
 *   @0x30dffe ldmdbeq r12, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x30e002 .word 0xf10844d8
 *   @0x30e006 ldm r9!, {r4, r5, r11}
 *   @0x30e00a stm r8!, {r0, r1, r2, r3}
 *   @0x30e00e .word 0xf8d9000f
 *   @0x30e012 .word 0xf8c83000
 *   @0x30e016 strb r3, [r5, r0]!
 *   @0x30e01a ldmdbeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30e01e stmdami r5, {r0, r3, r8, r9, r11, r12, sp, lr, pc}
 *   @0x30e022 .word 0xf108ce0f
 *   @0x30e026 stm r8!, {r2, r3, r4, r11}
 *   @0x30e02a ldmdavs r3!, {r0, r1, r2, r3}
 *   @0x30e02e andlo pc, r0, r8, asr #17
 *   @0x30e032 movweq pc, #0x110c
 *   @0x30e036 .word 0xf1ba6163
 *   @0x30e03a andsle r0, r3, r0, lsl #30
 *   @0x30e03e svcgt #0xf3501
 *   @0x30e042 strmi pc, [r5, #-0xb09]
 *   @0x30e046 strgt r3, [pc, #-0x51c]
 *   @0x30e04a eorvs r6, r11, r11, lsr r8
 *   @0x30e04e movweq pc, #0x210c
 *   @0x30e052 and r6, r7, r3, ror #2
 *   @0x30e056 stmvs r11, {r1, r4, r7, r11, sp, lr}
 *   @0x30e05a blle 0x3deaca <error_g0017+0x3776e>
 *   @0x30e05e .word 0xf04f460e
 *   @0x30e062 strb r0, [r7, -r1, lsl #20]
 *   @0x30e066 pop {r0, r2, r12, sp, pc}
 *   @0x30e06a push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x30e06e ssub8mi r4, r6, r8
 *   @0x30e072 eorspl pc, r5, #0, #10
 *   @0x30e076 strmi r4, [r9], r4, lsl #12
 *   @0x30e07a blvs 0xff71f8e6 <b2_toiTime+0xfffffffffefc6442>
 *   @0x30e07e ldrpl pc, [r6, #-0x504]!
 *   @0x30e082 .word 0xf7ff9f08
 *   @0x30e086 shadd8mi pc, r9, r6
 *   @0x30e08a stmdavs r8!, {r7, r9, r10, lr}
 *   @0x30e08e mrc2 p7, #0x4, apsr_nzcv, c1, c15, #0x7
 *   @0x30e092 strmi r4, [r0], #1593
 *   @0x30e096 .word 0xf7ff4648
 *   @0x30e09a stmdavs r3!, {r0, r1, r2, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30e09e strmi r4, [r7], -r1, asr #12
 *   @0x30e0a2 .word 0xf7ff6c18
 *   @0x30e0a6 stmdavs r2!, {r1, r2, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30e0aa .word 0x46814639
 *   @0x30e0ae .word 0xf7ff6c90
 *   @0x30e0b2 stmvs r11!, {r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30e0b6 strbmi r4, [r8], #-1601
 *   @0x30e0ba eorsvs r4, r3, r3, lsl #8
 *   @0x30e0be mrrcvs p8, #0x2, r6, r8, c3
 *   @0x30e0c2 mrc2 p7, #0x3, apsr_nzcv, c7, c15, #0x7
 *   @0x30e0c6 ldrtmi r6, [r9], -r3, lsr #16
 *   @0x30e0ca ldclvs p6, c4, [r8], {128}
 *   @0x30e0ce mrc2 p7, #0x3, apsr_nzcv, c1, c15, #0x7
 *   @0x30e0d2 strbmi r6, [r0], #-2283
 *   @0x30e0d6 rsbsvs r4, r0, r8, lsl r4
 *   @0x30e0da .word 0x83f8e8bd
 *   @0x30e0de .word 0x4604b510
 *   @0x30e0e2 stmdbvs r1!, {r0, r1, r11, sp, lr} ^
 *   @0x30e0e6 .word 0xf7d96e58
 *   @0x30e0ea movwhs pc, #0x925
 *   @0x30e0ee .word 0x61236163
 *   @0x30e0f2 ldrblt r11, [r0, #-0xd10]!
 *   @0x30e0f6 cmplt r8, r4, lsl #12
 *   @0x30e0fa strhs r6, [r0, #-0x806]
 *   @0x30e0fe ldrtmi r6, [r0], -r1, ror #29
 *   @0x30e102 .word 0xf918f7d9
 *   @0x30e106 ldrtmi r6, [r0], -r5, ror #13
 *   @0x30e10a .word 0xf7d96f61
 *   @0x30e10e .word 0x6765f913
 *   @0x30e112 ldrlt r11, [r8, #-0xd70]!
 *   @0x30e116 strhs r4, [r0, #-0x604]
 *   @0x30e11a stmibvs r1!, {r11, sp, lr} ^
 *   @0x30e11e smulttvs r5, r5, r0
 *   @0x30e122 .word 0xf7d961a5
 *   @0x30e126 mvnvs pc, r7, lsl #18
 *   @0x30e12a push {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x30e12e .word 0x460441f0
 *   @0x30e132 strmi r6, [lr], -r3, lsl #18
 *   @0x30e136 ldrtmi r11, [r0], -r11, asr #18
 *   @0x30e13a .word 0xf7d96921
 *   @0x30e13e stmdavs r3!, {r0, r1, r3, r4, r5, r6, r7, r11, r12, sp, lr, pc} ^
 *   @0x30e142 .word 0x61252500
 *   @0x30e146 stmiblt r3, {r3, r5, r7, r9, r10, lr} ^
 *   @0x30e14a strhs lr, [r0, #-0xf]
 *   @0x30e14e stmvs r3!, {r0, r1, r2, r3, r5, r9, r10, lr} ^
 *   @0x30e152 rscsle r4, r0, #-805306359
 *   @0x30e156 ldrtmi r6, [r0], -r3, lsr #18
 *   @0x30e15a eorne pc, r5, r3, asr r8
 *   @0x30e15e .word 0xf8eaf7d9
 *   @0x30e162 .word 0xf8436923
 *   @0x30e166 strlo r7, [r1, #-0x25]
 *   @0x30e16a shsub8mi lr, r0, r1
 *   @0x30e16e .word 0xf7d96861
 *   @0x30e172 movwhs pc, #0x8e1
 *   @0x30e176 pop {r0, r1, r5, r6, sp, lr}
 *   @0x30e17a stmdavs r3!, {r4, r5, r6, r7, r8, pc}
 *   @0x30e17e rscsle r4, r4, #-805306359
 *   @0x30e182 rsceq r6, pc, r3, ror #16
 *   @0x30e186 strlo r4, [r1, #-0x630]
 *   @0x30e18a ldmdavs r9, {r0, r1, r3, r4, r5, r10, lr} ^
 *   @0x30e18e .word 0xf8d2f7d9
 *   @0x30e192 ldrmi r6, [pc], #-2147
 *   @0x30e196 andhi pc, r4, r7, asr #17
 *   @0x30e19a ldrlt lr, [r8, #-0x7ef]!
 *   @0x30e19e stmdavs r3, {r2, r9, r10, lr} ^
 *   @0x30e1a2 adchs pc, r0, #13828096
 *   @0x30e1a6 .word 0x5c08f8d2
 *   @0x30e1aa mrcvs p1, #0x0, r11, c11, c13, #0x2
 *   @0x30e1ae ldmdavs r8, {r1, r2, r8, r11, lr} ^
 *   @0x30e1b2 .word 0xf7d74479
 *   @0x30e1b6 .word 0xb120fe9c
 *   @0x30e1ba ldrmi r6, [r8, r11, lsr #17]
 *   @0x30e1be ldrsblo pc, [r12], r4
 *   @0x30e1c2 andhs r6, r0, r8, asr r2
 *   @0x30e1c6 stmibeq r4!, {r3, r4, r5, r8, r10, r11, r12, sp, pc} ^
 *   @0x30e1ca ldrblt r0, [r0, #-0x8]!
 *   @0x30e1ce strmi r2, [r5], -r4, asr #5
 *   @0x30e1d2 strmi r4, [r8], -r12, lsl #12
 *   @0x30e1d6 .word 0xf5a82100
 *   @0x30e1da strtmi lr, [r10], -r10, ror #19
 *   @0x30e1de svcne #0xbcf812
 *   @0x30e1e2 eorvc r2, r1, #0, #6
 *   @0x30e1e6 andle r4, r7, #-1342177272
 *   @0x30e1ea streq lr, [r3], r2, lsl #22
 *   @0x30e1ee subeq lr, r3, r4, lsl #22
 *   @0x30e1f2 ldmdavs r6!, {r0, r8, r9, r12, sp} ^
 *   @0x30e1f6 ldrb r8, [r5, r6, lsl #3]!
 *   @0x30e1fa umlalshs pc, sp, r5, r8
 *   @0x30e1fe .word 0x01bcf105
 *   @0x30e202 rsbvc r2, r2, #0, #6
 *   @0x30e206 andle r4, r7, #805306377
 *   @0x30e20a streq lr, [r3], r1, lsl #22
 *   @0x30e20e subeq lr, r3, r4, lsl #22
 *   @0x30e212 blvs 0x9ae1e
 *   @0x30e216 ldrb r8, [r5, r6, lsl #10]!
 *   @0x30e21a umlalshs pc, lr, r5, r8
 *   @0x30e21e .word 0x01bcf105
 *   @0x30e222 adcvc r2, r2, #0, #6
 *   @0x30e226 andle r4, r7, #805306377
 *   @0x30e22a streq lr, [r3], r1, lsl #22
 *   @0x30e22e subeq lr, r3, r4, lsl #22
 *   @0x30e232 cdpvs p3, #0x7, c3, c6, c1, #0x0
 *   @0x30e236 ldrb r8, [r5, r6, lsl #15]!
 *   @0x30e23a umlalshs pc, pc, r5, r8
 *   @0x30e23e .word 0x01bcf105
 *   @0x30e242 rscvc r2, r2, #0, #6
 *   @0x30e246 andle r4, r9, #805306377
 *   @0x30e24a streq lr, [r3], r1, lsl #22
 *   @0x30e24e subeq lr, r3, r4, lsl #22
 *   @0x30e252 .word 0xf8d63301
 *   @0x30e256 .word 0xf8a0609c
 *   @0x30e25a ubfx r6, r8, #0x0, #0x14
 *   @0x30e25e .word 0x3180f8d5
 *   @0x30e262 .word 0x01bcf105
 *   @0x30e266 .word 0xf8d566e3
 *   @0x30e26a strvs r3, [r3, -r4, lsl #3]!
 *   @0x30e26e .word 0x3188f8d5
 *   @0x30e272 .word 0xf8d56763
 *   @0x30e276 .word 0xf8a4318c
 *   @0x30e27a .word 0xf8d53078
 *   @0x30e27e .word 0xf8a43190
 *   @0x30e282 movwhs r3, #0x7a
 *   @0x30e286 .word 0x2194f895
 *   @0x30e28a rsbshs pc, r12, r4, lsl #17
 *   @0x30e28e andle r4, r9, #805306377
 *   @0x30e292 streq lr, [r3], r1, lsl #22
 *   @0x30e296 subeq lr, r3, r4, lsl #22
 *   @0x30e29a .word 0xf8d63301
 *   @0x30e29e .word 0xf8a060dc
 *   @0x30e2a2 ldrb r6, [r3, r0, lsl #1]!
 *   @0x30e2a6 .word 0x2195f895
 *   @0x30e2aa .word 0x01bcf105
 *   @0x30e2ae .word 0xf8842300
 *   @0x30e2b2 addsmi r2, r3, #125
 *   @0x30e2b6 bl 0x382ae2 <_ZTS13C_UTF16String+0x19b8e>
 *   @0x30e2ba bl 0x40fcce <g_RomDisk+0x184ae>
 *   @0x30e2be movwlo r0, #0x1043
 *   @0x30e2c2 ldrsbvs pc, [r0, -r6]
 *   @0x30e2c6 addsvs pc, r10, r0, lsr #17
 *   @0x30e2ca .word 0xf895e7f3
 *   @0x30e2ce .word 0xf8843200
 *   @0x30e2d2 .word 0xf8d5307e
 *   @0x30e2d6 .word 0xf8c4320c
 *   @0x30e2da .word 0xf8d530b8
 *   @0x30e2de rsbvs r3, r3, r8, lsl #4
 *   @0x30e2e2 ldrblt r11, [r3, #-0xd70]!
 *   @0x30e2e6 strmi r10, [r4], -r1, lsl #26
 *   @0x30e2ea stcvc p6, c4, [r2], #-56
 *   @0x30e2ee stmdavs r0, {r0, r3, r5, r9, r10, lr}
 *   @0x30e2f2 blx 0x164c25c <b2_toiTime+0xef2db8>
 *   @0x30e2f6 stmdblt r0, {r1, r9, r10, lr} ^
 *   @0x30e2fa ldrmi r7, [r3], -r1, lsr #24
 *   @0x30e2fe ble 0x45ed26 <g_RomDisk+0x67506>
 *   @0x30e302 andlo r5, r1, r12, lsr #24
 *   @0x30e306 movwhs lr, #0x3a44
 *   @0x30e30a movwhs lr, #0x7f8
 *   @0x30e30e eorsvs r4, r2, r8, lsl r6
 *   @0x30e312 ldcllt p0, c11, [r0, #-8]!
 *   @0x30e316 svcmi #0xf7e92d
 *   @0x30e31a .word 0x460d469a
 *   @0x30e31e ldrmi r2, [r1], r0, lsl #6
 *   @0x30e322 strmi r9, [r4], -r1, lsl #6
 *   @0x30e326 rsble r2, r1, r0, lsl #16
 *   @0x30e32a addmi r6, r10, #12713984
 *   @0x30e32e stmibvs r3, {r1, r2, r3, r4, r6, r8, r11, r12, lr, pc} ^
 *   @0x30e332 .word 0x8000f8d0
 *   @0x30e336 stmvs r1, {r0, r1, r5, r8, r9, r11, r12, sp, pc}
 *   @0x30e33a strmi r6, [r11], #-2115
 *   @0x30e33e strbmi r7, [r0], -r1, lsl #24
 *   @0x30e342 .word 0x3105fb01
 *   @0x30e346 blx 0xfeecc2ae <b2_toiTime+0xfffffffffe772e0a>
 *   @0x30e34a stmdahs r0, {r0, r12, pc}
 *   @0x30e34e .word 0xf10dd150
 *   @0x30e352 strtmi r0, [r0], -r4, lsl #22
 *   @0x30e356 .word 0xf7ff4659
 *   @0x30e35a blls 0x38e272 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x22ce>
 *   @0x30e35e blhs 0x31fb82
 *   @0x30e362 stmdblt r8!, {r1, r2, r6, r8, r12, lr, pc}
 *   @0x30e366 strmi r2, [r7], -r0
 *   @0x30e36a stmvs r3!, {r2, r4, sp, lr, pc} ^
 *   @0x30e36e andsle r4, r1, #-805306359
 *   @0x30e372 ldrbmi r4, [r9], -r0, lsr #12
 *   @0x30e376 .word 0xf7ff3501
 *   @0x30e37a stmdahs r0, {r2, r4, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30e37e strd sp, lr, [r9], -r5
 *   @0x30e382 eorvc pc, r1, r3, asr r8
 *   @0x30e386 rscle r2, sp, r0, lsl #30
 *   @0x30e38a .word 0xf8533501
 *   @0x30e38e stmdblt r8, {r0, r2, r5}
 *   @0x30e392 .word 0xd3f94295
 *   @0x30e396 .word 0x2004f8d8
 *   @0x30e39a andlo r6, r1, #1622016
 *   @0x30e39e stmdale r2, {r4, r7, r9, lr}
 *   @0x30e3a2 addmi r1, r11, #69632
 *   @0x30e3a6 bne 0xff7447ae <b2_toiTime+0xfffffffffefeb30a>
 *   @0x30e3aa adcsmi r11, r8, #-1073741771
 *   @0x30e3ae blne 0xff4c4816 <b2_toiTime+0xfffffffffed6b372>
 *   @0x30e3b2 andvs pc, r0, r10, asr #17
 *   @0x30e3b6 .word 0xb1236a23
 *   @0x30e3ba ldrtmi r3, [r11], #-3841
 *   @0x30e3be andlo pc, r0, r9, asr #17
 *   @0x30e3c2 stmdbvs r1!, {r1, r2, r4, sp, lr, pc} ^
 *   @0x30e3c6 stmdblo r1, {r6, r9, r10, lr}
 *   @0x30e3ca .word 0xf7d84439
 *   @0x30e3ce andls pc, r1, r11, ror #20
 *   @0x30e3d2 .word 0x4640b970
 *   @0x30e3d6 .word 0x464a4631
 *   @0x30e3da stc2l p7, c15, [r2, #-868]!
 *   @0x30e3de and r9, r7, r1
 *   @0x30e3e2 .word 0xf8c92300
 *   @0x30e3e6 .word 0xf8ca3000
 *   @0x30e3ea and r3, r1, r0
 *   @0x30e3ee movwls r2, #0x1306
 *   @0x30e3f2 andlt r9, r3, r1, lsl #16
 *   @0x30e3f6 svchi #0xf0e8bd
 *   @0x30e3fa .word 0xf890b510
 *   @0x30e3fe stmdbvs r4, {r0, r6, r12, sp} ^
 *   @0x30e402 stmdahi r2!, {r0, r1, r5, r8, r11, r12, sp, pc}
 *   @0x30e406 andlo r4, r1, #24, #12
 *   @0x30e40a ldclt p0, c8, [r0, #-136]
 *   @0x30e40e rfeib r0!
 *   @0x30e412 rfeib r0!
 *   @0x30e416 ldrmi r2, [r10], #-20
 *   @0x30e41a andlo r6, r1, #8585216
 *   @0x30e41e stmdale r12, {r1, r3, r4, r7, r9, lr}
 *   @0x30e422 strhlo pc, [r0], -r4
 *   @0x30e426 vstrle d2, [pc, #-0]
 *   @0x30e42a movwmi pc, #0x103
 *   @0x30e42e stmdahi r1!, {r1, r5, r6, r7, r11, sp, lr} ^
 *   @0x30e432 stmdblo r1, {r0, r8, r9, r11, r12, sp}
 *   @0x30e436 andsne pc, r3, r2, lsr #16
 *   @0x30e43a .word 0x2100e006
 *   @0x30e43e .word 0xf7d92201
 *   @0x30e442 stmdahs r0, {r0, r5, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30e446 ldclt p0, c13, [r0, #-944]
 *   @0x30e44a andhs r8, r0, r3, lsr #16
 *   @0x30e44e eorhi r3, r3, r1, lsl #6
 *   @0x30e452 push {r4, r8, r10, r11, r12, sp, pc}
 *   @0x30e456 ssub8mi r4, sp, r7
 *   @0x30e45a .word 0xb10b9201
 *   @0x30e45e eorvs r2, r11, r0, lsl #6
 *   @0x30e462 subls pc, r0, #14614528
 *   @0x30e466 ldrtmi r2, [r4], r0, lsl #12
 *   @0x30e46a andhs r4, r4, #52, #12
 *   @0x30e46e strls r2, [r0], -r10, lsl #14
 *   @0x30e472 andlo r11, r1, r10, lsl r1
 *   @0x30e476 .word 0xf0804288
 *   @0x30e47a stmdavc r3, {r0, r1, r2, r8, pc}
 *   @0x30e47e .word 0xf1c24113
 *   @0x30e482 .word 0xf0030204
 *   @0x30e486 blhs 0x68f0ca <g_SWFlinevertbuff+0x3c002>
 *   @0x30e48a movwhs sp, #0x1102
 *   @0x30e48e strb r9, [pc, r0, lsl #6]!
 *   @0x30e492 .word 0xdc0b2b09
 *   @0x30e496 stcle p5, c4, [r2, #-304]
 *   @0x30e49a .word 0x0c01f10c
 *   @0x30e49e stmdblt r11, {r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x30e4a2 rscle r2, r5, r0, lsl #24
 *   @0x30e4a6 blx 0x4dbcb4 <SrcVerts+0x38cf8>
 *   @0x30e4aa strb r3, [r1, r4, lsl #8]!
 *   @0x30e4ae .word 0xf04f2b0a
 *   @0x30e4b2 tstle r12, r0, lsl #14
 *   @0x30e4b6 .word 0xa1ecf8df
 *   @0x30e4ba .word 0xb11a4699
 *   @0x30e4be addmi r3, r8, #1
 *   @0x30e4c2 rschi pc, r2, r0, lsl #1
 *   @0x30e4c6 tstmi r3, r3, lsl #16
 *   @0x30e4ca andeq pc, r4, #-2147483600
 *   @0x30e4ce movweq pc, #0xf003
 *   @0x30e4d2 .word 0xdc0c2b09
 *   @0x30e4d6 ldmdblt r4, {r0, r1, r3, r4, r8, r11, r12, sp, pc}
 *   @0x30e4da ldcllo p1, c15, [pc], #48
 *   @0x30e4de ldrbmi lr, [r4, #-0x7ed]
 *   @0x30e4e2 svchs #0x8dceb
 *   @0x30e4e6 strlo sp, [r1, -r9, ror #25]
 *   @0x30e4ea strlo pc, [r4], #-2825
 *   @0x30e4ee blhs 0x64848a <g_SWFaavertbuff+0x753c2>
 *   @0x30e4f2 blhs 0x60250e <g_SWFaavertbuff+0x2f446>
 *   @0x30e4f6 .word 0xf04fbf08
 *   @0x30e4fa teqle r1, r0, lsl #18
 *   @0x30e4fe .word 0xf04fe001
 *   @0x30e502 .word 0xf04f0901
 *   @0x30e506 ldrbmi r0, [r3], -r0, lsl #20
 *   @0x30e50a andlo r11, r1, r10, lsl r1
 *   @0x30e50e .word 0xf0804288
 *   @0x30e512 .word 0xf89080bb
 *   @0x30e516 blx 0x15fa51e <b2_toiTime+0xea107a>
 *   @0x30e51a .word 0xf1c2fb02
 *   @0x30e51e .word 0xf00b0204
 *   @0x30e522 .word 0xf1bb0b0f
 *   @0x30e526 .word 0xdc0a0f09
 *   @0x30e52a svcvc #0x7af5b3
 *   @0x30e52e .word 0xf04fdd02
 *   @0x30e532 strb r0, [r9, r1, lsl #20]!
 *   @0x30e536 stmdaeq r10, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x30e53a movwlt pc, #0x3b08
 *   @0x30e53e .word 0xf1b9e7e4
 *   @0x30e542 andle r0, r0, r0, lsl #30
 *   @0x30e546 .word 0x2c00425b
 *   @0x30e54a adchi pc, r3, r0
 *   @0x30e54e svceq #0xf1ba
 *   @0x30e552 .word 0xf1b9d00a
 *   @0x30e556 svclt #0x140f00
 *   @0x30e55a .word 0xf06f2000
 *   @0x30e55e adds r4, r9, r0
 *   @0x30e562 .word 0xf0002c00
 *   @0x30e566 movwhs r8, #0x96
 *   @0x30e56a ldrmi r9, [r4], #2561
 *   @0x30e56e bl 0x3df702 <error_g0017+0x383a6>
 *   @0x30e572 stchs p9, c0, [r0, #-24]
 *   @0x30e576 ldrtmi sp, [lr], #-74
 *   @0x30e57a bvc 0x30be9e <af_shaper_get_elem+0x170c>
 *   @0x30e57e stcle p14, c2, [r9], #-20
 *   @0x30e582 stcle p5, c4, [r7, #-336]
 *   @0x30e586 .word 0x210a4620
 *   @0x30e58a streq lr, [r9], -r6, asr #23
 *   @0x30e58e ldc2 p7, c15, [r2], {214}
 *   @0x30e592 ands r3, sp, r1, lsl #12
 *   @0x30e596 svceq #0xf1b9
 *   @0x30e59a .word 0xf1b9dd17
 *   @0x30e59e svclt #0xb40f05
 *   @0x30e5a2 strhs r4, [r5, -pc, asr #12]
 *   @0x30e5a6 blhs 0x31549a <FT_Bitmap_Embolden+0x654>
 *   @0x30e5aa bmi 0x12c59ee <b2_toiTime+0xb6c54a>
 *   @0x30e5ae streq lr, [r9], -r7, asr #23
 *   @0x30e5b2 .word 0xf852447a
 *   @0x30e5b6 cmpmi r12, #35
 *   @0x30e5ba stcle p5, c4, [r8, #-336]
 *   @0x30e5be .word 0x210a4620
 *   @0x30e5c2 bl 0xfecca5f2 <b2_toiTime+0xfffffffffe57114e>
 *   @0x30e5c6 strmi r3, [r4], -r1, lsl #12
 *   @0x30e5ca bl 0xff4c65d6 <b2_toiTime+0xfffffffffed6d132>
 *   @0x30e5ce strteq r0, [r0], #-1545
 *   @0x30e5d2 subs r6, pc, lr, lsr #32
 *   @0x30e5d6 ldrsblt pc, [r4], #143
 *   @0x30e5da qsub16mi r1, r0, r3
 *   @0x30e5de .word 0xf85b44fb
 *   @0x30e5e2 ldrtmi r7, [r9], -r3, lsr #32
 *   @0x30e5e6 bl 0xfe84a616 <b2_toiTime+0xfffffffffe0f1172>
 *   @0x30e5ea stcle p5, c4, [r8, #-320]
 *   @0x30e5ee strtmi r3, [r0], -r4, lsl #28
 *   @0x30e5f2 eorne pc, r6, r11, asr r8
 *   @0x30e5f6 streq pc, [r4], -r9, lsr #3
 *   @0x30e5fa mrrc2 p7, #0xd, pc, r12, c6
 *   @0x30e5fe strtmi lr, [r0], -r8, ror #15
 *   @0x30e602 .word 0xf7d64639
 *   @0x30e606 .word 0xf1a9fc57
 *   @0x30e60a strb r0, [r1, r5, lsl #12]!
 *   @0x30e60e svceq #0x5f1b9
 *   @0x30e612 .word 0xf119dc3c
 *   @0x30e616 blle 0x1052232 <b2_toiTime+0x8f8d8e>
 *   @0x30e61a svceq #0xf1b9
 *   @0x30e61e streq lr, [r7, -r3, asr #23]
 *   @0x30e622 blmi 0xbc4e52 <b2_toiTime+0x46b9ae>
 *   @0x30e626 andeq pc, r0, #1073741874
 *   @0x30e62a strbmi r4, [pc], #-1568
 *   @0x30e62e .word 0xf853447b
 *   @0x30e632 .word 0xf00a1022
 *   @0x30e636 strmi lr, [r4], -r12, ror #22
 *   @0x30e63a .word 0xf6472f0a
 *   @0x30e63e strdle r7, r8, [r6, -pc]
 *   @0x30e642 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x30e646 bl 0x1c4a676 <b2_toiTime+0x14f11d2>
 *   @0x30e64a strmi r2, [r4], -r9, lsl #14
 *   @0x30e64e svchs #0xe001
 *   @0x30e652 blmi 0x905a92 <b2_toiTime+0x1ac5ee>
 *   @0x30e656 ldrbtmi r4, [r11], #-1568
 *   @0x30e65a eorvs pc, r7, r3, asr r8
 *   @0x30e65e .word 0xf00a4631
 *   @0x30e662 adcmi lr, r8, #88064
 *   @0x30e666 qadd16mi sp, r0, r0
 *   @0x30e66a .word 0xf7d64631
 *   @0x30e66e ands pc, r1, r3, lsr #24
 *   @0x30e672 rsbsmi r4, pc, #69632
 *   @0x30e676 .word 0xf852447a
 *   @0x30e67a movtmi r0, #0x4027
 *   @0x30e67e .word 0xdc0542ac
 *   @0x30e682 and r0, r7, r0, lsr #8
 *   @0x30e686 and r4, r5, r8, lsr #12
 *   @0x30e68a and r2, r3, r0
 *   @0x30e68e andmi pc, r0, pc, rrx
 *   @0x30e692 strtmi lr, [r0], -r0
 *   @0x30e696 .word 0xb1039b00
 *   @0x30e69a andlt r4, r3, r0, asr #4
 *   @0x30e69e svchi #0xf0e8bd
 *   @0x30e6a2 stclgt p15, c11, [r11], {0}
 *   @0x30e6a6 rsbpl r0, r6, #204, #24
 *   @0x30e6aa eorspl r0, r10, #9
 *   @0x30e6ae mvnpl r0, r9
 *   @0x30e6b2 bicpl r0, r0, r9
 *   @0x30e6b6 movpl r0, r9
 *   @0x30e6ba addlt r0, r2, r9
 *   @0x30e6be svcmi #0xf0e92d
 *   @0x30e6c2 .word 0x4604b095
 *   @0x30e6c6 tstls pc, #24117248
 *   @0x30e6ca teqpl r7, #4, #10
 *   @0x30e6ce ldmdavs lr!, {r1, r3, r7, r9, r10, lr}
 *   @0x30e6d2 .word 0xf89d6a5a
 *   @0x30e6d6 bhs 0x38e8ee <_ZTS7CBucketILj16384ELj262144ELb1EE+0x294a>
 *   @0x30e6da .word 0xf103bf0b
 *   @0x30e6de .word 0xf5040830
 *   @0x30e6e2 .word 0xf1035838
 *   @0x30e6e6 .word 0xf1030928
 *   @0x30e6ea .word 0xf8d80938
 *   @0x30e6ee andls r1, r6, r0
 *   @0x30e6f2 strhle r4, [r5, -r1]
 *   @0x30e6f6 .word 0x2004f8d8
 *   @0x30e6fa addsmi r6, r10, #8060928
 *   @0x30e6fe sbchi pc, r7, r0
 *   @0x30e702 .word 0x3004f8d9
 *   @0x30e706 .word 0x2000f8d9
 *   @0x30e70a ldrsbtlt pc, [r12], #-141
 *   @0x30e70e andls r9, r7, #8, #6
 *   @0x30e712 streq lr, [r11, #-0xbc6]
 *   @0x30e716 .word 0x3004f8d8
 *   @0x30e71a bls 0x51bb62 <SrcVerts+0x78ba6>
 *   @0x30e71e bl 0xff392cda <b2_toiTime+0xfffffffffec39836>
 *   @0x30e722 ldmdavs r10!, {r0, r1, r10, r11} ^
 *   @0x30e726 .word 0xf10c9b20
 *   @0x30e72a andls r0, r9, #16, #24
 *   @0x30e72e .word 0x1c6cea4f
 *   @0x30e732 bne 0xfe9f334e <b2_toiTime+0xfffffffffe299eaa>
 *   @0x30e736 tstlo r0, #28672
 *   @0x30e73a andsgt pc, r0, sp, asr #17
 *   @0x30e73e cmpne r11, r9, lsl #21
 *   @0x30e742 andseq pc, r0, r1, lsl #2
 *   @0x30e746 ldrmi r9, [r9], -r3, lsl #6
 *   @0x30e74a .word 0xf7ff1140
 *   @0x30e74e .word 0xf8ddfb32
 *   @0x30e752 qadd16mi r12, r9, r0
 *   @0x30e756 strbtmi r4, [r0], -r2, lsl #12
 *   @0x30e75a .word 0xf7ff9204
 *   @0x30e75e bls 0x44d40e <g_RomDisk+0x55bee>
 *   @0x30e762 bne 0x7b5376 <b2_toiTime+0x5bed2>
 *   @0x30e766 msrhi APSR_nzcvqg, r0
 *   @0x30e76a ldrmi r9, [r9], -r7, lsl #16
 *   @0x30e76e bne 0x10b2f86 <b2_toiTime+0x959ae2>
 *   @0x30e772 andseq pc, r0, r6, lsl #2
 *   @0x30e776 .word 0xf7ff1140
 *   @0x30e77a blls 0x58d3f2 <g_SWFlineaavertbuff+0x3a32a>
 *   @0x30e77e strmi r9, [r6], -r8, lsl #18
 *   @0x30e782 andslo r1, r0, r8, asr r10
 *   @0x30e786 .word 0x11404629
 *   @0x30e78a blx 0x80c790 <b2_toiTime+0xb32ec>
 *   @0x30e78e ldrmi r9, [r1], -r4, lsl #20
 *   @0x30e792 .word 0xf7d61a30
 *   @0x30e796 .word 0xf8d9fb8f
 *   @0x30e79a .word 0xf8d86000
 *   @0x30e79e blne 0xfe5527a6 <b2_toiTime+0xfffffffffddf9302>
 *   @0x30e7a2 .word 0xf7ff9003
 *   @0x30e7a6 blls 0x40d3c6 <g_RomDisk+0x15ba6>
 *   @0x30e7aa .word 0x5004f8d9
 *   @0x30e7ae .word 0x1004f8d8
 *   @0x30e7b2 strmi r1, [r6], #-2889
 *   @0x30e7b6 .word 0xf7ff4618
 *   @0x30e7ba .word 0xf8d9fafc
 *   @0x30e7be .word 0xf8d83000
 *   @0x30e7c2 addsmi r2, r3, #0
 *   @0x30e7c6 teqpl r6, #4, #10
 *   @0x30e7ca strmi r9, [r5], #-520
 *   @0x30e7ce bne 0xfef42bf6 <b2_toiTime+0xfffffffffe7e9752>
 *   @0x30e7d2 blvs 0x19b4bfa <b2_toiTime+0x125b756>
 *   @0x30e7d6 svclt #0xb82800
 *   @0x30e7da addsmi r4, r0, #64, #4
 *   @0x30e7de .word 0x460ebfb8
 *   @0x30e7e2 .word 0x2004f8d9
 *   @0x30e7e6 .word 0x0004f8d8
 *   @0x30e7ea smlabble r10, r2, r2, r4
 *   @0x30e7ee .word 0x0c05ebc0
 *   @0x30e7f2 .word 0xf1bc6b5a
 *   @0x30e7f6 svclt #0xb80f00
 *   @0x30e7fa .word 0x0c00f1cc
 *   @0x30e7fe svclt #0xb84594
 *   @0x30e802 .word 0xf8d74605
 *   @0x30e806 ldrbmi r12, [r12]
 *   @0x30e80a bl 0xff602c3a <b2_toiTime+0xfffffffffeea9796>
 *   @0x30e80e blvs 0x1990c2e <b2_toiTime+0x123778a>
 *   @0x30e812 svceq #0xf1b9
 *   @0x30e816 .word 0xf1c9bfb8
 *   @0x30e81a ldrmi r0, [r1, #0x900]
 *   @0x30e81e .word 0x465ebfb8
 *   @0x30e822 stmdbls r5, {r1, r3, r4, r5, r6, r11, sp, lr}
 *   @0x30e826 andls r4, r7, #-1610612728
 *   @0x30e82a .word 0xf504d10d
 *   @0x30e82e bl 0xff364d0e <b2_toiTime+0xfffffffffec0b86a>
 *   @0x30e832 .word 0xf1bb0b05
 *   @0x30e836 svclt #0xb80f00
 *   @0x30e83a bleq 0x34af6e
 *   @0x30e83e ldrsbtls pc, [r4], -r9
 *   @0x30e842 svclt #0xb845cb
 *   @0x30e846 stmdbls r8, {r0, r2, r3, r9, r10, lr}
 *   @0x30e84a strbtmi r6, [r1], #-2843
 *   @0x30e84e bicsvc lr, r1, r1, lsl #22
 *   @0x30e852 stmdbeq r1!, {r1, r2, r4, r5, r7, r8, r9, r11, sp, lr, pc} ^
 *   @0x30e856 .word 0x0161ea4f
 *   @0x30e85a bl 0xff4be592 <b2_toiTime+0xfffffffffed650ee>
 *   @0x30e85e strbmi r0, [r9], -r1, lsl #2
 *   @0x30e862 .word 0xdc164299
 *   @0x30e866 ldrmi r9, [r0], #-2567
 *   @0x30e86a sbcsvc lr, r0, r0, lsl #22
 *   @0x30e86e strheq lr, [r0, #-181]!
 *   @0x30e872 rsbeq lr, r0, pc, asr #20
 *   @0x30e876 bl 0xff47e5ae <b2_toiTime+0xfffffffffed2510a>
 *   @0x30e87a strmi r0, [r8], -r0
 *   @0x30e87e .word 0xdc084298
 *   @0x30e882 andvs pc, r0, r8, asr #17
 *   @0x30e886 bleq 0x38a9ca <bigtens_D2A+0xe9a>
 *   @0x30e88a andpl pc, r4, r8, asr #17
 *   @0x30e88e strhs lr, [r0, #-0x3]
 *   @0x30e892 .word 0xf04f462e
 *   @0x30e896 .word 0xf5040b00
 *   @0x30e89a .word 0xf10d5c37
 *   @0x30e89e .word 0xf10c082c
 *   @0x30e8a2 .word 0xf8dc0910
 *   @0x30e8a6 ldm r9, {r2, r5, r12, sp}
 *   @0x30e8aa blhs 0x38e8be <_ZTS7CBucketILj16384ELj262144ELb1EE+0x291a>
 *   @0x30e8ae andeq lr, r3, r8, lsl #17
 *   @0x30e8b2 blhs 0x44296e <g_RomDisk+0x4b14e>
 *   @0x30e8b6 tstls r3, #-2147483629
 *   @0x30e8ba .word 0xf8dc4620
 *   @0x30e8be uasxmi r3, r1, r4
 *   @0x30e8c2 andeq pc, r8, #8, #2
 *   @0x30e8c6 .word 0xf8dc9300
 *   @0x30e8ca .word 0xf8cd3030
 *   @0x30e8ce .word 0xf7ffc010
 *   @0x30e8d2 .word 0xf8ddfbcc
 *   @0x30e8d6 qadd16mi r12, r0, r0
 *   @0x30e8da cpsie f
 *   @0x30e8de .word 0xf8dc0210
 *   @0x30e8e2 movwls r3, #0x3c
 *   @0x30e8e6 ldrsbtlo pc, [r8], -r12
 *   @0x30e8ea blx 0xff30c8f0 <b2_toiTime+0xfffffffffebb344c>
 *   @0x30e8ee teqpl r8, #4, #10
 *   @0x30e8f2 ldrbmi r4, [r1], -r0, lsr #12
 *   @0x30e8f6 andls r6, r0, #5898240
 *   @0x30e8fa andseq pc, r8, #8, #2
 *   @0x30e8fe .word 0xf7ff681b
 *   @0x30e902 stmdavs r0!, {r2, r4, r5, r7, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x30e906 stmvs r3, {r0, r6, r9, r10, lr} ^
 *   @0x30e90a blge 0x760772 <b2_toiTime+0x72ce>
 *   @0x30e90e tstls r3, #30
 *   @0x30e912 andeq pc, r8, #8, #2
 *   @0x30e916 ldrsbtlo pc, [r4], -r12
 *   @0x30e91a movwls r9, #0x806
 *   @0x30e91e qadd16mi r11, r0, r8
 *   @0x30e922 .word 0x7124f604
 *   @0x30e926 strtmi lr, [r0], -r1
 *   @0x30e92a .word 0xf8dc4651
 *   @0x30e92e .word 0xf7ff3030
 *   @0x30e932 blls 0x68d7aa <g_SWFlinevertbuff+0x3a6e2>
 *   @0x30e936 addsmi r9, r10, #45056
 *   @0x30e93a blls 0x6c2d4e <g_SWFlinevertbuff+0x6fc86>
 *   @0x30e93e addsmi r9, r10, #12, #20
 *   @0x30e942 stmdavs r0!, {r3, r12, lr, pc} ^
 *   @0x30e946 stmdavs r3, {r0, r6, r9, r10, lr} ^
 *   @0x30e94a blge 0x6607b2 <g_SWFlinevertbuff+0xd6ea>
 *   @0x30e94e muleq r3, r3, r8
 *   @0x30e952 andeq lr, r3, r9, lsl #17
 *   @0x30e956 svceq #0xf1bb
 *   @0x30e95a stmdbls r6, {r2, r12, lr, pc}
 *   @0x30e95e eorsvs r11, lr, r1, lsr #18
 *   @0x30e962 eor r6, pc, sp, ror r0
 *   @0x30e966 .word 0xb12a9a06
 *   @0x30e96a qsub16mi r6, r0, r11
 *   @0x30e96e .word 0x7124f604
 *   @0x30e972 and r9, r3, r0, lsl #6
 *   @0x30e976 qsub16mi r6, r0, r11
 *   @0x30e97a movwls r4, #0x651
 *   @0x30e97e andeq pc, r8, #8, #2
 *   @0x30e982 .word 0xf7ff683b
 *   @0x30e986 .word 0xf504fb72
 *   @0x30e98a stmdbls sp, {r0, r1, r2, r4, r5, r8, r9, r12, lr}
 *   @0x30e98e addsmi r6, r1, #425984
 *   @0x30e992 ldmdbvs r10, {r0, r1, r8, r12, lr, pc} ^
 *   @0x30e996 addsmi r9, r3, #14336
 *   @0x30e99a ldm r9, {r1, r2, r3, r12, lr, pc}
 *   @0x30e99e movwhs r0, #0x2003
 *   @0x30e9a2 stm r8, {r0, r1, r4, r8, r9, r12, pc}
 *   @0x30e9a6 strbmi r0, [r1], -r3
 *   @0x30e9aa stmdavs r3, {r5, r6, r11, sp, lr} ^
 *   @0x30e9ae blge 0x660816 <g_SWFlinevertbuff+0xd74e>
 *   @0x30e9b2 muleq r3, r3, r8
 *   @0x30e9b6 andeq lr, r3, r9, lsl #17
 *   @0x30e9ba svceq #0xf1bb
 *   @0x30e9be strb sp, [lr, r2]
 *   @0x30e9c2 .word 0xe7654615
 *   @0x30e9c6 pop {r0, r2, r4, r12, sp, pc}
 *   @0x30e9ca strdlt r4, r5, [r2], -r0
 *   @0x30e9ce ldrblt r4, [r0, #0x770]!
 *   @0x30e9d2 stmvs r6, {r0, r2, r7, r12, sp, pc}
 *   @0x30e9d6 strmi r4, [r4], -sp, lsl #12
 *   @0x30e9da .word 0xf06f6807
 *   @0x30e9de movwhs r4, #0x0
 *   @0x30e9e2 movwls r4, #0x3631
 *   @0x30e9e6 ldmdb r0!, {r1, r3, r12, sp, lr, pc}
 *   @0x30e9ea ldmdale r10, {r0, r2, r7, r9, lr}
 *   @0x30e9ee stmibvs r3!, {r1, r2, r3, r5, r6, r8, r9, lr} ^
 *   @0x30e9f2 .word 0x21014638
 *   @0x30e9f6 movwls r6, #0x9a2
 *   @0x30e9fa movwls r10, #0x1b03
 *   @0x30e9fe .word 0xf7d94633
 *   @0x30ea02 svcls #0x3fb45
 *   @0x30ea06 stmdblt r7!, {r5, r6, r7, r8, sp, lr} ^
 *   @0x30ea0a rscvs r6, r5, r3, ror #18
 *   @0x30ea0e .word 0x61a642ab
 *   @0x30ea12 stmdavs r0!, {r0, r2, r8, r11, r12, lr, pc} ^
 *   @0x30ea16 .word 0xf7ff2182
 *   @0x30ea1a .word 0x6165fa13
 *   @0x30ea1e andhs lr, r1, r5
 *   @0x30ea22 stmdavs r0!, {r2, sp, lr, pc} ^
 *   @0x30ea26 .word 0xf7ff2140
 *   @0x30ea2a andhs pc, r0, r11, lsl #20
 *   @0x30ea2e ldcllt p0, c11, [r0, #20]!
 *   @0x30ea32 svcmi #0xf0e92d
 *   @0x30ea36 stmdavs r6, {r0, r2, r3, r7, r12, sp, pc} ^
 *   @0x30ea3a movwls r4, #0x6604
 *   @0x30ea3e movwhs r4, #0x615
 *   @0x30ea42 ldmvs r7!, {r0, r1, r8, r12, pc}
 *   @0x30ea46 andvc r9, r3, r11, lsl #6
 *   @0x30ea4a tstlt r10, r5, lsl #14
 *   @0x30ea4e stclo p8, c15, [r12], #-728
 *   @0x30ea52 .word 0xd133429a
 *   @0x30ea56 stclo p8, c15, [r4], #-856
 *   @0x30ea5a addsmi r9, pc, #3, #30
 *   @0x30ea5e .word 0xf8d6d22e
 *   @0x30ea62 .word 0x21013c28
 *   @0x30ea66 bl 0x3e8ff6 <tt_cmap2_class_rec+0xa>
 *   @0x30ea6a strls r0, [r8, -r7, asr #15]
 *   @0x30ea6e addseq r9, r2, r3, lsl #30
 *   @0x30ea72 .word 0xf8539805
 *   @0x30ea76 svcge #0xb3037
 *   @0x30ea7a .word 0xf1039701
 *   @0x30ea7e stmibvs r3!, {r0, r11}
 *   @0x30ea82 movwls r9, #0x707
 *   @0x30ea86 orreq lr, r8, #323584
 *   @0x30ea8a blx 0x34c9f8
 *   @0x30ea8e lslvs r9, r11, #20
 *   @0x30ea92 .word 0xf0402a00
 *   @0x30ea96 .word 0xf8c48085
 *   @0x30ea9a .word 0x46928014
 *   @0x30ea9e svcls #0x8e01a
 *   @0x30eaa2 orrmi pc, r0, #-2147483646
 *   @0x30eaa6 .word 0xf8d63b01
 *   @0x30eaaa .word 0xf8d60c30
 *   @0x30eaae ldmdavs r9!, {r2, r4, r5, r10, r11, sp} ^
 *   @0x30eab2 stmibeq r3, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x30eab6 eorlo pc, r3, r1, asr r8
 *   @0x30eaba movwle r4, #0xe283
 *   @0x30eabe movwls r2, #0xb303
 *   @0x30eac2 .word 0xf1bae06e
 *   @0x30eac6 mvnle r0, r0, lsl #30
 *   @0x30eaca vst2.32 {d22, d24}, [pc:128], r3
 *   @0x30eace andsvs r3, r8, r0, lsl #1
 *   @0x30ead2 beq 0x38af02 <bigtens_D2A+0x13d2>
 *   @0x30ead6 .word 0xd3f445c2
 *   @0x30eada stmibvs r1!, {r0, r3, r6, sp, lr, pc}
 *   @0x30eade strbmi r11, [r9], #-2325
 *   @0x30eae2 ldrb r6, [r5, sp, asr #32]!
 *   @0x30eae6 stmdbeq r4, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x30eaea bleq 0x34ac2e
 *   @0x30eaee addlo pc, r0, pc, asr #8
 *   @0x30eaf2 addeq lr, r3, #2048
 *   @0x30eaf6 andeq pc, r9, r1, asr #16
 *   @0x30eafa .word 0x210c9209
 *   @0x30eafe blx 0x37532c <_ZTS13C_UTF16String+0xc3d8>
 *   @0x30eb02 ldmdavs r0, {r0, r1, r3, r8, r9, r12, sp, lr, pc}
 *   @0x30eb06 stmpl r2, {r0, r6, r7, r11, r12} ^
 *   @0x30eb0a addsmi r6, r10, #4915200
 *   @0x30eb0e stmvs r9, {r0, r1, r2, r3, r4, r10, r11, r12, lr, pc}
 *   @0x30eb12 .word 0xdc1c428b
 *   @0x30eb16 ble 0x35931e
 *   @0x30eb1a .word 0xdc182900
 *   @0x30eb1e svcls #0x6b1bb
 *   @0x30eb22 eoreq pc, r11, r7, asr r8
 *   @0x30eb26 blle 0x71f56e <g_SWFvertbuff+0x4c4a6>
 *   @0x30eb2a .word 0xdc0e4288
 *   @0x30eb2e mulle lr, r8, r2
 *   @0x30eb32 bl 0xff33e9e6 <b2_toiTime+0xfffffffffebe5542>
 *   @0x30eb36 bl 0xff38eb42 <b2_toiTime+0xfffffffffec3569e>
 *   @0x30eb3a bl 0xff3cef4e <b2_toiTime+0xfffffffffec75aaa>
 *   @0x30eb3e bl 0xff38ef4a <b2_toiTime+0xfffffffffec35aa6>
 *   @0x30eb42 .word 0xf7d60000
 *   @0x30eb46 .word 0x4601f9b7
 *   @0x30eb4a .word 0x2100e003
 *   @0x30eb4e vst4.8 {d30, d31, d0, d1}, [pc], r1
 *   @0x30eb52 stmibvs r3!, {r7, r8, r12, sp}
 *   @0x30eb56 bleq 0x38af8a <_pcre_utt+0x2e>
 *   @0x30eb5a andeq pc, r9, r3, asr r8
 *   @0x30eb5e .word 0xf7d69304
 *   @0x30eb62 blls 0x44d13a <g_RomDisk+0x5591a>
 *   @0x30eb66 .word 0xf84345ab
 *   @0x30eb6a bicle r0, r6, r9
 *   @0x30eb6e svcls #0x3e7b0
 *   @0x30eb72 orrslt r6, r5, r7, lsr #1
 *   @0x30eb76 adceq r6, lr, r3, lsr #18
 *   @0x30eb7a stmdage r11, {r1, r5, r6, r7, r11, sp, lr}
 *   @0x30eb7e andls r2, r1, r1, lsl #2
 *   @0x30eb82 ldrtmi r9, [r3], -r0, lsl #6
 *   @0x30eb86 addseq r9, r2, r5, lsl #16
 *   @0x30eb8a blx 0xfe34caf6 <b2_toiTime+0xfffffffffdbf3652>
 *   @0x30eb8e .word 0x61209b0b
 *   @0x30eb92 stmdbls r6, {r0, r1, r4, r5, r8, r11, r12, sp, pc}
 *   @0x30eb96 .word 0xf5a74632
 *   @0x30eb9a movwhs lr, #0x1d10
 *   @0x30eb9e eorvc r6, r3, r5, ror #1
 *   @0x30eba2 andlt r9, sp, r11, lsl #16
 *   @0x30eba6 svchi #0xf0e8bd
 *   @0x30ebaa .word 0x4604b538
 *   @0x30ebae strmi r6, [sp], -r3, asr #18
 *   @0x30ebb2 addsmi r6, r3, #12713984
 *   @0x30ebb6 stmibvs r3!, {r0, r1, r3, r12, lr, pc} ^
 *   @0x30ebba stmvs r2!, {r0, r3, r5, r9, r10, lr}
 *   @0x30ebbe blx 0x329148
 *   @0x30ebc2 .word 0xf5a73002
 *   @0x30ebc6 stmdbvs r3!, {r1, r3, r4, r5, r6, r7, r10, r11, sp, lr, pc} ^
 *   @0x30ebca .word 0x61633301
 *   @0x30ebce stmdbvs r1, {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x30ebd2 .word 0xf7ff4419
 *   @0x30ebd6 stmdahs r0, {r2, r3, r4, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30ebda ldclt p1, c13, [r8, #-948]!
 *   @0x30ebde svcmi #0xf0e92d
 *   @0x30ebe2 stmdavs r2, {r1, r2, r4, r9, r10, lr}
 *   @0x30ebe6 strmi r11, [r4], -r9, lsl #1
 *   @0x30ebea movwhs r9, #0x305
 *   @0x30ebee ldrsbhi pc, [r12], -r2
 *   @0x30ebf2 stmibvs r2, {r0, r1, r3, sp, lr} ^
 *   @0x30ebf6 movwls r9, #0x6104
 *   @0x30ebfa .word 0xf8d4b13a
 *   @0x30ebfe stmibvs r7!, {r2, r3, sp, pc}
 *   @0x30ec02 svceq #0xf1ba
 *   @0x30ec06 sbcshi pc, r8, r0
 *   @0x30ec0a stmdavs r5, {r1, r2, r4, r5, r6, sp, lr, pc}
 *   @0x30ec0e andls r6, r7, #12779520
 *   @0x30ec12 ldrsbge pc, [r12], -r5
 *   @0x30ec16 rsble r2, r2, r0, lsl #22
 *   @0x30ec1a bleq 0x38b02e <_pcre_utt+0xd2>
 *   @0x30ec1e blge 0x4edc42 <SrcVerts+0x4ac86>
 *   @0x30ec22 movwls r9, #0x1200
 *   @0x30ec26 usaxmi r4, r11, r0
 *   @0x30ec2a .word 0xf7d92104
 *   @0x30ec2e blls 0x50d4f2 <SrcVerts+0x6a536>
 *   @0x30ec32 blhs 0x3273ba
 *   @0x30ec36 stmvs r1!, {r0, r1, r4, r6, r8, r12, lr, pc}
 *   @0x30ec3a stmdavs r3!, {r3, r5, r9, r10, lr} ^
 *   @0x30ec3e .word 0xf7d74419
 *   @0x30ec42 andls pc, r7, r1, lsr lr
 *   @0x30ec46 mrsle r2, spsr
 *   @0x30ec4a blx 0x50d880 <SrcVerts+0x6a8c4>
 *   @0x30ec4e ldrbmi r4, [r9], -r8, lsr #12
 *   @0x30ec52 .word 0xf8e6f7d9
 *   @0x30ec56 stmdahs r0, {r0, r1, r2, r12, pc}
 *   @0x30ec5a bvs 0xe03166 <b2_toiTime+0x6a9cc2>
 *   @0x30ec5e stmibvs r2!, {r1, r8, r9, r10, r11, sp} ^
 *   @0x30ec62 mulle pc, r11, r4
 *   @0x30ec66 andsle r2, r8, r3, lsl #30
 *   @0x30ec6a .word 0xd1252f01
 *   @0x30ec6e ssaxmi r4, r9, r11
 *   @0x30ec72 stmdavc r9, {r2, r9, r12, lr, pc}
 *   @0x30ec76 .word 0xf8423301
 *   @0x30ec7a ldrb r1, [r7, r4, lsl #22]!
 *   @0x30ec7e .word 0xf7d94628
 *   @0x30ec82 eor pc, r12, r10, lsl r9
 *   @0x30ec86 rscsle r4, r9, #381681664
 *   @0x30ec8a movwlo r7, #0x2818
 *   @0x30ec8e .word 0x1c01f813
 *   @0x30ec92 .word 0x2100ea41
 *   @0x30ec96 blne 0x44cda6 <g_RomDisk+0x55586>
 *   @0x30ec9a ldrbmi lr, [r11, #-0x7f4]
 *   @0x30ec9e ldmdavc r9, {r1, r2, r3, r5, r6, r7, r9, r12, lr, pc} ^
 *   @0x30eca2 .word 0xf8133303
 *   @0x30eca6 andeq r0, r9, #768
 *   @0x30ecaa .word 0x4100ea41
 *   @0x30ecae .word 0x0c01f813
 *   @0x30ecb2 .word 0xf8424301
 *   @0x30ecb6 ldrb r1, [r0, r4, lsl #22]!
 *   @0x30ecba sbcsle r4, pc, #381681664
 *   @0x30ecbe movwlo r7, #0x4859
 *   @0x30ecc2 .word 0x0c04f813
 *   @0x30ecc6 b 0x134fcf2 <b2_toiTime+0xbf684e>
 *   @0x30ecca .word 0xf8136100
 *   @0x30ecce movwmi r0, #0x1c01
 *   @0x30ecd2 .word 0x0c02f813
 *   @0x30ecd6 .word 0x2100ea41
 *   @0x30ecda blne 0x44cdea <g_RomDisk+0x555ca>
 *   @0x30ecde blls 0x508c96 <SrcVerts+0x65cda>
 *   @0x30ece2 ldrbmi r11, [r0], -r11, lsr #2
 *   @0x30ece6 .word 0xf7d869e1
 *   @0x30ecea movwhs pc, #0xb25
 *   @0x30ecee blls 0x4e7482 <SrcVerts+0x444c6>
 *   @0x30ecf2 blhs 0x333912
 *   @0x30ecf6 subs sp, pc, r1, lsl #1
 *   @0x30ecfa stcge p2, c2, [r6, #-0]
 *   @0x30ecfe strbmi r9, [r0], -r0, lsl #4
 *   @0x30ed02 .word 0x21049501
 *   @0x30ed06 movweq pc, #0x110a
 *   @0x30ed0a .word 0xf9c0f7d9
 *   @0x30ed0e strmi r9, [r1], r6, lsl #20
 *   @0x30ed12 cmple r1, r0, lsl #20
 *   @0x30ed16 smlsdls r3, r7, r4, r4
 *   @0x30ed1a strtmi r11, [r10], -r6, asr #2
 *   @0x30ed1e ldrtmi r4, [r9], -r0, asr #12
 *   @0x30ed22 blx 0x34cc8a
 *   @0x30ed26 strmi r9, [r2], r6, lsl #20
 *   @0x30ed2a sub r11, r5, r10, lsl #2
 *   @0x30ed2e bvs 0xbe07fe <b2_toiTime+0x48735a>
 *   @0x30ed32 strbmi r2, [sp], -r0, lsl #14
 *   @0x30ed36 .word 0xf04f4639
 *   @0x30ed3a vmlahs.f64 d0, d0, d1
 *   @0x30ed3e uadd16mi r11, r2, r4
 *   @0x30ed42 .word 0xf8c9461a
 *   @0x30ed46 stmvs r2!, {sp} ^
 *   @0x30ed4a stmdale r11!, {r0, r1, r4, r7, r8, r10, lr}
 *   @0x30ed4e .word 0xf85269e2
 *   @0x30ed52 .word 0xf102202b
 *   @0x30ed56 strmi r3, [r8, #0x8ff]
 *   @0x30ed5a stmibvs r2!, {r2, r8, r9, r12, lr, pc}
 *   @0x30ed5e svclt #0x284590
 *   @0x30ed62 mul r0, r0, r6
 *   @0x30ed66 ldmdblt lr, {r3, r7, r9, r10, lr}
 *   @0x30ed6a andeq lr, r8, #3072
 *   @0x30ed6e ands r6, r4, r10, rrx
 *   @0x30ed72 bl 0x52039a <SrcVerts+0x7d3de>
 *   @0x30ed76 ldrbmi r0, [r2], #-519
 *   @0x30ed7a andle r6, lr, r10, rrx
 *   @0x30ed7e ldrmi r6, [r9], #-2088
 *   @0x30ed82 strlo r9, [r1, -r2, lsl #6]
 *   @0x30ed86 .word 0xf5a71a12
 *   @0x30ed8a stmdavs r10!, {r3, r4, r10, r11, sp, lr, pc} ^
 *   @0x30ed8e .word 0x0100f04f
 *   @0x30ed92 stmdavs r10!, {r0, r4, r12, sp, lr} ^
 *   @0x30ed96 rsbvs r3, r10, r1, lsl #4
 *   @0x30ed9a .word 0xf10b9b02
 *   @0x30ed9e strlo r0, [r4, #-0xb01]
 *   @0x30eda2 ldrb r4, [r0, r1, asr #12]
 *   @0x30eda6 .word 0xf8c29a04
 *   @0x30edaa .word 0xb10e9000
 *   @0x30edae andge pc, r0, r6, asr #17
 *   @0x30edb2 .word 0xb10b9b05
 *   @0x30edb6 andsvs r9, r9, r3, lsl #18
 *   @0x30edba andlt r9, r9, r6, lsl #16
 *   @0x30edbe svchi #0xf0e8bd
 *   @0x30edc2 .word 0x4604b538
 *   @0x30edc6 orrslt r6, r0, r0, lsl #16
 *   @0x30edca stmibvs r5, {r1, r5, r9, r11, sp, lr} ^
 *   @0x30edce .word 0xf104b11a
 *   @0x30edd2 .word 0xf7d90120
 *   @0x30edd6 qadd16mi pc, r8, r9
 *   @0x30edda .word 0xf7d869e1
 *   @0x30edde smlatbhs r0, r11, r10, pc
 *   @0x30ede2 mvnvs r4, r0, lsr #12
 *   @0x30ede6 pop {r2, r5, r9, sp}
 *   @0x30edea .word 0xf00c4038
 *   @0x30edee ldclt p14, c11, [r8, #-440]!
 *   @0x30edf2 .word 0x4606b570
 *   @0x30edf6 movwlt r4, #0x160c
 *   @0x30edfa andsvc pc, r8, r1, lsl #10
 *   @0x30edfe .word 0xf7ff2500
 *   @0x30ee02 .word 0x4630ffdf
 *   @0x30ee06 addne pc, r4, #212, #16
 *   @0x30ee0a blx 0xfe84cd72 <b2_toiTime+0xfffffffffe0f38ce>
 *   @0x30ee0e .word 0xf8d44630
 *   @0x30ee12 .word 0xf8c4123c
 *   @0x30ee16 .word 0xf7d85284
 *   @0x30ee1a ldrtmi pc, [r0], -sp, lsl #21
 *   @0x30ee1e subne pc, r4, #212, #16
 *   @0x30ee22 eorspl pc, r12, #196, #16
 *   @0x30ee26 blx 0xfe4ccd8e <b2_toiTime+0xfffffffffdd738ea>
 *   @0x30ee2a subpl pc, r4, #196, #16
 *   @0x30ee2e .word 0xf8d44630
 *   @0x30ee32 .word 0xf7d81250
 *   @0x30ee36 .word 0xf8c4fa7f
 *   @0x30ee3a ldcllt p2, c5, [r0, #-320]!
 *   @0x30ee3e ldrlt r0, [r8, #-0x0]!
 *   @0x30ee42 stmdavs r3, {r2, r9, r10, lr}
 *   @0x30ee46 stmvs r2!, {r0, r2, r3, r9, r10, lr} ^
 *   @0x30ee4a ldmdavs r8, {r0, r1, r3, r4, r9, r10, r11, sp, lr} ^
 *   @0x30ee4e ldrbtmi r4, [r11], #-2831
 *   @0x30ee52 addsmi r6, r10, #1769472
 *   @0x30ee56 blmi 0x682eae <g_SWFlinevertbuff+0x2fde6>
 *   @0x30ee5a ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x30ee5e mulle pc, r10, r2
 *   @0x30ee62 ldrbtmi r4, [r9], #-2316
 *   @0x30ee66 .word 0xf843f7d7
 *   @0x30ee6a andhs r4, r0, #180224
 *   @0x30ee6e .word 0xf7d74479
 *   @0x30ee72 .word 0xb140f861
 *   @0x30ee76 .word 0xb12b6803
 *   @0x30ee7a strtmi r4, [r9], -r0, lsr #12
 *   @0x30ee7e ldclt p7, c4, [r8, #-608]!
 *   @0x30ee82 ldclt p0, c2, [r8, #-600]!
 *   @0x30ee86 ldclt p6, c4, [r8, #-96]!
 *   @0x30ee8a stchs p15, c11, [r8, #0]!
 *   @0x30ee8e stchs p0, c0, [r2, #56]!
 *   @0x30ee92 stc2l p0, c0, [r11, #-56]
 *   @0x30ee96 .word 0xf8a90007
 *   @0x30ee9a ldrlt r0, [r8, #-0x7]!
 *   @0x30ee9e stmvs r3, {r2, r9, r10, lr}
 *   @0x30eea2 adcpl pc, r0, #208, #16
 *   @0x30eea6 .word 0xf8d0071b
 *   @0x30eeaa ldrle r2, [r1, #-0x21c]
 *   @0x30eeae cdpvs p1, #0x0, c11, c3, c2, #0x4
 *   @0x30eeb2 ldmdavs r8, {r0, r3, r8, r11, lr} ^
 *   @0x30eeb6 .word 0xf7d74479
 *   @0x30eeba stmdbmi r7, {r1, r3, r4, r11, r12, sp, lr, pc}
 *   @0x30eebe ldrbtmi r2, [r9], #-512
 *   @0x30eec2 rfeda r8!
 *   @0x30eec6 stmdavs r3, {r5, r8, r12, sp, pc}
 *   @0x30eeca qadd16mi r11, r0, r3
 *   @0x30eece ldclt p7, c4, [r8, #-608]!
 *   @0x30eed2 strbeq pc, [r4, #-0x8d5]
 *   @0x30eed6 ldc2l p13, c11, [r9], #224
 *   @0x30eeda rfeda r7!
 *   @0x30eede ldrblt r0, [r8, #0x7]!
 *   @0x30eee2 .word 0xf8d04605
 *   @0x30eee6 strmi r4, [lr], -r0, lsr #5
 *   @0x30eeea blhs 0x3ae77e <error_g0017+0x7422>
 *   @0x30eeee mcrvs p1, #0x0, sp, c3, c4, #0x0
 *   @0x30eef2 ldmdavs r8, {r5, r8, r11, lr} ^
 *   @0x30eef6 .word 0xf7d64479
 *   @0x30eefa ldmdbmi lr, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30eefe ldrbtmi r2, [r9], #-512
 *   @0x30ef02 .word 0xf818f7d7
 *   @0x30ef06 andhs r11, r0, r8, lsl #18
 *   @0x30ef0a stmdavs r3, {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc} ^
 *   @0x30ef0e rscsle r2, r10, r0, lsl #22
 *   @0x30ef12 ldrtmi r4, [r1], -r8, lsr #12
 *   @0x30ef16 ldcllt p7, c4, [r8, #608]!
 *   @0x30ef1a andhs r4, r1, #24, #18
 *   @0x30ef1e ldrbtmi r6, [r9], #-3584
 *   @0x30ef22 .word 0xf808f7d7
 *   @0x30ef26 stmdahs r0, {r0, r1, r2, r9, r10, lr}
 *   @0x30ef2a strhs sp, [r0, #-0xed]
 *   @0x30ef2e addsmi r6, sp, #1622016
 *   @0x30ef32 .word 0xf8d4d2e9
 *   @0x30ef36 rfeda r3!
 *   @0x30ef3a .word 0xf5b00015
 *   @0x30ef3e stmdble r11, {r0, r1, r6, r7, r8, r9, r10, r11, r12, sp, lr}
 *   @0x30ef42 strbhs pc, [r12, #-0x8d4]
 *   @0x30ef46 bicvc pc, r3, #1862270976
 *   @0x30ef4a addsmi r1, r3, #12779520
 *   @0x30ef4e .word 0xf8d4d20c
 *   @0x30ef52 .word 0xf8522550
 *   @0x30ef56 and r1, r2, r3, lsr #32
 *   @0x30ef5a .word 0x4790697a
 *   @0x30ef5e tstlt r9, r1, lsl #12
 *   @0x30ef62 .word 0xf5a74630
 *   @0x30ef66 .word 0xb108eb06
 *   @0x30ef6a ldrb r3, [pc, r1, lsl #10]
 *   @0x30ef6e ldcllt p6, c4, [r8, #160]!
 *   @0x30ef72 ldc2 p15, c11, [r9], #0
 *   @0x30ef76 .word 0xf7ec0007
 *   @0x30ef7a .word 0xf9990007
 *   @0x30ef7e push {r0, r1, r2}
 *   @0x30ef82 .word 0x460d43f7
 *   @0x30ef86 .word 0xf8d14604
 *   @0x30ef8a .word 0x4691801c
 *   @0x30ef8e eorhs r2, r4, #0, #2
 *   @0x30ef92 .word 0xf5a7461f
 *   @0x30ef96 eorvs lr, r5, r12, lsl #22
 *   @0x30ef9a cdpge p6, #0x0, c4, c1, c8, #0x1
 *   @0x30ef9e stc2l p7, c15, [pc], {215}
 *   @0x30efa2 rsbvs r4, r0, r1, lsr r6
 *   @0x30efa6 teqlt pc, r8, lsr #12
 *   @0x30efaa .word 0xff0bf7d7
 *   @0x30efae strmi r9, [r7], -r1, lsl #22
 *   @0x30efb2 teqle sp, r0, lsl #22
 *   @0x30efb6 and r2, r6, r5, lsl #6
 *   @0x30efba stc2 p7, c15, [r3, #860]!
 *   @0x30efbe blhs 0x335bca
 *   @0x30efc2 .word 0x4607d136
 *   @0x30efc6 adcvs r2, r3, r3, lsl #6
 *   @0x30efca eorsle r2, r1, r0, lsl #30
 *   @0x30efce ldrtmi r4, [r1], -r8, lsr #12
 *   @0x30efd2 ldc2l p7, c15, [r2, #-860]!
 *   @0x30efd6 bllt 0x19b57e2 <b2_toiTime+0x125c33e>
 *   @0x30efda cdpne p2, #0x5, c11, c10, c3, #0x6
 *   @0x30efde ldmdale r6, {r0, r1, r9, r11, sp}
 *   @0x30efe2 strlo r6, [r1, -r7, ror #1]
 *   @0x30efe6 blx 0x4e9270 <SrcVerts+0x462b4>
 *   @0x30efea stmdavs r2!, {r0, r1, r8, r12, sp, lr, pc} ^
 *   @0x30efee strmi r7, [r2], #-1059
 *   @0x30eff2 strmi r4, [r10], #-1576
 *   @0x30eff6 smulbtvs r2, r9, r10
 *   @0x30effa ldc2 p7, c15, [r9], {215}
 *   @0x30effe ldmiblt r8!, {r0, r12, pc}
 *   @0x30f002 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x30f006 .word 0xf96df7ff
 *   @0x30f00a stmiblt r11, {r0, r8, r9, r11, r12, pc}
 *   @0x30f00e movwhs r11, #0x8910
 *   @0x30f012 and r9, sp, r1, lsl #6
 *   @0x30f016 strtmi r1, [r8], -r1, asr #28
 *   @0x30f01a .word 0xf1b961a1
 *   @0x30f01e andle r0, r4, r0, lsl #30
 *   @0x30f022 eoreq pc, r0, #4, #2
 *   @0x30f026 .word 0xff3cf7d8
 *   @0x30f02a .word 0xf7d7e001
 *   @0x30f02e andls pc, r1, r0, lsl #25
 *   @0x30f032 .word 0xb12b9b01
 *   @0x30f036 stmibvs r1!, {r6, r9, r10, lr} ^
 *   @0x30f03a .word 0xf97cf7d8
 *   @0x30f03e mvnvs r2, r0, lsl #6
 *   @0x30f042 andlt r9, r3, r1, lsl #16
 *   @0x30f046 mvnshi lr, #12386304
 *   @0x30f04a .word 0xe92d0000
 *   @0x30f04e .word 0x460541f0
 *   @0x30f052 strmi r4, [r8], -pc, lsl #12
 *   @0x30f056 addlt r4, r10, r0, asr r9
 *   @0x30f05a sadd16mi r4, lr, r4
 *   @0x30f05e .word 0xf5a74479
 *   @0x30f062 stmdahs r0, {r3, r7, r9, r11, sp, lr, pc}
 *   @0x30f066 movwlt sp, #0xe14e
 *   @0x30f06a stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x30f06e andhs r4, r10, #6291456
 *   @0x30f072 strbmi r4, [r1], -r0, lsr #12
 *   @0x30f076 .word 0xf5a7af02
 *   @0x30f07a blls 0x389c6a <bigtens_D2A+0x13a>
 *   @0x30f07e bhs 0xe2d0ee <b2_toiTime+0x6d3c4a>
 *   @0x30f082 ldrhle r5, [pc, #-24]!
 *   @0x30f086 .word 0xd07d429c
 *   @0x30f08a mrrcne p6, #0x0, r3, r12, c4
 *   @0x30f08e mvnle r2, r12, lsl lr
 *   @0x30f092 strtmi r2, [r0], -r10, lsl #4
 *   @0x30f096 .word 0xf5a74641
 *   @0x30f09a blls 0x389c4a <bigtens_D2A+0x11a>
 *   @0x30f09e .word 0xf012781a
 *   @0x30f0a2 ldrdls r0, r1, [r9], -pc
 *   @0x30f0a6 addsmi sp, r12, #-2147483621
 *   @0x30f0aa ldrtmi sp, [r12], -r12, rrx
 *   @0x30f0ae mulne r1, r4, r8
 *   @0x30f0b2 stmdahs r0, {r1, r5, r7, r11, sp, lr}
 *   @0x30f0b6 stmdbvs r3!, {r0, r1, r2, r5, r6, r7, r11, sp, lr}
 *   @0x30f0ba stmibvs r1!, {r1, r2, r5, r6, r8, r11, sp, lr}
 *   @0x30f0be blle 0x1b69856 <b2_toiTime+0x14103b2>
 *   @0x30f0c2 blle 0x1ad98ca <b2_toiTime+0x1380426>
 *   @0x30f0c6 blle 0x1a59cce <b2_toiTime+0x130082a>
 *   @0x30f0ca blle 0x19d94d2 <b2_toiTime+0x128002e>
 *   @0x30f0ce mrrcle p2, #0x9, r4, r9, c0
 *   @0x30f0d2 mrrcle p2, #0x9, r4, r7, c10
 *   @0x30f0d6 mrrcle p2, #0x8, r4, r5, c11
 *   @0x30f0da svcvc #0xfaf5bc
 *   @0x30f0de .word 0xf5b7d852
 *   @0x30f0e2 stmdale pc, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr} ^
 *   @0x30f0e6 svcvc #0xfaf5b6
 *   @0x30f0ea .word 0xf5b4d84c
 *   @0x30f0ee stmdale r9, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr} ^
 *   @0x30f0f2 .word 0xf8c56268
 *   @0x30f0f6 rscvs r12, r10, #40
 *   @0x30f0fa .word 0x636b632f
 *   @0x30f0fe .word 0x63e963ae
 *   @0x30f102 eors r6, sp, r12, lsr #8
 *   @0x30f106 ldrtmi r4, [r8], -r5, lsr #18
 *   @0x30f10a .word 0xf5a74479
 *   @0x30f10e ldmdblt r8!, {r1, r4, r5, r9, r11, sp, lr, pc} ^
 *   @0x30f112 stmdbmi r2!, {r1, r2, r3, r6, r8, r12, sp, pc}
 *   @0x30f116 ldrbtmi r4, [r9], #-1568
 *   @0x30f11a b 0xe4c7be <b2_toiTime+0x6f331a>
 *   @0x30f11e teqle r1, r0, lsl #16
 *   @0x30f122 mvnvs r2, r1, lsl #6
 *   @0x30f126 stmdavs r3!, {r1, r4, r5, sp, lr, pc}
 *   @0x30f12a .word 0xd12d2b01
 *   @0x30f12e eor r6, r7, r11, ror #3
 *   @0x30f132 shadd16mi r4, r8, r12
 *   @0x30f136 .word 0xf5a74479
 *   @0x30f13a pkhbtmi lr, r0, r12, lsl #20
 *   @0x30f13e cmplt r6, r8, ror r9
 *   @0x30f142 strbmi r4, [r1], -r0, lsr #12
 *   @0x30f146 .word 0xf5a7220a
 *   @0x30f14a ldmdblt r0, {r1, r4, r7, r9, r11, sp, lr, pc}
 *   @0x30f14e eoreq pc, r0, r5, lsl #17
 *   @0x30f152 movwhs lr, #0x101d
 *   @0x30f156 stmdavc r3!, {sp, lr, pc}
 *   @0x30f15a eorlo pc, r0, r5, lsl #17
 *   @0x30f15e ldmdbmi r1, {r4, sp, lr, pc}
 *   @0x30f162 ldrbtmi r4, [r9], #-1592
 *   @0x30f166 b 0x4cc80a <SrcVerts+0x2984e>
 *   @0x30f16a ldmdblt r8!, {r0, r9, r10, lr} ^
 *   @0x30f16e strtmi r11, [r0], -r6, lsr #2
 *   @0x30f172 .word 0xf5a7220a
 *   @0x30f176 and lr, r0, r12, ror r10
 *   @0x30f17a b 0xb29202 <b2_toiTime+0x3cfd5e>
 *   @0x30f17e strbtvs r7, [r8], #-224
 *   @0x30f182 and r2, r4, r0
 *   @0x30f186 and r2, r2, r6
 *   @0x30f18a and r2, r0, r7
 *   @0x30f18e andlt r2, r10, r12
 *   @0x30f192 ldrhhi lr, [r0, #141]!
 *   @0x30f196 .word 0xff38bf00
 *   @0x30f19a ldreq r0, [r7, #-0x7]!
 *   @0x30f19e ldreq r0, [r8, #-0x8]!
 *   @0x30f1a2 cdp2 p0, #0x7, c0, c5, c8, #0x0
 *   @0x30f1a6 ldrbteq r0, [r2], #7
 *   @0x30f1aa stmdb sp!, {r3}
 *   @0x30f1ae stmdahs r0, {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x30f1b2 stmdahi r6, {r1, r6, r12, lr, pc}
 *   @0x30f1b6 blhs 0x37ba8a <_ZTS13C_UTF16String+0x12b36>
 *   @0x30f1ba .word 0xf103dd07
 *   @0x30f1be stmvs r1, {r9, lr} ^
 *   @0x30f1c2 rfedb r1!
 *   @0x30f1c6 andlo r2, r1, #18
 *   @0x30f1ca andhs lr, r0, #0
 *   @0x30f1ce eorslt r8, sp, #4653056
 *   @0x30f1d2 ldcle p13, c2, [sp, #-4]
 *   @0x30f1d6 .word 0xf1056841
 *   @0x30f1da .word 0x3c015400
 *   @0x30f1de .word 0xc008f8d0
 *   @0x30f1e2 stmibeq r2, {r0, r8, r9, r11, sp, lr, pc} ^
 *   @0x30f1e6 eorsge pc, r2, r1, asr r8
 *   @0x30f1ea stmeq r4, {r0, r8, r9, r11, sp, lr, pc} ^
 *   @0x30f1ee eorsne pc, r4, r1, asr r8
 *   @0x30f1f2 smlabble sp, r10, r5, r4
 *   @0x30f1f6 .word 0x4004f8d9
 *   @0x30f1fa .word 0x1004f8d8
 *   @0x30f1fe smlabble r7, r12, r2, r4
 *   @0x30f202 .word 0xf8154465
 *   @0x30f206 stmdbhs r1, {r0, r10, r11, r12}
 *   @0x30f20a .word 0xf107bf04
 *   @0x30f20e strdhi r3, r4, [r7], #-127
 *   @0x30f212 vldrle d2, [r1, #-0]
 *   @0x30f216 andlt r8, r12, #4259840
 *   @0x30f21a adcmi r3, r2, #256
 *   @0x30f21e rscslo pc, pc, #1073741824
 *   @0x30f222 cdplo p1, #0x0, c13, c1, c4, #0x0
 *   @0x30f226 andhi r8, r6, r2, asr #32
 *   @0x30f22a .word 0x87f0e8bd
 *   @0x30f22e movwmi pc, #0x103
 *   @0x30f232 bllo 0x36953e <_ZTS13C_UTF16String+0x5ea>
 *   @0x30f236 andshs pc, r3, r1, lsr #16
 *   @0x30f23a .word 0x87f0e8bd
 *   @0x30f23e stmibvs r4, {r4, r8, r10, r12, sp, pc} ^
 *   @0x30f242 .word 0xf7ff6960
 *   @0x30f246 movwhs pc, #0xfb2
 *   @0x30f24a sublo pc, r0, r4, lsl #17
 *   @0x30f24e strlt r11, [r8, #-0xd10]
 *   @0x30f252 stmvs r2, {r0, r1, r6, r7, r11, sp, lr}
 *   @0x30f256 andle r4, r3, #805306377
 *   @0x30f25a sbcvs r1, r2, r10, asr r12
 *   @0x30f25e stclt p8, c7, [r8, #-96]
 *   @0x30f262 cmphs r5, r0, lsl #16
 *   @0x30f266 stc2l p7, c15, [r12, #1016]!
 *   @0x30f26a stclt p0, c2, [r8, #-0]
 *   @0x30f26e andeq pc, r8, #0, #2
 *   @0x30f272 bgt 0xa3c6ba <b2_toiTime+0x2e3216>
 *   @0x30f276 sbceq lr, r4, #2048
 *   @0x30f27a swple r4, r3, [r5]
 *   @0x30f27e orrhs r6, r2, r0, asr #16
 *   @0x30f282 ldrhmi lr, [r0], -sp
 *   @0x30f286 ldcllt p7, c15, [r12, #1016]
 *   @0x30f28a andhs r6, r2, #25
 *   @0x30f28e subsvs r6, r10, r3, asr #17
 *   @0x30f292 movwlo r6, #0x88c3
 *   @0x30f296 ldclt p0, c6, [r0, #-780]
 *   @0x30f29a andeq pc, r8, #0, #2
 *   @0x30f29e bgt 0xa3c6e6 <b2_toiTime+0x2e3242>
 *   @0x30f2a2 sbceq lr, r4, #2048
 *   @0x30f2a6 swple r4, r3, [r5]
 *   @0x30f2aa orrhs r6, r2, r0, asr #16
 *   @0x30f2ae ldrhmi lr, [r0], -sp
 *   @0x30f2b2 stcllt p7, c15, [r6, #1016]
 *   @0x30f2b6 andhs r6, r0, #25
 *   @0x30f2ba subsvs r6, r10, r3, asr #17
 *   @0x30f2be movwlo r6, #0x88c3
 *   @0x30f2c2 ldclt p0, c6, [r0, #-780]
 *   @0x30f2c6 stmvs r3, {r3, r8, r10, r12, sp, pc} ^
 *   @0x30f2ca addsmi r6, r3, #8519680
 *   @0x30f2ce stmdavs r0, {r1, r8, r12, lr, pc} ^
 *   @0x30f2d2 and r2, r5, r1, lsr #3
 *   @0x30f2d6 .word 0x2c04f853
 *   @0x30f2da andle r2, r5, r2, lsl #20
 *   @0x30f2de asrhs r6, r0, #16
 *   @0x30f2e2 stc2 p7, c15, [lr, #1016]!
 *   @0x30f2e6 stclt p0, c2, [r8, #-0]
 *   @0x30f2ea andeq pc, r8, #-1073741784
 *   @0x30f2ee .word 0xf85360c2
 *   @0x30f2f2 stclt p12, c0, [r8, #-32]
 *   @0x30f2f6 stmvs r3, {r3, r8, r10, r12, sp, pc} ^
 *   @0x30f2fa addsmi r6, r3, #8519680
 *   @0x30f2fe stmdavs r0, {r0, r2, r8, r12, lr, pc} ^
 *   @0x30f302 .word 0xf7fe21a1
 *   @0x30f306 mulhs r0, sp, sp
 *   @0x30f30a .word 0xf1a3bd08
 *   @0x30f30e sbcvs r0, r2, r8, lsl #4
 *   @0x30f312 andeq lr, r5, r3, lsl r9
 *   @0x30f316 andle r2, r3, r1, lsl #20
 *   @0x30f31a .word 0xd10c2a02
 *   @0x30f31e stclt p4, c0, [r8, #-0]
 *   @0x30f322 ble 0x41932a <g_RomDisk+0x21b0a>
 *   @0x30f326 andpl pc, r0, r0, asr #11
 *   @0x30f32a submi r1, r0, #128, #6
 *   @0x30f32e .word 0xf500bd08
 *   @0x30f332 orrne r5, r0, #0
 *   @0x30f336 stclt p13, c11, [r8, #-32]
 *   @0x30f33a stmvs r3, {r3, r8, r10, r12, sp, pc}
 *   @0x30f33e bne 0xff7a964e <b2_toiTime+0xffffffffff0501aa>
 *   @0x30f342 svceq #0xe2ebb1
 *   @0x30f346 stmdavs r0, {r0, r2, r8, r9, r12, lr, pc} ^
 *   @0x30f34a .word 0xf7fe2182
 *   @0x30f34e andhs pc, r0, r9, ror sp
 *   @0x30f352 bl 0x3fe77a <g_RomDisk+0x6f5a>
 *   @0x30f356 .word 0xf85302c1
 *   @0x30f35a ldmdavs r2, {r0, r4, r5} ^
 *   @0x30f35e andle r2, r3, r1, lsl #20
 *   @0x30f362 .word 0xd10c2a02
 *   @0x30f366 stclt p4, c0, [r8, #-0]
 *   @0x30f36a ble 0x419372 <g_RomDisk+0x21b52>
 *   @0x30f36e andpl pc, r0, r0, asr #11
 *   @0x30f372 submi r1, r0, #128, #6
 *   @0x30f376 .word 0xf500bd08
 *   @0x30f37a orrne r5, r0, #0
 *   @0x30f37e stclt p13, c11, [r8, #-32]
 *   @0x30f382 .word 0x43f8e92d
 *   @0x30f386 stmdahs r0, {r0, r1, r2, r9, r10, lr}
 *   @0x30f38a adchi pc, r11, r0
 *   @0x30f38e andslo pc, r12, #208, #16
 *   @0x30f392 .word 0x9064f8d0
 *   @0x30f396 ldmvs r11, {r0, r1, r3, r8, r12, sp, pc} ^
 *   @0x30f39a .word 0xf8d74798
 *   @0x30f39e .word 0x2c0042a0
 *   @0x30f3a2 addshi pc, r9, r0
 *   @0x30f3a6 rsbeq pc, r12, r4, lsl #2
 *   @0x30f3aa .word 0xf7ff68a5
 *   @0x30f3ae .word 0xf504fd09
 *   @0x30f3b2 .word 0xf7ff609b
 *   @0x30f3b6 .word 0xf104fd05
 *   @0x30f3ba .word 0xf7ff0024
 *   @0x30f3be vadd.f32 d15, d4, d1
 *   @0x30f3c2 .word 0xf7ff40b4
 *   @0x30f3c6 .word 0xf8d4fcfd
 *   @0x30f3ca .word 0xb1ab37e8
 *   @0x30f3ce .word 0xf8d42600
 *   @0x30f3d2 addsmi r3, lr, #232, #14
 *   @0x30f3d6 bl 0x443bfe <g_RomDisk+0x4c3de>
 *   @0x30f3da strtmi r0, [r8], -r6, lsl #7
 *   @0x30f3de .word 0xf8d33601
 *   @0x30f3e2 .word 0xf7ff17ec
 *   @0x30f3e6 ldrb pc, [r2, r5, lsl #26]!
 *   @0x30f3ea .word 0xf8d44628
 *   @0x30f3ee .word 0xf7d717ec
 *   @0x30f3f2 movwhs pc, #0xfa1
 *   @0x30f3f6 strblo pc, [r12, r4, asr #17]!
 *   @0x30f3fa strhs r6, [r0], -r3, ror #16
 *   @0x30f3fe addsvs pc, r0, r4, asr #17
 *   @0x30f402 addsvs pc, r4, r4, asr #17
 *   @0x30f406 addsvs pc, r8, r4, asr #17
 *   @0x30f40a ldrsbhi pc, [r12], -r3
 *   @0x30f40e strtne pc, [r8], #2260
 *   @0x30f412 .word 0xf7d74640
 *   @0x30f416 strbmi pc, [r0], -pc, lsl #31
 *   @0x30f41a strtne pc, [r4], #2260
 *   @0x30f41e strtvs pc, [r8], #2244
 *   @0x30f422 strtvs pc, [r12], #2244
 *   @0x30f426 .word 0xff86f7d7
 *   @0x30f42a eormi pc, r4, r4, lsl #12
 *   @0x30f42e .word 0xf8c44629
 *   @0x30f432 .word 0xf8c464a4
 *   @0x30f436 .word 0xf8c4649c
 *   @0x30f43a .word 0xf7fe64a0
 *   @0x30f43e qsub16mi pc, r8, r6
 *   @0x30f442 cmppl r12, r4, lsl #4
 *   @0x30f446 ldc2l p7, c15, [r4], {255}
 *   @0x30f44a bllo 0x4d7a2
 *   @0x30f44e tstlt r11, r0, ror #16
 *   @0x30f452 mvnslo pc, r4, lsl #12
 *   @0x30f456 ldc2l p7, c15, [r8], {216}
 *   @0x30f45a strtmi r2, [r8], -r0, lsl #12
 *   @0x30f45e .word 0x1c10f8d4
 *   @0x30f462 blvs 0x14d77a <_Z30F_PhysicsSetParticleGroupFlagsR6RValueP9CInstanceS2_iPS_+0x3e>
 *   @0x30f466 blvs 0xffe4d67e <b2_toiTime+0xffffffffff6f41da>
 *   @0x30f46a blvs 0xfff4d782 <b2_toiTime+0xffffffffff7f42de>
 *   @0x30f46e .word 0xff62f7d7
 *   @0x30f472 .word 0xf8d44628
 *   @0x30f476 .word 0xf8c41544
 *   @0x30f47a .word 0xf7d76c10
 *   @0x30f47e qsaxmi pc, r8, r11
 *   @0x30f482 strbne pc, [r8, #-0x8d4]
 *   @0x30f486 strbvs pc, [r4, #-0x8c4]
 *   @0x30f48a .word 0xff54f7d7
 *   @0x30f48e .word 0xf8d44628
 *   @0x30f492 .word 0xf8c41550
 *   @0x30f496 .word 0xf7d76548
 *   @0x30f49a .word 0xf8c4ff4d
 *   @0x30f49e qsaxmi r6, r8, r0
 *   @0x30f4a2 ldrbne pc, [r4, #-0x8d4]
 *   @0x30f4a6 .word 0xff46f7d7
 *   @0x30f4aa stclo p8, c15, [r0], #-848
 *   @0x30f4ae ldrbvs pc, [r4, #-0x8c4]
 *   @0x30f4b2 .word 0xf8d4b14b
 *   @0x30f4b6 .word 0x47980c1c
 *   @0x30f4ba .word 0xf8d44628
 *   @0x30f4be .word 0xf7d71c1c
 *   @0x30f4c2 .word 0xf8c4ff39
 *   @0x30f4c6 .word 0x46486c1c
 *   @0x30f4ca adcne pc, r0, #14090240
 *   @0x30f4ce .word 0xff32f7d7
 *   @0x30f4d2 .word 0xf8c72300
 *   @0x30f4d6 ldrtmi r3, [r8], -r0, lsr #5
 *   @0x30f4da stc2l p7, c15, [r5], #-1016
 *   @0x30f4de .word 0xf8c72300
 *   @0x30f4e2 pop {r3, r4, r5, r7, r9, r12, sp}
 *   @0x30f4e6 ldrlt r8, [r0, #-0x3f8]
 *   @0x30f4ea adclo pc, r0, #208, #16
 *   @0x30f4ee .word 0xf8d34909
 *   @0x30f4f2 ldrbtmi r4, [r9], #-3080
 *   @0x30f4f6 ldmdavs r8, {r0, r1, r9, r10, r11, sp, lr} ^
 *   @0x30f4fa ldc2l p7, c15, [r9], #856
 *   @0x30f4fe teqlt r0, r3, lsl #12
 *   @0x30f502 stmdavs r3!, {r2, r3, r4, r8, r12, sp, pc}
 *   @0x30f506 .word 0x4798b11b
 *   @0x30f50a qadd16mi r11, r0, r0
 *   @0x30f50e sadd16mi r11, r8, r0
 *   @0x30f512 .word 0xf6a2bd10
 *   @0x30f516 push {r0, r1, r2}
 *   @0x30f51a .word 0x46044ff0
 *   @0x30f51e addlt r6, r5, r1, asr #5
 *   @0x30f522 .word 0xf7d56800
 *   @0x30f526 stmdavs r0!, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30f52a .word 0xffddf7ff
 *   @0x30f52e stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x30f532 stmdavs r3!, {r3, r4, r5, r12, lr, pc}
 *   @0x30f536 stmdbvs r1!, {r8, r9, r10, sp}
 *   @0x30f53a .word 0xf8d36962
 *   @0x30f53e bvs 0xfebeffc6 <b2_toiTime+0xfffffffffe496b22>
 *   @0x30f542 strls pc, [r0, #0x8d8]!
 *   @0x30f546 .word 0xa000f8d3
 *   @0x30f54a smladxls r0, r11, r6, r4
 *   @0x30f54e .word 0xf8da6845
 *   @0x30f552 strmi r0, [r8, r0]!
 *   @0x30f556 ubfxpl pc, r8, #0x11, #0x9
 *   @0x30f55a stclo p3, c11, [r1, #-148]
 *   @0x30f55e bleq 0xfe489ea2 <b2_toiTime+0xfffffffffdd309fe>
 *   @0x30f562 movweq lr, #0xbb08
 *   @0x30f566 ubfxlo pc, r3, #0x11, #0xd
 *   @0x30f56a ldrmi r6, [r9, #0xc5f]!
 *   @0x30f56e strbmi sp, [r9], -lr
 *   @0x30f572 stmdbvs r0!, {r1, r3, r4, r5, r9, r10, lr}
 *   @0x30f576 blx 0xffb8d4d4 <b2_toiTime+0xffffffffff434030>
 *   @0x30f57a .word 0x4649463a
 *   @0x30f57e stmdbvs r0!, {r0, r1, r9, r10, lr} ^
 *   @0x30f582 .word 0xf7d59303
 *   @0x30f586 blls 0x40e4f6 <g_RomDisk+0x16cd6>
 *   @0x30f58a and r4, r1, r2, lsl #12
 *   @0x30f58e stmdbvs r2!, {r0, r1, r5, r8, r11, sp, lr} ^
 *   @0x30f592 .word 0x010beb0a
 *   @0x30f596 andls r2, r0, r0
 *   @0x30f59a ldrmi r6, [r9], -r8, asr #16
 *   @0x30f59e movwhs r6, #0x877
 *   @0x30f5a2 .word 0xe7d947b8
 *   @0x30f5a6 andlt r2, r5, r0
 *   @0x30f5aa svchi #0xf0e8bd
 *   @0x30f5ae ldrblt r4, [r8, #0x602]!
 *   @0x30f5b2 stmdavs r0, {r1, r4, r7, r9, r11, sp, lr}
 *   @0x30f5b6 mcrvs p8, #0x2, r6, c7, c4, #0x0
 *   @0x30f5ba adcpl pc, r0, #208, #16
 *   @0x30f5be .word 0xf7ffb1bc
 *   @0x30f5c2 .word 0x4606ff92
 *   @0x30f5c6 ldrtmi r11, [r8], -r8, lsr #18
 *   @0x30f5ca pop {r0, r5, r9, r10, lr}
 *   @0x30f5ce .word 0xf7d740f8
 *   @0x30f5d2 stmvs r3, {r0, r4, r5, r7, r9, r10, r11, r12, sp, pc}
 *   @0x30f5d6 ldrmi r6, [r8, r0, lsr #16]
 *   @0x30f5da ubfxpl pc, r5, #0x11, #0x9
 *   @0x30f5de rscsle r2, r2, r0, lsl #26
 *   @0x30f5e2 ldmvs r3!, {r0, r8, r10, r11, r12, sp}
 *   @0x30f5e6 addeq lr, r5, #4, #22
 *   @0x30f5ea .word 0x47986850
 *   @0x30f5ee ldcllt p7, c14, [r8, #984]!
 *   @0x30f5f2 svcmi #0xf0e92d
 *   @0x30f5f6 stmdavs r0, {r2, r9, r10, lr}
 *   @0x30f5fa strmi r11, [sp], -r7, lsl #1
 *   @0x30f5fe ldreq r6, [r11, r3, lsl #17]
 *   @0x30f602 .word 0xf8d0d50e
 *   @0x30f606 bge 0x45be7e <g_RomDisk+0x6465e>
 *   @0x30f60a .word 0x47986e9b
 *   @0x30f60e .word 0xf04fb118
 *   @0x30f612 rscvs r3, r3, #-67108861
 *   @0x30f616 strtmi lr, [r0], -r4
 *   @0x30f61a .word 0xf7ff9905
 *   @0x30f61e sub pc, r4, r12, ror pc
 *   @0x30f622 strtmi r6, [r9], -r0, lsr #16
 *   @0x30f626 .word 0xffaff7d5
 *   @0x30f62a .word 0xf7ff6820
 *   @0x30f62e .word 0x4606ff5c
 *   @0x30f632 andhs r11, r0, r8, lsl #18
 *   @0x30f636 stmdavs r3!, {r0, r3, r4, r5, sp, lr, pc}
 *   @0x30f63a stmdbvs r1!, {r8, r9, r10, sp}
 *   @0x30f63e .word 0xf8d36962
 *   @0x30f642 bvs 0xfebf00ca <b2_toiTime+0xfffffffffe496c26>
 *   @0x30f646 strls pc, [r0, #0x8d8]!
 *   @0x30f64a .word 0xa000f8d3
 *   @0x30f64e smladxls r0, r11, r6, r4
 *   @0x30f652 .word 0xf8da6845
 *   @0x30f656 strmi r0, [r8, r0]!
 *   @0x30f65a ubfxpl pc, r8, #0x11, #0x9
 *   @0x30f65e rscle r2, r8, r0, lsl #26
 *   @0x30f662 b 0x16dea6e <b2_toiTime+0xf855ca>
 *   @0x30f666 bl 0x512482 <SrcVerts+0x6f4c6>
 *   @0x30f66a .word 0xf8d3030b
 *   @0x30f66e mrrcvs p7, #0xe, r3, pc, c12
 *   @0x30f672 strhle r4, [lr], -r9
 *   @0x30f676 ldrtmi r4, [r10], -r9, asr #12
 *   @0x30f67a .word 0xf7d56920
 *   @0x30f67e shsaxmi pc, r10, lr
 *   @0x30f682 strmi r4, [r3], -r9, asr #12
 *   @0x30f686 movwls r6, #0x3960
 *   @0x30f68a blx 0x190d5e8 <b2_toiTime+0x11b4144>
 *   @0x30f68e strmi r9, [r2], -r3, lsl #22
 *   @0x30f692 stmdbvs r3!, {r0, sp, lr, pc}
 *   @0x30f696 bl 0x5a9c26 <g_SWFlineaavertbuff+0x56b5e>
 *   @0x30f69a andhs r0, r0, r11, lsl #2
 *   @0x30f69e stmdavs r8, {r12, pc} ^
 *   @0x30f6a2 ldmdavs r7!, {r0, r3, r4, r9, r10, lr} ^
 *   @0x30f6a6 ldrmi r2, [r8, r0, lsl #6]!
 *   @0x30f6aa ldrdlt lr, pc, [r7], -r8
 *   @0x30f6ae svchi #0xf0e8bd
 *   @0x30f6b2 ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x30f6b6 .word 0x4604b0b2
 *   @0x30f6ba movwhs r6, #0x800
 *   @0x30f6be .word 0xf7ff9300
 *   @0x30f6c2 pkhbtmi pc, r0, r2, lsl #30
 *   @0x30f6c6 eorsle r2, r7, r0, lsl #16
 *   @0x30f6ca vadd.i8 d22, d0, d19
 *   @0x30f6ce strbtmi r4, [r10], -r4, lsl #2
 *   @0x30f6d2 .word 0xf8d36e58
 *   @0x30f6d6 .word 0xf7d792a0
 *   @0x30f6da blls 0x34eb76
 *   @0x30f6de blhs 0x320f02
 *   @0x30f6e2 cdpge p1, #0x0, c13, c1, c13, #0x1
 *   @0x30f6e6 subspl pc, r12, r9, lsl #4
 *   @0x30f6ea .word 0xf7fe4631
 *   @0x30f6ee stmdavs r2!, {r1, r2, r3, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x30f6f2 .word 0x3000f8d8
 *   @0x30f6f6 mrcvs p6, #0x2, r4, c0, c1, #0x1
 *   @0x30f6fa .word 0x4798463a
 *   @0x30f6fe ldmiblt r0!, {r12, pc} ^
 *   @0x30f702 ubfxpl pc, r9, #0x11, #0x9
 *   @0x30f706 beq 0xfe48a32a <b2_toiTime+0xfffffffffdd30e86>
 *   @0x30f70a stclo p1, c11, [r1, #-660]
 *   @0x30f70e bl 0x560fda <g_SWFlineaavertbuff+0xdf12>
 *   @0x30f712 .word 0xf8d30385
 *   @0x30f716 .word 0xf7fe07ec
 *   @0x30f71a stmdavs r2!, {r3, r4, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x30f71e .word 0x3000f8d8
 *   @0x30f722 mrcvs p6, #0x2, r4, c0, c1, #0x1
 *   @0x30f726 .word 0x47984652
 *   @0x30f72a beq 0x44bdda <g_RomDisk+0x545ba>
 *   @0x30f72e stmdahs r0, {r12, pc}
 *   @0x30f732 and sp, r4, r10, ror #1
 *   @0x30f736 andsvs r6, pc, r3, lsr #21
 *   @0x30f73a .word 0x33fff04f
 *   @0x30f73e stmdals r0, {r0, r1, r5, r6, r7, r9, sp, lr}
 *   @0x30f742 pop {r1, r4, r5, r12, sp, pc}
 *   @0x30f746 push {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x30f74a .word 0x460d47f0
 *   @0x30f74e swphs r4, r1, [r0]
 *   @0x30f752 .word 0x469a2214
 *   @0x30f756 .word 0xf8dd4604
 *   @0x30f75a .word 0xf89d8024
 *   @0x30f75e .word 0xf5a66028
 *   @0x30f762 strtmi lr, [r8], -r6, lsr #30
 *   @0x30f766 .word 0xf7fe4649
 *   @0x30f76a .word 0x4605fb70
 *   @0x30f76e stmdavs pc!, {r7, r11, sp, lr} ^
 *   @0x30f772 .word 0xf5131bc3
 *   @0x30f776 smlatble r5, r8, pc, r1
 *   @0x30f77a adcvs r11, r0, r6, lsl r1
 *   @0x30f77e ands r2, r6, r1, lsl #6
 *   @0x30f782 ands r2, r4, r0, lsl #6
 *   @0x30f786 svcne #0xa0f513
 *   @0x30f78a cdphs p1, #0x0, c13, c0, c4, #0x0
 *   @0x30f78e .word 0x60a7d1f8
 *   @0x30f792 and r2, r12, r2, lsl #6
 *   @0x30f796 ble 0x41a39e <g_RomDisk+0x22b7e>
 *   @0x30f79a adcvs r11, r0, lr, lsl #2
 *   @0x30f79e adcvs lr, r7, r3
 *   @0x30f7a2 tstlt r6, r4
 *   @0x30f7a6 movwhs r6, #0x40a7
 *   @0x30f7aa adcvs lr, r0, r1
 *   @0x30f7ae eorvs r2, r3, r8, lsl #6
 *   @0x30f7b2 .word 0xf0166826
 *   @0x30f7b6 andle r0, r5, r10, lsl #4
 *   @0x30f7ba .word 0x1000f8da
 *   @0x30f7be bl 0x3e9a52 <t1_driver_class+0x17e>
 *   @0x30f7c2 adcvs r0, r3, r1, asr #6
 *   @0x30f7c6 stmdals r8, {r0, r1, r5, r7, r11, sp, lr}
 *   @0x30f7ca andshi pc, r0, r4, asr #17
 *   @0x30f7ce .word 0xf8c44418
 *   @0x30f7d2 adcvs r9, r0, r4
 *   @0x30f7d6 stmdavc r11!, {r1, r2, r3, r4, r6, r8, r12, sp, pc}
 *   @0x30f7da .word 0xb10ab14b
 *   @0x30f7de and r6, r0, r11, lsr #18
 *   @0x30f7e2 .word 0xf04668eb
 *   @0x30f7e6 rscvs r0, r3, r0, lsl r6
 *   @0x30f7ea pop {r1, r2, r5, sp, lr}
 *   @0x30f7ee .word 0x464187f0
 *   @0x30f7f2 blx 0xffb0d7f2 <b2_toiTime+0xffffffffff3b434e>
 *   @0x30f7f6 pop {r5, r6, r7, sp, lr}
 *   @0x30f7fa ldrblt r8, [r3, #-0x7f0]!
 *   @0x30f7fe .word 0xf8d04616
 *   @0x30f802 ldrmi r4, [sp], -r0, lsl #1
 *   @0x30f806 .word 0xb14c6b64
 *   @0x30f80a strbtmi r6, [r10], -r0, lsr #16
 *   @0x30f80e stmdavs r0!, {r0, r1, r11, sp, lr} ^
 *   @0x30f812 stmdbls r0, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x30f816 eorsvs r9, r1, r1, lsl #20
 *   @0x30f81a and r6, r5, r10, lsr #32
 *   @0x30f81e adceq pc, r0, #208, #16
 *   @0x30f822 adcsmi pc, r4, r0, lsl #4
 *   @0x30f826 ldc2l p7, c15, [r6, #-1016]!
 *   @0x30f82a ldcllt p0, c11, [r0, #-8]!
 *   @0x30f82e ldrblt r0, [r3, #-0x0]!
 *   @0x30f832 strmi r4, [r12], -r6, lsl #12
 *   @0x30f836 sadd16mi r4, r5, r0
 *   @0x30f83a andshs r2, r0, #0, #2
 *   @0x30f83e cdp p5, #0xb, c15, c8, c6, #0x5
 *   @0x30f842 .word 0xf8d06870
 *   @0x30f846 blvs 0x199ba4e <b2_toiTime+0x12425aa>
 *   @0x30f84a ldclvs p9, c11, [r1], #744
 *   @0x30f84e strtlo pc, [r4], #2257
 *   @0x30f852 ldclhs p3, c11, [pc], #12
 *   @0x30f856 mrcmi p8, #0x0, sp, c0, c14, #0x0
 *   @0x30f85a ldrbtmi r6, [lr], #-2377
 *   @0x30f85e strbeq lr, [r4], #-2822
 *   @0x30f862 ldrmi r8, [r4], -r6, lsr #26
 *   @0x30f866 andsle r4, r5, r12, lsl #5
 *   @0x30f86a andshs pc, r4, r3, lsr r8
 *   @0x30f86e strhle r4, [r2, -r2]
 *   @0x30f872 ble 0x39a87a <ft_adobe_glyph_list+0x9f56>
 *   @0x30f876 strlo lr, [r1], #-14
 *   @0x30f87a qsub8mi lr, r1, r4
 *   @0x30f87e blge 0x36122e <_ZTS12CDS_Priority+0x3286>
 *   @0x30f882 .word 0xffbbf7ff
 *   @0x30f886 blls 0x33dd6e
 *   @0x30f88a rsbvs r9, r11, r1, lsl #20
 *   @0x30f88e rscvs r4, r11, r10, lsl r4
 *   @0x30f892 and r6, r0, r10, lsr #1
 *   @0x30f896 andlt r2, r2, r2, lsl r0
 *   @0x30f89a svclo #0xbcbd70
 *   @0x30f89e stmdavs r0, {r0, r3}
 *   @0x30f8a2 ldrhlo pc, [r6], -r0
 *   @0x30f8a6 ldrhths pc, [r10], -r0
 *   @0x30f8aa stmdavs r3, {r1, r3, r4, r10, lr} ^
 *   @0x30f8ae addsmi r4, r10, #167772160
 *   @0x30f8b2 andhs sp, r0, #32768
 *   @0x30f8b6 stclt p7, c15, [r6], #-864
 *   @0x30f8ba ldrbmi r2, [r0, -r0]!
 *   @0x30f8be .word 0x4605b5f8
 *   @0x30f8c2 andlo r4, r12, lr, lsl #12
 *   @0x30f8c6 ldrmi r2, [r7], -r1, lsl #2
 *   @0x30f8ca .word 0xffe9f7ff
 *   @0x30f8ce stmdblt r8!, {r2, r9, r10, lr}
 *   @0x30f8d2 ldrtmi r4, [r1], -r8, lsr #12
 *   @0x30f8d6 movwhs r4, #0x163a
 *   @0x30f8da .word 0xf9dcf7fe
 *   @0x30f8de ldcllt p6, c4, [r8, #128]!
 *   @0x30f8e2 .word 0xe92d0000
 *   @0x30f8e6 .word 0x46814ff0
 *   @0x30f8ea addslt r6, r1, r3, lsl #18
 *   @0x30f8ee .word 0xf1036942
 *   @0x30f8f2 bvs 0x40fd5a <g_RomDisk+0x1853a>
 *   @0x30f8f6 .word 0xf0c0428a
 *   @0x30f8fa stmdbmi r9!, {r0, r2, r6, r7, pc} ^
 *   @0x30f8fe bleq 0x44bf92 <g_RomDisk+0x54772>
 *   @0x30f902 .word 0xf04f2600
 *   @0x30f906 .word 0xf06f4700
 *   @0x30f90a andhs r4, r1, #0, #20
 *   @0x30f90e .word 0xf8844479
 *   @0x30f912 .word 0x91032040
 *   @0x30f916 svceq #0x4f85b
 *   @0x30f91a stmdaeq r8!, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x30f91e blhs 0xaad932 <b2_toiTime+0x35448e>
 *   @0x30f922 .word 0xf8d9d107
 *   @0x30f926 andhs r1, r0, #8
 *   @0x30f92a movweq lr, #0x6b08
 *   @0x30f92e ldc2 p7, c15, [r1, #1016]
 *   @0x30f932 .word 0xf8dbe049
 *   @0x30f936 .word 0xf7fe1004
 *   @0x30f93a .word 0xf647f9c6
 *   @0x30f93e addsmi r7, r0, #-268435441
 *   @0x30f942 ldcle p6, c4, [r12, #-20]!
 *   @0x30f946 addsmi r4, r8, #83968
 *   @0x30f94a blmi 0x1786d8a <b2_toiTime+0x102d8e6>
 *   @0x30f94e stcle p2, c4, [sp, #-608]
 *   @0x30f952 addsmi r4, r8, #82944
 *   @0x30f956 blmi 0x1746d8e <b2_toiTime+0xfed8ea>
 *   @0x30f95a stcle p2, c4, [r11, #-608]
 *   @0x30f95e addsmi r4, r8, #80, #22
 *   @0x30f962 movwhs r11, #0xafcc
 *   @0x30f966 and r2, r6, r9, lsl #6
 *   @0x30f96a and r2, r4, r5, lsl #6
 *   @0x30f96e and r2, r2, r6, lsl #6
 *   @0x30f972 and r2, r0, r7, lsl #6
 *   @0x30f976 stmdbls r3, {r3, r8, r9, sp}
 *   @0x30f97a .word 0x0c05f1a3
 *   @0x30f97e movwls r4, #0x628
 *   @0x30f982 andgt pc, r8, sp, asr #17
 *   @0x30f986 eorhs pc, r12, r1, asr r8
 *   @0x30f98a andls r4, r1, #17825792
 *   @0x30f98e stmib r0, {r0, r3, r12, sp, lr, pc} ^
 *   @0x30f992 mvnsvc pc, r7, asr #12
 *   @0x30f996 blls 0x3361a2
 *   @0x30f99a .word 0xc008f8dd
 *   @0x30f99e stcle p2, c4, [r7, #-544]
 *   @0x30f9a2 bllo 0x4361b6 <g_RomDisk+0x3e996>
 *   @0x30f9a6 .word 0xf8484628
 *   @0x30f9aa .word 0xf8523006
 *   @0x30f9ae and r1, r3, r3, lsr #32
 *   @0x30f9b2 ldrmi r4, [r1], -r8, lsr #12
 *   @0x30f9b6 andgt pc, r6, r8, asr #16
 *   @0x30f9ba blx 0x224d916 <b2_toiTime+0x1af4472>
 *   @0x30f9be streq lr, [r0], #-3
 *   @0x30f9c2 .word 0xf8482300
 *   @0x30f9c6 stcge p0, c3, [r4, #-24]
 *   @0x30f9ca teqlt r8, r0, ror r1
 *   @0x30f9ce andlo pc, r6, r8, asr r8
 *   @0x30f9d2 svclt #0xb8429f
 *   @0x30f9d6 ldrmi r4, [r10, #0x61f]
 *   @0x30f9da ldrmi r11, [r10], r8, lsr #31
 *   @0x30f9de cdphs p6, #0x1, c3, c8, c4, #0x0
 *   @0x30f9e2 .word 0xf107d198
 *   @0x30f9e6 blhs 0x550612 <gp_ActiveMaskObjects+0xb94a>
 *   @0x30f9ea bl 0xff5c5a02 <b2_toiTime+0xfffffffffee6c55e>
 *   @0x30f9ee .word 0xf1ba0a07
 *   @0x30f9f2 stmdble r11, {r0, r3, r8, r9, r10, r11}
 *   @0x30f9f6 vst4.8 {d18, d19, d20, d21}, [pc], r0
 *   @0x30f9fa movvs r3, #128, #6
 *   @0x30f9fe .word 0x63e36323
 *   @0x30fa02 .word 0x63602301
 *   @0x30fa06 strbtvs r6, [r0], #1184
 *   @0x30fa0a eors r6, r12, r3, ror #8
 *   @0x30fa0e ldrsbls pc, [r8], pc
 *   @0x30fa12 ldrbtmi r2, [r9], #1536
 *   @0x30fa16 blhs 0x3260ca
 *   @0x30fa1a .word 0xf858d01d
 *   @0x30fa1e bl 0xff397a3e <b2_toiTime+0xfffffffffec3e59a>
 *   @0x30fa22 .word 0xf8590207
 *   @0x30fa26 b 0x16d3ab6 <b2_toiTime+0xf7a612>
 *   @0x30fa2a ble 0x54fbb6 <gp_ActiveMaskObjects+0xaeee>
 *   @0x30fa2e andmi pc, r0, #0, #2
 *   @0x30fa32 addsmi r3, r10, #268435456
 *   @0x30fa36 bl 0xff33f98e <b2_toiTime+0xfffffffffebe64ea>
 *   @0x30fa3a .word 0xf04f0003
 *   @0x30fa3e and r4, r7, r0
 *   @0x30fa42 andmi pc, r0, #111
 *   @0x30fa46 addsmi r1, r10, #73728
 *   @0x30fa4a stmne r0, {r2, r3, r6, r7, r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x30fa4e andmi pc, r0, pc, rrx
 *   @0x30fa52 ldmdb lr, {r0, r3, r12, sp, lr, pc} ^
 *   @0x30fa56 strlo r5, [r4], -r8, lsr #3
 *   @0x30fa5a bicsle r2, r11, r8, lsl lr
 *   @0x30fa5e rsbsmi r9, pc, #4, #22
 *   @0x30fa62 .word 0x63232000
 *   @0x30fa66 .word 0x63a39b05
 *   @0x30fa6a .word 0x63639b06
 *   @0x30fa6e .word 0x63e39b07
 *   @0x30fa72 strtvs r9, [r3], #2824
 *   @0x30fa76 strbtvs r9, [r3], #2825
 *   @0x30fa7a ldrbtmi r4, [r11], #-2828
 *   @0x30fa7e eorlo pc, r7, r3, asr r8
 *   @0x30fa82 and r6, r0, r3, ror #8
 *   @0x30fa86 andslt r2, r1, r1, lsr #1
 *   @0x30fa8a svchi #0xf0e8bd
 *   @0x30fa8e ldrhi r11, [pc], r0, lsl #30
 *   @0x30fa92 eorsmi r0, pc, #1
 *   @0x30fa96 ldrbtls r0, [pc], -pc
 *   @0x30fa9a smlals r0, pc, r8, r0
 *   @0x30fa9e ldmibgt pc!, {r0, r2, r4, r5, r6, r7, r8, r10} ^
 *   @0x30faa2 svclo #0xa3b9a
 *   @0x30faa6 cdplo p0, #0x0, c0, c4, c9, #0x0
 *   @0x30faaa ldclo p0, c0, [r12, #36]
 *   @0x30faae ldrlt r0, [r0, #-0x9]
 *   @0x30fab2 strmi r4, [r8], -r3, lsl #12
 *   @0x30fab6 ldrmi r7, [r4], -r9, lsl #16
 *   @0x30faba sadd16mi r2, r9, lr
 *   @0x30fabe movwhs sp, #0x104
 *   @0x30fac2 ldrhmi lr, [r0], -sp
 *   @0x30fac6 stcllt p7, c15, [r5], {254}
 *   @0x30faca .word 0xf8fdf7fe
 *   @0x30face blmi 0x57bf66 <g_SWFlineaavertbuff+0x28e9e>
 *   @0x30fad2 .word 0xf853447b
 *   @0x30fad6 cmpmi r8, #36
 *   @0x30fada svcmi #0xf5b0
 *   @0x30fade .word 0xf510da04
 *   @0x30fae2 stcle p15, c4, [r4, #-0]
 *   @0x30fae6 ldclt p4, c0, [r0, #-0]
 *   @0x30faea andmi pc, r0, pc, rrx
 *   @0x30faee stmdami r0, {r4, r8, r10, r11, r12, sp, pc}
 *   @0x30faf2 andeq r11, r1, r0, lsl sp
 *   @0x30faf6 stcllo p0, c8, [r6, #-0]
 *   @0x30fafa stmvs r0, {r0, r3}
 *   @0x30fafe .word 0xf7ff2200
 *   @0x30fb02 ldrblt r11, [r0, #-0xfd6]!
 *   @0x30fb06 stmdbvs r5, {r2, r9, r10, lr}
 *   @0x30fb0a .word 0xf1056943
 *   @0x30fb0e bvs 0x490356 <g_prim_v+0x34a>
 *   @0x30fb12 tstle r12, #805306377
 *   @0x30fb16 .word 0xf7ff6829
 *   @0x30fb1a .word 0xf7d5fff0
 *   @0x30fb1e ldrbvs pc, [r0, #-0x8fe]!
 *   @0x30fb22 stmdavs r9!, {r5, r9, r10, lr} ^
 *   @0x30fb26 .word 0xffe9f7ff
 *   @0x30fb2a .word 0xf8f7f7d5
 *   @0x30fb2e .word 0x462065b0
 *   @0x30fb32 .word 0xf7ff68a9
 *   @0x30fb36 pld [r5, r2, ror #31]
 *   @0x30fb3a ldrbvs pc, [r0, #0x8f0]!
 *   @0x30fb3e stmvs r9!, {r5, r9, r10, lr} ^
 *   @0x30fb42 .word 0xffdbf7ff
 *   @0x30fb46 .word 0xf8e9f7d5
 *   @0x30fb4a andhs r6, r0, r0, lsr r6
 *   @0x30fb4e adchs r11, r1, r0, ror sp
 *   @0x30fb52 strlt r11, [r8, #-0xd70]
 *   @0x30fb56 stmdavc r10, {r0, r1, r9, r10, lr}
 *   @0x30fb5a .word 0xd1072a1e
 *   @0x30fb5e strmi r2, [r8], -r0, lsl #4
 *   @0x30fb62 sadd16mi r6, r3, r9
 *   @0x30fb66 ldc2l p7, c15, [r5], #-1016
 *   @0x30fb6a stclt p4, c1, [r8, #-0]
 *   @0x30fb6e strdle r2, r3, [r10, -pc]
 *   @0x30fb72 stmdavc r11, {r3, r7, r11, r12, sp, lr} ^
 *   @0x30fb76 b 0x131037e <b2_toiTime+0xbb6eda>
 *   @0x30fb7a stmvc r11, {r0, r1, lr} ^
 *   @0x30fb7e addlo r4, r0, r8, lsl r3
 *   @0x30fb82 andhs pc, pc, r0, asr #6
 *   @0x30fb86 strmi r11, [r8], -r8, lsl #26
 *   @0x30fb8a pop {r0, r3, r4, r11, sp, lr}
 *   @0x30fb8e .word 0xf7fe4008
 *   @0x30fb92 ldrlt r11, [r8, #-0x89a]!
 *   @0x30fb96 stmdbvs r2, {r2, r9, r11, sp, lr}
 *   @0x30fb9a .word 0xf8d4b16c
 *   @0x30fb9e cmplt r3, r12, ror #2
 *   @0x30fba2 eorpl pc, sp, #9633792
 *   @0x30fba6 ldmdavs r1, {r0, r2, r3, r6, r8, r11, r12, sp, pc}
 *   @0x30fbaa .word 0xf7ff3008
 *   @0x30fbae .word 0xf8c4ffd2
 *   @0x30fbb2 strtmi r0, [r8], -r8, ror #2
 *   @0x30fbb6 andhs r11, r3, r8, lsr sp
 *   @0x30fbba adchs r11, r0, r8, lsr sp
 *   @0x30fbbe ldrlt r11, [r0, #-0xd38]
 *   @0x30fbc2 stmdbvs r3, {r2, r9, r11, sp, lr}
 *   @0x30fbc6 ldmdavs r9, {r2, r7, r8, r12, sp, pc}
 *   @0x30fbca .word 0xf7ff3008
 *   @0x30fbce .word 0xf240ffc2
 *   @0x30fbd2 addsmi r2, r8, #67108864
 *   @0x30fbd6 ldrmi r11, [r8], -r8, lsr #30
 *   @0x30fbda adcseq pc, r8, r4, asr #17
 *   @0x30fbde svcvc #0xf5b0
 *   @0x30fbe2 .word 0xf8c4d804
 *   @0x30fbe6 strh r3, [r1], -r8
 *   @0x30fbea ldclt p0, c2, [r0, #-12]
 *   @0x30fbee ldclt p0, c2, [r0, #-0]
 *   @0x30fbf2 stmdbvs r4, {r4, r5, r6, r8, r10, r12, sp, pc}
 *   @0x30fbf6 .word 0xf1046943
 *   @0x30fbfa bvs 0x450432 <g_RomDisk+0x58c12>
 *   @0x30fbfe tstle r5, #805306377
 *   @0x30fc02 streq pc, [r8], -r0, lsl #2
 *   @0x30fc06 ldrtmi r6, [r0], -r1, lsr #16
 *   @0x30fc0a .word 0xffa3f7ff
 *   @0x30fc0e addeq pc, r4, r5, asr #17
 *   @0x30fc12 stmdavs r1!, {r4, r5, r9, r10, lr} ^
 *   @0x30fc16 .word 0xff9df7ff
 *   @0x30fc1a addeq pc, r8, r5, asr #17
 *   @0x30fc1e stmvs r1!, {r4, r5, r9, r10, lr}
 *   @0x30fc22 .word 0xff97f7ff
 *   @0x30fc26 addeq pc, r12, r5, asr #17
 *   @0x30fc2a ldcllt p0, c2, [r0, #-0]!
 *   @0x30fc2e ldcllt p0, c2, [r0, #-644]!
 *   @0x30fc32 .word 0x4604b538
 *   @0x30fc36 stmdbvs r2, {r0, r1, r8, r11, sp, lr} ^
 *   @0x30fc3a tsteq r4, r3, lsl #2
 *   @0x30fc3e addmi r6, r10, #20480
 *   @0x30fc42 ldmdavs r9, {r1, r2, r4, r8, r9, r12, lr, pc}
 *   @0x30fc46 .word 0xf7ff3008
 *   @0x30fc4a cdpne p15, #0x8, c15, c3, c4, #0x4
 *   @0x30fc4e ldmdale r1, {r1, r2, r3, r8, r9, r11, sp}
 *   @0x30fc52 .word 0xf8a5b280
 *   @0x30fc56 stmdbvs r2!, {r4, r5, r7} ^
 *   @0x30fc5a bne 0xff7ea0ee <b2_toiTime+0xffffffffff090c4a>
 *   @0x30fc5e bllo 0x413ed2 <g_RomDisk+0x1c6b2>
 *   @0x30fc62 adcslo pc, r2, r5, lsr #17
 *   @0x30fc66 andhs r8, r0, r0, lsr #9
 *   @0x30fc6a ldrhtlo pc, [r2], r5
 *   @0x30fc6e ldclt p4, c8, [r8, #-908]!
 *   @0x30fc72 ldclt p0, c2, [r8, #-644]!
 *   @0x30fc76 ldclt p0, c2, [r8, #-12]!
 *   @0x30fc7a stmdbvs r4, {r4, r5, r6, r8, r10, r12, sp, pc}
 *   @0x30fc7e .word 0xf1046943
 *   @0x30fc82 bvs 0x4504aa <g_RomDisk+0x58c8a>
 *   @0x30fc86 tstle r3, #805306377
 *   @0x30fc8a streq pc, [r8], -r0, lsl #2
 *   @0x30fc8e ldrtmi r6, [r0], -r1, lsr #16
 *   @0x30fc92 .word 0xff5ff7ff
 *   @0x30fc96 ble 0x359c9e
 *   @0x30fc9a ldcllt p0, c2, [r0, #-12]!
 *   @0x30fc9e ldrtmi r6, [r0], -r8, lsr #15
 *   @0x30fca2 .word 0xf7ff6861
 *   @0x30fca6 stmdahs r0, {r1, r2, r4, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30fcaa .word 0x6768dbf6
 *   @0x30fcae ldcllt p0, c2, [r0, #-0]!
 *   @0x30fcb2 ldcllt p0, c2, [r0, #-644]!
 *   @0x30fcb6 .word 0x4604b538
 *   @0x30fcba orrlt r7, r8, r0, lsl #16
 *   @0x30fcbe addmi r6, sp, #10813440
 *   @0x30fcc2 stmvs r5!, {r1, r2, r3, r8, r12, lr, pc} ^
 *   @0x30fcc6 swple r4, r5, [r11]
 *   @0x30fcca ldrmi r11, [r8], -r5, asr #2
 *   @0x30fcce adceq r6, r10, r1, lsr #18
 *   @0x30fcd2 svc #0xb6f5a6
 *   @0x30fcd6 svclt #0x183000
 *   @0x30fcda ldclt p0, c2, [r8, #-4]!
 *   @0x30fcde ldclt p6, c4, [r8, #-160]!
 *   @0x30fce2 ldclt p0, c2, [r8, #-4]!
 *   @0x30fce6 svcmi #0xf0e92d
 *   @0x30fcea bvs 0x3e1506 <error_g0017+0x3a1aa>
 *   @0x30fcee stmdblt r11, {r0, r1, r3, r7, r12, sp, pc}
 *   @0x30fcf2 rsc r2, r11, r3
 *   @0x30fcf6 .word 0x416cf8d3
 *   @0x30fcfa rscsle r2, r9, r0, lsl #24
 *   @0x30fcfe .word 0x8168f8d3
 *   @0x30fd02 stmdbvc r11, {r2, r8, r10, r12, sp, lr, pc}
 *   @0x30fd06 subvc pc, r8, #212, #16
 *   @0x30fd0a subvs pc, r12, #212, #16
 *   @0x30fd0e strbmi r4, [r1], -r8, asr #12
 *   @0x30fd12 shasxmi r4, r3, r10
 *   @0x30fd16 .word 0xffcef7ff
 *   @0x30fd1a stmdbvs r11!, {r5, r6, r8, r11, r12, sp, pc} ^
 *   @0x30fd1e stmdbeq r8, {r0, r2, r8, r12, sp, lr, pc}
 *   @0x30fd22 .word 0xf8534648
 *   @0x30fd26 .word 0xf7ff1c04
 *   @0x30fd2a stmibvs r11!, {r2, r4, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x30fd2e .word 0x46074298
 *   @0x30fd32 ldrd sp, lr, [r8], -lr
 *   @0x30fd36 strbmi r4, [r1], -r8, asr #12
 *   @0x30fd3a shasxmi r4, r3, r10
 *   @0x30fd3e mrc2 p7, #0x3, apsr_nzcv, c8, c14, #0x7
 *   @0x30fd42 rscle r2, r10, r0, lsl #16
 *   @0x30fd46 .word 0xf8d4e0c2
 *   @0x30fd4a ldmvs r8, {r4, r5, r9, r12, sp}
 *   @0x30fd4e movwls r2, #0x9300
 *   @0x30fd52 sublo pc, r0, #212, #16
 *   @0x30fd56 blx 0x50e96a <SrcVerts+0x6b9ae>
 *   @0x30fd5a .word 0xf1a3696b
 *   @0x30fd5e stmdbvs r11!, {r2, r10, r11}
 *   @0x30fd62 movweq lr, #0xcbc3
 *   @0x30fd66 bleq 0xfec0a6aa <b2_toiTime+0xfffffffffe4b1206>
 *   @0x30fd6a stmdble r2, {r1, r3, r4, r6, r7, r8, r10, lr}
 *   @0x30fd6e movwls r2, #0x93a1
 *   @0x30fd72 .word 0xf04fe0a8
 *   @0x30fd76 .word 0xf8d40805
 *   @0x30fd7a blx 0x51c6e4 <SrcVerts+0x79728>
 *   @0x30fd7e .word 0xf8d4f807
 *   @0x30fd82 strbmi r2, [r3], #-604
 *   @0x30fd86 stmdale pc, {r0, r1, r4, r7, r9, lr}
 *   @0x30fd8a bleq 0x60acba <g_SWFaavertbuff+0x37bf2>
 *   @0x30fd8e subslo pc, r8, #212, #16
 *   @0x30fd92 andslt pc, r0, sp, asr #17
 *   @0x30fd96 ldrtmi r4, [r10], #-1626
 *   @0x30fd9a andls r4, r5, #1124073472
 *   @0x30fd9e subslo pc, r8, #196, #16
 *   @0x30fda2 .word 0xf04f4692
 *   @0x30fda6 subs r0, r11, r0, lsl #16
 *   @0x30fdaa subslo pc, r4, #212, #16
 *   @0x30fdae .word 0xf8d42101
 *   @0x30fdb2 movwls r6, #0x4250
 *   @0x30fdb6 strls r10, [r0], -r9, lsl #22
 *   @0x30fdba bl 0x5349c6 <_IO_KeyMap+0x2ee>
 *   @0x30fdbe .word 0xf7d80302
 *   @0x30fdc2 blls 0x58e35e <g_SWFlineaavertbuff+0x3b296>
 *   @0x30fdc6 subseq pc, r0, #196, #16
 *   @0x30fdca cmnle r11, r0, lsl #22
 *   @0x30fdce subslo pc, r8, #212, #16
 *   @0x30fdd2 .word 0xf8c44403
 *   @0x30fdd6 .word 0xf8d43254
 *   @0x30fdda strbmi r3, [r3], #-604
 *   @0x30fdde subslo pc, r12, #196, #16
 *   @0x30fde2 sbcsle r2, r1, r0, lsl #28
 *   @0x30fde6 strhle r4, [pc], #32
 *   @0x30fdea blne 0xfe32a29e <b2_toiTime+0xfffffffffdbd0dfa>
 *   @0x30fdee addsmi r6, r3, #1736704
 *   @0x30fdf2 .word 0xf853d2ca
 *   @0x30fdf6 adcsmi r2, r2, #4, #22
 *   @0x30fdfa stmdbls r4, {r3, r4, r5, r6, r7, r8, r9, r12, lr, pc}
 *   @0x30fdfe svclt #0x3c428a
 *   @0x30fe02 .word 0xf8431812
 *   @0x30fe06 ldrb r2, [r1, r4, lsl #24]!
 *   @0x30fe0a subslo pc, r4, #212, #16
 *   @0x30fe0e stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x30fe12 .word 0xf842468a
 *   @0x30fe16 .word 0xf8d4302b
 *   @0x30fe1a mrrcne p2, #0x5, r3, r10, c4
 *   @0x30fe1e subshs pc, r4, #196, #16
 *   @0x30fe22 rscslo pc, pc, #79
 *   @0x30fe26 .word 0xf8d4701a
 *   @0x30fe2a mrrcne p2, #0x5, r3, r10, c4
 *   @0x30fe2e subshs pc, r4, #196, #16
 *   @0x30fe32 andsvc r0, r10, r2, lsr lr
 *   @0x30fe36 subslo pc, r4, #212, #16
 *   @0x30fe3a .word 0xf8c41c5a
 *   @0x30fe3e vmov.i32 q9, #0xe400
 *   @0x30fe42 andsvc r4, r10, r7, lsl #4
 *   @0x30fe46 subslo pc, r4, #212, #16
 *   @0x30fe4a .word 0xf8c41c5a
 *   @0x30fe4e vmov.i32 q9, #0xe400
 *   @0x30fe52 andsvc r2, r10, r7, lsl #4
 *   @0x30fe56 subslo pc, r4, #212, #16
 *   @0x30fe5a .word 0xf8c41c5a
 *   @0x30fe5e andsvc r2, lr, r4, asr r2
 *   @0x30fe62 stmdbvs r11!, {r3, r4, r5, r7, r8, r10, lr}
 *   @0x30fe66 .word 0xf8ddd02a
 *   @0x30fe6a .word 0x4648b010
 *   @0x30fe6e subhs pc, r4, #212, #16
 *   @0x30fe72 .word 0xf85344c3
 *   @0x30fe76 andls r1, r6, #43
 *   @0x30fe7a mcr2 p7, #0x3, pc, c11, c15, #0x7
 *   @0x30fe7e .word 0x0c00f04f
 *   @0x30fe82 .word 0xf8d40406
 *   @0x30fe86 .word 0xf10c2240
 *   @0x30fe8a bl 0x610a96 <g_SWFaavertbuff+0x3d9ce>
 *   @0x30fe8e addsmi r0, r3, #-2147483646
 *   @0x30fe92 adcsle r6, r9, #688128
 *   @0x30fe96 .word 0xf8529806
 *   @0x30fe9a bl 0x313f26 <af_shaper_get_elem+0x9794>
 *   @0x30fe9e .word 0xf8dc0c8c
 *   @0x30fea2 movwls r0, #0x3004
 *   @0x30fea6 strbmi r9, [r8], -r7
 *   @0x30feaa mrc2 p7, #0x2, apsr_nzcv, c3, c15, #0x7
 *   @0x30feae stmdals r7, {r0, r10}
 *   @0x30feb2 .word 0xffcbf7d4
 *   @0x30feb6 ldrmi r9, [r12], r3, lsl #22
 *   @0x30feba strb r4, [r2, r6, lsl #8]!
 *   @0x30febe bl 0x3f66da <g_MP3UpdateVolume+0x13fe>
 *   @0x30fec2 smulbbvs r11, r2, r3
 *   @0x30fec6 movwhs r9, #0x1809
 *   @0x30feca eorlo pc, sp, #132, #16
 *   @0x30fece pop {r0, r1, r3, r12, sp, pc}
 *   @0x30fed2 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x30fed6 strdlt r4, r5, [r7], r0
 *   @0x30feda ldrmi r4, [sp], -r12, lsl #12
 *   @0x30fede umaalne pc, r4, sp, r8
 *   @0x30fee2 blls 0x7b3efe <b2_toiTime+0x5aa5a>
 *   @0x30fee6 .word 0xf0002900
 *   @0x30feea ldmvs r9, {r3, r7, pc}
 *   @0x30feee .word 0xb000f8d3
 *   @0x30fef2 .word 0xa004f8d3
 *   @0x30fef6 ldmibvs r9, {r1, r8, r12, pc}
 *   @0x30fefa .word 0x900cf8d3
 *   @0x30fefe .word 0xf8d3691f
 *   @0x30ff02 ldmdals r0, {r2, r4, pc}
 *   @0x30ff06 ldrdls r6, r7, [r3, -r11]
 *   @0x30ff0a stmdbls r5, {r4, r10, lr}
 *   @0x30ff0e .word 0xf7fd9304
 *   @0x30ff12 blx 0xff04fc5a <b2_toiTime+0xfffffffffe8f67b6>
 *   @0x30ff16 .word 0xf1c3f384
 *   @0x30ff1a blx 0xfef10c1a <b2_toiTime+0xfffffffffe7b7776>
 *   @0x30ff1e strmi pc, [r6], -r0, lsl #5
 *   @0x30ff22 blhs 0xe56996 <b2_toiTime+0x6fd4f2>
 *   @0x30ff26 bls 0x407336 <g_RomDisk+0xfb16>
 *   @0x30ff2a and r0, r3, r3, lsl r4
 *   @0x30ff2e .word 0xf7fd4621
 *   @0x30ff32 strmi pc, [r3], -r0, asr #30
 *   @0x30ff36 andmi lr, r11, pc, asr #20
 *   @0x30ff3a ble 0x3a094e <af_orya_uniranges+0x2>
 *   @0x30ff3e andmi lr, r10, pc, asr #20
 *   @0x30ff42 bls 0x3c808e <error_g0017+0x20d32>
 *   @0x30ff46 .word 0x4c02ea4f
 *   @0x30ff4a ble 0xb214de <b2_toiTime+0x3c803a>
 *   @0x30ff4e bleq 0x3cae82 <error_g0017+0x23b26>
 *   @0x30ff52 .word 0xf8cd4621
 *   @0x30ff56 .word 0xf7d4c004
 *   @0x30ff5a .word 0xf8ddffad
 *   @0x30ff5e .word 0xf1bbc004
 *   @0x30ff62 .word 0xd10a0f00
 *   @0x30ff66 strbtmi r9, [r0], -r2, lsl #22
 *   @0x30ff6a bl 0xff3e17f6 <b2_toiTime+0xfffffffffec88352>
 *   @0x30ff6e .word 0xf7d40a07
 *   @0x30ff72 .word 0xf1baffa1
 *   @0x30ff76 andsle r0, r1, r0, lsl #30
 *   @0x30ff7a bne 0xf48016 <b2_toiTime+0x7eeb72>
 *   @0x30ff7e smlabteq r9, r10, r11, lr
 *   @0x30ff82 .word 0xf7d4465a
 *   @0x30ff86 .word 0x4606feda
 *   @0x30ff8a andmi lr, r10, pc, asr #20
 *   @0x30ff8e bl 0xff008026 <b2_toiTime+0xfffffffffe8aeb82>
 *   @0x30ff92 blle 0xffce3bb6 <b2_toiTime+0xffffffffff58a712>
 *   @0x30ff96 bl 0xfeff67aa <b2_toiTime+0xfffffffffe89d306>
 *   @0x30ff9a ble 0xba3baa <b2_toiTime+0x44a706>
 *   @0x30ff9e ldrteq r9, [r8], #-2563
 *   @0x30ffa2 bl 0xff4e182e <b2_toiTime+0xfffffffffed8838a>
 *   @0x30ffa6 .word 0xf7d40902
 *   @0x30ffaa .word 0xf1b9ff85
 *   @0x30ffae andsle r0, r8, r0, lsl #30
 *   @0x30ffb2 bne 0xf36bca <b2_toiTime+0x7dd726>
 *   @0x30ffb6 bl 0xff5218e6 <b2_toiTime+0xfffffffffedc8442>
 *   @0x30ffba .word 0xf7d40103
 *   @0x30ffbe .word 0x4606febe
 *   @0x30ffc2 andmi lr, r8, pc, asr #20
 *   @0x30ffc6 bne 0xf47fee <b2_toiTime+0x7eeb4a>
 *   @0x30ffca smlabteq r8, r9, r11, lr
 *   @0x30ffce .word 0xf7d44652
 *   @0x30ffd2 .word 0x4606feb4
 *   @0x30ffd6 andmi lr, r9, pc, asr #20
 *   @0x30ffda .word 0xf7d44621
 *   @0x30ffde ldrtmi pc, [r0], #-3947
 *   @0x30ffe2 bls 0x447ffa <g_RomDisk+0x507da>
 *   @0x30ffe6 qadd16mi r0, r1, r0
 *   @0x30ffea .word 0xff64f7d4
 *   @0x30ffee eorvs r9, r8, r5, lsl #22
 *   @0x30fff2 subseq r6, r9, r8, lsr #16
 *   @0x30fff6 .word 0xff5ef7d4
 *   @0x30fffa blls 0x7280a2 <g_SWFvertbuff+0x54fda>
 *   @0x30fffe sbcsvc lr, r3, #3072
 *   @0x310002 bl 0x3ea0b6 <t1_driver_class+0x7e2>
 *   @0x310006 eorvs r0, r11, r2, ror #6
 *   @0x31000a pop {r0, r1, r2, r12, sp, pc}
 *   @0x31000e ldrblt r8, [r0, #-0xff0]!
 *   @0x310012 strmi r4, [lr], -r4, lsl #12
 *   @0x310016 ldmdbmi r5, {r3, r9, r10, lr}
 *   @0x31001a ldrbtmi r4, [r9], #-1557
 *   @0x31001e b 0xfedcd6be <b2_toiTime+0xfffffffffe67421a>
 *   @0x310022 bvs 0x1bfe62a <b2_toiTime+0x14a5186>
 *   @0x310026 bvs 0xfebe80da <b2_toiTime+0xfffffffffe48ec36>
 *   @0x31002a bvs 0xffbe81de <b2_toiTime+0xffffffffff48ed3a>
 *   @0x31002e blvs 0xbe82e2 <b2_toiTime+0x48ee3e>
 *   @0x310032 blvs 0x1be83e6 <b2_toiTime+0x148ef42>
 *   @0x310036 blvs 0xfebe84ea <b2_toiTime+0xfffffffffe48f046>
 *   @0x31003a blvs 0xffbe85ee <b2_toiTime+0xffffffffff48f14a>
 *   @0x31003e stcvs p1, c6, [r3], #-684
 *   @0x310042 ldcllt p1, c6, [r0, #-940]!
 *   @0x310046 ldrtmi r4, [r0], -r11, lsl #18
 *   @0x31004a .word 0xf5a64479
 *   @0x31004e ldmdblt r0, {r1, r4, r7, r9, r11, sp, lr, pc}
 *   @0x310052 eorvs r6, r11, r3, ror #19
 *   @0x310056 stmdbmi r7, {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x31005a ldrbtmi r4, [r9], #-1584
 *   @0x31005e b 0xfe5cd6fe <b2_toiTime+0xfffffffffde7425a>
 *   @0x310062 .word 0xf894b918
 *   @0x310066 eorvc r3, r11, r0, lsr #32
 *   @0x31006a andhs r11, r12, r0, ror sp
 *   @0x31006e svc #0x7abd70
 *   @0x310072 .word 0xf5f70007
 *   @0x310076 svc #0x4f0007
 *   @0x31007a ldrlt r0, [r8, #-0x7]!
 *   @0x31007e stmdami r11, {r2, r9, r10, lr}
 *   @0x310082 ldrbtmi r4, [r8], #-1549
 *   @0x310086 .word 0xf964f7d5
 *   @0x31008a cmnlt r4, r0, lsl #19
 *   @0x31008e stmdblt r8, {r5, r6, r11, sp, lr}
 *   @0x310092 ldclt p0, c2, [r8, #-0]!
 *   @0x310096 ldrbtmi r4, [r9], #-2311
 *   @0x31009a .word 0xff29f7d5
 *   @0x31009e rscsle r2, r7, r0, lsl #16
 *   @0x3100a2 strtmi r6, [r9], -r3, lsl #16
 *   @0x3100a6 .word 0x47986a1b
 *   @0x3100aa qasxmi r11, r0, r8
 *   @0x3100ae blge 0x1d3f596 <b2_toiTime+0x15e60f2>
 *   @0x3100b2 bl 0x8d00ee <b2_toiTime+0x176c4a>
 *   @0x3100b6 push {r0, r1, r2}
 *   @0x3100ba .word 0xf1004ff0
 *   @0x3100be stmdbvs r3, {r3, r8, r11}
 *   @0x3100c2 strmi r11, [r4], -r5, lsl #1
 *   @0x3100c6 ldrmi r4, [r0], sp, lsl #12
 *   @0x3100ca blmi 0x1b285de <b2_toiTime+0x13cf13a>
 *   @0x3100ce ldrbtmi r6, [r11], #-97
 *   @0x3100d2 rscvs r6, r1, r2, lsr #1
 *   @0x3100d6 strbmi r9, [r5, #-0x303]
 *   @0x3100da stmdavc r11!, {r0, r3, r4, r9, r12, lr, pc}
 *   @0x3100de blhs 0x9aa56a <b2_toiTime+0x2510c6>
 *   @0x3100e2 stmibvs r0!, {r1, r5, r6, r8, r11, sp, lr}
 *   @0x3100e6 blhs 0xb065a2 <b2_toiTime+0x3ad0fe>
 *   @0x3100ea blhs 0x30419e <TT_New_Context+0x3f96>
 *   @0x3100ee bne 0x178419a <b2_toiTime+0x102acf6>
 *   @0x3100f2 svceq #0xa1ebb0
 *   @0x3100f6 andhs sp, r6, r1, lsl #16
 *   @0x3100fa blhs 0xac839a <b2_toiTime+0x36eef6>
 *   @0x3100fe .word 0x0104f102
 *   @0x310102 andsvs r6, r5, r1, ror #2
 *   @0x310106 stclne p1, c13, [r11], #-64
 *   @0x31010a ldrmi r4, [sp], -r3, asr #10
 *   @0x31010e andhs sp, r0, r1, lsl #2
 *   @0x310112 .word 0xf813e09a
 *   @0x310116 ldmdbeq r1, {r0, r8, r9, r11, sp}
 *   @0x31011a .word 0xf000290f
 *   @0x31011e .word 0xf0028093
 *   @0x310122 bhs 0x6d0966 <g_SWFlinevertbuff+0x7d89e>
 *   @0x310126 strd sp, lr, [sp], r0
 *   @0x31012a .word 0xd1012b1c
 *   @0x31012e add r3, r9, r2, lsl #10
 *   @0x310132 .word 0xd1012b1d
 *   @0x310136 add r3, r5, r4, lsl #10
 *   @0x31013a .word 0xf2402bf6
 *   @0x31013e strlo r8, [r1, #-0x83]
 *   @0x310142 bne 0x178834a <b2_toiTime+0x102eea6>
 *   @0x310146 addmi r1, r1, #137
 *   @0x31014a blhs 0x644ca6 <g_SWFaavertbuff+0x71bde>
 *   @0x31014e .word 0xd1066015
 *   @0x310152 strbmi r1, [r2, #-0xc6a]
 *   @0x310156 stmdavc r11!, {r0, r1, r2, r3, r6, r7, r9, r12, lr, pc} ^
 *   @0x31015a vst1.8 {d20, d21, d22}, [r3:64], r5
 *   @0x31015e stmibvs r2!, {r7, r8, r9, r12, sp, lr} ^
 *   @0x310162 tstmi r3, #196608
 *   @0x310166 rsbeq pc, r12, #0, #2
 *   @0x31016a .word 0x0c1cf852
 *   @0x31016e ldreq pc, [r12], -r2, lsr #3
 *   @0x310172 stmdahs r0, {r0, r1, r2, r4, r9, r10, lr}
 *   @0x310176 .word 0xf857d061
 *   @0x31017a andslo r7, r12, #24, #24
 *   @0x31017e .word 0xd1f3429f
 *   @0x310182 stmdahs r6, {r0, r1, r2, r5, r9, r11, sp, lr}
 *   @0x310186 .word 0xa008f8d6
 *   @0x31018a bleq 0x5cadae <g_SWFlineaavertbuff+0x77ce6>
 *   @0x31018e stmdbhs r0, {r0, r1, r3, r5, r12, lr, pc}
 *   @0x310192 stmdalo r1, {r0, r4, r5, r7, r12, lr, pc}
 *   @0x310196 stmdale r12, {r2, r11, sp} ^
 *   @0x31019a .word 0xf000e8df
 *   @0x31019e movweq r0, #0xf903
 *   @0x3101a2 stmdbvs r2!, {r0, r1}
 *   @0x3101a6 ldmdavs r1, {r3, r6, r9, r10, lr}
 *   @0x3101aa ldc2l p7, c15, [r3], {255}
 *   @0x3101ae stmdbvs r2!, {r0, r1, r3, sp, lr, pc}
 *   @0x3101b2 ldmdavs r1, {r5, r9, r10, lr}
 *   @0x3101b6 stc2 p7, c15, [r1], #1020
 *   @0x3101ba stmdbvs r2!, {r0, r2, sp, lr, pc}
 *   @0x3101be ldmdavs r1, {r5, r7, r11, sp, lr}
 *   @0x3101c2 .word 0xf7ff2203
 *   @0x3101c6 blvc 0xfcf39e <b2_toiTime+0x875efa>
 *   @0x3101ca andle r2, r6, r2, lsl #20
 *   @0x3101ce andle r2, r7, r4, lsl #20
 *   @0x3101d2 .word 0xd1052a01
 *   @0x3101d6 andeq pc, r10, r7, lsl #16
 *   @0x3101da .word 0xf827e02f
 *   @0x3101de eor r0, r12, r10
 *   @0x3101e2 andeq pc, r10, r7, asr #16
 *   @0x3101e6 ldmdbvs r2!, {r0, r3, r5, sp, lr, pc} ^
 *   @0x3101ea addsmi r6, r1, #573440
 *   @0x3101ee .word 0x460abf38
 *   @0x3101f2 ldrbtpl r6, [r10], #-2481
 *   @0x3101f6 movwlt r2, #0x2700
 *   @0x3101fa blne 0x44e34e <g_RomDisk+0x56b2e>
 *   @0x3101fe andls r4, r2, #72, #12
 *   @0x310202 .word 0xf7ff9301
 *   @0x310206 blvc 0xf8f4a6 <b2_toiTime+0x836002>
 *   @0x31020a stmdbhs r2, {r1, r9, r11, r12, pc}
 *   @0x31020e strmi r9, [r7], #-2817
 *   @0x310212 stmdbhs r4, {r1, r2, r12, lr, pc}
 *   @0x310216 stmdbhs r1, {r0, r1, r2, r12, lr, pc}
 *   @0x31021a .word 0xf88bd105
 *   @0x31021e and r7, r4, r0
 *   @0x310222 andvc pc, r0, r11, lsr #17
 *   @0x310226 .word 0xf8cbe001
 *   @0x31022a blvc 0xf6c232 <b2_toiTime+0x812d8e>
 *   @0x31022e strmi r3, [r11], #2561
 *   @0x310232 ldmdbvs r3!, {r0, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x310236 ldrmi r4, [r8, r0, lsr #12]
 *   @0x31023a ldmdavs r3!, {r4, r5, r8, r11, r12, sp, pc}
 *   @0x31023e svclt #0x1c2b08
 *   @0x310242 .word 0x61636923
 *   @0x310246 strb r3, [r6, -r1, lsl #10]
 *   @0x31024a pop {r0, r2, r12, sp, pc}
 *   @0x31024e blge 0xa34216 <b2_toiTime+0x2dad72>
 *   @0x310252 push {r0, r2, r3}
 *   @0x310256 .word 0x460c4ff0
 *   @0x31025a strmi r6, [r5], -r6, asr #16
 *   @0x31025e eorseq pc, r0, #196, #16
 *   @0x310262 svcvs #0x602100
 *   @0x310266 sadd8mi r11, r7, r3
 *   @0x31026a .word 0xf8844698
 *   @0x31026e stmdahs r0, {r0, r2, r3, r5, r9, r12}
 *   @0x310272 addshi pc, pc, r0
 *   @0x310276 stmdahs r0, {r5, r7, r8, r9, r10, r11, sp, lr}
 *   @0x31027a addshi pc, r11, r0
 *   @0x31027e beq 0xff24c696 <b2_toiTime+0xfffffffffeaf31f2>
 *   @0x310282 adcsvc pc, r8, #1325400064
 *   @0x310286 .word 0xf5a64650
 *   @0x31028a movwhs lr, #0x7992
 *   @0x31028e orrlo pc, r4, r4, asr #17
 *   @0x310292 .word 0xf8c42301
 *   @0x310296 .word 0xf04f3188
 *   @0x31029a .word 0xf8c433ff
 *   @0x31029e .word 0xf6403208
 *   @0x3102a2 .word 0xf8c4735c
 *   @0x3102a6 blmi 0x145caee <b2_toiTime+0xd0364a>
 *   @0x3102aa eormi pc, r8, #196, #16
 *   @0x3102ae subvc pc, r8, #196, #16
 *   @0x3102b2 orrlo pc, r0, r4, asr #17
 *   @0x3102b6 subhi pc, r12, #196, #16
 *   @0x3102ba mlalo r0, r5, r8, pc
 *   @0x3102be .word 0xf8d5b12b
 *   @0x3102c2 vst1.8 {d23, d24, d25}, [pc:64], r4
 *   @0x3102c6 strlo r4, [r1, -r0, lsr #23]
 *   @0x3102ca strbhs lr, [r1, -r2]!
 *   @0x3102ce blpl 0x34d412
 *   @0x3102d2 .word 0xf10d682b
 *   @0x3102d6 rfeia r4!
 *   @0x3102da strhhs r12, [r0, -r0]
 *   @0x3102de movwls r4, #0x5640
 *   @0x3102e2 rfeia r4!
 *   @0x3102e6 .word 0xf8d230b2
 *   @0x3102ea eorhs r9, r8, #0
 *   @0x3102ee .word 0xf8cd9303
 *   @0x3102f2 .word 0xf5a6c010
 *   @0x3102f6 bls 0x48a86e <prim_v+0xeba>
 *   @0x3102fa blls 0x3d8712 <error_g0017+0x313b6>
 *   @0x3102fe .word 0xf8dd4648
 *   @0x310302 .word 0xf8cdc010
 *   @0x310306 .word 0xf04fa040
 *   @0x31030a andls r0, r8, #0, #20
 *   @0x31030e .word 0xf8ad4652
 *   @0x310312 blge 0x4dc432 <SrcVerts+0x39476>
 *   @0x310316 andge pc, r0, sp, asr #17
 *   @0x31031a ldrtmi r9, [r11], -r1, lsl #6
 *   @0x31031e eorslt pc, r12, sp, asr #17
 *   @0x310322 subgt pc, r4, sp, lsr #17
 *   @0x310326 mrc2 p7, #0x5, apsr_nzcv, c2, c7, #0x6
 *   @0x31032a strmi r9, [r1], -r7, lsl #22
 *   @0x31032e .word 0xb12b900c
 *   @0x310332 .word 0xf7d64648
 *   @0x310336 .word 0xf8cdffff
 *   @0x31033a and r10, r1, r0, lsr r0
 *   @0x31033e andls r9, sp, lr, lsl #14
 *   @0x310342 .word 0xb10b9b07
 *   @0x310346 eor r2, r7, r0, lsl #10
 *   @0x31034a ldrtmi r6, [r0], -r9, ror #17
 *   @0x31034e ldrmi r6, [r9], #-3939
 *   @0x310352 blx 0xfed4e2b2 <b2_toiTime+0xfffffffffe5f4e0e>
 *   @0x310356 ldmiblt r8!, {r0, r2, r9, r10, lr} ^
 *   @0x31035a svcvs #0xa14630
 *   @0x31035e stc2l p7, c15, [r0, #-860]!
 *   @0x310362 stmiblt r8, {r0, r2, r9, r10, lr} ^
 *   @0x310366 bvs 0xf61c6e <b2_toiTime+0x8087ca>
 *   @0x31036a .word 0xf7ff6a72
 *   @0x31036e strmi pc, [r5], -r4, lsr #29
 *   @0x310372 .word 0xf7d74630
 *   @0x310376 ldmdblt sp!, {r5, r7, r8, r10, r11, r12, sp, lr, pc} ^
 *   @0x31037a umlalslo pc, r12, r4, r8
 *   @0x31037e movweq pc, #0x1023
 *   @0x310382 adcslo pc, r12, r4, lsl #17
 *   @0x310386 andslo pc, r4, #212, #16
 *   @0x31038a ble 0x35af92
 *   @0x31038e and r4, r1, r11, asr r2
 *   @0x310392 blmi 0x604afa <g_SWFaavertbuff+0x31a32>
 *   @0x310396 andslo pc, r4, #196, #16
 *   @0x31039a subslo pc, r0, #212, #16
 *   @0x31039e .word 0xf8c4990c
 *   @0x3103a2 movwhs r3, #0x254
 *   @0x3103a6 subslo pc, r8, #196, #16
 *   @0x3103aa ldmdavs r8, {r3, r8, r9, r11, r12, pc}
 *   @0x3103ae .word 0xffc2f7d6
 *   @0x3103b2 strmi lr, [r5], -r0
 *   @0x3103b6 andslt r4, r3, r8, lsr #12
 *   @0x3103ba svchi #0xf0e8bd
 *   @0x3103be andge r11, r0, r0, lsl #30
 *   @0x3103c2 ldmvs r1!, {r0, r1, r2, r5}
 *   @0x3103c6 push {r1, r2, r3, r4, r6, r7, r9, r11, r12, sp}
 *   @0x3103ca .word 0x46924ff0
 *   @0x3103ce addlt r6, r7, pc, asr #17
 *   @0x3103d2 strmi r6, [r6], -r10, lsl #17
 *   @0x3103d6 ldrmi r4, [sp], -r12, lsl #12
 *   @0x3103da .word 0xf8dd1abf
 *   @0x3103de rscsne r9, pc, r0, asr #32
 *   @0x3103e2 stmdaeq r1, {r0, r1, r2, r4, r12, sp, lr, pc}
 *   @0x3103e6 .word 0xf899d00d
 *   @0x3103ea ldmdblt r1, {r12} ^
 *   @0x3103ee .word 0xf7fe4620
 *   @0x3103f2 ldmdavs r2!, {r0, r1, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3103f6 rsclo pc, r0, #13762560
 *   @0x3103fa eorlo pc, r0, #13828096
 *   @0x3103fe andmi lr, r3, r0, lsl #22
 *   @0x310402 ldmdavs r3!, {r3, r5, sp, lr}
 *   @0x310406 eorsvs pc, r1, #9633792
 *   @0x31040a .word 0xf10db9fe
 *   @0x31040e strbmi r0, [r5], -r4, lsl #22
 *   @0x310412 adcsmi r4, sp, #176, #12
 *   @0x310416 qadd16mi sp, r9, r7
 *   @0x31041a .word 0xf7fe4620
 *   @0x31041e stclne p15, c15, [r9], #-564
 *   @0x310422 strmi r3, [r6], #-1282
 *   @0x310426 strls r4, [r2], -r0, lsr #12
 *   @0x31042a .word 0xff86f7fe
 *   @0x31042e .word 0xf88d4659
 *   @0x310432 .word 0xf8cd8004
 *   @0x310436 .word 0xf8cd8010
 *   @0x31043a strmi r8, [r6], #-20
 *   @0x31043e .word 0x96034650
 *   @0x310442 blx 0xfefce444 <b2_toiTime+0xfffffffffe874fa0>
 *   @0x310446 stmvs r3!, {r0, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x31044a movwhs r6, #0x10e3
 *   @0x31044e andlo pc, r0, r9, lsl #17
 *   @0x310452 pop {r0, r1, r2, r12, sp, pc}
 *   @0x310456 strlt r8, [r8, #-0xff0]
 *   @0x31045a .word 0x73fff64f
 *   @0x31045e mulsle r5, r9, r2
 *   @0x310462 svcvc #0xc3f5b1
 *   @0x310466 vld2.8 {d29, d31}, [pc], r11
 *   @0x31046a ldrmi r7, [r9], #-963
 *   @0x31046e strblo pc, [r12, #-0x8d0]
 *   @0x310472 andle r4, r11, #-1879048183
 *   @0x310476 ldrblo pc, [r0, #-0x8d0]
 *   @0x31047a eoreq pc, r1, r3, asr r8
 *   @0x31047e .word 0xf8d0bd08
 *   @0x310482 .word 0xb1200c0c
 *   @0x310486 strmi r6, [r8], -r3, asr #18
 *   @0x31048a stclt p7, c4, [r8, #-608]
 *   @0x31048e stclt p0, c2, [r8, #-0]
 *   @0x310492 adceq pc, r0, #208, #16
 *   @0x310496 strtlo pc, [r4], #2256
 *   @0x31049a andsne pc, r1, r3, lsr r8
 *   @0x31049e svclt #0xdbf7ff
 *   @0x3104a2 .word 0x460fb5f8
 *   @0x3104a6 adcmi pc, r0, #208, #16
 *   @0x3104aa sadd16mi r4, sp, r6
 *   @0x3104ae .word 0xf8d4b31c
 *   @0x3104b2 .word 0xf64f15e0
 *   @0x3104b6 addsmi r7, r9, #-67108861
 *   @0x3104ba cmplt r7, pc, lsl r0
 *   @0x3104be .word 0x3c14f8d4
 *   @0x3104c2 strtmi r11, [r0], -r3, lsr #18
 *   @0x3104c6 .word 0xffc7f7ff
 *   @0x3104ca .word 0x0c14f8c4
 *   @0x3104ce .word 0x3c14f8d4
 *   @0x3104d2 .word 0xb166603b
 *   @0x3104d6 .word 0x3c18f8d4
 *   @0x3104da qasxmi r11, r0, r3
 *   @0x3104de strbne pc, [r4, #0x8d4]!
 *   @0x3104e2 .word 0xffb9f7ff
 *   @0x3104e6 .word 0x0c18f8c4
 *   @0x3104ea .word 0x3c18f8d4
 *   @0x3104ee tstlt r5, r3, lsr r0
 *   @0x3104f2 strblo pc, [r8, #0x8d4]!
 *   @0x3104f6 andhs r6, r0, r11, lsr #32
 *   @0x3104fa strdhs r11, r12, [r6], -r8
 *   @0x3104fe ldrblt r11, [r3, #-0xdf8]!
 *   @0x310502 .word 0xf8d02300
 *   @0x310506 strmi r4, [sp], -r0, lsr #5
 *   @0x31050a .word 0x2c009301
 *   @0x31050e .word 0xf8d4d040
 *   @0x310512 blhs 0x31f55a
 *   @0x310516 mcrvs p1, #0x2, sp, c0, c4, #0x1
 *   @0x31051a bge 0x3589a2
 *   @0x31051e mcr2 p7, #0x0, pc, c2, c6, #0x6
 *   @0x310522 strmi r9, [r6], -r1, lsl #22
 *   @0x310526 teqle r3, r0, lsl #22
 *   @0x31052a ldrbne pc, [r12, #-0x8d4]
 *   @0x31052e .word 0xf7ff4620
 *   @0x310532 mlasvs r0, r2, pc, pc
 *   @0x310536 .word 0xf8d44620
 *   @0x31053a .word 0xf7ff1560
 *   @0x31053e rsbsvs pc, r0, r12, lsl #31
 *   @0x310542 .word 0xf8d44620
 *   @0x310546 .word 0xf7ff1568
 *   @0x31054a adcsvs pc, r0, r6, lsl #31
 *   @0x31054e .word 0xf8d44620
 *   @0x310552 .word 0xf7ff156c
 *   @0x310556 rscsvs pc, r0, r0, lsl #31
 *   @0x31055a .word 0xf8d44620
 *   @0x31055e .word 0xf7ff1570
 *   @0x310562 teqvs r0, r10, ror pc
 *   @0x310566 ldrblo pc, [r8, #-0x8d4]!
 *   @0x31056a .word 0xf8946173
 *   @0x31056e shsub16vc r3, r3, r4
 *   @0x310572 ldrblo pc, [r12, #-0x8d4]!
 *   @0x310576 .word 0xf8d48373
 *   @0x31057a .word 0x83b33580
 *   @0x31057e .word 0x6c10f8c4
 *   @0x310582 .word 0x4c10f8d4
 *   @0x310586 strgt r12, [pc, #-0xc0f]
 *   @0x31058a muleq pc, r4, r8
 *   @0x31058e andeq lr, pc, r5, lsl #17
 *   @0x310592 andlt r9, r2, r1, lsl #16
 *   @0x310596 push {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x31059a .word 0x460541f0
 *   @0x31059e adceq pc, r0, #208, #16
 *   @0x3105a2 pkhbtmi r4, r8, lr, lsl #12
 *   @0x3105a6 mcrvc p6, #0x0, r4, c3, c7, #0x0
 *   @0x3105aa tstle r8, r2, lsl #22
 *   @0x3105ae ldmdbmi r6, {r0, r1, r3, r5, r9, r10, r11, sp, lr}
 *   @0x3105b2 ldrbtmi r6, [r9], #-2136
 *   @0x3105b6 ldc2 p7, c15, [r11], {213}
 *   @0x3105ba andhs r4, r0, #344064
 *   @0x3105be .word 0xf7d54479
 *   @0x3105c2 ldmdblt r0, {r0, r3, r4, r5, r7, r10, r11, r12, sp, lr, pc}
 *   @0x3105c6 pop {r0, r1, r3, sp}
 *   @0x3105ca stmdavs r4, {r4, r5, r6, r7, r8, pc}
 *   @0x3105ce rscsle r2, r9, r0, lsl #24
 *   @0x3105d2 strbmi r4, [r1], -r8, lsr #12
 *   @0x3105d6 shasxmi r4, r3, r10
 *   @0x3105da pop {r5, r7, r8, r9, r10, lr}
 *   @0x3105de .word 0xf8d081f0
 *   @0x3105e2 blhs 0x31f61a
 *   @0x3105e6 .word 0xf8d0d0ee
 *   @0x3105ea rfeda r3!
 *   @0x3105ee .word 0xf7ff1011
 *   @0x3105f2 .word 0x4601ff32
 *   @0x3105f6 shasxmi r11, r8, r0
 *   @0x3105fa .word 0xf7d84632
 *   @0x3105fe andhs pc, r0, r3, ror r9
 *   @0x310602 ldrhhi lr, [r0, #141]!
 *   @0x310606 ldrhhi lr, [r0, #141]!
 *   @0x31060a ldrb r11, [r11, #0xf00]!
 *   @0x31060e .word 0xe12e0007
 *   @0x310612 push {r0, r1, r2}
 *   @0x310616 bne 0x19e15fe <b2_toiTime+0x128815a>
 *   @0x31061a svcls #0x99c08
 *   @0x31061e stmdaeq r4, {r1, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x310622 cdpls p8, #0x0, c6, c10, c4, #0x0
 *   @0x310626 smlalmi pc, r12, r4, r8
 *   @0x31062a .word 0xf1c3b124
 *   @0x31062e .word 0xf1c80c00
 *   @0x310632 and r0, r1, r0, lsl #10
 *   @0x310636 ldrmi r4, [r12], r5, asr #12
 *   @0x31063a eorsvs r2, r4, r0, lsl #8
 *   @0x31063e .word 0xf500603c
 *   @0x310642 .word 0xf8945436
 *   @0x310646 .word 0xf1b99012
 *   @0x31064a subsle r0, lr, r0, lsl #30
 *   @0x31064e .word 0xf1bc6840
 *   @0x310652 blx 0x7d425c <b2_toiTime+0x7adb8>
 *   @0x310656 blx 0x94d328 <b2_toiTime+0x1f3e84>
 *   @0x31065a stmdbvs r2, {r0, r4, r5, r11, r12, sp, lr, pc}
 *   @0x31065e movweq lr, #0x8bc3
 *   @0x310662 .word 0x61034413
 *   @0x310666 vstrhs d13, [r0, #-148]
 *   @0x31066a bl 0xff2472a6 <b2_toiTime+0xfffffffffeaede02>
 *   @0x31066e stcle p15, c0, [r2, #-276]
 *   @0x310672 eorsvs r2, r11, r0, lsl #6
 *   @0x310676 bl 0xff08871e <b2_toiTime+0xfffffffffe92f27a>
 *   @0x31067a stcle p15, c0, [r1, #-304]
 *   @0x31067e and r6, sp, r3, lsr #21
 *   @0x310682 eorslo pc, r3, r11, asr #4
 *   @0x310686 .word 0xf06fe00e
 *   @0x31068a .word 0x436b0301
 *   @0x31068e stclle p5, c4, [pc], #624
 *   @0x310692 bl 0xff06104e <b2_toiTime+0xfffffffffe907baa>
 *   @0x310696 stcle p15, c0, [r4, #-304]
 *   @0x31069a subsmi r6, r11, #667648
 *   @0x31069e bvs 0xffbe8792 <b2_toiTime+0xffffffffff48f2ee>
 *   @0x3106a2 ldmdami r10, {r1, r4, sp, lr, pc}
 *   @0x3106a6 .word 0xf7fd6aa1
 *   @0x3106aa eorsvs pc, r8, r4, lsl #23
 *   @0x3106ae sbcmi pc, sp, r4, asr #12
 *   @0x3106b2 stchs p0, c14, [r0, #-156]
 *   @0x3106b6 andeq pc, r0, #204, #2
 *   @0x3106ba bl 0xfefc730a <b2_toiTime+0xfffffffffe86de66>
 *   @0x3106be stcle p15, c0, [r6, #-276]
 *   @0x3106c2 eorsvs r2, r11, r0, lsl #6
 *   @0x3106c6 subseq r6, r11, r3, ror #21
 *   @0x3106ca pop {r0, r1, r4, r5, sp, lr}
 *   @0x3106ce .word 0xf06f83f8
 *   @0x3106d2 blx 0x3d12e0 <error_g0017+0x29f84>
 *   @0x3106d6 strbmi pc, [r5, #-0xc0c]!
 *   @0x3106da .word 0xf24bdcd0
 *   @0x3106de and r3, r11, r3, lsr r0
 *   @0x3106e2 movweq pc, #0x106f
 *   @0x3106e6 .word 0xf105fb03
 *   @0x3106ea stclle p2, c4, [r9], #552
 *   @0x3106ee .word 0xfc0cfb03
 *   @0x3106f2 strbmi r4, [r5, #-0x26d]!
 *   @0x3106f6 stmdami r5, {r4, r6, r7, r10, r11, r12, lr, pc}
 *   @0x3106fa .word 0xf7fd6aa1
 *   @0x3106fe eorsvs pc, r8, r10, asr r11
 *   @0x310702 bvs 0xffb6271a <b2_toiTime+0xffffffffff409276>
 *   @0x310706 blx 0x188e704 <b2_toiTime+0x1135260>
 *   @0x31070a pop {r4, r5, sp, lr}
 *   @0x31070e stclmi p3, c8, [lr], {248}
 *   @0x310712 teqlt r3, #1020
 *   @0x310716 bhs 0x1b10722 <b2_toiTime+0x13b727e>
 *   @0x31071a .word 0x4604b570
 *   @0x31071e stmdble r5, {r1, r2, r3, r9, r10, lr}
 *   @0x310722 tsths r2, r0, lsl #16
 *   @0x310726 ldrhtmi lr, [r0], #-141
 *   @0x31072a bllt 0xfe5ce726 <b2_toiTime+0xfffffffffde75282>
 *   @0x31072e ldrdvs r1, r2, [r2], r3
 *   @0x310732 ldrdvs r0, r1, [r3], #139
 *   @0x310736 .word 0x71032301
 *   @0x31073a cmplt r2, r3, asr #2
 *   @0x31073e stmvs r3!, {r8, r10, sp} ^
 *   @0x310742 andle r4, r6, #-805306359
 *   @0x310746 .word 0xf7fe4630
 *   @0x31074a stmdbne r3!, {r1, r7, r8, r10, r11, r12, sp, lr, pc} ^
 *   @0x31074e ldrvc r3, [r8], #-1281
 *   @0x310752 ldcllt p7, c14, [r0, #-980]!
 *   @0x310756 mvnsmi lr, sp, lsr #18
 *   @0x31075a stmibvs r4, {r1, r2, r9, r10, lr} ^
 *   @0x31075e .word 0xf894460d
 *   @0x310762 ldmdblt r11!, {r6, r12, sp} ^
 *   @0x310766 .word 0x8000f8d1
 *   @0x31076a stmdavs pc, {r0, r8, r9, sp} ^
 *   @0x31076e .word 0xf8844620
 *   @0x310772 .word 0xf7fd3040
 *   @0x310776 ldmdblt r8, {r0, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x31077a strbmi r4, [r1], -r0, lsr #12
 *   @0x31077e .word 0xf7ff463a
 *   @0x310782 stmdblt r8!, {r0, r2, r3, r4, r7, r11, r12, sp, lr, pc}
 *   @0x310786 stmvs r9!, {r5, r9, r10, lr}
 *   @0x31078a .word 0xf7ff68ea
 *   @0x31078e .word 0xb118f897
 *   @0x310792 ldmdavs r10, {r0, r1, r4, r5, r7, r8, r11, sp, lr}
 *   @0x310796 andsvs r11, r8, r2, lsl #18
 *   @0x31079a ldrhhi lr, [r0, #141]!
 *   @0x31079e mvnsmi lr, sp, lsr #18
 *   @0x3107a2 stmibvs r5, {r0, r1, r2, r9, r10, lr} ^
 *   @0x3107a6 .word 0xf895460c
 *   @0x3107aa stmiblt r11!, {r6, r12, sp}
 *   @0x3107ae .word 0x8000f8d1
 *   @0x3107b2 stmdavs lr, {r0, r8, r9, sp} ^
 *   @0x3107b6 .word 0xf8854628
 *   @0x3107ba .word 0xf7fd3040
 *   @0x3107be stmdblt r8!, {r0, r2, r3, r4, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3107c2 strbmi r4, [r1], -r8, lsr #12
 *   @0x3107c6 .word 0xf7ff4632
 *   @0x3107ca .word 0xb128f879
 *   @0x3107ce ldmdavs r10, {r0, r1, r3, r4, r5, r7, r8, r11, sp, lr}
 *   @0x3107d2 andsvs r11, r8, r10, lsl r11
 *   @0x3107d6 ldrhhi lr, [r0, #141]!
 *   @0x3107da andeq pc, r12, r5, lsl #2
 *   @0x3107de .word 0xf7ff2103
 *   @0x3107e2 .word 0x4606f85e
 *   @0x3107e6 ldmibvs r11!, {r3, r5, r8, r12, sp, pc}
 *   @0x3107ea ldmiblt r2!, {r1, r3, r4, r11, sp, lr}
 *   @0x3107ee pop {r3, r4, sp, lr}
 *   @0x3107f2 qsub8mi r8, r8, r0
 *   @0x3107f6 stmvs r2!, {r0, r5, r7, r11, sp, lr} ^
 *   @0x3107fa .word 0xf7fd4633
 *   @0x3107fe strtmi pc, [r8], -r11, asr #20
 *   @0x310802 ldrtmi r6, [r3], -r1, lsr #18
 *   @0x310806 .word 0xf7fd6962
 *   @0x31080a strtmi pc, [r8], -r5, asr #20
 *   @0x31080e movwhs r6, #0x19a1
 *   @0x310812 pop {r1, r5, r6, r7, r8, r11, sp, lr}
 *   @0x310816 .word 0xf7fd41f0
 *   @0x31081a pop {r0, r2, r3, r4, r5, r9, r11, r12, sp, pc}
 *   @0x31081e ldrblt r8, [pc, #-0x1f0]!
 *   @0x310822 bvs 0x1be203a <b2_toiTime+0x1488b96>
 *   @0x310826 stmdblt r11, {r2, r5, r12, sp}
 *   @0x31082a ands r2, pc, r0, lsl #10
 *   @0x31082e ldmibvs sp, {r0, r9, r10, r11, sp, pc} ^
 *   @0x310832 ldrtmi r10, [r2], -r2, lsl #22
 *   @0x310836 stc2l p7, c15, [lr, #-1012]!
 *   @0x31083a stmdahs r0, {r0, r1, r12, pc}
 *   @0x31083e stmdbls r2, {r2, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x310842 bge 0x3e20ea <error_g0017+0x3ad8e>
 *   @0x310846 .word 0xf7d63101
 *   @0x31084a blls 0x40fa06 <g_RomDisk+0x181e6>
 *   @0x31084e ldmdblt r11!, {r0, r2, r9, r10, lr}
 *   @0x310852 tstlt r2, r2, lsl #20
 *   @0x310856 .word 0xf5a59901
 *   @0x31085a blls 0x3cc322 <error_g0017+0x24fc6>
 *   @0x31085e strbtpl r2, [r10], #512
 *   @0x310862 ldmdblt r11, {r0, r1, r5, r6, r10, r11, sp, lr}
 *   @0x310866 ldrtmi r6, [r1], -r0, ror #20
 *   @0x31086a blx 0xff6ce7ce <b2_toiTime+0xfffffffffef7532a>
 *   @0x31086e andlt r4, r4, r8, lsr #12
 *   @0x310872 ldrlt r11, [r3, #-0xd70]
 *   @0x310876 .word 0x3080f8d0
 *   @0x31087a qdaddlt r6, r11, r3
 *   @0x31087e stm sp, {r0, r3, r11, sp, lr}
 *   @0x310882 strbtmi r0, [r9], -r6
 *   @0x310886 ldmdavs r8, {r1, r3, r4, r11, sp, lr} ^
 *   @0x31088a .word 0x47906852
 *   @0x31088e .word 0xf8d0e008
 *   @0x310892 .word 0xf8d332a0
 *   @0x310896 ldmdblt r10, {r2, r4, r6, r7, r10, sp}
 *   @0x31089a ldrteq pc, [r4], #2259
 *   @0x31089e blx 0xff04e802 <b2_toiTime+0xfffffffffe8f535e>
 *   @0x3108a2 ldclt p0, c11, [r0, #-8]
 *   @0x3108a6 .word 0xe92d0000
 *   @0x3108aa ssub8mi r4, lr, r0
 *   @0x3108ae strblo pc, [r0, #0x8df]!
 *   @0x3108b2 strmi r11, [r11], r9, lsr #1
 *   @0x3108b6 ldrbtmi r4, [r11], #-1559
 *   @0x3108ba .word 0xf89d681b
 *   @0x3108be strmi r1, [r4], -r12, asr #1
 *   @0x3108c2 ldmdavs r10, {r0, r2, r11, sp, lr}
 *   @0x3108c6 tstls r3, #8, #2
 *   @0x3108ca stmiblt r1, {r0, r1, r2, r5, r9, r12, pc} ^
 *   @0x3108ce .word 0xa004f8d0
 *   @0x3108d2 mullo r12, r10, r8
 *   @0x3108d6 .word 0xf10db99b
 *   @0x3108da andshs r0, r12, #128, #16
 *   @0x3108de .word 0x9000f8d6
 *   @0x3108e2 .word 0xf5a54640
 *   @0x3108e6 bls 0xfcc27e <b2_toiTime+0x872dda>
 *   @0x3108ea ldrbmi r2, [r0], -r1, lsl #6
 *   @0x3108ee ldrbmi r9, [r9], -r1, lsl #6
 *   @0x3108f2 strbmi r9, [r3], -r0, lsl #4
 *   @0x3108f6 .word 0xf8cd463a
 *   @0x3108fa .word 0xf7ff9080
 *   @0x3108fe ldmdbvc r3!, {r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x310902 ssatmi r11, #0x11, r3, asr #3
 *   @0x310906 .word 0x61672700
 *   @0x31090a stceq p1, c15, [r0], {13}
 *   @0x31090e ldm r8!, {r0, r1, r2, r5, r7, r8, sp, lr}
 *   @0x310912 stm r12!, {r0, r1, r2, r3}
 *   @0x310916 ldm r8, {r0, r1, r2, r3}
 *   @0x31091a .word 0xf10d0007
 *   @0x31091e .word 0xf8db0880
 *   @0x310922 .word 0xf8cd3014
 *   @0x310926 movwls r8, #0xa034
 *   @0x31092a andeq lr, r7, r12, lsl #17
 *   @0x31092e stmdbls r10, {r0, r1, r4, r5, r7, r11, sp, lr}
 *   @0x310932 vqsub.s8 d4, d16, d9
 *   @0x310936 eor r8, r11, r2, lsr #5
 *   @0x31093a ldrsblo pc, [r4], -r11
 *   @0x31093e ldrmi r6, [r3], #-2426
 *   @0x310942 stmdble r4, {r5, r6, r8, r9, r11, sp}
 *   @0x310946 tsths r2, r0, lsr r8
 *   @0x31094a blx 0x21ce946 <b2_toiTime+0x1a754a2>
 *   @0x31094e ldclne p0, c14, [r9, #108]
 *   @0x310952 adcsvs r2, r3, r1, lsl #4
 *   @0x310956 teqvc r2, r9, asr #17
 *   @0x31095a ldrshvc r6, [r2, #-1]!
 *   @0x31095e stmibne r8, {r0, r1, r3, r4, r7, r8, r12, sp, pc}
 *   @0x310962 .word 0x27ff4632
 *   @0x310966 andle r4, r2, r2, lsl #5
 *   @0x31096a andlo r7, r1, #385875968
 *   @0x31096e stmdblo r1, {r1, r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x310972 ldrtmi r4, [r1], #-603
 *   @0x310976 rscslo pc, pc, #79
 *   @0x31097a movweq pc, #0x7003
 *   @0x31097e vpmax.u8 d15, d3, d2
 *   @0x310982 andsmi r7, r3, r10, lsl #24
 *   @0x310986 ldmdbvc r3!, {r0, r1, r3, r10, r12, sp, lr}
 *   @0x31098a .word 0xf0002b00
 *   @0x31098e .word 0xe7b88276
 *   @0x310992 smlalslo pc, r9, r5, r8
 *   @0x310996 .word 0xf10db193
 *   @0x31099a ldrtmi r0, [r9], -r12, ror #16
 *   @0x31099e .word 0x46402214
 *   @0x3109a2 cdp p5, #0x0, c15, c6, c5, #0x5
 *   @0x3109a6 .word 0xf5054620
 *   @0x3109aa .word 0x46427190
 *   @0x3109ae blx 0xfe7ce9aa <b2_toiTime+0xfffffffffe075506>
 *   @0x3109b2 strbmi r4, [r1], -r0, lsr #12
 *   @0x3109b6 addvc pc, r6, #20971520
 *   @0x3109ba blx 0xfe64e9b6 <b2_toiTime+0xfffffffffdef5512>
 *   @0x3109be beq 0xfe34cb02 <b2_toiTime+0xfffffffffdbf365e>
 *   @0x3109c2 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x3109c6 streq lr, [r10, -sp, lsl #22]
 *   @0x3109ca stmeq r8!, {r0, r2, r8, r12, sp, lr, pc} ^
 *   @0x3109ce .word 0xf8cd3710
 *   @0x3109d2 smladxls r6, r8, r0, r8
 *   @0x3109d6 stmdaeq r12!, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x3109da .word 0xf8cdaf16
 *   @0x3109de strls r8, [pc, -r0, asr #32]
 *   @0x3109e2 ldrmi r9, [r9, #0xf0a]!
 *   @0x3109e6 rschi pc, r4, r0
 *   @0x3109ea ldmdavc r11!, {r1, r2, r8, r9, r10, r11, r12, pc}
 *   @0x3109ee svceq #0x3ea1a
 *   @0x3109f2 sbchi pc, pc, r0
 *   @0x3109f6 ldmdage r6, {r1, r4, r5, r8, r9, r10, r11, r12, pc}
 *   @0x3109fa ldrbmi r6, [r9], -r3, lsr #18
 *   @0x3109fe strls r4, [r0, -r10, asr #12]
 *   @0x310a02 movwhs r9, #0x1301
 *   @0x310a06 blls 0x6b5616 <g_SWFlinevertbuff+0x6254e>
 *   @0x310a0a mrc2 p7, #0x4, apsr_nzcv, c13, c14, #0x7
 *   @0x310a0e ldrbmi r6, [r9], -r3, lsr #18
 *   @0x310a12 strls r4, [r0, -r10, asr #12]
 *   @0x310a16 movwls r10, #0x181b
 *   @0x310a1a movwls r2, #0x2300
 *   @0x310a1e .word 0xf7fe9b0e
 *   @0x310a22 ldmdbls r6, {r1, r4, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x310a26 smlabtls r9, r10, r6, r0
 *   @0x310a2a adchi pc, r9, r0, lsl #2
 *   @0x310a2e .word 0xf010981b
 *   @0x310a32 .word 0xf0400310
 *   @0x310a36 svcls #0x1880a4
 *   @0x310a3a ldrsbths pc, [r4], #133
 *   @0x310a3e .word 0x1104f8d5
 *   @0x310a42 .word 0xf105970b
 *   @0x310a46 andsls r0, r1, #240, #14
 *   @0x310a4a ssatmi r9, #0x1d, sp, lsl #20
 *   @0x310a4e svcls #0x9970c
 *   @0x310a52 .word 0xf0009205
 *   @0x310a56 .word 0xf007020a
 *   @0x310a5a andsls r0, r4, #1310720
 *   @0x310a5e bls 0x7766ba <b2_toiTime+0x1d216>
 *   @0x310a62 .word 0xf0004293
 *   @0x310a66 .word 0xf8dd8096
 *   @0x310a6a bl 0xff470b32 <b2_toiTime+0xfffffffffed1768e>
 *   @0x310a6e strbmi r0, [r2], #-524
 *   @0x310a72 ldcvc p8, c15, [r12], {18}
 *   @0x310a76 eorsle r2, r7, r0, lsl #30
 *   @0x310a7a svchs #0x9f15
 *   @0x310a7e .word 0xf852d06d
 *   @0x310a82 bne 0x22efd3a <b2_toiTime+0x1b96896>
 *   @0x310a86 svcls #0xb46b8
 *   @0x310a8a stclle p5, c4, [r6], #-736
 *   @0x310a8e stchs p8, c15, [r8], #328
 *   @0x310a92 ssatmi r1, #0x19, r7, asr #16
 *   @0x310a96 strbmi r9, [r7, #-0xf0b]
 *   @0x310a9a .word 0xf895dc5f
 *   @0x310a9e strdlt r1, r2, [r9, -r8]!
 *   @0x310aa2 blx 0x3992fc <ft_adobe_glyph_list+0x89d8>
 *   @0x310aa6 .word 0xf8d35303
 *   @0x310aaa ands r3, r10, r0, asr #2
 *   @0x310aae bl 0xff376ee2 <b2_toiTime+0xfffffffffec1da3e>
 *   @0x310ab2 .word 0xf8d50c02
 *   @0x310ab6 bls 0x954ebe <b2_toiTime+0x1fba1a>
 *   @0x310aba blle 0x6a20f2 <g_SWFlinevertbuff+0x4f02a>
 *   @0x310abe .word 0xf5022114
 *   @0x310ac2 blx 0x3612cc <_ZTS12CDS_Priority+0x3324>
 *   @0x310ac6 .word 0x0c125303
 *   @0x310aca .word 0xf8d30412
 *   @0x310ace .word 0xf5a33140
 *   @0x310ad2 addsmi r3, r10, #128, #6
 *   @0x310ad6 .word 0x4613bfb8
 *   @0x310ada .word 0xf502e003
 *   @0x310ade .word 0x0c1b4300
 *   @0x310ae2 bls 0x951b56 <b2_toiTime+0x1f86b2>
 *   @0x310ae6 mlas r12, r11, r10, r1
 *   @0x310aea .word 0xb3b79f14
 *   @0x310aee stcvc p8, c15, [r12], #328
 *   @0x310af2 stmdaeq r7, {r0, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x310af6 svcls #0x59707
 *   @0x310afa stcle p5, c4, [lr], #-736
 *   @0x310afe stchs p8, c15, [r8], #328
 *   @0x310b02 addsmi r4, r7, #167772160
 *   @0x310b06 .word 0xf895dc29
 *   @0x310b0a strdlt r2, r3, [r10, -r8]!
 *   @0x310b0e blx 0x399368 <ft_adobe_glyph_list+0x8a44>
 *   @0x310b12 .word 0xf8d35303
 *   @0x310b16 ands r3, r11, r0, asr #2
 *   @0x310b1a stmdbls r5, {r0, r1, r2, r9, r11, r12, pc}
 *   @0x310b1e stmdaeq r1, {r1, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x310b22 .word 0x2100f8d5
 *   @0x310b26 bls 0xaa216e <b2_toiTime+0x348cca>
 *   @0x310b2a tsths r4, lr, lsl #22
 *   @0x310b2e andmi pc, r0, #8388608
 *   @0x310b32 movwpl pc, #0x3b01
 *   @0x310b36 ldreq r0, [r2], #-3090
 *   @0x310b3a .word 0x3140f8d3
 *   @0x310b3e orrlo pc, r0, #12582912
 *   @0x310b42 svclt #0xa8429a
 *   @0x310b46 and r4, r3, r3, lsl r6
 *   @0x310b4a movwmi pc, #0x502
 *   @0x310b4e ldreq r0, [r11], #-3099
 *   @0x310b52 svcls #0x99a1e
 *   @0x310b56 .word 0xb15f1a9b
 *   @0x310b5a movwlo lr, #0x1003
 *   @0x310b5e .word 0x0c14f10c
 *   @0x310b62 bls 0x98a95e <b2_toiTime+0x2314ba>
 *   @0x310b66 ldrmi r9, [r10], #-3849
 *   @0x310b6a .word 0xf0479219
 *   @0x310b6e andsls r0, r6, #16, #4
 *   @0x310b72 bls 0xabd01a <b2_toiTime+0x363b76>
 *   @0x310b76 tstls lr, #318767104
 *   @0x310b7a tsteq r0, #64
 *   @0x310b7e qadd16mi r9, r0, r11
 *   @0x310b82 bge 0x9fafe2 <b2_toiTime+0x2a1b3e>
 *   @0x310b86 .word 0xf9a6f7fd
 *   @0x310b8a ldmdavc r11!, {r1, r2, r8, r9, r10, r11, r12, pc}
 *   @0x310b8e movweq lr, #0xaa23
 *   @0x310b92 .word 0xf009703b
 *   @0x310b96 blhs 0x4d17ba <SrcVerts+0x2e7fe>
 *   @0x310b9a svcls #0x6d105
 *   @0x310b9e beq 0xfe34cce2 <b2_toiTime+0xfffffffffdbf383e>
 *   @0x310ba2 strls r3, [r6, -r1, lsl #14]
 *   @0x310ba6 b 0x1708bb2 <b2_toiTime+0xfaf70e>
 *   @0x310baa .word 0xf1090a5a
 *   @0x310bae ldr r0, [r7, -r1, lsl #18]
 *   @0x310bb2 ldmdblt pc, {r3, r8, r9, r10, r11, r12, pc} ^
 *   @0x310bb6 stmeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x310bba .word 0x0108eb0d
 *   @0x310bbe .word 0xf101aa1b
 *   @0x310bc2 strblo r0, [r8, #0x910]!
 *   @0x310bc6 beq 0x194d002 <b2_toiTime+0x11f3b5e>
 *   @0x310bca sub r9, lr, r6, lsl #4
 *   @0x310bce .word 0xb14b6963
 *   @0x310bd2 bhs 0x32b562
 *   @0x310bd6 bllo 0x387bf6 <_ZTS13C_UTF16String+0x1eca2>
 *   @0x310bda blx 0x399434 <ft_adobe_glyph_list+0x8b10>
 *   @0x310bde bvs 0x19e17f2 <b2_toiTime+0x128834e>
 *   @0x310be2 ble 0x145b7ea <b2_toiTime+0xd02346>
 *   @0x310be6 .word 0x2100af16
 *   @0x310bea ldcge p2, c2, [r11, #-80]
 *   @0x310bee .word 0xf5a54638
 *   @0x310bf2 teqhs r1, #56832
 *   @0x310bf6 qadd16mi r9, r8, r6
 *   @0x310bfa .word 0x21006923
 *   @0x310bfe tstls r10, #20, #4
 *   @0x310c02 ldcl p5, c15, [r6], {165}
 *   @0x310c06 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x310c0a .word 0xf7fd462a
 *   @0x310c0e eor pc, pc, r3, ror #18
 *   @0x310c12 mullo r0, r9, r8
 *   @0x310c16 svceq #0x3ea18
 *   @0x310c1a blls 0xfc4c92 <b2_toiTime+0x86b7ee>
 *   @0x310c1e usaxmi r4, r9, r0
 *   @0x310c22 movwls r4, #0x63a
 *   @0x310c26 movwls r6, #0x1923
 *   @0x310c2a movwls r2, #0x2301
 *   @0x310c2e .word 0xf7fe462b
 *   @0x310c32 ldmdbls r2!, {r1, r3, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x310c36 ldmdage r11, {r0, r1, r5, r8, r11, sp, lr}
 *   @0x310c3a .word 0x9100463a
 *   @0x310c3e movwls r4, #0x1659
 *   @0x310c42 movwls r2, #0x2300
 *   @0x310c46 .word 0xf7fe462b
 *   @0x310c4a qsub16mi pc, r0, lr
 *   @0x310c4e bge 0x9e259a <b2_toiTime+0x2890f6>
 *   @0x310c52 .word 0xf940f7fd
 *   @0x310c56 movweq pc, #0x7007
 *   @0x310c5a blhs 0x4de866 <SrcVerts+0x3b8aa>
 *   @0x310c5e .word 0xf109bf0a
 *   @0x310c62 b 0x16d306e <b2_toiTime+0xf79bca>
 *   @0x310c66 .word 0xf04f0858
 *   @0x310c6a bls 0x592e72 <g_SWFlineaavertbuff+0x3fdaa>
 *   @0x310c6e .word 0xd1cf4297
 *   @0x310c72 ldrhs r6, [r4, -r3, lsr #17]
 *   @0x310c76 cmpvs sp, r0, lsl #10
 *   @0x310c7a movwls r10, #0x7b1b
 *   @0x310c7e addmi r6, r5, #96, #18
 *   @0x310c82 adchi pc, sp, r0, lsl #1
 *   @0x310c86 movwmi pc, #0x5b07
 *   @0x310c8a .word 0xf01369db
 *   @0x310c8e svclt #0xc0f0c
 *   @0x310c92 beq 0x34cdd6
 *   @0x310c96 beq 0x38cdda <_ZTS7CBucketILj16384ELj262144ELb1EE+0xe36>
 *   @0x310c9a svceq #0xf1ba
 *   @0x310c9e .word 0xf105d002
 *   @0x310ca2 and r0, r0, r1, lsl #18
 *   @0x310ca6 ldrbeq r4, [r11], r9, lsr #13
 *   @0x310caa blx 0x505e5c <SrcVerts+0x62ea0>
 *   @0x310cae blx 0x4e18cc <SrcVerts+0x3e910>
 *   @0x310cb2 bvs 0xfe9614de <b2_toiTime+0xfffffffffe20803a>
 *   @0x310cb6 .word 0xc028f8d2
 *   @0x310cba .word 0xf1c3b28b
 *   @0x310cbe .word 0xf8cd0800
 *   @0x310cc2 blx 0xaf0d5a <b2_toiTime+0x3978b6>
 *   @0x310cc6 .word 0xf1c2f28c
 *   @0x310cca .word 0xf8cd0800
 *   @0x310cce .word 0xb10b8018
 *   @0x310cd2 orrlo pc, r0, #817889280
 *   @0x310cd6 .word 0xf5c2b10a
 *   @0x310cda addsmi r3, r10, #128, #4
 *   @0x310cde .word 0x4613bfb8
 *   @0x310ce2 ldrsbhi pc, [r8], -sp
 *   @0x310ce6 stmdalo r1, {r0, r3, r9, r11, r12, pc}
 *   @0x310cea svclt #0xb84590
 *   @0x310cee strmi r4, [r1, #0x690]
 *   @0x310cf2 .word 0xf109d209
 *   @0x310cf6 ldrmi r0, [r12], #513
 *   @0x310cfa .word 0x4c00f50c
 *   @0x310cfe andmi pc, r2, r7, lsl #22
 *   @0x310d02 strbmi r6, [r0, #-0xa80]!
 *   @0x310d06 .word 0xb14ddb10
 *   @0x310d0a strbmi r1, [r1], #-3690
 *   @0x310d0e smlatbmi r0, r1, r5, pc
 *   @0x310d12 andmi pc, r2, #7168
 *   @0x310d16 addmi r6, r10, #598016
 *   @0x310d1a adchi pc, sp, r0, lsl #6
 *   @0x310d1e andeq pc, r0, #200, #2
 *   @0x310d22 svclt #0xb8429a
 *   @0x310d26 adc r4, r6, r3, asr #12
 *   @0x310d2a cdpne p1, #0x6, c11, c8, c5, #0x2
 *   @0x310d2e .word 0xf5a14441
 *   @0x310d32 blx 0x4e113c <SrcVerts+0x3e180>
 *   @0x310d36 bvs 0xfe320d3e <b2_toiTime+0xfffffffffdbc789a>
 *   @0x310d3a .word 0xdc044288
 *   @0x310d3e smlabteq r0, r8, r1, pc
 *   @0x310d42 blle 0x3a1776 <af_latn_ordn_style_class+0xe>
 *   @0x310d46 .word 0xf04fe00f
 *   @0x310d4a blx 0x4d2d54 <SrcVerts+0x2fd98>
 *   @0x310d4e ldmibvs r2, {r1, r9, lr} ^
 *   @0x310d52 strle r0, [r8], #-1746
 *   @0x310d56 ldmdbge r11, {r5, r7, r11, sp, lr}
 *   @0x310d5a movweq lr, #0x3bc8
 *   @0x310d5e rsbls pc, r12, sp, asr #17
 *   @0x310d62 .word 0xf7fd931c
 *   @0x310d66 blx 0x5109f4 <SrcVerts+0x6da38>
 *   @0x310d6a bvs 0xfe9a1986 <b2_toiTime+0xfffffffffe2484e2>
 *   @0x310d6e addsvs r4, r10, #1107296256
 *   @0x310d72 svceq #0xf1ba
 *   @0x310d76 blx 0x504d90 <SrcVerts+0x61dd4>
 *   @0x310d7a bvs 0xfe9a19a6 <b2_toiTime+0xfffffffffe248502>
 *   @0x310d7e addsvs r4, r10, #1107296256
 *   @0x310d82 .word 0xf105b19d
 *   @0x310d86 blx 0x4df18c <SrcVerts+0x3c1d0>
 *   @0x310d8a blx 0x4e15a8 <SrcVerts+0x3e5ec>
 *   @0x310d8e bvs 0x1762db6 <b2_toiTime+0x1009912>
 *   @0x310d92 .word 0x3024f8d8
 *   @0x310d96 mulle r8, r9, r2
 *   @0x310d9a bne 0xff56b7e2 <b2_toiTime+0xfffffffffee1233e>
 *   @0x310d9e .word 0x2028f8d8
 *   @0x310da2 .word 0xf7d41a80
 *   @0x310da6 .word 0xf8c8f887
 *   @0x310daa .word 0xf1ba002c
 *   @0x310dae andsle r0, r4, r0, lsl #30
 *   @0x310db2 andmi pc, r9, #7168
 *   @0x310db6 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x310dba stmdbmi r9, {r0, r1, r2, r8, r9, r11, r12, sp, lr, pc}
 *   @0x310dbe .word 0xf8d96a51
 *   @0x310dc2 addsmi r3, r9, #36
 *   @0x310dc6 bvs 0xfe744dee <b2_toiTime+0xfffffffffdfeb94a>
 *   @0x310dca .word 0xf8d91ac9
 *   @0x310dce bne 0xfe318e76 <b2_toiTime+0xfffffffffdbbf9d2>
 *   @0x310dd2 .word 0xf870f7d4
 *   @0x310dd6 eoreq pc, r12, r9, asr #17
 *   @0x310dda strlo r3, [r1, #-0x501]
 *   @0x310dde stmvs r3!, {r1, r2, r3, r6, r8, r9, r10, sp, lr, pc}
 *   @0x310de2 ldmdbvs sp, {r2, r4, r8, r9, r10, sp} ^
 *   @0x310de6 stclo p3, c11, [r1, #-212]
 *   @0x310dea strtmi r6, [r9], -r0, lsr #17
 *   @0x310dee .word 0xf82df7fd
 *   @0x310df2 stmdavs r3, {r0, r11, sp, lr} ^
 *   @0x310df6 .word 0xfc01fb07
 *   @0x310dfa stmdaeq r12, {r2, r8, r9, r11, sp, lr, pc}
 *   @0x310dfe .word 0x2028f8d8
 *   @0x310e02 mcrrne p4, #0x1, r4, r10, c3
 *   @0x310e06 ldmibmi pc!, {r0, r1, r8, r10, r12, sp, lr, pc} ^
 *   @0x310e0a andmi pc, r2, #7168
 *   @0x310e0e ldmdbeq pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x310e12 ldrmi r6, [r1, #0xa92]
 *   @0x310e16 .word 0xf8c8dae6
 *   @0x310e1a strbmi r3, [r3], -r8, lsr #32
 *   @0x310e1e .word 0xf01369db
 *   @0x310e22 sbcsle r0, pc, r12, lsl #30
 *   @0x310e26 stmdavs r2, {r0, r8, r11, r12, sp} ^
 *   @0x310e2a .word 0x4101fb07
 *   @0x310e2e ldrmi r6, [r3], #-2699
 *   @0x310e32 ldrb r6, [r7, r11, lsl #5]
 *   @0x310e36 .word 0xb1279f08
 *   @0x310e3a .word 0x73232301
 *   @0x310e3e cmnvc r3, r0, lsl #6
 *   @0x310e42 svcls #0x8e01b
 *   @0x310e46 .word 0xf04f4625
 *   @0x310e4a stmdbvs r3!, {r0, r11} ^
 *   @0x310e4e rscsle r4, r3, #-268435447
 *   @0x310e52 ldreq r6, [r9], r11, ror #19
 *   @0x310e56 ldrbmi sp, [r8], -r12, lsl #8
 *   @0x310e5a .word 0xf7fc6a29
 *   @0x310e5e stmibvs r11!, {r1, r2, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x310e62 svceq #0xaf013
 *   @0x310e66 .word 0xf8806aab
 *   @0x310e6a svclt #0x148000
 *   @0x310e6e sbcvs r6, r3, r3, lsl #2
 *   @0x310e72 ldrlo r3, [r4, #-0x701]
 *   @0x310e76 ldrmi lr, [r8], r9, ror #15
 *   @0x310e7a svcls #0x13e775
 *   @0x310e7e ldmdavs r11!, {r0, r1, r2, r5, r9, r11, r12, pc}
 *   @0x310e82 mulle r1, r10, r2
 *   @0x310e86 bl 0xfecce522 <b2_toiTime+0xfffffffffe57507e>
 *   @0x310e8a pop {r0, r3, r5, r12, sp, pc}
 *   @0x310e8e ldrshle r8, [r12], r0
 *   @0x310e92 ldrblt r0, [r7, #0xd]!
 *   @0x310e96 ldrtpl pc, [r6], #-1280
 *   @0x310e9a strmi r4, [lr], -r5, lsl #12
 *   @0x310e9e ldrmi r7, [r7], -r3, lsr #24
 *   @0x310ea2 .word 0xf000b10b
 *   @0x310ea6 .word 0xf505f8cf
 *   @0x310eaa orrsvs r5, lr, r7, lsr r3
 *   @0x310eae .word 0xf105609e
 *   @0x310eb2 bicsvs r0, pc, r8, lsl #12
 *   @0x310eb6 movwhs r6, #0x10df
 *   @0x310eba stcvc p4, c7, [r11, #-908]!
 *   @0x310ebe stmibvs r3!, {r0, r1, r4, r8, r12, sp, pc} ^
 *   @0x310ec2 qdaddlt r7, r11, r11
 *   @0x310ec6 .word 0xf1046a23
 *   @0x310eca shadd16mi r0, r0, r4
 *   @0x310ece movwhs r9, #0x300
 *   @0x310ed2 stmdbgt lr, {r0, r8, r9, r12, pc}
 *   @0x310ed6 stc2l p7, c15, [r7], #1020
 *   @0x310eda eorvc pc, r4, r5, lsl #12
 *   @0x310ede .word 0xf6404631
 *   @0x310ee2 .word 0xf5a5721c
 *   @0x310ee6 andlt lr, r3, r10, ror #22
 *   @0x310eea ldrblt r11, [r0, #0xdf0]!
 *   @0x310eee movwhs r11, #0x108f
 *   @0x310ef2 movwls r10, #0xdd02
 *   @0x310ef6 teqpl r7, #0, #10
 *   @0x310efa ldreq pc, [r0], -r3, lsl #2
 *   @0x310efe stm r5, {r2, r9, r10, lr}
 *   @0x310f02 svcge #0x50006
 *   @0x310f06 muleq r3, r6, r8
 *   @0x310f0a stm r7, {r1, r5, r8, r10, r11, r12, sp, lr}
 *   @0x310f0e stmdblt r2!, {r0, r1}
 *   @0x310f12 ldmibvs r9, {r5, r9, r10, lr}
 *   @0x310f16 .word 0xf7ff69da
 *   @0x310f1a blls 0x410e12 <g_RomDisk+0x195f2>
 *   @0x310f1e .word 0xf1044620
 *   @0x310f22 .word 0xf1070108
 *   @0x310f26 movwls r0, #0x208
 *   @0x310f2a .word 0xf7fd9b02
 *   @0x310f2e stmdavs r0!, {r1, r2, r3, r4, r7, r11, r12, sp, lr, pc} ^
 *   @0x310f32 .word 0xf5044639
 *   @0x310f36 ldrtlo r5, [r8], #-1078
 *   @0x310f3a ldrmi r6, [r8, r3, lsl #16]
 *   @0x310f3e ldm r3, {r0, r1, r2, r8, r9, r11, sp, pc}
 *   @0x310f42 stm r6, {r0, r1}
 *   @0x310f46 ldm r5, {r0, r1}
 *   @0x310f4a stm r4, {r0, r1}
 *   @0x310f4e andlt r0, pc, r3
 *   @0x310f52 push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x310f56 .word 0xf5004ff0
 *   @0x310f5a addlt r5, sp, r6, lsr r5
 *   @0x310f5e stmibvs r11!, {r1, r2, r9, r10, lr} ^
 *   @0x310f62 ldrmi r4, [r7], -r8, lsl #13
 *   @0x310f66 teqlt r11, r11, asr r9
 *   @0x310f6a mulslt r1, r5, r8
 *   @0x310f6e bleq 0x38d6e2 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x173e>
 *   @0x310f72 .word 0xf04fbf38
 *   @0x310f76 and r0, r0, r0, lsl #22
 *   @0x310f7a .word 0xf506469b
 *   @0x310f7e blx 0x1ae6062 <b2_toiTime+0x138cbbe>
 *   @0x310f82 movwls pc, #0x538b
 *   @0x310f86 strbmi r6, [r1, #-0x8a1]
 *   @0x310f8a stmvs r3!, {r0, r2, r8, r12, lr, pc} ^
 *   @0x310f8e strhle r4, [r2, -r11]
 *   @0x310f92 blhs 0x337bae
 *   @0x310f96 smlsdls r0, r3, r0, sp
 *   @0x310f9a ldrtmi r10, [r0], -r6, lsl #22
 *   @0x310f9e blge 0x4f5baa <SrcVerts+0x52bee>
 *   @0x310fa2 strbmi r9, [r3], -r2, lsl #6
 *   @0x310fa6 .word 0xf7ff68e2
 *   @0x310faa bls 0x4cfc82 <SrcVerts+0x2ccc6>
 *   @0x310fae .word 0xf10d68a3
 *   @0x310fb2 stmvs r1!, {r5, r8, r9, r11} ^
 *   @0x310fb6 beq 0x3cbbde <error_g0017+0x24882>
 *   @0x310fba movwls r4, #0x8413
 *   @0x310fbe ldrmi r9, [r9], #-2823
 *   @0x310fc2 stmdbeq r3, {r0, r1, r2, r8, r9, r11, sp, lr, pc}
 *   @0x310fc6 smlattls r9, r11, r12, r7
 *   @0x310fca ldrtmi r11, [r0], -r3, ror #2
 *   @0x310fce muleq r6, r11, r8
 *   @0x310fd2 .word 0xff8bf7ff
 *   @0x310fd6 strbtvc r2, [r11], #768
 *   @0x310fda strtvc r2, [r11], #-769
 *   @0x310fde andge pc, r0, r4, asr #17
 *   @0x310fe2 andls pc, r4, r4, asr #17
 *   @0x310fe6 mlalo r0, r4, r8, pc
 *   @0x310fea movwhs r11, #0x153
 *   @0x310fee andls pc, r0, sp, asr #17
 *   @0x310ff2 ldrtmi r9, [r0], -r1, lsl #6
 *   @0x310ff6 .word 0xf1064653
 *   @0x310ffa ldrbmi r0, [r10], -r8, lsl #2
 *   @0x310ffe blx 0x1a8effc <b2_toiTime+0x1335b58>
 *   @0x311002 muleq r3, r11, r8
 *   @0x311006 .word 0xf8842301
 *   @0x31100a movwhs r3, #0x2020
 *   @0x31100e .word 0xf1046263
 *   @0x311012 stm r3, {r3, r5, r8, r9}
 *   @0x311016 blls 0x45102a <g_RomDisk+0x5980a>
 *   @0x31101a eorsge pc, r0, r4, asr #17
 *   @0x31101e eorsls pc, r4, r4, asr #17
 *   @0x311022 bvs 0xdfd576 <b2_toiTime+0x6a40d2>
 *   @0x311026 tsteq r4, r5, lsl #2
 *   @0x31102a andeq pc, r8, r6, lsl #2
 *   @0x31102e movwhs r9, #0x300
 *   @0x311032 stmdbgt lr, {r0, r8, r9, r12, pc}
 *   @0x311036 ldc2 p7, c15, [r7], #-1020
 *   @0x31103a andhi pc, r8, r4, asr #17
 *   @0x31103e andlt r6, sp, r7, ror #1
 *   @0x311042 svchi #0xf0e8bd
 *   @0x311046 .word 0xf500b5f7
 *   @0x31104a .word 0xf5005437
 *   @0x31104e smladxhs r1, r6, r5, r5
 *   @0x311052 strbtvc r4, [pc], #-1542
 *   @0x311056 stmibvs r2!, {r0, r5, r7, r8, r11, sp, lr} ^
 *   @0x31105a .word 0xff7bf7ff
 *   @0x31105e mlalo r0, r4, r8, pc
 *   @0x311062 smlsdls r1, r3, r1, r11
 *   @0x311066 stmdavs r3!, {r4, r5, r9, r10, lr} ^
 *   @0x31106a .word 0x0108f106
 *   @0x31106e eorseq pc, r8, #1073741825
 *   @0x311072 stmdavs r3!, {r8, r9, r12, pc}
 *   @0x311076 blx 0xb8f074 <b2_toiTime+0x435bd0>
 *   @0x31107a strbtvc r2, [r11], #769
 *   @0x31107e strtvc r2, [r11], #-768
 *   @0x311082 .word 0xf884746b
 *   @0x311086 andlt r3, r3, r0, lsr #32
 *   @0x31108a push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x31108e .word 0xf5004ff0
 *   @0x311092 addlt r5, pc, r7, lsr r4
 *   @0x311096 ldrmi r4, [r7], -r8, lsl #13
 *   @0x31109a andls r4, r0, #162529280
 *   @0x31109e movwls r10, #0x1b06
 *   @0x3110a2 movwls r10, #0x2b07
 *   @0x3110a6 stmvs r1!, {r0, r1, r6, r9, r10, lr}
 *   @0x3110aa stmvs r2!, {r0, r2, r9, r10, lr} ^
 *   @0x3110ae .word 0xf7ff9e18
 *   @0x3110b2 bls 0x9cfb7a <b2_toiTime+0x2766d6>
 *   @0x3110b6 blge 0x522a22 <SrcVerts+0x7fa66>
 *   @0x3110ba movwls r4, #0x1628
 *   @0x3110be andls r10, r0, #9216
 *   @0x3110c2 movwls r4, #0x2632
 *   @0x3110c6 .word 0xf7ff9b19
 *   @0x3110ca blne 0xfff8fb62 <b2_toiTime+0xffffffffff8366be>
 *   @0x3110ce andeq lr, r11, #200, #22
 *   @0x3110d2 blx 0x76b288 <b2_toiTime+0x11de4>
 *   @0x3110d6 .word 0xf8ddf138
 *   @0x3110da blx 0x7b5274 <b2_toiTime+0x5bdd0>
 *   @0x3110de bne 0xfe58d9c2 <b2_toiTime+0xfffffffffde3451e>
 *   @0x3110e2 strmi r6, [r10], #-2330
 *   @0x3110e6 bls 0x4a9556 <SrcVerts+0x659a>
 *   @0x3110ea stmvs r1!, {r0, r1, r5, r7, r11, sp, lr} ^
 *   @0x3110ee ldrmi r4, [r3], #-1168
 *   @0x3110f2 movwls r9, #0xaa08
 *   @0x3110f6 ldrmi r9, [r3], #2823
 *   @0x3110fa bls 0x9a2346 <b2_toiTime+0x248ea2>
 *   @0x3110fe ldrmi r4, [pc], #-1049
 *   @0x311102 .word 0x910b9b09
 *   @0x311106 bl 0x4a2176 <m_CurrentMatrix+0x6>
 *   @0x31110a .word 0xf5050a03
 *   @0x31110e andls r5, r5, #-671088640
 *   @0x311112 ldclvc p14, c10, [r10], {10}
 *   @0x311116 ldm r6, {r1, r3, r5, r6, r8, r12, sp, pc}
 *   @0x31111a strtmi r0, [r8], -r6
 *   @0x31111e .word 0xf7ff9304
 *   @0x311122 blls 0x450cba <g_RomDisk+0x5949a>
 *   @0x311126 ldrbvc r2, [r10], #512
 *   @0x31112a ldrvc r2, [r10], #-513
 *   @0x31112e andhi pc, r0, r4, asr #17
 *   @0x311132 .word 0xf5056067
 *   @0x311136 .word 0xf8935337
 *   @0x31113a .word 0xb1633020
 *   @0x31113e strls r2, [r0, -r0, lsl #6]
 *   @0x311142 strtmi r9, [r8], -r1, lsl #6
 *   @0x311146 .word 0xf1054643
 *   @0x31114a ldrtmi r0, [r2], -r8, lsl #2
 *   @0x31114e eorshi pc, r0, sp, asr #17
 *   @0x311152 .word 0xf7fd970d
 *   @0x311156 ldm r6, {r1, r4, r5, r7, r9, r11, r12, sp, lr, pc}
 *   @0x31115a movwhs r0, #0x1003
 *   @0x31115e eorlo pc, r0, r4, lsl #17
 *   @0x311162 rsbvs r2, r3, #4, #6
 *   @0x311166 msreq APSR_nzcvq, #4, #2
 *   @0x31116a stm r3, {r0, r2, r9, r11, r12, pc}
 *   @0x31116e .word 0xf5050003
 *   @0x311172 .word 0xf8c45338
 *   @0x311176 .word 0x63678030
 *   @0x31117a eorslt pc, r8, r4, asr #17
 *   @0x31117e eorsge pc, r12, r4, asr #17
 *   @0x311182 .word 0xf505605a
 *   @0x311186 .word 0xf8c35236
 *   @0x31118a ldmibvs r3, {r12, pc} ^
 *   @0x31118e qdaddlt r7, r9, r9
 *   @0x311192 .word 0xf1056a11
 *   @0x311196 .word 0x91000008
 *   @0x31119a mrsls r2, apsr
 *   @0x31119e ldmibvs r2, {r0, r4, r6, r8, r11, sp, lr}
 *   @0x3111a2 blx 0xfe38f1a8 <b2_toiTime+0xfffffffffdc35d04>
 *   @0x3111a6 .word 0xf5059b19
 *   @0x3111aa bls 0x9a668e <b2_toiTime+0x24d1ea>
 *   @0x3111ae rscvs r6, r10, r11, lsr #1
 *   @0x3111b2 pop {r0, r1, r2, r3, r12, sp, pc}
 *   @0x3111b6 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x3111ba ldrshlt r4, [r9], r0
 *   @0x3111be stmdavs r11, {r1, r3, r4, r7, r9, r10, lr}
 *   @0x3111c2 .word 0x9088f8dd
 *   @0x3111c6 strmi r2, [r7], -r0, lsl #10
 *   @0x3111ca movwls r4, #0xa688
 *   @0x3111ce ldmdavs r3, {r2, r3, r5, r9, r10, lr}
 *   @0x3111d2 .word 0xf8994616
 *   @0x3111d6 movwls r11, #0xb009
 *   @0x3111da bleq 0x38d94e <_ZTS7CBucketILj16384ELj262144ELb1EE+0x19aa>
 *   @0x3111de svclt #0x38ab0a
 *   @0x3111e2 bleq 0x34d326
 *   @0x3111e6 svceq #0xf1bb
 *   @0x3111ea andhs r11, r10, #12, #30
 *   @0x3111ee andls r2, r8, #-1879048192
 *   @0x3111f2 eorgt pc, r5, r3, asr r8
 *   @0x3111f6 addeq lr, r5, #3072
 *   @0x3111fa andne pc, r5, r9, lsl r8
 *   @0x3111fe andgt pc, r8, r2, asr #17
 *   @0x311202 stclne p1, c11, [r1], #-516
 *   @0x311206 .word 0x91094638
 *   @0x31120a andls r4, r5, #34603008
 *   @0x31120e .word 0xf8cd9306
 *   @0x311212 .word 0xf7fec01c
 *   @0x311216 bls 0x48f462 <prim_v+0x5aae>
 *   @0x31121a ldrsbgt pc, [r12], -sp
 *   @0x31121e strbtmi r9, [r0], #-3081
 *   @0x311222 blls 0x4a946a <SrcVerts+0x64ae>
 *   @0x311226 strlo r9, [r1, #-0xa08]
 *   @0x31122a blle 0xffb61c86 <b2_toiTime+0xffffffffff4087e2>
 *   @0x31122e .word 0xf1bb4621
 *   @0x311232 andle r0, r1, r0, lsl #30
 *   @0x311236 tstls r5, #3342336
 *   @0x31123a umulllo pc, r12, sp, r8
 *   @0x31123e .word 0xf8ddb30b
 *   @0x311242 shsaxmi r9, r8, r0
 *   @0x311246 .word 0x3000f8d8
 *   @0x31124a ldcls p6, c4, [r5, #-132]
 *   @0x31124e movweq lr, #0x9bc3
 *   @0x311252 rscvc lr, r3, #536576
 *   @0x311256 rscvc lr, r3, #165888
 *   @0x31125a andls r6, r5, #3342336
 *   @0x31125e b 0xfe3d7e12 <b2_toiTime+0xfffffffffdc7e96e>
 *   @0x311262 bl 0xfedf01f6 <b2_toiTime+0xfffffffffe696d52>
 *   @0x311266 .word 0xf7fe7be3
 *   @0x31126a bls 0x48f40e <prim_v+0x5a5a>
 *   @0x31126e stcle p5, c4, [r2, #-360]
 *   @0x311272 andsls r4, r6, r8, asr #8
 *   @0x311276 .word 0xf8d8e01e
 *   @0x31127a strmi r3, [r5], #-0
 *   @0x31127e tstls r6, #96468992
 *   @0x311282 .word 0xf899e01a
 *   @0x311286 teqlt r11, r10
 *   @0x31128a ldcls p6, c4, [r4, #-224]
 *   @0x31128e .word 0xf854f7fe
 *   @0x311292 strtmi r3, [r8], #-1025
 *   @0x311296 and r9, r2, r6, lsl r0
 *   @0x31129a .word 0x3000f8d8
 *   @0x31129e .word 0xf8999316
 *   @0x3112a2 teqlt r11, r11
 *   @0x3112a6 qasxmi r4, r1, r8
 *   @0x3112aa .word 0xf7fe9d15
 *   @0x3112ae strtmi pc, [r8], #-2117
 *   @0x3112b2 and r9, r1, r7, lsl r0
 *   @0x3112b6 tstls r7, #3342336
 *   @0x3112ba stmdbge r12, {r0, r1, r2, r3, r8, r9, r11, r12, pc}
 *   @0x3112be movwls r4, #0x650
 *   @0x3112c2 movwls r9, #0x1b10
 *   @0x3112c6 movwls r9, #0x2b11
 *   @0x3112ca .word 0xf7ffc90e
 *   @0x3112ce ldmdbge r2, {r1, r2, r3, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3112d2 uadd16mi r9, r0, r6
 *   @0x3112d6 blls 0x87833a <b2_toiTime+0x11ee96>
 *   @0x3112da stm sp, {r1, r10, r12, pc}
 *   @0x3112de stmdbgt lr, {r3, r5}
 *   @0x3112e2 mrc2 p7, #0x6, apsr_nzcv, c3, c15, #0x7
 *   @0x3112e6 ldrhtvs r6, [r11], #139
 *   @0x3112ea andpl pc, r0, r8, asr #17
 *   @0x3112ee andslt r6, r9, r4, lsr r0
 *   @0x3112f2 svchi #0xf0e8bd
 *   @0x3112f6 .word 0xe92d0000
 *   @0x3112fa ldrshlt r4, [r3], r0
 *   @0x3112fe .word 0x4607461d
 *   @0x311302 ldrsbthi pc, [r4], #-141
 *   @0x311306 strmi r2, [r12], -r0, lsl #6
 *   @0x31130a .word 0xf5b89205
 *   @0x31130e cdpls p15, #0x1, c5, c15, c0, #0x2
 *   @0x311312 andle r9, r4, r6, lsl #6
 *   @0x311316 strhmi pc, [r0, r8]
 *   @0x31131a .word 0x414b424b
 *   @0x31131e movwhs lr, #0x1000
 *   @0x311322 ldmibeq pc!, {r0, r1, r12, sp, lr, pc} ^
 *   @0x311326 andhs pc, r1, #64, #4
 *   @0x31132a svclt #0x82b00
 *   @0x31132e blls 0xa99cb6 <b2_toiTime+0x340812>
 *   @0x311332 .word 0x21009203
 *   @0x311336 .word 0xf8d32228
 *   @0x31133a blge 0x539342 <obj_numb_event+0x23d2>
 *   @0x31133e ldrmi r9, [r8], -r4, lsl #6
 *   @0x311342 .word 0xb000f8da
 *   @0x311346 ldmdb r4!, {r0, r2, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x31134a eorshi pc, r12, sp, asr #17
 *   @0x31134e stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x311352 eorge pc, r0, sp, asr #17
 *   @0x311356 blls 0x3d976e <error_g0017+0x32412>
 *   @0x31135a beq 0xa4d796 <b2_toiTime+0x2f42f2>
 *   @0x31135e andhi pc, r0, sp, asr #17
 *   @0x311362 .word 0xf8cd4658
 *   @0x311366 strbmi r10, [r2], -r4
 *   @0x31136a .word 0xf7d69710
 *   @0x31136e blls 0x510db2 <SrcVerts+0x6ddf6>
 *   @0x311372 andls r4, r12, r1, lsl #12
 *   @0x311376 ldrbmi r11, [r8], -r11, lsr #2
 *   @0x31137a .word 0xffdcf7d5
 *   @0x31137e eorshi pc, r0, sp, asr #17
 *   @0x311382 blls 0x409392 <g_RomDisk+0x11b72>
 *   @0x311386 movwls r9, #0xe00d
 *   @0x31138a ldrsblt pc, [r12], -sp
 *   @0x31138e svceq #0xf1bb
 *   @0x311392 adcshi pc, sp, r0, asr #32
 *   @0x311396 uasxmi r4, r9, r8
 *   @0x31139a .word 0xf5a522bc
 *   @0x31139e blmi 0x1b4b7c6 <b2_toiTime+0x13f2322>
 *   @0x3113a2 vst1.8 {d22, d23, d24, d25}, [pc:256], r11
 *   @0x3113a6 rsbsvs r1, r11, #72, #6
 *   @0x3113aa rscsvs r2, r11, #134217728
 *   @0x3113ae orrlo pc, r0, #1325400064
 *   @0x3113b2 .word 0x63fb633b
 *   @0x3113b6 tsths r0, #536870916
 *   @0x3113ba addslo pc, r12, r7, asr #17
 *   @0x3113be .word 0x73fff64f
 *   @0x3113c2 mlasvs r11, r8, r6, r4
 *   @0x3113c6 adcsvs r6, r11, r11, ror r0
 *   @0x3113ca ldrshvs r6, [r11, -r11]!
 *   @0x3113ce .word 0xf8c7617b
 *   @0x3113d2 .word 0xf8c73080
 *   @0x3113d6 .word 0xf8c73084
 *   @0x3113da .word 0xf8c73088
 *   @0x3113de vhadd.s8 d19, d16, d28
 *   @0x3113e2 .word 0xf1b92301
 *   @0x3113e6 svclt #0x80f00
 *   @0x3113ea .word 0xf8c72330
 *   @0x3113ee stmvs r3!, {r3, r4, r5, r7, r12, sp} ^
 *   @0x3113f2 strtmi r11, [r0], -r3, asr #2
 *   @0x3113f6 bge 0x4b7812 <SrcVerts+0x14856>
 *   @0x3113fa .word 0xf7fc4653
 *   @0x3113fe strmi pc, [r3], r11, lsl #31
 *   @0x311402 ands r11, r0, r0, asr #19
 *   @0x311406 stmdbvs r1!, {r3, r5, r9, r10, lr} ^
 *   @0x31140a blx 0x164f366 <b2_toiTime+0xef5ec2>
 *   @0x31140e stmdahs r0, {r0, r1, r7, r9, r10, lr}
 *   @0x311412 qsub16mi sp, r8, sp
 *   @0x311416 bge 0x4abaa2 <SrcVerts+0x8ae6>
 *   @0x31141a stc2l p7, c15, [r2, #-856]
 *   @0x31141e stmdahs r0, {r0, r1, r7, r9, r10, lr}
 *   @0x311422 stmibvs r3!, {r0, r2, r4, r5, r6, r8, r12, lr, pc}
 *   @0x311426 stmdbls r6, {r0, r1, r2, r8, r9, r12, pc}
 *   @0x31142a bls 0x4fb452 <SrcVerts+0x58496>
 *   @0x31142e .word 0xf7fe440a
 *   @0x311432 strmi pc, [r3], r2, asr #28
 *   @0x311436 tstlt r11, r3, ror #17
 *   @0x31143a stmdblt r11!, {r0, r1, r5, r9, r11, sp, lr}
 *   @0x31143e and r6, r0, r0, lsr #16
 *   @0x311442 stmdbge r6, {r3, r5, r9, r10, lr}
 *   @0x311446 stc2l p7, c15, [r0], #856
 *   @0x31144a svceq #0xf1bb
 *   @0x31144e .word 0xf8d7d15f
 *   @0x311452 strbmi r3, [r3, #-0x84]
 *   @0x311456 ldmdals lr, {r0, r1, r3, r4, r6, r8, r12, lr, pc}
 *   @0x31145a uasxmi r4, r10, r9
 *   @0x31145e .word 0xf7fe465b
 *   @0x311462 stmdahs r0, {r3, r4, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x311466 .word 0xf1b9d152
 *   @0x31146a teqle r2, r0, lsl #30
 *   @0x31146e .word 0x3080f8d6
 *   @0x311472 .word 0x1c5a6bdb
 *   @0x311476 mrcvs p1, #0x1, sp, c2, c6, #0x0
 *   @0x31147a .word 0xf8c76c53
 *   @0x31147e mrrcvs p2, #0x8, r3, r3, c8
 *   @0x311482 .word 0xf8d7b93b
 *   @0x311486 bllt 0xbddeae <b2_toiTime+0x484a0a>
 *   @0x31148a andslo pc, r4, #14090240
 *   @0x31148e addlo pc, r8, #13041664
 *   @0x311492 b 0xfe409516 <b2_toiTime+0xfffffffffdcb0072>
 *   @0x311496 b 0xfe3de1aa <b2_toiTime+0xfffffffffdc84d06>
 *   @0x31149a b 0xfe7e21ee <b2_toiTime+0xfffffffffe088d4a>
 *   @0x31149e ldrbtle r1, [r8], #835
 *   @0x3114a2 ubfx r6, r3, #0x8, #0xf
 *   @0x3114a6 addlo pc, r8, #13041664
 *   @0x3114aa .word 0x3080f8d6
 *   @0x3114ae blhs 0x32c422
 *   @0x3114b2 .word 0xf8d6d0e7
 *   @0x3114b6 blvs 0xff99d6be <b2_toiTime+0xffffffffff24421a>
 *   @0x3114ba sublo lr, r2, #532480
 *   @0x3114be subsmi lr, r2, #532480
 *   @0x3114c2 subne lr, r2, #532480
 *   @0x3114c6 .word 0xf8d663da
 *   @0x3114ca blvs 0xff9dd6d2 <b2_toiTime+0xffffffffff28422e>
 *   @0x3114ce blle 0xfff1c0d6 <b2_toiTime+0xffffffffff7c2c32>
 *   @0x3114d2 .word 0xf8d7e7d7
 *   @0x3114d6 bicslt r3, r3, r8, lsl r2
 *   @0x3114da qsub16mi r6, r8, r9
 *   @0x3114de ldrmi r9, [r9], #-2588
 *   @0x3114e2 .word 0xf7d54411
 *   @0x3114e6 pkhtbmi pc, r3, pc, asr #19
 *   @0x3114ea .word 0xf507b988
 *   @0x3114ee qadd16mi r7, r9, r8
 *   @0x3114f2 strbmi r2, [r11], -r1, lsl #4
 *   @0x3114f6 .word 0xf7fd4620
 *   @0x3114fa strmi pc, [r3], r2, asr #26
 *   @0x3114fe qasxmi r11, r0, r8
 *   @0x311502 .word 0x7121f507
 *   @0x311506 usaxmi r4, r11, r10
 *   @0x31150a blx 0x1d4f508 <b2_toiTime+0x15f6064>
 *   @0x31150e blls 0x522f22 <SrcVerts+0x7ff66>
 *   @0x311512 ldmdavs r8, {r2, r3, r8, r11, r12, pc}
 *   @0x311516 .word 0xff0ef7d5
 *   @0x31151a andslt r4, r3, r8, asr r6
 *   @0x31151e svchi #0xf0e8bd
 *   @0x311522 andeq r11, r0, r0, lsl #30
 *   @0x311526 push {r2, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x31152a ssub8mi r4, pc, r0
 *   @0x31152e strmi r6, [r10], r11, lsl #28
 *   @0x311532 ldrhtlt r4, [r1], pc
 *   @0x311536 .word 0xf8d34605
 *   @0x31153a ldrbtmi r11, [r9], #-4
 *   @0x31153e .word 0xf8dd9209
 *   @0x311542 ldrbmi r8, [r8], -r8, ror #1
 *   @0x311546 stc2l p7, c15, [pc], #848
 *   @0x31154a stmdahs r0, {r2, r3, r12, pc}
 *   @0x31154e ldrhi pc, [r2], -r0
 *   @0x311552 andhs r4, r1, #184, #18
 *   @0x311556 .word 0x0060f8da
 *   @0x31155a .word 0xf7d44479
 *   @0x31155e ldmibmi r5!, {r0, r1, r3, r5, r6, r7, r10, r11, r12, sp, lr, pc}
 *   @0x311562 andsls r4, r2, r9, ror r4
 *   @0x311566 .word 0xf7d44658
 *   @0x31156a .word 0x2100fcde
 *   @0x31156e qadd16mi r9, r8, r6
 *   @0x311572 .word 0xf998f7d5
 *   @0x311576 andsls r4, r11, r4, lsl #12
 *   @0x31157a .word 0xf0412800
 *   @0x31157e cdpls p0, #0x0, c8, c12, c12, #0x5
 *   @0x311582 .word 0xf8cd463b
 *   @0x311586 strtmi r8, [r8], -r0
 *   @0x31158a bls 0x562ed6 <g_SWFlineaavertbuff+0xfe0e>
 *   @0x31158e .word 0x47b06876
 *   @0x311592 andsls r4, r11, r3, lsl #12
 *   @0x311596 mrsle r2, spsr
 *   @0x31159a ldrsbhs pc, [r4], r10
 *   @0x31159e addmi r4, r10, #160, #18
 *   @0x3115a2 movwhs sp, #0x2002
 *   @0x3115a6 stcllt p0, c15, [r7, #0]!
 *   @0x3115aa cdphs p14, #0x0, c9, c0, c9, #0x0
 *   @0x3115ae addshi pc, r5, r1, asr #5
 *   @0x3115b2 andmi pc, r4, #14286848
 *   @0x3115b6 ldmibmi r10, {r4, r6, r9, r10, lr}
 *   @0x3115ba strmi r4, [r0, r10, lsr #12]!
 *   @0x3115be ldmdblt r0!, {r0, r1, r3, r4, r12, pc} ^
 *   @0x3115c2 strtmi r9, [r8], -r12, lsl #28
 *   @0x3115c6 andhi pc, r0, sp, asr #17
 *   @0x3115ca bls 0x562f16 <g_SWFlineaavertbuff+0xfe4e>
 *   @0x3115ce ldmvs r4!, {r0, r1, r3, r4, r5, r9, r10, lr}
 *   @0x3115d2 andsls r4, r11, r0, lsr #15
 *   @0x3115d6 .word 0xf0412800
 *   @0x3115da andls r8, r7, lr, ror r0
 *   @0x3115de cdpls p0, #0x0, c14, c12, c10, #0x0
 *   @0x3115e2 qsaxmi r4, r9, r0
 *   @0x3115e6 .word 0x47986a33
 *   @0x3115ea stmdahs r0, {r0, r1, r3, r4, r12, pc}
 *   @0x3115ee rsbshi pc, r3, r1, asr #32
 *   @0x3115f2 strls r2, [r7], -r1, lsl #12
 *   @0x3115f6 andmi pc, r4, #14286848
 *   @0x3115fa stmibmi r10, {r4, r6, r9, r10, lr}
 *   @0x3115fe movwhs r4, #0x62a
 *   @0x311602 andsls r4, r11, r0, lsr #15
 *   @0x311606 movwhs r11, #0x1920
 *   @0x31160a adcslo pc, r4, #9043968
 *   @0x31160e mul r1, r9, r6
 *   @0x311612 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x311616 stmhs lr, {r6, r7, r9, r12, sp, pc}
 *   @0x31161a .word 0xf8dad107
 *   @0x31161e ldrbmi r4, [r0], -r4, lsl #4
 *   @0x311622 strtmi r4, [r10], -r2, lsl #19
 *   @0x311626 strmi r2, [r0, r0, lsl #6]!
 *   @0x31162a blls 0x9f569e <b2_toiTime+0x29c1fa>
 *   @0x31162e .word 0xf0412b00
 *   @0x311632 .word 0x26018052
 *   @0x311636 and r9, r11, r1, lsl r6
 *   @0x31163a strtmi r4, [r1], -r8, lsr #12
 *   @0x31163e rfedb r2!
 *   @0x311642 stmdahs r0, {r0, r1, r3, r4, r12, pc}
 *   @0x311646 subhi pc, r7, r1, asr #32
 *   @0x31164a strhs r4, [r1], -r1, lsl #13
 *   @0x31164e .word 0x96079011
 *   @0x311652 .word 0x6064f8da
 *   @0x311656 teqmi r8, r0, asr #12
 *   @0x31165a shadd16mi r10, r0, r11
 *   @0x31165e .word 0xf7d5960d
 *   @0x311662 svcls #0x1bfd61
 *   @0x311666 svchs #0x4604
 *   @0x31166a eorshi pc, r5, r1, asr #32
 *   @0x31166e adceq pc, r0, #13238272
 *   @0x311672 stmibvs lr!, {r0, r3, r4, r5, r9, r10, lr} ^
 *   @0x311676 eorsmi pc, r8, #64, #12
 *   @0x31167a mrcge p6, #0x0, r9, c14, c3, #0x0
 *   @0x31167e svc #0x98f5a4
 *   @0x311682 eorhs r4, r4, #59768832
 *   @0x311686 .word 0x960e4630
 *   @0x31168a svc #0x92f5a4
 *   @0x31168e .word 0xf7d54628
 *   @0x311692 mrcls p9, #0x0, apsr_nzcv, c3, c6, #0x2
 *   @0x311696 strtmi r4, [r2], -r9, ror #18
 *   @0x31169a andlt pc, r0, r4, asr #17
 *   @0x31169e rsbvs r4, r5, r9, ror r4
 *   @0x3116a2 .word 0xf50160a6
 *   @0x3116a6 .word 0xf884710a
 *   @0x3116aa andls r9, r10, r0, lsr #32
 *   @0x3116ae strtmi r6, [r8], -r0, ror #1
 *   @0x3116b2 .word 0xfc0ff7d6
 *   @0x3116b6 stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x3116ba ldrhi pc, [r8, #-0x40]!
 *   @0x3116be svceq #0xf1b9
 *   @0x3116c2 cdpvc p0, #0x2, c13, c3, c14, #0x0
 *   @0x3116c6 cmple r5, r2, lsl #22
 *   @0x3116ca blhs 0x43115e <g_RomDisk+0x3993e>
 *   @0x3116ce qsaxmi sp, r8, r2
 *   @0x3116d2 .word 0xf7d5a91c
 *   @0x3116d6 blls 0xa4ff36 <b2_toiTime+0x2f6a92>
 *   @0x3116da orrslt r6, r3, r0, ror #3
 *   @0x3116de stclt p0, c15, [r6, #-0]!
 *   @0x3116e2 ldmdbge r12, {r3, r5, r9, r10, lr}
 *   @0x3116e6 .word 0xf9e8f7d5
 *   @0x3116ea blhs 0x338362
 *   @0x3116ee ldrhi pc, [lr, #-0x40]
 *   @0x3116f2 blhs 0x370f86 <_ZTS13C_UTF16String+0x8032>
 *   @0x3116f6 mcrvc p1, #0x5, sp, c3, c14, #0x1
 *   @0x3116fa ldmdble r11!, {r0, r1, r8, r9, r11, sp}
 *   @0x3116fe stmdahs r4, {r6, r7, r9, r12, sp, pc}
 *   @0x311702 mcrvc p8, #0x5, sp, c1, c8, #0x1
 *   @0x311706 cdpls p6, #0x0, c4, c10, c8, #0x1
 *   @0x31170a .word 0xf7d54431
 *   @0x31170e strmi pc, [r1], -r11, asr #17
 *   @0x311712 bllt 0x193578a <b2_toiTime+0x11dc2e6>
 *   @0x311716 svceq #0xf1b9
 *   @0x31171a eorhs sp, r4, #31
 *   @0x31171e addsvs pc, r11, r4, lsl #10
 *   @0x311722 svc #0x46f5a4
 *   @0x311726 .word 0xf7d54628
 *   @0x31172a stmibvs r1!, {r1, r3, r8, r11, r12, sp, lr, pc} ^
 *   @0x31172e ldrbtne pc, [r0], #2244
 *   @0x311732 strbteq pc, [r12], #2244
 *   @0x311736 .word 0xf7d54628
 *   @0x31173a ldrshls pc, [r12], -r10
 *   @0x31173e .word 0xf0402800
 *   @0x311742 andhs r8, r1, #-184549376
 *   @0x311746 rsbeq pc, r12, r4, lsl #2
 *   @0x31174a ldrmi r4, [r3], -r9, lsr #12
 *   @0x31174e .word 0xfc17f7fd
 *   @0x311752 stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x311756 .word 0xf000d04f
 *   @0x31175a .word 0xf104bce9
 *   @0x31175e strtmi r0, [r9], -r4, lsr #32
 *   @0x311762 strbmi r4, [r11], -r10, asr #12
 *   @0x311766 .word 0xfc0bf7fd
 *   @0x31176a .word 0xb128901c
 *   @0x31176e cdphs p14, #0x0, c9, c0, c7, #0x0
 *   @0x311772 ldrbhi pc, [r12], #0
 *   @0x311776 rsbs r2, pc, #134217728
 *   @0x31177a blhs 0x36c40e <_ZTS13C_UTF16String+0x34ba>
 *   @0x31177e blvs 0xffbc7ba6 <b2_toiTime+0xffffffffff46e702>
 *   @0x311782 andle r4, r5, #-1610612727
 *   @0x311786 cdphs p14, #0x0, c9, c0, c7, #0x0
 *   @0x31178a movwhs r11, #0x3f0c
 *   @0x31178e rsbs r2, r3, #134217728
 *   @0x311792 .word 0xf5042200
 *   @0x311796 sadd8mi r6, r3, r11
 *   @0x31179a .word 0xf7fd4629
 *   @0x31179e .word 0x4603fbf0
 *   @0x3117a2 stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x3117a6 strbhi pc, [r2], #64
 *   @0x3117aa qadd16mi r10, r9, lr
 *   @0x3117ae .word 0xf7fd2201
 *   @0x3117b2 strmi pc, [r3], -r6, ror #23
 *   @0x3117b6 stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x3117ba ldrthi pc, [r8], #64
 *   @0x3117be rsbeq pc, r12, r4, lsl #2
 *   @0x3117c2 andhs r4, r1, #42991616
 *   @0x3117c6 blx 0xffa0f7c4 <b2_toiTime+0xffffffffff2b6320>
 *   @0x3117ca stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x3117ce strthi pc, [lr], #64
 *   @0x3117d2 .word 0xf504a81e
 *   @0x3117d6 vrhadd.s8 d6, d20, d26
 *   @0x3117da .word 0xf5045254
 *   @0x3117de .word 0xf7fd63ab
 *   @0x3117e2 ldrshls pc, [r12], -sp
 *   @0x3117e6 .word 0xf0402800
 *   @0x3117ea blvs 0xbb2a76 <b2_toiTime+0x4595d2>
 *   @0x3117ee strbtlo pc, [r4], #2260
 *   @0x3117f2 vqsub.s8 d4, d16, d10
 *   @0x3117f6 blls 0xb720fe <b2_toiTime+0x418c5a>
 *   @0x3117fa .word 0xf8c49e07
 *   @0x3117fe blvs 0xbded36 <b2_toiTime+0x485892>
 *   @0x311802 cdpls p1, #0x0, c11, c9, c14, #0x7
 *   @0x311806 .word 0x9610b2b6
 *   @0x31180a cdphs p14, #0x0, c9, c0, c9, #0x0
 *   @0x31180e cdpls p13, #0x1, c13, c0, c4, #0x0
 *   @0x311812 movwle r4, #0x129e
 *   @0x311816 eor r2, pc, #402653184
 *   @0x31181a .word 0x61236b23
 *   @0x31181e strbpl lr, [pc], #-20
 *   @0x311822 qdsubvs r4, r4, r4
 *   @0x311826 ldrtmi r6, [r2], -r5, ror #16
 *   @0x31182a strtmi r4, [r0], -r6, asr #6
 *   @0x31182e ldrbtle r4, [r3], -r6, asr #6
 *   @0x311832 cmple pc, #7
 *   @0x311836 ldrtle r0, [r4], -r7
 *   @0x31183a cmnhs r10, r7
 *   @0x31183e blhs 0x35186a
 *   @0x311842 andshi pc, r9, #0, #4
 *   @0x311846 ldrls r9, [r0], -r7, lsl #28
 *   @0x31184a cdphs p14, #0x0, c9, c0, c9, #0x0
 *   @0x31184e strbthi pc, [lr], #-704
 *   @0x311852 .word 0xf1b99e0a
 *   @0x311856 svclt #0xc0f00
 *   @0x31185a orrpl pc, r0, #1325400064
 *   @0x31185e movtpl pc, #0x44f
 *   @0x311862 vshl.s8 d9, d2, d4
 *   @0x311866 movwls r5, #0x105c
 *   @0x31186a orrsvs pc, r11, r4, lsl #10
 *   @0x31186e strtmi r9, [r11], -r0, lsl #12
 *   @0x311872 andge pc, r12, sp, asr #17
 *   @0x311876 .word 0xf7ff9a10
 *   @0x31187a andsls pc, r12, lr, lsr sp
 *   @0x31187e .word 0xf0402800
 *   @0x311882 .word 0xf8d48455
 *   @0x311886 strtmi r1, [r8], -r12, asr #11
 *   @0x31188a .word 0xf7d54431
 *   @0x31188e strmi pc, [r2], -r11, lsl #16
 *   @0x311892 stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x311896 strbhi pc, [r10], #-64
 *   @0x31189a adcsmi pc, r4, r4, lsl #4
 *   @0x31189e strbmi r4, [r11], -r9, lsr #12
 *   @0x3118a2 blx 0x1e8f8a0 <b2_toiTime+0x17363fc>
 *   @0x3118a6 stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x3118aa strbhi pc, [r0], #-64
 *   @0x3118ae strbhs pc, [r0, #0x8d4]!
 *   @0x3118b2 .word 0x73fff64f
 *   @0x3118b6 swple r4, r10, [r3]
 *   @0x3118ba svceq #0xf1b9
 *   @0x3118be bicshi pc, r6, r0
 *   @0x3118c2 strtmi pc, [r4], -r4, lsl #12
 *   @0x3118c6 stmibvs lr!, {r0, r1, r2, r4, r9, r10, r12, pc} ^
 *   @0x3118ca .word 0x1610f8d4
 *   @0x3118ce strhs r9, [r3], -r8, lsl #12
 *   @0x3118d2 stmdbhs r0, {r0, r1, r2, r5, r9, r10, r12, pc}
 *   @0x3118d6 tsthi sp, r0
 *   @0x3118da strtmi r9, [r8], -r10, lsl #20
 *   @0x3118de .word 0xf7d44411
 *   @0x3118e2 eorls pc, r7, r1, ror #31
 *   @0x3118e6 .word 0x2600b110
 *   @0x3118ea tst r5, r11, lsl #12
 *   @0x3118ee .word 0x21024628
 *   @0x3118f2 .word 0xf81df7d5
 *   @0x3118f6 stmdahs r0, {r0, r1, r2, r5, r12, pc}
 *   @0x3118fa qsub8mi sp, r8, r5
 *   @0x3118fe bleq 0xfea4dd3a <b2_toiTime+0xfffffffffe2f4896>
 *   @0x311902 .word 0xf81df7d5
 *   @0x311906 andsls r4, r4, r9, asr r6
 *   @0x31190a .word 0xf7d54628
 *   @0x31190e blls 0xd0fcfe <b2_toiTime+0x5b685a>
 *   @0x311912 mvnle r2, r0, lsl #22
 *   @0x311916 andle r2, r2, r1, lsl #16
 *   @0x31191a movwls r9, #0xb627
 *   @0x31191e qsub8mi lr, r8, r12
 *   @0x311922 .word 0xf7d54659
 *   @0x311926 blls 0xd10266 <b2_toiTime+0x5b6dc2>
 *   @0x31192a blhs 0x32314a
 *   @0x31192e .word 0x4628d1db
 *   @0x311932 .word 0xf7d54659
 *   @0x311936 .word 0xf8c4f8e6
 *   @0x31193a strmi r0, [r3], -r4, lsr #24
 *   @0x31193e bhs 0x3381e2
 *   @0x311942 stm sp, {r0, r4, r6, r7, r8, r12, lr, pc}
 *   @0x311946 .word 0x21040804
 *   @0x31194a .word 0xf7d69808
 *   @0x31194e svcls #0x27fb9f
 *   @0x311952 svchs #0x900b
 *   @0x311956 rschi pc, r0, r0, asr #32
 *   @0x31195a stclo p8, c15, [r4], #-848
 *   @0x31195e addsmi r4, pc, #40, #12
 *   @0x311962 ldrbmi sp, [r9], -r11, lsl #4
 *   @0x311966 blx 0xe8f8c2 <b2_toiTime+0x73641e>
 *   @0x31196a .word 0xf841990b
 *   @0x31196e blls 0xcd1a12 <b2_toiTime+0x57856e>
 *   @0x311972 .word 0xf0402b00
 *   @0x311976 .word 0x370180d1
 *   @0x31197a ldmdbls r4, {r1, r2, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x31197e .word 0xf7d44431
 *   @0x311982 mlals r7, r1, pc, pc
 *   @0x311986 .word 0xf0402800
 *   @0x31198a strtmi r8, [r8], -r7, asr #1
 *   @0x31198e .word 0xf7d54659
 *   @0x311992 .word 0xf8a4f8b8
 *   @0x311996 blls 0xcd4a4e <b2_toiTime+0x57b5aa>
 *   @0x31199a .word 0xf0402b00
 *   @0x31199e .word 0x462880bd
 *   @0x3119a2 .word 0xf7d54659
 *   @0x3119a6 .word 0xf8c4f8ae
 *   @0x3119aa .word 0x46030c30
 *   @0x3119ae bhs 0x338252
 *   @0x3119b2 adcshi pc, r2, r0, asr #32
 *   @0x3119b6 stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc}
 *   @0x3119ba stmdals r8, {r2, r8, sp}
 *   @0x3119be blx 0x1ccf920 <b2_toiTime+0x157647c>
 *   @0x3119c2 ldceq p8, c15, [r4], #-784
 *   @0x3119c6 cdphs p14, #0x0, c9, c0, c7, #0x1
 *   @0x3119ca adchi pc, r6, r0, asr #32
 *   @0x3119ce ldclo p8, c15, [r0], #-848
 *   @0x3119d2 suble r4, sp, #-536870903
 *   @0x3119d6 ldcvc p8, c15, [r4], #-848
 *   @0x3119da rfeia r4!
 *   @0x3119de bl 0x4e0a96 <SrcVerts+0x3dada>
 *   @0x3119e2 stm sp, {r1, r2, r7, r9}
 *   @0x3119e6 andsls r0, r8, #131072
 *   @0x3119ea stmdals r8, {r2, r3, r8, sp}
 *   @0x3119ee .word 0xf7d62200
 *   @0x3119f2 .word 0xf847fb4d
 *   @0x3119f6 svcls #0x270026
 *   @0x3119fa .word 0xf0402f00
 *   @0x3119fe rfeia r4!
 *   @0x311a02 addsmi r3, pc, #44, #24
 *   @0x311a06 blls 0x9462d6 <b2_toiTime+0x1ece32>
 *   @0x311a0a blx 0x39a244 <ft_adobe_glyph_list+0x9920>
 *   @0x311a0e strtmi pc, [r8], -r7, lsl #16
 *   @0x311a12 uadd16mi r6, r9, r11
 *   @0x311a16 strbmi r9, [r3], #-789
 *   @0x311a1a .word 0xf7d5930f
 *   @0x311a1e blls 0xd0fbee <b2_toiTime+0x5b674a>
 *   @0x311a22 andsls r11, r9, r0, lsl #5
 *   @0x311a26 cmnle r7, r0, lsl #22
 *   @0x311a2a ldrbmi r4, [r9], -r8, lsr #12
 *   @0x311a2e .word 0xf869f7d5
 *   @0x311a32 addlt r9, r2, #39936
 *   @0x311a36 .word 0xd16f2b00
 *   @0x311a3a ldrbmi r4, [r9], -r8, lsr #12
 *   @0x311a3e .word 0xf7d59205
 *   @0x311a42 blls 0xd0fbca <b2_toiTime+0x5b6726>
 *   @0x311a46 addlt r9, r0, #20480
 *   @0x311a4a .word 0xd1652b00
 *   @0x311a4e andslt r9, r2, #409600
 *   @0x311a52 addseq r3, r2, r1, lsl #14
 *   @0x311a56 ldmdbls r5, {r0, r1, r3, r9, r12, sp, pc}
 *   @0x311a5a .word 0xf841009b
 *   @0x311a5e blls 0x6dda86 <g_SWFvertbuff+0xa9be>
 *   @0x311a62 andlt r6, r3, #90
 *   @0x311a66 addseq r9, r11, pc, lsl #20
 *   @0x311a6a bfi r6, r3, #1, #8
 *   @0x311a6e str r3, [sp, r1, lsl #12]!
 *   @0x311a72 stmdals r8, {r9, sp}
 *   @0x311a76 stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc}
 *   @0x311a7a .word 0xf8d42108
 *   @0x311a7e .word 0xf7d63c24
 *   @0x311a82 .word 0xf8c4fb05
 *   @0x311a86 cdpls p12, #0x2, c0, c7, c8, #0x1
 *   @0x311a8a .word 0xd1452e00
 *   @0x311a8e stclo p8, c15, [r4], #-848
 *   @0x311a92 eorsle r4, pc, #-536870903
 *   @0x311a96 stclo p8, c15, [r8], #-848
 *   @0x311a9a bls 0x5e3342 <g_SWFaavertbuff+0x1027a>
 *   @0x311a9e stmeq r6, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0x311aa2 ldrmi r9, [pc], -pc, lsl #6
 *   @0x311aa6 eorne pc, r6, r2, asr r8
 *   @0x311aaa blls 0x822bce <b2_toiTime+0xc972a>
 *   @0x311aae .word 0xf7d44419
 *   @0x311ab2 .word 0x9027fef9
 *   @0x311ab6 .word 0xd12f2800
 *   @0x311aba .word 0x21044628
 *   @0x311abe .word 0xff37f7d4
 *   @0x311ac2 bllt 0x1535b66 <b2_toiTime+0xddc6c2>
 *   @0x311ac6 ldrbmi r4, [r9], -r8, lsr #12
 *   @0x311aca .word 0xf81bf7d5
 *   @0x311ace .word 0xf8429a0f
 *   @0x311ad2 strmi r0, [r3], -r8
 *   @0x311ad6 ldmiblt r10!, {r0, r1, r2, r5, r9, r11, r12, pc} ^
 *   @0x311ada stmdaeq r4, {r0, r2, r3, r7, r11, sp, lr, pc}
 *   @0x311ade stmdals r8, {r2, r8, sp}
 *   @0x311ae2 blx 0xff84fa42 <b2_toiTime+0xffffffffff0f659e>
 *   @0x311ae6 blls 0xce9cce <b2_toiTime+0x59082a>
 *   @0x311aea .word 0x4698b9b3
 *   @0x311aee ldrmi r6, [r8, #0x83b]
 *   @0x311af2 ldmdavs r11!, {r0, r2, r3, r9, r12, lr, pc} ^
 *   @0x311af6 ldrbmi r4, [r9], -r8, lsr #12
 *   @0x311afa .word 0xf7d59305
 *   @0x311afe blls 0x48fb0e <SurfaceStack+0x362>
 *   @0x311b02 eoreq pc, r8, r3, asr #16
 *   @0x311b06 ldmdblt r11!, {r0, r1, r2, r5, r8, r9, r11, r12, pc}
 *   @0x311b0a stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x311b0e strlo lr, [r1], -lr, ror #15
 *   @0x311b12 strhls lr, [r11, -r12]
 *   @0x311b16 .word 0x93272300
 *   @0x311b1a stmdbls r11, {r3, r11, r12, pc}
 *   @0x311b1e .word 0xfc0af7d5
 *   @0x311b22 tstlt r11, r7, lsr #22
 *   @0x311b26 stmdbls r8, {r0, r1, r2, r4, r11, r12, pc}
 *   @0x311b2a blx 0x30fb22 <af_shaper_get_elem+0x5390>
 *   @0x311b2e tstls r12, #39936
 *   @0x311b32 .word 0xf0402b00
 *   @0x311b36 .word 0xf8d482fb
 *   @0x311b3a strtmi r1, [r8], -r0, lsl #12
 *   @0x311b3e ldrtmi r9, [r1], #-3594
 *   @0x311b42 mrc2 p7, #0x5, apsr_nzcv, c0, c4, #0x6
 *   @0x311b46 andsls r4, r12, r2, lsl #12
 *   @0x311b4a .word 0xf0402800
 *   @0x311b4e cdpge p2, #0x2, c8, c7, c15, #0x7
 *   @0x311b52 strbmi r4, [r11], -r9, lsr #12
 *   @0x311b56 .word 0xf7fd4630
 *   @0x311b5a .word 0x4602fa12
 *   @0x311b5e stmdahs r0, {r2, r3, r4, r12, pc}
 *   @0x311b62 rschi pc, r4, #64
 *   @0x311b66 .word 0xf5b39b2a
 *   @0x311b6a ldmdale r9!, {r7, r8, r9, r10, r11, r12, sp, lr} ^
 *   @0x311b6e strblo pc, [r8, r4, asr #17]!
 *   @0x311b72 andls r10, r0, r12, lsl r9
 *   @0x311b76 vst4.8 {d25, d27, d29, d31}, [pc], r1
 *   @0x311b7a ldmdals r3, {r0, r1, r5, r8, r12, sp, lr}
 *   @0x311b7e blx 0xfe4cfade <b2_toiTime+0xfffffffffdd7663a>
 *   @0x311b82 blhs 0x3387fa
 *   @0x311b86 bls 0xdc613e <b2_toiTime+0x66cc9a>
 *   @0x311b8a .word 0x7123f44f
 *   @0x311b8e mulle r7, r3, r2
 *   @0x311b92 vmlaeq.f64 d15, d3, d1
 *   @0x311b96 streq lr, [r3, r4, lsl #22]
 *   @0x311b9a .word 0xf8c73301
 *   @0x311b9e ldrb lr, [r5, r12, ror #15]!
 *   @0x311ba2 blls 0xd9b7aa <b2_toiTime+0x642306>
 *   @0x311ba6 andsle r4, r7, #-268435447
 *   @0x311baa bl 0x437fda <g_RomDisk+0x407ba>
 *   @0x311bae ldrtmi r0, [r10], -r7, lsl #7
 *   @0x311bb2 ubfxeq pc, r3, #0x11, #0xd
 *   @0x311bb6 svceq #0xf1b9
 *   @0x311bba .word 0xf44fbf0c
 *   @0x311bbe vst2.32 {d21, d22, d23, d24}, [pc], r0
 *   @0x311bc2 stm sp, {r7, r8, r9, lr}
 *   @0x311bc6 shadd16mi r0, r1, r10
 *   @0x311bca .word 0xf7ff462b
 *   @0x311bce mulsls r12, r4, r11
 *   @0x311bd2 mrsle r2, spsr
 *   @0x311bd6 strb r3, [r4, r1, lsl #14]!
 *   @0x311bda svceq #0xf1b9
 *   @0x311bde blhs 0x385bea <_ZTS13C_UTF16String+0x1cc96>
 *   @0x311be2 .word 0xf8d4d93e
 *   @0x311be6 strtmi r1, [r8], -r4, lsl #12
 *   @0x311bea .word 0xf8d49a0a
 *   @0x311bee ldrmi r7, [r1], #-1216
 *   @0x311bf2 mrc2 p7, #0x2, apsr_nzcv, c8, c4, #0x6
 *   @0x311bf6 bllt 0xfe535c72 <b2_toiTime+0xfffffffffdddc7ce>
 *   @0x311bfa bleq 0x204e036 <b2_toiTime+0x18f4b92>
 *   @0x311bfe ldrbmi r4, [r9], -r8, lsr #12
 *   @0x311c02 .word 0xff5af7d4
 *   @0x311c06 blx 0x1af8882 <b2_toiTime+0x139f3de>
 *   @0x311c0a bllt 0x120fe12 <b2_toiTime+0xab696e>
 *   @0x311c0e blhi 0xffe4fe26 <b2_toiTime+0xffffffffff6f6982>
 *   @0x311c12 .word 0x3c00f8c4
 *   @0x311c16 svceq #0xf1b8
 *   @0x311c1a .word 0xf1b8d003
 *   @0x311c1e andle r0, r3, r3, lsl #30
 *   @0x311c22 .word 0xf8c4e01a
 *   @0x311c26 strd r7, r8, [lr], -r8
 *   @0x311c2a ldrbmi r4, [r9], -r8, lsr #12
 *   @0x311c2e .word 0xff69f7d4
 *   @0x311c32 ldmiblt r11, {r0, r2, r3, r4, r8, r9, r11, r12, pc}
 *   @0x311c36 .word 0xf8cdb910
 *   @0x311c3a and r8, pc, r4, ror r0
 *   @0x311c3e .word 0xf000fb08
 *   @0x311c42 .word 0xf8c43002
 *   @0x311c46 qsub8mi r0, r8, r8
 *   @0x311c4a blne 0x14ffa2 <_Z24F_PhysicsCreateWeldJointR6RValueP9CInstanceS2_iPS_+0x3a>
 *   @0x311c4e rscslo pc, r4, #4, #12
 *   @0x311c52 .word 0xf926f7d6
 *   @0x311c56 and r9, r1, sp, lsl r0
 *   @0x311c5a tstls sp, #201326592
 *   @0x311c5e tstls r12, #29696
 *   @0x311c62 .word 0xf7fd4630
 *   @0x311c66 blls 0xa4ff22 <b2_toiTime+0x2f6a7e>
 *   @0x311c6a subs r11, pc, #-1073741820
 *   @0x311c6e strbls pc, [r8, r4, asr #17]!
 *   @0x311c72 strblo pc, [r12, #0x8d4]
 *   @0x311c76 movwhs r11, #0x3913
 *   @0x311c7a subs r9, r7, #28, #6
 *   @0x311c7e strblo pc, [r0], #2260
 *   @0x311c82 .word 0xf1042200
 *   @0x311c86 .word 0xf504006c
 *   @0x311c8a smultbvs r3, r9, r1
 *   @0x311c8e .word 0xf7fc4613
 *   @0x311c92 andsls pc, r12, r5, lsr #31
 *   @0x311c96 .word 0xf0402800
 *   @0x311c9a .word 0xf1b98249
 *   @0x311c9e andle r0, r6, r0, lsl #30
 *   @0x311ca2 ldmdbls r0, {r5, r9, r10, lr}
 *   @0x311ca6 ldc2 p7, c15, [r11, #1016]!
 *   @0x311caa strbeq pc, [r4, #-0x8c4]
 *   @0x311cae stmdbvs r6!, {r1, r2, r3, r4, r5, r9, sp, lr, pc} ^
 *   @0x311cb2 rscsle r2, r5, r0, lsl #28
 *   @0x311cb6 strblo pc, [r0, #0x8d4]!
 *   @0x311cba rscsvc pc, pc, #82837504
 *   @0x311cbe vmla.i8 d9, d4, d7
 *   @0x311cc2 stmibvs pc!, {r2, r3, r4, r7, r8, r9, r11, lr} ^
 *   @0x311cc6 svclt #0x84293
 *   @0x311cca sbclt r2, r11, #0, #2
 *   @0x311cce strbne pc, [r4, #0x8d4]
 *   @0x311cd2 stmdbhs r2, {r0, r1, r3, r8, r9, r12, pc}
 *   @0x311cd6 addsls pc, r12, sp, asr #17
 *   @0x311cda addhi pc, r9, r0, asr #4
 *   @0x311cde strtmi r9, [r8], -r10, lsl #22
 *   @0x311ce2 .word 0xf8c44419
 *   @0x311ce6 .word 0xf7d414a0
 *   @0x311cea .word 0x9027fddd
 *   @0x311cee .word 0xf0402800
 *   @0x311cf2 .word 0xf10d80d3
 *   @0x311cf6 qadd8mi r0, r8, r12
 *   @0x311cfa .word 0xf7d44641
 *   @0x311cfe sbclt pc, r0, #3536
 *   @0x311d02 ldreq pc, [r12], #2244
 *   @0x311d06 blhs 0x3389aa
 *   @0x311d0a sbchi pc, r6, r0, asr #32
 *   @0x311d0e .word 0xf8cd4633
 *   @0x311d12 .word 0xf8cd9000
 *   @0x311d16 ldrtmi r8, [r8], -r4
 *   @0x311d1a strbmi r2, [r10], -r2, lsl #2
 *   @0x311d1e rfeib r6!
 *   @0x311d22 strteq pc, [r4], #2244
 *   @0x311d26 blhs 0x3389ca
 *   @0x311d2a adcshi pc, r6, r0, asr #32
 *   @0x311d2e andls pc, r0, r0, lsr #17
 *   @0x311d32 ldrlo pc, [r12], #2260
 *   @0x311d36 blhs 0x3be1ca <error_g0017+0x16e6e>
 *   @0x311d3a .word 0xf04fd861
 *   @0x311d3e sub r0, r7, r1, lsl #18
 *   @0x311d42 .word 0x4100f106
 *   @0x311d46 stmdblo r1, {r3, r5, r9, r10, lr}
 *   @0x311d4a .word 0xf7d60049
 *   @0x311d4e eorls pc, r7, r9, ror #16
 *   @0x311d52 .word 0xf0402800
 *   @0x311d56 .word 0xf04f80a1
 *   @0x311d5a ldrmi r0, [r0, #0x801]!
 *   @0x311d5e strtmi sp, [r8], -r9
 *   @0x311d62 strtls pc, [r4], #2260
 *   @0x311d66 mcr2 p7, #0x2, pc, c4, c4, #0x6
 *   @0x311d6a andseq pc, r8, r9, lsr #16
 *   @0x311d6e stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x311d72 qsub8mi lr, r8, r3
 *   @0x311d76 .word 0xf89ff7d6
 *   @0x311d7a strtmi lr, [r8], -r6, lsl #1
 *   @0x311d7e .word 0xf7d44641
 *   @0x311d82 blls 0xd1188a <b2_toiTime+0x5b83e6>
 *   @0x311d86 blhs 0x335dae
 *   @0x311d8a addhi pc, r6, r0, asr #32
 *   @0x311d8e ldrlo pc, [r12], #2260
 *   @0x311d92 strbmi r4, [r1], -r8, lsr #12
 *   @0x311d96 tstle lr, r2, lsl #22
 *   @0x311d9a mrc2 p7, #0x5, apsr_nzcv, c3, c4, #0x6
 *   @0x311d9e blhs 0x338a42
 *   @0x311da2 .word 0xf5c0d17a
 *   @0x311da6 bls 0x522baa <SrcVerts+0x7fbee>
 *   @0x311daa bl 0xff55edae <b2_toiTime+0xfffffffffee0590a>
 *   @0x311dae addsmi r0, r3, #6, #28
 *   @0x311db2 movweq pc, #0x4f
 *   @0x311db6 .word 0xf5c2bf3c
 *   @0x311dba rscslo r4, pc, pc, ror r0
 *   @0x311dbe .word 0xc020f8dd
 *   @0x311dc2 bl 0x3e3396 <error_g0017+0x3c03a>
 *   @0x311dc6 ldrmi r0, [r12], #265
 *   @0x311dca stc2 p10, c15, [r12], {31}
 *   @0x311dce strmi sp, [r9], r7, lsl #2
 *   @0x311dd2 bicsle r4, r2, #742391808
 *   @0x311dd6 .word 0xf7d4e058
 *   @0x311dda sbclt pc, r0, #1776
 *   @0x311dde addmi lr, r3, #58195968
 *   @0x311de2 .word 0xf8d4d8f5
 *   @0x311de6 movwlo r2, #0x14a4
 *   @0x311dea andsgt pc, r1, r2, lsr #16
 *   @0x311dee stmdbhs r1, {r1, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x311df2 strtne pc, [r0], #2244
 *   @0x311df6 stmdbhs r2, {r0, r1, r3, r4, r12, lr, pc}
 *   @0x311dfa cdphs p0, #0xe, c13, c5, c15, #0x1
 *   @0x311dfe movwhs sp, #0x3902
 *   @0x311e02 sub r9, r9, r7, lsr #6
 *   @0x311e06 .word 0xf8cdab27
 *   @0x311e0a movwls r9, #0x1000
 *   @0x311e0e shasxmi r4, r3, r8
 *   @0x311e12 strbmi r2, [r10], -r2, lsl #2
 *   @0x311e16 rfedb r10!
 *   @0x311e1a strteq pc, [r4], #2244
 *   @0x311e1e blhs 0x338ac2
 *   @0x311e22 .word 0xf8dfd13a
 *   @0x311e26 ldrbtmi r1, [r9], #-2276
 *   @0x311e2a mrsvc pc, apsr
 *   @0x311e2e cdphs p0, #0xa, c14, c6, c9, #0x1
 *   @0x311e32 blge 0xd081ce <b2_toiTime+0x5aed2a>
 *   @0x311e36 andls pc, r0, sp, asr #17
 *   @0x311e3a ldrtmi r9, [r8], -r1, lsl #6
 *   @0x311e3e .word 0x21024633
 *   @0x311e42 .word 0xf7d6464a
 *   @0x311e46 .word 0xf8c4f923
 *   @0x311e4a blls 0xcd30e2 <b2_toiTime+0x579c3e>
 *   @0x311e4e .word 0xf8dfbb23
 *   @0x311e52 ldrbtmi r1, [r9], #-2248
 *   @0x311e56 .word 0x4106f201
 *   @0x311e5a mrchs p0, #0x2, lr, c7, c3, #0x0
 *   @0x311e5e blge 0xd081a2 <b2_toiTime+0x5aecfe>
 *   @0x311e62 andls pc, r0, sp, asr #17
 *   @0x311e66 ldrtmi r9, [r8], -r1, lsl #6
 *   @0x311e6a .word 0x464a4633
 *   @0x311e6e .word 0xf90ef7d6
 *   @0x311e72 strteq pc, [r4], #2244
 *   @0x311e76 ldmdblt r11!, {r0, r1, r2, r5, r8, r9, r11, r12, pc} ^
 *   @0x311e7a stmne r4!, {r0, r1, r2, r3, r4, r6, r7, r11, r12, sp, lr, pc}
 *   @0x311e7e .word 0xf2014479
 *   @0x311e82 rsbseq r5, r2, r2, asr r1
 *   @0x311e86 bl 0xfe9cf51e <b2_toiTime+0xfffffffffe27607a>
 *   @0x311e8a .word 0xb12b9b0b
 *   @0x311e8e shsaxmi r4, r1, r8
 *   @0x311e92 .word 0xf5a7463a
 *   @0x311e96 eorls pc, r7, r6, ror #20
 *   @0x311e9a .word 0xb1a39b27
 *   @0x311e9e .word 0xf8d44638
 *   @0x311ea2 strhs r1, [r0], -r4, lsr #9
 *   @0x311ea6 blx 0x14cfe02 <b2_toiTime+0xd7695e>
 *   @0x311eaa strtvs pc, [r4], #2244
 *   @0x311eae .word 0xf8d44638
 *   @0x311eb2 .word 0xf7d514a8
 *   @0x311eb6 .word 0xf8c4fa3f
 *   @0x311eba .word 0xf8c464a8
 *   @0x311ebe .word 0xf8c4649c
 *   @0x311ec2 .word 0xf8c464a0
 *   @0x311ec6 bls 0xceb15e <b2_toiTime+0x591cba>
 *   @0x311eca bhs 0x336742
 *   @0x311ece .word 0x812ef040
 *   @0x311ed2 strblo pc, [r0, #0x8d4]!
 *   @0x311ed6 ldrbtvc pc, [pc], pc, asr #12
 *   @0x311eda .word 0xf47f42b3
 *   @0x311ede .word 0xf8d4aee1
 *   @0x311ee2 .word 0xf8d434a4
 *   @0x311ee6 .word 0xf8d49014
 *   @0x311eea blhs 0x317612 <ft_lzwstate_io+0x65e>
 *   @0x311eee adchi pc, sp, r0
 *   @0x311ef2 .word 0xf1044610
 *   @0x311ef6 movwls r0, #0x8390
 *   @0x311efa ldrmi r9, [r3], #-2824
 *   @0x311efe .word 0xf5b23202
 *   @0x311f02 orrshi r7, r8, r0, lsl #30
 *   @0x311f06 andeq pc, r12, #10682368
 *   @0x311f0a stmdbhs r1, {r1, r2, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x311f0e sbcshi pc, r3, r0, asr #4
 *   @0x311f12 strtmi r9, [r8], -r10, lsl #28
 *   @0x311f16 .word 0xf8c44431
 *   @0x311f1a .word 0xf7d41094
 *   @0x311f1e eorls pc, r7, r3, asr #25
 *   @0x311f22 .word 0xf0402800
 *   @0x311f26 mcrge p0, #0x1, r8, c7, c14, #0x7
 *   @0x311f2a ldrtmi r4, [r1], -r8, lsr #12
 *   @0x311f2e stc2l p7, c15, [r4, #848]
 *   @0x311f32 .word 0xf8c4b2c0
 *   @0x311f36 blls 0xcd217e <b2_toiTime+0x578cda>
 *   @0x311f3a .word 0xf0402b00
 *   @0x311f3e qsub8mi r8, r8, r2
 *   @0x311f42 .word 0xf7d44631
 *   @0x311f46 bls 0xd11632 <b2_toiTime+0x5b818e>
 *   @0x311f4a bhs 0x33ea6e
 *   @0x311f4e rschi pc, r9, r0, asr #32
 *   @0x311f52 ldrsblo pc, [r0], r4
 *   @0x311f56 ldmdaeq pc!, {r0, r1, r4, r12, sp, lr, pc} ^
 *   @0x311f5a .word 0xf1b8d006
 *   @0x311f5e cmnle r4, r1, lsl #30
 *   @0x311f62 addshs pc, r8, r4, asr #17
 *   @0x311f66 .word 0xe0524694
 *   @0x311f6a qsub16mi r1, r8, r11
 *   @0x311f6e addslo pc, r8, r4, asr #17
 *   @0x311f72 .word 0xf7d54639
 *   @0x311f76 eorls pc, r7, r5, asr pc
 *   @0x311f7a .word 0xf0402800
 *   @0x311f7e bvs 0xd322ce <b2_toiTime+0x5d8e2a>
 *   @0x311f82 adcsmi r2, r11, #67108864
 *   @0x311f86 stmne r2, {r4, r11, r12, lr, pc} ^
 *   @0x311f8a .word 0xf812454b
 *   @0x311f8e andle r2, r9, #256
 *   @0x311f92 subeq lr, r2, #4, #22
 *   @0x311f96 addslo pc, r12, #10616832
 *   @0x311f9a strtne pc, [r4], #2260
 *   @0x311f9e andsne pc, r3, r1, lsr r8
 *   @0x311fa2 addsne pc, r12, r2, lsr #17
 *   @0x311fa6 strb r3, [r12, r1, lsl #6]!
 *   @0x311faa .word 0xf7d54628
 *   @0x311fae sub pc, pc, r4, lsl #31
 *   @0x311fb2 ldrtmi r4, [r1], -r8, lsr #12
 *   @0x311fb6 andsgt pc, r4, sp, asr #17
 *   @0x311fba ldc2l p7, c15, [lr, #-848]!
 *   @0x311fbe blx 0x1af8c62 <b2_toiTime+0x139f7be>
 *   @0x311fc2 blhs 0x350dca
 *   @0x311fc6 adchi pc, sp, r0, asr #32
 *   @0x311fca ldrtmi r4, [r1], -r8, lsr #12
 *   @0x311fce ldc2l p7, c15, [r4, #-848]!
 *   @0x311fd2 .word 0xf8dd9a27
 *   @0x311fd6 sbclt r12, r0, #20
 *   @0x311fda .word 0xf0402a00
 *   @0x311fde .word 0xf06f80a2
 *   @0x311fe2 .word 0xf8d44100
 *   @0x311fe6 blx 0x35e250 <_ZTS12CDS_Priority+0x2a8>
 *   @0x311fea andlo r11, r1, r8, lsl #28
 *   @0x311fee blls 0x522a56 <SrcVerts+0x7fa9a>
 *   @0x311ff2 subeq lr, r8, #323584
 *   @0x311ff6 .word 0xf8c4bf88
 *   @0x311ffa bl 0x3d2262 <error_g0017+0x2af06>
 *   @0x311ffe strbmi r0, [r3], -lr, asr #28
 *   @0x312002 bl 0xff3e320a <b2_toiTime+0xfffffffffec89d66>
 *   @0x312006 strbmi r0, [r3, #-0xb0b]
 *   @0x31200a .word 0xf10cd304
 *   @0x31200e ldrmi r0, [r12, #0xc01]!
 *   @0x312012 ands sp, r0, lr, asr #7
 *   @0x312016 andle r4, r11, #314572800
 *   @0x31201a .word 0x0103eb0b
 *   @0x31201e stmdale r7, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r11, sp}
 *   @0x312022 andeq lr, r2, lr, lsl #22
 *   @0x312026 andlo pc, r12, #160, #16
 *   @0x31202a strtne pc, [r4], #2260
 *   @0x31202e orrhi r5, r1, r9, lsl #21
 *   @0x312032 andlo r3, r2, #67108864
 *   @0x312036 .word 0xf8d4e7e7
 *   @0x31203a .word 0xf5b33098
 *   @0x31203e stmdble r7, {r7, r8, r9, r10, r11, r12, sp, lr}
 *   @0x312042 orrvc pc, r0, #1325400064
 *   @0x312046 addslo pc, r8, r4, asr #17
 *   @0x31204a movwhs lr, #0x3002
 *   @0x31204e rsb r9, r8, r7, lsr #6
 *   @0x312052 ldrsblo pc, [r0], r4
 *   @0x312056 strble r0, [r4, #-0x619]!
 *   @0x31205a ldrtmi r4, [r1], -r8, lsr #12
 *   @0x31205e stc2 p7, c15, [r12, #-848]!
 *   @0x312062 sbclt r9, r7, #39936
 *   @0x312066 cmple r12, r0, lsl #22
 *   @0x31206a ldrmi r4, [r8, #0x698]!
 *   @0x31206e qsaxmi sp, r8, r9
 *   @0x312072 .word 0xf7d44631
 *   @0x312076 blls 0xd11502 <b2_toiTime+0x5b805e>
 *   @0x31207a blx 0xfe350a00 <b2_toiTime+0xfffffffffdbf755c>
 *   @0x31207e cmple r0, r0, lsl #22
 *   @0x312082 ldrtmi r4, [r1], -r8, lsr #12
 *   @0x312086 ldc2 p7, c15, [sp, #-848]!
 *   @0x31208a blhs 0x338d2e
 *   @0x31208e bl 0x4465ba <g_RomDisk+0x4ed9a>
 *   @0x312092 .word 0xf8a2024b
 *   @0x312096 strbmi r0, [r11, #-0x9c]
 *   @0x31209a .word 0xf8d4d00a
 *   @0x31209e rfeda r1!
 *   @0x3120a2 addmi r1, r1, #19
 *   @0x3120a6 .word 0xf8a2d102
 *   @0x3120aa mul r1, r12, r2
 *   @0x3120ae ldrb r3, [r2, r1, lsl #6]!
 *   @0x3120b2 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x3120b6 .word 0xf104e7d9
 *   @0x3120ba mulle r4, r12, r0
 *   @0x3120be .word 0x1664f8df
 *   @0x3120c2 .word 0x31284479
 *   @0x3120c6 .word 0xf8dfe004
 *   @0x3120ca ldrbtmi r1, [r9], #-1628
 *   @0x3120ce bicvs pc, r0, r1, lsl #10
 *   @0x3120d2 b 0x204f76a <b2_toiTime+0x18f62c6>
 *   @0x3120d6 ldrbmi r2, [r8], -r0, lsl #6
 *   @0x3120da addslo pc, r8, r4, asr #17
 *   @0x3120de stmibvs r10!, {r0, r3, r6, r9, r10, lr} ^
 *   @0x3120e2 rfedb pc!
 *   @0x3120e6 stmiblt r0!, {r0, r1, r2, r5, r12, pc} ^
 *   @0x3120ea orrseq pc, r12, #4, #2
 *   @0x3120ee vhsub.s8 d18, d0, d1
 *   @0x3120f2 rfeda r3!
 *   @0x3120f6 .word 0xb1691b02
 *   @0x3120fa strtpl pc, [r12], #2260
 *   @0x3120fe stmdale r9, {r0, r3, r5, r7, r9, lr}
 *   @0x312102 strtpl pc, [r8], #2260
 *   @0x312106 andsne pc, r1, r5, lsr r8
 *   @0x31210a .word 0xf8a3b121
 *   @0x31210e .word 0xf8c411fe
 *   @0x312112 mul r3, r8, r0
 *   @0x312116 mvnseq pc, r3, lsr #17
 *   @0x31211a .word 0x0c02f823
 *   @0x31211e adcsmi r3, r2, #268435456
 *   @0x312122 blls 0xd068c6 <b2_toiTime+0x5ad422>
 *   @0x312126 blhs 0x336d9e
 *   @0x31212a ldcge p4, c15, [r10, #252]!
 *   @0x31212e .word 0xf7fca81e
 *   @0x312132 ldmdals r12, {r0, r1, r2, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x312136 stmdahs r0, {r0, r1, r3, r4, r12, pc}
 *   @0x31213a sbchi pc, sp, #64
 *   @0x31213e cdphs p14, #0x0, c9, c0, c9, #0x0
 *   @0x312142 stmdbvs r3!, {r0, r1, r9, r11, r12, lr, pc}
 *   @0x312146 andlo pc, r0, r10, asr #17
 *   @0x31214a mrcls p2, #0x0, lr, c6, c8, #0x6
 *   @0x31214e .word 0x6c08f8c4
 *   @0x312152 .word 0xf8c49e12
 *   @0x312156 cdpls p12, #0x0, c6, c9, c12, #0x0
 *   @0x31215a .word 0xf8cab2b3
 *   @0x31215e stmdbvs r3!, {r2, r12, sp} ^
 *   @0x312162 ldrbtvc pc, [pc], pc, asr #12
 *   @0x312166 andslo pc, r0, r10, asr #17
 *   @0x31216a strblo pc, [r0, #0x8d4]!
 *   @0x31216e strhle r4, [r4, -r3]
 *   @0x312172 ldmdblt r1, {r1, r4, r8, r11, r12, pc}
 *   @0x312176 tstls r11, #738197504
 *   @0x31217a .word 0xf8dae2ad
 *   @0x31217e .word 0xf8da3008
 *   @0x312182 ldrbeq r7, [r10, #0x224]
 *   @0x312186 svchs #0xd53d
 *   @0x31218a bls 0x58627e <g_SWFlineaavertbuff+0x331b6>
 *   @0x31218e stmdami r2!, {r0, r1, r2, r3, r4, r6, r9, r11, sp, lr, pc}
 *   @0x312192 .word 0x2100d037
 *   @0x312196 uasxmi r6, r0, r11
 *   @0x31219a .word 0x46014798
 *   @0x31219e stmdahs r0, {r0, r1, r3, r4, r12, pc}
 *   @0x3121a2 addshi pc, r9, #64
 *   @0x3121a6 movwls r10, #0xb1e
 *   @0x3121aa .word 0x460b69fd
 *   @0x3121ae .word 0x460a4650
 *   @0x3121b2 blls 0xaa405a <b2_toiTime+0x34abb6>
 *   @0x3121b6 .word 0xb325691d
 *   @0x3121ba stmdbls r12, {r2, r3, r8, r9, sp}
 *   @0x3121be .word 0xf808fb03
 *   @0x3121c2 svcvs #0x4b4650
 *   @0x3121c6 stmdaeq r12, {r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x3121ca andeq lr, r8, #5120
 *   @0x3121ce bge 0xcf441a <b2_toiTime+0x59af76>
 *   @0x3121d2 mulsls r11, r8, r7
 *   @0x3121d6 .word 0xf0402800
 *   @0x3121da .word 0xf8da827e
 *   @0x3121de tstlt r1, r8, lsl r0
 *   @0x3121e2 .word 0xf7d5980d
 *   @0x3121e6 blls 0xd1048a <b2_toiTime+0x5b6fe6>
 *   @0x3121ea bls 0xaa3b32 <b2_toiTime+0x34a68e>
 *   @0x3121ee andslo pc, r8, r10, asr #17
 *   @0x3121f2 ldmdavs r1, {r0, r1, r3, r4, r5, r6, r8, r11, sp, lr}
 *   @0x3121f6 andhs pc, r8, r5, asr r8
 *   @0x3121fa mulsls r11, r8, r7
 *   @0x3121fe .word 0xf0402800
 *   @0x312202 .word 0xf894826a
 *   @0x312206 stmdblt r3, {r2, r3, r4, r7, r8, r10, r12, sp} ^
 *   @0x31220a ldmdblt r2, {r0, r1, r2, r9, r11, r12, pc}
 *   @0x31220e strhlo pc, [r4], #-138
 *   @0x312212 vst4.8 {d30, d31, d0, d1}, [pc], r1
 *   @0x312216 .word 0xf8c4737a
 *   @0x31221a .word 0xf8d435a0
 *   @0x31221e stmdblt sp, {r3, r4, r7, r8, r10, r12, lr}
 *   @0x312222 ldrpl pc, [r4, #0x8d4]
 *   @0x312226 svclt #0xb82d00
 *   @0x31222a .word 0xf5b5426d
 *   @0x31222e eorsle r3, r0, r0, lsl #31
 *   @0x312232 .word 0xf8d44629
 *   @0x312236 .word 0xf7d205a0
 *   @0x31223a qasxmi pc, r9, sp
 *   @0x31223e streq pc, [r0, #0x8c4]!
 *   @0x312242 streq pc, [r12, #0x8d4]
 *   @0x312246 mrc2 p7, #0x1, apsr_nzcv, c6, c2, #0x6
 *   @0x31224a .word 0xf8c44629
 *   @0x31224e .word 0xf8d4058c
 *   @0x312252 .word 0xf7d20594
 *   @0x312256 strtmi pc, [r9], -pc, lsr #28
 *   @0x31225a ldreq pc, [r4, #0x8c4]
 *   @0x31225e ldreq pc, [r0, #0x8d4]
 *   @0x312262 mcr2 p7, #0x1, pc, c8, c2, #0x6
 *   @0x312266 .word 0xf8c44629
 *   @0x31226a .word 0xf8d40590
 *   @0x31226e .word 0xf7d20598
 *   @0x312272 strtmi pc, [r9], -r1, lsr #28
 *   @0x312276 ldreq pc, [r8, #0x8c4]
 *   @0x31227a streq pc, [r4, #0x8d4]!
 *   @0x31227e mrc2 p7, #0x0, apsr_nzcv, c10, c2, #0x6
 *   @0x312282 .word 0xf8c44629
 *   @0x312286 .word 0xf8d405a4
 *   @0x31228a .word 0xf7d205a8
 *   @0x31228e .word 0xf8c4fe13
 *   @0x312292 rfeib r4!
 *   @0x312296 vrshl.s8 d3, d22, d20
 *   @0x31229a .word 0xf8d4588c
 *   @0x31229e .word 0xf8c497e8
 *   @0x3122a2 rfeib r4!
 *   @0x3122a6 .word 0xf8c435aa
 *   @0x3122aa .word 0xf1b935a8
 *   @0x3122ae rsbsle r0, r0, r0, lsl #30
 *   @0x3122b2 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x3122b6 orreq lr, r9, #4, #22
 *   @0x3122ba ubfxpl pc, r3, #0x11, #0xd
 *   @0x3122be umaallo pc, r0, r5, r8
 *   @0x3122c2 .word 0xf894b313
 *   @0x3122c6 orrlt r3, r11, #156, #10
 *   @0x3122ca strlo pc, [r0, #0x8d4]!
 *   @0x3122ce stmdble r6, {r0, r8, r9, r11, sp}
 *   @0x3122d2 svchs #0x16c6f
 *   @0x3122d6 addsmi sp, pc, #49152
 *   @0x3122da ldrmi r11, [pc], -r8, lsr #30
 *   @0x3122de strhs lr, [r1, -r0]
 *   @0x3122e2 .word 0xf1054640
 *   @0x3122e6 shasxmi r0, r10, r0
 *   @0x3122ea mrc2 p7, #0x3, apsr_nzcv, c0, c2, #0x6
 *   @0x3122ee subeq pc, r8, r5, lsl #2
 *   @0x3122f2 ldrtmi r4, [r10], -r1, asr #12
 *   @0x3122f6 mcr2 p7, #0x5, pc, c11, c2, #0x6
 *   @0x3122fa .word 0xf8d46c68
 *   @0x3122fe ldrtmi r1, [r10], -r0, lsr #11
 *   @0x312302 ldc2 p7, c15, [r11, #-840]
 *   @0x312306 ands r6, r1, r8, ror #8
 *   @0x31230a orrpl pc, r12, #4, #4
 *   @0x31230e ldreq pc, [r0, -r5, lsl #2]!
 *   @0x312312 stm r7, {r0, r1, r2, r3, r8, r9, r11, lr, pc}
 *   @0x312316 vhadd.s8 d0, d4, d15
 *   @0x31231a .word 0xf10552a4
 *   @0x31231e ldm r2, {r3, r6, r8, r9}
 *   @0x312322 stm r3, {r0, r1}
 *   @0x312326 .word 0xf8d40003
 *   @0x31232a strbtvs r3, [r11], #-1440
 *   @0x31232e stmdblt r7, {r0, r1, r2, r3, r5, r6, r7, r8, r9, r11, sp, lr}
 *   @0x312332 svchs #0x6baf
 *   @0x312336 rsbsmi r11, pc, #184, #30
 *   @0x31233a svclo #0x80f5b7
 *   @0x31233e ldrtmi sp, [r9], -r2, lsr #32
 *   @0x312342 .word 0xf7d26c68
 *   @0x312346 .word 0x4639fdb7
 *   @0x31234a blvs 0xd2b4f2 <b2_toiTime+0x5d204e>
 *   @0x31234e ldc2 p7, c15, [r2, #840]!
 *   @0x312352 .word 0x63284639
 *   @0x312356 .word 0xf7d26ba8
 *   @0x31235a ldrtmi pc, [r9], -sp, lsr #27
 *   @0x31235e blvs 0x1d2b206 <b2_toiTime+0x15d1d62>
 *   @0x312362 stc2 p7, c15, [r8, #840]!
 *   @0x312366 .word 0x63684639
 *   @0x31236a .word 0xf7d26be8
 *   @0x31236e ldrtmi pc, [r9], -r3, lsr #27
 *   @0x312372 stcvs p3, c6, [r8], #928
 *   @0x312376 ldc2 p7, c15, [lr, #840]
 *   @0x31237a strtvs r4, [r8], #1593
 *   @0x31237e .word 0xf7d26ce8
 *   @0x312382 strbtvs pc, [r8], #3481
 *   @0x312386 strhlo pc, [r10], #-149
 *   @0x31238a rfeib r5!
 *   @0x31238e strbtvs r3, [r11], #78
 *   @0x312392 blls 0x50c1c6 <SrcVerts+0x6920a>
 *   @0x312396 .word 0xf0002b00
 *   @0x31239a stmdbvs r3!, {r0, r3, r5, r8, pc}
 *   @0x31239e .word 0xf8ca210a
 *   @0x3123a2 .word 0xf8d43000
 *   @0x3123a6 adcsmi r3, r3, #224, #10
 *   @0x3123aa .word 0xf8d4bf16
 *   @0x3123ae .word 0xf8d434ac
 *   @0x3123b2 movwlo r3, #0x14c0
 *   @0x3123b6 andslo pc, r0, r10, asr #17
 *   @0x3123ba ldrlo pc, [r2, #0x9b4]!
 *   @0x3123be eorslo pc, r4, r10, asr #17
 *   @0x3123c2 ldrpl pc, [r6, #0x9b4]!
 *   @0x3123c6 eorspl pc, r8, r10, asr #17
 *   @0x3123ca .word 0xf885fa1f
 *   @0x3123ce ldrlo pc, [r8, #0x8d4]!
 *   @0x3123d2 cmnmi pc, #12582912
 *   @0x3123d6 ldrne r3, [r11], #-1023
 *   @0x3123da eorslo pc, r12, r10, asr #17
 *   @0x3123de ldrvc pc, [r12, #0x8d4]!
 *   @0x3123e2 .word 0xf507230c
 *   @0x3123e6 .word 0x37ff477f
 *   @0x3123ea .word 0xf8ca143f
 *   @0x3123ee .word 0xf8d47040
 *   @0x3123f2 blx 0xad3a7a <b2_toiTime+0x37a5d6>
 *   @0x3123f6 .word 0xf8aaf987
 *   @0x3123fa .word 0xf8aa8048
 *   @0x3123fe blx 0x6f651e <g_SWFvertbuff+0x23456>
 *   @0x312402 .word 0xf8aaf888
 *   @0x312406 addlt r0, r0, #68
 *   @0x31240a .word 0xf989fa0f
 *   @0x31240e .word 0xf0064358
 *   @0x312412 bl 0xff54d612 <b2_toiTime+0xfffffffffedf416e>
 *   @0x312416 bls 0x554442 <g_SWFlineaavertbuff+0x137a>
 *   @0x31241a addlt r11, r0, #268435465
 *   @0x31241e strbmi r11, [r3, #-0x203]
 *   @0x312422 .word 0xf8aabfae
 *   @0x312426 bl 0xff452556 <b2_toiTime+0xfffffffffecf90b2>
 *   @0x31242a .word 0xf8aa0507
 *   @0x31242e rfeib r4!
 *   @0x312432 qsub16mi r3, r0, lr
 *   @0x312436 subslo pc, r0, r10, lsr #17
 *   @0x31243a strlo pc, [r2, #0x9b4]
 *   @0x31243e subslo pc, r2, r10, lsr #17
 *   @0x312442 .word 0xf9edf7fe
 *   @0x312446 andseq pc, r4, r10, asr #17
 *   @0x31244a rsble r2, r12, r0, lsl #16
 *   @0x31244e strbne pc, [r8, #-0x8d4]!
 *   @0x312452 .word 0xf7fe4620
 *   @0x312456 .word 0xf8daf800
 *   @0x31245a .word 0x46075014
 *   @0x31245e .word 0xf5a44628
 *   @0x312462 andlo lr, r1, r10, ror #16
 *   @0x312466 ldcle p8, c2, [r8, #-24]
 *   @0x31246a blhs 0xdf0b1e <b2_toiTime+0x69767a>
 *   @0x31246e andhs sp, r1, #1073741829
 *   @0x312472 stclpl p3, c2, [r9], #0
 *   @0x312476 stmdblo r1, {r0, r8, r9, r12, sp} ^
 *   @0x31247a svclt #0x882919
 *   @0x31247e blhs 0x49ac86 <TimingData+0xc6e>
 *   @0x312482 ldrshlt sp, [r2, #-23]
 *   @0x312486 stmdane r10!, {r0, r1, r3, r5, r6, r7, r8, r10, r11, r12}
 *   @0x31248a mulle r4, r3, r2
 *   @0x31248e blne 0x3904e2 <_ZTS15b2QueryCallback+0xaa>
 *   @0x312492 .word 0x1c08f803
 *   @0x312496 stmdalo r7, {r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x31249a .word 0xf8d4e7e4
 *   @0x31249e stmdblt r9, {r2, r3, r5, r6, r8, r10, r12}
 *   @0x3124a2 subs r11, r9, pc, lsr #18
 *   @0x3124a6 .word 0xf7fd4620
 *   @0x3124aa ldmdblt r0, {r1, r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3124ae ldmdblt sp, {r3, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x3124b2 svchs #0xe052
 *   @0x3124b6 .word 0x4605d050
 *   @0x3124ba blhs 0x3305ae
 *   @0x3124be stmdavc r10!, {r2, r3, r6, r12, lr, pc}
 *   @0x3124c2 swple r4, r3, [r1]
 *   @0x3124c6 and r3, r3, r1, lsl #10
 *   @0x3124ca andle r2, r1, r0, lsr #22
 *   @0x3124ce .word 0xd1012b2d
 *   @0x3124d2 ldrb r3, [r1, r1, lsl #14]!
 *   @0x3124d6 andle r2, r1, r0, lsr #20
 *   @0x3124da .word 0xd1012a2d
 *   @0x3124de strb r3, [r11, r1, lsl #10]!
 *   @0x3124e2 teqle r9, r0, lsl #20
 *   @0x3124e6 bge 0xce3dd2 <b2_toiTime+0x58a92e>
 *   @0x3124ea .word 0xf7d6980d
 *   @0x3124ee .word 0xf8daf9e9
 *   @0x3124f2 .word 0x46075014
 *   @0x3124f6 .word 0xf5a44628
 *   @0x3124fa pkhbtmi lr, r0, lr, lsl #16
 *   @0x3124fe .word 0xf5a44638
 *   @0x312502 strmi lr, [r0, #0x81a]
 *   @0x312506 stcle p6, c4, [r3, #-12]!
 *   @0x31250a andeq lr, r8, r5, lsl #22
 *   @0x31250e andhs r1, r1, #16318464
 *   @0x312512 vqsub.u8 d4, d16, d10
 *   @0x312516 .word 0xf81080e3
 *   @0x31251a .word 0xf811cd01
 *   @0x31251e ldrbmi lr, [r4, #0xd01]!
 *   @0x312522 andlo sp, r1, #-2147483643
 *   @0x312526 .word 0xf8d4e7f4
 *   @0x31252a strtmi r1, [r0], -r8, lsl #12
 *   @0x31252e .word 0xff93f7fd
 *   @0x312532 orrlt r4, r8, r1, lsl #12
 *   @0x312536 bge 0xcf8572 <b2_toiTime+0x59f0ce>
 *   @0x31253a .word 0xf9c2f7d6
 *   @0x31253e andseq pc, r4, r10, asr #17
 *   @0x312542 stclpl p0, c14, [r10], #40
 *   @0x312546 .word 0xf0402a2d
 *   @0x31254a bllo 0x372882 <_ZTS13C_UTF16String+0x992e>
 *   @0x31254e vldmiale r8!, {d18}
 *   @0x312552 .word 0xf8cab117
 *   @0x312556 and r7, r7, r8, lsl r0
 *   @0x31255a bge 0xce4b32 <b2_toiTime+0x58b68e>
 *   @0x31255e ldrbtmi r9, [r9], #-2061
 *   @0x312562 .word 0xf9aef7d6
 *   @0x312566 andseq pc, r8, r10, asr #17
 *   @0x31256a .word 0xf6409911
 *   @0x31256e .word 0xf6400219
 *   @0x312572 stmdbhs r0, {r0, r4, r8, r9}
 *   @0x312576 sadd16mi r11, r3, r8
 *   @0x31257a ldrbhs pc, [r4, #-0x894]!
 *   @0x31257e .word 0xf043b10a
 *   @0x312582 .word 0xf8da0304
 *   @0x312586 strtmi r2, [r0], -r8
 *   @0x31258a .word 0xf8ca4313
 *   @0x31258e .word 0xf8d43008
 *   @0x312592 .word 0xf8d45578
 *   @0x312596 strlo r1, [r0, #-0x570]
 *   @0x31259a strhs r11, [r1, #-0xf18]
 *   @0x31259e .word 0xff5bf7fd
 *   @0x3125a2 .word 0xb1604607
 *   @0x3125a6 ldrbtmi r4, [r9], #-2402
 *   @0x3125aa svc #0xe4f5a3
 *   @0x3125ae stmdbmi r0!, {r3, r5, r8, r12, sp, pc} ^
 *   @0x3125b2 ldrbtmi r4, [r9], #-1592
 *   @0x3125b6 svc #0xdef5a3
 *   @0x3125ba .word 0xf045b908
 *   @0x3125be streq r0, [r11, r2, lsl #10]!
 *   @0x3125c2 .word 0xf8dad412
 *   @0x3125c6 cmnlt pc, r8, lsl r0
 *   @0x3125ca shsaxmi r4, r8, r11
 *   @0x3125ce ldrbtmi r2, [r9], #-516
 *   @0x3125d2 stmda r6, {r2, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x3125d6 ldmdbmi r8, {r4, r5, r8, r12, sp, pc} ^
 *   @0x3125da andhs r4, r5, #56, #12
 *   @0x3125de .word 0xf5a34479
 *   @0x3125e2 stmdblt r8, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, sp, lr, pc}
 *   @0x3125e6 streq pc, [r2, #-0x45]
 *   @0x3125ea andpl pc, r12, r10, asr #17
 *   @0x3125ee strblo pc, [r0, #0x8d4]!
 *   @0x3125f2 strhle r4, [r5, -r3]
 *   @0x3125f6 .word 0x3008f8da
 *   @0x3125fa movwvc pc, #0x443
 *   @0x3125fe andlo pc, r8, r10, asr #17
 *   @0x312602 strblo pc, [r0, #0x8d4]!
 *   @0x312606 strhle r4, [r7], -r3
 *   @0x31260a .word 0xb12a9a07
 *   @0x31260e .word 0x3008f8da
 *   @0x312612 orrpl pc, r0, #1124073472
 *   @0x312616 andlo pc, r8, r10, asr #17
 *   @0x31261a .word 0x5024f8da
 *   @0x31261e ldmdami r8!, {r8, r9, sp}
 *   @0x312622 andle r4, r10, r11, lsr #5
 *   @0x312626 .word 0x2028f8da
 *   @0x31262a eorhs pc, r3, r2, asr r8
 *   @0x31262e addmi r6, r1, #9502720
 *   @0x312632 ldmdbhi r2, {r1, r2, r3, r5, r12, lr, pc}
 *   @0x312636 movwlo r11, #0x1362
 *   @0x31263a blls 0x50c60a <SrcVerts+0x6964e>
 *   @0x31263e .word 0xf8d4b11b
 *   @0x312642 adcsmi r3, r3, #224, #10
 *   @0x312646 movwhs sp, #0x3147
 *   @0x31264a adclo pc, r4, sp, lsr #17
 *   @0x31264e .word 0xf8ad2301
 *   @0x312652 blmi 0xe1e8f2 <b2_toiTime+0x6c544e>
 *   @0x312656 ldmdami r9!, {r8, sp}
 *   @0x31265a .word 0xf8cdaa27
 *   @0x31265e .word 0x9328a09c
 *   @0x312662 stmdavs r0, {r3, r4, r5, r6, r10, lr}
 *   @0x312666 .word 0xf7d5460b
 *   @0x31266a tstlt r0, r5, lsl #29
 *   @0x31266e blhs 0xfebff182 <b2_toiTime+0xfffffffffe4a5cde>
 *   @0x312672 movwhs sp, #0x130
 *   @0x312676 .word 0xf8da931b
 *   @0x31267a stmdblt r11, {r2, r3, r4, r6, r12, sp} ^
 *   @0x31267e .word 0x3024f8da
 *   @0x312682 mulle r5, sp, r2
 *   @0x312686 .word 0x3028f8da
 *   @0x31268a eorlo pc, r5, r3, asr r8
 *   @0x31268e subslo pc, r12, r10, asr #17
 *   @0x312692 ldrsblo pc, [r8], r4
 *   @0x312696 movwhs r11, #0x71fb
 *   @0x31269a addsge pc, r12, sp, asr #17
 *   @0x31269e adclo pc, r4, sp, lsr #17
 *   @0x3126a2 ldrsblo pc, [r4], r4
 *   @0x3126a6 .word 0xf8adb91b
 *   @0x3126aa blmi 0x91e94a <b2_toiTime+0x1c54a6>
 *   @0x3126ae blhs 0x38a6da <bigtens_D2A+0xbaa>
 *   @0x3126b2 .word 0xf8add103
 *   @0x3126b6 blmi 0x89e956 <b2_toiTime+0x1454b2>
 *   @0x3126ba movwhs lr, #0x2003
 *   @0x3126be adclo pc, r6, sp, lsr #17
 *   @0x3126c2 ldmdami pc, {r0, r2, r4, r8, r9, r11, lr}
 *   @0x3126c6 .word 0x93282100
 *   @0x3126ca ldrbtmi r10, [r8], #-2599
 *   @0x3126ce strmi r6, [r11], -r0, lsl #16
 *   @0x3126d2 mrc2 p7, #0x2, apsr_nzcv, c0, c5, #0x6
 *   @0x3126d6 ldmdals r11, {r0, r1, r3, r4, r12, pc}
 *   @0x3126da and lr, pc, r0, lsl r0
 *   @0x3126de movweq lr, #0x8bc3
 *   @0x3126e2 bhs 0xb4c3b6 <b2_toiTime+0x3f2f12>
 *   @0x3126e6 svcge #0x31f43f
 *   @0x3126ea .word 0xf43f2a5f
 *   @0x3126ee bhs 0xdfe3ae <b2_toiTime+0x6a4f0a>
 *   @0x3126f2 svcge #0x2bf43f
 *   @0x3126f6 andhs r4, r0, #721420288
 *   @0x3126fa .word 0xe729705a
 *   @0x3126fe pop {r0, r4, r5, r12, sp, pc}
 *   @0x312702 strdeq r8, r9, [r3], -r0
 *   @0x312706 stmdbvs r3!, {r0} ^
 *   @0x31270a ldmibne r0!, {r1, r2, r3, r5, r6, r8, r10, r12, sp, lr} ^
 *   @0x31270e svcmi #0x420009
 *   @0x312712 submi r4, r5, #68, #2
 *   @0x312716 submi r4, r3, #68, #2
 *   @0x31271a stmibne r4, {r2, r6, r8, lr} ^
 *   @0x31271e ldmibne r10, {r0, r3}
 *   @0x312722 ldrbne r0, [r6, -r9]
 *   @0x312726 strbne r0, [r12, -r9]
 *   @0x31272a adcgt r0, r12, #9
 *   @0x31272e subgt r0, r2, #7
 *   @0x312732 strbtgt r0, [r4], r7
 *   @0x312736 andsgt r0, r10, #7
 *   @0x31273a ldrtgt r0, [r10], r7
 *   @0x31273e .word 0xf59a0007
 *   @0x312742 .word 0xf52c000d
 *   @0x312746 push {r0, r2, r3}
 *   @0x31274a .word 0xf5ad4ff0
 *   @0x31274e addlt r5, r7, r11, ror sp
 *   @0x312752 ldrgt pc, [r12, #0x8df]
 *   @0x312756 ldrbpl pc, [r12, #-0x50d]!
 *   @0x31275a strlo r10, [r12, #-0xc36]
 *   @0x31275e .word 0xf50d910b
 *   @0x312762 ldrbtmi r5, [r12], #380
 *   @0x312766 .word 0xc000f8dc
 *   @0x31276a strmi r6, [r3], sp, lsr #16
 *   @0x31276e strhs r7, [r10, -r9, lsl #16]
 *   @0x312772 mcrge p3, #0x1, r9, c6, c7, #0x0
 *   @0x312776 .word 0xf8d09510
 *   @0x31277a .word 0xf8dc50b0
 *   @0x31277e tstls r11, r0
 *   @0x312782 cmnpl r11, sp, lsl #10
 *   @0x312786 stcne p5, c9, [r5, #-36]
 *   @0x31278a tstlo r4, pc, lsl #10
 *   @0x31278e andvs r6, r11, r5, asr #22
 *   @0x312792 .word 0xf8d02100
 *   @0x312796 ldrls r8, [r4, #-0x0]
 *   @0x31279a andsls r9, r10, #576
 *   @0x31279e .word 0xf8d52280
 *   @0x3127a2 ldcge p2, c3, [lr, #-896]!
 *   @0x3127a6 qadd16mi r9, r8, r12
 *   @0x3127aa eorlo pc, r0, #13828096
 *   @0x3127ae .word 0xf50d9311
 *   @0x3127b2 movwlo r5, #0x837c
 *   @0x3127b6 .word 0xf8cd681b
 *   @0x3127ba movwls r12, #0xa010
 *   @0x3127be cdp p5, #0xf, c15, c8, c3, #0x5
 *   @0x3127c2 tsths r0, #960
 *   @0x3127c6 .word 0xf1a49a0f
 *   @0x3127ca .word 0x93280120
 *   @0x3127ce .word 0xf8442314
 *   @0x3127d2 adcvs r3, r3, r8, lsl r12
 *   @0x3127d6 cmnpl r10, #54525952
 *   @0x3127da strls r3, [r7, #-0x31c]!
 *   @0x3127de tstls r3, r0, lsl #10
 *   @0x3127e2 .word 0x2c1cf844
 *   @0x3127e6 rsbvs r4, r2, r9, lsr #12
 *   @0x3127ea andshs r4, r12, #24, #12
 *   @0x3127ee strls r9, [r10, -r9, lsr #10]!
 *   @0x3127f2 strls r9, [r12, #-0x52b]!
 *   @0x3127f6 .word 0xf844952d
 *   @0x3127fa .word 0xf8445c14
 *   @0x3127fe .word 0xf8447c10
 *   @0x312802 .word 0xf8445c0c
 *   @0x312806 .word 0xf8445c08
 *   @0x31280a rscvs r5, r5, r4, lsl #24
 *   @0x31280e .word 0x61656127
 *   @0x312812 mvnvs r6, r5, lsr #3
 *   @0x312816 .word 0xf8cd931d
 *   @0x31281a .word 0xf8448098
 *   @0x31281e .word 0xf8c48c20
 *   @0x312822 .word 0xf5a38000
 *   @0x312826 .word 0xf50deec4
 *   @0x31282a stmdbls pc, {r2, r7, r8, r9, r12, lr}
 *   @0x31282e .word 0xf50d3318
 *   @0x312832 .word 0xf1a3527a
 *   @0x312836 andslo r0, r12, #4, #20
 *   @0x31283a qadd16mi r6, r9, r1
 *   @0x31283e andvs pc, r8, #69206016
 *   @0x312842 movwls r4, #0x7650
 *   @0x312846 cdp p5, #0xb, c15, c4, c3, #0x5
 *   @0x31284a orrpl pc, r4, sp, lsl #10
 *   @0x31284e ldmdbpl r5!, {r1, r3, r8, r10, r12, sp, lr, pc}
 *   @0x312852 bls 0x99ecaa <b2_toiTime+0x245806>
 *   @0x312856 andlt pc, r0, r1, asr #17
 *   @0x31285a tsteq r12, #1073741826
 *   @0x31285e .word 0xf8c9990f
 *   @0x312862 .word 0xf50a702c
 *   @0x312866 .word 0xf8ca57f2
 *   @0x31286a .word 0xf6402004
 *   @0x31286e movwls r7, #0x821c
 *   @0x312872 movwhs r4, #0x8638
 *   @0x312876 eorne pc, r0, r9, asr #17
 *   @0x31287a eorlo pc, r4, r9, asr #17
 *   @0x31287e .word 0xf8c94629
 *   @0x312882 .word 0xf5a3801c
 *   @0x312886 .word 0xf89bee94
 *   @0x31288a bls 0x81eb72 <b2_toiTime+0xc56ce>
 *   @0x31288e rscspl pc, sp, sp, lsl #10
 *   @0x312892 andslo r9, r8, r8, lsl #18
 *   @0x312896 teqvs r10, r11, ror r3
 *   @0x31289a andsvc pc, r12, #64, #12
 *   @0x31289e .word 0x462960b9
 *   @0x3128a2 andlt pc, r0, r7, asr #17
 *   @0x3128a6 movwls r6, #0x507f
 *   @0x3128aa cdp p5, #0x8, c15, c2, c3, #0x5
 *   @0x3128ae blls 0x479106 <g_RomDisk+0x818e6>
 *   @0x3128b2 .word 0xf8ca9908
 *   @0x3128b6 .word 0xf50d2f34
 *   @0x3128ba andslo r5, r8, #132, #4
 *   @0x3128be svclo #0x31f88a
 *   @0x3128c2 svcne #0x2cf8ca
 *   @0x3128c6 qadd16mi r1, r9, r0
 *   @0x3128ca svclt #0x24f8ca
 *   @0x3128ce svcvc #0x28f8ca
 *   @0x3128d2 andsvc pc, r12, #64, #12
 *   @0x3128d6 .word 0xf5a39305
 *   @0x3128da blls 0x48e28a <prim_v+0x48d6>
 *   @0x3128de .word 0xf8db9d14
 *   @0x3128e2 .word 0xf88a2030
 *   @0x3128e6 blls 0x51e942 <SrcVerts+0x7b986>
 *   @0x3128ea andspl pc, r8, r10, asr #17
 *   @0x3128ee andlt pc, r8, r10, asr #17
 *   @0x3128f2 andslo pc, r0, r10, asr #17
 *   @0x3128f6 .word 0x3028f8db
 *   @0x3128fa andvc pc, r12, r10, asr #17
 *   @0x3128fe eorslo pc, r12, r9, asr #17
 *   @0x312902 teqpl r6, #41943040
 *   @0x312906 eoreq lr, r4, r3, lsl #17
 *   @0x31290a andeq pc, r8, #-1073741824
 *   @0x31290e orrsvs r9, r12, r7, lsl sp
 *   @0x312912 muleq r3, r5, r8
 *   @0x312916 stm r2, {r1, r3, r8, r10, r11, r12, pc}
 *   @0x31291a .word 0xf50d0003
 *   @0x31291e andslo r5, r12, #-1610612729
 *   @0x312922 .word 0xf10b61da
 *   @0x312926 subsvs r0, r10, #240, #4
 *   @0x31292a umlalshs pc, r9, r11, r8
 *   @0x31292e cmpvs r9, lr, lsr #18
 *   @0x312932 .word 0x10e4f8db
 *   @0x312936 .word 0xf8db749a
 *   @0x31293a addsvs r2, r9, #232
 *   @0x31293e svclt #0xb82900
 *   @0x312942 andsvs r4, sp, #-1879048188
 *   @0x312946 bhs 0x32b4b6
 *   @0x31294a subsmi r11, r2, #184, #30
 *   @0x31294e svclt #0xa84291
 *   @0x312952 subseq r4, r2, r10, lsl #12
 *   @0x312956 .word 0xf641631a
 *   @0x31295a cmpvs r10, #-1610612727
 *   @0x31295e ldrbvc r2, [r10], #513
 *   @0x312962 mullo r8, r11, r8
 *   @0x312966 svclt #0x183300
 *   @0x31296a .word 0xf8062301
 *   @0x31296e stcls p12, c3, [r9, #-20]
 *   @0x312972 rsclo pc, r0, #13959168
 *   @0x312976 .word 0xf8d39d10
 *   @0x31297a ldreq r3, [r11], #-540
 *   @0x31297e .word 0xf8dd602b
 *   @0x312982 .word 0xf89bc010
 *   @0x312986 .word 0xf8cd3008
 *   @0x31298a smlawblt r11, r0, r0, r12
 *   @0x31298e stclvs p13, c9, [r11], #36
 *   @0x312992 .word 0x3614f8d3
 *   @0x312996 and r9, r1, r5, lsl r3
 *   @0x31299a ldrls r2, [r5, #-0x530]
 *   @0x31299e strbmi r10, [r0], -r6, ror #26
 *   @0x3129a2 smulwbeq r0, r5, r1
 *   @0x3129a6 qaddls r10, lr, r8
 *   @0x3129aa .word 0x26002114
 *   @0x3129ae stcvs p8, c15, [r0], #-276
 *   @0x3129b2 blx 0xff15090c <b2_toiTime+0xfffffffffe9f7468>
 *   @0x3129b6 stclo p8, c15, [r0], #-340
 *   @0x3129ba ldmdblt r11, {r2, r9, r10, lr}
 *   @0x3129be .word 0xf8c09a0f
 *   @0x3129c2 subvs r8, r2, r0
 *   @0x3129c6 .word 0x9600ab5e
 *   @0x3129ca strbmi r9, [r0], -r1, lsl #6
 *   @0x3129ce .word 0x21089b15
 *   @0x3129d2 .word 0xf7d52200
 *   @0x3129d6 adcvs pc, r0, r11, asr r11
 *   @0x3129da stclo p8, c15, [r0], #-340
 *   @0x3129de .word 0x4640b13b
 *   @0x3129e2 .word 0xf7d44621
 *   @0x3129e6 strhs pc, [r0, #-0xca7]
 *   @0x3129ea .word 0xf0009512
 *   @0x3129ee ldcls p15, c11, [r5, #-776]
 *   @0x3129f2 ldrls r6, [r2], #-224
 *   @0x3129f6 .word 0x2c006125
 *   @0x3129fa ldrhi pc, [r11, r0]!
 *   @0x3129fe fstmdbxge r6!, {d9, d10, d11, d12, d13, d14, d15, d16, d17, d18, d19, d20, d21, d22, d23, d24, d25, d26, d27, d28}
 *   @0x312a02 blhs 0x737e32 <g_SWFvertbuff+0x64d6a>
 *   @0x312a06 tsths r1, #32768
 *   @0x312a0a and r9, r5, r11, lsr #6
 *   @0x312a0e tsths r1, r6, lsr #16
 *   @0x312a12 .word 0xffddf7fb
 *   @0x312a16 mvnsle r2, r0, lsl #16
 *   @0x312a1a strls r9, [r7, #-0xd2d]
 *   @0x312a1e ldm r5, {r0, r1, r3, r8, r10, r11, r12, pc}
 *   @0x312a22 stcls p0, c0, [r7, #-60]
 *   @0x312a26 andeq lr, pc, r5, lsl #17
 *   @0x312a2a .word 0x5004f8db
 *   @0x312a2e teqle r5, r0, lsl #26
 *   @0x312a32 ldmdbls r1, {r4, r5, r7, r8, r9, r11, lr}
 *   @0x312a36 bmi 0xfee23c2a <b2_toiTime+0xfffffffffe6ca786>
 *   @0x312a3a msreq APSR_g, #3145728
 *   @0x312a3e blmi 0xfee776ca <b2_toiTime+0xfffffffffe71e226>
 *   @0x312a42 strls r0, [r11, #-0x409]
 *   @0x312a46 ldreq pc, [r3, #0x10d]
 *   @0x312a4a ldrbtmi r9, [r11], #-1297
 *   @0x312a4e .word 0xf6034dab
 *   @0x312a52 tstls r6, r8, lsl r3
 *   @0x312a56 andsls r4, r9, #2097152000
 *   @0x312a5a strls r9, [r3, #-0x322]!
 *   @0x312a5e blls 0x64aaa2 <g_SWFaavertbuff+0x779da>
 *   @0x312a62 blne 0x1a6ccf2 <b2_toiTime+0x131384e>
 *   @0x312a66 bne 0xfe9acdfa <b2_toiTime+0xfffffffffe253956>
 *   @0x312a6a svceq #0xe2ebb5
 *   @0x312a6e rschi pc, r4, r0, asr #4
 *   @0x312a72 .word 0x21a16860
 *   @0x312a76 .word 0xf9e4f7fb
 *   @0x312a7a .word 0xf88b2301
 *   @0x312a7e stcls p0, c3, [r7, #-372]
 *   @0x312a82 stmvs r11!, {r1, r3, r5, r6, r7, r11, sp, lr}
 *   @0x312a86 movwle r4, #0xc29a
 *   @0x312a8a stchs p13, c9, [r0, #-44]
 *   @0x312a8e .word 0xf04fbf0c
 *   @0x312a92 .word 0xf04f080e
 *   @0x312a96 .word 0xf8db080b
 *   @0x312a9a .word 0xb1a33004
 *   @0x312a9e .word 0xf0002500
 *   @0x312aa2 stmdals r7, {r0, r3, r5, r6, r8, r9, r10, r11, r12, sp, pc}
 *   @0x312aa6 blx 0xff810aa0 <b2_toiTime+0xffffffffff0b75fc>
 *   @0x312aaa .word 0xf880fa5f
 *   @0x312aae svceq #0xbf1b8
 *   @0x312ab2 .word 0xf1b8d002
 *   @0x312ab6 mvnle r0, lr, lsl #30
 *   @0x312aba mullo r8, r11, r8
 *   @0x312abe svclt #0x182b00
 *   @0x312ac2 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x312ac6 ldcls p7, c14, [r9, #-924]
 *   @0x312aca ldrls r3, [r9, #-0xd01]
 *   @0x312ace strhi pc, [r4], #0
 *   @0x312ad2 svceq #0x1ff1b8
 *   @0x312ad6 strhi pc, [r4, -r0, lsl #4]
 *   @0x312ada .word 0xf018e8df
 *   @0x312ade adcseq r0, r2, r7, asr #14
 *   @0x312ae2 sbceq r0, r1, r7, asr #14
 *   @0x312ae6 ldrsbeq r0, [r1, -r10]
 *   @0x312aea teqeq r12, r12, lsr r1
 *   @0x312aee strbeq r0, [r7, -r9, ror #2]
 *   @0x312af2 eoreq r0, r3, #-2147483593
 *   @0x312af6 strbeq r0, [r7, -pc, lsr #4]
 *   @0x312afa eoreq r0, r0, r11, ror #7
 *   @0x312afe smlaldxeq r0, r7, r4, r0
 *   @0x312b02 streq r0, [r0], #178
 *   @0x312b06 ldrbeq r0, [lr], #1152
 *   @0x312b0a sbceq r0, r1, r0, lsl r5
 *   @0x312b0e ldreq r0, [sp, #-0x169]!
 *   @0x312b12 .word 0x060405b1
 *   @0x312b16 ldrsheq r0, [lr, #102]
 *   @0x312b1a usaxeq r0, r7, r7
 *   @0x312b1e mullo r8, r11, r8
 *   @0x312b22 .word 0xf0002b00
 *   @0x312b26 .word 0xf89b8722
 *   @0x312b2a blhs 0x31eca6
 *   @0x312b2e ldrbhi pc, [r4], #-64
 *   @0x312b32 .word 0xf7fc4620
 *   @0x312b36 stmdahs r0, {r0, r1, r2, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x312b3a ldrhi pc, [r7, -r0, asr #5]
 *   @0x312b3e rsbseq pc, r8, r11, asr #17
 *   @0x312b42 svclt #0x13f000
 *   @0x312b46 mullo r8, r11, r8
 *   @0x312b4a .word 0xf0002b00
 *   @0x312b4e .word 0xf8db870e
 *   @0x312b52 blhs 0x31ecda
 *   @0x312b56 strbhi pc, [r0], #-0
 *   @0x312b5a ldrsbtvc pc, [r8], #-139
 *   @0x312b5e ldmdaeq r12, {r0, r1, r3, r8, r12, sp, lr, pc} ^
 *   @0x312b62 ldrsbtvs pc, [r12], #-139
 *   @0x312b66 .word 0x5080f8db
 *   @0x312b6a ldrtmi r4, [r9], -r0, asr #12
 *   @0x312b6e qasxmi r4, r11, r2
 *   @0x312b72 .word 0xf8a0f7fd
 *   @0x312b76 strtmi r11, [r0], -r8, lsr #19
 *   @0x312b7a blx 0xfec50b74 <b2_toiTime+0xfffffffffe4f76d0>
 *   @0x312b7e adcmi r9, r8, #1344
 *   @0x312b82 vmax.s8 d4, d0, d6
 *   @0x312b86 .word 0xf8db8429
 *   @0x312b8a stmvs r2!, {r4, r5, r6, r12, lr} ^
 *   @0x312b8e movtmi r6, #0x58a3
 *   @0x312b92 bl 0xff4596e6 <b2_toiTime+0xfffffffffed00242>
 *   @0x312b96 movwls r0, #0xd3e3
 *   @0x312b9a ldrmi r9, [r9], r12, lsl #10
 *   @0x312b9e strmi r2, [r1], #1280
 *   @0x312ba2 qadd16mi lr, r11, r5
 *   @0x312ba6 ldrtmi r4, [r9], -r0, asr #12
 *   @0x312baa .word 0xf7fb4632
 *   @0x312bae strmi pc, [r5], -r1, asr #30
 *   @0x312bb2 rscle r2, r0, r0, lsl #16
 *   @0x312bb6 cdplt p0, #0xd, c15, c14, c0, #0x0
 *   @0x312bba stmvs r1!, {r1, r5, r7, r11, sp, lr} ^
 *   @0x312bbe bl 0xff0d95ea <b2_toiTime+0xfffffffffe980146>
 *   @0x312bc2 ldmdble r1!, {r0, r5, r6, r7, r8, r9, r10, r11}
 *   @0x312bc6 orrhs r6, r2, r0, ror #16
 *   @0x312bca rfedb r10!
 *   @0x312bce adcsmi r3, r5, #4194304
 *   @0x312bd2 svcge #0x45f43f
 *   @0x312bd6 strtmi r9, [r0], -sp, lsl #30
 *   @0x312bda ldrsbths pc, [r4], #-139
 *   @0x312bde stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x312be2 ldrtmi r4, [r9], -pc, lsr #8
 *   @0x312be6 .word 0xf7fc920e
 *   @0x312bea strmi pc, [r3], -r7, lsr #23
 *   @0x312bee ldrsbths pc, [r0], #-139
 *   @0x312bf2 rscle r4, r1, #144, #10
 *   @0x312bf6 strtmi r9, [r0], -lr, lsl #18
 *   @0x312bfa .word 0x0c01f109
 *   @0x312bfe eorhs pc, r8, r1, asr r8
 *   @0x312c02 movwls r4, #0x5649
 *   @0x312c06 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x312c0a andsgt pc, r0, sp, asr #17
 *   @0x312c0e .word 0xf7fc9206
 *   @0x312c12 bls 0x4d1a66 <SrcVerts+0x2eaaa>
 *   @0x312c16 ldrmi r4, [r0], -r1, lsl #12
 *   @0x312c1a .word 0xf8cbf7fb
 *   @0x312c1e ldrsbgt pc, [r0], -sp
 *   @0x312c22 strbtmi r9, [r1], r5, lsl #22
 *   @0x312c26 strb r4, [r1, r3, lsl #8]!
 *   @0x312c2a eorslo pc, r7, r2, asr #16
 *   @0x312c2e stmvs r3!, {r9, sp}
 *   @0x312c32 strbeq lr, [r7, r3, lsl #22]
 *   @0x312c36 .word 0xe7c9607a
 *   @0x312c3a blne 0x19d2ff6 <b2_toiTime+0x1279b52>
 *   @0x312c3e ldr r6, [r11, -r3, ror #1]
 *   @0x312c42 ldrbpl pc, [r10, #-0x50d]!
 *   @0x312c46 stmdavc r11!, {r5, r8, r10, r12, sp}
 *   @0x312c4a .word 0xf0402b00
 *   @0x312c4e .word 0xf10d868e
 *   @0x312c52 .word 0xf10b0393
 *   @0x312c56 movwls r0, #0xb0
 *   @0x312c5a bge 0xea44e6 <b2_toiTime+0x74b042>
 *   @0x312c5e .word 0xf50de00d
 *   @0x312c62 eorlo r5, r0, #-1610612729
 *   @0x312c66 blhs 0x330cba
 *   @0x312c6a ldrbthi pc, [pc], -r0, asr #32
 *   @0x312c6e adcseq pc, r0, r11, lsl #2
 *   @0x312c72 qasxmi r10, r1, r6
 *   @0x312c76 orrseq pc, r3, #1073741827
 *   @0x312c7a blls 0x737882 <g_SWFvertbuff+0x647ba>
 *   @0x312c7e blx 0xfec10c7c <b2_toiTime+0xfffffffffe4b77d8>
 *   @0x312c82 ldrsbtlo pc, [r0], r11
 *   @0x312c86 eorslo pc, r1, #9633792
 *   @0x312c8a .word 0xf0002b00
 *   @0x312c8e str r8, [r5, -lr, ror #12]
 *   @0x312c92 stmvs r3!, {r1, r5, r6, r7, r11, sp, lr}
 *   @0x312c96 blhs 0x6d97ea <g_SWFvertbuff+0x6722>
 *   @0x312c9a .word 0xf89dd909
 *   @0x312c9e ldmdblt r1!, {r0, r1, r4, r7, r12}
 *   @0x312ca2 .word 0xf7fc4620
 *   @0x312ca6 vldrls d15, [r6, #-292]
 *   @0x312caa ldcls p4, c4, [r0, #-160]
 *   @0x312cae movwhs r6, #0x1028
 *   @0x312cb2 addslo pc, r3, sp, lsl #17
 *   @0x312cb6 ldrsbtlo pc, [r0], r11
 *   @0x312cba eorslo pc, r1, #9633792
 *   @0x312cbe .word 0xf47f2b00
 *   @0x312cc2 .word 0xf50daeed
 *   @0x312cc6 qsub16mi r5, r0, r12
 *   @0x312cca stmdavs sp, {r3, r8, r12, sp}
 *   @0x312cce blx 0x7d0cc8 <b2_toiTime+0x77824>
 *   @0x312cd2 cmnpl r12, #54525952
 *   @0x312cd6 stmdane r10!, {r3, r8, r9, r12, sp}
 *   @0x312cda ldrbpl pc, [r12, #-0x50d]!
 *   @0x312cde andsvs r3, r10, r4, lsl #10
 *   @0x312ce2 stmdavs r9!, {r4, r6, r9, r10, lr}
 *   @0x312ce6 ldclt p0, c15, [r4], #-0
 *   @0x312cea stchs p15, c11, [r0, #-0]
 *   @0x312cee mvnslt r0, r1, lsr r1
 *   @0x312cf2 stcleq p0, c0, [r2, #52]!
 *   @0x312cf6 stcleq p0, c0, [r12, #36]
 *   @0x312cfa stcleq p0, c0, [r2, #36]
 *   @0x312cfe stmvs r6!, {r0, r3} ^
 *   @0x312d02 stmvs r3!, {r8, r10, sp}
 *   @0x312d06 ldrshtne r1, [r6], #166
 *   @0x312d0a .word 0xf08042b5
 *   @0x312d0e .word 0xf50d862e
 *   @0x312d12 qsub16mi r5, r0, r12
 *   @0x312d16 stmdavs pc, {r2, r8, r12, sp}
 *   @0x312d1a .word 0xf7fc4629
 *   @0x312d1e .word 0xf50dfb0d
 *   @0x312d22 andlo r5, r4, #124, #4
 *   @0x312d26 cmnpl r12, #54525952
 *   @0x312d2a stclne p3, c3, [r9], #-32
 *   @0x312d2e ldrtmi r3, [r8], #-1282
 *   @0x312d32 qadd16mi r6, r0, r0
 *   @0x312d36 .word 0xf7fc681f
 *   @0x312d3a .word 0xf50dfaff
 *   @0x312d3e .word 0xf50d517c
 *   @0x312d42 .word 0x3108537c
 *   @0x312d46 ldmdane r10!, {r2, r8, r9, r12, sp}
 *   @0x312d4a andvs r4, r10, r0, asr r6
 *   @0x312d4e .word 0xf7fe6819
 *   @0x312d52 ldrb pc, [r9, r0, lsl #18]
 *   @0x312d56 .word 0xf1b868e5
 *   @0x312d5a stmvs r3!, {r1, r2, r8, r9, r10}
 *   @0x312d5e cmnmi lr, lr, ror r2
 *   @0x312d62 bne 0xffe5c96a <b2_toiTime+0xffffffffff7034c6>
 *   @0x312d66 adcmi r1, pc, #237
 *   @0x312d6a ldrbhi pc, [pc, #0x0]!
 *   @0x312d6e ldrtmi r4, [r9], -r0, lsr #12
 *   @0x312d72 blx 0xffbd0d6a <b2_toiTime+0xffffffffff4778c6>
 *   @0x312d76 .word 0xf50db136
 *   @0x312d7a .word 0x3104517c
 *   @0x312d7e ldrmi r6, [r8], #-2059
 *   @0x312d82 and r6, r5, r8
 *   @0x312d86 rsbspl pc, r12, #54525952
 *   @0x312d8a ldmdavs r3, {r3, r9, r12, sp}
 *   @0x312d8e andsvs r4, r0, r8, lsl r4
 *   @0x312d92 cmnpl r12, #54525952
 *   @0x312d96 movwlo r4, #0x4650
 *   @0x312d9a streq pc, [r1], -r6, lsl #1
 *   @0x312d9e .word 0xf50d6819
 *   @0x312da2 movwlo r5, #0x837c
 *   @0x312da6 ldmdavs r10, {r0, r8, r9, r10, r12, sp}
 *   @0x312daa .word 0xf8d3f7fe
 *   @0x312dae stmvs r2!, {r0, r1, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x312db2 stmvs r3!, {r8, r10, sp}
 *   @0x312db6 ldrsbne r1, [r11], #163
 *   @0x312dba bls 0x6779f6 <g_SWFlinevertbuff+0x2492e>
 *   @0x312dbe .word 0x0c06f105
 *   @0x312dc2 stmdale r2, {r2, r4, r7, r8, r10, lr} ^
 *   @0x312dc6 strtmi r4, [r0], -r9, lsr #12
 *   @0x312dca andsgt pc, r0, sp, asr #17
 *   @0x312dce blx 0xff050dc6 <b2_toiTime+0xfffffffffe8f7922>
 *   @0x312dd2 cmnpl r12, sp, lsl #10
 *   @0x312dd6 stmdavs r11, {r2, r8, r12, sp}
 *   @0x312dda stmne r3, {r0, r3, r5, r6, r10, r11, r12} ^
 *   @0x312dde movwls r4, #0xc620
 *   @0x312de2 blx 0xfedd0dda <b2_toiTime+0xfffffffffe677936>
 *   @0x312de6 rsbspl pc, r12, #54525952
 *   @0x312dea andlo r1, r8, #43264
 *   @0x312dee bl 0x32ce42
 *   @0x312df2 strtmi r0, [r0], -r3, lsl #18
 *   @0x312df6 blx 0xfeb50dee <b2_toiTime+0xfffffffffe3f794a>
 *   @0x312dfa stclne p15, c9, [r9], #48
 *   @0x312dfe strtmi r4, [r0], -r7, lsl #8
 *   @0x312e02 blx 0xfe9d0dfa <b2_toiTime+0xfffffffffe277956>
 *   @0x312e06 bl 0x31a2b2 <_Unwind_VRS_Pop+0xf6>
 *   @0x312e0a strtmi r0, [r0], -r9, lsl #6
 *   @0x312e0e .word 0xf7fc9305
 *   @0x312e12 vstmdbne r9!, {s31}
 *   @0x312e16 strtmi r1, [r0], -r6, asr #19
 *   @0x312e1a blx 0xfe6d0e12 <b2_toiTime+0xfffffffffdf7796e>
 *   @0x312e1e stmdbls r12, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x312e22 stm sp, {r1, r3, r6, r9, r10, lr}
 *   @0x312e26 stmne r5, {r3, r6} ^
 *   @0x312e2a strls r4, [r2, #-0x63b]
 *   @0x312e2e .word 0xf7fe4650
 *   @0x312e32 .word 0xf50df92c
 *   @0x312e36 .word 0xf50d537c
 *   @0x312e3a movwlo r5, #0x417c
 *   @0x312e3e andsvs r3, lr, r8, lsl #2
 *   @0x312e42 .word 0xf8dd600d
 *   @0x312e46 uqadd16mi r12, r5, r0
 *   @0x312e4a .word 0xf1b8e7b7
 *   @0x312e4e .word 0xf0400f18
 *   @0x312e52 .word 0xf50d858c
 *   @0x312e56 qsub16mi r5, r9, r12
 *   @0x312e5a strtmi r3, [r0], -r4, lsl #6
 *   @0x312e5e .word 0xf7fc681e
 *   @0x312e62 .word 0xf50dfa6b
 *   @0x312e66 .word 0xf50d517c
 *   @0x312e6a .word 0x3104527c
 *   @0x312e6e ldrtmi r3, [r0], #-520
 *   @0x312e72 stclne p0, c6, [r9], #-32
 *   @0x312e76 ldmdavs r6, {r5, r9, r10, lr}
 *   @0x312e7a blx 0x1ad0e72 <b2_toiTime+0x13779ce>
 *   @0x312e7e ldrbpl pc, [r12, #-0x50d]!
 *   @0x312e82 cmnpl r12, #54525952
 *   @0x312e86 movwlo r3, #0x8504
 *   @0x312e8a ldmdane r2!, {r0, r3, r5, r11, sp, lr}
 *   @0x312e8e andsvs r4, r10, r0, asr r6
 *   @0x312e92 .word 0xf85ff7fe
 *   @0x312e96 stcllt p0, c15, [r9, #-0]!
 *   @0x312e9a ldchs p13, c9, [r0, #-44]
 *   @0x312e9e addshi pc, r12, #0, #6
 *   @0x312ea2 stmdage r6!, {r0, r8, r10, r12, sp}
 *   @0x312ea6 .word 0xf7fa4629
 *   @0x312eaa .word 0x9007ffd0
 *   @0x312eae .word 0xf7fc4620
 *   @0x312eb2 .word 0xf1b8fa09
 *   @0x312eb6 .word 0xf04f0f1d
 *   @0x312eba .word 0xf04f0100
 *   @0x312ebe .word 0x46060210
 *   @0x312ec2 tstle r4, r7, lsl #16
 *   @0x312ec6 bl 0x205055a <b2_toiTime+0x18f70b6>
 *   @0x312eca .word 0xf8d19909
 *   @0x312ece ldrmi r3, [lr], #-708
 *   @0x312ed2 adcslo pc, r12, #13697024
 *   @0x312ed6 .word 0xf080429e
 *   @0x312eda .word 0xf8d1827f
 *   @0x312ede bls 0x4dfa16 <SrcVerts+0x3ca5a>
 *   @0x312ee2 eorlo pc, r6, r3, asr r8
 *   @0x312ee6 ldrsbvs r6, [r3], #-3
 *   @0x312eea sbclo pc, r12, #13697024
 *   @0x312eee .word 0xf5a3e013
 *   @0x312ef2 stmdbls r9, {r1, r2, r3, r4, r6, r8, r9, r11, sp, lr, pc}
 *   @0x312ef6 sbclo pc, r0, #13697024
 *   @0x312efa .word 0xf8d1441e
 *   @0x312efe addsmi r3, lr, #184, #4
 *   @0x312f02 rsbhi pc, r10, #128
 *   @0x312f06 sbclo pc, r8, #13697024
 *   @0x312f0a .word 0xf8539a07
 *   @0x312f0e sbcsvs r3, r3, r6, lsr #32
 *   @0x312f12 .word 0xf8d16053
 *   @0x312f16 bl 0x3dfa3e <error_g0017+0x386e2>
 *   @0x312f1a ldmdavs r3!, {r1, r2, r7, r9, r10} ^
 *   @0x312f1e addsvs r9, r3, r11, lsl #10
 *   @0x312f22 stcls p5, c14, [r11, #-692]
 *   @0x312f26 .word 0xf0002d00
 *   @0x312f2a stclo p2, c8, [r1, #-348]
 *   @0x312f2e strls r10, [r11, #-0x826]
 *   @0x312f32 .word 0xf7fa4629
 *   @0x312f36 andls pc, r7, r10, lsl #31
 *   @0x312f3a stmdals r7, {r0, r5, r7, r8, r10, sp, lr, pc}
 *   @0x312f3e .word 0xf987f7fc
 *   @0x312f42 cdpne p2, #0x4, c11, c3, c0, #0x6
 *   @0x312f46 ldmdale r2, {r2, r5, r8, r9, r11, sp} ^
 *   @0x312f4a .word 0xf013e8df
 *   @0x312f4e streq r0, [pc, #-0x50f]
 *   @0x312f52 subseq r0, r1, r1, asr r0
 *   @0x312f56 streq r0, [pc, #-0x51]
 *   @0x312f5a streq r0, [pc, #-0x50f]
 *   @0x312f5e subseq r0, r1, r1, asr r0
 *   @0x312f62 subseq r0, r1, r1, asr r0
 *   @0x312f66 subseq r0, r1, pc, lsl #10
 *   @0x312f6a streq r0, [pc, #-0x51]
 *   @0x312f6e subseq r0, r1, pc, lsl #10
 *   @0x312f72 subseq r0, r1, pc, lsl #10
 *   @0x312f76 subseq r0, r1, r1, asr r0
 *   @0x312f7a subseq r0, r1, r1, asr r0
 *   @0x312f7e subseq r0, r1, pc, lsl #10
 *   @0x312f82 subseq r0, r1, r1, asr r0
 *   @0x312f86 subseq r0, r1, r1, asr r0
 *   @0x312f8a streq r0, [pc, #-0x50f]
 *   @0x312f8e eoreq r0, r5, pc, lsl #10
 *   @0x312f92 eorseq r0, lr, r12, lsr #32
 *   @0x312f96 .word 0xf8df004d
 *   @0x312f9a ldrbtmi r3, [r11], #-2616
 *   @0x312f9e movwvs pc, #0x503
 *   @0x312fa2 ands r9, r3, r0, lsl #6
 *   @0x312fa6 .word 0xf50d9d23
 *   @0x312faa .word 0xf50d517c
 *   @0x312fae qsub16mi r5, r0, r12
 *   @0x312fb2 movweq pc, #0xc605
 *   @0x312fb6 movwls r3, #0x104
 *   @0x312fba movwhs r3, #0x208
 *   @0x312fbe ldrbmi r9, [r3], -r1, lsl #6
 *   @0x312fc2 .word 0xf8f9f7fe
 *   @0x312fc6 ldcllt p0, c15, [r1], {0}
 *   @0x312fca strls r9, [r0, #-0xd22]
 *   @0x312fce .word 0xf50d2300
 *   @0x312fd2 .word 0xf50d517c
 *   @0x312fd6 movwls r5, #0x127c
 *   @0x312fda .word 0x31044620
 *   @0x312fde ldrbmi r3, [r3], -r8, lsl #4
 *   @0x312fe2 .word 0xf8e9f7fe
 *   @0x312fe6 stcls p5, c14, [r1, #-300]!
 *   @0x312fea strls r2, [r0, #-0x301]
 *   @0x312fee .word 0xf89be7ef
 *   @0x312ff2 blhs 0x31f01a
 *   @0x312ff6 ldrthi pc, [r9], #64
 *   @0x312ffa vadd.i8 d2, d0, d21
 *   @0x312ffe stmdalo r3, {r1, r2, r4, r5, r7, r10, pc}
 *   @0x313002 vtst.8 d2, d0, d11
 *   @0x313006 ldm pc, {r1, r4, r5, r7, r10, pc} ^
 *   @0x31300a andseq pc, r12, r0, lsl r0
 *   @0x31300e eorseq r0, r4, r6, lsr #32
 *   @0x313012 ldrteq r0, [r0], #1200
 *   @0x313016 ldrhteq r0, [r12], -r0
 *   @0x31301a subeq r0, sp, r4, asr #32
 *   @0x31301e ldrteq r0, [r0], #86
 *   @0x313022 rsbeq r0, r6, r1, rrx
 *   @0x313026 ldrteq r0, [r0], #1200
 *   @0x31302a ldrteq r0, [r0], #115
 *   @0x31302e addeq r0, r5, r7, ror r0
 *   @0x313032 umlaleq r0, r6, r2, r0
 *   @0x313036 ldrteq r0, [r0], #183
 *   @0x31303a sbcseq r0, r5, r2, asr #1
 *   @0x31303e .word 0x00eb00dc
 *   @0x313042 strtmi r0, [r0], -r5, lsl #2
 *   @0x313046 .word 0xf956f7fc
 *   @0x31304a strtmi r4, [r0], -r5, lsl #12
 *   @0x31304e .word 0xf952f7fc
 *   @0x313052 strmi r11, [r1], -r8, asr #18
 *   @0x313056 strtmi lr, [r0], -r9, asr #32
 *   @0x31305a .word 0xf94cf7fc
 *   @0x31305e strtmi r4, [r0], -r5, lsl #12
 *   @0x313062 .word 0xf948f7fc
 *   @0x313066 stcne p9, c11, [r9], #-96
 *   @0x31306a .word 0x2101bf18
 *   @0x31306e .word 0x2101e03d
 *   @0x313072 qasxmi lr, r0, r11
 *   @0x313076 rfedb lr!
 *   @0x31307a .word 0x0101f1d0
 *   @0x31307e .word 0x2100bf38
 *   @0x313082 qasxmi lr, r0, r3
 *   @0x313086 rfedb r6!
 *   @0x31308a mvnvc lr, r0, lsl #21
 *   @0x31308e mvnvc lr, r1, lsr #23
 *   @0x313092 .word 0x4620e0be
 *   @0x313096 .word 0xf92ef7fc
 *   @0x31309a strtmi r4, [r0], -r5, lsl #12
 *   @0x31309e .word 0xf92af7fc
 *   @0x3130a2 adcs r1, r5, r1, asr #18
 *   @0x3130a6 .word 0xf7fc4620
 *   @0x3130aa strmi pc, [r5], -r5, lsr #18
 *   @0x3130ae .word 0xf7fc4620
 *   @0x3130b2 blne 0x139153e <b2_toiTime+0xc3809a>
 *   @0x3130b6 strtmi lr, [r0], -r12, lsr #1
 *   @0x3130ba .word 0xf91cf7fc
 *   @0x3130be strtmi r4, [r0], -r5, lsl #12
 *   @0x3130c2 .word 0xf918f7fc
 *   @0x3130c6 .word 0xf7d14629
 *   @0x3130ca .word 0xe0a0fef5
 *   @0x3130ce .word 0xf7fc4620
 *   @0x3130d2 submi pc, r1, #278528
 *   @0x3130d6 qadd8mi lr, r0, r12
 *   @0x3130da .word 0xf90cf7fc
 *   @0x3130de strtmi r4, [r0], -r5, lsl #12
 *   @0x3130e2 .word 0xf908f7fc
 *   @0x3130e6 submi r1, r1, #64, #22
 *   @0x3130ea strtmi r4, [r0], -r1, asr #2
 *   @0x3130ee .word 0xbc1ef000
 *   @0x3130f2 .word 0xf7fc4620
 *   @0x3130f6 strb pc, [r2], #2303
 *   @0x3130fa .word 0xf7fc4620
 *   @0x3130fe strmi pc, [r5], -r3, ror #17
 *   @0x313102 .word 0xf7fc4620
 *   @0x313106 ldchs p8, c15, [pc, #-988]
 *   @0x31310a ldcge p6, c15, [r9], #252
 *   @0x31310e .word 0xf843ab3e
 *   @0x313112 ldrt r0, [r4], #37
 *   @0x313116 .word 0xf7fc4620
 *   @0x31311a ldmdahs pc, {r0, r2, r4, r6, r7, r11, r12, sp, lr, pc}
 *   @0x31311e .word 0xf63f4603
 *   @0x313122 ldcge p12, c10, [lr, #-696]!
 *   @0x313126 .word 0xf8554620
 *   @0x31312a .word 0xf0001023
 *   @0x31312e qadd16mi r11, r0, r10
 *   @0x313132 .word 0xf8e0f7fc
 *   @0x313136 strtmi r4, [r0], -r6, lsl #12
 *   @0x31313a .word 0xf8dcf7fc
 *   @0x31313e strtmi r4, [r0], -r7, lsl #12
 *   @0x313142 .word 0xf8d8f7fc
 *   @0x313146 strtmi r4, [r0], -r5, lsl #12
 *   @0x31314a .word 0xf8d4f7fc
 *   @0x31314e svclt #0xcc42b7
 *   @0x313152 strmi r4, [r1], -r9, lsr #12
 *   @0x313156 stcls p0, c14, [r9, #-368]
 *   @0x31315a .word 0xf8d54620
 *   @0x31315e .word 0xf8d332e0
 *   @0x313162 b 0xfe357b8a <b2_toiTime+0xfffffffffdbfe6e6>
 *   @0x313166 addlt r3, r9, #268435460
 *   @0x31316a b 0xfe39f576 <b2_toiTime+0xfffffffffdc460d2>
 *   @0x31316e b 0xfe3a3abe <b2_toiTime+0xfffffffffdc4a61a>
 *   @0x313172 .word 0xf8c31242
 *   @0x313176 .word 0xe3f42288
 *   @0x31317a .word 0xf7fc4620
 *   @0x31317e .word 0x4605f8bb
 *   @0x313182 .word 0xf7fc4620
 *   @0x313186 .word 0x4629f8b7
 *   @0x31318a mrc2 p7, #0x0, apsr_nzcv, c3, c10, #0x7
 *   @0x31318e qasxmi lr, r0, pc
 *   @0x313192 rfeia r0!
 *   @0x313196 stcle p14, c1, [r11, #-24]
 *   @0x31319a qasxmi r4, r9, r5
 *   @0x31319e .word 0xf7d14630
 *   @0x3131a2 strtmi pc, [r8], #-3721
 *   @0x3131a6 subne r1, r9, r1, asr #24
 *   @0x3131aa eorsle r4, r1, r9, lsr #5
 *   @0x3131ae ldrb r4, [r4, sp, lsl #12]!
 *   @0x3131b2 eor r2, sp, r0, lsl #2
 *   @0x3131b6 .word 0xf7fc4620
 *   @0x3131ba .word 0x4605f89d
 *   @0x3131be strtmi r4, [r9], -r0, lsr #12
 *   @0x3131c2 strtmi lr, [r0], -r9
 *   @0x3131c6 .word 0xf896f7fc
 *   @0x3131ca strtmi r4, [r0], -r6, lsl #12
 *   @0x3131ce .word 0xf892f7fc
 *   @0x3131d2 .word 0x46054631
 *   @0x3131d6 .word 0xf7fc4620
 *   @0x3131da qsaxmi pc, r0, pc
 *   @0x3131de bic r4, r0, #42991616
 *   @0x3131e2 .word 0xf7fc4620
 *   @0x3131e6 stmvs r1!, {r0, r1, r2, r3, r5, r6, r11, r12, sp, lr, pc} ^
 *   @0x3131ea bne 0xff56d47e <b2_toiTime+0xfffffffffee13fda>
 *   @0x3131ee .word 0xf43f10c9
 *   @0x3131f2 stmdahs r0, {r1, r2, r6, r10, r11, sp, pc}
 *   @0x3131f6 stmdblo r1, {r0, r9, r11, r12, lr, pc}
 *   @0x3131fa addmi lr, r8, #6
 *   @0x3131fe .word 0xf101bf3a
 *   @0x313202 bl 0xff31fa06 <b2_toiTime+0xfffffffffebc6562>
 *   @0x313206 .word 0x21000101
 *   @0x31320a .word 0xf7fc4620
 *   @0x31320e .word 0x4601f895
 *   @0x313212 .word 0xe3a64620
 *   @0x313216 .word 0xf7fc4620
 *   @0x31321a .word 0x4606f855
 *   @0x31321e .word 0xf7fc4620
 *   @0x313222 stmdahs r1, {r0, r4, r6, r11, r12, sp, lr, pc}
 *   @0x313226 .word 0xf77f4605
 *   @0x31322a stmvs r2!, {r1, r3, r5, r10, r11, sp, pc} ^
 *   @0x31322e bne 0xff7ed4c2 <b2_toiTime+0xffffffffff09401e>
 *   @0x313232 svceq #0xe3ebb0
 *   @0x313236 stmdavs r0!, {r2, r8, r11, r12, lr, pc} ^
 *   @0x31323a .word 0xf7fa2182
 *   @0x31323e ldr pc, [lr], #-3585
 *   @0x313242 ble 0x45ea4a <g_RomDisk+0x6722a>
 *   @0x313246 qsub16mi r4, r9, r0
 *   @0x31324a ldcl p0, c15, [r0, #20]
 *   @0x31324e and r4, r3, r9, asr #4
 *   @0x313252 qasxmi r4, r9, r0
 *   @0x313256 stcl p0, c15, [r10, #20]
 *   @0x31325a .word 0xf43f2900
 *   @0x31325e andhs r10, r0, r0, lsl r12
 *   @0x313262 .word 0x33fff04f
 *   @0x313266 strmi r2, [r7], -r2, lsl #12
 *   @0x31326a ldrmi r4, [lr, #0x69e]
 *   @0x31326e smlatble r7, r2, r8, r6
 *   @0x313272 movweq pc, #0x110e
 *   @0x313276 strbeq lr, [r3], r2, lsl #22
 *   @0x31327a eorseq pc, r3, r2, asr r8
 *   @0x31327e ldmdavs r6!, {r1, r2, r3, r4, r7, r9, r10, lr} ^
 *   @0x313282 adcmi r4, r11, #184549376
 *   @0x313286 blne 0x1a09e92 <b2_toiTime+0x12b09ee>
 *   @0x31328a blhs 0x34b29a
 *   @0x31328e ldmdbne r11, {r3, r4, r5, r7, r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x313292 bl 0x3a0e9e <af_latn_uniranges+0xea>
 *   @0x313296 adcmi r0, pc, #49920
 *   @0x31329a eorshi pc, r3, r2, asr r8
 *   @0x31329e .word 0x9004f8dc
 *   @0x3132a2 eorseq pc, r3, r2, asr #16
 *   @0x3132a6 andvs pc, r4, r12, asr #17
 *   @0x3132aa blge 0xffd903ae <b2_toiTime+0xffffffffff636f0a>
 *   @0x3132ae strbmi r4, [r0], -lr, asr #12
 *   @0x3132b2 stmvs r2!, {r0, r1, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x3132b6 bne 0xff7ed54a <b2_toiTime+0xffffffffff0940a6>
 *   @0x3132ba .word 0xf02310db
 *   @0x3132be blhs 0x353ed6
 *   @0x3132c2 .word 0xf89dd109
 *   @0x3132c6 ldmdblt r1!, {r0, r1, r4, r7, r12}
 *   @0x3132ca .word 0xf7fc4620
 *   @0x3132ce ldcls p8, c15, [r6, #-212]
 *   @0x3132d2 ldcls p4, c4, [r0, #-160]
 *   @0x3132d6 movwhs r6, #0x1028
 *   @0x3132da addslo pc, r3, sp, lsl #17
 *   @0x3132de ldrsbtlo pc, [r0], r11
 *   @0x3132e2 eorslo pc, r1, #9633792
 *   @0x3132e6 .word 0xf47f2b00
 *   @0x3132ea .word 0xf50aabd9
 *   @0x3132ee .word 0x7c1b5336
 *   @0x3132f2 uadd16mi r11, r0, r3
 *   @0x3132f6 mcr2 p7, #0x5, pc, c6, c13, #0x7
 *   @0x3132fa mullo r8, r11, r8
 *   @0x3132fe .word 0xf47f2b00
 *   @0x313302 stmvs r2!, {r0, r2, r3, r6, r7, r8, r9, r11, sp, pc} ^
 *   @0x313306 bne 0xff7ed59a <b2_toiTime+0xffffffffff0940f6>
 *   @0x31330a .word 0xf67f2b0f
 *   @0x31330e vldrls d10, [r11, #-796]
 *   @0x313312 .word 0xd1612d00
 *   @0x313316 cdpge p6, #0x6, c4, c6, c0, #0x1
 *   @0x31331a .word 0xffd4f7fb
 *   @0x31331e strtmi r4, [r0], -r5, lsl #12
 *   @0x313322 .word 0xffd0f7fb
 *   @0x313326 strtmi r4, [r0], -r7, lsl #12
 *   @0x31332a .word 0xffe4f7fb
 *   @0x31332e cmnpl r12, sp, lsl #10
 *   @0x313332 andvs r3, r8, r8, lsl #2
 *   @0x313336 .word 0xf7fb4620
 *   @0x31333a .word 0xf50dffdd
 *   @0x31333e andlo r5, r4, #124, #4
 *   @0x313342 andsvs r4, r0, r9, lsr #12
 *   @0x313346 stmdals r9, {r1, r2, r3, r4, r6, r9, r11, sp, pc}
 *   @0x31334a blx 0x1f91342 <b2_toiTime+0x1837e9e>
 *   @0x31334e stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x313352 tsthi r0, #64
 *   @0x313356 ldrbpl pc, [r12, #-0x50d]!
 *   @0x31335a cmnpl r12, sp, lsl #10
 *   @0x31335e .word 0xf04f3504
 *   @0x313362 .word 0xf8cd0901
 *   @0x313366 .word 0x31089000
 *   @0x31336a ldrbmi r6, [r8], -r11, lsr #16
 *   @0x31336e .word 0xf10d9a1a
 *   @0x313372 mrrcge p8, #0x9, r0, pc, c4
 *   @0x313376 stmdavs r11, {r0, r8, r9, r12, pc}
 *   @0x31337a .word 0xf8cda95e
 *   @0x31337e movwls r8, #0x200c
 *   @0x313382 .word 0xf7ff9b17
 *   @0x313386 stcls p9, c15, [r9, #-896]
 *   @0x31338a .word 0x3c1cf856
 *   @0x31338e .word 0xf8564621
 *   @0x313392 stmdavs r8!, {r3, r4, r10, r11, sp} ^
 *   @0x313396 .word 0xf7fd1ad2
 *   @0x31339a stmdals r9, {r2, r3, r5, r6, r9, r11, r12, sp, lr, pc}
 *   @0x31339e bge 0x1aa4c8a <b2_toiTime+0x134b7e6>
 *   @0x3133a2 blx 0x149139a <b2_toiTime+0xd37ef6>
 *   @0x3133a6 stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x3133aa rschi pc, r4, #64
 *   @0x3133ae uadd16mi r9, r8, r11
 *   @0x3133b2 blls 0x8f9c22 <b2_toiTime+0x1a077e>
 *   @0x3133b6 .word 0x91029101
 *   @0x3133ba .word 0xf8cda95e
 *   @0x3133be .word 0xf8cd9000
 *   @0x3133c2 .word 0xf7ff800c
 *   @0x3133c6 stmdbls r9, {r6, r7, r8, r11, r12, sp, lr, pc}
 *   @0x3133ca blls 0x1af9d52 <b2_toiTime+0x13a08ae>
 *   @0x3133ce strtmi r6, [r1], -r8, asr #16
 *   @0x3133d2 .word 0xf7fd1ad2
 *   @0x3133d6 sbc pc, sp, #319488
 *   @0x3133da sbc r2, r11, #75497472
 *   @0x3133de stmvs r3!, {r1, r5, r6, r7, r11, sp, lr}
 *   @0x3133e2 blhs 0x6d9f36 <g_SWFvertbuff+0x6e6e>
 *   @0x3133e6 .word 0xf50dd906
 *   @0x3133ea eorlo r5, r0, #-1610612729
 *   @0x3133ee blhs 0x331442
 *   @0x3133f2 adcshi pc, r11, #64
 *   @0x3133f6 .word 0xf10dad36
 *   @0x3133fa .word 0xf10b0393
 *   @0x3133fe movwls r0, #0xb0
 *   @0x313402 blls 0x724c8e <g_SWFvertbuff+0x51bc6>
 *   @0x313406 .word 0xf7fc462a
 *   @0x31340a .word 0xf8dbffde
 *   @0x31340e .word 0xf89330b0
 *   @0x313412 svchs #0x7231
 *   @0x313416 blge 0x13d061a <b2_toiTime+0xc77176>
 *   @0x31341a svceq #0x13f1b8
 *   @0x31341e stmdbvs r10!, {r0, r3, r8, r12, lr, pc} ^
 *   @0x313422 rsbspl pc, r10, sp, lsl #10
 *   @0x313426 andslo r9, r12, r3, lsr r11
 *   @0x31342a ldrmi r9, [r10], #-2311
 *   @0x31342e .word 0xf973f7fd
 *   @0x313432 shadd8mi lr, r9, r11
 *   @0x313436 .word 0xf640a85e
 *   @0x31343a .word 0xf50d721c
 *   @0x31343e .word 0xf5a3587a
 *   @0x313442 .word 0xf89be8b6
 *   @0x313446 bls 0x81f72e <b2_toiTime+0xc628a>
 *   @0x31344a ldmdaeq r8!, {r3, r8, r12, sp, lr, pc}
 *   @0x31344e .word 0xf8cd4639
 *   @0x313452 .word 0xf88db178
 *   @0x313456 strbmi r3, [r0], -r5, lsl #3
 *   @0x31345a .word 0xf50a9262
 *   @0x31345e andshs r5, r12, #-939524093
 *   @0x313462 .word 0xf50a935f
 *   @0x313466 tstlo r12, #-738197504
 *   @0x31346a .word 0xf5a39360
 *   @0x31346e blls 0x70d6f6 <g_SWFvertbuff+0x3a62e>
 *   @0x313472 cmnpl r10, sp, lsl #10
 *   @0x313476 bls 0xfeda36 <b2_toiTime+0x894592>
 *   @0x31347a .word 0x46403138
 *   @0x31347e ldrtmi r6, [r2], #-11
 *   @0x313482 .word 0xf7fd9907
 *   @0x313486 strls pc, [r0, -r8, asr #18]
 *   @0x31348a ldmdage lr, {r0, r8, r9, r10, r12, pc} ^
 *   @0x31348e strtmi r10, [r10], -lr, lsr #18
 *   @0x313492 .word 0xf7fd4643
 *   @0x313496 rsb pc, r8, #8, #20
 *   @0x31349a stmvs r3!, {r1, r5, r6, r7, r11, sp, lr}
 *   @0x31349e blhs 0x8d9ff2 <b2_toiTime+0x180b4e>
 *   @0x3134a2 .word 0xf89dd909
 *   @0x3134a6 ldmdblt r1!, {r0, r1, r4, r7, r12}
 *   @0x3134aa .word 0xf7fb4620
 *   @0x3134ae ldcls p15, c15, [r6, #-276]
 *   @0x3134b2 ldcls p4, c4, [r0, #-160]
 *   @0x3134b6 movwhs r6, #0x1028
 *   @0x3134ba addslo pc, r3, sp, lsl #17
 *   @0x3134be ldrsbtlo pc, [r0], r11
 *   @0x3134c2 eorslo pc, r1, #9633792
 *   @0x3134c6 .word 0xf47f2b00
 *   @0x3134ca .word 0xf50daae9
 *   @0x3134ce qsub16mi r5, r0, r12
 *   @0x3134d2 stmdavs sp, {r3, r8, r12, sp}
 *   @0x3134d6 .word 0xff0ef7fb
 *   @0x3134da rsbspl pc, r12, #54525952
 *   @0x3134de cmnpl r12, #54525952
 *   @0x3134e2 movwlo r3, #0x4208
 *   @0x3134e6 andsvs r4, r0, r8, lsr #8
 *   @0x3134ea ldmdavs sp, {r5, r9, r10, lr}
 *   @0x3134ee .word 0xff02f7fb
 *   @0x3134f2 .word 0xf50d1829
 *   @0x3134f6 strlo r5, [r4, #-0x57c]
 *   @0x3134fa eor r6, r4, r9, lsr #32
 *   @0x3134fe stmvs r3!, {r1, r5, r6, r7, r11, sp, lr}
 *   @0x313502 blhs 0x6da056 <g_SWFvertbuff+0x6f8e>
 *   @0x313506 .word 0xf89dd909
 *   @0x31350a ldmdblt r1!, {r0, r1, r4, r7, r12}
 *   @0x31350e .word 0xf7fb4620
 *   @0x313512 ldcls p15, c15, [r6, #-76]
 *   @0x313516 ldcls p4, c4, [r0, #-160]
 *   @0x31351a movwhs r6, #0x1028
 *   @0x31351e addslo pc, r3, sp, lsl #17
 *   @0x313522 ldrsbtlo pc, [r0], r11
 *   @0x313526 eorslo pc, r1, #9633792
 *   @0x31352a .word 0xf47f2b00
 *   @0x31352e .word 0xf50daab7
 *   @0x313532 qsub16mi r5, r0, r12
 *   @0x313536 stmdavs sp, {r2, r8, r12, sp}
 *   @0x31353a mrc2 p7, #0x6, apsr_nzcv, c12, c11, #0x7
 *   @0x31353e rsbspl pc, r12, #54525952
 *   @0x313542 stmdane r9!, {r2, r9, r12, sp}
 *   @0x313546 .word 0xf50d6011
 *   @0x31354a usub16mi r5, r0, r12
 *   @0x31354e ldmdavs r10, {r3, r8, r9, r12, sp}
 *   @0x313552 ldc2 p7, c15, [pc], {253}
 *   @0x313556 stmvs r6!, {r0, r3, r9, sp, lr, pc} ^
 *   @0x31355a stmvs r3!, {r8, r10, sp}
 *   @0x31355e ldrshtne r1, [r6], #166
 *   @0x313562 adcsmi r1, r3, #10944
 *   @0x313566 .word 0xf50dd222
 *   @0x31356a qsub16mi r5, r0, r12
 *   @0x31356e stmdavs pc, {r2, r8, r12, sp}
 *   @0x313572 .word 0xf7fb4629
 *   @0x313576 .word 0xf50dfee1
 *   @0x31357a andlo r5, r4, #124, #4
 *   @0x31357e cmnpl r12, #54525952
 *   @0x313582 stclne p3, c3, [r9], #-32
 *   @0x313586 ldrtmi r3, [r8], #-1282
 *   @0x31358a qadd16mi r6, r0, r0
 *   @0x31358e .word 0xf7fb681f
 *   @0x313592 .word 0xf50dfed3
 *   @0x313596 .word 0xf50d517c
 *   @0x31359a .word 0x3108537c
 *   @0x31359e ldmdane r10!, {r2, r8, r9, r12, sp}
 *   @0x3135a2 andvs r4, r10, r0, asr r6
 *   @0x3135a6 .word 0xf7fd6819
 *   @0x3135aa .word 0xe7d9fcd4
 *   @0x3135ae .word 0xf08042b5
 *   @0x3135b2 .word 0x462981dc
 *   @0x3135b6 .word 0xf7fb4620
 *   @0x3135ba .word 0xf50dfebf
 *   @0x3135be .word 0x3104517c
 *   @0x3135c2 stclne p8, c6, [r9], #-44
 *   @0x3135c6 strtmi r1, [r0], -r3, asr #17
 *   @0x3135ca .word 0xf7fb930c
 *   @0x3135ce .word 0xf50dfeb5
 *   @0x3135d2 stcne p2, c5, [r9], #496
 *   @0x3135d6 ldmdavs r3, {r3, r9, r12, sp}
 *   @0x3135da stmdbeq r3, {r8, r9, r11, sp, lr, pc}
 *   @0x3135de .word 0xf7fb4620
 *   @0x3135e2 .word 0xf8ddfeab
 *   @0x3135e6 stclne p0, c8, [r9], #192
 *   @0x3135ea strtmi r4, [r0], -r0, lsl #9
 *   @0x3135ee mcr2 p7, #0x5, pc, c4, c11, #0x7
 *   @0x3135f2 bl 0x31aa9e <__gnu_unwind_execute+0x362>
 *   @0x3135f6 strtmi r0, [r0], -r9, lsl #6
 *   @0x3135fa .word 0xf7fb9305
 *   @0x3135fe stclne p14, c15, [r9, #-628]!
 *   @0x313602 bl 0x320a22
 *   @0x313606 strtmi r0, [r0], -r8, lsl #14
 *   @0x31360a mrc2 p7, #0x4, apsr_nzcv, c6, c11, #0x7
 *   @0x31360e stmdbls r12, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x313612 bl 0x324f42
 *   @0x313616 ldrbmi r0, [r0], -r3, lsl #24
 *   @0x31361a addne lr, r8, sp, lsl #17
 *   @0x31361e .word 0xf8cd4643
 *   @0x313622 .word 0xf7fdc010
 *   @0x313626 .word 0xf50dfd32
 *   @0x31362a .word 0xf50d537c
 *   @0x31362e movwlo r5, #0x417c
 *   @0x313632 andsvs r3, pc, r8, lsl #2
 *   @0x313636 ldrsbgt pc, [r0], -sp
 *   @0x31363a andgt pc, r0, r1, asr #17
 *   @0x31363e stmvs r5!, {r1, r2, r4, r5, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x313642 bne 0xffe6d8d6 <b2_toiTime+0xffffffffff714432>
 *   @0x313646 .word 0xf02510ed
 *   @0x31364a blne 0xffe5525a <b2_toiTime+0xffffffffff6fbdb6>
 *   @0x31364e .word 0xf08042bd
 *   @0x313652 blne 0x21f3c8a <b2_toiTime+0x1a9a7e6>
 *   @0x313656 strle r0, [r11, #-0x7d9]
 *   @0x31365a strtmi r4, [r0], -r9, lsr #12
 *   @0x31365e mcr2 p7, #0x3, pc, c12, c11, #0x7
 *   @0x313662 rsbspl pc, r12, #54525952
 *   @0x313666 strlo r3, [r1, #-0x204]
 *   @0x31366a bl 0x32d6be
 *   @0x31366e and r0, r4, r3, lsl #18
 *   @0x313672 cmnpl r12, #54525952
 *   @0x313676 .word 0xf8d33304
 *   @0x31367a strtmi r9, [r9], -r0
 *   @0x31367e .word 0xf7fb4620
 *   @0x313682 .word 0xf50dfe5b
 *   @0x313686 .word 0x3108517c
 *   @0x31368a stclne p8, c6, [r9], #-44
 *   @0x31368e stmdaeq r3, {r8, r9, r11, sp, lr, pc}
 *   @0x313692 .word 0xf7fb4620
 *   @0x313696 stcne p14, c15, [r9], #324
 *   @0x31369a streq lr, [r9], -r0, lsl #22
 *   @0x31369e .word 0xf7fb4620
 *   @0x3136a2 stclne p14, c15, [r9], #300
 *   @0x3136a6 bl 0x320abe
 *   @0x3136aa strtmi r0, [r0], -r8, lsl #6
 *   @0x3136ae .word 0xf7fb9305
 *   @0x3136b2 blls 0x492fc6 <g_prim_v+0x2fba>
 *   @0x3136b6 strbmi r4, [r9], -r2, asr #12
 *   @0x3136ba .word 0x0c03eb00
 *   @0x3136be stm sp, {r4, r6, r9, r10, lr}
 *   @0x3136c2 ldrtmi r1, [r3], -r8, asr #32
 *   @0x3136c6 andsgt pc, r0, sp, asr #17
 *   @0x3136ca ldc2l p7, c15, [pc], {253}
 *   @0x3136ce rsbspl pc, r12, #54525952
 *   @0x3136d2 cmnpl r12, #54525952
 *   @0x3136d6 movwlo r3, #0x8204
 *   @0x3136da .word 0xf8dd6016
 *   @0x3136de .word 0xf8c3c010
 *   @0x3136e2 ldr r12, [r3, r0]!
 *   @0x3136e6 stmvs r3!, {r0, r2, r5, r6, r7, r11, sp, lr}
 *   @0x3136ea rscne r1, sp, sp, ror #21
 *   @0x3136ee streq pc, [r2, -r5, lsr #32]
 *   @0x3136f2 adcsmi r1, sp, #242688
 *   @0x3136f6 teqhi r9, r0, lsl #1
 *   @0x3136fa .word 0x07da1b7b
 *   @0x3136fe strtmi sp, [r9], -r11, lsl #10
 *   @0x313702 .word 0xf7fb4620
 *   @0x313706 .word 0xf50dfe19
 *   @0x31370a .word 0x3108517c
 *   @0x31370e stmdavs r11, {r0, r8, r10, r12, sp}
 *   @0x313712 stmdbeq r3, {r8, r9, r11, sp, lr, pc}
 *   @0x313716 .word 0xf50de004
 *   @0x31371a andlo r5, r8, #124, #4
 *   @0x31371e .word 0x9000f8d2
 *   @0x313722 strtmi r4, [r0], -r9, lsr #12
 *   @0x313726 mcr2 p7, #0x0, pc, c8, c11, #0x7
 *   @0x31372a cmnpl r12, sp, lsl #10
 *   @0x31372e stmdavs r11, {r2, r8, r12, sp}
 *   @0x313732 bl 0x31a8de <__gnu_unwind_execute+0x1a2>
 *   @0x313736 strtmi r0, [r0], -r3, lsl #16
 *   @0x31373a ldc2l p7, c15, [lr, #1004]!
 *   @0x31373e bl 0x31a9ea <__gnu_unwind_execute+0x2ae>
 *   @0x313742 strtmi r0, [r0], -r8, lsl #6
 *   @0x313746 .word 0xf7fb9305
 *   @0x31374a stclne p13, c15, [r9], #988
 *   @0x31374e bl 0x320b66
 *   @0x313752 strtmi r0, [r0], -r9, lsl #12
 *   @0x313756 ldc2l p7, c15, [r0, #1004]!
 *   @0x31375a strbmi r9, [r10], -r5, lsl #22
 *   @0x31375e strbmi r9, [r1], -r2, lsl #12
 *   @0x313762 .word 0x0c03eb00
 *   @0x313766 stm sp, {r4, r6, r9, r10, lr}
 *   @0x31376a .word 0xf8cd1040
 *   @0x31376e .word 0xf7fdc010
 *   @0x313772 .word 0xf8ddfc8c
 *   @0x313776 .word 0xf50dc010
 *   @0x31377a .word 0xf50d527c
 *   @0x31377e andlo r5, r4, #124, #6
 *   @0x313782 .word 0xf8c23308
 *   @0x313786 andsvs r12, lr, r0
 *   @0x31378a stmvs r3!, {r0, r1, r4, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x31378e bne 0xffe6db2a <b2_toiTime+0xffffffffff714686>
 *   @0x313792 tsteq pc, #184, #2
 *   @0x313796 stmdaeq r0, {r0, r1, r4, r6, r7, r8, r12, sp, lr, pc}
 *   @0x31379a strbeq lr, [r5, #0xa4f]!
 *   @0x31379e stmdaeq r3, {r3, r4, r6, r8, r9, r11, sp, lr, pc}
 *   @0x3137a2 .word 0x0102f025
 *   @0x3137a6 bne 0x1e77c0e <b2_toiTime+0x171e76a>
 *   @0x3137aa addmi r9, sp, #24, #18
 *   @0x3137ae sbcshi pc, sp, r0, lsl #1
 *   @0x3137b2 vstmiane r10!, {d25, d26, d27, d28, d29, d30, d31}
 *   @0x3137b6 stmdbeq r1, {r0, r2, r8, r12, sp, lr, pc}
 *   @0x3137ba blne 0x19f7ffa <b2_toiTime+0x129eb56>
 *   @0x3137be stcne p13, c1, [pc], #168
 *   @0x3137c2 andsls r9, pc, #2013265920
 *   @0x3137c6 svceq #0xf1b8
 *   @0x3137ca strtmi sp, [r9], -r11, lsr #32
 *   @0x3137ce .word 0xf7fb4620
 *   @0x3137d2 .word 0xf50dfdb3
 *   @0x3137d6 .word 0xf50d517c
 *   @0x3137da .word 0x3104527c
 *   @0x3137de stmdavs r11, {r3, r9, r12, sp}
 *   @0x3137e2 ldmdavs r2, {r0, r3, r6, r9, r10, lr}
 *   @0x3137e6 stmne r3, {r0, r2, r3, r9, r12, pc} ^
 *   @0x3137ea movwls r4, #0xc620
 *   @0x3137ee stc2 p7, c15, [r4, #1004]!
 *   @0x3137f2 ldrtmi r9, [r9], -r12, lsl #28
 *   @0x3137f6 strtmi r4, [r0], -r6, lsl #8
 *   @0x3137fa ldc2 p7, c15, [lr, #1004]
 *   @0x3137fe stmdbls lr, {r0, r2, r3, r8, r9, r10, r11, r12, pc}
 *   @0x313802 strtmi r4, [r0], -r7, lsl #8
 *   @0x313806 ldc2 p7, c15, [r8, #1004]
 *   @0x31380a blhs 0x47a48a <_ZN2VM13m_breakpointsE+0x256>
 *   @0x31380e andls r4, lr, r8, lsr r4
 *   @0x313812 qasxmi sp, r0, r9
 *   @0x313816 .word 0xf7fb991f
 *   @0x31381a strbmi pc, [sp], -pc, lsl #27
 *   @0x31381e .word 0x0c06eb00
 *   @0x313822 .word 0xf50de032
 *   @0x313826 qsub16mi r5, r9, r12
 *   @0x31382a strtmi r3, [r0], -r4, lsl #4
 *   @0x31382e andls r6, r12, #1179648
 *   @0x313832 stc2 p7, c15, [r2, #1004]
 *   @0x313836 cmnpl r12, sp, lsl #10
 *   @0x31383a stmdavs r11, {r3, r8, r12, sp}
 *   @0x31383e stmne r3, {r0, r3, r6, r9, r10, lr} ^
 *   @0x313842 movwls r4, #0xd620
 *   @0x313846 ldc2l p7, c15, [r8, #-1004]!
 *   @0x31384a ldrtmi r9, [r9], -r12, lsl #28
 *   @0x31384e strtmi r4, [r0], -r6, lsl #8
 *   @0x313852 ldc2l p7, c15, [r2, #-1004]!
 *   @0x313856 stmdbls lr, {r0, r2, r3, r8, r9, r10, r11, r12, pc}
 *   @0x31385a strtmi r4, [r0], -r7, lsl #8
 *   @0x31385e stc2l p7, c15, [r12, #-1004]!
 *   @0x313862 bhs 0x47a0e2 <szLine+0x3ce>
 *   @0x313866 .word 0x0c06eb00
 *   @0x31386a qadd16mi sp, r0, r1
 *   @0x31386e .word 0xf8cd991f
 *   @0x313872 .word 0xf7fbc010
 *   @0x313876 strbmi pc, [sp], -r1, ror #26
 *   @0x31387a stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x31387e ldrsbgt pc, [r0], -sp
 *   @0x313882 andls r4, lr, r8, lsr r4
 *   @0x313886 ldrtmi lr, [r4], r6
 *   @0x31388a stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x31388e .word 0xf04fe002
 *   @0x313892 strls r0, [lr, -r1, lsl #16]
 *   @0x313896 ldrbmi r9, [r0], -lr, lsl #22
 *   @0x31389a addne lr, r0, sp, lsl #17
 *   @0x31389e stmdbls r12, {r2, r8, r10, r12, sp}
 *   @0x3138a2 ldrtmi r9, [r3], -r2, lsl #6
 *   @0x3138a6 .word 0xf8cd9a0d
 *   @0x3138aa .word 0xf7fdc010
 *   @0x3138ae .word 0xf8ddfbee
 *   @0x3138b2 .word 0xf50dc010
 *   @0x3138b6 .word 0xf50d517c
 *   @0x3138ba bls 0x6a86b2 <g_SWFlinevertbuff+0x555ea>
 *   @0x3138be movwlo r3, #0x8104
 *   @0x3138c2 andgt pc, r0, r1, asr #17
 *   @0x3138c6 .word 0xe76f601a
 *   @0x3138ca .word 0xf7fb9807
 *   @0x3138ce strmi pc, [r5], -r0, asr #25
 *   @0x3138d2 .word 0xf7fb9807
 *   @0x3138d6 b 0x1352bce <b2_toiTime+0xbf972a>
 *   @0x3138da strtmi r2, [r0], -r5, lsl #2
 *   @0x3138de eor r11, r5, r9, lsl #4
 *   @0x3138e2 svceq #0xf6f1b8
 *   @0x3138e6 strtmi sp, [r0], -r3, lsl #16
 *   @0x3138ea orreq pc, r11, r8, lsr #3
 *   @0x3138ee .word 0xf1b8e01e
 *   @0x3138f2 stmdale r11, {r1, r3, r4, r5, r6, r7, r8, r9, r10, r11}
 *   @0x3138f6 .word 0xf1a89807
 *   @0x3138fa .word 0xf7fb08f7
 *   @0x3138fe b 0x1712ba6 <b2_toiTime+0xfb9702>
 *   @0x313902 bl 0x51d92a <SrcVerts+0x7a96e>
 *   @0x313906 strtmi r0, [r0], -r0, lsl #2
 *   @0x31390a and r3, pc, r12, ror #2
 *   @0x31390e svceq #0xfff1b8
 *   @0x313912 stmdals r7, {r4, r12, lr, pc}
 *   @0x313916 ldmeq r11!, {r3, r5, r7, r8, r12, sp, lr, pc} ^
 *   @0x31391a ldc2 p7, c15, [r9], {251}
 *   @0x31391e .word 0x016bf06f
 *   @0x313922 stmdahs r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x313926 strtmi r4, [r0], -r0, lsl #9
 *   @0x31392a smlabteq r1, r8, r11, lr
 *   @0x31392e ldc2 p7, c15, [lr], {251}
 *   @0x313932 stmlt r5!, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc}
 *   @0x313936 .word 0xf7fb9807
 *   @0x31393a strmi pc, [r6], -r10, lsl #25
 *   @0x31393e .word 0xf7fb9807
 *   @0x313942 strmi pc, [r7], -r6, lsl #25
 *   @0x313946 .word 0xf7fb9807
 *   @0x31394a ldrteq pc, [pc], #-3202
 *   @0x31394e strvs lr, [r6], -r7, asr #20
 *   @0x313952 stmdals r7, {r0, r2, r9, r10, lr}
 *   @0x313956 ldc2l p7, c15, [r11], #-1004
 *   @0x31395a .word 0x0100ea46
 *   @0x31395e b 0x13651e6 <b2_toiTime+0xc0bd42>
 *   @0x313962 .word 0xf7fb2105
 *   @0x313966 .word 0xf7fffc99
 *   @0x31396a stmvs r3!, {r1, r3, r7, r11, r12, sp, pc}
 *   @0x31396e .word 0xf7ff60e3
 *   @0x313972 strbhs r11, [r0, #-0x886]
 *   @0x313976 stmdals pc, {r0, r3, r5, r9, r10, lr}
 *   @0x31397a blx 0x1bd196a <b2_toiTime+0x14784c6>
 *   @0x31397e eorspl pc, r5, r10, lsl #10
 *   @0x313982 .word 0xf7fa301c
 *   @0x313986 ldmdage r6!, {r1, r2, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x31398a blx 0xff41197c <b2_toiTime+0xfffffffffecb84d8>
 *   @0x31398e .word 0xf7faa82e
 *   @0x313992 stmdage r6!, {r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x313996 blx 0xff291988 <b2_toiTime+0xfffffffffeb384e4>
 *   @0x31399a cmplt r5, r2, lsl sp
 *   @0x31399e stmvs r9!, {r2, r3, r5, r11, sp, lr}
 *   @0x3139a2 .word 0xf7d34620
 *   @0x3139a6 movwhs pc, #0xcc7
 *   @0x3139aa adcvs r4, r11, r0, lsr #12
 *   @0x3139ae .word 0xf7d39912
 *   @0x3139b2 .word 0xf50dfcc1
 *   @0x3139b6 stcls p1, c5, [r0, #-492]!
 *   @0x3139ba stmdavs r10, {r2, r4, r8, r12, sp}
 *   @0x3139be addsmi r6, r10, #2818048
 *   @0x3139c2 .word 0xf5a2d001
 *   @0x3139c6 .word 0xf50dee06
 *   @0x3139ca andlt r5, r7, r11, ror sp
 *   @0x3139ce svchi #0xf0e8bd
 *   @0x3139d2 ldmdaeq r12!, {r8, r9, r10, r11, r12, sp, pc} ^
 *   @0x3139d6 push {r0, r3}
 *   @0x3139da ldrshlt r4, [r11], r0
 *   @0x3139de strmi r2, [r5], -r0, lsl #6
 *   @0x3139e2 strmi r9, [pc], -r10, lsl #6
 *   @0x3139e6 ldrmi r6, [r1], r3, asr #25
 *   @0x3139ea .word 0xf8d36806
 *   @0x3139ee bllt 0x2026a66 <b2_toiTime+0x18cd5c2>
 *   @0x3139f2 .word 0x27c0f8df
 *   @0x3139f6 .word 0x7109f44f
 *   @0x3139fa .word 0xf8c3447a
 *   @0x3139fe bge 0x59ea86 <g_SWFlineaavertbuff+0x4b9be>
 *   @0x313a02 ldrtmi r6, [r0], -r4, asr #25
 *   @0x313a06 blx 0xfe6d195c <b2_toiTime+0xfffffffffdf784b8>
 *   @0x313a0a .word 0xf8c4990a
 *   @0x313a0e stmdbhs r0, {r2, r3, r4, r10, r11}
 *   @0x313a12 bichi pc, r1, #64
 *   @0x313a16 eorhs r6, r0, #60160
 *   @0x313a1a .word 0x4c1cf8d3
 *   @0x313a1e .word 0xf8404620
 *   @0x313a22 .word 0xf5a26b90
 *   @0x313a26 stcne p13, c14, [r3, #-784]!
 *   @0x313a2a adclo pc, r8, r4, asr #17
 *   @0x313a2e .word 0x3788f8df
 *   @0x313a32 adcvs pc, r4, r4, asr #17
 *   @0x313a36 .word 0xf8c4447b
 *   @0x313a3a .word 0xf8df3090
 *   @0x313a3e ldrbtmi r3, [r11], #-1916
 *   @0x313a42 addslo pc, r4, r4, asr #17
 *   @0x313a46 .word 0x3778f8df
 *   @0x313a4a .word 0xf8c4447b
 *   @0x313a4e .word 0xf8c4309c
 *   @0x313a52 strhhs r5, [r0, -r0]
 *   @0x313a56 adcpl pc, r12, r4, asr #17
 *   @0x313a5a .word 0xf8d52210
 *   @0x313a5e .word 0xf8d88004
 *   @0x313a62 .word 0xf8d83080
 *   @0x313a66 .word 0xf8936060
 *   @0x313a6a blge 0x73fb52 <g_SWFvertbuff+0x6ca8a>
 *   @0x313a6e mlage r0, r6, r8, pc
 *   @0x313a72 movwls r4, #0x6618
 *   @0x313a76 ldc p5, c15, [r12, #648]
 *   @0x313a7a .word 0x97119713
 *   @0x313a7e .word 0xf10d444f
 *   @0x313a82 andshs r0, r8, #80, #18
 *   @0x313a86 ldrls r2, [r2, -r0, lsl #2]
 *   @0x313a8a .word 0xf5a24648
 *   @0x313a8e stmvs r11!, {r4, r7, r8, r10, r11, sp, lr, pc}
 *   @0x313a92 umlalhs pc, r0, r3, r8
 *   @0x313a96 umlaleq pc, r1, r3, r8
 *   @0x313a9a .word 0xf8d3b192
 *   @0x313a9e .word 0xf8d310a4
 *   @0x313aa2 .word 0xf11130a8
 *   @0x313aa6 svclt #0x480720
 *   @0x313aaa ldrbeq pc, [pc, -r1, lsl #2]
 *   @0x313aae .word 0x0120f113
 *   @0x313ab2 .word 0xf103bf48
 *   @0x313ab6 .word 0x11bf015f
 *   @0x313aba orrne r9, r9, r4, lsl r7
 *   @0x313abe and r9, r3, r7, lsl r1
 *   @0x313ac2 orrvs pc, r0, #1325400064
 *   @0x313ac6 tstls r7, #20, #6
 *   @0x313aca adcslo pc, r4, #152, #16
 *   @0x313ace stmdblt r10, {r0, r1, r5, r9, r12, sp, lr}
 *   @0x313ad2 and r6, r1, r2, ror #1
 *   @0x313ad6 rscvs r2, r3, r1, lsl #6
 *   @0x313ada .word 0xf1bbb160
 *   @0x313ade andle r0, r5, r0, lsl #30
 *   @0x313ae2 svceq #0x80f01b
 *   @0x313ae6 .word 0xf1bad006
 *   @0x313aea .word 0xd1030f00
 *   @0x313aee .word 0xf04368e3
 *   @0x313af2 rscvs r0, r3, r2, lsl #6
 *   @0x313af6 .word 0xf8c46a73
 *   @0x313afa bvs 0xfefdfdf2 <b2_toiTime+0xfffffffffe88694e>
 *   @0x313afe sbclo pc, r0, r4, asr #17
 *   @0x313b02 .word 0xf8c46af3
 *   @0x313b06 blvs 0xfdfe1e <b2_toiTime+0x88697a>
 *   @0x313b0a sbclo pc, r8, r4, asr #17
 *   @0x313b0e .word 0xf8c46b73
 *   @0x313b12 blvs 0xfefdfe4a <b2_toiTime+0xfffffffffe8869a6>
 *   @0x313b16 sbcslo pc, r0, r4, asr #17
 *   @0x313b1a .word 0xf8c46bf3
 *   @0x313b1e ldcvs p0, c3, [r3], #-848
 *   @0x313b22 sbcslo pc, r8, r4, asr #17
 *   @0x313b26 rfeia r3!
 *   @0x313b2a .word 0xf8c41044
 *   @0x313b2e stmiblt r0, {r2, r7, r12} ^
 *   @0x313b32 strhs r9, [r0, #-0xb18]
 *   @0x313b36 ldrsbtvc pc, [r0], r4
 *   @0x313b3a movwls r9, #0xe50b
 *   @0x313b3e .word 0xf8d49b19
 *   @0x313b42 .word 0xf8d48088
 *   @0x313b46 movwls r10, #0xf08c
 *   @0x313b4a .word 0xf8d76065
 *   @0x313b4e .word 0xf8d462e0
 *   @0x313b52 strls r3, [r12, #-0xb4]
 *   @0x313b56 strls r4, [sp, #-0x2b3]
 *   @0x313b5a .word 0xf8c4d01a
 *   @0x313b5e strhs r6, [r1, #-0xb4]
 *   @0x313b62 mrcls p0, #0x0, lr, c4, c6, #0x0
 *   @0x313b66 vcge.f32 d18, d0, d0
 *   @0x313b6a ldcls p3, c8, [r7, #-124]
 *   @0x313b6e vpadd.f32 d18, d0, d0
 *   @0x313b72 .word 0xf5b1831b
 *   @0x313b76 blle 0x36777e <_ZTS12CDS_Priority+0x97d6>
 *   @0x313b7a tst r6, #164
 *   @0x313b7e rscsvs pc, r10, pc, asr #32
 *   @0x313b82 .word 0xf7d10409
 *   @0x313b86 addmi pc, r6, #2473984
 *   @0x313b8a addmi sp, r5, #62976
 *   @0x313b8e .word 0xe7cfdcf4
 *   @0x313b92 .word 0xf8d36cfb
 *   @0x313b96 blhs 0x322c2e
 *   @0x313b9a andhs sp, r0, #48
 *   @0x313b9e ldmdavs r8!, {r9, r12, pc} ^
 *   @0x313ba2 blge 0x67dfda <g_SWFlinevertbuff+0x2af12>
 *   @0x313ba6 .word 0xf8f6f7fa
 *   @0x313baa stmdahs r0, {r5, r6, sp, lr}
 *   @0x313bae adcshi pc, r2, #64
 *   @0x313bb2 ldrsbtgt pc, [r0], -sp
 *   @0x313bb6 andvc pc, r11, r6, lsl #10
 *   @0x313bba ldrsbtlt pc, [r4], -sp
 *   @0x313bbe eorne pc, r4, #14024704
 *   @0x313bc2 .word 0xf8cd4662
 *   @0x313bc6 uadd16mi r12, r11, r0
 *   @0x313bca .word 0xf874f7fc
 *   @0x313bce ldrsbgt pc, [r0], -sp
 *   @0x313bd2 ldclvs p1, c11, [r8], #192
 *   @0x313bd6 uqasxmi r4, r2, r1
 *   @0x313bda .word 0xf7fc465b
 *   @0x313bde strhs pc, [r1, #-0xb3a]
 *   @0x313be2 eorslo pc, r0, #14024704
 *   @0x313be6 movwhs r6, #0x623
 *   @0x313bea subslo pc, sp, r4, lsl #17
 *   @0x313bee eorlo pc, r4, #14024704
 *   @0x313bf2 blls 0x62da86 <g_SWFaavertbuff+0x5a9be>
 *   @0x313bf6 blls 0x66db8a <g_SWFlinevertbuff+0x1aac2>
 *   @0x313bfa addlo pc, r0, r4, asr #17
 *   @0x313bfe .word 0xf104687b
 *   @0x313c02 .word 0xf8d40610
 *   @0x313c06 strbmi r12, [r8], -r12
 *   @0x313c0a ldrtmi r6, [r1], -r2, lsr #27
 *   @0x313c0e blx 0x1aef282 <b2_toiTime+0x1395dde>
 *   @0x313c12 ldmibhi r11, {r2, r3, r7, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x313c16 addsmi r0, r10, #452984832
 *   @0x313c1a andseq pc, r0, #79
 *   @0x313c1e strvs r11, [r3, #0xf18]!
 *   @0x313c22 movweq pc, #0x100b
 *   @0x313c26 adcslo pc, r8, r4, lsl #17
 *   @0x313c2a strhs r11, [r1, #-0xf18]
 *   @0x313c2e andsgt pc, r0, sp, asr #17
 *   @0x313c32 stmda r6, {r0, r1, r5, r7, r8, r10, r12, sp, lr, pc}
 *   @0x313c36 ldrsbgt pc, [r0], -sp
 *   @0x313c3a .word 0x464db1f0
 *   @0x313c3e cdpeq p0, #0x0, c15, c0, c15, #0x2
 *   @0x313c42 strgt r12, [pc], -pc, lsl #26
 *   @0x313c46 muleq r3, r5, r8
 *   @0x313c4a andeq lr, r3, r6, lsl #17
 *   @0x313c4e strteq pc, [r8], -r4, lsl #2
 *   @0x313c52 strheq lr, [pc], -r9
 *   @0x313c56 eor pc, r4, r4, asr #17
 *   @0x313c5a eor pc, r0, r4, asr #17
 *   @0x313c5e vst1.8 {d28, d29, d30}, [pc]
 *   @0x313c62 ldm r5, {r7, r8, r9, r12, sp}
 *   @0x313c66 strhs r0, [r1, #-0x3]
 *   @0x313c6a andeq lr, r3, r6, lsl #17
 *   @0x313c6e strtvs r6, [r3], #-1251
 *   @0x313c72 sub pc, r8, r4, asr #17
 *   @0x313c76 sub pc, r4, r4, asr #17
 *   @0x313c7a umlalslo pc, r10, r4, r8
 *   @0x313c7e .word 0x0c02f00c
 *   @0x313c82 andle r4, r4, r3, ror #10
 *   @0x313c86 bleq 0x3cfcba <error_g0017+0x2895e>
 *   @0x313c8a adcslt pc, r10, r4, lsl #17
 *   @0x313c8e stchs p0, c14, [r0, #-8]
 *   @0x313c92 subhi pc, r0, #0
 *   @0x313c96 .word 0x6084f8d4
 *   @0x313c9a rsbsvc pc, r10, pc, asr #32
 *   @0x313c9e cdphs p13, #0x0, c6, c0, c3, #0x5
 *   @0x313ca2 .word 0xf44fbf08
 *   @0x313ca6 .word 0xf5b3767a
 *   @0x313caa svclt #0xac2f80
 *   @0x313cae vst1.32 {d20, d21, d22}, [pc:64], r9
 *   @0x313cb2 ldrtmi r2, [r1], -r0, lsl #19
 *   @0x313cb6 stmda r12!, {r0, r2, r12, sp, lr, pc}
 *   @0x313cba rsclo pc, r0, #14090240
 *   @0x313cbe ldrsblo pc, [r0, r3]
 *   @0x313cc2 .word 0xf8c4041b
 *   @0x313cc6 blhs 0x32003e
 *   @0x313cca .word 0xdc064605
 *   @0x313cce addseq pc, r6, pc, asr #8
 *   @0x313cd2 .word 0xf7d14629
 *   @0x313cd6 .word 0xf8c4f8ef
 *   @0x313cda .word 0xf1b800dc
 *   @0x313cde ldcle p15, c0, [r12, #-0]
 *   @0x313ce2 .word 0x46490436
 *   @0x313ce6 .word 0xf7d14630
 *   @0x313cea strmi pc, [r0, #0x8e5]
 *   @0x313cee ldrtmi sp, [r0], -r4, lsl #24
 *   @0x313cf2 .word 0xf7d14649
 *   @0x313cf6 pkhtbmi pc, r0, pc, asr #17
 *   @0x313cfa .word 0xf8c42300
 *   @0x313cfe .word 0xf1b830e4
 *   @0x313d02 eorle r0, r1, r0, lsl #30
 *   @0x313d06 orrhs pc, lr, #64, #4
 *   @0x313d0a ldcle p2, c4, [sp, #-628]
 *   @0x313d0e ldmvc r8, {r3, r8, r9, r11, sp, lr, pc} ^
 *   @0x313d12 .word 0x0368ea4f
 *   @0x313d16 rsclo pc, r4, r4, asr #17
 *   @0x313d1a .word 0xf894e016
 *   @0x313d1e strhhs r3, [r0, -r10]
 *   @0x313d22 ldrsbhs pc, [r12], #132
 *   @0x313d26 rscne pc, r4, r4, asr #17
 *   @0x313d2a .word 0xf240b173
 *   @0x313d2e addmi r2, r5, #142
 *   @0x313d32 stm sp, {r1, r3, r8, r10, r11, r12, lr, pc}
 *   @0x313d36 strtmi r0, [r8], -r10
 *   @0x313d3a .word 0x03bcf104
 *   @0x313d3e movwls r4, #0x2649
 *   @0x313d42 .word 0x03e4f104
 *   @0x313d46 .word 0xf8c5f7fc
 *   @0x313d4a rsclo pc, r0, #14090240
 *   @0x313d4e .word 0x318cf8d3
 *   @0x313d52 bhs 0x314dc2 <FT_GlyphSlot_Own_Bitmap+0x2>
 *   @0x313d56 .word 0xf8d4dd07
 *   @0x313d5a bl 0xfef9c0d2 <b2_toiTime+0xfffffffffe842c2e>
 *   @0x313d5e stcle p15, c4, [r2, #-268]
 *   @0x313d62 addseq pc, r6, pc, asr #8
 *   @0x313d66 vst4.8 {d30, d31, d0, d1}, [pc], r1
 *   @0x313d6a .word 0x462900dc
 *   @0x313d6e .word 0xf8a2f7d1
 *   @0x313d72 .word 0xf8942100
 *   @0x313d76 .word 0xf8c430ba
 *   @0x313d7a .word 0xf8c410e8
 *   @0x313d7e .word 0xf8d400e0
 *   @0x313d82 .word 0xf1ba20e0
 *   @0x313d86 .word 0xd1000f00
 *   @0x313d8a .word 0xf240b17b
 *   @0x313d8e addmi r2, sp, #-2147483613
 *   @0x313d92 movwls sp, #0x1d0b
 *   @0x313d96 .word 0xf1044628
 *   @0x313d9a .word 0xf8cd03bc
 *   @0x313d9e movwls r10, #0x2000
 *   @0x313da2 .word 0xf1044649
 *   @0x313da6 .word 0xf7fc03e8
 *   @0x313daa .word 0xf8d4f894
 *   @0x313dae ldmdblt r3, {r2, r5, r6, r7, r12, sp}
 *   @0x313db2 .word 0x30e8f8d4
 *   @0x313db6 movwhs r11, #0x1103
 *   @0x313dba .word 0xf8842100
 *   @0x313dbe .word 0xf88430b9
 *   @0x313dc2 .word 0xf44f10ec
 *   @0x313dc6 .word 0xf104729a
 *   @0x313dca .word 0xf8d400f0
 *   @0x313dce .word 0xf5a250b0
 *   @0x313dd2 blvs 0x1c0ed92 <b2_toiTime+0x14b58ee>
 *   @0x313dd6 cmnvc r10, pc, asr #32
 *   @0x313dda rscslo pc, r0, r4, asr #17
 *   @0x313dde rsclo pc, r0, #13959168
 *   @0x313de2 .word 0x0180f8d3
 *   @0x313de6 .word 0xf866f7d1
 *   @0x313dea rscseq pc, r12, r4, asr #17
 *   @0x313dee rsclo pc, r0, #13959168
 *   @0x313df2 .word 0x3184f8d3
 *   @0x313df6 .word 0xf8c4041b
 *   @0x313dfa .word 0xf8d53100
 *   @0x313dfe .word 0xf8d332e0
 *   @0x313e02 ldreq r3, [r11], #-392
 *   @0x313e06 smlabtlo r4, r4, r8, pc
 *   @0x313e0a rscpl pc, r0, #13959168
 *   @0x313e0e biceq pc, r0, r5, lsl #2
 *   @0x313e12 ldmibeq r8!, {r0, r2, r8, r12, sp, lr, pc} ^
 *   @0x313e16 umlalslo pc, lr, r5, r8
 *   @0x313e1a umlalsvc pc, sp, r5, r8
 *   @0x313e1e umlalseq pc, r12, r5, r8
 *   @0x313e22 .word 0xf8959305
 *   @0x313e26 .word 0x970730bf
 *   @0x313e2a ldrvc pc, [r0, r5, lsl #10]
 *   @0x313e2e movwls r9, #0x9708
 *   @0x313e32 andlo pc, r12, #13959168
 *   @0x313e36 .word 0xd1022b01
 *   @0x313e3a stmdahs r4, {r3, r4, r5, r6, r7, r8, r12, sp, pc}
 *   @0x313e3e andhs sp, r0, #5
 *   @0x313e42 ldmdaeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x313e46 .word 0x46944616
 *   @0x313e4a .word 0xf8d5e05f
 *   @0x313e4e ldreq r3, [r11], #-192
 *   @0x313e52 svceq #0xf0f513
 *   @0x313e56 .word 0xf8d5daf3
 *   @0x313e5a ldreq r3, [r11], #-196
 *   @0x313e5e svceq #0xf0f513
 *   @0x313e62 .word 0xf8d5daed
 *   @0x313e66 ldreq r3, [r11], #-200
 *   @0x313e6a svcvc #0x5cf1b3
 *   @0x313e6e .word 0xf8d5dde7
 *   @0x313e72 ldreq r3, [r11], #-204
 *   @0x313e76 svcvc #0x5cf1b3
 *   @0x313e7a .word 0xf46fdde1
 *   @0x313e7e .word 0xf8d400f0
 *   @0x313e82 .word 0xf8c410f0
 *   @0x313e86 .word 0xf7f90128
 *   @0x313e8a .word 0xf8d4ff94
 *   @0x313e8e teqhs r1, #240
 *   @0x313e92 smlawtlo r0, r4, r8, pc
 *   @0x313e96 teqne r0, r4, asr #17
 *   @0x313e9a andmi pc, r0, r0, lsl #10
 *   @0x313e9e streq r0, [r0], #-3072
 *   @0x313ea2 andmi pc, r0, r0, lsr #11
 *   @0x313ea6 smlawteq r12, r4, r8, pc
 *   @0x313eaa .word 0x00e8f8d4
 *   @0x313eae cps #0x0
 *   @0x313eb2 andlo r7, r1, r12, asr r0
 *   @0x313eb6 tsteq r4, r4, asr #17
 *   @0x313eba .word 0xff7bf7f9
 *   @0x313ebe ldrsbtlo pc, [r0], #132
 *   @0x313ec2 tstlo r12, r4, asr #17
 *   @0x313ec6 .word 0xf8c42332
 *   @0x313eca movwhs r3, #0x110c
 *   @0x313ece rscslo pc, r9, r4, lsl #17
 *   @0x313ed2 andmi pc, r0, r0, lsl #10
 *   @0x313ed6 streq r0, [r0], #-3072
 *   @0x313eda andmi pc, r0, r0, lsl #10
 *   @0x313ede tsteq r8, r4, asr #17
 *   @0x313ee2 .word 0xf8d4e118
 *   @0x313ee6 stmdavs pc, {r2, r4, r5, r6, r7, sp, lr, pc}
 *   @0x313eea movwmi pc, #0xeb08
 *   @0x313eee .word 0xf8c3043f
 *   @0x313ef2 stmdavs pc, {r2, r4, r5, r8, r12, sp, lr} ^
 *   @0x313ef6 bmi 0x50e83a <SrcVerts+0x6b87e>
 *   @0x313efa ldrsbvc pc, [r4, -r3]!
 *   @0x313efe teqge r8, r3, asr #17
 *   @0x313f02 .word 0x0707ebba
 *   @0x313f06 andlo sp, r2, #4, #10
 *   @0x313f0a addmi r3, r2, #8, #2
 *   @0x313f0e ands sp, sp, r9, ror #7
 *   @0x313f12 svclt #0xb842be
 *   @0x313f16 bhs 0x325816
 *   @0x313f1a teqhi pc, r0
 *   @0x313f1e .word 0x70e8f8d4
 *   @0x313f22 smlalbbgt pc, r4, r3, r8
 *   @0x313f26 bleq 0x150e86a <b2_toiTime+0xdb53c6>
 *   @0x313f2a streq lr, [r11, -r10, lsl #22]
 *   @0x313f2e teqvc r8, r3, asr #17
 *   @0x313f32 ldrsbvc pc, [r4, -r3]!
 *   @0x313f36 .word 0xf8c3445f
 *   @0x313f3a .word 0xf8d37134
 *   @0x313f3e .word 0xf8c37134
 *   @0x313f42 .word 0xf10e713c
 *   @0x313f46 .word 0xf8c40301
 *   @0x313f4a .word 0xe7dc30f4
 *   @0x313f4e andhs r4, r0, r10, asr #12
 *   @0x313f52 cdpeq p0, #0x1, c15, c4, c15, #0x2
 *   @0x313f56 .word 0x0c01f04f
 *   @0x313f5a addsmi r9, r8, #7168
 *   @0x313f5e .word 0xf8d4d21f
 *   @0x313f62 ldmdavs r1, {r2, r4, r5, r6, r7, pc}
 *   @0x313f66 movwmi pc, #0x8b0e
 *   @0x313f6a .word 0xf8c30409
 *   @0x313f6e ldmdavs r1, {r2, r4, r5, r8, r12} ^
 *   @0x313f72 ldrsbvc pc, [r4, -r3]!
 *   @0x313f76 .word 0xf8c30409
 *   @0x313f7a blne 0xff558462 <b2_toiTime+0xfffffffffedfefbe>
 *   @0x313f7e addmi sp, lr, #12, #8
 *   @0x313f82 .word 0x460ebfb8
 *   @0x313f86 ldrsbne pc, [r8, -r3]!
 *   @0x313f8a smlalbbgt pc, r4, r3, r8
 *   @0x313f8e streq pc, [r1, -r8, lsl #2]
 *   @0x313f92 teqne r12, r3, asr #17
 *   @0x313f96 rscsvc pc, r4, r4, asr #17
 *   @0x313f9a andlo r3, r8, #2
 *   @0x313f9e .word 0xf8d4e7dc
 *   @0x313fa2 .word 0xf44f10f0
 *   @0x313fa6 .word 0xf7d03080
 *   @0x313faa .word 0xf104ff85
 *   @0x313fae .word 0xf8d408f0
 *   @0x313fb2 strdhs r9, r10, [r0, -r4]
 *   @0x313fb6 strbmi r4, [r9, #-0x6c6]
 *   @0x313fba bl 0xff448132 <b2_toiTime+0xfffffffffeceec8e>
 *   @0x313fbe strbmi r0, [r2], #-526
 *   @0x313fc2 ldclo p8, c15, [r12], {18}
 *   @0x313fc6 stcgt p8, c15, [r4], #328
 *   @0x313fca .word 0xf06fb923
 *   @0x313fce .word 0xf04f4b00
 *   @0x313fd2 sub r0, r0, r2, lsl #20
 *   @0x313fd6 bmi 0x35019a
 *   @0x313fda blls 0x55dbe2 <g_SWFlineaavertbuff+0xab1a>
 *   @0x313fde andsle r4, r4, #-268435447
 *   @0x313fe2 orreq lr, r7, #5120
 *   @0x313fe6 ldrsblo pc, [r12, #-131]
 *   @0x313fea blmi 0x40e92e <g_RomDisk+0x1710e>
 *   @0x313fee movweq lr, #0xcbcb
 *   @0x313ff2 svclt #0xb82b00
 *   @0x313ff6 ldrbmi r4, [r3, #-0x25b]
 *   @0x313ffa addmi sp, r3, #20480
 *   @0x313ffe .word 0xf842da03
 *   @0x314002 tstlt r11, r4, lsr #25
 *   @0x314006 .word 0x3702469a
 *   @0x31400a ldrbmi lr, [r3], -r7, ror #15
 *   @0x31400e svchs #0x19f05
 *   @0x314012 .word 0xf8d5d92c
 *   @0x314016 ldrteq r7, [pc], #-292
 *   @0x31401a .word 0x0c0cebc7
 *   @0x31401e svceq #0xf1bc
 *   @0x314022 .word 0xf1ccbfb8
 *   @0x314026 ldrmi r0, [r12, #0xc00]
 *   @0x31402a strmi sp, [r4, #0xa20]
 *   @0x31402e .word 0xf842da1e
 *   @0x314032 ands r7, r11, r4, lsr #25
 *   @0x314036 .word 0xf8579f08
 *   @0x31403a .word 0xf8d4302a
 *   @0x31403e rsbseq r7, pc, r8, ror #1
 *   @0x314042 movwmi lr, #0x3b07
 *   @0x314046 streq lr, [r12, -r3, asr #23]
 *   @0x31404a svclt #0xb82f00
 *   @0x31404e ldrbmi r4, [pc, #-0x27f]
 *   @0x314052 .word 0xf10adb05
 *   @0x314056 blls 0x456866 <g_RomDisk+0x5f046>
 *   @0x31405a .word 0xd3eb459a
 *   @0x31405e addmi lr, r7, #6
 *   @0x314062 .word 0xf842daf7
 *   @0x314066 smlatblt pc, r4, r12, r3
 *   @0x31406a .word 0xe7f246bb
 *   @0x31406e .word 0xf10e3101
 *   @0x314072 .word 0xe7a00e14
 *   @0x314076 vst4.16 {d27, d29, d31, d1}, [pc:256], lr
 *   @0x31407a ldrtmi r3, [r1], -r0, lsl #1
 *   @0x31407e ldrsbtpl pc, [r12], #132
 *   @0x314082 .word 0xff18f7d0
 *   @0x314086 stcle p2, c4, [r6, #-532]
 *   @0x31408a addlo pc, r0, pc, asr #8
 *   @0x31408e .word 0xf7d04631
 *   @0x314092 .word 0xf8c4ff11
 *   @0x314096 .word 0xf8d400fc
 *   @0x31409a .word 0xf8d410f0
 *   @0x31409e addsmi r2, r1, #252
 *   @0x3140a2 movwhs sp, #0x1a11
 *   @0x3140a6 addsne pc, r10, r9, asr #12
 *   @0x3140aa rscslo pc, r8, r4, lsl #17
 *   @0x3140ae mcr2 p7, #0x2, pc, c5, c0, #0x6
 *   @0x3140b2 .word 0x73fff647
 *   @0x3140b6 andsmi pc, r9, r0, asr #11
 *   @0x3140ba addsmi r3, r8, #154
 *   @0x3140be .word 0xf8c4bfd4
 *   @0x3140c2 .word 0xf8c40108
 *   @0x3140c6 .word 0xf8943108
 *   @0x3140ca ldrhlt r3, [r3, -r10]
 *   @0x3140ce .word 0xf8c42300
 *   @0x3140d2 .word 0xf5043108
 *   @0x3140d6 strhs r7, [r0], -r2, lsr #11
 *   @0x3140da ldrsbtlo pc, [r4], #132
 *   @0x3140de andsle r4, r9, #-536870903
 *   @0x3140e2 .word 0xf855782b
 *   @0x3140e6 .word 0xf8d40c08
 *   @0x3140ea strdlt r1, r2, [r11, -r0]!
 *   @0x3140ee mcr2 p7, #0x3, pc, c1, c9, #0x7
 *   @0x3140f2 .word 0x3108f8d4
 *   @0x3140f6 and r1, r4, r0, asr #21
 *   @0x3140fa mrc2 p7, #0x2, apsr_nzcv, c11, c9, #0x7
 *   @0x3140fe .word 0x3108f8d4
 *   @0x314102 .word 0xf5004418
 *   @0x314106 strlo r4, [r1], -r0, lsl #6
 *   @0x31410a .word 0x0c1b3514
 *   @0x31410e .word 0xf845041b
 *   @0x314112 .word 0xe7e13c18
 *   @0x314116 bllt 0x1e6e2b2 <b2_toiTime+0x1714e0e>
 *   @0x31411a umlalsvs pc, r9, r4, r8
 *   @0x31411e .word 0xf10daf0e
 *   @0x314122 .word 0xf884082c
 *   @0x314126 .word 0xf8d450ec
 *   @0x31412a .word 0xf8c430ac
 *   @0x31412e ldmvs r8, {r5, r7, r12, lr} ^
 *   @0x314132 .word 0xf8c3f7d1
 *   @0x314136 addseq pc, r0, #4, #2
 *   @0x31413a strtmi r9, [r0], -r0, lsl #10
 *   @0x31413e ldmdbge r0, {r0, r8, r10, r12, pc}
 *   @0x314142 ldrtmi r9, [r11], -r2, lsl #10
 *   @0x314146 andhi pc, r12, sp, asr #17
 *   @0x31414a blx 0x29214a <Java_com_yoyogames_runner_RunnerJNILib_RenderSplash+0x30a>
 *   @0x31414e stmiblt r10, {r1, r5, r6, r11, sp, lr}
 *   @0x314152 .word 0xf8d4b146
 *   @0x314156 blhs 0x3203de
 *   @0x31415a movwhs sp, #0x1a04
 *   @0x31415e .word 0xf8844616
 *   @0x314162 strb r3, [r0, r12, ror #1]!
 *   @0x314166 .word 0x50acf8d4
 *   @0x31416a .word 0xf7fb6968
 *   @0x31416e stmvs r8!, {r1, r2, r3, r4, r11, r12, sp, lr, pc} ^
 *   @0x314172 .word 0xf8c1f7d1
 *   @0x314176 .word 0x21001d20
 *   @0x31417a .word 0xf7f99d0b
 *   @0x31417e stmdavs r0!, {r0, r5, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x314182 .word 0xf8d4b938
 *   @0x314186 .word 0xf50530ac
 *   @0x31418a strtne r4, [sp], #-1280
 *   @0x31418e eorpl pc, r8, #12779520
 *   @0x314192 andhs lr, r3, r11
 *   @0x314196 subhs lr, r0, r9
 *   @0x31419a .word 0xf04fe007
 *   @0x31419e .word 0xf8830701
 *   @0x3141a2 .word 0xf8d37144
 *   @0x3141a6 .word 0xe6ca7138
 *   @0x3141aa andslt r2, r11, r4, lsr #32
 *   @0x3141ae svchi #0xf0e8bd
 *   @0x3141b2 ldrbtge r11, [r7], r0, lsl #30
 *   @0x3141b6 stmdalt r5, {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3141ba ldcgt p15, c15, [r3, #-1020]
 *   @0x3141be ldclgt p15, c15, [r1, #-1020]
 *   @0x3141c2 push {r0, r1, r2, r3, r4, r5, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3141c6 ssub8mi r4, r6, r0
 *   @0x3141ca ldrmi r6, [r11], r5, asr #16
 *   @0x3141ce .word 0x73fff64f
 *   @0x3141d2 stclvc p5, c15, [pc, #-692]
 *   @0x3141d6 strmi r4, [r8], r4, lsl #12
 *   @0x3141da adcvc pc, r0, #13959168
 *   @0x3141de strbhs pc, [r0, #0x8d7]!
 *   @0x3141e2 mulle sp, r10, r2
 *   @0x3141e6 strtlo pc, [r8], #2263
 *   @0x3141ea qdsublt r11, r3, r6
 *   @0x3141ee strths pc, [r12], #2263
 *   @0x3141f2 stmdble r1, {r1, r2, r4, r7, r9, lr}
 *   @0x3141f6 cmp r2, #6
 *   @0x3141fa andsvs pc, r6, r3, lsr r8
 *   @0x3141fe .word 0xe7f9b91e
 *   @0x314202 addsmi r6, lr, #2015232
 *   @0x314206 .word 0xf41bd2f6
 *   @0x31420a .word 0xf44f6f80
 *   @0x31420e svclt #0x183380
 *   @0x314212 bleq 0x410346 <g_RomDisk+0x18b26>
 *   @0x314216 adclo pc, r4, r4, asr #17
 *   @0x31421a adclo pc, r8, r4, asr #17
 *   @0x31421e svceq #0xf1b8
 *   @0x314222 addshi pc, r3, r0
 *   @0x314226 ldrsblo pc, [r0], -r8
 *   @0x31422a adclo pc, r4, r4, asr #17
 *   @0x31422e ldrsblo pc, [r4], -r8
 *   @0x314232 adclo pc, r8, r4, asr #17
 *   @0x314236 .word 0x2000f8d8
 *   @0x31423a .word 0x102cf8d8
 *   @0x31423e andslo pc, r12, #13762560
 *   @0x314242 mcrrne p14, #0x9, r6, r10, c0
 *   @0x314246 addhi pc, r1, r0
 *   @0x31424a bhs 0x32faba
 *   @0x31424e .word 0xf01bd07d
 *   @0x314252 cmnle r10, r8, lsl #30
 *   @0x314256 .word 0xf1049000
 *   @0x31425a .word 0xf10d024c
 *   @0x31425e andls r0, r1, #84, #18
 *   @0x314262 andls pc, r8, sp, asr #17
 *   @0x314266 .word 0xf8d34628
 *   @0x31426a ldrtmi r12, [r2], -r8, asr #32
 *   @0x31426e ubfxmi r4, r11, #0xc, #0x1
 *   @0x314272 .word 0xd16a2800
 *   @0x314276 strhlo pc, [r2], -r9
 *   @0x31427a svceq #0x10f01b
 *   @0x31427e strhhs pc, [r4], -r9
 *   @0x314282 stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x314286 rsbeq pc, lr, r4, lsr #17
 *   @0x31428a orrne lr, r3, #323584
 *   @0x31428e rfeia r9!
 *   @0x314292 .word 0xf8a43000
 *   @0x314296 rfeib r9!
 *   @0x31429a b 0x16d42ca <b2_toiTime+0xf7ae26>
 *   @0x31429e mvnvs r1, r3, lsl #7
 *   @0x3142a2 orrne lr, r2, #323584
 *   @0x3142a6 rfeib r9!
 *   @0x3142aa svclt #0x143006
 *   @0x3142ae strbtvs r6, [r2], -r0, ror #12
 *   @0x3142b2 b 0x16e5b82 <b2_toiTime+0xf8c6de>
 *   @0x3142b6 rsbvs r1, r1, #-1073741792
 *   @0x3142ba strhne pc, [r8], -r9
 *   @0x3142be strtvs r11, [r3], r8, lsl #30
 *   @0x3142c2 orrne lr, r1, pc, asr #20
 *   @0x3142c6 b 0x16ecd52 <b2_toiTime+0xf938ae>
 *   @0x3142ca rscvs r1, r1, #128, #2
 *   @0x3142ce strhne pc, [r12], -r9
 *   @0x3142d2 b 0x16e5b7a <b2_toiTime+0xf8c6d6>
 *   @0x3142d6 .word 0x63271781
 *   @0x3142da strhvc pc, [lr], -r9
 *   @0x3142de ssatvs r11, #0x2, r8, lsl #30
 *   @0x3142e2 .word 0x01bf2100
 *   @0x3142e6 svcmi #0xa86367
 *   @0x3142ea svcge #0xd64a7
 *   @0x3142ee andslo pc, r12, #13959168
 *   @0x3142f2 .word 0xf8d39700
 *   @0x3142f6 .word 0x4643c070
 *   @0x3142fa ldmdahi r11!, {r5, r6, r7, r8, r9, r10, lr}
 *   @0x3142fe .word 0xf89563a3
 *   @0x314302 .word 0xb1233124
 *   @0x314306 strhlo pc, [r10, #-133]
 *   @0x31430a svclt #0x183300
 *   @0x31430e cmplt r11, r1, lsl #6
 *   @0x314312 andslo pc, r12, #13959168
 *   @0x314316 strls r4, [r0, -r8, lsr #12]
 *   @0x31431a ldrtmi r2, [r2], -r1, lsl #2
 *   @0x31431e ldrsbtgt pc, [r0], #-131
 *   @0x314322 strbmi r4, [r0, r3, asr #12]!
 *   @0x314326 and r8, lr, r11, lsr r8
 *   @0x31432a ldrhlo pc, [r4, #-133]!
 *   @0x31432e rscsvc pc, pc, #82837504
 *   @0x314332 svclt #0x194293
 *   @0x314336 ldrhhs pc, [r10, r5]!
 *   @0x31433a ldrhlo pc, [r12, r5]!
 *   @0x31433e ldrhhs pc, [r12], #149
 *   @0x314342 ldrhlo pc, [lr], #149
 *   @0x314346 .word 0x63e31ad3
 *   @0x31434a .word 0xf41be196
 *   @0x31434e .word 0xf47f4f80
 *   @0x314352 .word 0xf8d7af51
 *   @0x314356 .word 0xf1bee7e8
 *   @0x31435a eorsle r0, r5, r0, lsl #30
 *   @0x31435e .word 0xf6074631
 *   @0x314362 .word 0xf7f930ec
 *   @0x314366 .word 0xf8d7fce9
 *   @0x31436a .word 0xf10d37e8
 *   @0x31436e .word 0xf8d70c34
 *   @0x314372 addsmi r10, r8, #160, #10
 *   @0x314376 .word 0xf103bf24
 *   @0x31437a sbclt r3, r0, #255
 *   @0x31437e addeq lr, r0, r7, lsl #22
 *   @0x314382 ubfx pc, r0, #0x11, #0xd
 *   @0x314386 teqeq r0, #-2147483645
 *   @0x31438a .word 0x9044f8de
 *   @0x31438e strbmi r12, [r10, #0xb0f]
 *   @0x314392 andeq lr, pc, r12, lsl #17
 *   @0x314396 .word 0x3048f8de
 *   @0x31439a .word 0x204cf8de
 *   @0x31439e andls r9, r6, #8, #6
 *   @0x3143a2 ldrbmi sp, [r1], -r2, lsr #32
 *   @0x3143a6 .word 0xf8d4464a
 *   @0x3143aa .word 0xf7d000a4
 *   @0x3143ae ldrbmi pc, [r1], -r6, asr #25
 *   @0x3143b2 .word 0xf8c4464a
 *   @0x3143b6 .word 0xf8d400a4
 *   @0x3143ba .word 0xf7d000a8
 *   @0x3143be movwhs pc, #0x1cbe
 *   @0x3143c2 .word 0xf8c49309
 *   @0x3143c6 ands r0, r1, r8, lsr #1
 *   @0x3143ca orrpl pc, r12, #1879048192
 *   @0x3143ce ldceq p1, c15, [r4], #-52
 *   @0x3143d2 eor pc, r4, sp, asr #17
 *   @0x3143d6 stm r12, {r0, r1, r2, r3, r8, r9, r11, lr, pc}
 *   @0x3143da .word 0xf8d7000f
 *   @0x3143de .word 0xf8d725a4
 *   @0x3143e2 andls r3, r8, #168, #10
 *   @0x3143e6 and r9, r1, r6, lsl #6
 *   @0x3143ea andls r2, r9, #0, #4
 *   @0x3143ee movweq pc, #0x208b
 *   @0x3143f2 ldmdbeq r4, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x3143f6 movteq pc, #0x3c3
 *   @0x3143fa .word 0xf00b9307
 *   @0x3143fe bls 0x4d500a <SrcVerts+0x3204e>
 *   @0x314402 .word 0xf083930b
 *   @0x314406 .word 0xf8840301
 *   @0x31440a .word 0xf04f30a1
 *   @0x31440e blmi 0x1ad6c16 <b2_toiTime+0x137d772>
 *   @0x314412 .word 0xf8844651
 *   @0x314416 strbmi r2, [r8], -r0, lsr #1
 *   @0x31441a rsbge pc, lr, r4, lsr #17
 *   @0x31441e andmi pc, r3, #738197507
 *   @0x314422 .word 0xf8a464a3
 *   @0x314426 .word 0xf8d5a06c
 *   @0x31442a andls r12, r10, #160, #4
 *   @0x31442e eorsvc pc, r9, #1325400064
 *   @0x314432 .word 0xf8cd9304
 *   @0x314436 .word 0xf5a2c014
 *   @0x31443a .word 0xf8c9e8ba
 *   @0x31443e andhs r5, r1, #4
 *   @0x314442 andmi pc, r8, r9, asr #17
 *   @0x314446 subhs pc, r1, r9, lsl #17
 *   @0x31444a .word 0xf8c96e6a
 *   @0x31444e .word 0xf8d42000
 *   @0x314452 ldmdavs r0, {r2, r3, r4, r7, sp}
 *   @0x314456 andseq pc, r4, #0, #2
 *   @0x31445a andshs pc, r0, r9, asr #17
 *   @0x31445e andeq pc, r12, r9, asr #17
 *   @0x314462 eorseq pc, r8, #0, #2
 *   @0x314466 andshs pc, r4, r9, asr #17
 *   @0x31446a .word 0xff27f7d0
 *   @0x31446e .word 0xf8c99b07
 *   @0x314472 .word 0xf8c9a048
 *   @0x314476 .word 0xf8dda044
 *   @0x31447a cmnlt r3, r4, lsl r0
 *   @0x31447e svceq #0xf1b8
 *   @0x314482 .word 0xf8d8d00b
 *   @0x314486 ldmdavs r11, {r3, r5, r12, sp}
 *   @0x31448a ldmdavs r11, {r0, r1, r3, r4, r5, r8, r12, sp, pc}
 *   @0x31448e sublo pc, r8, r9, asr #17
 *   @0x314492 ldrsblo pc, [r12], r4
 *   @0x314496 .word 0xf8c96a5b
 *   @0x31449a movwhs r3, #0x44
 *   @0x31449e adcgt pc, r0, sp, asr #17
 *   @0x3144a2 tstls r12, #1811939328
 *   @0x3144a6 tstls lr, #1946157056
 *   @0x3144aa .word 0x9320931f
 *   @0x3144ae ldrsbths pc, [r8], #-140
 *   @0x3144b2 .word 0xf8dc92c4
 *   @0x3144b6 bicls r1, r8, r8, asr #10
 *   @0x3144ba strne pc, [r8, #0x8dc]
 *   @0x3144be andle r2, r12, r1, lsl #18
 *   @0x3144c2 svcvs #0x9bf5b2
 *   @0x3144c6 vcgt.s8 d29, d0, d8
 *   @0x3144ca .word 0xf248436b
 *   @0x3144ce addmi r4, r10, #-1073741798
 *   @0x3144d2 .word 0xf44fbf88
 *   @0x3144d6 and r4, r0, r0, lsl #6
 *   @0x3144da bicls r2, r6, #-1409286143
 *   @0x3144de svcvc #0x80f41b
 *   @0x3144e2 .word 0xf10d9b0a
 *   @0x3144e6 qsaxmi r0, r8, r4
 *   @0x3144ea bge 0x625db6 <g_SWFaavertbuff+0x52cee>
 *   @0x3144ee svclt #0x1c93cb
 *   @0x3144f2 .word 0xf88a2301
 *   @0x3144f6 movwhs r3, #0x231
 *   @0x3144fa sublo pc, r2, r10, lsl #17
 *   @0x3144fe .word 0xf7fbab11
 *   @0x314502 sxtab16mi pc, r1, r12, ror #16
 *   @0x314506 .word 0xf0402800
 *   @0x31450a .word 0xf8da80bb
 *   @0x31450e .word 0xf8d33004
 *   @0x314512 .word 0xf8d992a0
 *   @0x314516 ldmdblt r3, {r3, r5, r6, r7, r8, r9, r10, r12, sp}
 *   @0x31451a cmppl r12, #-1879048192
 *   @0x31451e .word 0xf609e01b
 *   @0x314522 ldrtmi r3, [r1], -r12, ror #1
 *   @0x314526 .word 0xfc08f7f9
 *   @0x31452a ubfxlo pc, r9, #0x11, #0x9
 *   @0x31452e .word 0xf0804298
 *   @0x314532 bl 0x5747ce <g_SWFlineaavertbuff+0x21706>
 *   @0x314536 .word 0xf8da0380
 *   @0x31453a .word 0xf8d32044
 *   @0x31453e cmplt r2, r12, ror #15
 *   @0x314542 svceq #0xf1b8
 *   @0x314546 .word 0xf8d8d007
 *   @0x31454a ldmdavs r2, {r3, r5, sp}
 *   @0x31454e addeq lr, r0, r2, lsl #22
 *   @0x314552 .word 0xf8ca6842
 *   @0x314556 .word 0xf8d32048
 *   @0x31455a bicls r1, r3, r12, ror #4
 *   @0x31455e addhs pc, r4, #13828096
 *   @0x314562 bls 0xd39086 <b2_toiTime+0x5dfbe2>
 *   @0x314566 strhs pc, [r8, #0x8d2]
 *   @0x31456a andle r2, r11, r1, lsl #20
 *   @0x31456e svcvs #0x9bf5b1
 *   @0x314572 vcgt.s8 d29, d0, d15
 *   @0x314576 .word 0xf248426b
 *   @0x31457a addmi r4, r1, #107
 *   @0x31457e .word 0xf44fbf88
 *   @0x314582 and r4, r7, r0, lsl #4
 *   @0x314586 and r2, r5, r0, lsl #4
 *   @0x31458a ldrbtvc r11, [r3], #-3840
 *   @0x31458e strbtvc r6, [r12], #-617
 *   @0x314592 rsbhs r6, r11, #468
 *   @0x314596 .word 0xf10d92c5
 *   @0x31459a .word 0xf8d30c54
 *   @0x31459e .word 0xf10d221c
 *   @0x3145a2 strbtmi r0, [r0], -r4, asr #20
 *   @0x3145a6 addsls r9, pc, #12, #18
 *   @0x3145aa eorhs pc, r0, #13828096
 *   @0x3145ae blge 0x6394ea <g_SWFaavertbuff+0x66422>
 *   @0x3145b2 .word 0xf8da92a0
 *   @0x3145b6 movwls r2, #0x4000
 *   @0x3145ba andsgt pc, r4, sp, asr #17
 *   @0x3145be blx 0x6125c2 <g_SWFaavertbuff+0x3f4fa>
 *   @0x3145c2 .word 0xf8dd9b04
 *   @0x3145c6 sbclt r12, r2, #20
 *   @0x3145ca bhs 0xfec25fd6 <b2_toiTime+0xfffffffffe4ccb32>
 *   @0x3145ce .word 0xf04fd10e
 *   @0x3145d2 ldmdavs r9, {r9}
 *   @0x3145d6 adchs pc, r0, r4, lsl #17
 *   @0x3145da .word 0xf8da4660
 *   @0x3145de .word 0xf7ff2000
 *   @0x3145e2 movwhs pc, #0x19fa
 *   @0x3145e6 movwls r2, #0x9200
 *   @0x3145ea strmi r9, [r1], r7, lsl #4
 *   @0x3145ee stmdbge r12, {r3, r5, r9, r10, lr}
 *   @0x3145f2 .word 0x2000f8da
 *   @0x3145f6 rfedb sp!
 *   @0x3145fa svceq #0xf1b9
 *   @0x3145fe .word 0xf8d5d140
 *   @0x314602 blvs 0x19e080a <b2_toiTime+0x1287366>
 *   @0x314606 .word 0xf8c4b123
 *   @0x31460a .word 0xf8c49088
 *   @0x31460e and r9, lr, r12, lsl #1
 *   @0x314612 ldrblo pc, [r0], #2263
 *   @0x314616 .word 0xf853b15b
 *   @0x31461a .word 0xf8d73026
 *   @0x31461e bllo 0x35d976 <_ZTS7CFontGM+0x103e>
 *   @0x314622 .word 0xf8c44413
 *   @0x314626 .word 0xf8da3088
 *   @0x31462a .word 0xf8c43000
 *   @0x31462e blge 0x860866 <b2_toiTime+0x1073c2>
 *   @0x314632 swpblt r6, pc, [r7]
 *   @0x314636 ldrsbgt pc, [r0], -r3
 *   @0x31463a ldm r12!, {r2, r3, r5, r6, r8, r9, r10, r12, sp}
 *   @0x31463e strgt r0, [pc, -pc]
 *   @0x314642 .word 0x3000f8dc
 *   @0x314646 .word 0xf8d5603b
 *   @0x31464a blvs 0x19e0852 <b2_toiTime+0x12873ae>
 *   @0x31464e .word 0xf41bb9d3
 *   @0x314652 eorsle r6, r10, r0, lsl #3
 *   @0x314656 .word 0xf8d49b1d
 *   @0x31465a eorvs r5, r3, #156
 *   @0x31465e adcvs r9, r3, #162816
 *   @0x314662 .word 0xf105ab0d
 *   @0x314666 blgt 0x6d569e <g_SWFvertbuff+0x25d6>
 *   @0x31466a andeq lr, pc, r4, lsl #17
 *   @0x31466e bls 0x4bb296 <SrcVerts+0x182da>
 *   @0x314672 movwhs r6, #0x11eb
 *   @0x314676 eorvc r6, r11, #-1610612734
 *   @0x31467a tst r0, r0
 *   @0x31467e stmdbeq r3, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x314682 .word 0xe10c4648
 *   @0x314686 ldmvs r2, {r1, r3, r4, r11, sp, lr}
 *   @0x31468a rscle r2, r0, r0, lsl #20
 *   @0x31468e svcge #0x119a1d
 *   @0x314692 subls pc, r8, sp, asr #17
 *   @0x314696 .word 0xf10d4631
 *   @0x31469a andsls r0, r1, #84, #20
 *   @0x31469e andsls r9, r3, #126976
 *   @0x3146a2 andsls r9, r4, #32, #20
 *   @0x3146a6 ldmdavs r8, {r1, r3, r4, r11, sp, lr} ^
 *   @0x3146aa .word 0xf8d2463b
 *   @0x3146ae andhs r12, r0, #8
 *   @0x3146b2 ldmdavs r11!, {r5, r6, r7, r8, r9, r10, lr}
 *   @0x3146b6 eorlo pc, r0, r10, asr #17
 *   @0x3146ba .word 0xf8ca68bb
 *   @0x3146be ldmvs r11!, {r3, r5, r12, sp} ^
 *   @0x3146c2 eorlo pc, r12, r10, asr #17
 *   @0x3146c6 sbcle r2, r2, r0, lsl #16
 *   @0x3146ca rfeia r5!
 *   @0x3146ce ldrshlt r3, [r11, r10]!
 *   @0x3146d2 eorsne pc, r0, sp, lsr #17
 *   @0x3146d6 .word 0xf8adaf0c
 *   @0x3146da .word 0xf10d1044
 *   @0x3146de .word 0xf8d50944
 *   @0x3146e2 shadd16mi r3, r2, r12
 *   @0x3146e6 andls pc, r0, sp, asr #17
 *   @0x3146ea .word 0xf8d34628
 *   @0x3146ee shsub16mi r12, r11, r0
 *   @0x3146f2 rfeia r9!
 *   @0x3146f6 rfeib r7!
 *   @0x3146fa adcvs r2, r3, #0
 *   @0x3146fe and r6, r1, r2, lsr #4
 *   @0x314702 adcvs r9, r3, #162816
 *   @0x314706 andhs r6, r0, #-1946157054
 *   @0x31470a ldrsblo pc, [r12], r4
 *   @0x31470e .word 0xf895721a
 *   @0x314712 .word 0xb1233124
 *   @0x314716 strhlo pc, [r10, #-133]
 *   @0x31471a svclt #0x181a9b
 *   @0x31471e .word 0xf0032301
 *   @0x314722 ldrshlt r0, [r3, pc]!
 *   @0x314726 .word 0xf8ad2300
 *   @0x31472a .word 0xf8ad3030
 *   @0x31472e .word 0xf10d3044
 *   @0x314732 .word 0xf8d50930
 *   @0x314736 svcge #0x11321c
 *   @0x31473a strls r4, [r0, -r8, lsr #12]
 *   @0x31473e ldrtmi r2, [r2], -r1, lsl #2
 *   @0x314742 ldrsbtgt pc, [r0], #-131
 *   @0x314746 strbmi r4, [r0, r11, asr #12]!
 *   @0x31474a strhlo pc, [r0], -r9
 *   @0x31474e ldmdahi r11!, {r0, r1, r5, r8, r9, sp, lr}
 *   @0x314752 rfeia r5!
 *   @0x314756 .word 0xf64f3174
 *   @0x31475a addsmi r7, r3, #-268435441
 *   @0x31475e rfeib r5!
 *   @0x314762 rfeib r5!
 *   @0x314766 rfeib r5!
 *   @0x31476a rfeib r5!
 *   @0x31476e bne 0xff7e0aee <b2_toiTime+0xffffffffff08764a>
 *   @0x314772 blvs 0x1bed506 <b2_toiTime+0x1494062>
 *   @0x314776 blmi 0x15ed70a <b2_toiTime+0xe94266>
 *   @0x31477a movwhs r6, #0x4a3
 *   @0x31477e .word 0xf1b867e3
 *   @0x314782 andle r0, r6, r0, lsl #30
 *   @0x314786 strhlo pc, [lr], -r8
 *   @0x31478a svclt #0x9c2b17
 *   @0x31478e orrvc pc, r0, #1325400064
 *   @0x314792 svcvs #0xe367e3
 *   @0x314796 .word 0xf043ad0d
 *   @0x31479a strbvs r0, [r3, r4, lsl #6]!
 *   @0x31479e .word 0xf5b3682b
 *   @0x3147a2 smlabble r7, r0, pc, r3
 *   @0x3147a6 .word 0xf5b368eb
 *   @0x3147aa smlabble r3, r0, pc, r3
 *   @0x3147ae stmdblt r11, {r0, r1, r3, r5, r6, r11, sp, lr}
 *   @0x3147b2 cmnlt r3, r11, lsr #17
 *   @0x3147b6 rsbeq pc, r12, r4, lsl #2
 *   @0x3147ba .word 0xf7d14629
 *   @0x3147be stmdavs r9!, {r5, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x3147c2 .word 0xf7d06aa0
 *   @0x3147c6 stmvs r9!, {r1, r6, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x3147ca blvs 0x1b2d252 <b2_toiTime+0x13d3dae>
 *   @0x3147ce blx 0x1292718 <b2_toiTime+0xb39274>
 *   @0x3147d2 bls 0x52d55a <SrcVerts+0x8a59e>
 *   @0x3147d6 blls 0x4c2c06 <SrcVerts+0x1fc4a>
 *   @0x3147da bls 0x4c0d8e <SrcVerts+0x1ddd2>
 *   @0x3147de rsbeq pc, r12, r4, lsl #2
 *   @0x3147e2 .word 0xf7d19908
 *   @0x3147e6 bvs 0xfec14066 <b2_toiTime+0xfffffffffe4babc2>
 *   @0x3147ea ldrmi r9, [r3], #-2568
 *   @0x3147ee adcvs r9, r3, #24576
 *   @0x3147f2 ldrmi r6, [r3], #-2915
 *   @0x3147f6 blls 0x5ed58a <g_SWFaavertbuff+0x1a4c2>
 *   @0x3147fa bls 0x580c2e <g_SWFlineaavertbuff+0x2db66>
 *   @0x3147fe blls 0x50156e <SrcVerts+0x5e5b2>
 *   @0x314802 .word 0xf8d46f25
 *   @0x314806 .word 0xf8d480a4
 *   @0x31480a smultblt r3, r8, r0
 *   @0x31480e cmplt r3, r6, lsr #22
 *   @0x314812 bvs 0xfeb2611e <b2_toiTime+0xfffffffffe3ccc7a>
 *   @0x314816 blx 0x992760 <b2_toiTime+0x2392bc>
 *   @0x31481a adcvs r4, r0, #59768832
 *   @0x31481e .word 0xf7d06b60
 *   @0x314822 msrvs SPSR, #20, #22
 *   @0x314826 rfeib r4!
 *   @0x31482a strhs r9, [r0], -lr, rrx
 *   @0x31482e movweq lr, #0x9bc6
 *   @0x314832 blhs 0x321c5a
 *   @0x314836 strbmi sp, [r1], -r12, ror #27
 *   @0x31483a .word 0x0c08f855
 *   @0x31483e blx 0x492788 <g_prim_v+0x277c>
 *   @0x314842 .word 0x36014639
 *   @0x314846 .word 0x0c08f845
 *   @0x31484a .word 0x0c04f855
 *   @0x31484e blx 0x292796 <Java_com_yoyogames_runner_RunnerJNILib_SetKeyValue+0x136>
 *   @0x314852 .word 0x0c04f845
 *   @0x314856 ldcge p7, c14, [r1, #-936]
 *   @0x31485a rsbeq pc, r12, r4, lsl #2
 *   @0x31485e .word 0xf7d14629
 *   @0x314862 stmdavs r11!, {r2, r4, r5, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x314866 stmdavs r9!, {r1, r3, r5, r7, r11, sp, lr} ^
 *   @0x31486a ldrdvs r1, r2, [r2, r2]!
 *   @0x31486e eorvs r6, r3, #15335424
 *   @0x314872 mvnvs r1, r1, asr r10
 *   @0x314876 .word 0xf1ba6262
 *   @0x31487a andle r0, r6, r0, lsl #30
 *   @0x31487e bl 0x3af30e <error_g0017+0x7fb2>
 *   @0x314882 bl 0xfebf13d2 <b2_toiTime+0xfffffffffe497f2e>
 *   @0x314886 rscvs r0, r3, #-2013265919
 *   @0x31488a .word 0xf01be6f6
 *   @0x31488e .word 0xf43f0f10
 *   @0x314892 .word 0xf104aef3
 *   @0x314896 blvs 0x1b548fe <b2_toiTime+0x13fb45a>
 *   @0x31489a mcr2 p7, #0x1, pc, c1, c0, #0x6
 *   @0x31489e .word 0xf50de6ec
 *   @0x3148a2 pop {r0, r1, r2, r3, r6, r8, r10, r11, r12, sp, lr}
 *   @0x3148a6 strbtvc r8, [r12], #-4080
 *   @0x3148aa ldrlt r6, [r0, #-0xf75]!
 *   @0x3148ae stmdblt r9, {r3, r4, r5, r6, r8, r12, sp, pc}
 *   @0x3148b2 movweq pc, #0x3043
 *   @0x3148b6 strle r0, [r5], #-2012
 *   @0x3148ba stmdavs sp, {r0, r3, r5, r8, r12, sp, pc}
 *   @0x3148be adcmi r6, r5, #68, #16
 *   @0x3148c2 and sp, r0, r7, lsl #2
 *   @0x3148c6 pop {r8, sp}
 *   @0x3148ca .word 0xf7ff4030
 *   @0x3148ce eorhs r11, r5, r10, ror r12
 *   @0x3148d2 eorhs r11, r3, r0, lsr sp
 *   @0x3148d6 push {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x3148da .word 0x469147ff
 *   @0x3148de strmi r6, [r4], -r2, lsl #17
 *   @0x3148e2 ldrsbhi pc, [r4], #-128
 *   @0x3148e6 ldreq r4, [r0, -lr, lsl #12]
 *   @0x3148ea strble r9, [r7, #-0xf0c]
 *   @0x3148ee svceq #0x10f013
 *   @0x3148f2 adcshs pc, r12, #148, #16
 *   @0x3148f6 ldmdblt r10, {r5, r12, lr, pc}
 *   @0x3148fa sbchs pc, r0, #212, #16
 *   @0x3148fe ldrle r0, [r11, #-0x6d1]!
 *   @0x314902 .word 0x2124f894
 *   @0x314906 eorsle r2, r9, r0, lsl #20
 *   @0x31490a beq 0x650d46 <g_SWFaavertbuff+0x7dc7e>
 *   @0x31490e stmdaeq lr, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x314912 strbmi r2, [sp, #-0x500]
 *   @0x314916 .word 0xf8d4d04d
 *   @0x31491a uadd16mi r2, r3, r12
 *   @0x31491e andhi pc, r0, sp, asr #17
 *   @0x314922 .word 0x21014620
 *   @0x314926 ldrsbtgt pc, [r0], #-130
 *   @0x31492a strbmi r1, [r0, r10, lsr #19]!
 *   @0x31492e strhlo pc, [lr], -sp
 *   @0x314932 eorlo pc, r5, r7, asr #16
 *   @0x314936 strb r3, [r12, r1, lsl #10]!
 *   @0x31493a .word 0xf8d4b91a
 *   @0x31493e ldreq r2, [r2, r0, asr #5]
 *   @0x314942 rfeia r4!
 *   @0x314946 strdlt r2, r3, [r10, #10]
 *   @0x31494a beq 0x650d86 <g_SWFaavertbuff+0x7dcbe>
 *   @0x31494e stmdaeq lr, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x314952 strbmi r2, [sp, #-0x500]
 *   @0x314956 .word 0xf8d4d02d
 *   @0x31495a uadd16mi r2, r3, r12
 *   @0x31495e andhi pc, r0, sp, asr #17
 *   @0x314962 .word 0x21004620
 *   @0x314966 ldrsbtgt pc, [r0], #-130
 *   @0x31496a strbmi r1, [r0, r10, lsr #19]!
 *   @0x31496e strhlo pc, [lr], -sp
 *   @0x314972 eorlo pc, r5, r7, asr #16
 *   @0x314976 strb r3, [r12, r1, lsl #10]!
 *   @0x31497a ands r2, r11, r7
 *   @0x31497e bvc 0xfe351a92 <b2_toiTime+0xfffffffffdbf85ee>
 *   @0x314982 .word 0x463544b1
 *   @0x314986 .word 0xf00a3f04
 *   @0x31498a strbmi r0, [sp, #-0x610]
 *   @0x31498e .word 0x4640d011
 *   @0x314992 strtmi r6, [r10], -r1, lsr #27
 *   @0x314996 .word 0xf7ff4653
 *   @0x31499a ldmdblt r8, {r3, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x31499e ldrsbths pc, [r8], -r8
 *   @0x3149a2 .word 0xf8d83501
 *   @0x3149a6 mcrhs p0, #0x0, r3, c0, c12, #0x1
 *   @0x3149aa sadd16mi r11, r10, r8
 *   @0x3149ae svchs #0x4f847
 *   @0x3149b2 andhs lr, r0, r11, ror #15
 *   @0x3149b6 pop {r2, r12, sp, pc}
 *
 * ══ §2/2 b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)  0x2de464  size 1180  295 条（0x2de464..0x2de900）
 * @func 0x2de464 0x2de900  size 1180  295 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2de0f4+0x120×2 / b2ClipSegmentToLine(b2ClipVertex*, b2ClipVertex const*, b2Vec2 const&, float, int)×2 / b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x54×2 / b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x3f8 / b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x46c / b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x460 / b2CollidePolygons(b2Manifold*, b2PolygonShape const*, b2Transform const&, b2PolygonShape const*, b2Transform const&)+0x3e4 / 0xfe3a32a8
 * 字段偏移 top8: 0x38×3 / 0x10×3 / 0x3c×2 / 0x94×2 / 0x11×2 / 0x12×2 / 0x13×2 / 0xd8×1
 * VFP 指令 161 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2de464 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2de468 vpush {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2de46c sub sp, sp, #120
 *   @0x2de470 vldr s16, [r1, #8]
 *   @0x2de474 mov r8, r0
 *   @0x2de478 add r0, sp, #120
 *   @0x2de47c ldr r5, [sp, #0xd8]
 *   @0x2de480 vldr s15, [r3, #8]
 *   @0x2de484 mov r4, #0
 *   @0x2de488 str r4, [r0, #-0x58]!
 *   @0x2de48c str r4, [r8, #0x3c]
 *   @0x2de490 vadd.f32 s16, s16, s15
 *   @0x2de494 str r5, [sp]
 *   @0x2de498 mov r7, r1
 *   @0x2de49c mov r6, r3
 *   @0x2de4a0 mov r9, r2
 *   @0x2de4a4 bl 0x2de214 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x158>
 *   @0x2de4a8 vcmpe.f32 s16, s0
 *   @0x2de4ac vmov.f32 s17, s0
 *   @0x2de4b0 vmrs APSR_nzcv, fpscr
 *   @0x2de4b4 bpl 0x2de4c4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x60>
 *   @0x2de4b8 add sp, sp, #120
 *   @0x2de4bc vpop {d8, d9, d10, d11, d12, d13, d14, d15}
 *   @0x2de4c0 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2de4c4 add r0, sp, #120
 *   @0x2de4c8 str r9, [sp]
 *   @0x2de4cc mov r1, r6
 *   @0x2de4d0 mov r2, r5
 *   @0x2de4d4 str r4, [r0, #-0x54]!
 *   @0x2de4d8 mov r3, r7
 *   @0x2de4dc bl 0x2de214 <_Z23b2CollideEdgeAndPolygonP10b2ManifoldPK11b2EdgeShapeRK11b2TransformPK14b2PolygonShapeS6_+0x158>
 *   @0x2de4e0 vcmpe.f32 s16, s0
 *   @0x2de4e4 vmrs APSR_nzcv, fpscr
 *   @0x2de4e8 bmi 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54>
 *   @0x2de4ec vldr s14, [pc, #1004]
 *   @0x2de4f0 vldr s15, [pc, #1004]
 *   @0x2de4f4 vmla.f32 s15, s17, s14
 *   @0x2de4f8 vcmpe.f32 s0, s15
 *   @0x2de4fc vmrs APSR_nzcv, fpscr
 *   @0x2de500 ble 0x2de85c <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x3f8>
 *   @0x2de504 ldr r10, [sp, #0x24]
 *   @0x2de508 mov r4, #1
 *   @0x2de50c vldr s11, [r5]
 *   @0x2de510 vldr s13, [r5, #4]
 *   @0x2de514 vldr s18, [r5, #8]
 *   @0x2de518 vldr s17, [r5, #12]
 *   @0x2de51c vldr s30, [r9]
 *   @0x2de520 vldr s29, [r9, #4]
 *   @0x2de524 vldr s21, [r9, #8]
 *   @0x2de528 vldr s19, [r9, #12]
 *   @0x2de52c mov r3, #2
 *   @0x2de530 vstr s11, [sp, #16]
 *   @0x2de534 vstr s13, [sp, #12]
 *   @0x2de538 str r3, [r8, #0x38]
 *   @0x2de53c lsl r0, r10, #3
 *   @0x2de540 add r3, r6, #84
 *   @0x2de544 add r3, r3, r0
 *   @0x2de548 vldr s15, [r3, #4]
 *   @0x2de54c vmul.f32 s11, s17, s15
 *   @0x2de550 vldr s14, [r3]
 *   @0x2de554 ldr r3, [r7, #0x94]
 *   @0x2de558 add lr, r7, #20
 *   @0x2de55c add r2, r7, #84
 *   @0x2de560 mov r1, #0
 *   @0x2de564 cmp r3, #0
 *   @0x2de568 vmla.f32 s11, s18, s14
 *   @0x2de56c vmul.f32 s15, s18, s15
 *   @0x2de570 vnmls.f32 s15, s17, s14
 *   @0x2de574 vmul.f32 s12, s21, s11
 *   @0x2de578 vmul.f32 s11, s19, s11
 *   @0x2de57c vneg.f32 s13, s21
 *   @0x2de580 vmla.f32 s12, s19, s15
 *   @0x2de584 vstr s13, [sp, #28]
 *   @0x2de588 vmla.f32 s11, s15, s13
 *   @0x2de58c ble 0x2de8d0 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x46c>
 *   @0x2de590 mov r12, r1
 *   @0x2de594 vldr s13, [pc, #844]
 *   @0x2de598 vldr s15, [r2, #4]
 *   @0x2de59c vldr s14, [r2]
 *   @0x2de5a0 add r2, r2, #8
 *   @0x2de5a4 vmul.f32 s15, s11, s15
 *   @0x2de5a8 vmla.f32 s15, s12, s14
 *   @0x2de5ac vcmpe.f32 s13, s15
 *   @0x2de5b0 vmrs APSR_nzcv, fpscr
 *   @0x2de5b4 movgt r1, r12
 *   @0x2de5b8 add r12, r12, #1
 *   @0x2de5bc vmovgt.f32 s13, s15
 *   @0x2de5c0 cmp r12, r3
 *   @0x2de5c4 bne 0x2de598 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x134>
 *   @0x2de5c8 add r5, r1, #1
 *   @0x2de5cc lsl r2, r1, #3
 *   @0x2de5d0 cmp r12, r5
 *   @0x2de5d4 uxtb r1, r1
 *   @0x2de5d8 ble 0x2de8c4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x460>
 *   @0x2de5dc lsl r3, r5, #3
 *   @0x2de5e0 uxtb r12, r5
 *   @0x2de5e4 add r3, lr, r3
 *   @0x2de5e8 vldr s15, [r3, #4]
 *   @0x2de5ec vmul.f32 s14, s21, s15
 *   @0x2de5f0 vldr s11, [r3]
 *   @0x2de5f4 ldr r3, [r6, #0x94]
 *   @0x2de5f8 add r5, r10, #1
 *   @0x2de5fc add r6, r6, #20
 *   @0x2de600 add r2, lr, r2
 *   @0x2de604 cmp r3, r5
 *   @0x2de608 uxtb r3, r10
 *   @0x2de60c strb r3, [sp, #0x38]
 *   @0x2de610 vldr s13, [r2, #4]
 *   @0x2de614 strb r3, [sp, #0x44]
 *   @0x2de618 mov r3, #0
 *   @0x2de61c strb r3, [sp, #0x3b]
 *   @0x2de620 movle r5, r3
 *   @0x2de624 strb r3, [sp, #0x47]
 *   @0x2de628 addgt r3, r0, #8
 *   @0x2de62c add r3, r6, r3
 *   @0x2de630 add r0, r6, r0
 *   @0x2de634 vldr s27, [r3, #4]
 *   @0x2de638 vldr s25, [r0, #4]
 *   @0x2de63c vldr s26, [r0]
 *   @0x2de640 vldr s28, [r3]
 *   @0x2de644 vldr s10, [r2]
 *   @0x2de648 strb r1, [sp, #0x39]
 *   @0x2de64c vnmls.f32 s14, s19, s11
 *   @0x2de650 mov r2, #1
 *   @0x2de654 strb r12, [sp, #0x45]
 *   @0x2de658 strb r2, [sp, #0x3a]
 *   @0x2de65c strb r2, [sp, #0x46]
 *   @0x2de660 vadd.f32 s14, s14, s30
 *   @0x2de664 vmul.f32 s15, s19, s15
 *   @0x2de668 vstr s14, [sp, #60]
 *   @0x2de66c vsub.f32 s23, s27, s25
 *   @0x2de670 vmul.f32 s14, s23, s23
 *   @0x2de674 vmla.f32 s15, s21, s11
 *   @0x2de678 vsub.f32 s22, s28, s26
 *   @0x2de67c vmla.f32 s14, s22, s22
 *   @0x2de680 vadd.f32 s15, s15, s29
 *   @0x2de684 vmul.f32 s12, s21, s13
 *   @0x2de688 vstr s15, [sp, #64]
 *   @0x2de68c vmul.f32 s13, s19, s13
 *   @0x2de690 vsqrt.f32 s15, s14
 *   @0x2de694 vnmls.f32 s12, s19, s10
 *   @0x2de698 vmla.f32 s13, s21, s10
 *   @0x2de69c vadd.f32 s12, s12, s30
 *   @0x2de6a0 vadd.f32 s13, s13, s29
 *   @0x2de6a4 vstr s12, [sp, #48]
 *   @0x2de6a8 vcmp.f32 s15, s15
 *   @0x2de6ac vstr s13, [sp, #52]
 *   @0x2de6b0 vmrs APSR_nzcv, fpscr
 *   @0x2de6b4 bne 0x2de8f0 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x48c>
 *   @0x2de6b8 vldr s14, [pc, #556]
 *   @0x2de6bc vcmpe.f32 s15, s14
 *   @0x2de6c0 vldr s11, [sp, #12]
 *   @0x2de6c4 vldr s13, [sp, #16]
 *   @0x2de6c8 add r6, sp, #72
 *   @0x2de6cc add r7, sp, #96
 *   @0x2de6d0 str r10, [sp]
 *   @0x2de6d4 add r1, sp, #48
 *   @0x2de6d8 vmrs APSR_nzcv, fpscr
 *   @0x2de6dc vmovpl.f32 s14, #1.000000e+00
 *   @0x2de6e0 mov r0, r6
 *   @0x2de6e4 mov r2, r7
 *   @0x2de6e8 vdivpl.f32 s15, s14, s15
 *   @0x2de6ec vmulpl.f32 s23, s23, s15
 *   @0x2de6f0 vmulpl.f32 s22, s22, s15
 *   @0x2de6f4 vmul.f32 s15, s17, s25
 *   @0x2de6f8 vmul.f32 s20, s17, s23
 *   @0x2de6fc vmla.f32 s15, s18, s26
 *   @0x2de700 vmul.f32 s14, s18, s25
 *   @0x2de704 vmla.f32 s20, s18, s22
 *   @0x2de708 vmul.f32 s24, s18, s23
 *   @0x2de70c vstr s20, [sp, #44]
 *   @0x2de710 vnmls.f32 s14, s17, s26
 *   @0x2de714 vadd.f32 s15, s11, s15
 *   @0x2de718 vnmls.f32 s24, s17, s22
 *   @0x2de71c vstr s15, [sp, #24]
 *   @0x2de720 vmul.f32 s15, s20, s15
 *   @0x2de724 vstr s24, [sp, #40]
 *   @0x2de728 vadd.f32 s14, s13, s14
 *   @0x2de72c vmla.f32 s15, s24, s14
 *   @0x2de730 vstr s14, [sp, #20]
 *   @0x2de734 vsub.f32 s15, s16, s15
 *   @0x2de738 vneg.f32 s14, s20
 *   @0x2de73c vmov r3, s15
 *   @0x2de740 vneg.f32 s31, s24
 *   @0x2de744 vstr s14, [sp, #100]
 *   @0x2de748 vstr s31, [sp, #96]
 *   @0x2de74c bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi>
 *   @0x2de750 cmp r0, #1
 *   @0x2de754 ble 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54>
 *   @0x2de758 vmul.f32 s15, s17, s27
 *   @0x2de75c vldr s14, [sp, #12]
 *   @0x2de760 vldr s11, [sp, #16]
 *   @0x2de764 str r5, [sp]
 *   @0x2de768 mov r0, r7
 *   @0x2de76c mov r1, r6
 *   @0x2de770 add r2, sp, #40
 *   @0x2de774 vmla.f32 s15, s18, s28
 *   @0x2de778 vmul.f32 s18, s18, s27
 *   @0x2de77c vnmls.f32 s18, s17, s28
 *   @0x2de780 vadd.f32 s15, s14, s15
 *   @0x2de784 vmul.f32 s15, s20, s15
 *   @0x2de788 vadd.f32 s18, s11, s18
 *   @0x2de78c vmla.f32 s15, s24, s18
 *   @0x2de790 vadd.f32 s15, s16, s15
 *   @0x2de794 vmov r3, s15
 *   @0x2de798 bl 0x2c39c4 <_Z19b2ClipSegmentToLineP12b2ClipVertexPKS_RK6b2Vec2fi>
 *   @0x2de79c cmp r0, #1
 *   @0x2de7a0 ble 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54>
 *   @0x2de7a4 vldr s13, [sp, #24]
 *   @0x2de7a8 vmul.f32 s12, s31, s13
 *   @0x2de7ac vldr s14, [sp, #20]
 *   @0x2de7b0 add r3, sp, #104
 *   @0x2de7b4 add r0, sp, #128
 *   @0x2de7b8 mov r1, #0
 *   @0x2de7bc vstr s23, [r8, #40]
 *   @0x2de7c0 vmov.f32 s15, #5.000000e-01
 *   @0x2de7c4 vadd.f32 s26, s28, s26
 *   @0x2de7c8 vadd.f32 s25, s27, s25
 *   @0x2de7cc vmla.f32 s12, s20, s14
 *   @0x2de7d0 vmul.f32 s26, s26, s15
 *   @0x2de7d4 vmul.f32 s15, s25, s15
 *   @0x2de7d8 vstr s26, [r8, #48]
 *   @0x2de7dc vneg.f32 s22, s22
 *   @0x2de7e0 vstr s15, [r8, #52]
 *   @0x2de7e4 vstr s22, [r8, #44]
 *   @0x2de7e8 vldr s13, [r3, #-4]
 *   @0x2de7ec vmul.f32 s15, s31, s13
 *   @0x2de7f0 vldr s14, [r3, #-8]
 *   @0x2de7f4 add r2, r1, r1, lsl #2
 *   @0x2de7f8 add r2, r8, r2, lsl #2
 *   @0x2de7fc vmla.f32 s15, s20, s14
 *   @0x2de800 vsub.f32 s15, s15, s12
 *   @0x2de804 vcmpe.f32 s16, s15
 *   @0x2de808 vmrs APSR_nzcv, fpscr
 *   @0x2de80c blt 0x2de848 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x3e4>
 *   @0x2de810 vsub.f32 s13, s13, s29
 *   @0x2de814 vldr s11, [sp, #28]
 *   @0x2de818 ldr r12, [r3]
 *   @0x2de81c cmp r4, #0
 *   @0x2de820 add r1, r1, #1
 *   @0x2de824 str r12, [r2, #0x10]
 *   @0x2de828 vmul.f32 s15, s13, s21
 *   @0x2de82c vmul.f32 s13, s13, s19
 *   @0x2de830 vsub.f32 s14, s14, s30
 *   @0x2de834 vmla.f32 s15, s14, s19
 *   @0x2de838 vmla.f32 s13, s14, s11
 *   @0x2de83c vstr s15, [r2]
 *   @0x2de840 vstr s13, [r2, #4]
 *   @0x2de844 bne 0x2de8a0 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x43c>
 *   @0x2de848 add r3, r3, #12
 *   @0x2de84c cmp r3, r0
 *   @0x2de850 bne 0x2de7e8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x384>
 *   @0x2de854 str r1, [r8, #0x3c]
 *   @0x2de858 b 0x2de4b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x54>
 *   @0x2de85c mov r3, r6
 *   @0x2de860 vldr s14, [r9]
 *   @0x2de864 vldr s15, [r9, #4]
 *   @0x2de868 mov r6, r7
 *   @0x2de86c vldr s18, [r9, #8]
 *   @0x2de870 mov r7, r3
 *   @0x2de874 vldr s17, [r9, #12]
 *   @0x2de878 vldr s30, [r5]
 *   @0x2de87c vldr s29, [r5, #4]
 *   @0x2de880 vldr s21, [r5, #8]
 *   @0x2de884 vldr s19, [r5, #12]
 *   @0x2de888 mov r3, #1
 *   @0x2de88c ldr r10, [sp, #0x20]
 *   @0x2de890 vstr s14, [sp, #16]
 *   @0x2de894 vstr s15, [sp, #12]
 *   @0x2de898 str r3, [r8, #0x38]
 *   @0x2de89c b 0x2de53c <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0xd8>
 *   @0x2de8a0 ldrb r7, [r2, #0x10]
 *   @0x2de8a4 ldrb r6, [r2, #0x11]
 *   @0x2de8a8 ldrb r5, [r2, #0x12]
 *   @0x2de8ac ldrb r12, [r2, #0x13]
 *   @0x2de8b0 strb r7, [r2, #0x11]
 *   @0x2de8b4 strb r6, [r2, #0x10]
 *   @0x2de8b8 strb r5, [r2, #0x13]
 *   @0x2de8bc strb r12, [r2, #0x12]
 *   @0x2de8c0 b 0x2de848 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x3e4>
 *   @0x2de8c4 mov r12, #0
 *   @0x2de8c8 mov r3, r12
 *   @0x2de8cc b 0x2de5e4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x180>
 *   @0x2de8d0 mov r2, r1
 *   @0x2de8d4 mov r12, r1
 *   @0x2de8d8 mov r3, r1
 *   @0x2de8dc b 0x2de5e4 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x180>
 *   @0x2de8e0 svclo #0x7ae148
 *   @0x2de8e4 blo 0xfe3a32a8 <b2_toiTime+0xfffffffffdc49e04>
 *   @0x2de8e8 svcvc #0x7fffff
 *   @0x2de8ec strlo r0, [r0], #-0
 *   @0x2de8f0 vmov r0, s14
 *   @0x2de8f4 bl 0xb6700 <sqrtf@plt>
 *   @0x2de8f8 vmov s15, r0
 *   @0x2de8fc b 0x2de6b8 <_Z17b2CollidePolygonsP10b2ManifoldPK14b2PolygonShapeRK11b2TransformS3_S6_+0x254>
 */
