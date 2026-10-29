/* cally 逆向卡：All_15 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 8 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/8 anon_2f1de8  0x2f1de8  size 28704  7176 条（0x2f1de8..0x2f8e08）
 * @func 0x2f1de8 0x2f8e08  size 28704  7176 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xffdafe26 / 0x34be94 / 0x34c4c0 / 0x50c1e4 / 0x13f2678 / 0x38c66c / 0x3b2110 / 0x4a810c
 * 字段偏移 top8: 0x18×8 / 0x8×7 / 0x6×7 / 0x4×4 / 0xc×3 / 0xe×2 / 0x9×1 / 0x3×1
 * VFP 指令 33 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2f1de8 andhs r2, r2, #0, #6
 *   @0x2f1dec sbcvs r6, r2, r3, asr #32
 *   @0x2f1df0 bicvs r6, r3, r3, lsl #2
 *   @0x2f1df4 movtvs r6, #0x3283
 *   @0x2f1df8 strbvs r6, [r3], #1027
 *   @0x2f1dfc ldrblt r4, [r0, #-0x770]!
 *   @0x2f1e00 stmdavs r0, {r2, r9, r10, lr} ^
 *   @0x2f1e04 ldmiblt r0!, {r1, r2, r3, r9, r10, lr}
 *   @0x2f1e08 .word 0xf8504620
 *   @0x2f1e0c .word 0xf7fe5b10
 *   @0x2f1e10 .word 0xf104fbf5
 *   @0x2f1e14 strtmi r0, [r9], -r8, lsr #32
 *   @0x2f1e18 .word 0xff81f7fe
 *   @0x2f1e1c .word 0xf104b958
 *   @0x2f1e20 shasxmi r0, r1, r4
 *   @0x2f1e24 blx 0xffdafe26 <b2_toiTime+0xffffffffff656982>
 *   @0x2f1e28 subeq pc, r12, r4, lsl #2
 *   @0x2f1e2c pop {r0, r3, r5, r9, r10, lr}
 *   @0x2f1e30 .word 0xf7fe4070
 *   @0x2f1e34 ldcllt p15, c11, [r0, #-464]!
 *   @0x2f1e38 .word 0x4604b573
 *   @0x2f1e3c sadd16mi r6, r5, r0
 *   @0x2f1e40 .word 0xf7f2460e
 *   @0x2f1e44 strne pc, [r0], #-3947
 *   @0x2f1e48 stmdavs r8!, {r12, pc} ^
 *   @0x2f1e4c .word 0xff66f7f2
 *   @0x2f1e50 strne r6, [r0], #-2147
 *   @0x2f1e54 stmdblt r11!, {r0, r12, pc}
 *   @0x2f1e58 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2f1e5c strbtmi r2, [r11], -r1, lsl #4
 *   @0x2f1e60 .word 0xf895f7ff
 *   @0x2f1e64 ldcllt p0, c11, [r0, #-8]!
 *   @0x2f1e68 .word 0x4604b5f7
 *   @0x2f1e6c strmi r6, [pc], -r3, asr #16
 *   @0x2f1e70 stmvs r3, {r0, r1, r3, r5, r6, r7, r8, r11, r12, sp, pc} ^
 *   @0x2f1e74 blhs 0x34be94
 *   @0x2f1e78 stcge p1, c13, [r1, #-92]
 *   @0x2f1e7c .word 0xf7fe3010
 *   @0x2f1e80 .word 0xf104fbbd
 *   @0x2f1e84 shadd16mi r0, r1, r12
 *   @0x2f1e88 .word 0xf7fe462a
 *   @0x2f1e8c stmdblt r8!, {r0, r3, r4, r5, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f1e90 eorseq pc, r4, r4, lsl #2
 *   @0x2f1e94 .word 0xf7fe4639
 *   @0x2f1e98 .word 0xf104fbb1
 *   @0x2f1e9c ldrtmi r0, [r1], -r0, asr #32
 *   @0x2f1ea0 .word 0xf7fe462a
 *   @0x2f1ea4 stmdblt r8, {r0, r2, r3, r5, r10, r11, r12, sp, lr, pc}
 *   @0x2f1ea8 andhs lr, r6, r1
 *   @0x2f1eac andlt r6, r3, r0, rrx
 *   @0x2f1eb0 push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2f1eb4 .word 0x460647f3
 *   @0x2f1eb8 .word 0xf1069c0b
 *   @0x2f1ebc .word 0xf10d0a0c
 *   @0x2f1ec0 strmi r0, [r8], r4, lsl #18
 *   @0x2f1ec4 ldrmi r9, [r7], -r10, lsl #18
 *   @0x2f1ec8 .word 0xf7fe461d
 *   @0x2f1ecc uadd8mi pc, r0, r7
 *   @0x2f1ed0 strbmi r4, [r10], -r1, lsr #12
 *   @0x2f1ed4 .word 0xfc14f7fe
 *   @0x2f1ed8 teqle r1, r0, lsl #16
 *   @0x2f1edc stmdblt r11!, {r0, r1, r4, r5, r6, r7, r11, sp, lr}
 *   @0x2f1ee0 qsaxmi r4, r1, r0
 *   @0x2f1ee4 .word 0xf7fe464a
 *   @0x2f1ee8 and pc, r6, r11, lsl #24
 *   @0x2f1eec orrpl pc, r0, #-1073741824
 *   @0x2f1ef0 bllo 0x34c4c0
 *   @0x2f1ef4 movwne lr, #0x3b02
 *   @0x2f1ef8 cdpls p3, #0x0, c9, c1, c1, #0x0
 *   @0x2f1efc ldrtmi r11, [r0], -r0, lsl #22
 *   @0x2f1f00 strtmi r4, [r2], -r9, lsr #12
 *   @0x2f1f04 stc2 p7, c15, [r11], #-1016
 *   @0x2f1f08 .word 0xf007b9d0
 *   @0x2f1f0c strhs r0, [r0], #519
 *   @0x2f1f10 bl 0x50c1e4 <SrcVerts+0x69228>
 *   @0x2f1f14 blx 0x13f2678 <b2_toiTime+0xc991d4>
 *   @0x2f1f18 eorsvs pc, r5, r2, lsl #4
 *   @0x2f1f1c stmdavc pc, {r0, r2, r7, r8, r12, sp, pc}
 *   @0x2f1f20 ldmdavc lr, {r0, r8, r10, r11, r12, sp}
 *   @0x2f1f24 svclt #0xc4217
 *   @0x2f1f28 .word 0x432643a6
 *   @0x2f1f2c andsvc r1, lr, r2, asr r0
 *   @0x2f1f30 .word 0x3101bf04
 *   @0x2f1f34 rsbne r2, r4, r0, lsl #5
 *   @0x2f1f38 movwlo r11, #0x1f04
 *   @0x2f1f3c strb r2, [sp, r0, lsl #9]!
 *   @0x2f1f40 pop {r1, r12, sp, pc}
 *   @0x2f1f44 push {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2f1f48 ssub8mi r4, r7, r3
 *   @0x2f1f4c strmi r6, [r4], -r2, asr #16
 *   @0x2f1f50 stmdbvs r5, {r1, r3, r6, r7, r8, r11, r12, sp, pc}
 *   @0x2f1f54 .word 0xf8d06b46
 *   @0x2f1f58 ldmdbne r3!, {pc} ^
 *   @0x2f1f5c .word 0xd1124299
 *   @0x2f1f60 smlabbeq r4, sp, r8, lr
 *   @0x2f1f64 shadd16mi r3, r9, r0
 *   @0x2f1f68 .word 0xf7ff462b
 *   @0x2f1f6c stmdblt r8, {r1, r5, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f1f70 smlabbeq r1, sp, r8, lr
 *   @0x2f1f74 .word 0xf1044639
 *   @0x2f1f78 qasxmi r0, r10, r4
 *   @0x2f1f7c .word 0xf7ff4633
 *   @0x2f1f80 swplt pc, r8, [r0]
 *   @0x2f1f84 andlt r6, r2, r0, rrx
 *   @0x2f1f88 ldrhhi lr, [r0, #141]!
 *   @0x2f1f8c mvnsmi lr, sp, lsr #18
 *   @0x2f1f90 stmdavs r3, {r1, r2, r3, r4, r9, r10, lr} ^
 *   @0x2f1f94 strmi r4, [r8], r4, lsl #12
 *   @0x2f1f98 stmdbvs r3, {r0, r1, r3, r4, r6, r7, r8, r11, r12, sp, pc}
 *   @0x2f1f9c stmdavs r7, {r0, r2, r6, r8, r9, r11, sp, lr}
 *   @0x2f1fa0 addmi r1, r10, #15269888
 *   @0x2f1fa4 qadd16mi sp, r10, r5
 *   @0x2f1fa8 andhi pc, r0, sp, asr #17
 *   @0x2f1fac andslo r9, r0, r1, lsl #14
 *   @0x2f1fb0 .word 0xf7ff4631
 *   @0x2f1fb4 .word 0x4602ff7e
 *   @0x2f1fb8 .word 0xf8cdb950
 *   @0x2f1fbc .word 0xf1048000
 *   @0x2f1fc0 smladxls r1, r4, r0, r0
 *   @0x2f1fc4 qasxmi r4, r11, r1
 *   @0x2f1fc8 .word 0xff73f7ff
 *   @0x2f1fcc .word 0xb1004602
 *   @0x2f1fd0 andlt r6, r2, r2, rrx
 *   @0x2f1fd4 ldrhhi lr, [r0, #141]!
 *   @0x2f1fd8 stmdavs r10, {r0, r1, r11, sp, lr}
 *   @0x2f1fdc andmi pc, r0, r3, lsr #32
 *   @0x2f1fe0 .word 0x4100f022
 *   @0x2f1fe4 svclt #0x84288
 *   @0x2f1fe8 stmdale r4, {r0, r1, r4, r7, r9, lr}
 *   @0x2f1fec andhs r11, r0, r12, lsr #30
 *   @0x2f1ff0 andeq pc, r0, pc, rrx
 *   @0x2f1ff4 andhs r4, r1, r0, ror r7
 *   @0x2f1ff8 ldrlt r4, [r0, #-0x770]!
 *   @0x2f1ffc stmdbvs r3, {r2, r8, r11, sp, lr} ^
 *   @0x2f2000 .word 0xf1042000
 *   @0x2f2004 .word 0x3c015400
 *   @0x2f2008 strbeq lr, [r4], #2819
 *   @0x2f200c ldmdale r8, {r0, r1, r5, r7, r9, lr}
 *   @0x2f2010 smulwtne sp, r5, r10
 *   @0x2f2014 sbceq lr, r5, #3072
 *   @0x2f2018 eorspl pc, r5, r3, asr r8
 *   @0x2f201c andsle r4, r2, sp, lsl #5
 *   @0x2f2020 strmi pc, [r0, #-0x25]
 *   @0x2f2024 andle r4, r6, sp, lsl #5
 *   @0x2f2028 andle r4, r10, r3, lsr #5
 *   @0x2f202c andle r4, r5, #-805306360
 *   @0x2f2030 movweq pc, #0x8102
 *   @0x2f2034 adcmi lr, r3, #61341696
 *   @0x2f2038 ldrmi sp, [r0], -r5
 *   @0x2f203c streq pc, [r8], #-418
 *   @0x2f2040 tstlt r0, r4, ror #15
 *   @0x2f2044 ldmdavs r0, {r1, r9, r10, lr} ^
 *   @0x2f2048 ldclt p13, c11, [r0, #-192]!
 *   @0x2f204c mvnsmi lr, sp, lsr #18
 *   @0x2f2050 stmdbvs r7, {r8, r9, sp}
 *   @0x2f2054 stmdavs r10, {r1, r2, r9, r10, lr}
 *   @0x2f2058 andlo r4, r1, #24, #12
 *   @0x2f205c adcmi r4, r11, #63963136
 *   @0x2f2060 bne 0xffe268cc <b2_toiTime+0xffffffffff6cd428>
 *   @0x2f2064 ldrsbhi pc, [r4], -r6
 *   @0x2f2068 ldrbeq lr, [r4], #-2819
 *   @0x2f206c vstmiaeq r4, {d30, d31}
 *   @0x2f2070 eorshi pc, r4, r8, asr r8
 *   @0x2f2074 swple r4, r0, [r2]
 *   @0x2f2078 .word 0x0004f8dc
 *   @0x2f207c .word 0xf028e018
 *   @0x2f2080 ldrmi r4, [r0, #0x800]
 *   @0x2f2084 .word 0xf8dcd102
 *   @0x2f2088 and r0, r2, r4
 *   @0x2f208c stclne p15, c11, [r3], #-240
 *   @0x2f2090 strtmi r4, [r5], -r12, lsr #12
 *   @0x2f2094 ldmdblt r8, {r0, r1, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x2f2098 andle r4, r8, #-1342177269
 *   @0x2f209c bl 0x38c66c <_ZTS7CBucketILj16384ELj262144ELb1EE+0x6c8>
 *   @0x2f20a0 .word 0xf85200c3
 *   @0x2f20a4 stmdavs r0, {r0, r1, r4, r5, sp} ^
 *   @0x2f20a8 andmi pc, r0, #34
 *   @0x2f20ac strmi lr, [r2], -r0
 *   @0x2f20b0 pop {r1, r3, sp, lr}
 *   @0x2f20b4 strdeq r8, r9, [r0], -r0
 *   @0x2f20b8 .word 0xf5b04b06
 *   @0x2f20bc svclt #0x287f81
 *   @0x2f20c0 ldrbtmi r2, [r11], #-0
 *   @0x2f20c4 rfedb r3!
 *   @0x2f20c8 blmi 0x3b2110 <error_g0017+0xadb4>
 *   @0x2f20cc ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x2f20d0 .word 0x47704418
 *   @0x2f20d4 andeq pc, pc, r10, lsl #22
 *   @0x2f20d8 andeq pc, pc, r4, lsl #22
 *   @0x2f20dc svcvc #0xc3f5b0
 *   @0x2f20e0 blmi 0x4a810c <SrcVerts+0x5150>
 *   @0x2f20e4 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x2f20e8 andseq pc, r0, r3, lsr r9
 *   @0x2f20ec ldrbtmi r4, [r11], #-2820
 *   @0x2f20f0 ldrmi r6, [r8], #-2075
 *   @0x2f20f4 andhs r4, r0, r0, ror r7
 *   @0x2f20f8 svclt #0x4770
 *   @0x2f20fc .word 0x000ffaf0
 *   @0x2f2100 andeq pc, pc, r2, ror #21
 *   @0x2f2104 ldrbtmi r4, [r8], #-2049
 *   @0x2f2108 stmdblt r3!, {r0, r1, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc}
 *   @0x2f210c strdeq r6, r7, [pc], -r10
 *   @0x2f2110 mvnsmi lr, sp, lsr #18
 *   @0x2f2114 .word 0xf8902534
 *   @0x2f2118 strhs r12, [r0], -r0
 *   @0x2f211c ble 0x16c2bdc <b2_toiTime+0xf69738>
 *   @0x2f2120 bmi 0xd386f8 <b2_toiTime+0x5df254>
 *   @0x2f2124 ldrbtmi r1, [r10], #-100
 *   @0x2f2128 ldcne p8, c6, [r3], {18}
 *   @0x2f212c stmdaeq r4, {r0, r1, r8, r9, r11, sp, lr, pc} ^
 *   @0x2f2130 andsvc pc, r4, r3, lsl r8
 *   @0x2f2134 mullo r1, r8, r8
 *   @0x2f2138 strhs lr, [r7, -r3, asr #20]
 *   @0x2f213c ldcpl p8, c1, [pc], #748
 *   @0x2f2140 ldrbeq pc, [pc, -r7]!
 *   @0x2f2144 .word 0xd1014567
 *   @0x2f2148 and r3, pc, r1
 *   @0x2f214c strtmi r11, [r5], -r12, lsr #31
 *   @0x2f2150 strb r1, [r3, r6, ror #24]!
 *   @0x2f2154 andlo r7, r1, r6, lsr #16
 *   @0x2f2158 mulmi r0, r3, r9
 *   @0x2f215c ldmdavc r12, {r10, r11, sp} ^
 *   @0x2f2160 .word 0xf004da15
 *   @0x2f2164 adcmi r0, r6, #2130706432
 *   @0x2f2168 movwlo sp, #0x112a
 *   @0x2f216c strmi r4, [r4], -r8, lsl #5
 *   @0x2f2170 .word 0xf993d3f0
 *   @0x2f2174 bhs 0x2fa17c <ps_hints_apply+0x8d7c>
 *   @0x2f2178 .word 0xf993db22
 *   @0x2f217c bhs 0x2fa188 <ps_hints_apply+0x8d88>
 *   @0x2f2180 ldmvc r8, {r1, r2, r3, r4, r9, r11, r12, lr, pc}
 *   @0x2f2184 b 0x13d04f8 <b2_toiTime+0xc77054>
 *   @0x2f2188 ldm sp!, {sp}
 *   @0x2f218c .word 0xf00481f0
 *   @0x2f2190 qsub16eq r0, r4, pc
 *   @0x2f2194 movwlo r11, #0x1f54
 *   @0x2f2198 ldclne p3, c3, [r12], {3}
 *   @0x2f219c strmi r2, [r12, #0x500]!
 *   @0x2f21a0 .word 0xf814d00e
 *   @0x2f21a4 strlo r7, [r1, #-0xc02]
 *   @0x2f21a8 .word 0x3c01f814
 *   @0x2f21ac b 0x13bf1bc <b2_toiTime+0xc65d18>
 *   @0x2f21b0 ldmibne r3, {r0, r1, r2, r8, r9, r10, sp} ^
 *   @0x2f21b4 .word 0xf0075dd7
 *   @0x2f21b8 adcsmi r0, lr, #33292288
 *   @0x2f21bc ldrb sp, [r5, pc, ror #3]
 *   @0x2f21c0 ldm sp!, {sp}
 *   @0x2f21c4 svclt #0x81f0
 *   @0x2f21c8 strheq pc, [pc], -r2
 *   @0x2f21cc stmdavc r3, {r4, r5, r6, r8, r10, r12, sp, pc}
 *   @0x2f21d0 .word 0xd12d2b75
 *   @0x2f21d4 blhs 0x1e902e8 <b2_toiTime+0x1736e44>
 *   @0x2f21d8 stmvc r3, {r3, r4, r8, r12, lr, pc}
 *   @0x2f21dc tstle r5, r9, ror #22
 *   @0x2f21e0 stclne p12, c1, [r5, #776]
 *   @0x2f21e4 .word 0xf8122300
 *   @0x2f21e8 .word 0xf1a44b01
 *   @0x2f21ec stmdbhs r9, {r4, r5, r8}
 *   @0x2f21f0 .word 0xf1a4d904
 *   @0x2f21f4 stmdbhs r5, {r0, r6, r8}
 *   @0x2f21f8 .word 0x310ad808
 *   @0x2f21fc bl 0x342cac
 *   @0x2f2200 mvnsle r1, r3, lsl #6
 *   @0x2f2204 .word 0xb3a27812
 *   @0x2f2208 andsle r2, r12, lr, lsr #20
 *   @0x2f220c andhs r1, r6, #16640
 *   @0x2f2210 strmi r2, [r12], -r0, lsl #6
 *   @0x2f2214 stmdavc r6!, {r0, r8, r12, sp}
 *   @0x2f2218 ldreq pc, [r0, #-0x1a6]!
 *   @0x2f221c stmdble r9, {r0, r3, r8, r10, r11, sp}
 *   @0x2f2220 strbeq pc, [r1, #-0x1a6]
 *   @0x2f2224 stmdale r1, {r0, r2, r8, r10, r11, sp}
 *   @0x2f2228 and r3, r3, r10, lsl #10
 *   @0x2f222c vstrle s4, [r6, #-8]
 *   @0x2f2230 and r4, lr, r1, lsl #12
 *   @0x2f2234 bl 0x440a40 <g_RomDisk+0x49220>
 *   @0x2f2238 strmi r1, [r12], -r3, lsl #6
 *   @0x2f223c stmdavc r2!, {r0, r3, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2f2240 bhs 0xe9e930 <b2_toiTime+0x74548c>
 *   @0x2f2244 .word 0xf043d1f4
 *   @0x2f2248 ldcllt p0, c4, [r0, #-0]!
 *   @0x2f224c andle r2, r4, lr, lsr #22
 *   @0x2f2250 stmdavc r11, {r0, r8, r12, sp}
 *   @0x2f2254 mvnsle r2, r0, lsl #22
 *   @0x2f2258 addmi lr, r1, #2
 *   @0x2f225c strd sp, lr, [r5], -r8
 *   @0x2f2260 andle r4, r4, #136, #4
 *   @0x2f2264 ldrhtmi lr, [r0], #-141
 *   @0x2f2268 svclt #0x52f7ff
 *   @0x2f226c andhs r11, r0, r9, lsl r9
 *   @0x2f2270 ssub16mi r11, r8, r0
 *   @0x2f2274 addmi r11, r8, #112, #26
 *   @0x2f2278 .word 0xf7ffd202
 *   @0x2f227c and pc, r0, r9, asr #30
 *   @0x2f2280 .word 0xf0402000
 *   @0x2f2284 ldcllt p0, c4, [r0, #-0]!
 *   @0x2f2288 svcmi #0xf0e92d
 *   @0x2f228c .word 0xf10db09f
 *   @0x2f2290 strmi r0, [sp], -r8, lsr #16
 *   @0x2f2294 ldrmi r4, [r7], -r1, lsl #13
 *   @0x2f2298 eorhs r2, r8, #0, #2
 *   @0x2f229c movwls r4, #0x6640
 *   @0x2f22a0 stmib r6, {r2, r6, r7, r8, r10, r12, sp, lr, pc}
 *   @0x2f22a4 blge 0x53aaac <obj_numb_event+0x3b3c>
 *   @0x2f22a8 movwls r6, #0x512a
 *   @0x2f22ac movwls r4, #0x1648
 *   @0x2f22b0 .word 0x616a2108
 *   @0x2f22b4 movweq pc, #0xa107
 *   @0x2f22b8 .word 0xf7f59200
 *   @0x2f22bc cdpls p14, #0x0, c15, c9, c8, #0x7
 *   @0x2f22c0 .word 0x61684604
 *   @0x2f22c4 .word 0xf0402e00
 *   @0x2f22c8 .word 0xf8df808a
 *   @0x2f22cc blmi 0x14de744 <b2_toiTime+0xd852a0>
 *   @0x2f22d0 ldrbtmi r4, [r11], #-1275
 *   @0x2f22d4 adcsmi r9, lr, #469762048
 *   @0x2f22d8 stmdals r9!, {r0, r3, r6, r12, lr, pc}
 *   @0x2f22dc blls 0x483ba8 <g_matstack+0x4c>
 *   @0x2f22e0 pkhbtmi r4, r2, r8, lsl #15
 *   @0x2f22e4 suble r2, r0, r0, lsl #16
 *   @0x2f22e8 .word 0xf10b2300
 *   @0x2f22ec b 0x16b2854 <b2_toiTime+0xf593b0>
 *   @0x2f22f0 movwls r0, #0x4c83
 *   @0x2f22f4 eoreq pc, r3, r1, asr r8
 *   @0x2f22f8 .word 0xf8cd4651
 *   @0x2f22fc ldrbmi r12, [r8], #-12
 *   @0x2f2300 ldmdb r8!, {r2, r6, r7, r8, r10, r12, sp, lr, pc}
 *   @0x2f2304 .word 0xf8dd9b04
 *   @0x2f2308 ldmdblt r0, {r2, r3, lr, pc} ^
 *   @0x2f230c andlo pc, r12, r8, asr r8
 *   @0x2f2310 movwhs r11, #0x1953
 *   @0x2f2314 andlo pc, r12, r8, asr #16
 *   @0x2f2318 strbtmi r10, [r3], #-2846
 *   @0x2f231c stcvs p8, c15, [r8], #-268
 *   @0x2f2320 movwlo lr, #0x1002
 *   @0x2f2324 mvnle r2, r10, lsl #22
 *   @0x2f2328 .word 0xf7ff4650
 *   @0x2f232c .word 0xf020ff4f
 *   @0x2f2330 .word 0xb1ab4300
 *   @0x2f2334 .word 0xf8dd2300
 *   @0x2f2338 addseq lr, r9, r12, lsl r0
 *   @0x2f233c addeq pc, r0, #-2147483645
 *   @0x2f2340 eorhs pc, r3, r2, asr r8
 *   @0x2f2344 swple r4, r0, [r5]
 *   @0x2f2348 strmi r10, [r11], #-2846
 *   @0x2f234c .word 0xf8432102
 *   @0x2f2350 and r1, r2, r0, asr r12
 *   @0x2f2354 blhs 0x57ef60 <g_SWFlineaavertbuff+0x2be98>
 *   @0x2f2358 stm r4, {r0, r2, r3, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2f235c strlo r0, [r8], #-65
 *   @0x2f2360 tstlt r3, r8, lsr #22
 *   @0x2f2364 ldrbmi r9, [r1], -r9, lsr #16
 *   @0x2f2368 .word 0x36014798
 *   @0x2f236c stmdbmi r0!, {r0, r1, r4, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2f2370 ldrbtmi r2, [r9], #-768
 *   @0x2f2374 andhs pc, r3, r8, asr r8
 *   @0x2f2378 .word 0xd1092a01
 *   @0x2f237c addeq pc, r0, #1073741824
 *   @0x2f2380 ldmpl r10, {r3, r10, r12, sp}
 *   @0x2f2384 .word 0x2c08f844
 *   @0x2f2388 ldmpl r10, {r2, r4, r9, r11, sp, pc}
 *   @0x2f238c .word 0x2c04f844
 *   @0x2f2390 blhs 0xcfefa8 <b2_toiTime+0x5a5b04>
 *   @0x2f2394 stmdbvs r9!, {r1, r2, r3, r5, r6, r7, r8, r12, lr, pc} ^
 *   @0x2f2398 rscne r1, r4, r4, ror #20
 *   @0x2f239c strbmi sp, [r8], -r8, lsl #2
 *   @0x2f23a0 .word 0xffc9f7f4
 *   @0x2f23a4 .word 0x616c9b09
 *   @0x2f23a8 .word 0x23a3b9c3
 *   @0x2f23ac ands r9, r5, r9, lsl #6
 *   @0x2f23b0 svceq #0x57ebb4
 *   @0x2f23b4 .word 0x9100d20b
 *   @0x2f23b8 strbmi r10, [r8], -r9, lsl #22
 *   @0x2f23bc .word 0x21089301
 *   @0x2f23c0 ldrtmi r4, [r10], -r3, lsr #12
 *   @0x2f23c4 mcr2 p7, #0x3, pc, c3, c5, #0x7
 *   @0x2f23c8 movwls r2, #0x9300
 *   @0x2f23cc blmi 0x54a974 <gp_ActiveMaskObjects+0x5cac>
 *   @0x2f23d0 stmdbvs r8!, {r0, r5, r9, r10, lr} ^
 *   @0x2f23d4 ldrbtmi r2, [r11], #-520
 *   @0x2f23d8 stmib r0, {r2, r6, r7, r8, r10, r12, sp, lr, pc}
 *   @0x2f23dc stmdals r9, {r2, r3, r5, r8, sp, lr}
 *   @0x2f23e0 pop {r0, r1, r2, r3, r4, r12, sp, pc}
 *   @0x2f23e4 svclt #0x8ff0
 *   @0x2f23e8 andeq lr, r9, r8, lsr #11
 *   @0x2f23ec andeq lr, r9, r6, lsr #11
 *   @0x2f23f0 andeq lr, r9, r6, lsl #10
 *   @0x2f23f4 .word 0xfffffbff
 *   @0x2f23f8 stmvs r1, {r1, r8, r11, sp, lr}
 *   @0x2f23fc andvs r6, r2, #196608
 *   @0x2f2400 strmi r4, [r11], #-1034
 *   @0x2f2404 bl 0x38c710 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x76c>
 *   @0x2f2408 bl 0x3cef58 <error_g0017+0x27bfc>
 *   @0x2f240c ldrsbne r7, [r2], #-51
 *   @0x2f2410 subsne r6, r11, r2, lsl #3
 *   @0x2f2414 ldrmi r6, [r3], #-131
 *   @0x2f2418 bl 0x3cc928 <error_g0017+0x255cc>
 *   @0x2f241c subvs r7, r2, #1275068419
 *   @0x2f2420 subsne r4, r11, r10, lsl #8
 *   @0x2f2424 stmdavs r3, {r0, r1, r8, sp, lr} ^
 *   @0x2f2428 sbcsvc lr, r2, #2048
 *   @0x2f242c subsne r4, r2, r11, lsl #8
 *   @0x2f2430 bl 0x3cab40 <error_g0017+0x237e4>
 *   @0x2f2434 ldrsbne r7, [r11], #-51
 *   @0x2f2438 ldrmi r6, [r3], #-195
 *   @0x2f243c bicsvc lr, r3, #3072
 *   @0x2f2440 qdaddvs r1, r11, r3
 *   @0x2f2444 ldrblt r4, [r0, #-0x770]!
 *   @0x2f2448 stmvs r6, {r2, r7, r8, r11, sp, lr}
 *   @0x2f244c stmdavs r2, {r0, r2, r8, r11, sp, lr}
 *   @0x2f2450 movwvs r1, #0x4971
 *   @0x2f2454 strtmi r4, [r12], #-1074
 *   @0x2f2458 strlo r3, [r1], #-513
 *   @0x2f245c stmvs r6, {r0, r8, r12, sp} ^
 *   @0x2f2460 subsne r1, r2, r4, rrx
 *   @0x2f2464 addvs r1, r2, r9, asr #32
 *   @0x2f2468 strmi r1, [r10], #-2147
 *   @0x2f246c movwlo r3, #0x1201
 *   @0x2f2470 subsne r6, r2, r4, lsl #5
 *   @0x2f2474 subsne r6, r11, r4, asr #19
 *   @0x2f2478 .word 0x61026945
 *   @0x2f247c ldrmi r6, [r3], #-515
 *   @0x2f2480 ldmdbne r1!, {r1, r6, r11, sp, lr} ^
 *   @0x2f2484 strtmi r6, [r12], #-836
 *   @0x2f2488 strlo r4, [r1], #-1074
 *   @0x2f248c .word 0x31013201
 *   @0x2f2490 rsbne r3, r4, r1, lsl #6
 *   @0x2f2494 subne r1, r9, r2, asr r0
 *   @0x2f2498 sbcvs r1, r2, r11, asr r0
 *   @0x2f249c strmi r6, [r10], #-387
 *   @0x2f24a0 andlo r1, r1, #6488064
 *   @0x2f24a4 sbcvs r3, r4, #67108864
 *   @0x2f24a8 qdaddvs r1, r2, r2
 *   @0x2f24ac subvs r1, r3, #91
 *   @0x2f24b0 movwlo r4, #0x1413
 *   @0x2f24b4 bicvs r1, r3, r11, asr r0
 *   @0x2f24b8 svcvs #0x3bd70
 *   @0x2f24bc .word 0xf8a0425a
 *   @0x2f24c0 rfeib r1!
 *   @0x2f24c4 blhs 0x2fa4cc <ps_hints_apply+0x90cc>
 *   @0x2f24c8 andeq pc, r0, #-2147483600
 *   @0x2f24cc .word 0xf202fb03
 *   @0x2f24d0 addshs pc, r4, r0, asr #17
 *   @0x2f24d4 cdpvs p13, #0x8, c13, c1, c5, #0x0
 *   @0x2f24d8 blx 0x3c08e6 <error_g0017+0x1958a>
 *   @0x2f24dc .word 0xf8c02301
 *   @0x2f24e0 .word 0x47703094
 *   @0x2f24e4 svcls #0x5b5f0
 *   @0x2f24e8 stmdavs r5, {r2, r6, r11, sp, lr}
 *   @0x2f24ec ldmdbne r1, {r0, r1, r2, r3, r4, r5, r7, r8, r11, pc}
 *   @0x2f24f0 stmdblo r1, {r1, r2, r5, r6, r9, lr}
 *   @0x2f24f4 streq pc, [r7, -r7]
 *   @0x2f24f8 svchs #0x24031
 *   @0x2f24fc .word 0xf105fa41
 *   @0x2f2500 bne 0xfe9a6518 <b2_toiTime+0xfffffffffe24d074>
 *   @0x2f2504 blne 0x80ca28 <b2_toiTime+0xb3584>
 *   @0x2f2508 stcle p2, c4, [r2, #-752]
 *   @0x2f250c .word 0x412b4033
 *   @0x2f2510 strmi lr, [r11], -r0
 *   @0x2f2514 blle 0xfbd11c <b2_toiTime+0x863c78>
 *   @0x2f2518 addsmi r8, r1, #2, #30
 *   @0x2f251c addsmi sp, r3, #48, #20
 *   @0x2f2520 mvnvc lr, r1, lsr #20
 *   @0x2f2524 .word 0xf102bfa8
 *   @0x2f2528 ldrbhs r3, [pc, #-0x3ff]!
 *   @0x2f252c andeq pc, r7, #3
 *   @0x2f2530 vstmiaeq r1!, {s29, s30, s31}
 *   @0x2f2534 .word 0xf0014115
 *   @0x2f2538 .word 0xf8d00107
 *   @0x2f253c .word 0x27ff2094
 *   @0x2f2540 vst1.16 {d15, d16}, [r1], r7
 *   @0x2f2544 .word 0x03e3ebcc
 *   @0x2f2548 strbtmi r6, [r2], #-3009
 *   @0x2f254c b 0x1ebd154 <b2_toiTime+0x1763cb0>
 *   @0x2f2550 rsclt r0, r4, #20971520
 *   @0x2f2554 bl 0x35f110 <_ZTS12CDS_Priority+0x1168>
 *   @0x2f2558 stcpl p6, c0, [r8], {2}
 *   @0x2f255c .word 0x4320dd0d
 *   @0x2f2560 cdpne p4, #0x5, c5, c9, c8, #0x4
 *   @0x2f2564 andlo r2, r1, #0, #4
 *   @0x2f2568 mulle r1, r10, r2
 *   @0x2f256c .word 0xe7fa54b7
 *   @0x2f2570 ldmdavc r12, {r0, r1, r4, r5, r6, r11, r12} ^
 *   @0x2f2574 subsvc r4, sp, r5, lsr #6
 *   @0x2f2578 .word 0x402cbdf0
 *   @0x2f257c strpl r4, [r8], #800
 *   @0x2f2580 .word 0xf8d0bdf0
 *   @0x2f2584 push {r2, lr, pc}
 *   @0x2f2588 bl 0x38656c <_ZTS13C_UTF16String+0x1d618>
 *   @0x2f258c .word 0xf1cc040c
 *   @0x2f2590 .word 0x3c010700
 *   @0x2f2594 b 0x3c268c <error_g0017+0x1b330>
 *   @0x2f2598 adcmi r0, r12, #29360128
 *   @0x2f259c cdpls p1, #0x0, c9, c12, c1, #0x0
 *   @0x2f25a0 ldrsbtls pc, [r4], -sp
 *   @0x2f25a4 strtmi sp, [r12], #3419
 *   @0x2f25a8 strhhi pc, [r12], -r6
 *   @0x2f25ac .word 0xd16a4564
 *   @0x2f25b0 .word 0x0c07f008
 *   @0x2f25b4 svceq #0x5f1bc
 *   @0x2f25b8 ldm pc, {r0, r2, r5, r6, r11, r12, lr, pc} ^
 *   @0x2f25bc msreq CPSR_fsc, #12
 *   @0x2f25c0 .word 0x03246464
 *   @0x2f25c4 strbmi r6, [r9, #-0x9f1]
 *   @0x2f25c8 ldmdbvs r1!, {r1, r3, r8, r12, lr, pc}
 *   @0x2f25cc .word 0xdc072900
 *   @0x2f25d0 svceq #0x10f018
 *   @0x2f25d4 stmvs r1, {r0, r1, r2, r4, r6, r12, lr, pc}
 *   @0x2f25d8 beq 0x3ed4e8 <_ZTIPKDi+0x4>
 *   @0x2f25dc blle 0x1783c0c <b2_toiTime+0x102a768>
 *   @0x2f25e0 ldrsbls pc, [r12], -r9
 *   @0x2f25e4 strhle r4, [r11, -r1]
 *   @0x2f25e8 .word 0xf8dd6976
 *   @0x2f25ec ldrbmi r10, [r6, #-0x4]
 *   @0x2f25f0 .word 0xf018d106
 *   @0x2f25f4 suble r0, r6, r0, lsr #30
 *   @0x2f25f8 bne 0xfea8c804 <b2_toiTime+0xfffffffffe333360>
 *   @0x2f25fc blle 0x138303c <b2_toiTime+0xc29b98>
 *   @0x2f2600 svceq #0x1f1bc
 *   @0x2f2604 ldrmi sp, [r3], #-8
 *   @0x2f2608 bllo 0x34c814
 *   @0x2f260c bicsvc lr, r3, #3072
 *   @0x2f2610 .word 0x0163eb01
 *   @0x2f2614 and r4, r0, pc
 *   @0x2f2618 svchs #0x462f
 *   @0x2f261c blle 0x4cc630 <SrcVerts+0x29674>
 *   @0x2f2620 blx 0x14d6230 <b2_toiTime+0xd7cd8c>
 *   @0x2f2624 addsmi pc, r1, #-1073741824
 *   @0x2f2628 adcmi sp, r7, #20480
 *   @0x2f262c and sp, r0, r4, lsl #2
 *   @0x2f2630 strtmi r4, [r12], -r7, lsr #12
 *   @0x2f2634 strtmi lr, [pc], -r0
 *   @0x2f2638 ldrle r4, [r1], #-284
 *   @0x2f263c addsmi r8, r12, #3, #30
 *   @0x2f2640 blvs 0xff3a8e80 <b2_toiTime+0xfffffffffec4f9dc>
 *   @0x2f2644 ldrsblo pc, [r4], r0
 *   @0x2f2648 rsceq lr, r4, #2048
 *   @0x2f264c streq pc, [r7], #-4
 *   @0x2f2650 addhs r5, r0, #54016
 *   @0x2f2654 vst1.16 {d15, d16}, [r4], r2
 *   @0x2f2658 andle r4, r1, r3, lsr #4
 *   @0x2f265c qadd16mi lr, r7, r3
 *   @0x2f2660 tstmi pc, r3, lsl #16
 *   @0x2f2664 svchi #0x3d40f
 *   @0x2f2668 ble 0x6030ec <g_SWFaavertbuff+0x30024>
 *   @0x2f266c ldrsblo pc, [r4], r0
 *   @0x2f2670 blvs 0xff37ac78 <b2_toiTime+0xfffffffffec217d4>
 *   @0x2f2674 .word 0x03e7eb03
 *   @0x2f2678 streq pc, [r7, -r7]
 *   @0x2f267c .word 0xf707fa41
 *   @0x2f2680 movwmi r5, #0xfcd1
 *   @0x2f2684 ldrdlt r5, r6, [r3], -r7
 *   @0x2f2688 svchi #0xf0e8bd
 *   @0x2f268c ldrsblo pc, [r4], r0
 *   @0x2f2690 ldrhhs pc, [r12], r0
 *   @0x2f2694 .word 0xf8c04413
 *   @0x2f2698 .word 0x47703094
 *   @0x2f269c ldrlt r4, [r0, #-0x770]!
 *   @0x2f26a0 stmdavs r4, {r0, r2, r3, r4, r7, r9, r11, r12} ^
 *   @0x2f26a4 ble 0xb83140 <b2_toiTime+0x429c9c>
 *   @0x2f26a8 rsbmi r4, r5, #570425344
 *   @0x2f26ac eormi r3, r10, r1, lsl #20
 *   @0x2f26b0 adcmi r4, r10, #29
 *   @0x2f26b4 stmdavs r3, {r0, r1, r3, r4, r8, r12, lr, pc}
 *   @0x2f26b8 ldrle r4, [r8], #-282
 *   @0x2f26bc adcmi r6, r2, #132, #28
 *   @0x2f26c0 .word 0xf001d215
 *   @0x2f26c4 strhs r0, [r0, #0x307]
 *   @0x2f26c8 svcvs #0x3411d
 *   @0x2f26cc blhs 0x30d5d4 <af_shaper_get_elem+0x2e42>
 *   @0x2f26d0 bl 0x31f28c
 *   @0x2f26d4 svclt #0xc801e1
 *   @0x2f26d8 ldrbtlo pc, [pc], #260
 *   @0x2f26dc tstne r2, r3, lsl #22
 *   @0x2f26e0 blx 0x3e260a <error_g0017+0x3b2ae>
 *   @0x2f26e4 stmdavc r10, {r2, r8, r12}
 *   @0x2f26e8 movweq lr, #0x2a45
 *   @0x2f26ec ldclt p0, c7, [r0, #-44]!
 *   @0x2f26f0 svcmi #0xf0e92d
 *   @0x2f26f4 cdpls p8, #0x0, c6, c9, c7, #0x2
 *   @0x2f26f8 .word 0xf1c719d4
 *   @0x2f26fc .word 0x3c010c00
 *   @0x2f2700 streq lr, [r12, #-0xa03]
 *   @0x2f2704 streq lr, [r12], #-2564
 *   @0x2f2708 .word 0xa028f8dd
 *   @0x2f270c stclle p2, c4, [r4, #-688]!
 *   @0x2f2710 rfeia r6!
 *   @0x2f2714 adcsmi r9, r12, #12
 *   @0x2f2718 .word 0xf009d17c
 *   @0x2f271c .word 0xf1b80807
 *   @0x2f2720 ldmdale r7!, {r0, r2, r8, r9, r10, r11} ^
 *   @0x2f2724 .word 0xf008e8df
 *   @0x2f2728 ldrbtvc r0, [r6], -r12, lsr #6
 *   @0x2f272c ldmibvs r7!, {r1, r5, r8, r9} ^
 *   @0x2f2730 qaddle r4, r7, r10
 *   @0x2f2734 svchs #0x6937
 *   @0x2f2738 .word 0xf019dc07
 *   @0x2f273c rsble r0, r9, r0, lsl pc
 *   @0x2f2740 bl 0xff38c964 <b2_toiTime+0xfffffffffec334c0>
 *   @0x2f2744 ldrmi r0, [r11, #0xb03]!
 *   @0x2f2748 .word 0xf8dadb64
 *   @0x2f274c adcsmi r7, r7, #28
 *   @0x2f2750 ldmdbvs r6!, {r0, r3, r8, r12, lr, pc} ^
 *   @0x2f2754 smlabble r6, lr, r2, r4
 *   @0x2f2758 svceq #0x20f019
 *   @0x2f275c stmvs r6, {r1, r3, r4, r6, r12, lr, pc}
 *   @0x2f2760 adcsmi r1, r7, #651264
 *   @0x2f2764 .word 0xf1b8db56
 *   @0x2f2768 andle r0, r9, r1, lsl #30
 *   @0x2f276c stmvs r6, {r0, r1, r4, r10, lr}
 *   @0x2f2770 bl 0x3c137c <error_g0017+0x1a020>
 *   @0x2f2774 bl 0x48f6c8 <prim_v+0x5d14>
 *   @0x2f2778 b 0x47410c <g_RomDisk+0x7c8ec>
 *   @0x2f277c and r0, r0, r12, lsl #24
 *   @0x2f2780 .word 0xf1bc46ac
 *   @0x2f2784 stmdavs r3, {r8, r9, r10, r11}
 *   @0x2f2788 vdivvs.f64 d13, d2, d7
 *   @0x2f278c .word 0xf603fa4c
 *   @0x2f2790 andle r4, r5, #1610612745
 *   @0x2f2794 smlatble r4, r4, r5, r4
 *   @0x2f2798 strtmi lr, [r4], r0
 *   @0x2f279c and r4, r0, r12, lsr #12
 *   @0x2f27a0 tstmi r12, r12, lsr #13
 *   @0x2f27a4 blvs 0xff3ce3b4 <b2_toiTime+0xfffffffffec74f10>
 *   @0x2f27a8 bl 0x3bcfb0 <error_g0017+0x15c54>
 *   @0x2f27ac blx 0x37373a <_ZTS13C_UTF16String+0xa7e6>
 *   @0x2f27b0 stcle p3, c3, [r3, #-80]
 *   @0x2f27b4 stclo p14, c6, [r1, #-532]
 *   @0x2f27b8 movwlo pc, #0x5b02
 *   @0x2f27bc blle 0x63d7c4 <g_SWFaavertbuff+0x6a6fc>
 *   @0x2f27c0 addsmi r6, r4, #2080
 *   @0x2f27c4 .word 0xf001d20a
 *   @0x2f27c8 strhs r0, [r0], #519
 *   @0x2f27cc blx 0x1410840 <b2_toiTime+0xcb739c>
 *   @0x2f27d0 andsmi pc, r3, #536870912
 *   @0x2f27d4 pop {r1, r12, lr, pc}
 *   @0x2f27d8 .word 0x46a48ff0
 *   @0x2f27dc blx 0x1a0c7f0 <b2_toiTime+0x12b334c>
 *   @0x2f27e0 ldrle pc, [r7], #-3075
 *   @0x2f27e4 strmi r6, [r4, #0xe84]!
 *   @0x2f27e8 blvs 0xff3e7040 <b2_toiTime+0xfffffffffec8db9c>
 *   @0x2f27ec bl 0x3bb1f4 <error_g0017+0x13e98>
 *   @0x2f27f0 .word 0xf00103e1
 *   @0x2f27f4 blx 0x1372c18 <b2_toiTime+0xc19774>
 *   @0x2f27f8 svcvs #0x2f101
 *   @0x2f27fc sbclt r2, r9, #0, #20
 *   @0x2f2800 tstlo r12, #2048
 *   @0x2f2804 .word 0xf104bfc4
 *   @0x2f2808 blx 0x37fc0e <_ZTS13C_UTF16String+0x16cba>
 *   @0x2f280c ldmdavc r10, {r2, r8, r9, r12, sp}
 *   @0x2f2810 andsvc r4, r9, r1, lsl r3
 *   @0x2f2814 svchi #0xf0e8bd
 *   @0x2f2818 .word 0x47704770
 *   @0x2f281c ldrbmi r2, [r0, -r0]!
 *   @0x2f2820 stmvs r2, {r4, r8, r10, r12, sp, pc} ^
 *   @0x2f2824 blvs 0x130c938 <b2_toiTime+0xbb3494>
 *   @0x2f2828 .word 0xf8d36b92
 *   @0x2f282c ldmvs r4, {r2, r5, r7, r12}
 *   @0x2f2830 .word 0x20a8f8d3
 *   @0x2f2834 andhs r4, r0, r0, lsr #15
 *   @0x2f2838 strlt r11, [r8, #-0xd10]
 *   @0x2f283c blvs 0x130cb50 <b2_toiTime+0xbb36ac>
 *   @0x2f2840 ldmvs r11, {r0, r1, r3, r4, r7, r8, r9, r11, sp, lr} ^
 *   @0x2f2844 stclt p7, c4, [r8, #-608]
 *   @0x2f2848 stmdavs r0, {r0, r9, r10, lr}
 *   @0x2f284c ldcllt p7, c15, [r3, #-976]!
 *   @0x2f2850 movwhs r11, #0x537
 *   @0x2f2854 andvs r4, r11, r12, lsl #12
 *   @0x2f2858 bl 0x63ac70 <g_SWFaavertbuff+0x67ba8>
 *   @0x2f285c strmi r0, [r5], -r1, lsl #4
 *   @0x2f2860 stc2l p7, c15, [r1], #-976
 *   @0x2f2864 stmdblt r11, {r0, r8, r9, r11, r12, pc}
 *   @0x2f2868 eorvs r6, r0, r5
 *   @0x2f286c andlt r9, r3, r1, lsl #16
 *   @0x2f2870 ldrblt r11, [r0, #-0xd30]!
 *   @0x2f2874 strmi r4, [sp], -r6, lsl #12
 *   @0x2f2878 sadd16mi r4, r4, r0
 *   @0x2f287c andshs r2, r0, #0, #2
 *   @0x2f2880 cdp p5, #0x9, c15, c6, c3, #0x6
 *   @0x2f2884 ldmdbvs r2!, {r0, r1, r3, r5, r7, r10, r11, sp, lr}
 *   @0x2f2888 swple r4, r3, [r6]
 *   @0x2f288c rsbeq pc, r12, r5, lsl #2
 *   @0x2f2890 pop {r0, r5, r9, r10, lr}
 *   @0x2f2894 .word 0xf7f34070
 *   @0x2f2898 ldcllt p13, c11, [r0, #-612]!
 *   @0x2f289c svcmi #0xf0e92d
 *   @0x2f28a0 strmi r4, [r12], -r1, lsl #13
 *   @0x2f28a4 .word 0xf8d96c88
 *   @0x2f28a8 addslt r1, r7, r0, lsl r0
 *   @0x2f28ac smlalbble r4, r8, r8, r2
 *   @0x2f28b0 .word 0xf0402a02
 *   @0x2f28b4 .word 0xf10480a2
 *   @0x2f28b8 .word 0xb123066c
 *   @0x2f28bc ldm r3, {r4, r5, r9, r10, lr}
 *   @0x2f28c0 .word 0xf7f30006
 *   @0x2f28c4 ldrtmi pc, [r0], -pc, lsr #27
 *   @0x2f28c8 .word 0xf7f3a906
 *   @0x2f28cc stmdals r6, {r0, r1, r2, r3, r4, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2f28d0 .word 0xf1009908
 *   @0x2f28d4 bls 0x4b3d5c <SrcVerts+0x10da0>
 *   @0x2f28d8 stceq p1, c15, [r0], #-4
 *   @0x2f28dc ldreq pc, [pc, #-0x25]!
 *   @0x2f28e0 .word 0xf02c9b09
 *   @0x2f28e4 bl 0xff4359e8 <b2_toiTime+0xfffffffffecdc544>
 *   @0x2f28e8 .word 0xf1020c0c
 *   @0x2f28ec .word 0xf1030720
 *   @0x2f28f0 .word 0xf0270820
 *   @0x2f28f4 .word 0xf028073f
 *   @0x2f28f8 b 0x16b49fc <b2_toiTime+0xf5b558>
 *   @0x2f28fc .word 0xf1bc1bac
 *   @0x2f2900 .word 0xd1090f00
 *   @0x2f2904 bleq 0x12eed10 <b2_toiTime+0xb9586c>
 *   @0x2f2908 ldreq pc, [pc, #-0x20]!
 *   @0x2f290c bleq 0x12ee9c0 <b2_toiTime+0xb9551c>
 *   @0x2f2910 bleq 0x5ed82c <g_SWFaavertbuff+0x1a764>
 *   @0x2f2914 blne 0xfeded258 <b2_toiTime+0xfffffffffe693db4>
 *   @0x2f2918 smlabteq r8, r7, r11, lr
 *   @0x2f291c bne 0xfeb6d260 <b2_toiTime+0xfffffffffe413dbc>
 *   @0x2f2920 .word 0xf103b949
 *   @0x2f2924 .word 0xf022083f
 *   @0x2f2928 .word 0xf028073f
 *   @0x2f292c bl 0xff4b4a30 <b2_toiTime+0xfffffffffed5b58c>
 *   @0x2f2930 b 0x16b5158 <b2_toiTime+0xf5bcb4>
 *   @0x2f2934 .word 0xf64f1aaa
 *   @0x2f2938 ldrmi r7, [r11, #0x3ff]
 *   @0x2f293c ldrmi sp, [r10, #0x801]
 *   @0x2f2940 movwhs sp, #0x6902
 *   @0x2f2944 subs r9, r6, r5, lsl #6
 *   @0x2f2948 ldrsblo pc, [r12], r4
 *   @0x2f294c .word 0xc008f8d9
 *   @0x2f2950 .word 0x07db685b
 *   @0x2f2954 strbtmi sp, [r0], -pc, lsl #10
 *   @0x2f2958 .word 0xf8cd6da1
 *   @0x2f295c .word 0xf7f4c00c
 *   @0x2f2960 movwhs pc, #0xcea
 *   @0x2f2964 .word 0xf8d465a3
 *   @0x2f2968 ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^
 *   @0x2f296c andeq pc, r1, #34
 *   @0x2f2970 .word 0xf8dd605a
 *   @0x2f2974 movwhs r12, #0x100c
 *   @0x2f2978 subslo pc, lr, r4, lsl #17
 *   @0x2f297c movweq pc, #0xf10b
 *   @0x2f2980 subge pc, r12, r4, asr #17
 *   @0x2f2984 stmdbge r5, {r9, sp}
 *   @0x2f2988 .word 0x9101091b
 *   @0x2f298c subslt pc, r0, r4, asr #17
 *   @0x2f2990 subseq r4, r11, r1, asr r6
 *   @0x2f2994 strbvs r9, [r3, #-0x200]!
 *   @0x2f2998 .word 0xf7f54660
 *   @0x2f299c .word 0xf8ddfb78
 *   @0x2f29a0 strvs r10, [r0, #0x14]!
 *   @0x2f29a4 svceq #0xf1ba
 *   @0x2f29a8 .word 0xf8d4d125
 *   @0x2f29ac shadd8mi r3, r0, r12
 *   @0x2f29b0 ldmdavs r10, {r0, r3, r5, r6, r9, lr} ^
 *   @0x2f29b4 andeq pc, r1, #66
 *   @0x2f29b8 rsbsmi r6, r10, #90
 *   @0x2f29bc ldc2 p7, c15, [r2, #-972]!
 *   @0x2f29c0 movteq pc, #0xc104
 *   @0x2f29c4 movwls r10, #0xa90a
 *   @0x2f29c8 .word 0xf8d9960b
 *   @0x2f29cc .word 0xf8cd3038
 *   @0x2f29d0 .word 0xf8d9a030
 *   @0x2f29d4 .word 0x47980034
 *   @0x2f29d8 ldrtmi r4, [r10], -r9, lsr #12
 *   @0x2f29dc ldrtmi r9, [r0], -r5
 *   @0x2f29e0 stc2 p7, c15, [r0, #-972]!
 *   @0x2f29e4 ldmdblt r3!, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x2f29e8 .word 0x11ad4b06
 *   @0x2f29ec strtvs r6, [r3], #1637
 *   @0x2f29f0 .word 0x13a8ea4f
 *   @0x2f29f4 stmdals r5, {r0, r1, r5, r7, r9, r10, sp, lr}
 *   @0x2f29f8 andshs lr, r3, r0
 *   @0x2f29fc pop {r0, r1, r2, r4, r12, sp, pc}
 *   @0x2f2a00 svclt #0x8ff0
 *   @0x2f2a04 rsbvs r7, r9, #1929379840
 *   @0x2f2a08 .word 0xf5adb5f0
 *   @0x2f2a0c addlt r4, r1, r8, lsl #27
 *   @0x2f2a10 smulleq lr, r0, r1, r8
 *   @0x2f2a14 .word 0xf0002800
 *   @0x2f2a18 svchs #0x80d6
 *   @0x2f2a1c sbcshi pc, r9, r0
 *   @0x2f2a20 stmdahs r0, {r3, r4, r5, r6, r11, pc}
 *   @0x2f2a24 sbcshi pc, r6, r0
 *   @0x2f2a28 strhhs pc, [r0], -r7
 *   @0x2f2a2c vpmax.u8 d18, d0, d0
 *   @0x2f2a30 ldmvs sp!, {r1, r2, r3, r6, r7, pc} ^
 *   @0x2f2a34 .word 0xf0002d00
 *   @0x2f2a38 ldmdavs r11!, {r2, r3, r6, r7, pc} ^
 *   @0x2f2a3c .word 0xf0002b00
 *   @0x2f2a40 cps #0x8
 *   @0x2f2a44 andlt r4, r4, #0, #4
 *   @0x2f2a48 rfedb r5!
 *   @0x2f2a4c andlo r2, r1, #18
 *   @0x2f2a50 .word 0xf0404294
 *   @0x2f2a54 stmvs r10, {r1, r2, r3, r4, r5, r7, pc}
 *   @0x2f2a58 .word 0xf0400795
 *   @0x2f2a5c mcrhs p0, #0x0, r8, c0, c6, #0x5
 *   @0x2f2a60 adcshi pc, r7, r0
 *   @0x2f2a64 bhs 0x30cc34 <af_shaper_get_elem+0x24a2>
 *   @0x2f2a68 adcshi pc, r1, r0
 *   @0x2f2a6c stmdahs r0, {r4, r5, r11, sp, lr}
 *   @0x2f2a70 adcshi pc, r0, r0
 *   @0x2f2a74 bhs 0x30ce44 <af_shaper_get_elem+0x26b2>
 *   @0x2f2a78 adchi pc, r11, r0
 *   @0x2f2a7c strbeq lr, [r4], #2819
 *   @0x2f2a80 .word 0xf1a33308
 *   @0x2f2a84 addsmi r0, r4, #8, #4
 *   @0x2f2a88 .word 0xf853d911
 *   @0x2f2a8c ldrmi r2, [r9], -r8, lsl #24
 *   @0x2f2a90 addvc pc, r0, #-2147483648
 *   @0x2f2a94 svcvc #0xf1b2
 *   @0x2f2a98 addshi pc, r11, r0, lsl #4
 *   @0x2f2a9c .word 0x2c04f851
 *   @0x2f2aa0 .word 0xf1023308
 *   @0x2f2aa4 .word 0xf1b27280
 *   @0x2f2aa8 stmible r10!, {r8, r9, r10, r11, r12, sp, lr} ^
 *   @0x2f2aac svcgt #0xfe091
 *   @0x2f2ab0 strbtmi r10, [r12], -r0, lsr #26
 *   @0x2f2ab4 ldmdavs r11!, {r0, r1, r2, r3, r8, r10, lr, pc}
 *   @0x2f2ab8 ldcge p0, c6, [r10, #-172]
 *   @0x2f2abc strgt r12, [pc, #-0xe0f]
 *   @0x2f2ac0 orrvs pc, r0, #54525952
 *   @0x2f2ac4 muleq r3, r6, r8
 *   @0x2f2ac8 .word 0xf50d9307
 *   @0x2f2acc movwls r4, #0x8388
 *   @0x2f2ad0 andeq lr, r3, r5, lsl #17
 *   @0x2f2ad4 ldrbeq r9, [r8, #0xb24]
 *   @0x2f2ad8 andhs sp, r12, #25165824
 *   @0x2f2adc vst1.8 {d25, d26, d27, d28}, [pc], r0
 *   @0x2f2ae0 andls r7, r4, #128, #4
 *   @0x2f2ae4 and r2, r4, lr, lsl r2
 *   @0x2f2ae8 andls r2, r0, #1610612736
 *   @0x2f2aec andls r2, r4, #32, #4
 *   @0x2f2af0 stmdavs r1!, {r1, r9, sp}
 *   @0x2f2af4 andhs r6, r1, #-2147483624
 *   @0x2f2af8 rsbvs r4, r2, r10, lsl #1
 *   @0x2f2afc sbcsvc lr, r2, #2048
 *   @0x2f2b00 adcvs r1, r2, r2, asr r0
 *   @0x2f2b04 ldreq r1, [r9, -r10, lsl #31]
 *   @0x2f2b08 .word 0x61a260e2
 *   @0x2f2b0c andhs sp, r2, #4194304
 *   @0x2f2b10 .word 0xf013e00a
 *   @0x2f2b14 svclt #0x180210
 *   @0x2f2b18 .word 0xf8842204
 *   @0x2f2b1c .word 0x069a20b0
 *   @0x2f2b20 .word 0xf894d404
 *   @0x2f2b24 andlo r2, r1, #176
 *   @0x2f2b28 adcshs pc, r0, r4, lsl #17
 *   @0x2f2b2c movwvc pc, #0x483
 *   @0x2f2b30 .word 0xf3c32100
 *   @0x2f2b34 .word 0xf8842340
 *   @0x2f2b38 blmi 0xcfee04 <b2_toiTime+0x5a5960>
 *   @0x2f2b3c .word 0xf8c44668
 *   @0x2f2b40 ldrbtmi r1, [r11], #-1020
 *   @0x2f2b44 adclo pc, r0, r4, asr #17
 *   @0x2f2b48 .word 0xf8a44b25
 *   @0x2f2b4c ldrbtmi r1, [r11], #-956
 *   @0x2f2b50 adclo pc, r4, r4, asr #17
 *   @0x2f2b54 ldrbtmi r4, [r11], #-2851
 *   @0x2f2b58 adclo pc, r8, r4, asr #17
 *   @0x2f2b5c ldrbtmi r4, [r11], #-2850
 *   @0x2f2b60 adclo pc, r12, r4, asr #17
 *   @0x2f2b64 bllo 0x34e5f8
 *   @0x2f2b68 .word 0x33bef8a4
 *   @0x2f2b6c strhi r6, [r3, -r3, ror #29]!
 *   @0x2f2b70 .word 0x63e36f63
 *   @0x2f2b74 .word 0xfffcf5c4
 *   @0x2f2b78 .word 0xf894bb60
 *   @0x2f2b7c movwlt r3, #0x30b1
 *   @0x2f2b80 umlalslo pc, r0, r4, r8
 *   @0x2f2b84 eorle r2, r5, r2, lsl #22
 *   @0x2f2b88 .word 0x21014b18
 *   @0x2f2b8c .word 0x03fcf8c4
 *   @0x2f2b90 .word 0xf8c4447b
 *   @0x2f2b94 blmi 0x87ee1c <b2_toiTime+0x125978>
 *   @0x2f2b98 .word 0x03bcf8a4
 *   @0x2f2b9c ldrbtmi r4, [r11], #-1640
 *   @0x2f2ba0 adclo pc, r4, r4, asr #17
 *   @0x2f2ba4 ldrbtmi r4, [r11], #-2835
 *   @0x2f2ba8 adclo pc, r8, r4, asr #17
 *   @0x2f2bac ldrbtmi r4, [r11], #-2834
 *   @0x2f2bb0 adclo pc, r12, r4, asr #17
 *   @0x2f2bb4 bllo 0x34e748
 *   @0x2f2bb8 .word 0x33bef8a4
 *   @0x2f2bbc .word 0xffd8f5c4
 *   @0x2f2bc0 ldrmi lr, [r8], -r8
 *   @0x2f2bc4 rsbhs lr, r0, r6
 *   @0x2f2bc8 andshs lr, r3, r4
 *   @0x2f2bcc andhs lr, r0, r2
 *   @0x2f2bd0 andshs lr, r4, r0
 *   @0x2f2bd4 stcmi p5, c15, [r8, #52]
 *   @0x2f2bd8 ldcllt p0, c11, [r0, #4]!
 *   @0x2f2bdc .word 0xfffff975
 *   @0x2f2be0 .word 0xfffff993
 *   @0x2f2be4 .word 0xfffffa29
 *   @0x2f2be8 .word 0xfffffb2b
 *   @0x2f2bec .word 0xfffffb09
 *   @0x2f2bf0 .word 0xfffffafd
 *   @0x2f2bf4 .word 0xfffffb47
 *   @0x2f2bf8 .word 0xfffffc67
 *   @0x2f2bfc .word 0x460db538
 *   @0x2f2c00 stcvs p6, c4, [r11], {28}
 *   @0x2f2c04 addmi r6, r11, #16384
 *   @0x2f2c08 .word 0xb122d10e
 *   @0x2f2c0c rsbeq pc, r12, r5, lsl #2
 *   @0x2f2c10 .word 0xf7f34611
 *   @0x2f2c14 strhlt pc, [r12, -r5]!
 *   @0x2f2c18 rsbeq pc, r12, r5, lsl #2
 *   @0x2f2c1c muleq r6, r4, r8
 *   @0x2f2c20 .word 0xfc00f7f3
 *   @0x2f2c24 ldclt p0, c2, [r8, #-0]!
 *   @0x2f2c28 ldclt p0, c2, [r8, #-24]!
 *   @0x2f2c2c stmdale r4!, {r1, r2, r8, r11, sp}
 *   @0x2f2c30 .word 0xf001e8df
 *   @0x2f2c34 streq r1, [lr], -r4, lsl #20
 *   @0x2f2c38 andseq r1, sp, r8, lsl #14
 *   @0x2f2c3c ldrbmi r3, [r0, -r0, lsr #1]!
 *   @0x2f2c40 .word 0x477030d8
 *   @0x2f2c44 .word 0x3124f890
 *   @0x2f2c48 .word 0xf500b1cb
 *   @0x2f2c4c .word 0x47707094
 *   @0x2f2c50 ldrhhs pc, [r4, #-128]!
 *   @0x2f2c54 .word 0x73fff64f
 *   @0x2f2c58 mulle lr, r10, r2
 *   @0x2f2c5c adcsvc pc, r10, r0, lsl #10
 *   @0x2f2c60 .word 0xf5004770
 *   @0x2f2c64 ldrbmi r7, [r0, -lr, ror #1]!
 *   @0x2f2c68 addvc pc, r2, r0, lsl #10
 *   @0x2f2c6c .word 0xf8d04770
 *   @0x2f2c70 .word 0xb1233234
 *   @0x2f2c74 andvc pc, sp, r0, lsl #10
 *   @0x2f2c78 andhs r4, r0, r0, ror r7
 *   @0x2f2c7c ssub16mi r4, r8, r0
 *   @0x2f2c80 andeq r4, r0, r0, ror r7
 *   @0x2f2c84 stmdale r10, {r0, r1, r2, r3, r4, r5, r6, r11, sp}
 *   @0x2f2c88 stmeq r3, {r1, r2, r9, r11, lr} ^
 *   @0x2f2c8c andeq pc, r7, r0
 *   @0x2f2c90 ldclpl p4, c4, [r3], {122}
 *   @0x2f2c94 blx 0x37b4a0 <_ZTS13C_UTF16String+0x1254c>
 *   @0x2f2c98 andsmi pc, r8, r0
 *   @0x2f2c9c andhs r4, r0, r0, ror r7
 *   @0x2f2ca0 svclt #0x4770
 *   @0x2f2ca4 ldrdeq r12, sp, [r10], -r0
 *   @0x2f2ca8 teqeq r0, #160, #2
 *   @0x2f2cac stmdble r7, {r0, r3, r8, r9, r11, sp}
 *   @0x2f2cb0 eoreq pc, r0, r0, lsr #32
 *   @0x2f2cb4 ldmdahs r9, {r0, r6, r11, r12, sp}
 *   @0x2f2cb8 andhs r11, r0, r12, lsl #31
 *   @0x2f2cbc ldrbmi r2, [r0, -r1]!
 *   @0x2f2cc0 ldrbmi r2, [r0, -r1]!
 *   @0x2f2cc4 b 0xfe3058e0 <b2_toiTime+0xfffffffffdbac43c>
 *   @0x2f2cc8 cmpmi r8, #16
 *   @0x2f2ccc b 0xfe3058e4 <b2_toiTime+0xfffffffffdbac440>
 *   @0x2f2cd0 cmpmi r8, #80
 *   @0x2f2cd4 andsmi lr, r0, r0, lsl #21
 *   @0x2f2cd8 svclt #0x4770
 *   @0x2f2cdc strbhi r12, [r11, #0xa6b]!
 *   @0x2f2ce0 adcsgt r10, r2, #848
 *   @0x2f2ce4 mvnsmi lr, #737280
 *   @0x2f2ce8 .word 0x0c14f04f
 *   @0x2f2cec ldrbtlo pc, [pc], #79
 *   @0x2f2cf0 stmdami r9, {r6, r9, r12, sp, lr, pc}
 *   @0x2f2cf4 andsvs r6, r12, r4, lsl r0
 *   @0x2f2cf8 rfeia r0!
 *   @0x2f2cfc adcmi r5, r12, #84, #2
 *   @0x2f2d00 blx 0x62959a <g_SWFaavertbuff+0x564d2>
 *   @0x2f2d04 .word 0xf8d0f604
 *   @0x2f2d08 ldmibne sp!, {r2, r5, r6, r8, r12, sp, lr}
 *   @0x2f2d0c strhls pc, [r6], -r5
 *   @0x2f2d10 tstle r9, r9, lsl #11
 *   @0x2f2d14 strhls pc, [r8], -r5
 *   @0x2f2d18 svceq #0xf1b9
 *   @0x2f2d1c rfeda r7!
 *   @0x2f2d20 .word 0xf1b99006
 *   @0x2f2d24 .word 0xd1090f03
 *   @0x2f2d28 strhls pc, [r2], -r5
 *   @0x2f2d2c svceq #0x1f1b9
 *   @0x2f2d30 rfeia r5!
 *   @0x2f2d34 strbmi r9, [r1, #0x4]
 *   @0x2f2d38 andsvs r11, r4, r8, lsl #30
 *   @0x2f2d3c mcrhs p9, #0x0, r5, c1, c14, #0x5
 *   @0x2f2d40 stmhi sp!, {r1, r8, r12, lr, pc}
 *   @0x2f2d44 andsvs r11, r12, r5, lsl #18
 *   @0x2f2d48 ldrb r3, [r6, r1, lsl #8]
 *   @0x2f2d4c bhs 0x30cd9c <af_shaper_get_elem+0x260a>
 *   @0x2f2d50 ldmdavs r8, {r0, r2, r3, r4, r5, r7, r8, r9, r10, r11, r12, sp, pc}
 *   @0x2f2d54 svceq #0xc043c0
 *   @0x2f2d58 pop {r0, sp}
 *   @0x2f2d5c stmdavs r3, {r4, r5, r6, r7, r8, r9, pc}
 *   @0x2f2d60 ldmdavs r11, {r1, r3, r11, sp, lr} ^
 *   @0x2f2d64 addsmi r6, r3, #5373952
 *   @0x2f2d68 svclt #0x2cd804
 *   @0x2f2d6c .word 0xf06f2000
 *   @0x2f2d70 ldrbmi r0, [r0, -r0]!
 *   @0x2f2d74 ldrbmi r2, [r0, -r1]!
 *   @0x2f2d78 andhs r6, r0, r1, lsl #2
 *   @0x2f2d7c stmdbvs r3, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2f2d80 svclt #0x9a29ff
 *   @0x2f2d84 stmibvc r8, {r0, r3, r6, r7, r11, r12}
 *   @0x2f2d88 ldrbmi r2, [r0, -r0]!
 *   @0x2f2d8c stmdavs r11, {r1, r8, r11, sp, lr}
 *   @0x2f2d90 blhs 0x2bf99c <jinit_d_main_controller+0x188>
 *   @0x2f2d94 ldmne r0, {r2, r11, r12, lr, pc} ^
 *   @0x2f2d98 stmdahs r0, {r7, r8, r11, r12, sp, lr}
 *   @0x2f2d9c strd sp, lr, [r1], -r8
 *   @0x2f2da0 ldrmi r2, [r8], -r0, lsl #6
 *   @0x2f2da4 ldrbmi r6, [r0, -r11]!
 *   @0x2f2da8 andhs r6, r0, r3, lsl #18
 *   @0x2f2dac ldmdbvc r10, {r3, r6, sp, lr}
 *   @0x2f2db0 b 0x13d1324 <b2_toiTime+0xc77e80>
 *   @0x2f2db4 andvs r2, r11, r2, lsl #6
 *   @0x2f2db8 .word 0xf5b14770
 *   @0x2f2dbc andsle r3, sp, #128, #30
 *   @0x2f2dc0 vadd.f32 d1, d16, d3
 *   @0x2f2dc4 beq 0x4fb5e4 <SrcVerts+0x58628>
 *   @0x2f2dc8 bl 0x3e71f8 <error_g0017+0x3fe9c>
 *   @0x2f2dcc .word 0xf8130041
 *   @0x2f2dd0 stmdavc r3, {r0, r4, r12} ^
 *   @0x2f2dd4 movwhs lr, #0x1a53
 *   @0x2f2dd8 ldrmi r11, [r0], -r12, lsl #30
 *   @0x2f2ddc ldrbmi r2, [r0, -r0]!
 *   @0x2f2de0 .word 0x0140eb03
 *   @0x2f2de4 andseq pc, r0, r3, lsl r8
 *   @0x2f2de8 b 0x13d0f1c <b2_toiTime+0xc77a78>
 *   @0x2f2dec .word 0xf0202000
 *   @0x2f2df0 ldrmi r0, [r0], #-7
 *   @0x2f2df4 svclt #0x84290
 *   @0x2f2df8 ldrbmi r2, [r0, -r0]!
 *   @0x2f2dfc ldrbmi r2, [r0, -r0]!
 *   @0x2f2e00 .word 0x460cb5f8
 *   @0x2f2e04 .word 0xf7ff6900
 *   @0x2f2e08 .word 0xb320ffd8
 *   @0x2f2e0c rsclt r7, r4, #458752
 *   @0x2f2e10 stmdbvc r6, {r0, r6, r11, r12, sp, lr}
 *   @0x2f2e14 .word 0x2107ea41
 *   @0x2f2e18 bne 0x1b5103c <b2_toiTime+0x13f7b98>
 *   @0x2f2e1c stmdbvc r5, {r2, r6, r7, r11, r12, sp, lr} ^
 *   @0x2f2e20 strhs lr, [r7], #-2628
 *   @0x2f2e24 adcmi r7, r1, #2146304
 *   @0x2f2e28 andsle r7, r1, #3178496
 *   @0x2f2e2c movwhs lr, #0x3a52
 *   @0x2f2e30 bl 0x3e6e78 <error_g0017+0x3fb1c>
 *   @0x2f2e34 andlo r0, r6, r1, asr #6
 *   @0x2f2e38 stclpl p8, c1, [r0], {194}
 *   @0x2f2e3c b 0x17d0f90 <b2_toiTime+0x1077aec>
 *   @0x2f2e40 andle r2, r8, r0
 *   @0x2f2e44 movwhs lr, #0x6a45
 *   @0x2f2e48 .word 0xf083fa00
 *   @0x2f2e4c ldcllt p2, c11, [r8, #512]!
 *   @0x2f2e50 ldcllt p0, c2, [r8, #0]!
 *   @0x2f2e54 ldcllt p6, c4, [r8, #96]!
 *   @0x2f2e58 svcmi #0xf8e92d
 *   @0x2f2e5c stmdavs r12, {r0, r1, r2, r3, r9, r10, lr}
 *   @0x2f2e60 ldmibvc pc!, {r0, r1, r2, r3, r6, r9, r10, r12, sp, lr, pc} ^
 *   @0x2f2e64 ldrsbhi pc, [r0], -r0
 *   @0x2f2e68 strbmi r3, [r12, #-0x401]
 *   @0x2f2e6c .word 0x4640d83d
 *   @0x2f2e70 .word 0xf7ff4621
 *   @0x2f2e74 orrslt pc, r8, #648
 *   @0x2f2e78 stmibvc r2, {r1, r2, r7, r8, r11, r12, sp, lr} ^
 *   @0x2f2e7c stmdavc r3, {r0, r2, r11, r12, sp, lr} ^
 *   @0x2f2e80 andhs lr, r6, #335872
 *   @0x2f2e84 mullt r2, r0, r8
 *   @0x2f2e88 mulge r3, r0, r8
 *   @0x2f2e8c mulgt r4, r0, r8
 *   @0x2f2e90 eorle r7, r5, r1, asr #18
 *   @0x2f2e94 movwhs lr, #0x5a43
 *   @0x2f2e98 addsmi r11, lr, #1610612750
 *   @0x2f2e9c ldrbteq pc, [pc], #36
 *   @0x2f2ea0 bl 0xff3e2b48 <b2_toiTime+0xfffffffffec896a4>
 *   @0x2f2ea4 b 0x13342c4 <b2_toiTime+0xbdae20>
 *   @0x2f2ea8 svclt #0x34210c
 *   @0x2f2eac ldrtmi r2, [r3], -r0, lsl #10
 *   @0x2f2eb0 subeq lr, r5, #2048
 *   @0x2f2eb4 ldrmi r3, [r12], #-6
 *   @0x2f2eb8 b 0x1583ec8 <b2_toiTime+0xe2aa24>
 *   @0x2f2ebc andlt r2, r9, #45056
 *   @0x2f2ec0 stmdbne r11!, {r0, r2, r3, r5, r8, r9, r11, r12}
 *   @0x2f2ec4 andle r4, r11, #348127232
 *   @0x2f2ec8 bleq 0x3b0f18 <error_g0017+0x9bbc>
 *   @0x2f2ecc .word 0x3c01f812
 *   @0x2f2ed0 andhs lr, r0, r3, asr r10
 *   @0x2f2ed4 strmi sp, [r8], #-2
 *   @0x2f2ed8 stmdblt r0, {r7, r9, r12, sp, pc} ^
 *   @0x2f2edc ldrb r3, [r0, r1, lsl #8]!
 *   @0x2f2ee0 ldrbteq pc, [pc], #36
 *   @0x2f2ee4 strvc pc, [r0], #1284
 *   @0x2f2ee8 strhs lr, [r0], #-1983
 *   @0x2f2eec eorsvs r4, r12, r0, lsr #12
 *   @0x2f2ef0 svchi #0xf8e8bd
 *   @0x2f2ef4 andhs r6, r2, #49152
 *   @0x2f2ef8 andhs r6, r0, r10, asr #32
 *   @0x2f2efc ldmdbvc r11, {r1, r3, r4, r8, r11, r12, sp, lr} ^
 *   @0x2f2f00 movwhs lr, #0x2a43
 *   @0x2f2f04 ldrbmi r6, [r0, -r11]!
 *   @0x2f2f08 strmi r6, [r3], -r1, lsl #2
 *   @0x2f2f0c stmibvc r10, {r3, r7, r8, r11, r12, sp, lr} ^
 *   @0x2f2f10 andhs lr, r0, #270336
 *   @0x2f2f14 bicsvs r2, r8, r0
 *   @0x2f2f18 andsvs r0, r10, #5373952
 *   @0x2f2f1c rscslo pc, pc, #79
 *   @0x2f2f20 .word 0x4770619a
 *   @0x2f2f24 svcmi #0xf0e92d
 *   @0x2f2f28 bvs 0x41f144 <g_RomDisk+0x27924>
 *   @0x2f2f2c stmdbvs r3, {r0, r2, r3, r6}
 *   @0x2f2f30 .word 0xf1041c62
 *   @0x2f2f34 ldmdbne pc, {r0, r1, r2, r3, r4, r5, r6, r7, r9, r11, r12, sp} ^
 *   @0x2f2f38 subseq r9, r2, r1, lsl #14
 *   @0x2f2f3c bl 0x3ba99c <error_g0017+0x13640>
 *   @0x2f2f40 bl 0x335350
 *   @0x2f2f44 ldrmi r0, [r6], #-2054
 *   @0x2f2f48 ldrtmi r1, [r5], #-2223
 *   @0x2f2f4c stmdaeq r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0x2f2f50 strbmi r1, [r1], #2397
 *   @0x2f2f54 .word 0xf1094490
 *   @0x2f2f58 ldmibne pc, {r1, r2, r3, r8, r11} ^
 *   @0x2f2f5c ldrmi r9, [r8], #1283
 *   @0x2f2f60 ldrbvc pc, [pc, #0x64f]!
 *   @0x2f2f64 strls r2, [r2, -r0, lsl #6]
 *   @0x2f2f68 suble r4, r0, #268435466
 *   @0x2f2f6c ldrbmi r9, [r1, #-0xa01]
 *   @0x2f2f70 blvc 0xfe883fe0 <b2_toiTime+0xfffffffffe12ab3c>
 *   @0x2f2f74 bls 0x391ed8 <ft_adobe_glyph_list+0x15b4>
 *   @0x2f2f78 strhs lr, [r6, -r7, asr #20]
 *   @0x2f2f7c ldrmi r6, [r10], #-711
 *   @0x2f2f80 .word 0xf8927b96
 *   @0x2f2f84 bls 0x3e2fc8 <error_g0017+0x3bc6c>
 *   @0x2f2f88 .word 0x2c06ea4c
 *   @0x2f2f8c eorgt pc, r8, r0, asr #17
 *   @0x2f2f90 blvc 0xfe884000 <b2_toiTime+0xfffffffffe12ab5c>
 *   @0x2f2f94 b 0x1391ee4 <b2_toiTime+0xc38a40>
 *   @0x2f2f98 bl 0x53b7b8 <obj_has_event+0xc48>
 *   @0x2f2f9c andslt r0, r2, #3145728
 *   @0x2f2fa0 bl 0x50bbb0 <SrcVerts+0x68bf4>
 *   @0x2f2fa4 .word 0xf8920203
 *   @0x2f2fa8 blvc 0xff79efe8 <b2_toiTime+0xffffffffff045b44>
 *   @0x2f2fac andhs lr, r11, #270336
 *   @0x2f2fb0 strmi sp, [r12, #0x311]!
 *   @0x2f2fb4 adcmi sp, pc, #-1073741821
 *   @0x2f2fb8 stmdavs r7, {r0, r2, r3, r8, r12, lr, pc}
 *   @0x2f2fbc ldrsblt pc, [r12, #135]!
 *   @0x2f2fc0 andgt pc, r0, #14090240
 *   @0x2f2fc4 ldcne p1, c11, [r7], {178}
 *   @0x2f2fc8 ldrtmi r4, [r7], #-1244
 *   @0x2f2fcc stmdble r2, {r0, r1, r2, r5, r6, r8, r10, lr}
 *   @0x2f2fd0 movwvs r2, #0x3301
 *   @0x2f2fd4 adcmi lr, r10, #14
 *   @0x2f2fd8 movweq pc, #0x2103
 *   @0x2f2fdc .word 0xb102d005
 *   @0x2f2fe0 movtvs r4, #0x2432
 *   @0x2f2fe4 andhs r6, r0, r1, asr #4
 *   @0x2f2fe8 mrslo lr, apsr
 *   @0x2f2fec .word 0xf04fe7bc
 *   @0x2f2ff0 strd r3, r4, [r1], -pc
 *   @0x2f2ff4 ldrb r2, [r4, r0, lsl #4]!
 *   @0x2f2ff8 pop {r0, r2, r12, sp, pc}
 *   @0x2f2ffc push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f3000 .word 0xf64f4ff8
 *   @0x2f3004 stmibvs r5, {r1, r2, r3, r4, r5, r6, r7, r8, r9, r12, sp, lr}
 *   @0x2f3008 stmdavs r6, {r2, r9, r10, lr}
 *   @0x2f300c .word 0xf8d6429d
 *   @0x2f3010 .word 0xf8d611fc
 *   @0x2f3014 ldmdale r2, {r9, sp} ^
 *   @0x2f3018 strlo r6, [r1, #-0xa83]
 *   @0x2f301c stmdaeq r2, {r0, r8, r9, r11, sp, lr, pc}
 *   @0x2f3020 ldrbvc pc, [pc, pc, asr #12]!
 *   @0x2f3024 svclt #0x38429d
 *   @0x2f3028 bvs 0xffb848a4 <b2_toiTime+0xffffffffff42b400>
 *   @0x2f302c addsmi r6, r5, #99328
 *   @0x2f3030 ldmdale r8!, {r0, r1, r5, r8, r9, r11, sp, lr}
 *   @0x2f3034 bvs 0xfeb1f700 <b2_toiTime+0xfffffffffe3c625c>
 *   @0x2f3038 bl 0x3398e0
 *   @0x2f303c strbmi r0, [r1, #-0x140]
 *   @0x2f3040 .word 0xf811d831
 *   @0x2f3044 .word 0xf811cb02
 *   @0x2f3048 b 0x16f6054 <b2_toiTime+0xf9cbb0>
 *   @0x2f304c andle r2, r6, r12
 *   @0x2f3050 addlt r4, r0, #24, #8
 *   @0x2f3054 .word 0x61a5b118
 *   @0x2f3058 pop {r5, r6, r7, r8, sp, lr}
 *   @0x2f305c strlo r8, [r1, #-0xff8]
 *   @0x2f3060 .word 0xe7ed4295
 *   @0x2f3064 ldrsbls pc, [r0], -r6
 *   @0x2f3068 .word 0x0c03eb02
 *   @0x2f306c blo 0xfe330780 <b2_toiTime+0xfffffffffdbd72dc>
 *   @0x2f3070 bleq 0x32f784
 *   @0x2f3074 addlt r1, r1, #232, #16
 *   @0x2f3078 movwle r4, #0xc549
 *   @0x2f307c ble 0x3fd084 <g_RomDisk+0x5864>
 *   @0x2f3080 svceq #0xf1bc
 *   @0x2f3084 ldrbmi sp, [sp], -r3, lsl #22
 *   @0x2f3088 adcsmi lr, r8, #10
 *   @0x2f308c ldrmi sp, [r12, #0xc0b]!
 *   @0x2f3090 ldrbmi sp, [r5], -r9, lsl #26
 *   @0x2f3094 tstlt r9, r4
 *   @0x2f3098 mvnvs r6, r5, lsr #3
 *   @0x2f309c svchi #0xf8e8bd
 *   @0x2f30a0 addsmi r3, r5, #4194304
 *   @0x2f30a4 bvs 0x1b69844 <b2_toiTime+0x14103a0>
 *   @0x2f30a8 .word 0x31014620
 *   @0x2f30ac .word 0xff3af7ff
 *   @0x2f30b0 blle 0x3fd0b8 <g_RomDisk+0x5898>
 *   @0x2f30b4 addsmi r6, sp, #667648
 *   @0x2f30b8 sasxmi r11, sp, r8
 *   @0x2f30bc .word 0xf04fe7b5
 *   @0x2f30c0 strdvs r3, r4, [r3, pc]!
 *   @0x2f30c4 mvnvs r2, r0, lsl #6
 *   @0x2f30c8 svchi #0xf8e8bd
 *   @0x2f30cc svcmi #0xf0e92d
 *   @0x2f30d0 stmdavs r11, {r0, r3, r7, r12, sp, pc}
 *   @0x2f30d4 stmdbvs r1, {r2, r8, r12, pc}
 *   @0x2f30d8 .word 0xc000f8d0
 *   @0x2f30dc stmibvc r8, {r1, r2, r3, r7, r8, r11, r12, sp, lr} ^
 *   @0x2f30e0 ldrsbpl pc, [r12, #140]!
 *   @0x2f30e4 andhs lr, r6, r0, asr #20
 *   @0x2f30e8 andmi pc, r0, #220, #16
 *   @0x2f30ec andeq pc, r1, r0, lsr #32
 *   @0x2f30f0 strls r0, [r1], -r6, asr #16
 *   @0x2f30f4 .word 0xf0002800
 *   @0x2f30f8 swplt r8, r5, [r2]
 *   @0x2f30fc .word 0xf64f3301
 *   @0x2f3100 ldrbmi r7, [r3, #-0xaff]
 *   @0x2f3104 addshi pc, r0, r0, lsl #4
 *   @0x2f3108 ldmdaeq r0, {r8, r12, sp, lr, pc}
 *   @0x2f310c .word 0xb004f8dd
 *   @0x2f3110 .word 0xf04f4488
 *   @0x2f3114 .word 0xf1010900
 *   @0x2f3118 stmdbne r12!, {r1, r2, r3, r8, r9, r10}
 *   @0x2f311c .word 0x0140eb08
 *   @0x2f3120 bllo 0x2ef554 <FT_Done_Memory+0x58e0>
 *   @0x2f3124 strls r4, [r3], #-576
 *   @0x2f3128 andls r9, r5, r2, lsl #14
 *   @0x2f312c andslt pc, r12, sp, asr #17
 *   @0x2f3130 .word 0xf8189802
 *   @0x2f3134 .word 0xf8106b02
 *   @0x2f3138 andls r5, r2, r2, lsl #22
 *   @0x2f313c .word 0x0c01f810
 *   @0x2f3140 strhs lr, [r5, #-0xa40]
 *   @0x2f3144 .word 0x0c01f818
 *   @0x2f3148 strhs lr, [r6], -r0, asr #20
 *   @0x2f314c andle r4, r2, #805306379
 *   @0x2f3150 rsble r2, r11, r0, lsl #20
 *   @0x2f3154 .word 0x9c054633
 *   @0x2f3158 strls r4, [r6], #-1036
 *   @0x2f315c ldmdale r6, {r0, r1, r3, r5, r7, r9, lr} ^
 *   @0x2f3160 .word 0xf8dd9f05
 *   @0x2f3164 stclpl p0, c11, [r12, #112]
 *   @0x2f3168 svcls #0x645d9
 *   @0x2f316c stmdavc pc, {r3, r4, r5, r6, r11, r12, sp, lr}
 *   @0x2f3170 strhs lr, [r4], #-2624
 *   @0x2f3174 eorlt r7, r4, #72, #16
 *   @0x2f3178 andhs lr, r7, r0, asr #20
 *   @0x2f317c ldrbmi sp, [r6, #-0x30c]
 *   @0x2f3180 adcsmi sp, r5, #-2147483646
 *   @0x2f3184 mvnslt sp, r8, lsl #2
 *   @0x2f3188 .word 0xf8dd1c87
 *   @0x2f318c strmi r11, [pc], #-12
 *   @0x2f3190 eorsle r4, r10, #784334848
 *   @0x2f3194 ands r2, r7, r1, lsl #8
 *   @0x2f3198 eorsle r4, r8, r0, asr r5
 *   @0x2f319c blne 0xfeadf824 <b2_toiTime+0xfffffffffe386380>
 *   @0x2f31a0 strbeq lr, [r7, -r0, lsl #22]
 *   @0x2f31a4 tstlt r2, pc, lsl #8
 *   @0x2f31a8 addmi r9, r7, #196608
 *   @0x2f31ac ldmdavc r8!, {r0, r1, r2, r3, r5, r11, r12, lr, pc}
 *   @0x2f31b0 b 0x18d13b4 <b2_toiTime+0x1177f10>
 *   @0x2f31b4 eorle r2, r0, r0
 *   @0x2f31b8 .word 0xf8dc4420
 *   @0x2f31bc addlt r4, r0, #16
 *   @0x2f31c0 svclt #0x2842a0
 *   @0x2f31c4 ands r2, r8, r0
 *   @0x2f31c8 bleq 0x42dddc <g_RomDisk+0x365bc>
 *   @0x2f31cc .word 0xf08bfa1f
 *   @0x2f31d0 .word 0xf8dcb36a
 *   @0x2f31d4 adcsmi r7, r8, #16
 *   @0x2f31d8 .word 0xf1bbd310
 *   @0x2f31dc ble 0x3b6de4 <error_g0017+0xfa88>
 *   @0x2f31e0 strle r4, [r3], #-741
 *   @0x2f31e4 and r4, r6, r3, ror #4
 *   @0x2f31e8 .word 0xdc1045d3
 *   @0x2f31ec ldrbmi r1, [r0, #-0x928]
 *   @0x2f31f0 .word 0xf5c4dd0d
 *   @0x2f31f4 andhs r3, r0, r0, lsl #7
 *   @0x2f31f8 biclt lr, r2, r1
 *   @0x2f31fc .word 0xf64fb978
 *   @0x2f3200 adcmi r7, r3, #-33554432
 *   @0x2f3204 movwlo sp, #0x180b
 *   @0x2f3208 adcmi lr, r8, #168, #14
 *   @0x2f320c cdpls p1, #0x0, c13, c1, c7, #0x6
 *   @0x2f3210 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f3214 ldrmi r3, [r1, #0x102]!
 *   @0x2f3218 teqlt r10, r10, lsl #3
 *   @0x2f321c svcls #0x42000
 *   @0x2f3220 and r6, r4, r11, lsr r0
 *   @0x2f3224 and r9, r2, r1, lsl #16
 *   @0x2f3228 and r2, r0, r0
 *   @0x2f322c andlt r4, r9, r0, lsl r6
 *   @0x2f3230 svchi #0xf0e8bd
 *   @0x2f3234 svcmi #0xf0e92d
 *   @0x2f3238 pkhbtmi r11, r0, r5, lsl #1
 *   @0x2f323c .word 0xb000f8d1
 *   @0x2f3240 .word 0xf8d8910e
 *   @0x2f3244 andls r1, r12, #16
 *   @0x2f3248 stmibvc r10, {r11, sp, lr}
 *   @0x2f324c andls r7, r11, r11, asr #19
 *   @0x2f3250 movwhs lr, #0x2a43
 *   @0x2f3254 ldrsbpl pc, [r12, #128]!
 *   @0x2f3258 beq 0x36f32c <_ZTS13C_UTF16String+0x63d8>
 *   @0x2f325c andvs pc, r0, #208, #16
 *   @0x2f3260 mrsle r9, apsr
 *   @0x2f3264 mov r2, r0
 *   @0x2f3268 b 0x16d9ea0 <b2_toiTime+0xf809fc>
 *   @0x2f326c andls r0, r10, #-1610612731
 *   @0x2f3270 .word 0xf10bb10b
 *   @0x2f3274 stmdbls r10, {r0, r8, r9, r11}
 *   @0x2f3278 .word 0xf64f2000
 *   @0x2f327c .word 0xf10a74ff
 *   @0x2f3280 strls r0, [r6, -r2, lsl #14]
 *   @0x2f3284 addsmi r4, r0, #10485760
 *   @0x2f3288 smulbbhi r0, r0, r0
 *   @0x2f328c .word 0x9c051883
 *   @0x2f3290 b 0x16daeb0 <b2_toiTime+0xf81a0c>
 *   @0x2f3294 cpsid f
 *   @0x2f3298 bl 0x3f3ebc <VS_Common+0xb60>
 *   @0x2f329c .word 0xf8140143
 *   @0x2f32a0 stmdavc r11, {r0, r1, r4, lr} ^
 *   @0x2f32a4 movwhs lr, #0x4a43
 *   @0x2f32a8 blls 0x497ec0 <g_prim_v+0x7eb4>
 *   @0x2f32ac strmi r5, [r11], #-3532
 *   @0x2f32b0 b 0x135141c <b2_toiTime+0xbf7f78>
 *   @0x2f32b4 mrsls r2, apsr
 *   @0x2f32b8 .word 0xf0c0458b
 *   @0x2f32bc stmdals r4, {r1, r6, r8, pc}
 *   @0x2f32c0 stmdble r2, {r0, r1, r7, r8, r10, lr}
 *   @0x2f32c4 andeq pc, r1, r12, lsl #2
 *   @0x2f32c8 bl 0x3eb7c0 <_ZTV15Buffer_Standard+0x38>
 *   @0x2f32cc .word 0xf813020a
 *   @0x2f32d0 stmibne lr!, {r1, r3}
 *   @0x2f32d4 ldmdavc r1, {r4, r9, r10, r12, pc} ^
 *   @0x2f32d8 andls r4, r8, #1375731712
 *   @0x2f32dc .word 0x2100ea41
 *   @0x2f32e0 andshs pc, r10, r3, lsl r8
 *   @0x2f32e4 .word 0x9103b209
 *   @0x2f32e8 stmdavc r11, {r3, r8, r11, r12, pc} ^
 *   @0x2f32ec stmdbhs r2, {r0, r1, r6, r9, r11, sp, lr, pc}
 *   @0x2f32f0 vnmlsne.f32 s19, s6, s20
 *   @0x2f32f4 tstle r5, #156, #10
 *   @0x2f32f8 .word 0xf64f9b07
 *   @0x2f32fc adcmi r7, r3, #-16777216
 *   @0x2f3300 stcls p1, c13, [r4, #-64]
 *   @0x2f3304 smlatble sp, r5, r2, r4
 *   @0x2f3308 svceq #0xf1b9
 *   @0x2f330c .word 0xf109d00a
 *   @0x2f3310 bls 0x3b3f20 <error_g0017+0xcbc4>
 *   @0x2f3314 addsmi r4, lr, #184549376
 *   @0x2f3318 andhs r11, r1, #56, #30
 *   @0x2f331c strbmi r11, [r11], -r12, lsr #30
 *   @0x2f3320 and r2, r1, r0, lsl #6
 *   @0x2f3324 strbmi r9, [r11], -r3, lsl #20
 *   @0x2f3328 ldrsbne pc, [r4], -r8
 *   @0x2f332c andeq pc, r2, r1, lsl r0
 *   @0x2f3330 sbchi pc, r8, r0
 *   @0x2f3334 .word 0xf10c9f06
 *   @0x2f3338 .word 0xf64f0006
 *   @0x2f333c .word 0x9c0476ff
 *   @0x2f3340 strbeq lr, [r10, #-0xb07]
 *   @0x2f3344 bl 0x443e18 <g_RomDisk+0x4c5f8>
 *   @0x2f3348 stmdals r5, {r6, r8, r10}
 *   @0x2f334c svclt #0x89e07
 *   @0x2f3350 mrseq pc, apsr
 *   @0x2f3354 .word 0xf06f4405
 *   @0x2f3358 blx 0x2f3366 <ps_hints_apply+0x1f66>
 *   @0x2f335c svclt #0x18f00a
 *   @0x2f3360 strls r4, [r2], -r1, ror #12
 *   @0x2f3364 .word 0xf1ca427f
 *   @0x2f3368 .word 0xf8cd0600
 *   @0x2f336c ldrls r12, [r2, -r4]
 *   @0x2f3370 andsls r9, r1, r3, lsl r6
 *   @0x2f3374 cdpls p8, #0x0, c9, c1, c8, #0x0
 *   @0x2f3378 eorle r2, r12, r0, lsl #28
 *   @0x2f337c mrcls p15, #0x0, r9, c2, c1, #0x0
 *   @0x2f3380 strls r4, [r9, -pc, lsr #8]
 *   @0x2f3384 .word 0x960d5dbe
 *   @0x2f3388 ldrtmi r9, [r7], #-3602
 *   @0x2f338c ldmdavc pc!, {r0, r2, r3, r9, r10, r11, r12, pc} ^
 *   @0x2f3390 strhs lr, [r6], -r7, asr #20
 *   @0x2f3394 ldrmi r9, [r3, #0x60d]!
 *   @0x2f3398 svcls #0x11d81d
 *   @0x2f339c bls 0x544c44 <g_pWADBaseAddress>
 *   @0x2f33a0 stclpl p8, c7, [r11, #176]!
 *   @0x2f33a4 b 0x14d1508 <b2_toiTime+0xd78064>
 *   @0x2f33a8 blls 0x7bcfbc <b2_toiTime+0x63b18>
 *   @0x2f33ac .word 0xf64f9702
 *   @0x2f33b0 stclpl p7, c7, [r10], #1020
 *   @0x2f33b4 stclo p4, c4, [r2, #-172]
 *   @0x2f33b8 b 0x13d152c <b2_toiTime+0xc78088>
 *   @0x2f33bc stmvc r11!, {r1, r9, sp} ^
 *   @0x2f33c0 movwhs lr, #0x4a43
 *   @0x2f33c4 andslt r9, r2, #256
 *   @0x2f33c8 .word 0x9c0d1e66
 *   @0x2f33cc svclt #0x1842bb
 *   @0x2f33d0 .word 0x96014631
 *   @0x2f33d4 cpsid aif
 *   @0x2f33d8 adcmi r0, r9, #4194304
 *   @0x2f33dc svcls #0x1d14f
 *   @0x2f33e0 .word 0xd1054567
 *   @0x2f33e4 ldrmi r9, [r9], r8
 *   @0x2f33e8 andls r9, r3, #131072
 *   @0x2f33ec andls r9, r7, r4, lsl #8
 *   @0x2f33f0 bls 0x47ab2c <_ZN2VM13m_breakpointsE+0x8f8>
 *   @0x2f33f4 strmi r9, [lr], -r7, lsl #30
 *   @0x2f33f8 strbeq lr, [r5, #-0xb02]
 *   @0x2f33fc stmdals r8, {r0, r2, r8, r9, r11, r12, pc}
 *   @0x2f3400 bls 0x3c4d8c <error_g0017+0x1da30>
 *   @0x2f3404 smladls r2, sp, r4, r4
 *   @0x2f3408 svcls #0x6464b
 *   @0x2f340c strbeq lr, [r10], #-2639
 *   @0x2f3410 rsbsmi r9, pc, #150994944
 *   @0x2f3414 strls r9, [r4, -r4, lsl #24]
 *   @0x2f3418 adcsmi r9, lr, #10, #30
 *   @0x2f341c svcls #0x4d22a
 *   @0x2f3420 .word 0xf8154628
 *   @0x2f3424 strtmi r9, [pc], #-7
 *   @0x2f3428 b 0x14d162c <b2_toiTime+0xd78188>
 *   @0x2f342c stmdavc pc!, {r0, r3, r8, r11, sp}
 *   @0x2f3430 andls pc, r12, sp, asr #17
 *   @0x2f3434 mulls r1, r5, r8
 *   @0x2f3438 stmdbhs r7, {r0, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f343c tstle r9, #851443712
 *   @0x2f3440 movweq lr, #0xab05
 *   @0x2f3444 andhs pc, r10, r5, lsl r8
 *   @0x2f3448 ldmdavc r11, {r0, r3, r11, r12, pc} ^
 *   @0x2f344c .word 0xf8cd4428
 *   @0x2f3450 b 0x13d7478 <b2_toiTime+0xc7dfd4>
 *   @0x2f3454 blls 0x53bc64 <obj_has_event+0x10f4>
 *   @0x2f3458 stclpl p2, c11, [r12], #72
 *   @0x2f345c stmdavc r3, {r1, r8, r10, r12, sp} ^
 *   @0x2f3460 movwhs lr, #0x4a43
 *   @0x2f3464 ldrbtvc pc, [pc], #1615
 *   @0x2f3468 svclt #0x1842a3
 *   @0x2f346c .word 0x36014631
 *   @0x2f3470 ldrb r9, [r1, r3, lsl #24]
 *   @0x2f3474 .word 0xf1064561
 *   @0x2f3478 .word 0x960136ff
 *   @0x2f347c stcls p0, c13, [r1, #-404]
 *   @0x2f3480 eorle r4, r8, r9, lsr #5
 *   @0x2f3484 cdpls p13, #0x0, c1, c5, c10, #0x6
 *   @0x2f3488 stcls p8, c9, [r6, #-24]
 *   @0x2f348c movteq lr, #0x2b06
 *   @0x2f3490 andsmi pc, r2, r6, lsl r8
 *   @0x2f3494 ldmdavc r10, {r0, r2, r3, r4, r10, lr} ^
 *   @0x2f3498 bl 0x44a51c <g_RomDisk+0x52cfc>
 *   @0x2f349c stmdavc r11!, {r1, r3} ^
 *   @0x2f34a0 strhs lr, [r4], #-2626
 *   @0x2f34a4 andhs pc, r10, r5, lsl r8
 *   @0x2f34a8 movwhs lr, #0x7a43
 *   @0x2f34ac stmdavc r3, {r1, r8, r9, r12, pc} ^
 *   @0x2f34b0 .word 0xf8154450
 *   @0x2f34b4 b 0x13c7524 <b2_toiTime+0xc6e080>
 *   @0x2f34b8 stmdavc r3, {r1, r9, sp} ^
 *   @0x2f34bc b 0x13dfd0c <b2_toiTime+0xc86868>
 *   @0x2f34c0 and r2, r8, r5, lsl #6
 *   @0x2f34c4 mvnsvc pc, pc, asr #12
 *   @0x2f34c8 suble r4, r1, r11, lsl #5
 *   @0x2f34cc strbtmi r9, [r1], -r7, lsl #26
 *   @0x2f34d0 .word 0x9c049808
 *   @0x2f34d4 .word 0xb1bb9502
 *   @0x2f34d8 bl 0xff49ace8 <b2_toiTime+0xfffffffffed41844>
 *   @0x2f34dc bl 0x3b5110 <error_g0017+0xddb4>
 *   @0x2f34e0 svcls #0xc0347
 *   @0x2f34e4 tstlt r7, r8, lsl r4
 *   @0x2f34e8 addsmi r9, r8, #16, #22
 *   @0x2f34ec stmdavc r5, {r0, r1, r3, r4, r6, r11, r12, lr, pc}
 *   @0x2f34f0 b 0x17d1604 <b2_toiTime+0x1078160>
 *   @0x2f34f4 eorle r2, lr, r5, lsl #10
 *   @0x2f34f8 ldrmi r9, [r5], #-3595
 *   @0x2f34fc ldmdbvs r3!, {r0, r2, r3, r5, r7, r9, r12, sp, pc}
 *   @0x2f3500 svclt #0x28429d
 *   @0x2f3504 eor r2, r6, r0, lsl #10
 *   @0x2f3508 andeq lr, r2, r11, lsl #22
 *   @0x2f350c addlt r9, r5, #12, #30
 *   @0x2f3510 suble r2, r4, r0, lsl #30
 *   @0x2f3514 ldmdbvs lr!, {r0, r1, r3, r8, r9, r10, r11, r12, pc}
 *   @0x2f3518 tstle lr, #1342177291
 *   @0x2f351c ble 0x3fd524 <g_RomDisk+0x5d04>
 *   @0x2f3520 strle r4, [r6], #-724
 *   @0x2f3524 bleq 0x32fc34
 *   @0x2f3528 .word 0xf64fe03b
 *   @0x2f352c adcmi r7, r8, #1069547520
 *   @0x2f3530 stmne r3!, {r0, r1, r2, r4, r5, r10, r11, r12, lr, pc}
 *   @0x2f3534 ldrbtvc pc, [pc], pc, asr #12
 *   @0x2f3538 ldcle p2, c4, [r4, #-716]!
 *   @0x2f353c bllo 0xfe330c4c <b2_toiTime+0xfffffffffdbd77a8>
 *   @0x2f3540 uqasxmi lr, r2, r1
 *   @0x2f3544 .word 0x9c044661
 *   @0x2f3548 stmdbls r1, {r0, r2, r3, r4, r7, r9, r10, sp, lr, pc}
 *   @0x2f354c and r2, r2, r0, lsl #10
 *   @0x2f3550 strbtmi r9, [r1], -r4, lsl #24
 *   @0x2f3554 svcls #0xc4605
 *   @0x2f3558 strmi r11, [r3, #0x30f]!
 *   @0x2f355c stmdals r10, {r2, r8, r11, r12, lr, pc}
 *   @0x2f3560 addmi r3, r1, #1073741824
 *   @0x2f3564 mrcge p4, #0x3, apsr_nzcv, c14, c15, #0x1
 *   @0x2f3568 .word 0xf7ff4640
 *   @0x2f356c .word 0xb120fcdb
 *   @0x2f3570 blls 0x69fc2c <g_SWFlinevertbuff+0x4cb64>
 *   @0x2f3574 andlt pc, r0, r3, asr #17
 *   @0x2f3578 .word 0xf8c8e011
 *   @0x2f357c tstlt r5, r8, lsl r0
 *   @0x2f3580 andspl pc, r12, r8, asr #17
 *   @0x2f3584 strbmi lr, [r0], -r7
 *   @0x2f3588 ldc2 p7, c15, [r9, #-1020]!
 *   @0x2f358c ldrsbpl pc, [r12], -r8
 *   @0x2f3590 .word 0xf43f2d00
 *   @0x2f3594 .word 0xf8d8ae67
 *   @0x2f3598 .word 0x9c0e3018
 *   @0x2f359c strtmi r6, [r8], -r3, lsr #32
 *   @0x2f35a0 ldrmi lr, [sp], -r3
 *   @0x2f35a4 strhs lr, [r0, #-0x7d9]
 *   @0x2f35a8 ldrsblt lr, [r5], -r7
 *   @0x2f35ac svchi #0xf0e8bd
 *   @0x2f35b0 svclo #0x80f5b1
 *   @0x2f35b4 mrsls r11, apsr
 *   @0x2f35b8 stmdbvs r2, {r0, r1, r3, r9, r12, lr, pc} ^
 *   @0x2f35bc .word 0xf012a901
 *   @0x2f35c0 andle r0, r3, r1, lsl #4
 *   @0x2f35c4 .word 0xf7ff2200
 *   @0x2f35c8 and pc, r3, r1, lsl #27
 *   @0x2f35cc mrc2 p7, #0x1, apsr_nzcv, c2, c15, #0x7
 *   @0x2f35d0 andhs lr, r0, r0
 *   @0x2f35d4 .word 0xf85db003
 *   @0x2f35d8 ldrlt pc, [r8, #-0xb04]!
 *   @0x2f35dc rscsvc pc, lr, #82837504
 *   @0x2f35e0 strmi r6, [r4], -r11, lsl #16
 *   @0x2f35e4 addsmi r4, r3, #13631488
 *   @0x2f35e8 stmdbvs r2, {r1, r2, r4, r11, r12, lr, pc} ^
 *   @0x2f35ec strle r0, [r4, #-0x7d2]
 *   @0x2f35f0 pop {r0, r9, sp}
 *   @0x2f35f4 .word 0xf7ff4038
 *   @0x2f35f8 stmibvs r2, {r0, r3, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2f35fc swple r4, r3, [r6]
 *   @0x2f3600 ldc2l p7, c15, [sp], #1020
 *   @0x2f3604 smlalttlt r6, r0, r0, r9
 *   @0x2f3608 eorvs r6, r11, r3, lsr #19
 *   @0x2f360c andhs r11, r1, #56, #26
 *   @0x2f3610 ldrhtmi lr, [r8], -sp
 *   @0x2f3614 mcrlt p7, #0x0, pc, c14, c15, #0x7
 *   @0x2f3618 ldclt p0, c2, [r8, #-0]!
 *   @0x2f361c andhs r6, r4, #49152
 *   @0x2f3620 andhs r6, r0, r10, asr #32
 *   @0x2f3624 ldmdbvc r11, {r1, r3, r4, r8, r11, r12, sp, lr} ^
 *   @0x2f3628 movwhs lr, #0x2a43
 *   @0x2f362c ldrbmi r6, [r0, -r11]!
 *   @0x2f3630 ldmibvc r8, {r0, r1, r8, r11, sp, lr}
 *   @0x2f3634 b 0x1391da4 <b2_toiTime+0xc38900>
 *   @0x2f3638 bvc 0x8fbe40 <b2_toiTime+0x1a299c>
 *   @0x2f363c bvc 0x197a068 <b2_toiTime+0x1220bc4>
 *   @0x2f3640 andhs lr, r0, #270336
 *   @0x2f3644 andle r4, r8, #268435465
 *   @0x2f3648 bl 0x3c0278 <error_g0017+0x18f1c>
 *   @0x2f364c .word 0xf8130241
 *   @0x2f3650 ldmdavc r3, {r0, r4} ^
 *   @0x2f3654 andhs lr, r0, r3, asr #20
 *   @0x2f3658 andhs r4, r0, r0, ror r7
 *   @0x2f365c stmdavs r11, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2f3660 movwlo r11, #0x15f0
 *   @0x2f3664 .word 0xf64f6902
 *   @0x2f3668 addmi r7, r3, #255
 *   @0x2f366c .word 0xf8924607
 *   @0x2f3670 ldmibvc r4, {r1, r2, lr, pc} ^
 *   @0x2f3674 bvc 0x1851ed4 <b2_toiTime+0x10f8a30>
 *   @0x2f3678 b 0x14296f0 <b2_toiTime+0xcd024c>
 *   @0x2f367c andlo r2, r10, #12, #8
 *   @0x2f3680 svclt #0x28429c
 *   @0x2f3684 b 0x1444f18 <b2_toiTime+0xceba74>
 *   @0x2f3688 blne 0x8fcea8 <b2_toiTime+0x1a3a04>
 *   @0x2f368c subeq lr, r0, #2048
 *   @0x2f3690 adcsmi r1, r5, #29696
 *   @0x2f3694 .word 0xf812d20a
 *   @0x2f3698 .word 0xf8125b02
 *   @0x2f369c b 0x16f66a8 <b2_toiTime+0xf9d204>
 *   @0x2f36a0 mrsle r2, apsr
 *   @0x2f36a4 strhle r4, [r6], -r11
 *   @0x2f36a8 ldrb r3, [r1, r1, lsl #6]!
 *   @0x2f36ac ldrmi r2, [r8], -r0, lsl #6
 *   @0x2f36b0 ldcllt p0, c6, [r0, #44]!
 *   @0x2f36b4 ldcllt p0, c2, [r0, #0]!
 *   @0x2f36b8 andhs r6, r6, #49152
 *   @0x2f36bc andhs r6, r0, r10, asr #32
 *   @0x2f36c0 ldmdbvc r11, {r1, r3, r4, r8, r11, r12, sp, lr} ^
 *   @0x2f36c4 movwhs lr, #0x2a43
 *   @0x2f36c8 ldrbmi r6, [r0, -r11]!
 *   @0x2f36cc stmdbvs r3, {r4, r5, r6, r7, r8, r10, r12, sp, pc}
 *   @0x2f36d0 movwpl pc, #0x503
 *   @0x2f36d4 .word 0xf8133310
 *   @0x2f36d8 .word 0xf8130c03
 *   @0x2f36dc streq r2, [r0], #-3076
 *   @0x2f36e0 andvs lr, r2, r0, asr #20
 *   @0x2f36e4 .word 0x2c01f813
 *   @0x2f36e8 .word 0xf8134310
 *   @0x2f36ec b 0x12fe6fc <b2_toiTime+0xba5258>
 *   @0x2f36f0 cmnlt r0, #2
 *   @0x2f36f4 ldmdavc r12, {r1, r3, r4, r6, r11, r12, sp, lr}
 *   @0x2f36f8 mulgt r5, r3, r8
 *   @0x2f36fc bvc 0xa7474c <b2_toiTime+0x31b2a8>
 *   @0x2f3700 andvs lr, r4, #270336
 *   @0x2f3704 b 0x16d1a7c <b2_toiTime+0xf785d8>
 *   @0x2f3708 bvc 0x1ac6740 <b2_toiTime+0x136d29c>
 *   @0x2f370c ldmvc r12, {r1, r5, r8, r9, lr}
 *   @0x2f3710 b 0x139228c <b2_toiTime+0xc38de8>
 *   @0x2f3714 ldmdbvc r12, {r2, r9, sp}
 *   @0x2f3718 b 0x1604164 <b2_toiTime+0xeaacc0>
 *   @0x2f371c ldmibvc r12, {r2, r10, r11, sp, lr} ^
 *   @0x2f3720 .word 0x0c04ea4c
 *   @0x2f3724 b 0x1611d9c <b2_toiTime+0xeb88f8>
 *   @0x2f3728 bvc 0xfe9fe740 <b2_toiTime+0xfffffffffe2a529c>
 *   @0x2f372c strbmi sp, [r1, #-0x312]!
 *   @0x2f3730 movweq pc, #0xc103
 *   @0x2f3734 ldrteq sp, [r8], #-2059
 *   @0x2f3738 b 0x12fa164 <b2_toiTime+0xba0cc0>
 *   @0x2f373c .word 0x43286006
 *   @0x2f3740 b 0x1304674 <b2_toiTime+0xbab1d0>
 *   @0x2f3744 addsmi r2, r8, #4
 *   @0x2f3748 strmi sp, [r8], #-2052
 *   @0x2f374c stmdalo r1, {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2f3750 ldcllt p7, c14, [r0, #828]!
 *   @0x2f3754 ldcllt p0, c2, [r0, #0]!
 *   @0x2f3758 mvnsmi lr, sp, lsr #18
 *   @0x2f375c stmdavs r7, {r0, r1, r8, r11, sp, lr}
 *   @0x2f3760 movwpl pc, #0x503
 *   @0x2f3764 blvc 0x9924dc <b2_toiTime+0x239038>
 *   @0x2f3768 b 0x13f4800 <b2_toiTime+0xc9b35c>
 *   @0x2f376c blvc 0xff98c77c <b2_toiTime+0xffffffffff2332d8>
 *   @0x2f3770 blvc 0xfe9843c8 <b2_toiTime+0xfffffffffe22af24>
 *   @0x2f3774 strhs lr, [r2], #-2628
 *   @0x2f3778 mrrcne p8, #0x0, r6, r0, c10
 *   @0x2f377c andlo sp, r1, #68
 *   @0x2f3780 .word 0x2c003310
 *   @0x2f3784 ldmdavc r8, {r0, r3, r4, r5, r12, lr, pc} ^
 *   @0x2f3788 .word 0xf893781d
 *   @0x2f378c streq r12, [r0], #-5
 *   @0x2f3790 b 0x1312010 <b2_toiTime+0xbb8b6c>
 *   @0x2f3794 ldmvc sp, {r0, r2, sp, lr} ^
 *   @0x2f3798 .word 0x4c0cea4f
 *   @0x2f379c ldmvc sp, {r3, r5, r8, r9, lr}
 *   @0x2f37a0 andhs lr, r5, r0, asr #20
 *   @0x2f37a4 addmi r7, r2, #475136
 *   @0x2f37a8 .word 0x4602bf38
 *   @0x2f37ac ldmlo pc!, {r8, r12, sp, lr, pc} ^
 *   @0x2f37b0 .word 0x6c05ea4c
 *   @0x2f37b4 b 0x1611f30 <b2_toiTime+0xeb8a8c>
 *   @0x2f37b8 ldmibvc sp, {r0, r2, r10, r11}
 *   @0x2f37bc .word 0x2c05ea4c
 *   @0x2f37c0 strteq r7, [sp], #-2653
 *   @0x2f37c4 strvs lr, [r6, #-0xa45]
 *   @0x2f37c8 teqmi r5, #909312
 *   @0x2f37cc b 0x145224c <b2_toiTime+0xcf8da8>
 *   @0x2f37d0 bne 0xe7cbf0 <b2_toiTime+0x72374c>
 *   @0x2f37d4 stmdale sp, {r1, r5, r6, r8, r10, lr}
 *   @0x2f37d8 andeq lr, r8, r2, asr #23
 *   @0x2f37dc stmdale r9, {r0, r2, r7, r9, lr}
 *   @0x2f37e0 strhle r1, [r4, -r0]
 *   @0x2f37e4 svclo #0xfff1b2
 *   @0x2f37e8 andlo sp, r1, #10
 *   @0x2f37ec ldmdbvs sp!, {r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2f37f0 movwle r4, #0x62a8
 *   @0x2f37f4 movwlo r3, #0xcc01
 *   @0x2f37f8 strtmi lr, [r2], -r3, asr #15
 *   @0x2f37fc and r4, r0, r0, lsr #12
 *   @0x2f3800 andvs r4, r10, r2, lsl #12
 *   @0x2f3804 ldrhhi lr, [r0, #141]!
 *   @0x2f3808 ldm sp!, {sp}
 *   @0x2f380c stmdbvs r3, {r4, r5, r6, r7, r8, pc}
 *   @0x2f3810 subvs r2, r10, r8, lsl #4
 *   @0x2f3814 bvc 0x912184 <b2_toiTime+0x1b8ce0>
 *   @0x2f3818 b 0x1374868 <b2_toiTime+0xc1b3c4>
 *   @0x2f381c bvc 0xff90c024 <b2_toiTime+0xffffffffff1b2b80>
 *   @0x2f3820 movwmi r7, #0x2a9b
 *   @0x2f3824 b 0x137b82c <b2_toiTime+0xc22388>
 *   @0x2f3828 andvs r2, r11, r3, lsl #6
 *   @0x2f382c ldrblt r4, [r0, #-0x770]!
 *   @0x2f3830 blvc 0x198dc44 <b2_toiTime+0x12347a0>
 *   @0x2f3834 .word 0x7c1d7b18
 *   @0x2f3838 mrrcvc p4, #0x1, r0, lr, c2
 *   @0x2f383c andvs lr, r0, #270336
 *   @0x2f3840 vldmiavc r12, {d23, d24, d25, d26, d27, d28, d29, d30, d31}
 *   @0x2f3844 blvc 0xfe904454 <b2_toiTime+0xfffffffffe1aafb0>
 *   @0x2f3848 andhs lr, r0, #270336
 *   @0x2f384c addsmi r7, r1, #152, #24
 *   @0x2f3850 bne 0xfe56849c <b2_toiTime+0xfffffffffde0eff8>
 *   @0x2f3854 b 0x1374924 <b2_toiTime+0xc1b480>
 *   @0x2f3858 .word 0x43226205
 *   @0x2f385c andhs lr, r0, #270336
 *   @0x2f3860 andle r4, r8, #268435465
 *   @0x2f3864 bl 0x3c04bc <error_g0017+0x19160>
 *   @0x2f3868 .word 0xf8130241
 *   @0x2f386c ldmdavc r3, {r0, r4} ^
 *   @0x2f3870 andhs lr, r0, r3, asr #20
 *   @0x2f3874 andhs r11, r0, r0, ror sp
 *   @0x2f3878 ldrblt r11, [r0, #-0xd70]!
 *   @0x2f387c blvc 0x198dc90 <b2_toiTime+0x12347ec>
 *   @0x2f3880 vmovvc r7, lr, d8
 *   @0x2f3884 .word 0x7c1c0412
 *   @0x2f3888 andvs lr, r0, #270336
 *   @0x2f388c ldrteq r7, [r6], #-3032
 *   @0x2f3890 blvc 0xfe9044a0 <b2_toiTime+0xfffffffffe1aaffc>
 *   @0x2f3894 strvs lr, [r4], -r6, asr #20
 *   @0x2f3898 b 0x1392c10 <b2_toiTime+0xc3976c>
 *   @0x2f389c .word 0xf1032200
 *   @0x2f38a0 ldcvc p0, c0, [r11], {20}
 *   @0x2f38a4 b 0x1484544 <b2_toiTime+0xd2b0a0>
 *   @0x2f38a8 stmdavs r11, {r0, r1, r9, r10, sp}
 *   @0x2f38ac andsle r1, r7, r12, asr r12
 *   @0x2f38b0 addsmi r3, r10, #67108864
 *   @0x2f38b4 ldrmi r11, [r3], -r8, lsr #30
 *   @0x2f38b8 bl 0x2fa330 <ps_hints_apply+0x8f30>
 *   @0x2f38bc bne 0xfe8f49d4 <b2_toiTime+0xfffffffffe19b530>
 *   @0x2f38c0 andle r4, r10, #176, #4
 *   @0x2f38c4 blpl 0x3b191c <error_g0017+0xa5c0>
 *   @0x2f38c8 .word 0x0c01f814
 *   @0x2f38cc andhs lr, r5, r0, asr r10
 *   @0x2f38d0 mrrcne p1, #0x0, sp, sp, c4
 *   @0x2f38d4 movwlo sp, #0x1005
 *   @0x2f38d8 strdhs lr, pc, [r0], -r1
 *   @0x2f38dc ldcllt p0, c6, [r0, #-44]!
 *   @0x2f38e0 ldcllt p0, c2, [r0, #-0]!
 *   @0x2f38e4 andhs r6, r10, #49152
 *   @0x2f38e8 bvc 0x198ba18 <b2_toiTime+0x1232574>
 *   @0x2f38ec ldreq r7, [r2], #-2584
 *   @0x2f38f0 andvs lr, r0, #270336
 *   @0x2f38f4 bvc 0xfe9d245c <b2_toiTime+0xfffffffffe278fb8>
 *   @0x2f38f8 andhs r4, r0, r2, lsl #6
 *   @0x2f38fc movwhs lr, #0x3a42
 *   @0x2f3900 ldrbmi r6, [r0, -r11]!
 *   @0x2f3904 strmi r6, [r3], -r1, lsl #2
 *   @0x2f3908 blvc 0x512638 <SrcVerts+0x6f67c>
 *   @0x2f390c b 0x137495c <b2_toiTime+0xc1b4b8>
 *   @0x2f3910 blvc 0xff50c118 <b2_toiTime+0xfffffffffedb2c74>
 *   @0x2f3914 movwmi r7, #0x2b89
 *   @0x2f3918 ldrvc r2, [r8], -r0
 *   @0x2f391c andhs lr, r1, #270336
 *   @0x2f3920 .word 0x4770629a
 *   @0x2f3924 push {r1, r6, r7, r8, r11, sp, lr}
 *   @0x2f3928 mrrcne p3, #0xf, r4, r1, c0
 *   @0x2f392c suble r6, r11, r7, lsl #16
 *   @0x2f3930 strhs r6, [r12], #-2625
 *   @0x2f3934 .word 0xc028f8d0
 *   @0x2f3938 movtmi r3, #0xc201
 *   @0x2f393c strbmi r3, [r1, #-0x410]!
 *   @0x2f3940 stmdbvs r5, {r1, r6, r9, r12, lr, pc}
 *   @0x2f3944 stcpl p9, c1, [lr, #-172]!
 *   @0x2f3948 .word 0xf893785d
 *   @0x2f394c .word 0xf8938005
 *   @0x2f3950 strteq r9, [sp], #-8
 *   @0x2f3954 strvs lr, [r6, #-0xa45]
 *   @0x2f3958 b 0x16d1cd8 <b2_toiTime+0xf78834>
 *   @0x2f395c teqmi r5, #8, #16
 *   @0x2f3960 b 0x1451be0 <b2_toiTime+0xcf873c>
 *   @0x2f3964 ldmdbvc lr, {r1, r2, r8, r10, sp}
 *   @0x2f3968 svclt #0x3842aa
 *   @0x2f396c b 0x150521c <b2_toiTime+0xdabd78>
 *   @0x2f3970 ldmibvc lr, {r1, r2, r11, sp, lr} ^
 *   @0x2f3974 stmdaeq r6, {r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f3978 b 0x1511ff8 <b2_toiTime+0xdb8b54>
 *   @0x2f397c bvc 0x1a7d99c <b2_toiTime+0x13244f8>
 *   @0x2f3980 b 0x1474a60 <b2_toiTime+0xd1b5bc>
 *   @0x2f3984 .word 0xf8936609
 *   @0x2f3988 bvc 0xfe9d79bc <b2_toiTime+0xfffffffffe27e518>
 *   @0x2f398c streq lr, [r9], -r6, asr #20
 *   @0x2f3990 ldmiblo pc!, {r0, r2, r8, r12, sp, lr, pc} ^
 *   @0x2f3994 strhs lr, [r3], -r6, asr #20
 *   @0x2f3998 strbmi r1, [r2, #-0xb75]
 *   @0x2f399c bl 0xff3a99e8 <b2_toiTime+0xfffffffffec50544>
 *   @0x2f39a0 addsmi r0, lr, #603979776
 *   @0x2f39a4 stmne r11!, {r0, r2, r3, r11, r12, lr, pc}
 *   @0x2f39a8 mrrcne p1, #0x0, sp, r3, c3
 *   @0x2f39ac andlo sp, r1, #12
 *   @0x2f39b0 ldmdbvs sp!, {r0, r1, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2f39b4 andle r4, r4, #-1342177270
 *   @0x2f39b8 andvs r6, r3, #-2147483600
 *   @0x2f39bc pop {r0, r6, r9, sp, lr}
 *   @0x2f39c0 strdlo r8, r9, [r1, -r0]
 *   @0x2f39c4 ldr r3, [r10, r12, lsl #8]!
 *   @0x2f39c8 strvc r2, [r3], -r0, lsl #6
 *   @0x2f39cc mvnshi lr, #12386304
 *   @0x2f39d0 svcmi #0xf8e92d
 *   @0x2f39d4 stmdbvs r7, {r2, r9, r10, lr}
 *   @0x2f39d8 stmdavs sp, {r0, r3, r7, r9, r10, lr}
 *   @0x2f39dc mulgt sp, r7, r8
 *   @0x2f39e0 b 0x16d26d4 <b2_toiTime+0xf79230>
 *   @0x2f39e4 b 0x1606a1c <b2_toiTime+0xead578>
 *   @0x2f39e8 blvc 0x1ce9fc <_Z11HandleOtherv+0x468>
 *   @0x2f39ec .word 0x0c03ea4c
 *   @0x2f39f0 b 0x1a128e4 <b2_toiTime+0x12b9440>
 *   @0x2f39f4 rsble r2, r3, r3, lsl #24
 *   @0x2f39f8 stclne p1, c11, [r11], #-72
 *   @0x2f39fc strlo sp, [r1, #-0x63]
 *   @0x2f3a00 .word 0xf04f4660
 *   @0x2f3a04 bl 0x2f5a0c <ps_hints_apply+0x460c>
 *   @0x2f3a08 movwhs r0, #0xc608
 *   @0x2f3a0c blx 0x3b5bee <error_g0017+0xe892>
 *   @0x2f3a10 tstlo r0, r6, lsl #2
 *   @0x2f3a14 .word 0xf817187b
 *   @0x2f3a18 ldmdavc r9, {r0, sp, pc} ^
 *   @0x2f3a1c mullt r4, r3, r8
 *   @0x2f3a20 b 0x1334a4c <b2_toiTime+0xbdb5a8>
 *   @0x2f3a24 .word 0xf893610a
 *   @0x2f3a28 b 0x135ba3c <b2_toiTime+0xc02598>
 *   @0x2f3a2c .word 0xf893010a
 *   @0x2f3a30 b 0x135ba40 <b2_toiTime+0xc0259c>
 *   @0x2f3a34 .word 0xf893210a
 *   @0x2f3a38 addmi r10, sp, #5
 *   @0x2f3a3c bmi 0x5ae380 <g_SWFlineaavertbuff+0x5b2b8>
 *   @0x2f3a40 bvs 0x5ee370 <g_SWFaavertbuff+0x1b2a8>
 *   @0x2f3a44 mullt r7, r3, r8
 *   @0x2f3a48 beq 0x5ee378 <g_SWFaavertbuff+0x1b2b0>
 *   @0x2f3a4c mullt r6, r3, r8
 *   @0x2f3a50 bhs 0x5ee380 <g_SWFaavertbuff+0x1b2b8>
 *   @0x2f3a54 ldrbmi sp, [r5, #-0x314]
 *   @0x2f3a58 .word 0xf106d902
 *   @0x2f3a5c ands r0, r0, r1, lsl #16
 *   @0x2f3a60 bne 0x1d523c8 <b2_toiTime+0x15f8f24>
 *   @0x2f3a64 streq r7, [r0], #-2591
 *   @0x2f3a68 andvs lr, r7, r0, asr #20
 *   @0x2f3a6c bvc 0xfe9d25f0 <b2_toiTime+0xfffffffffe27914c>
 *   @0x2f3a70 b 0x1304758 <b2_toiTime+0xbab2b4>
 *   @0x2f3a74 bicmi r2, r11, #3
 *   @0x2f3a78 stmdale r4, {r3, r4, r7, r9, lr}
 *   @0x2f3a7c and r4, r3, r8, lsl #8
 *   @0x2f3a80 strmi r4, [r0, #0x630]
 *   @0x2f3a84 strhhs sp, [r0], -pc
 *   @0x2f3a88 ldrbmi r11, [r5, #-0x1f2]
 *   @0x2f3a8c stmdble r2, {r0, r1, r5, r11, sp, lr}
 *   @0x2f3a90 strbmi r3, [r6, #-0x601]!
 *   @0x2f3a94 andhs sp, r1, #23
 *   @0x2f3a98 strtvc r6, [r2], -r5, ror #3
 *   @0x2f3a9c ldmdbvs r11, {r1, r2, r5, r6, r9, sp, lr}
 *   @0x2f3aa0 andle r4, r0, #152, #4
 *   @0x2f3aa4 qasxmi r11, r0, r0
 *   @0x2f3aa8 .word 0xff3cf7ff
 *   @0x2f3aac tstlt r0, r0, lsr #28
 *   @0x2f3ab0 and r6, r0, r0, lsr #20
 *   @0x2f3ab4 stmibvs r3!, {r5, r9, sp, lr} ^
 *   @0x2f3ab8 andlo pc, r0, r9, asr #17
 *   @0x2f3abc svchi #0xf8e8bd
 *   @0x2f3ac0 pop {r5, r6, r9, r10, lr}
 *   @0x2f3ac4 strdhs r8, r9, [r0], -r8
 *   @0x2f3ac8 svchi #0xf8e8bd
 *   @0x2f3acc blge 0x3a0ef0 <af_khms_nonbase_uniranges+0x4>
 *   @0x2f3ad0 .word 0xf8432200
 *   @0x2f3ad4 ldrmi r1, [r9], -r4, lsl #26
 *   @0x2f3ad8 .word 0xff7af7ff
 *   @0x2f3adc .word 0xf85db003
 *   @0x2f3ae0 stmdbvs r3, {r2, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f3ae4 subvs r2, r10, r12, lsl #4
 *   @0x2f3ae8 bvc 0x912458 <b2_toiTime+0x1b8fb4>
 *   @0x2f3aec b 0x1374b3c <b2_toiTime+0xc1b698>
 *   @0x2f3af0 bvc 0xff90c2f8 <b2_toiTime+0xffffffffff1b2e54>
 *   @0x2f3af4 movwmi r7, #0x2a9b
 *   @0x2f3af8 b 0x137bb00 <b2_toiTime+0xc2265c>
 *   @0x2f3afc andvs r2, r11, r3, lsl #6
 *   @0x2f3b00 .word 0x61014770
 *   @0x2f3b04 blvc 0x1585318 <b2_toiTime+0xe2be74>
 *   @0x2f3b08 ldreq r7, [r2], #-2824
 *   @0x2f3b0c andvs lr, r0, #270336
 *   @0x2f3b10 blvc 0xfe552a38 <b2_toiTime+0xfffffffffddf9594>
 *   @0x2f3b14 andhs r4, r0, r2, lsl #6
 *   @0x2f3b18 b 0x1391380 <b2_toiTime+0xc37edc>
 *   @0x2f3b1c addsvs r2, r10, #268435456
 *   @0x2f3b20 push {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2f3b24 stmibvs r4, {r4, r5, r6, r7, r8, r9, r10, r11, lr} ^
 *   @0x2f3b28 stclne p8, c6, [r3], #-28
 *   @0x2f3b2c bvs 0x13a7c48 <b2_toiTime+0xc4e7a4>
 *   @0x2f3b30 bvs 0xfe47bf68 <b2_toiTime+0xfffffffffdd22ac4>
 *   @0x2f3b34 cmpmi r1, #16777216
 *   @0x2f3b38 adcsmi r3, r2, #16, #2
 *   @0x2f3b3c stmdbvs r5, {r0, r2, r3, r4, r5, r9, r12, lr, pc}
 *   @0x2f3b40 stclpl p8, c1, [sp], #-428
 *   @0x2f3b44 mulge r1, r3, r8
 *   @0x2f3b48 mullt r4, r3, r8
 *   @0x2f3b4c mulhi r8, r3, r8
 *   @0x2f3b50 bmi 0x5ae494 <g_SWFlineaavertbuff+0x5b3cc>
 *   @0x2f3b54 mulls r9, r3, r8
 *   @0x2f3b58 bvs 0x46e488 <g_RomDisk+0x76c68>
 *   @0x2f3b5c .word 0xf89378dd
 *   @0x2f3b60 b 0x15a3b94 <b2_toiTime+0xe4a6f0>
 *   @0x2f3b64 ldmvc sp, {r0, r2, r9, r11}
 *   @0x2f3b68 bhs 0x46e498 <g_RomDisk+0x76c78>
 *   @0x2f3b6c ldrbmi r7, [r4, #-0xa9d]
 *   @0x2f3b70 uasxmi r11, r4, r8
 *   @0x2f3b74 mulge r5, r3, r8
 *   @0x2f3b78 bmi 0x5ae4bc <g_SWFlineaavertbuff+0x5b3f4>
 *   @0x2f3b7c bvs 0x5ee4ac <g_SWFaavertbuff+0x1b3e4>
 *   @0x2f3b80 mullt r7, r3, r8
 *   @0x2f3b84 b 0x15921f8 <b2_toiTime+0xe38d54>
 *   @0x2f3b88 b 0x15763bc <b2_toiTime+0xe1cf18>
 *   @0x2f3b8c addsmi r2, r12, #201326592
 *   @0x2f3b90 b 0x16e9bd8 <b2_toiTime+0xf90734>
 *   @0x2f3b94 b 0x13c47c0 <b2_toiTime+0xc6b31c>
 *   @0x2f3b98 b 0x13cc7c0 <b2_toiTime+0xc7331c>
 *   @0x2f3b9c b 0x17b47d4 <b2_toiTime+0x105b330>
 *   @0x2f3ba0 andle r2, r7, r5, lsl #6
 *   @0x2f3ba4 adcmi r6, r11, #999424
 *   @0x2f3ba8 bicvs sp, r4, r4, lsl #4
 *   @0x2f3bac subvs r6, r2, #805306368
 *   @0x2f3bb0 svchi #0xf0e8bd
 *   @0x2f3bb4 .word 0x310c3201
 *   @0x2f3bb8 movwhs lr, #0x7bf
 *   @0x2f3bbc pop {r0, r1, r9, r10, r12, sp, lr}
 *   @0x2f3bc0 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f3bc4 .word 0x46044ff8
 *   @0x2f3bc8 strmi r6, [r9], r7, lsl #18
 *   @0x2f3bcc .word 0xf897680e
 *   @0x2f3bd0 blvc 0x11e3c0c <b2_toiTime+0xa8a768>
 *   @0x2f3bd4 .word 0x4c0cea4f
 *   @0x2f3bd8 .word 0x6c03ea4c
 *   @0x2f3bdc b 0x1612bd0 <b2_toiTime+0xeb972c>
 *   @0x2f3be0 blvc 0xff1b6bf4 <b2_toiTime+0xfffffffffea5d750>
 *   @0x2f3be4 .word 0x2c03ea5c
 *   @0x2f3be8 tstlt r2, r0, rrx
 *   @0x2f3bec rsble r1, r0, r3, ror r12
 *   @0x2f3bf0 strbtmi r3, [r0], -r1, lsl #12
 *   @0x2f3bf4 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f3bf8 streq lr, [r8, #-0xb00]
 *   @0x2f3bfc stmdaeq sp!, {r2, r3, r8, r9, sp} ^
 *   @0x2f3c00 blx 0x472814 <g_RomDisk+0x7aff4>
 *   @0x2f3c04 beq 0x730034 <g_SWFvertbuff+0x5cf6c>
 *   @0x2f3c08 movweq lr, #0xab07
 *   @0x2f3c0c .word 0xf8937959
 *   @0x2f3c10 streq r11, [r9], #-4
 *   @0x2f3c14 .word 0x610bea41
 *   @0x2f3c18 mullt r7, r3, r8
 *   @0x2f3c1c .word 0x010bea41
 *   @0x2f3c20 mullt r6, r3, r8
 *   @0x2f3c24 .word 0x210bea41
 *   @0x2f3c28 andlt pc, r10, r7, lsl r8
 *   @0x2f3c2c mulge r1, r3, r8
 *   @0x2f3c30 bmi 0x5ae574 <g_SWFlineaavertbuff+0x5b4ac>
 *   @0x2f3c34 bvs 0x5ee564 <g_SWFaavertbuff+0x1b49c>
 *   @0x2f3c38 mullt r3, r3, r8
 *   @0x2f3c3c beq 0x5ee56c <g_SWFaavertbuff+0x1b4a4>
 *   @0x2f3c40 mullt r2, r3, r8
 *   @0x2f3c44 bhs 0x5ee574 <g_SWFaavertbuff+0x1b4ac>
 *   @0x2f3c48 movwle r4, #0xf556
 *   @0x2f3c4c stmdble r2, {r1, r2, r3, r7, r9, lr}
 *   @0x2f3c50 stmdaeq r1, {r0, r2, r8, r12, sp, lr, pc}
 *   @0x2f3c54 bvc 0x192bc88 <b2_toiTime+0x11d27e4>
 *   @0x2f3c58 streq r7, [r0], #-2591
 *   @0x2f3c5c andvs lr, r7, r0, asr #20
 *   @0x2f3c60 bvc 0xfe9d27e4 <b2_toiTime+0xfffffffffe279340>
 *   @0x2f3c64 b 0x130494c <b2_toiTime+0xbab4a8>
 *   @0x2f3c68 and r2, r3, r3
 *   @0x2f3c6c strmi r4, [r0, #0x628]
 *   @0x2f3c70 andhs sp, r0, r2, asr #7
 *   @0x2f3c74 addmi r11, lr, #-2147483588
 *   @0x2f3c78 stmdble r2, {r0, r1, r5, r11, sp, lr}
 *   @0x2f3c7c strbmi r3, [r5, #-0x501]!
 *   @0x2f3c80 andhs sp, r1, #23
 *   @0x2f3c84 strtvc r6, [r2], -r6, ror #3
 *   @0x2f3c88 ldmdbvs r11, {r0, r2, r5, r6, r9, sp, lr}
 *   @0x2f3c8c andle r4, r0, #152, #4
 *   @0x2f3c90 qasxmi r11, r0, r0
 *   @0x2f3c94 .word 0xff45f7ff
 *   @0x2f3c98 tstlt r0, r0, lsr #28
 *   @0x2f3c9c and r6, r0, r0, lsr #20
 *   @0x2f3ca0 stmibvs r3!, {r5, r9, sp, lr} ^
 *   @0x2f3ca4 andlo pc, r0, r9, asr #17
 *   @0x2f3ca8 svchi #0xf8e8bd
 *   @0x2f3cac pop {r5, r6, r9, r10, lr}
 *   @0x2f3cb0 strdhs r8, r9, [r0], -r8
 *   @0x2f3cb4 svchi #0xf8e8bd
 *   @0x2f3cb8 blge 0x3a10dc <af_glag_nonbase_uniranges>
 *   @0x2f3cbc .word 0xf8432200
 *   @0x2f3cc0 ldrmi r1, [r9], -r4, lsl #26
 *   @0x2f3cc4 .word 0xff7df7ff
 *   @0x2f3cc8 .word 0xf85db003
 *   @0x2f3ccc stmdbvs r3, {r2, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f3cd0 subvs r2, r10, sp, lsl #4
 *   @0x2f3cd4 bvc 0x912644 <b2_toiTime+0x1b91a0>
 *   @0x2f3cd8 b 0x1374d28 <b2_toiTime+0xc1b884>
 *   @0x2f3cdc bvc 0xff90c4e4 <b2_toiTime+0xffffffffff1b3040>
 *   @0x2f3ce0 movwmi r7, #0x2a9b
 *   @0x2f3ce4 b 0x137bcec <b2_toiTime+0xc22848>
 *   @0x2f3ce8 andvs r2, r11, r3, lsl #6
 *   @0x2f3cec .word 0x61014770
 *   @0x2f3cf0 stmibvc r10, {r0, r1, r9, r10, lr} ^
 *   @0x2f3cf4 ldreq r7, [r2], #-2440
 *   @0x2f3cf8 andvs lr, r0, #270336
 *   @0x2f3cfc bvc 0x552624 <gp_ActiveMaskObjects+0xd95c>
 *   @0x2f3d00 andhs r4, r0, r2, lsl #6
 *   @0x2f3d04 b 0x138c46c <b2_toiTime+0xc32fc8>
 *   @0x2f3d08 andsvs r2, r8, #268435456
 *   @0x2f3d0c .word 0x4770619a
 *   @0x2f3d10 ldrbmi r2, [r0, -r0]!
 *   @0x2f3d14 andvs r2, r8, r0
 *   @0x2f3d18 .word 0xf04f4770
 *   @0x2f3d1c movwhs r3, #0xe2ff
 *   @0x2f3d20 stm r1, {sp}
 *   @0x2f3d24 ldrbmi r0, [r0, -r12]!
 *   @0x2f3d28 strdlo r11, r12, [r4], -r0
 *   @0x2f3d2c .word 0x2c03f810
 *   @0x2f3d30 .word 0xf8102400
 *   @0x2f3d34 ldreq r3, [r2], #-3076
 *   @0x2f3d38 andvs lr, r3, #270336
 *   @0x2f3d3c .word 0x3c01f810
 *   @0x2f3d40 .word 0xf810431a
 *   @0x2f3d44 b 0x1382d54 <b2_toiTime+0xc298b0>
 *   @0x2f3d48 addsmi r2, r4, #805306368
 *   @0x2f3d4c ldmdbne r3, {r0, r2, r4, r9, r12, lr, pc}
 *   @0x2f3d50 bl 0x2f5ec4 <ps_hints_apply+0x4ac4>
 *   @0x2f3d54 .word 0xf8100583
 *   @0x2f3d58 stmdavc lr!, {r0, r1, r5, r12, sp, lr} ^
 *   @0x2f3d5c b 0x147463c <b2_toiTime+0xd1b198>
 *   @0x2f3d60 stmvc pc!, {r0, r1, r2, r9, r10, lr}
 *   @0x2f3d64 teqmi lr, #15532032
 *   @0x2f3d68 andle r4, r1, #268435467
 *   @0x2f3d6c .word 0xe7ec461a
 *   @0x2f3d70 adcsmi r4, r1, #771751936
 *   @0x2f3d74 mrrcne p9, #0x0, sp, r12, c3
 *   @0x2f3d78 andhs lr, r0, r7, ror #15
 *   @0x2f3d7c strdhs r11, r12, [r1], -r0
 *   @0x2f3d80 ldrblt r11, [r0, #0xdf0]!
 *   @0x2f3d84 .word 0xf8103004
 *   @0x2f3d88 strhs r2, [r0], #-3075
 *   @0x2f3d8c .word 0x3c04f810
 *   @0x2f3d90 ldreq r2, [r2], #-1797
 *   @0x2f3d94 andvs lr, r3, #270336
 *   @0x2f3d98 .word 0x3c01f810
 *   @0x2f3d9c .word 0xf810431a
 *   @0x2f3da0 b 0x1382db0 <b2_toiTime+0xc2990c>
 *   @0x2f3da4 addsmi r2, r4, #805306368
 *   @0x2f3da8 ldmdbne r5, {r1, r3, r4, r9, r12, lr, pc}
 *   @0x2f3dac blx 0x4b5f6a <SrcVerts+0x12fae>
 *   @0x2f3db0 stmibne r3, {r0, r2, r9, r10, r12, sp, lr, pc}
 *   @0x2f3db4 andgt pc, r6, r0, lsl r8
 *   @0x2f3db8 eorseq r7, r6, #6160384
 *   @0x2f3dbc strmi lr, [r12], -r6, asr #20
 *   @0x2f3dc0 mulgt r2, r3, r8
 *   @0x2f3dc4 streq lr, [r12], -r6, asr #20
 *   @0x2f3dc8 andle r4, r1, #268435467
 *   @0x2f3dcc strb r4, [r10, r10, lsr #12]!
 *   @0x2f3dd0 stclne p9, c13, [r12], #-4
 *   @0x2f3dd4 ldmvc r8, {r0, r1, r2, r5, r6, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x2f3dd8 b 0x13d224c <b2_toiTime+0xc78da8>
 *   @0x2f3ddc ldcllt p0, c2, [r0, #0]!
 *   @0x2f3de0 ldcllt p0, c2, [r0, #0]!
 *   @0x2f3de4 strdlo r11, r12, [r4], -r0
 *   @0x2f3de8 .word 0x3c03f810
 *   @0x2f3dec .word 0xf810270b
 *   @0x2f3df0 ldreq r2, [r11], #-3076
 *   @0x2f3df4 movwvs lr, #0x2a43
 *   @0x2f3df8 .word 0x2c01f810
 *   @0x2f3dfc .word 0xf8104313
 *   @0x2f3e00 b 0x13bee10 <b2_toiTime+0xc6596c>
 *   @0x2f3e04 andhs r2, r0, #134217728
 *   @0x2f3e08 andsle r4, r7, #-1610612727
 *   @0x2f3e0c stmdaeq r4!, {r2, r3, r4, r7, r11, r12} ^
 *   @0x2f3e10 .word 0xf604fb07
 *   @0x2f3e14 .word 0xf8101985
 *   @0x2f3e18 stmdavc lr!, {r1, r2, lr, pc} ^
 *   @0x2f3e1c b 0x14746fc <b2_toiTime+0xd1b258>
 *   @0x2f3e20 .word 0xf895460c
 *   @0x2f3e24 b 0x14a3e34 <b2_toiTime+0xd4a990>
 *   @0x2f3e28 adcsmi r0, r1, #12, #12
 *   @0x2f3e2c strtmi sp, [r3], -r1, lsl #4
 *   @0x2f3e30 stmdale r1, {r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2f3e34 ldcllt p12, c1, [r0, #928]!
 *   @0x2f3e38 strb r1, [r5, r2, ror #24]!
 *   @0x2f3e3c ldcllt p0, c2, [r0, #0]!
 *   @0x2f3e40 .word 0x460fb5f8
 *   @0x2f3e44 ldrmi r6, [r9], -r4, lsl #18
 *   @0x2f3e48 stcne p6, c4, [r0, #84]!
 *   @0x2f3e4c .word 0xffcaf7ff
 *   @0x2f3e50 stmdavc r3, {r3, r4, r5, r8, r9, r12, sp, pc} ^
 *   @0x2f3e54 stmdbvc r6, {r1, r11, r12, sp, lr} ^
 *   @0x2f3e58 ldreq r7, [r11], #-2305
 *   @0x2f3e5c movwvs lr, #0x2a43
 *   @0x2f3e60 ldrteq r7, [r6], #-2242
 *   @0x2f3e64 b 0x1484ab8 <b2_toiTime+0xd2b614>
 *   @0x2f3e68 stmvc r2, {r0, r9, r10, sp, lr}
 *   @0x2f3e6c stmibvc r0, {r0, r6, r7, r8, r11, r12, sp, lr}
 *   @0x2f3e70 b 0x1484ab0 <b2_toiTime+0xd2b60c>
 *   @0x2f3e74 b 0x17bd67c <b2_toiTime+0x10641d8>
 *   @0x2f3e78 andle r2, r10, r2
 *   @0x2f3e7c strtmi r4, [r9], -r0, lsr #8
 *   @0x2f3e80 .word 0xff52f7ff
 *   @0x2f3e84 ldmvs r11!, {r3, r5, r8, r12, sp, pc} ^
 *   @0x2f3e88 qasxmi r4, r9, r8
 *   @0x2f3e8c .word 0x479868db
 *   @0x2f3e90 strdlt r11, r12, [lr, -r8]!
 *   @0x2f3e94 strtmi r1, [r9], -r0, lsr #19
 *   @0x2f3e98 ldrhtmi lr, [r8], #141
 *   @0x2f3e9c svclt #0x71f7ff
 *   @0x2f3ea0 ldcllt p6, c4, [r8, #192]!
 *   @0x2f3ea4 .word 0x460db570
 *   @0x2f3ea8 ldrmi r6, [r1], -r4, lsl #18
 *   @0x2f3eac .word 0xf7ff1da0
 *   @0x2f3eb0 teqlt r0, #612
 *   @0x2f3eb4 stmdavc r2, {r0, r1, r6, r11, r12, sp, lr}
 *   @0x2f3eb8 stmdbvc r1, {r1, r2, r6, r8, r11, r12, sp, lr}
 *   @0x2f3ebc b 0x13b4f30 <b2_toiTime+0xc5ba8c>
 *   @0x2f3ec0 stmvc r2, {r1, r8, r9, sp, lr} ^
 *   @0x2f3ec4 tstmi r3, #905969664
 *   @0x2f3ec8 strvs lr, [r1], -r6, asr #20
 *   @0x2f3ecc stmibvc r1, {r1, r7, r11, r12, sp, lr} ^
 *   @0x2f3ed0 stmibvc r1, {r1, r2, r3, r8, r9, lr}
 *   @0x2f3ed4 andhs lr, r2, r3, asr r10
 *   @0x2f3ed8 strhs lr, [r1], -r6, asr #20
 *   @0x2f3edc strtmi sp, [r0], #-4
 *   @0x2f3ee0 .word 0xf7ff4629
 *   @0x2f3ee4 ldmdblt r0, {r0, r5, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f3ee8 stmibne r0!, {r1, r2, r3, r4, r6, r8, r12, sp, pc}
 *   @0x2f3eec .word 0xf7ff4629
 *   @0x2f3ef0 stmdahs r0, {r3, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f3ef4 andhs r11, r0, r4, lsl pc
 *   @0x2f3ef8 andeq pc, r0, pc, rrx
 *   @0x2f3efc andhs r11, r1, r0, ror sp
 *   @0x2f3f00 .word 0xf04fbd70
 *   @0x2f3f04 ldcllt p0, c3, [r0, #-1020]!
 *   @0x2f3f08 stmdavc r2, {r0, r1, r6, r11, r12, sp, lr}
 *   @0x2f3f0c b 0x13b4f80 <b2_toiTime+0xc5badc>
 *   @0x2f3f10 stmvc r2, {r1, r8, r9, sp, lr} ^
 *   @0x2f3f14 stmvc r2, {r0, r1, r4, r8, r9, lr}
 *   @0x2f3f18 movwhs lr, #0x2a43
 *   @0x2f3f1c andhs r1, r0, r2, asr #27
 *   @0x2f3f20 .word 0xb12b3204
 *   @0x2f3f24 .word 0x1c04f812
 *   @0x2f3f28 .word 0x31013b01
 *   @0x2f3f2c ldrb r4, [r7, r8, lsl #8]!
 *   @0x2f3f30 strlt r4, [r8, #-0x770]
 *   @0x2f3f34 blvs 0x9ce248 <b2_toiTime+0x274da4>
 *   @0x2f3f38 stclt p7, c4, [r8, #-608]
 *   @0x2f3f3c svcmi #0xf7e92d
 *   @0x2f3f40 bmi 0x36e850 <_ZTS13C_UTF16String+0x58fc>
 *   @0x2f3f44 movwmi pc, #0x48d0
 *   @0x2f3f48 .word 0xf8d04605
 *   @0x2f3f4c .word 0xf04f3308
 *   @0x2f3f50 .word 0xf8d00801
 *   @0x2f3f54 strhs r9, [r0, -r12, lsl #6]
 *   @0x2f3f58 strlo r1, [r4], #-2275
 *   @0x2f3f5c .word 0xf1b99300
 *   @0x2f3f60 rsble r0, sp, r0, lsl #30
 *   @0x2f3f64 stcne p14, c9, [r3, #0]!
 *   @0x2f3f68 .word 0xd369429e
 *   @0x2f3f6c stmvc r3!, {r1, r5, r7, r11, r12, sp, lr} ^
 *   @0x2f3f70 b 0x13da378 <b2_toiTime+0xc80ed4>
 *   @0x2f3f74 .word 0xf8942302
 *   @0x2f3f78 strtmi r11, [r3], #-4
 *   @0x2f3f7c addmi r7, r11, #1671168
 *   @0x2f3f80 sasxmi r11, r9, r8
 *   @0x2f3f84 tstlo r0, #13959168
 *   @0x2f3f88 b 0x918394 <b2_toiTime+0x1beef0>
 *   @0x2f3f8c subsle r0, r1, r3, lsl #30
 *   @0x2f3f90 strlo r7, [lr], #-2466
 *   @0x2f3f94 .word 0x3c07f814
 *   @0x2f3f98 .word 0x21061b08
 *   @0x2f3f9c movwhs lr, #0x2a43
 *   @0x2f3fa0 .word 0xf203fb01
 *   @0x2f3fa4 ble 0x3849ec <_ZTS13C_UTF16String+0x1ba98>
 *   @0x2f3fa8 cdp p0, #0xb, c15, c2, c4, #0x1
 *   @0x2f3fac b 0x14857c0 <b2_toiTime+0xd2c31c>
 *   @0x2f3fb0 b 0x1abbfe4 <b2_toiTime+0x1362b40>
 *   @0x2f3fb4 teqle sp, r0, lsl r12
 *   @0x2f3fb8 tstvs r4, #13959168
 *   @0x2f3fbc svceq #0x6ea18
 *   @0x2f3fc0 ldrmi sp, [r12, #0x22]
 *   @0x2f3fc4 bl 0x3e88a4 <jpeg_std_message_table+0x14c>
 *   @0x2f3fc8 strhs r0, [r6], -r12, lsl #4
 *   @0x2f3fcc blx 0x47611e <g_RomDisk+0x7e8fe>
 *   @0x2f3fd0 stmdane r6!, {r1, r8, r12, sp, lr, pc} ^
 *   @0x2f3fd4 andlt pc, r1, r4, lsl r8
 *   @0x2f3fd8 streq r7, [r9], #-2161
 *   @0x2f3fdc .word 0x610bea41
 *   @0x2f3fe0 mullt r3, r6, r8
 *   @0x2f3fe4 .word 0x010bea41
 *   @0x2f3fe8 mullt r2, r6, r8
 *   @0x2f3fec .word 0x210bea41
 *   @0x2f3ff0 qaddle r4, r1, r2
 *   @0x2f3ff4 ldmdbvc r3!, {r1, r4, r5, r8, r11, r12, sp, lr} ^
 *   @0x2f3ff8 svclt #0x2ce015
 *   @0x2f3ffc .word 0xf1024613
 *   @0x2f4000 ldrb r0, [lr, r1, lsl #24]
 *   @0x2f4004 bllo 0x341024
 *   @0x2f4008 stmdavc r2!, {r0, r1, r5, r7, r8, r12, sp, pc} ^
 *   @0x2f400c ldreq r7, [r2], #-2081
 *   @0x2f4010 andvs lr, r1, #270336
 *   @0x2f4014 movwmi r7, #0xa8e1
 *   @0x2f4018 b 0x13922a4 <b2_toiTime+0xc38e00>
 *   @0x2f401c ldrbmi r2, [r2, #-0x201]
 *   @0x2f4020 stmdbvc r2!, {r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2f4024 b 0x13d25b8 <b2_toiTime+0xc79114>
 *   @0x2f4028 streq r2, [r2, -r2, lsl #6]
 *   @0x2f402c svclt #0x54b21b
 *   @0x2f4030 ssub8mi r1, pc, pc
 *   @0x2f4034 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x2f4038 stmdaeq r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0x2f403c str r9, [lr, r1, lsl #24]
 *   @0x2f4040 andlt r4, r3, r8, lsr r6
 *   @0x2f4044 svchi #0xf0e8bd
 *   @0x2f4048 ldrsblo pc, [r12], r0
 *   @0x2f404c ldrheq pc, [r8], r0
 *   @0x2f4050 andne lr, r0, r3, lsl #22
 *   @0x2f4054 andle r4, r6, #805306376
 *   @0x2f4058 addmi r6, r10, #1703936
 *   @0x2f405c ldmvs r10, {r0, r8, r12, lr, pc} ^
 *   @0x2f4060 tstlo r0, #425984
 *   @0x2f4064 strdhs lr, pc, [r0], -r6
 *   @0x2f4068 ssub16mi r4, r8, r0
 *   @0x2f406c push {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2f4070 blhs 0x308038 <TT_New_Context+0x7e30>
 *   @0x2f4074 stmvs r6, {r0, r2, r7, r11, sp, lr} ^
 *   @0x2f4078 ldm r5, {r0, r3, r8, r9, r10, r11, r12, pc}
 *   @0x2f407c stmvs r12!, {r9, r10, r12} ^
 *   @0x2f4080 mulshi r2, r0, r8
 *   @0x2f4084 ldmdahi r6!, {r0, r2, r4, r5, r6, r11, pc}
 *   @0x2f4088 ldmdbne r8, {r0, r2, r4, r5, r6, r8, r9, r11, r12, lr, pc} ^
 *   @0x2f408c ldmdale r2!, {r4, r6, r8, r10, lr} ^
 *   @0x2f4090 blle 0x1effc98 <b2_toiTime+0x17a67f4>
 *   @0x2f4094 strbmi r1, [r8, #-0x9b8]
 *   @0x2f4098 blx 0x52a256 <SrcVerts+0x8729a>
 *   @0x2f409c .word 0xf108f805
 *   @0x2f40a0 sbcne r0, r0, r7
 *   @0x2f40a4 andne pc, r0, r6, lsl #22
 *   @0x2f40a8 .word 0xd3644282
 *   @0x2f40ac .word 0xf01310da
 *   @0x2f40b0 blx 0x5f4cd6 <g_SWFaavertbuff+0x21c0e>
 *   @0x2f40b4 ldrtmi r2, [r12], #-1799
 *   @0x2f40b8 .word 0xf04fd004
 *   @0x2f40bc vst2.8 {d16, d18}, [pc], r0
 *   @0x2f40c0 sub r4, r0, pc, ror r10
 *   @0x2f40c4 ldrbmi pc, [pc, -pc, asr #8]!
 *   @0x2f40c8 swple r4, lr, [r2]
 *   @0x2f40cc ldm sp!, {sp}
 *   @0x2f40d0 qsub8mi r8, r0, r0
 *   @0x2f40d4 bhs 0x4c59e4 <SrcVerts+0x22a28>
 *   @0x2f40d8 .word 0xf1004605
 *   @0x2f40dc stcle p0, c0, [r9, #-4]
 *   @0x2f40e0 .word 0x9c01f810
 *   @0x2f40e4 .word 0xf8113a08
 *   @0x2f40e8 b 0x154acf4 <b2_toiTime+0xdf1850>
 *   @0x2f40ec .word 0xf8000505
 *   @0x2f40f0 ldrb r5, [r0, r1, lsl #24]!
 *   @0x2f40f4 teqlt r10, r8, lsl #12
 *   @0x2f40f8 blx 0xcd2100 <b2_toiTime+0x578c5c>
 *   @0x2f40fc .word 0x3101f202
 *   @0x2f4100 stmdavc r8!, {r1, lr}
 *   @0x2f4104 eorvc r4, r10, r2, lsl #6
 *   @0x2f4108 movwlo r4, #0x1464
 *   @0x2f410c .word 0x460fe7dc
 *   @0x2f4110 .word 0xf897b138
 *   @0x2f4114 blx 0xda011c <b2_toiTime+0x646c78>
 *   @0x2f4118 .word 0x3101f700
 *   @0x2f411c streq lr, [r7, -r11, lsl #20]
 *   @0x2f4120 ldrmi r4, [r8], #-826
 *   @0x2f4124 mullt r0, r5, r8
 *   @0x2f4128 blx 0xb7e150 <b2_toiTime+0x424cac>
 *   @0x2f412c b 0x14f1d40 <b2_toiTime+0xd9889c>
 *   @0x2f4130 eorvc r0, pc, r11, lsl #14
 *   @0x2f4134 andseq sp, r2, #4, #26
 *   @0x2f4138 sbcsmi r7, r10, r8, ror #16
 *   @0x2f413c rsbvc r4, r10, r2, lsl #6
 *   @0x2f4140 .word 0xf1094464
 *   @0x2f4144 strbmi r0, [lr, #-0x901]
 *   @0x2f4148 strtmi sp, [r7], -r0, asr #1
 *   @0x2f414c andhs r4, r0, #64, #12
 *   @0x2f4150 ldrtmi r2, [sp], -r7, lsl #16
 *   @0x2f4154 streq pc, [r1, -r7, lsl #2]
 *   @0x2f4158 .word 0xf811ddd9
 *   @0x2f415c stmdalo r8, {r0, r8, r9, r11, r12, lr}
 *   @0x2f4160 .word 0xf817432a
 *   @0x2f4164 blx 0xb8b170 <b2_toiTime+0x431ccc>
 *   @0x2f4168 andseq pc, r2, #3072
 *   @0x2f416c streq lr, [r5, #-0xa4b]
 *   @0x2f4170 .word 0x5c01f807
 *   @0x2f4174 andhs lr, r3, r12, ror #15
 *   @0x2f4178 svchi #0xf0e8bd
 *   @0x2f417c svcmi #0xf0e92d
 *   @0x2f4180 stmdbeq r0, {r0, r1, r4, r5, r7, r8, r12, sp, lr, pc}
 *   @0x2f4184 addlt r6, r7, r4, lsl #17
 *   @0x2f4188 .word 0xc00cf8d0
 *   @0x2f418c stmvs r6!, {r4, r8, r10, r11, r12, pc}
 *   @0x2f4190 .word 0x0180e894
 *   @0x2f4194 strls r7, [r2], -r0, lsl #25
 *   @0x2f4198 rfeia r12!
 *   @0x2f419c rfeia r12!
 *   @0x2f41a0 vaddl.s8 q14, d0, d0
 *   @0x2f41a4 bl 0x5544a8 <g_SWFlineaavertbuff+0x13e0>
 *   @0x2f41a8 strbmi r0, [r3, #-0x304]
 *   @0x2f41ac adcshi pc, r10, r0, lsl #4
 *   @0x2f41b0 .word 0xf2c02d00
 *   @0x2f41b4 bl 0x454498 <g_RomDisk+0x5cc78>
 *   @0x2f41b8 adcsmi r0, r11, #12, #6
 *   @0x2f41bc adcshi pc, r2, r0, lsl #4
 *   @0x2f41c0 .word 0xf304fb00
 *   @0x2f41c4 .word 0xf003fb0c
 *   @0x2f41c8 bl 0x3401ec
 *   @0x2f41cc addmi r0, r2, #224
 *   @0x2f41d0 adchi pc, r8, r0, asr #1
 *   @0x2f41d4 andhs r11, r0, r11, lsl #18
 *   @0x2f41d8 .word 0xf1bce0a5
 *   @0x2f41dc rscsle r0, r10, r0, lsl #30
 *   @0x2f41e0 b 0x16da1f0 <b2_toiTime+0xf80d4c>
 *   @0x2f41e4 .word 0xf00907e9
 *   @0x2f41e8 .word 0xf8cd0907
 *   @0x2f41ec .word 0xf1c9c004
 *   @0x2f41f0 blx 0x2f621a <ps_hints_apply+0x4e1a>
 *   @0x2f41f4 ldrmi r7, [r8, #0x705]
 *   @0x2f41f8 ldrmi r11, [r8], r8, lsr #31
 *   @0x2f41fc .word 0xf1c820ff
 *   @0x2f4200 blx 0x2f5628 <ps_hints_apply+0x4228>
 *   @0x2f4204 bl 0xff57022c <b2_toiTime+0xfffffffffee16d88>
 *   @0x2f4208 ldrtmi r0, [r7], #-1029
 *   @0x2f420c bicmi r9, r0, #20971520
 *   @0x2f4210 streq lr, [r3], -r8, asr #23
 *   @0x2f4214 strls r4, [r4], -r0, lsr #1
 *   @0x2f4218 andls r11, r3, r0, asr #5
 *   @0x2f421c strmi r2, [r4], -r0
 *   @0x2f4220 svceq #0xf1b9
 *   @0x2f4224 .word 0xf8ddd023
 *   @0x2f4228 strbmi r10, [r2, #0x4]!
 *   @0x2f422c stmdavc r8, {r0, r1, r8, r12, lr, pc}
 *   @0x2f4230 .word 0x3101464c
 *   @0x2f4234 strbmi lr, [r4, #-0xd]
 *   @0x2f4238 addsmi sp, r1, #8, #20
 *   @0x2f423c stmdavc sp, {r1, r9, r12, lr, pc}
 *   @0x2f4240 .word 0x43283101
 *   @0x2f4244 ldrsblt pc, [r4], -sp
 *   @0x2f4248 and r4, r2, r12, asr r4
 *   @0x2f424c bl 0xff4f6a54 <b2_toiTime+0xfffffffffed9d5b0>
 *   @0x2f4250 stcls p4, c0, [r3, #-16]
 *   @0x2f4254 blx 0x432b5c <g_RomDisk+0x3b33c>
 *   @0x2f4258 ldclne p2, c0, [lr], #-0
 *   @0x2f425c beq 0x5aea78 <g_SWFlineaavertbuff+0x5b9b0>
 *   @0x2f4260 addlt r7, r0, #3997696
 *   @0x2f4264 streq lr, [r5, #-0xa4a]
 *   @0x2f4268 stcls p0, c7, [r4, #-244]
 *   @0x2f426c ldrmi lr, [sp], -r1
 *   @0x2f4270 stchs p6, c4, [r7, #-248]
 *   @0x2f4274 .word 0xf811dd0f
 *   @0x2f4278 vstrlo d10, [r8, #-4]
 *   @0x2f427c andeq lr, r10, r0, asr #20
 *   @0x2f4280 blge 0x3722e0 <_ZTS13C_UTF16String+0x938c>
 *   @0x2f4284 blx 0x432b8e <g_RomDisk+0x3b36e>
 *   @0x2f4288 b 0x15b4a90 <b2_toiTime+0xe5b5ec>
 *   @0x2f428c .word 0xf8060a0a
 *   @0x2f4290 addlt r10, r0, #256
 *   @0x2f4294 stchs p7, c14, [r0, #-948]
 *   @0x2f4298 ldcle p6, c4, [r11, #-552]!
 *   @0x2f429c ble 0xb84d54 <b2_toiTime+0x42b8b0>
 *   @0x2f42a0 andle r4, r4, #268435465
 *   @0x2f42a4 mulge r0, r10, r8
 *   @0x2f42a8 b 0x13006b4 <b2_toiTime+0xba7210>
 *   @0x2f42ac blx 0x12f42dc <b2_toiTime+0xb9ae38>
 *   @0x2f42b0 .word 0xf44ffa04
 *   @0x2f42b4 .word 0xf8cd4b7f
 *   @0x2f42b8 blx 0xddc2c0 <b2_toiTime+0x682e1c>
 *   @0x2f42bc .word 0xf8ddfa05
 *   @0x2f42c0 andeq r11, r0, #0
 *   @0x2f42c4 streq pc, [r8, #-0x1c5]
 *   @0x2f42c8 beq 0x5aeafc <g_SWFlineaavertbuff+0x5ba34>
 *   @0x2f42cc andge pc, r0, sp, asr #17
 *   @0x2f42d0 .word 0xb000f8dd
 *   @0x2f42d4 .word 0xf896442c
 *   @0x2f42d8 addlt r10, r0, #0
 *   @0x2f42dc beq 0x5aec10 <g_SWFlineaavertbuff+0x5bb48>
 *   @0x2f42e0 andge pc, r0, r6, lsl #17
 *   @0x2f42e4 blx 0x132c344 <b2_toiTime+0xbd2ea0>
 *   @0x2f42e8 .word 0xf44ffa04
 *   @0x2f42ec .word 0xf8cd4b7f
 *   @0x2f42f0 blx 0xddc2f8 <b2_toiTime+0x682e54>
 *   @0x2f42f4 .word 0xf8ddfa05
 *   @0x2f42f8 blne 0x1c20300 <b2_toiTime+0x14c6e5c>
 *   @0x2f42fc beq 0x5aeb30 <g_SWFlineaavertbuff+0x5ba68>
 *   @0x2f4300 andge pc, r0, sp, asr #17
 *   @0x2f4304 .word 0xb000f8dd
 *   @0x2f4308 mulge r0, r6, r8
 *   @0x2f430c beq 0x5aec40 <g_SWFlineaavertbuff+0x5bb78>
 *   @0x2f4310 andge pc, r0, r6, lsl #17
 *   @0x2f4314 stcls p14, c9, [r2, #-4]
 *   @0x2f4318 strls r3, [r1], -r1, lsl #28
 *   @0x2f431c .word 0xf47f442f
 *   @0x2f4320 .word 0xe758af7f
 *   @0x2f4324 andlt r2, r7, r3
 *   @0x2f4328 svchi #0xf0e8bd
 *   @0x2f432c ldrbtmi r4, [r8], #-2049
 *   @0x2f4330 stmdalt pc, {r0, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc}
 *   @0x2f4334 andeq r4, pc, lr, lsl r11
 *   @0x2f4338 svcmi #0xf0e92d
 *   @0x2f433c addlt r4, r5, lr, lsl #12
 *   @0x2f4340 andmi pc, r4, #208, #16
 *   @0x2f4344 ldrtmi r4, [r2], -r10, asr #18
 *   @0x2f4348 strmi r10, [r5], -r3, lsl #22
 *   @0x2f434c strmi r4, [r4], -r0, lsr #15
 *   @0x2f4350 .word 0xf0402800
 *   @0x2f4354 stmdbls r3, {r0, r3, r7, pc}
 *   @0x2f4358 vmla.i8 d18, d0, d3
 *   @0x2f435c ldrtmi r8, [r0], -r4, lsl #1
 *   @0x2f4360 subvc pc, r1, #20971520
 *   @0x2f4364 ldc2 p7, c15, [sp, #972]
 *   @0x2f4368 stmdahs r0, {r2, r9, r10, lr}
 *   @0x2f436c .word 0xf8d5d17c
 *   @0x2f4370 strmi r2, [r7], -r4, lsl #6
 *   @0x2f4374 strmi r9, [r0], r3, lsl #22
 *   @0x2f4378 bl 0x385b98 <_ZTS13C_UTF16String+0x1cc44>
 *   @0x2f437c .word 0xf8c50a03
 *   @0x2f4380 ldcne p3, c3, [r3, #-32]
 *   @0x2f4384 ldmvc r2, {r0, r4, r7, r11, r12, sp, lr} ^
 *   @0x2f4388 andhs lr, r1, #270336
 *   @0x2f438c svclt #0x282a20
 *   @0x2f4390 andls r2, r1, #32, #4
 *   @0x2f4394 addsmi r9, r6, #4096
 *   @0x2f4398 ldcne p0, c13, [r10, #8]
 *   @0x2f439c andle r4, r6, #612368384
 *   @0x2f43a0 movwvs pc, #0xc8c5
 *   @0x2f43a4 tsthi r0, #12910592
 *   @0x2f43a8 tstvc r4, #12910592
 *   @0x2f43ac .word 0xf893e05c
 *   @0x2f43b0 ldmvc r10, {r1, r12, pc} ^
 *   @0x2f43b4 b 0x1392820 <b2_toiTime+0xc3937c>
 *   @0x2f43b8 ldmdbvc r10, {r0, r3, r8, r11, sp} ^
 *   @0x2f43bc svceq #0xef1b9
 *   @0x2f43c0 andhs lr, r1, #270336
 *   @0x2f43c4 ldrmi sp, [r9], #2540
 *   @0x2f43c8 andeq pc, r3, #2
 *   @0x2f43cc svclt #0x2845d1
 *   @0x2f43d0 bhs 0x345f1c
 *   @0x2f43d4 .word 0xf103d144
 *   @0x2f43d8 strbmi r0, [r8, #-0xe]
 *   @0x2f43dc ldmibvc r9, {r6, r11, r12, lr, pc}
 *   @0x2f43e0 .word 0x0c06f04f
 *   @0x2f43e4 bl 0xff312b54 <b2_toiTime+0xfffffffffebb96b0>
 *   @0x2f43e8 b 0x1374414 <b2_toiTime+0xc1af70>
 *   @0x2f43ec blx 0x5fcbfa <g_SWFaavertbuff+0x29b32>
 *   @0x2f43f0 addmi pc, r8, #-2147483648
 *   @0x2f43f4 ldrmi sp, [r0], -r1, lsl #22
 *   @0x2f43f8 .word 0x2106e004
 *   @0x2f43fc .word 0xf0249300
 *   @0x2f4400 blls 0x32f628
 *   @0x2f4404 blx 0x33c810
 *   @0x2f4408 b 0x1530c28 <b2_toiTime+0xdd7784>
 *   @0x2f440c teqlt r8, #131072
 *   @0x2f4410 stmdalo r1, {r0, r3, r4, r6, r7, r8, r9, r11, r12, sp, lr}
 *   @0x2f4414 mulgt lr, r3, r8
 *   @0x2f4418 streq r3, [r9], #-788
 *   @0x2f441c .word 0x610cea41
 *   @0x2f4420 .word 0xcc03f813
 *   @0x2f4424 .word 0x010cea41
 *   @0x2f4428 .word 0xcc04f813
 *   @0x2f442c .word 0x210cea41
 *   @0x2f4430 .word 0xf893b1a8
 *   @0x2f4434 .word 0xf893c001
 *   @0x2f4438 b 0x16e0440 <b2_toiTime+0xf86f9c>
 *   @0x2f443c b 0x1607474 <b2_toiTime+0xeadfd0>
 *   @0x2f4440 .word 0xf8936c0b
 *   @0x2f4444 b 0x1620458 <b2_toiTime+0xec6fb4>
 *   @0x2f4448 .word 0xf8930c0b
 *   @0x2f444c b 0x162045c <b2_toiTime+0xec6fb8>
 *   @0x2f4450 strmi r2, [r12, #0xc0b]
 *   @0x2f4454 movwlo sp, #0x6904
 *   @0x2f4458 strbtmi r3, [r1], -r1, lsl #16
 *   @0x2f445c tstmi r7, #232, #14
 *   @0x2f4460 strbmi r3, [r11], -r1, lsl #12
 *   @0x2f4464 strhs lr, [lr], #1942
 *   @0x2f4468 andlt r4, r5, r0, lsr #12
 *   @0x2f446c svchi #0xf0e8bd
 *   @0x2f4470 blvs 0x1c50e30 <b2_toiTime+0x14f798c>
 *   @0x2f4474 .word 0x4604b510
 *   @0x2f4478 .word 0xf5046e80
 *   @0x2f447c .word 0xf7f3713c
 *   @0x2f4480 movwhs pc, #0xcc4
 *   @0x2f4484 rscslo pc, r4, #196, #16
 *   @0x2f4488 rscslo pc, r8, #196, #16
 *   @0x2f448c rscslo pc, r12, #196, #16
 *   @0x2f4490 ldrlt r11, [r8, #-0xd10]!
 *   @0x2f4494 sadd16mi r4, r12, r5
 *   @0x2f4498 ldc2l p7, c15, [r6, #1020]
 *   @0x2f449c .word 0xb1404601
 *   @0x2f44a0 stmvs r3, {r2, r3, r8, r12, sp, pc} ^
 *   @0x2f44a4 strtmi r6, [r8], -r3, lsr #32
 *   @0x2f44a8 pop {r0, r3, r7, r11, sp, lr}
 *   @0x2f44ac .word 0xf7f24038
 *   @0x2f44b0 strdhs r11, r12, [lr], r10
 *   @0x2f44b4 andeq r11, r0, r8, lsr sp
 *   @0x2f44b8 svcmi #0xf0e92d
 *   @0x2f44bc .word 0xf8d0b089
 *   @0x2f44c0 movwhs r8, #0x58
 *   @0x2f44c4 strmi r9, [r4], -r2, lsl #2
 *   @0x2f44c8 sadd16mi r6, r6, r3
 *   @0x2f44cc msrne APSR_nzcvqg, #144, #16
 *   @0x2f44d0 cmnle lr, r0, lsl #18
 *   @0x2f44d4 .word 0xf5006e87
 *   @0x2f44d8 andshs r7, r8, #293601280
 *   @0x2f44dc .word 0xf5c24628
 *   @0x2f44e0 strtmi lr, [r0], -r8, ror #16
 *   @0x2f44e4 ldrtmi r4, [r10], -r4, lsl #19
 *   @0x2f44e8 .word 0xf7ffab07
 *   @0x2f44ec stmdahs r0, {r1, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f44f0 stmdbls r7, {r0, r2, r3, r5, r6, r8, r12, lr, pc}
 *   @0x2f44f4 stmdble r10!, {r0, r1, r2, r8, r11, sp} ^
 *   @0x2f44f8 qasxmi r4, r10, r8
 *   @0x2f44fc ldc2l p7, c15, [r1], {243}
 *   @0x2f4500 .word 0xd1642800
 *   @0x2f4504 tstlo r8, #212, #16
 *   @0x2f4508 ldmne r9, {r0, r1, r2, r9, r11, r12, pc}
 *   @0x2f450c tstne r12, #196, #16
 *   @0x2f4510 mulls r3, r3, r8
 *   @0x2f4514 mulge r0, r3, r8
 *   @0x2f4518 .word 0xf8cd7899
 *   @0x2f451c .word 0xf8939010
 *   @0x2f4520 mrsls r9, apsr
 *   @0x2f4524 mulgt r5, r3, r8
 *   @0x2f4528 andsls pc, r4, sp, asr #17
 *   @0x2f452c mulls r1, r3, r8
 *   @0x2f4530 b 0x155299c <b2_toiTime+0xdf94f8>
 *   @0x2f4534 .word 0xf893290a
 *   @0x2f4538 .word 0xf1b9b007
 *   @0x2f453c teqle sp, r1, lsl #30
 *   @0x2f4540 .word 0x4c0cea4f
 *   @0x2f4544 .word 0x6c01ea4c
 *   @0x2f4548 bleq 0x5eee80 <g_SWFaavertbuff+0x1bdb8>
 *   @0x2f454c ldrsbgt pc, [r4], -sp
 *   @0x2f4550 blhs 0x62ee84 <g_SWFaavertbuff+0x5bdbc>
 *   @0x2f4554 svceq #0x7f1bb
 *   @0x2f4558 .word 0xf8ddd930
 *   @0x2f455c .word 0xf8ddc00c
 *   @0x2f4560 b 0x15585a8 <b2_toiTime+0xdff104>
 *   @0x2f4564 .word 0xf1ab210c
 *   @0x2f4568 bl 0xfef37590 <b2_toiTime+0xfffffffffe7de0ec>
 *   @0x2f456c stmdale r5!, {r2, r3, r4, r7, r8, r9, r10, r11}
 *   @0x2f4570 .word 0x0c01f10b
 *   @0x2f4574 stmdale r1!, {r2, r4, r7, r8, r10, lr}
 *   @0x2f4578 .word 0x0c0beb03
 *   @0x2f457c bl 0xff5c11a4 <b2_toiTime+0xfffffffffee67d00>
 *   @0x2f4580 .word 0xf8c40202
 *   @0x2f4584 bl 0x3bd21c <error_g0017+0x15ec0>
 *   @0x2f4588 .word 0xf04f0281
 *   @0x2f458c .word 0xf8c4090a
 *   @0x2f4590 .word 0xf8c41328
 *   @0x2f4594 addmi r12, r1, #32, #6
 *   @0x2f4598 .word 0xf893d00a
 *   @0x2f459c andlo r11, r1, r2
 *   @0x2f45a0 mulge r3, r3, r8
 *   @0x2f45a4 b 0x15811bc <b2_toiTime+0xe27d18>
 *   @0x2f45a8 blx 0x53edde <obj_has_event+0x426e>
 *   @0x2f45ac ldrb r2, [r2, r10, lsl #4]!
 *   @0x2f45b0 stmdale r3, {r1, r5, r6, r8, r10, lr}
 *   @0x2f45b4 .word 0xf8842301
 *   @0x2f45b8 and r3, r10, r12, lsr #6
 *   @0x2f45bc qasxmi r4, r9, r8
 *   @0x2f45c0 stc2 p7, c15, [r3], #-972
 *   @0x2f45c4 .word 0x21004628
 *   @0x2f45c8 .word 0xf5c12218
 *   @0x2f45cc strdhs lr, pc, [r8], -r2
 *   @0x2f45d0 .word 0xf8d4e08e
 *   @0x2f45d4 .word 0xf8d4a328
 *   @0x2f45d8 .word 0xf1b85318
 *   @0x2f45dc .word 0xf0000f00
 *   @0x2f45e0 stmdbls r2, {r1, r2, r7, pc}
 *   @0x2f45e4 .word 0xf0002900
 *   @0x2f45e8 strmi r8, [r8], -r2, lsl #1
 *   @0x2f45ec svc #0xa4f5c1
 *   @0x2f45f0 stmdahs r0, {r0, r7, r9, r10, lr}
 *   @0x2f45f4 .word 0xf105d07b
 *   @0x2f45f8 .word 0x210a0308
 *   @0x2f45fc streq lr, [r10, #0xb03]
 *   @0x2f4600 svceq #0xf1ba
 *   @0x2f4604 ldmvc pc, {r0, r1, r4, r5, r6, r12, lr, pc}
 *   @0x2f4608 ldmvc r8, {r1, r3, r4, r9, r10, lr} ^
 *   @0x2f460c .word 0xf8133304
 *   @0x2f4610 ldmdavc r2, {r2, r10, r11, lr, pc} ^
 *   @0x2f4614 strhs lr, [r7, -r0, asr #20]
 *   @0x2f4618 strheq pc, [lr], -r8
 *   @0x2f461c andhs lr, r12, #270336
 *   @0x2f4620 mulle lr, r0, r2
 *   @0x2f4624 strpl pc, [r7, #-0xb01]
 *   @0x2f4628 blo 0x2f0a58 <FT_Done_Memory+0x6de4>
 *   @0x2f462c .word 0xf895e7e8
 *   @0x2f4630 stmdbvc r11!, {r2, r12, sp, pc} ^
 *   @0x2f4634 blhs 0x5eef48 <g_SWFaavertbuff+0x1be80>
 *   @0x2f4638 svceq #0x10f01b
 *   @0x2f463c strlo sp, [r10, #-0x104]
 *   @0x2f4640 svchs #0x3f01
 *   @0x2f4644 ldrsh sp, [r2], #-19
 *   @0x2f4648 stmdavc r11!, {r0, r3, r5, r6, r11, r12, sp, lr}
 *   @0x2f464c streq r7, [r9], #-2602
 *   @0x2f4650 msrhi APSR_g, #212, #16
 *   @0x2f4654 .word 0x6103ea41
 *   @0x2f4658 andls r7, r3, #15400960
 *   @0x2f465c stmvc r11!, {r0, r3, r4, r8, r9, lr}
 *   @0x2f4660 .word 0xf8957a6a
 *   @0x2f4664 b 0x1364688 <b2_toiTime+0xc0b1e4>
 *   @0x2f4668 stmibvc r11!, {r0, r1, r8, sp}
 *   @0x2f466c andls r4, r4, #272629760
 *   @0x2f4670 bl 0xff36920c <b2_toiTime+0xfffffffffec0fd68>
 *   @0x2f4674 ldrmi r0, [r1, #0x208]
 *   @0x2f4678 .word 0xf8d4d2e1
 *   @0x2f467c stmdals r2, {r5, r8, r9, sp, pc}
 *   @0x2f4680 stm sp, {r0, r4, r6, r10, lr}
 *   @0x2f4684 .word 0xf5c11008
 *   @0x2f4688 ldm sp, {r2, r3, r5, r7, r8, r9, r10, r11, sp, lr, pc}
 *   @0x2f468c stmdahs r0, {r3, r12}
 *   @0x2f4690 b 0x16e8dec <b2_toiTime+0xf8f948>
 *   @0x2f4694 .word 0xf00b4c0c
 *   @0x2f4698 b 0x15f72dc <b2_toiTime+0xe9de38>
 *   @0x2f469c .word 0xf8dd6303
 *   @0x2f46a0 b 0x13e46e8 <b2_toiTime+0xc8b244>
 *   @0x2f46a4 .word 0xf8dd030c
 *   @0x2f46a8 b 0x13e46e0 <b2_toiTime+0xc8b23c>
 *   @0x2f46ac .word 0xf1bb230c
 *   @0x2f46b0 stmle r4, {r0, r1, r8, r9, r10, r11} ^
 *   @0x2f46b4 .word 0xf00be8df
 *   @0x2f46b8 ldrne r0, [r4], -r2, lsl #4
 *   @0x2f46bc adcsle r4, lr, #281018368
 *   @0x2f46c0 andeq lr, r3, r10, lsl #22
 *   @0x2f46c4 strbmi r2, [r2], -r0, lsl #2
 *   @0x2f46c8 .word 0xf5c19300
 *   @0x2f46cc blls 0x33067c
 *   @0x2f46d0 adcsle r2, r4, r0, lsl #16
 *   @0x2f46d4 eorsvs r2, r2, r1, lsl #4
 *   @0x2f46d8 .word 0x2320f8d4
 *   @0x2f46dc and r4, r3, r3, lsl r4
 *   @0x2f46e0 and r2, r0, r2, lsl #4
 *   @0x2f46e4 eorsvs r2, r2, r3, lsl #4
 *   @0x2f46e8 andhs r6, r0, r3, ror r0
 *   @0x2f46ec andhs lr, r6, r0
 *   @0x2f46f0 pop {r0, r3, r12, sp, pc}
 *   @0x2f46f4 svclt #0x8ff0
 *   @0x2f46f8 submi r4, r4, #32, #12
 *   @0x2f46fc .word 0x460db57f
 *   @0x2f4700 ldrmi r4, [r4], -lr, lsl #18
 *   @0x2f4704 strmi r10, [r6], -r2, lsl #20
 *   @0x2f4708 .word 0xf7ff4479
 *   @0x2f470c ldmiblt r0, {r0, r2, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f4710 ldrtmi r4, [r0], -r11, lsl #18
 *   @0x2f4714 ldrbtmi r4, [r9], #-1642
 *   @0x2f4718 mcr2 p7, #0x6, pc, c14, c15, #0x7
 *   @0x2f471c blls 0x3a2c84 <af_blue_strings+0x960>
 *   @0x2f4720 .word 0xd1072b01
 *   @0x2f4724 blhs 0x35b32c
 *   @0x2f4728 blls 0x368b40 <_ZTS12CDS_Priority+0xab98>
 *   @0x2f472c blls 0x3cc7e0 <error_g0017+0x25484>
 *   @0x2f4730 and r6, r0, r3, lsr #32
 *   @0x2f4734 andlt r2, r4, r6
 *   @0x2f4738 svclt #0xbd70
 *   @0x2f473c andeq r10, r9, r6, asr r1
 *   @0x2f4740 andeq r10, r9, r9, asr r1
 *   @0x2f4744 .word 0x460db5f7
 *   @0x2f4748 .word 0xf500b12a
 *   @0x2f474c .word 0xf500744d
 *   @0x2f4750 stmdbmi r11, {r2, r4, r5, r9, r10, r12, sp, lr}
 *   @0x2f4754 stmdbmi r11, {r2, sp, lr, pc}
 *   @0x2f4758 strbvc pc, [r12], #-1280
 *   @0x2f475c ldrtvc pc, [r3], -r0, lsl #10
 *   @0x2f4760 andvc pc, r4, #208, #16
 *   @0x2f4764 blge 0x346014
 *   @0x2f4768 .word 0x460747b8
 *   @0x2f476c blls 0x362c14 <_ZTS12CDS_Priority+0x4c6c>
 *   @0x2f4770 eorsvs r4, r3, r8, lsr #12
 *   @0x2f4774 .word 0xf8e4f7f2
 *   @0x2f4778 ldrtmi r6, [r8], -r0, lsr #32
 *   @0x2f477c ldcllt p0, c11, [r0, #12]!
 *   @0x2f4780 uqsub16vc r7, sp, r8
 *   @0x2f4784 stmdavs sp!, {r3, r4, r5, r6, r10, r12, sp, lr} ^
 *   @0x2f4788 svcmi #0xf0e92d
 *   @0x2f478c strmi r11, [r4], -r7, lsl #1
 *   @0x2f4790 mcrvs p6, #0x4, r4, c6, c5, #0x0
 *   @0x2f4794 .word 0xf8d0461f
 *   @0x2f4798 .word 0xf8d09228
 *   @0x2f479c .word 0xf8d02330
 *   @0x2f47a0 .word 0xf8d4c334
 *   @0x2f47a4 .word 0xf8d0b2d0
 *   @0x2f47a8 smlabtls r0, r12, r2, r0
 *   @0x2f47ac .word 0xf504b121
 *   @0x2f47b0 uadd8mi r7, r8, r4
 *   @0x2f47b4 and r4, r1, r2, ror #12
 *   @0x2f47b8 bicseq pc, r8, #4, #2
 *   @0x2f47bc .word 0xb022f8b3
 *   @0x2f47c0 svceq #0xf1bb
 *   @0x2f47c4 ldrbmi sp, [sp, #-0x4c]
 *   @0x2f47c8 beq 0x3af3d0 <error_g0017+0x8074>
 *   @0x2f47cc bl 0x3a9048 <error_g0017+0x1cec>
 *   @0x2f47d0 stcne p1, c0, [r11, #-532]
 *   @0x2f47d4 stmdale r3, {r0, r1, r4, r6, r8, r10, lr} ^
 *   @0x2f47d8 .word 0xf7f24630
 *   @0x2f47dc andls pc, r3, r4, ror #16
 *   @0x2f47e0 teqle sp, r0, lsl #16
 *   @0x2f47e4 bleq 0x630c20 <g_SWFaavertbuff+0x5db58>
 *   @0x2f47e8 uasxmi r4, r9, r0
 *   @0x2f47ec .word 0xf98af7f2
 *   @0x2f47f0 andshi r9, r8, r0, lsl r11
 *   @0x2f47f4 blhs 0x31b408 <__divdi3+0x1e8>
 *   @0x2f47f8 shasxmi sp, r0, r2
 *   @0x2f47fc .word 0xf7f24659
 *   @0x2f4800 blls 0x3f2e0c <SVN_Lit_VertexShader+0x2b0>
 *   @0x2f4804 bllt 0x19d48ec <b2_toiTime+0x127b448>
 *   @0x2f4808 .word 0xf10be02e
 *   @0x2f480c bl 0x381010 <_ZTS13C_UTF16String+0x180bc>
 *   @0x2f4810 cpsie i
 *   @0x2f4814 ldrbmi r0, [r1, #-0x104]
 *   @0x2f4818 ldrtmi sp, [r0], -r2, lsr #16
 *   @0x2f481c .word 0xf7f24641
 *   @0x2f4820 andls pc, r3, r2, asr #16
 *   @0x2f4824 bge 0x3e2fac <error_g0017+0x3bc50>
 *   @0x2f4828 andls r4, r1, #48, #12
 *   @0x2f482c .word 0xf7f24611
 *   @0x2f4830 blls 0x732ddc <g_SWFvertbuff+0x5fd14>
 *   @0x2f4834 stmdals r3, {r3, r4, pc}
 *   @0x2f4838 .word 0xf1cbb990
 *   @0x2f483c strtmi r0, [r9], #-258
 *   @0x2f4840 .word 0x0141eb08
 *   @0x2f4844 ldrbmi r1, [r3, #-0xc8b]
 *   @0x2f4848 ldrtmi sp, [r0], -r8, lsl #16
 *   @0x2f484c .word 0xf82bf7f2
 *   @0x2f4850 stmdblt r8, {r0, r1, r12, pc} ^
 *   @0x2f4854 stmdbge r3, {r4, r5, r9, r10, lr}
 *   @0x2f4858 .word 0xf954f7f2
 *   @0x2f485c and r8, r3, r8, lsr r0
 *   @0x2f4860 movwhs r9, #0xa10
 *   @0x2f4864 andshi r8, r3, r11, lsr r0
 *   @0x2f4868 svceq #0xf1b9
 *   @0x2f486c bls 0x728904 <g_SWFvertbuff+0x5583c>
 *   @0x2f4870 movwls r8, #0x4813
 *   @0x2f4874 strhlo pc, [r0], -r7
 *   @0x2f4878 blls 0x319494 <__fixsfdi+0x2c>
 *   @0x2f487c .word 0xf8d9b14b
 *   @0x2f4880 tstlt r11, r12
 *   @0x2f4884 strtmi r4, [r9], -r0, lsr #12
 *   @0x2f4888 ldrmi r10, [r8, r4, lsl #20]
 *   @0x2f488c ldrsblo pc, [r0], -r9
 *   @0x2f4890 .word 0xf8d9e008
 *   @0x2f4894 tstlt r11, r0
 *   @0x2f4898 strtmi r4, [r9], -r0, lsr #12
 *   @0x2f489c ldrmi r10, [r8, r4, lsl #20]
 *   @0x2f48a0 .word 0x3004f8d9
 *   @0x2f48a4 qadd16mi r11, r0, r11
 *   @0x2f48a8 bge 0x446154 <g_RomDisk+0x4e934>
 *   @0x2f48ac blls 0x406714 <g_RomDisk+0xeef4>
 *   @0x2f48b0 andshi r9, r3, r0, lsl r10
 *   @0x2f48b4 eorshi r9, r11, r5, lsl #22
 *   @0x2f48b8 pop {r0, r1, r2, r12, sp, pc}
 *   @0x2f48bc ldrblt r8, [pc, #-0xff0]!
 *   @0x2f48c0 stmdbhi r5, {r10, sp}
 *   @0x2f48c4 stmdbvs r6, {r0, r1, r8, r9, r11, sp, pc}
 *   @0x2f48c8 movwls r4, #0x1622
 *   @0x2f48cc strls r4, [r0], #-1544
 *   @0x2f48d0 stmdane r11!, {r0, r8, sp} ^
 *   @0x2f48d4 blx 0xff9f28aa <b2_toiTime+0xffffffffff299406>
 *   @0x2f48d8 ldmdblt r3!, {r0, r1, r8, r9, r11, r12, pc} ^
 *   @0x2f48dc andle r4, r1, #-1342177270
 *   @0x2f48e0 ldmdblt r1, {r0, r4, r5, r6, r7, r10, r11, r12, lr}
 *   @0x2f48e4 strbpl r2, [r2], #512
 *   @0x2f48e8 .word 0xf1a1e008
 *   @0x2f48ec bhs 0x1ab5174 <b2_toiTime+0x135bcd0>
 *   @0x2f48f0 teqhs pc, r8, lsl #31
 *   @0x2f48f4 movwlo r5, #0x14c1
 *   @0x2f48f8 qsub8mi lr, r0, r0
 *   @0x2f48fc ldcllt p0, c11, [r0, #-16]!
 *   @0x2f4900 strhs r11, [r0], #-1407
 *   @0x2f4904 blge 0x3d6d24 <error_g0017+0x2f9c8>
 *   @0x2f4908 strtmi r6, [r2], -r5, lsl #18
 *   @0x2f490c strmi r9, [r8], -r1, lsl #6
 *   @0x2f4910 .word 0x21010876
 *   @0x2f4914 ldmdane r3!, {r10, r12, pc} ^
 *   @0x2f4918 blx 0xff1728ee <b2_toiTime+0xfffffffffea1944a>
 *   @0x2f491c ldmiblt r11, {r0, r1, r8, r9, r11, r12, pc}
 *   @0x2f4920 andle r4, r6, #805306379
 *   @0x2f4924 blne 0x3b2980 <error_g0017+0xb624>
 *   @0x2f4928 .word 0x2c01f815
 *   @0x2f492c qaddhs lr, r2, r1
 *   @0x2f4930 andhs sp, r0, #-2147483648
 *   @0x2f4934 and r5, r8, r2, asr #9
 *   @0x2f4938 eoreq pc, r0, #1073741864
 *   @0x2f493c svclt #0x882a5f
 *   @0x2f4940 strbpl r2, [r1], #319
 *   @0x2f4944 strb r3, [r11, r1, lsl #6]!
 *   @0x2f4948 andlt r4, r4, r0, lsr #12
 *   @0x2f494c ldrlt r11, [r0, #-0xd70]!
 *   @0x2f4950 stmibvs r3, {r0, r2, r3, r9, r10, lr} ^
 *   @0x2f4954 smlabbhs r0, r5, r0, r11
 *   @0x2f4958 addsmi r4, sp, #4, #12
 *   @0x2f495c stmdble lr, {r0, r1, r8, r12, pc}
 *   @0x2f4960 subvs r6, r2, #4096
 *   @0x2f4964 sadd16mi r4, r10, r0
 *   @0x2f4968 .word 0x9100462b
 *   @0x2f496c mrsls r10, apsr
 *   @0x2f4970 .word 0xf7f32104
 *   @0x2f4974 eorvs pc, r0, #140, #22
 *   @0x2f4978 stmdblt r8, {r0, r1, r11, r12, pc}
 *   @0x2f497c stmdals r3, {r0, r2, r5, r6, r7, r8, sp, lr}
 *   @0x2f4980 ldclt p0, c11, [r0, #-20]!
 *   @0x2f4984 .word 0x4605b5f8
 *   @0x2f4988 strmi r4, [r12], -r8, lsl #12
 *   @0x2f498c .word 0xf7ff4617
 *   @0x2f4990 stmdavc r3!, {r0, r1, r3, r4, r5, r7, r9, r11, r12, sp, lr, pc} ^
 *   @0x2f4994 stmdavc r2!, {r1, r2, r5, r8, r10, r11, r12}
 *   @0x2f4998 b 0x13b5a0c <b2_toiTime+0xc5c568>
 *   @0x2f499c stmvc r2!, {r1, r8, r9, sp, lr} ^
 *   @0x2f49a0 tstmi r3, #164, #16
 *   @0x2f49a4 b 0x13c6294 <b2_toiTime+0xc6cdf0>
 *   @0x2f49a8 mcrrne p4, #0x0, r2, r1, c4
 *   @0x2f49ac .word 0xf7ff4628
 *   @0x2f49b0 ldmiblt r0, {r1, r2, r3, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f49b4 ldrtmi r6, [r3], -r9, lsr #20
 *   @0x2f49b8 ldmdavc r10, {r2, r5, r7, r8, r12, sp, pc} ^
 *   @0x2f49bc ldmvc lr, {r3, r4, r11, r12, sp, lr}
 *   @0x2f49c0 b 0x1375210 <b2_toiTime+0xc1bd6c>
 *   @0x2f49c4 ldmvc r8, {r9, lr} ^
 *   @0x2f49c8 .word 0x460e4332
 *   @0x2f49cc stmne r7, {r0, r12, sp}
 *   @0x2f49d0 blhs 0x432af0 <g_RomDisk+0x3b2d0>
 *   @0x2f49d4 addsmi r3, r7, #268435456
 *   @0x2f49d8 bl 0x3691c8 <_ZTS13C_UTF16String+0x274>
 *   @0x2f49dc .word 0x3c010180
 *   @0x2f49e0 strb r3, [r9, r4, lsl #6]!
 *   @0x2f49e4 bvs 0xd0ca1c <b2_toiTime+0x5b3578>
 *   @0x2f49e8 strdhs r11, r12, [r0], -r8
 *   @0x2f49ec ldrblt r11, [r0, #-0xdf8]!
 *   @0x2f49f0 stmdavc sp, {r2, r3, r8, r10, r11, r12} ^
 *   @0x2f49f4 stmdavc r11, {r1, r2, r9, r10, lr}
 *   @0x2f49f8 b 0x1435ab4 <b2_toiTime+0xcdc610>
 *   @0x2f49fc stmvc r11, {r0, r1, r8, r10, sp, lr} ^
 *   @0x2f4a00 stmvc r11, {r0, r2, r3, r4, r8, r9, lr}
 *   @0x2f4a04 strhs lr, [r3, #-0xa45]
 *   @0x2f4a08 .word 0xf7ff1c69
 *   @0x2f4a0c ldmiblt r0!, {r5, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f4a10 .word 0x46036a32
 *   @0x2f4a14 andle r4, sp, r11, lsr #5
 *   @0x2f4a18 strlo r7, [r5], #-2145
 *   @0x2f4a1c .word 0x0c05f814
 *   @0x2f4a20 b 0x133524c <b2_toiTime+0xbdbda8>
 *   @0x2f4a24 .word 0xf8144100
 *   @0x2f4a28 movwmi r0, #0x1c03
 *   @0x2f4a2c eorne pc, r3, r2, asr #16
 *   @0x2f4a30 strb r3, [pc, r1, lsl #6]!
 *   @0x2f4a34 ldrmi r2, [r0], -r0, lsl #2
 *   @0x2f4a38 eorne pc, r3, r2, asr #16
 *   @0x2f4a3c andhs r11, r0, r0, ror sp
 *   @0x2f4a40 push {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2f4a44 .word 0x46044ff0
 *   @0x2f4a48 ldrsbhi pc, [r0], -r0
 *   @0x2f4a4c strmi r11, [r9], r7, lsl #1
 *   @0x2f4a50 .word 0xf1084611
 *   @0x2f4a54 .word 0xf7ff0006
 *   @0x2f4a58 strmi pc, [r3], -r5, asr #19
 *   @0x2f4a5c andhs r11, r0, r8, lsl #18
 *   @0x2f4a60 .word 0xf890e10d
 *   @0x2f4a64 stmdavc r2, {r0, sp, pc}
 *   @0x2f4a68 b 0x16d2fd4 <b2_toiTime+0xf79b30>
 *   @0x2f4a6c b 0x158729c <b2_toiTime+0xe2ddf8>
 *   @0x2f4a70 stmvc r2, {r1, r9, r11, sp, lr} ^
 *   @0x2f4a74 b 0x1575aa0 <b2_toiTime+0xe1c5fc>
 *   @0x2f4a78 stmvc r2, {r1, r9, r11}
 *   @0x2f4a7c b 0x1992e84 <b2_toiTime+0x12399e0>
 *   @0x2f4a80 b 0x133f290 <b2_toiTime+0xbe5dec>
 *   @0x2f4a84 ldmibvc r8, {r8, sp, lr} ^
 *   @0x2f4a88 b 0x13530fc <b2_toiTime+0xbf9c58>
 *   @0x2f4a8c b 0x1334e94 <b2_toiTime+0xbdb9f0>
 *   @0x2f4a90 .word 0xd1042103
 *   @0x2f4a94 rscle r2, r2, r0, lsl #18
 *   @0x2f4a98 strbmi r4, [r1], #-1568
 *   @0x2f4a9c bl 0x52cb48 <SrcVerts+0x89b8c>
 *   @0x2f4aa0 bicslt r0, r9, r10, lsl #10
 *   @0x2f4aa4 streq lr, [r1], -r8, lsl #22
 *   @0x2f4aa8 andlo pc, r1, r8, lsl r8
 *   @0x2f4aac ldmdavc r7!, {r3, r5, r9, r10, lr} ^
 *   @0x2f4ab0 b 0x14b5bb4 <b2_toiTime+0xd5c710>
 *   @0x2f4ab4 ldmvc r3!, {r0, r1, r8, r9, r10, sp, lr} ^
 *   @0x2f4ab8 ldmvc r3!, {r0, r1, r2, r3, r4, r8, r9, lr}
 *   @0x2f4abc movwhs lr, #0x3a47
 *   @0x2f4ac0 .word 0xf7ff9301
 *   @0x2f4ac4 svcls #0x1fa21
 *   @0x2f4ac8 andge pc, r10, r8, lsl r8
 *   @0x2f4acc mulgt r1, r5, r8
 *   @0x2f4ad0 mulhi r2, r5, r8
 *   @0x2f4ad4 mullt r3, r5, r8
 *   @0x2f4ad8 ldmdblt pc!, {r0, r1, r9, r10, lr}
 *   @0x2f4adc strtmi r4, [r9], -r0, lsr #12
 *   @0x2f4ae0 andlt r4, r7, r10, asr #12
 *   @0x2f4ae4 svcmi #0xf0e8bd
 *   @0x2f4ae8 svclt #0x4cf7ff
 *   @0x2f4aec qasxmi r11, r0, r8
 *   @0x2f4af0 .word 0x464a4631
 *   @0x2f4af4 pop {r0, r1, r2, r12, sp, pc}
 *   @0x2f4af8 .word 0xf7ff4ff0
 *   @0x2f4afc svcls #0x1bf78
 *   @0x2f4b00 strbmi r4, [r10], -r0, lsr #12
 *   @0x2f4b04 andgt pc, r12, sp, asr #17
 *   @0x2f4b08 ldrmi r1, [r9], #-3193
 *   @0x2f4b0c .word 0xff1ff7ff
 *   @0x2f4b10 .word 0xc00cf8dd
 *   @0x2f4b14 stmdahs r0, {r0, r1, r9, r10, lr}
 *   @0x2f4b18 b 0x16e91a4 <b2_toiTime+0xf8fd00>
 *   @0x2f4b1c stmdbvc r9!, {r2, r3, r10, r11, lr}
 *   @0x2f4b20 bvs 0x5af458 <g_SWFlineaavertbuff+0x5c390>
 *   @0x2f4b24 mulgt r5, r5, r8
 *   @0x2f4b28 b 0x15930f0 <b2_toiTime+0xe39c4c>
 *   @0x2f4b2c b 0x1577360 <b2_toiTime+0xe1debc>
 *   @0x2f4b30 bvs 0xb7f358 <b2_toiTime+0x425eb4>
 *   @0x2f4b34 .word 0x2c0cea4f
 *   @0x2f4b38 streq pc, [r8], #-261
 *   @0x2f4b3c .word 0x4c01ea4c
 *   @0x2f4b40 andeq r7, r0, #2768896
 *   @0x2f4b44 mulls r7, r5, r8
 *   @0x2f4b48 .word 0x0c01ea4c
 *   @0x2f4b4c b 0x1313018 <b2_toiTime+0xbb9b74>
 *   @0x2f4b50 ldmibvc r1!, {r0, lr}
 *   @0x2f4b54 .word 0x91024301
 *   @0x2f4b58 mrseq pc, apsr
 *   @0x2f4b5c ldrtmi r2, [r5], -r1, lsl #12
 *   @0x2f4b60 bl 0x55ab70 <g_SWFlineaavertbuff+0x7aa8>
 *   @0x2f4b64 strbmi r0, [r0, #-0x80c]
 *   @0x2f4b68 ldrmi sp, [r11], r4, lsr #18
 *   @0x2f4b6c stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f4b70 streq lr, [r3, r2, lsl #22]
 *   @0x2f4b74 svcls #0x59705
 *   @0x2f4b78 andeq lr, r12, r8, lsl #22
 *   @0x2f4b7c .word 0xf8473301
 *   @0x2f4b80 .word 0xf1080028
 *   @0x2f4b84 strbmi r0, [r8, #0x801]
 *   @0x2f4b88 ldrmi sp, [r11], r1, lsl #16
 *   @0x2f4b8c strlo lr, [r1, #-0x7f3]
 *   @0x2f4b90 ldmdale r3, {r0, r2, r4, r6, r8, r10, lr} ^
 *   @0x2f4b94 mulgt r1, r4, r8
 *   @0x2f4b98 .word 0xf8143404
 *   @0x2f4b9c .word 0xf8148c04
 *   @0x2f4ba0 b 0x16dbbac <b2_toiTime+0xf82708>
 *   @0x2f4ba4 b 0x15ffbdc <b2_toiTime+0xea6738>
 *   @0x2f4ba8 .word 0xf8144c08
 *   @0x2f4bac b 0x1617bbc <b2_toiTime+0xebe718>
 *   @0x2f4bb0 ldrb r0, [r5, r8, lsl #24]
 *   @0x2f4bb4 strlo r9, [r1], -r2, lsl #16
 *   @0x2f4bb8 strbmi r9, [r0, #-0xf01]!
 *   @0x2f4bbc .word 0xf842bf3c
 *   @0x2f4bc0 movwlo r0, #0x1023
 *   @0x2f4bc4 stmdale r12, {r1, r2, r3, r4, r5, r7, r9, lr}
 *   @0x2f4bc8 .word 0x31057848
 *   @0x2f4bcc .word 0x8c05f811
 *   @0x2f4bd0 b 0x12f53d8 <b2_toiTime+0xb9bf34>
 *   @0x2f4bd4 .word 0xf8114008
 *   @0x2f4bd8 b 0x1317bec <b2_toiTime+0xbbe748>
 *   @0x2f4bdc andls r0, r2, r8
 *   @0x2f4be0 ldrbmi lr, [r5, #-0x7be]
 *   @0x2f4be4 .word 0x2100d904
 *   @0x2f4be8 .word 0xf8424610
 *   @0x2f4bec sub r1, r6, r3, lsr #32
 *   @0x2f4bf0 addeq lr, r3, r2, lsl #22
 *   @0x2f4bf4 bl 0x33cffc
 *   @0x2f4bf8 .word 0xf840060c
 *   @0x2f4bfc .word 0x31016021
 *   @0x2f4c00 strbmi r3, [r9, #-0x301]
 *   @0x2f4c04 ldrbmi sp, [r5, #-0x9f7]
 *   @0x2f4c08 .word 0xf894d0ed
 *   @0x2f4c0c bl 0x3a4c18 <af_blue_strings+0x28f4>
 *   @0x2f4c10 stmdavc r1!, {r0, r1, r7, r9, r10}
 *   @0x2f4c14 b 0x16d2f9c <b2_toiTime+0xf79af8>
 *   @0x2f4c18 b 0x15ffc50 <b2_toiTime+0xea67ac>
 *   @0x2f4c1c stmvc r1!, {r0, r10, r11, lr}
 *   @0x2f4c20 .word 0x0c01ea4c
 *   @0x2f4c24 bl 0x33d02c
 *   @0x2f4c28 .word 0xf846070c
 *   @0x2f4c2c .word 0x31017021
 *   @0x2f4c30 addmi r3, r1, #67108864
 *   @0x2f4c34 strlo sp, [r1, #-0x9f7]
 *   @0x2f4c38 strb r3, [r4, r4, lsl #8]!
 *   @0x2f4c3c adcsmi r9, lr, #1, #30
 *   @0x2f4c40 stmdals r2, {r0, r4, r6, r7, r11, r12, lr, pc}
 *   @0x2f4c44 streq pc, [r2], #-267
 *   @0x2f4c48 eoreq pc, r3, r2, asr #16
 *   @0x2f4c4c addeq lr, r11, r2, lsl #22
 *   @0x2f4c50 blne 0xfea9b85c <b2_toiTime+0xfffffffffe3423b8>
 *   @0x2f4c54 adcsmi r2, r3, #0, #6
 *   @0x2f4c58 stmdavc pc, {r0, r1, r2, r3, r12, lr, pc} ^
 *   @0x2f4c5c streq lr, [r3, #0xb00]
 *   @0x2f4c60 mulgt r0, r1, r8
 *   @0x2f4c64 .word 0x31053301
 *   @0x2f4c68 b 0x14b556c <b2_toiTime+0xd5c0c8>
 *   @0x2f4c6c .word 0xf811470c
 *   @0x2f4c70 b 0x14e7c84 <b2_toiTime+0xd8e7e0>
 *   @0x2f4c74 adcvs r0, pc, r12, lsl #14
 *   @0x2f4c78 strtmi lr, [r3], #-2029
 *   @0x2f4c7c strhlt lr, [r7], -r3
 *   @0x2f4c80 svchi #0xf0e8bd
 *   @0x2f4c84 svcmi #0xf7e92d
 *   @0x2f4c88 stmibvs r6, {r0, r1, r3, r9, r10, lr}
 *   @0x2f4c8c stmdbvs r4, {r4, r7, r9, r10, lr}
 *   @0x2f4c90 ldclne p6, c4, [r1], #-104
 *   @0x2f4c94 strlo r4, [r10], #-1541
 *   @0x2f4c98 mrc2 p7, #0x2, apsr_nzcv, c9, c15, #0x7
 *   @0x2f4c9c teqle r12, r0, lsl #16
 *   @0x2f4ca0 vmlahs.f32 s12, s0, s31
 *   @0x2f4ca4 stmdbvc r2!, {r1, r2, r4, r5, r12, lr, pc}
 *   @0x2f4ca8 stmibvc r1!, {r0, r1, r5, r6, r7, r11, r12, sp, lr} ^
 *   @0x2f4cac stmdbvc r0!, {r1, r4, r10} ^
 *   @0x2f4cb0 andvs lr, r3, #270336
 *   @0x2f4cb4 .word 0xf89479a3
 *   @0x2f4cb8 tstmi r10, #0
 *   @0x2f4cbc .word 0xf8947a23
 *   @0x2f4cc0 b 0x17a0ccc <b2_toiTime+0x1047828>
 *   @0x2f4cc4 .word 0xf8942000
 *   @0x2f4cc8 b 0x16d8cd8 <b2_toiTime+0xf7f834>
 *   @0x2f4ccc b 0x13c58e0 <b2_toiTime+0xc6c43c>
 *   @0x2f4cd0 bvc 0xfeb4d8dc <b2_toiTime+0xfffffffffe3f4438>
 *   @0x2f4cd4 movweq lr, #0x1a43
 *   @0x2f4cd8 b 0x13d3664 <b2_toiTime+0xc7a1c0>
 *   @0x2f4cdc andle r2, r7, r1, lsl #6
 *   @0x2f4ce0 movwls r6, #0x1929
 *   @0x2f4ce4 strbmi r4, [r1], -r8, lsl #8
 *   @0x2f4ce8 .word 0xf81ef7ff
 *   @0x2f4cec ldmdblt r0!, {r0, r8, r9, r11, r12, pc}
 *   @0x2f4cf0 stmdbvs r8!, {r0, r1, r3, r5, r6, r8, r12, sp, pc}
 *   @0x2f4cf4 ldrmi r4, [r8], #-1601
 *   @0x2f4cf8 .word 0xf843f7ff
 *   @0x2f4cfc b 0x16e11e4 <b2_toiTime+0xf87d40>
 *   @0x2f4d00 b 0x15bf934 <b2_toiTime+0xe66490>
 *   @0x2f4d04 b 0x1587534 <b2_toiTime+0xe2e090>
 *   @0x2f4d08 .word 0xf8470309
 *   @0x2f4d0c vmlalo.f64 d3, d1, d4
 *   @0x2f4d10 strb r3, [r6, r11, lsl #8]
 *   @0x2f4d14 bvs 0xd0ce14 <b2_toiTime+0x5b3970>
 *   @0x2f4d18 andhs lr, r0, r0
 *   @0x2f4d1c pop {r0, r1, r12, sp, pc}
 *   @0x2f4d20 ldrblt r8, [r0, #-0xff0]!
 *   @0x2f4d24 stmibvs r6, {r1, r3, r9, r10, lr}
 *   @0x2f4d28 stmdbvs r4, {r0, r2, r9, r10, lr}
 *   @0x2f4d2c strlo r1, [r10], #-3185
 *   @0x2f4d30 mcr2 p7, #0x0, pc, c13, c15, #0x7
 *   @0x2f4d34 bvs 0xda33fc <b2_toiTime+0x649f58>
 *   @0x2f4d38 adcsmi r4, r3, #3145728
 *   @0x2f4d3c stmdavc r1!, {r0, r2, r3, r12, lr, pc} ^
 *   @0x2f4d40 .word 0xf814340b
 *   @0x2f4d44 andeq r0, r9, #2816
 *   @0x2f4d48 .word 0x4100ea41
 *   @0x2f4d4c .word 0x0c09f814
 *   @0x2f4d50 .word 0xf8424301
 *   @0x2f4d54 movwlo r1, #0x1023
 *   @0x2f4d58 smlatths r0, pc, r7, lr
 *   @0x2f4d5c .word 0xf8424610
 *   @0x2f4d60 ldcllt p0, c1, [r0, #-140]!
 *   @0x2f4d64 ldcllt p0, c2, [r0, #-0]!
 *   @0x2f4d68 mvnsmi lr, sp, lsr #18
 *   @0x2f4d6c .word 0xf8d1460c
 *   @0x2f4d70 qadd16mi r8, r2, r12
 *   @0x2f4d74 andvs pc, r4, #208, #16
 *   @0x2f4d78 stmdbmi r9!, {r8, r9, sp}
 *   @0x2f4d7c ldrmi r4, [r0, r5, lsl #12]!
 *   @0x2f4d80 stmdahs r0, {r0, r1, r12, pc}
 *   @0x2f4d84 strtmi sp, [r0], -r7, asr #2
 *   @0x2f4d88 .word 0xf7f32104
 *   @0x2f4d8c strmi pc, [r6], -r10, asr #16
 *   @0x2f4d90 stmdahs r0, {r0, r1, r12, pc}
 *   @0x2f4d94 qasxmi sp, r0, pc
 *   @0x2f4d98 mcr2 p7, #0x1, pc, c11, c1, #0x7
 *   @0x2f4d9c eoreq pc, r12, #10813440
 *   @0x2f4da0 .word 0xf7f14620
 *   @0x2f4da4 .word 0xf8a5fe26
 *   @0x2f4da8 strtmi r0, [r0], -lr, lsr #4
 *   @0x2f4dac .word 0xf884f7f3
 *   @0x2f4db0 eorlo pc, r12, #11862016
 *   @0x2f4db4 stmdble r4, {r0, r8, r9, r11, sp}
 *   @0x2f4db8 .word 0xf8a52308
 *   @0x2f4dbc movwls r6, #0x322e
 *   @0x2f4dc0 rfeia r5!
 *   @0x2f4dc4 blge 0x3d1684 <error_g0017+0x2a328>
 *   @0x2f4dc8 strbmi r9, [r0], -r0, lsl #12
 *   @0x2f4dcc .word 0x21049301
 *   @0x2f4dd0 shasxmi r4, r2, r11
 *   @0x2f4dd4 .word 0xf95bf7f3
 *   @0x2f4dd8 .word 0xf8c59b03
 *   @0x2f4ddc ldmiblt r3, {r4, r5, r9} ^
 *   @0x2f4de0 adcseq r4, r9, r0, lsr #12
 *   @0x2f4de4 .word 0xf81df7f3
 *   @0x2f4de8 stmiblt r0!, {r0, r1, r12, pc}
 *   @0x2f4dec eorspl pc, r0, #13959168
 *   @0x2f4df0 adcsmi r4, lr, #6291456
 *   @0x2f4df4 streq pc, [r4, #-0x105]
 *   @0x2f4df8 andle r4, r10, #32, #12
 *   @0x2f4dfc ldc2l p7, c15, [r9, #964]!
 *   @0x2f4e00 .word 0xf8253601
 *   @0x2f4e04 strtmi r0, [r0], -r4, lsl #24
 *   @0x2f4e08 ldc2l p7, c15, [r3, #964]!
 *   @0x2f4e0c .word 0x0c02f825
 *   @0x2f4e10 .word 0xf7f3e7ef
 *   @0x2f4e14 stmdals r3, {r0, r4, r6, r11, r12, sp, lr, pc}
 *   @0x2f4e18 pop {r2, r12, sp, pc}
 *   @0x2f4e1c svclt #0x81f0
 *   @0x2f4e20 .word 0x67617370
 *   @0x2f4e24 svcmi #0xf0e92d
 *   @0x2f4e28 .word 0xf8d0b089
 *   @0x2f4e2c .word 0xf04f6164
 *   @0x2f4e30 .word 0xf8d035ff
 *   @0x2f4e34 strtmi r8, [pc], -r4, rrx
 *   @0x2f4e38 ldrhge pc, [r4, #-128]
 *   @0x2f4e3c tsteq r4, #-2147483647
 *   @0x2f4e40 andhs r9, r0, #1342177280
 *   @0x2f4e44 ldrmi r9, [r1], r4, lsl #2
 *   @0x2f4e48 strtmi r4, [r12], -r9, lsr #12
 *   @0x2f4e4c blx 0xad9670 <b2_toiTime+0x3801cc>
 *   @0x2f4e50 ldrbmi pc, [r4, #0xc82]
 *   @0x2f4e54 rfeda r3!
 *   @0x2f4e58 .word 0xf8ddcc0e
 *   @0x2f4e5c ldrbmi r11, [r12, #0x10]
 *   @0x2f4e60 rfeda r3!
 *   @0x2f4e64 .word 0xf1bccc0c
 *   @0x2f4e68 eorsle r0, pc, r0, lsl #30
 *   @0x2f4e6c .word 0xcc14f833
 *   @0x2f4e70 andgt pc, r12, sp, asr #17
 *   @0x2f4e74 svceq #0x3f1bc
 *   @0x2f4e78 ldm pc, {r3, r4, r5, r11, r12, lr, pc} ^
 *   @0x2f4e7c streq pc, [r2], #-12
 *   @0x2f4e80 ldrmi r1, [r5], -r2, lsl #4
 *   @0x2f4e84 rfeda r3!
 *   @0x2f4e88 .word 0xf1bccc10
 *   @0x2f4e8c .word 0xd1010f00
 *   @0x2f4e90 eor r4, r11, r1, lsl r6
 *   @0x2f4e94 .word 0xcc12f833
 *   @0x2f4e98 svceq #0xf1bc
 *   @0x2f4e9c ldrmi r11, [r4], -r8, lsl #30
 *   @0x2f4ea0 .word 0xf1b7e024
 *   @0x2f4ea4 strdle r3, r4, [r6], -pc
 *   @0x2f4ea8 .word 0xcc10f833
 *   @0x2f4eac .word 0x0c09f3cc
 *   @0x2f4eb0 svceq #0x9f1bc
 *   @0x2f4eb4 rfeda r3!
 *   @0x2f4eb8 .word 0xf1bbbc12
 *   @0x2f4ebc ldmdale r5, {r1, r3, r8, r9, r10, r11}
 *   @0x2f4ec0 .word 0x0c01f04f
 *   @0x2f4ec4 blx 0x5f36fe <g_SWFaavertbuff+0x20636>
 *   @0x2f4ec8 .word 0x4c03f240
 *   @0x2f4ecc .word 0x0c0cea0b
 *   @0x2f4ed0 svceq #0xf1bc
 *   @0x2f4ed4 rfeda r3!
 *   @0x2f4ed8 .word 0xf3c99c10
 *   @0x2f4edc .word 0xf1b90909
 *   @0x2f4ee0 .word 0xf1d70709
 *   @0x2f4ee4 bl 0x19372ec <b2_toiTime+0x11dde48>
 *   @0x2f4ee8 ldrmi r0, [r7], -r7, lsl #18
 *   @0x2f4eec tstlo r4, #268435456
 *   @0x2f4ef0 mcrrne p7, #0xa, lr, r10, c13
 *   @0x2f4ef4 tsteq r4, #79
 *   @0x2f4ef8 bvs 0x5b3b0c <g_SWFlineaavertbuff+0x60a44>
 *   @0x2f4efc ldclne p1, c13, [r10], #-8
 *   @0x2f4f00 ands sp, r2, r3, lsl #2
 *   @0x2f4f04 .word 0x460c1c7b
 *   @0x2f4f08 stclne p0, c13, [r5], #-68
 *   @0x2f4f0c .word 0xf1b9d002
 *   @0x2f4f10 andle r0, r12, r0, lsl #30
 *   @0x2f4f14 beq 0x831058 <b2_toiTime+0xd7bb4>
 *   @0x2f4f18 bvs 0x4f3b48 <SrcVerts+0x50b8c>
 *   @0x2f4f1c strhlo pc, [r2], -r10
 *   @0x2f4f20 ldmdble r4, {r0, r8, r9, r11, sp} ^
 *   @0x2f4f24 subsle r2, r2, r10, lsl #22
 *   @0x2f4f28 stclne p0, c14, [r1], #-296
 *   @0x2f4f2c .word 0xf04fd006
 *   @0x2f4f30 blx 0x57778a <g_SWFlineaavertbuff+0x246c2>
 *   @0x2f4f34 .word 0x4c276a04
 *   @0x2f4f38 and r4, r7, r12, ror r4
 *   @0x2f4f3c andle r1, r4, r10, ror #24
 *   @0x2f4f40 blx 0x3c7fde <error_g0017+0x20c82>
 *   @0x2f4f44 ldrbtmi r6, [r12], #-2565
 *   @0x2f4f48 strhs lr, [r0], #-0
 *   @0x2f4f4c svceq #0xf1ba
 *   @0x2f4f50 .word 0x2c00d034
 *   @0x2f4f54 .word 0xf8dad034
 *   @0x2f4f58 bllt 0x197cfa0 <b2_toiTime+0x1223afc>
 *   @0x2f4f5c ldrsbpl pc, [r0, #-128]!
 *   @0x2f4f60 rfeia r10!
 *   @0x2f4f64 strbmi r3, [r0], -r8
 *   @0x2f4f68 mrshs r9, apsr
 *   @0x2f4f6c .word 0xf7f39200
 *   @0x2f4f70 blls 0x4f31b0 <SrcVerts+0x501f4>
 *   @0x2f4f74 andseq pc, r0, r10, asr #17
 *   @0x2f4f78 .word 0x4640b153
 *   @0x2f4f7c ldrsbne pc, [r0], -r10
 *   @0x2f4f80 .word 0xf9d9f7f2
 *   @0x2f4f84 .word 0xf8ca2000
 *   @0x2f4f88 .word 0xf8aa0010
 *   @0x2f4f8c ands r0, r8, r8
 *   @0x2f4f90 .word 0xf8da4628
 *   @0x2f4f94 .word 0xf7f1100c
 *   @0x2f4f98 andls pc, r7, r6, lsl #25
 *   @0x2f4f9c mvnle r2, r0, lsl #16
 *   @0x2f4fa0 .word 0xf8da4628
 *   @0x2f4fa4 rfeia r10!
 *   @0x2f4fa8 .word 0xf7f12008
 *   @0x2f4fac .word 0x9007fcf0
 *   @0x2f4fb0 mvnle r2, r0, lsl #16
 *   @0x2f4fb4 .word 0x46414650
 *   @0x2f4fb8 and r4, r2, r0, lsr #15
 *   @0x2f4fbc and r4, r0, r0, asr r6
 *   @0x2f4fc0 blls 0x43cfc8 <g_RomDisk+0x457a8>
 *   @0x2f4fc4 stmdals r7, {r3, r4, sp, lr}
 *   @0x2f4fc8 pop {r0, r3, r12, sp, pc}
 *   @0x2f4fcc .word 0x4c038ff0
 *   @0x2f4fd0 .word 0xe7c0447c
 *   @0x2f4fd4 .word 0xfffff983
 *   @0x2f4fd8 .word 0xfffff9b7
 *   @0x2f4fdc .word 0xfffff92d
 *   @0x2f4fe0 .word 0x4604b5f8
 *   @0x2f4fe4 rsbslo pc, r4, #144, #16
 *   @0x2f4fe8 biclt r6, r11, #1120
 *   @0x2f4fec ldrsblo pc, [r12, #128]
 *   @0x2f4ff0 svclo #0xf5b3
 *   @0x2f4ff4 strhs sp, [r0, #-0x127]
 *   @0x2f4ff8 .word 0xf8d44630
 *   @0x2f4ffc qsub16mi r1, pc, r12
 *   @0x2f5000 .word 0xf999f7f2
 *   @0x2f5004 rsbspl pc, r12, #196, #16
 *   @0x2f5008 rsbspl pc, r8, #164, #16
 *   @0x2f500c rsbslo pc, r10, #180, #16
 *   @0x2f5010 stmdble sp, {r0, r1, r3, r5, r7, r9, lr}
 *   @0x2f5014 addlo pc, r0, #212, #16
 *   @0x2f5018 .word 0xf8534630
 *   @0x2f501c .word 0xf7f21025
 *   @0x2f5020 .word 0xf8d4f98a
 *   @0x2f5024 .word 0xf8433280
 *   @0x2f5028 strlo r7, [r1, #-0x25]
 *   @0x2f502c strb r11, [sp, sp, lsr #5]!
 *   @0x2f5030 .word 0xf8d44630
 *   @0x2f5034 .word 0xf7f21280
 *   @0x2f5038 movwhs pc, #0x97e
 *   @0x2f503c addlo pc, r0, #196, #16
 *   @0x2f5040 rsbslo pc, r10, #164, #16
 *   @0x2f5044 .word 0xf5b3e00c
 *   @0x2f5048 .word 0xd1093f20
 *   @0x2f504c .word 0xf8d44630
 *   @0x2f5050 .word 0xf7f2127c
 *   @0x2f5054 movwhs pc, #0x970
 *   @0x2f5058 rsbslo pc, r12, #196, #16
 *   @0x2f505c rsbslo pc, r8, #164, #16
 *   @0x2f5060 .word 0xf8842300
 *   @0x2f5064 ldcllt p2, c3, [r8, #464]!
 *   @0x2f5068 mvnsmi lr, sp, lsr #18
 *   @0x2f506c cdpvs p6, #0x0, c4, c3, c4, #0x0
 *   @0x2f5070 .word 0x5164f8d0
 *   @0x2f5074 .word 0xb1bd689e
 *   @0x2f5078 ldrsblo pc, [r12, #-128]
 *   @0x2f507c ldmdaeq r4, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f5080 blx 0x4fec8a <SrcVerts+0x5bcce>
 *   @0x2f5084 strbmi r5, [r5, #-0x803]
 *   @0x2f5088 andle r4, r6, #48, #12
 *   @0x2f508c ldrlo r6, [r4, #-0x929]
 *   @0x2f5090 .word 0xf951f7f2
 *   @0x2f5094 .word 0x7c04f845
 *   @0x2f5098 .word 0xf8d4e7f5
 *   @0x2f509c .word 0xf7f21164
 *   @0x2f50a0 movwhs pc, #0x94a
 *   @0x2f50a4 smulbtlo r4, r4, r8
 *   @0x2f50a8 .word 0x516cf8d4
 *   @0x2f50ac .word 0xf8d4b1bd
 *   @0x2f50b0 .word 0xf04f3168
 *   @0x2f50b4 strhs r0, [r0, -r12, lsl #16]
 *   @0x2f50b8 stmdapl r3, {r3, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f50bc ldrtmi r4, [r0], -r5, asr #10
 *   @0x2f50c0 stmvs r9!, {r1, r2, r9, r12, lr, pc}
 *   @0x2f50c4 .word 0xf7f2350c
 *   @0x2f50c8 .word 0xf845f936
 *   @0x2f50cc ldrb r7, [r5, r4, lsl #24]!
 *   @0x2f50d0 .word 0x116cf8d4
 *   @0x2f50d4 .word 0xf92ff7f2
 *   @0x2f50d8 .word 0xf8c42300
 *   @0x2f50dc movwhs r3, #0x16c
 *   @0x2f50e0 cmplo r12, r4, asr #17
 *   @0x2f50e4 smulbtlo r8, r4, r8
 *   @0x2f50e8 cmplo r8, r4, lsr #17
 *   @0x2f50ec smulbtlo r0, r4, r8
 *   @0x2f50f0 ldrhhi lr, [r0, #141]!
 *   @0x2f50f4 .word 0x4604b5f8
 *   @0x2f50f8 .word 0xf0002800
 *   @0x2f50fc .word 0xf8d08091
 *   @0x2f5100 mcrvs p2, #0x2, r7, c6, c12, #0x0
 *   @0x2f5104 ldcvs p1, c11, [r11, #-220]!
 *   @0x2f5108 ldrmi r11, [r8, r3, lsl #2]
 *   @0x2f510c .word 0xb10b6e7b
 *   @0x2f5110 ldrmi r4, [r8, r0, lsr #12]
 *   @0x2f5114 msrlo APSR_nzcvqg, #148, #16
 *   @0x2f5118 .word 0xf8d4b173
 *   @0x2f511c mcrvs p3, #0x5, r3, c0, c8, #0x0
 *   @0x2f5120 .word 0xf504b11b
 *   @0x2f5124 .word 0xf7f27146
 *   @0x2f5128 movwhs pc, #0xe70
 *   @0x2f512c tstlo r12, #196, #16
 *   @0x2f5130 .word 0x3320f8c4
 *   @0x2f5134 msrlo APSR_g, #196, #16
 *   @0x2f5138 .word 0xf5046ea0
 *   @0x2f513c strhs r7, [r0, #-0x141]
 *   @0x2f5140 mcr2 p7, #0x3, pc, c3, c2, #0x7
 *   @0x2f5144 .word 0xf8d44630
 *   @0x2f5148 .word 0xf8c41090
 *   @0x2f514c .word 0xf8c45308
 *   @0x2f5150 .word 0xf8c4530c
 *   @0x2f5154 .word 0xf8c45310
 *   @0x2f5158 .word 0xf7f25314
 *   @0x2f515c ldrtmi pc, [r0], -r12, ror #17
 *   @0x2f5160 ldrsbne pc, [r12], r4
 *   @0x2f5164 addspl pc, r0, r4, asr #17
 *   @0x2f5168 addpl pc, r12, r4, asr #17
 *   @0x2f516c .word 0xf8e3f7f2
 *   @0x2f5170 addspl pc, r12, r4, asr #17
 *   @0x2f5174 addspl pc, r8, r4, lsr #17
 *   @0x2f5178 mvnsvc pc, r4, lsl #10
 *   @0x2f517c .word 0xf7f26ea0
 *   @0x2f5180 .word 0xf894fe44
 *   @0x2f5184 .word 0xf8c43124
 *   @0x2f5188 .word 0xf8c45200
 *   @0x2f518c .word 0xf8c452cc
 *   @0x2f5190 ldrsblt r5, [r11, #-32]!
 *   @0x2f5194 .word 0xf8d44630
 *   @0x2f5198 .word 0xf7f2114c
 *   @0x2f519c .word 0xf8c4f8cc
 *   @0x2f51a0 ldrtmi r5, [r0], -r12, asr #2
 *   @0x2f51a4 ldrsbne pc, [r0, #-132]
 *   @0x2f51a8 .word 0xf8c5f7f2
 *   @0x2f51ac cmppl r0, r4, asr #17
 *   @0x2f51b0 smlawbpl r4, r4, r8, pc
 *   @0x2f51b4 .word 0xf8d44630
 *   @0x2f51b8 .word 0xf7f21230
 *   @0x2f51bc movwhs pc, #0x8bc
 *   @0x2f51c0 eorslo pc, r0, #196, #16
 *   @0x2f51c4 eorlo pc, lr, #164, #16
 *   @0x2f51c8 blvs 0x21e162c <b2_toiTime+0x1a88188>
 *   @0x2f51cc ldrmi r4, [r8, r0, lsr #12]
 *   @0x2f51d0 stmdbvs r1!, {r4, r5, r9, r10, lr} ^
 *   @0x2f51d4 .word 0xf7f22500
 *   @0x2f51d8 ldrtmi pc, [r0], -lr, lsr #17
 *   @0x2f51dc smultbvs r5, r1, r9
 *   @0x2f51e0 .word 0xf8a9f7f2
 *   @0x2f51e4 bvs 0xb46aac <b2_toiTime+0x3ed608>
 *   @0x2f51e8 .word 0xf7f261a5
 *   @0x2f51ec ldrtmi pc, [r0], -r4, lsr #17
 *   @0x2f51f0 movwne pc, #0x8d4
 *   @0x2f51f4 .word 0xf7f26225
 *   @0x2f51f8 shadd8mi pc, r0, lr
 *   @0x2f51fc adcne pc, r8, #212, #16
 *   @0x2f5200 movwpl pc, #0x8c4
 *   @0x2f5204 .word 0xf7f261e5
 *   @0x2f5208 .word 0xf8c4f896
 *   @0x2f520c ldrtmi r5, [r0], -r8, lsr #5
 *   @0x2f5210 sbcne pc, r4, #212, #16
 *   @0x2f5214 .word 0xf88ff7f2
 *   @0x2f5218 sbcpl pc, r4, #196, #16
 *   @0x2f521c andspl pc, r12, #196, #16
 *   @0x2f5220 ldrlt r11, [r0, #-0xdf8]
 *   @0x2f5224 stmdavs r1!, {r2, r9, r10, lr}
 *   @0x2f5228 .word 0xf7f269c0
 *   @0x2f522c movwhs pc, #0x884
 *   @0x2f5230 rsbvs r6, r3, r3, lsr #32
 *   @0x2f5234 ldclt p1, c6, [r0, #-652]
 *   @0x2f5238 .word 0x4604b538
 *   @0x2f523c strhs r6, [r0, #-0xa40]
 *   @0x2f5240 smulwtlt r0, r5, r1
 *   @0x2f5244 tstlt r1, r1, lsr #20
 *   @0x2f5248 .word 0xf875f7f2
 *   @0x2f524c ldclt p2, c6, [r8, #-148]!
 *   @0x2f5250 ldrbmi lr, [r3, sp, lsr #18]!
 *   @0x2f5254 .word 0x460e4614
 *   @0x2f5258 bge 0x3976e4 <ft_adobe_glyph_list+0x6dc0>
 *   @0x2f525c ldrmi r2, [r9], r0, lsl #10
 *   @0x2f5260 stmdaeq r9, {r0, r1, r2, r9, r10, lr} ^
 *   @0x2f5264 stcpl p8, c15, [r4, #-264]
 *   @0x2f5268 .word 0xf89d3101
 *   @0x2f526c .word 0xf7f1a028
 *   @0x2f5270 blls 0x374fe0 <_ZTS13C_UTF16String+0xc08c>
 *   @0x2f5274 blhs 0x306c7c <TT_New_Context+0x6a74>
 *   @0x2f5278 shasxmi sp, r0, r5
 *   @0x2f527c .word 0xf7f168e1
 *   @0x2f5280 andls pc, r1, r2, lsl r11
 *   @0x2f5284 ldrtmi r11, [r8], -r0, ror #2
 *   @0x2f5288 .word 0xf7f24641
 *   @0x2f528c strhs pc, [r0, #-0x854]
 *   @0x2f5290 .word 0x81254638
 *   @0x2f5294 stmdbvs r1!, {r0, r2, r5, r6, r7, sp, lr}
 *   @0x2f5298 .word 0xf84df7f2
 *   @0x2f529c eor r6, r2, r5, lsr #2
 *   @0x2f52a0 stmdbhi r1!, {r4, r5, r9, r10, lr}
 *   @0x2f52a4 ldc2 p7, c15, [sp, #968]!
 *   @0x2f52a8 stmdahs r0, {r0, r12, pc}
 *   @0x2f52ac stmdbhi r7!, {r0, r1, r3, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2f52b0 bvs 0x1046bc8 <b2_toiTime+0x8ed724>
 *   @0x2f52b4 orrlt r0, r7, pc, ror r8
 *   @0x2f52b8 mullo r0, r5, r9
 *   @0x2f52bc .word 0xf995b953
 *   @0x2f52c0 strbmi r0, [r8, r1]
 *   @0x2f52c4 .word 0xf1bab910
 *   @0x2f52c8 andle r0, r3, r0, lsl #30
 *   @0x2f52cc strlo r7, [r1], #-2155
 *   @0x2f52d0 .word 0x3c01f804
 *   @0x2f52d4 strlo r3, [r2, #-0xf01]
 *   @0x2f52d8 ldrtmi lr, [r0], -sp, ror #15
 *   @0x2f52dc .word 0xf7f27027
 *   @0x2f52e0 strbmi pc, [r0], -r11, ror #27
 *   @0x2f52e4 strtmi lr, [r8], -r0
 *   @0x2f52e8 pop {r1, r12, sp, pc}
 *   @0x2f52ec push {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2f52f0 ssub8mi r4, r4, r3
 *   @0x2f52f4 bge 0x386b34 <_ZTS13C_UTF16String+0x1dbe0>
 *   @0x2f52f8 strhs r8, [r0, #-0x921]
 *   @0x2f52fc stcpl p8, c15, [r4, #-264]
 *   @0x2f5300 swplo r4, r8, [r1]
 *   @0x2f5304 .word 0xf89d4682
 *   @0x2f5308 .word 0xf7f19028
 *   @0x2f530c blls 0x374f44 <_ZTS13C_UTF16String+0xbff0>
 *   @0x2f5310 blhs 0x306b34 <TT_New_Context+0x692c>
 *   @0x2f5314 shasxmi sp, r0, r4
 *   @0x2f5318 .word 0xf7f168e1
 *   @0x2f531c andls pc, r1, r4, asr #21
 *   @0x2f5320 ldrbmi r11, [r0], -r0, ror #2
 *   @0x2f5324 .word 0xf7f24639
 *   @0x2f5328 strhs pc, [r0, #-0x806]
 *   @0x2f532c rscvs r4, r5, r0, asr r6
 *   @0x2f5330 stmdbvs r1!, {r0, r2, r5, r8, pc}
 *   @0x2f5334 .word 0xfffff7f1
 *   @0x2f5338 eor r6, r1, r5, lsr #2
 *   @0x2f533c stmdbhi r1!, {r4, r5, r9, r10, lr}
 *   @0x2f5340 stc2l p7, c15, [pc, #-968]!
 *   @0x2f5344 stmdahs r0, {r0, r12, pc}
 *   @0x2f5348 rfeia r4!
 *   @0x2f534c ldrtmi r10, [r12], -r8
 *   @0x2f5350 strtmi r6, [r10], #2613
 *   @0x2f5354 andle r4, r12, r10, lsr #11
 *   @0x2f5358 bleq 0x3737b4 <_ZTS13C_UTF16String+0xa860>
 *   @0x2f535c ldmdblt r0, {r6, r7, r8, r9, r10, lr}
 *   @0x2f5360 svceq #0xf1b9
 *   @0x2f5364 .word 0xf815d0f6
 *   @0x2f5368 strlo r3, [r1], #-3073
 *   @0x2f536c .word 0x3c01f804
 *   @0x2f5370 movwhs lr, #0x7f0
 *   @0x2f5374 eorvc r4, r3, r0, lsr r6
 *   @0x2f5378 ldc2 p7, c15, [lr, #968]
 *   @0x2f537c and r4, r0, r8, lsr r6
 *   @0x2f5380 andlt r4, r2, r8, lsr #12
 *   @0x2f5384 .word 0x87f0e8bd
 *   @0x2f5388 mvnsmi lr, sp, lsr #18
 *   @0x2f538c ldrmi r4, [r4], -r6, lsl #12
 *   @0x2f5390 stcls p6, c4, [r6, #-124]
 *   @0x2f5394 .word 0xf7feb131
 *   @0x2f5398 asrlt pc, r7, lr
 *   @0x2f539c stmvs r3, {r0, r7, r11, sp, lr} ^
 *   @0x2f53a0 and r4, r1, r12, lsl #8
 *   @0x2f53a4 stmdavs r11, {r0, r7, r9, r10, r11, sp, lr} ^
 *   @0x2f53a8 stmdavs r9!, {r0, r2, r4, r5, r8, r12, sp, pc}
 *   @0x2f53ac eorvs r11, r11, r9, lsl r9
 *   @0x2f53b0 pop {r3, r9, r10, lr}
 *   @0x2f53b4 .word 0x460b81f0
 *   @0x2f53b8 .word 0x46216eb0
 *   @0x2f53bc pop {r1, r3, r4, r5, r9, r10, lr}
 *   @0x2f53c0 .word 0xf7f141f0
 *   @0x2f53c4 strhhs r11, [lr], pc
 *   @0x2f53c8 ldrhhi lr, [r0, #141]!
 *   @0x2f53cc mvnsmi lr, sp, lsr #18
 *   @0x2f53d0 .word 0xf8d04605
 *   @0x2f53d4 ldrmi r3, [r4], -r0, lsl #6
 *   @0x2f53d8 stmibvs r2, {r0, r1, r4, r5, r8, r12, sp, pc} ^
 *   @0x2f53dc .word 0xf0804291
 *   @0x2f53e0 .word 0xf85380be
 *   @0x2f53e4 and r1, r4, r1, lsr #32
 *   @0x2f53e8 rscslo pc, r12, #208, #16
 *   @0x2f53ec .word 0xf0804299
 *   @0x2f53f0 .word 0xf8d580b6
 *   @0x2f53f4 stmdahs r0, {r3, r4, r5, r6, r7, r9}
 *   @0x2f53f8 adcshi pc, r4, r0
 *   @0x2f53fc stmdble r2, {r1, r11, sp}
 *   @0x2f5400 subsle r2, r5, r3, lsl #16
 *   @0x2f5404 teqhs r0, #174
 *   @0x2f5408 .word 0xf8d54359
 *   @0x2f540c strdlo r3, r4, [r8, -r0]
 *   @0x2f5410 .word 0xf8914419
 *   @0x2f5414 eorhi r0, r0, r12, lsr #32
 *   @0x2f5418 mlahs sp, r1, r8, pc
 *   @0x2f541c .word 0xf9918062
 *   @0x2f5420 b 0x16ed468 <b2_toiTime+0xf93fc4>
 *   @0x2f5424 .word 0xf8c41e8e
 *   @0x2f5428 .word 0xf991e00c
 *   @0x2f542c .word 0x01b66011
 *   @0x2f5430 cdphs p1, #0x0, c6, c0, c6, #0x1
 *   @0x2f5434 cdpvc p14, #0x4, c7, c11, c15, #0x0
 *   @0x2f5438 ldreq sp, [r11], -r4, lsl #26
 *   @0x2f543c rsbsmi sp, r6, #79691776
 *   @0x2f5440 ands r6, r0, r6, lsr #2
 *   @0x2f5444 .word 0xf1bed10f
 *   @0x2f5448 .word 0xd10c0f00
 *   @0x2f544c ldrbteq pc, [pc], r7
 *   @0x2f5450 .word 0xb12bb907
 *   @0x2f5454 subslt r11, r11, #1610612743
 *   @0x2f5458 ldrheq r0, [r11, r6]
 *   @0x2f545c and r6, r1, r6, ror #1
 *   @0x2f5460 smlalvs r0, r6, r6, r1
 *   @0x2f5464 stmvs r3!, {r0, r1, r5, r8, sp, lr} ^
 *   @0x2f5468 blne 0xfea8f908 <b2_toiTime+0xfffffffffe336464>
 *   @0x2f546c .word 0x6166d001
 *   @0x2f5470 orrseq lr, r2, r3
 *   @0x2f5474 bne 0xfe98da04 <b2_toiTime+0xfffffffffe234560>
 *   @0x2f5478 .word 0xf9916122
 *   @0x2f547c stcvc p0, c2, [r11], {22}
 *   @0x2f5480 .word 0xf9914413
 *   @0x2f5484 vst4.8 {d18, d19, d20, d21}, [pc:64], r7
 *   @0x2f5488 ldrmi r0, [r3], #-384
 *   @0x2f548c .word 0x61a3019b
 *   @0x2f5490 ldrhths pc, [r2], r5
 *   @0x2f5494 mrrc2 p7, #0xe, pc, r2, c15
 *   @0x2f5498 orreq pc, r0, pc, asr #8
 *   @0x2f549c stmdahi r0!, {r5, r6, sp, lr} ^
 *   @0x2f54a0 ldrhths pc, [r2], r5
 *   @0x2f54a4 mcrr2 p7, #0xe, pc, r10, c15
 *   @0x2f54a8 andhs r6, r0, r0, lsr #1
 *   @0x2f54ac ldrhhi lr, [r0, #141]!
 *   @0x2f54b0 rscshs pc, r0, #13959168
 *   @0x2f54b4 cdpvs p1, #0xa, c3, c14, c2, #0x0
 *   @0x2f54b8 orreq lr, r1, #2048
 *   @0x2f54bc eorne pc, r1, r2, lsl r8
 *   @0x2f54c0 ldreq r7, [r2], #-2138
 *   @0x2f54c4 andvs lr, r1, #270336
 *   @0x2f54c8 ldmvc r11, {r0, r3, r4, r6, r7, r11, r12, sp, lr}
 *   @0x2f54cc b 0x13860fc <b2_toiTime+0xc2cc58>
 *   @0x2f54d0 .word 0xf8d52303
 *   @0x2f54d4 ldcne p3, c2, [r9, #-240]
 *   @0x2f54d8 stmdale r7, {r0, r4, r7, r9, lr} ^
 *   @0x2f54dc teqne r8, #13959168
 *   @0x2f54e0 ldrmi r4, [r9], #-1584
 *   @0x2f54e4 .word 0xf9dff7f1
 *   @0x2f54e8 teqle pc, r0, lsl #16
 *   @0x2f54ec .word 0x21044630
 *   @0x2f54f0 ldc2 p7, c15, [r7], {242}
 *   @0x2f54f4 stmdahs r0, {r7, r9, r10, lr}
 *   @0x2f54f8 shasxmi sp, r0, r7
 *   @0x2f54fc blx 0x21734c8 <b2_toiTime+0x1a1a024>
 *   @0x2f5500 ldrtmi r4, [r0], -r7, lsl #12
 *   @0x2f5504 blx 0x20734d0 <b2_toiTime+0x191a02c>
 *   @0x2f5508 .word 0xf7f24630
 *   @0x2f550c rfeia r5!
 *   @0x2f5510 strhthi r6, [r7], -r2
 *   @0x2f5514 .word 0x01bf8067
 *   @0x2f5518 rfeib r5!
 *   @0x2f551c .word 0x463900dc
 *   @0x2f5520 .word 0xfc0cf7ef
 *   @0x2f5524 shasxmi r4, r2, r9
 *   @0x2f5528 rfeib r5!
 *   @0x2f552c .word 0xf7ef00de
 *   @0x2f5530 ldrtmi pc, [r9], -r5, lsl #24
 *   @0x2f5534 .word 0x61204632
 *   @0x2f5538 ldrhlo pc, [lr], #149
 *   @0x2f553c ldrheq pc, [r12], #149
 *   @0x2f5540 rfeib r5!
 *   @0x2f5544 ldrmi r3, [r8], #-224
 *   @0x2f5548 blx 0x13350e <_Z15F_ScriptExecuteR6RValueP9CInstanceS2_iPS_+0x59e>
 *   @0x2f554c shasxmi r4, r2, r9
 *   @0x2f5550 rfeia r5!
 *   @0x2f5554 .word 0xf7ef00e2
 *   @0x2f5558 .word 0x61a0fbf1
 *   @0x2f555c andhs lr, r6, r5
 *   @0x2f5560 ldrhhi lr, [r0, #141]!
 *   @0x2f5564 pop {r1, sp}
 *   @0x2f5568 .word 0x464081f0
 *   @0x2f556c ldrhhi lr, [r0, #141]!
 *   @0x2f5570 andhs r4, r0, #19922944
 *   @0x2f5574 svclt #0x56f7ef
 *   @0x2f5578 .word 0x43f7e92d
 *   @0x2f557c movwhs r4, #0x60d
 *   @0x2f5580 andvc pc, r4, #208, #16
 *   @0x2f5584 rscslo pc, r0, #192, #16
 *   @0x2f5588 .word 0xf8c0462a
 *   @0x2f558c .word 0x460432f4
 *   @0x2f5590 rscslo pc, r8, #192, #16
 *   @0x2f5594 rscslo pc, r12, #192, #16
 *   @0x2f5598 stmibmi r4, {r0, r1, r3, r5, r6, r9, r10, lr}
 *   @0x2f559c stmdblt r8, {r3, r4, r5, r7, r8, r9, r10, lr}
 *   @0x2f55a0 ands r2, lr, r2, lsl #6
 *   @0x2f55a4 andvc pc, r4, #212, #16
 *   @0x2f55a8 stmibmi r1, {r5, r9, r10, lr}
 *   @0x2f55ac strbtmi r4, [r11], -r10, lsr #12
 *   @0x2f55b0 stmdblt r8, {r3, r4, r5, r7, r8, r9, r10, lr}
 *   @0x2f55b4 ands r2, r4, r1, lsl #6
 *   @0x2f55b8 andvc pc, r4, #212, #16
 *   @0x2f55bc ldmdbmi sp!, {r5, r9, r10, lr} ^
 *   @0x2f55c0 strbtmi r4, [r11], -r10, lsr #12
 *   @0x2f55c4 stmdahs r0, {r3, r4, r5, r7, r8, r9, r10, lr}
 *   @0x2f55c8 .word 0xf8d4d0f4
 *   @0x2f55cc strtmi r7, [r0], -r4, lsl #4
 *   @0x2f55d0 qsub16mi r4, r10, r9
 *   @0x2f55d4 ldrmi r4, [r8, r11, ror #12]!
 *   @0x2f55d8 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2f55dc sbcshi pc, r2, r0, asr #32
 *   @0x2f55e0 .word 0xf8c42303
 *   @0x2f55e4 blls 0x3021cc <TT_New_Context+0x1fc4>
 *   @0x2f55e8 stmdble r3, {r0, r1, r2, r8, r9, r11, sp} ^
 *   @0x2f55ec .word 0xf7f14628
 *   @0x2f55f0 .word 0xf8d4f9a7
 *   @0x2f55f4 .word 0x468032f8
 *   @0x2f55f8 .word 0xf0002b00
 *   @0x2f55fc blhs 0x39583c <ft_adobe_glyph_list+0x4f18>
 *   @0x2f5600 blhs 0x3eba10 <_ZTV7CFontGM+0x8>
 *   @0x2f5604 add sp, r8, r6, asr #32
 *   @0x2f5608 stmdbls r0, {r3, r5, r9, r10, lr}
 *   @0x2f560c eorsvc pc, r12, #4, #10
 *   @0x2f5610 mcrr2 p7, #0xf, pc, r7, c2
 *   @0x2f5614 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2f5618 adcshi pc, r4, r0, asr #32
 *   @0x2f561c rscslo pc, r0, #212, #16
 *   @0x2f5620 .word 0xf8c49a00
 *   @0x2f5624 ldmdavc r8, {r2, r4, r5, r6, r7, r9, sp} ^
 *   @0x2f5628 .word 0xf8937819
 *   @0x2f562c streq r12, [r0], #-4
 *   @0x2f5630 mulls r5, r3, r8
 *   @0x2f5634 andvs lr, r1, r0, asr #20
 *   @0x2f5638 ldmibvc lr, {r0, r3, r4, r6, r7, r11, r12, sp, lr}
 *   @0x2f563c ldmvc r9, {r3, r8, r9, lr}
 *   @0x2f5640 b 0x1313dc4 <b2_toiTime+0xbba920>
 *   @0x2f5644 mcrreq p0, #0x0, r2, r1, c1
 *   @0x2f5648 .word 0xf5b10449
 *   @0x2f564c andle r3, r7, r0, lsl #30
 *   @0x2f5650 mvnsvs pc, pc, asr #12
 *   @0x2f5654 .word 0xf5b14001
 *   @0x2f5658 andle r7, r1, r0, lsl #30
 *   @0x2f565c adds r2, r1, r2, lsl #12
 *   @0x2f5660 movwmi lr, #0x9a4f
 *   @0x2f5664 movwvs lr, #0xca43
 *   @0x2f5668 b 0x13c635c <b2_toiTime+0xc6ceb8>
 *   @0x2f566c .word 0xf5b32306
 *   @0x2f5670 movwle r3, #0x1f80
 *   @0x2f5674 add r2, r5, r3, lsl #12
 *   @0x2f5678 blx 0x33db42
 *   @0x2f567c andlo pc, r8, r3
 *   @0x2f5680 stmdble r4, {r4, r7, r9, lr}
 *   @0x2f5684 andeq pc, r8, r2, lsr #3
 *   @0x2f5688 b 0xffab171c <b2_toiTime+0xffffffffff358278>
 *   @0x2f568c .word 0xf8c44603
 *   @0x2f5690 strd r3, r4, [r2], #-44
 *   @0x2f5694 .word 0x21084628
 *   @0x2f5698 blx 0xff3f366a <b2_toiTime+0xfffffffffec9a1c6>
 *   @0x2f569c stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2f56a0 qsub16mi sp, r8, r0
 *   @0x2f56a4 .word 0xf9a5f7f1
 *   @0x2f56a8 strtmi r4, [r8], -r6, lsl #12
 *   @0x2f56ac .word 0xf9a1f7f1
 *   @0x2f56b0 strtmi r4, [r8], -r1, lsl #13
 *   @0x2f56b4 .word 0xf9d1f7f1
 *   @0x2f56b8 strtmi r4, [r8], -r7, lsl #12
 *   @0x2f56bc blx 0x23368e <oggpackB_write+0x13e>
 *   @0x2f56c0 sbcle r2, r11, r0, lsl #28
 *   @0x2f56c4 stmdbeq r2, {r0, r3, r5, r12, sp, lr, pc}
 *   @0x2f56c8 .word 0xf989fa1f
 *   @0x2f56cc svceq #0x1f1b9
 *   @0x2f56d0 .word 0xf5b7d1d0
 *   @0x2f56d4 sbcle r3, sp, #128, #30
 *   @0x2f56d8 blls 0x2fc9c8 <ps_hints_apply+0xb5c8>
 *   @0x2f56dc bl 0xfefc6f84 <b2_toiTime+0xfffffffffe86dae0>
 *   @0x2f56e0 svclt #0x3c0f82
 *   @0x2f56e4 streq pc, [r8, -r3, lsr #3]
 *   @0x2f56e8 .word 0xf7f108bf
 *   @0x2f56ec .word 0xf1a0f929
 *   @0x2f56f0 strtmi r0, [r8], -r8, lsl #2
 *   @0x2f56f4 .word 0xf8d7f7f1
 *   @0x2f56f8 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2f56fc ldcne p1, c13, [r9], #264
 *   @0x2f5700 .word 0xf5044628
 *   @0x2f5704 addeq r7, r9, r12, lsr r2
 *   @0x2f5708 rscsne pc, r4, #196, #16
 *   @0x2f570c blx 0xff5736de <b2_toiTime+0xfffffffffee1a23a>
 *   @0x2f5710 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2f5714 .word 0xf8c4d136
 *   @0x2f5718 movwhs r7, #0x2fc
 *   @0x2f571c teqlo r8, #196, #16
 *   @0x2f5720 teqlo r12, #196, #16
 *   @0x2f5724 rscslo pc, r8, #212, #16
 *   @0x2f5728 .word 0xd1032b03
 *   @0x2f572c teqhi r8, #196, #16
 *   @0x2f5730 ands r9, pc, r0, lsl #22
 *   @0x2f5734 cdpge p3, #0x0, c11, c1, c3, #0x0
 *   @0x2f5738 andvc pc, r4, #212, #16
 *   @0x2f573c ldmdbmi pc, {r5, r9, r10, lr}
 *   @0x2f5740 ldrtmi r4, [r3], -r10, lsr #12
 *   @0x2f5744 ldrhlt r4, [r8, #-120]!
 *   @0x2f5748 andvc pc, r4, #212, #16
 *   @0x2f574c ldmdbmi r12, {r5, r9, r10, lr}
 *   @0x2f5750 ldrtmi r4, [r3], -r10, lsr #12
 *   @0x2f5754 ldrhlt r4, [r8, -r8]!
 *   @0x2f5758 andvc pc, r4, #212, #16
 *   @0x2f575c ldmdbmi r9, {r5, r9, r10, lr}
 *   @0x2f5760 ldrtmi r4, [r3], -r10, lsr #12
 *   @0x2f5764 ldmdblt r8!, {r3, r4, r5, r7, r8, r9, r10, lr}
 *   @0x2f5768 .word 0xf7f14628
 *   @0x2f576c blls 0x373b18 <_ZTS13C_UTF16String+0xabc4>
 *   @0x2f5770 teqeq r8, #196, #16
 *   @0x2f5774 teqlo r12, #196, #16
 *   @0x2f5778 teqeq r12, #212, #16
 *   @0x2f577c .word 0xf8c4b988
 *   @0x2f5780 strd r0, r1, [pc], -r12
 *   @0x2f5784 rscslo pc, r0, #212, #16
 *   @0x2f5788 strtmi r11, [r8], -r3, lsr #2
 *   @0x2f578c teqvc r12, r4, lsl #10
 *   @0x2f5790 blx 0x11f3762 <b2_toiTime+0xa9a2be>
 *   @0x2f5794 ldrtmi r2, [r0], -r0, lsl #6
 *   @0x2f5798 rscslo pc, r4, #196, #16
 *   @0x2f579c rscslo pc, r8, #196, #16
 *   @0x2f57a0 andhs lr, r0, r0
 *   @0x2f57a4 pop {r0, r1, r12, sp, pc}
 *   @0x2f57a8 svclt #0x83f0
 *   @0x2f57ac movtmi r4, #0x2c43
 *   @0x2f57b0 strbmi r4, [r2, #-0xc43]
 *   @0x2f57b4 rsbvs r6, r12, #396
 *   @0x2f57b8 .word 0x73626978
 *   @0x2f57bc movtmi r4, #0x2454
 *   @0x2f57c0 strbmi r4, [r2, #-0x454]
 *   @0x2f57c4 rsbvs r6, r4, #116, #2
 *   @0x2f57c8 svcmi #0xf0e92d
 *   @0x2f57cc stmibvs r11, {r0, r1, r4, r7, r12, sp, pc} ^
 *   @0x2f57d0 strmi r4, [r8], -r0, lsl #13
 *   @0x2f57d4 movwls r4, #0x560c
 *   @0x2f57d8 rfeia r2!
 *   @0x2f57dc movwls r10, #0x4b08
 *   @0x2f57e0 andls r4, sp, r9, lsl r6
 *   @0x2f57e4 .word 0xf7f14620
 *   @0x2f57e8 blls 0x5343a4 <g_InputEvents+0x74c>
 *   @0x2f57ec blhs 0x31981c <__gnu_uldivmod_helper+0x228>
 *   @0x2f57f0 .word 0x8102f040
 *   @0x2f57f4 strtmi r4, [r0], -r9, lsl #19
 *   @0x2f57f8 ldrbtmi r10, [r9], #-2570
 *   @0x2f57fc .word 0xf7f23110
 *   @0x2f5800 andls pc, r8, r9, ror #22
 *   @0x2f5804 .word 0xf0402800
 *   @0x2f5808 blls 0x595bec <g_SWFlineaavertbuff+0x42b24>
 *   @0x2f580c addsmi r4, r3, #124, #20
 *   @0x2f5810 addhi pc, r3, r0
 *   @0x2f5814 strtmi r9, [r0], -sp, lsl #22
 *   @0x2f5818 bleq 0x631c2c <g_SWFaavertbuff+0x5eb64>
 *   @0x2f581c .word 0xf7f14659
 *   @0x2f5820 andls pc, r9, r2, asr #16
 *   @0x2f5824 cmnle r4, r0, lsl #16
 *   @0x2f5828 .word 0x46064b7d
 *   @0x2f582c strmi r4, [r4], r2, lsl #13
 *   @0x2f5830 .word 0x4605447b
 *   @0x2f5834 .word 0x33284681
 *   @0x2f5838 blge 0x69a458 <g_SWFlinevertbuff+0x47390>
 *   @0x2f583c rfeia sp!
 *   @0x2f5840 strbmi r3, [r11, #-0x2c]
 *   @0x2f5844 qsaxmi sp, r0, r4
 *   @0x2f5848 bge 0x69bc68 <g_SWFlinevertbuff+0x48ba0>
 *   @0x2f584c andgt pc, r12, sp, asr #17
 *   @0x2f5850 blx 0x1333822 <b2_toiTime+0xbda37e>
 *   @0x2f5854 .word 0xc00cf8dd
 *   @0x2f5858 .word 0xb1209009
 *   @0x2f585c ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x2f5860 eorls pc, r12, sp, lsr #17
 *   @0x2f5864 ldmdbls r0, {r2, r6, sp, lr, pc}
 *   @0x2f5868 addsmi r6, r9, #6488064
 *   @0x2f586c bls 0x76b960 <b2_toiTime+0x124bc>
 *   @0x2f5870 addsmi r1, r10, #372736
 *   @0x2f5874 blls 0x6abc98 <g_SWFlinevertbuff+0x58bd0>
 *   @0x2f5878 addmi r4, r3, #6422528
 *   @0x2f587c .word 0xf100d003
 *   @0x2f5880 addmi r6, r3, #96
 *   @0x2f5884 blls 0x6a9d48 <g_SWFlinevertbuff+0x56c80>
 *   @0x2f5888 ldmdami pc, {r0, r8, r10, r12, sp} ^
 *   @0x2f588c addmi r11, r3, #-805306358
 *   @0x2f5890 ldmdami lr, {r1, r12, lr, pc} ^
 *   @0x2f5894 tstle r12, r3, lsl #5
 *   @0x2f5898 stmdale r1, {r0, r2, r4, r5, r9, r11, sp}
 *   @0x2f589c eor r2, r10, lr, lsl #7
 *   @0x2f58a0 .word 0x310c4620
 *   @0x2f58a4 .word 0xfffff7f0
 *   @0x2f58a8 stmdahs r0, {r0, r3, r12, pc}
 *   @0x2f58ac qasxmi sp, r0, r1
 *   @0x2f58b0 .word 0xf7f1a909
 *   @0x2f58b4 blls 0x5742d8 <g_SWFlineaavertbuff+0x21210>
 *   @0x2f58b8 .word 0xf109bb5b
 *   @0x2f58bc strtmi r0, [r0], -r1, lsl #2
 *   @0x2f58c0 .word 0x1101eb0b
 *   @0x2f58c4 .word 0xffeff7f0
 *   @0x2f58c8 bllt 0x7198f4 <g_SWFvertbuff+0x4682c>
 *   @0x2f58cc .word 0x0c01f04f
 *   @0x2f58d0 bmi 0x16ed8fc <b2_toiTime+0xf94458>
 *   @0x2f58d4 mulle r4, r3, r2
 *   @0x2f58d8 addsmi r4, r3, #319488
 *   @0x2f58dc strhs r11, [r1], -r8, lsl #30
 *   @0x2f58e0 .word 0xf04fe001
 *   @0x2f58e4 .word 0xf1090a01
 *   @0x2f58e8 blx 0xab7cf4 <b2_toiTime+0x35e850>
 *   @0x2f58ec str pc, [r6, r9, lsl #19]!
 *   @0x2f58f0 ldmdblt r5, {r0, r1, r2, r3, r5, r9, r10, lr}
 *   @0x2f58f4 movwls r2, #0x9302
 *   @0x2f58f8 .word 0xf1bce00b
 *   @0x2f58fc .word 0xd1030f00
 *   @0x2f5900 svceq #0xf1ba
 *   @0x2f5904 .word 0xb10ed002
 *   @0x2f5908 and r2, r0, r0, lsl #6
 *   @0x2f590c strtmi r2, [pc], -lr, lsl #7
 *   @0x2f5910 blls 0x55a53c <g_SWFlineaavertbuff+0x7474>
 *   @0x2f5914 tstlt r3, r8, lsl #6
 *   @0x2f5918 rfeia sp!
 *   @0x2f591c blls 0x5919d4 <g_SWFlineaavertbuff+0x3e90c>
 *   @0x2f5920 .word 0xf8a82200
 *   @0x2f5924 .word 0x21107098
 *   @0x2f5928 .word 0xf8c89200
 *   @0x2f592c blge 0x501b84 <SrcVerts+0x5ebc8>
 *   @0x2f5930 movwls r9, #0x1805
 *   @0x2f5934 .word 0xf7f2463b
 *   @0x2f5938 blls 0x5347e8 <_IO_KeyMap+0x110>
 *   @0x2f593c addseq pc, r12, r8, asr #17
 *   @0x2f5940 cmple r9, r0, lsl #22
 *   @0x2f5944 strtmi r9, [r0], -sp, lsl #18
 *   @0x2f5948 .word 0xf7f0310c
 *   @0x2f594c andls pc, r8, r12, lsr #31
 *   @0x2f5950 cmple r1, r0, lsl #16
 *   @0x2f5954 .word 0x102cf8bd
 *   @0x2f5958 .word 0x01094620
 *   @0x2f595c blx 0x1b7392c <b2_toiTime+0x141a488>
 *   @0x2f5960 stmdahs r0, {r3, r12, pc}
 *   @0x2f5964 .word 0xf8dfd148
 *   @0x2f5968 .word 0x4605b09c
 *   @0x2f596c strmi r4, [r1], r10, lsr #20
 *   @0x2f5970 .word 0x302cf8bd
 *   @0x2f5974 ldmdble r10!, {r0, r1, r3, r6, r8, r10, lr}
 *   @0x2f5978 andls r4, r3, #32, #12
 *   @0x2f597c .word 0xf86df7f1
 *   @0x2f5980 strtmi r4, [r0], -r6, lsl #12
 *   @0x2f5984 .word 0xf869f7f1
 *   @0x2f5988 strtmi r4, [r0], -r2, lsl #13
 *   @0x2f598c .word 0xf865f7f1
 *   @0x2f5990 strtmi r4, [r0], -r7, lsl #12
 *   @0x2f5994 .word 0xf861f7f1
 *   @0x2f5998 bls 0x3cfb2c <error_g0017+0x287d0>
 *   @0x2f599c stmdale r1!, {r0, r1, r2, r3, r4, r7, r9, lr}
 *   @0x2f59a0 addsmi r1, r8, #224256
 *   @0x2f59a4 ldrbmi sp, [lr, #-0x905]
 *   @0x2f59a8 addsmi sp, r6, #1
 *   @0x2f59ac .word 0xf023d11a
 *   @0x2f59b0 movwhs r0, #0x3
 *   @0x2f59b4 adcmi r11, r9, #-1879048183
 *   @0x2f59b8 ldrsbne pc, [r12], r8
 *   @0x2f59bc b 0x16ea1e0 <b2_toiTime+0xf90d3c>
 *   @0x2f59c0 movwlo r1, #0x1e03
 *   @0x2f59c4 andne pc, lr, r1, asr r8
 *   @0x2f59c8 ldrhle r4, [r3, #33]!
 *   @0x2f59cc .word 0xf105e00a
 *   @0x2f59d0 .word 0x012d0e01
 *   @0x2f59d4 .word 0x514e194b
 *   @0x2f59d8 .word 0xf58efa1f
 *   @0x2f59dc andge pc, r4, r3, asr #17
 *   @0x2f59e0 smullsvs r6, r8, pc, r0
 *   @0x2f59e4 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f59e8 .word 0xf989fa1f
 *   @0x2f59ec .word 0xf8a8e7c0
 *   @0x2f59f0 qadd8mi r5, r0, r8
 *   @0x2f59f4 blx 0x1b339c4 <b2_toiTime+0x13da520>
 *   @0x2f59f8 andslt r9, r3, r8, lsl #16
 *   @0x2f59fc svchi #0xf0e8bd
 *   @0x2f5a00 svcmi #0x54544f
 *   @0x2f5a04 stmdavs sp!, {r3, r4, r5, r6, r10, r12, sp, lr} ^
 *   @0x2f5a08 stmdavs r5!, {r2, r5, r6, r8, sp, lr} ^
 *   @0x2f5a0c rsbvs r6, r8, #100, #10
 *   @0x2f5a10 movtpl r4, #0x9e47
 *   @0x2f5a14 stclmi p4, c5, [r5, #-260]
 *   @0x2f5a18 uqsub16vc r7, sp, r8
 *   @0x2f5a1c andeq r10, r10, r6, ror #6
 *   @0x2f5a20 andeq r10, r10, r0, lsr r3
 *   @0x2f5a24 .word 0x460db570
 *   @0x2f5a28 andvs pc, r4, #208, #16
 *   @0x2f5a2c stmdbmi r8, {r1, r3, r5, r9, r10, lr}
 *   @0x2f5a30 strmi r2, [r4], -r0, lsl #6
 *   @0x2f5a34 stmdblt r8, {r4, r5, r7, r8, r9, r10, lr} ^
 *   @0x2f5a38 strtmi r4, [r8], -r6, lsl #18
 *   @0x2f5a3c andvc pc, sp, #4, #10
 *   @0x2f5a40 .word 0x31404479
 *   @0x2f5a44 ldrhtmi lr, [r0], #-141
 *   @0x2f5a48 blt 0x1433a18 <b2_toiTime+0xcda574>
 *   @0x2f5a4c svclt #0xbd70
 *   @0x2f5a50 subpl r4, r3, r4, asr r12
 *   @0x2f5a54 andeq r10, r10, r0, lsr #2
 *   @0x2f5a58 svcmi #0xf0e92d
 *   @0x2f5a5c addlt r4, r9, r4, lsl #12
 *   @0x2f5a60 .word 0xf8d1460d
 *   @0x2f5a64 qadd16mi r9, r10, r12
 *   @0x2f5a68 cmnne r0, r4, asr #17
 *   @0x2f5a6c .word 0xf8d0ab07
 *   @0x2f5a70 stmibmi r4, {r2, r9, sp, lr}
 *   @0x2f5a74 strhls r4, [r6], -r0
 *   @0x2f5a78 .word 0xf0402800
 *   @0x2f5a7c qsub8mi r8, r8, lr
 *   @0x2f5a80 .word 0xff5ef7f0
 *   @0x2f5a84 .word 0xf5044981
 *   @0x2f5a88 ldrbtmi r7, [r9], #-684
 *   @0x2f5a8c strmi r3, [r0], r4, lsl #3
 *   @0x2f5a90 .word 0xf7f24628
 *   @0x2f5a94 andls pc, r6, pc, lsl r10
 *   @0x2f5a98 .word 0xf0402800
 *   @0x2f5a9c .word 0xf8d480ee
 *   @0x2f5aa0 .word 0xf04f715c
 *   @0x2f5aa4 blls 0x4b86dc <SrcVerts+0x15720>
 *   @0x2f5aa8 strhi pc, [r7, -r11, lsl #22]
 *   @0x2f5aac beq 0x3f06d4
 *   @0x2f5ab0 ldrbmi r3, [r7, #-0x706]
 *   @0x2f5ab4 orrshs sp, r1, #32768
 *   @0x2f5ab8 sbcs r9, lr, r6, lsl #6
 *   @0x2f5abc ldrhlo pc, [r8, #-132]
 *   @0x2f5ac0 .word 0xd1642b01
 *   @0x2f5ac4 ldrtmi r4, [r9], -r8, lsr #12
 *   @0x2f5ac8 mcr2 p7, #0x7, pc, c13, c0, #0x7
 *   @0x2f5acc stmdahs r0, {r1, r2, r12, pc}
 *   @0x2f5ad0 sbcshi pc, r3, r0, asr #32
 *   @0x2f5ad4 strtmi r10, [r8], -r6, lsl #22
 *   @0x2f5ad8 ldrmi r9, [r9], -r4, lsl #6
 *   @0x2f5adc .word 0xf812f7f1
 *   @0x2f5ae0 blls 0x41c300 <g_RomDisk+0x24ae0>
 *   @0x2f5ae4 .word 0xf8c44606
 *   @0x2f5ae8 bhs 0x2f6090 <ps_hints_apply+0x4c90>
 *   @0x2f5aec sbchi pc, r5, r0, asr #32
 *   @0x2f5af0 andeq lr, r12, sp, lsl #17
 *   @0x2f5af4 ldrtmi r4, [r3], -r8, asr #12
 *   @0x2f5af8 .word 0xf7f24659
 *   @0x2f5afc blls 0x4b4624 <SrcVerts+0x11668>
 *   @0x2f5b00 smulbteq r12, r4, r8
 *   @0x2f5b04 .word 0xf0402b00
 *   @0x2f5b08 .word 0xf8d480b8
 *   @0x2f5b0c strtmi r1, [r8], -r8, ror #2
 *   @0x2f5b10 .word 0xf7f20089
 *   @0x2f5b14 andls pc, r6, r6, lsl #19
 *   @0x2f5b18 .word 0xf0402800
 *   @0x2f5b1c strlo r8, [r2, -lr, lsr #1]
 *   @0x2f5b20 .word 0x3168f8d4
 *   @0x2f5b24 streq lr, [r6, r7, lsl #22]
 *   @0x2f5b28 .word 0x616cf8d4
 *   @0x2f5b2c blx 0x5c7546 <g_SWFlineaavertbuff+0x7447e>
 *   @0x2f5b30 blmi 0x18d0744 <b2_toiTime+0x11772a0>
 *   @0x2f5b34 ldrbtmi r3, [r11], #-1548
 *   @0x2f5b38 .word 0xf1a63398
 *   @0x2f5b3c strtmi r0, [r8], -r12, lsl #4
 *   @0x2f5b40 andsle r4, r12, #377487360
 *   @0x2f5b44 movwls r4, #0x4619
 *   @0x2f5b48 andgt pc, r12, sp, asr #17
 *   @0x2f5b4c .word 0xf9c2f7f2
 *   @0x2f5b50 .word 0x2160f8d4
 *   @0x2f5b54 andls r4, r6, r2, asr #8
 *   @0x2f5b58 .word 0x1c08f856
 *   @0x2f5b5c .word 0xf846440a
 *   @0x2f5b60 adcsmi r2, r10, #8, #24
 *   @0x2f5b64 .word 0xf8dd9b04
 *   @0x2f5b68 movwle r12, #0x400c
 *   @0x2f5b6c .word 0x1c0cf836
 *   @0x2f5b70 ldrbmi r4, [r2, #-0x40a]
 *   @0x2f5b74 .word 0xf826d901
 *   @0x2f5b78 strlo r12, [r12], -r12, lsl #24
 *   @0x2f5b7c .word 0xf7f2e7dd
 *   @0x2f5b80 qadd8mi pc, r8, r11
 *   @0x2f5b84 .word 0x0106f108
 *   @0x2f5b88 mcr2 p7, #0x4, pc, c13, c0, #0x7
 *   @0x2f5b8c andhs r9, r0, #6
 *   @0x2f5b90 ldrsblo pc, [r12, #-132]
 *   @0x2f5b94 .word 0xf10d9200
 *   @0x2f5b98 .word 0x46480b18
 *   @0x2f5b9c andlt pc, r4, sp, asr #17
 *   @0x2f5ba0 .word 0xf7f22114
 *   @0x2f5ba4 blls 0x4b457c <SrcVerts+0x115c0>
 *   @0x2f5ba8 smulbteq r4, r4, r8
 *   @0x2f5bac .word 0xd1642b00
 *   @0x2f5bb0 ldrsbne pc, [r12, #-132]
 *   @0x2f5bb4 .word 0x0c0cf04f
 *   @0x2f5bb8 .word 0xf8cd4628
 *   @0x2f5bbc blx 0x625bf6 <g_SWFaavertbuff+0x52b2e>
 *   @0x2f5bc0 .word 0xf7f2f101
 *   @0x2f5bc4 .word 0xf8ddf92e
 *   @0x2f5bc8 andls r12, r6, r12
 *   @0x2f5bcc cmple r4, r0, lsl #16
 *   @0x2f5bd0 .word 0xf8d44a30
 *   @0x2f5bd4 .word 0xf8d46164
 *   @0x2f5bd8 ldrbtmi r3, [r10], #-348
 *   @0x2f5bdc andls r3, r5, #164, #4
 *   @0x2f5be0 strtmi r11, [r8], -r11, lsl #7
 *   @0x2f5be4 ldrtmi r9, [r2], -r5, lsl #18
 *   @0x2f5be8 .word 0xf8cd9304
 *   @0x2f5bec .word 0xf7f2c00c
 *   @0x2f5bf0 blls 0x4341bc <g_RomDisk+0x3c99c>
 *   @0x2f5bf4 .word 0xc00cf8dd
 *   @0x2f5bf8 bllt 0x719c18 <g_SWFvertbuff+0x46b50>
 *   @0x2f5bfc movwlt r8, #0x1931
 *   @0x2f5c00 .word 0x0160f8d4
 *   @0x2f5c04 strmi r6, [r2], #-2290
 *   @0x2f5c08 rscsvs r4, r2, r2, asr #8
 *   @0x2f5c0c tstle r8, #-1610612725
 *   @0x2f5c10 ldrbmi r4, [r2, #-0x40a]
 *   @0x2f5c14 rfeia r4!
 *   @0x2f5c18 bhs 0x33e180
 *   @0x2f5c1c ldmhi r2!, {r4, r8, r12, lr, pc}
 *   @0x2f5c20 strle r0, [sp, #-0x411]
 *   @0x2f5c24 .word 0x1168f8d4
 *   @0x2f5c28 andmi pc, r0, r2, lsr #11
 *   @0x2f5c2c andle r4, r8, #136, #4
 *   @0x2f5c30 .word 0x116cf8d4
 *   @0x2f5c34 andne pc, r2, #12, #22
 *   @0x2f5c38 sbchs pc, r0, #679477248
 *   @0x2f5c3c .word 0xb1028812
 *   @0x2f5c40 bllo 0x343498
 *   @0x2f5c44 .word 0xf8d4e7cc
 *   @0x2f5c48 tsths r4, r4, ror #2
 *   @0x2f5c4c strbmi r4, [r8], -lr, lsl #20
 *   @0x2f5c50 stm sp, {r1, r2, r4, r5, r6, r7, r9, r11, r12}
 *   @0x2f5c54 adcsne r0, r6, r8, lsl #16
 *   @0x2f5c58 .word 0xf8d44356
 *   @0x2f5c5c shsaxmi r2, r3, r12
 *   @0x2f5c60 blx 0x873c30 <b2_toiTime+0x11a78c>
 *   @0x2f5c64 cmpvs r12, r4, asr #17
 *   @0x2f5c68 smulbteq r4, r4, r8
 *   @0x2f5c6c .word 0xf7f24628
 *   @0x2f5c70 .word 0xf8d4f923
 *   @0x2f5c74 .word 0xf8a4315c
 *   @0x2f5c78 stmdals r6, {r2, r4, r6, r8, r12, sp}
 *   @0x2f5c7c pop {r0, r3, r12, sp, pc}
 *   @0x2f5c80 svclt #0x8ff0
 *   @0x2f5c84 cdpvs p13, #0x6, c6, c1, c5, #0x3
 *   @0x2f5c88 stclgt p12, c12, [r12], {205}
 *   @0x2f5c8c ldrdeq r10, r11, [r10], -r6
 *   @0x2f5c90 andeq r10, r10, r10, lsr #32
 *   @0x2f5c94 andeq r9, r10, r6, lsl #31
 *   @0x2f5c98 .word 0x460db570
 *   @0x2f5c9c andvs pc, r4, #208, #16
 *   @0x2f5ca0 stmdbmi r8, {r1, r3, r5, r9, r10, lr}
 *   @0x2f5ca4 strmi r2, [r4], -r0, lsl #6
 *   @0x2f5ca8 stmdblt r8, {r4, r5, r7, r8, r9, r10, lr} ^
 *   @0x2f5cac strtmi r4, [r8], -r6, lsl #18
 *   @0x2f5cb0 rscvc pc, lr, #4, #10
 *   @0x2f5cb4 biclo r4, r0, r9, ror r4
 *   @0x2f5cb8 ldrhtmi lr, [r0], #-141
 *   @0x2f5cbc stmdblt r10, {r1, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc}
 *   @0x2f5cc0 svclt #0xbd70
 *   @0x2f5cc4 rsbvc r7, pc, r4, ror r3
 *   @0x2f5cc8 andeq r9, r10, r12, lsr #29
 *   @0x2f5ccc mvnsmi lr, sp, lsr #18
 *   @0x2f5cd0 .word 0xf8d0460e
 *   @0x2f5cd4 ldrtmi r5, [r2], -r4, lsl #4
 *   @0x2f5cd8 movwhs r4, #0x927
 *   @0x2f5cdc strmi r4, [r8, r4, lsl #12]!
 *   @0x2f5ce0 stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x2f5ce4 .word 0xf8dfd144
 *   @0x2f5ce8 .word 0xf5048094
 *   @0x2f5cec ldrtmi r7, [r0], -r2, lsl #15
 *   @0x2f5cf0 shsub8mi r4, r10, r8
 *   @0x2f5cf4 mvneq pc, r8, lsl #2
 *   @0x2f5cf8 .word 0xf8ecf7f2
 *   @0x2f5cfc bllt 0xff107518 <b2_toiTime+0xfffffffffe9ae074>
 *   @0x2f5d00 .word 0x3104f8d4
 *   @0x2f5d04 smlatbeq r10, r4, r8, pc
 *   @0x2f5d08 svclo #0x80f5b3
 *   @0x2f5d0c smlatbeq r12, r4, r8, pc
 *   @0x2f5d10 smlatbeq lr, r4, r8, pc
 *   @0x2f5d14 tsteq r0, r4, lsr #17
 *   @0x2f5d18 tsteq r2, r4, lsr #17
 *   @0x2f5d1c tsteq r4, r4, lsr #17
 *   @0x2f5d20 tsteq r6, r4, lsr #17
 *   @0x2f5d24 tsteq r8, r4, lsr #17
 *   @0x2f5d28 tsteq r10, r4, lsr #17
 *   @0x2f5d2c tsteq r12, r4, lsr #17
 *   @0x2f5d30 tsteq lr, r4, lsr #17
 *   @0x2f5d34 smulwbeq r0, r4, r8
 *   @0x2f5d38 smulwbeq r2, r4, r8
 *   @0x2f5d3c shadd16mi sp, r0, r8
 *   @0x2f5d40 mvnseq pc, r8, lsl #2
 *   @0x2f5d44 .word 0xf7f2463a
 *   @0x2f5d48 stmiblt r0, {r0, r2, r6, r7, r11, r12, sp, lr, pc}
 *   @0x2f5d4c ldrhlo pc, [r8, -r4]
 *   @0x2f5d50 ldrhhs pc, [r4, -r4]
 *   @0x2f5d54 svclt #0x9c2b3f
 *   @0x2f5d58 .word 0xf8a42340
 *   @0x2f5d5c .word 0xf64f3118
 *   @0x2f5d60 addsmi r7, r10, #-335544317
 *   @0x2f5d64 .word 0xf8a4d904
 *   @0x2f5d68 strhs r3, [r0, #-0x114]
 *   @0x2f5d6c strmi lr, [r5], -r0
 *   @0x2f5d70 pop {r3, r5, r9, r10, lr}
 *   @0x2f5d74 svclt #0x81f0
 *   @0x2f5d78 stclvs p8, c7, [r1, #-448]!
 *   @0x2f5d7c andeq r9, r10, r0, ror lr
 *   @0x2f5d80 ssub16mi r11, r3, r0
 *   @0x2f5d84 strmi r4, [sp], -r4, lsl #12
 *   @0x2f5d88 andvs pc, r4, #208, #16
 *   @0x2f5d8c stmdbmi r12, {r1, r3, r4, r5, r8, r12, sp, pc}
 *   @0x2f5d90 movwhs r4, #0x62a
 *   @0x2f5d94 ldmiblt r0, {r4, r5, r7, r8, r9, r10, lr}
 *   @0x2f5d98 ldrvc pc, [r4], #1284
 *   @0x2f5d9c stmdbmi r9, {r2, sp, lr, pc}
 *   @0x2f5da0 ldrmi r4, [r0, r10, lsr #12]!
 *   @0x2f5da4 ldrblo r11, [r8], #2392
 *   @0x2f5da8 strtmi r4, [r8], -r7, lsl #18
 *   @0x2f5dac ldrbtmi r4, [r9], #-1570
 *   @0x2f5db0 orrsvc pc, r12, r1, lsl #10
 *   @0x2f5db4 .word 0xf88ef7f2
 *   @0x2f5db8 rsbvs r11, r0, #8, #18
 *   @0x2f5dbc ldcllt p2, c6, [r0, #-640]!
 *   @0x2f5dc0 strbtvc r6, [r8], -r1, ror #10
 *   @0x2f5dc4 stmdavs r8!, {r0, r5, r6, r8, r10, sp, lr} ^
 *   @0x2f5dc8 strheq r9, [r10], -r2
 *   @0x2f5dcc svcmi #0xf0e92d
 *   @0x2f5dd0 .word 0x4604b091
 *   @0x2f5dd4 andls r4, r10, #14680064
 *   @0x2f5dd8 movwls r6, #0xba41
 *   @0x2f5ddc stmibvs r3, {r0, r2, r7, r9, r11, sp, lr} ^
 *   @0x2f5de0 ldmdals r10, {r1, r9, r11, sp, lr}
 *   @0x2f5de4 .word 0xf89d4419
 *   @0x2f5de8 stmdahs r4!, {r2, r3, r5, r6, pc} ^
 *   @0x2f5dec ldmdble r2, {r0, r2, r3, r8, r12, pc}
 *   @0x2f5df0 sub r2, r5, #8
 *   @0x2f5df4 fldmiaxne r8, {d9, d10, d11, d12, d13, d14}
 *   @0x2f5df8 ldmdavc pc, {r0, r2, r3, r12, pc}
 *   @0x2f5dfc b 0x1313f64 <b2_toiTime+0xbbaac0>
 *   @0x2f5e00 ldcne p7, c2, [r8, #-28]
 *   @0x2f5e04 strhls r4, [sp], -lr
 *   @0x2f5e08 mulgt r2, r3, r8
 *   @0x2f5e0c andle r7, r5, #216, #16
 *   @0x2f5e10 movwlo r3, #0x8a01
 *   @0x2f5e14 bhs 0x31aa50 <__gnu_unwind_execute+0x314>
 *   @0x2f5e18 eor sp, r12, #236, #2
 *   @0x2f5e1c andhs lr, r12, r0, asr #20
 *   @0x2f5e20 ldmle r5!, {r1, r2, r7, r9, lr} ^
 *   @0x2f5e24 ldmdbvc r10, {r3, r4, r6, r8, r11, r12, sp, lr}
 *   @0x2f5e28 b 0x12f6e30 <b2_toiTime+0xb9d98c>
 *   @0x2f5e2c ldmibvc r10, {r1, sp, lr} ^
 *   @0x2f5e30 tstmi r0, #2539520
 *   @0x2f5e34 andhs lr, r3, r0, asr #20
 *   @0x2f5e38 addsmi r1, r8, #438272
 *   @0x2f5e3c stmdane r11, {r3, r4, r6, r7, r11, r12, lr, pc}
 *   @0x2f5e40 andeq pc, r8, #-1073741824
 *   @0x2f5e44 .word 0xf0c04295
 *   @0x2f5e48 .word 0xf1038216
 *   @0x2f5e4c .word 0xf8cd0c02
 *   @0x2f5e50 .word 0x5c08c034
 *   @0x2f5e54 b 0x1353fc0 <b2_toiTime+0xbfab1c>
 *   @0x2f5e58 ldcne p1, c2, [r8, #-0]
 *   @0x2f5e5c stmdblo r1, {r0, r2, r3, r12, pc}
 *   @0x2f5e60 mulgt r2, r3, r8
 *   @0x2f5e64 andsgt pc, r0, sp, asr #17
 *   @0x2f5e68 mulgt r3, r3, r8
 *   @0x2f5e6c .word 0xf8cd920d
 *   @0x2f5e70 .word 0xf893c014
 *   @0x2f5e74 .word 0xf8cdc004
 *   @0x2f5e78 .word 0xf893c018
 *   @0x2f5e7c .word 0xf8cdc005
 *   @0x2f5e80 .word 0xf893c01c
 *   @0x2f5e84 .word 0xf8cdc006
 *   @0x2f5e88 .word 0xf893c020
 *   @0x2f5e8c .word 0xf8cdc007
 *   @0x2f5e90 ldmdbhs r2, {r2, r5, lr, pc}
 *   @0x2f5e94 mvnhi pc, r0, lsl #4
 *   @0x2f5e98 .word 0xf011e8df
 *   @0x2f5e9c eorseq r0, r8, r3, lsl r0
 *   @0x2f5ea0 rsbseq r0, r10, r2, rrx
 *   @0x2f5ea4 strheq r0, [sp, #7]!
 *   @0x2f5ea8 mvneq r0, sp, ror #3
 *   @0x2f5eac mvneq r0, sp, ror #3
 *   @0x2f5eb0 mvneq r0, sp, ror #3
 *   @0x2f5eb4 mvneq r0, sp, ror #3
 *   @0x2f5eb8 mvneq r0, sp, ror #3
 *   @0x2f5ebc mvneq r0, sp, ror #3
 *   @0x2f5ec0 blne 0x761a4
 *   @0x2f5ec4 orreq lr, r6, #2048
 *   @0x2f5ec8 .word 0x0108f103
 *   @0x2f5ecc .word 0xf0c0428d
 *   @0x2f5ed0 ldcne p1, c8, [r8, #-840]
 *   @0x2f5ed4 .word 0xf812900d
 *   @0x2f5ed8 ldmdavc lr, {r1, r2, r5, sp} ^
 *   @0x2f5edc mulls r5, r3, r8
 *   @0x2f5ee0 ldrteq r7, [r6], #-2200
 *   @0x2f5ee4 mulge r6, r3, r8
 *   @0x2f5ee8 strvs lr, [r2], -r6, asr #20
 *   @0x2f5eec b 0x16d425c <b2_toiTime+0xf7adb8>
 *   @0x2f5ef0 mrsls r4, apsr
 *   @0x2f5ef4 ldmdbvc r10, {r1, r2, r4, r8, r9, lr}
 *   @0x2f5ef8 strhs lr, [r0], -r6, asr #20
 *   @0x2f5efc stmdbvs r2, {r0, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f5f00 b 0x1554670 <b2_toiTime+0xdfb1cc>
 *   @0x2f5f04 b 0x1538314 <b2_toiTime+0xddee70>
 *   @0x2f5f08 eors r2, sp, r10, lsl #18
 *   @0x2f5f0c andseq pc, r4, #-1073741824
 *   @0x2f5f10 .word 0xf0c04295
 *   @0x2f5f14 .word 0xf89381b0
 *   @0x2f5f18 ldmdbge r0, {r0, r3, lr, pc}
 *   @0x2f5f1c andeq pc, r12, #-1073741824
 *   @0x2f5f20 mullt r8, r3, r8
 *   @0x2f5f24 stchs p8, c15, [r12, #-260]
 *   @0x2f5f28 .word 0xf8934620
 *   @0x2f5f2c strtmi r9, [r10], -r10
 *   @0x2f5f30 mulge r11, r3, r8
 *   @0x2f5f34 .word 0xf8cd2301
 *   @0x2f5f38 .word 0xf5c2c00c
 *   @0x2f5f3c .word 0xf8ddf969
 *   @0x2f5f40 stmdahs r0, {r2, r3, lr, pc}
 *   @0x2f5f44 orrshi pc, r7, r0, asr #32
 *   @0x2f5f48 .word 0x4c0cea4f
 *   @0x2f5f4c b 0x15fcf2c <b2_toiTime+0xea3a88>
 *   @0x2f5f50 b 0x15d0b84 <b2_toiTime+0xe776e0>
 *   @0x2f5f54 b 0x1578784 <b2_toiTime+0xe1f2e0>
 *   @0x2f5f58 blx 0x480386 <_ZN10InputQuery13ms_InputText2E+0xf96>
 *   @0x2f5f5c adds pc, r10, r9, lsl #12
 *   @0x2f5f60 bl 0x37cf40 <_ZTS13C_UTF16String+0x13fec>
 *   @0x2f5f64 ldcne p3, c0, [r9, #-280]
 *   @0x2f5f68 .word 0xf0c0428d
 *   @0x2f5f6c ldcne p1, c8, [r8], {132}
 *   @0x2f5f70 .word 0xf812900d
 *   @0x2f5f74 ldmdavc r10, {r1, r2, r4, sp, lr} ^
 *   @0x2f5f78 .word 0xf893910d
 *   @0x2f5f7c b 0x1399f8c <b2_toiTime+0xc40ae8>
 *   @0x2f5f80 ldmvc r11, {r1, r2, r9, r10, sp} ^
 *   @0x2f5f84 stmdbhs r9, {r0, r1, r6, r9, r11, sp, lr, pc}
 *   @0x2f5f88 .word 0xf040454e
 *   @0x2f5f8c cmn r2, r5, lsl #1
 *   @0x2f5f90 andeq pc, r12, #-1073741824
 *   @0x2f5f94 vhsub.s8 d4, d16, d26
 *   @0x2f5f98 bvc 0xad6558 <b2_toiTime+0x37d0b4>
 *   @0x2f5f9c .word 0xf8133310
 *   @0x2f5fa0 .word 0xf813cc07
 *   @0x2f5fa4 .word 0xf8131c06
 *   @0x2f5fa8 addsmi r0, sp, #1280
 *   @0x2f5fac .word 0xf0c0920d
 *   @0x2f5fb0 b 0x16d6540 <b2_toiTime+0xf7d09c>
 *   @0x2f5fb4 bne 0xfed88fec <b2_toiTime+0xfffffffffe62fb48>
 *   @0x2f5fb8 .word 0x6c07ea4c
 *   @0x2f5fbc andeq lr, r0, r12, asr #20
 *   @0x2f5fc0 b 0x12fa210 <b2_toiTime+0xba0d6c>
 *   @0x2f5fc4 blo 0x33e3d0
 *   @0x2f5fc8 vqsub.s8 d4, d16, d1
 *   @0x2f5fcc andhs r8, r0, #84, #2
 *   @0x2f5fd0 .word 0xf000428a
 *   @0x2f5fd4 blls 0x65651c <g_SWFlinevertbuff+0x3454>
 *   @0x2f5fd8 mulls sp, r8, r12
 *   @0x2f5fdc ldmdavc r8, {r0, r2, r3, r4, r11, r12, sp, lr} ^
 *   @0x2f5fe0 andhs lr, r5, r0, asr #20
 *   @0x2f5fe4 .word 0xf10342b0
 *   @0x2f5fe8 andls r0, sp, r4
 *   @0x2f5fec ldmvc lr, {r0, r1, r3, r8, r12, lr, pc}
 *   @0x2f5ff0 .word 0xf89378da
 *   @0x2f5ff4 b 0x139a014 <b2_toiTime+0xc40b70>
 *   @0x2f5ff8 ldcne p6, c2, [r10, #24]
 *   @0x2f5ffc andls r7, sp, #3588096
 *   @0x2f6000 stmdbhs r9, {r0, r1, r6, r9, r11, sp, lr, pc}
 *   @0x2f6004 andlo lr, r1, #72
 *   @0x2f6008 .word 0xf103e7e2
 *   @0x2f600c addsmi r0, r5, #24, #4
 *   @0x2f6010 teqhi r1, r0, asr #1
 *   @0x2f6014 .word 0xf103a910
 *   @0x2f6018 .word 0xf893020c
 *   @0x2f601c strtmi r11, [r0], -r8
 *   @0x2f6020 stchs p8, c15, [r12, #-260]
 *   @0x2f6024 bvc 0x1ac78d4 <b2_toiTime+0x136e430>
 *   @0x2f6028 mulls r10, r3, r8
 *   @0x2f602c mulge r11, r3, r8
 *   @0x2f6030 .word 0xf5c22301
 *   @0x2f6034 stmdahs r0, {r0, r2, r3, r5, r6, r7, r11, r12, sp, lr, pc}
 *   @0x2f6038 tsthi sp, r0, asr #32
 *   @0x2f603c vldrne d9, [r10, #-52]
 *   @0x2f6040 .word 0xf893920d
 *   @0x2f6044 bne 0xfee66050 <b2_toiTime+0xfffffffffe70cbac>
 *   @0x2f6048 b 0x16d40b4 <b2_toiTime+0xf7ac10>
 *   @0x2f604c b 0x1609084 <b2_toiTime+0xeafbe0>
 *   @0x2f6050 ldmvc r9, {r0, r10, r11, sp, lr} ^
 *   @0x2f6054 .word 0x0101ea4c
 *   @0x2f6058 mulgt r2, r3, r8
 *   @0x2f605c .word 0x210cea41
 *   @0x2f6060 svceq #0x65ebb1
 *   @0x2f6064 .word 0x8107f200
 *   @0x2f6068 .word 0xf0004288
 *   @0x2f606c blls 0x656484 <g_SWFlinevertbuff+0x33bc>
 *   @0x2f6070 andls r1, sp, #39424
 *   @0x2f6074 ldmdavc r11, {r1, r3, r4, r11, r12, sp, lr} ^
 *   @0x2f6078 movwhs lr, #0x2a43
 *   @0x2f607c strhle r4, [r1], -r3
 *   @0x2f6080 ldrb r3, [r1, r1]!
 *   @0x2f6084 b 0x14b7188 <b2_toiTime+0xd5dce4>
 *   @0x2f6088 b 0x15d0cbc <b2_toiTime+0xe77818>
 *   @0x2f608c b 0x15788bc <b2_toiTime+0xe1f418>
 *   @0x2f6090 blx 0x5404be <obj_has_event+0x594e>
 *   @0x2f6094 ldrtmi pc, [r1], #1536
 *   @0x2f6098 vrshl.s8 q2, q7, q0
 *   @0x2f609c .word 0xf8dd80ec
 *   @0x2f60a0 stmdavs r5!, {r2, r3, r4, lr, pc} ^
 *   @0x2f60a4 movwmi lr, #0xca4f
 *   @0x2f60a8 ldrsbgt pc, [r8], -sp
 *   @0x2f60ac movwvs lr, #0xca43
 *   @0x2f60b0 .word 0xc024f8dd
 *   @0x2f60b4 movweq lr, #0xca43
 *   @0x2f60b8 .word 0xc020f8dd
 *   @0x2f60bc movwhs lr, #0xca43
 *   @0x2f60c0 bl 0xff147194 <b2_toiTime+0xfffffffffe9edcf0>
 *   @0x2f60c4 .word 0xf0000606
 *   @0x2f60c8 stmibvs r2!, {r1, r2, r4, r6, r7, pc}
 *   @0x2f60cc addsmi r1, r1, #2506752
 *   @0x2f60d0 sbcshi pc, r1, r0, lsl #4
 *   @0x2f60d4 strtmi r6, [r8], -r1, ror #18
 *   @0x2f60d8 .word 0xf7f04419
 *   @0x2f60dc stmdahs r0, {r2, r5, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f60e0 sbchi pc, lr, r0, asr #32
 *   @0x2f60e4 bleq 0x1232520 <b2_toiTime+0xad907c>
 *   @0x2f60e8 ldrtmi r4, [r1], -r8, lsr #12
 *   @0x2f60ec .word 0xf7f1465a
 *   @0x2f60f0 stmdahs r0, {r3, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f60f4 sbchi pc, r4, r0, asr #32
 *   @0x2f60f8 .word 0xf8dd9804
 *   @0x2f60fc blls 0x6e6154 <g_SWFvertbuff+0x1308c>
 *   @0x2f6100 strhs lr, [r0, -r12, asr #20]
 *   @0x2f6104 ldrmi r3, [lr], #-3841
 *   @0x2f6108 movwls r2, #0xef11
 *   @0x2f610c svchs #0x12d90e
 *   @0x2f6110 adchi pc, r6, r0, lsl #4
 *   @0x2f6114 .word 0xf007e8df
 *   @0x2f6118 strtge r2, [r4], #1863
 *   @0x2f611c stclo p7, c4, [r7], #-228
 *   @0x2f6120 strtge r10, [r4], #1098
 *   @0x2f6124 strtge r10, [r4], #1188
 *   @0x2f6128 eoreq r2, r4, r4, lsr #8
 *   @0x2f612c cdpeq p0, #0x0, c15, c1, c15, #0x2
 *   @0x2f6130 blx 0x688e8c <g_SWFlinevertbuff+0x35dc4>
 *   @0x2f6134 andmi pc, r11, r7, lsl #2
 *   @0x2f6138 bmi 0x182462c <b2_toiTime+0x10cb188>
 *   @0x2f613c bhs 0x30616c <TT_New_Context+0x5f64>
 *   @0x2f6140 strtmi sp, [r0], -r5, ror #1
 *   @0x2f6144 ldrtmi r10, [r2], -lr, lsl #18
 *   @0x2f6148 stmdbge lr, {r0, r1, sp, lr, pc}
 *   @0x2f614c ldrtmi r4, [r2], -r0, lsr #12
 *   @0x2f6150 .word 0xf5c24673
 *   @0x2f6154 pkhtbmi pc, r1, sp, asr #16
 *   @0x2f6158 .word 0xf0402800
 *   @0x2f615c ldrb r8, [r6, r6, lsl #1]
 *   @0x2f6160 stmdbeq r7, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f6164 stmvs r3!, {r0, r7, sp, lr, pc} ^
 *   @0x2f6168 ldmdahi r10, {r0, r3, r4, r6, r11, pc}
 *   @0x2f616c ldmeq r11, {r0, r1, r3, r6, r7, r8, r10, r11, r12} ^
 *   @0x2f6170 movtmi r4, #0xa353
 *   @0x2f6174 bl 0xfefc2998 <b2_toiTime+0xfffffffffe8694f4>
 *   @0x2f6178 ldmdble r10, {r1, r4, r6, r7, r8, r9, r10, r11}
 *   @0x2f617c bne 0xfef9c9bc <b2_toiTime+0xfffffffffe843518>
 *   @0x2f6180 mulsle r9, r3, r2
 *   @0x2f6184 ldrbtmi r4, [pc], #-3906
 *   @0x2f6188 svcmi #0x42e018
 *   @0x2f618c ands r4, r5, pc, ror r4
 *   @0x2f6190 movwlo r9, #0x1b0e
 *   @0x2f6194 stmdble r2, {r0, r1, r4, r5, r7, r9, lr}
 *   @0x2f6198 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f619c svcmi #0x3ee065
 *   @0x2f61a0 ldrbtmi r9, [pc], #-782
 *   @0x2f61a4 svcmi #0x3de00a
 *   @0x2f61a8 and r4, r7, pc, ror r4
 *   @0x2f61ac ldrbtmi r4, [pc], #-3900
 *   @0x2f61b0 svcmi #0x3ce004
 *   @0x2f61b4 and r4, r1, pc, ror r4
 *   @0x2f61b8 ldrbtmi r4, [pc], #-3899
 *   @0x2f61bc blhs 0x315350 <FT_Bitmap_Embolden+0x50a>
 *   @0x2f61c0 stcvc p1, c13, [r2], #-256
 *   @0x2f61c4 bhs 0x310458 <af_shaper_get_elem+0x5cc6>
 *   @0x2f61c8 stmvs r2!, {r0, r1, r2, r4, r6, r12, lr, pc} ^
 *   @0x2f61cc ldmdahi r1, {r4, r6, r11, pc}
 *   @0x2f61d0 andsvs r6, r9, r8, asr r0
 *   @0x2f61d4 bhs 0x415464 <g_RomDisk+0x1dc44>
 *   @0x2f61d8 stmdale r10, {r0, r3, r4, r12, lr, pc}
 *   @0x2f61dc andsle r2, r0, r1, lsl #20
 *   @0x2f61e0 .word 0xd1402a02
 *   @0x2f61e4 ldrmi r2, [r0], #-515
 *   @0x2f61e8 andhs r7, r4, #-1711276032
 *   @0x2f61ec addsvs r0, r8, r0, lsl #17
 *   @0x2f61f0 bhs 0x52e258 <SrcVerts+0x8b29c>
 *   @0x2f61f4 bhs 0xb2a240 <b2_toiTime+0x3d0d9c>
 *   @0x2f61f8 andhs sp, r7, #1073741837
 *   @0x2f61fc ldrvc r0, [r10], #128
 *   @0x2f6200 andlo lr, r7, sp
 *   @0x2f6204 andhs r7, r2, #-1711276032
 *   @0x2f6208 addsvs r0, r8, r0, asr #17
 *   @0x2f620c andlo lr, r1, r10
 *   @0x2f6210 andshs r7, r0, #-1711276032
 *   @0x2f6214 addsvs r0, r8, r0, asr #16
 *   @0x2f6218 andhs lr, r2, #4
 *   @0x2f621c vst3.32 {d23, d24, d25}, [pc:64], r10
 *   @0x2f6220 addsvs r7, r8, r0, lsl #5
 *   @0x2f6224 ldmvs r11, {r1, r3, r4, r9, pc}
 *   @0x2f6228 andle r4, r11, r9, asr r3
 *   @0x2f622c svceq #0xf1b8
 *   @0x2f6230 stmdavs r2!, {r1, r4, r5, r7, r8, r12, lr, pc}
 *   @0x2f6234 .word 0xf7f16d50
 *   @0x2f6238 pkhtbmi pc, r1, r11, asr #23
 *   @0x2f623c movwhs r11, #0x19a8
 *   @0x2f6240 and r7, r2, r3, ror #8
 *   @0x2f6244 svceq #0xf1b8
 *   @0x2f6248 stmdals r11, {r1, r2, r5, r7, r8, r12, lr, pc}
 *   @0x2f624c stmdbls lr, {r1, r3, r4, r9, r11, r12, pc}
 *   @0x2f6250 strtmi r9, [r0], -r0
 *   @0x2f6254 ldrtmi r9, [r2], -r1, lsl #4
 *   @0x2f6258 ldrmi r9, [r8, r10, lsl #22]!
 *   @0x2f625c and r4, r4, r1, lsl #13
 *   @0x2f6260 stmdbeq r8, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f6264 .word 0xf04fe001
 *   @0x2f6268 strtmi r0, [r8], -r3, lsl #18
 *   @0x2f626c .word 0xf7f14659
 *   @0x2f6270 strbmi pc, [r8], -r12, asr #27
 *   @0x2f6274 andhs lr, r6, r4
 *   @0x2f6278 .word 0xf04fe002
 *   @0x2f627c ldrb r0, [r4, r6, lsl #18]!
 *   @0x2f6280 pop {r0, r4, r12, sp, pc}
 *   @0x2f6284 svclt #0x8ff0
 *   @0x2f6288 andeq r0, r2, r0, ror #2
 *   @0x2f628c andeq r0, r1, r3, lsl #1
 *   @0x2f6290 .word 0xffffdff3
 *   @0x2f6294 .word 0xffffdfed
 *   @0x2f6298 andeq r0, r0, r7, lsl #2
 *   @0x2f629c .word 0xffffdec3
 *   @0x2f62a0 strdeq r0, r1, [r0], -r11
 *   @0x2f62a4 .word 0xffffdfc5
 *   @0x2f62a8 .word 0xffffdeb1
 *   @0x2f62ac svcmi #0xf0e92d
 *   @0x2f62b0 stmvs r3, {r2, r3, r4, r7, r9, r10, lr} ^
 *   @0x2f62b4 stcne p0, c11, [sp], {137}
 *   @0x2f62b8 addsmi r4, r5, #4, #12
 *   @0x2f62bc rfeia r3!
 *   @0x2f62c0 rfeia r3!
 *   @0x2f62c4 strls r10, [r5, -r6]
 *   @0x2f62c8 rfeia r3!
 *   @0x2f62cc rfeia r3!
 *   @0x2f62d0 strls r8, [r6, -lr]
 *   @0x2f62d4 stmdavc r11, {r0, r1, r2, r3, r6, r11, r12, lr, pc}
 *   @0x2f62d8 b 0x14d441c <b2_toiTime+0xd7af78>
 *   @0x2f62dc strls r2, [r3, -r3, lsl #14]
 *   @0x2f62e0 orreq lr, r7, #5120
 *   @0x2f62e4 movtle r4, #0x629a
 *   @0x2f62e8 .word 0x26009b13
 *   @0x2f62ec movwls r3, #0x7301
 *   @0x2f62f0 adcsmi r9, lr, #3, #30
 *   @0x2f62f4 svcls #0x7d21b
 *   @0x2f62f8 .word 0xf8952000
 *   @0x2f62fc strlo lr, [r4, #-0x0]
 *   @0x2f6300 .word 0x1c03f815
 *   @0x2f6304 .word 0x2c02f815
 *   @0x2f6308 .word 0x3c01f815
 *   @0x2f630c .word 0x210eea41
 *   @0x2f6310 strbtmi r9, [r2], #-1792
 *   @0x2f6314 andls r9, r1, r2, lsl pc
 *   @0x2f6318 ldrtmi r4, [r11], #-1568
 *   @0x2f631c andsgt pc, r0, sp, asr #17
 *   @0x2f6320 ldc2l p7, c15, [r4, #-1020]
 *   @0x2f6324 ldrsbgt pc, [r0], -sp
 *   @0x2f6328 .word 0x3601b910
 *   @0x2f632c andhs lr, r0, r0, ror #15
 *   @0x2f6330 blx 0x16d06c4 <b2_toiTime+0xf77220>
 *   @0x2f6334 svcls #0x5fb8b
 *   @0x2f6338 blx 0xfe5b4c7c <b2_toiTime+0xfffffffffde5b7d8>
 *   @0x2f633c andlt pc, r4, r3, lsr #17
 *   @0x2f6340 rscslt r6, r10, #14876672
 *   @0x2f6344 .word 0xf8a39f06
 *   @0x2f6348 stmvs r3!, {r1, r2, sp, pc} ^
 *   @0x2f634c rsbslt r8, r10, #-2147483642
 *   @0x2f6350 cmphi r10, r3, ror #17
 *   @0x2f6354 .word 0xf289fa4f
 *   @0x2f6358 orrshi r6, r10, r3, ror #17
 *   @0x2f635c .word 0xf288fa5f
 *   @0x2f6360 bicshi r6, r10, r3, ror #17
 *   @0x2f6364 stmvs r3!, {r1, r5, r7, r11, sp, lr} ^
 *   @0x2f6368 subshi r7, r10, r2, lsl r9
 *   @0x2f636c stmvs r3!, {r1, r5, r7, r11, sp, lr} ^
 *   @0x2f6370 andshi r7, r10, r2, lsl r8
 *   @0x2f6374 andhs lr, r3, r0
 *   @0x2f6378 pop {r0, r3, r12, sp, pc}
 *   @0x2f637c strdeq r8, r9, [r0], -r0
 *   @0x2f6380 sbcslt r11, r6, r0, lsl r5
 *   @0x2f6384 ldrsbne pc, [r12, #128]!
 *   @0x2f6388 andls r10, r2, r7, lsl #22
 *   @0x2f638c andhs pc, r0, #208, #16
 *   @0x2f6390 andsvs r9, r9, r3, lsl #2
 *   @0x2f6394 stmdblt r9, {r0, r3, r4, r11, sp, lr}
 *   @0x2f6398 adcs r2, r0, r8
 *   @0x2f639c ldrmi r9, [r1], #-2307
 *   @0x2f63a0 .word 0x9104681a
 *   @0x2f63a4 addsmi r3, r1, #4, #4
 *   @0x2f63a8 ldmdavs r10, {r1, r2, r4, r5, r6, r7, r8, r9, r12, lr, pc}
 *   @0x2f63ac andsvs r3, r10, r2, lsl #4
 *   @0x2f63b0 ldmdavs r10, {r0, r3, r4, r11, sp, lr}
 *   @0x2f63b4 .word 0x1c02f811
 *   @0x2f63b8 .word 0x2c01f812
 *   @0x2f63bc andhs lr, r1, #335872
 *   @0x2f63c0 ldmdavs r10, {r1, r3, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2f63c4 andsvs r3, r10, r2, lsl #4
 *   @0x2f63c8 ldmdavs r11, {r1, r3, r4, r11, sp, lr}
 *   @0x2f63cc .word 0x2c02f812
 *   @0x2f63d0 .word 0x3c01f813
 *   @0x2f63d4 andhs lr, r2, #274432
 *   @0x2f63d8 andls r4, r6, #75776
 *   @0x2f63dc ldrbtmi r10, [r11], #-2570
 *   @0x2f63e0 movwls r9, #0x5201
 *   @0x2f63e4 stmdahs r0, {r1, r2, r11, r12, pc}
 *   @0x2f63e8 addhi pc, r9, r0
 *   @0x2f63ec ldmdavs r10, {r0, r1, r2, r8, r9, r11, sp, pc}
 *   @0x2f63f0 andlo r9, r8, #4, #18
 *   @0x2f63f4 .word 0xf0c04291
 *   @0x2f63f8 ldmdavs r10, {r0, r7, pc}
 *   @0x2f63fc andsvs r3, r10, r2, lsl #4
 *   @0x2f6400 ldmdavs r10, {r0, r3, r4, r11, sp, lr}
 *   @0x2f6404 .word 0x1c02f811
 *   @0x2f6408 .word 0x2c01f812
 *   @0x2f640c .word 0x2101ea42
 *   @0x2f6410 subne pc, r0, sp, lsr #17
 *   @0x2f6414 .word 0x31026819
 *   @0x2f6418 ldmdavs r8, {r0, r3, r4, sp, lr}
 *   @0x2f641c ldmdavs r10, {r0, r3, r4, r11, sp, lr}
 *   @0x2f6420 .word 0x0c02f810
 *   @0x2f6424 .word 0x1c01f811
 *   @0x2f6428 andsvs r3, r10, r4, lsl #4
 *   @0x2f642c .word 0x2100ea41
 *   @0x2f6430 .word 0xf8ad6818
 *   @0x2f6434 ldmdavs r12, {r1, r6, r12}
 *   @0x2f6438 ldmdavs r10, {r1, r8, r11, r12, pc}
 *   @0x2f643c .word 0x2100910e
 *   @0x2f6440 ldmdavs r9, {r0, r1, r2, r3, r8, r12, pc}
 *   @0x2f6444 .word 0x3c03f814
 *   @0x2f6448 .word 0x0c04f810
 *   @0x2f644c .word 0x1c01f811
 *   @0x2f6450 .word 0xf812041b
 *   @0x2f6454 b 0x13c1464 <b2_toiTime+0xc67fc0>
 *   @0x2f6458 movwmi r6, #0xb300
 *   @0x2f645c movwhs lr, #0x2a53
 *   @0x2f6460 stmdbls r2, {r3, r6, r12, lr, pc}
 *   @0x2f6464 andhs pc, r0, #13697024
 *   @0x2f6468 addsmi r3, r3, #8192
 *   @0x2f646c bls 0x3ec57c <_ZTI15b2RevoluteJoint+0xc>
 *   @0x2f6470 andls r4, r8, #436207616
 *   @0x2f6474 blls 0x51cc9c <SrcVerts+0x79ce0>
 *   @0x2f6478 ldmdavc r11, {r1, r4, r11, r12, sp, lr} ^
 *   @0x2f647c movwhs lr, #0x2a43
 *   @0x2f6480 andsvs r10, r3, r9, lsl #20
 *   @0x2f6484 movwls r9, #0xab05
 *   @0x2f6488 stmdbls r10, {r0, r1, r3, r8, r9, r11, sp, pc}
 *   @0x2f648c stmdbhs r0, {r0, r3, r11, sp, lr}
 *   @0x2f6490 stmdbls r10, {r0, r1, r2, r3, r5, r12, lr, pc}
 *   @0x2f6494 andsvs r6, r9, r9, lsl #16
 *   @0x2f6498 ldmdavs r1, {r3, r4, r11, sp, lr}
 *   @0x2f649c addmi r6, r8, #128, #20
 *   @0x2f64a0 .word 0xac11d123
 *   @0x2f64a4 movwls r2, #0xc300
 *   @0x2f64a8 strtmi r9, [r0], -r8, lsl #18
 *   @0x2f64ac .word 0xf7ee9a04
 *   @0x2f64b0 stmdbls r2, {r0, r1, r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f64b4 rfeia r1!
 *   @0x2f64b8 cmpls r5, #8, #2
 *   @0x2f64bc b 0xbb3bc4 <b2_toiTime+0x45a720>
 *   @0x2f64c0 blls 0x5e4968 <g_SWFaavertbuff+0x118a0>
 *   @0x2f64c4 stmdals r8, {r0, r4, r8, r11, sp, pc}
 *   @0x2f64c8 .word 0x47986adb
 *   @0x2f64cc blls 0x181a504 <b2_toiTime+0x10c1060>
 *   @0x2f64d0 .word 0xac0db97b
 *   @0x2f64d4 bge 0x69c508 <g_SWFlinevertbuff+0x49440>
 *   @0x2f64d8 strtmi r9, [r3], -r8, lsl #18
 *   @0x2f64dc .word 0xff4bf7f1
 *   @0x2f64e0 bls 0x6249c8 <g_SWFaavertbuff+0x51900>
 *   @0x2f64e4 cmpvs r10, r3, lsr #16
 *   @0x2f64e8 stmdbls r10, {r0, r1, sp, lr, pc}
 *   @0x2f64ec .word 0x910a3104
 *   @0x2f64f0 blls 0x5b0424 <g_SWFlineaavertbuff+0x5d35c>
 *   @0x2f64f4 blo 0x35cd14 <_ZTS7CFontGM+0x3dc>
 *   @0x2f64f8 ldrb r9, [r3, -r6, lsl #4]!
 *   @0x2f64fc subslt r2, r6, r0
 *   @0x2f6500 svclt #0xbd10
 *   @0x2f6504 andeq r6, pc, lr, ror #10
 *   @0x2f6508 svcmi #0xf0e92d
 *   @0x2f650c .word 0xf8d12200
 *   @0x2f6510 addslt r5, r3, r12, lsl r2
 *   @0x2f6514 .word 0x46064f94
 *   @0x2f6518 rsb pc, r4, #14614528
 *   @0x2f651c ldrmi r4, [r0], r12, lsl #12
 *   @0x2f6520 addsmi r4, r10, #152043520
 *   @0x2f6524 ldmdals r12, {r0, r2, r3, r9, r11, r12, lr, pc}
 *   @0x2f6528 eorsne pc, r2, r0, asr r8
 *   @0x2f652c strhle r4, [r4], -r9
 *   @0x2f6530 svclt #0x84571
 *   @0x2f6534 stmdaeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f6538 .word 0xf04fe001
 *   @0x2f653c andlo r0, r1, #16384
 *   @0x2f6540 .word 0xf8d4e7ef
 *   @0x2f6544 blvs 0x19c274c <b2_toiTime+0x12692a8>
 *   @0x2f6548 qadd8mi r11, r0, r11
 *   @0x2f654c .word 0xf7fd4987
 *   @0x2f6550 ldmdblt r0!, {r0, r1, r3, r4, r5, r6, r8, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f6554 stmibmi r6, {r5, r9, r10, lr}
 *   @0x2f6558 ldc2l p7, c15, [r6, #-1012]!
 *   @0x2f655c strtmi r11, [r0], -r8, asr #18
 *   @0x2f6560 .word 0xf7fd4984
 *   @0x2f6564 .word 0xf110fd71
 *   @0x2f6568 svclt #0x180a00
 *   @0x2f656c beq 0x3726b0 <_ZTS13C_UTF16String+0x975c>
 *   @0x2f6570 .word 0xf04fe001
 *   @0x2f6574 .word 0xf8d40a01
 *   @0x2f6578 strtmi r7, [r0], -r4, lsl #4
 *   @0x2f657c shsub16mi r4, r2, lr
 *   @0x2f6580 ldrmi r2, [r8, r0, lsl #6]!
 *   @0x2f6584 .word 0x0701f1d0
 *   @0x2f6588 smladxhs r0, r8, pc, r11
 *   @0x2f658c .word 0xf1bab91f
 *   @0x2f6590 .word 0xf0400f00
 *   @0x2f6594 stclvs p2, c8, [r11], #-716
 *   @0x2f6598 .word 0xf0002b00
 *   @0x2f659c .word 0x462082b1
 *   @0x2f65a0 .word 0x47984631
 *   @0x2f65a4 stmdblt r0!, {r1, r3, r12, pc}
 *   @0x2f65a8 bleq 0x3726ec <_ZTS13C_UTF16String+0x9798>
 *   @0x2f65ac strmi r11, [r7], -r7, ror #2
 *   @0x2f65b0 .word 0xf04fe002
 *   @0x2f65b4 ldrbmi r0, [pc], -r0, lsl #22
 *   @0x2f65b8 strtmi r6, [r0], -r11, lsr #19
 *   @0x2f65bc .word 0x47984631
 *   @0x2f65c0 stmdahs r0, {r1, r3, r12, pc}
 *   @0x2f65c4 addshi pc, r6, #64
 *   @0x2f65c8 ldrhtlo pc, [r2], r4
 *   @0x2f65cc movwhs r11, #0x8913
 *   @0x2f65d0 add r9, pc, #671088640
 *   @0x2f65d4 ldrtmi r6, [r1], -r11, ror #20
 *   @0x2f65d8 ldrmi r4, [r8, r0, lsr #12]
 *   @0x2f65dc ldrtmi r6, [r1], -r11, lsr #20
 *   @0x2f65e0 strtmi r9, [r0], -r10
 *   @0x2f65e4 blvs 0xdc844c <b2_toiTime+0x66efa8>
 *   @0x2f65e8 andls r4, r10, r1, lsr r6
 *   @0x2f65ec ldrmi r4, [r8, r0, lsr #12]
 *   @0x2f65f0 ldrtmi r6, [r1], -r11, ror #21
 *   @0x2f65f4 strtmi r9, [r0], -r10
 *   @0x2f65f8 pkhbtmi r4, r2, r8, lsl #15
 *   @0x2f65fc .word 0xf1bb900a
 *   @0x2f6600 cmple r0, r0, lsl #30
 *   @0x2f6604 strtmi r6, [r0], -r11, ror #19
 *   @0x2f6608 uasxmi r4, r10, r1
 *   @0x2f660c mulls r10, r8, r7
 *   @0x2f6610 stclvs p9, c11, [r11, #352]!
 *   @0x2f6614 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2f6618 .word 0x4798465a
 *   @0x2f661c blhs 0xfe6a3130 <b2_toiTime+0xfffffffffdf49c8c>
 *   @0x2f6620 andls sp, r10, r1
 *   @0x2f6624 orrshs lr, r3, #26
 *   @0x2f6628 sbclt lr, r0, #12
 *   @0x2f662c tstle r5, lr, lsl #17
 *   @0x2f6630 ldrsblo pc, [r4], r4
 *   @0x2f6634 addsmi r4, r3, #331776
 *   @0x2f6638 .word 0xf8cdd103
 *   @0x2f663c ldrbmi r11, [pc], -r8, lsr #32
 *   @0x2f6640 orrhs lr, pc, #12
 *   @0x2f6644 .word 0xf8d4930a
 *   @0x2f6648 blvs 0x19c2850 <b2_toiTime+0x12693ac>
 *   @0x2f664c ldmdavs r11, {r0, r1, r4, r5, r8, r12, sp, pc}
 *   @0x2f6650 .word 0xb11b689b
 *   @0x2f6654 rscslt pc, r10, r4, lsr #17
 *   @0x2f6658 eorlt pc, r8, sp, asr #17
 *   @0x2f665c blhs 0x31d28c
 *   @0x2f6660 subhi pc, r8, #64
 *   @0x2f6664 strtmi r6, [r0], -r11, ror #19
 *   @0x2f6668 andhs r4, r1, #51380224
 *   @0x2f666c mulls r10, r8, r7
 *   @0x2f6670 stclvs p9, c11, [r11, #288]!
 *   @0x2f6674 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2f6678 ldrmi r2, [r8, r1, lsl #4]
 *   @0x2f667c ldmdblt r0, {r1, r3, r12, pc}
 *   @0x2f6680 .word 0xf8842301
 *   @0x2f6684 blls 0x582b1c <g_SWFlineaavertbuff+0x2fa54>
 *   @0x2f6688 sbcslt r11, r11, #-1073741818
 *   @0x2f668c .word 0xf0402b8e
 *   @0x2f6690 bvs 0xfedd6f5c <b2_toiTime+0xfffffffffe67dab8>
 *   @0x2f6694 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2f6698 mulls r10, r8, r7
 *   @0x2f669c .word 0xf64fb118
 *   @0x2f66a0 .word 0xf8a473ff
 *   @0x2f66a4 mcrvs p1, #0x1, r3, c11, c4, #0x3
 *   @0x2f66a8 qadd16mi r11, r0, r11
 *   @0x2f66ac .word 0x47984631
 *   @0x2f66b0 stcvs p0, c9, [r11], #-40
 *   @0x2f66b4 qasxmi r4, r0, r1
 *   @0x2f66b8 blvs 0xffdc8520 <b2_toiTime+0xffffffffff66f07c>
 *   @0x2f66bc andls r4, r10, r1, lsr r6
 *   @0x2f66c0 ldrmi r4, [r8, r0, lsr #12]
 *   @0x2f66c4 ldrtmi r6, [r1], -r11, lsr #23
 *   @0x2f66c8 strtmi r9, [r0], -r10
 *   @0x2f66cc rfeia r4!
 *   @0x2f66d0 rfeia r4!
 *   @0x2f66d4 .word 0x61232174
 *   @0x2f66d8 .word 0x61632300
 *   @0x2f66dc .word 0xf64f61a3
 *   @0x2f66e0 addsmi r7, r10, #-67108861
 *   @0x2f66e4 suble r9, sp, r10
 *   @0x2f66e8 ldrhlo pc, [r4, r4]!
 *   @0x2f66ec strble r0, [r9, #-0x5da]
 *   @0x2f66f0 svceq #0xf1b9
 *   @0x2f66f4 stmdbvs r3!, {r1, r12, lr, pc} ^
 *   @0x2f66f8 and r11, r9, r3, lsr #19
 *   @0x2f66fc tsths r0, r0, lsr #12
 *   @0x2f6700 andseq pc, r4, #4, #2
 *   @0x2f6704 blx 0xfe6b4706 <b2_toiTime+0xfffffffffdf5b262>
 *   @0x2f6708 stmdahs r0, {r1, r3, r12, pc}
 *   @0x2f670c ldrsh sp, [r1, #3]!
 *   @0x2f6710 .word 0x21014620
 *   @0x2f6714 andseq pc, r4, #4, #2
 *   @0x2f6718 blx 0xfe43471a <b2_toiTime+0xfffffffffdcdb276>
 *   @0x2f671c stmdahs r0, {r1, r3, r12, pc}
 *   @0x2f6720 mvnhi pc, r0, asr #32
 *   @0x2f6724 svceq #0xf1b8
 *   @0x2f6728 strtmi sp, [r0], -r9, lsl #2
 *   @0x2f672c .word 0xf1042111
 *   @0x2f6730 .word 0xf7fe0218
 *   @0x2f6734 andls pc, r10, r7, ror r11
 *   @0x2f6738 .word 0xf0402800
 *   @0x2f673c stmibvs r3!, {r0, r1, r3, r4, r6, r7, r8, pc}
 *   @0x2f6740 .word 0xf104b94b
 *   @0x2f6744 qadd16mi r0, r0, r8
 *   @0x2f6748 .word 0xf7fe2102
 *   @0x2f674c andls pc, r10, r11, ror #22
 *   @0x2f6750 .word 0xf0402800
 *   @0x2f6754 .word 0xf8d481cf
 *   @0x2f6758 stmvs r3!, {r3, r4, r5, r6, r7, r9, sp}
 *   @0x2f675c bhs 0x344f6c
 *   @0x2f6760 vst2.16 {d29, d30}, [r3:64], r5
 *   @0x2f6764 subs r4, r2, r0, lsl #7
 *   @0x2f6768 stmdbvs r7!, {r1, r2, r5, r6, r12, sp, lr} ^
 *   @0x2f676c strbvs r7, [r12, -r6, ror #18]!
 *   @0x2f6770 movtmi r4, #0x6620
 *   @0x2f6774 movtmi r4, #0x6632
 *   @0x2f6778 .word 0x73626978
 *   @0x2f677c ldrbtvc r7, [r2], #-1381
 *   @0x2f6780 stmdbvs r7!, {r0, r1, r4, r5, r6, r12, sp, lr} ^
 *   @0x2f6784 ldreq pc, [r4], -r4, lsl #2
 *   @0x2f6788 tsths r5, r0, lsr #12
 *   @0x2f678c .word 0xf7fe4632
 *   @0x2f6790 andls pc, r10, r9, asr #22
 *   @0x2f6794 .word 0xf0402800
 *   @0x2f6798 stmdbvs r3!, {r0, r2, r3, r5, r7, r8, pc} ^
 *   @0x2f679c stmdbvs r3!, {r0, r1, r4, r8, r12, sp, pc} ^
 *   @0x2f67a0 and r11, r11, r11, lsr #19
 *   @0x2f67a4 svceq #0xf1b9
 *   @0x2f67a8 qsub8mi sp, r0, r9
 *   @0x2f67ac shadd16mi r2, r2, r0
 *   @0x2f67b0 blx 0x11347b2 <b2_toiTime+0x9db30e>
 *   @0x2f67b4 stmdahs r0, {r1, r3, r12, pc}
 *   @0x2f67b8 ldrsh sp, [r11, r1]
 *   @0x2f67bc .word 0x21014620
 *   @0x2f67c0 .word 0xf7fe4632
 *   @0x2f67c4 andls pc, r10, pc, lsr #22
 *   @0x2f67c8 .word 0xf0402800
 *   @0x2f67cc .word 0xf1048193
 *   @0x2f67d0 qadd16mi r0, r0, r8
 *   @0x2f67d4 shadd16mi r2, r2, r6
 *   @0x2f67d8 blx 0xc347da <b2_toiTime+0x4db336>
 *   @0x2f67dc stmdahs r0, {r1, r3, r12, pc}
 *   @0x2f67e0 orrhi pc, r8, r0, asr #32
 *   @0x2f67e4 teqlt r3, r3, lsr #19
 *   @0x2f67e8 blhs 0x310e7c <af_shaper_get_elem+0x66ea>
 *   @0x2f67ec .word 0x4620d1b3
 *   @0x2f67f0 ldrtmi r2, [r2], -r2, lsl #2
 *   @0x2f67f4 .word 0xf1b8e7a9
 *   @0x2f67f8 mvnsle r0, r0, lsl #30
 *   @0x2f67fc tsths r1, r0, lsr #12
 *   @0x2f6800 .word 0xf7fe4632
 *   @0x2f6804 andls pc, r10, pc, lsl #22
 *   @0x2f6808 rscle r2, sp, r0, lsl #16
 *   @0x2f680c svchs #0x1e172
 *   @0x2f6810 .word 0xf043bf08
 *   @0x2f6814 .word 0xf0430301
 *   @0x2f6818 .word 0xf1ba0618
 *   @0x2f681c .word 0xd1060f00
 *   @0x2f6820 ldrsbhs pc, [r12, #132]
 *   @0x2f6824 svclo #0x40f5b2
 *   @0x2f6828 .word 0xf443bf18
 *   @0x2f682c .word 0xf8d47606
 *   @0x2f6830 smlattlt r11, r8, r1, r3
 *   @0x2f6834 streq pc, [r4], -r6, asr #32
 *   @0x2f6838 .word 0x3124f894
 *   @0x2f683c .word 0xf046b10b
 *   @0x2f6840 .word 0xf8d40620
 *   @0x2f6844 .word 0xb10b3310
 *   @0x2f6848 strbeq pc, [r0], -r6, asr #32
 *   @0x2f684c sbclo pc, r0, #212, #16
 *   @0x2f6850 ldrle r0, [r2, #-0x7db]
 *   @0x2f6854 stmibmi r12!, {r5, r9, r10, lr}
 *   @0x2f6858 blx 0xb4856
 *   @0x2f685c qasxmi r11, r0, r0
 *   @0x2f6860 .word 0xf7fd49aa
 *   @0x2f6864 .word 0xb108fbf1
 *   @0x2f6868 strvc pc, [r0], r6, asr #8
 *   @0x2f686c stmibmi r8!, {r5, r9, r10, lr}
 *   @0x2f6870 blx 0xffdb486e <b2_toiTime+0xffffffffff65b3ca>
 *   @0x2f6874 vst4.8 {d27, d29, d31, d1}, [r6], r8
 *   @0x2f6878 svchs #0x17680
 *   @0x2f687c tstle r2, r6, lsr #1
 *   @0x2f6880 ldrhlo pc, [r4, #-132]!
 *   @0x2f6884 mvnsvc pc, pc, asr #12
 *   @0x2f6888 andle r4, r12, r11, lsl #5
 *   @0x2f688c ldrhhs pc, [r4, r4]!
 *   @0x2f6890 movwhs pc, #0x1240
 *   @0x2f6894 movwlo r4, #0x13
 *   @0x2f6898 movwhs r11, #0x1f18
 *   @0x2f689c strle r0, [sp, #-0x690]
 *   @0x2f68a0 movweq pc, #0x2043
 *   @0x2f68a4 rfeia r4!
 *   @0x2f68a8 .word 0xf01220cc
 *   @0x2f68ac svclt #0x140f01
 *   @0x2f68b0 movwhs r2, #0x302
 *   @0x2f68b4 svclt #0x480791
 *   @0x2f68b8 movweq pc, #0x1043
 *   @0x2f68bc qadd8mi r4, r0, r5
 *   @0x2f68c0 cdpmi p8, #0x9, c6, c5, c2, #0x7
 *   @0x2f68c4 tstmi r3, #2130706432
 *   @0x2f68c8 strvc pc, [r2, -r7, lsl #10]
 *   @0x2f68cc ldrbtmi r6, [lr], #-227
 *   @0x2f68d0 ldc2l p7, c15, [r6, #-1020]
 *   @0x2f68d4 bvs 0x1bbf0dc <b2_toiTime+0x1465c38>
 *   @0x2f68d8 ble 0xb47348 <b2_toiTime+0x3edea4>
 *   @0x2f68dc .word 0xf8536aa3
 *   @0x2f68e0 .word 0xf5061022
 *   @0x2f68e4 rfeia r1!
 *   @0x2f68e8 rfeia r1!
 *   @0x2f68ec .word 0xf853800a
 *   @0x2f68f0 .word 0xf1a30c0c
 *   @0x2f68f4 strbmi r0, [r0, #-0x90c]!
 *   @0x2f68f8 .word 0xf853d108
 *   @0x2f68fc strbmi r0, [r0, #-0xc08]
 *   @0x2f6900 .word 0xf8d9d102
 *   @0x2f6904 and r3, r8, r8
 *   @0x2f6908 rscsle r3, r10, r1
 *   @0x2f690c .word 0xf10342bb
 *   @0x2f6910 andle r0, r1, #12
 *   @0x2f6914 strb r4, [r10, r3, lsl #12]!
 *   @0x2f6918 subvs r2, r11, r0, lsl #6
 *   @0x2f691c ldrb r3, [r10, r1, lsl #4]
 *   @0x2f6920 rscshi pc, r12, #212, #16
 *   @0x2f6924 svceq #0xf1b8
 *   @0x2f6928 mcrvs p0, #0x5, sp, c3, c11, #0x3
 *   @0x2f692c ldrhtvc pc, [r2], r4
 *   @0x2f6930 ldrhge pc, [r6, #-132]!
 *   @0x2f6934 ldrsbls pc, [r12], -r3
 *   @0x2f6938 rfeia r4!
 *   @0x2f693c .word 0xf64f3174
 *   @0x2f6940 addsmi r7, r3, #-268435441
 *   @0x2f6944 .word 0xf04fd102
 *   @0x2f6948 ldrbmi r0, [r7], -r1, lsl #20
 *   @0x2f694c blge 0x57f154 <g_SWFlineaavertbuff+0x2c08c>
 *   @0x2f6950 strbmi r9, [r8], -r0, lsl #4
 *   @0x2f6954 tsths r0, r5, lsl #6
 *   @0x2f6958 strbmi r9, [r3], -r1, lsl #6
 *   @0x2f695c blx 0xfe8f492a <b2_toiTime+0xfffffffffe19b486>
 *   @0x2f6960 eorvs r9, r0, #40960
 *   @0x2f6964 .word 0xf0402a00
 *   @0x2f6968 stmdage r10, {r0, r2, r6, r7, pc}
 *   @0x2f696c andls r9, r1, r0, lsl #4
 *   @0x2f6970 strbmi r2, [r8], -r4, lsl #2
 *   @0x2f6974 .word 0xf7f14643
 *   @0x2f6978 vmlals.f64 d15, d26, d10
 *   @0x2f697c cdphs p0, #0x0, c9, c0, c6, #0x0
 *   @0x2f6980 adcshi pc, r8, r0, asr #32
 *   @0x2f6984 ldmdaeq r11!, {r0, r1, r4, r5, r7, r9, r10, lr} ^
 *   @0x2f6988 blx 0xfe5b51cc <b2_toiTime+0xfffffffffde5bd28>
 *   @0x2f698c .word 0xf8cd9307
 *   @0x2f6990 blge 0x5dea28 <g_SWFaavertbuff+0xb960>
 *   @0x2f6994 .word 0xf8d49308
 *   @0x2f6998 strtmi r12, [r0], -r0, lsr #32
 *   @0x2f699c ldrbmi r6, [r9], -r11, ror #29
 *   @0x2f69a0 .word 0xf8cdaa0b
 *   @0x2f69a4 .word 0x4798c010
 *   @0x2f69a8 ldrsbgt pc, [r0], -sp
 *   @0x2f69ac bllt 0x71a9dc <g_SWFvertbuff+0x47914>
 *   @0x2f69b0 teqeq r2, r0, lsl r9
 *   @0x2f69b4 movweq lr, #0x2b0c
 *   @0x2f69b8 .word 0xe024f8dd
 *   @0x2f69bc .word 0xf82c1189
 *   @0x2f69c0 stmdbls r7, {r1, r12}
 *   @0x2f69c4 .word 0x202cf8bd
 *   @0x2f69c8 blx 0x39b5e2 <ft_adobe_glyph_list+0xacbe>
 *   @0x2f69cc ldrtmi r1, [r9], -lr
 *   @0x2f69d0 .word 0xf0229203
 *   @0x2f69d4 blls 0x431054 <g_RomDisk+0x39834>
 *   @0x2f69d8 bls 0x3d6b40 <error_g0017+0x2f7e4>
 *   @0x2f69dc .word 0x102ef8bd
 *   @0x2f69e0 umullsvs r0, r10, r2, r1
 *   @0x2f69e4 sbcsvs r0, r9, r9, lsl #3
 *   @0x2f69e8 qsublt r6, r9, r2
 *   @0x2f69ec blls 0x4a2e58 <g_SrcBlend+0xa58>
 *   @0x2f69f0 eorlt pc, r6, r3, asr #16
 *   @0x2f69f4 .word 0xf10b3601
 *   @0x2f69f8 strbmi r0, [r3, #0xb01]
 *   @0x2f69fc blls 0x4ab130 <SrcVerts+0x8174>
 *   @0x2f6a00 .word 0x2104a80a
 *   @0x2f6a04 ldrbmi r9, [r10], -r1
 *   @0x2f6a08 movwls r4, #0x648
 *   @0x2f6a0c .word 0xf7f14633
 *   @0x2f6a10 teqlt r6, lr, lsr r11
 *   @0x2f6a14 .word 0xf8c468a3
 *   @0x2f6a18 .word 0xf0430300
 *   @0x2f6a1c mvnvs r0, r2, lsl #6
 *   @0x2f6a20 stmvs r3!, {r0, r1, r5, r7, sp, lr}
 *   @0x2f6a24 svclt #0x4079a
 *   @0x2f6a28 movweq pc, #0x1043
 *   @0x2f6a2c stmvs r3!, {r0, r1, r5, r7, sp, lr}
 *   @0x2f6a30 ldrble r0, [pc, #-0x7db]
 *   @0x2f6a34 strhlo pc, [r4], #148
 *   @0x2f6a38 ldrhhs pc, [r12], #132
 *   @0x2f6a3c strhtne pc, [r0], #132
 *   @0x2f6a40 rfeib r4!
 *   @0x2f6a44 ldrmi r3, [r1], #-198
 *   @0x2f6a48 subhs pc, r6, r4, lsr #17
 *   @0x2f6a4c rfeib r4!
 *   @0x2f6a50 .word 0x63e330c8
 *   @0x2f6a54 strhlo pc, [r10], #148
 *   @0x2f6a58 rfeia r4!
 *   @0x2f6a5c .word 0xf8a430b2
 *   @0x2f6a60 rfeia r4!
 *   @0x2f6a64 bne 0xff542de4 <b2_toiTime+0xfffffffffede9940>
 *   @0x2f6a68 subne pc, r10, r4, lsr #17
 *   @0x2f6a6c sublo pc, r8, r4, lsr #17
 *   @0x2f6a70 bllt 0xbe5720 <b2_toiTime+0x48c27c>
 *   @0x2f6a74 ldrhlo pc, [r4, #-132]!
 *   @0x2f6a78 mvnsvc pc, pc, asr #12
 *   @0x2f6a7c andsle r4, lr, r11, lsl #5
 *   @0x2f6a80 ldrhlo pc, [r10, r4]!
 *   @0x2f6a84 rfeib r4!
 *   @0x2f6a88 strhlt r2, [r2, #-28]!
 *   @0x2f6a8c ldrhhs pc, [r12, r4]!
 *   @0x2f6a90 ldrhne pc, [lr, r4]!
 *   @0x2f6a94 sublo pc, r6, r4, lsr #17
 *   @0x2f6a98 .word 0xf8a4440b
 *   @0x2f6a9c bne 0xfe97ebc4 <b2_toiTime+0xfffffffffe225720>
 *   @0x2f6aa0 subhs pc, r10, r4, lsr #17
 *   @0x2f6aa4 rfeia r4!
 *   @0x2f6aa8 rfeia r4!
 *   @0x2f6aac .word 0xf8a421c2
 *   @0x2f6ab0 subsmi r3, r1, #70
 *   @0x2f6ab4 .word 0xf8a44413
 *   @0x2f6ab8 .word 0xf8a41048
 *   @0x2f6abc rfeia r4!
 *   @0x2f6ac0 .word 0xf8a430e2
 *   @0x2f6ac4 .word 0xf894304c
 *   @0x2f6ac8 tstlt r3, r4, lsr #2
 *   @0x2f6acc ldrhlo pc, [r2, -r4]!
 *   @0x2f6ad0 rfeia r4!
 *   @0x2f6ad4 .word 0xf8a4304a
 *   @0x2f6ad8 rfeia r4!
 *   @0x2f6adc rfeia r4!
 *   @0x2f6ae0 andslt r1, r10, #228, #2
 *   @0x2f6ae4 subslo pc, r2, r4, lsr #17
 *   @0x2f6ae8 sbcsvc lr, r2, #2048
 *   @0x2f6aec rsbeq lr, r2, #164864
 *   @0x2f6af0 subshs pc, r0, r4, lsr #17
 *   @0x2f6af4 andslt r9, r3, r10, lsl #16
 *   @0x2f6af8 svchi #0xf0e8bd
 *   @0x2f6afc and r2, r0, r1, lsl #14
 *   @0x2f6b00 .word 0xf04f461f
 *   @0x2f6b04 ldrb r0, [r7, #-0xb00]
 *   @0x2f6b08 strbvs r7, [r12, -r6, ror #18]!
 *   @0x2f6b0c .word 0x67766172
 *   @0x2f6b10 movtmi r4, #0x6632
 *   @0x2f6b14 muleq r10, r12, r2
 *   @0x2f6b18 muleq r10, r2, r2
 *   @0x2f6b1c svcmi #0xf0e92d
 *   @0x2f6b20 cdpvs p6, #0x0, c4, c11, c4, #0x0
 *   @0x2f6b24 .word 0xf8d1b09d
 *   @0x2f6b28 pkhbtmi r0, r11, r12, lsl #4
 *   @0x2f6b2c ldmdavs sp, {r0, r3, r9, r12, pc} ^
 *   @0x2f6b30 stmdblt r8!, {r1, r2, r12, pc} ^
 *   @0x2f6b34 .word 0x462849d5
 *   @0x2f6b38 .word 0xf7ef4479
 *   @0x2f6b3c .word 0x9006f9f5
 *   @0x2f6b40 .word 0xf0002800
 *   @0x2f6b44 .word 0xf8cb8422
 *   @0x2f6b48 stmdavs r3, {r2, r3, r4, r9}
 *   @0x2f6b4c andlo pc, r4, #13303808
 *   @0x2f6b50 andhs r4, r1, #3391488
 *   @0x2f6b54 .word 0x0060f8db
 *   @0x2f6b58 .word 0xf7ef4479
 *   @0x2f6b5c .word 0xf8dbf9ec
 *   @0x2f6b60 .word 0xf8cb6224
 *   @0x2f6b64 ldmdblt lr, {r5, r9} ^
 *   @0x2f6b68 strtmi r4, [r8], -r10, asr #19
 *   @0x2f6b6c .word 0xf7ef4479
 *   @0x2f6b70 stmibmi r9, {r0, r1, r2, r3, r4, r5, r7, r8, r11, r12, sp, lr, pc} ^
 *   @0x2f6b74 ldrbtmi r4, [r9], #-1586
 *   @0x2f6b78 .word 0xf9ddf7ef
 *   @0x2f6b7c eoreq pc, r4, #13303808
 *   @0x2f6b80 eorvs pc, r8, #14352384
 *   @0x2f6b84 stmibmi r5, {r1, r2, r3, r4, r6, r8, r11, r12, sp, pc} ^
 *   @0x2f6b88 ldrbtmi r4, [r9], #-1576
 *   @0x2f6b8c rfeib r0!
 *   @0x2f6b90 ldrtmi r4, [r2], -r3, asr #19
 *   @0x2f6b94 .word 0xf7ef4479
 *   @0x2f6b98 .word 0xf8cbf9ce
 *   @0x2f6b9c stmibvs r1!, {r3, r5, r9} ^
 *   @0x2f6ba0 .word 0xf8cb2300
 *   @0x2f6ba4 .word 0xf8cb3084
 *   @0x2f6ba8 .word 0xf8cb3088
 *   @0x2f6bac blmi 0xff242de4 <b2_toiTime+0xfffffffffeae9940>
 *   @0x2f6bb0 rscshi pc, r4, #14614528
 *   @0x2f6bb4 .word 0x910a447b
 *   @0x2f6bb8 movwvc pc, #0x2503
 *   @0x2f6bbc movwls r4, #0xc4f8
 *   @0x2f6bc0 eorshi pc, r4, sp, asr #17
 *   @0x2f6bc4 cdpge p6, #0x0, c4, c14, c0, #0x1
 *   @0x2f6bc8 cdp2 p7, #0xb, c15, c10, c15, #0x7
 *   @0x2f6bcc .word 0x46054631
 *   @0x2f6bd0 .word 0xf7f04620
 *   @0x2f6bd4 .word 0x4607f8f7
 *   @0x2f6bd8 stmdahs r0, {r1, r2, r3, r11, r12, pc}
 *   @0x2f6bdc addhi pc, r11, #64
 *   @0x2f6be0 addsmi r4, pc, #168, #22
 *   @0x2f6be4 andshi pc, lr, #64
 *   @0x2f6be8 strtmi r4, [r9], -r0, lsr #12
 *   @0x2f6bec cdp2 p7, #0x5, c15, c11, c15, #0x7
 *   @0x2f6bf0 stmdahs r0, {r1, r2, r3, r12, pc}
 *   @0x2f6bf4 rsbshi pc, pc, #64
 *   @0x2f6bf8 bge 0x75ac3c <b2_toiTime+0x1798>
 *   @0x2f6bfc stmdbls r12, {r5, r9, r10, lr}
 *   @0x2f6c00 .word 0xf7f169e6
 *   @0x2f6c04 andls pc, pc, r7, ror #18
 *   @0x2f6c08 .word 0xf0402800
 *   @0x2f6c0c blls 0x797428 <b2_toiTime+0x3df84>
 *   @0x2f6c10 .word 0xf00042bb
 *   @0x2f6c14 bmi 0xfea1741c <b2_toiTime+0xfffffffffe2bdf78>
 *   @0x2f6c18 .word 0xf0004293
 *   @0x2f6c1c blls 0x7d7414 <b2_toiTime+0x7df70>
 *   @0x2f6c20 addsmi r6, r3, #6422528
 *   @0x2f6c24 mvnshi pc, r0, asr #32
 *   @0x2f6c28 ldrhne pc, [r0], #-141
 *   @0x2f6c2c .word 0xf0002900
 *   @0x2f6c30 andshs r8, r4, #-2147483588
 *   @0x2f6c34 eorlo r4, r12, #671088641
 *   @0x2f6c38 .word 0xf080429a
 *   @0x2f6c3c smlatteq r9, r12, r1, r8
 *   @0x2f6c40 .word 0x310c9b15
 *   @0x2f6c44 .word 0xf0804299
 *   @0x2f6c48 ldreq r8, [r8, r6, ror #3]
 *   @0x2f6c4c mvnhi pc, r0, asr #32
 *   @0x2f6c50 blls 0x91d4b4 <b2_toiTime+0x1c4010>
 *   @0x2f6c54 blhs 0x325144
 *   @0x2f6c58 bicshi pc, sp, r0, asr #32
 *   @0x2f6c5c blhs 0x31d8c8
 *   @0x2f6c60 bicshi pc, r9, r0, asr #32
 *   @0x2f6c64 tstlt r11, r4
 *   @0x2f6c68 blhs 0x31d8d4
 *   @0x2f6c6c bicshi pc, r3, r0
 *   @0x2f6c70 ldmdblt r11, {r1, r3, r4, r8, r9, r11, r12, pc}
 *   @0x2f6c74 blhs 0x31d8e8
 *   @0x2f6c78 bichi pc, sp, r0, asr #32
 *   @0x2f6c7c bge 0x6e0cc0 <g_SWFvertbuff+0xdbf8>
 *   @0x2f6c80 ldrtmi r9, [r0], -r8
 *   @0x2f6c84 blx 0x16f4c4c <b2_toiTime+0xf9b7a8>
 *   @0x2f6c88 strmi r9, [r5], -pc, lsl #30
 *   @0x2f6c8c .word 0xf0402f00
 *   @0x2f6c90 shadd8mi r8, r0, pc
 *   @0x2f6c94 bge 0x6bf13c <g_SWFlinevertbuff+0x6c074>
 *   @0x2f6c98 blx 0x1474c60 <b2_toiTime+0xd1b7bc>
 *   @0x2f6c9c strmi r9, [r2], pc, lsl #22
 *   @0x2f6ca0 .word 0xf0402b00
 *   @0x2f6ca4 rfeia sp!
 *   @0x2f6ca8 pkhtbmi r1, r8, r0, asr #32
 *   @0x2f6cac svceq #0xf1b8
 *   @0x2f6cb0 b 0x16eacc4 <b2_toiTime+0xf91820>
 *   @0x2f6cb4 movwlo r0, #0x1858
 *   @0x2f6cb8 .word 0xf89de7f8
 *   @0x2f6cbc bllo 0x336df0
 *   @0x2f6cc0 .word 0x01092210
 *   @0x2f6cc4 mlavc r8, r10, r0, r4
 *   @0x2f6cc8 rfeia sp!
 *   @0x2f6ccc rsbvc r0, r8, r10, asr #32
 *   @0x2f6cd0 beq 0x31cd20
 *   @0x2f6cd4 ldmdals r2, {r3, r5, r7, r12, sp, lr}
 *   @0x2f6cd8 rfeia sp!
 *   @0x2f6cdc beq 0x2f6e24 <ps_hints_apply+0x5a24>
 *   @0x2f6ce0 rfeia sp!
 *   @0x2f6ce4 mvnvc r0, r0, asr r0
 *   @0x2f6ce8 .word 0x7168726b
 *   @0x2f6cec rscvc r0, r9, #16, #20
 *   @0x2f6cf0 .word 0x71a80a1a
 *   @0x2f6cf4 eorvc r0, r10, #45056
 *   @0x2f6cf8 adcvc r10, r11, #245760
 *   @0x2f6cfc rfeia sp!
 *   @0x2f6d00 .word 0x46423050
 *   @0x2f6d04 tsths r8, r1, lsl #2
 *   @0x2f6d08 andhi pc, r0, sp, asr #17
 *   @0x2f6d0c rfeib pc!
 *   @0x2f6d10 andls r9, r7, pc, lsl #22
 *   @0x2f6d14 .word 0xf0402b00
 *   @0x2f6d18 rfeia sp!
 *   @0x2f6d1c bge 0x6c2e64 <g_SWFlinevertbuff+0x6fd9c>
 *   @0x2f6d20 andhi pc, r0, sp, asr #17
 *   @0x2f6d24 andls r4, r1, #48, #12
 *   @0x2f6d28 strbmi r2, [r2], -r4, lsl #2
 *   @0x2f6d2c .word 0xf9aff7f1
 *   @0x2f6d30 andls r9, r5, pc, lsl #22
 *   @0x2f6d34 .word 0xf0402b00
 *   @0x2f6d38 rfeia sp!
 *   @0x2f6d3c tsths r4, r0, asr r0
 *   @0x2f6d40 cmpmi r9, #32, #12
 *   @0x2f6d44 .word 0xf86df7f1
 *   @0x2f6d48 stmdahs r0, {r0, r1, r2, r3, r12, pc}
 *   @0x2f6d4c .word 0x814cf040
 *   @0x2f6d50 strbmi r9, [r1], r7, lsl #30
 *   @0x2f6d54 ldrhlo pc, [r0], #-141
 *   @0x2f6d58 ble 0xc083c4 <b2_toiTime+0x4aef20>
 *   @0x2f6d5c strls r4, [r4, -r0, lsr #12]
 *   @0x2f6d60 cdp2 p7, #0x7, c15, c11, c15, #0x7
 *   @0x2f6d64 qasxmi r6, r0, r8
 *   @0x2f6d68 cdp2 p7, #0x7, c15, c7, c15, #0x7
 *   @0x2f6d6c qsub16mi r6, r0, r8
 *   @0x2f6d70 cdp2 p7, #0x7, c15, c3, c15, #0x7
 *   @0x2f6d74 .word 0x462060b8
 *   @0x2f6d78 cdp2 p7, #0x6, c15, c15, c15, #0x7
 *   @0x2f6d7c qsub8mi r6, r0, r8
 *   @0x2f6d80 cdp2 p7, #0x6, c15, c11, c15, #0x7
 *   @0x2f6d84 .word 0xf8576138
 *   @0x2f6d88 bls 0x4059f0 <g_RomDisk+0xe1d0>
 *   @0x2f6d8c stmdale r3, {r0, r1, r6, r8, r10, lr}
 *   @0x2f6d90 .word 0xf7f14620
 *   @0x2f6d94 umulls pc, r10, r1, r8
 *   @0x2f6d98 ldrmi r9, [r8], r5, lsl #16
 *   @0x2f6d9c eorhs pc, r9, r0, asr #16
 *   @0x2f6da0 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f6da4 .word 0x4620e7d6
 *   @0x2f6da8 .word 0xf7f12700
 *   @0x2f6dac stmdals r5, {r0, r2, r7, r11, r12, sp, lr, pc}
 *   @0x2f6db0 ldrhne pc, [r0], #-141
 *   @0x2f6db4 blls 0x63f5cc <g_SWFaavertbuff+0x6c504>
 *   @0x2f6db8 ldc p5, c15, [r0], {191}
 *   @0x2f6dbc ldrhhs pc, [r0], #-141
 *   @0x2f6dc0 ldmdals r3, {r2, r4, r8, sp}
 *   @0x2f6dc4 ldrsbls pc, [r4], #-141
 *   @0x2f6dc8 tsteq r3, r1, asr r3
 *   @0x2f6dcc andls r3, r3, r12, lsl #6
 *   @0x2f6dd0 addsmi r3, r7, #44, #2
 *   @0x2f6dd4 stmdals r5, {r1, r2, r5, r9, r11, r12, lr, pc}
 *   @0x2f6dd8 eorgt pc, r7, r0, asr r8
 *   @0x2f6ddc .word 0x0004f8dc
 *   @0x2f6de0 cmnle r4, r8, lsl #5
 *   @0x2f6de4 .word 0xe008f8dc
 *   @0x2f6de8 strmi r9, [r6, #0x803]
 *   @0x2f6dec bl 0xff6acfb0 <b2_toiTime+0xfffffffffef53b0c>
 *   @0x2f6df0 strbmi r0, [r1, #-0x800]
 *   @0x2f6df4 .word 0xf8dcd86b
 *   @0x2f6df8 strbmi r0, [r8, #-0xc]
 *   @0x2f6dfc bl 0xff32cfa0 <b2_toiTime+0xfffffffffebd3afc>
 *   @0x2f6e00 strbmi r0, [r3, #-0x809]
 *   @0x2f6e04 strmi sp, [r6, #0x863]
 *   @0x2f6e08 .word 0xf10ed861
 *   @0x2f6e0c andlo r0, r3, r3, lsl #28
 *   @0x2f6e10 cdpeq p0, #0x0, c15, c3, c14, #0x1
 *   @0x2f6e14 andeq pc, r3, r0, lsr #32
 *   @0x2f6e18 andslo pc, r4, r12, asr #17
 *   @0x2f6e1c strmi r4, [r3], #-1137
 *   @0x2f6e20 ldrb r3, [r6, r1, lsl #14]
 *   @0x2f6e24 teqlt r0, r7, lsl r8
 *   @0x2f6e28 cmple r0, r8, lsl #5
 *   @0x2f6e2c strmi r9, [r1], #-2072
 *   @0x2f6e30 addmi r9, r1, #1245184
 *   @0x2f6e34 ldmdals r10, {r0, r1, r3, r6, r11, r12, lr, pc}
 *   @0x2f6e38 .word 0x3103b148
 *   @0x2f6e3c .word 0x0103f021
 *   @0x2f6e40 smlalbble r4, r4, r8, r2
 *   @0x2f6e44 strmi r9, [r1], #-2331
 *   @0x2f6e48 addmi r9, r1, #1245184
 *   @0x2f6e4c ldmdals r5, {r0, r1, r2, r3, r4, r5, r11, r12, lr, pc}
 *   @0x2f6e50 teqle r12, r3, lsl #5
 *   @0x2f6e54 addmi r9, r1, #1245184
 *   @0x2f6e58 tsteq r2, r9, lsr r1
 *   @0x2f6e5c stmdage pc, {r8, r10, r12, pc}
 *   @0x2f6e60 andls r2, r1, r1, lsl #2
 *   @0x2f6e64 ldrtmi r3, [r0], -r12, lsl #4
 *   @0x2f6e68 .word 0xf911f7f1
 *   @0x2f6e6c strmi r9, [r5], -pc, lsl #22
 *   @0x2f6e70 .word 0xf0402b00
 *   @0x2f6e74 ldmdbge r0, {r0, r3, r4, r5, r7, pc}
 *   @0x2f6e78 stmdbeq r12, {r8, r12, sp, lr, pc}
 *   @0x2f6e7c ldrmi r9, [r8], r7, lsl #30
 *   @0x2f6e80 eor r9, r12, r8, lsl #2
 *   @0x2f6e84 strbvc r4, [pc, -r6, asr #12]
 *   @0x2f6e88 ldrbtvc r6, [r4], #-870
 *   @0x2f6e8c andeq r8, r9, r7, ror r0
 *   @0x2f6e90 andeq r7, r9, r1, ror #26
 *   @0x2f6e94 strheq r7, [r9], -r4
 *   @0x2f6e98 andeq r8, r9, lr, lsr r0
 *   @0x2f6e9c muleq r9, r6, r11
 *   @0x2f6ea0 andeq r8, r9, lr, lsr #32
 *   @0x2f6ea4 andeq r8, r10, r12, lsr #31
 *   @0x2f6ea8 .word 0xffffc19f
 *   @0x2f6eac shadd16mi r9, r0, r0
 *   @0x2f6eb0 andls r6, r0, #1982464
 *   @0x2f6eb4 strtmi r10, [r9], #-2576
 *   @0x2f6eb8 .word 0xf01f6a23
 *   @0x2f6ebc andls pc, pc, sp, asr #29
 *   @0x2f6ec0 .word 0xf0402800
 *   @0x2f6ec4 ldmvs r11!, {r0, r4, r7, pc} ^
 *   @0x2f6ec8 addsmi r9, r10, #16, #20
 *   @0x2f6ecc movwhs sp, #0x8056
 *   @0x2f6ed0 add r9, r9, pc, lsl #6
 *   @0x2f6ed4 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x2f6ed8 ldmdbeq r0, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f6edc rfeia sp!
 *   @0x2f6ee0 ldrmi r3, [r8, #0x50]
 *   @0x2f6ee4 ldmvc r11!, {r0, r1, r2, r4, r6, r9, r11, r12, lr, pc} ^
 *   @0x2f6ee8 .word 0xf8894620
 *   @0x2f6eec ldmdahi r11!, {r12, sp} ^
 *   @0x2f6ef0 andlo pc, r1, r9, lsl #17
 *   @0x2f6ef4 beq 0x9d0fe8 <b2_toiTime+0x277b44>
 *   @0x2f6ef8 andlo pc, r2, r9, lsl #17
 *   @0x2f6efc .word 0xf889683b
 *   @0x2f6f00 ldclvc p0, c3, [r11], #12
 *   @0x2f6f04 andlo pc, r4, r9, lsl #17
 *   @0x2f6f08 .word 0xf8898a7b
 *   @0x2f6f0c ldmdbvs r11!, {r0, r2, r12, sp}
 *   @0x2f6f10 .word 0xf8890a1b
 *   @0x2f6f14 ldmdbvs r11!, {r1, r2, r12, sp}
 *   @0x2f6f18 andlo pc, r7, r9, lsl #17
 *   @0x2f6f1c .word 0xf8897dfb
 *   @0x2f6f20 bhi 0x1c2f48 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4b8>
 *   @0x2f6f24 andlo pc, r9, r9, lsl #17
 *   @0x2f6f28 beq 0x9d151c <b2_toiTime+0x278078>
 *   @0x2f6f2c andlo pc, r10, r9, lsl #17
 *   @0x2f6f30 .word 0xf889697b
 *   @0x2f6f34 blvc 0x1c2f68 <_ZN8CHashMapIiP6CLayerLi7EE6InsertEiS1_+0x4d8>
 *   @0x2f6f38 andlo pc, r12, r9, lsl #17
 *   @0x2f6f3c .word 0xf88989fb
 *   @0x2f6f40 ldmvs r11!, {r0, r2, r3, r12, sp} ^
 *   @0x2f6f44 .word 0xf8890a1b
 *   @0x2f6f48 ldmvs r11!, {r1, r2, r3, r12, sp} ^
 *   @0x2f6f4c andlo pc, pc, r9, lsl #17
 *   @0x2f6f50 .word 0xf7ef6879
 *   @0x2f6f54 andls pc, pc, r8, lsr #25
 *   @0x2f6f58 mrsle r2, spsr
 *   @0x2f6f5c ldmvs r9!, {r5, r9, r10, lr}
 *   @0x2f6f60 .word 0xff5ff7f0
 *   @0x2f6f64 stmdahs r0, {r0, r1, r2, r3, r12, pc}
 *   @0x2f6f68 ldmvs r10!, {r1, r2, r3, r4, r5, r8, r12, lr, pc}
 *   @0x2f6f6c addsmi r6, r10, #16449536
 *   @0x2f6f70 ldmdbvs r8!, {r2, r3, r4, r7, r8, r12, lr, pc} ^
 *   @0x2f6f74 strtmi r6, [r8], #-2593
 *   @0x2f6f78 bl 0xb3467c <b2_toiTime+0x3db1d8>
 *   @0x2f6f7c .word 0xf7f04620
 *   @0x2f6f80 ldmvs r10!, {r0, r1, r3, r4, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f6f84 ldrmi r6, [r3], #-2427
 *   @0x2f6f88 umlalle r0, r3, r10, r7
 *   @0x2f6f8c andeq pc, r0, #79
 *   @0x2f6f90 movwlo r5, #0x14ea
 *   @0x2f6f94 usub8mi lr, r0, r8
 *   @0x2f6f98 bls 0x848844 <b2_toiTime+0xef3a0>
 *   @0x2f6f9c ldc2l p7, c15, [r5], #-956
 *   @0x2f6fa0 .word 0xf8ca69e3
 *   @0x2f6fa4 blmi 0xff5c301c <b2_toiTime+0xfffffffffee69b78>
 *   @0x2f6fa8 .word 0xf8ca447b
 *   @0x2f6fac .word 0xf8db3018
 *   @0x2f6fb0 .word 0xf8db1008
 *   @0x2f6fb4 .word 0xf3c10068
 *   @0x2f6fb8 .word 0xf7f02180
 *   @0x2f6fbc .word 0xf8dbfa50
 *   @0x2f6fc0 .word 0xf8cb3008
 *   @0x2f6fc4 vld4.16 {d10, d11, d12, d13}, [r3:128], r8
 *   @0x2f6fc8 .word 0xf8cb6380
 *   @0x2f6fcc and r3, r11, r8
 *   @0x2f6fd0 beq 0x333114
 *   @0x2f6fd4 andsge pc, r4, sp, asr #17
 *   @0x2f6fd8 andsge pc, r12, sp, asr #17
 *   @0x2f6fdc strls lr, [r5, -r4]
 *   @0x2f6fe0 and r9, r1, r7, lsl #14
 *   @0x2f6fe4 andshi pc, r4, sp, asr #17
 *   @0x2f6fe8 stmdbls r7, {r4, r5, r9, r10, lr}
 *   @0x2f6fec .word 0xf9a3f7f0
 *   @0x2f6ff0 stmdbls r5, {r4, r5, r9, r10, lr}
 *   @0x2f6ff4 .word 0xf99ff7f0
 *   @0x2f6ff8 cmplt r3, pc, lsl #22
 *   @0x2f6ffc ldrtmi r4, [r0], -r9, lsr #12
 *   @0x2f7000 .word 0xf999f7f0
 *   @0x2f7004 .word 0xf7ef4650
 *   @0x2f7008 ldrtmi pc, [r0], -r8, asr #24
 *   @0x2f700c .word 0xf7f04651
 *   @0x2f7010 stmdals pc, {r1, r4, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2f7014 andhs lr, r8, r0
 *   @0x2f7018 stmdahs r0, {r1, r2, r3, r12, pc}
 *   @0x2f701c .word 0xf8dbd16b
 *   @0x2f7020 strb r4, [pc, #0x68]
 *   @0x2f7024 svclo #0x80f5b7
 *   @0x2f7028 andle r4, sp, r5, lsr #23
 *   @0x2f702c mulle r11, pc, r2
 *   @0x2f7030 addsmi r4, r7, #164, #20
 *   @0x2f7034 bmi 0xfec2b05c <b2_toiTime+0xfffffffffe4d1bb8>
 *   @0x2f7038 mulle r5, r7, r2
 *   @0x2f703c addsmi r4, r7, #667648
 *   @0x2f7040 .word 0xf5b7d002
 *   @0x2f7044 .word 0xd14f3f00
 *   @0x2f7048 .word 0xf8cb429f
 *   @0x2f704c teqle r8, r4, lsl #1
 *   @0x2f7050 .word 0xf10b49a1
 *   @0x2f7054 strtmi r0, [r0], -r4, lsl #5
 *   @0x2f7058 .word 0xf5014479
 *   @0x2f705c .word 0xf7f07111
 *   @0x2f7060 .word 0x4602ff39
 *   @0x2f7064 stmdahs r0, {r1, r2, r3, r12, pc}
 *   @0x2f7068 .word 0xf8dbd145
 *   @0x2f706c blhs 0x3032a4 <TT_New_Context+0x309c>
 *   @0x2f7070 stmdavs r1!, {r2, r3, r4, r5, r12, lr, pc} ^
 *   @0x2f7074 svcne #0x51ebb3
 *   @0x2f7078 stm sp, {r1, r3, r4, r5, r11, r12, lr, pc}
 *   @0x2f707c .word 0x21040044
 *   @0x2f7080 .word 0xf7f1980a
 *   @0x2f7084 .word 0xf8cbf804
 *   @0x2f7088 stmdals lr, {r4, r7}
 *   @0x2f708c .word 0xf8dbbb98
 *   @0x2f7090 strtmi r1, [r0], -r12, lsl #1
 *   @0x2f7094 .word 0xf7f00089
 *   @0x2f7098 andls pc, lr, r4, asr #29
 *   @0x2f709c .word 0x4605bb58
 *   @0x2f70a0 .word 0x308cf8db
 *   @0x2f70a4 ble 0x507b20 <SrcVerts+0x64b64>
 *   @0x2f70a8 .word 0xf8db4620
 *   @0x2f70ac .word 0xf7ef6090
 *   @0x2f70b0 .word 0xf846fcd4
 *   @0x2f70b4 strlo r0, [r1, #-0x25]
 *   @0x2f70b8 qsub8mi lr, r0, r2
 *   @0x2f70bc mrc2 p7, #0x7, apsr_nzcv, c12, c0, #0x7
 *   @0x2f70c0 vst4.8 {d30, d31, d0, d1}, [pc:64], r0
 *   @0x2f70c4 stmdals r10, {r7, r8, r9, r12, sp}
 *   @0x2f70c8 addlo pc, r8, r11, asr #17
 *   @0x2f70cc movwhs r2, #0x1104
 *   @0x2f70d0 .word 0xf8cb4632
 *   @0x2f70d4 .word 0xf7f0308c
 *   @0x2f70d8 blls 0x6b5178 <g_SWFlinevertbuff+0x620b0>
 *   @0x2f70dc addseq pc, r0, r11, asr #17
 *   @0x2f70e0 andvs r11, r5, r3, asr #18
 *   @0x2f70e4 and r9, r6, lr, lsl #16
 *   @0x2f70e8 and r2, r4, r2
 *   @0x2f70ec and r2, r2, r8
 *   @0x2f70f0 and r2, r0, r10
 *   @0x2f70f4 andsls r4, r0, r8, lsl r6
 *   @0x2f70f8 .word 0xf0402800
 *   @0x2f70fc .word 0x9c098151
 *   @0x2f7100 .word 0x2c009809
 *   @0x2f7104 rsbmi r11, r4, #184, #30
 *   @0x2f7108 .word 0x208cf8db
 *   @0x2f710c .word 0xf8db2800
 *   @0x2f7110 adclt r5, r3, #104
 *   @0x2f7114 .word 0xf103bfb8
 *   @0x2f7118 addsmi r3, r3, #-67108861
 *   @0x2f711c stmdbls r9, {r2, r8, r9, r11, r12, lr, pc}
 *   @0x2f7120 .word 0xf2802900
 *   @0x2f7124 movwhs r8, #0x134
 *   @0x2f7128 ldrsbhs pc, [r0], r11
 *   @0x2f712c .word 0xf8524628
 *   @0x2f7130 .word 0xf7ef1023
 *   @0x2f7134 ldrhls pc, [r0], -r8
 *   @0x2f7138 .word 0xf0402800
 *   @0x2f713c bls 0x497608 <g_prim_v+0x75fc>
 *   @0x2f7140 qsaxmi r4, r9, r8
 *   @0x2f7144 .word 0x47986d93
 *   @0x2f7148 stmdahs r0, {r4, r12, pc}
 *   @0x2f714c .word 0x8128f040
 *   @0x2f7150 .word 0x3064f8db
 *   @0x2f7154 ldrbmi r1, [r8], -r4, lsr #8
 *   @0x2f7158 ldmdbmi sp, {r1, r3, r10, r12, pc} ^
 *   @0x2f715c movwls r4, #0x662a
 *   @0x2f7160 .word 0xf8db2301
 *   @0x2f7164 .word 0xf88b4204
 *   @0x2f7168 blge 0x743c60 <g_SWFvertbuff+0x70b98>
 *   @0x2f716c stmdahs r0, {r5, r7, r8, r9, r10, lr}
 *   @0x2f7170 .word 0x810ff040
 *   @0x2f7174 blhs 0x7dddc0 <b2_toiTime+0x8491c>
 *   @0x2f7178 .word 0x810bf240
 *   @0x2f717c stmdbeq r0, {r0, r2, r3, r8, r12, sp, lr, pc} ^
 *   @0x2f7180 strbmi r4, [r9], -r8, lsr #12
 *   @0x2f7184 cdp2 p7, #0x1, c15, c14, c15, #0x7
 *   @0x2f7188 andls r9, r5, r0, lsl r11
 *   @0x2f718c .word 0xf0402b00
 *   @0x2f7190 strtmi r8, [r8], -r0, lsl #2
 *   @0x2f7194 .word 0xf7ef4649
 *   @0x2f7198 blls 0x736474 <g_SWFvertbuff+0x633ac>
 *   @0x2f719c blhs 0x308bac <TT_New_Context+0x89a4>
 *   @0x2f71a0 rscshi pc, r7, r0, asr #32
 *   @0x2f71a4 .word 0x21024628
 *   @0x2f71a8 blx 0xff3b516e <b2_toiTime+0xfffffffffec5bcca>
 *   @0x2f71ac stmdahs r0, {r4, r12, pc}
 *   @0x2f71b0 rschi pc, pc, r0, asr #32
 *   @0x2f71b4 strbmi r4, [r9], -r8, lsr #12
 *   @0x2f71b8 stc2 p7, c15, [r4], #956
 *   @0x2f71bc .word 0x46069b10
 *   @0x2f71c0 .word 0xf0402b00
 *   @0x2f71c4 strtmi r8, [r8], -r6, ror #1
 *   @0x2f71c8 .word 0xf7ef4649
 *   @0x2f71cc blls 0x736440 <g_SWFvertbuff+0x63378>
 *   @0x2f71d0 blhs 0x3089f4 <TT_New_Context+0x87ec>
 *   @0x2f71d4 sbcshi pc, sp, r0, asr #32
 *   @0x2f71d8 strbmi r4, [r9], -r8, lsr #12
 *   @0x2f71dc ldc2 p7, c15, [r2], {239}
 *   @0x2f71e0 .word 0x46049b10
 *   @0x2f71e4 .word 0xf0402b00
 *   @0x2f71e8 .word 0x462880d4
 *   @0x2f71ec .word 0xf7ef4649
 *   @0x2f71f0 blls 0x73641c <g_SWFvertbuff+0x63354>
 *   @0x2f71f4 blhs 0x308bfc <TT_New_Context+0x89f4>
 *   @0x2f71f8 sbchi pc, r11, r0, asr #32
 *   @0x2f71fc ldrbmi r9, [r1], r5, lsl #20
 *   @0x2f7200 svclo #0x80f5b2
 *   @0x2f7204 svchs #0x14d120
 *   @0x2f7208 mrcne p1, #0x3, sp, c1, c14, #0x0
 *   @0x2f720c rscsvc pc, sp, #70254592
 *   @0x2f7210 addsmi r11, r1, #-1879048184
 *   @0x2f7214 ldclne p8, c13, [r2], #-96
 *   @0x2f7218 addsmi r0, r0, #146
 *   @0x2f721c andlo sp, r2, #2
 *   @0x2f7220 .word 0xd1114290
 *   @0x2f7224 svcmi #0xfef5b4
 *   @0x2f7228 tsths r4, #16, #4
 *   @0x2f722c bge 0x4b5e40 <SrcVerts+0x12e84>
 *   @0x2f7230 blx 0x41de7e <g_RomDisk+0x2665e>
 *   @0x2f7234 ldrmi r10, [r10, #0xa08]
 *   @0x2f7238 .word 0xf8dbd808
 *   @0x2f723c .word 0xf04332c0
 *   @0x2f7240 .word 0xf8cb0301
 *   @0x2f7244 and r3, r2, r0, asr #5
 *   @0x2f7248 and r4, r0, r12, lsl r6
 *   @0x2f724c .word 0xf8db2400
 *   @0x2f7250 .word 0xf01332c0
 *   @0x2f7254 subsle r0, sp, r1, lsl #20
 *   @0x2f7258 .word 0xf10d00b3
 *   @0x2f725c stmdals r6, {r6, r9, r11}
 *   @0x2f7260 uadd16mi r4, r2, r9
 *   @0x2f7264 .word 0xf7ef9307
 *   @0x2f7268 blls 0x736fe8 <g_SWFvertbuff+0x63f20>
 *   @0x2f726c blhs 0x31b288 <__divdi3+0x68>
 *   @0x2f7270 usaxmi sp, r2, r3
 *   @0x2f7274 stmdbls r7, {r1, r2, r11, r12, pc}
 *   @0x2f7278 .word 0xff55f7ef
 *   @0x2f727c pkhbtmi r9, r2, r0, lsl #22
 *   @0x2f7280 .word 0xd14c2b00
 *   @0x2f7284 movwls r4, #0x4628
 *   @0x2f7288 blx 0x19b524e <b2_toiTime+0x125bdaa>
 *   @0x2f728c strmi r9, [r1], #2820
 *   @0x2f7290 eorls pc, r0, sp, asr #17
 *   @0x2f7294 .word 0x0c08f1a9
 *   @0x2f7298 stmdals r5, {r0, r3, r4, r7, r9, r10, lr}
 *   @0x2f729c bl 0x308968 <TT_New_Context+0x8760>
 *   @0x2f72a0 andsle r0, r11, #-1879048184
 *   @0x2f72a4 strtmi r4, [r8], -r1, ror #12
 *   @0x2f72a8 .word 0xf8cd2304
 *   @0x2f72ac .word 0xf7efc010
 *   @0x2f72b0 .word 0xf8ddfb49
 *   @0x2f72b4 .word 0xf109c010
 *   @0x2f72b8 ldrtmi r0, [r12], #2305
 *   @0x2f72bc .word 0xe7ec9010
 *   @0x2f72c0 ldrbtvc r6, [r4], #-870
 *   @0x2f72c4 svcmi #0x54544f
 *   @0x2f72c8 ldrbtvc r7, [r2], #-1381
 *   @0x2f72cc ldrbtvc r7, [r9], #-49
 *   @0x2f72d0 uhsub16vs r6, r6, r2
 *   @0x2f72d4 .word 0xffffe277
 *   @0x2f72d8 andeq r8, r10, r8, lsl #22
 *   @0x2f72dc blx 0x49d706 <TimingData+0x36ee>
 *   @0x2f72e0 strhs r1, [r0, -r7, lsl #12]
 *   @0x2f72e4 adcmi r3, r7, #12, #28
 *   @0x2f72e8 ldrtmi sp, [r1], -r12, lsl #4
 *   @0x2f72ec qsaxmi r4, r8, r2
 *   @0x2f72f0 .word 0xf7ef9b07
 *   @0x2f72f4 ldrbmi pc, [r1], -r7, lsr #22
 *   @0x2f72f8 andsls r9, r0, r7, lsl #20
 *   @0x2f72fc .word 0xf5bf9805
 *   @0x2f7300 stmdblt r0!, {r5, r7, r10, r11, sp, lr, pc}
 *   @0x2f7304 smlatble r10, r7, r2, r4
 *   @0x2f7308 adclt r3, r4, #16777216
 *   @0x2f730c strbmi lr, [r6], #-7
 *   @0x2f7310 strb r3, [r8, r1, lsl #14]!
 *   @0x2f7314 andsge pc, r4, sp, asr #17
 *   @0x2f7318 .word 0xf04fe001
 *   @0x2f731c stmdals r6, {r9, r11}
 *   @0x2f7320 .word 0xf7f09905
 *   @0x2f7324 stmdals r6, {r3, r11, r12, sp, lr, pc}
 *   @0x2f7328 .word 0xf7f04651
 *   @0x2f732c .word 0xf8dbf804
 *   @0x2f7330 ldrbmi r6, [r8], -r4, lsl #4
 *   @0x2f7334 qadd16mi r4, r10, r12
 *   @0x2f7338 ldrmi r2, [r0, r0, lsl #6]!
 *   @0x2f733c .word 0xf8dbb188
 *   @0x2f7340 ldrbmi r6, [r8], -r4, lsl #4
 *   @0x2f7344 qadd16mi r4, r10, r9
 *   @0x2f7348 ldrmi r2, [r0, r0, lsl #6]!
 *   @0x2f734c .word 0xf8dbb148
 *   @0x2f7350 ldrbmi r6, [r8], -r4, lsl #4
 *   @0x2f7354 qadd16mi r4, r10, r6
 *   @0x2f7358 ldrmi r2, [r0, r0, lsl #6]!
 *   @0x2f735c svclt #0x82800
 *   @0x2f7360 .word 0xf8dd2400
 *   @0x2f7364 strmi r8, [r0, #0x28]!
 *   @0x2f7368 stmdals r9, {r0, r1, r8, r10, r11, r12, lr, pc}
 *   @0x2f736c ble 0x681374 <g_SWFlinevertbuff+0x2e2ac>
 *   @0x2f7370 .word 0xf8db2400
 *   @0x2f7374 strteq r3, [r4], #-140
 *   @0x2f7378 .word 0xf8cb9909
 *   @0x2f737c .word 0xf8cb400c
 *   @0x2f7380 .word 0xf8cb3000
 *   @0x2f7384 ldmdals r0, {r2, r12}
 *   @0x2f7388 andhs lr, r11, r10
 *   @0x2f738c andhs lr, r6, r8
 *   @0x2f7390 .word 0xf04fe006
 *   @0x2f7394 strbmi r0, [r7], -r0, lsl #16
 *   @0x2f7398 strbmi r4, [r1], r6, asr #12
 *   @0x2f739c ldrb r4, [r6, -r4, asr #12]
 *   @0x2f73a0 pop {r0, r2, r3, r4, r12, sp, pc}
 *   @0x2f73a4 svclt #0x8ff0
 *   @0x2f73a8 strbvs r7, [r12, -r6, ror #18]!
 *   @0x2f73ac movtmi r4, #0x6632
 *   @0x2f73b0 movtmi r4, #0x6620
 *   @0x2f73b4 svcmi #0xf0e92d
 *   @0x2f73b8 .word 0xf8d11d03
 *   @0x2f73bc addlt r2, r5, r4, lsl #2
 *   @0x2f73c0 strmi r4, [r12], -r5, lsl #12
 *   @0x2f73c4 andle r4, r3, #-1610612727
 *   @0x2f73c8 .word 0x21084608
 *   @0x2f73cc .word 0xffe1f7ed
 *   @0x2f73d0 stmvc r11!, {r1, r3, r5, r7, r11, r12, sp, lr} ^
 *   @0x2f73d4 movwhs lr, #0x2a43
 *   @0x2f73d8 .word 0x2104f8d4
 *   @0x2f73dc stmdbeq r3, {r0, r2, r8, r9, r11, sp, lr, pc}
 *   @0x2f73e0 stmdale r3, {r0, r4, r7, r8, r10, lr}
 *   @0x2f73e4 andhs pc, r5, #64, #4
 *   @0x2f73e8 stmdale r3, {r0, r1, r4, r7, r9, lr}
 *   @0x2f73ec .word 0x21084620
 *   @0x2f73f0 .word 0xffcff7ed
 *   @0x2f73f4 vadd.f32 d1, d21, d30
 *   @0x2f73f8 strhs r2, [r0, -r6, lsl #10]
 *   @0x2f73fc blhi 0x3b545c <error_g0017+0xe100>
 *   @0x2f7400 .word 0x3c01f816
 *   @0x2f7404 stmdahs r8, {r0, r1, r6, r9, r11, sp, lr, pc}
 *   @0x2f7408 .word 0x3108f8d4
 *   @0x2f740c stmdble r6, {r0, r8, r9, r11, sp}
 *   @0x2f7410 svceq #0x7f018
 *   @0x2f7414 strtmi sp, [r0], -r3
 *   @0x2f7418 .word 0xf7ed2108
 *   @0x2f741c b 0x16f730c <b2_toiTime+0xf9de68>
 *   @0x2f7420 strbmi r0, [r7, #-0x8d8]
 *   @0x2f7424 .word 0x4647bf38
 *   @0x2f7428 mvnle r4, lr, lsr #5
 *   @0x2f742c beq 0x373850 <_ZTS13C_UTF16String+0xa8fc>
 *   @0x2f7430 .word 0x3104f8d4
 *   @0x2f7434 beq 0xff5b2050 <b2_toiTime+0xfffffffffee58bac>
 *   @0x2f7438 stmdble r3, {r1, r3, r4, r7, r8, r10, lr}
 *   @0x2f743c .word 0x21084620
 *   @0x2f7440 .word 0xffa7f7ed
 *   @0x2f7444 stmdaeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f7448 .word 0xf105792b
 *   @0x2f744c .word 0xf8950608
 *   @0x2f7450 stmvc r10!, {r1, lr, pc} ^
 *   @0x2f7454 stmdbvc r11!, {r1, r8, r9, r12, pc} ^
 *   @0x2f7458 stmdavc r9!, {r3, r5, r11, r12, sp, lr} ^
 *   @0x2f745c .word 0xf8959303
 *   @0x2f7460 stmibvc r11!, {r0, r1, r2, r12, sp, pc}
 *   @0x2f7464 strhs lr, [r12, #-0xa52]
 *   @0x2f7468 .word 0xf8d4d03f
 *   @0x2f746c bhs 0x33f894
 *   @0x2f7470 b 0x136d8ac <b2_toiTime+0xc14408>
 *   @0x2f7474 ldmibhs pc!, {r8, sp} ^
 *   @0x2f7478 strtmi sp, [r9], #-2051
 *   @0x2f747c svcvc #0x80f5b1
 *   @0x2f7480 strtmi sp, [r0], -r5, lsl #18
 *   @0x2f7484 movwls r2, #0x1108
 *   @0x2f7488 .word 0xff83f7ed
 *   @0x2f748c b 0x19de098 <b2_toiTime+0x1284bf4>
 *   @0x2f7490 eorle r2, r10, r3, lsl #6
 *   @0x2f7494 ldrtmi r3, [r3], #-2818
 *   @0x2f7498 movwle r4, #0x3553
 *   @0x2f749c movteq lr, #0x5b03
 *   @0x2f74a0 andle r4, r3, #641728512
 *   @0x2f74a4 .word 0x21094620
 *   @0x2f74a8 .word 0xff73f7ed
 *   @0x2f74ac .word 0x3108f8d4
 *   @0x2f74b0 blls 0x3a3c24 <af_blue_strings+0x1900>
 *   @0x2f74b4 strbeq lr, [r5, #-0xb06]
 *   @0x2f74b8 b 0x139dccc <b2_toiTime+0xc44828>
 *   @0x2f74bc blx 0x6c20d0 <g_SWFlinevertbuff+0x6f008>
 *   @0x2f74c0 adcmi pc, lr, #142336
 *   @0x2f74c4 .word 0xf816d211
 *   @0x2f74c8 .word 0xf8162b02
 *   @0x2f74cc b 0x17c64d8 <b2_toiTime+0x106d034>
 *   @0x2f74d0 rscsle r2, r6, r2, lsl #6
 *   @0x2f74d4 .word 0xf8d4445b
 *   @0x2f74d8 addslt r1, r11, #16, #2
 *   @0x2f74dc mvnsle r4, #-1342177272
 *   @0x2f74e0 tsths r0, r0, lsr #12
 *   @0x2f74e4 .word 0xff55f7ed
 *   @0x2f74e8 .word 0xf108e7eb
 *   @0x2f74ec ldrmi r0, [r8, #0x801]!
 *   @0x2f74f0 ldrtmi sp, [r5], -r1, lsl #16
 *   @0x2f74f4 andhs lr, r0, r8, lsr #15
 *   @0x2f74f8 pop {r0, r2, r12, sp, pc}
 *   @0x2f74fc push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2f7500 stcne p15, c4, [r3, #-960]
 *   @0x2f7504 .word 0x2104f8d1
 *   @0x2f7508 strmi r11, [r5], -sp, lsl #1
 *   @0x2f750c addsmi r4, r10, #12, #12
 *   @0x2f7510 strmi sp, [r8], -r3, lsl #4
 *   @0x2f7514 .word 0xf7ed2108
 *   @0x2f7518 stmvc r10!, {r2, r3, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f751c b 0x13d58d0 <b2_toiTime+0xc7c42c>
 *   @0x2f7520 .word 0xf8d42302
 *   @0x2f7524 movwls r2, #0x3104
 *   @0x2f7528 addsmi r4, r10, #721420288
 *   @0x2f752c .word 0xf8d4d20a
 *   @0x2f7530 tstlt r11, r8, lsl #2
 *   @0x2f7534 .word 0x21084620
 *   @0x2f7538 .word 0xff2bf7ed
 *   @0x2f753c .word 0x3104f8d4
 *   @0x2f7540 movwls r1, #0x3b5b
 *   @0x2f7544 bhs 0x6ddd58 <g_SWFvertbuff+0xac90>
 *   @0x2f7548 strtmi sp, [r0], -r3, lsl #16
 *   @0x2f754c .word 0xf7ed2108
 *   @0x2f7550 .word 0xf895ff20
 *   @0x2f7554 stmibvc r11!, {r1, r2, pc} ^
 *   @0x2f7558 stmdahs r8, {r0, r1, r6, r9, r11, sp, lr, pc}
 *   @0x2f755c .word 0x3108f8d4
 *   @0x2f7560 stmdble r6, {r0, r8, r9, r11, sp}
 *   @0x2f7564 svceq #0x1f018
 *   @0x2f7568 strtmi sp, [r0], -r3
 *   @0x2f756c .word 0xf7ed2108
 *   @0x2f7570 b 0x16f71b8 <b2_toiTime+0xf9dd14>
 *   @0x2f7574 bls 0x3b96dc <error_g0017+0x12380>
 *   @0x2f7578 movweq pc, #0x2108
 *   @0x2f757c svceq #0xc3ebb2
 *   @0x2f7580 strtmi sp, [r0], -r3, lsl #4
 *   @0x2f7584 .word 0xf7ed2108
 *   @0x2f7588 .word 0xf8d4ff04
 *   @0x2f758c blhs 0x3439b4
 *   @0x2f7590 bvc 0xeeda3c <b2_toiTime+0x794598>
 *   @0x2f7594 blvc 0xe95f48 <b2_toiTime+0x73caa4>
 *   @0x2f7598 strhs lr, [r7, -r3, asr #20]
 *   @0x2f759c .word 0xf8957b6b
 *   @0x2f75a0 b 0x13df5d0 <b2_toiTime+0xc8612c>
 *   @0x2f75a4 .word 0xf8952606
 *   @0x2f75a8 b 0x149b5dc <b2_toiTime+0xd42138>
 *   @0x2f75ac ldrbeq r0, [r11, r7, lsl #6]
 *   @0x2f75b0 strtmi sp, [r0], -r3, lsl #10
 *   @0x2f75b4 .word 0xf7ed2108
 *   @0x2f75b8 ldmdaeq r11!, {r2, r3, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f75bc stmdale lr, {r0, r1, r6, r8, r10, lr}
 *   @0x2f75c0 svceq #0x43ebb8
 *   @0x2f75c4 bl 0x3ed5f8 <_ZTIv+0x54>
 *   @0x2f75c8 strbmi r0, [r6, #-0x656]
 *   @0x2f75cc b 0x156b9f0 <b2_toiTime+0xe1254c>
 *   @0x2f75d0 .word 0xf04f290a
 *   @0x2f75d4 blx 0x579de0 <g_SWFlineaavertbuff+0x26d18>
 *   @0x2f75d8 strbmi pc, [r11, #-0x909]
 *   @0x2f75dc strtmi sp, [r0], -r3
 *   @0x2f75e0 .word 0xf7ed2108
 *   @0x2f75e4 .word 0xf105fed6
 *   @0x2f75e8 movwls r0, #0x430e
 *   @0x2f75ec movweq pc, #0x8108
 *   @0x2f75f0 stmne r10!, {r0, r1, r3, r4, r6} ^
 *   @0x2f75f4 stmdals r5, {r0, r2, r9, r12, pc}
 *   @0x2f75f8 andseq pc, r0, #-1073741784
 *   @0x2f75fc andls r4, r6, r0, lsl r4
 *   @0x2f7600 ldrmi r4, [r3], #1667
 *   @0x2f7604 andls r4, r9, #1509949440
 *   @0x2f7608 .word 0x2108f8d4
 *   @0x2f760c stmdble lr, {r0, r9, r11, sp}
 *   @0x2f7610 bllo 0x79da28 <b2_toiTime+0x44584>
 *   @0x2f7614 ldrmi r9, [r9], #-2052
 *   @0x2f7618 stmdavc r11, {r1, r6, r7, r10, r11, r12, lr} ^
 *   @0x2f761c movwhs lr, #0x2a43
 *   @0x2f7620 movwlo r11, #0x121b
 *   @0x2f7624 strtmi sp, [r0], -r3
 *   @0x2f7628 .word 0xf7ed2108
 *   @0x2f762c movwhs pc, #0xeb2
 *   @0x2f7630 rscslo pc, pc, #8, #2
 *   @0x2f7634 .word 0x4699469c
 *   @0x2f7638 andls r4, r10, #161480704
 *   @0x2f763c .word 0xf00045c1
 *   @0x2f7640 bls 0x4578f0 <g_RomDisk+0x600d0>
 *   @0x2f7644 blvs 0x3b5694 <error_g0017+0xe338>
 *   @0x2f7648 .word 0xf8129205
 *   @0x2f764c b 0x1382658 <b2_toiTime+0xc291b4>
 *   @0x2f7650 bls 0x400e70 <g_RomDisk+0x9650>
 *   @0x2f7654 blvc 0x3b56a4 <error_g0017+0xe348>
 *   @0x2f7658 .word 0xf8129204
 *   @0x2f765c b 0x1382668 <b2_toiTime+0xc291c4>
 *   @0x2f7660 bls 0x481284 <_ZN10InputQuery13ms_InputText2E+0x1e94>
 *   @0x2f7664 .word 0xf81242be
 *   @0x2f7668 andls r0, r6, #2048
 *   @0x2f766c .word 0x2c01f812
 *   @0x2f7670 andls r9, r11, #8
 *   @0x2f7674 .word 0xf812465a
 *   @0x2f7678 andls r1, r7, #2048
 *   @0x2f767c .word 0x2c01f812
 *   @0x2f7680 andhs lr, r1, #270336
 *   @0x2f7684 strtmi sp, [r0], -r7, lsl #18
 *   @0x2f7688 stm sp, {r3, r8, sp}
 *   @0x2f768c .word 0xf7ed100c
 *   @0x2f7690 ldm sp, {r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f7694 addsmi r1, lr, #12
 *   @0x2f7698 .word 0xf1b9d815
 *   @0x2f769c andsle r0, r2, r0, lsl #30
 *   @0x2f76a0 .word 0x1108f8d4
 *   @0x2f76a4 qasxmi r11, r0, r1
 *   @0x2f76a8 andls r2, r0, #8, #2
 *   @0x2f76ac cdp2 p7, #0x7, c15, c1, c13, #0x7
 *   @0x2f76b0 and r9, r8, r0, lsl #20
 *   @0x2f76b4 stmdale r1, {r2, r4, r5, r7, r8, r10, lr}
 *   @0x2f76b8 stmdble r2, {r0, r1, r3, r4, r5, r7, r9, lr}
 *   @0x2f76bc beq 0x3737ec <_ZTS13C_UTF16String+0xa898>
 *   @0x2f76c0 .word 0xf04ae001
 *   @0x2f76c4 bhs 0x2f9ed4 <ps_hints_apply+0x8ad4>
 *   @0x2f76c8 .word 0xf64fd05e
 *   @0x2f76cc addsmi r7, r10, #-67108861
 *   @0x2f76d0 .word 0xf8d4d049
 *   @0x2f76d4 ldrmi r3, [r3], #264
 *   @0x2f76d8 bls 0x563ccc <g_SWFlineaavertbuff+0x10c04>
 *   @0x2f76dc movwle r4, #0x7593
 *   @0x2f76e0 blls 0x3be8d0 <error_g0017+0x17574>
 *   @0x2f76e4 strtmi r1, [r11], #-2962
 *   @0x2f76e8 subeq lr, r2, #11264
 *   @0x2f76ec ldmdble r8, {r1, r3, r4, r7, r9, lr}
 *   @0x2f76f0 .word 0x21084620
 *   @0x2f76f4 cdp2 p7, #0x4, c15, c13, c13, #0x7
 *   @0x2f76f8 blls 0x5af74c <g_SWFlineaavertbuff+0x5c684>
 *   @0x2f76fc swple r4, r9, [r5]
 *   @0x2f7700 rscsvc pc, pc, pc, asr #12
 *   @0x2f7704 smlabble r1, r6, r2, r4
 *   @0x2f7708 strhle r4, [r10], -r7
 *   @0x2f770c ldrmi r9, [r3, #0xa09]
 *   @0x2f7710 ldclne p3, c13, [r11], #-952
 *   @0x2f7714 .word 0x2104f8d4
 *   @0x2f7718 bl 0x5be58c <g_SWFlineaavertbuff+0x6b4c4>
 *   @0x2f771c addsmi r0, r10, #201326593
 *   @0x2f7720 .word 0xf8d4d3e6
 *   @0x2f7724 cmnlt r11, #8, #2
 *   @0x2f7728 blls 0x5dd750 <g_SWFaavertbuff+0xa688>
 *   @0x2f772c andhs lr, r0, #274432
 *   @0x2f7730 andslt r4, r2, #53477376
 *   @0x2f7734 eorle r4, r7, #-1342177269
 *   @0x2f7738 bleq 0x3b57ac <error_g0017+0xe450>
 *   @0x2f773c .word 0x1c01f81b
 *   @0x2f7740 qaddhs lr, r1, r0
 *   @0x2f7744 ldrmi sp, [r1], #-13
 *   @0x2f7748 ldrsbeq pc, [r0, -r4]
 *   @0x2f774c addmi r11, r1, #-1879048184
 *   @0x2f7750 strtmi sp, [r0], -r7, lsl #6
 *   @0x2f7754 stm sp, {r4, r8, sp}
 *   @0x2f7758 .word 0xf7ed000c
 *   @0x2f775c ldm sp, {r1, r3, r4, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f7760 movwlo r0, #0x100c
 *   @0x2f7764 .word 0xf8d4e7e6
 *   @0x2f7768 blhs 0x343b90
 *   @0x2f776c bls 0x5ad794 <g_SWFlineaavertbuff+0x5a6cc>
 *   @0x2f7770 swple r4, r1, [r5]
 *   @0x2f7774 .word 0x73fff64f
 *   @0x2f7778 swple r4, lr, [r1]
 *   @0x2f777c strhle r4, [r3], -r7
 *   @0x2f7780 .word 0x21084620
 *   @0x2f7784 cdp2 p7, #0x0, c15, c5, c13, #0x7
 *   @0x2f7788 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f778c ldrsblt pc, [r12], -sp
 *   @0x2f7790 .word 0x46b4463b
 *   @0x2f7794 usaxmi lr, r0, r2
 *   @0x2f7798 pop {r0, r2, r3, r12, sp, pc}
 *   @0x2f779c ldrblt r8, [r8, #0xff0]!
 *   @0x2f77a0 streq pc, [r10], -r0, lsl #2
 *   @0x2f77a4 .word 0x3104f8d1
 *   @0x2f77a8 strmi r4, [r12], -r5, lsl #12
 *   @0x2f77ac andle r4, r3, #805306379
 *   @0x2f77b0 .word 0x21084608
 *   @0x2f77b4 stc2l p7, c15, [sp, #948]!
 *   @0x2f77b8 stmvc r11!, {r1, r3, r5, r7, r11, r12, sp, lr} ^
 *   @0x2f77bc b 0x13d6080 <b2_toiTime+0xc7cbdc>
 *   @0x2f77c0 bvc 0x1d803d0 <b2_toiTime+0x1626f2c>
 *   @0x2f77c4 b 0x1388840 <b2_toiTime+0xc2f39c>
 *   @0x2f77c8 .word 0xf8d42707
 *   @0x2f77cc adcmi r2, r10, #4, #2
 *   @0x2f77d0 ldclne p3, c13, [r10, #-12]!
 *   @0x2f77d4 svceq #0x42ebb3
 *   @0x2f77d8 strtmi sp, [r0], -r3, lsl #4
 *   @0x2f77dc .word 0xf7ed2108
 *   @0x2f77e0 .word 0xf8d4fdd8
 *   @0x2f77e4 orrslt r3, r3, r8, lsl #2
 *   @0x2f77e8 adcmi r2, pc, #0, #10
 *   @0x2f77ec .word 0xf816d00f
 *   @0x2f77f0 .word 0xf8162b02
 *   @0x2f77f4 b 0x13c6800 <b2_toiTime+0xc6d35c>
 *   @0x2f77f8 .word 0xf8d42202
 *   @0x2f77fc addsmi r3, r10, #16, #2
 *   @0x2f7800 strtmi sp, [r0], -r3, lsl #6
 *   @0x2f7804 .word 0xf7ed2110
 *   @0x2f7808 strlo pc, [r1, #-0xdc4]
 *   @0x2f780c andhs lr, r0, sp, ror #15
 *   @0x2f7810 push {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2f7814 .word 0xf5004ff0
 *   @0x2f7818 .word 0xf8d15500
 *   @0x2f781c .word 0xf1052104
 *   @0x2f7820 addlt r0, r7, r0, lsl r3
 *   @0x2f7824 addsmi r4, r10, #7340032
 *   @0x2f7828 andle r4, r3, #12, #12
 *   @0x2f782c .word 0x21084608
 *   @0x2f7830 stc2 p7, c15, [pc, #948]!
 *   @0x2f7834 ldmdbvc r10!, {r0, r1, r3, r4, r5, r6, r8, r11, r12, sp, lr}
 *   @0x2f7838 b 0x13b88ac <b2_toiTime+0xc5f408>
 *   @0x2f783c ldmibvc r10!, {r1, r8, r9, sp, lr} ^
 *   @0x2f7840 ldmibvc r10!, {r0, r1, r4, r8, r9, lr}
 *   @0x2f7844 movwhs lr, #0x2a43
 *   @0x2f7848 .word 0x2104f8d4
 *   @0x2f784c addsmi r1, r3, #215040
 *   @0x2f7850 vadd.i8 d29, d2, d3
 *   @0x2f7854 addsmi r0, r3, #-268435456
 *   @0x2f7858 strtmi sp, [r0], -r3, lsl #16
 *   @0x2f785c .word 0xf7ed2108
 *   @0x2f7860 .word 0xf895fd98
 *   @0x2f7864 .word 0xf105900d
 *   @0x2f7868 blvc 0xdb90b0 <b2_toiTime+0x65fc0c>
 *   @0x2f786c .word 0xf8d4210c
 *   @0x2f7870 strlo r0, [r12, -r4, lsl #2]
 *   @0x2f7874 stmdbmi r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f7878 b 0x155d488 <b2_toiTime+0xe03fe4>
 *   @0x2f787c blvc 0xffdd1c90 <b2_toiTime+0xffffffffff6787ec>
 *   @0x2f7880 b 0x153e688 <b2_toiTime+0xde51e4>
 *   @0x2f7884 blvc 0xfedb9c98 <b2_toiTime+0xfffffffffe6607f4>
 *   @0x2f7888 movwhs lr, #0x3a49
 *   @0x2f788c .word 0xf0219303
 *   @0x2f7890 blls 0x3f2008 <g_SaveSlotSize>
 *   @0x2f7894 stmdble r3, {r0, r1, r7, r9, lr}
 *   @0x2f7898 .word 0x21084620
 *   @0x2f789c ldc2l p7, c15, [r9, #-948]!
 *   @0x2f78a0 ldrtmi r2, [r7], -r0, lsl #4
 *   @0x2f78a4 blls 0x3c9100 <error_g0017+0x21da4>
 *   @0x2f78a8 .word 0xf000429d
 *   @0x2f78ac .word 0xf897809e
 *   @0x2f78b0 ldmdavc r9!, {r0, lr, pc}
 *   @0x2f78b4 b 0x16d5eb4 <b2_toiTime+0xf7ca10>
 *   @0x2f78b8 bvc 0xff1ca8f0 <b2_toiTime+0xfffffffffea7144c>
 *   @0x2f78bc .word 0x6c01ea4c
 *   @0x2f78c0 ldrteq r7, [r6], #-2297
 *   @0x2f78c4 mulge r8, r7, r8
 *   @0x2f78c8 .word 0x0c01ea4c
 *   @0x2f78cc movwls r7, #0x48b9
 *   @0x2f78d0 b 0x16164c4 <b2_toiTime+0xebd020>
 *   @0x2f78d4 ldmdbvc r9!, {r0, r11, sp}
 *   @0x2f78d8 mullt r9, r7, r8
 *   @0x2f78dc b 0x149c4f8 <b2_toiTime+0xd43054>
 *   @0x2f78e0 ldmibvc r9!, {r0, r9, r10, sp, lr} ^
 *   @0x2f78e4 ldmibvc r9!, {r1, r2, r3, r8, r9, lr}
 *   @0x2f78e8 strhs lr, [r1], -r6, asr #20
 *   @0x2f78ec stmdble r5, {r4, r5, r7, r8, r10, lr}
 *   @0x2f78f0 .word 0x21084620
 *   @0x2f78f4 .word 0xf7ed9201
 *   @0x2f78f8 bls 0x376e30 <_ZTS13C_UTF16String+0xdedc>
 *   @0x2f78fc ldrmi r11, [r0, #0x12d]
 *   @0x2f7900 strtmi sp, [r0], -r3, lsl #16
 *   @0x2f7904 .word 0xf7ed2108
 *   @0x2f7908 .word 0xf8d4fd44
 *   @0x2f790c bhs 0x2ffd34 <TT_RunIns+0x2f40>
 *   @0x2f7910 .word 0xf8d4d067
 *   @0x2f7914 bl 0xff4fbd5c <b2_toiTime+0xfffffffffeda28b8>
 *   @0x2f7918 strmi r0, [r9, #0x906]
 *   @0x2f791c blls 0x46d958 <g_RomDisk+0x76138>
 *   @0x2f7920 blmi 0x5f2264 <g_SWFaavertbuff+0x1f19c>
 *   @0x2f7924 bvs 0x5b2258 <g_SWFlineaavertbuff+0x5f190>
 *   @0x2f7928 smlabteq r1, r9, r11, lr
 *   @0x2f792c beq 0x3f225c <g_SaveRenderStates+0x98>
 *   @0x2f7930 b 0x159e548 <b2_toiTime+0xe450a4>
 *   @0x2f7934 strmi r2, [r10, #0xa03]
 *   @0x2f7938 strtmi sp, [r0], -r3, lsl #6
 *   @0x2f793c .word 0xf7ed2110
 *   @0x2f7940 b 0x16f6de8 <b2_toiTime+0xf9d944>
 *   @0x2f7944 .word 0xf1094118
 *   @0x2f7948 .word 0xf1080b01
 *   @0x2f794c streq r0, [r9], #-2561
 *   @0x2f7950 strbmi r11, [r10], #833
 *   @0x2f7954 andeq lr, r10, #207872
 *   @0x2f7958 svceq #0xf1bb
 *   @0x2f795c blls 0x3aba68 <error_g0017+0x470c>
 *   @0x2f7960 blx 0xabacac <b2_toiTime+0x361808>
 *   @0x2f7964 .word 0xf3c2f982
 *   @0x2f7968 mrrcpl p2, #0x0, r4, r9, c2
 *   @0x2f796c blx 0x13c0774 <b2_toiTime+0xc672d0>
 *   @0x2f7970 andsmi pc, r1, #536870912
 *   @0x2f7974 strtmi sp, [r0], -r3, lsl #2
 *   @0x2f7978 .word 0xf7ed2108
 *   @0x2f797c blls 0x3b6dac <error_g0017+0xfa50>
 *   @0x2f7980 sbcseq lr, r9, #323584
 *   @0x2f7984 .word 0x0c07f009
 *   @0x2f7988 orrhs r5, r0, #39424
 *   @0x2f798c .word 0xfc0cfa43
 *   @0x2f7990 svceq #0xcea12
 *   @0x2f7994 strtmi sp, [r0], -r3, lsl #2
 *   @0x2f7998 .word 0xf7ed2108
 *   @0x2f799c .word 0xf10bfcfa
 *   @0x2f79a0 .word 0xe7d73bff
 *   @0x2f79a4 streq r0, [r9], #-3121
 *   @0x2f79a8 qadd16mi r11, r0, r9
 *   @0x2f79ac .word 0xf7ed2108
 *   @0x2f79b0 strbmi pc, [r10], #3312
 *   @0x2f79b4 smlabteq r10, r11, r11, lr
 *   @0x2f79b8 svceq #0xf1bb
 *   @0x2f79bc addlt sp, r9, #17
 *   @0x2f79c0 stmeq r10, {r1, r8, r9, r11, r12, pc} ^
 *   @0x2f79c4 mrseq pc, apsr
 *   @0x2f79c8 orrhs r5, r0, #39424
 *   @0x2f79cc .word 0xf101fa43
 *   @0x2f79d0 andle r4, r3, r10, lsl #4
 *   @0x2f79d4 .word 0x21084620
 *   @0x2f79d8 ldc2l p7, c15, [r11], {237}
 *   @0x2f79dc bllo 0x2f3e10 <ps_hints_apply+0x2a10>
 *   @0x2f79e0 strlo lr, [r1, #-0x7e8]
 *   @0x2f79e4 ldrtmi r3, [r2], -r12, lsl #14
 *   @0x2f79e8 andhs lr, r0, sp, asr r7
 *   @0x2f79ec pop {r0, r1, r2, r12, sp, pc}
 *   @0x2f79f0 ldrblt r8, [r8, #0xff0]!
 *   @0x2f79f4 ldreq pc, [r4, -r0, lsl #2]
 *   @0x2f79f8 .word 0x3104f8d1
 *   @0x2f79fc strmi r4, [sp], -r4, lsl #12
 *   @0x2f7a00 andle r4, r3, #-1342177269
 *   @0x2f7a04 .word 0x21084608
 *   @0x2f7a08 stc2l p7, c15, [r3], {237}
 *   @0x2f7a0c stmdbvc r2!, {r0, r1, r5, r6, r8, r11, r12, sp, lr}
 *   @0x2f7a10 ldreq r7, [r11], #-3174
 *   @0x2f7a14 movwvs lr, #0x2a43
 *   @0x2f7a18 ldrteq r7, [r6], #-2530
 *   @0x2f7a1c stmibvc r2!, {r0, r1, r4, r8, r9, lr}
 *   @0x2f7a20 movwhs lr, #0x2a43
 *   @0x2f7a24 b 0x1496ab4 <b2_toiTime+0xd3d610>
 *   @0x2f7a28 stclvc p6, c6, [r2], #8
 *   @0x2f7a2c stcvc p3, c4, [r2], #88
 *   @0x2f7a30 strhs lr, [r2], -r6, asr #20
 *   @0x2f7a34 .word 0x2104f8d5
 *   @0x2f7a38 adcmi r1, r3, #20, #22
 *   @0x2f7a3c blhs 0x7eda58 <b2_toiTime+0x945b4>
 *   @0x2f7a40 bllo 0x82de54 <b2_toiTime+0xd49b0>
 *   @0x2f7a44 svceq #0x53ebb6
 *   @0x2f7a48 strtmi sp, [r8], -r3, lsl #18
 *   @0x2f7a4c .word 0xf7ed2108
 *   @0x2f7a50 .word 0xf8d5fca0
 *   @0x2f7a54 orrlt r3, r11, r8, lsl #2
 *   @0x2f7a58 cmnlt lr, r12, lsr r6
 *   @0x2f7a5c blhs 0x3b5ab4 <error_g0017+0xe758>
 *   @0x2f7a60 .word 0x3c01f814
 *   @0x2f7a64 andhs lr, r2, #274432
 *   @0x2f7a68 ldrsblo pc, [r0, -r5]
 *   @0x2f7a6c movwle r4, #0x329a
 *   @0x2f7a70 tsths r0, r8, lsr #12
 *   @0x2f7a74 stc2 p7, c15, [sp], {237}
 *   @0x2f7a78 strb r3, [lr, r1, lsl #28]!
 *   @0x2f7a7c ldcllt p0, c2, [r8, #0]!
 *   @0x2f7a80 svcmi #0xf0e92d
 *   @0x2f7a84 ldreq pc, [r0], -r0, lsl #2
 *   @0x2f7a88 .word 0x3104f8d1
 *   @0x2f7a8c strmi r11, [r5], -r5, lsl #1
 *   @0x2f7a90 adcsmi r4, r3, #12, #12
 *   @0x2f7a94 strmi sp, [r8], -r3, lsl #4
 *   @0x2f7a98 .word 0xf7ed2108
 *   @0x2f7a9c stmdbvc r8!, {r1, r3, r4, r5, r6, r10, r11, r12, sp, lr, pc} ^
 *   @0x2f7aa0 blvc 0x1ed5f54 <b2_toiTime+0x177cab0>
 *   @0x2f7aa4 b 0x12f8aac <b2_toiTime+0xb9f608>
 *   @0x2f7aa8 stmibvc r11!, {r0, r1, sp, lr} ^
 *   @0x2f7aac tstmi r8, #1056964608
 *   @0x2f7ab0 b 0x1316164 <b2_toiTime+0xbbccc0>
 *   @0x2f7ab4 blvc 0xdbfac8 <b2_toiTime+0x666624>
 *   @0x2f7ab8 strvs lr, [r3, -r7, asr #20]
 *   @0x2f7abc tstmi pc, #240640
 *   @0x2f7ac0 b 0x14d6974 <b2_toiTime+0xd7d4d0>
 *   @0x2f7ac4 movwls r2, #0x2303
 *   @0x2f7ac8 .word 0x3104f8d4
 *   @0x2f7acc adcmi r1, r8, #95232
 *   @0x2f7ad0 stmdahs pc, {r3, r11, r12, lr, pc}
 *   @0x2f7ad4 ldmdalo r0, {r1, r2, r8, r11, r12, lr, pc}
 *   @0x2f7ad8 .word 0xf021210c
 *   @0x2f7adc blls 0x3b1dbc <error_g0017+0xaa60>
 *   @0x2f7ae0 andle r4, r3, #152, #4
 *   @0x2f7ae4 .word 0x21084620
 *   @0x2f7ae8 mrrc2 p7, #0xe, pc, r3, c13
 *   @0x2f7aec ldrtmi r2, [r7], -r0, lsl #4
 *   @0x2f7af0 blls 0x38934c <_ZTS13C_UTF16String+0x203f8>
 *   @0x2f7af4 umaalle r4, r11, sp, r2
 *   @0x2f7af8 mulgt r1, r7, r8
 *   @0x2f7afc ldmdbvc lr!, {r0, r3, r4, r5, r11, r12, sp, lr} ^
 *   @0x2f7b00 .word 0x4c0cea4f
 *   @0x2f7b04 b 0x16165f8 <b2_toiTime+0xebd154>
 *   @0x2f7b08 ldmvc r9!, {r0, r10, r11, sp, lr} ^
 *   @0x2f7b0c .word 0xf8970436
 *   @0x2f7b10 b 0x161fb38 <b2_toiTime+0xec6694>
 *   @0x2f7b14 ldmvc r9!, {r0, r10, r11}
 *   @0x2f7b18 mullt r9, r7, r8
 *   @0x2f7b1c b 0x161c730 <b2_toiTime+0xec328c>
 *   @0x2f7b20 ldmdbvc r9!, {r0, r11, sp}
 *   @0x2f7b24 mulls r11, r7, r8
 *   @0x2f7b28 strvs lr, [r1], -r6, asr #20
 *   @0x2f7b2c movwmi r7, #0xe9f9
 *   @0x2f7b30 b 0x149621c <b2_toiTime+0xd3cd78>
 *   @0x2f7b34 ldrmi r2, [r0, #0x601]!
 *   @0x2f7b38 strtmi sp, [r0], -r5, lsl #18
 *   @0x2f7b3c andls r2, r1, #8, #2
 *   @0x2f7b40 stc2 p7, c15, [r7], #-948
 *   @0x2f7b44 .word 0xb12d9a01
 *   @0x2f7b48 stmdale r3, {r4, r7, r8, r10, lr}
 *   @0x2f7b4c .word 0x21084620
 *   @0x2f7b50 .word 0xfc1ff7ed
 *   @0x2f7b54 .word 0x2108f8d4
 *   @0x2f7b58 .word 0xf8d4b1b2
 *   @0x2f7b5c bl 0xff4fffa4 <b2_toiTime+0xfffffffffeda6b00>
 *   @0x2f7b60 ldrmi r0, [r4, #0xc06]
 *   @0x2f7b64 b 0x16edb9c <b2_toiTime+0xf946f8>
 *   @0x2f7b68 blls 0x3ca79c <error_g0017+0x23440>
 *   @0x2f7b6c bvs 0x5b24a0 <g_SWFlineaavertbuff+0x5f3d8>
 *   @0x2f7b70 .word 0x0c02ebcc
 *   @0x2f7b74 stmdbeq r9, {r1, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f7b78 stmdahs r3, {r0, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f7b7c movwle r4, #0x35e0
 *   @0x2f7b80 tsths r0, r0, lsr #12
 *   @0x2f7b84 .word 0xfc05f7ed
 *   @0x2f7b88 strlo r3, [r12, -r1, lsl #10]
 *   @0x2f7b8c .word 0xe7b04632
 *   @0x2f7b90 andlt r2, r5, r0
 *   @0x2f7b94 svchi #0xf0e8bd
 *   @0x2f7b98 svcmi #0xf0e92d
 *   @0x2f7b9c ldreq pc, [r0, -r0, lsl #2]
 *   @0x2f7ba0 .word 0x3104f8d1
 *   @0x2f7ba4 strmi r11, [r5], -r5, lsl #1
 *   @0x2f7ba8 adcsmi r4, r11, #12, #12
 *   @0x2f7bac strmi sp, [r8], -r3, lsl #4
 *   @0x2f7bb0 .word 0xf7ed2108
 *   @0x2f7bb4 stmdbvc r8!, {r1, r2, r3, r5, r6, r7, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x2f7bb8 blvc 0x1e9606c <b2_toiTime+0x173cbc8>
 *   @0x2f7bbc b 0x12f8bc4 <b2_toiTime+0xb9f720>
 *   @0x2f7bc0 stmibvc r11!, {r0, r1, sp, lr} ^
 *   @0x2f7bc4 tstmi r8, #905969664
 *   @0x2f7bc8 b 0x131627c <b2_toiTime+0xbbcdd8>
 *   @0x2f7bcc blvc 0xdbfbe0 <b2_toiTime+0x66673c>
 *   @0x2f7bd0 strvs lr, [r3], -r6, asr #20
 *   @0x2f7bd4 tstmi lr, #240640
 *   @0x2f7bd8 b 0x1496a8c <b2_toiTime+0xd3d5e8>
 *   @0x2f7bdc movwls r2, #0x3303
 *   @0x2f7be0 .word 0x3104f8d4
 *   @0x2f7be4 adcmi r1, r8, #95232
 *   @0x2f7be8 stmdahs pc, {r3, r11, r12, lr, pc}
 *   @0x2f7bec ldmdalo r0, {r1, r2, r8, r11, r12, lr, pc}
 *   @0x2f7bf0 .word 0xf021210c
 *   @0x2f7bf4 blls 0x3f1ca4
 *   @0x2f7bf8 andle r4, r3, #152, #4
 *   @0x2f7bfc .word 0x21084620
 *   @0x2f7c00 blx 0xff4f5bbe <b2_toiTime+0xfffffffffed9c71a>
 *   @0x2f7c04 ldrtmi r2, [lr], -r0, lsl #4
 *   @0x2f7c08 blls 0x3c9464 <error_g0017+0x22108>
 *   @0x2f7c0c umaalle r4, r8, sp, r2
 *   @0x2f7c10 mulgt r1, r6, r8
 *   @0x2f7c14 ldmdbvc r7!, {r0, r4, r5, r11, r12, sp, lr} ^
 *   @0x2f7c18 .word 0x4c0cea4f
 *   @0x2f7c1c mulge r8, r6, r8
 *   @0x2f7c20 .word 0x6c01ea4c
 *   @0x2f7c24 ldrteq r7, [pc], #-2289
 *   @0x2f7c28 mullt r9, r6, r8
 *   @0x2f7c2c .word 0x0c01ea4c
 *   @0x2f7c30 .word 0xf89678b1
 *   @0x2f7c34 .word 0xf896800a
 *   @0x2f7c38 b 0x161bc6c <b2_toiTime+0xec27c8>
 *   @0x2f7c3c ldmdbvc r1!, {r0, r10, r11, sp}
 *   @0x2f7c40 strvs lr, [r1, -r7, asr #20]
 *   @0x2f7c44 movwmi r7, #0xf9f1
 *   @0x2f7c48 b 0x14d6314 <b2_toiTime+0xd7ce70>
 *   @0x2f7c4c ldrmi r2, [r12, #0x701]!
 *   @0x2f7c50 strtmi sp, [r0], -r9, lsl #18
 *   @0x2f7c54 andls r2, r2, #8, #2
 *   @0x2f7c58 andgt pc, r4, sp, asr #17
 *   @0x2f7c5c blx 0xfe975c1a <b2_toiTime+0xfffffffffe21c776>
 *   @0x2f7c60 .word 0xc004f8dd
 *   @0x2f7c64 .word 0xb12d9a02
 *   @0x2f7c68 stmdale r3, {r2, r4, r7, r8, r10, lr}
 *   @0x2f7c6c .word 0x21084620
 *   @0x2f7c70 blx 0xfe6f5c2e <b2_toiTime+0xfffffffffdf9c78a>
 *   @0x2f7c74 .word 0x2108f8d4
 *   @0x2f7c78 b 0x16e4268 <b2_toiTime+0xf8adc4>
 *   @0x2f7c7c .word 0xf8d44b0b
 *   @0x2f7c80 b 0x15c00c8 <b2_toiTime+0xe66c24>
 *   @0x2f7c84 b 0x15924b4 <b2_toiTime+0xe39010>
 *   @0x2f7c88 b 0x153a0b4 <b2_toiTime+0xde0c10>
 *   @0x2f7c8c ldrmi r2, [r0, #0x808]
 *   @0x2f7c90 strtmi sp, [r0], -r3, lsl #6
 *   @0x2f7c94 .word 0xf7ed2110
 *   @0x2f7c98 strlo pc, [r1, #-0xb7c]
 *   @0x2f7c9c ldrtmi r3, [r10], -r12, lsl #12
 *   @0x2f7ca0 strhhs lr, [r0], -r3
 *   @0x2f7ca4 pop {r0, r2, r12, sp, pc}
 *   @0x2f7ca8 strdeq r8, r9, [r0], -r0
 *   @0x2f7cac svcmi #0xf0e92d
 *   @0x2f7cb0 streq pc, [r10, #-0x100]
 *   @0x2f7cb4 .word 0x3104f8d1
 *   @0x2f7cb8 strmi r11, [r6], -r9, lsl #1
 *   @0x2f7cbc adcmi r4, r11, #12, #12
 *   @0x2f7cc0 strmi sp, [r8], -r3, lsl #4
 *   @0x2f7cc4 .word 0xf7ed2108
 *   @0x2f7cc8 .word 0xf896fb64
 *   @0x2f7ccc ldmvc r3!, {r0, r1, pc}
 *   @0x2f7cd0 b 0x16d64b4 <b2_toiTime+0xf7d010>
 *   @0x2f7cd4 b 0x1509cfc <b2_toiTime+0xdb0858>
 *   @0x2f7cd8 ldmdbvc r3!, {r0, r1, r11, sp, lr} ^
 *   @0x2f7cdc b 0x14f8de0 <b2_toiTime+0xd9f93c>
 *   @0x2f7ce0 ldmdbvc r3!, {r0, r1, r11}
 *   @0x2f7ce4 stmdahs r3, {r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f7ce8 b 0x14d63bc <b2_toiTime+0xd7cf18>
 *   @0x2f7cec bvc 0x1fd1900 <b2_toiTime+0x187845c>
 *   @0x2f7cf0 bvc 0xfc8974 <b2_toiTime+0x86f4d0>
 *   @0x2f7cf4 strhs lr, [r3, -r7, asr #20]
 *   @0x2f7cf8 .word 0x3104f8d4
 *   @0x2f7cfc ldrmi r1, [r8, #0xb9b]
 *   @0x2f7d00 .word 0xf1b8d809
 *   @0x2f7d04 stmdble r6, {r0, r3, r8, r9, r10, r11}
 *   @0x2f7d08 andeq pc, r10, r8, lsr #3
 *   @0x2f7d0c .word 0xf020210b
 *   @0x2f7d10 adcsmi lr, r8, #156, #30
 *   @0x2f7d14 strtmi sp, [r0], -r3, lsl #4
 *   @0x2f7d18 .word 0xf7ed2108
 *   @0x2f7d1c movwhs pc, #0xbb3a
 *   @0x2f7d20 blx 0x3c052e <error_g0017+0x191d2>
 *   @0x2f7d24 andls r5, r4, #469762048
 *   @0x2f7d28 bls 0x4dc94c <SrcVerts+0x39990>
 *   @0x2f7d2c .word 0xf0004295
 *   @0x2f7d30 .word 0xf89580f2
 *   @0x2f7d34 stmdavc r11!, {r0, sp, pc}
 *   @0x2f7d38 b 0x16d61fc <b2_toiTime+0xf7cd58>
 *   @0x2f7d3c .word 0xf8952a0a
 *   @0x2f7d40 b 0x159bd68 <b2_toiTime+0xe428c4>
 *   @0x2f7d44 stmvc r11!, {r0, r1, r9, r11, lr}
 *   @0x2f7d48 b 0x1578e4c <b2_toiTime+0xe1f9a8>
 *   @0x2f7d4c stmvc r11!, {r0, r1, r9, r11} ^
 *   @0x2f7d50 stmdbmi r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f7d54 strvs lr, [r3, -r7, asr #20]
 *   @0x2f7d58 tstmi pc, #2801664
 *   @0x2f7d5c b 0x14d6310 <b2_toiTime+0xd7ce6c>
 *   @0x2f7d60 stmibvc r11!, {r0, r1, r8, r9, r10, sp} ^
 *   @0x2f7d64 b 0x1549288 <b2_toiTime+0xdefde4>
 *   @0x2f7d68 bvc 0xfedd217c <b2_toiTime+0xfffffffffe678cd8>
 *   @0x2f7d6c stmdbeq r3, {r0, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f7d70 b 0x1556724 <b2_toiTime+0xdfd280>
 *   @0x2f7d74 andle r2, r1, #49152
 *   @0x2f7d78 movwle r4, #0x35c1
 *   @0x2f7d7c .word 0x21084620
 *   @0x2f7d80 blx 0x4f5d3e <SrcVerts+0x52d82>
 *   @0x2f7d84 ldrmi r9, [r10, #0xb04]
 *   @0x2f7d88 strtmi sp, [r0], -r3, lsl #4
 *   @0x2f7d8c .word 0xf7ed2108
 *   @0x2f7d90 .word 0xf10afb00
 *   @0x2f7d94 .word 0xf8cd0a01
 *   @0x2f7d98 ldmdblt pc, {r4, sp, pc}
 *   @0x2f7d9c svceq #0xf1b9
 *   @0x2f7da0 adcs sp, r6, r7, asr r1
 *   @0x2f7da4 bleq 0x4f29c4 <SrcVerts+0x4fa08>
 *   @0x2f7da8 .word 0x2104f8d4
 *   @0x2f7dac movweq pc, #0x410b
 *   @0x2f7db0 stmdble r5, {r0, r1, r4, r7, r9, lr}
 *   @0x2f7db4 .word 0x21084620
 *   @0x2f7db8 .word 0xf7ed9302
 *   @0x2f7dbc blls 0x3b696c <error_g0017+0xf610>
 *   @0x2f7dc0 mulge r1, r11, r8
 *   @0x2f7dc4 b 0x16cf594 <b2_toiTime+0xf760f0>
 *   @0x2f7dc8 b 0x158a5f8 <b2_toiTime+0xe31154>
 *   @0x2f7dcc .word 0xf89b6a02
 *   @0x2f7dd0 b 0x157fde4 <b2_toiTime+0xe26940>
 *   @0x2f7dd4 .word 0xf89b0a02
 *   @0x2f7dd8 b 0x157fde8 <b2_toiTime+0xe26944>
 *   @0x2f7ddc andls r2, r3, #536870912
 *   @0x2f7de0 .word 0x2104f8d4
 *   @0x2f7de4 bne 0xff79e1f8 <b2_toiTime+0xffffffffff044d54>
 *   @0x2f7de8 svceq #0x92ebb1
 *   @0x2f7dec strtmi sp, [r0], -r5, lsl #18
 *   @0x2f7df0 movwls r2, #0x2108
 *   @0x2f7df4 blx 0xff675db0 <b2_toiTime+0xfffffffffef1c90c>
 *   @0x2f7df8 andhs r9, r0, #2048
 *   @0x2f7dfc .word 0x4692461f
 *   @0x2f7e00 ldrmi r9, [r10, #0xb03]
 *   @0x2f7e04 .word 0xf897d0ca
 *   @0x2f7e08 ldmdavc r9!, {r0, lr, pc}
 *   @0x2f7e0c mullt r3, r7, r8
 *   @0x2f7e10 .word 0x2c0cea4f
 *   @0x2f7e14 b 0x160ab24 <b2_toiTime+0xeb1680>
 *   @0x2f7e18 ldmvc r9!, {r0, r10, r11, lr}
 *   @0x2f7e1c .word 0x0c01ea4c
 *   @0x2f7e20 ldrmi r4, [r11, #0x4e3]
 *   @0x2f7e24 strtmi sp, [r0], -r9, lsl #18
 *   @0x2f7e28 andls r2, r2, #8, #2
 *   @0x2f7e2c andgt pc, r4, sp, asr #17
 *   @0x2f7e30 blx 0xfeef5dec <b2_toiTime+0xfffffffffe79c948>
 *   @0x2f7e34 .word 0xc004f8dd
 *   @0x2f7e38 ldrmi r9, [r4, #0xa02]
 *   @0x2f7e3c strtmi sp, [r0], -r3, lsl #4
 *   @0x2f7e40 .word 0xf7ed2108
 *   @0x2f7e44 .word 0xf10bfaa6
 *   @0x2f7e48 .word 0xf10a0201
 *   @0x2f7e4c strlo r0, [r4, -r1, lsl #20]
 *   @0x2f7e50 bl 0x4b1db0 <SrcVerts+0xedf4>
 *   @0x2f7e54 .word 0xf8d40a09
 *   @0x2f7e58 .word 0xf10a3104
 *   @0x2f7e5c addsmi r0, pc, #4, #14
 *   @0x2f7e60 strtmi sp, [r0], -r3, lsl #18
 *   @0x2f7e64 .word 0xf7ed2108
 *   @0x2f7e68 .word 0xf816fa94
 *   @0x2f7e6c mrshs r3, apsr
 *   @0x2f7e70 mulls r1, r10, r8
 *   @0x2f7e74 .word 0x0104f8d4
 *   @0x2f7e78 stmdbmi r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f7e7c b 0x153ed84 <b2_toiTime+0xde58e0>
 *   @0x2f7e80 .word 0xf89a6903
 *   @0x2f7e84 b 0x1543e98 <b2_toiTime+0xdea9f4>
 *   @0x2f7e88 .word 0xf89a0903
 *   @0x2f7e8c b 0x1543e9c <b2_toiTime+0xdea9f8>
 *   @0x2f7e90 .word 0xf0202903
 *   @0x2f7e94 strmi lr, [r1, #0xeda]
 *   @0x2f7e98 strtmi sp, [r0], -r3, lsl #18
 *   @0x2f7e9c .word 0xf7ed2108
 *   @0x2f7ea0 .word 0xf04ffa78
 *   @0x2f7ea4 .word 0xf8cd0b00
 *   @0x2f7ea8 blls 0x3e3ee0 <error_g0017+0x3cb84>
 *   @0x2f7eac eorsle r4, r0, r11, asr #10
 *   @0x2f7eb0 mulgt r1, r7, r8
 *   @0x2f7eb4 ldmvc r10!, {r0, r3, r4, r5, r11, r12, sp, lr} ^
 *   @0x2f7eb8 .word 0x2c0cea4f
 *   @0x2f7ebc b 0x16163b0 <b2_toiTime+0xebcf0c>
 *   @0x2f7ec0 ldmvc r9!, {r0, r10, r11, lr}
 *   @0x2f7ec4 b 0x161c6e0 <b2_toiTime+0xec323c>
 *   @0x2f7ec8 ldmdbmi r5, {r0, r9, r11}
 *   @0x2f7ecc strmi r9, [r10, #0x306]
 *   @0x2f7ed0 strtmi sp, [r0], -r3, lsl #18
 *   @0x2f7ed4 .word 0xf7ed2108
 *   @0x2f7ed8 ldrbmi pc, [r10, #0xa5c]
 *   @0x2f7edc strtmi sp, [r0], -r3, lsl #4
 *   @0x2f7ee0 .word 0xf7ed2108
 *   @0x2f7ee4 .word 0xf8d4fa56
 *   @0x2f7ee8 .word 0xf10a1108
 *   @0x2f7eec cmplt r9, r1, lsl #22
 *   @0x2f7ef0 bls 0x49eb0c <TimingData+0x4af4>
 *   @0x2f7ef4 ldrsbne pc, [r0, -r4]
 *   @0x2f7ef8 bhs 0x3f2808 <g_TextureWrapModeV+0x1c>
 *   @0x2f7efc movwle r4, #0x358a
 *   @0x2f7f00 tsths r0, r0, lsr #12
 *   @0x2f7f04 blx 0x1475ec0 <b2_toiTime+0xd1ca1c>
 *   @0x2f7f08 strlo r9, [r5, -r3, lsl #20]
 *   @0x2f7f0c andls r3, r3, #268435456
 *   @0x2f7f10 strlo lr, [r11, #-0x7cb]
 *   @0x2f7f14 andhs lr, r0, r9, lsl #14
 *   @0x2f7f18 pop {r0, r3, r12, sp, pc}
 *   @0x2f7f1c svclt #0x8ff0
 *   @0x2f7f20 ldrsheq pc, [r0], -pc
 *   @0x2f7f24 .word 0x9c03b530
 *   @0x2f7f28 .word 0xb1bcb1c3
 *   @0x2f7f2c ldrhpl pc, [r8], r0
 *   @0x2f7f30 eorvs r11, r5, r10, lsl #18
 *   @0x2f7f34 adcmi lr, r9, #16
 *   @0x2f7f38 .word 0xf8d0d212
 *   @0x2f7f3c swpeq r5, r12, [r9]
 *   @0x2f7f40 andsvs r5, r5, sp, ror #16
 *   @0x2f7f44 ldrsbhs pc, [r12], r0
 *   @0x2f7f48 ldmvs r2, {r1, r3, r10, lr}
 *   @0x2f7f4c .word 0xf8d0601a
 *   @0x2f7f50 ldrmi r3, [r9], #-156
 *   @0x2f7f54 eorvs r6, r3, r11, asr #17
 *   @0x2f7f58 ldclt p0, c2, [r0, #-0]!
 *   @0x2f7f5c ldclt p0, c2, [r0, #-24]!
 *   @0x2f7f60 ldclt p0, c2, [r0, #-568]!
 *   @0x2f7f64 .word 0x4604b538
 *   @0x2f7f68 strmi r7, [sp], -r3, lsl #28
 *   @0x2f7f6c stmibvs r2, {r0, r1, r3, r4, r6, r8, r12, sp, pc} ^
 *   @0x2f7f70 addsmi r6, r10, #720896
 *   @0x2f7f74 .word 0xf7fbd107
 *   @0x2f7f78 mcrvc p12, #0x1, pc, c0, c5, #0x6
 *   @0x2f7f7c stmibvs r3!, {r4, r6, r8, r12, sp, pc} ^
 *   @0x2f7f80 eorvs r6, r11, r0, lsr #20
 *   @0x2f7f84 qasxmi r11, r0, r8
 *   @0x2f7f88 andhs r4, r1, #42991616
 *   @0x2f7f8c ldrhtmi lr, [r8], -sp
 *   @0x2f7f90 ldclt p7, c15, [lr, #-1004]
 *   @0x2f7f94 ldrlt r11, [r8, #-0xd38]!
 *   @0x2f7f98 cdpvc p6, #0x0, c4, c3, c4, #0x0
 *   @0x2f7f9c cmplt r11, sp, lsl #12
 *   @0x2f7fa0 stmdavs r11, {r1, r6, r7, r8, r11, sp, lr}
 *   @0x2f7fa4 swple r4, r10, [r7]
 *   @0x2f7fa8 ldc2 p7, c15, [r11, #1004]!
 *   @0x2f7fac cmplt r0, r0, lsr #28
 *   @0x2f7fb0 bvs 0xb12744 <b2_toiTime+0x3b92a0>
 *   @0x2f7fb4 ldclt p0, c6, [r8, #-172]!
 *   @0x2f7fb8 strtmi r4, [r9], -r0, lsr #12
 *   @0x2f7fbc pop {r0, r9, sp}
 *   @0x2f7fc0 .word 0xf7fb4038
 *   @0x2f7fc4 ldclt p13, c11, [r8, #-1016]!
 *   @0x2f7fc8 .word 0x460db570
 *   @0x2f7fcc andvs pc, r4, #208, #16
 *   @0x2f7fd0 stmdbmi r9, {r1, r3, r5, r9, r10, lr}
 *   @0x2f7fd4 movwvc pc, #0x500
 *   @0x2f7fd8 ldrmi r4, [r0, r4, lsl #12]!
 *   @0x2f7fdc qsaxmi r11, r8, r0
 *   @0x2f7fe0 andne pc, r0, #212, #16
 *   @0x2f7fe4 rscsvc pc, lr, #4, #10
 *   @0x2f7fe8 .word 0xff5bf7ef
 *   @0x2f7fec movwhs r11, #0x110
 *   @0x2f7ff0 andlo pc, r0, #196, #16
 *   @0x2f7ff4 svclt #0xbd70
 *   @0x2f7ff8 .word 0x636d6170
 *   @0x2f7ffc svcmi #0xf0e92d
 *   @0x2f8000 cdpvs p0, #0x8, c11, c4, c11, #0x4
 *   @0x2f8004 .word 0xf8d0ab08
 *   @0x2f8008 strmi r5, [r6], -r4, lsl #4
 *   @0x2f800c strtmi r4, [r2], -r3, lsr #19
 *   @0x2f8010 strmi r4, [r5], -r8, lsr #15
 *   @0x2f8014 .word 0xf0402800
 *   @0x2f8018 qasxmi r8, r0, sp
 *   @0x2f801c ldc2 p7, c15, [r0], {238}
 *   @0x2f8020 .word 0xf8dd2120
 *   @0x2f8024 .word 0xf8d6a020
 *   @0x2f8028 pkhtbmi r7, r3, r12, asr #3
 *   @0x2f802c .word 0xf7ee4620
 *   @0x2f8030 .word 0x4605fc7f
 *   @0x2f8034 .word 0xf0402800
 *   @0x2f8038 .word 0xf5b7812d
 *   @0x2f803c .word 0xf0403f00
 *   @0x2f8040 stmdage r9, {r5, r6, r7, pc}
 *   @0x2f8044 andls r10, r4, r9, lsl #18
 *   @0x2f8048 .word 0xf8d44620
 *   @0x2f804c .word 0xf7ee801c
 *   @0x2f8050 blls 0x5775bc <g_SWFlineaavertbuff+0x244f4>
 *   @0x2f8054 blhs 0x309a60 <TT_New_Context+0x9858>
 *   @0x2f8058 tsthi r6, r0, asr #32
 *   @0x2f805c strhlo pc, [r8, -r6]
 *   @0x2f8060 vqsub.u8 d4, d16, d8
 *   @0x2f8064 bge 0x558404 <g_SWFlineaavertbuff+0x533c>
 *   @0x2f8068 andls r4, r1, #78643200
 *   @0x2f806c strls r4, [r0, #-0x640]
 *   @0x2f8070 strtmi r2, [r10], -r2, lsl #2
 *   @0x2f8074 .word 0xf80bf7f0
 *   @0x2f8078 andls r9, r6, r9, lsl #22
 *   @0x2f807c movwhs r11, #0x113
 *   @0x2f8080 adcs r9, r7, r3, lsl #6
 *   @0x2f8084 b 0x16c990c <b2_toiTime+0xf70468>
 *   @0x2f8088 .word 0xf7ef0149
 *   @0x2f808c andls pc, r9, r10, asr #29
 *   @0x2f8090 mvnsle r2, r0, lsl #16
 *   @0x2f8094 strbmi r4, [pc, #-0x62f]
 *   @0x2f8098 ble 0x489920 <g_circle_cos+0x7c>
 *   @0x2f809c stc2 p7, c15, [r9], #952
 *   @0x2f80a0 .word 0xf8229a06
 *   @0x2f80a4 smladlo r1, r7, r0, r0
 *   @0x2f80a8 .word 0xf7efe7f5
 *   @0x2f80ac movwhs pc, #0xf05
 *   @0x2f80b0 vmin.s8 d20, d0, d15
 *   @0x2f80b4 strbmi r1, [r11, #-0x101]
 *   @0x2f80b8 stmdals r6, {r2, r3, r9, r11, r12, lr, pc}
 *   @0x2f80bc andshs pc, r3, r0, lsr r8
 *   @0x2f80c0 stcle p2, c4, [r5, #-552]
 *   @0x2f80c4 addvc pc, r0, pc, ror #8
 *   @0x2f80c8 adcsmi r4, r10, #33554432
 *   @0x2f80cc addslt r11, r7, #200, #30
 *   @0x2f80d0 ldrb r3, [r0, r1, lsl #6]!
 *   @0x2f80d4 blge 0x5408dc <obj_has_event+0x5d6c>
 *   @0x2f80d8 strbmi r9, [r0], -r0, lsl #4
 *   @0x2f80dc .word 0x21049301
 *   @0x2f80e0 .word 0xf7ef463b
 *   @0x2f80e4 blls 0x57803c <g_SWFlineaavertbuff+0x24f74>
 *   @0x2f80e8 blhs 0x31c0fc
 *   @0x2f80ec addhi pc, r2, r0, asr #32
 *   @0x2f80f0 .word 0xf8cd44da
 *   @0x2f80f4 .word 0x469aa014
 *   @0x2f80f8 andls r3, r7, r4, lsl #16
 *   @0x2f80fc strhtle r4, [r3], #-90
 *   @0x2f8100 .word 0xf7ee4620
 *   @0x2f8104 bls 0x477180 <g_RomDisk+0x7f960>
 *   @0x2f8108 movwle r4, #0x4290
 *   @0x2f810c svclt #0x3845ba
 *   @0x2f8110 cmple r7, #0, #8
 *   @0x2f8114 qsaxmi lr, r0, r8
 *   @0x2f8118 .word 0xf7eea909
 *   @0x2f811c blls 0x57745c <g_SWFlineaavertbuff+0x24394>
 *   @0x2f8120 blx 0xfe336aa6 <b2_toiTime+0xfffffffffdbdd602>
 *   @0x2f8124 strhs r11, [r0], #-283
 *   @0x2f8128 strtmi r9, [r2], r3, lsl #26
 *   @0x2f812c blls 0x470290 <g_RomDisk+0x78a70>
 *   @0x2f8130 stmdble r8, {r0, r1, r3, r4, r7, r8, r10, lr}
 *   @0x2f8134 .word 0xf7ee4620
 *   @0x2f8138 bls 0x47714c <g_RomDisk+0x7f92c>
 *   @0x2f813c bleq 0x3b3044 <error_g0017+0xbce8>
 *   @0x2f8140 blvc 0xffdf29f4 <b2_toiTime+0xffffffffff699550>
 *   @0x2f8144 strtmi lr, [r0], -r7
 *   @0x2f8148 blx 0x1b610a <_ZN10ObjectPoolI19CLayerSpriteElementED2Ev+0x76>
 *   @0x2f814c bl 0xff5de968 <b2_toiTime+0xfffffffffee854c4>
 *   @0x2f8150 addsmi r0, r8, #134217728
 *   @0x2f8154 movwhs sp, #0x8ee
 *   @0x2f8158 ldrmi r2, [r10], -r1, lsl #2
 *   @0x2f815c stmdage r9, {r8, r9, r12, pc}
 *   @0x2f8160 movweq lr, #0x1b0b
 *   @0x2f8164 strbmi r9, [r0], -r1
 *   @0x2f8168 .word 0xff91f7ef
 *   @0x2f816c subsvs r9, r0, r7, lsl #20
 *   @0x2f8170 blls 0x54997c <gp_ActiveMaskObjects+0x4cb4>
 *   @0x2f8174 bicsle r2, r6, r0, lsl #22
 *   @0x2f8178 ldrbmi r4, [r10], -r0, lsr #12
 *   @0x2f817c .word 0xfc07f7ee
 *   @0x2f8180 stmdahs r0, {r0, r3, r12, pc}
 *   @0x2f8184 bls 0x4ec8c8 <SrcVerts+0x4990c>
 *   @0x2f8188 beq 0x3745b8 <_ZTS13C_UTF16String+0xb664>
 *   @0x2f818c blx 0xfe5b6a10 <b2_toiTime+0xfffffffffde5d56c>
 *   @0x2f8190 svclo #0x4f852
 *   @0x2f8194 .word 0xf8039207
 *   @0x2f8198 str r0, [pc, r11]!
 *   @0x2f819c bge 0x5405a8 <obj_has_event+0x5a38>
 *   @0x2f81a0 andls r4, r1, #11534336
 *   @0x2f81a4 strbmi r9, [r0], -r0, lsl #8
 *   @0x2f81a8 .word 0xf7ef2200
 *   @0x2f81ac blls 0x3f7f74 <g_RomDisk+0x754>
 *   @0x2f81b0 eoreq pc, r10, r3, asr #16
 *   @0x2f81b4 blhs 0x31ede0
 *   @0x2f81b8 .word 0xf10ad1b5
 *   @0x2f81bc andvc r0, r3, r1, lsl #20
 *   @0x2f81c0 blx 0xfe5b6a44 <b2_toiTime+0xfffffffffde5d5a0>
 *   @0x2f81c4 strhle r4, [r9, #90]!
 *   @0x2f81c8 stmdals r3, {r1, r2, r8, r9, r11, r12, pc}
 *   @0x2f81cc rsbsls pc, r8, #10878976
 *   @0x2f81d0 rsbsvc pc, r10, #10878976
 *   @0x2f81d4 rsbslo pc, r12, #12976128
 *   @0x2f81d8 addeq pc, r0, #12976128
 *   @0x2f81dc adcsmi lr, r12, #87
 *   @0x2f81e0 strlo sp, [r1], #-8
 *   @0x2f81e4 strbmi r6, [r0], -r9, lsr #16
 *   @0x2f81e8 .word 0xf8a5f7ef
 *   @0x2f81ec .word 0xf845b2a4
 *   @0x2f81f0 ldrb r10, [r4, r4, lsl #22]!
 *   @0x2f81f4 stmdbls r3, {r6, r9, r10, lr}
 *   @0x2f81f8 .word 0xf89df7ef
 *   @0x2f81fc stmdbls r6, {r6, r9, r10, lr}
 *   @0x2f8200 .word 0xf5b7e040
 *   @0x2f8204 .word 0xd1413f20
 *   @0x2f8208 stmdaeq r4!, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x2f820c .word 0xf8d44620
 *   @0x2f8210 .word 0x4641901c
 *   @0x2f8214 ldc2l p7, c15, [r6], #-952
 *   @0x2f8218 strmi r9, [r7], -r9, lsl #22
 *   @0x2f821c teqle r3, r0, lsl #22
 *   @0x2f8220 strhlo pc, [r8, -r6]
 *   @0x2f8224 .word 0xdc044298
 *   @0x2f8228 addslt r1, r11, #1072
 *   @0x2f822c svcvc #0x81f5b3
 *   @0x2f8230 movwhs sp, #0x3302
 *   @0x2f8234 eor r9, r7, r9, lsl #6
 *   @0x2f8238 smlawbeq r0, sp, r8, lr
 *   @0x2f823c .word 0x4648463b
 *   @0x2f8240 strtmi r2, [r10], -r1, lsl #2
 *   @0x2f8244 .word 0xff23f7ef
 *   @0x2f8248 strmi r9, [r0], r9, lsl #22
 *   @0x2f824c strtmi r11, [r0], -r3, asr #19
 *   @0x2f8250 ldrtmi r4, [r10], -r1, asr #12
 *   @0x2f8254 blx 0xfe9f6216 <b2_toiTime+0xfffffffffe29cd72>
 *   @0x2f8258 stmiblt r8, {r0, r3, r12, pc}
 *   @0x2f825c .word 0xf918462b
 *   @0x2f8260 ldmne r10, {r0, r1, sp}
 *   @0x2f8264 adcsmi sp, r10, #16777216
 *   @0x2f8268 movwhs sp, #0x3d02
 *   @0x2f826c and r9, r7, r9, lsl #6
 *   @0x2f8270 adcsmi r3, r11, #67108864
 *   @0x2f8274 .word 0xf8a6dbf3
 *   @0x2f8278 .word 0xf8c67278
 *   @0x2f827c and r8, r6, r12, ror r2
 *   @0x2f8280 strbmi r4, [r1], -r8, asr #12
 *   @0x2f8284 .word 0xf857f7ef
 *   @0x2f8288 and r9, r0, r9, lsl #26
 *   @0x2f828c movwhs r2, #0x1503
 *   @0x2f8290 rsbslo pc, r4, #8781824
 *   @0x2f8294 andlt r4, r11, r8, lsr #12
 *   @0x2f8298 svchi #0xf0e8bd
 *   @0x2f829c rsbvc r7, pc, r4, ror r3
 *   @0x2f82a0 .word 0x460db5f8
 *   @0x2f82a4 .word 0x46044616
 *   @0x2f82a8 subsle r2, r6, r0, lsl #16
 *   @0x2f82ac strhlo pc, [r8, -r0]
 *   @0x2f82b0 subsle r4, r4, #-1879048183
 *   @0x2f82b4 eorvc pc, r0, #208, #16
 *   @0x2f82b8 suble r2, r12, r0, lsl #30
 *   @0x2f82bc andhs r6, r0, r11, lsr r9
 *   @0x2f82c0 mlasvs r0, r8, r7, r4
 *   @0x2f82c4 ldrsblo pc, [r12, #132]
 *   @0x2f82c8 svclo #0x80f5b3
 *   @0x2f82cc .word 0xf5b5d105
 *   @0x2f82d0 eorsle r7, lr, #516
 *   @0x2f82d4 qasxmi r6, r8, r11
 *   @0x2f82d8 .word 0xf5b3e039
 *   @0x2f82dc .word 0xd1203f00
 *   @0x2f82e0 rsbslo pc, r4, #148, #16
 *   @0x2f82e4 rfeia r4!
 *   @0x2f82e8 addsmi r3, sp, #120, #4
 *   @0x2f82ec eors sp, r0, r6, lsl #6
 *   @0x2f82f0 .word 0xf7ff4620
 *   @0x2f82f4 stmdahs r0, {r0, r1, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f82f8 .word 0xe02ad0f5
 *   @0x2f82fc rsbslo pc, r12, #212, #16
 *   @0x2f8300 andseq pc, r5, r3, lsr r8
 *   @0x2f8304 svcvc #0x81f5b0
 *   @0x2f8308 ldmdbvs r11!, {r0, r9, r12, lr, pc}
 *   @0x2f830c .word 0xf8d4e01f
 *   @0x2f8310 cps #0x0
 *   @0x2f8314 .word 0xf5a04080
 *   @0x2f8318 .word 0xf8537081
 *   @0x2f831c eorsvs r3, r3, r0, lsr #32
 *   @0x2f8320 .word 0xf5b3e017
 *   @0x2f8324 tstle r4, r0, lsr #30
 *   @0x2f8328 rsbslo pc, r4, #148, #16
 *   @0x2f832c rfeia r4!
 *   @0x2f8330 addsmi r3, sp, #120, #4
 *   @0x2f8334 .word 0xf8d4d20d
 *   @0x2f8338 .word 0x5758327c
 *   @0x2f833c strtmi r6, [r8], #-2363
 *   @0x2f8340 strtmi lr, [r0], -r5
 *   @0x2f8344 mrc2 p7, #0x2, apsr_nzcv, c10, c15, #0x7
 *   @0x2f8348 rscsle r2, r0, r0, lsl #16
 *   @0x2f834c ldrmi lr, [r8, r1]
 *   @0x2f8350 andhs r6, r0, r0, lsr r0
 *   @0x2f8354 strdhs r11, r12, [r7], -r8
 *   @0x2f8358 .word 0x2023bdf8
 *   @0x2f835c ldrshhs r11, [r0], -r8
 *   @0x2f8360 push {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2f8364 .word 0x460641f3
 *   @0x2f8368 strmi r6, [pc], -r5, lsl #18
 *   @0x2f836c ble 0x343774
 *   @0x2f8370 ands r2, r3, r0
 *   @0x2f8374 stmdaeq r4, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x2f8378 adcmi r2, r12, #0, #8
 *   @0x2f837c shsub8mi sp, r0, r8
 *   @0x2f8380 strbmi r4, [r2], -r1, lsr #12
 *   @0x2f8384 .word 0xff8cf7ff
 *   @0x2f8388 shasxmi r11, r8, r0
 *   @0x2f838c .word 0xf5be9901
 *   @0x2f8390 stmdblt r8, {r1, r4, r5, r6, r7, r11, sp, lr, pc}
 *   @0x2f8394 and r4, r1, r0, lsr #12
 *   @0x2f8398 strb r3, [lr, r1, lsl #8]!
 *   @0x2f839c pop {r1, r12, sp, pc}
 *   @0x2f83a0 ldrblt r8, [r3, #-0x1f0]!
 *   @0x2f83a4 bge 0x349c00
 *   @0x2f83a8 .word 0xf7ff461e
 *   @0x2f83ac .word 0x4604ff79
 *   @0x2f83b0 strtmi r11, [r8], -r0, lsr #18
 *   @0x2f83b4 ldrtmi r9, [r2], -r1, lsl #18
 *   @0x2f83b8 blx 0xfe876380 <b2_toiTime+0xfffffffffe11cedc>
 *   @0x2f83bc andlt r4, r2, r0, lsr #12
 *   @0x2f83c0 andeq r11, r0, r0, ror sp
 *   @0x2f83c4 svcmi #0xf0e92d
 *   @0x2f83c8 ldrmi r11, [r9], pc, lsl #1
 *   @0x2f83cc .word 0xf8d0ae18
 *   @0x2f83d0 .word 0x460532f8
 *   @0x2f83d4 ldm r6, {r4, r7, r9, r10, lr}
 *   @0x2f83d8 blhs 0x2f96e0 <ps_hints_apply+0x82e0>
 *   @0x2f83dc rscshi pc, r4, r0
 *   @0x2f83e0 stmdble r0!, {r1, r8, r9, r11, sp}
 *   @0x2f83e4 .word 0xf0402b03
 *   @0x2f83e8 .word 0xf8d080ef
 *   @0x2f83ec .word 0xf04f3300
 *   @0x2f83f0 .word 0xf8df0905
 *   @0x2f83f4 .word 0xf853b264
 *   @0x2f83f8 movwhs r1, #0x21
 *   @0x2f83fc andlo pc, r2, r10, lsr #17
 *   @0x2f8400 andlo pc, r0, r10, lsr #17
 *   @0x2f8404 .word 0xf8d03102
 *   @0x2f8408 bl 0x380fd0 <_ZTS13C_UTF16String+0x1807c>
 *   @0x2f840c .word 0xf8120381
 *   @0x2f8410 ldmdavc pc, {r0, r5, sp} ^
 *   @0x2f8414 b 0x14b9518 <b2_toiTime+0xd60074>
 *   @0x2f8418 ldmvc r10, {r1, r8, r9, r10, sp, lr} ^
 *   @0x2f841c tstmi r7, #10158080
 *   @0x2f8420 strhs lr, [r3, -r7, asr #20]
 *   @0x2f8424 .word 0xf8d0e0ba
 *   @0x2f8428 cdpvs p3, #0x8, c3, c6, c0, #0x0
 *   @0x2f842c eorlt pc, r1, r3, asr r8
 *   @0x2f8430 teqlo r12, #208, #16
 *   @0x2f8434 .word 0xf0002b00
 *   @0x2f8438 ldrtmi r8, [r0], -r3, lsl #2
 *   @0x2f843c teqne r8, #13959168
 *   @0x2f8440 blx 0xf76400 <b2_toiTime+0x81cf5c>
 *   @0x2f8444 stmdahs r0, {r2, r9, r10, lr}
 *   @0x2f8448 rscshi pc, r11, r0, asr #32
 *   @0x2f844c .word 0xf8d56d6b
 *   @0x2f8450 movtlo r2, #0xc2f0
 *   @0x2f8454 .word 0xf8d59305
 *   @0x2f8458 .word 0xf88d3338
 *   @0x2f845c .word 0xf88d001c
 *   @0x2f8460 movwls r0, #0x801d
 *   @0x2f8464 teqlo r12, #13959168
 *   @0x2f8468 strls r9, [r4], -r3, lsl #10
 *   @0x2f846c .word 0xf8d59309
 *   @0x2f8470 .word 0xf8cd32f4
 *   @0x2f8474 ldmne r1, {r3, r4, sp, pc} ^
 *   @0x2f8478 teqhs r0, sp, lsl #2
 *   @0x2f847c blx 0x35ccb6 <_ZTS7CFontGM+0x37e>
 *   @0x2f8480 .word 0xf101f10b
 *   @0x2f8484 addsmi r0, r8, #55
 *   @0x2f8488 addhi pc, sp, r0, lsl #4
 *   @0x2f848c ldmdane r6, {r3, r8, r12, sp} ^
 *   @0x2f8490 ldmdavc r2!, {r0, r4, r6, r10, r11, r12, lr} ^
 *   @0x2f8494 b 0x13794e4 <b2_toiTime+0xc20040>
 *   @0x2f8498 ldmvc r1!, {r0, r9, sp, lr} ^
 *   @0x2f849c ldmvc r1!, {r1, r3, r8, r9, lr}
 *   @0x2f84a0 andhs lr, r1, #270336
 *   @0x2f84a4 bvc 0x1f5ccd4 <b2_toiTime+0x1803830>
 *   @0x2f84a8 bvc 0xf08f18 <b2_toiTime+0x7afa74>
 *   @0x2f84ac .word 0x4101ea4f
 *   @0x2f84b0 .word 0x6100ea41
 *   @0x2f84b4 b 0x135707c <b2_toiTime+0xbfdbd8>
 *   @0x2f84b8 bvc 0xfeef88c0 <b2_toiTime+0xfffffffffe79f41c>
 *   @0x2f84bc .word 0x2100ea41
 *   @0x2f84c0 .word 0xf896910b
 *   @0x2f84c4 .word 0xf88d002e
 *   @0x2f84c8 stmdale r12!, {r1, r2, r3, r4} ^
 *   @0x2f84cc bl 0xfef3ef40 <b2_toiTime+0xfffffffffe7e5a9c>
 *   @0x2f84d0 stmdale r8!, {r0, r1, r4, r6, r7, r8, r9, r10, r11} ^
 *   @0x2f84d4 .word 0xf8d5e07a
 *   @0x2f84d8 addsmi r3, pc, #60, #6
 *   @0x2f84dc .word 0xf108d263
 *   @0x2f84e0 blne 0xff9ba4f4 <b2_toiTime+0xffffffffff261050>
 *   @0x2f84e4 stmeq r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f84e8 cmple r12, #281018368
 *   @0x2f84ec teqlo r8, #13959168
 *   @0x2f84f0 stmdaeq r12, {r3, r5, r7, r8, r12, sp, lr, pc}
 *   @0x2f84f4 movwlo r4, #0x4630
 *   @0x2f84f8 strbmi r1, [r1], #-2521
 *   @0x2f84fc .word 0xf9d3f7ee
 *   @0x2f8500 stmdahs r0, {r2, r9, r10, lr}
 *   @0x2f8504 addshi pc, sp, r0, asr #32
 *   @0x2f8508 .word 0x21084630
 *   @0x2f850c stc2 p7, c15, [r9], {239}
 *   @0x2f8510 stmdahs r0, {r2, r9, r10, lr}
 *   @0x2f8514 addshi pc, r5, r0, asr #32
 *   @0x2f8518 .word 0xf7ee4630
 *   @0x2f851c .word 0x4604fa9e
 *   @0x2f8520 .word 0xf7ee4630
 *   @0x2f8524 pkhbtmi pc, r0, r10, lsl #21
 *   @0x2f8528 .word 0xf7ef4630
 *   @0x2f852c strbmi pc, [r4, #-0xcc5]
 *   @0x2f8530 ldmdale r8!, {r0, r1, r2, r4, r5, r12, lr, pc}
 *   @0x2f8534 beq 0x53344c <g_pPNGFile+0x480>
 *   @0x2f8538 svceq #0x7f1ba
 *   @0x2f853c .word 0xf8d5d933
 *   @0x2f8540 blne 0xff781238 <b2_toiTime+0xffffffffff027d94>
 *   @0x2f8544 .word 0xd32e4542
 *   @0x2f8548 teqne r8, #13959168
 *   @0x2f854c ldrtmi r4, [r9], #-1584
 *   @0x2f8550 .word 0xf7ee4421
 *   @0x2f8554 strmi pc, [r4], -r8, lsr #19
 *   @0x2f8558 cmnle r2, r0, lsl #16
 *   @0x2f855c uasxmi r4, r1, r0
 *   @0x2f8560 mrrc2 p7, #0xe, pc, pc, c15
 *   @0x2f8564 stmdahs r0, {r2, r9, r10, lr}
 *   @0x2f8568 ldrtmi sp, [r0], -r11, ror #2
 *   @0x2f856c blx 0x137652c <b2_toiTime+0xc1d088>
 *   @0x2f8570 .word 0xf7ee4630
 *   @0x2f8574 shasxmi pc, r0, lr
 *   @0x2f8578 blx 0x1ef6538 <b2_toiTime+0x179d094>
 *   @0x2f857c addsmi r4, r8, #52224
 *   @0x2f8580 ldmdale r2, {r0, r1, r3, r4, r12, lr, pc}
 *   @0x2f8584 tstle r6, r8, asr r5
 *   @0x2f8588 stmdbeq r1, {r0, r3, r4, r5, r7, r8, r12, sp, lr, pc}
 *   @0x2f858c shadd16mi sp, r0, r7
 *   @0x2f8590 blx 0xef6550 <b2_toiTime+0x79d0ac>
 *   @0x2f8594 ldrtmi r4, [r0], -r0, lsl #13
 *   @0x2f8598 stc2 p7, c15, [lr], {239}
 *   @0x2f859c ldrmi r6, [r8, #0x92b]
 *   @0x2f85a0 strhs sp, [r6], #-2457
 *   @0x2f85a4 strhs lr, [r3], #-77
 *   @0x2f85a8 blmi 0xd706dc <b2_toiTime+0x617238>
 *   @0x2f85ac mulle r4, r8, r2
 *   @0x2f85b0 addsmi r4, r8, #40, #22
 *   @0x2f85b4 strhs sp, [r7], #-1
 *   @0x2f85b8 strhs lr, [r2], #-2
 *   @0x2f85bc strhs lr, [r3], #-0
 *   @0x2f85c0 .word 0xf7ef4630
 *   @0x2f85c4 eors pc, r12, r9, ror r12
 *   @0x2f85c8 eors r2, r10, r2, lsl #8
 *   @0x2f85cc strls r10, [r0], #-3587
 *   @0x2f85d0 orrpl pc, r0, #603979779
 *   @0x2f85d4 movwls r4, #0x1622
 *   @0x2f85d8 qasxmi r4, r3, r0
 *   @0x2f85dc .word 0xf7fd4641
 *   @0x2f85e0 .word 0x4604fbf5
 *   @0x2f85e4 .word 0xf419bb68
 *   @0x2f85e8 smulwble r10, r0, pc
 *   @0x2f85ec blhs 0x4d78e0 <SrcVerts+0x34924>
 *   @0x2f85f0 stclvs p1, c13, [r11, #-156]!
 *   @0x2f85f4 .word 0xf8d34630
 *   @0x2f85f8 .word 0xf01c8000
 *   @0x2f85fc .word 0x4639f9df
 *   @0x2f8600 movwhs r4, #0x1632
 *   @0x2f8604 .word 0xf01c4640
 *   @0x2f8608 strmi pc, [r4], -r3, ror #20
 *   @0x2f860c strbmi r11, [r0], -r0, lsr #2
 *   @0x2f8610 .word 0xf01c4631
 *   @0x2f8614 ands pc, r4, r3, lsl #24
 *   @0x2f8618 mulslo lr, sp, r8
 *   @0x2f861c ldrtvc r9, [r11], #2310
 *   @0x2f8620 adcsvs r9, r11, r5, lsl #22
 *   @0x2f8624 ldrhlo pc, [r12], -sp
 *   @0x2f8628 stclvs p2, c8, [r8, #-236]!
 *   @0x2f862c .word 0xff92f7ee
 *   @0x2f8630 .word 0xf8d36d6b
 *   @0x2f8634 ldmdavs r10, {r2, r3, r4, r7, r12, sp} ^
 *   @0x2f8638 andeq pc, r1, #66
 *   @0x2f863c and r6, r0, r10, asr r0
 *   @0x2f8640 strtmi r2, [r0], -lr, lsl #9
 *   @0x2f8644 pop {r0, r1, r2, r3, r12, sp, pc}
 *   @0x2f8648 svclt #0x8ff0
 *   @0x2f864c bvs 0x1f122d4 <b2_toiTime+0x17b8e30>
 *   @0x2f8650 rsbvc r6, r7, #108, #4
 *   @0x2f8654 strbtvc r6, [r9], #-1638
 *   @0x2f8658 ldrbtvs r7, [r5], #-101
 *   @0x2f865c .word 0x460db570
 *   @0x2f8660 andvs pc, r4, #208, #16
 *   @0x2f8664 movwhs r4, #0x611
 *   @0x2f8668 strmi r4, [r4], -r10, lsr #12
 *   @0x2f866c ldmdblt r0, {r4, r5, r7, r8, r9, r10, lr} ^
 *   @0x2f8670 strtmi r4, [r8], -r5, lsl #18
 *   @0x2f8674 adceq pc, r0, #4, #2
 *   @0x2f8678 .word 0xf5014479
 *   @0x2f867c pop {r0, r2, r4, r8, r12, sp, lr}
 *   @0x2f8680 .word 0xf7ef4070
 *   @0x2f8684 ldcllt p12, c11, [r0, #-156]!
 *   @0x2f8688 andeq r7, r10, r8, ror #9
 *   @0x2f868c .word 0xf7ff4a01
 *   @0x2f8690 svclt #0xbfe5
 *   @0x2f8694 rsbvs r6, r8, #100, #10
 *   @0x2f8698 .word 0xf7ff4a01
 *   @0x2f869c svclt #0xbfdf
 *   @0x2f86a0 stmdavs r5!, {r2, r5, r6, r8, sp, lr} ^
 *   @0x2f86a4 mvnsmi lr, sp, lsr #18
 *   @0x2f86a8 .word 0xf8d0460e
 *   @0x2f86ac ldrtmi r5, [r2], -r4, lsl #4
 *   @0x2f86b0 movwhs r4, #0x926
 *   @0x2f86b4 strmi r4, [r8, r4, lsl #12]!
 *   @0x2f86b8 stmdahs r0, {r0, r2, r9, r10, lr}
 *   @0x2f86bc .word 0xf8dfd142
 *   @0x2f86c0 .word 0xf5048090
 *   @0x2f86c4 .word 0x463077ba
 *   @0x2f86c8 shsub8mi r4, r10, r8
 *   @0x2f86cc .word 0x712af508
 *   @0x2f86d0 .word 0xfc00f7ef
 *   @0x2f86d4 bllt 0xfed09ef0 <b2_toiTime+0xfffffffffe5b0a4c>
 *   @0x2f86d8 .word 0x73fff64f
 *   @0x2f86dc bicslo pc, r8, r4, lsr #17
 *   @0x2f86e0 ldrhlo pc, [r4, #-132]!
 *   @0x2f86e4 biceq pc, r4, r4, asr #17
 *   @0x2f86e8 biceq pc, r8, r4, asr #17
 *   @0x2f86ec biceq pc, r12, r4, lsr #17
 *   @0x2f86f0 biceq pc, lr, r4, lsr #17
 *   @0x2f86f4 bicseq pc, r0, r4, lsr #17
 *   @0x2f86f8 bicseq pc, r2, r4, lsr #17
 *   @0x2f86fc bicseq pc, r4, r4, lsr #17
 *   @0x2f8700 bicseq pc, r6, r4, lsr #17
 *   @0x2f8704 shsub8mi r11, r0, r3
 *   @0x2f8708 cmpvc r6, r8, lsl #10
 *   @0x2f870c .word 0xf7ef463a
 *   @0x2f8710 ldmiblt r0!, {r0, r5, r6, r7, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f8714 ldrhlo pc, [r4, #-132]!
 *   @0x2f8718 ldmdble r3, {r0, r8, r9, r11, sp}
 *   @0x2f871c .word 0xf5084630
 *   @0x2f8720 shsaxmi r7, r10, r10
 *   @0x2f8724 blx 0xff8b66ea <b2_toiTime+0xffffffffff15d246>
 *   @0x2f8728 rfeia r4!
 *   @0x2f872c blhs 0x404d04 <g_RomDisk+0xd4e4>
 *   @0x2f8730 ldrtmi sp, [r0], -r8, lsl #18
 *   @0x2f8734 .word 0x7161f508
 *   @0x2f8738 pop {r1, r3, r4, r5, r9, r10, lr}
 *   @0x2f873c .word 0xf7ef41f0
 *   @0x2f8740 strmi r11, [r5], -r9, asr #23
 *   @0x2f8744 pop {r3, r5, r9, r10, lr}
 *   @0x2f8748 svclt #0x81f0
 *   @0x2f874c svcmi #0x532f32
 *   @0x2f8750 muleq r10, r8, r4
 *   @0x2f8754 stcne p5, c11, [r3, #-448]
 *   @0x2f8758 .word 0x2104f8d1
 *   @0x2f875c strmi r4, [r12], -r5, lsl #12
 *   @0x2f8760 andle r4, r3, #-1610612727
 *   @0x2f8764 .word 0x21084608
 *   @0x2f8768 cdp2 p7, #0x1, c15, c3, c12, #0x7
 *   @0x2f876c stmvc r11!, {r1, r3, r5, r7, r11, r12, sp, lr} ^
 *   @0x2f8770 .word 0x1104f8d4
 *   @0x2f8774 movwhs lr, #0x2a43
 *   @0x2f8778 addsmi r1, r1, #15335424
 *   @0x2f877c .word 0xf5b3d302
 *   @0x2f8780 andle r7, r3, #524
 *   @0x2f8784 .word 0x21084620
 *   @0x2f8788 cdp2 p7, #0x0, c15, c3, c12, #0x7
 *   @0x2f878c .word 0x3108f8d4
 *   @0x2f8790 stcne p1, c11, [lr, #460]!
 *   @0x2f8794 strvc pc, [r3, #0x505]
 *   @0x2f8798 blhs 0x3767f8 <_ZTS13C_UTF16String+0xd8a4>
 *   @0x2f879c ldrsblo pc, [r0, -r4]
 *   @0x2f87a0 movwle r4, #0x329a
 *   @0x2f87a4 tsths r0, r0, lsr #12
 *   @0x2f87a8 ldc2l p7, c15, [r3, #944]!
 *   @0x2f87ac mvnsle r4, lr, lsr #5
 *   @0x2f87b0 ldcllt p0, c2, [r0, #-0]!
 *   @0x2f87b4 svcmi #0xf0e92d
 *   @0x2f87b8 .word 0xf8d04604
 *   @0x2f87bc addslt r6, r3, r8, lsr #5
 *   @0x2f87c0 .word 0xf0402e00
 *   @0x2f87c4 .word 0xf8d082f9
 *   @0x2f87c8 blhs 0x3052b0 <TT_New_Context+0x50a8>
 *   @0x2f87cc sbcshi pc, r2, #0
 *   @0x2f87d0 sbclo pc, r4, #208, #16
 *   @0x2f87d4 .word 0x8064f8d0
 *   @0x2f87d8 eorls pc, r4, #208, #16
 *   @0x2f87dc teqle sp, r0, lsl #22
 *   @0x2f87e0 stcge p15, c10, [r12, #-44]
 *   @0x2f87e4 shadd16mi r2, r10, r9
 *   @0x2f87e8 .word 0xf7fa462b
 *   @0x2f87ec ldmdblt r8!, {r0, r1, r3, r4, r5, r6, r9, r11, r12, sp, lr, pc} ^
 *   @0x2f87f0 tsths r0, r0, lsr #12
 *   @0x2f87f4 qasxmi r4, r11, r10
 *   @0x2f87f8 blx 0x20367e8 <b2_toiTime+0x18dd344>
 *   @0x2f87fc strtmi r11, [r0], -r0, asr #18
 *   @0x2f8800 ldrtmi r2, [r10], -r1, lsl #2
 *   @0x2f8804 .word 0xf7fa462b
 *   @0x2f8808 stmdahs r0, {r0, r2, r3, r5, r6, r9, r11, r12, sp, lr, pc}
 *   @0x2f880c adchi pc, pc, #0
 *   @0x2f8810 .word 0x21009d0b
 *   @0x2f8814 .word 0x91002214
 *   @0x2f8818 .word 0xf8d41c68
 *   @0x2f881c cdpvs p1, #0x6, c3, c0, c4, #0x3
 *   @0x2f8820 ldrsbne pc, [r0, #-132]!
 *   @0x2f8824 blx 0x3ac846 <error_g0017+0x54ea>
 *   @0x2f8828 blmi 0xfefc5044 <b2_toiTime+0xfffffffffe86bba0>
 *   @0x2f882c .word 0xf7fc447b
 *   @0x2f8830 and pc, r6, pc, lsl #26
 *   @0x2f8834 blx 0x39fc6e <ft_standard_glyph_names+0xf7a>
 *   @0x2f8838 blmi 0xfef05054 <b2_toiTime+0xfffffffffe7abbb0>
 *   @0x2f883c .word 0xf7fc447b
 *   @0x2f8840 .word 0x4605fd56
 *   @0x2f8844 mrc p5, #0x3, apsr_nzcv, c8, c13, #0x5
 *   @0x2f8848 stmdble r3, {r0, r1, r3, r4, r6, r11, sp}
 *   @0x2f884c movwhs r2, #0x5b
 *   @0x2f8850 subslo pc, r11, r5, lsl #17
 *   @0x2f8854 sbcpl pc, r4, #196, #16
 *   @0x2f8858 sbceq pc, r8, #196, #16
 *   @0x2f885c bge 0x56348c <g_SWFlineaavertbuff+0x103c4>
 *   @0x2f8860 strtmi r9, [r0], -r0, lsl #6
 *   @0x2f8864 .word 0xf8d92300
 *   @0x2f8868 stmdbge r8, {r2, r3, r4, r12, lr}
 *   @0x2f886c stmdavs r2!, {r3, r5, r7, r8, r9, r10, lr} ^
 *   @0x2f8870 mulsmi r3, sp, r11
 *   @0x2f8874 subsle r2, r12, r0, lsl #22
 *   @0x2f8878 .word 0xf04f141b
 *   @0x2f887c bllo 0x33acb4
 *   @0x2f8880 andsvc pc, r12, #212, #16
 *   @0x2f8884 .word 0xf903fb09
 *   @0x2f8888 ldmdbvs r11, {r1, r3, r8, r9, r11, r12, pc}
 *   @0x2f888c ldmvs r9, {r0, r1, r3, r6, r10, lr}
 *   @0x2f8890 movwls r2, #0xd300
 *   @0x2f8894 andle r2, r4, r6, lsl #18
 *   @0x2f8898 orrvc pc, r0, #675282944
 *   @0x2f889c svcmi #0xfef5b3
 *   @0x2f88a0 svcvs #0x7dd204
 *   @0x2f88a4 addlt r4, r9, #32, #12
 *   @0x2f88a8 strmi r10, [r8, sp, lsl #20]!
 *   @0x2f88ac .word 0xb12d9d0d
 *   @0x2f88b0 .word 0xf5bd4628
 *   @0x2f88b4 andlo lr, r1, r2, asr #28
 *   @0x2f88b8 .word 0xe121182e
 *   @0x2f88bc strtmi r9, [r0], -r10, lsl #22
 *   @0x2f88c0 bge 0x6946bc <g_SWFlinevertbuff+0x415f4>
 *   @0x2f88c4 strbmi r6, [r11], #-2331
 *   @0x2f88c8 .word 0x47a88899
 *   @0x2f88cc orrlt r9, r0, #917504
 *   @0x2f88d0 mrc p5, #0x1, apsr_nzcv, c2, c13, #0x5
 *   @0x2f88d4 sbcne pc, r8, #212, #16
 *   @0x2f88d8 .word 0x3102aa07
 *   @0x2f88dc strbmi r4, [r0], -r1, lsl #8
 *   @0x2f88e0 stc2 p7, c15, [r1], #-952
 *   @0x2f88e4 strmi r9, [r5], -r7, lsl #22
 *   @0x2f88e8 .word 0xf0402b00
 *   @0x2f88ec .word 0xf8d48240
 *   @0x2f88f0 .word 0xf5bd12c4
 *   @0x2f88f4 .word 0xf8d4ee58
 *   @0x2f88f8 smlawths sp, r8, r2, r2
 *   @0x2f88fc strtpl r1, [r9], #2219
 *   @0x2f8900 stmdbls lr, {r0, r8, r9, r12, sp}
 *   @0x2f8904 .word 0xf8113901
 *   @0x2f8908 cmplt r10, r1, lsl #30
 *   @0x2f890c eorseq pc, r0, r2, lsr #3
 *   @0x2f8910 stmdble r4, {r0, r3, r11, sp}
 *   @0x2f8914 eoreq pc, r0, r2, lsr #32
 *   @0x2f8918 ldmdahs r9, {r0, r6, r11, r12, sp}
 *   @0x2f891c ldrshvc sp, [r10], -r3
 *   @0x2f8920 ldrb r3, [r0, r1, lsl #6]!
 *   @0x2f8924 .word 0x4640701a
 *   @0x2f8928 mrrcne p9, #0x0, r9, lr, c14
 *   @0x2f892c stc2 p7, c15, [r3, #-952]
 *   @0x2f8930 blls 0x5b0cd0 <g_SWFlineaavertbuff+0x5dc08>
 *   @0x2f8934 .word 0xf8d42211
 *   @0x2f8938 strbmi r1, [r0], -r8, asr #5
 *   @0x2f893c ldrdlo r6, r7, [r1, -pc]
 *   @0x2f8940 blx 0x39f56a <ft_standard_glyph_names+0x876>
 *   @0x2f8944 bge 0x4bcd58 <SrcVerts+0x19d9c>
 *   @0x2f8948 blx 0xffe7690a <b2_toiTime+0xffffffffff71d466>
 *   @0x2f894c ldrsbls pc, [r12], -sp
 *   @0x2f8950 .word 0xf1b94605
 *   @0x2f8954 .word 0xf0400f00
 *   @0x2f8958 .word 0xf8d4820a
 *   @0x2f895c .word 0xf10d12c4
 *   @0x2f8960 .word 0xf5bd0a38
 *   @0x2f8964 .word 0xf8d4ee20
 *   @0x2f8968 .word 0xf04f62c8
 *   @0x2f896c strtmi r0, [lr], #-2058
 *   @0x2f8970 ldrmi r9, [r9, #0xb08]
 *   @0x2f8974 sbchi pc, r4, r0, lsl #1
 *   @0x2f8978 ldmdavs r10, {r0, r3, r8, r9, r11, r12, pc}
 *   @0x2f897c addsmi r6, r10, #12255232
 *   @0x2f8980 adchi pc, r11, r0
 *   @0x2f8984 eorsvc r2, r3, pc, asr r3
 *   @0x2f8988 ldmdavs r11, {r0, r3, r8, r9, r11, r12, pc}
 *   @0x2f898c .word 0xd1042b00
 *   @0x2f8990 .word 0x36022330
 *   @0x2f8994 .word 0x3c01f806
 *   @0x2f8998 blle 0x370b28 <_ZTS13C_UTF16String+0x7bd4>
 *   @0x2f899c and r3, r3, r1, lsl #12
 *   @0x2f89a0 subsmi r2, r11, #-805306366
 *   @0x2f89a4 .word 0x36027072
 *   @0x2f89a8 addslt r0, r11, #6656
 *   @0x2f89ac ldrdlt r4, r5, [r2, r3]
 *   @0x2f89b0 .word 0x210a4610
 *   @0x2f89b4 andls r9, r4, #201326592
 *   @0x2f89b8 b 0x934a40 <b2_toiTime+0x1db59c>
 *   @0x2f89bc .word 0xf80b3130
 *   @0x2f89c0 bls 0x3ff5cc <g_RomDisk+0x7dac>
 *   @0x2f89c4 ldrmi r2, [r0], -r10, lsl #2
 *   @0x2f89c8 stmib r2!, {r5, r12, sp, lr, pc}
 *   @0x2f89cc strmi r9, [r2], -r3, lsl #22
 *   @0x2f89d0 ldrbmi lr, [r10], -sp, ror #15
 *   @0x2f89d4 stmdble r4, {r1, r4, r6, r8, r10, lr}
 *   @0x2f89d8 stcne p8, c15, [r1, #-72]
 *   @0x2f89dc blne 0x3769fc <_ZTS13C_UTF16String+0xdaa8>
 *   @0x2f89e0 blhs 0x3329c8
 *   @0x2f89e4 blx 0x52cade <SrcVerts+0x89b22>
 *   @0x2f89e8 .word 0xf106f303
 *   @0x2f89ec ldrtmi r0, [r2], -r1, lsl #24
 *   @0x2f89f0 .word 0xf802212e
 *   @0x2f89f4 movwlo r1, #0x5b06
 *   @0x2f89f8 uqadd16mi r1, r1, r8
 *   @0x2f89fc mlaslo r0, r11, r2, r11
 *   @0x2f8a00 bleq 0x376a0c <_ZTS13C_UTF16String+0xdab8>
 *   @0x2f8a04 addsmi r11, r1, #-1073741814
 *   @0x2f8a08 .word 0xf303fb08
 *   @0x2f8a0c strmi sp, [r12], r1
 *   @0x2f8a10 bl 0xff4b29e0 <b2_toiTime+0xfffffffffed5953c>
 *   @0x2f8a14 cdphs p6, #0x0, c0, c5, c12, #0x0
 *   @0x2f8a18 bmi 0x102ce60 <b2_toiTime+0x8d39bc>
 *   @0x2f8a1c .word 0xdc0d4293
 *   @0x2f8a20 .word 0xd1032831
 *   @0x2f8a24 .word 0xf8012330
 *   @0x2f8a28 and r3, r7, r1, lsl #24
 *   @0x2f8a2c adcsmi r4, r3, #48, #28
 *   @0x2f8a30 strbeq sp, [r2, r6, lsl #2]
 *   @0x2f8a34 stmdalo r1, {r1, r8, r10, r12, lr, pc}
 *   @0x2f8a38 .word 0x0c01f801
 *   @0x2f8a3c and r4, r5, r3, ror #12
 *   @0x2f8a40 addsmi r4, r3, #44, #20
 *   @0x2f8a44 ldmdahs r0!, {r1, r3, r4, r5, r6, r7, r10, r11, r12, lr, pc}
 *   @0x2f8a48 udf #0x7d15
 *   @0x2f8a4c bllo 0x34a2cc
 *   @0x2f8a50 bhs 0xf16b20 <b2_toiTime+0x7bd67c>
 *   @0x2f8a54 .word 0xf04fd103
 *   @0x2f8a58 subsvc r0, lr, r0, lsl #12
 *   @0x2f8a5c .word 0x3601e7f6
 *   @0x2f8a60 sbcslt r7, r10, #64256
 *   @0x2f8a64 andle r2, r10, r0, lsr #20
 *   @0x2f8a68 teqeq r0, r3, lsr #3
 *   @0x2f8a6c stmdble r4, {r0, r3, r8, r11, sp}
 *   @0x2f8a70 hinteq #0x23
 *   @0x2f8a74 blhs 0x947780 <b2_toiTime+0x1ee2dc>
 *   @0x2f8a78 eorsvc sp, r2, r1, lsl #16
 *   @0x2f8a7c bhi 0x2186288 <b2_toiTime+0x1a2cde4>
 *   @0x2f8a80 blhs 0xb255d4 <b2_toiTime+0x3cc130>
 *   @0x2f8a84 .word 0xf1a3d00a
 *   @0x2f8a88 stmdbhs r9, {r4, r5, r8}
 *   @0x2f8a8c .word 0xf002d904
 *   @0x2f8a90 blo 0x1339614 <b2_toiTime+0xbe0170>
 *   @0x2f8a94 stmdale r1, {r0, r3, r4, r9, r11, sp}
 *   @0x2f8a98 .word 0x36017033
 *   @0x2f8a9c beq 0x792f8c <b2_toiTime+0x39ae8>
 *   @0x2f8aa0 blhs 0xb255f4 <b2_toiTime+0x3cc150>
 *   @0x2f8aa4 .word 0xf1a3d00a
 *   @0x2f8aa8 stmdbhs r9, {r4, r5, r8}
 *   @0x2f8aac .word 0xf002d904
 *   @0x2f8ab0 blo 0x1339634 <b2_toiTime+0xbe0190>
 *   @0x2f8ab4 stmdale r1, {r0, r3, r4, r9, r11, sp}
 *   @0x2f8ab8 .word 0x36017033
 *   @0x2f8abc sbcslt r6, r3, #950272
 *   @0x2f8ac0 andle r2, r10, r0, lsr #22
 *   @0x2f8ac4 teqeq r0, r3, lsr #3
 *   @0x2f8ac8 stmdble r4, {r0, r3, r8, r11, sp}
 *   @0x2f8acc sbcseq pc, pc, #2
 *   @0x2f8ad0 bhs 0x9473dc <b2_toiTime+0x1edf38>
 *   @0x2f8ad4 eorsvc sp, r3, r1, lsl #16
 *   @0x2f8ad8 blls 0x5462e4 <gp_ActiveMaskObjects+0x161c>
 *   @0x2f8adc stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f8ae0 movwlo r3, #0x4718
 *   @0x2f8ae4 strb r9, [r3, -r9, lsl #6]
 *   @0x2f8ae8 svcvc #0xff0000
 *   @0x2f8aec ldrdeq r4, r5, [r5], -pc
 *   @0x2f8af0 andeq r10, r2, r0, lsr #2
 *   @0x2f8af4 andeq r10, r2, pc, lsl r1
 *   @0x2f8af8 .word 0xffffa479
 *   @0x2f8afc .word 0xffffa469
 *   @0x2f8b00 stmdaeq r6, {r0, r2, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2f8b04 svceq #0x7ff1b8
 *   @0x2f8b08 teqhi r0, r0, asr #6
 *   @0x2f8b0c eorne lr, r8, #323584
 *   @0x2f8b10 beq 0x474c54 <g_RomDisk+0x7d434>
 *   @0x2f8b14 movwne lr, #0x2b05
 *   @0x2f8b18 andls r4, r5, #536870917
 *   @0x2f8b1c stmdbne r2, {r0, r1, r8, r9, r11, sp, lr, pc}
 *   @0x2f8b20 ldrmi r4, [r0], -r7, lsr #21
 *   @0x2f8b24 .word 0x46944696
 *   @0x2f8b28 .word 0x1000f8d9
 *   @0x2f8b2c ldmdbeq r0, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f8b30 .word 0xf8594ea4
 *   @0x2f8b34 blx 0x497b6e <g_prim_v+0x7b62>
 *   @0x2f8b38 stmibmi r3!, {r0, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2f8b3c movtmi r4, #0xfea3
 *   @0x2f8b40 blmi 0x21f3484 <b2_toiTime+0x1a99fe0>
 *   @0x2f8b44 blx 0x5f7752 <g_SWFaavertbuff+0x2468a>
 *   @0x2f8b48 b 0x16cb1d4 <b2_toiTime+0xf71d30>
 *   @0x2f8b4c cmnmi r7, #14417920
 *   @0x2f8b50 bleq 0x5f3588 <g_SWFaavertbuff+0x204c0>
 *   @0x2f8b54 addgt pc, r4, #14614528
 *   @0x2f8b58 bllo 0x21f3798 <b2_toiTime+0x1a9a2f4>
 *   @0x2f8b5c streq lr, [lr, -r7, lsl #21]
 *   @0x2f8b60 rsbs pc, r12, #14614528
 *   @0x2f8b64 blx 0x5f7796 <g_SWFaavertbuff+0x246ce>
 *   @0x2f8b68 ldrblo lr, [r7, r0, lsl #22]!
 *   @0x2f8b6c .word 0xf707fb0a
 *   @0x2f8b70 .word 0xf8df44dc
 *   @0x2f8b74 ldrtmi r11, [lr], #604
 *   @0x2f8b78 .word 0x7c08f859
 *   @0x2f8b7c svcmi #0x91437e
 *   @0x2f8b80 ldrbtlo lr, [r6], pc, asr #20
 *   @0x2f8b84 submi r4, r6, lr, asr #6
 *   @0x2f8b88 bl 0x38add8 <bigtens_D2A+0x12a8>
 *   @0x2f8b8c blx 0x58a56e <g_SWFlineaavertbuff+0x374a6>
 *   @0x2f8b90 ldrtmi pc, [r0], #-1542
 *   @0x2f8b94 .word 0x6c04f859
 *   @0x2f8b98 shsub16mi r4, lr, r1
 *   @0x2f8b9c .word 0x31b1ea4f
 *   @0x2f8ba0 svcmi #0x8a4379
 *   @0x2f8ba4 bmi 0xfe608cf0 <b2_toiTime+0xfffffffffdeaf84c>
 *   @0x2f8ba8 mvnsmi lr, r12, lsl #22
 *   @0x2f8bac .word 0xf101fb0a
 *   @0x2f8bb0 stmdbls r5, {r1, r3, r10, lr}
 *   @0x2f8bb4 mrsls r3, apsr
 *   @0x2f8bb8 .word 0xd1b54983
 *   @0x2f8bbc stmdbeq pc, {r3, r12, sp, lr, pc}
 *   @0x2f8bc0 ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x2f8bc4 andsls pc, r4, sp, asr #17
 *   @0x2f8bc8 svceq #0xef1b9
 *   @0x2f8bcc ldm pc, {r0, r2, r3, r4, r5, r6, r11, r12, lr, pc} ^
 *   @0x2f8bd0 ldclvs p0, c15, [r3, #-36]!
 *   @0x2f8bd4 svcmi #0x566467
 *   @0x2f8bd8 cdphs p3, #0x3, c4, c5, c8, #0x2
 *   @0x2f8bdc ldceq p2, c2, [r4, #-156]
 *   @0x2f8be0 .word 0xf8930008
 *   @0x2f8be4 b 0x16dcc24 <b2_toiTime+0xf83780>
 *   @0x2f8be8 and r4, r1, r9, lsl #18
 *   @0x2f8bec stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f8bf0 mulge sp, r3, r8
 *   @0x2f8bf4 stmdbhs r10, {r0, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f8bf8 .word 0xf04fe001
 *   @0x2f8bfc .word 0xf8930900
 *   @0x2f8c00 b 0xfe560c38 <b2_toiTime+0xfffffffffde07794>
 *   @0x2f8c04 blx 0x5bb036 <g_SWFlineaavertbuff+0x67f6e>
 *   @0x2f8c08 b 0x16f7034 <b2_toiTime+0xf9db90>
 *   @0x2f8c0c blx 0x4872fa <g_States+0x1932>
 *   @0x2f8c10 b 0xfe57703c <b2_toiTime+0xfffffffffde1db98>
 *   @0x2f8c14 .word 0xf8930202
 *   @0x2f8c18 b 0x16dcc4c <b2_toiTime+0xf837a8>
 *   @0x2f8c1c and r6, r1, r9, lsl #18
 *   @0x2f8c20 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f8c24 mulge r10, r3, r8
 *   @0x2f8c28 stmdbmi r10, {r0, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f8c2c .word 0xf04fe001
 *   @0x2f8c30 .word 0xf8930900
 *   @0x2f8c34 b 0xfe560c60 <b2_toiTime+0xfffffffffde077bc>
 *   @0x2f8c38 and r2, r1, r10, lsl #18
 *   @0x2f8c3c stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f8c40 mulge r8, r3, r8
 *   @0x2f8c44 stmdbeq r10, {r0, r3, r7, r9, r11, sp, lr, pc}
 *   @0x2f8c48 .word 0xf909fb07
 *   @0x2f8c4c ldmiblo r9!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0x2f8c50 blx 0x577886 <g_SWFlineaavertbuff+0x247be>
 *   @0x2f8c54 andeq lr, r0, r11, lsl #21
 *   @0x2f8c58 mulls r7, r3, r8
 *   @0x2f8c5c stmdbvs r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2f8c60 .word 0xf04fe001
 *   @0x2f8c64 .word 0xf8930900
 *   @0x2f8c68 b 0x1560c88 <b2_toiTime+0xe077e4>
 *   @0x2f8c6c and r4, r1, r10, lsl #18
 *   @0x2f8c70 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f8c74 mulge r5, r3, r8
 *   @0x2f8c78 stmdbhs r10, {r0, r3, r7, r9, r11, sp, lr, pc}
 *   @0x2f8c7c .word 0xf04fe001
 *   @0x2f8c80 .word 0xf8930900
 *   @0x2f8c84 b 0xfe560c9c <b2_toiTime+0xfffffffffde077f8>
 *   @0x2f8c88 blx 0x33b0ba
 *   @0x2f8c8c b 0x16f70b8 <b2_toiTime+0xf9dc14>
 *   @0x2f8c90 blx 0x4cb17e <SrcVerts+0x281c2>
 *   @0x2f8c94 b 0xfe4f68c0 <b2_toiTime+0xfffffffffdd9d41c>
 *   @0x2f8c98 ldmvc pc, {r1, r2, r3, r9, r10, r11} ^
 *   @0x2f8c9c and r0, r0, pc, lsr r6
 *   @0x2f8ca0 .word 0xf8932700
 *   @0x2f8ca4 b 0x14dccb4 <b2_toiTime+0xd83810>
 *   @0x2f8ca8 and r4, r0, r9, lsl #14
 *   @0x2f8cac .word 0xf8932700
 *   @0x2f8cb0 b 0xfe4dccbc <b2_toiTime+0xfffffffffdd83818>
 *   @0x2f8cb4 and r2, r0, r9, lsl #14
 *   @0x2f8cb8 ldmdavc r11, {r8, r9, r10, sp}
 *   @0x2f8cbc cmnmi lr, #95
 *   @0x2f8cc0 ldrbtmi lr, [r6], -pc, asr #20
 *   @0x2f8cc4 b 0xfe349a90 <b2_toiTime+0xfffffffffdbf05ec>
 *   @0x2f8cc8 b 0xfe67bd00 <b2_toiTime+0xfffffffffdf2285c>
 *   @0x2f8ccc b 0xfe5fc4f4 <b2_toiTime+0xfffffffffdea3050>
 *   @0x2f8cd0 b 0xfe2fbcf8 <b2_toiTime+0xfffffffffdba2854>
 *   @0x2f8cd4 ldrbtmi r0, [r4], #776
 *   @0x2f8cd8 andeq lr, r8, #532480
 *   @0x2f8cdc bl 0x609f54 <g_SWFaavertbuff+0x36e8c>
 *   @0x2f8ce0 stmne r6, {r1} ^
 *   @0x2f8ce4 streq lr, [lr, -r0, lsl #22]
 *   @0x2f8ce8 stmdaeq r2, {r8, r9, r11, sp, lr, pc}
 *   @0x2f8cec .word 0xffeaf7f9
 *   @0x2f8cf0 ldrtmi r4, [r8], -r1, lsl #13
 *   @0x2f8cf4 .word 0xffe6f7f9
 *   @0x2f8cf8 ldrtmi r4, [r0], -r7, lsl #12
 *   @0x2f8cfc .word 0xffe2f7f9
 *   @0x2f8d00 strbmi r4, [r0], -r6, lsl #12
 *   @0x2f8d04 .word 0xffdef7f9
 *   @0x2f8d08 movweq lr, #0x9b07
 *   @0x2f8d0c sbchs pc, r8, #212, #16
 *   @0x2f8d10 .word 0x212d4433
 *   @0x2f8d14 movwls r4, #0xe403
 *   @0x2f8d18 ldrmi r4, [lr], #-1055
 *   @0x2f8d1c strmi r9, [r3], #-1807
 *   @0x2f8d20 tstls r1, #48, #30
 *   @0x2f8d24 ldrls r1, [r0], -r11, lsr #17
 *   @0x2f8d28 strtpl r4, [r9], #1151
 *   @0x2f8d2c andhs r10, r0, #12, #28
 *   @0x2f8d30 .word 0x0120f103
 *   @0x2f8d34 eorhs pc, r4, r3, lsl #17
 *   @0x2f8d38 .word 0xf883222e
 *   @0x2f8d3c .word 0xf8832023
 *   @0x2f8d40 .word 0xf8832022
 *   @0x2f8d44 blge 0x700dd0 <g_SWFvertbuff+0x2dd08>
 *   @0x2f8d48 andhs r6, r0, #88, #16
 *   @0x2f8d4c .word 0x0c0ff000
 *   @0x2f8d50 ldrtmi r0, [r12], #2304
 *   @0x2f8d54 orrsgt pc, r4, #156, #16
 *   @0x2f8d58 andgt pc, r2, r1, lsl #16
 *   @0x2f8d5c .word 0xf1123a01
 *   @0x2f8d60 mvnsle r0, r8, lsl #30
 *   @0x2f8d64 stmdblo r8, {r2, r8, r9, r11, r12, sp}
 *   @0x2f8d68 strhle r4, [sp, #35]!
 *   @0x2f8d6c .word 0xf8c4462e
 *   @0x2f8d70 eor r6, r1, r8, lsr #5
 *   @0x2f8d74 bge 0x641194 <g_SWFaavertbuff+0x6e0cc>
 *   @0x2f8d78 .word 0xf7f9ab0e
 *   @0x2f8d7c ldrhlt pc, [r8, #243]
 *   @0x2f8d80 mrshs r9, apsr
 *   @0x2f8d84 .word 0x91002214
 *   @0x2f8d88 cdpvs p12, #0x6, c1, c0, c11, #0x3
 *   @0x2f8d8c .word 0x3164f8d4
 *   @0x2f8d90 ldrsbne pc, [r0, #-132]!
 *   @0x2f8d94 blx 0x3acdb6 <error_g0017+0x5a5a>
 *   @0x2f8d98 blmi 0x7c55b4 <b2_toiTime+0x6c110>
 *   @0x2f8d9c .word 0xf7fc447b
 *   @0x2f8da0 and pc, r6, r7, asr r10
 *   @0x2f8da4 blx 0x3a01e6 <ft_standard_glyph_names+0x14f2>
 *   @0x2f8da8 blmi 0x7055c4 <g_SWFvertbuff+0x324fc>
 *   @0x2f8dac .word 0xf7fc447b
 *   @0x2f8db0 .word 0x4606fa9e
 *   @0x2f8db4 adceq pc, r8, #196, #16
 *   @0x2f8db8 andslt r4, r3, r0, lsr r6
 *   @0x2f8dbc svchi #0xf0e8bd
 *   @0x2f8dc0 smmlaeq r11, r5, sp, r12
 *   @0x2f8dc4 orrshs r9, r11, #28311552
 *   @0x2f8dc8 blge 0x69ebf4 <g_SWFlinevertbuff+0x4bb2c>
 *   @0x2f8dcc ldmlo r3!, {r0, r2, r5, r6, r7, r9, r11, lr}
 *   @0x2f8dd0 .word 0xa1e38b93
 *   @0x2f8dd4 .word 0x96cd1c35
 *   @0x2f8dd8 adclo r3, r12, #23552
 *   @0x2f8ddc sadd16pl r12, r12, r11
 *   @0x2f8de0 bleq 0xff5a2b04 <b2_toiTime+0xfffffffffee49660>
 *   @0x2f8de4 andeq r6, r10, r8, lsr lr
 *   @0x2f8de8 .word 0xffff9ee5
 *   @0x2f8dec .word 0xffff9ed5
 *   @0x2f8df0 sasxmi r11, r12, r8
 *   @0x2f8df4 andslo pc, r12, #208, #16
 *   @0x2f8df8 eorvs r2, r5, r0, lsl #10
 *   @0x2f8dfc tstlt r3, r5, rrx
 *   @0x2f8e00 .word 0x47986d5b
 *   @0x2f8e04 andhs r6, r0, r0, lsr #32
 *
 * ══ §2/8 anon_25fe2c  0x25fe2c  size 26424  294 条（0x25fe2c..0x266564）｜其中 6312 条已由别的卡落锚，本节不再重复
 * @func 0x25fe2c 0x266564  size 26424  294 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xb65e0×12 / _pcre_ord2utf×8 / 0xb6694×8 / 0xb65bc×8 / anon_25fe2c+0x5d2c×6 / anon_25b524+0x25ac×6 / anon_25b524+0xdd4×5 / anon_25b524+0x24f4×4
 * 字段偏移 top8: 0x13c×185 / 0x1×154 / 0x48×75 / 0x2×66 / 0x10×62 / 0x40×61 / 0x4c×59 / 0x50×50
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x25fe2c push {r3, r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25fe30 mov r8, r1
 *   @0x25fe34 ldr r7, [sp, #0x2c]
 *   @0x25fe38 ldr r9, [sp, #0x28]
 *   @0x25fe3c cmp r7, #255
 *   @0x25fe40 movlo r6, r7
 *   @0x25fe44 movhs r6, #255
 *   @0x25fe48 ands r4, r2, #1
 *   @0x25fe4c beq 0x25fe90 <_pcre_ord2utf+0xf8>
 *   @0x25fe50 cmp r6, r9
 *   @0x25fe54 blo 0x25ff2c <_pcre_ord2utf+0x194>
 *   @0x25fe58 mov r12, r9
 *   @0x25fe5c mov r4, #0
 *   @0x25fe60 mov r10, #1
 *   @0x25fe64 ldr r1, [r3]
 *   @0x25fe68 add r4, r4, #1
 *   @0x25fe6c ldrb r1, [r1, r12]
 *   @0x25fe70 add r12, r12, #1
 *   @0x25fe74 cmp r6, r12
 *   @0x25fe78 and r5, r1, #7
 *   @0x25fe7c lsr r1, r1, #3
 *   @0x25fe80 ldrb r11, [r0, r1]
 *   @0x25fe84 orr r5, r11, r10, lsl r5
 *   @0x25fe88 strb r5, [r0, r1]
 *   @0x25fe8c bhs 0x25fe64 <_pcre_ord2utf+0xcc>
 *   @0x25fe90 ands r2, r2, #2048
 *   @0x25fe94 moveq r7, r6
 *   @0x25fe98 cmp r6, r9
 *   @0x25fe9c blo 0x25fec8 <_pcre_ord2utf+0x130>
 *   @0x25fea0 mov r3, r9
 *   @0x25fea4 mov r1, #1
 *   @0x25fea8 ldrb r12, [r0, r3, lsr #3]
 *   @0x25feac and r5, r3, #7
 *   @0x25feb0 add r4, r4, #1
 *   @0x25feb4 orr r12, r12, r1, lsl r5
 *   @0x25feb8 strb r12, [r0, r3, lsr #3]
 *   @0x25febc add r3, r3, #1
 *   @0x25fec0 cmp r6, r3
 *   @0x25fec4 bhs 0x25fea8 <_pcre_ord2utf+0x110>
 *   @0x25fec8 cmp r9, #255
 *   @0x25fecc movls r9, #256
 *   @0x25fed0 cmp r7, r9
 *   @0x25fed4 blo 0x25fef4 <_pcre_ord2utf+0x15c>
 *   @0x25fed8 cmp r2, #0
 *   @0x25fedc ldr r3, [r8]
 *   @0x25fee0 beq 0x25fef0 <_pcre_ord2utf+0x158>
 *   @0x25fee4 cmp r7, r9
 *   @0x25fee8 bhi 0x25fefc <_pcre_ord2utf+0x164>
 *   @0x25feec beq 0x25ff34 <_pcre_ord2utf+0x19c>
 *   @0x25fef0 str r3, [r8]
 *   @0x25fef4 mov r0, r4
 *   @0x25fef8 pop {r3, r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x25fefc add r5, r3, #1
 *   @0x25ff00 mov r2, #2
 *   @0x25ff04 mov r0, r9
 *   @0x25ff08 strb r2, [r3]
 *   @0x25ff0c mov r1, r5
 *   @0x25ff10 bl 0x25fd98 <_pcre_ord2utf>
 *   @0x25ff14 add r5, r5, r0
 *   @0x25ff18 mov r0, r7
 *   @0x25ff1c mov r1, r5
 *   @0x25ff20 bl 0x25fd98 <_pcre_ord2utf>
 *   @0x25ff24 add r3, r5, r0
 *   @0x25ff28 b 0x25fef0 <_pcre_ord2utf+0x158>
 *   @0x25ff2c mov r4, #0
 *   @0x25ff30 b 0x25fe90 <_pcre_ord2utf+0xf8>
 *   @0x25ff34 add r5, r3, #1
 *   @0x25ff38 mov r2, #1
 *   @0x25ff3c mov r0, r7
 *   @0x25ff40 strb r2, [r3]
 *   @0x25ff44 mov r1, r5
 *   @0x25ff48 bl 0x25fd98 <_pcre_ord2utf>
 *   @0x25ff4c add r3, r5, r0
 *   @0x25ff50 b 0x25fef0 <_pcre_ord2utf+0x158>
 *   @0x25ff54 push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x25ff58 sub sp, sp, #444
 *   @0x25ff5c ldr r12, [pc, #0xf1c]
 *   @0x25ff60 add r6, sp, #512
 *   @0x25ff64 str r2, [sp, #0xc4]
 *   @0x25ff68 add r12, pc, r12
 *   @0x25ff6c str r12, [sp, #0xa0]
 *   @0x25ff70 ldr r12, [sp, #0xc4]
 *   @0x25ff74 str r1, [sp, #0xd0]
 *   @0x25ff78 ldr r1, [pc, #0xf04]
 *   @0x25ff7c ldr r4, [r12]
 *   @0x25ff80 ldr r12, [sp, #0xa0]
 *   @0x25ff84 str r3, [sp, #0x48]
 *   @0x25ff88 str r0, [sp, #0x40]
 *   @0x25ff8c ldr r1, [r12, r1]
 *   @0x25ff90 ldr r12, [sp, #0xd0]
 *   @0x25ff94 ldr r2, [pc, #0xeec]
 *   @0x25ff98 ldr r3, [r1]
 *   @0x25ff9c ldr r12, [r12]
 *   @0x25ffa0 str r1, [sp, #0xf4]
 *   @0x25ffa4 str r3, [sp, #0x1b4]
 *   @0x25ffa8 str r12, [sp, #0x90]
 *   @0x25ffac ldr r12, [sp, #0xa0]
 *   @0x25ffb0 ldr r5, [sp, #0x1e8]
 *   @0x25ffb4 ldr r3, [r12, r2]
 *   @0x25ffb8 ldr r12, [sp, #0x1f0]
 *   @0x25ffbc ldr r3, [r3]
 *   @0x25ffc0 str r12, [sp, #0x114]
 *   @0x25ffc4 ldr r12, [sp, #0x1f4]
 *   @0x25ffc8 cmp r3, #0
 *   @0x25ffcc str r12, [sp, #0x118]
 *   @0x25ffd0 ldr r12, [sp, #0x1f8]
 *   @0x25ffd4 str r12, [sp, #0x11c]
 *   @0x25ffd8 ldr r12, [sp, #0x1fc]
 *   @0x25ffdc str r12, [sp, #0x120]
 *   @0x25ffe0 ldm r6, {r6, r7, r12}
 *   @0x25ffe4 str r12, [sp, #0xc8]
 *   @0x25ffe8 beq 0x25fff8 <_pcre_ord2utf+0x260>
 *   @0x25ffec blx r3
 *   @0x25fff0 cmp r0, #0
 *   @0x25fff4 bne 0x262bdc <_pcre_ord2utf+0x2e44>
 *   @0x25fff8 ldr r12, [sp, #0x90]
 *   @0x25fffc add r2, r5, #6
 *   @0x260000 str r6, [sp, #0x16c]
 *   @0x260004 str r2, [sp, #0x130]
 *   @0x260008 str r12, [sp, #0x170]
 *   @0x26000c ldrb r3, [r12]
 *   @0x260010 ldr r12, [r7, #0x20]
 *   @0x260014 cmp r3, #133
 *   @0x260018 str r12, [sp, #0x108]
 *   @0x26001c ldr r12, [r7, #0x10]
 *   @0x260020 str r12, [sp, #0x10c]
 *   @0x260024 movne r12, #0
 *   @0x260028 strne r12, [sp, #0xdc]
 *   @0x26002c beq 0x2631cc <_pcre_ord2utf+0x3434>
 *   @0x260030 ldr r12, [sp, #0x90]
 *   @0x260034 mov r3, #0
 *   @0x260038 add r5, r5, #3
 *   @0x26003c ldr r2, [pc, #0xe48]
 *   @0x260040 str r3, [sp, #0xa4]
 *   @0x260044 add r0, sp, #440
 *   @0x260048 strb r3, [r12, #0x1]
 *   @0x26004c add r2, pc, r2
 *   @0x260050 strb r3, [r12, #0x2]
 *   @0x260054 mov r9, r7
 *   @0x260058 ldr r12, [r7, #0x40]
 *   @0x26005c add r2, r2, #408
 *   @0x260060 ldr r3, [pc, #0xe28]
 *   @0x260064 str r5, [sp, #0xe8]
 *   @0x260068 str r12, [sp, #0xec]
 *   @0x26006c add r3, pc, r3
 *   @0x260070 ldr r12, [sp, #0x90]
 *   @0x260074 add r3, r3, #420
 *   @0x260078 str r2, [sp, #0xfc]
 *   @0x26007c add r12, r12, r5
 *   @0x260080 str r12, [sp, #0x60]
 *   @0x260084 ldr r12, [pc, #0xe08]
 *   @0x260088 str r3, [sp, #0x100]
 *   @0x26008c add r12, pc, r12
 *   @0x260090 str r12, [sp, #0x128]
 *   @0x260094 mvn r12, #1
 *   @0x260098 str r12, [sp, #0xac]
 *   @0x26009c ldr r12, [sp, #0xc8]
 *   @0x2600a0 cmp r12, #0
 *   @0x2600a4 movw r12, #0xcccb
 *   @0x2600a8 movt r12, #0xccc
 *   @0x2600ac str r12, [sp, #0xd4]
 *   @0x2600b0 ldr r12, [sp, #0xec]
 *   @0x2600b4 subne r6, r0, #136
 *   @0x2600b8 moveq r6, #0
 *   @0x2600bc str r6, [sp, #0x3c]
 *   @0x2600c0 str r12, [sp, #0xe0]
 *   @0x2600c4 mov r12, #0
 *   @0x2600c8 str r12, [sp, #0xcc]
 *   @0x2600cc str r12, [sp, #0xd8]
 *   @0x2600d0 mvn r12, #1
 *   @0x2600d4 str r12, [sp, #0xb8]
 *   @0x2600d8 ldr r12, [sp, #0x90]
 *   @0x2600dc str r12, [sp, #0xb4]
 *   @0x2600e0 ldr r12, [sp, #0x1e4]
 *   @0x2600e4 cmp r12, #0
 *   @0x2600e8 ldrne r12, [sp, #0xec]
 *   @0x2600ec strne r12, [r9, #0x40]
 *   @0x2600f0 ldr r12, [sp, #0x1e0]
 *   @0x2600f4 cmp r12, #0
 *   @0x2600f8 beq 0x260134 <_pcre_ord2utf+0x39c>
 *   @0x2600fc ldr r12, [sp, #0x60]
 *   @0x260100 mov r3, #124
 *   @0x260104 add r12, r12, #1
 *   @0x260108 strb r3, [r12, #-0x1]
 *   @0x26010c mov r3, #0
 *   @0x260110 strb r3, [r12]
 *   @0x260114 strb r3, [r12, #0x1]
 *   @0x260118 ldr r3, [sp, #0x130]
 *   @0x26011c str r12, [sp, #0xd8]
 *   @0x260120 ldr r12, [sp, #0x60]
 *   @0x260124 add r3, r3, #3
 *   @0x260128 str r3, [sp, #0x130]
 *   @0x26012c add r12, r12, #3
 *   @0x260130 str r12, [sp, #0x60]
 *   @0x260134 ldr r12, [sp, #0x40]
 *   @0x260138 mov r3, #0
 *   @0x26013c ldr r7, [r9, #0x10]
 *   @0x260140 mov r11, r4
 *   @0x260144 ubfx r12, r12, #0x9, #0x1
 *   @0x260148 str r12, [sp, #0xb0]
 *   @0x26014c eor r12, r12, #1
 *   @0x260150 str r12, [sp, #0xe4]
 *   @0x260154 mvn r12, #1
 *   @0x260158 str r12, [sp, #0x58]
 *   @0x26015c ldr r12, [sp, #0x40]
 *   @0x260160 mov r8, r3
 *   @0x260164 str r3, [sp, #0x5c]
 *   @0x260168 ubfx r6, r12, #0xb, #0x1
 *   @0x26016c and r12, r12, #1
 *   @0x260170 str r12, [sp, #0x98]
 *   @0x260174 mvn r12, #1
 *   @0x260178 str r12, [sp, #0x78]
 *   @0x26017c mov r10, r6
 *   @0x260180 str r12, [sp, #0x64]
 *   @0x260184 str r12, [sp, #0x4c]
 *   @0x260188 ldr r12, [sp, #0x60]
 *   @0x26018c str r3, [sp, #0x7c]
 *   @0x260190 str r3, [sp, #0x44]
 *   @0x260194 mov r6, r12
 *   @0x260198 str r3, [sp, #0x9c]
 *   @0x26019c str r3, [sp, #0x94]
 *   @0x2601a0 str r3, [sp, #0xbc]
 *   @0x2601a4 str r3, [sp, #0x80]
 *   @0x2601a8 str r3, [sp, #0x74]
 *   @0x2601ac str r3, [sp, #0x6c]
 *   @0x2601b0 str r3, [sp, #0x70]
 *   @0x2601b4 str r12, [sp, #0x54]
 *   @0x2601b8 str r4, [sp, #0x13c]
 *   @0x2601bc str r3, [sp, #0x134]
 *   @0x2601c0 ldrb r4, [r11]
 *   @0x2601c4 ldr r12, [sp, #0x44]
 *   @0x2601c8 rsbs r3, r4, #1
 *   @0x2601cc movlo r3, #0
 *   @0x2601d0 cmp r12, #0
 *   @0x2601d4 moveq r3, #0
 *   @0x2601d8 cmp r3, #0
 *   @0x2601dc strne r12, [sp, #0x13c]
 *   @0x2601e0 ldrbne r4, [r12]
 *   @0x2601e4 movne r12, #0
 *   @0x2601e8 strne r12, [sp, #0x44]
 *   @0x2601ec ldr r12, [sp, #0x3c]
 *   @0x2601f0 cmp r12, #0
 *   @0x2601f4 beq 0x260dc0 <_pcre_ord2utf+0x1028>
 *   @0x2601f8 ldr r3, [r9, #0x3c]
 *   @0x2601fc sub r2, r3, #100
 *   @0x260200 add r2, r7, r2
 *   @0x260204 cmp r6, r2
 *   @0x260208 bhi 0x26194c <_pcre_ord2utf+0x1bb4>
 *   @0x265b58 cmp r2, #0
 *   @0x265b5c push {r4, r5, r6, r7, r8, lr}
 *   @0x265b60 mov r8, r0
 *   @0x265b64 sub sp, sp, #8
 *   @0x265b68 mov r7, r3
 *   @0x265b6c beq 0x265ba8 <_pcre_ord2utf+0x5e10>
 *   @0x265b70 sub r1, r1, #1
 *   @0x265b74 add r4, r2, r0
 *   @0x265b78 rsb r12, r0, r1
 *   @0x265b7c mov r3, r0
 *   @0x265b80 ldrb r0, [r3], #1
 *   @0x265b84 ldr r1, [r7]
 *   @0x265b88 cmp r3, r4
 *   @0x265b8c add r1, r1, r3
 *   @0x265b90 ldrb r1, [r1, r12]
 *   @0x265b94 orr r1, r0, r1
 *   @0x265b98 strb r1, [r3, #-0x1]
 *   @0x265b9c bne 0x265b80 <_pcre_ord2utf+0x5de8>
 *   @0x265ba0 cmp r2, #32
 *   @0x265ba4 beq 0x265c08 <_pcre_ord2utf+0x5e70>
 *   @0x265ba8 mov r4, #128
 *   @0x265bac mov r5, #1
 *   @0x265bb0 b 0x265bc0 <_pcre_ord2utf+0x5e28>
 *   @0x265bb4 add r4, r4, #1
 *   @0x265bb8 cmp r4, #256
 *   @0x265bbc beq 0x265c08 <_pcre_ord2utf+0x5e70>
 *   @0x265bc0 ldr r12, [r7]
 *   @0x265bc4 and r2, r4, #7
 *   @0x265bc8 ldrb r12, [r12, r4, lsr #3]
 *   @0x265bcc asr r2, r12, r2
 *   @0x265bd0 tst r2, #1
 *   @0x265bd4 beq 0x265bb4 <_pcre_ord2utf+0x5e1c>
 *   @0x265bd8 mov r0, r4
 *   @0x265bdc mov r1, sp
 *   @0x265be0 bl 0x25fd98 <_pcre_ord2utf>
 *   @0x265be4 ldrb r3, [sp]
 *   @0x265be8 add r4, r4, #1
 *   @0x265bec and r1, r3, #7
 *   @0x265bf0 cmp r4, #256
 *   @0x265bf4 lsr r3, r3, #3
 *   @0x265bf8 ldrb r2, [r8, r3]
 *   @0x265bfc orr r2, r2, r5, lsl r1
 *   @0x265c00 strb r2, [r8, r3]
 *   @0x265c04 bne 0x265bc0 <_pcre_ord2utf+0x5e28>
 *   @0x265c08 add sp, sp, #8
 *   @0x265c0c pop {r4, r5, r6, r7, r8, pc}
 *
 * ══ §3/8 anon_221ff4  0x221ff4  size 1492  19 条（0x221ff4..0x2225c8）｜其中 354 条已由别的卡落锚，本节不再重复
 * @func 0x221ff4 0x2225c8  size 1492  19 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: _alutInputStreamReadInt32BE×8 / anon_221ff4+0x52c×4 / _alutInputStreamSkip×4 / _alutInputStreamReadUInt32LE×4 / _alutInputStreamReadUInt16LE×4 / _alutSetError×3 / anon_221ff4×2 / _alutInputStreamGetRemainingLength×2
 * 字段偏移 top8: 0x30×6 / 0x34×4 / 0x18×4 / 0x1c×4 / 0x2c×4 / 0xc×3 / 0x14×2 / 0x-1×2
 * VFP 指令 6 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x221ff4 cmn r0, #1
 *   @0x221ff8 bxeq lr
 *   @0x221ffc ldr r3, [pc, #0x34]
 *   @0x222000 ldr r3, [pc, r3]
 *   @0x222004 ldr r3, [r3]
 *   @0x222008 uxtab r3, r3, r0
 *   @0x22200c ldrb r3, [r3, #0x1]
 *   @0x222010 tst r3, #1
 *   @0x222014 bxeq lr
 *   @0x222018 cmp r0, #255
 *   @0x22201c bxhi lr
 *   @0x222020 ldr r3, [pc, #0x14]
 *   @0x222024 ldr r3, [pc, r3]
 *   @0x222028 ldr r3, [r3]
 *   @0x22202c add r0, r3, r0, lsl #1
 *   @0x222030 ldrsh r0, [r0, #2]
 *   @0x222034 bx lr
 *   @0x222038 andseq r11, r12, r0, lsl #19
 *   @0x22203c andseq r11, r12, r0, ror #18
 *
 * ══ §4/8 anon_2bec94  0x2bec94  size 1284  1 条（0x2bec94..0x2bf198）｜其中 320 条已由别的卡落锚，本节不再重复
 * @func 0x2bec94 0x2bf198  size 1284  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_fill_bit_buffer×6 / jpeg_huff_decode×3 / anon_2bec94+0x400×3 / anon_2bec94+0x268 / anon_2bec94+0x438 / anon_2bec94+0x4dc / anon_2bec94+0x2f8 / anon_2bec94+0x2c8
 * 字段偏移 top8: 0x48×9 / 0x44×8 / 0x10×7 / 0x24×6 / 0x14×6 / 0x2×6 / 0x18×5 / 0xc×5
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2bec94 ldr r3, [r0, #0xfc]
 *
 * ══ §5/8 Command_LoadGame(char const*)  0x1d14fc  size 404  1 条（0x1d14fc..0x1d1690）｜其中 100 条已由别的卡落锚，本节不再重复
 * @func 0x1d14fc 0x1d1690  size 404  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d160c→0x3eb70c, 0x1d164c→0x3eb70c
 * 调用序列: LoadSave::fseek(_YYFILE*, long, int)×2 / LoadSave::SaveFileExists(char const*) / LoadSave::BundleFileExists(char const*) / LoadSave::fopen(char const*, char const*) / LoadSave::ftell(_YYFILE*) / CreateBuffer(int, eBuffer_Format, int) / GetIBuffer(int) / LoadSave::fread(void const*, unsigned int, unsigned int, _YYFILE*)
 * 字段偏移 top8: 0xc×3 / 0x404×2 / 0x4×2 / 0x168×1 / 0x164×1 / 0x124×1 / 0xac×1 / 0x70×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d168c andseq pc, r7, r0, lsl #16
 *
 * ══ §6/8 Command_LoadGame(int)  0x1d0dd8  size 252  1 条（0x1d0dd8..0x1d0ed4）｜其中 62 条已由别的卡落锚，本节不再重复
 * @func 0x1d0dd8 0x1d0ed4  size 252  1 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 0x3f1c58
 * 门字节（加载点→目标全局）: 0x1d0dfc→0x3eb70c, 0x1d0e34→0x5428e8, 0x1d0e50→0x544c38, 0x1d0e84→0x3eb70c
 * 调用序列: GetIBuffer(int) / Debug_AddTag(eTagNameType, char const*, ...)
 * 字段偏移 top8: 0xb4×2 / 0xc×2 / 0x88×2 / 0xd0×1 / 0xc8×1 / 0x4×1 / 0x70×1 / 0x58×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x1d0ed0 mulseq r7, r0, pc
 *
 * ══ §7/8 png_destroy_read_struct  0x2a7e2c  size 140  6 条（0x2a7e2c..0x2a7eb8）｜其中 29 条已由别的卡落锚，本节不再重复
 * @func 0x2a7e2c 0x2a7eb8  size 140  6 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_free_data / png_destroy_struct_2
 * 字段偏移 top8: 无
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a7e60 cmnlt lr, r1, lsl #30
 *   @0x2a7e7c movwhs pc, #0xef0
 *   @0x2a7e88 qsub8mi r3, r0, pc
 *   @0x2a7e90 .word 0xf7fd4280
 *   @0x2a7e94 qadd8mi pc, r8, r5
 *   @0x2a7eac movwhs pc, #0xed8
 *
 * ══ §8/8 anon_b9c5c  0xb9c5c  size 8  2 条（0xb9c5c..0xb9c64）
 * @func 0xb9c5c 0xb9c64  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x2c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xb9c5c ldr r1, [pc, #0x2c]
 *   @0xb9c60 mov r2, #50
 */
