/* cally 逆向卡：All_16 —— 可达集里未出卡函数的结构级批次（原版 libyoyo.so，armv7）
 * 节: 7 个函数｜锚点 7500 条｜来源: scripts/reachability.py --dump（1,439 个可达函数 / 148,233 条指令）
 * 级别: 骨架 —— 门字节（GOT 槽→全局）、调用序列、字段偏移直方图、VFP 用量与逐条锚点；
 *       **不主张语义**：这些函数还没逐条读过，每节尾部的 open 就是欠账清单。
 * 选择规则: 只取可达集里「一个地址都还没被别的卡主张」的函数，按字节降序填到预算为止。
 * 索引: asm/instructions.jsonl；符号: asm/functions.tsv；槽→目标: .rel.dyn
 *
 * ══ §1/7 anon_2e9c78  0x2e9c78  size 26568  6642 条（0x2e9c78..0x2f0440）
 * @func 0x2e9c78 0x2f0440  size 26568  6642 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 0xfe78498c / 0xfe9c49a4 / 0x3b6158 / 0x37a714 / 0x582170 / 0x47a7e0 / 0x3f0874 / 0xff4b51c4
 * 字段偏移 top8: 0x6×8 / 0x4×7 / 0x18×7 / 0x8×5 / 0xa×4 / 0x12×4 / 0xc×4 / 0x16×3
 * VFP 指令 54 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2e9c78 andhs r4, r0, r0, ror r7
 *   @0x2e9c7c ldrlt r4, [r0, #-0x770]
 *   @0x2e9c80 stmdavs r3, {r1, r6, r7, r11, sp, lr} ^
 *   @0x2e9c84 blvs 0xfe78498c <b2_toiTime+0xfffffffffe02b4e8>
 *   @0x2e9c88 .word 0x10a4f8d3
 *   @0x2e9c8c .word 0xf8d36894
 *   @0x2e9c90 strmi r2, [r0, r8, lsr #1]!
 *   @0x2e9c94 ldclt p0, c2, [r0, #-0]
 *   @0x2e9c98 stmvs r3, {r3, r8, r10, r12, sp, pc} ^
 *   @0x2e9c9c blvs 0xfe9c49a4 <b2_toiTime+0xfffffffffe26b500>
 *   @0x2e9ca0 .word 0x479868db
 *   @0x2e9ca4 strmi r11, [r1], -r8, lsl #26
 *   @0x2e9ca8 .word 0xf7fd6800
 *   @0x2e9cac ldrlt r11, [r8, #-0xb44]!
 *   @0x2e9cb0 .word 0x2104f8d0
 *   @0x2e9cb4 ldrsblo pc, [r0, -r0]
 *   @0x2e9cb8 .word 0x5100f8d0
 *   @0x2e9cbc .word 0xf8d01ad2
 *   @0x2e9cc0 bl 0x3b6158 <error_g0017+0xedfc>
 *   @0x2e9cc4 ldmdavs r3, {r1, r7, r9}
 *   @0x2e9cc8 ldmdavs r9, {r0, r1, r4, r5, r8, r12, sp, pc}
 *   @0x2e9ccc .word 0xdc0342a9
 *   @0x2e9cd0 .word 0xf103d01d
 *   @0x2e9cd4 ldrb r0, [r6, r12, lsl #4]!
 *   @0x2e9cd8 ldrsblo pc, [r0, -r0]!
 *   @0x2e9cdc .word 0x112cf8d0
 *   @0x2e9ce0 blle 0x37a714 <_ZTS13C_UTF16String+0x117c0>
 *   @0x2e9ce4 .word 0xf5cd2101
 *   @0x2e9ce8 .word 0xf8d0e94a
 *   @0x2e9cec mrrcne p1, #0x2, r4, r9, c8
 *   @0x2e9cf0 teqne r0, r0, asr #17
 *   @0x2e9cf4 stmdane r3!, {r0, r3, r4, r8} ^
 *   @0x2e9cf8 .word 0xf8d05065
 *   @0x2e9cfc addsvs r1, r9, r8, lsl r1
 *   @0x2e9d00 ldrsbne pc, [r12, -r0]
 *   @0x2e9d04 ldmdavs r1, {r0, r3, r4, r6, sp, lr}
 *   @0x2e9d08 ldrsbvs r6, [r3], -r9
 *   @0x2e9d0c ldmvs r9, {r3, r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2e9d10 ldrsbhs pc, [r8, -r0]
 *   @0x2e9d14 addsvs r4, r10, r10, lsl #8
 *   @0x2e9d18 .word 0xf8d0685a
 *   @0x2e9d1c strmi r1, [r10], #-284
 *   @0x2e9d20 ldclt p0, c6, [r8, #-360]!
 *   @0x2e9d24 .word 0x3108f8d0
 *   @0x2e9d28 addsmi r11, r9, #112, #10
 *   @0x2e9d2c svclt #0xb8460d
 *   @0x2e9d30 ldrblo pc, [pc, #0x103]!
 *   @0x2e9d34 .word 0x3120f8d0
 *   @0x2e9d38 ldrmi r4, [r6], -r4, lsl #12
 *   @0x2e9d3c .word 0xf7ffb90b
 *   @0x2e9d40 movwhs pc, #0xfb6
 *   @0x2e9d44 tstlo r8, r4, asr #17
 *   @0x2e9d48 tstlo r12, r4, asr #17
 *   @0x2e9d4c ldrsblo pc, [r4, -r4]
 *   @0x2e9d50 smlabtpl r0, r4, r8, pc
 *   @0x2e9d54 .word 0xf8c4429e
 *   @0x2e9d58 ble 0x582170 <g_SWFlineaavertbuff+0x2f0a8>
 *   @0x2e9d5c ldrsblo pc, [r0, -r4]
 *   @0x2e9d60 blle 0x47a7e0 <_ZN2VM13m_breakpointsE+0x5ac>
 *   @0x2e9d64 .word 0x310cf8d4
 *   @0x2e9d68 svclt #0xb4429d
 *   @0x2e9d6c strhs r2, [r1, #-0x500]
 *   @0x2e9d70 strhs lr, [r1, #-0x0]
 *   @0x2e9d74 smlawtpl r0, r4, r8, pc
 *   @0x2e9d78 push {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2e9d7c strdlt r4, r5, [r7], r0
 *   @0x2e9d80 pkhbtmi r4, r11, pc, lsl #12
 *   @0x2e9d84 .word 0x46049b11
 *   @0x2e9d88 movwls r9, #0x4d10
 *   @0x2e9d8c stmdbls r4, {r0, r1, r4, r9, r12}
 *   @0x2e9d90 stmdahs r5!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2e9d94 smlabble r6, pc, r2, r4
 *   @0x2e9d98 ldrbmi r4, [r10], -r1, asr #12
 *   @0x2e9d9c pop {r0, r1, r2, r12, sp, pc}
 *   @0x2e9da0 .word 0xf7ff4ff0
 *   @0x2e9da4 .word 0xf06fbfbf
 *   @0x2e9da8 strbmi r0, [r3, #-0x1ff]
 *   @0x2e9dac .word 0x2c03fb01
 *   @0x2e9db0 .word 0x5108fb01
 *   @0x2e9db4 rsbsle r9, r12, r5, lsl #2
 *   @0x2e9db8 bls 0x3f0874
 *   @0x2e9dbc bl 0xff4b51c4 <b2_toiTime+0xfffffffffed5bd20>
 *   @0x2e9dc0 stcle p9, c0, [r9, #-8]
 *   @0x2e9dc4 strvc pc, [r0], r12, asr #11
 *   @0x2e9dc8 orrvc pc, r0, pc, asr #8
 *   @0x2e9dcc beq 0x365f10 <_ZTS12CDS_Priority+0x7f68>
 *   @0x2e9dd0 blx 0x54e1e6 <gp_ActiveMaskObjects+0x951e>
 *   @0x2e9dd4 and pc, r6, r6, lsl #12
 *   @0x2e9dd8 .word 0xf60cfb09
 *   @0x2e9ddc .word 0xf04f426d
 *   @0x2e9de0 andhs r3, r0, #1044480
 *   @0x2e9de4 ldrtmi r9, [r0], -r3, lsl #4
 *   @0x2e9de8 movwls r4, #0x1629
 *   @0x2e9dec andgt pc, r8, sp, asr #17
 *   @0x2e9df0 svc #0x8ef02e
 *   @0x2e9df4 .word 0xf8dd9903
 *   @0x2e9df8 .word 0xf8d4c008
 *   @0x2e9dfc strmi r2, [r12], #280
 *   @0x2e9e00 ldrbmi r9, [r3], #-2817
 *   @0x2e9e04 ldrmi r9, [r9], -r1, lsl #6
 *   @0x2e9e08 ldrvs pc, [r0], -r5, lsl #22
 *   @0x2e9e0c svclt #0xbc2e00
 *   @0x2e9e10 rscslo pc, pc, r0, lsl #2
 *   @0x2e9e14 strmi r1, [r7], #-2422
 *   @0x2e9e18 andhs pc, r12, #0, #22
 *   @0x2e9e1c tsths r8, r4, asr #17
 *   @0x2e9e20 ldrsbhs pc, [r12, -r4]
 *   @0x2e9e24 strtmi r4, [r0], -r2, lsl #8
 *   @0x2e9e28 tsths r12, r4, asr #17
 *   @0x2e9e2c .word 0xf7ff465a
 *   @0x2e9e30 blls 0x369c1c <_ZTS13C_UTF16String+0xcc8>
 *   @0x2e9e34 eorsle r4, r9, r3, asr #10
 *   @0x2e9e38 .word 0x2c09ea4f
 *   @0x2e9e3c .word 0xf8cd4629
 *   @0x2e9e40 strbtmi r12, [r0], -r8
 *   @0x2e9e44 svc #0x64f02e
 *   @0x2e9e48 .word 0xc008f8dd
 *   @0x2e9e4c ldrbmi r9, [r3], #-2817
 *   @0x2e9e50 .word 0xcc10fb05
 *   @0x2e9e54 .word 0xf1bc4681
 *   @0x2e9e58 svclt #0xbc0f00
 *   @0x2e9e5c ldmiblo pc!, {r8, r12, sp, lr, pc} ^
 *   @0x2e9e60 strbtmi r4, [r6], #-1196
 *   @0x2e9e64 ldrsbne pc, [r8, -r4]
 *   @0x2e9e68 strtmi r4, [r0], -lr, lsr #5
 *   @0x2e9e6c .word 0xf109bfa6
 *   @0x2e9e70 bl 0xff42a67c <b2_toiTime+0xfffffffffecd11d8>
 *   @0x2e9e74 strbmi r0, [r10], -r6, lsl #12
 *   @0x2e9e78 bl 0x33aedc
 *   @0x2e9e7c .word 0xf8c42102
 *   @0x2e9e80 .word 0xf8d41118
 *   @0x2e9e84 movwls r1, #0x111c
 *   @0x2e9e88 uadd16mi r4, r10, r1
 *   @0x2e9e8c tstne r12, r4, asr #17
 *   @0x2e9e90 .word 0xf8cd4619
 *   @0x2e9e94 .word 0xf7ffc008
 *   @0x2e9e98 blls 0x369bb4 <_ZTS13C_UTF16String+0xc60>
 *   @0x2e9e9c .word 0xc008f8dd
 *   @0x2e9ea0 bl 0x3bb3b4 <error_g0017+0x14058>
 *   @0x2e9ea4 andle r0, r1, r10, lsl #4
 *   @0x2e9ea8 bfi r4, r3, #12, #15
 *   @0x2e9eac .word 0xf5c39b03
 *   @0x2e9eb0 blls 0x4090b8 <g_RomDisk+0x11898>
 *   @0x2e9eb4 blls 0x430e38 <g_RomDisk+0x39618>
 *   @0x2e9eb8 .word 0xf8d4449c
 *   @0x2e9ebc blx 0x4b6326 <SrcVerts+0x1336a>
 *   @0x2e9ec0 .word 0xf8c4330c
 *   @0x2e9ec4 .word 0xf8d43118
 *   @0x2e9ec8 ldrmi r3, [pc], #-284
 *   @0x2e9ecc tstvc r12, r4, asr #17
 *   @0x2e9ed0 pop {r0, r1, r2, r12, sp, pc}
 *   @0x2e9ed4 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2e9ed8 strdlt r4, r5, [r9], r0
 *   @0x2e9edc ldrsbpl pc, [r8, -r0]!
 *   @0x2e9ee0 .word 0xf8d04604
 *   @0x2e9ee4 b 0x16b633c <b2_toiTime+0xf5ce98>
 *   @0x2e9ee8 .word 0x91042922
 *   @0x2e9eec andls r1, r5, #-268435454
 *   @0x2e9ef0 blle 0x37a974 <_ZTS13C_UTF16String+0x11a20>
 *   @0x2e9ef4 vshl.i64 d4, d9, #0x0
 *   @0x2e9ef8 .word 0xf8d480df
 *   @0x2e9efc addsmi r3, pc, #16, #2
 *   @0x2e9f00 ldrmi sp, [r9, #0xa02]
 *   @0x2e9f04 sbcshi pc, r8, r0, asr #5
 *   @0x2e9f08 .word 0xf06f9805
 *   @0x2e9f0c strbmi r0, [pc, #-0x6ff]
 *   @0x2e9f10 bpl 0x4e8b30 <SrcVerts+0x45b74>
 *   @0x2e9f14 andeq pc, r9, r6, lsl #22
 *   @0x2e9f18 .word 0xd1089007
 *   @0x2e9f1c ldrtmi r9, [r9], -r4, lsl #26
 *   @0x2e9f20 ldrbmi r9, [r3], -r1
 *   @0x2e9f24 .word 0xf8d44620
 *   @0x2e9f28 strls r2, [r0, #-0x134]
 *   @0x2e9f2c .word 0xf8d4e0c2
 *   @0x2e9f30 blls 0x3f2408 <g_PrevViewPortY>
 *   @0x2e9f34 bl 0xfefcff50 <b2_toiTime+0xfffffffffe876aac>
 *   @0x2e9f38 bl 0xff42cb48 <b2_toiTime+0xfffffffffecd36a4>
 *   @0x2e9f3c mrsle r0, spsr
 *   @0x2e9f40 stmdahs r2!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2e9f44 svclt #0xd42d00
 *   @0x2e9f48 bleq 0x32608c
 *   @0x2e9f4c blvc 0xfe327090 <b2_toiTime+0xfffffffffdbcdbec>
 *   @0x2e9f50 ldrsblo pc, [r8, -r4]
 *   @0x2e9f54 strhs pc, [r8], -r6, lsl #22
 *   @0x2e9f58 beq 0x5e4e88 <g_SWFaavertbuff+0x11dc0>
 *   @0x2e9f5c .word 0xf04fbfd4
 *   @0x2e9f60 strhs r3, [r1, #-0x5ff]
 *   @0x2e9f64 strtmi r4, [pc], #-1568
 *   @0x2e9f68 ldrtmi r4, [r10], -r1, asr #12
 *   @0x2e9f6c blx 0x56a14e <g_SWFlineaavertbuff+0x17086>
 *   @0x2e9f70 .word 0xf8c43306
 *   @0x2e9f74 .word 0xf8d43118
 *   @0x2e9f78 ldrbmi r3, [r3], #-284
 *   @0x2e9f7c beq 0x15e48c0 <b2_toiTime+0xe8b41c>
 *   @0x2e9f80 bvc 0xfe327630 <b2_toiTime+0xfffffffffdbce18c>
 *   @0x2e9f84 tstlo r12, r4, asr #17
 *   @0x2e9f88 mcr2 p7, #0x6, pc, c12, c15, #0x7
 *   @0x2e9f8c .word 0xf306fb0a
 *   @0x2e9f90 .word 0xf8d4454f
 *   @0x2e9f94 .word 0xf8d41118
 *   @0x2e9f98 andle r2, lr, r12, lsl r1
 *   @0x2e9f9c ldrmi r4, [r9], #-1071
 *   @0x2e9fa0 .word 0xf8c44452
 *   @0x2e9fa4 .word 0xf8c41118
 *   @0x2e9fa8 qadd16mi r2, r0, r12
 *   @0x2e9fac ldrtmi r4, [r10], -r1, asr #12
 *   @0x2e9fb0 .word 0xf7ff9302
 *   @0x2e9fb4 blls 0x3a9a98 <error_g0017+0x273c>
 *   @0x2e9fb8 stcls p7, c14, [r7, #-936]
 *   @0x2e9fbc orrvc pc, r0, #692060160
 *   @0x2e9fc0 ldrbmi r4, [r10], #-1179
 *   @0x2e9fc4 tsths r12, r4, asr #17
 *   @0x2e9fc8 strne pc, [r6], -r11, lsl #22
 *   @0x2e9fcc tstvs r8, r4, asr #17
 *   @0x2e9fd0 stchs p0, c14, [r0, #-456]
 *   @0x2e9fd4 .word 0xf5cadd08
 *   @0x2e9fd8 andhs r7, r1, r0, lsl #17
 *   @0x2e9fdc orrvc pc, r0, #1325400064
 *   @0x2e9fe0 blx 0x5ce002 <g_SWFlineaavertbuff+0x7af3a>
 *   @0x2e9fe4 and pc, r6, r8, lsl #16
 *   @0x2e9fe8 .word 0xf80afb0b
 *   @0x2e9fec movwhs r4, #0x26d
 *   @0x2e9ff0 rscslo pc, pc, pc, asr #32
 *   @0x2e9ff4 strbmi r9, [r0], -r6
 *   @0x2e9ff8 movwls r4, #0x3629
 *   @0x2e9ffc .word 0xf02e9202
 *   @0x2ea000 bls 0x3a5a28 <_ZTSPKDn+0x260>
 *   @0x2ea004 uasxmi r4, r3, r9
 *   @0x2ea008 ldmdahi r0, {r0, r2, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2ea00c svceq #0xf1b8
 *   @0x2ea010 .word 0xf100bfbc
 *   @0x2ea014 strtmi r3, [r8], #255
 *   @0x2ea018 stmdals r3, {r1, r2, r4, r11, r12}
 *   @0x2ea01c andls r9, r1, r0, lsl #12
 *   @0x2ea020 .word 0xf7ff4620
 *   @0x2ea024 blls 0x4a9ad4 <SrcVerts+0x6b18>
 *   @0x2ea028 eorsne r4, r1, #32, #12
 *   @0x2ea02c shadd16mi r4, r10, pc
 *   @0x2ea030 mrc2 p7, #0x3, apsr_nzcv, c8, c15, #0x7
 *   @0x2ea034 eorsle r4, r3, pc, asr #10
 *   @0x2ea038 blhs 0x5e497c <g_SWFaavertbuff+0x118b4>
 *   @0x2ea03c ldrbmi r4, [r8], -r9, lsr #12
 *   @0x2ea040 cdp p0, #0x6, c15, c6, c14, #0x1
 *   @0x2ea044 blx 0x43b916 <g_RomDisk+0x440f6>
 *   @0x2ea048 pkhbtmi r11, r2, r0, lsl #22
 *   @0x2ea04c svceq #0xf1bb
 *   @0x2ea050 .word 0xf100bfb8
 *   @0x2ea054 stmdals r3, {r0, r1, r2, r3, r4, r5, r6, r7, r9, r11, r12, sp}
 *   @0x2ea058 strtmi r11, [r11], #4024
 *   @0x2ea05c stcvc p5, c15, [r0], {192}
 *   @0x2ea060 .word 0x463944d8
 *   @0x2ea064 strtmi r4, [r0], -r8, lsr #11
 *   @0x2ea068 .word 0xf10abfa6
 *   @0x2ea06c bl 0xff42ac78 <b2_toiTime+0xfffffffffecd17d4>
 *   @0x2ea070 ldrbmi r0, [r3], -r8, lsl #16
 *   @0x2ea074 blls 0x3bb0f4 <error_g0017+0x13d98>
 *   @0x2ea078 .word 0xf8cd9600
 *   @0x2ea07c movwls r12, #0x1008
 *   @0x2ea080 .word 0xf7ff4663
 *   @0x2ea084 stmdals r6, {r1, r3, r4, r5, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ea088 strmi r1, [r7], #-561
 *   @0x2ea08c ldrtmi r4, [r10], -r0, lsr #12
 *   @0x2ea090 mcr2 p7, #0x2, pc, c8, c15, #0x7
 *   @0x2ea094 .word 0xf8dd454f
 *   @0x2ea098 andle r12, r1, r8
 *   @0x2ea09c .word 0xe7df4632
 *   @0x2ea0a0 strtmi r9, [r0], -r4, lsl #26
 *   @0x2ea0a4 shasxmi r4, r2, r9
 *   @0x2ea0a8 stcls p5, c9, [r7, #-0]
 *   @0x2ea0ac stcls p5, c9, [r3, #-4]
 *   @0x2ea0b0 orrvc pc, r0, #826277888
 *   @0x2ea0b4 mcr2 p7, #0x3, pc, c1, c15, #0x7
 *   @0x2ea0b8 .word 0xf8c49d04
 *   @0x2ea0bc stcls p1, c5, [r5, #-208]
 *   @0x2ea0c0 teqpl r8, r4, asr #17
 *   @0x2ea0c4 pop {r0, r3, r12, sp, pc}
 *   @0x2ea0c8 push {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2ea0cc .word 0x46054ff0
 *   @0x2ea0d0 ldmdavs pc, {r0, r2, r5, r6, r7, r12, sp, pc}
 *   @0x2ea0d4 .word 0xac026858
 *   @0x2ea0d8 ldmdavs r6, {r0, r1, r4, r11, sp, lr} ^
 *   @0x2ea0dc strheq r0, [r0], pc
 *   @0x2ea0e0 ldrsbhs pc, [r8, -r5]!
 *   @0x2ea0e4 umlalvs r0, r3, r11, r0
 *   @0x2ea0e8 b 0x16c411c <b2_toiTime+0xf6ac78>
 *   @0x2ea0ec stmdavs r9, {r5, r10, r11, sp} ^
 *   @0x2ea0f0 strhtvs r0, [r7], -r6
 *   @0x2ea0f4 .word 0x6123009b
 *   @0x2ea0f8 ldrsblo pc, [r4, -r5]!
 *   @0x2ea0fc rsbvs r0, r0, r9, lsl #1
 *   @0x2ea100 .word 0x61a360e6
 *   @0x2ea104 ldrsblo pc, [r4, -r5]
 *   @0x2ea108 ldrmi r6, [r12, #0x161]
 *   @0x2ea10c blle 0x50289c <SrcVerts+0x5f8e0>
 *   @0x2ea110 svchs #0x26ebb3
 *   @0x2ea114 bl 0xfefe1130 <b2_toiTime+0xfffffffffe887c8c>
 *   @0x2ea118 .word 0xdc022f21
 *   @0x2ea11c svchs #0x22ebb3
 *   @0x2ea120 .word 0xf8d5dd0c
 *   @0x2ea124 ldrmi r3, [r12, #0x110]
 *   @0x2ea128 bl 0xfefe0a54 <b2_toiTime+0xfffffffffe8875b0>
 *   @0x2ea12c stclle p15, c2, [r6, #-152]
 *   @0x2ea130 svchs #0x21ebb3
 *   @0x2ea134 bl 0xfefe1648 <b2_toiTime+0xfffffffffe8881a4>
 *   @0x2ea138 stclle p15, c2, [r0, #-136]
 *   @0x2ea13c teqvc r4, r5, asr #17
 *   @0x2ea140 teqeq r8, r5, asr #17
 *   @0x2ea144 strhs lr, [r10, -r5, lsr #1]!
 *   @0x2ea148 stmdaeq r6, {r0, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2ea14c .word 0xf909fb07
 *   @0x2ea150 bl 0xff3844f4 <b2_toiTime+0xfffffffffec2b050>
 *   @0x2ea154 blx 0x4ec97a <SrcVerts+0x499be>
 *   @0x2ea158 blx 0x5a7d6e <g_SWFlineaavertbuff+0x54ca6>
 *   @0x2ea15c svchs #0x7710
 *   @0x2ea160 rsbsmi r11, pc, #184, #30
 *   @0x2ea164 mcrrle p5, #0x4, r4, r10, c15
 *   @0x2ea168 bl 0xff34460c <b2_toiTime+0xfffffffffebeb168>
 *   @0x2ea16c stmdbvs r7!, {r0, r1, r2, r10, r11} ^
 *   @0x2ea170 blx 0x3e8daa <ps_parser_funcs+0x1a>
 *   @0x2ea174 blx 0x4b0c7a <SrcVerts+0xdcbe>
 *   @0x2ea178 .word 0xf1bbbb10
 *   @0x2ea17c svclt #0xb80f00
 *   @0x2ea180 bleq 0x3268b4
 *   @0x2ea184 ldcle p5, c4, [r10], #-812
 *   @0x2ea188 bleq 0x5a509c <g_SWFlineaavertbuff+0x51fd4>
 *   @0x2ea18c stmdbeq r8, {r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2ea190 blx 0x5a8dc4 <g_SWFlineaavertbuff+0x55cfc>
 *   @0x2ea194 bge 0x528dc0 <SrcVerts+0x85e04>
 *   @0x2ea198 svceq #0xf1ba
 *   @0x2ea19c bne 0x1e1260 <_Z9GetShaderi+0xc>
 *   @0x2ea1a0 andeq lr, r12, r0, asr #23
 *   @0x2ea1a4 blx 0x2faf2a <ps_hints_apply+0x9b2a>
 *   @0x2ea1a8 .word 0xf1bc7c0c
 *   @0x2ea1ac stcle p15, c0, [r6], #-0
 *   @0x2ea1b0 .word 0xf7ff4628
 *   @0x2ea1b4 blge 0x3a9bfc <error_g0017+0x28a0>
 *   @0x2ea1b8 mlsle r10, r12, r2, r4
 *   @0x2ea1bc stmibvs r3!, {r3, r4, r10, r11, r12, sp} ^
 *   @0x2ea1c0 .word 0xf8d42703
 *   @0x2ea1c4 stmdavs r1!, {r3, r4, sp, lr, pc}
 *   @0x2ea1c8 bl 0xff344358 <b2_toiTime+0xfffffffffebeaeb4>
 *   @0x2ea1cc movwls r0, #0x100e
 *   @0x2ea1d0 b 0xfe2f0c44 <b2_toiTime+0xfffffffffdb977a0>
 *   @0x2ea1d4 bl 0xfed4895c <b2_toiTime+0xfffffffffe5ef4b8>
 *   @0x2ea1d8 b 0xfe3c8960 <b2_toiTime+0xfffffffffdc6f4bc>
 *   @0x2ea1dc bl 0xfec87d70 <b2_toiTime+0xfffffffffe52e8cc>
 *   @0x2ea1e0 ldrmi r7, [r1, #0x6e3]!
 *   @0x2ea1e4 cmnmi lr, #812
 *   @0x2ea1e8 .word 0xf909fb07
 *   @0x2ea1ec stmibeq r6!, {r0, r3, r8, r9, r11, sp, lr, pc} ^
 *   @0x2ea1f0 stmibeq r9!, {r1, r2, r8, r9, r11, sp, lr, pc} ^
 *   @0x2ea1f4 ldrbtvc pc, [pc], r7, asr #12
 *   @0x2ea1f8 stmvs r6!, {r0, r4, r5, r7, r8, r10, lr}
 *   @0x2ea1fc stmdbvs r0!, {r0, r1, r5, r7, r8, r10, r11, r12, lr, pc}
 *   @0x2ea200 .word 0xf8c44431
 *   @0x2ea204 ldrlo lr, [r8], #-48
 *   @0x2ea208 strmi r4, [r6], #-1158
 *   @0x2ea20c bicsvc lr, r1, r1, lsl #22
 *   @0x2ea210 .word 0x0c0cf854
 *   @0x2ea214 .word 0x7edeeb0e
 *   @0x2ea218 ldrbvc lr, [r6], r6, lsl #22
 *   @0x2ea21c .word 0xf8441049
 *   @0x2ea220 b 0x16b1268 <b2_toiTime+0xf57dc4>
 *   @0x2ea224 rsbsne r0, r6, lr, ror #6
 *   @0x2ea228 ldrtmi r6, [r1], #-291
 *   @0x2ea22c strmi r4, [r2], #-1075
 *   @0x2ea230 bicsvc lr, r1, r1, lsl #22
 *   @0x2ea234 bicsvc lr, r3, #3072
 *   @0x2ea238 sbcsvc lr, r2, #2048
 *   @0x2ea23c .word 0xf8441049
 *   @0x2ea240 subsne r1, r11, r8, lsl #24
 *   @0x2ea244 strmi r6, [r11], #-163
 *   @0x2ea248 .word 0x1c04f854
 *   @0x2ea24c .word 0xf8441052
 *   @0x2ea250 bl 0x3b5288 <error_g0017+0xdf2c>
 *   @0x2ea254 ldrsbne r7, [r11], #-51
 *   @0x2ea258 blls 0x3422ec
 *   @0x2ea25c strmi r6, [r11], #-483
 *   @0x2ea260 bl 0x3bb26c <error_g0017+0x13f10>
 *   @0x2ea264 bl 0x3471b8
 *   @0x2ea268 ldrsbne r7, [r11], #-17
 *   @0x2ea26c subne r6, r9, r3, ror #2
 *   @0x2ea270 strmi r4, [r11], #-1034
 *   @0x2ea274 sbcsvc lr, r2, #2048
 *   @0x2ea278 bicsvc lr, r3, #3072
 *   @0x2ea27c subsne r1, r11, r2, asr r0
 *   @0x2ea280 ldrmi r6, [r3], #-227
 *   @0x2ea284 .word 0x2c04f844
 *   @0x2ea288 bicsvc lr, r3, #3072
 *   @0x2ea28c rsbvs r1, r3, r11, asr r0
 *   @0x2ea290 mlslt r5, r5, r7, lr
 *   @0x2ea294 svchi #0xf0e8bd
 *   @0x2ea298 .word 0x4606b570
 *   @0x2ea29c ldrmi r4, [r4], -sp, lsl #12
 *   @0x2ea2a0 shadd16mi r4, r1, r8
 *   @0x2ea2a4 strtmi r4, [r3], -r10, lsr #12
 *   @0x2ea2a8 .word 0xff0ff7ff
 *   @0x2ea2ac ldcllt p0, c2, [r0, #-0]!
 *   @0x2ea2b0 svcmi #0xf0e92d
 *   @0x2ea2b4 ldmdavs r6, {r0, r2, r9, r10, lr}
 *   @0x2ea2b8 ldmdavs r2, {r0, r1, r6, r7, r12, sp, pc} ^
 *   @0x2ea2bc ldrsbvc pc, [r4, -r5]
 *   @0x2ea2c0 adcseq r6, r6, r12, lsl #16
 *   @0x2ea2c4 stmdavs r11, {r1, r4, r7} ^
 *   @0x2ea2c8 ldrsbgt pc, [r4, -r5]!
 *   @0x2ea2cc ldrsbne pc, [r8, -r5]!
 *   @0x2ea2d0 stmdahs r2!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2ea2d4 b 0x16bb9bc <b2_toiTime+0xf62518>
 *   @0x2ea2d8 b 0x16ab4f0 <b2_toiTime+0xf5204c>
 *   @0x2ea2dc strls r0, [r0], -r3, lsl #7
 *   @0x2ea2e0 strls r9, [r2], #-513
 *   @0x2ea2e4 .word 0xf8cd9303
 *   @0x2ea2e8 .word 0x9105c010
 *   @0x2ea2ec bl 0xff0e0f08 <b2_toiTime+0xfffffffffe987a64>
 *   @0x2ea2f0 .word 0xdc022f23
 *   @0x2ea2f4 svchs #0x21ebb7
 *   @0x2ea2f8 .word 0xf8d5dd09
 *   @0x2ea2fc ldrmi r7, [r8, #0x110]!
 *   @0x2ea300 bl 0xff0e0b30 <b2_toiTime+0xfffffffffe98768c>
 *   @0x2ea304 stcle p15, c2, [r7, #-140]
 *   @0x2ea308 svchs #0x21ebb7
 *   @0x2ea30c .word 0xf8c5dd04
 *   @0x2ea310 .word 0xf8c56134
 *   @0x2ea314 rsbs r2, r0, r8, lsr r1
 *   @0x2ea318 .word 0xf06f4466
 *   @0x2ea31c strmi r0, [r10], #-3585
 *   @0x2ea320 strvs pc, [r4, -lr, lsl #22]
 *   @0x2ea324 svclt #0xbc2f00
 *   @0x2ea328 bl 0xff46a4c0 <b2_toiTime+0xfffffffffed1101c>
 *   @0x2ea32c strhs r0, [r1], -r4, lsl #14
 *   @0x2ea330 strhs pc, [r3], #-2830
 *   @0x2ea334 svclt #0xbc2c00
 *   @0x2ea338 bl 0xff36a4ac <b2_toiTime+0xfffffffffec11008>
 *   @0x2ea33c adcsmi r0, r12, #50331648
 *   @0x2ea340 strtmi r11, [r3], -r12, lsr #31
 *   @0x2ea344 blhs 0x12fbc38 <b2_toiTime+0xba2794>
 *   @0x2ea348 addsne sp, r11, r2, lsl #26
 *   @0x2ea34c .word 0xe7fa0076
 *   @0x2ea350 .word 0xf102466a
 *   @0x2ea354 cps #0x10
 *   @0x2ea358 .word 0xf1020b20
 *   @0x2ea35c .word 0xf1020e08
 *   @0x2ea360 sadd16mi r0, r4, r8
 *   @0x2ea364 eorsmi r2, r1, #1073741824
 *   @0x2ea368 bne 0xfebde868 <b2_toiTime+0xfffffffffe4853c4>
 *   @0x2ea36c ldrlo r0, [r0], #-73
 *   @0x2ea370 .word 0xf843581f
 *   @0x2ea374 .word 0xf853700b
 *   @0x2ea378 bl 0x4ce3b8 <SrcVerts+0x2b3fc>
 *   @0x2ea37c bl 0x4ec3a8 <SrcVerts+0x493ec>
 *   @0x2ea380 b 0x16c86e8 <b2_toiTime+0xf6f244>
 *   @0x2ea384 .word 0xf8430868
 *   @0x2ea388 .word 0xf854800c
 *   @0x2ea38c strbmi r7, [pc], #-3088
 *   @0x2ea390 stmdbeq r11, {r0, r1, r8, r9, r11, sp, lr, pc}
 *   @0x2ea394 ldrbvc lr, [r7, r7, lsl #22]
 *   @0x2ea398 .word 0xf843107f
 *   @0x2ea39c strbmi r7, [r7], #-14
 *   @0x2ea3a0 ldrbvc lr, [r7, r7, lsl #22]
 *   @0x2ea3a4 andspl r1, pc, pc, ror r0
 *   @0x2ea3a8 .word 0xf8d7181f
 *   @0x2ea3ac .word 0xf8c98004
 *   @0x2ea3b0 bl 0x3ca3c8 <error_g0017+0x2306c>
 *   @0x2ea3b4 strbtmi r0, [r3], #-2318
 *   @0x2ea3b8 .word 0xa004f8d9
 *   @0x2ea3bc bl 0x4fb704 <SrcVerts+0x58748>
 *   @0x2ea3c0 b 0x16c8728 <b2_toiTime+0xf6f284>
 *   @0x2ea3c4 .word 0xf8c30868
 *   @0x2ea3c8 .word 0xf8548004
 *   @0x2ea3cc ldrbmi r3, [r3], #-3084
 *   @0x2ea3d0 bicsvc lr, r3, #3072
 *   @0x2ea3d4 .word 0xf8c9105b
 *   @0x2ea3d8 ldrmi r3, [r8], #4
 *   @0x2ea3dc ldmvc r8, {r3, r8, r9, r11, sp, lr, pc} ^
 *   @0x2ea3e0 .word 0x0368ea4f
 *   @0x2ea3e4 .word 0xe7be607b
 *   @0x2ea3e8 muleq r6, r4, r8
 *   @0x2ea3ec .word 0xf7ff4628
 *   @0x2ea3f0 mcrlo p13, #0x0, pc, c1, c2, #0x3
 *   @0x2ea3f4 andseq pc, r0, #164, #2
 *   @0x2ea3f8 sublt sp, r3, r11, lsr #3
 *   @0x2ea3fc svchi #0xf0e8bd
 *   @0x2ea400 ldrlt r4, [r0, #-0x60b]
 *   @0x2ea404 strtmi r4, [r1], -r4, lsl #12
 *   @0x2ea408 sadd16mi r4, r10, r0
 *   @0x2ea40c .word 0xff50f7ff
 *   @0x2ea410 ldclt p0, c2, [r0, #-0]
 *   @0x2ea414 stmdavs r3, {r3, r8, r10, r12, sp, pc}
 *   @0x2ea418 strmi r6, [r8], -r2, asr #16
 *   @0x2ea41c umullseq r0, r2, r9, r0
 *   @0x2ea420 ldc2l p7, c15, [r9, #-1020]
 *   @0x2ea424 stclt p0, c2, [r8, #-0]
 *   @0x2ea428 .word 0x460cb570
 *   @0x2ea42c stmdavs r5, {r1, r2, r11, sp, lr} ^
 *   @0x2ea430 adcseq r4, r6, r8, lsl #12
 *   @0x2ea434 eorsne r0, r1, #173
 *   @0x2ea438 .word 0xf7ff122a
 *   @0x2ea43c .word 0xf8c4fc73
 *   @0x2ea440 .word 0xf8c46134
 *   @0x2ea444 andhs r5, r0, r8, lsr r1
 *   @0x2ea448 ldrblt r11, [r0, #-0xd70]!
 *   @0x2ea44c strmi r4, [sp], -r6, lsl #12
 *   @0x2ea450 sadd16mi r4, r4, r0
 *   @0x2ea454 andshs r2, r0, #0, #2
 *   @0x2ea458 stm r10!, {r2, r3, r6, r7, r8, r10, r12, sp, lr, pc}
 *   @0x2ea45c ldmdbvs r2!, {r0, r1, r3, r5, r7, r10, r11, sp, lr}
 *   @0x2ea460 swple r4, r3, [r6]
 *   @0x2ea464 rsbeq pc, r12, r5, lsl #2
 *   @0x2ea468 pop {r0, r5, r9, r10, lr}
 *   @0x2ea46c .word 0xf7fb4070
 *   @0x2ea470 ldcllt p15, c11, [r0, #-692]!
 *   @0x2ea474 movwhs r11, #0x537
 *   @0x2ea478 andvs r4, r11, r12, lsl #12
 *   @0x2ea47c bl 0x632894 <g_SWFaavertbuff+0x5f7cc>
 *   @0x2ea480 strmi r0, [r5], -r1, lsl #4
 *   @0x2ea484 mcr2 p7, #0x2, pc, c15, c12, #0x7
 *   @0x2ea488 stmdblt r11, {r0, r8, r9, r11, r12, pc}
 *   @0x2ea48c eorvs r6, r0, r5
 *   @0x2ea490 andlt r9, r3, r1, lsl #16
 *   @0x2ea494 andeq r11, r0, r0, lsr sp
 *   @0x2ea498 svcmi #0xf0e92d
 *   @0x2ea49c .word 0x460cb09b
 *   @0x2ea4a0 andls r4, r3, r7, lsl r6
 *   @0x2ea4a4 stcvs p8, c6, [r9], {128}
 *   @0x2ea4a8 stmdals r3, {r2, r12, pc}
 *   @0x2ea4ac addsmi r6, r1, #32768
 *   @0x2ea4b0 movwhs sp, #0x6001
 *   @0x2ea4b4 bls 0xc225f8 <b2_toiTime+0x4c9154>
 *   @0x2ea4b8 mulle r1, r7, r2
 *   @0x2ea4bc sub r2, r10, r3, lsl r3
 *   @0x2ea4c0 ldm r3, {r0, r1, r4, r8, r12, sp, pc}
 *   @0x2ea4c4 and r0, r1, r0, lsl #6
 *   @0x2ea4c8 .word 0x46984699
 *   @0x2ea4cc .word 0xf1041ef8
 *   @0x2ea4d0 movwls r0, #0x136c
 *   @0x2ea4d4 .word 0x41434243
 *   @0x2ea4d8 stmdals r1, {r1, r3, r8, r11, sp, pc}
 *   @0x2ea4dc .word 0xf7fb9306
 *   @0x2ea4e0 blls 0x5aa2bc <g_SWFlineaavertbuff+0x571f4>
 *   @0x2ea4e4 strbmi r9, [r3], #-2572
 *   @0x2ea4e8 strbmi r9, [r2], #-2317
 *   @0x2ea4ec beq 0x12e6580 <b2_toiTime+0xb8d0dc>
 *   @0x2ea4f0 blls 0x5b6df4 <g_SWFlineaavertbuff+0x63d2c>
 *   @0x2ea4f4 eorseq pc, pc, #34
 *   @0x2ea4f8 strbmi r4, [r11], #-1097
 *   @0x2ea4fc teqlo pc, r12, lsl #4
 *   @0x2ea500 andeq lr, r2, #206848
 *   @0x2ea504 teqeq pc, r1, lsr #32
 *   @0x2ea508 teqeq pc, #35
 *   @0x2ea50c bne 0xff66cb5c <b2_toiTime+0xfffffffffef136b8>
 *   @0x2ea510 .word 0xf8cd9806
 *   @0x2ea514 ldrmi r10, [r3], r8, lsr #32
 *   @0x2ea518 ldmibeq r6!, {r0, r1, r3, r8, r9, r12, pc}
 *   @0x2ea51c mrsls r9, apsr
 *   @0x2ea520 teqlt r8, r2, lsl #4
 *   @0x2ea524 blx 0x372d3a <_ZTS13C_UTF16String+0x9de6>
 *   @0x2ea528 bl 0x5e915c <g_SWFaavertbuff+0x16094>
 *   @0x2ea52c .word 0xf0250502
 *   @0x2ea530 and r0, r0, r3, lsl #10
 *   @0x2ea534 svcne #0x399d02
 *   @0x2ea538 .word 0x414f424f
 *   @0x2ea53c tstlt r7, r7, lsl #14
 *   @0x2ea540 cmnmi r7, #786432
 *   @0x2ea544 ldrtmi lr, [r7], -r0
 *   @0x2ea548 rscsvc pc, pc, #74448896
 *   @0x2ea54c .word 0xdc014593
 *   @0x2ea550 stcle p2, c4, [r2, #-604]
 *   @0x2ea554 movwls r2, #0x9362
 *   @0x2ea558 .word 0xf8d4e0b0
 *   @0x2ea55c ldmdavs r2, {r2, r3, r4, r7, sp} ^
 *   @0x2ea560 strle r0, [sp, #-0x7d2]
 *   @0x2ea564 stmdals r4, {r0, r5, r7, r8, r10, r11, sp, lr}
 *   @0x2ea568 .word 0xf7fc9300
 *   @0x2ea56c andhs pc, r0, #228, #28
 *   @0x2ea570 .word 0xf8d465a2
 *   @0x2ea574 ldmdavs r1, {r2, r3, r4, r7, sp} ^
 *   @0x2ea578 .word 0x0101f021
 *   @0x2ea57c blls 0x3026c8 <TT_New_Context+0x24c0>
 *   @0x2ea580 stmdals r4, {r0, r3, r9, r11, sp, pc}
 *   @0x2ea584 .word 0xf105fb07
 *   @0x2ea588 .word 0xf7fc9300
 *   @0x2ea58c bls 0x569cc4 <g_SWFlineaavertbuff+0x16bfc>
 *   @0x2ea590 strvs r9, [r0, #0xb00]!
 *   @0x2ea594 .word 0xf0402a00
 *   @0x2ea598 bl 0xff3ca7e4 <b2_toiTime+0xfffffffffec71340>
 *   @0x2ea59c .word 0xf8d40909
 *   @0x2ea5a0 stmdbls r5, {r2, r3, r4, r7, r12, sp}
 *   @0x2ea5a4 stmdaeq r10, {r3, r4, r5, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2ea5a8 .word 0xf042685a
 *   @0x2ea5ac subsvs r0, r10, r1, lsl #4
 *   @0x2ea5b0 .word 0xf8c44b44
 *   @0x2ea5b4 strbtvs r11, [r7], #80
 *   @0x2ea5b8 b 0x16c384c <b2_toiTime+0xf6a3a8>
 *   @0x2ea5bc strbvs r1, [r5, #-0x3aa]!
 *   @0x2ea5c0 b 0x16c3f54 <b2_toiTime+0xf6aab0>
 *   @0x2ea5c4 strtvs r1, [r3], r1, lsr #7
 *   @0x2ea5c8 movweq pc, #0x204f
 *   @0x2ea5cc subslo pc, lr, r4, lsl #17
 *   @0x2ea5d0 orrvc pc, r0, #1325400064
 *   @0x2ea5d4 subslo pc, r12, r4, lsr #17
 *   @0x2ea5d8 .word 0xf1b9d102
 *   @0x2ea5dc andle r0, r7, r0, lsl #30
 *   @0x2ea5e0 strbmi r9, [r1], -r1, lsl #16
 *   @0x2ea5e4 .word 0xf04f464a
 *   @0x2ea5e8 .word 0xf7fb0a01
 *   @0x2ea5ec and pc, r0, r11, lsl pc
 *   @0x2ea5f0 stmdals r3, {r1, r3, r6, r7, r9, r10, lr}
 *   @0x2ea5f4 movteq pc, #0xc104
 *   @0x2ea5f8 stmdbge lr, {r1, r2, r3, r8, r9, r12, pc}
 *   @0x2ea5fc blvs 0xfe391208 <b2_toiTime+0xfffffffffdc37d64>
 *   @0x2ea600 movwls r6, #0xfb40
 *   @0x2ea604 tstls r0, #67108864
 *   @0x2ea608 ldrmi r9, [r0, r0, lsl #6]
 *   @0x2ea60c andls r9, r9, r0, lsl #22
 *   @0x2ea610 teqle r11, r0, lsl #16
 *   @0x2ea614 ldmdblt r3, {r1, r2, r8, r9, r11, r12, pc}
 *   @0x2ea618 stmiblt r11, {r0, r1, r2, r8, r9, r11, r12, pc} ^
 *   @0x2ea61c stcvs p0, c14, [r2, #84]!
 *   @0x2ea620 stmdahs r0, {r4, r5, r9, r10, lr}
 *   @0x2ea624 stmdbls r2, {r3, r4, r5, r6, r7, r12, lr, pc}
 *   @0x2ea628 movweq lr, #0xbb02
 *   @0x2ea62c stmdblo r1, {r0, r4, r6, r8, r12, sp, pc}
 *   @0x2ea630 .word 0xf8123b03
 *   @0x2ea634 .word 0xf883c001
 *   @0x2ea638 .word 0xf883c000
 *   @0x2ea63c .word 0xf883c001
 *   @0x2ea640 ldrb r12, [r3, r2]!
 *   @0x2ea644 strtmi r3, [r10], #-2049
 *   @0x2ea648 strhs lr, [r0, #-0x7eb]
 *   @0x2ea64c ands r9, lr, r9, lsl #10
 *   @0x2ea650 blne 0xff2c5ce4 <b2_toiTime+0xfffffffffeb6c840>
 *   @0x2ea654 strlo pc, [r7, -r5, lsl #22]
 *   @0x2ea658 rscsle r2, r6, r0, lsl #28
 *   @0x2ea65c sasxmi r4, r8, r9
 *   @0x2ea660 cdplo p6, #0x0, c4, c1, c10, #0x1
 *   @0x2ea664 svc #0xaaf5cb
 *   @0x2ea668 qasxmi r4, r10, r9
 *   @0x2ea66c strtmi r4, [r11], #-1539
 *   @0x2ea670 .word 0xf5cb4618
 *   @0x2ea674 ldrtmi lr, [r9], -r4, lsr #31
 *   @0x2ea678 strtmi r4, [pc], #-1578
 *   @0x2ea67c strtmi r4, [r11], #-1539
 *   @0x2ea680 .word 0xf5cb4618
 *   @0x2ea684 .word 0x4603ef9c
 *   @0x2ea688 strb r4, [r5, r11, lsr #8]!
 *   @0x2ea68c .word 0xf1ba461d
 *   @0x2ea690 andle r0, r6, r0, lsl #30
 *   @0x2ea694 .word 0xf1c89801
 *   @0x2ea698 .word 0xf1c90100
 *   @0x2ea69c .word 0xf7fb0200
 *   @0x2ea6a0 cmplt sp, r1, asr #29
 *   @0x2ea6a4 stcvs p8, c9, [r1, #16]!
 *   @0x2ea6a8 mcr2 p7, #0x2, pc, c5, c12, #0x7
 *   @0x2ea6ac strvs r2, [r3, #0x300]!
 *   @0x2ea6b0 ldrsblo pc, [r12], r4
 *   @0x2ea6b4 .word 0xf022685a
 *   @0x2ea6b8 subsvs r0, r10, r1, lsl #4
 *   @0x2ea6bc andslt r9, r11, r9, lsl #16
 *   @0x2ea6c0 svchi #0xf0e8bd
 *   @0x2ea6c4 rsbvs r7, r9, #1929379840
 *   @0x2ea6c8 strhs r11, [r0], #-1299
 *   @0x2ea6cc bhs 0x34f6d4
 *   @0x2ea6d0 strtmi r11, [r2], -r8, lsl #30
 *   @0x2ea6d4 mcr2 p7, #0x7, pc, c0, c15, #0x7
 *   @0x2ea6d8 ldclt p0, c11, [r0, #-8]
 *   @0x2ea6dc strhs r11, [r3, #-0x537]
 *   @0x2ea6e0 strmi r9, [r12], -r0, lsl #10
 *   @0x2ea6e4 mrc2 p7, #0x6, apsr_nzcv, c8, c15, #0x7
 *   @0x2ea6e8 movwhs r11, #0x5910
 *   @0x2ea6ec subslo pc, lr, r4, lsl #17
 *   @0x2ea6f0 ldclt p0, c11, [r0, #-12]!
 *   @0x2ea6f4 strhs r11, [r4, #-0x537]
 *   @0x2ea6f8 strmi r9, [r12], -r0, lsl #10
 *   @0x2ea6fc mcr2 p7, #0x6, pc, c12, c15, #0x7
 *   @0x2ea700 movwhs r11, #0x6910
 *   @0x2ea704 subslo pc, lr, r4, lsl #17
 *   @0x2ea708 ldclt p0, c11, [r0, #-12]!
 *   @0x2ea70c .word 0x460db538
 *   @0x2ea710 stcvs p6, c4, [r11], {28}
 *   @0x2ea714 addmi r6, r11, #16384
 *   @0x2ea718 .word 0xb122d10e
 *   @0x2ea71c rsbeq pc, r12, r5, lsl #2
 *   @0x2ea720 .word 0xf7fb4611
 *   @0x2ea724 .word 0xb12cff2d
 *   @0x2ea728 rsbeq pc, r12, r5, lsl #2
 *   @0x2ea72c muleq r6, r4, r8
 *   @0x2ea730 mrc2 p7, #0x3, apsr_nzcv, c8, c11, #0x7
 *   @0x2ea734 ldclt p0, c2, [r8, #-0]!
 *   @0x2ea738 ldclt p0, c2, [r8, #-24]!
 *   @0x2ea73c ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x2ea740 sbcslt r4, r12, r12, lsl #12
 *   @0x2ea744 smulleq lr, r0, r1, r8
 *   @0x2ea748 andhs r11, r6, r8, lsl #18
 *   @0x2ea74c .word 0xf8d1e09e
 *   @0x2ea750 .word 0xf0199008
 *   @0x2ea754 .word 0xf0000f01
 *   @0x2ea758 stmdblt pc, {r3, r4, r7, pc}
 *   @0x2ea75c adds r2, r5, r4, lsl r0
 *   @0x2ea760 stmdblt r9, {r0, r3, r4, r5, r6, r11, pc}
 *   @0x2ea764 adds r2, r1, r0
 *   @0x2ea768 strhlo pc, [r0], -r7
 *   @0x2ea76c .word 0xddf92b00
 *   @0x2ea770 bhs 0x304b60 <TT_New_Context+0x4958>
 *   @0x2ea774 ldmdavs r8!, {r1, r4, r5, r6, r7, r12, lr, pc} ^
 *   @0x2ea778 rscle r2, pc, r0, lsl #16
 *   @0x2ea77c movwmi pc, #0x103
 *   @0x2ea780 bllo 0x356fac
 *   @0x2ea784 andslo pc, r3, r2, lsr r9
 *   @0x2ea788 addsmi r3, r9, #67108864
 *   @0x2ea78c ldrtmi sp, [r12], r6, ror #3
 *   @0x2ea790 ldmdaeq r0, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x2ea794 strheq lr, [pc], -r12
 *   @0x2ea798 ldrvc pc, [lr, #0x508]
 *   @0x2ea79c svceq #0x2f019
 *   @0x2ea7a0 .word 0xf8dcc50f
 *   @0x2ea7a4 eorvs r3, r11, r0
 *   @0x2ea7a8 stmvs r3!, {r0, r2, r12, lr, pc} ^
 *   @0x2ea7ac sbcsle r2, r9, r0, lsl #22
 *   @0x2ea7b0 stmibvs r3!, {r1, r3, r4, r6, r8, r9, r12, pc} ^
 *   @0x2ea7b4 mcrhs p0, #0x0, lr, c0, c6, #0x0
 *   @0x2ea7b8 ldmdavs r3!, {r0, r1, r2, r6, r7, r12, lr, pc} ^
 *   @0x2ea7bc sbcsle r2, r1, r0, lsl #22
 *   @0x2ea7c0 bhs 0x304890 <TT_New_Context+0x4688>
 *   @0x2ea7c4 ldmvs r3!, {r1, r2, r3, r6, r7, r12, lr, pc} ^
 *   @0x2ea7c8 adcsle r2, lr, r0, lsl #22
 *   @0x2ea7cc stmdbhs r0, {r0, r4, r5, r7, r11, sp, lr}
 *   @0x2ea7d0 .word 0xf102bfa4
 *   @0x2ea7d4 blx 0x3773da <_ZTS13C_UTF16String+0xe486>
 *   @0x2ea7d8 cmpls r8, #67108864
 *   @0x2ea7dc cmpls r9, #11730944
 *   @0x2ea7e0 cmpls r10, #0, #6
 *   @0x2ea7e4 uqasxmi r4, r9, r8
 *   @0x2ea7e8 .word 0xf7fb935b
 *   @0x2ea7ec stmdals r0, {r0, r1, r2, r3, r5, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2ea7f0 svcmi #0x7ff1b0
 *   @0x2ea7f4 stmdbls r2, {r1, r4, r5, r7, r8, r9, r11, r12, lr, pc}
 *   @0x2ea7f8 svcvc #0x80f1b1
 *   @0x2ea7fc blls 0x361abc <_ZTS12CDS_Priority+0x3b14>
 *   @0x2ea800 svcmi #0x7ff1b3
 *   @0x2ea804 svcls #0x3dbaa
 *   @0x2ea808 svcvc #0x80f1b7
 *   @0x2ea80c stmvs r5!, {r1, r2, r5, r7, r10, r11, r12, lr, pc}
 *   @0x2ea810 stmibne r3!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2ea814 .word 0x373f313f
 *   @0x2ea818 movweq pc, #0x2015
 *   @0x2ea81c bne 0xfeb25160 <b2_toiTime+0xfffffffffe3cbcbc>
 *   @0x2ea820 vstmiane r1!, {s28, s29, s30, s31}
 *   @0x2ea824 strne lr, [r7, pc, asr #20]!
 *   @0x2ea828 andge pc, r0, sp, asr #17
 *   @0x2ea82c andls pc, r4, sp, asr #17
 *   @0x2ea830 andgt pc, r8, sp, asr #17
 *   @0x2ea834 .word 0xd1029703
 *   @0x2ea838 ldmdavs r2!, {r0, r4, r5, r6, r11, sp, lr}
 *   @0x2ea83c strbeq lr, [r11, -r10]!
 *   @0x2ea840 bvs 0xb1fc58 <b2_toiTime+0x3c67b4>
 *   @0x2ea844 bvs 0xfeb451d8 <b2_toiTime+0xfffffffffe3ebd34>
 *   @0x2ea848 and r6, r4, r2, ror #21
 *   @0x2ea84c .word 0xf6474b11
 *   @0x2ea850 ssub8mi r7, r1, pc
 *   @0x2ea854 ldrbmi r4, [r0, #-0x618]
 *   @0x2ea858 .word 0x4650bfb8
 *   @0x2ea85c svclt #0xa84561
 *   @0x2ea860 strbmi r4, [r11, #-0x661]
 *   @0x2ea864 .word 0x464bbfb8
 *   @0x2ea868 svclt #0xa842ba
 *   @0x2ea86c addmi r4, r1, #60817408
 *   @0x2ea870 movtls r9, #0x8046
 *   @0x2ea874 subls r9, r9, #-1073741807
 *   @0x2ea878 svcge #0x74f77f
 *   @0x2ea87c .word 0xf77f429a
 *   @0x2ea880 .word 0x4640af71
 *   @0x2ea884 stc2l p5, c15, [lr], {204}
 *   @0x2ea888 andshs lr, r3, r0
 *   @0x2ea88c pop {r2, r3, r4, r6, r12, sp, pc}
 *   @0x2ea890 svclt #0x87f0
 *   @0x2ea894 .word 0xffff8000
 *   @0x2ea898 .word 0xf8d36803
 *   @0x2ea89c .word 0x61022128
 *   @0x2ea8a0 .word 0x312cf8d3
 *   @0x2ea8a4 andhs r6, r0, r3, asr #2
 *   @0x2ea8a8 movwhs r4, #0x770
 *   @0x2ea8ac .word 0x61036143
 *   @0x2ea8b0 ldrblt r4, [r0, #-0x770]!
 *   @0x2ea8b4 stmdbvs r2, {r2, r6, r8, r11, sp, lr}
 *   @0x2ea8b8 addsmi r2, r0, #0
 *   @0x2ea8bc ldmdane r3, {r1, r2, r3, r9, r12, lr, pc}
 *   @0x2ea8c0 .word 0xf854085b
 *   @0x2ea8c4 bl 0x3fe998 <g_RomDisk+0x7178>
 *   @0x2ea8c8 adcmi r0, r9, #204472320
 *   @0x2ea8cc ldmhi r0!, {r1, r8, r12, lr, pc}
 *   @0x2ea8d0 ldcllt p0, c3, [r0, #-4]!
 *   @0x2ea8d4 sasxmi r11, r10, r4
 *   @0x2ea8d8 ubfx r1, r8, #0x18, #0xf
 *   @0x2ea8dc ldcllt p0, c2, [r0, #-0]!
 *   @0x2ea8e0 movwhs r11, #0x5f0
 *   @0x2ea8e4 stmdbvs r6, {r1, r3, r11, sp, lr}
 *   @0x2ea8e8 andlo r6, r1, #68, #18
 *   @0x2ea8ec adcmi r4, r11, #55574528
 *   @0x2ea8f0 stmne r8!, {r1, r2, r3, r9, r12, lr, pc} ^
 *   @0x2ea8f4 .word 0xf8540840
 *   @0x2ea8f8 bl 0x4069c0 <g_RomDisk+0xf1a0>
 *   @0x2ea8fc adcsmi r0, r10, #192, #24
 *   @0x2ea900 rfeia r12!
 *   @0x2ea904 and r0, r10, r4
 *   @0x2ea908 .word 0x4605bf34
 *   @0x2ea90c strb r1, [lr, r3, asr #24]!
 *   @0x2ea910 andle r4, r6, #805306379
 *   @0x2ea914 sbceq lr, r3, r4, lsl #22
 *   @0x2ea918 eorshs pc, r3, r4, asr r8
 *   @0x2ea91c andlo r8, r1, r0, lsl #17
 *   @0x2ea920 andhs lr, r0, #1
 *   @0x2ea924 andvs r4, r10, r0, lsl r6
 *   @0x2ea928 .word 0xf8d0bdf0
 *   @0x2ea92c strhvs r3, [r11], -r0
 *   @0x2ea930 ldrsbtlo pc, [r4], r0
 *   @0x2ea934 andsvs r2, r3, r0
 *   @0x2ea938 andhs r4, r12, r0, ror r7
 *   @0x2ea93c andhs r4, r12, r0, ror r7
 *   @0x2ea940 andhs r4, r0, r0, ror r7
 *   @0x2ea944 .word 0x47704770
 *   @0x2ea948 .word 0x4604b538
 *   @0x2ea94c strtmi r6, [r8], -r5, lsl #16
 *   @0x2ea950 stc2l p7, c15, [r8, #1000]!
 *   @0x2ea954 .word 0x30ccf8d5
 *   @0x2ea958 eorseq pc, pc, #111
 *   @0x2ea95c orrseq r2, r11, r0
 *   @0x2ea960 .word 0xf8d561a3
 *   @0x2ea964 cmpmi r3, #208
 *   @0x2ea968 rfeib r5!
 *   @0x2ea96c orrseq r3, r11, r12, ror #1
 *   @0x2ea970 ldclt p2, c6, [r8, #-396]!
 *   @0x2ea974 .word 0x4606b5f8
 *   @0x2ea978 strmi r6, [sp], -r4, lsl #16
 *   @0x2ea97c stmvs r8, {r0, r1, r3, r8, r11, sp, lr}
 *   @0x2ea980 .word 0xb1236a27
 *   @0x2ea984 qdaddhs r4, r8, r8
 *   @0x2ea988 .word 0xf02e3024
 *   @0x2ea98c eorlo lr, r0, r2, asr #19
 *   @0x2ea990 orrne r6, r0, r11, lsr #16
 *   @0x2ea994 blhs 0x356de8
 *   @0x2ea998 ands sp, r4, r6
 *   @0x2ea99c .word 0x332068fb
 *   @0x2ea9a0 svcne #0xa3ebb0
 *   @0x2ea9a4 and sp, r8, r7, lsl #2
 *   @0x2ea9a8 .word 0x20ccf8d4
 *   @0x2ea9ac ldrsblo pc, [r0], #132
 *   @0x2ea9b0 addsmi r4, r8, #318767104
 *   @0x2ea9b4 andshs sp, r7, r1
 *   @0x2ea9b8 shsub8mi r11, r0, r8
 *   @0x2ea9bc pop {r8, sp}
 *   @0x2ea9c0 .word 0xf7ff40f8
 *   @0x2ea9c4 andhs r11, r7, r1, asr #31
 *   @0x2ea9c8 strdeq r11, r12, [r0], -r8
 *   @0x2ea9cc ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x2ea9d0 stmdavs sp, {r2, r9, r10, lr}
 *   @0x2ea9d4 stchs p6, c4, [r0, #-612]
 *   @0x2ea9d8 sbcshi pc, r2, r0
 *   @0x2ea9dc addsmi r6, r10, #704512
 *   @0x2ea9e0 sbcshi pc, r1, r0, lsl #1
 *   @0x2ea9e4 .word 0x8068f8d5
 *   @0x2ea9e8 blo 0x356df8
 *   @0x2ea9ec .word 0x1124f8d5
 *   @0x2ea9f0 .word 0xf04f0112
 *   @0x2ea9f4 stmne lr, {r0, r10, r11}
 *   @0x2ea9f8 strheq pc, [r6], -r6
 *   @0x2ea9fc strhlo pc, [r8], -r6
 *   @0x2eaa00 strbtvs r4, [r3], #1027
 *   @0x2eaa04 strhvc pc, [r2], -r6
 *   @0x2eaa08 .word 0xf8a45e88
 *   @0x2eaa0c bne 0x111ab84 <b2_toiTime+0x9c16e0>
 *   @0x2eaa10 subsgt pc, lr, r4, lsl #17
 *   @0x2eaa14 .word 0xf8d56520
 *   @0x2eaa18 .word 0xf0077134
 *   @0x2eaa1c blx 0x5ec630 <g_SWFaavertbuff+0x19568>
 *   @0x2eaa20 .word 0xf10cfc07
 *   @0x2eaa24 .word 0xf1bc3cff
 *   @0x2eaa28 vmax.f32 d0, d0, d7
 *   @0x2eaa2c ldm pc, {r0, r1, r2, r3, r5, r7, pc} ^
 *   @0x2eaa30 streq pc, [r4, -r12]
 *   @0x2eaa34 .word 0xadad0bad
 *   @0x2eaa38 andlo r0, r7, sp, lsr #31
 *   @0x2eaa3c and r0, r10, r0, asr #17
 *   @0x2eaa40 stmdbeq r0, {r0, r1, r2, r3, r12, sp}
 *   @0x2eaa44 and r0, r6, r0, asr #32
 *   @0x2eaa48 stmdbeq r0, {r0, r1, r2, r3, r4, r12, sp} ^
 *   @0x2eaa4c and r0, r2, r0, lsl #1
 *   @0x2eaa50 stmibeq r0, {r0, r1, r2, r3, r4, r5, r12, sp}
 *   @0x2eaa54 strbvs r0, [r0, #-0xc0]!
 *   @0x2eaa58 stmdami pc, {r0, r1, r3, r4, r7, r8} ^
 *   @0x2eaa5c cdppl p4, #0x8, c6, c8, c0, #0x5
 *   @0x2eaa60 rfeib r6!
 *   @0x2eaa64 strtvs r0, [r0], r6
 *   @0x2eaa68 strheq pc, [r4], -r6
 *   @0x2eaa6c adcvs r0, r0, #128, #2
 *   @0x2eaa70 orreq r5, r0, r8, lsl #29
 *   @0x2eaa74 rfeib r6!
 *   @0x2eaa78 orreq r0, r0, r6
 *   @0x2eaa7c rfeib r6!
 *   @0x2eaa80 cdppl p0, #0x8, c0, c10, c2, #0x0
 *   @0x2eaa84 bne 0xfe383218 <b2_toiTime+0xfffffffffdc29d74>
 *   @0x2eaa88 andseq pc, r8, r4, lsl #2
 *   @0x2eaa8c .word 0x61a20192
 *   @0x2eaa90 .word 0x10ccf8d5
 *   @0x2eaa94 ldrsblo pc, [r0], #133
 *   @0x2eaa98 orreq r4, r9, r9, lsl r4
 *   @0x2eaa9c stc2 p7, c15, [r0, #-1000]!
 *   @0x2eaaa0 svceq #0x80f419
 *   @0x2eaaa4 stclvs p1, c13, [r3, #-468]!
 *   @0x2eaaa8 stclvs p6, c4, [r7], #128
 *   @0x2eaaac shsaxmi r4, r9, pc
 *   @0x2eaab0 .word 0xff9ef7fc
 *   @0x2eaab4 .word 0xd16d2800
 *   @0x2eaab8 ldmvs r1!, {r6, r9, r10, lr} ^
 *   @0x2eaabc mrc2 p7, #0x7, apsr_nzcv, c3, c11, #0x7
 *   @0x2eaac0 .word 0xd1672800
 *   @0x2eaac4 stcvs p6, c4, [r1, #256]!
 *   @0x2eaac8 .word 0xf7fb463a
 *   @0x2eaacc stmdahs r0, {r5, r6, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2eaad0 .word 0xf8d5d160
 *   @0x2eaad4 .word 0x071b3134
 *   @0x2eaad8 .word 0xf8d5d508
 *   @0x2eaadc vbic.i32 d19, #0xb4
 *   @0x2eaae0 .word 0xf3c301c0
 *   @0x2eaae4 addsmi r0, r1, #128, #4
 *   @0x2eaae8 subs sp, r2, r10, lsl r1
 *   @0x2eaaec ldmne lr!, {r0, r1, r5, r7, r8, r10, r11, sp, lr} ^
 *   @0x2eaaf0 ldrhtle r4, [r2], #35
 *   @0x2eaaf4 stmdaeq r2, {r3, r4, r11, r12, sp, lr} ^
 *   @0x2eaaf8 .word 0xf0020041
 *   @0x2eaafc .word 0xf0010255
 *   @0x2eab00 tstmi r1, #-2147483606
 *   @0x2eab04 addeq r0, r10, r8, lsl #17
 *   @0x2eab08 eorseq pc, r3, r0
 *   @0x2eab0c sbceq pc, r12, #2
 *   @0x2eab10 tsteq r1, r2, lsl #6
 *   @0x2eab14 b 0x1357640 <b2_toiTime+0xbfe19c>
 *   @0x2eab18 .word 0xf8031212
 *   @0x2eab1c strb r2, [r7, r1, lsl #22]!
 *   @0x2eab20 movwne pc, #0x13c3
 *   @0x2eab24 blx 0x373330 <_ZTS13C_UTF16String+0xa3dc>
 *   @0x2eab28 blhs 0x3a773c <error_g0017+0x3e0>
 *   @0x2eab2c blhs 0x41eb44 <g_RomDisk+0x27324>
 *   @0x2eab30 stcvs p1, c13, [r3, #188]!
 *   @0x2eab34 and r4, pc, pc, lsl r4
 *   @0x2eab38 movwlo r6, #0x2da3
 *   @0x2eab3c bne 0x17bbc0 <_Z10AddPerfBarP13SVertex_Floatffj+0x70>
 *   @0x2eab40 stmdble r6!, {r0, r9, r11, sp}
 *   @0x2eab44 .word 0x2c02f813
 *   @0x2eab48 .word 0xf8133302
 *   @0x2eab4c .word 0xf8031c03
 *   @0x2eab50 .word 0xf8032c03
 *   @0x2eab54 ldrb r1, [r2, r4, lsl #24]!
 *   @0x2eab58 bhs 0x3b1748 <error_g0017+0xa3ec>
 *   @0x2eab5c ldmdavc r10, {r0, r3, r4, r8, r11, r12, lr, pc}
 *   @0x2eab60 .word 0xf8133304
 *   @0x2eab64 .word 0xf8031c01
 *   @0x2eab68 .word 0xf8032c01
 *   @0x2eab6c .word 0xf8131c04
 *   @0x2eab70 .word 0xf8132c03
 *   @0x2eab74 .word 0xf8031c02
 *   @0x2eab78 .word 0xf8032c02
 *   @0x2eab7c strb r1, [r11, r3, lsl #24]!
 *   @0x2eab80 pop {r0, r1, r5, sp}
 *   @0x2eab84 strdhs r8, r9, [r6], -r0
 *   @0x2eab88 .word 0x87f0e8bd
 *   @0x2eab8c pop {r0, r1, sp}
 *   @0x2eab90 strdhs r8, r9, [r0], -r0
 *   @0x2eab94 .word 0x87f0e8bd
 *   @0x2eab98 rsbvs r7, r9, #1929379840
 *   @0x2eab9c svcmi #0xf8e92d
 *   @0x2eaba0 stmdahs r0, {r2, r9, r10, lr}
 *   @0x2eaba4 cdpvs p0, #0x4, c13, c5, c10, #0x3
 *   @0x2eaba8 .word 0xf8d42600
 *   @0x2eabac strtmi r1, [r8], -r12, lsr #2
 *   @0x2eabb0 blx 0xff368baa <b2_toiTime+0xfffffffffec0f706>
 *   @0x2eabb4 smlawtvs r12, r4, r8, pc
 *   @0x2eabb8 .word 0xf8d44628
 *   @0x2eabbc .word 0xf7fc1124
 *   @0x2eabc0 .word 0xf8d4fbba
 *   @0x2eabc4 .word 0xf8c4311c
 *   @0x2eabc8 movtlt r6, #0x3124
 *   @0x2eabcc bleq 0x626d10 <g_SWFaavertbuff+0x53c48>
 *   @0x2eabd0 .word 0xf8d446b2
 *   @0x2eabd4 addsmi r3, lr, #24, #2
 *   @0x2eabd8 blx 0x5e1446 <g_SWFaavertbuff+0xe37e>
 *   @0x2eabdc .word 0xf8d4f706
 *   @0x2eabe0 bl 0x90b058 <b2_toiTime+0x1b1bb4>
 *   @0x2eabe4 andsle r0, r0, r7, lsl #18
 *   @0x2eabe8 .word 0xf8584628
 *   @0x2eabec .word 0xf7fc1007
 *   @0x2eabf0 .word 0xf848fba2
 *   @0x2eabf4 .word 0xf899a007
 *   @0x2eabf8 teqlt r3, r4
 *   @0x2eabfc .word 0xf8d94628
 *   @0x2eac00 .word 0xf7fc1008
 *   @0x2eac04 .word 0xf8c9fb98
 *   @0x2eac08 strlo r10, [r1], -r8
 *   @0x2eac0c strtmi lr, [r8], -r1, ror #15
 *   @0x2eac10 ldrsbne pc, [r12, -r4]
 *   @0x2eac14 blx 0xfe6e8c0e <b2_toiTime+0xfffffffffdf8f76a>
 *   @0x2eac18 .word 0xf8c42300
 *   @0x2eac1c qadd16mi r3, r8, r12
 *   @0x2eac20 .word 0x10c0f8d4
 *   @0x2eac24 blx 0xfe4e8c1e <b2_toiTime+0xfffffffffdd8f77a>
 *   @0x2eac28 strtmi r2, [r8], -r0, lsl #12
 *   @0x2eac2c .word 0xf8c46961
 *   @0x2eac30 .word 0xf7fc60c0
 *   @0x2eac34 strtmi pc, [r8], -r0, lsl #23
 *   @0x2eac38 smultbvs r6, r1, r9
 *   @0x2eac3c blx 0x21e8c36 <b2_toiTime+0x1a8f792>
 *   @0x2eac40 bvs 0xb3c4e8 <b2_toiTime+0x3e3044>
 *   @0x2eac44 .word 0xf7fc61a6
 *   @0x2eac48 qsub16mi pc, r8, r6
 *   @0x2eac4c ldrsbtne pc, [r0], r4
 *   @0x2eac50 .word 0xf7fc6226
 *   @0x2eac54 qsub16mi pc, r8, r0
 *   @0x2eac58 adcsvs pc, r0, r4, asr #17
 *   @0x2eac5c ldrsbtne pc, [r4], r4
 *   @0x2eac60 blx 0x1d68c5a <b2_toiTime+0x160f7b6>
 *   @0x2eac64 .word 0xf1046ea0
 *   @0x2eac68 .word 0xf8c40384
 *   @0x2eac6c addsmi r6, r8, #180
 *   @0x2eac70 .word 0xf7fbd104
 *   @0x2eac74 .word 0xf8d4fe12
 *   @0x2eac78 strtvs r3, [r3], r12, lsr #1
 *   @0x2eac7c svchi #0xf8e8bd
 *   @0x2eac80 mvnsmi lr, sp, lsr #18
 *   @0x2eac84 .word 0xf8d02400
 *   @0x2eac88 .word 0x460f511c
 *   @0x2eac8c ldrsbvs pc, [r8, -r0]
 *   @0x2eac90 stmdaeq r12, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2eac94 adcsmi r4, r4, #32, #12
 *   @0x2eac98 ldmdblt r8, {r1, r4, r9, r11, r12, lr, pc} ^
 *   @0x2eac9c .word 0xf304fb08
 *   @0x2eaca0 strlo r4, [r1], #-1593
 *   @0x2eaca4 .word 0xf5cb58e8
 *   @0x2eaca8 .word 0xf1d0ec66
 *   @0x2eacac svclt #0x380001
 *   @0x2eacb0 ldrb r2, [r0, r0]!
 *   @0x2eacb4 blx 0x2f2cee <ps_hints_apply+0x18ee>
 *   @0x2eacb8 stmdalo r12, {r2, r12, lr}
 *   @0x2eacbc ldrhhi lr, [r0, #141]!
 *   @0x2eacc0 mvnsle r2, r0, lsl #16
 *   @0x2eacc4 ldrhhi lr, [r0, #141]!
 *   @0x2eacc8 sadd16mi r11, r4, r0
 *   @0x2eaccc .word 0xffd8f7ff
 *   @0x2eacd0 stmdbvc r3, {r5, r6, r8, r12, sp, pc}
 *   @0x2eacd4 movwhs r11, #0x112b
 *   @0x2eacd8 stmvs r3, {r0, r1, r5, sp, lr}
 *   @0x2eacdc andhs r6, r0, r3, rrx
 *   @0x2eace0 andhs r11, r2, #16, #26
 *   @0x2eace4 stmvs r2, {r1, r5, sp, lr}
 *   @0x2eace8 ldrb r6, [r8, r2, rrx]!
 *   @0x2eacec ldclt p0, c2, [r0, #-24]
 *   @0x2eacf0 strhs r11, [r0, #-0x5f8]
 *   @0x2eacf4 addsmi r9, r5, #7, #28
 *   @0x2eacf8 .word 0x460cd017
 *   @0x2eacfc blvc 0x728e48 <g_SWFvertbuff+0x55d80>
 *   @0x2ead00 .word 0xd110429f
 *   @0x2ead04 stmvs r1!, {r0, r1, r7, r11, sp, lr} ^
 *   @0x2ead08 stmdble r1, {r0, r1, r3, r7, r9, lr}
 *   @0x2ead0c and r2, sp, r3, asr r0
 *   @0x2ead10 .word 0xf7fb1ac9
 *   @0x2ead14 stmdahs r0, {r0, r2, r3, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ead18 stmvs r3!, {r3, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2ead1c blls 0x482df0 <_ZN10InputQuery12ms_InputTextE+0x19fc>
 *   @0x2ead20 andsvs r6, r10, r2, ror #16
 *   @0x2ead24 strlo r11, [r1, #-0xdf8]
 *   @0x2ead28 andhs lr, r3, r5, ror #15
 *   @0x2ead2c eorsvs r2, r3, r0, lsl #6
 *   @0x2ead30 strdeq r11, r12, [r0], -r8
 *   @0x2ead34 ldrbtmi r4, [r8], #-2049
 *   @0x2ead38 bllt 0x5e8d28 <g_SWFaavertbuff+0x15c60>
 *   @0x2ead3c andeq sp, pc, r6, lsr #25
 *   @0x2ead40 sadd16mi r11, r4, r3
 *   @0x2ead44 rscseq pc, pc, #49
 *   @0x2ead48 .word 0xd10c4603
 *   @0x2ead4c strle r0, [r2, #-0x74a]
 *   @0x2ead50 ldrbtmi r4, [r9], #-2324
 *   @0x2ead54 ldmdbmi r4, {r1, sp, lr, pc}
 *   @0x2ead58 .word 0x31204479
 *   @0x2ead5c qadd16mi r4, r2, r8
 *   @0x2ead60 rfeia r8!
 *   @0x2ead64 ldmdbmi r1, {r0, r1, r3, r4, sp, lr, pc}
 *   @0x2ead68 ldrbtmi r4, [r9], #-1642
 *   @0x2ead6c .word 0xf7fd3140
 *   @0x2ead70 stmiblt r0!, {r0, r4, r5, r7, r11, r12, sp, lr, pc}
 *   @0x2ead74 mullo r0, sp, r8
 *   @0x2ead78 bllo 0xfe30b300 <b2_toiTime+0xfffffffffdbb1e5c>
 *   @0x2ead7c .word 0xf89d8023
 *   @0x2ead80 bllo 0xfe2f6d8c <b2_toiTime+0xfffffffffdb9d8e8>
 *   @0x2ead84 .word 0xf89d8063
 *   @0x2ead88 bllo 0xfe2f6d98 <b2_toiTime+0xfffffffffdb9d8f4>
 *   @0x2ead8c .word 0xf89d80a3
 *   @0x2ead90 bllo 0xfe2f6da4 <b2_toiTime+0xfffffffffdb9d900>
 *   @0x2ead94 .word 0xf89d80e3
 *   @0x2ead98 bllo 0xfe2f6db0 <b2_toiTime+0xfffffffffdb9d90c>
 *   @0x2ead9c andlt r8, r2, r3, lsr #2
 *   @0x2eada0 svclt #0xbd10
 *   @0x2eada4 strheq r5, [r10], -r2
 *   @0x2eada8 andeq r5, r10, r12, lsr #17
 *   @0x2eadac muleq r10, r10, r8
 *   @0x2eadb0 strdlt r11, r12, [r7], r0
 *   @0x2eadb4 ldrmi r4, [r3], -r12, lsl #12
 *   @0x2eadb8 andls r10, r0, #12288
 *   @0x2eadbc andls r10, r1, #4, #20
 *   @0x2eadc0 .word 0x10c0f8d1
 *   @0x2eadc4 .word 0xf8d44605
 *   @0x2eadc8 .word 0xf7ff20bc
 *   @0x2eadcc mulls r5, r1, pc
 *   @0x2eadd0 cmple r6, r0, lsl #16
 *   @0x2eadd4 stmdbge r5, {r3, r5, r9, r10, lr}
 *   @0x2eadd8 .word 0xf886f7fc
 *   @0x2eaddc andls r9, r3, r5, lsl #22
 *   @0x2eade0 .word 0xd14e2b00
 *   @0x2eade4 .word 0x73fff420
 *   @0x2eade8 movweq pc, #0x1023
 *   @0x2eadec .word 0xd1482b00
 *   @0x2eadf0 svceq #0x4f010
 *   @0x2eadf4 sbceq pc, r4, #4, #2
 *   @0x2eadf8 andsle r4, r2, r8, lsr #12
 *   @0x2eadfc ldrbtmi r4, [r9], #-2338
 *   @0x2eae00 .word 0xf7fd315c
 *   @0x2eae04 andls pc, r5, r7, ror #16
 *   @0x2eae08 teqle r10, r0, lsl #16
 *   @0x2eae0c ldrbeq pc, [r8], r4, lsl #2
 *   @0x2eae10 .word 0xf89d4628
 *   @0x2eae14 ldrtmi r1, [r2], -r12
 *   @0x2eae18 .word 0xff92f7ff
 *   @0x2eae1c bllt 0xfe30ee38 <b2_toiTime+0xfffffffffdbb5994>
 *   @0x2eae20 ldmdbmi r10, {r0, r1, sp, lr, pc}
 *   @0x2eae24 orrslo r4, r0, r9, ror r4
 *   @0x2eae28 .word 0xf104e7eb
 *   @0x2eae2c strtmi r0, [r8], -r8, ror #15
 *   @0x2eae30 mulne r12, sp, r8
 *   @0x2eae34 .word 0xf7ff463a
 *   @0x2eae38 andls pc, r5, r3, lsl #31
 *   @0x2eae3c stmdbls r3, {r3, r8, r9, r11, r12, sp, pc}
 *   @0x2eae40 ldcleq p1, c15, [r8], #16
 *   @0x2eae44 .word 0x03fff021
 *   @0x2eae48 svcvc #0x80f5b3
 *   @0x2eae4c strtmi sp, [r8], -pc, lsl #2
 *   @0x2eae50 strbtmi r11, [r2], -r9, asr #5
 *   @0x2eae54 .word 0xff74f7ff
 *   @0x2eae58 ldmiblt r0, {r0, r2, r12, pc}
 *   @0x2eae5c .word 0xf89d4628
 *   @0x2eae60 .word 0xf504100c
 *   @0x2eae64 .word 0xf7ff7284
 *   @0x2eae68 andls pc, r5, r11, ror #30
 *   @0x2eae6c ldm r6, {r0, r3, sp, lr, pc}
 *   @0x2eae70 .word 0xf504000f
 *   @0x2eae74 stm r12, {r2, r7, r10, r12, sp, lr}
 *   @0x2eae78 ldm r7, {r0, r1, r2, r3}
 *   @0x2eae7c stm r4, {r0, r1, r2, r3}
 *   @0x2eae80 stmdals r5, {r0, r1, r2, r3}
 *   @0x2eae84 ldcllt p0, c11, [r0, #28]!
 *   @0x2eae88 andeq r5, r10, r6, lsl #16
 *   @0x2eae8c andeq r5, r10, r0, ror #15
 *   @0x2eae90 svcmi #0xf0e92d
 *   @0x2eae94 cdpvs p6, #0x4, c4, c9, c12, #0x0
 *   @0x2eae98 pkhbtmi r11, r1, r7, lsl #1
 *   @0x2eae9c swpls r4, r2, [r9]
 *   @0x2eaea0 .word 0xf7fb2100
 *   @0x2eaea4 andls pc, lr, r0, lsl #26
 *   @0x2eaea8 andhs r11, r1, r8, lsl #2
 *   @0x2eaeac ldmibmi r2!, {r0, r4, r5, r7, sp, lr, pc}
 *   @0x2eaeb0 .word 0xf1044648
 *   @0x2eaeb4 ldrbtmi r0, [r9], #-696
 *   @0x2eaeb8 .word 0xf7fd31c4
 *   @0x2eaebc andls pc, lr, r11, lsl #16
 *   @0x2eaec0 mvnsle r2, r0, lsl #16
 *   @0x2eaec4 ldrsbtlo pc, [r8], r4
 *   @0x2eaec8 addsmi r4, r3, #696320
 *   @0x2eaecc addshi pc, r12, r0, asr #32
 *   @0x2eaed0 ldrsbtlo pc, [r12], r4
 *   @0x2eaed4 .word 0xf0002b00
 *   @0x2eaed8 .word 0xf8d98097
 *   @0x2eaedc bhs 0x6b2ef4 <g_SWFlinevertbuff+0x5fe2c>
 *   @0x2eaee0 addshi pc, r2, r0, asr #4
 *   @0x2eaee4 addsmi r0, r3, #294912
 *   @0x2eaee8 blhs 0x560ef4 <g_SWFlineaavertbuff+0xde2c>
 *   @0x2eaeec bhs 0x561304 <g_SWFlineaavertbuff+0xe23c>
 *   @0x2eaef0 andhs r11, r9, #40, #30
 *   @0x2eaef4 adcshs pc, r12, r4, asr #17
 *   @0x2eaef8 blge 0x673700 <g_SWFlinevertbuff+0x20638>
 *   @0x2eaefc tsths r0, r0, lsl #4
 *   @0x2eaf00 stmdals r9, {r0, r8, r9, r12, pc}
 *   @0x2eaf04 ldrsbtlo pc, [r12], r4
 *   @0x2eaf08 .word 0xf8c1f7fd
 *   @0x2eaf0c strmi r9, [r6], -lr, lsl #26
 *   @0x2eaf10 sbceq pc, r0, r4, asr #17
 *   @0x2eaf14 cmnle r9, r0, lsl #26
 *   @0x2eaf18 ldrbtmi r4, [pc], #-3992
 *   @0x2eaf1c .word 0xf8d437d4
 *   @0x2eaf20 bl 0x477218 <g_RomDisk+0x7f9f8>
 *   @0x2eaf24 addsmi r1, sp, #1342177280
 *   @0x2eaf28 strbmi sp, [r8], -r8, lsl #4
 *   @0x2eaf2c .word 0xf7fc4639
 *   @0x2eaf30 .word 0x900effd1
 *   @0x2eaf34 cmple sp, r0, lsl #16
 *   @0x2eaf38 ldrb r3, [r0, r1, lsl #10]!
 *   @0x2eaf3c .word 0x20c0f8d4
 *   @0x2eaf40 .word 0x0c00f04f
 *   @0x2eaf44 .word 0xf8d49204
 *   @0x2eaf48 bllo 0x337240
 *   @0x2eaf4c movwle r4, #0x859c
 *   @0x2eaf50 ldrsbtne pc, [r12], r4
 *   @0x2eaf54 .word 0x30c0f8d4
 *   @0x2eaf58 .word 0xf8d91e4e
 *   @0x2eaf5c .word 0x21002004
 *   @0x2eaf60 stcls p0, c14, [r4, #-220]
 *   @0x2eaf64 ldrmi r2, [r8], r0, lsl #6
 *   @0x2eaf68 ldrsbths pc, [r12], r4
 *   @0x2eaf6c bl 0xff5f9778 <b2_toiTime+0xfffffffffeea02d4>
 *   @0x2eaf70 ldrmi r0, [r0, #0x202]
 *   @0x2eaf74 stmvs r9!, {r1, r5, r9, r12, lr, pc} ^
 *   @0x2eaf78 stmibvs r10!, {r0, r1, r3, r5, r7, r9, r10, lr} ^
 *   @0x2eaf7c stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x2eaf80 stmdble pc, {r0, r4, r7, r9, lr}
 *   @0x2eaf84 muleq pc, r5, r8
 *   @0x2eaf88 .word 0xf105af12
 *   @0x2eaf8c stm r7, {r4, r9, r10}
 *   @0x2eaf90 ldm r6, {r0, r1, r2, r3}
 *   @0x2eaf94 stm r5, {r0, r1, r2, r3}
 *   @0x2eaf98 ldm r7, {r0, r1, r2, r3}
 *   @0x2eaf9c stm r6, {r0, r1, r2, r3}
 *   @0x2eafa0 movwhs r0, #0x100f
 *   @0x2eafa4 stmibvs r9!, {r1, r3, r5, r7, r11, sp, lr} ^
 *   @0x2eafa8 stmdale r5, {r1, r3, r7, r9, lr}
 *   @0x2eafac .word 0xf8db1a8a
 *   @0x2eafb0 ldrlo r1, [r0, #-0xc]
 *   @0x2eafb4 ldmible r7, {r0, r4, r7, r9, lr} ^
 *   @0x2eafb8 ands r2, r0, r9, lsl #6
 *   @0x2eafbc sbcle r2, r7, r0, lsl #22
 *   @0x2eafc0 .word 0x0c01f10c
 *   @0x2eafc4 ldmvs sp, {r0, r1, r2, r3, r4, r5, r7, r8, r9, r10, sp, lr, pc} ^
 *   @0x2eafc8 addmi r1, r5, #16, #20
 *   @0x2eafcc tstlo r0, #393216
 *   @0x2eafd0 adcsmi r3, r1, #1073741824
 *   @0x2eafd4 ldmvs r8, {r0, r2, r9, r12, lr, pc}
 *   @0x2eafd8 ldmible r4!, {r4, r7, r9, lr} ^
 *   @0x2eafdc movwls r2, #0xe308
 *   @0x2eafe0 ldmvs r9, {r3, sp, lr, pc} ^
 *   @0x2eafe4 ldmle r9!, {r0, r4, r7, r9, lr} ^
 *   @0x2eafe8 ldmvs r9, {r1, r4, r6, r9, r11, r12}
 *   @0x2eafec stmdble pc, {r0, r4, r7, r9, lr}
 *   @0x2eaff0 mul sp, r10, r0
 *   @0x2eaff4 .word 0xf8d49809
 *   @0x2eaff8 .word 0xf7fc10c0
 *   @0x2eaffc movwhs pc, #0x99c
 *   @0x2eb000 .word 0xf8c4980e
 *   @0x2eb004 and r3, r4, r0, asr #1
 *   @0x2eb008 and r2, r2, r3
 *   @0x2eb00c and r4, r0, r8, lsr #12
 *   @0x2eb010 andls r2, r12, r0
 *   @0x2eb014 .word 0xf0402800
 *   @0x2eb018 .word 0xf1ba84be
 *   @0x2eb01c .word 0xf04f0f00
 *   @0x2eb020 rsbvs r0, r0, r1, lsl #6
 *   @0x2eb024 vaddl.s8 q11, d0, d19
 *   @0x2eb028 stmdage sp, {r1, r2, r6, r7, r10, pc}
 *   @0x2eb02c andls r10, r4, lr, lsl #18
 *   @0x2eb030 strbmi r9, [r8], -r0
 *   @0x2eb034 mrsls r9, apsr
 *   @0x2eb038 ldrsbths pc, [r12], r4
 *   @0x2eb03c .word 0x10c0f8d4
 *   @0x2eb040 .word 0xf7ff6e67
 *   @0x2eb044 andsls pc, r2, r5, asr lr
 *   @0x2eb048 strhs r11, [r0, #-0x108]
 *   @0x2eb04c cdpge p0, #0x1, c14, c2, c1, #0x1
 *   @0x2eb050 ldrtmi r4, [r1], -r8, asr #12
 *   @0x2eb054 .word 0xff48f7fb
 *   @0x2eb058 andls r9, sp, r2, lsl r11
 *   @0x2eb05c mvnsle r2, r0, lsl #22
 *   @0x2eb060 rscseq pc, pc, #48
 *   @0x2eb064 .word 0xf010d1f1
 *   @0x2eb068 ldrtmi r0, [r1], -r4, lsl #30
 *   @0x2eb06c andle r4, r2, r8, asr #12
 *   @0x2eb070 mcr2 p7, #0x5, pc, c8, c11, #0x7
 *   @0x2eb074 .word 0xf7fbe001
 *   @0x2eb078 ldcls p15, c15, [r2, #-220]
 *   @0x2eb07c stchs p6, c4, [r0, #-512]
 *   @0x2eb080 stmdals lr, {r0, r1, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2eb084 .word 0xf02d2109
 *   @0x2eb088 strmi lr, [r0, #0xde0]
 *   @0x2eb08c movwhs sp, #0x8903
 *   @0x2eb090 strls r9, [r5, #-0x312]
 *   @0x2eb094 .word 0xf5b8e0dd
 *   @0x2eb098 svclt #0x347f80
 *   @0x2eb09c vst1.16 {d20, d21, d22}, [pc], r3
 *   @0x2eb0a0 stm sp, {r7, r8, r9, r12, sp, lr}
 *   @0x2eb0a4 .word 0xf8c40060
 *   @0x2eb0a8 shadd16mi r3, r8, r8
 *   @0x2eb0ac strtmi r2, [r10], -r12, lsl #2
 *   @0x2eb0b0 .word 0xf7fc9306
 *   @0x2eb0b4 blls 0x7ab06c <b2_toiTime+0x51bc8>
 *   @0x2eb0b8 blhs 0x30f0d4 <af_shaper_get_elem+0x4942>
 *   @0x2eb0bc sbchi pc, r9, r0, asr #32
 *   @0x2eb0c0 blmi 0xebcb30 <b2_toiTime+0x76368c>
 *   @0x2eb0c4 ldrbtmi r4, [r11], #-1667
 *   @0x2eb0c8 orrvc pc, r0, #12582912
 *   @0x2eb0cc blmi 0xe4fcf4 <b2_toiTime+0x6f6850>
 *   @0x2eb0d0 movwls r4, #0xa47b
 *   @0x2eb0d4 strmi r9, [r2, #0x806]
 *   @0x2eb0d8 stcls p0, c13, [sp, #-104]
 *   @0x2eb0dc .word 0xf0154648
 *   @0x2eb0e0 andle r0, r8, r4, lsl #10
 *   @0x2eb0e4 ldrbmi r9, [r10], -r10, lsl #22
 *   @0x2eb0e8 mvneq pc, r3, lsl #2
 *   @0x2eb0ec mrc2 p7, #0x7, apsr_nzcv, c2, c12, #0x7
 *   @0x2eb0f0 .word 0xb1409012
 *   @0x2eb0f4 stmdbls r8, {r2, r3, r5, r7, sp, lr, pc}
 *   @0x2eb0f8 .word 0xf7fc465a
 *   @0x2eb0fc andsls pc, r2, r11, ror #29
 *   @0x2eb100 .word 0xf0402800
 *   @0x2eb104 .word 0xf10a80a6
 *   @0x2eb108 .word 0xf10b0a01
 *   @0x2eb10c strb r0, [r1, r12, lsl #22]!
 *   @0x2eb110 beq 0x526040 <SrcVerts+0x83084>
 *   @0x2eb114 strbmi r2, [r8], -r9, lsl #2
 *   @0x2eb118 .word 0xf10afb01
 *   @0x2eb11c .word 0xfc08f7fb
 *   @0x2eb120 andsls r4, r2, r5, lsl #12
 *   @0x2eb124 cmphs r3, #16, #2
 *   @0x2eb128 adds r9, r1, r2, lsl r3
 *   @0x2eb12c .word 0x0103f018
 *   @0x2eb130 strbmi sp, [r8], -r9
 *   @0x2eb134 smlabteq r4, r1, r1, pc
 *   @0x2eb138 blx 0x1a912e <_ZN7IBitmap6CreateEv+0x2>
 *   @0x2eb13c andsls r11, r2, r8, lsl #18
 *   @0x2eb140 cmphs r3, #1
 *   @0x2eb144 blls 0x663354 <g_SWFlinevertbuff+0x1028c>
 *   @0x2eb148 ldrtmi r4, [r1], -r8, asr #12
 *   @0x2eb14c strle r0, [r2, #-0x75a]
 *   @0x2eb150 mrc2 p7, #0x1, apsr_nzcv, c8, c11, #0x7
 *   @0x2eb154 .word 0xf7fbe001
 *   @0x2eb158 bls 0x7aac7c <b2_toiTime+0x517d8>
 *   @0x2eb15c cmnle r7, r0, lsl #20
 *   @0x2eb160 .word 0x21099b0e
 *   @0x2eb164 tstlo r8, #1024
 *   @0x2eb168 stmdble sp, {r3, r4, r7, r9, lr}
 *   @0x2eb16c ldrmi r2, [r5], -r8, lsl #6
 *   @0x2eb170 rsb r9, lr, r2, lsl r3
 *   @0x2eb174 rsbvc r6, r3, r1, lsl #12
 *   @0x2eb178 andeq r5, r10, lr, asr #14
 *   @0x2eb17c andeq r5, r10, r10, ror #13
 *   @0x2eb180 andeq r5, r10, lr, lsr r5
 *   @0x2eb184 andeq r5, r10, r4, lsr r5
 *   @0x2eb188 svchs #0x1f1b0
 *   @0x2eb18c .word 0x4682bf34
 *   @0x2eb190 bhs 0x3672d4 <_ZTS12CDS_Priority+0x932c>
 *   @0x2eb194 stm sp, {r0, r8, sp}
 *   @0x2eb198 bl 0x56b2b0 <g_SWFlineaavertbuff+0x181e8>
 *   @0x2eb19c ldrtmi r0, [r8], -r1, lsl #6
 *   @0x2eb1a0 .word 0xff75f7fc
 *   @0x2eb1a4 .word 0x46059b12
 *   @0x2eb1a8 cmple r2, r0, lsl #22
 *   @0x2eb1ac .word 0x46484652
 *   @0x2eb1b0 .word 0xf7fb4629
 *   @0x2eb1b4 strmi pc, [r2], -r12, ror #23
 *   @0x2eb1b8 stmdahs r0, {r1, r4, r12, pc}
 *   @0x2eb1bc blls 0x49f6e8 <TimingData+0x56d0>
 *   @0x2eb1c0 stm sp, {r3, r4, r5, r9, r10, lr}
 *   @0x2eb1c4 .word 0x210c0044
 *   @0x2eb1c8 .word 0xff61f7fc
 *   @0x2eb1cc blhs 0x311e1c <af_shaper_get_elem+0x768a>
 *   @0x2eb1d0 .word 0xf8ddd13f
 *   @0x2eb1d4 pkhbtmi r11, r0, r4
 *   @0x2eb1d8 tsteq r12, r4, asr #17
 *   @0x2eb1dc addmi r9, r11, #98304
 *   @0x2eb1e0 .word 0xf8dbd033
 *   @0x2eb1e4 stmdbhs r0, {r12}
 *   @0x2eb1e8 ldrbmi sp, [r1, #-0xb19]
 *   @0x2eb1ec shadd16mi sp, r2, r7
 *   @0x2eb1f0 strtmi r4, [r9], #-1592
 *   @0x2eb1f4 .word 0xf7fd9302
 *   @0x2eb1f8 .word 0xf8c8fb64
 *   @0x2eb1fc bls 0x76b204 <b2_toiTime+0x11d60>
 *   @0x2eb200 bllt 0xf91e10 <b2_toiTime+0x83896c>
 *   @0x2eb204 mulhs r4, r11, r8
 *   @0x2eb208 andhs pc, r4, r8, lsl #17
 *   @0x2eb20c mulhs r4, r11, r8
 *   @0x2eb210 .word 0x1008f8db
 *   @0x2eb214 stmdbhs r0, {r1, r3, r7, r8, r12, sp, pc}
 *   @0x2eb218 ldrbmi sp, [r1, #-0xb01]
 *   @0x2eb21c movwhs sp, #0x9901
 *   @0x2eb220 shadd16mi lr, r2, r4
 *   @0x2eb224 strtmi r4, [r9], #-1592
 *   @0x2eb228 .word 0xf7fd9302
 *   @0x2eb22c .word 0xf8c8fb4a
 *   @0x2eb230 bls 0x76b258 <b2_toiTime+0x11db4>
 *   @0x2eb234 tstlt r2, r2, lsl #22
 *   @0x2eb238 .word 0xf8c8e00b
 *   @0x2eb23c movwlo r1, #0x1008
 *   @0x2eb240 stmdaeq r12, {r3, r8, r12, sp, lr, pc}
 *   @0x2eb244 bleq 0x627678 <g_SWFaavertbuff+0x545b0>
 *   @0x2eb248 movwhs lr, #0x7c8
 *   @0x2eb24c and r9, r0, r2, lsl r3
 *   @0x2eb250 ldrtmi r2, [r8], -r0, lsl #10
 *   @0x2eb254 .word 0xf7fc9905
 *   @0x2eb258 ldrtmi pc, [r8], -lr, ror #16
 *   @0x2eb25c .word 0xf7fc4629
 *   @0x2eb260 blls 0x7a9410 <b2_toiTime+0x4ff6c>
 *   @0x2eb264 blhs 0x30fe9c <af_shaper_get_elem+0x570a>
 *   @0x2eb268 orrshi pc, r5, #64
 *   @0x2eb26c .word 0x10c0f8d4
 *   @0x2eb270 ldrsbths pc, [r12], r4
 *   @0x2eb274 .word 0xf0004293
 *   @0x2eb278 .word 0x01188394
 *   @0x2eb27c .word 0xf5b05808
 *   @0x2eb280 andle r7, r1, r0, lsl #31
 *   @0x2eb284 ldrb r3, [r5, r1, lsl #6]!
 *   @0x2eb288 andls r2, r11, #268435456
 *   @0x2eb28c .word 0xf10dab0e
 *   @0x2eb290 movwls r0, #0xa48
 *   @0x2eb294 .word 0xf8cd4648
 *   @0x2eb298 movwhs r10, #0x4004
 *   @0x2eb29c .word 0x10c0f8d4
 *   @0x2eb2a0 ldrsbths pc, [r12], r4
 *   @0x2eb2a4 .word 0xf7ff6e67
 *   @0x2eb2a8 andls pc, sp, r3, lsr #26
 *   @0x2eb2ac .word 0xf0402800
 *   @0x2eb2b0 strbmi r8, [r8], -r6, lsl #1
 *   @0x2eb2b4 .word 0xf7fba90d
 *   @0x2eb2b8 blls 0x66ab1c <g_SWFlinevertbuff+0x17a54>
 *   @0x2eb2bc blhs 0x30f2fc <af_shaper_get_elem+0x4b6a>
 *   @0x2eb2c0 .word 0xf030d178
 *   @0x2eb2c4 strdle r0, r1, [r4], -pc
 *   @0x2eb2c8 svcvc #0x80f5b3
 *   @0x2eb2cc andhs sp, r3, r12
 *   @0x2eb2d0 .word 0xf010e075
 *   @0x2eb2d4 stmdbge sp, {r2, r8, r9, r10, r11}
 *   @0x2eb2d8 andle r4, r2, r8, asr #12
 *   @0x2eb2dc ldc2l p7, c15, [r2, #-1004]!
 *   @0x2eb2e0 .word 0xf7fbe00c
 *   @0x2eb2e4 and pc, r9, r1, lsl #28
 *   @0x2eb2e8 svceq #0x4f010
 *   @0x2eb2ec strbmi r10, [r8], -sp, lsl #18
 *   @0x2eb2f0 .word 0xf7fbd002
 *   @0x2eb2f4 and pc, r1, r7, lsl #24
 *   @0x2eb2f8 ldc2 p7, c15, [r4, #-1004]
 *   @0x2eb2fc strmi r9, [r6], -sp, lsl #22
 *   @0x2eb300 mvnle r2, r0, lsl #22
 *   @0x2eb304 .word 0xf0339b0e
 *   @0x2eb308 ldmdals r2, {r0, r1, r2, r3, r4, r5, r6, r7}
 *   @0x2eb30c .word 0x210cbf0c
 *   @0x2eb310 .word 0xf02d2105
 *   @0x2eb314 addmi lr, r6, #39424
 *   @0x2eb318 cdphs p8, #0x0, c13, c0, c14, #0x2
 *   @0x2eb31c .word 0xf5b6d04c
 *   @0x2eb320 svclt #0x283f80
 *   @0x2eb324 strlo pc, [r0], pc, asr #8
 *   @0x2eb328 stmdbge sp, {r9, sp}
 *   @0x2eb32c smlawtvs r0, r4, r8, pc
 *   @0x2eb330 ldrtmi r9, [r3], -r1, lsl #2
 *   @0x2eb334 ldrtmi r9, [r8], -r0, lsl #4
 *   @0x2eb338 .word 0xf7fc2110
 *   @0x2eb33c blls 0x66ade4 <g_SWFlinevertbuff+0x17d1c>
 *   @0x2eb340 smlawteq r4, r4, r8, pc
 *   @0x2eb344 teqle r9, r0, lsl #22
 *   @0x2eb348 ldreq pc, [r0, #-0x100]
 *   @0x2eb34c .word 0x4698469b
 *   @0x2eb350 stmdbls lr, {r3, r6, r9, r10, lr}
 *   @0x2eb354 andseq pc, r0, #1073741865
 *   @0x2eb358 ldc2l p7, c15, [r2], #1020
 *   @0x2eb35c .word 0xf845900d
 *   @0x2eb360 cmplt r0, r4, lsl #24
 *   @0x2eb364 .word 0xb32b9b0d
 *   @0x2eb368 .word 0xf8d44638
 *   @0x2eb36c .word 0xf7fb1124
 *   @0x2eb370 movwhs pc, #0xfe2
 *   @0x2eb374 smlawtlo r4, r4, r8, pc
 *   @0x2eb378 rfedb r5!
 *   @0x2eb37c rfedb r5!
 *   @0x2eb380 addsmi r3, r10, #16, #24
 *   @0x2eb384 rfedb r5!
 *   @0x2eb388 rfedb r5!
 *   @0x2eb38c subsmi r2, r11, #2560
 *   @0x2eb390 ble 0x53be00 <obj_has_event+0x1290>
 *   @0x2eb394 .word 0x8c0cf825
 *   @0x2eb398 .word 0x8c10f825
 *   @0x2eb39c .word 0x8c0ef825
 *   @0x2eb3a0 .word 0x8c0af825
 *   @0x2eb3a4 .word 0x8c08f825
 *   @0x2eb3a8 bleq 0x3677dc <_ZTS12CDS_Priority+0x9834>
 *   @0x2eb3ac ldrmi r3, [r3, #0x510]!
 *   @0x2eb3b0 ldrb sp, [r7, lr, asr #7]
 *   @0x2eb3b4 and r9, r2, sp, lsl #16
 *   @0x2eb3b8 and r2, r0, r8
 *   @0x2eb3bc andls r4, r12, r8, lsl r6
 *   @0x2eb3c0 .word 0xf0402800
 *   @0x2eb3c4 bge 0x68bf6c <g_SWFlinevertbuff+0x38ea4>
 *   @0x2eb3c8 stm sp, {r3, r6, r9, r10, lr}
 *   @0x2eb3cc movwhs r0, #0x8404
 *   @0x2eb3d0 .word 0x10c0f8d4
 *   @0x2eb3d4 ldrsbths pc, [r12], r4
 *   @0x2eb3d8 .word 0x8064f8d4
 *   @0x2eb3dc stc2 p7, c15, [r8], {255}
 *   @0x2eb3e0 stmdahs r0, {r0, r2, r3, r12, pc}
 *   @0x2eb3e4 strbmi sp, [r8], -lr, ror #2
 *   @0x2eb3e8 .word 0xf7fc2108
 *   @0x2eb3ec andls pc, sp, r10, lsl sp
 *   @0x2eb3f0 .word 0xd1672800
 *   @0x2eb3f4 .word 0xf7fb4648
 *   @0x2eb3f8 .word 0xf010fb48
 *   @0x2eb3fc andls r0, lr, r4, lsl #30
 *   @0x2eb400 andle r4, r2, r8, asr #12
 *   @0x2eb404 blx 0xd693fa <b2_toiTime+0x60ff56>
 *   @0x2eb408 .word 0xf7fbe001
 *   @0x2eb40c .word 0x4607fb3e
 *   @0x2eb410 .word 0xf7fc4648
 *   @0x2eb414 bls 0x6aa960 <g_SWFlinevertbuff+0x57898>
 *   @0x2eb418 rscseq pc, pc, #50
 *   @0x2eb41c .word 0xf8d4d154
 *   @0x2eb420 .word 0xf5b73120
 *   @0x2eb424 svclt #0x283f80
 *   @0x2eb428 strlo pc, [r0, pc, asr #8]
 *   @0x2eb42c swpble r4, pc, [r11]
 *   @0x2eb430 andls r10, r0, #13312
 *   @0x2eb434 strbmi r9, [r0], -r1, lsl #6
 *   @0x2eb438 ldrtmi r2, [r11], -r4, lsl #2
 *   @0x2eb43c mcr2 p7, #0x1, pc, c7, c12, #0x7
 *   @0x2eb440 strmi r9, [r6], -sp, lsl #26
 *   @0x2eb444 mrsle r2, spsr
 *   @0x2eb448 strhle r4, [sp], -sp
 *   @0x2eb44c strbmi r9, [r8], -lr, lsl #22
 *   @0x2eb450 ldrbeq r10, [r11, -sp, lsl #18]
 *   @0x2eb454 .word 0xf7fbd502
 *   @0x2eb458 strh pc, [r1], -r5
 *   @0x2eb45c stc2l p7, c15, [r4, #-1004]
 *   @0x2eb460 eoreq pc, r5, r6, asr #16
 *   @0x2eb464 strb r3, [pc, r1, lsl #10]!
 *   @0x2eb468 bllt 0xdd20a4 <b2_toiTime+0x678c00>
 *   @0x2eb46c blls 0x674884 <g_SWFlinevertbuff+0x217bc>
 *   @0x2eb470 stmdbge sp, {r3, r6, r9, r10, lr}
 *   @0x2eb474 strle r0, [r2, #-0x75a]
 *   @0x2eb478 stc2 p7, c15, [r4], #1004
 *   @0x2eb47c .word 0xf7fbe001
 *   @0x2eb480 blls 0x66a954 <g_SWFlinevertbuff+0x1788c>
 *   @0x2eb484 stclo p9, c11, [r1, #-780]
 *   @0x2eb488 ldmdals r2, {r0, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2eb48c adcsmi r4, r11, #45088768
 *   @0x2eb490 .word 0xf856d00f
 *   @0x2eb494 bhs 0x2f3528 <ps_hints_apply+0x2128>
 *   @0x2eb498 addmi sp, r2, #9216
 *   @0x2eb49c .word 0xf8d4d807
 *   @0x2eb4a0 bl 0x32f938
 *   @0x2eb4a4 .word 0xf8d91503
 *   @0x2eb4a8 strmi r1, [r10], #-8
 *   @0x2eb4ac movwlo r6, #0x10ea
 *   @0x2eb4b0 blls 0x6a546c <g_SWFlinevertbuff+0x523a4>
 *   @0x2eb4b4 teqlo r4, r4, asr #17
 *   @0x2eb4b8 ldrtmi r4, [r1], -r0, asr #12
 *   @0x2eb4bc .word 0xff3bf7fb
 *   @0x2eb4c0 and r9, r2, sp, lsl #26
 *   @0x2eb4c4 and r4, r0, r5, lsl #12
 *   @0x2eb4c8 strls r2, [r12, #-0x503]
 *   @0x2eb4cc .word 0xf0402d00
 *   @0x2eb4d0 cdpvs p2, #0x6, c8, c0, c2, #0x3
 *   @0x2eb4d4 .word 0xf8d4a90e
 *   @0x2eb4d8 .word 0x232020bc
 *   @0x2eb4dc streq lr, [r2], #-2189
 *   @0x2eb4e0 strbmi r9, [r8], -r10
 *   @0x2eb4e4 .word 0x10c0f8d4
 *   @0x2eb4e8 .word 0xfc02f7ff
 *   @0x2eb4ec stmdahs r0, {r0, r2, r3, r12, pc}
 *   @0x2eb4f0 adcshi pc, r7, r0, asr #32
 *   @0x2eb4f4 .word 0x210e4648
 *   @0x2eb4f8 ldc2 p7, c15, [r3], {252}
 *   @0x2eb4fc stmdahs r0, {r0, r2, r3, r12, pc}
 *   @0x2eb500 adchi pc, pc, r0, asr #32
 *   @0x2eb504 .word 0xf7fb4648
 *   @0x2eb508 .word 0xf010fac0
 *   @0x2eb50c andls r0, lr, r4, lsl #30
 *   @0x2eb510 andsle r4, r5, r8, asr #12
 *   @0x2eb514 blx 0x1e69508 <b2_toiTime+0x1710064>
 *   @0x2eb518 andls r11, r5, r0, lsl #4
 *   @0x2eb51c .word 0xf7fb4648
 *   @0x2eb520 andlt pc, r0, #104, #20
 *   @0x2eb524 strbmi r9, [r8], -r6
 *   @0x2eb528 blx 0x1be951c <b2_toiTime+0x1490078>
 *   @0x2eb52c strbmi r11, [r8], -r6, lsl #4
 *   @0x2eb530 blx 0x1ae9524 <b2_toiTime+0x1390080>
 *   @0x2eb534 andls r11, r8, r0, lsl #4
 *   @0x2eb538 .word 0xf7fb4648
 *   @0x2eb53c ands pc, r4, r10, asr r10
 *   @0x2eb540 blx 0x1ce9534 <b2_toiTime+0x1590090>
 *   @0x2eb544 andls r11, r5, r0, lsl #4
 *   @0x2eb548 .word 0xf7fb4648
 *   @0x2eb54c andlt pc, r0, #401408
 *   @0x2eb550 strbmi r9, [r8], -r6
 *   @0x2eb554 blx 0x1a69548 <b2_toiTime+0x13100a4>
 *   @0x2eb558 strbmi r11, [r8], -r6, lsl #4
 *   @0x2eb55c blx 0x1969550 <b2_toiTime+0x12100ac>
 *   @0x2eb560 andls r11, r8, r0, lsl #4
 *   @0x2eb564 .word 0xf7fb4648
 *   @0x2eb568 .word 0xf8a4fa54
 *   @0x2eb56c .word 0x46480130
 *   @0x2eb570 stc2 p7, c15, [r2], #1008
 *   @0x2eb574 .word 0xf0329a0e
 *   @0x2eb578 ldrshle r0, [r4, #-47]!
 *   @0x2eb57c blhs 0x312198 <af_shaper_get_elem+0x7a06>
 *   @0x2eb580 stmdals r6, {r0, r1, r4, r5, r6, r8, r9, r11, r12, lr, pc}
 *   @0x2eb584 ldclle p2, c4, [r0], #-524
 *   @0x2eb588 stclle p8, c2, [lr], #-1020
 *   @0x2eb58c blle 0x1df6d94 <b2_toiTime+0x169d8f0>
 *   @0x2eb590 addmi r9, lr, #8, #18
 *   @0x2eb594 ldmibhs pc!, {r0, r3, r5, r6, r10, r11, r12, lr, pc} ^
 *   @0x2eb598 blne 0xfe5e273c <b2_toiTime+0xfffffffffde89298>
 *   @0x2eb59c movwlo r9, #0x1905
 *   @0x2eb5a0 bl 0xff34fda8 <b2_toiTime+0xfffffffffebf6904>
 *   @0x2eb5a4 stmdals r10, {r8, r9, r11}
 *   @0x2eb5a8 bleq 0x3679dc <_ZTS12CDS_Priority+0x9a34>
 *   @0x2eb5ac blx 0x5b39d6 <g_SWFlineaavertbuff+0x6090e>
 *   @0x2eb5b0 blge 0x66a1c4 <g_SWFlinevertbuff+0x170fc>
 *   @0x2eb5b4 ldrbmi r9, [r11], -r1, lsl #6
 *   @0x2eb5b8 stc2l p7, c15, [r9, #-1008]!
 *   @0x2eb5bc strmi r9, [r7], -sp, lsl #22
 *   @0x2eb5c0 cmple r4, r0, lsl #22
 *   @0x2eb5c4 b 0x16bceec <b2_toiTime+0xf63a48>
 *   @0x2eb5c8 .word 0xf7fc014b
 *   @0x2eb5cc andls pc, sp, r10, lsr #24
 *   @0x2eb5d0 mrsle r2, spsr
 *   @0x2eb5d4 .word 0x2c06ea4f
 *   @0x2eb5d8 blls 0x43cfe0 <g_RomDisk+0x457c0>
 *   @0x2eb5dc strbmi r9, [r8], -lr, lsl #18
 *   @0x2eb5e0 strbeq r9, [r11, -r2, lsl #6]
 *   @0x2eb5e4 andgt pc, r12, sp, asr #17
 *   @0x2eb5e8 .word 0xf7fbd505
 *   @0x2eb5ec blls 0x3a9dfc <error_g0017+0x2aa0>
 *   @0x2eb5f0 .word 0xc00cf8dd
 *   @0x2eb5f4 .word 0xf7fbe004
 *   @0x2eb5f8 .word 0xf8ddfa0c
 *   @0x2eb5fc blls 0x39b634 <ft_adobe_glyph_list+0xad10>
 *   @0x2eb600 mvnsvc pc, pc, asr #12
 *   @0x2eb604 andle r4, r8, r8, lsl #5
 *   @0x2eb608 biceq lr, r8, r7, lsl #22
 *   @0x2eb60c andeq lr, r12, #3072
 *   @0x2eb610 eorshs pc, r8, r7, asr #16
 *   @0x2eb614 stmdaeq r1, {r3, r8, r12, sp, lr, pc}
 *   @0x2eb618 bls 0x48b840 <prim_v+0x1e8c>
 *   @0x2eb61c addsmi r3, r3, #67108864
 *   @0x2eb620 blls 0x522d98 <SrcVerts+0x7fddc>
 *   @0x2eb624 .word 0xf50c3601
 *   @0x2eb628 addsmi r7, lr, #128, #24
 *   @0x2eb62c .word 0x4648ddd5
 *   @0x2eb630 mcrr2 p7, #0xf, pc, r2, c12
 *   @0x2eb634 stmdage sp, {r8, r9, r10, r12, pc}
 *   @0x2eb638 andls r4, r1, r3, asr #12
 *   @0x2eb63c stmdals r10, {r3, r8, sp}
 *   @0x2eb640 .word 0xf7fc465a
 *   @0x2eb644 blls 0x66aadc <g_SWFlinevertbuff+0x17a14>
 *   @0x2eb648 stmdblt r3!, {r0, r1, r2, r9, r10, lr}
 *   @0x2eb64c smlawthi r8, r4, r8, pc
 *   @0x2eb650 smlawteq r12, r4, r8, pc
 *   @0x2eb654 stmdals r10, {r2, r3, sp, lr, pc}
 *   @0x2eb658 .word 0xf7fb4639
 *   @0x2eb65c stcls p14, c15, [sp, #-432]
 *   @0x2eb660 strmi lr, [r5], -r6
 *   @0x2eb664 strhs lr, [r3, #-0x4]
 *   @0x2eb668 strhs lr, [r8, #-0x2]
 *   @0x2eb66c ldrmi lr, [sp], -r0
 *   @0x2eb670 stchs p5, c9, [r0, #-48]
 *   @0x2eb674 orrhi pc, pc, r0, asr #32
 *   @0x2eb678 ldmdblt r1, {r0, r1, r3, r8, r11, r12, pc} ^
 *   @0x2eb67c .word 0xf04368a3
 *   @0x2eb680 umlalvs r0, r2, r2, r2
 *   @0x2eb684 smullhs pc, r7, r4, r8
 *   @0x2eb688 .word 0xf043b172
 *   @0x2eb68c umlalvs r0, r3, r6, r3
 *   @0x2eb690 strbmi lr, [r8], -r10
 *   @0x2eb694 .word 0xf44f4621
 *   @0x2eb698 .word 0xf7ff7280
 *   @0x2eb69c andls pc, r12, r9, lsl #23
 *   @0x2eb6a0 .word 0xf0402800
 *   @0x2eb6a4 .word 0xe7e98178
 *   @0x2eb6a8 stmdage lr, {r8, r10, sp}
 *   @0x2eb6ac andshs r4, r0, #42991616
 *   @0x2eb6b0 cdpvs p5, #0x6, c9, c7, c13, #0x0
 *   @0x2eb6b4 svc #0x7cf5ca
 *   @0x2eb6b8 strtmi r4, [r0], -r1, asr #19
 *   @0x2eb6bc ldrbtmi r6, [r9], #-229
 *   @0x2eb6c0 blx 0xffaa96c4 <b2_toiTime+0xffffffffff350220>
 *   @0x2eb6c4 stmdbvc r3, {r3, r4, r5, r7, r8, r12, sp, pc}
 *   @0x2eb6c8 stmvs r3, {r0, r1, r3, r5, r7, r8, r12, sp, pc}
 *   @0x2eb6cc .word 0xf003781b
 *   @0x2eb6d0 blhs 0x16ac654 <b2_toiTime+0xf531b0>
 *   @0x2eb6d4 blhs 0x155f6e0 <b2_toiTime+0xe0623c>
 *   @0x2eb6d8 movwhs sp, #0x110d
 *   @0x2eb6dc stmvs r3, {r0, r1, r5, r6, r7, sp, lr}
 *   @0x2eb6e0 .word 0xf003781b
 *   @0x2eb6e4 blhs 0x16ac668 <b2_toiTime+0xf531c4>
 *   @0x2eb6e8 blmi 0xff09faf8 <b2_toiTime+0xfffffffffe946654>
 *   @0x2eb6ec and r4, r1, r11, ror r4
 *   @0x2eb6f0 ldrbtmi r4, [r11], #-2997
 *   @0x2eb6f4 ldmibmi r5!, {r4, r8, r9, r12, pc}
 *   @0x2eb6f8 ldrbtmi r4, [r9], #-1568
 *   @0x2eb6fc blx 0xff329700 <b2_toiTime+0xfffffffffebd025c>
 *   @0x2eb700 stmdbvc r3, {r4, r5, r6, r8, r12, sp, pc}
 *   @0x2eb704 stmvs r3, {r0, r1, r5, r6, r8, r12, sp, pc}
 *   @0x2eb708 .word 0xf003781b
 *   @0x2eb70c blhs 0x136c690 <b2_toiTime+0xc131ec>
 *   @0x2eb710 stmvs r3!, {r1, r2, r8, r12, lr, pc} ^
 *   @0x2eb714 movweq pc, #0x2043
 *   @0x2eb718 blmi 0xfee43aac <b2_toiTime+0xfffffffffe6ea608>
 *   @0x2eb71c movwls r4, #0xf47b
 *   @0x2eb720 strtmi r4, [r0], -r12, lsr #19
 *   @0x2eb724 .word 0xf7ff4479
 *   @0x2eb728 smlaltblt pc, r8, r11, r10
 *   @0x2eb72c teqlt r11, r3, lsl #18
 *   @0x2eb730 ldmdavc r10, {r0, r1, r7, r11, sp, lr}
 *   @0x2eb734 .word 0xf002b122
 *   @0x2eb738 bhs 0x166c2bc <b2_toiTime+0xf12e18>
 *   @0x2eb73c tstls r1, #24, #30
 *   @0x2eb740 strtmi r4, [r0], -r5, lsr #19
 *   @0x2eb744 .word 0xf7ff4479
 *   @0x2eb748 swpblt pc, r11, [r8]
 *   @0x2eb74c teqlt r11, r3, lsl #18
 *   @0x2eb750 ldmdavc r10, {r0, r1, r7, r11, sp, lr}
 *   @0x2eb754 .word 0xf002b122
 *   @0x2eb758 bhs 0x166c2dc <b2_toiTime+0xf12e38>
 *   @0x2eb75c movwls r11, #0xef18
 *   @0x2eb760 strtmi r2, [lr], -r0, lsl #10
 *   @0x2eb764 bge 0x67d20c <g_SWFlinevertbuff+0x2a144>
 *   @0x2eb768 andhi pc, r5, r10, asr #16
 *   @0x2eb76c qsublt r5, r0, r8
 *   @0x2eb770 cdp p5, #0xe, c15, c2, c10, #0x6
 *   @0x2eb774 strmi r3, [r6], #-1537
 *   @0x2eb778 andeq pc, r5, r10, asr #16
 *   @0x2eb77c ldchs p5, c3, [r0, #-16]
 *   @0x2eb780 stmdblt lr!, {r0, r4, r5, r6, r7, r8, r12, lr, pc}
 *   @0x2eb784 .word 0x26084b95
 *   @0x2eb788 movwls r4, #0xe47b
 *   @0x2eb78c tstls r2, #469762048
 *   @0x2eb790 shasxmi r4, r1, r8
 *   @0x2eb794 .word 0xf7fbaa0d
 *   @0x2eb798 stcls p12, c15, [sp, #-792]
 *   @0x2eb79c lslvs r4, r3, #12
 *   @0x2eb7a0 strhs r11, [sp, -r5, asr #22]!
 *   @0x2eb7a4 stmdaeq r0!, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2eb7a8 .word 0xf85aa80e
 *   @0x2eb7ac .word 0xf8506025
 *   @0x2eb7b0 biclt r1, r9, r5, lsr #32
 *   @0x2eb7b4 addsmi r6, r3, #2654208
 *   @0x2eb7b8 .word 0xf883bf1c
 *   @0x2eb7bc movwlo r8, #0x1000
 *   @0x2eb7c0 sasxmi r4, r8, r2
 *   @0x2eb7c4 cdp p5, #0xf, c15, c10, c10, #0x6
 *   @0x2eb7c8 strmi r4, [r6], #-1539
 *   @0x2eb7cc stchs p1, c11, [r3, #-116]
 *   @0x2eb7d0 ldrtmi sp, [r3], -r1
 *   @0x2eb7d4 adcsmi lr, r3, #8
 *   @0x2eb7d8 .word 0xf813d0fb
 *   @0x2eb7dc bhs 0xaf63e8 <b2_toiTime+0x39cf44>
 *   @0x2eb7e0 .word 0xf803bf08
 *   @0x2eb7e4 ldrb r7, [r6, r1, lsl #24]!
 *   @0x2eb7e8 stchs p5, c3, [r4, #-4]
 *   @0x2eb7ec andhs sp, r0, #220, #2
 *   @0x2eb7f0 stcls p0, c7, [sp, #-104]
 *   @0x2eb7f4 stchs p5, c9, [r0, #-48]
 *   @0x2eb7f8 sbchi pc, sp, r0, asr #32
 *   @0x2eb7fc qsub16mi r4, r0, r8
 *   @0x2eb800 ldrbtmi r10, [r9], #-3852
 *   @0x2eb804 blx 0x1229808 <b2_toiTime+0xad0364>
 *   @0x2eb808 .word 0xb1604603
 *   @0x2eb80c cmplt r2, r2, lsl #18
 *   @0x2eb810 shadd8mi r6, r10, r9
 *   @0x2eb814 .word 0xf7fd9809
 *   @0x2eb818 blls 0x629970 <g_SWFaavertbuff+0x568a8>
 *   @0x2eb81c blhs 0x303da4 <TT_New_Context+0x3b9c>
 *   @0x2eb820 adcshi pc, r9, r0, asr #32
 *   @0x2eb824 movwhs lr, #0x1
 *   @0x2eb828 .word 0xf8d46163
 *   @0x2eb82c andhs r3, r0, #32, #2
 *   @0x2eb830 stm sp, {r4, r8, sp}
 *   @0x2eb834 movwlo r0, #0x1084
 *   @0x2eb838 .word 0x61239809
 *   @0x2eb83c mvnvs r2, r1, lsl #6
 *   @0x2eb840 stc2 p7, c15, [r5], #-1008
 *   @0x2eb844 strmi r9, [r5], -r12, lsl #18
 *   @0x2eb848 stmdbhs r0, {r5, r9, sp, lr}
 *   @0x2eb84c adchi pc, r3, r0, asr #32
 *   @0x2eb850 .word 0xf5ca2210
 *   @0x2eb854 .word 0xf8d4eeae
 *   @0x2eb858 .word 0xf8d460d0
 *   @0x2eb85c strtmi r3, [r0], -r12, asr #1
 *   @0x2eb860 ldrmi r4, [lr], #-2400
 *   @0x2eb864 eorslt r4, r6, #2030043136
 *   @0x2eb868 svclt #0xb82e00
 *   @0x2eb86c adcslt r4, r6, #1610612743
 *   @0x2eb870 .word 0xf7ff802e
 *   @0x2eb874 cmnlt r0, r5, lsl #20
 *   @0x2eb878 smlabbhs r10, r0, r8, r6
 *   @0x2eb87c andlt r3, r0, #5
 *   @0x2eb880 svceq #0x9f110
 *   @0x2eb884 .word 0xf02dda03
 *   @0x2eb888 submi lr, r0, #68, #20
 *   @0x2eb88c .word 0xf02de001
 *   @0x2eb890 addlt lr, r0, #64, #20
 *   @0x2eb894 eorslt lr, r0, #4
 *   @0x2eb898 andhs r2, r3, #-2147483648
 *   @0x2eb89c blx 0x16a9888 <b2_toiTime+0xf503e4>
 *   @0x2eb8a0 rsbhi r4, r8, r1, asr r9
 *   @0x2eb8a4 ldrbtmi r4, [r9], #-1568
 *   @0x2eb8a8 .word 0xf9eaf7ff
 *   @0x2eb8ac stmvs r0, {r3, r6, r8, r12, sp, pc}
 *   @0x2eb8b0 mvnhs pc, pc, asr #8
 *   @0x2eb8b4 stmdahs r0, {r0, r6, r9, r11, lr}
 *   @0x2eb8b8 submi r11, r0, #184, #30
 *   @0x2eb8bc blx 0x12a98a8 <b2_toiTime+0xb50404>
 *   @0x2eb8c0 stmdbmi r10, {r3, r5, r6, sp, lr} ^
 *   @0x2eb8c4 ldrbtmi r4, [r9], #-1568
 *   @0x2eb8c8 .word 0xf9daf7ff
 *   @0x2eb8cc rfeib r0!
 *   @0x2eb8d0 blhs 0x2f78f8 <ps_hints_apply+0x64f8>
 *   @0x2eb8d4 subsmi r11, r11, #184, #30
 *   @0x2eb8d8 smlalvs r0, r11, r11, r1
 *   @0x2eb8dc strtmi r4, [r0], -r4, asr #18
 *   @0x2eb8e0 .word 0xf7ff4479
 *   @0x2eb8e4 smlalbtlt pc, r8, sp, r9
 *   @0x2eb8e8 strhhi pc, [r8], -r0
 *   @0x2eb8ec svceq #0xf1b8
 *   @0x2eb8f0 .word 0xf1c8bfb8
 *   @0x2eb8f4 blx 0xaad8fc <b2_toiTime+0x354458>
 *   @0x2eb8f8 and pc, r0, r8, lsl #17
 *   @0x2eb8fc ldmdbmi sp!, {r7, r9, r10, lr}
 *   @0x2eb900 ldrbtmi r4, [r9], #-1568
 *   @0x2eb904 rfeib r12!
 *   @0x2eb908 rfeib r0!
 *   @0x2eb90c cdphs p0, #0x0, c6, c0, c8, #0x0
 *   @0x2eb910 rsbsmi r11, r6, #184, #30
 *   @0x2eb914 strh r11, [r0], -r6
 *   @0x2eb918 stmvs r11!, {r1, r2, r9, r10, lr} ^
 *   @0x2eb91c stmdavs r8!, {r0, r1, r4, r7, r8, r11, r12, sp, pc} ^
 *   @0x2eb920 .word 0xb1a660e8
 *   @0x2eb924 subhs r11, r8, #268435459
 *   @0x2eb928 blx 0x529914 <SrcVerts+0x86958>
 *   @0x2eb92c .word 0xf1b860e8
 *   @0x2eb930 andle r0, r12, r0, lsl #30
 *   @0x2eb934 blx 0x6c5cdc <g_SWFlinevertbuff+0x72c14>
 *   @0x2eb938 eorslt pc, r2, #136, #2
 *   @0x2eb93c .word 0xf9fef7f9
 *   @0x2eb940 and r6, r6, r8, lsr #1
 *   @0x2eb944 svceq #0xf1b8
 *   @0x2eb948 cdphs p0, #0x0, c13, c0, c1, #0x0
 *   @0x2eb94c stmvs r11!, {r1, r4, r5, r6, r7, r8, r12, lr, pc} ^
 *   @0x2eb950 stmdbmi r9!, {r0, r1, r3, r5, r7, sp, lr}
 *   @0x2eb954 ldrbtmi r4, [r9], #-1568
 *   @0x2eb958 .word 0xf992f7ff
 *   @0x2eb95c ldrbtmi r4, [r9], #-2343
 *   @0x2eb960 strtmi r4, [r0], -r5, lsl #12
 *   @0x2eb964 .word 0xf98cf7ff
 *   @0x2eb968 .word 0xb1a54603
 *   @0x2eb96c orrslt r7, r2, r10, lsr #18
 *   @0x2eb970 stmdbvc r2, {r3, r7, r8, r12, sp, pc}
 *   @0x2eb974 ldmvs r9, {r1, r3, r4, r5, r6, r8, r12, sp, pc}
 *   @0x2eb978 stmdals r9, {r1, r3, r4, r5, r9, r10, lr}
 *   @0x2eb97c .word 0xffa1f7fc
 *   @0x2eb980 .word 0xf8c49b0c
 *   @0x2eb984 ldmdblt r3!, {r4, r5, r7}
 *   @0x2eb988 ldrtmi r9, [r10], -r9, lsl #16
 *   @0x2eb98c .word 0xf7fc68a9
 *   @0x2eb990 .word 0xf8c4ff98
 *   @0x2eb994 blls 0x5ebc6c <g_SWFaavertbuff+0x18ba4>
 *   @0x2eb998 movwhs r11, #0x310b
 *   @0x2eb99c stmdals r12, {r2, r3, r8, r9, r12, pc}
 *   @0x2eb9a0 strbmi lr, [r8], -r9
 *   @0x2eb9a4 andhs r4, r2, #34603008
 *   @0x2eb9a8 blx 0x3a99ac <error_g0017+0x2650>
 *   @0x2eb9ac stmdahs r0, {r2, r3, r12, pc}
 *   @0x2eb9b0 strdls sp, lr, [r11], -r1
 *   @0x2eb9b4 andslt lr, r7, r10, ror #8
 *   @0x2eb9b8 svchi #0xf0e8bd
 *   @0x2eb9bc andeq r1, r1, lr, asr #20
 *   @0x2eb9c0 andeq r3, r10, r10, lsl r1
 *   @0x2eb9c4 ldrdeq r3, r4, [r10], -sp
 *   @0x2eb9c8 ldrdeq r3, r4, [r10], -pc
 *   @0x2eb9cc andeq r3, r10, r4, ror #1
 *   @0x2eb9d0 andeq r3, r10, lr, asr #1
 *   @0x2eb9d4 andeq r3, r10, r11, asr #1
 *   @0x2eb9d8 strheq r3, [r10], -r9
 *   @0x2eb9dc andeq r3, r10, r4, lsl #1
 *   @0x2eb9e0 andeq r3, r10, r2, lsl r0
 *   @0x2eb9e4 strheq r2, [r10], -r12
 *   @0x2eb9e8 andeq r2, r10, r8, lsl #31
 *   @0x2eb9ec andeq r2, r10, r3, ror pc
 *   @0x2eb9f0 andeq r2, r10, r4, ror #30
 *   @0x2eb9f4 andeq r2, r10, pc, asr #30
 *   @0x2eb9f8 andeq r2, r10, r8, lsl #30
 *   @0x2eb9fc andeq r2, r10, r1, lsl pc
 *   @0x2eba00 strdlt r11, r12, [r5], r0
 *   @0x2eba04 strmi r4, [r12], -r7, lsl #12
 *   @0x2eba08 .word 0xf7ff4616
 *   @0x2eba0c ldmdblt r0, {r0, r6, r9, r11, r12, sp, lr, pc}
 *   @0x2eba10 ble 0xb77218 <b2_toiTime+0x41dd74>
 *   @0x2eba14 .word 0xf104e07a
 *   @0x2eba18 strtmi r0, [r0], -r4, lsl #11
 *   @0x2eba1c rfeia lr!
 *   @0x2eba20 qasxmi r4, r8, r9
 *   @0x2eba24 .word 0xf84cf02b
 *   @0x2eba28 blhs 0x4d853c <SrcVerts+0x35580>
 *   @0x2eba2c ldmdblt r0, {r0, r3, r5, r6, r12, lr, pc} ^
 *   @0x2eba30 adcvc pc, r12, r4, asr #17
 *   @0x2eba34 strtvs r4, [r5], r8, lsr #12
 *   @0x2eba38 ldrtmi r4, [r2], -r1, lsr #12
 *   @0x2eba3c blx 0xd29a40 <b2_toiTime+0x5d059c>
 *   @0x2eba40 cmple lr, r0, lsl #16
 *   @0x2eba44 strtmi lr, [r8], -r4, ror #15
 *   @0x2eba48 .word 0xf02b4639
 *   @0x2eba4c sbclt pc, r3, #135168
 *   @0x2eba50 subsle r2, r6, r7, lsl #22
 *   @0x2eba54 cmple r4, r0, lsl #16
 *   @0x2eba58 andle lr, r6, r10, ror #15
 *   @0x2eba5c strhlt r11, [r6, -r6]!
 *   @0x2eba60 .word 0xf7ff4620
 *   @0x2eba64 mulhs r6, r11, r8
 *   @0x2eba68 .word 0xf8d4e051
 *   @0x2eba6c .word 0xf8d430b4
 *   @0x2eba70 teqlt r3, #176
 *   @0x2eba74 ldmdavc r10, {r0, r2, r3, r4, r5, r8, r9, r12, sp, pc}
 *   @0x2eba78 sbcseq pc, pc, #2
 *   @0x2eba7c .word 0xd1262a49
 *   @0x2eba80 .word 0xf002785a
 *   @0x2eba84 bhs 0x17ac608 <b2_toiTime+0x1053164>
 *   @0x2eba88 ldmvc r10, {r0, r5, r8, r12, lr, pc}
 *   @0x2eba8c sbcseq pc, pc, #2
 *   @0x2eba90 tstle r12, pc, asr #20
 *   @0x2eba94 stmdbmi r0!, {r1, r2, r3, r4, r6, r7, r10, r11, r12}
 *   @0x2eba98 ldrbtmi r4, [r9], #-1584
 *   @0x2eba9c stcl p5, c15, [r10, #-808]!
 *   @0x2ebaa0 ldmdbmi lr, {r3, r4, r7, r8, r12, sp, pc}
 *   @0x2ebaa4 ldrbtmi r4, [r9], #-1584
 *   @0x2ebaa8 stcl p5, c15, [r4, #-808]!
 *   @0x2ebaac ldmdbmi r12, {r3, r4, r5, r6, r8, r11, r12, sp, pc}
 *   @0x2ebab0 ldrbtmi r4, [r9], #-1576
 *   @0x2ebab4 ldcl p5, c15, [lr, #-808]
 *   @0x2ebab8 .word 0x0001f1d0
 *   @0x2ebabc andhs r11, r0, r8, lsr pc
 *   @0x2ebac0 ldrmi lr, [r8], -r6
 *   @0x2ebac4 strtmi lr, [r8], -r4
 *   @0x2ebac8 andhs lr, r1, r2
 *   @0x2ebacc andhs lr, r0, r0
 *   @0x2ebad0 strls r2, [r1], #-768
 *   @0x2ebad4 .word 0xf8ad9302
 *   @0x2ebad8 .word 0xf8ad300c
 *   @0x2ebadc teqlt r8, lr
 *   @0x2ebae0 movwls r4, #0x2b0c
 *   @0x2ebae4 .word 0xf8ad2303
 *   @0x2ebae8 movwhs r3, #0x100c
 *   @0x2ebaec andlo pc, lr, sp, lsr #17
 *   @0x2ebaf0 .word 0x2100480c
 *   @0x2ebaf4 strmi r10, [r11], -r1, lsl #20
 *   @0x2ebaf8 eorlo r4, r0, r8, ror r4
 *   @0x2ebafc ldc2 p7, c15, [r11], #-1008
 *   @0x2ebb00 strtmi lr, [r0], -r5
 *   @0x2ebb04 .word 0xf84af7ff
 *   @0x2ebb08 and r2, r0, r2
 *   @0x2ebb0c andlt r2, r5, r0
 *   @0x2ebb10 svclt #0xbdf0
 *   @0x2ebb14 strbvc r6, [lr, #-0x963]!
 *   @0x2ebb18 andeq r2, r10, r6, ror #27
 *   @0x2ebb1c andeq r2, r10, r0, ror #27
 *   @0x2ebb20 ldrdeq r2, r3, [r10], -r9
 *   @0x2ebb24 andeq r12, pc, r4, ror #29
 *   @0x2ebb28 stmdavs r3, {r4, r8, r10, r12, sp, pc}
 *   @0x2ebb2c ldrsbne pc, [r8, r3]
 *   @0x2ebb30 .word 0xf8d36101
 *   @0x2ebb34 movwhs r2, #0x11a0
 *   @0x2ebb38 addmi r6, r11, #-2147483632
 *   @0x2ebb3c ldmdavs r4, {r1, r2, r9, r12, lr, pc}
 *   @0x2ebb40 svceq #0x10f852
 *   @0x2ebb44 andle r4, r3, #132, #4
 *   @0x2ebb48 ldrb r3, [r6, r1, lsl #6]!
 *   @0x2ebb4c ldclt p0, c2, [r0, #-0]
 *   @0x2ebb50 ldclt p0, c2, [r0, #-32]
 *   @0x2ebb54 .word 0x61432300
 *   @0x2ebb58 ldrbmi r6, [r0, -r3, lsl #2]!
 *   @0x2ebb5c movwhs r11, #0x570
 *   @0x2ebb60 adcmi r6, r3, #4, #18
 *   @0x2ebb64 bne 0xffba03a0 <b2_toiTime+0xffffffffff446efc>
 *   @0x2ebb68 bl 0x3c6084 <error_g0017+0x1ed28>
 *   @0x2ebb6c tsteq r6, r2, asr r2
 *   @0x2ebb70 addmi r5, sp, #2834432
 *   @0x2ebb74 mrrcne p1, #0x0, sp, r0, c1
 *   @0x2ebb78 svclt #0x2cbd70
 *   @0x2ebb7c mrrcne p6, #0x1, r4, r3, c4
 *   @0x2ebb80 andhs lr, r0, pc, ror #15
 *   @0x2ebb84 stmdavs r10, {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2ebb88 andlo r11, r1, #240, #10
 *   @0x2ebb8c ldrtmi r6, [r5], -r6, lsl #18
 *   @0x2ebb90 adcmi r2, r11, #0, #6
 *   @0x2ebb94 bne 0xffe203e4 <b2_toiTime+0xffffffffff6c6f40>
 *   @0x2ebb98 bl 0x3c60bc <error_g0017+0x1ed60>
 *   @0x2ebb9c b 0x16accf4 <b2_toiTime+0xf53850>
 *   @0x2ebba0 .word 0xf8571c04
 *   @0x2ebba4 addsmi r7, r7, #12
 *   @0x2ebba8 .word 0xb10cd104
 *   @0x2ebbac ands r1, r1, r3, ror #24
 *   @0x2ebbb0 strb r3, [r12, r1, lsl #4]!
 *   @0x2ebbb4 strtmi r11, [r5], -r12, lsr #30
 *   @0x2ebbb8 strb r1, [r10, r3, ror #24]!
 *   @0x2ebbbc andle r4, r5, #805306379
 *   @0x2ebbc0 teqlt r3, r0, asr #18
 *   @0x2ebbc4 movwlo r0, #0x111a
 *   @0x2ebbc8 and r5, r3, r2, lsl #17
 *   @0x2ebbcc ldrmi r2, [r3], -r0, lsl #4
 *   @0x2ebbd0 ldrmi lr, [r10], -r0
 *   @0x2ebbd4 ldrmi r6, [r8], -r10
 *   @0x2ebbd8 .word 0xf890bdf0
 *   @0x2ebbdc push {r5, sp}
 *   @0x2ebbe0 stmibvs r3, {r4, r5, r6, r7, r8, r9, r10, lr} ^
 *   @0x2ebbe4 svchi #0x1eb39a
 *   @0x2ebbe8 ldrhtgt pc, [r10], -r3
 *   @0x2ebbec stchs p2, c11, [r0, #-212]
 *   @0x2ebbf0 .word 0xf78cfa0f
 *   @0x2ebbf4 rscslo pc, pc, #-1073741823
 *   @0x2ebbf8 .word 0xf105dd06
 *   @0x2ebbfc mrrcvs p1, #0x0, r4, r12, c0
 *   @0x2ebc00 rfedb r4!
 *   @0x2ebc04 and r1, r0, r1, lsl r0
 *   @0x2ebc08 addmi r2, r10, #0, #2
 *   @0x2ebc0c blvs 0xffa23068 <b2_toiTime+0xffffffffff2c9bc4>
 *   @0x2ebc10 stmeq r1, {r2, r8, r9, r11, sp, lr, pc} ^
 *   @0x2ebc14 stmibeq r2, {r2, r8, r9, r11, sp, lr, pc} ^
 *   @0x2ebc18 eorsge pc, r1, r4, asr r8
 *   @0x2ebc1c eorsmi pc, r2, r4, asr r8
 *   @0x2ebc20 smlatble r12, r2, r5, r4
 *   @0x2ebc24 .word 0x8004f8d8
 *   @0x2ebc28 .word 0x4004f8d9
 *   @0x2ebc2c smlatble r6, r0, r5, r4
 *   @0x2ebc30 .word 0xf10c1eba
 *   @0x2ebc34 .word 0xf8a33cff
 *   @0x2ebc38 addmi r12, r10, #58
 *   @0x2ebc3c .word 0x6c59db04
 *   @0x2ebc40 ldrhi r3, [lr, -r1, lsl #12]
 *   @0x2ebc44 andshs pc, r5, r1, lsr #16
 *   @0x2ebc48 .word 0xf8802300
 *   @0x2ebc4c pop {r5, r12, sp}
 *   @0x2ebc50 blx 0xfe34dc1a <b2_toiTime+0xfffffffffdbf4776>
 *   @0x2ebc54 b 0x16b845c <b2_toiTime+0xf5efb8>
 *   @0x2ebc58 .word 0xf50070e2
 *   @0x2ebc5c ldmdane r11, {lr}
 *   @0x2ebc60 andeq pc, r0, #-2147483632
 *   @0x2ebc64 andsmi lr, r3, pc, asr #20
 *   @0x2ebc68 andmi lr, r2, r0, asr #20
 *   @0x2ebc6c push {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2ebc70 .word 0x46994ff8
 *   @0x2ebc74 .word 0xf8c92300
 *   @0x2ebc78 .word 0xf8c93000
 *   @0x2ebc7c mrslt r3, apsr
 *   @0x2ebc80 .word 0xb1023901
 *   @0x2ebc84 .word 0xf8d03a01
 *   @0x2ebc88 addsmi r3, r9, #152, #2
 *   @0x2ebc8c adcshi pc, r5, r0, lsl #4
 *   @0x2ebc90 vqsub.s8 d4, d16, d10
 *   @0x2ebc94 .word 0xf8d080b2
 *   @0x2ebc98 tsteq r2, r0, lsr #3
 *   @0x2ebc9c .word 0xf8d00109
 *   @0x2ebca0 .word 0xf8d041a8
 *   @0x2ebca4 bpl 0xfe993e4c <b2_toiTime+0xfffffffffe23a9a8>
 *   @0x2ebca8 b 0x1381e1c <b2_toiTime+0xc28978>
 *   @0x2ebcac teqlt r12, r3, lsl #16
 *   @0x2ebcb0 ldrmi r6, [r8, #0x923]
 *   @0x2ebcb4 stmdbvs r3!, {r1, r8, r9, r12, lr, pc} ^
 *   @0x2ebcb8 stmdble r3, {r3, r4, r7, r8, r10, lr}
 *   @0x2ebcbc ldrb r6, [r6, r4, lsr #16]!
 *   @0x2ebcc0 adds r4, r11, r6, lsr #12
 *   @0x2ebcc4 stmvs r1!, {r4, r6, r9, r10, lr} ^
 *   @0x2ebcc8 stc2l p7, c15, [sp, #1000]!
 *   @0x2ebccc stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2ebcd0 addshi pc, r4, r0, asr #32
 *   @0x2ebcd4 ldrbmi r7, [r0], -r1, lsr #18
 *   @0x2ebcd8 cmpmi r9, #10682368
 *   @0x2ebcdc .word 0xf8a1f7fc
 *   @0x2ebce0 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2ebce4 addhi pc, r10, r0, asr #32
 *   @0x2ebce8 movwhs r7, #0x1921
 *   @0x2ebcec blx 0xfef45f74 <b2_toiTime+0xfffffffffe7ecad0>
 *   @0x2ebcf0 .word 0xf894fe81
 *   @0x2ebcf4 .word 0xf1cec005
 *   @0x2ebcf8 .word 0xf8da0e1f
 *   @0x2ebcfc blx 0x3b3d84 <error_g0017+0xca28>
 *   @0x2ebd00 b 0x62b540 <g_SWFaavertbuff+0x58478>
 *   @0x2ebd04 .word 0xf00c0303
 *   @0x2ebd08 blx 0x2eed1a <FT_Done_Memory+0x50a6>
 *   @0x2ebd0c bl 0xfef6994c <b2_toiTime+0xfffffffffe8104a8>
 *   @0x2ebd10 blx 0x1aaf550 <b2_toiTime+0x13560ac>
 *   @0x2ebd14 eorsle pc, lr, r12, lsl #25
 *   @0x2ebd18 .word 0xfe0efb00
 *   @0x2ebd1c streq lr, [lr, #-0xb02]
 *   @0x2ebd20 .word 0xf812b183
 *   @0x2ebd24 stcne p0, c11, [r9, #-56]!
 *   @0x2ebd28 mul r1, r5, r8
 *   @0x2ebd2c vmlsmi.f32 s28, s28, s30
 *   @0x2ebd30 vmlsvs.f32 s28, s22, s28
 *   @0x2ebd34 mullt r3, r5, r8
 *   @0x2ebd38 b 0x1689ff4 <b2_toiTime+0xf30b50>
 *   @0x2ebd3c b 0x166f570 <b2_toiTime+0xf160cc>
 *   @0x2ebd40 and r2, r5, r5, lsl #10
 *   @0x2ebd44 and pc, lr, r2, lsl r8
 *   @0x2ebd48 stmdavc sp!, {r0, r3, r5, r7, r10, r11, r12} ^
 *   @0x2ebd4c strmi lr, [lr, #-0xa45]
 *   @0x2ebd50 eorsle r4, pc, r5, asr #10
 *   @0x2ebd54 .word 0xf1bcd21f
 *   @0x2ebd58 andle r0, r1, r0, lsl #30
 *   @0x2ebd5c ands r1, r10, r10, lsl #25
 *   @0x2ebd60 ands r1, r8, r10, asr #24
 *   @0x2ebd64 ldmibne r5, {r0, r1, r2, r3, r4, r5, r6, r11} ^
 *   @0x2ebd68 .word 0xf895b1c3
 *   @0x2ebd6c stcne p0, c14, [r9, #-4]!
 *   @0x2ebd70 andlt pc, r7, r2, lsl r8
 *   @0x2ebd74 vmlsmi.f32 s28, s28, s30
 *   @0x2ebd78 vmlsvs.f32 s28, s22, s28
 *   @0x2ebd7c mullt r3, r5, r8
 *   @0x2ebd80 vmlseq.f32 s28, s22, s28
 *   @0x2ebd84 mullt r2, r5, r8
 *   @0x2ebd88 vmlshs.f32 s28, s22, s28
 *   @0x2ebd8c eorle r4, r1, r6, asr #11
 *   @0x2ebd90 ldrmi r11, [r5], -r8, lsr #30
 *   @0x2ebd94 addmi r4, r7, #44040192
 *   @0x2ebd98 and sp, r7, r4, ror #17
 *   @0x2ebd9c andlt pc, r7, r2, lsl r8
 *   @0x2ebda0 .word 0xf8951ca9
 *   @0x2ebda4 b 0x16a3db0 <b2_toiTime+0xf4a90c>
 *   @0x2ebda8 strb r4, [pc, r11, lsl #28]!
 *   @0x2ebdac ldmdavc r3, {r0, r1, r3, r4, r6, r8, r12, sp, pc} ^
 *   @0x2ebdb0 ldmdavc r0, {r0, r4, r8, r10, r11, r12}
 *   @0x2ebdb4 b 0x13ace28 <b2_toiTime+0xc53984>
 *   @0x2ebdb8 ldmvc r0, {r8, r9, sp, lr} ^
 *   @0x2ebdbc movwmi r7, #0x3892
 *   @0x2ebdc0 movwhs lr, #0x2a43
 *   @0x2ebdc4 ldmdavc r0, {r2, sp, lr, pc}
 *   @0x2ebdc8 ldmdavc r3, {r0, r4, r7, r10, r11, r12} ^
 *   @0x2ebdcc movwmi lr, #0xa43
 *   @0x2ebdd0 .word 0xd10e4543
 *   @0x2ebdd4 svceq #0xf1bc
 *   @0x2ebdd8 stmdavc r10, {r0, r2, r12, lr, pc}
 *   @0x2ebddc b 0x13c9f10 <b2_toiTime+0xc70a6c>
 *   @0x2ebde0 andslt r2, r11, #134217728
 *   @0x2ebde4 stmdavc r11, {sp, lr, pc}
 *   @0x2ebde8 strhhs pc, [r6], -r4
 *   @0x2ebdec .word 0xf8c94413
 *   @0x2ebdf0 ldrbmi r3, [r0], -r0
 *   @0x2ebdf4 .word 0xf860f7fc
 *   @0x2ebdf8 strhs lr, [r0], -r0
 *   @0x2ebdfc pop {r4, r5, r9, r10, lr}
 *   @0x2ebe00 ldrlt r8, [r8, #-0xff8]!
 *   @0x2ebe04 ldrmi r4, [r12], -r5, lsl #12
 *   @0x2ebe08 .word 0xff31f7ff
 *   @0x2ebe0c .word 0x112cf8d5
 *   @0x2ebe10 ldrsbhs pc, [r0, -r5]!
 *   @0x2ebe14 mulle sp, r1, r2
 *   @0x2ebe18 tstlt r0, r0, lsr #16
 *   @0x2ebe1c .word 0xff8ef7f8
 *   @0x2ebe20 stmdavs r0!, {r5, sp, lr} ^
 *   @0x2ebe24 .word 0xf8d5b130
 *   @0x2ebe28 .word 0xf8d5112c
 *   @0x2ebe2c .word 0xf7f82130
 *   @0x2ebe30 rsbvs pc, r0, r5, lsl #31
 *   @0x2ebe34 ldclt p0, c2, [r8, #-0]!
 *   @0x2ebe38 strdlt r11, r12, [r5], r0
 *   @0x2ebe3c andhs r4, r0, #23068672
 *   @0x2ebe40 strmi r9, [r3], -r3, lsl #4
 *   @0x2ebe44 ldmdavs r0!, {r1, r4, r5, r6, r7, r10, r11, sp, lr}
 *   @0x2ebe48 vmovne r11, sp, d18
 *   @0x2ebe4c stmdale r1!, {r0, r2, r3, r7, r9, lr}
 *   @0x2ebe50 .word 0xf004781c
 *   @0x2ebe54 bl 0x4ada98 <SrcVerts+0xaadc>
 *   @0x2ebe58 bl 0x430eb0 <g_RomDisk+0x39690>
 *   @0x2ebe5c addsmi r0, r9, #68, #6
 *   @0x2ebe60 blge 0x3e0ac8 <error_g0017+0x3976c>
 *   @0x2ebe64 movwls r9, #0x1200
 *   @0x2ebe68 strtmi r2, [r3], -r4, lsl #2
 *   @0x2ebe6c .word 0xf90ff7fc
 *   @0x2ebe70 stmiblt r11, {r0, r1, r8, r9, r11, r12, pc}
 *   @0x2ebe74 streq lr, [r7, r0, lsl #22]
 *   @0x2ebe78 ldrtvs r6, [r7], #-1264
 *   @0x2ebe7c .word 0xf815b164
 *   @0x2ebe80 .word 0x3c012b02
 *   @0x2ebe84 .word 0x3c01f815
 *   @0x2ebe88 movwhs lr, #0x2a43
 *   @0x2ebe8c .word 0xf840b21b
 *   @0x2ebe90 ldrb r3, [r3, r4, lsl #22]!
 *   @0x2ebe94 movwls r2, #0x3308
 *   @0x2ebe98 andlt r9, r5, r3, lsl #16
 *   @0x2ebe9c push {r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2ebea0 .word 0x46034ff0
 *   @0x2ebea4 stmdaeq r5, {r0, r1, r8, r12, sp, lr, pc}
 *   @0x2ebea8 strbmi r11, [r1, #-0x85]
 *   @0x2ebeac ldmdavs r0, {r2, r4, r9, r10, lr}
 *   @0x2ebeb0 .word 0xf04f4689
 *   @0x2ebeb4 andls r0, r3, #0, #4
 *   @0x2ebeb8 adchi pc, r12, r0, asr #1
 *   @0x2ebebc .word 0x4645791f
 *   @0x2ebec0 ldmvc lr, {r1, r5, r6, r7, r8, r10, r11, sp, lr} ^
 *   @0x2ebec4 bl 0x4c7758 <SrcVerts+0x2479c>
 *   @0x2ebec8 ldrmi r0, [r10, #0xa02]
 *   @0x2ebecc mcrvs p9, #0x3, sp, c3, c2, #0x0
 *   @0x2ebed0 beq 0x3e8300 <error_g0017+0x40fa4>
 *   @0x2ebed4 beq 0x3e7f84 <error_g0017+0x40c28>
 *   @0x2ebed8 movwls r2, #0x124
 *   @0x2ebedc movwls r10, #0x1b03
 *   @0x2ebee0 .word 0xf7fc4653
 *   @0x2ebee4 blls 0x3ea23c <t1cid_driver_class+0x16c>
 *   @0x2ebee8 blhs 0x305870 <TT_New_Context+0x5668>
 *   @0x2ebeec addhi pc, lr, r0, asr #32
 *   @0x2ebef0 rsbge pc, r0, r4, asr #17
 *   @0x2ebef4 .word 0x0101f016
 *   @0x2ebef8 andeq pc, r2, #6
 *   @0x2ebefc movwhs r11, #0x9f14
 *   @0x2ebf00 .word 0xf0022308
 *   @0x2ebf04 strdlt r0, r1, [r2, -pc]
 *   @0x2ebf08 .word 0xf0063301
 *   @0x2ebf0c .word 0xf0020204
 *   @0x2ebf10 strdlt r0, r1, [r2, -pc]
 *   @0x2ebf14 .word 0xf0063301
 *   @0x2ebf18 .word 0xf0020208
 *   @0x2ebf1c strdlt r0, r1, [r2, -pc]
 *   @0x2ebf20 .word 0xf0063301
 *   @0x2ebf24 .word 0xf0020210
 *   @0x2ebf28 strdlt r0, r1, [r2, -pc]
 *   @0x2ebf2c blx 0x4b8b3a <SrcVerts+0x15b7e>
 *   @0x2ebf30 cdpvs p3, #0x6, c8, c2, c3, #0x0
 *   @0x2ebf34 ldrsblt pc, [r12], #-132
 *   @0x2ebf38 .word 0xd36b4599
 *   @0x2ebf3c .word 0xf04f2324
 *   @0x2ebf40 blx 0x3adf4a <error_g0017+0x6bee>
 *   @0x2ebf44 .word 0x3324230b
 *   @0x2ebf48 subsle r4, r12, #184, #10
 *   @0x2ebf4c .word 0xf895b139
 *   @0x2ebf50 .word 0xf105b000
 *   @0x2ebf54 stmdavc r10!, {r1, r8, r11} ^
 *   @0x2ebf58 andhs lr, r11, #270336
 *   @0x2ebf5c stmdavc r10!, {r1, sp, lr, pc}
 *   @0x2ebf60 stmdbeq r1, {r0, r2, r8, r12, sp, lr, pc}
 *   @0x2ebf64 stchs p8, c15, [r4], #-268
 *   @0x2ebf68 .word 0xf899b140
 *   @0x2ebf6c .word 0xf109b000
 *   @0x2ebf70 .word 0xf8990202
 *   @0x2ebf74 b 0x143ff80 <b2_toiTime+0xce6adc>
 *   @0x2ebf78 and r2, r3, r11, lsl #10
 *   @0x2ebf7c mulpl r0, r9, r8
 *   @0x2ebf80 andeq pc, r1, #1073741826
 *   @0x2ebf84 stcpl p8, c15, [r0], #-268
 *   @0x2ebf88 .word 0xf8437815
 *   @0x2ebf8c .word 0xf8925c1c
 *   @0x2ebf90 .word 0xf892b001
 *   @0x2ebf94 .word 0xf1bc9002
 *   @0x2ebf98 andle r0, r9, r0, lsl #30
 *   @0x2ebf9c stmdbhs r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2ebfa0 b 0x15333fc <b2_toiTime+0xdd9f58>
 *   @0x2ebfa4 .word 0xf8924b0b
 *   @0x2ebfa8 b 0x15cffbc <b2_toiTime+0xe76b18>
 *   @0x2ebfac and r0, r2, r9, lsl #4
 *   @0x2ebfb0 b 0x153330c <b2_toiTime+0xdd9e68>
 *   @0x2ebfb4 .word 0xf843220b
 *   @0x2ebfb8 .word 0xf8952c10
 *   @0x2ebfbc .word 0xf895b000
 *   @0x2ebfc0 .word 0xf1ba9001
 *   @0x2ebfc4 andle r0, r9, r0, lsl #30
 *   @0x2ebfc8 stmdbhs r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2ebfcc b 0x153337c <b2_toiTime+0xdd9ed8>
 *   @0x2ebfd0 .word 0xf8954b0b
 *   @0x2ebfd4 b 0x15cffe4 <b2_toiTime+0xe76b40>
 *   @0x2ebfd8 and r0, r2, r9, lsl #10
 *   @0x2ebfdc b 0x153328c <b2_toiTime+0xdd9de8>
 *   @0x2ebfe0 .word 0xf843250b
 *   @0x2ebfe4 teqlt r6, r12, lsl #24
 *   @0x2ebfe8 mulls r0, r2, r8
 *   @0x2ebfec ldmdavc r2, {r0, r2, r4, r7, r10, r11, r12} ^
 *   @0x2ebff0 andhs lr, r9, #270336
 *   @0x2ebff4 mrrcne p0, #0x0, lr, r5, c1
 *   @0x2ebff8 .word 0xf8437812
 *   @0x2ebffc .word 0xf1082c08
 *   @0x2ec000 .word 0x33240801
 *   @0x2ec004 stclvs p7, c14, [r3, #640]!
 *   @0x2ec008 strbvs r4, [r7, #0x41f]!
 *   @0x2ec00c andlt r9, r5, r3, lsl #16
 *   @0x2ec010 svchi #0xf0e8bd
 *   @0x2ec014 movwls r2, #0x3308
 *   @0x2ec018 ldrlt lr, [r8, #-0x7f8]!
 *   @0x2ec01c .word 0xf890460d
 *   @0x2ec020 stmibvs r4, {r5, r12, sp} ^
 *   @0x2ec024 rfeib r4!
 *   @0x2ec028 rfeib r4!
 *   @0x2ec02c ldrmi r2, [r10], #-22
 *   @0x2ec030 andlo r6, r1, #6488064
 *   @0x2ec034 ldmdale r0, {r1, r3, r4, r7, r9, lr}
 *   @0x2ec038 ldrhtlo pc, [r10], -r4
 *   @0x2ec03c ldm r5, {r1, r5, r6, r7, r8, r9, r11, sp, lr}
 *   @0x2ec040 bl 0x36c054 <_ZTS13C_UTF16String+0x3100>
 *   @0x2ec044 stm r2, {r0, r1, r6, r7, r9}
 *   @0x2ec048 mrshs r0, apsr
 *   @0x2ec04c andhs r6, r0, r2, lsr #24
 *   @0x2ec050 svchi #0x6354d1
 *   @0x2ec054 strbhi r4, [r3, -r11, lsl #8]!
 *   @0x2ec058 qasxmi r11, r0, r8
 *   @0x2ec05c andhs r2, r0, #1073741824
 *   @0x2ec060 .word 0xf851f7fc
 *   @0x2ec064 strb r11, [r7, r8, lsl #18]!
 *   @0x2ec068 ldclt p0, c2, [r8, #-32]!
 *   @0x2ec06c .word 0x4604b570
 *   @0x2ec070 ldrsbtlo pc, [r12], r0
 *   @0x2ec074 .word 0xf8d42500
 *   @0x2ec078 ldmdavs lr, {r3, r5, r7, r12}
 *   @0x2ec07c .word 0xf7fb4630
 *   @0x2ec080 .word 0xf8c4f95a
 *   @0x2ec084 .word 0xf8c450a8
 *   @0x2ec088 ldrtmi r5, [r0], -r12, lsr #1
 *   @0x2ec08c adcpl pc, r4, r4, asr #17
 *   @0x2ec090 ldrsbtne pc, [r8], r4
 *   @0x2ec094 .word 0xf94ff7fb
 *   @0x2ec098 adcspl pc, r8, r4, asr #17
 *   @0x2ec09c adcspl pc, r4, r4, asr #17
 *   @0x2ec0a0 adcspl pc, r0, r4, asr #17
 *   @0x2ec0a4 adcspl pc, r12, r4, asr #17
 *   @0x2ec0a8 sbcpl pc, r0, r4, lsl #17
 *   @0x2ec0ac push {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2ec0b0 .word 0x460441f0
 *   @0x2ec0b4 subsle r2, r12, r0, lsl #16
 *   @0x2ec0b8 strhs r6, [r0, #-0xe03]
 *   @0x2ec0bc ldmvs pc, {r1, r2, r6, r9, r10, r11, sp, lr}
 *   @0x2ec0c0 orrvs r6, r5, r5, asr #2
 *   @0x2ec0c4 .word 0xf8d44630
 *   @0x2ec0c8 .word 0xf7fb1170
 *   @0x2ec0cc .word 0xf8c4f934
 *   @0x2ec0d0 shsub16mi r5, r0, r0
 *   @0x2ec0d4 ldrsbne pc, [r4, #-132]!
 *   @0x2ec0d8 .word 0xf92df7fb
 *   @0x2ec0dc cmnpl r4, r4, asr #17
 *   @0x2ec0e0 .word 0xf8d44630
 *   @0x2ec0e4 .word 0xf7fb1178
 *   @0x2ec0e8 .word 0xf8c4f926
 *   @0x2ec0ec shsub16mi r5, r0, r8
 *   @0x2ec0f0 .word 0x116cf8d4
 *   @0x2ec0f4 .word 0xf91ff7fb
 *   @0x2ec0f8 smulbtpl r12, r4, r8
 *   @0x2ec0fc smulbtpl r8, r4, r8
 *   @0x2ec100 .word 0xf8c44630
 *   @0x2ec104 .word 0xf8c45160
 *   @0x2ec108 .word 0xf8d4515c
 *   @0x2ec10c .word 0xf7fb1184
 *   @0x2ec110 .word 0xf8c4f912
 *   @0x2ec114 .word 0xf8c45184
 *   @0x2ec118 shsub16mi r5, r0, r12
 *   @0x2ec11c orrpl pc, r0, r4, asr #17
 *   @0x2ec120 .word 0x11a0f8d4
 *   @0x2ec124 .word 0xf907f7fb
 *   @0x2ec128 asrpl pc, r4, #17
 *   @0x2ec12c orrspl pc, r8, r4, asr #17
 *   @0x2ec130 .word 0xf8c44630
 *   @0x2ec134 .word 0xf8d4519c
 *   @0x2ec138 .word 0xf7fb118c
 *   @0x2ec13c .word 0xf8c4f8fc
 *   @0x2ec140 .word 0xf8c4518c
 *   @0x2ec144 .word 0xf8d45188
 *   @0x2ec148 teqlt sp, r8, lsr #3
 *   @0x2ec14c .word 0x8000f8d5
 *   @0x2ec150 ldrtmi r4, [r0], -r9, lsr #12
 *   @0x2ec154 .word 0xf8eff7fb
 *   @0x2ec158 ldrb r4, [r6, r5, asr #12]!
 *   @0x2ec15c .word 0x51a8f8c4
 *   @0x2ec160 .word 0xf8c44638
 *   @0x2ec164 .word 0xf8c451ac
 *   @0x2ec168 bvs 0xb40800 <b2_toiTime+0x3e735c>
 *   @0x2ec16c .word 0xf8e3f7fb
 *   @0x2ec170 pop {r0, r2, r5, r9, sp, lr}
 *   @0x2ec174 ldrblt r8, [r0, #-0x1f0]!
 *   @0x2ec178 .word 0xf8d02100
 *   @0x2ec17c .word 0x4604309c
 *   @0x2ec180 adclo r2, r0, r4, lsr #4
 *   @0x2ec184 ldmdavs sp, {r9, r10, sp}
 *   @0x2ec188 b 0x7a98b8 <b2_toiTime+0x50414>
 *   @0x2ec18c sbcvs pc, r0, r4, lsl #17
 *   @0x2ec190 .word 0xf8c44628
 *   @0x2ec194 .word 0xf7f950bc
 *   @0x2ec198 shadd8mi pc, r0, r1
 *   @0x2ec19c push {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2ec1a0 ssub8mi r4, r5, r3
 *   @0x2ec1a4 bge 0x386268 <_ZTS13C_UTF16String+0x1d314>
 *   @0x2ec1a8 strmi r2, [r4], -r0, lsl #6
 *   @0x2ec1ac stclo p8, c15, [r4, #-264]
 *   @0x2ec1b0 ldrtmi r4, [r8], -r8, lsl #13
 *   @0x2ec1b4 .word 0xf7fa2118
 *   @0x2ec1b8 blls 0x36c098 <_ZTS13C_UTF16String+0x3144>
 *   @0x2ec1bc blhs 0x2fd9c8 <TT_RunIns+0xbd4>
 *   @0x2ec1c0 stcne p1, c13, [r3, #-364]!
 *   @0x2ec1c4 cmple r12, #152, #10
 *   @0x2ec1c8 .word 0x71027822
 *   @0x2ec1cc stmvc r0!, {r1, r2, r5, r6, r11, r12, sp, lr}
 *   @0x2ec1d0 andhs lr, r6, r0, asr #20
 *   @0x2ec1d4 stmvc r6!, {r3, r6, r7, pc} ^
 *   @0x2ec1d8 .word 0xf8d5714e
 *   @0x2ec1dc bl 0xff2ec434 <b2_toiTime+0xfffffffffeb92f90>
 *   @0x2ec1e0 stmdavs r8!, {r0, r1, r10, r11} ^
 *   @0x2ec1e4 .word 0xf0164460
 *   @0x2ec1e8 sbcvs r0, r8, r1, lsl #24
 *   @0x2ec1ec andhs r11, r3, r12, lsl #30
 *   @0x2ec1f0 addvs r2, r8, r5
 *   @0x2ec1f4 strle r0, [r2, #-0x7b0]
 *   @0x2ec1f8 andlo r6, r1, r8, lsl #17
 *   @0x2ec1fc stmvs r8, {r3, r7, sp, lr}
 *   @0x2ec200 strlo pc, [r2], -r0, lsl #22
 *   @0x2ec204 teqle r12, #176, #10
 *   @0x2ec208 eorsle r2, r3, r0, lsl #20
 *   @0x2ec20c .word 0xf1bc3a01
 *   @0x2ec210 andsle r0, r5, r0, lsl #30
 *   @0x2ec214 stmdbvc r6!, {r0, r1, r2, r5, r8, r11, r12, sp, lr} ^
 *   @0x2ec218 b 0x147cf60 <b2_toiTime+0xd23abc>
 *   @0x2ec21c stmibvc r7!, {r0, r1, r2, r9, r10, sp}
 *   @0x2ec220 b 0x140a9b8 <b2_toiTime+0xcb1514>
 *   @0x2ec224 b 0x13f5248 <b2_toiTime+0xc9bda4>
 *   @0x2ec228 .word 0x610c4406
 *   @0x2ec22c .word 0x5c1a181c
 *   @0x2ec230 stmvc r0!, {r0, r1, r5, r6, r11, r12, sp, lr}
 *   @0x2ec234 andhs lr, r2, #274432
 *   @0x2ec238 b 0x13ca5cc <b2_toiTime+0xc71128>
 *   @0x2ec23c and r2, r8, r0, lsl #6
 *   @0x2ec240 stmdbvc r6!, {r4, r6, r8, r9, lr}
 *   @0x2ec244 b 0x140a7dc <b2_toiTime+0xcb1338>
 *   @0x2ec248 .word 0x610c4406
 *   @0x2ec24c .word 0x5c1a181c
 *   @0x2ec250 b 0x13ca3e4 <b2_toiTime+0xc70f40>
 *   @0x2ec254 .word 0x614b4302
 *   @0x2ec258 andvs r2, r11, r0, lsl #6
 *   @0x2ec25c .word 0x308cf8d5
 *   @0x2ec260 .word 0xf8c56019
 *   @0x2ec264 .word 0xf8d5108c
 *   @0x2ec268 stmdbvc r10, {r2, r7, r12, sp}
 *   @0x2ec26c .word 0xf8c54413
 *   @0x2ec270 and r3, r2, r4, lsl #1
 *   @0x2ec274 .word 0xf7fb4638
 *   @0x2ec278 stmdals r1, {r1, r2, r3, r4, r6, r11, r12, sp, lr, pc}
 *   @0x2ec27c pop {r1, r12, sp, pc}
 *   @0x2ec280 shsub8mi r8, r8, r0
 *   @0x2ec284 .word 0xf857f7fb
 *   @0x2ec288 movwls r2, #0x1308
 *   @0x2ec28c ldrblt lr, [r7, #0x7f5]!
 *   @0x2ec290 movwls r2, #0x1300
 *   @0x2ec294 ldcvs p6, c4, [r3, #-28]
 *   @0x2ec298 ldmdavs r0, {r2, r4, r9, r10, lr}
 *   @0x2ec29c blne 0xff65a850 <b2_toiTime+0xfffffffffef013ac>
 *   @0x2ec2a0 .word 0x1c69aa01
 *   @0x2ec2a4 .word 0xff3ff7fa
 *   @0x2ec2a8 strvs r9, [r0, #-0xe01]!
 *   @0x2ec2ac ldrtmi r11, [r9], -lr, lsr #18
 *   @0x2ec2b0 .word 0xf5ca462a
 *   @0x2ec2b4 stcvs p9, c14, [r3, #-528]!
 *   @0x2ec2b8 stmdals r1, {r1, r2, r3, r4, r6, r8, r10, r12, lr}
 *   @0x2ec2bc ldcllt p0, c11, [r0, #12]!
 *   @0x2ec2c0 mvnsmi lr, sp, lsr #18
 *   @0x2ec2c4 ldmdavs r9, {r0, r2, r3, r9, r10, lr}
 *   @0x2ec2c8 strmi r2, [r7], -r0, lsl #8
 *   @0x2ec2cc sadd8mi r4, lr, r0
 *   @0x2ec2d0 tstlt r9, r1, lsl #8
 *   @0x2ec2d4 .word 0xf7fb4610
 *   @0x2ec2d8 eorsvs pc, r4, lr, lsr #16
 *   @0x2ec2dc cdpne p1, #0x6, c11, c11, c5, #0x1
 *   @0x2ec2e0 bhs 0x3036d0 <TT_New_Context+0x34c8>
 *   @0x2ec2e4 ldrmi r11, [sp], -r8, lsl #30
 *   @0x2ec2e8 adcmi r2, r12, #0, #8
 *   @0x2ec2ec ldcpl p0, c13, [r11, #-20]!
 *   @0x2ec2f0 blhs 0x1abaf78 <b2_toiTime+0x1361ad4>
 *   @0x2ec2f4 strlo sp, [r1], #-2068
 *   @0x2ec2f8 ldrshlt lr, [r12, r7]
 *   @0x2ec2fc stclne p6, c4, [r1], #-256
 *   @0x2ec300 .word 0xf7faaa01
 *   @0x2ec304 .word 0xf8ddff10
 *   @0x2ec308 strmi r8, [r5], -r4
 *   @0x2ec30c svceq #0xf1b8
 *   @0x2ec310 ldrtmi sp, [r9], -r9, lsl #2
 *   @0x2ec314 .word 0xf5ca4622
 *   @0x2ec318 .word 0xf805e952
 *   @0x2ec31c and r8, r2, r4
 *   @0x2ec320 and r2, r0, r0, lsl #10
 *   @0x2ec324 stmdals r1, {r0, r2, r5, r9, r10, lr}
 *   @0x2ec328 andlt r6, r2, r5, lsr r0
 *   @0x2ec32c ldrhhi lr, [r0, #141]!
 *   @0x2ec330 ldrbtmi r4, [r8], #-2049
 *   @0x2ec334 stmdalt sp, {r0, r3, r4, r5, r6, r7, r8, r9, r10, r12, sp, lr, pc}
 *   @0x2ec338 andeq r12, pc, r2, ror #14
 *   @0x2ec33c mvnsmi lr, sp, lsr #18
 *   @0x2ec340 ldrmi r4, [pc], -r4, lsl #12
 *   @0x2ec344 stcvs p14, c9, [r5, #24]
 *   @0x2ec348 .word 0xf8d0b111
 *   @0x2ec34c andvs r3, r11, r12, lsr #2
 *   @0x2ec350 .word 0xf8d4b112
 *   @0x2ec354 andsvs r3, r3, r0, lsr r1
 *   @0x2ec358 stmibhi r8!, {r0, r2, r3, r5, r6, r8, r12, sp, pc}
 *   @0x2ec35c ldrsbne pc, [r0, -r4]!
 *   @0x2ec360 .word 0xf7f80180
 *   @0x2ec364 .word 0xf8d4fda8
 *   @0x2ec368 .word 0x46801130
 *   @0x2ec36c orreq r8, r0, r8, ror #19
 *   @0x2ec370 stc2 p7, c15, [r1, #992]!
 *   @0x2ec374 vst4.8 {d30, d31, d0, d1}, [pc], r2
 *   @0x2ec378 strmi r3, [r0], r0, lsl #1
 *   @0x2ec37c .word 0xf8c7b10f
 *   @0x2ec380 .word 0xb1068000
 *   @0x2ec384 andhs r6, r0, r0, lsr r0
 *   @0x2ec388 ldrhhi lr, [r0, #141]!
 *   @0x2ec38c andsvs r2, r3, r0, lsl #6
 *   @0x2ec390 .word 0xb169b510
 *   @0x2ec394 .word 0xf8d0b160
 *   @0x2ec398 stmdblo r1, {r3, r4, r7, r8, lr}
 *   @0x2ec39c andle r4, r7, #268435466
 *   @0x2ec3a0 .word 0x01a0f8d0
 *   @0x2ec3a4 .word 0x1101eb00
 *   @0x2ec3a8 stmdavs r9, {r3, r4, r9, r10, lr} ^
 *   @0x2ec3ac ldclt p0, c6, [r0, #-68]
 *   @0x2ec3b0 ldclt p0, c2, [r0, #-24]
 *   @0x2ec3b4 stmdavs r3, {r4, r5, r6, r8, r10, r12, sp, pc}
 *   @0x2ec3b8 addmi r1, r10, #23040
 *   @0x2ec3bc ldmdavc lr, {r0, r4, r11, r12, lr, pc}
 *   @0x2ec3c0 andhs r4, r0, #19922944
 *   @0x2ec3c4 mulle r10, r6, r2
 *   @0x2ec3c8 adcmi r1, r9, #40192
 *   @0x2ec3cc ldmdavc r12, {r0, r3, r8, r9, r12, lr, pc}
 *   @0x2ec3d0 strtmi r3, [r11], -r1, lsl #4
 *   @0x2ec3d4 addmi r4, r12, #44, #8
 *   @0x2ec3d8 strtmi sp, [r3], -r3, lsl #16
 *   @0x2ec3dc andhs lr, r0, #63438848
 *   @0x2ec3e0 andhs lr, r8, #0
 *   @0x2ec3e4 ldrmi r6, [r0], -r3
 *   @0x2ec3e8 andeq r11, r0, r0, ror sp
 *   @0x2ec3ec svcmi #0xf0e92d
 *   @0x2ec3f0 .word 0x4604b091
 *   @0x2ec3f4 .word 0x91024608
 *   @0x2ec3f8 ldrmi r4, [r9], #-1553
 *   @0x2ec3fc .word 0xf8dd9204
 *   @0x2ec400 .word 0xf7fa8068
 *   @0x2ec404 .word 0x4606fa50
 *   @0x2ec408 .word 0xf0402800
 *   @0x2ec40c stmdals r2, {r0, r2, r4, r6, r8, r9, pc}
 *   @0x2ec410 .word 0xf7fb4641
 *   @0x2ec414 strmi pc, [r6], -r6, lsl #26
 *   @0x2ec418 .word 0xf0402800
 *   @0x2ec41c stmdals r2, {r0, r2, r3, r6, r8, r9, pc}
 *   @0x2ec420 bvs 0x3c6bc4 <error_g0017+0x1f868>
 *   @0x2ec424 streq lr, [r8, #-0xb03]
 *   @0x2ec428 .word 0xf1b81c5a
 *   @0x2ec42c .word 0xf0000f00
 *   @0x2ec430 .word 0xf993816a
 *   @0x2ec434 stmdbhs r0, {r12}
 *   @0x2ec438 smulbbhi r5, r0, r2
 *   @0x2ec43c adcmi r6, r10, #540672
 *   @0x2ec440 strls r9, [r8], -r7, lsl #6
 *   @0x2ec444 .word 0xf8d79103
 *   @0x2ec448 vhadd.s8 d10, d0, d0
 *   @0x2ec44c andls r8, r7, #239
 *   @0x2ec450 sadd16eq r7, lr, r11
 *   @0x2ec454 rschi pc, r10, r0, asr #2
 *   @0x2ec458 .word 0xf0030658
 *   @0x2ec45c strle r0, [r7], #-1599
 *   @0x2ec460 ldrsbls pc, [r0], -r4
 *   @0x2ec464 bl 0x4869f4 <g_States+0x102c>
 *   @0x2ec468 ldrmi r0, [r0, #0x809]
 *   @0x2ec46c ands sp, pc, r8, lsl #16
 *   @0x2ec470 strtmi r10, [r9], -r7, lsl #16
 *   @0x2ec474 .word 0xff9ef7ff
 *   @0x2ec478 stmdahs r0, {r3, r12, pc}
 *   @0x2ec47c ldrsh sp, [r7], #0
 *   @0x2ec480 stmdaeq r3, {r3, r8, r12, sp, lr, pc}
 *   @0x2ec484 stmdaeq r3, {r3, r5, r12, sp, lr, pc}
 *   @0x2ec488 svceq #0x40f1b8
 *   @0x2ec48c sbchi pc, lr, r0, lsl #4
 *   @0x2ec490 ldrbmi r6, [r0], -r3, lsr #19
 *   @0x2ec494 movwls r2, #0x118
 *   @0x2ec498 movwls r10, #0x1b08
 *   @0x2ec49c .word 0xf7fb4643
 *   @0x2ec4a0 blls 0x52bc80 <SrcVerts+0x88cc4>
 *   @0x2ec4a4 blhs 0x304b2c <TT_New_Context+0x4924>
 *   @0x2ec4a8 sbchi pc, r2, r0, asr #32
 *   @0x2ec4ac andshi pc, r4, r4, asr #17
 *   @0x2ec4b0 andshs r6, r8, #2670592
 *   @0x2ec4b4 vst4.8 {d18, d19, d20, d21}, [pc], r0
 *   @0x2ec4b8 blx 0x37bec2 <_ZTS13C_UTF16String+0x12f6e>
 *   @0x2ec4bc ldrmi r3, [r3], #-777
 *   @0x2ec4c0 .word 0xf08042b0
 *   @0x2ec4c4 bls 0x4cc7a0 <SrcVerts+0x297e4>
 *   @0x2ec4c8 adcmi r1, r9, #20736
 *   @0x2ec4cc adchi pc, lr, r0, lsl #4
 *   @0x2ec4d0 ldmdavc r2, {r0, r1, r2, r8, r12, pc}
 *   @0x2ec4d4 .word 0xec18f843
 *   @0x2ec4d8 ldrle r0, [r0, #-0x6d1]
 *   @0x2ec4dc .word 0xf1019907
 *   @0x2ec4e0 strmi r0, [r12, #0xc02]!
 *   @0x2ec4e4 adchi pc, r2, r0, lsl #4
 *   @0x2ec4e8 andsgt pc, r12, sp, asr #17
 *   @0x2ec4ec mulgt r0, r1, r8
 *   @0x2ec4f0 b 0x134a61c <b2_toiTime+0xbf1178>
 *   @0x2ec4f4 andlt r2, r9, #12, #2
 *   @0x2ec4f8 .word 0xf8430109
 *   @0x2ec4fc .word 0x06911c18
 *   @0x2ec500 .word 0xec14f843
 *   @0x2ec504 stmdbls r7, {r4, r8, r10, r12, lr, pc}
 *   @0x2ec508 .word 0x0c02f101
 *   @0x2ec50c vrshl.s8 d4, d28, d16
 *   @0x2ec510 .word 0xf8cd808d
 *   @0x2ec514 .word 0xf891c01c
 *   @0x2ec518 stmdavc r9, {lr, pc} ^
 *   @0x2ec51c .word 0x210cea41
 *   @0x2ec520 .word 0x0109b209
 *   @0x2ec524 .word 0x1c14f843
 *   @0x2ec528 mrseq pc, apsr
 *   @0x2ec52c andle r2, r2, r1, lsl #18
 *   @0x2ec530 andle r2, pc, r2, lsl #18
 *   @0x2ec534 stmdbls r7, {r3, r4, sp, lr, pc}
 *   @0x2ec538 .word 0x0c02f101
 *   @0x2ec53c ldmdale r5!, {r2, r3, r5, r7, r8, r10, lr} ^
 *   @0x2ec540 andsgt pc, r12, sp, asr #17
 *   @0x2ec544 mulgt r0, r1, r8
 *   @0x2ec548 b 0x134a674 <b2_toiTime+0xbf11d0>
 *   @0x2ec54c blx 0x6b7584 <g_SWFlinevertbuff+0x644bc>
 *   @0x2ec550 and pc, r11, r12, lsl #25
 *   @0x2ec554 .word 0xf1019907
 *   @0x2ec558 strmi r0, [r12, #0xc01]!
 *   @0x2ec55c .word 0xf8cdd866
 *   @0x2ec560 .word 0xf991c01c
 *   @0x2ec564 and r12, r1, r0
 *   @0x2ec568 .word 0x0c00f04f
 *   @0x2ec56c orreq pc, r1, r2, asr #7
 *   @0x2ec570 andle r2, r2, r1, lsl #18
 *   @0x2ec574 andle r2, lr, r2, lsl #18
 *   @0x2ec578 stmdbls r7, {r0, r1, r2, r4, sp, lr, pc}
 *   @0x2ec57c stmdaeq r2, {r0, r8, r12, sp, lr, pc}
 *   @0x2ec580 ldmdale r3, {r3, r5, r7, r8, r10, lr} ^
 *   @0x2ec584 andshi pc, r12, sp, asr #17
 *   @0x2ec588 mulhi r0, r1, r8
 *   @0x2ec58c b 0x134a6b8 <b2_toiTime+0xbf1214>
 *   @0x2ec590 andlt r2, r9, #8, #2
 *   @0x2ec594 stmdbls r7, {r1, r3, sp, lr, pc}
 *   @0x2ec598 stmdaeq r1, {r0, r8, r12, sp, lr, pc}
 *   @0x2ec59c stmdale r5, {r3, r5, r7, r8, r10, lr} ^
 *   @0x2ec5a0 andshi pc, r12, sp, asr #17
 *   @0x2ec5a4 mulne r0, r1, r9
 *   @0x2ec5a8 .word 0x2100e000
 *   @0x2ec5ac svceq #0x40f012
 *   @0x2ec5b0 .word 0xcc10f843
 *   @0x2ec5b4 .word 0x1c0cf843
 *   @0x2ec5b8 andle r9, r11, r7, lsl #18
 *   @0x2ec5bc .word 0x0c02f101
 *   @0x2ec5c0 ldmdale r3!, {r2, r3, r5, r7, r8, r10, lr}
 *   @0x2ec5c4 andsgt pc, r12, sp, asr #17
 *   @0x2ec5c8 mulgt r0, r1, r8
 *   @0x2ec5cc b 0x134a6f8 <b2_toiTime+0xbf1254>
 *   @0x2ec5d0 and r2, r6, r12, lsl #2
 *   @0x2ec5d4 .word 0x0c01f101
 *   @0x2ec5d8 stmdale r7!, {r2, r3, r5, r7, r8, r10, lr}
 *   @0x2ec5dc andsgt pc, r12, sp, asr #17
 *   @0x2ec5e0 .word 0xf0127809
 *   @0x2ec5e4 .word 0xf8430f80
 *   @0x2ec5e8 bls 0x4b3600 <SrcVerts+0x10644>
 *   @0x2ec5ec ldclne p0, c13, [r1], {14}
 *   @0x2ec5f0 ldmdale r11, {r0, r3, r5, r7, r9, lr}
 *   @0x2ec5f4 .word 0xf8929107
 *   @0x2ec5f8 ldmdavc r1, {r0, lr, pc}
 *   @0x2ec5fc .word 0x2c0cea4f
 *   @0x2ec600 .word 0x4c01ea4c
 *   @0x2ec604 b 0x160a850 <b2_toiTime+0xeb13ac>
 *   @0x2ec608 and r0, r7, r1, lsl #4
 *   @0x2ec60c adcmi r1, r9, #37120
 *   @0x2ec610 mrsls sp, apsr
 *   @0x2ec614 ldmdavc r2, {r0, r4, r11, r12, sp, lr} ^
 *   @0x2ec618 andhs lr, r1, #270336
 *   @0x2ec61c .word 0x2c08f843
 *   @0x2ec620 stmdbvs r2!, {r0, r12, sp}
 *   @0x2ec624 andlo r3, r1, #24, #6
 *   @0x2ec628 strb r6, [r9, -r2, lsr #2]
 *   @0x2ec62c movwls r2, #0x8308
 *   @0x2ec630 stmdals r2, {r3, r9, r10, r11, r12, pc}
 *   @0x2ec634 mcrr2 p7, #0xf, pc, r0, c11
 *   @0x2ec638 .word 0xf0402e00
 *   @0x2ec63c stmdbvs r3!, {r0, r2, r3, r4, r5, r9, pc}
 *   @0x2ec640 bls 0x3be108 <error_g0017+0x16dac>
 *   @0x2ec644 movwls r1, #0x5a9b
 *   @0x2ec648 .word 0xf108e001
 *   @0x2ec64c stmdals r5, {r0, r11}
 *   @0x2ec650 .word 0xf0004580
 *   @0x2ec654 .word 0xf8dd8231
 *   @0x2ec658 tsths r8, #12
 *   @0x2ec65c ldrhge pc, [r6], -r7
 *   @0x2ec660 strbmi r4, [r3], #1568
 *   @0x2ec664 blx 0x3d2a76 <error_g0017+0x2b71a>
 *   @0x2ec668 stmibvs r3!, {r0, r1, r3, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2ec66c ldmdbvs r10, {r0, r1, r3, r4, r6, r10, lr} ^
 *   @0x2ec670 bls 0x410e78 <g_RomDisk+0x19658>
 *   @0x2ec674 .word 0xf7ff691b
 *   @0x2ec678 stmdahs r0, {r0, r3, r4, r5, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ec67c andshi pc, r11, #64
 *   @0x2ec680 rfeib r7!
 *   @0x2ec684 bl 0x3d06e4 <error_g0017+0x29388>
 *   @0x2ec688 .word 0xf853050b
 *   @0x2ec68c bl 0xff5786c0 <b2_toiTime+0xfffffffffee1f21c>
 *   @0x2ec690 .word 0xf5b30909
 *   @0x2ec694 smlabble r3, r0, pc, r3
 *   @0x2ec698 .word 0xf5b3686b
 *   @0x2ec69c andsle r3, sp, r0, lsl #31
 *   @0x2ec6a0 .word 0xf04f69b9
 *   @0x2ec6a4 bl 0x32f2ac
 *   @0x2ec6a8 strbmi r0, [r11, #0xaca]
 *   @0x2ec6ac beq 0x528adc <SrcVerts+0x85b20>
 *   @0x2ec6b0 stmdavs r9!, {r0, r1, r3, r6, r7, r9, r11, r12, lr, pc}
 *   @0x2ec6b4 bleq 0x368ae8 <_ZTS12CDS_Priority+0xab40>
 *   @0x2ec6b8 .word 0x0c08f85a
 *   @0x2ec6bc blx 0xff4aa6a6 <b2_toiTime+0xfffffffffed51202>
 *   @0x2ec6c0 ldrmi r6, [r8], #-2219
 *   @0x2ec6c4 .word 0x0c08f84a
 *   @0x2ec6c8 .word 0x0c04f85a
 *   @0x2ec6cc .word 0xf7f86869
 *   @0x2ec6d0 stmvs r11!, {r0, r2, r3, r4, r5, r7, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x2ec6d4 .word 0xf84a4418
 *   @0x2ec6d8 strb r0, [r6, r4, lsl #24]!
 *   @0x2ec6dc bl 0x346dc8
 *   @0x2ec6e0 strbmi r0, [r8, #-0x1ca]
 *   @0x2ec6e4 .word 0x0108f101
 *   @0x2ec6e8 .word 0xf851daaf
 *   @0x2ec6ec andlo r2, r1, r8, lsl #24
 *   @0x2ec6f0 ldrmi r6, [r3], #-2219
 *   @0x2ec6f4 .word 0x2c04f851
 *   @0x2ec6f8 .word 0x3c08f841
 *   @0x2ec6fc ldrmi r6, [r3], #-2283
 *   @0x2ec700 .word 0x3c04f841
 *   @0x2ec704 adcmi lr, r10, #62128128
 *   @0x2ec708 .word 0xf04f9306
 *   @0x2ec70c mrsls r0, apsr
 *   @0x2ec710 vtst.8 d6, d0, d24
 *   @0x2ec714 andls r8, r6, #1073741874
 *   @0x2ec718 shadd16eq r7, r2, lr
 *   @0x2ec71c bichi pc, r4, r0, lsl #2
 *   @0x2ec720 strle r0, [r11, #-0x777]
 *   @0x2ec724 adcmi r1, r10, #39424
 *   @0x2ec728 .word 0x81bef200
 *   @0x2ec72c .word 0xf8939206
 *   @0x2ec730 .word 0xf00aa001
 *   @0x2ec734 b 0x16aeb78 <b2_toiTime+0xf556d4>
 *   @0x2ec738 ands r1, r6, r10, lsl r10
 *   @0x2ec73c andeq pc, r2, #6
 *   @0x2ec740 ldmibeq pc!, {r1, r12, sp, lr, pc} ^
 *   @0x2ec744 ldcne p1, c11, [r10], {50}
 *   @0x2ec748 vhsub.s8 d4, d16, d26
 *   @0x2ec74c andls r8, r6, #1073741867
 *   @0x2ec750 mulls r1, r3, r8
 *   @0x2ec754 beq 0x3687b4 <_ZTS12CDS_Priority+0xa80c>
 *   @0x2ec758 blls 0x4a077c <TimingData+0x6764>
 *   @0x2ec75c adcmi r1, r10, #23040
 *   @0x2ec760 .word 0x81a2f200
 *   @0x2ec764 .word 0xf8939206
 *   @0x2ec768 stmdavs r2!, {sp, pc} ^
 *   @0x2ec76c streq lr, [r9, -r10, lsl #22]
 *   @0x2ec770 ldmdble r2, {r0, r1, r2, r4, r7, r9, lr}
 *   @0x2ec774 .word 0xf10768a3
 *   @0x2ec778 .word 0xf0280807
 *   @0x2ec77c .word 0x21040807
 *   @0x2ec780 blge 0x4d1388 <SrcVerts+0x2e3cc>
 *   @0x2ec784 strbmi r9, [r3], -r1, lsl #6
 *   @0x2ec788 stc2 p7, c15, [r1], {251}
 *   @0x2ec78c adcvs r9, r0, r7, lsl #22
 *   @0x2ec790 .word 0xf0402b00
 *   @0x2ec794 .word 0xf8c4818b
 *   @0x2ec798 stmvs r3!, {r2, pc}
 *   @0x2ec79c orreq lr, r9, #3072
 *   @0x2ec7a0 movwhs r6, #0xe3
 *   @0x2ec7a4 sadd16mi r4, r10, r8
 *   @0x2ec7a8 .word 0xd02742ba
 *   @0x2ec7ac qaddle r0, r1, r6
 *   @0x2ec7b0 mcrrne p9, #0x0, r9, r8, c6
 *   @0x2ec7b4 vhsub.s8 d4, d16, d24
 *   @0x2ec7b8 andls r8, r6, r7, ror r1
 *   @0x2ec7bc .word 0xf0107808
 *   @0x2ec7c0 stmdbls r6, {r0, r8, r9, r10, r11}
 *   @0x2ec7c4 stcne p0, c13, [r11], {11}
 *   @0x2ec7c8 vhsub.s8 d4, d16, d27
 *   @0x2ec7cc movwls r8, #0x616d
 *   @0x2ec7d0 mul r0, r1, r8
 *   @0x2ec7d4 b 0x13ca908 <b2_toiTime+0xc71464>
 *   @0x2ec7d8 andslt r2, r11, #939524096
 *   @0x2ec7dc .word 0xf101e008
 *   @0x2ec7e0 strmi r0, [lr, #0xe01]!
 *   @0x2ec7e4 .word 0x8160f200
 *   @0x2ec7e8 ands pc, r8, sp, asr #17
 *   @0x2ec7ec strmi r7, [r11], #-2057
 *   @0x2ec7f0 stmdaeq r0, {r0, r5, r7, r11, sp, lr} ^
 *   @0x2ec7f4 eorlo pc, r2, r1, asr #16
 *   @0x2ec7f8 ldrb r3, [r5, r1, lsl #4]
 *   @0x2ec7fc strle r0, [r12], #-1843
 *   @0x2ec800 movwhs r10, #0xe08
 *   @0x2ec804 .word 0xf10d9309
 *   @0x2ec808 movwls r0, #0x8838
 *   @0x2ec80c muleq r3, r6, r8
 *   @0x2ec810 eorlo pc, r0, r4, lsl #17
 *   @0x2ec814 andeq lr, r3, r8, lsl #17
 *   @0x2ec818 stmdage r6, {r0, r1, r3, r5, sp, lr, pc}
 *   @0x2ec81c .word 0xf7ff4629
 *   @0x2ec820 andls pc, r7, r9, asr #27
 *   @0x2ec824 rscle r2, r11, r0, lsl #16
 *   @0x2ec828 stmibvs r7!, {r6, r8, sp, lr, pc} ^
 *   @0x2ec82c .word 0xf7ff4620
 *   @0x2ec830 movwhs pc, #0x19d4
 *   @0x2ec834 eorlo pc, r0, r4, lsl #17
 *   @0x2ec838 ldrhtlo pc, [r10], -r7
 *   @0x2ec83c ldrhhs pc, [r6], -r7
 *   @0x2ec840 ldmdavs r11!, {r1, r3, r4, r10, lr} ^
 *   @0x2ec844 addsmi r3, r10, #268435456
 *   @0x2ec848 rschi pc, r7, r0, lsl #4
 *   @0x2ec84c ldrhtlo pc, [r8], -r7
 *   @0x2ec850 ldrhhs pc, [r4], -r7
 *   @0x2ec854 ldmvs r11!, {r1, r3, r4, r10, lr}
 *   @0x2ec858 addsmi r3, r10, #268435456
 *   @0x2ec85c sbcshi pc, sp, r0, lsl #4
 *   @0x2ec860 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2ec864 blx 0xff96a86a <b2_toiTime+0xffffffffff2113c6>
 *   @0x2ec868 blls 0x4d088c <SrcVerts+0x2d8d0>
 *   @0x2ec86c .word 0xf0402b00
 *   @0x2ec870 blls 0x48ccec <prim_v+0x3338>
 *   @0x2ec874 adcmi r1, r10, #23040
 *   @0x2ec878 tsthi r6, r0, lsl #4
 *   @0x2ec87c .word 0xf8939206
 *   @0x2ec880 .word 0xf00ee000
 *   @0x2ec884 b 0x16ad4c8 <b2_toiTime+0xf54024>
 *   @0x2ec888 sadd16mi r1, r10, lr
 *   @0x2ec88c svceq #0x7f1be
 *   @0x2ec890 ldm pc, {r0, r1, r2, r3, r5, r11, r12, lr, pc} ^
 *   @0x2ec894 andne pc, r4, lr
 *   @0x2ec898 andsne r1, r0, r7, lsl #12
 *   @0x2ec89c strhs r2, [r0, -r6, lsr #20]
 *   @0x2ec8a0 and r4, r9, r10, lsr r6
 *   @0x2ec8a4 .word 0xf080454b
 *   @0x2ec8a8 stmvs r2!, {r0, r1, r2, r3, r4, r5, r6, r7, pc}
 *   @0x2ec8ac eorlo pc, r3, r2, asr r8
 *   @0x2ec8b0 blls 0x6d14d8 <g_SWFlinevertbuff+0x7e410>
 *   @0x2ec8b4 strhs lr, [r1, -sp]
 *   @0x2ec8b8 movweq pc, #0x8106
 *   @0x2ec8bc .word 0x0c00f04f
 *   @0x2ec8c0 ldrbmi lr, [r3, #-0x55]
 *   @0x2ec8c4 rscshi pc, r0, r0, lsl #1
 *   @0x2ec8c8 andls r9, r8, #57344
 *   @0x2ec8cc .word 0xf85268e2
 *   @0x2ec8d0 movwls r3, #0x9023
 *   @0x2ec8d4 ldm r6, {r9, sp}
 *   @0x2ec8d8 ldrmi r0, [r7], -r3
 *   @0x2ec8dc andeq lr, r3, r8, lsl #17
 *   @0x2ec8e0 strhs lr, [r3, -r10, ror #15]
 *   @0x2ec8e4 addlo pc, lr, #64, #12
 *   @0x2ec8e8 strhs lr, [r3, -r6, ror #15]
 *   @0x2ec8ec eorvs pc, r11, #64, #12
 *   @0x2ec8f0 strhs lr, [r4, -r2, ror #15]
 *   @0x2ec8f4 .word 0xf002e7e0
 *   @0x2ec8f8 stmdbhs r1, {r0, r1, r8}
 *   @0x2ec8fc eorsle sp, r9, #61
 *   @0x2ec900 mcrrne p9, #0x0, r9, r8, c6
 *   @0x2ec904 vhsub.s8 d4, d16, d24
 *   @0x2ec908 andls r8, r6, pc, asr #1
 *   @0x2ec90c strbmi r7, [r9, #-0x809]
 *   @0x2ec910 sbchi pc, r10, r0, lsl #1
 *   @0x2ec914 .word 0xf85068a0
 *   @0x2ec918 .word 0xf8431021
 *   @0x2ec91c .word 0xf3c21c08
 *   @0x2ec920 stmdbhs r1, {r0, r7, r8}
 *   @0x2ec924 suble sp, r1, #69
 *   @0x2ec928 mcrrne p9, #0x0, r9, r8, c6
 *   @0x2ec92c vhsub.s8 d4, d16, d24
 *   @0x2ec930 strhls r8, [r6], -r11
 *   @0x2ec934 ldrbmi r7, [r1, #-0x809]
 *   @0x2ec938 adcshi pc, r6, r0, lsl #1
 *   @0x2ec93c .word 0xf85068e0
 *   @0x2ec940 .word 0xf8431021
 *   @0x2ec944 .word 0xf1bc1c04
 *   @0x2ec948 .word 0xd1490f00
 *   @0x2ec94c .word 0xd1472f04
 *   @0x2ec950 .word 0x1c519a06
 *   @0x2ec954 vhsub.s8 d4, d16, d25
 *   @0x2ec958 smlatbls r6, r7, r0, r8
 *   @0x2ec95c ldmdavc r2, {r0, r1, r8, r9, r10, sp}
 *   @0x2ec960 andeq lr, r3, r3, lsl r9
 *   @0x2ec964 .word 0x0c01f10c
 *   @0x2ec968 stm r8, {r3, r8, r9, r12, sp}
 *   @0x2ec96c ldrmi r0, [r12, #0x3]!
 *   @0x2ec970 eors sp, r7, r1, asr #7
 *   @0x2ec974 andle r2, r12, r2, lsl #18
 *   @0x2ec978 stmdbls r6, {r1, r2, r4, sp, lr, pc}
 *   @0x2ec97c adcmi r1, r8, #136, #24
 *   @0x2ec980 addshi pc, r2, r0, lsl #4
 *   @0x2ec984 stmdavc r8, {r1, r2, r12, pc}
 *   @0x2ec988 b 0x134aab4 <b2_toiTime+0xbf1610>
 *   @0x2ec98c andlt r2, r9, #0, #2
 *   @0x2ec990 stmdbls r6, {r0, r1, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ec994 adcmi r1, r8, #72, #24
 *   @0x2ec998 addhi pc, r6, r0, lsl #4
 *   @0x2ec99c .word 0xf9919006
 *   @0x2ec9a0 .word 0x990e0000
 *   @0x2ec9a4 ldr r4, [r8, r1, lsl #8]!
 *   @0x2ec9a8 ldr r9, [r6, lr, lsl #18]!
 *   @0x2ec9ac andle r2, r11, r2, lsl #18
 *   @0x2ec9b0 stmdbls r6, {r2, r4, sp, lr, pc}
 *   @0x2ec9b4 adcmi r1, r8, #136, #24
 *   @0x2ec9b8 andls sp, r6, r6, ror r8
 *   @0x2ec9bc stmdavc r9, {r3, r11, r12, sp, lr} ^
 *   @0x2ec9c0 .word 0x2100ea41
 *   @0x2ec9c4 ldr r11, [r12, r9, lsl #4]!
 *   @0x2ec9c8 mcrrne p9, #0x0, r9, r8, c6
 *   @0x2ec9cc stmdale r11!, {r3, r5, r7, r9, lr} ^
 *   @0x2ec9d0 .word 0xf9919006
 *   @0x2ec9d4 .word 0x990f0000
 *   @0x2ec9d8 ldr r4, [r2, r1, lsl #8]!
 *   @0x2ec9dc ldr r9, [r0, pc, lsl #18]!
 *   @0x2ec9e0 .word 0xe7bd0912
 *   @0x2ec9e4 svceq #0x5f1be
 *   @0x2ec9e8 .word 0xa102d820
 *   @0x2ec9ec eorhs pc, lr, r1, asr r8
 *   @0x2ec9f0 smladmi r8, r1, r4, r4
 *   @0x2ec9f4 andeq r0, r0, r9, lsl r0
 *   @0x2ec9f8 .word 0xfffffe6d
 *   @0x2ec9fc .word 0xfffffe6d
 *   @0x2eca00 .word 0xfffffe6d
 *   @0x2eca04 .word 0xfffffe37
 *   @0x2eca08 .word 0xfffffe37
 *   @0x2eca0c .word 0xf7ff4620
 *   @0x2eca10 stmibvs r0!, {r2, r5, r6, r7, r11, r12, sp, lr, pc} ^
 *   @0x2eca14 ldc2l p7, c15, [r0], #-992
 *   @0x2eca18 .word 0x2101e048
 *   @0x2eca1c .word 0x460a4638
 *   @0x2eca20 blx 0x1f6aa16 <b2_toiTime+0x1811572>
 *   @0x2eca24 .word 0xf47f2800
 *   @0x2eca28 .word 0xe719af1f
 *   @0x2eca2c mlalo r0, r4, r8, pc
 *   @0x2eca30 blhs 0x3071d4 <TT_New_Context+0x6fcc>
 *   @0x2eca34 rfeib r7!
 *   @0x2eca38 rfeib r7!
 *   @0x2eca3c ldrmi r2, [r10], #-22
 *   @0x2eca40 andlo r6, r3, #8060928
 *   @0x2eca44 stmdale r4!, {r1, r3, r4, r7, r9, lr}
 *   @0x2eca48 ldrhths pc, [r10], -r7
 *   @0x2eca4c ldm r6, {r0, r1, r3, r4, r5, r6, r7, r8, r9, r11, sp, lr}
 *   @0x2eca50 bl 0x3aca64 <error_g0017+0x5708>
 *   @0x2eca54 .word 0xf8d703c2
 *   @0x2eca58 .word 0xf103c040
 *   @0x2eca5c stm r3, {r3, r8, r9, r11}
 *   @0x2eca60 stmdbge r10, {r0, r1}
 *   @0x2eca64 vmlaeq.f64 d14, d2, d12
 *   @0x2eca68 stmdbgt r3, {r4, r8, r9, r12, sp}
 *   @0x2eca6c andeq lr, r3, r11, lsl #17
 *   @0x2eca70 stmdbgt r3, {r2, r3, r8, r11, sp, pc}
 *   @0x2eca74 andeq lr, r3, r3, lsl #17
 *   @0x2eca78 .word 0xf80c2302
 *   @0x2eca7c andhs r3, r0, r2
 *   @0x2eca80 andlo pc, r1, lr, lsl #17
 *   @0x2eca84 .word 0xf88e2301
 *   @0x2eca88 svchi #0x7b3002
 *   @0x2eca8c ldrbhi r3, [r11, -r3, lsl #6]!
 *   @0x2eca90 ldrtmi lr, [r8], -r10, ror #13
 *   @0x2eca94 andhs r2, r0, #-1073741824
 *   @0x2eca98 blx 0x106aa8e <b2_toiTime+0x9115ea>
 *   @0x2eca9c .word 0xf47f2800
 *   @0x2ecaa0 ldrb r10, [r1, r3, ror #29]
 *   @0x2ecaa4 ldrb r2, [pc], r8
 *   @0x2ecaa8 movwls r2, #0x7308
 *   @0x2ecaac cdpls p8, #0x0, c9, c7, c2, #0x0
 *   @0x2ecab0 blx 0x3aaaa4 <error_g0017+0x3748>
 *   @0x2ecab4 strmi lr, [r6], -r0
 *   @0x2ecab8 andslt r4, r1, r0, lsr r6
 *   @0x2ecabc svchi #0xf0e8bd
 *   @0x2ecac0 svcmi #0xf0e92d
 *   @0x2ecac4 .word 0x4604b091
 *   @0x2ecac8 .word 0x91066847
 *   @0x2ecacc andls r9, r8, #603979776
 *   @0x2ecad0 blo 0x358f00
 *   @0x2ecad4 stmdblt pc, {r3, r9, r12, pc}
 *   @0x2ecad8 orrs r2, r10, #6291456
 *   @0x2ecadc ldrsblo pc, [r8, r7]
 *   @0x2ecae0 addsmi r9, lr, #8, #28
 *   @0x2ecae4 mcrls p2, #0x0, sp, c9, c8, #0x7
 *   @0x2ecae8 andeq pc, r9, #22
 *   @0x2ecaec .word 0x81bef040
 *   @0x2ecaf0 .word 0xf8d76ebb
 *   @0x2ecaf4 .word 0xf8d781a0
 *   @0x2ecaf8 movwls r0, #0x517c
 *   @0x2ecafc .word 0x3184f8d7
 *   @0x2ecb00 .word 0xf1034282
 *   @0x2ecb04 .word 0xf1a30324
 *   @0x2ecb08 .word 0xf0000524
 *   @0x2ecb0c stmdbls r6, {r0, r1, r2, r3, r5, r7, r8, pc}
 *   @0x2ecb10 .word 0xf853898e
 *   @0x2ecb14 adcsmi r1, r1, #36, #24
 *   @0x2ecb18 stmdbls r6, {r0, r2, r8, r12, lr, pc}
 *   @0x2ecb1c .word 0xf85389ce
 *   @0x2ecb20 adcsmi r1, r1, #32, #24
 *   @0x2ecb24 andlo sp, r1, #1
 *   @0x2ecb28 stmvs r11!, {r1, r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ecb2c ldrsbne pc, [r0, r7]!
 *   @0x2ecb30 svceq #0x1f013
 *   @0x2ecb34 svclt #0x149805
 *   @0x2ecb38 strhs r2, [r4], -r5, lsl #12
 *   @0x2ecb3c stmibvs r10!, {r1, r3, r4, r7, r8, r9, r10}
 *   @0x2ecb40 strlo r11, [r1], -r8, asr #30
 *   @0x2ecb44 ldrmi r0, [r1], #-1883
 *   @0x2ecb48 strlo r11, [r1], -r8, asr #30
 *   @0x2ecb4c mcr2 p7, #0x5, pc, c11, c9, #0x7
 *   @0x2ecb50 .word 0xf0402800
 *   @0x2ecb54 stmibvs r9!, {r0, r1, r3, r7, r8, pc} ^
 *   @0x2ecb58 cmnmi r1, #327680
 *   @0x2ecb5c .word 0xf961f7fb
 *   @0x2ecb60 .word 0xf0402800
 *   @0x2ecb64 cdpls p1, #0x0, c8, c8, c3, #0x4
 *   @0x2ecb68 ldrsb pc, [r12], -r5
 *   @0x2ecb6c bl 0x4ed040 <SrcVerts+0x4a084>
 *   @0x2ecb70 strls r0, [r10], -r3, lsl #12
 *   @0x2ecb74 andlo pc, r3, r8, asr r8
 *   @0x2ecb78 movwls r9, #0x7e05
 *   @0x2ecb7c bvs 0xf06e30 <b2_toiTime+0x7ad98c>
 *   @0x2ecb80 .word 0x0c01f013
 *   @0x2ecb84 svclt #0x146a71
 *   @0x2ecb88 andhs r2, r4, #1342177280
 *   @0x2ecb8c svclt #0x48079e
 *   @0x2ecb90 ldrbeq r3, [lr, -r1, lsl #4]
 *   @0x2ecb94 andlo r11, r1, #72, #30
 *   @0x2ecb98 strtle r0, [r6], #-1630
 *   @0x2ecb9c stmeq r0, {r0, r1, r6, r12, sp, lr, pc}
 *   @0x2ecba0 andhi pc, r8, r5, asr #17
 *   @0x2ecba4 stmdaeq r2, {r1, r2, r3, r8, r9, r11, r12, sp, lr, pc}
 *   @0x2ecba8 stmdale r3, {r3, r7, r8, r10, lr}
 *   @0x2ecbac .word 0xf04f4601
 *   @0x2ecbb0 ldrsh r3, [r0], -pc
 *   @0x2ecbb4 orreq pc, r0, #35
 *   @0x2ecbb8 ands r6, r2, r11, lsr #1
 *   @0x2ecbbc svceq #0xf1bc
 *   @0x2ecbc0 .word 0xf891d00c
 *   @0x2ecbc4 .word 0xf891b000
 *   @0x2ecbc8 b 0x1594bd4 <b2_toiTime+0xe3b730>
 *   @0x2ecbcc strbmi r2, [r10, #0xa0b]
 *   @0x2ecbd0 ldrmi sp, [r1], #-3568
 *   @0x2ecbd4 strbmi r4, [r1, #-0x6d1]
 *   @0x2ecbd8 strd sp, lr, [r2], -r0
 *   @0x2ecbdc mulge r0, r1, r8
 *   @0x2ecbe0 stmvs r11!, {r0, r2, r4, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ecbe4 movteq pc, #0x43
 *   @0x2ecbe8 stmvs sp!, {r0, r1, r3, r5, r7, sp, lr}
 *   @0x2ecbec stmibeq r0, {r0, r2, r4, r12, sp, lr, pc}
 *   @0x2ecbf0 .word 0x2100d040
 *   @0x2ecbf4 eorle r4, r0, #473956352
 *   @0x2ecbf8 stmdaeq r1, {r1, r2, r3, r8, r9, r11, sp, lr, pc}
 *   @0x2ecbfc ldmdaeq r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0x2ecc00 .word 0xf908fb02
 *   @0x2ecc04 beq 0x56780c <g_SWFlineaavertbuff+0x14744>
 *   @0x2ecc08 svceq #0xf1bc
 *   @0x2ecc0c .word 0xf810d008
 *   @0x2ecc10 .word 0xf10a9009
 *   @0x2ecc14 .word 0xf89a0302
 *   @0x2ecc18 b 0x1594c24 <b2_toiTime+0xe3b780>
 *   @0x2ecc1c and r2, r3, r9, lsl #18
 *   @0x2ecc20 andls pc, r9, r0, lsl r8
 *   @0x2ecc24 movweq pc, #0x110a
 *   @0x2ecc28 strbmi r9, [lr, #-0xe07]
 *   @0x2ecc2c strbmi sp, [r6], r1, lsl #4
 *   @0x2ecc30 stmdble r5, {r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ecc34 mrseq pc, apsr
 *   @0x2ecc38 .word 0xf04fe7dc
 *   @0x2ecc3c ands r0, r9, r0, lsl #18
 *   @0x2ecc40 strle r0, [r6, #-0x7ae]
 *   @0x2ecc44 mulls r0, r3, r8
 *   @0x2ecc48 ldmdavc r11, {r1, r3, r4, r7, r10, r11, r12} ^
 *   @0x2ecc4c stmdbhs r9, {r0, r1, r6, r9, r11, sp, lr, pc}
 *   @0x2ecc50 .word 0xf893e002
 *   @0x2ecc54 mrrcne p0, #0x0, r9, r10, c0
 *   @0x2ecc58 svceq #0x4f015
 *   @0x2ecc5c ldmdavc r5, {r0, r1, r4, r6, r11, r12, sp, lr}
 *   @0x2ecc60 andseq sp, r11, #5
 *   @0x2ecc64 b 0x13caeb4 <b2_toiTime+0xc71a10>
 *   @0x2ecc68 tstmi r5, #20971520
 *   @0x2ecc6c b 0x13e4c80 <b2_toiTime+0xc8b7dc>
 *   @0x2ecc70 and r2, r0, r5, lsl #10
 *   @0x2ecc74 stmdals r5, {r0, r2, r3, r6, r9, r10, lr}
 *   @0x2ecc78 .word 0xf91ef7fb
 *   @0x2ecc7c svceq #0xf1b9
 *   @0x2ecc80 rscshi pc, r4, r0
 *   @0x2ecc84 ldrsbhs pc, [r0, -r7]!
 *   @0x2ecc88 .word 0x112cf8d7
 *   @0x2ecc8c addmi r9, r10, #10240
 *   @0x2ecc90 andle r6, r1, r8, asr r8
 *   @0x2ecc94 .word 0xf852f7f8
 *   @0x2ecc98 movvs r9, #6, #28
 *   @0x2ecc9c ldmibhi r0!, {r1, r3, r8, r9, r11, r12, pc}
 *   @0x2ecca0 ldrsbhs pc, [r0, -r7]!
 *   @0x2ecca4 andeq r6, r0, #5832704
 *   @0x2ecca8 .word 0xf848f7f8
 *   @0x2eccac ldrsbtne pc, [r12], r7
 *   @0x2eccb0 strmi r4, [r2], r9, lsr #8
 *   @0x2eccb4 .word 0xf7f99805
 *   @0x2eccb8 stmdahs r0, {r1, r2, r4, r5, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2eccbc sbcshi pc, r6, r0, asr #32
 *   @0x2eccc0 strbmi r9, [r9], -r5, lsl #16
 *   @0x2eccc4 .word 0xf8adf7fb
 *   @0x2eccc8 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2ecccc sbchi pc, lr, r0, asr #32
 *   @0x2eccd0 bvs 0x3d2cec <error_g0017+0x2b990>
 *   @0x2eccd4 .word 0x1c596a42
 *   @0x2eccd8 .word 0xf0c0428a
 *   @0x2eccdc .word 0xf89380c0
 *   @0x2ecce0 .word 0xf0088000
 *   @0x2ecce4 stmdbhs r2, {r0, r1, r8}
 *   @0x2ecce8 stmdbhs r3, {r1, r2, r4, r12, lr, pc}
 *   @0x2eccec stmdbhs r1, {r0, r2, r5, r12, lr, pc}
 *   @0x2eccf0 ldcne p0, c13, [sp], {9}
 *   @0x2eccf4 vqsub.s8 d4, d16, d5
 *   @0x2eccf8 ldmdavc r8, {r1, r4, r5, r7, pc} ^
 *   @0x2eccfc cdpne p3, #0x0, c15, c3, c0, #0x2
 *   @0x2ecd00 andeq pc, r3, r0, asr #6
 *   @0x2ecd04 ldclne p0, c14, [sp], {46}
 *   @0x2ecd08 vqsub.s8 d4, d16, d5
 *   @0x2ecd0c .word 0xf99380a8
 *   @0x2ecd10 .word 0xf993e001
 *   @0x2ecd14 eor r0, r5, r2
 *   @0x2ecd18 addsmi r1, r5, #5952
 *   @0x2ecd1c addshi pc, pc, r0, lsl #4
 *   @0x2ecd20 mul r1, r3, r8
 *   @0x2ecd24 ldmdbvc r8, {r0, r3, r4, r7, r11, r12, sp, lr}
 *   @0x2ecd28 vmlshs.f32 s28, s28, s2
 *   @0x2ecd2c blx 0x6cb098 <g_SWFlinevertbuff+0x77fd0>
 *   @0x2ecd30 b 0x132c770 <b2_toiTime+0xbd32cc>
 *   @0x2ecd34 andlt r2, r0, #1
 *   @0x2ecd38 ldclne p0, c14, [sp, #80]
 *   @0x2ecd3c vqsub.s8 d4, d16, d5
 *   @0x2ecd40 .word 0xf893808e
 *   @0x2ecd44 ldmdavc r9, {r1, sp, lr, pc} ^
 *   @0x2ecd48 b 0x16cb2b0 <b2_toiTime+0xf71e0c>
 *   @0x2ecd4c b 0x167858c <b2_toiTime+0xf1f0e8>
 *   @0x2ecd50 ldmvc r9, {r0, r9, r10, r11, lr} ^
 *   @0x2ecd54 b 0x166d55c <b2_toiTime+0xf140b8>
 *   @0x2ecd58 ldmdbvc r9, {r0, r9, r10, r11}
 *   @0x2ecd5c b 0x130b3d0 <b2_toiTime+0xbb1f2c>
 *   @0x2ecd60 tstmi r8, #1
 *   @0x2ecd64 ldmeq r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2ecd68 movweq pc, #0x3008
 *   @0x2ecd6c andle r2, r12, r2, lsl #22
 *   @0x2ecd70 andsle r2, r1, r3, lsl #22
 *   @0x2ecd74 tstle sp, r1, lsl #22
 *   @0x2ecd78 .word 0x0c01f105
 *   @0x2ecd7c stmdale lr!, {r2, r4, r7, r8, r10, lr} ^
 *   @0x2ecd80 ldmdbeq r9, {r0, r1, r3, r5, r11, r12, sp, lr}
 *   @0x2ecd84 movweq pc, #0xf003
 *   @0x2ecd88 .word 0xf105e012
 *   @0x2ecd8c strbmi r0, [r2, #-0xc02]!
 *   @0x2ecd90 stmdavc r9!, {r0, r2, r5, r6, r8, r9, r12, lr, pc}
 *   @0x2ecd94 and r7, r11, r11, ror #16
 *   @0x2ecd98 .word 0x0c04f105
 *   @0x2ecd9c cmple lr, #411041792
 *   @0x2ecda0 stmdavc r11!, {r0, r3, r5, r11, r12, sp, lr} ^
 *   @0x2ecda4 .word 0x2101ea43
 *   @0x2ecda8 stmvc sp!, {r0, r1, r3, r5, r7, r11, r12, sp, lr} ^
 *   @0x2ecdac movwhs lr, #0x3a45
 *   @0x2ecdb0 and r4, r1, r5, ror #12
 *   @0x2ecdb4 ldrmi r2, [r9], -r0, lsl #6
 *   @0x2ecdb8 ldmeq r8, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2ecdbc .word 0x0c03f008
 *   @0x2ecdc0 svceq #0x2f1bc
 *   @0x2ecdc4 .word 0xf1bcd00e
 *   @0x2ecdc8 andsle r0, r7, r3, lsl #30
 *   @0x2ecdcc svceq #0x1f1bc
 *   @0x2ecdd0 .word 0xf105d123
 *   @0x2ecdd4 ldrmi r0, [r4, #0xc01]
 *   @0x2ecdd8 .word 0xf995d841
 *   @0x2ecddc b 0x16d4de4 <b2_toiTime+0xf7b940>
 *   @0x2ecde0 ands r2, r9, r10, lsl #20
 *   @0x2ecde4 .word 0x0c02f105
 *   @0x2ecde8 ldmdale r8!, {r2, r4, r7, r8, r10, lr}
 *   @0x2ecdec .word 0xf895782a
 *   @0x2ecdf0 b 0x1594dfc <b2_toiTime+0xe3b958>
 *   @0x2ecdf4 blx 0x6b7604 <g_SWFlinevertbuff+0x6453c>
 *   @0x2ecdf8 and pc, sp, r10, lsl #21
 *   @0x2ecdfc .word 0x0c03f105
 *   @0x2ece00 stmdale r12!, {r2, r4, r7, r8, r10, lr}
 *   @0x2ece04 mulge r1, r5, r8
 *   @0x2ece08 b 0x16caeb8 <b2_toiTime+0xf71a14>
 *   @0x2ece0c b 0x157763c <b2_toiTime+0xe1e198>
 *   @0x2ece10 stmvc r10!, {r1, r9, r11, lr}
 *   @0x2ece14 beq 0x3a7744 <error_g0017+0x3e8>
 *   @0x2ece18 b 0x16be7b4 <b2_toiTime+0xf65310>
 *   @0x2ece1c .word 0xf1b80898
 *   @0x2ece20 andsle r0, r3, r1, lsl #30
 *   @0x2ece24 .word 0xf1b8d30b
 *   @0x2ece28 tstle r8, r2, lsl #30
 *   @0x2ece2c stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2ece30 ldcleq p0, c15, [pc], #316
 *   @0x2ece34 .word 0xf203fb01
 *   @0x2ece38 ldmdbeq r9, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc} ^
 *   @0x2ece3c blx 0x364e6e <_ZTS12CDS_Priority+0x6ec6>
 *   @0x2ece40 andlo pc, r7, #805306368
 *   @0x2ece44 svceq #0xd2ebb9
 *   @0x2ece48 adc sp, r7, r9, lsl #6
 *   @0x2ece4c .word 0xf203fb01
 *   @0x2ece50 .word 0x0c0ff04f
 *   @0x2ece54 .word 0xf909fb0c
 *   @0x2ece58 vrshl.s8 q10, q5, q0
 *   @0x2ece5c .word 0x2608809f
 *   @0x2ece60 .word 0xf7fb9805
 *   @0x2ece64 cdphs p8, #0x0, c15, c0, c9, #0x1
 *   @0x2ece68 bicshi pc, r3, r0
 *   @0x2ece6c .word 0xf4169e09
 *   @0x2ece70 .word 0xf47f4580
 *   @0x2ece74 mcrls p14, #0x0, r10, c8, c1, #0x1
 *   @0x2ece78 .word 0x31a0f8d7
 *   @0x2ece7c rsbpl pc, lr, r4, lsr #17
 *   @0x2ece80 stmdane r6, {r0, r1, r8, r9, r11, sp, lr, pc}
 *   @0x2ece84 .word 0xf8a44bae
 *   @0x2ece88 .word 0xf8d4506c
 *   @0x2ece8c strtvs r0, [r3], #188
 *   @0x2ece90 ldrsbtls pc, [r12], r7
 *   @0x2ece94 .word 0x600cf8d8
 *   @0x2ece98 .word 0xa068f8d7
 *   @0x2ece9c .word 0xb008f8d8
 *   @0x2ecea0 blx 0x62ae88 <g_SWFaavertbuff+0x57dc0>
 *   @0x2ecea4 .word 0xf8c44633
 *   @0x2ecea8 .word 0xf10450b0
 *   @0x2eceac ldrbmi r0, [r1], -r0, lsr #1
 *   @0x2eceb0 andlt pc, r0, sp, asr #17
 *   @0x2eceb4 .word 0xf7ff464a
 *   @0x2eceb8 .word 0x4606fa99
 *   @0x2ecebc .word 0xf0402800
 *   @0x2ecec0 .word 0xf8d481a8
 *   @0x2ecec4 .word 0xf10450bc
 *   @0x2ecec8 stmdals r9, {r2, r3, r5, r6, r9, r10, r11}
 *   @0x2ececc beq 0x1e292e4 <b2_toiTime+0x16cfe40>
 *   @0x2eced0 .word 0xf0003514
 *   @0x2eced4 stcgt p9, c0, [pc, #-4]
 *   @0x2eced8 andeq lr, pc, lr, lsr #17
 *   @0x2ecedc stmdbls r6, {r0, r1, r3, r5, r11, sp, lr}
 *   @0x2ecee0 movweq pc, #0x1023
 *   @0x2ecee4 andeq pc, r4, #67
 *   @0x2ecee8 smulwtlt r9, r2, r7
 *   @0x2eceec bhs 0x8cf61c <b2_toiTime+0x176178>
 *   @0x2ecef0 .word 0xf443bf9c
 *   @0x2ecef4 strbvs r7, [r3, r2, lsl #7]!
 *   @0x2ecef8 adcvs r2, r3, #0, #6
 *   @0x2ecefc .word 0xf8d76363
 *   @0x2ecf00 .word 0xf8d72130
 *   @0x2ecf04 .word 0xf8d8112c
 *   @0x2ecf08 addmi r0, r10, #4
 *   @0x2ecf0c .word 0xf7f7d001
 *   @0x2ecf10 .word 0xf8d7ff15
 *   @0x2ecf14 ldrbeq r3, [sp, r4, asr #2]
 *   @0x2ecf18 adcvs r11, r0, #88, #30
 *   @0x2ecf1c svclt #0x486aa3
 *   @0x2ecf20 .word 0x63a36360
 *   @0x2ecf24 .word 0x63e36b63
 *   @0x2ecf28 rscvs r2, r3, #0, #6
 *   @0x2ecf2c .word 0xf1b96323
 *   @0x2ecf30 .word 0xd1240f00
 *   @0x2ecf34 svcvs #0x259a06
 *   @0x2ecf38 ldrsbhi pc, [r0], -r2
 *   @0x2ecf3c rfeib r4!
 *   @0x2ecf40 strlo r3, [r8, #-0x6e]
 *   @0x2ecf44 ble 0x6fe5b0 <g_SWFvertbuff+0x2b4e8>
 *   @0x2ecf48 .word 0xf8554641
 *   @0x2ecf4c .word 0xf7fe0c08
 *   @0x2ecf50 ldrtmi pc, [r9], -r0, lsl #29
 *   @0x2ecf54 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2ecf58 .word 0x0c08f845
 *   @0x2ecf5c .word 0x0c04f855
 *   @0x2ecf60 mrc2 p7, #0x3, apsr_nzcv, c7, c14, #0x7
 *   @0x2ecf64 .word 0x0c04f845
 *   @0x2ecf68 strbmi lr, [r1], -r9, ror #15
 *   @0x2ecf6c .word 0xf7fe6aa0
 *   @0x2ecf70 shsub16mi pc, r9, r0
 *   @0x2ecf74 blvs 0x1b059fc <b2_toiTime+0x13ac558>
 *   @0x2ecf78 mcr2 p7, #0x3, pc, c11, c14, #0x7
 *   @0x2ecf7c stmdbge r12, {r5, r6, r8, r9, sp, lr}
 *   @0x2ecf80 .word 0xf7f94650
 *   @0x2ecf84 bls 0x62b818 <g_SWFaavertbuff+0x58750>
 *   @0x2ecf88 stmdbls pc, {r1, r2, r3, r8, r9, r11, r12, pc}
 *   @0x2ecf8c .word 0x61a31a9b
 *   @0x2ecf90 eorvs r9, r2, #13312
 *   @0x2ecf94 mvnvs r1, r9, asr #21
 *   @0x2ecf98 teq r10, r3, ror #4
 *   @0x2ecf9c b 0x16bf948 <b2_toiTime+0xf664a4>
 *   @0x2ecfa0 strvs r0, [r1, #-0xaaa]!
 *   @0x2ecfa4 beq 0xb293d4 <b2_toiTime+0x3cff30>
 *   @0x2ecfa8 .word 0x0c01f04f
 *   @0x2ecfac strtvs r6, [r2], #1251
 *   @0x2ecfb0 orreq r1, r9, r10, asr #27
 *   @0x2ecfb4 submi r6, r9, #1073741864
 *   @0x2ecfb8 subsgt pc, lr, r4, lsl #17
 *   @0x2ecfbc b 0x16b130c <b2_toiTime+0xf57e68>
 *   @0x2ecfc0 subne r1, r9, r3, lsl #25
 *   @0x2ecfc4 smlatths r0, r1, r2, r6
 *   @0x2ecfc8 stmdbls r6, {r0, r5, r8, r9, sp, lr}
 *   @0x2ecfcc beq 0x12e907c <b2_toiTime+0xb8fbd8>
 *   @0x2ecfd0 andsgt pc, r12, r4, asr #17
 *   @0x2ecfd4 vstmiane lr, {s28, s29, s30, s31}
 *   @0x2ecfd8 .word 0xf8c46562
 *   @0x2ecfdc b 0x16dd064 <b2_toiTime+0xf83bc0>
 *   @0x2ecfe0 .word 0xf8c41c80
 *   @0x2ecfe4 ldrmi r10, [r8], #-40
 *   @0x2ecfe8 eorgt pc, r4, r4, asr #17
 *   @0x2ecfec strtvs r6, [r0], r9, lsl #20
 *   @0x2ecff0 .word 0x63619809
 *   @0x2ecff4 .word 0xf8c40241
 *   @0x2ecff8 .word 0xf53fe064
 *   @0x2ecffc qasxmi r10, r0, r1
 *   @0x2ed000 .word 0xf102fb03
 *   @0x2ed004 ldc2l p7, c15, [r4], #1000
 *   @0x2ed008 stmdahs r0, {r1, r2, r9, r10, lr}
 *   @0x2ed00c svcge #0x28f47f
 *   @0x2ed010 .word 0xf8d79905
 *   @0x2ed014 bvs 0x153935c <b2_toiTime+0xddfeb8>
 *   @0x2ed018 movweq pc, #0x2003
 *   @0x2ed01c .word 0xfe83fa5f
 *   @0x2ed020 stclvs p1, c9, [r1], #40
 *   @0x2ed024 .word 0xf43f2900
 *   @0x2ed028 stcvs p15, c10, [r2, #-108]!
 *   @0x2ed02c .word 0xf43f2a00
 *   @0x2ed030 stclvs p15, c10, [r0, #-92]!
 *   @0x2ed034 andls r6, r7, r3, lsr #27
 *   @0x2ed038 .word 0xf002fb01
 *   @0x2ed03c .word 0xf1be9004
 *   @0x2ed040 .word 0xd1050f00
 *   @0x2ed044 stmdbls r7, {r3, r6, r9, r10, r11, r12}
 *   @0x2ed048 movwlo pc, #0x1b00
 *   @0x2ed04c .word 0x91074249
 *   @0x2ed050 svceq #0x1f1b8
 *   @0x2ed054 tstle r6, #14
 *   @0x2ed058 svceq #0x2f1b8
 *   @0x2ed05c svcge #0xf47f
 *   @0x2ed060 .word 0xf04f2100
 *   @0x2ed064 ldrmi r0, [r11], r1, lsl #18
 *   @0x2ed068 .word 0xf04f4690
 *   @0x2ed06c strmi r0, [r12], r0, lsl #29
 *   @0x2ed070 adcs r4, r2, r10, asr #13
 *   @0x2ed074 bleq 0x3291b8
 *   @0x2ed078 ldrmi r9, [r2], r11, lsl #6
 *   @0x2ed07c ldrdhs r4, r5, [r0, lr]
 *   @0x2ed080 .word 0x46c146dc
 *   @0x2ed084 stmdals r10, {r0, r1, r2, r4, r6, sp, lr, pc}
 *   @0x2ed088 stmdbls r4, {r0, r3, r4, r7, r9, r10, lr}
 *   @0x2ed08c bl 0xff43ead4 <b2_toiTime+0xfffffffffece5630>
 *   @0x2ed090 addhs r0, r0, r0, lsl #28
 *   @0x2ed094 .word 0x0eceea4f
 *   @0x2ed098 svclt #0x28458e
 *   @0x2ed09c smlabbhs r0, lr, r6, r4
 *   @0x2ed0a0 beq 0x4e90e0 <SrcVerts+0x46124>
 *   @0x2ed0a4 .word 0xf1be468c
 *   @0x2ed0a8 eorle r0, r0, r0, lsl #30
 *   @0x2ed0ac bleq 0x4e90ec <SrcVerts+0x46130>
 *   @0x2ed0b0 svclt #0x445d3
 *   @0x2ed0b4 mulgt r0, r5, r8
 *   @0x2ed0b8 .word 0xf01c3501
 *   @0x2ed0bc svclt #0x180f80
 *   @0x2ed0c0 .word 0xf1b84301
 *   @0x2ed0c4 b 0x16af0d0 <b2_toiTime+0xf55c2c>
 *   @0x2ed0c8 b 0x16b0200 <b2_toiTime+0xf56d5c>
 *   @0x2ed0cc qaddle r0, r0, r6
 *   @0x2ed0d0 .word 0x46907019
 *   @0x2ed0d4 .word 0x21009b07
 *   @0x2ed0d8 ldrmi r4, [r9], r11, asr #8
 *   @0x2ed0dc ldmdblt r8, {r0, r1, sp, lr, pc}
 *   @0x2ed0e0 blne 0x36b0f4 <_ZTS13C_UTF16String+0x21a0>
 *   @0x2ed0e4 addhs r4, r0, r1, lsl #12
 *   @0x2ed0e8 cdplo p1, #0xf, c15, c15, c14, #0x0
 *   @0x2ed0ec stmhs r0, {r0, r1, r3, r4, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ed0f0 .word 0xf1b8e08b
 *   @0x2ed0f4 teqle r6, r0, lsl #30
 *   @0x2ed0f8 svceq #0xf1b9
 *   @0x2ed0fc .word 0xf1bad13c
 *   @0x2ed100 b 0x16af90c <b2_toiTime+0xf56468>
 *   @0x2ed104 teqle r10, r1, asr r1
 *   @0x2ed108 and pc, r0, r3, lsl #17
 *   @0x2ed10c blls 0x5beb5c <g_SWFlineaavertbuff+0x6ba94>
 *   @0x2ed110 cdpeq p0, #0x0, c15, c0, c15, #0x2
 *   @0x2ed114 strmi r9, [r11], #-2311
 *   @0x2ed118 orrhs r9, r0, r11, lsl #6
 *   @0x2ed11c ldcllo p1, c15, [pc], #48
 *   @0x2ed120 .word 0xf1bc9804
 *   @0x2ed124 .word 0xf1000f00
 *   @0x2ed128 strdls r3, r4, [r4], -pc
 *   @0x2ed12c .word 0xf04fbfcc
 *   @0x2ed130 .word 0xf04f0800
 *   @0x2ed134 stmdals r4, {r0, r11}
 *   @0x2ed138 bicsle r2, r10, r0, lsl #16
 *   @0x2ed13c svclt #0xe025
 *   @0x2ed140 svcvs #0x75746c
 *   @0x2ed144 rsbvs r7, r9, #1929379840
 *   @0x2ed148 addmi r9, r5, #655360
 *   @0x2ed14c .word 0xf895d212
 *   @0x2ed150 strlo r11, [r1, #-0x0]
 *   @0x2ed154 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2ed158 .word 0x1c2bea4f
 *   @0x2ed15c bleq 0x6e9190 <g_SWFvertbuff+0x160c8>
 *   @0x2ed160 svceq #0xf1bc
 *   @0x2ed164 .word 0xf1b9d1c8
 *   @0x2ed168 mvnle r0, r0, lsl #30
 *   @0x2ed16c .word 0xf04f46dc
 *   @0x2ed170 ldrb r0, [r5, r1, lsl #18]!
 *   @0x2ed174 stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2ed178 vmlseq.f32 s28, s2, s28
 *   @0x2ed17c stmdbhs r0, {r0, r1, r2, r3, r4, r5, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ed180 .word 0xf803d1cc
 *   @0x2ed184 strmi lr, [lr], r1, lsl #22
 *   @0x2ed188 stmibhs r0, {r0, r1, r2, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ed18c mcrge p4, #0x3, pc, c8, c15, #0x1
 *   @0x2ed190 and pc, r0, r3, lsl #17
 *   @0x2ed194 .word 0xf1b9e664
 *   @0x2ed198 .word 0xd1290f00
 *   @0x2ed19c svceq #0xf1ba
 *   @0x2ed1a0 b 0x13611ac <b2_toiTime+0xc07d08>
 *   @0x2ed1a4 .word 0xf1b8010e
 *   @0x2ed1a8 b 0x16af1b4 <b2_toiTime+0xf55d10>
 *   @0x2ed1ac qsuble r0, lr, r3
 *   @0x2ed1b0 .word 0x46907019
 *   @0x2ed1b4 .word 0x21009b07
 *   @0x2ed1b8 .word 0x469b445b
 *   @0x2ed1bc cdpeq p0, #0x8, c15, c0, c15, #0x2
 *   @0x2ed1c0 ldcllo p1, c15, [pc], #48
 *   @0x2ed1c4 .word 0xf1bc9804
 *   @0x2ed1c8 .word 0xf1000f00
 *   @0x2ed1cc strdls r3, r4, [r4], -pc
 *   @0x2ed1d0 .word 0xf04fbfcc
 *   @0x2ed1d4 .word 0xf04f0900
 *   @0x2ed1d8 stmdals r4, {r0, r8, r11}
 *   @0x2ed1dc bicsle r2, r10, r0, lsl #16
 *   @0x2ed1e0 .word 0xf815e011
 *   @0x2ed1e4 .word 0xf08acb01
 *   @0x2ed1e8 .word 0xf1bc0a01
 *   @0x2ed1ec bicsle r0, r5, r0, lsl #30
 *   @0x2ed1f0 addmi r9, r5, #655360
 *   @0x2ed1f4 .word 0xe7d1d3f5
 *   @0x2ed1f8 svceq #0xf1be
 *   @0x2ed1fc .word 0xf803d1e0
 *   @0x2ed200 ldrbtmi r1, [r1], -r1, lsl #22
 *   @0x2ed204 .word 0xf1bee7da
 *   @0x2ed208 .word 0xf43f0f80
 *   @0x2ed20c andsvc r10, r9, r9, lsr #28
 *   @0x2ed210 ldrtmi lr, [r0], -r6, lsr #12
 *   @0x2ed214 pop {r0, r4, r12, sp, pc}
 *   @0x2ed218 svclt #0x8ff0
 *   @0x2ed21c svcmi #0xf0e92d
 *   @0x2ed220 addslt r4, r1, r12, lsl #12
 *   @0x2ed224 strmi r2, [r5], -r0, lsl #2
 *   @0x2ed228 .word 0xf7f94617
 *   @0x2ed22c ldmdblt r8!, {r2, r3, r4, r5, r8, r9, r11, r12, sp, lr, pc} ^
 *   @0x2ed230 strtmi r4, [r8], -lr, lsr #19
 *   @0x2ed234 addeq pc, r4, #4, #2
 *   @0x2ed238 .word 0xf7fa4479
 *   @0x2ed23c ldmdblt r8!, {r0, r1, r3, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ed240 .word 0x20ccf8d4
 *   @0x2ed244 .word 0x30a8f8d4
 *   @0x2ed248 movwmi lr, #0x2b03
 *   @0x2ed24c adclo pc, r8, r4, asr #17
 *   @0x2ed250 bllt 0xfe911284 <b2_toiTime+0xfffffffffe1b7de0>
 *   @0x2ed254 .word 0x3084f8d4
 *   @0x2ed258 addsmi r4, r3, #667648
 *   @0x2ed25c .word 0xf8d4d132
 *   @0x2ed260 blhs 0x3f9488 <g_RomDisk+0x1c68>
 *   @0x2ed264 .word 0xf8d4d82e
 *   @0x2ed268 blhs 0x11394b0 <b2_toiTime+0x9e000c>
 *   @0x2ed26c .word 0xf8d4d92a
 *   @0x2ed270 .word 0xf640308c
 *   @0x2ed274 addsmi r5, r3, #-1610612736
 *   @0x2ed278 .word 0xf8d4d124
 *   @0x2ed27c qadd8mi r6, r8, r8
 *   @0x2ed280 .word 0xf7f94631
 *   @0x2ed284 andls pc, sp, r0, lsl r11
 *   @0x2ed288 strtmi r11, [r8], -r8, lsl #22
 *   @0x2ed28c .word 0xf7f9a90d
 *   @0x2ed290 blls 0x66c37c <g_SWFlinevertbuff+0x192b4>
 *   @0x2ed294 .word 0xf243b9db
 *   @0x2ed298 addsmi r3, r8, #-939524096
 *   @0x2ed29c andhs sp, r5, #1376256
 *   @0x2ed2a0 movtmi r6, #0x286b
 *   @0x2ed2a4 andlo r1, r2, #161792
 *   @0x2ed2a8 andle r4, lr, #536870923
 *   @0x2ed2ac movtmi r2, #0x2217
 *   @0x2ed2b0 addsmi r3, r10, #-268435451
 *   @0x2ed2b4 blls 0x661ae0 <g_SWFlinevertbuff+0xea18>
 *   @0x2ed2b8 cmplt r3, r11, lsl #6
 *   @0x2ed2bc andslt r9, r1, r11, lsl #16
 *   @0x2ed2c0 svchi #0xf0e8bd
 *   @0x2ed2c4 movwls r2, #0xb302
 *   @0x2ed2c8 movwhs lr, #0x87f8
 *   @0x2ed2cc andhs r9, r0, sp, lsl #6
 *   @0x2ed2d0 svchs #0xe7f1
 *   @0x2ed2d4 blle 0xfff4535c <b2_toiTime+0xffffffffff7ebeb8>
 *   @0x2ed2d8 .word 0x9706b2bf
 *   @0x2ed2dc blle 0x33dd00
 *   @0x2ed2e0 ldrb r2, [r0, r6, lsl #6]!
 *   @0x2ed2e4 .word 0xf8d44628
 *   @0x2ed2e8 .word 0xf8d41098
 *   @0x2ed2ec .word 0xf7f970cc
 *   @0x2ed2f0 .word 0x900cfada
 *   @0x2ed2f4 .word 0xf0402800
 *   @0x2ed2f8 .word 0xf10d80f5
 *   @0x2ed2fc qasxmi r0, r8, r0
 *   @0x2ed300 .word 0xf7f94641
 *   @0x2ed304 blls 0x62c308 <g_SWFaavertbuff+0x59240>
 *   @0x2ed308 .word 0xf0402b00
 *   @0x2ed30c stmdbls r6, {r0, r1, r3, r5, r6, r7, pc}
 *   @0x2ed310 .word 0xf0804281
 *   @0x2ed314 bls 0x48d6d0 <prim_v+0x3d1c>
 *   @0x2ed318 strtmi r2, [r8], -r5, lsl #2
 *   @0x2ed31c .word 0xf7f94351
 *   @0x2ed320 andls pc, r12, r7, lsl #22
 *   @0x2ed324 .word 0xf0402800
 *   @0x2ed328 .word 0x462880dd
 *   @0x2ed32c .word 0xf7f94641
 *   @0x2ed330 blls 0x62c2dc <g_SWFaavertbuff+0x59214>
 *   @0x2ed334 blhs 0x2feb54 <TT_RunIns+0x1d60>
 *   @0x2ed338 sbcshi pc, r4, r0, asr #32
 *   @0x2ed33c strtmi r4, [r8], -r1, asr #12
 *   @0x2ed340 ldc2 p7, c15, [r6, #-996]
 *   @0x2ed344 strmi r9, [r1], -r12, lsl #22
 *   @0x2ed348 .word 0xf0402b00
 *   @0x2ed34c .word 0xf8c480cb
 *   @0x2ed350 qsub8mi r0, r8, r4
 *   @0x2ed354 rscsvs pc, r0, r4, asr #17
 *   @0x2ed358 blx 0xfec6b344 <b2_toiTime+0xfffffffffe511ea0>
 *   @0x2ed35c stmdahs r0, {r2, r3, r12, pc}
 *   @0x2ed360 sbchi pc, r0, r0, asr #32
 *   @0x2ed364 ldrtmi r4, [r1], -r8, lsr #12
 *   @0x2ed368 ldc2l p7, c15, [r11, #-1000]
 *   @0x2ed36c stmdahs r0, {r2, r3, r12, pc}
 *   @0x2ed370 adcshi pc, r8, r0, asr #32
 *   @0x2ed374 bl 0x3c7c28 <error_g0017+0x208cc>
 *   @0x2ed378 .word 0xf1030806
 *   @0x2ed37c strmi r0, [r8, #0x10d]
 *   @0x2ed380 .word 0xf0c0930d
 *   @0x2ed384 ldclne p0, c8, [r10], {170}
 *   @0x2ed388 ldmdavc r10, {r0, r2, r3, r9, r12, pc} ^
 *   @0x2ed38c andseq r7, r2, #24, #16
 *   @0x2ed390 andmi lr, r0, #270336
 *   @0x2ed394 movwmi r7, #0x2898
 *   @0x2ed398 rscshs pc, r8, r4, asr #17
 *   @0x2ed39c andls r1, sp, #9856
 *   @0x2ed3a0 ldmvc r8, {r1, r3, r4, r8, r11, r12, sp, lr} ^
 *   @0x2ed3a4 b 0x136dbf4 <b2_toiTime+0xc14750>
 *   @0x2ed3a8 ldmdbvc r8, {r9, lr} ^
 *   @0x2ed3ac .word 0xf8c44302
 *   @0x2ed3b0 ldmibvc r10, {r2, r3, r4, r5, r6, r7, sp} ^
 *   @0x2ed3b4 andseq r7, r2, #152, #18
 *   @0x2ed3b8 andmi lr, r0, #270336
 *   @0x2ed3bc movwmi r7, #0x2a18
 *   @0x2ed3c0 smlabths r0, r4, r8, pc
 *   @0x2ed3c4 bvc 0x190be34 <b2_toiTime+0x11b2990>
 *   @0x2ed3c8 b 0x136dc18 <b2_toiTime+0xc14774>
 *   @0x2ed3cc bvc 0xff8fdbd4 <b2_toiTime+0xffffffffff1a4730>
 *   @0x2ed3d0 movwmi r9, #0x210d
 *   @0x2ed3d4 smlabths r4, r4, r8, pc
 *   @0x2ed3d8 .word 0xf0027b1a
 *   @0x2ed3dc .word 0xf0060604
 *   @0x2ed3e0 strdlt r0, r1, [lr, #-15]
 *   @0x2ed3e4 svceq #0x8f012
 *   @0x2ed3e8 .word 0x2602bf14
 *   @0x2ed3ec .word 0xf0122601
 *   @0x2ed3f0 .word 0xd1020f03
 *   @0x2ed3f4 and r3, r0, r3, lsl #12
 *   @0x2ed3f8 .word 0xf0024606
 *   @0x2ed3fc .word 0xf00e0e10
 *   @0x2ed400 .word 0xf1be0cff
 *   @0x2ed404 andle r0, r6, r0, lsl #30
 *   @0x2ed408 cdpeq p1, #0x0, c15, c1, c6, #0x0
 *   @0x2ed40c svceq #0x20f012
 *   @0x2ed410 .word 0x3602bf14
 *   @0x2ed414 strmi r4, [lr], #-1654
 *   @0x2ed418 cmple lr, #176, #10
 *   @0x2ed41c .word 0x0711b1f8
 *   @0x2ed420 .word 0xf103d508
 *   @0x2ed424 mrsls r0, apsr
 *   @0x2ed428 blvc 0xfe9cc194 <b2_toiTime+0xfffffffffe272cf0>
 *   @0x2ed42c movwhs lr, #0x1a43
 *   @0x2ed430 and r11, r3, r11, lsl r2
 *   @0x2ed434 .word 0x010ef103
 *   @0x2ed438 blvc 0x19d1874 <b2_toiTime+0x12783d0>
 *   @0x2ed43c .word 0xf8c40796
 *   @0x2ed440 .word 0xd10c310c
 *   @0x2ed444 .word 0x1cd99b0d
 *   @0x2ed448 ldmdavc r8, {r0, r2, r3, r8, r12, pc} ^
 *   @0x2ed44c andeq r7, r0, #1638400
 *   @0x2ed450 andmi lr, r1, r0, asr #20
 *   @0x2ed454 b 0x130b6c0 <b2_toiTime+0xbb221c>
 *   @0x2ed458 .word 0xf8c40301
 *   @0x2ed45c .word 0xf1bc3114
 *   @0x2ed460 andsle r0, r0, r0, lsl #30
 *   @0x2ed464 svceq #0x20f012
 *   @0x2ed468 andle r9, r7, sp, lsl #22
 *   @0x2ed46c swpls r1, r9, [sp]
 *   @0x2ed470 ldmdavc r11, {r0, r3, r4, r11, r12, sp, lr} ^
 *   @0x2ed474 movwhs lr, #0x1a43
 *   @0x2ed478 and r11, r2, r11, lsl r2
 *   @0x2ed47c qaddls r1, r9, sp
 *   @0x2ed480 .word 0xf8c4781b
 *   @0x2ed484 uadd16eq r3, r0, r0
 *   @0x2ed488 blls 0x6624a0 <g_SWFlinevertbuff+0xf3d8>
 *   @0x2ed48c strmi r1, [r8, #0xd59]
 *   @0x2ed490 and sp, r6, r3, lsr #6
 *   @0x2ed494 strbmi r10, [r1], -sp, lsl #16
 *   @0x2ed498 .word 0xff8cf7fe
 *   @0x2ed49c ldmiblt r0!, {r2, r3, r12, pc} ^
 *   @0x2ed4a0 ldcne p7, c14, [r10], {243}
 *   @0x2ed4a4 ldmdavc r8, {r0, r2, r3, r9, r12, pc}
 *   @0x2ed4a8 qaddls r7, r10, sp
 *   @0x2ed4ac andhs lr, r0, #270336
 *   @0x2ed4b0 tsths r8, r4, asr #17
 *   @0x2ed4b4 ldmvc r8, {r0, r3, r4, r6, r7, r11, r12, sp, lr}
 *   @0x2ed4b8 b 0x132dce4 <b2_toiTime+0xbd4840>
 *   @0x2ed4bc ldmdbvc r8, {r8, lr}
 *   @0x2ed4c0 .word 0xf8c44301
 *   @0x2ed4c4 cmplt r7, r12, lsl r1
 *   @0x2ed4c8 strmi r1, [r8, #0xd99]
 *   @0x2ed4cc ldmdbvc r11, {r0, r2, r8, r9, r12, lr, pc} ^
 *   @0x2ed4d0 andmi lr, r3, #2048
 *   @0x2ed4d4 tsths r8, r4, asr #17
 *   @0x2ed4d8 movwhs lr, #0x8001
 *   @0x2ed4dc strtmi r9, [r8], -r12, lsl #6
 *   @0x2ed4e0 stc2l p7, c15, [r10], #1000
 *   @0x2ed4e4 and r9, r4, r12, lsl #22
 *   @0x2ed4e8 subpl r5, r6, r0, lsr r2
 *   @0x2ed4ec andeq r3, r10, r0, ror #9
 *   @0x2ed4f0 movwls r2, #0xb306
 *   @0x2ed4f4 .word 0xf47f2b00
 *   @0x2ed4f8 .word 0xf8d4aee1
 *   @0x2ed4fc stmibvs r9!, {r2, r3, r4, r8} ^
 *   @0x2ed500 .word 0x31a8f8c4
 *   @0x2ed504 bicsvc pc, r4, #4, #10
 *   @0x2ed508 .word 0x91049005
 *   @0x2ed50c smlawtne r0, r4, r8, pc
 *   @0x2ed510 smlawteq r4, r4, r8, pc
 *   @0x2ed514 .word 0xf8c44628
 *   @0x2ed518 stmdbls r5, {r2, r3, r5, r7, r8, r12, sp}
 *   @0x2ed51c ldrsbvs pc, [r8, -r4]
 *   @0x2ed520 .word 0xf9c1f7f9
 *   @0x2ed524 stmdahs r0, {r0, r2, r3, r12, pc}
 *   @0x2ed528 bicshi pc, r6, r0, asr #32
 *   @0x2ed52c ldrtmi r4, [r1], -r8, lsr #12
 *   @0x2ed530 ldc2l p7, c15, [r7], #-1000
 *   @0x2ed534 stmdahs r0, {r0, r2, r3, r12, pc}
 *   @0x2ed538 bichi pc, lr, r0, asr #32
 *   @0x2ed53c .word 0xf8c46a2b
 *   @0x2ed540 bvs 0xdb9c18 <b2_toiTime+0x660774>
 *   @0x2ed544 .word 0xf103441e
 *   @0x2ed548 strbmi r0, [r6, #-0x80f]
 *   @0x2ed54c .word 0x81b7f0c0
 *   @0x2ed550 ldmdavc r10, {r0, r3, r4, r11, r12, sp, lr} ^
 *   @0x2ed554 andhs lr, r1, #270336
 *   @0x2ed558 smlawths r8, r4, r8, pc
 *   @0x2ed55c ldmvc r10, {r0, r3, r4, r7, r11, r12, sp, lr} ^
 *   @0x2ed560 andhs lr, r1, #270336
 *   @0x2ed564 smlawths r12, r4, r8, pc
 *   @0x2ed568 ldmdbvc r10, {r0, r3, r4, r8, r11, r12, sp, lr} ^
 *   @0x2ed56c andhs lr, r1, #270336
 *   @0x2ed570 teqhs r0, r4, asr #17
 *   @0x2ed574 ldmibvc r10, {r0, r3, r4, r7, r8, r11, r12, sp, lr} ^
 *   @0x2ed578 andhs lr, r1, #270336
 *   @0x2ed57c .word 0xf8c4b212
 *   @0x2ed580 bvc 0x935a58 <b2_toiTime+0x1dc5b4>
 *   @0x2ed584 b 0x138bef4 <b2_toiTime+0xc32a50>
 *   @0x2ed588 andslt r2, r2, #268435456
 *   @0x2ed58c teqhs r8, r4, asr #17
 *   @0x2ed590 bvc 0xff98bffc <b2_toiTime+0xffffffffff232b58>
 *   @0x2ed594 andhs lr, r1, #270336
 *   @0x2ed598 .word 0xf8c4b212
 *   @0x2ed59c blvc 0x935a94 <b2_toiTime+0x1dc5f0>
 *   @0x2ed5a0 b 0x138c310 <b2_toiTime+0xc32e6c>
 *   @0x2ed5a4 andslt r2, r2, #268435456
 *   @0x2ed5a8 smlalbths pc, r0, r4, r8
 *   @0x2ed5ac .word 0xf0077b9f
 *   @0x2ed5b0 .word 0xf0020204
 *   @0x2ed5b4 .word 0xf8c400ff
 *   @0x2ed5b8 andls r7, r8, r4, asr #2
 *   @0x2ed5bc .word 0xf103b95a
 *   @0x2ed5c0 ldrmi r0, [r0, #0x811]!
 *   @0x2ed5c4 cmnhi r11, r0, lsl #4
 *   @0x2ed5c8 .word 0x7c1b7bda
 *   @0x2ed5cc movwhs lr, #0x2a43
 *   @0x2ed5d0 .word 0xf8c4b21b
 *   @0x2ed5d4 ldrteq r3, [r9], -r8, asr #2
 *   @0x2ed5d8 .word 0xf108d53a
 *   @0x2ed5dc adcsmi r0, r3, #67108864
 *   @0x2ed5e0 .word 0xf8dfd82f
 *   @0x2ed5e4 .word 0xf504b4e0
 *   @0x2ed5e8 .word 0xf8987c90
 *   @0x2ed5ec ldrmi r10, [r8], r0
 *   @0x2ed5f0 .word 0xf1ba44fb
 *   @0x2ed5f4 eorle r0, r1, r0, lsl #30
 *   @0x2ed5f8 stmdbeq r2, {r3, r8, r12, sp, lr, pc}
 *   @0x2ed5fc .word 0xd320454e
 *   @0x2ed600 mullo r0, r8, r8
 *   @0x2ed604 muleq r1, r8, r8
 *   @0x2ed608 stmdaeq r3, {r0, r3, r8, r9, r11, sp, lr, pc}
 *   @0x2ed60c ldmdale r7, {r4, r5, r7, r8, r10, lr}
 *   @0x2ed610 eoreq pc, r0, #-1073741822
 *   @0x2ed614 .word 0x3c04f852
 *   @0x2ed618 andlo r11, r8, #-1073741798
 *   @0x2ed61c .word 0x1c10f852
 *   @0x2ed620 mvnsle r4, r1, lsl #5
 *   @0x2ed624 .word 0xf8cd4662
 *   @0x2ed628 strbmi r12, [r8], -r12
 *   @0x2ed62c ldrmi r4, [r8, r1, asr #12]
 *   @0x2ed630 .word 0xc00cf8dd
 *   @0x2ed634 .word 0xf10ab938
 *   @0x2ed638 .word 0xe7da3aff
 *   @0x2ed63c and r4, r3, r0, asr r6
 *   @0x2ed640 andhs r4, r8, r8, asr #13
 *   @0x2ed644 strbmi lr, [r8], r0
 *   @0x2ed648 stmdahs r0, {r0, r2, r3, r12, pc}
 *   @0x2ed64c teqhi r9, r0, asr #32
 *   @0x2ed650 movweq pc, #0x3108
 *   @0x2ed654 vqsub.s8 d4, d16, d19
 *   @0x2ed658 .word 0xf8988132
 *   @0x2ed65c .word 0xf898b001
 *   @0x2ed660 b 0x16b5668 <b2_toiTime+0xf5c1c4>
 *   @0x2ed664 b 0x15b8298 <b2_toiTime+0xe5edf4>
 *   @0x2ed668 .word 0xf8984b02
 *   @0x2ed66c b 0x19b567c <b2_toiTime+0x125c1d8>
 *   @0x2ed670 subsle r0, r4, r2, lsl #22
 *   @0x2ed674 stmdbeq r11, {r0, r1, r8, r9, r11, sp, lr, pc}
 *   @0x2ed678 vqrshl.s8 d4, d17, d16
 *   @0x2ed67c .word 0xf5048120
 *   @0x2ed680 .word 0xf50471bc
 *   @0x2ed684 strhls r7, [r7, -r10]
 *   @0x2ed688 ldcne p2, c9, [r8, #-36]
 *   @0x2ed68c movtle r4, #0x7581
 *   @0x2ed690 mulhi r0, r3, r8
 *   @0x2ed694 beq 0x3a9aa8 <error_g0017+0x274c>
 *   @0x2ed698 b 0x138b808 <b2_toiTime+0xc32364>
 *   @0x2ed69c .word 0xf1b82808
 *   @0x2ed6a0 ldmdble sp!, {r0, r1, r8, r9, r10, r11}
 *   @0x2ed6a4 ldmdale r11!, {r3, r4, r6, r7, r8, r10, lr}
 *   @0x2ed6a8 andeq pc, r2, #168, #2
 *   @0x2ed6ac ldrmi r7, [r2], #2201
 *   @0x2ed6b0 b 0x138ba20 <b2_toiTime+0xc3257c>
 *   @0x2ed6b4 bhs 0x375ec0 <_ZTS13C_UTF16String+0xcf6c>
 *   @0x2ed6b8 bhs 0x3e16e0 <error_g0017+0x3a384>
 *   @0x2ed6bc bhs 0x361744 <_ZTS12CDS_Priority+0x379c>
 *   @0x2ed6c0 .word 0xf1a8d128
 *   @0x2ed6c4 bls 0x3edadc
 *   @0x2ed6c8 ands r9, sp, r9, lsl #22
 *   @0x2ed6cc eoreq pc, r4, #-1073741824
 *   @0x2ed6d0 tstle pc, #612368384
 *   @0x2ed6d4 blvc 0xff98c540 <b2_toiTime+0xffffffffff23309c>
 *   @0x2ed6d8 andhs lr, r1, #270336
 *   @0x2ed6dc .word 0xf8c4b212
 *   @0x2ed6e0 .word 0x7c19214c
 *   @0x2ed6e4 b 0x138c854 <b2_toiTime+0xc333b0>
 *   @0x2ed6e8 andslt r2, r2, #268435456
 *   @0x2ed6ec cmphs r0, r4, asr #17
 *   @0x2ed6f0 ldclvc p12, c7, [r11], {154}
 *   @0x2ed6f4 movwhs lr, #0x2a43
 *   @0x2ed6f8 .word 0xf8c4b21b
 *   @0x2ed6fc and r3, r9, r4, asr r1
 *   @0x2ed700 .word 0xf1a89a04
 *   @0x2ed704 blls 0x4adb1c <SrcVerts+0xab60>
 *   @0x2ed708 ldc2l p7, c15, [r10, #1016]
 *   @0x2ed70c stmdahs r0, {r0, r2, r3, r12, pc}
 *   @0x2ed710 rschi pc, r2, r0, asr #32
 *   @0x2ed714 bleq 0x528608 <SrcVerts+0x8564c>
 *   @0x2ed718 ldrbmi sp, [r3], -r2
 *   @0x2ed71c .word 0x4699e7b5
 *   @0x2ed720 stmdaeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2ed724 vqrshl.s8 d4, d16, d16
 *   @0x2ed728 .word 0xf89980ca
 *   @0x2ed72c bl 0x511734 <SrcVerts+0x6e778>
 *   @0x2ed730 .word 0xf8c40b49
 *   @0x2ed734 ldrmi r9, [r3, #0x188]!
 *   @0x2ed738 sbchi pc, r1, r0, lsl #4
 *   @0x2ed73c strbmi r2, [r11], -r0, lsl #4
 *   @0x2ed740 .word 0xf10d9200
 *   @0x2ed744 stmdals r4, {r2, r4, r5, r9, r11}
 *   @0x2ed748 .word 0xf8cd2104
 *   @0x2ed74c .word 0xf7faa004
 *   @0x2ed750 blls 0x66c9d0 <g_SWFlinevertbuff+0x19908>
 *   @0x2ed754 orreq pc, r12, r4, asr #17
 *   @0x2ed758 .word 0xf0402b00
 *   @0x2ed75c strbmi r8, [r11, #-0xb2]
 *   @0x2ed760 .word 0xf818d20c
 *   @0x2ed764 .word 0xf8d40b02
 *   @0x2ed768 .word 0xf818218c
 *   @0x2ed76c b 0x1334778 <b2_toiTime+0xbdb2d4>
 *   @0x2ed770 andlt r2, r9, #0, #2
 *   @0x2ed774 eorne pc, r3, r2, asr #16
 *   @0x2ed778 ldrb r3, [r0, r1, lsl #6]!
 *   @0x2ed77c andeq pc, r8, #-1073741822
 *   @0x2ed780 .word 0xf0c04296
 *   @0x2ed784 .word 0xf89b809c
 *   @0x2ed788 ldrmi r3, [r0], r0
 *   @0x2ed78c .word 0xf8c49805
 *   @0x2ed790 .word 0xf89b3190
 *   @0x2ed794 .word 0xf8c43001
 *   @0x2ed798 .word 0xf89b3194
 *   @0x2ed79c .word 0xf89b1002
 *   @0x2ed7a0 b 0x13b97b4 <b2_toiTime+0xc60310>
 *   @0x2ed7a4 .word 0xf8c42301
 *   @0x2ed7a8 .word 0xf89b3164
 *   @0x2ed7ac .word 0xf89b1004
 *   @0x2ed7b0 b 0x13b97cc <b2_toiTime+0xc60328>
 *   @0x2ed7b4 .word 0xf8c42301
 *   @0x2ed7b8 .word 0xf89b3158
 *   @0x2ed7bc .word 0xf89b9006
 *   @0x2ed7c0 b 0x13b97e4 <b2_toiTime+0xc60340>
 *   @0x2ed7c4 .word 0xf8c42909
 *   @0x2ed7c8 bvs 0xdd1e30 <b2_toiTime+0x67898c>
 *   @0x2ed7cc strmi r1, [r3], #-2771
 *   @0x2ed7d0 .word 0xf8c49808
 *   @0x2ed7d4 .word 0xf007319c
 *   @0x2ed7d8 .word 0xf0030302
 *   @0x2ed7dc blhs 0x2edfe0 <FT_Done_Memory+0x436c>
 *   @0x2ed7e0 movwhs r11, #0x5f14
 *   @0x2ed7e4 .word 0x91052304
 *   @0x2ed7e8 movwlo r11, #0x2100
 *   @0x2ed7ec .word 0x0108f007
 *   @0x2ed7f0 rscseq pc, pc, r1
 *   @0x2ed7f4 mrslt r9, apsr
 *   @0x2ed7f8 .word 0xf0073301
 *   @0x2ed7fc .word 0xf0010110
 *   @0x2ed800 strdlt r0, r1, [r1, -pc]
 *   @0x2ed804 .word 0xf0073301
 *   @0x2ed808 .word 0xf0010120
 *   @0x2ed80c strdlt r0, r1, [r1, -pc]
 *   @0x2ed810 blx 0x53a41e <obj_numb_event+0x34ae>
 *   @0x2ed814 addsmi r2, lr, #201326592
 *   @0x2ed818 andhs sp, r0, #1140850689
 *   @0x2ed81c stm sp, {r2, r11, r12, pc}
 *   @0x2ed820 tsths r0, r4, lsl #8
 *   @0x2ed824 .word 0xf7fa464b
 *   @0x2ed828 bls 0x66c8f8 <g_SWFlinevertbuff+0x19830>
 *   @0x2ed82c asreq pc, r4, #17
 *   @0x2ed830 .word 0xd1462a00
 *   @0x2ed834 suble r4, r4, #310378496
 *   @0x2ed838 .word 0x61a0f8d4
 *   @0x2ed83c blls 0x42dc84 <g_RomDisk+0x36464>
 *   @0x2ed840 .word 0xb1431831
 *   @0x2ed844 mul r0, r8, r8
 *   @0x2ed848 movweq pc, #0x2108
 *   @0x2ed84c mulgt r1, r8, r8
 *   @0x2ed850 vmlshs.f32 s28, s28, s24
 *   @0x2ed854 .word 0xf898e003
 *   @0x2ed858 .word 0xf108e000
 *   @0x2ed85c .word 0xf8460301
 *   @0x2ed860 stmdals r8, {sp, lr, pc}
 *   @0x2ed864 ldmdavc lr, {r3, r4, r5, r8, r12, sp, pc}
 *   @0x2ed868 .word 0xf8133302
 *   @0x2ed86c b 0x12f0878 <b2_toiTime+0xb973d4>
 *   @0x2ed870 andlt r2, r0, #6
 *   @0x2ed874 .word 0xf8d4e001
 *   @0x2ed878 subvs r0, r8, r8, asr #2
 *   @0x2ed87c .word 0xb1009807
 *   @0x2ed880 .word 0xf1bb3301
 *   @0x2ed884 andle r0, r5, r0, lsl #30
 *   @0x2ed888 ldcne p8, c7, [r8], {30}
 *   @0x2ed88c b 0x13cba00 <b2_toiTime+0xc7255c>
 *   @0x2ed890 and r2, r1, r6, lsl #6
 *   @0x2ed894 ldmdavc r11, {r3, r4, r6, r10, r11, r12}
 *   @0x2ed898 stmdavc r3, {r0, r1, r3, r7, sp, lr}
 *   @0x2ed89c teqlt pc, r6, asr #16
 *   @0x2ed8a0 stmdaeq r3, {r8, r12, sp, lr, pc}
 *   @0x2ed8a4 stmvc r0, {r1, r2, r4, r5, r9}
 *   @0x2ed8a8 movwmi lr, #0x3a46
 *   @0x2ed8ac and r4, r3, r3, lsl #6
 *   @0x2ed8b0 stmdaeq r2, {r8, r12, sp, lr, pc}
 *   @0x2ed8b4 movwhs lr, #0x3a46
 *   @0x2ed8b8 andlo r6, r1, #203
 *   @0x2ed8bc movwhs lr, #0x87ba
 *   @0x2ed8c0 strtmi r9, [r8], -sp, lsl #6
 *   @0x2ed8c4 blx 0x12b8b4 <_Z24F_SpriteCreateFromScreenR6RValueP9CInstanceS2_iPS_+0x13c>
 *   @0x2ed8c8 .word 0xf7f94628
 *   @0x2ed8cc movwhs pc, #0x839
 *   @0x2ed8d0 .word 0x31b4f8c4
 *   @0x2ed8d4 asrseq pc, r4, #17
 *   @0x2ed8d8 movwls r9, #0xbb0d
 *   @0x2ed8dc .word 0xf47f2b00
 *   @0x2ed8e0 stmdbls r6, {r0, r2, r3, r5, r6, r7, r10, r11, sp, pc}
 *   @0x2ed8e4 ldrsbhs pc, [r8, r4]
 *   @0x2ed8e8 mrrcne p0, #0x6, r6, r1, c1
 *   @0x2ed8ec stmvs r1!, {r0, r5, r8, sp, lr}
 *   @0x2ed8f0 .word 0x0101f041
 *   @0x2ed8f4 and r6, r6, r1, lsr #1
 *   @0x2ed8f8 .word 0x11a0f8d4
 *   @0x2ed8fc .word 0x1103eb01
 *   @0x2ed900 ldmdblt r1, {r0, r3, r6, r7, r11, sp, lr} ^
 *   @0x2ed904 addsmi r3, r3, #67108864
 *   @0x2ed908 .word 0xf8d4d1f6
 *   @0x2ed90c tstlt r3, r12, ror r1
 *   @0x2ed910 adcvs r2, r3, r0, lsl #6
 *   @0x2ed914 movwhs lr, #0x3001
 *   @0x2ed918 .word 0xf8d4e4d5
 *   @0x2ed91c ldrbeq r3, [r10, -r4, asr #2]
 *   @0x2ed920 stmvs r2!, {r0, r1, r10, r12, lr, pc}
 *   @0x2ed924 andeq pc, r4, #66
 *   @0x2ed928 .word 0xf01360a2
 *   @0x2ed92c stmvs r3!, {r0, r8, r9, r10, r11}
 *   @0x2ed930 ldrsbpl pc, [r12, #-132]!
 *   @0x2ed934 .word 0xf043bf14
 *   @0x2ed938 .word 0xf0430320
 *   @0x2ed93c adcvs r0, r3, r0, lsl r3
 *   @0x2ed940 stmvs r3!, {r0, r2, r3, r4, r8, r12, sp, pc}
 *   @0x2ed944 movweq pc, #0x2043
 *   @0x2ed948 .word 0xf8d460a3
 *   @0x2ed94c tstlt r11, r4, lsr #3
 *   @0x2ed950 .word 0xf04368a3
 *   @0x2ed954 adcvs r0, r3, r0, asr #6
 *   @0x2ed958 ldrsblo pc, [r4, #-132]!
 *   @0x2ed95c ldmdblt r3, {r0, r1, r5, r6, r8, sp, lr}
 *   @0x2ed960 ldrsblo pc, [r0, #-132]!
 *   @0x2ed964 .word 0xf8d46163
 *   @0x2ed968 .word 0xf1043178
 *   @0x2ed96c .word 0x61a30634
 *   @0x2ed970 mvnvs r2, r0, lsl #6
 *   @0x2ed974 .word 0xf5046223
 *   @0x2ed978 blgt 0x6ca7e8 <g_SWFlinevertbuff+0x77720>
 *   @0x2ed97c andeq lr, pc, r6, lsl #17
 *   @0x2ed980 .word 0xf8d4230c
 *   @0x2ed984 .word 0x210a012c
 *   @0x2ed988 ldrsbvs pc, [r8, -r4]!
 *   @0x2ed98c .word 0x7140f8d4
 *   @0x2ed990 subeq pc, r4, r4, lsr #17
 *   @0x2ed994 blx 0xada39c <b2_toiTime+0x380ef8>
 *   @0x2ed998 .word 0xf8a4f886
 *   @0x2ed99c blx 0xacdac4 <b2_toiTime+0x374620>
 *   @0x2ed9a0 .word 0xf8a4f987
 *   @0x2ed9a4 cmpmi r8, #70
 *   @0x2ed9a8 ldmib r2!, {r0, r1, r3, r5, r12, sp, lr, pc}
 *   @0x2ed9ac .word 0xf989fa0f
 *   @0x2ed9b0 .word 0xf888fa0f
 *   @0x2ed9b4 stmdaeq r9, {r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2ed9b8 andlt r11, r3, #128, #4
 *   @0x2ed9bc svclt #0xae4543
 *   @0x2ed9c0 subeq pc, r10, r4, lsr #17
 *   @0x2ed9c4 streq lr, [r7], -r6, asr #23
 *   @0x2ed9c8 subvs pc, r10, r4, lsr #17
 *   @0x2ed9cc cdpvs p3, #0xa, c11, c3, c5, #0x4
 *   @0x2ed9d0 stmdbge r11, {r9, sp}
 *   @0x2ed9d4 .word 0x91019200
 *   @0x2ed9d8 ldmibvs r8, {r4, r8, sp} ^
 *   @0x2ed9dc .word 0xf7fa462b
 *   @0x2ed9e0 blls 0x5ec740 <g_SWFaavertbuff+0x19678>
 *   @0x2ed9e4 blhs 0x30626c <TT_New_Context+0x6064>
 *   @0x2ed9e8 stclge p4, c15, [r8], #-508
 *   @0x2ed9ec .word 0x2184f8d4
 *   @0x2ed9f0 .word 0xf10042ab
 *   @0x2ed9f4 cps #0x10
 *   @0x2ed9f8 andsle r0, r8, r4, lsr #4
 *   @0x2ed9fc stcne p8, c15, [r0], #-328
 *   @0x2eda00 .word 0xf8203301
 *   @0x2eda04 .word 0xf8521c10
 *   @0x2eda08 .word 0xf8201c24
 *   @0x2eda0c .word 0xf8521c0e
 *   @0x2eda10 orreq r1, r9, r0, lsr #24
 *   @0x2eda14 .word 0x1c0cf840
 *   @0x2eda18 stcne p8, c15, [r4], #-328
 *   @0x2eda1c .word 0xf8400189
 *   @0x2eda20 .word 0xf8521c08
 *   @0x2eda24 orreq r1, r9, r0, lsr #24
 *   @0x2eda28 .word 0x1c04f840
 *   @0x2eda2c mvnvs lr, r0, ror #15
 *   @0x2eda30 .word 0x3144f8d4
 *   @0x2eda34 strle r0, [r2], #-1883
 *   @0x2eda38 .word 0x3148f8d4
 *   @0x2eda3c .word 0xf8d4e00d
 *   @0x2eda40 movwhs r2, #0x198
 *   @0x2eda44 .word 0x11a0f8d4
 *   @0x2eda48 teqlt r2, r0, lsl r1
 *   @0x2eda4c .word 0x0c0cf851
 *   @0x2eda50 addmi r3, r3, #4096
 *   @0x2eda54 .word 0x4603bfb8
 *   @0x2eda58 rfeia r4!
 *   @0x2eda5c .word 0xf06f5044
 *   @0x2eda60 .word 0xf8a40109
 *   @0x2eda64 rfeia r4!
 *   @0x2eda68 strtmi r3, [r8], -r10, asr #32
 *   @0x2eda6c sublo pc, lr, r4, lsr #17
 *   @0x2eda70 stmdb lr, {r0, r1, r3, r5, r12, sp, lr, pc} ^
 *   @0x2eda74 .word 0xf8a4211e
 *   @0x2eda78 qsaxmi r0, r8, r0
 *   @0x2eda7c stm r4!, {r0, r1, r3, r5, r12, sp, lr, pc} ^
 *   @0x2eda80 .word 0xf8ad2303
 *   @0x2eda84 movwhs r3, #0x103c
 *   @0x2eda88 eorslo pc, lr, sp, lsr #17
 *   @0x2eda8c blmi 0x5f5e94 <g_SWFaavertbuff+0x22dcc>
 *   @0x2eda90 strls r10, [sp], #-2573
 *   @0x2eda94 strmi r9, [r11], -lr, lsl #6
 *   @0x2eda98 subseq pc, r2, r4, lsr #17
 *   @0x2eda9c ldrbtmi r4, [r8], #-2058
 *   @0x2edaa0 .word 0xf7fa6800
 *   @0x2edaa4 .word 0xf8d4fc68
 *   @0x2edaa8 andls r3, r11, r4, lsr #3
 *   @0x2edaac .word 0xf43f2b00
 *   @0x2edab0 stmvs r3!, {r0, r2, r10, r11, sp, pc}
 *   @0x2edab4 movteq pc, #0x43
 *   @0x2edab8 .word 0xf7ff60a3
 *   @0x2edabc svclt #0xbbff
 *   @0x2edac0 strbvc r6, [lr, #-0x963]!
 *   @0x2edac4 andeq r11, pc, r4, lsr #9
 *   @0x2edac8 andseq r4, r0, r6, lsl r1
 *   @0x2edacc muleq r12, r0, r8
 *   @0x2edad0 andmi lr, r2, #274432
 *   @0x2edad4 muleq r9, r1, r8
 *   @0x2edad8 movwmi lr, #0xa43
 *   @0x2edadc stmdale r4, {r1, r3, r4, r7, r9, lr}
 *   @0x2edae0 andhs r11, r0, r12, lsr #30
 *   @0x2edae4 andeq pc, r0, pc, rrx
 *   @0x2edae8 andhs r4, r1, r0, ror r7
 *   @0x2edaec andeq r4, r0, r0, ror r7
 *   @0x2edaf0 svcmi #0xf8e92d
 *   @0x2edaf4 stmdavs r4, {r7, r9, r10, lr}
 *   @0x2edaf8 ldrmi r4, [r5], -pc, lsl #12
 *   @0x2edafc subsle r4, r5, #140, #4
 *   @0x2edb00 blhs 0xb75554 <b2_toiTime+0x41c0b0>
 *   @0x2edb04 stmdavc r3!, {r1, r4, r6, r11, r12, lr, pc}
 *   @0x2edb08 andle r2, r1, sp, lsr #22
 *   @0x2edb0c .word 0xd1082b2b
 *   @0x2edb10 strlo r3, [r1], #-2861
 *   @0x2edb14 stmdbeq r0, {r0, r1, r4, r6, r7, r8, r12, sp, lr, pc}
 *   @0x2edb18 stmdbeq r3, {r0, r3, r4, r6, r8, r9, r11, sp, lr, pc}
 *   @0x2edb1c strhle r4, [r2, -r12]
 *   @0x2edb20 .word 0xf04fe044
 *   @0x2edb24 strtmi r0, [r9], -r0, lsl #18
 *   @0x2edb28 andmi pc, r0, pc, rrx
 *   @0x2edb2c ldm r0!, {r0, r1, r3, r5, r12, sp, lr, pc} ^
 *   @0x2edb30 strhs r4, [r0], -r9, lsr #12
 *   @0x2edb34 .word 0xf06f4682
 *   @0x2edb38 .word 0xf02b4000
 *   @0x2edb3c ldmdami lr, {r3, r4, r6, r8, r11, sp, lr, pc}
 *   @0x2edb40 ldrbtmi r4, [r8], #-1587
 *   @0x2edb44 stc2 p10, c15, [r1], {79}
 *   @0x2edb48 .word 0x462142bc
 *   @0x2edb4c .word 0xf814d203
 *   @0x2edb50 bhs 0xaf875c <b2_toiTime+0x39f2b8>
 *   @0x2edb54 cdphs p1, #0x0, c13, c0, c11, #0x0
 *   @0x2edb58 andne pc, r0, r8, asr #17
 *   @0x2edb5c .word 0xf06fbf18
 *   @0x2edb60 .word 0xf1b94300
 *   @0x2edb64 eorle r0, r4, r0, lsl #30
 *   @0x2edb68 pop {r3, r4, r6, r9, lr}
 *   @0x2edb6c .word 0xf1a28ff8
 *   @0x2edb70 .word 0xf1bb0b09
 *   @0x2edb74 stmible lr!, {r0, r8, r9, r10, r11} ^
 *   @0x2edb78 bleq 0x62a208 <g_SWFaavertbuff+0x57140>
 *   @0x2edb7c svceq #0x1f1bb
 *   @0x2edb80 blx 0x16e432c <b2_toiTime+0xf8ae88>
 *   @0x2edb84 .word 0xf1bbfb82
 *   @0x2edb88 stclle p15, c0, [r4, #0]!
 *   @0x2edb8c bhs 0x30359c <TT_New_Context+0x3394>
 *   @0x2edb90 adcmi sp, r10, #230400
 *   @0x2edb94 ldrbmi sp, [r3, #-0xadf]
 *   @0x2edb98 mrsle sp, apsr
 *   @0x2edb9c .word 0xdc024562
 *   @0x2edba0 movwhs pc, #0x3b05
 *   @0x2edba4 .word 0x4653e7d0
 *   @0x2edba8 strb r2, [sp, r1, lsl #12]
 *   @0x2edbac ldm sp!, {sp}
 *   @0x2edbb0 ssub8mi r8, r8, r8
 *   @0x2edbb4 svchi #0xf8e8bd
 *   @0x2edbb8 andeq r2, r10, r10, asr #24
 *   @0x2edbbc .word 0xac02b5f7
 *   @0x2edbc0 andhs r6, r10, #393216
 *   @0x2edbc4 strmi r4, [pc], -r5, lsl #12
 *   @0x2edbc8 stcvs p8, c15, [r4, #-272]
 *   @0x2edbcc .word 0xf7ff4620
 *   @0x2edbd0 blls 0x36da14 <_ZTS13C_UTF16String+0x4ac0>
 *   @0x2edbd4 .word 0x460242b3
 *   @0x2edbd8 andhs sp, r0, r1, lsl #2
 *   @0x2edbdc adcsmi lr, r11, #17
 *   @0x2edbe0 ldmdavc r9, {r2, r3, r9, r12, lr, pc}
 *   @0x2edbe4 .word 0xd1092923
 *   @0x2edbe8 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x2edbec .word 0x96011c5e
 *   @0x2edbf0 .word 0xff7ef7ff
 *   @0x2edbf4 adcsmi r9, r3, #1024
 *   @0x2edbf8 rscle r4, lr, r2, lsl #12
 *   @0x2edbfc ldrmi r9, [r0], -r1, lsl #22
 *   @0x2edc00 andlt r6, r3, r11, lsr #32
 *   @0x2edc04 blx 0xfe35d3ce <b2_toiTime+0xfffffffffdc03f2a>
 *   @0x2edc08 b 0x16ba410 <b2_toiTime+0xf60f6c>
 *   @0x2edc0c .word 0xf50070e2
 *   @0x2edc10 ldmdane r11, {lr}
 *   @0x2edc14 andeq pc, r0, #-2147483632
 *   @0x2edc18 andsmi lr, r3, pc, asr #20
 *   @0x2edc1c andmi lr, r2, r0, asr #20
 *   @0x2edc20 stmdavs r3, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2edc24 stmibvs r3, {r0, r3, r4, r6, r9, r11, r12}
 *   @0x2edc28 bl 0x3c8030 <error_g0017+0x20cd4>
 *   @0x2edc2c addmi r0, r3, #128
 *   @0x2edc30 .word 0xf853d207
 *   @0x2edc34 bhs 0x2f884c <ps_hints_apply+0x744c>
 *   @0x2edc38 strmi sp, [r10], #-249
 *   @0x2edc3c .word 0x2c04f843
 *   @0x2edc40 .word 0x4770e7f5
 *   @0x2edc44 ldrlt r6, [r0, #-0x803]
 *   @0x2edc48 andle r4, sp, #-1342177272
 *   @0x2edc4c .word 0xf1a2781a
 *   @0x2edc50 .word 0x2c010409
 *   @0x2edc54 .word 0xf1a2d915
 *   @0x2edc58 .word 0x2c01040c
 *   @0x2edc5c .word 0xf012d911
 *   @0x2edc60 ldrdle r0, r1, [lr], -pc
 *   @0x2edc64 andle r2, r1, r5, lsr #20
 *   @0x2edc68 ldclt p0, c6, [r0, #-12]
 *   @0x2edc6c sadd16mi r4, r3, r10
 *   @0x2edc70 blmi 0x36bcc0 <_ZTS13C_UTF16String+0x2d6c>
 *   @0x2edc74 andle r2, r4, sp, lsl #24
 *   @0x2edc78 andle r2, r2, r10, lsl #24
 *   @0x2edc7c ldrmi r4, [r3], -r10, lsl #5
 *   @0x2edc80 movwlo sp, #0x11f5
 *   @0x2edc84 ldrblt lr, [r0, #-0x7e0]!
 *   @0x2edc88 stmdavs r4, {r8, r10, sp}
 *   @0x2edc8c strtmi r4, [r3], -r12, lsl #5
 *   @0x2edc90 .word 0xf813d233
 *   @0x2edc94 bhs 0x19f88a0 <b2_toiTime+0x129f3fc>
 *   @0x2edc98 addmi sp, r11, #1073741833
 *   @0x2edc9c stmdavc r2!, {r0, r2, r3, r5, r12, lr, pc} ^
 *   @0x2edca0 andsle r2, r2, r2, ror #20
 *   @0x2edca4 bhs 0xd23cc0 <b2_toiTime+0x5ca81c>
 *   @0x2edca8 bhs 0xd628e0 <b2_toiTime+0x60943c>
 *   @0x2edcac bhs 0x1a240e8 <b2_toiTime+0x12cac44>
 *   @0x2edcb0 bhs 0x1ea5cd4 <b2_toiTime+0x174c830>
 *   @0x2edcb4 stmdale r1, {r0, r3, r12, lr, pc}
 *   @0x2edcb8 and r2, r2, r6, ror #20
 *   @0x2edcbc andle r2, r4, r2, ror r10
 *   @0x2edcc0 andle r2, r2, r4, ror r10
 *   @0x2edcc4 strlo r4, [r4], #-1562
 *   @0x2edcc8 stcne p0, c14, [r3], #36
 *   @0x2edccc ldmdavc lr, {r0, r1, r4, sp, lr, pc}
 *   @0x2edcd0 cdplo p2, #0x3, c3, c0, c1, #0x0
 *   @0x2edcd4 stmdale lr, {r0, r1, r2, r9, r10, r11, sp}
 *   @0x2edcd8 ldrmi r4, [r3], -r2, lsr #5
 *   @0x2edcdc addmi sp, r10, #11
 *   @0x2edce0 mvnsle r4, r3, lsl r6
 *   @0x2edce4 bhs 0xd25d08 <b2_toiTime+0x5cc864>
 *   @0x2edce8 strlo sp, [r1, #-0x101]
 *   @0x2edcec bhs 0xd65d00 <b2_toiTime+0x60c85c>
 *   @0x2edcf0 stclo p1, c13, [r1, #-4]
 *   @0x2edcf4 ldrmi sp, [r12], -r2
 *   @0x2edcf8 strhs lr, [r3, #-0x7c8]
 *   @0x2edcfc strtmi r6, [r8], -r3
 *   @0x2edd00 ldrblt r11, [r3, #-0xd70]!
 *   @0x2edd04 stmdavs r3, {r1, r8, r10, r11, sp, pc}
 *   @0x2edd08 strmi r4, [r12], -r6, lsl #12
 *   @0x2edd0c stclo p8, c15, [r4, #-276]
 *   @0x2edd10 movwlo r9, #0x1b01
 *   @0x2edd14 adcmi r9, r3, #67108864
 *   @0x2edd18 strtmi sp, [r8], -r6, lsl #4
 *   @0x2edd1c .word 0xf7ff4621
 *   @0x2edd20 blls 0x36db6c <_ZTS13C_UTF16String+0x4c18>
 *   @0x2edd24 movwle r4, #0x32a3
 *   @0x2edd28 adcmi r9, r3, #1024
 *   @0x2edd2c and sp, sp, r11, lsl #6
 *   @0x2edd30 .word 0xf1a3781b
 *   @0x2edd34 bhs 0x52e5fc <SrcVerts+0x8b640>
 *   @0x2edd38 .word 0xf023d9ea
 *   @0x2edd3c bllo 0x132e9c4 <b2_toiTime+0xbd5520>
 *   @0x2edd40 ldmle r1!, {r0, r2, r8, r9, r11, sp} ^
 *   @0x2edd44 ldmdavc r10, {r2, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2edd48 .word 0xd1032a3e
 *   @0x2edd4c andhs r3, r0, r1, lsl #6
 *   @0x2edd50 and r9, r0, r1, lsl #6
 *   @0x2edd54 blls 0x335d68
 *   @0x2edd58 andlt r6, r2, r3, lsr r0
 *   @0x2edd5c stmvs r1, {r4, r5, r6, r8, r10, r11, r12, sp, pc}
 *   @0x2edd60 svclt #0x70f7ff
 *   @0x2edd64 .word 0x4604b510
 *   @0x2edd68 .word 0xfff9f7ff
 *   @0x2edd6c stmvs r1!, {r5, r9, r10, lr}
 *   @0x2edd70 ldrhmi lr, [r0], -sp
 *   @0x2edd74 svclt #0x22f7ff
 *   @0x2edd78 svcmi #0xf8e92d
 *   @0x2edd7c strmi r4, [r9], r0, lsl #13
 *   @0x2edd80 .word 0x469b4615
 *   @0x2edd84 mlage r8, sp, r8, pc
 *   @0x2edd88 .word 0xffe9f7ff
 *   @0x2edd8c .word 0x4000f8d8
 *   @0x2edd90 .word 0x0008f8d8
 *   @0x2edd94 subsle r4, r1, #132, #4
 *   @0x2edd98 svceq #0xf1ba
 *   @0x2edd9c stmdavc r3!, {r1, r3, r12, lr, pc}
 *   @0x2edda0 andle r2, r2, r12, lsr r11
 *   @0x2edda4 pop {r0, r1, sp}
 *   @0x2edda8 strlo r8, [r1], #-4088
 *   @0x2eddac svclt #0x284284
 *   @0x2eddb0 eorsle r2, r4, #0, #10
 *   @0x2eddb4 rsbeq r4, sp, r3, lsr #20
 *   @0x2eddb8 strhs r1, [r1], -r0, lsl #22
 *   @0x2eddbc svclt #0x2842a8
 *   @0x2eddc0 ldrbtmi r4, [r10], #-1576
 *   @0x2eddc4 strtmi r2, [pc], -r0, lsl #10
 *   @0x2eddc8 andle r4, pc, r7, lsl #5
 *   @0x2eddcc andgt pc, r7, r4, lsl r8
 *   @0x2eddd0 movweq pc, #0x91ac
 *   @0x2eddd4 ldmdble pc, {r0, r8, r9, r11, sp}
 *   @0x2eddd8 movweq pc, #0xc1ac
 *   @0x2edddc ldmdble r11, {r0, r8, r9, r11, sp}
 *   @0x2edde0 svceq #0xdff01c
 *   @0x2edde4 .word 0xf1bcd018
 *   @0x2edde8 stmdble r7, {r0, r1, r2, r3, r4, r5, r6, r8, r9, r10, r11}
 *   @0x2eddec strtmi r2, [r10], -r1, lsl #28
 *   @0x2eddf0 teqeq r6, r4, lsl r0
 *   @0x2eddf4 .word 0xf8093501
 *   @0x2eddf8 and r6, pc, r2
 *   @0x2eddfc ldcleq p0, c15, [pc], #-48
 *   @0x2ede00 andlo pc, r12, r2, lsl r9
 *   @0x2ede04 ldmle r1!, {r0, r1, r2, r3, r8, r9, r11, sp} ^
 *   @0x2ede08 strne lr, [r6], -r3, asr #20
 *   @0x2ede0c strle r0, [r3, #-0x5f3]
 *   @0x2ede10 andvs pc, r5, r9, lsl #16
 *   @0x2ede14 strhs r3, [r1], -r1, lsl #10
 *   @0x2ede18 ldrb r3, [r5, r1, lsl #14]
 *   @0x2ede1c .word 0xf8cb443c
 *   @0x2ede20 .word 0xf1ba5000
 *   @0x2ede24 andle r0, r7, r0, lsl #30
 *   @0x2ede28 .word 0x3008f8d8
 *   @0x2ede2c andle r4, r2, #156, #4
 *   @0x2ede30 blhs 0x128bec4 <b2_toiTime+0xb32a20>
 *   @0x2ede34 strlo sp, [r1], #-438
 *   @0x2ede38 andmi pc, r0, r8, asr #17
 *   @0x2ede3c ldm sp!, {sp}
 *   @0x2ede40 svclt #0x8ff8
 *   @0x2ede44 andeq r2, r10, r10, asr #19
 *   @0x2ede48 strhs r11, [r0], #-1328
 *   @0x2ede4c cps #0x4
 *   @0x2ede50 .word 0x4c080514
 *   @0x2ede54 ldrbtmi r6, [r12], #-65
 *   @0x2ede58 addvs r6, r2, r4, lsr #16
 *   @0x2ede5c mrsvs r6, apsr
 *   @0x2ede60 strgt r12, [pc, #-0xc0f]
 *   @0x2ede64 strgt r12, [pc, #-0xc0f]
 *   @0x2ede68 strgt r12, [pc, #-0xc0f]
 *   @0x2ede6c eorvs r6, r11, r3, lsr #16
 *   @0x2ede70 svclt #0xbd30
 *   @0x2ede74 andseq r3, r0, r2, ror #26
 *   @0x2ede78 ldrlt r4, [r0, #-0x770]!
 *   @0x2ede7c smlawblt r12, r4, r8, r6
 *   @0x2ede80 strbtlo r6, [r12], #-2309
 *   @0x2ede84 strgt r12, [pc], #-3343
 *   @0x2ede88 eorvs r6, r3, r11, lsr #16
 *   @0x2ede8c push {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2ede90 stmdbvs r3, {r4, r5, r6, r7, r8, r9, r10, lr} ^
 *   @0x2ede94 suble r2, r12, r0, lsl #22
 *   @0x2ede98 andlt r8, r8, #1638400
 *   @0x2ede9c stcle p8, c2, [r7, #-4]
 *   @0x2edea0 andmi pc, r0, #0, #2
 *   @0x2edea4 blo 0x38821c <_ZTS13C_UTF16String+0x1f2c8>
 *   @0x2edea8 andshs pc, r2, r4, lsr r9
 *   @0x2edeac and r3, r2, r1, lsl #4
 *   @0x2edeb0 .word 0xb141460a
 *   @0x2edeb4 rfeib r3!
 *   @0x2edeb8 adcmi r4, r2, #2
 *   @0x2edebc stmdblo r1, {r0, r1, r8, r12, lr, pc}
 *   @0x2edec0 pop {r0, r3, r4, pc}
 *   @0x2edec4 ldmdahi pc, {r4, r5, r6, r7, r8, r9, r10, pc} ^
 *   @0x2edec8 mcrhs p2, #0x0, r11, c1, c14, #0x1
 *   @0x2edecc ldmdavs r12, {r0, r2, r3, r4, r8, r10, r11, r12, lr, pc} ^
 *   @0x2eded0 strpl pc, [r0, #-0x106]
 *   @0x2eded4 .word 0xf8d33d01
 *   @0x2eded8 bl 0x41df00 <g_RomDisk+0x266e0>
 *   @0x2ededc .word 0xf85409c2
 *   @0x2edee0 bl 0x415fb0 <g_RomDisk+0x1e790>
 *   @0x2edee4 .word 0xf85408c5
 *   @0x2edee8 strmi r4, [r2, #0x35]!
 *   @0x2edeec .word 0xf8d9d10d
 *   @0x2edef0 .word 0xf8d85004
 *   @0x2edef4 adcmi r4, r5, #4
 *   @0x2edef8 strbtmi sp, [r6], #-263
 *   @0x2edefc .word 0x4c01f816
 *   @0x2edf00 svclt #0x42c01
 *   @0x2edf04 ldrblo pc, [pc, r7, lsl #2]!
 *   @0x2edf08 stmdahs r0, {r0, r1, r2, r3, r4, r6, pc}
 *   @0x2edf0c ldmdahi r12, {r0, r4, r8, r10, r11, r12, lr, pc} ^
 *   @0x2edf10 stclo p2, c11, [r1, #-148]
 *   @0x2edf14 .word 0xf10442aa
 *   @0x2edf18 strdle r3, r4, [r4, -pc]
 *   @0x2edf1c subshi r3, r10, r1, lsl #18
 *   @0x2edf20 pop {r0, r3, r4, pc}
 *   @0x2edf24 .word 0xf10087f0
 *   @0x2edf28 ldmvs r11, {lr} ^
 *   @0x2edf2c .word 0xf8233801
 *   @0x2edf30 pop {r4, sp}
 *   @0x2edf34 stmdane r3, {r4, r5, r6, r7, r8, r9, r10, pc} ^
 *   @0x2edf38 ldrlt r4, [r0, #-0x298]!
 *   @0x2edf3c bne 0x9e2794 <b2_toiTime+0x2892f0>
 *   @0x2edf40 strbtvs pc, [sp], #-1612
 *   @0x2edf44 svclt #0x94428b
 *   @0x2edf48 stmdane r1, {r0, r6, r7, r11, r12} ^
 *   @0x2edf4c andle r4, r11, r8, lsl #5
 *   @0x2edf50 b 0xfe3cbf64 <b2_toiTime+0xfffffffffdc72ac0>
 *   @0x2edf54 ldrmi r2, [r10], #-1298
 *   @0x2edf58 blpl 0x36bf60 <_ZTS13C_UTF16String+0x300c>
 *   @0x2edf5c .word 0xf5024362
 *   @0x2edf60 eorslo r4, pc, #268435467
 *   @0x2edf64 .word 0xe7f1b292
 *   @0x2edf68 movwhs r11, #0xd30
 *   @0x2edf6c bicvs r6, r3, r3, lsl #3
 *   @0x2edf70 .word 0x61036143
 *   @0x2edf74 stmdavs r3, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2edf78 .word 0x11a4f8d3
 *   @0x2edf7c .word 0x21e8f8d3
 *   @0x2edf80 .word 0xf8d36181
 *   @0x2edf84 bicvs r3, r3, r8, lsr #3
 *   @0x2edf88 qdaddvs r6, r3, r3
 *   @0x2edf8c ldrdvs r6, r7, [r3, -r3]
 *   @0x2edf90 ldrbmi r2, [r0, -r0]!
 *   @0x2edf94 .word 0xf8d36803
 *   @0x2edf98 .word 0x61022178
 *   @0x2edf9c ldrsbne pc, [r12, #-131]!
 *   @0x2edfa0 smlalbbvs r1, r2, r10, r10
 *   @0x2edfa4 .word 0x3180f8d3
 *   @0x2edfa8 andhs r6, r0, r3, lsl #3
 *   @0x2edfac movwhs r4, #0x770
 *   @0x2edfb0 smlabbvs r3, r3, r1, r6
 *   @0x2edfb4 ldrbmi r6, [r0, -r3, asr #2]!
 *   @0x2edfb8 addsmi r6, r9, #49152
 *   @0x2edfbc stmdbvs r2, {r0, r1, r2, r8, r9, r12, lr, pc} ^
 *   @0x2edfc0 addsmi r4, r9, #318767104
 *   @0x2edfc4 stmibvs r3, {r0, r1, r9, r12, lr, pc}
 *   @0x2edfc8 andseq pc, r1, r3, lsr r8
 *   @0x2edfcc andhs r4, r0, r0, ror r7
 *   @0x2edfd0 stmdavs r11, {r4, r5, r6, r8, r9, r10, lr}
 *   @0x2edfd4 ldrblt r4, [r0, #-0x602]!
 *   @0x2edfd8 stmdbvs r0, {r0, r8, r9, r12, sp}
 *   @0x2edfdc addmi r6, r3, #84, #18
 *   @0x2edfe0 .word 0x4603bf38
 *   @0x2edfe4 subseq r1, r12, r6, lsl #18
 *   @0x2edfe8 andle r4, r5, #805306379
 *   @0x2edfec blpl 0xd08648 <b2_toiTime+0x5af1a4>
 *   @0x2edff0 ldmdblt r8, {r1, r10, r12, sp}
 *   @0x2edff4 ldrb r3, [r7, r1, lsl #6]!
 *   @0x2edff8 ldrmi r2, [r8], -r0, lsl #6
 *   @0x2edffc ldcllt p0, c6, [r0, #-44]!
 *   @0x2ee000 .word 0x31a8f8d0
 *   @0x2ee004 eoreq pc, r1, r3, asr r8
 *   @0x2ee008 andeq r4, r0, r0, ror r7
 *   @0x2ee00c .word 0x4601b513
 *   @0x2ee010 andhs r6, r0, r3, lsl #16
 *   @0x2ee014 .word 0x21e8f8d3
 *   @0x2ee018 andeq lr, r9, sp, lsl #17
 *   @0x2ee01c ldmdavs r4, {r3, r4, r6, r9, r10, r11, sp, lr} ^
 *   @0x2ee020 .word 0x21a4f8d3
 *   @0x2ee024 ldrbtmi r4, [r11], #-2818
 *   @0x2ee028 andlt r4, r2, r0, lsr #15
 *   @0x2ee02c svclt #0xbd10
 *   @0x2ee030 .word 0xffffffd7
 *   @0x2ee034 stmdavs r3, {r3, r8, r10, r12, sp, pc}
 *   @0x2ee038 .word 0x31e8f8d3
 *   @0x2ee03c .word 0x4798689b
 *   @0x2ee040 strlt r11, [r8, #-0xd08]
 *   @0x2ee044 .word 0xf8d36803
 *   @0x2ee048 ldmvs r11, {r3, r5, r6, r7, r8, r12, sp} ^
 *   @0x2ee04c stclt p7, c4, [r8, #-608]
 *   @0x2ee050 svclt #0x13f7ff
 *   @0x2ee054 .word 0x4604b570
 *   @0x2ee058 bmi 0x5c836c <g_SWFlineaavertbuff+0x752a4>
 *   @0x2ee05c addsmi r6, r3, #24576
 *   @0x2ee060 shadd16mi sp, r0, r0
 *   @0x2ee064 .word 0xf7f96821
 *   @0x2ee068 strhs pc, [r0, #-0x966]
 *   @0x2ee06c stmibvs r1!, {r4, r5, r9, r10, lr}
 *   @0x2ee070 .word 0xf7f96025
 *   @0x2ee074 .word 0x61a5f960
 *   @0x2ee078 stmibvs r1!, {r4, r5, r9, r10, lr} ^
 *   @0x2ee07c .word 0xf95bf7f9
 *   @0x2ee080 rscvs r6, r5, r5, ror #3
 *   @0x2ee084 svclt #0xbd70
 *   @0x2ee088 cdple p14, #0xa, c11, c13, c15, #0x7
 *   @0x2ee08c .word 0x4604b510
 *   @0x2ee090 .word 0xf7f9c803
 *   @0x2ee094 movwhs pc, #0x950
 *   @0x2ee098 ldclt p0, c6, [r0, #-396]
 *   @0x2ee09c .word 0x4604b510
 *   @0x2ee0a0 stmdbvs r1!, {r0, r1, r11, sp, lr} ^
 *   @0x2ee0a4 .word 0xf7f96e58
 *   @0x2ee0a8 movwhs pc, #0x946
 *   @0x2ee0ac .word 0x61236163
 *   @0x2ee0b0 ldrblt r11, [r3, #-0xd10]!
 *   @0x2ee0b4 stmdavs r5, {r2, r9, r10, lr}
 *   @0x2ee0b8 .word 0xb1ad6a06
 *   @0x2ee0bc stmdavs r1!, {r4, r5, r9, r10, lr} ^
 *   @0x2ee0c0 .word 0xf7f9aa01
 *   @0x2ee0c4 blls 0x36c18c <_ZTS13C_UTF16String+0x3238>
 *   @0x2ee0c8 stmdblt r11!, {r5, sp, lr} ^
 *   @0x2ee0cc stmdavs r2!, {r0, r3, r5, r9, r10, lr} ^
 *   @0x2ee0d0 b 0x202b7f8 <b2_toiTime+0x18d2354>
 *   @0x2ee0d4 strtmi r4, [r9], -r0, lsr #12
 *   @0x2ee0d8 stc2 p7, c15, [r3, #1020]!
 *   @0x2ee0dc ldrtmi r6, [r0], -r3, ror #16
 *   @0x2ee0e0 adcvs r4, r3, r9, lsr #12
 *   @0x2ee0e4 .word 0xf927f7f9
 *   @0x2ee0e8 ldcllt p0, c11, [r0, #-8]!
 *   @0x2ee0ec mvnsmi lr, sp, lsr #18
 *   @0x2ee0f0 strmi r4, [lr], -r5, lsl #12
 *   @0x2ee0f4 ldrmi r4, [r7], -r8, lsl #12
 *   @0x2ee0f8 bge 0x336540
 *   @0x2ee0fc .word 0xf7f94698
 *   @0x2ee100 .word 0x4604f812
 *   @0x2ee104 stmdblt r8, {r0, r11, r12, pc} ^
 *   @0x2ee108 movwhs r6, #0x2067
 *   @0x2ee10c .word 0xf8c46027
 *   @0x2ee110 rscvs r8, r3, r8
 *   @0x2ee114 rsbvs r6, r12, lr, lsr #32
 *   @0x2ee118 rscvs r6, r8, r8, lsr #1
 *   @0x2ee11c pop {r1, r12, sp, pc}
 *   @0x2ee120 strdeq r8, r9, [r0], -r0
 *   @0x2ee124 strdlt r11, r12, [r5], r0
 *   @0x2ee128 strmi r4, [pc], -r4, lsl #12
 *   @0x2ee12c eorvs r4, r2, #23068672
 *   @0x2ee130 andhs r10, r0, #3, #26
 *   @0x2ee134 ldrtmi r9, [r0], -r1, lsl #10
 *   @0x2ee138 .word 0x21049200
 *   @0x2ee13c .word 0xf7f9463b
 *   @0x2ee140 bls 0x3edfe0
 *   @0x2ee144 stmiblt r2, {r5, r7, r8, sp, lr} ^
 *   @0x2ee148 eoreq lr, r4, sp, lsl #17
 *   @0x2ee14c .word 0x21044630
 *   @0x2ee150 .word 0xf7f9463b
 *   @0x2ee154 stcls p15, c15, [r3, #-624]
 *   @0x2ee158 ldmdblt r5!, {r5, r6, r7, r8, sp, lr} ^
 *   @0x2ee15c .word 0x61654b0c
 *   @0x2ee160 rscvs r6, r3, r5, lsr #32
 *   @0x2ee164 adcvs r4, r5, r11, lsl #22
 *   @0x2ee168 ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x2ee16c .word 0xf1046065
 *   @0x2ee170 .word 0x61270524
 *   @0x2ee174 stm r5, {r0, r1, r2, r3, r8, r9, r11, lr, pc}
 *   @0x2ee178 blls 0x3ae1bc <error_g0017+0x6e60>
 *   @0x2ee17c ldrtmi r11, [r0], -r11, lsr #2
 *   @0x2ee180 .word 0xf7f969a1
 *   @0x2ee184 movwhs pc, #0x8d8
 *   @0x2ee188 stmdals r3, {r0, r1, r5, r7, r8, sp, lr}
 *   @0x2ee18c ldcllt p0, c11, [r0, #20]!
 *   @0x2ee190 cdple p14, #0xa, c11, c13, c15, #0x7
 *   @0x2ee194 andseq r3, r0, r4, asr r10
 *   @0x2ee198 ldrbmi lr, [r0, sp, lsr #18]!
 *   @0x2ee19c .word 0xf890469a
 *   @0x2ee1a0 ldrmi r3, [r1], r4, asr #32
 *   @0x2ee1a4 bicslt r6, r3, r4, asr #18
 *   @0x2ee1a8 rfeib r4!
 *   @0x2ee1ac stmdavs r6!, {r1, r12, lr} ^
 *   @0x2ee1b0 svceq #0xf1ba
 *   @0x2ee1b4 .word 0xf04fbf0c
 *   @0x2ee1b8 .word 0xf04f0a02
 *   @0x2ee1bc stmvs r7!, {r0, r9, r11}
 *   @0x2ee1c0 stc2 p7, c15, [r12, #984]!
 *   @0x2ee1c4 stmeq r5, {r1, r2, r8, r9, r11, sp, lr, pc} ^
 *   @0x2ee1c8 .word 0xf8461400
 *   @0x2ee1cc .word 0x46480035
 *   @0x2ee1d0 stc2 p7, c15, [r4, #984]!
 *   @0x2ee1d4 .word 0xf8c81400
 *   @0x2ee1d8 .word 0xf8070004
 *   @0x2ee1dc stmdahi r3!, {r0, r2, sp, pc} ^
 *   @0x2ee1e0 rsbhi r3, r3, r1, lsl #6
 *   @0x2ee1e4 .word 0x87f0e8bd
 *   @0x2ee1e8 svcmi #0xf0e92d
 *   @0x2ee1ec stmdavs r3, {r0, r2, r7, r12, sp, pc}
 *   @0x2ee1f0 strmi r4, [r8], r3, lsl #13
 *   @0x2ee1f4 addmi r4, r11, #24117248
 *   @0x2ee1f8 movwle r9, #0x1303
 *   @0x2ee1fc sbcs r2, r11, r0
 *   @0x2ee200 mulge r0, r3, r8
 *   @0x2ee204 svceq #0x2df1ba
 *   @0x2ee208 .word 0xf1bad002
 *   @0x2ee20c .word 0xd10a0f2b
 *   @0x2ee210 eoreq pc, sp, #-2147483602
 *   @0x2ee214 .word 0xf1d23301
 *   @0x2ee218 movwls r0, #0x3a00
 *   @0x2ee21c beq 0x3a8f8c <error_g0017+0x1c30>
 *   @0x2ee220 .word 0xd1024543
 *   @0x2ee224 .word 0xf04fe7ea
 *   @0x2ee228 vstrls s0, [r3, #-0]
 *   @0x2ee22c blhs 0xe8c2e0 <b2_toiTime+0x732e3c>
 *   @0x2ee230 stmdage r3, {r1, r2, r3, r12, lr, pc}
 *   @0x2ee234 .word 0xf7ff4641
 *   @0x2ee238 blls 0x3ed544 <_ZTIPw>
 *   @0x2ee23c strmi r4, [r4], -r11, lsr #5
 *   @0x2ee240 .word 0xf5b0d0dc
 *   @0x2ee244 ble 0x4c1e4c <SrcVerts+0x1ee90>
 *   @0x2ee248 .word 0xf04f0404
 *   @0x2ee24c and r0, r5, r0, lsl #18
 *   @0x2ee250 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2ee254 and r4, r1, r12, asr #12
 *   @0x2ee258 stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2ee25c strbmi r9, [r3, #-0xb03]
 *   @0x2ee260 ldmdavc r10, {r0, r1, r2, r4, r5, r9, r12, lr, pc}
 *   @0x2ee264 teqle r4, lr, lsr #20
 *   @0x2ee268 movwlo r4, #0x1955
 *   @0x2ee26c strhs r9, [r1], -r3, lsl #6
 *   @0x2ee270 strhs r4, [r0, #-0xb54]
 *   @0x2ee274 ldrbtmi r2, [r11], #-10
 *   @0x2ee278 bls 0x3d2e84 <error_g0017+0x2bb28>
 *   @0x2ee27c eorle r4, r10, #276824064
 *   @0x2ee280 blhs 0xb0c2d4 <b2_toiTime+0x3b2e30>
 *   @0x2ee284 .word 0xf1a3d027
 *   @0x2ee288 .word 0xf1bc0c09
 *   @0x2ee28c stmdble r2!, {r0, r8, r9, r10, r11}
 *   @0x2ee290 .word 0x0c0cf1a3
 *   @0x2ee294 svceq #0x1f1bc
 *   @0x2ee298 blx 0x16e4714 <b2_toiTime+0xf8b270>
 *   @0x2ee29c .word 0xf1bcfc83
 *   @0x2ee2a0 ldcle p15, c0, [r8, #-0]
 *   @0x2ee2a4 .word 0xc004f8dd
 *   @0x2ee2a8 andlo pc, r3, r12, lsl r8
 *   @0x2ee2ac ldmdale r2, {r0, r3, r8, r9, r11, sp}
 *   @0x2ee2b0 .word 0xdc0b428e
 *   @0x2ee2b4 .word 0xdc09428d
 *   @0x2ee2b8 blx 0x31ac2e <__muldf3+0xfa>
 *   @0x2ee2bc ldmdblt r12, {r0, r2, r8, r10, r12, sp}
 *   @0x2ee2c0 stcle p15, c2, [r1, #-0]
 *   @0x2ee2c4 and r3, r1, r1, lsl #30
 *   @0x2ee2c8 cmpmi lr, #671088640
 *   @0x2ee2cc andls r3, r3, #268435456
 *   @0x2ee2d0 .word 0x2601e7d3
 *   @0x2ee2d4 bls 0x3b76dc <error_g0017+0x10380>
 *   @0x2ee2d8 strbmi r1, [r3, #-0xc53]
 *   @0x2ee2dc ldmdavc r2, {r0, r1, r2, r4, r9, r12, lr, pc}
 *   @0x2ee2e0 sbcseq pc, pc, #2
 *   @0x2ee2e4 tstle r2, r5, asr #20
 *   @0x2ee2e8 strbmi r10, [r1], -r4, lsl #16
 *   @0x2ee2ec stclo p8, c15, [r4, #-256]
 *   @0x2ee2f0 .word 0xf7ff9300
 *   @0x2ee2f4 bls 0x3ed488 <_ZTIPh+0xc>
 *   @0x2ee2f8 addsmi r9, r3, #0, #22
 *   @0x2ee2fc svcge #0x7ef43f
 *   @0x2ee300 svcvc #0x7af5b0
 *   @0x2ee304 .word 0xf510dc05
 *   @0x2ee308 blle 0x48e0f8 <prim_v+0x4744>
 *   @0x2ee30c movwhs r4, #0x407
 *   @0x2ee310 movwhs lr, #0x4
 *   @0x2ee314 stmdbeq r1, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2ee318 movwhs lr, #0x1000
 *   @0x2ee31c .word 0xf8cb9a03
 *   @0x2ee320 ldmdblt r4, {sp}
 *   @0x2ee324 .word 0xf43f2d00
 *   @0x2ee328 .word 0xf1b9af69
 *   @0x2ee32c teqle r11, r0, lsl #30
 *   @0x2ee330 .word 0xf47f2b00
 *   @0x2ee334 .word 0xf8dfaf63
 *   @0x2ee338 .word 0xf04f8088
 *   @0x2ee33c svchs #0x90a
 *   @0x2ee340 strbmi sp, [r4, #-0xd11]
 *   @0x2ee344 strbmi sp, [r5, #-0xc30]
 *   @0x2ee348 .word 0xf404fb09
 *   @0x2ee34c cdphs p13, #0x0, c13, c1, c7, #0x0
 *   @0x2ee350 ldrtmi sp, [r0], -r10, lsr #32
 *   @0x2ee354 .word 0xf02a210a
 *   @0x2ee358 .word 0x4606ecdc
 *   @0x2ee35c blx 0x56636a <g_SWFlineaavertbuff+0x132a2>
 *   @0x2ee360 svclo #0x1f505
 *   @0x2ee364 .word 0xf8dfe7eb
 *   @0x2ee368 .word 0xf04f9058
 *   @0x2ee36c .word 0xb1a7080a
 *   @0x2ee370 .word 0x210a4620
 *   @0x2ee374 stcl p0, c15, [r12], {42}
 *   @0x2ee378 strmi r4, [r4], -lr, asr #10
 *   @0x2ee37c blx 0x52538e <SrcVerts+0x823d2>
 *   @0x2ee380 and pc, r4, r6, lsl #12
 *   @0x2ee384 .word 0x210a4628
 *   @0x2ee388 stcl p0, c15, [r2], {42}
 *   @0x2ee38c ldmdblt r4, {r0, r2, r9, r10, lr}
 *   @0x2ee390 .word 0xf43f2d00
 *   @0x2ee394 smladxlo r1, r3, pc, r10
 *   @0x2ee398 teqlt sp, r9, ror #15
 *   @0x2ee39c ldrtmi r4, [r1], -r8, lsr #12
 *   @0x2ee3a0 stc2 p7, c15, [r9, #984]
 *   @0x2ee3a4 and r4, r1, r4, lsl #8
 *   @0x2ee3a8 strmi pc, [r0], #-111
 *   @0x2ee3ac svceq #0xf1ba
 *   @0x2ee3b0 rsbmi sp, r0, #1
 *   @0x2ee3b4 strtmi lr, [r0], -r0
 *   @0x2ee3b8 pop {r0, r2, r12, sp, pc}
 *   @0x2ee3bc svclt #0x8ff0
 *   @0x2ee3c0 stcleq p12, c12, [r12], {203}
 *   @0x2ee3c4 andeq r2, r10, r6, lsl r5
 *   @0x2ee3c8 svcmi #0xf0e92d
 *   @0x2ee3cc stmdavs r3, {r0, r3, r4, r7, r9, r10, lr}
 *   @0x2ee3d0 strmi r11, [r7], -r5, lsl #1
 *   @0x2ee3d4 addmi r4, r11, #13631488
 *   @0x2ee3d8 movwls r4, #0x2693
 *   @0x2ee3dc ldmdavc r10, {r3, r4, r5, r9, r12, lr, pc}
 *   @0x2ee3e0 eorsle r2, r7, r11, asr r10
 *   @0x2ee3e4 svclt #0x82a7b
 *   @0x2ee3e8 eorsle r2, r4, sp, ror r6
 *   @0x2ee3ec .word 0xf10d2600
 *   @0x2ee3f0 strhs r0, [r0], #-2568
 *   @0x2ee3f4 adcmi r9, r11, #2048
 *   @0x2ee3f8 uasxmi sp, r0, r0
 *   @0x2ee3fc .word 0xf7ff4629
 *   @0x2ee400 .word 0xf8ddfc21
 *   @0x2ee404 strmi r8, [r8, #0x8]!
 *   @0x2ee408 .word 0xf898d228
 *   @0x2ee40c adcsmi r2, r2, #0
 *   @0x2ee410 .word 0xf108d103
 *   @0x2ee414 movwls r0, #0x2301
 *   @0x2ee418 .word 0xf1b9e020
 *   @0x2ee41c andle r0, r4, r0, lsl #30
 *   @0x2ee420 ble 0x9bf998 <b2_toiTime+0x2664f4>
 *   @0x2ee424 orreq lr, r4, #9216
 *   @0x2ee428 blge 0x3e6430 <error_g0017+0x3f0d4>
 *   @0x2ee42c ldrbmi r9, [r0], -lr, lsl #20
 *   @0x2ee430 movwls r4, #0x1629
 *   @0x2ee434 mrc2 p7, #0x6, apsr_nzcv, c8, c15, #0x7
 *   @0x2ee438 blls 0x354c48
 *   @0x2ee43c mulsvs r8, r0, r5
 *   @0x2ee440 strlo sp, [r1], #-3
 *   @0x2ee444 bicsle r2, r5, r0, lsl #28
 *   @0x2ee448 .word 0xf04fe008
 *   @0x2ee44c strd r3, r4, [r5], -pc
 *   @0x2ee450 and r2, r3, r0, lsl #8
 *   @0x2ee454 movwlo r2, #0x165d
 *   @0x2ee458 strb r9, [r8, r2, lsl #6]
 *   @0x2ee45c strtmi r9, [r0], -r2, lsl #22
 *   @0x2ee460 andlt r6, r5, r11, lsr r0
 *   @0x2ee464 svchi #0xf0e8bd
 *   @0x2ee468 .word 0x4606b5f7
 *   @0x2ee46c ldrmi r4, [r4], -sp, lsl #12
 *   @0x2ee470 .word 0xf7ff461f
 *   @0x2ee474 smusdxls r0, r4, r12
 *   @0x2ee478 ldmvs r1!, {r4, r5, r9, r10, lr}
 *   @0x2ee47c strtmi r4, [r3], -r10, lsr #12
 *   @0x2ee480 .word 0xffa2f7ff
 *   @0x2ee484 ldcllt p0, c11, [r0, #12]!
 *   @0x2ee488 svcmi #0xf0e92d
 *   @0x2ee48c addlt r4, r5, r0, lsl #13
 *   @0x2ee490 ldrmi r4, [r1], r10, lsl #13
 *   @0x2ee494 stc2l p7, c15, [r3], #-1020
 *   @0x2ee498 .word 0x3000f8d8
 *   @0x2ee49c .word 0x5008f8d8
 *   @0x2ee4a0 movwls r4, #0x32ab
 *   @0x2ee4a4 ldmdavc r10, {r0, r1, r2, r4, r5, r9, r12, lr, pc}
 *   @0x2ee4a8 eorsle r2, r6, r11, asr r10
 *   @0x2ee4ac svclt #0x82a7b
 *   @0x2ee4b0 eorsle r2, r3, sp, ror r6
 *   @0x2ee4b4 .word 0xf10d2600
 *   @0x2ee4b8 strhs r0, [r0], #-2828
 *   @0x2ee4bc adcmi r9, r11, #3072
 *   @0x2ee4c0 ldrbmi sp, [r8], -pc, lsr #4
 *   @0x2ee4c4 .word 0xf7ff4629
 *   @0x2ee4c8 svcls #0x3fbbd
 *   @0x2ee4cc eorle r4, r8, #-268435446
 *   @0x2ee4d0 adcsmi r7, r3, #3866624
 *   @0x2ee4d4 strlo sp, [r1, -r2, lsl #2]
 *   @0x2ee4d8 eor r9, r2, r3, lsl #14
 *   @0x2ee4dc svceq #0xf1b9
 *   @0x2ee4e0 ldrbmi sp, [r4, #-0x4]
 *   @0x2ee4e4 bl 0x564d60 <g_SWFlineaavertbuff+0x11c98>
 *   @0x2ee4e8 and r0, r1, r4, asr #6
 *   @0x2ee4ec movweq pc, #0xa10d
 *   @0x2ee4f0 qsaxmi r4, r9, r8
 *   @0x2ee4f4 movwls r2, #0x1200
 *   @0x2ee4f8 mrc2 p7, #0x3, apsr_nzcv, c6, c15, #0x7
 *   @0x2ee4fc strne r9, [r0], #-2817
 *   @0x2ee500 blls 0x3ce568 <error_g0017+0x2720c>
 *   @0x2ee504 mulle r3, pc, r2
 *   @0x2ee508 cdphs p4, #0x0, c3, c0, c1, #0x0
 *   @0x2ee50c ldrd sp, lr, [r8], -r6
 *   @0x2ee510 ldrbtlo pc, [pc], #79
 *   @0x2ee514 strhs lr, [r0], #-5
 *   @0x2ee518 ldrbhs lr, [sp], -r3
 *   @0x2ee51c movwls r3, #0x3301
 *   @0x2ee520 blls 0x3e844c <error_g0017+0x410f0>
 *   @0x2ee524 .word 0xf8c84620
 *   @0x2ee528 andlt r3, r5, r0
 *   @0x2ee52c svchi #0xf0e8bd
 *   @0x2ee530 .word 0x4605b538
 *   @0x2ee534 .word 0xf7ff460c
 *   @0x2ee538 qadd16mi pc, r8, r2
 *   @0x2ee53c strtmi r6, [r2], -r9, lsr #17
 *   @0x2ee540 ldrhtmi lr, [r8], -sp
 *   @0x2ee544 mrclt p7, #0x2, apsr_nzcv, c0, c15, #0x7
 *   @0x2ee548 stmdbvs r4, {r4, r8, r10, r12, sp, pc} ^
 *   @0x2ee54c .word 0xf890b354
 *   @0x2ee550 stmdblt r3!, {r2, r6, r12, sp}
 *   @0x2ee554 ldrmi r8, [r8], -r2, lsr #16
 *   @0x2ee558 eorhi r3, r2, r1, lsl #4
 *   @0x2ee55c stmvs r0, {r4, r8, r10, r11, r12, sp, pc} ^
 *   @0x2ee560 ldrhtlo pc, [r8], -r0
 *   @0x2ee564 ldrhhs pc, [r4], -r0
 *   @0x2ee568 stmvs r3, {r1, r3, r4, r10, lr}
 *   @0x2ee56c addsmi r3, r10, #268435456
 *   @0x2ee570 rfeib r4!
 *   @0x2ee574 blhs 0x2fa57c <ps_hints_apply+0x917c>
 *   @0x2ee578 .word 0xf103dd0f
 *   @0x2ee57c stmvs r2!, {r8, r9, lr} ^
 *   @0x2ee580 bllo 0x35070c
 *   @0x2ee584 .word 0xf8223901
 *   @0x2ee588 and r1, r6, r3, lsl r0
 *   @0x2ee58c andhs r2, r1, #0, #2
 *   @0x2ee590 ldc2 p7, c15, [r9, #996]!
 *   @0x2ee594 rscle r2, r12, r0, lsl #16
 *   @0x2ee598 stmdahi r3!, {r4, r8, r10, r11, r12, sp, pc}
 *   @0x2ee59c movwlo r2, #0x1000
 *   @0x2ee5a0 ldclt p0, c8, [r0, #-140]
 *   @0x2ee5a4 ldclt p0, c2, [r0, #-12]
 *   @0x2ee5a8 ssub8mi r11, sp, r8
 *   @0x2ee5ac movwhs r2, #0x1600
 *   @0x2ee5b0 strmi r6, [r4], -r6, lsl #8
 *   @0x2ee5b4 sublo pc, r4, r0, lsl #17
 *   @0x2ee5b8 subvs r4, r1, r7, lsl r6
 *   @0x2ee5bc cdpvs p0, #0x4, c6, c11, c5, #0x4
 *   @0x2ee5c0 .word 0xb1b56003
 *   @0x2ee5c4 ldrsblo pc, [r12], r5
 *   @0x2ee5c8 .word 0xf1006818
 *   @0x2ee5cc .word 0x61230314
 *   @0x2ee5d0 .word 0xf10060e0
 *   @0x2ee5d4 .word 0x61630338
 *   @0x2ee5d8 mrc2 p7, #0x3, apsr_nzcv, c0, c6, #0x7
 *   @0x2ee5dc ldmdavs r11, {r0, r1, r3, r4, r5, r7, r9, r11, sp, lr}
 *   @0x2ee5e0 strbtvs r6, [r3], #1190
 *   @0x2ee5e4 mulslo r8, sp, r8
 *   @0x2ee5e8 .word 0xf8d5b11b
 *   @0x2ee5ec bvs 0x19ba864 <b2_toiTime+0x12613c0>
 *   @0x2ee5f0 stcmi p4, c6, [r11, #-652]
 *   @0x2ee5f4 .word 0x61a32300
 *   @0x2ee5f8 ldrbtmi r3, [sp], #-1104
 *   @0x2ee5fc .word 0xf844682d
 *   @0x2ee600 .word 0xf8443c34
 *   @0x2ee604 .word 0xf8443c30
 *   @0x2ee608 .word 0xf8443c2c
 *   @0x2ee60c .word 0xf8443c28
 *   @0x2ee610 stcgt p12, c3, [pc, #-144]
 *   @0x2ee614 ldm r5, {r0, r1, r2, r3, r10, lr, pc}
 *   @0x2ee618 stm r4, {r0, r1, r2, r3}
 *   @0x2ee61c ldcllt p0, c0, [r8, #60]!
 *   @0x2ee620 andseq r3, r0, r6, asr #11
 *   @0x2ee624 ldrblt r2, [r8, #0x9ff]!
 *   @0x2ee628 .word 0xf8d04605
 *   @0x2ee62c stmdble r2, {r2, r6, r8, r10, r12, sp}
 *   @0x2ee630 rscslo pc, pc, pc, asr #32
 *   @0x2ee634 ldmibvs r10, {r3, r4, r5, r6, r7, r8, r10, r11, r12, sp, pc}
 *   @0x2ee638 ldmdbvs r11, {r10, sp} ^
 *   @0x2ee63c andseq pc, r1, r2, lsr r8
 *   @0x2ee640 .word 0xf8d54798
 *   @0x2ee644 strmi r7, [r6], -r8, asr #10
 *   @0x2ee648 ldrhtle r4, [r1], #44
 *   @0x2ee64c strblo pc, [r12, #-0x8d5]
 *   @0x2ee650 eoreq pc, r4, r3, asr r8
 *   @0x2ee654 stmdavc r1, {r3, r6, r8, r12, sp, pc}
 *   @0x2ee658 addsmi r7, r1, #3276800
 *   @0x2ee65c ldrtmi sp, [r1], -r5, lsl #2
 *   @0x2ee660 svc #0x88f5c7
 *   @0x2ee664 strtmi r11, [r0], -r8, lsl #18
 *   @0x2ee668 strlo r11, [r1], #-3576
 *   @0x2ee66c andeq lr, r0, r12, ror #15
 *   @0x2ee670 .word 0x460db5f7
 *   @0x2ee674 .word 0x21004616
 *   @0x2ee678 adcsvs pc, r12, #1325400064
 *   @0x2ee67c ldrmi r4, [pc], -r4, lsl #12
 *   @0x2ee680 svc #0x96f5c7
 *   @0x2ee684 andhs r4, r1, #376832
 *   @0x2ee688 ldrbtmi r6, [r9], #-3624
 *   @0x2ee68c mrrc2 p7, #0xf, pc, r3, c7
 *   @0x2ee690 .word 0xf89db320
 *   @0x2ee694 strtmi r3, [r9], -r8, lsr #32
 *   @0x2ee698 strbeq pc, [r4, #-0x8c4]
 *   @0x2ee69c qasxmi r4, r0, r2
 *   @0x2ee6a0 ldrtvs pc, [r9], #1284
 *   @0x2ee6a4 ldrtmi r9, [r11], -r0, lsl #6
 *   @0x2ee6a8 .word 0xff7ef7ff
 *   @0x2ee6ac .word 0xf844692b
 *   @0x2ee6b0 blls 0x4fd8b8 <SrcVerts+0x5a8fc>
 *   @0x2ee6b4 ldcllo p8, c15, [r12], #-272
 *   @0x2ee6b8 .word 0xf8449b0b
 *   @0x2ee6bc blls 0x53d6e4 <obj_has_event+0x2b74>
 *   @0x2ee6c0 .word 0x3c0cf844
 *   @0x2ee6c4 .word 0xf8449b0c
 *   @0x2ee6c8 blmi 0x4bd6e0 <SrcVerts+0x1a724>
 *   @0x2ee6cc ldmdavs r11, {r0, r1, r3, r4, r5, r6, r10, lr}
 *   @0x2ee6d0 muleq r7, r3, r8
 *   @0x2ee6d4 andeq lr, r7, r4, lsl #17
 *   @0x2ee6d8 and r2, r0, r0
 *   @0x2ee6dc andlt r2, r3, r7
 *   @0x2ee6e0 svclt #0xbdf0
 *   @0x2ee6e4 andeq r0, r10, pc, lsr #4
 *   @0x2ee6e8 ldrsheq r3, [r0], -r8
 *   @0x2ee6ec .word 0x43f8e92d
 *   @0x2ee6f0 .word 0xf8df4606
 *   @0x2ee6f4 strmi r9, [r8], r4, asr #32
 *   @0x2ee6f8 strhs r4, [r0], #-3856
 *   @0x2ee6fc ldrbtmi r7, [r9], #2053
 *   @0x2ee700 .word 0xf859447f
 *   @0x2ee704 ldmdavc r11, {r2, r5, r12, sp}
 *   @0x2ee708 smlatble pc, r11, r2, r4
 *   @0x2ee70c eoreq pc, r4, r7, asr r8
 *   @0x2ee710 adcmi r7, r11, #196608
 *   @0x2ee714 ldrtmi sp, [r1], -sp, lsl #2
 *   @0x2ee718 .word 0xf5c74642
 *   @0x2ee71c ldmdblt r0, {r1, r5, r6, r8, r9, r10, r11, sp, lr, pc}
 *   @0x2ee720 pop {r5, r9, r10, lr}
 *   @0x2ee724 strlo r8, [r1], #-1016
 *   @0x2ee728 mvnle r2, r10, asr #24
 *   @0x2ee72c mcrrhs p4, #0x0, r3, r9, c1
 *   @0x2ee730 subhs sp, r11, r7, ror #27
 *   @0x2ee734 .word 0x83f8e8bd
 *   @0x2ee738 andeq r10, pc, r10, ror #8
 *   @0x2ee73c andeq r10, pc, r8, ror #8
 *   @0x2ee740 stmdavs r3, {r1, r7, r11, sp, lr}
 *   @0x2ee744 andsle r4, r5, #805306377
 *   @0x2ee748 andvs r1, r1, r9, asr r12
 *   @0x2ee74c blhs 0xb0c7c0 <b2_toiTime+0x3b331c>
 *   @0x2ee750 blhs 0x562b34 <g_SWFlineaavertbuff+0xfa6c>
 *   @0x2ee754 blhs 0x662b30 <g_SWFlinevertbuff+0xfa68>
 *   @0x2ee758 blhs 0x5a2764 <g_SWFlineaavertbuff+0x4f69c>
 *   @0x2ee75c andhs sp, r2, #1073741824
 *   @0x2ee760 blhs 0x11e6794 <b2_toiTime+0xa8d2f0>
 *   @0x2ee764 andhs sp, r1, #1073741824
 *   @0x2ee768 mrrcne p0, #0x0, lr, r10, c7
 *   @0x2ee76c blhs 0x9a2784 <b2_toiTime+0x2492e0>
 *   @0x2ee770 and sp, r1, r4, lsl #2
 *   @0x2ee774 .word 0x33fff04f
 *   @0x2ee778 sbcvs r2, r2, r3, lsl #4
 *   @0x2ee77c .word 0x47704618
 *   @0x2ee780 .word 0x4604b510
 *   @0x2ee784 blhs 0x308a98 <TT_New_Context+0x8890>
 *   @0x2ee788 .word 0xf7ffdc01
 *   @0x2ee78c stmvs r3!, {r0, r3, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2ee790 .word 0xdc142b01
 *   @0x2ee794 stmvs r2!, {r5, r11, sp, lr}
 *   @0x2ee798 addsmi r6, r3, #2293760
 *   @0x2ee79c movwhs sp, #0x3301
 *   @0x2ee7a0 mrrcne p0, #0x0, lr, r9, c7
 *   @0x2ee7a4 ldmdavc r11, {r0, r5, sp, lr}
 *   @0x2ee7a8 andle r2, r1, sp, lsl #22
 *   @0x2ee7ac .word 0xd1032b0a
 *   @0x2ee7b0 rscvs r2, r3, r2, lsl #6
 *   @0x2ee7b4 ldclt p8, c3, [r0, #-4]
 *   @0x2ee7b8 mvnle r2, r10, lsl r11
 *   @0x2ee7bc andhs lr, r0, pc, ror #15
 *   @0x2ee7c0 push {r4, r8, r10, r11, r12, sp, pc}
 *   @0x2ee7c4 .word 0xf1b14ff7
 *   @0x2ee7c8 strmi r0, [r4], -r0, lsl #20
 *   @0x2ee7cc .word 0x46984691
 *   @0x2ee7d0 stmdbvs r3, {r0, r4, r6, r8, r9, r11, r12, lr, pc}
 *   @0x2ee7d4 ble 0x167fe44 <b2_toiTime+0xf269a0>
 *   @0x2ee7d8 stmvs r5, {r0, r1, r6, r11, sp, lr}
 *   @0x2ee7dc adcmi r4, r11, #1124073472
 *   @0x2ee7e0 stmdavs r6, {r2, r4, r5, r8, r11, r12, lr, pc}
 *   @0x2ee7e4 strle r1, [r4], #-2967
 *   @0x2ee7e8 svclt #0x2842af
 *   @0x2ee7ec ldrblo pc, [pc, pc, asr #32]!
 *   @0x2ee7f0 .word 0xf04fe001
 *   @0x2ee7f4 addsmi r3, sp, #66846720
 *   @0x2ee7f8 .word 0xf505d208
 *   @0x2ee7fc bl 0x387204 <_ZTS13C_UTF16String+0x1e2b0>
 *   @0x2ee800 vld3.32 {d0, d2, d4}, [r5:64], r5
 *   @0x2ee804 .word 0xf025757f
 *   @0x2ee808 ldrb r0, [r4, r3, lsl #10]!
 *   @0x2ee80c .word 0xb020f8d4
 *   @0x2ee810 bge 0x3400bc
 *   @0x2ee814 .word 0xf7f84658
 *   @0x2ee818 blls 0x36da38 <_ZTS13C_UTF16String+0x4ae4>
 *   @0x2ee81c tstlt r3, r0, lsr #32
 *   @0x2ee820 ldrmi r6, [r8], -r6, lsr #32
 *   @0x2ee824 cmplt lr, r8, lsr #32
 *   @0x2ee828 stmvs r2!, {r0, r4, r5, r9, r10, lr}
 *   @0x2ee82c cdp p5, #0xc, c15, c6, c7, #0x6
 *   @0x2ee830 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2ee834 .word 0xf9f5f7ff
 *   @0x2ee838 shsaxmi r4, r1, r8
 *   @0x2ee83c ldc2l p7, c15, [r11, #-992]!
 *   @0x2ee840 adcvs r1, r5, r11, ror r12
 *   @0x2ee844 stmdavs r3!, {r2, r3, r4, r8, r9, r10, r11, r12, sp, pc}
 *   @0x2ee848 stmdbeq r7, {r0, r1, r8, r9, r11, sp, lr, pc}
 *   @0x2ee84c ldm r4, {r0, r1, r5, r7, r8, r11, sp, lr}
 *   @0x2ee850 strmi r0, [r10], #-6
 *   @0x2ee854 eorhs pc, r10, r3, asr #16
 *   @0x2ee858 strbmi r6, [r9], -r3, ror #19
 *   @0x2ee85c .word 0xf8434642
 *   @0x2ee860 ldm r4, {r1, r3, r5, pc}
 *   @0x2ee864 ldrmi r0, [r8], #-9
 *   @0x2ee868 cdp p5, #0xa, c15, c8, c7, #0x6
 *   @0x2ee86c andhs r6, r0, r3, ror #16
 *   @0x2ee870 rsbvs r4, r3, r3, asr #8
 *   @0x2ee874 andhs lr, r6, r0
 *   @0x2ee878 pop {r0, r1, r12, sp, pc}
 *   @0x2ee87c stmvs r0, {r4, r5, r6, r7, r8, r9, r10, r11, pc} ^
 *   @0x2ee880 ldrhlo pc, [r6], -r0
 *   @0x2ee884 ldrhths pc, [r10], -r0
 *   @0x2ee888 stmdavs r3, {r1, r3, r4, r10, lr} ^
 *   @0x2ee88c addsmi r4, r10, #167772160
 *   @0x2ee890 andhs sp, r0, #32768
 *   @0x2ee894 ldclt p7, c15, [r7], #-996
 *   @0x2ee898 ldrbmi r2, [r0, -r0]!
 *   @0x2ee89c .word 0xf7ffb109
 *   @0x2ee8a0 strmi r11, [r8], -lr, ror #31
 *   @0x2ee8a4 ldmibhs pc!, {r4, r5, r6, r8, r9, r10, lr} ^
 *   @0x2ee8a8 .word 0x4605b5f8
 *   @0x2ee8ac stmdbvs r2, {r0, r1, r2, r4, r11, r12, lr, pc}
 *   @0x2ee8b0 stmdbvs r3, {r10, sp} ^
 *   @0x2ee8b4 andseq pc, r1, r2, lsr r8
 *   @0x2ee8b8 stmibvs pc!, {r3, r4, r7, r8, r9, r10, lr}
 *   @0x2ee8bc adcsmi r4, r12, #6291456
 *   @0x2ee8c0 stmibvs r11!, {r0, r2, r3, r12, lr, pc} ^
 *   @0x2ee8c4 eoreq pc, r4, r3, asr r8
 *   @0x2ee8c8 stmdavc r1, {r3, r4, r5, r8, r12, sp, pc}
 *   @0x2ee8cc addsmi r7, r1, #3276800
 *   @0x2ee8d0 ldrtmi sp, [r1], -r3, lsl #2
 *   @0x2ee8d4 cdp p5, #0x4, c15, c14, c7, #0x6
 *   @0x2ee8d8 strlo r11, [r1], #-272
 *   @0x2ee8dc strhs lr, [r0], #-2031
 *   @0x2ee8e0 ldcllt p6, c4, [r8, #128]!
 *   @0x2ee8e4 .word 0x4606b570
 *   @0x2ee8e8 strmi r6, [sp], -r12, lsl #16
 *   @0x2ee8ec ldclhs p4, c3, [pc], #4
 *   @0x2ee8f0 ldrtmi sp, [r0], -r6, lsl #16
 *   @0x2ee8f4 .word 0xf7ff4621
 *   @0x2ee8f8 stmdahs r0, {r1, r2, r4, r6, r7, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ee8fc strd sp, lr, [r1], -r6
 *   @0x2ee900 strtmi r2, [r0], -r0, lsl #8
 *   @0x2ee904 ldcllt p0, c6, [r0, #-176]!
 *   @0x2ee908 .word 0x460db5f8
 *   @0x2ee90c strmi r2, [r6], -r1, lsl #2
 *   @0x2ee910 .word 0xf7ff4617
 *   @0x2ee914 .word 0x4604ffb4
 *   @0x2ee918 ldrtmi r11, [r0], -r8, lsr #18
 *   @0x2ee91c ldrtmi r4, [r10], -r9, lsr #12
 *   @0x2ee920 .word 0xf7ff2301
 *   @0x2ee924 qasxmi pc, r0, r9
 *   @0x2ee928 ldrblt r11, [r0, #-0xdf8]!
 *   @0x2ee92c .word 0x6c034604
 *   @0x2ee930 ldrmi r4, [r5], -lr, lsl #12
 *   @0x2ee934 andle r2, r11, r3, lsl #22
 *   @0x2ee938 strvs r2, [r3], #-771
 *   @0x2ee93c mcr2 p7, #0x0, pc, c4, c15, #0x7
 *   @0x2ee940 qasxmi r11, r0, r8
 *   @0x2ee944 qasxmi r4, r10, r1
 *   @0x2ee948 ldrhtmi lr, [r0], #-141
 *   @0x2ee94c svclt #0xdcf7ff
 *   @0x2ee950 ldcllt p0, c2, [r0, #-0]!
 *   @0x2ee954 .word 0xf8d36803
 *   @0x2ee958 .word 0xf8d311a4
 *   @0x2ee95c orrvs r2, r1, r8, ror #3
 *   @0x2ee960 .word 0x31a8f8d3
 *   @0x2ee964 ldmdbvs r3, {r0, r1, r6, r7, r8, sp, lr} ^
 *   @0x2ee968 ldmibvs r3, {r0, r1, r6, r8, sp, lr}
 *   @0x2ee96c andhs r6, r0, r3, lsl #2
 *   @0x2ee970 ldrlt r4, [r0, #-0x770]
 *   @0x2ee974 stmvs r3, {r2, r9, r10, lr} ^
 *   @0x2ee978 .word 0xdc012b00
 *   @0x2ee97c mcr2 p7, #0x7, pc, c0, c15, #0x7
 *   @0x2ee980 blhs 0x308d14 <TT_New_Context+0x8b0c>
 *   @0x2ee984 stmdavs r0!, {r0, r2, r3, r4, r10, r11, r12, lr, pc}
 *   @0x2ee988 stmdavs r3!, {r1, r5, r7, r11, sp, lr}
 *   @0x2ee98c movwle r4, #0x1293
 *   @0x2ee990 and r2, r11, r3, lsl #6
 *   @0x2ee994 eorvs r1, r1, r9, asr r12
 *   @0x2ee998 blhs 0xb0ca0c <b2_toiTime+0x3b3568>
 *   @0x2ee99c blhs 0x5629e0 <g_SWFlineaavertbuff+0xf918>
 *   @0x2ee9a0 blhs 0x6629dc <g_SWFlinevertbuff+0xf914>
 *   @0x2ee9a4 blhs 0x5a29b0 <g_SWFlineaavertbuff+0x4f8e8>
 *   @0x2ee9a8 movwhs sp, #0x2102
 *   @0x2ee9ac and r6, r6, r3, ror #1
 *   @0x2ee9b0 .word 0xd1012b3b
 *   @0x2ee9b4 ldrb r2, [r9, r1, lsl #6]!
 *   @0x2ee9b8 mvnle r2, r10, lsl r11
 *   @0x2ee9bc stmdalo r1, {r3, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2ee9c0 andhs r11, r0, r0, lsl sp
 *   @0x2ee9c4 andeq r11, r0, r0, lsl sp
 *   @0x2ee9c8 push {r0, r2, r9, r11, sp}
 *   @0x2ee9cc .word 0x46064ff0
 *   @0x2ee9d0 ldrmi r11, [r0], r5, lsl #1
 *   @0x2ee9d4 stclle p8, c6, [r1], #-284
 *   @0x2ee9d8 .word 0xf10d4b33
 *   @0x2ee9dc .word 0xf10d0908
 *   @0x2ee9e0 strmi r0, [r12], -r12, lsl #22
 *   @0x2ee9e4 ldrbtmi r2, [r11], #-1280
 *   @0x2ee9e8 strbmi r9, [r5, #-0x301]
 *   @0x2ee9ec stmdavs r3!, {r3, r4, r6, r9, r11, r12, lr, pc}
 *   @0x2ee9f0 ldmdblt r3, {r3, r4, r5, r9, r10, lr}
 *   @0x2ee9f4 mcr2 p7, #0x6, pc, c4, c15, #0x7
 *   @0x2ee9f8 .word 0xf7ffe001
 *   @0x2ee9fc strhls pc, [r2], -r10
 *   @0x2eea00 stmdbhs r0, {r1, r8, r11, r12, pc}
 *   @0x2eea04 ldmdavs r11!, {r2, r3, r6, r12, lr, pc}
 *   @0x2eea08 bne 0x19c8a98 <b2_toiTime+0x126f5f4>
 *   @0x2eea0c blo 0x2eae20 <FT_Done_Memory+0x11ac>
 *   @0x2eea10 stmdale r0, {r0, r2, r9, r11, sp} ^
 *   @0x2eea14 .word 0xf002e8df
 *   @0x2eea18 ldcne p3, c0, [r7, #-12]
 *   @0x2eea1c ldmdavs r0!, {r0, r1, r5, r8, r9, r12, sp}
 *   @0x2eea20 mrseq pc, apsr
 *   @0x2eea24 .word 0xf7f8465a
 *   @0x2eea28 blls 0x3ed7dc
 *   @0x2eea2c blhs 0x306bb4 <TT_New_Context+0x69ac>
 *   @0x2eea30 uasxmi sp, r2, r1
 *   @0x2eea34 movwls r9, #0x902
 *   @0x2eea38 stcl p5, c15, [r0, #796]
 *   @0x2eea3c blls 0x308bcc <TT_New_Context+0x89c4>
 *   @0x2eea40 andlo pc, r10, r2, lsl #16
 *   @0x2eea44 strbmi lr, [r8], -r7, lsr #32
 *   @0x2eea48 andhs r4, r0, #1358954496
 *   @0x2eea4c blx 0xff62ca52 <b2_toiTime+0xfffffffffeed35ae>
 *   @0x2eea50 strbmi lr, [r8], -r3
 *   @0x2eea54 .word 0xf7ff4451
 *   @0x2eea58 strhtvs pc, [r0], #-129
 *   @0x2eea5c .word 0xf1bae01b
 *   @0x2eea60 .word 0xd1090f04
 *   @0x2eea64 ldrbmi r4, [r2], -r8, lsl #12
 *   @0x2eea68 .word 0xf5c79901
 *   @0x2eea6c .word 0xf1d0edba
 *   @0x2eea70 svclt #0x380001
 *   @0x2eea74 and r2, r0, r0
 *   @0x2eea78 .word 0x71202000
 *   @0x2eea7c .word 0xf8d6e00b
 *   @0x2eea80 .word 0xf1bcc00c
 *   @0x2eea84 andle r0, r4, r0, lsl #30
 *   @0x2eea88 ldmdbvs r2!, {r3, r9, r10, lr}
 *   @0x2eea8c ubfxmi r4, r1, #0xc, #0x1
 *   @0x2eea90 .word 0xf8c4e7e3
 *   @0x2eea94 strlo r12, [r1, #-0x4]
 *   @0x2eea98 str r3, [r6, r8, lsl #8]!
 *   @0x2eea9c and r2, r0, r0
 *   @0x2eeaa0 andlt r4, r5, r8, lsr #12
 *   @0x2eeaa4 svchi #0xf0e8bd
 *   @0x2eeaa8 andeq pc, r9, r4, ror #29
 *   @0x2eeaac .word 0x460cb513
 *   @0x2eeab0 andhs r10, r3, #32768
 *   @0x2eeab4 stchs p8, c15, [r8, #-260]
 *   @0x2eeab8 andhs r4, r1, #110100480
 *   @0x2eeabc .word 0xff84f7ff
 *   @0x2eeac0 svclt #0x52801
 *   @0x2eeac4 andhs r9, r0, r1, lsl #22
 *   @0x2eeac8 eorvs r2, r3, r0, lsr #1
 *   @0x2eeacc ldclt p0, c11, [r0, #-8]
 *   @0x2eead0 .word 0x4604b570
 *   @0x2eead4 strhs r4, [r0], -sp, lsl #12
 *   @0x2eead8 blhs 0x348e6c
 *   @0x2eeadc strtmi sp, [r0], -r2, lsl #24
 *   @0x2eeae0 mcr2 p7, #0x2, pc, c14, c15, #0x7
 *   @0x2eeae4 strtmi r6, [r0], -r6, ror #1
 *   @0x2eeae8 .word 0xff43f7ff
 *   @0x2eeaec stmvs r3!, {r3, r4, r8, r11, r12, sp, pc} ^
 *   @0x2eeaf0 rscsle r2, r1, r2, lsl #22
 *   @0x2eeaf4 .word 0xb125e006
 *   @0x2eeaf8 bne 0x9c8b8c <b2_toiTime+0x26f6e8>
 *   @0x2eeafc eorvs r3, r11, r1, lsl #22
 *   @0x2eeb00 ldcllt p13, c11, [r0, #-448]!
 *   @0x2eeb04 stchs p6, c4, [r0, #-12]
 *   @0x2eeb08 ldcllt p1, c13, [r0, #-996]!
 *   @0x2eeb0c svcmi #0xf0e92d
 *   @0x2eeb10 stmvs r5, {r0, r1, r2, r4, r7, r12, sp, pc}
 *   @0x2eeb14 strmi r2, [r4], -r0, lsl #6
 *   @0x2eeb18 .word 0x9000f8d0
 *   @0x2eeb1c stchs p3, c9, [r0, #-32]
 *   @0x2eeb20 .word 0x81baf000
 *   @0x2eeb24 ldmdaeq r12, {r0, r2, r3, r8, r12, sp, lr, pc}
 *   @0x2eeb28 strbmi r6, [r1], -r0, asr #16
 *   @0x2eeb2c .word 0xffd0f7ff
 *   @0x2eeb30 .word 0xf0002800
 *   @0x2eeb34 bls 0x4cf208 <SrcVerts+0x2c24c>
 *   @0x2eeb38 .word 0xf0402a10
 *   @0x2eeb3c ldmibmi r9, {r0, r1, r2, r3, r5, r7, r8, pc} ^
 *   @0x2eeb40 .word 0xf5c74479
 *   @0x2eeb44 stmdahs r0, {r1, r2, r3, r6, r8, r10, r11, sp, lr, pc}
 *   @0x2eeb48 .word 0x81a8f040
 *   @0x2eeb4c .word 0xf10daf0c
 *   @0x2eeb50 .word 0xf10d0a20
 *   @0x2eeb54 strths r0, [r0], r12, lsr #22
 *   @0x2eeb58 strbmi r6, [r1], -r0, ror #16
 *   @0x2eeb5c .word 0xffb8f7ff
 *   @0x2eeb60 .word 0xf0002800
 *   @0x2eeb64 stmdbls r7, {r0, r3, r7, r8, pc}
 *   @0x2eeb68 stc2l p7, c15, [r0, #1020]
 *   @0x2eeb6c eorsle r2, r0, r10, lsl r8
 *   @0x2eeb70 stmdahs lr, {r0, r1, r2, r11, r12, lr, pc}
 *   @0x2eeb74 ldmdahs r4, {r4, r6, r12, lr, pc}
 *   @0x2eeb78 cmnhi r12, r0
 *   @0x2eeb7c mvnle r2, r0, lsl #16
 *   @0x2eeb80 stmdahs r8!, {r0, r2, r3, r4, r5, sp, lr, pc}
 *   @0x2eeb84 stmdale r2, {r1, r3, r12, lr, pc}
 *   @0x2eeb88 andsle r2, r4, lr, lsl r8
 *   @0x2eeb8c stmdahs sp!, {r2, r5, r6, r7, r8, r9, r10, sp, lr, pc}
 *   @0x2eeb90 ldmdahs r1!, {r0, r1, r2, r3, r6, r12, lr, pc}
 *   @0x2eeb94 .word 0xf10dd1e0
 *   @0x2eeb98 adc r0, r1, r8, lsr #20
 *   @0x2eeb9c ldrbmi r4, [r1], -r0, lsr #12
 *   @0x2eeba0 .word 0xff84f7ff
 *   @0x2eeba4 .word 0xf0402800
 *   @0x2eeba8 blls 0x50f14c <SrcVerts+0x6c190>
 *   @0x2eebac andeq pc, r2, #51
 *   @0x2eebb0 .word 0x2607d0d2
 *   @0x2eebb4 strtmi lr, [r0], -r0, ror #2
 *   @0x2eebb8 andhs r4, r1, #59768832
 *   @0x2eebbc movwls r2, #0xc304
 *   @0x2eebc0 .word 0xff02f7ff
 *   @0x2eebc4 .word 0xf0402801
 *   @0x2eebc8 .word 0xf89d8157
 *   @0x2eebcc eorvc r3, r11, r4, lsr r0
 *   @0x2eebd0 strtmi lr, [r0], -r2, asr #15
 *   @0x2eebd4 andhs r4, r4, #59768832
 *   @0x2eebd8 movwls r2, #0xc302
 *   @0x2eebdc tstls r0, #939524096
 *   @0x2eebe0 .word 0xf7ff9312
 *   @0x2eebe4 stmdahs r4, {r0, r4, r5, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2eebe8 .word 0x8146f040
 *   @0x2eebec rsbvs r9, r11, sp, lsl #22
 *   @0x2eebf0 adcvs r9, r11, pc, lsl #22
 *   @0x2eebf4 rscvs r9, r11, r1, lsl r11
 *   @0x2eebf8 .word 0x612b9b13
 *   @0x2eebfc strtmi lr, [r0], -r12, lsr #15
 *   @0x2eec00 andhs r4, r1, #59768832
 *   @0x2eec04 movwls r2, #0xc302
 *   @0x2eec08 mrc2 p7, #0x6, apsr_nzcv, c14, c15, #0x7
 *   @0x2eec0c .word 0xf0402801
 *   @0x2eec10 blls 0x64f0e4 <g_SWFaavertbuff+0x7c01c>
 *   @0x2eec14 ldr r6, [pc, r11, ror #2]
 *   @0x2eec18 ldrtmi r4, [r9], -r0, lsr #12
 *   @0x2eec1c movwhs r2, #0x2201
 *   @0x2eec20 .word 0xf7ff930c
 *   @0x2eec24 stmdahs r1, {r0, r4, r6, r7, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2eec28 .word 0x8126f040
 *   @0x2eec2c .word 0x61ab9b0d
 *   @0x2eec30 qadd8mi lr, r0, r2
 *   @0x2eec34 movwhs r4, #0x659
 *   @0x2eec38 .word 0xf7ff930b
 *   @0x2eec3c stmdahs r0, {r0, r1, r2, r4, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2eec40 tsthi r10, r0, asr #32
 *   @0x2eec44 cdphs p14, #0x0, c9, c0, c11, #0x0
 *   @0x2eec48 stmdavs r0!, {r0, r1, r2, r3, r8, r10, r11, r12, lr, pc} ^
 *   @0x2eec4c .word 0xf7ff2100
 *   @0x2eec50 mcrlo p15, #0x0, pc, c1, c15, #0x1
 *   @0x2eec54 mvnsle r2, r0, lsl #16
 *   @0x2eec58 smulwb r0, r0, r0
 *   @0x2eec5c .word 0xf7ff990c
 *   @0x2eec60 ldmdahs r1, {r0, r2, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2eec64 ldmdahs r4, {r3, r12, lr, pc}
 *   @0x2eec68 stmdavs r0!, {r1, r2, r12, lr, pc} ^
 *   @0x2eec6c .word 0xf7ff4639
 *   @0x2eec70 stmdahs r0, {r0, r1, r2, r3, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2eec74 .word 0xe7efd1f2
 *   @0x2eec78 strb r2, [sp, -r0, lsl #12]!
 *   @0x2eec7c .word 0xf040284b
 *   @0x2eec80 stmdavs r0!, {r0, r1, r2, r4, r5, r6, r7, pc} ^
 *   @0x2eec84 .word 0xf7ff4631
 *   @0x2eec88 stmdahs r0, {r0, r1, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2eec8c rscshi pc, r0, r0
 *   @0x2eec90 .word 0xf7ff9909
 *   @0x2eec94 ldmdahs r3!, {r0, r1, r3, r5, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2eec98 ldmdahs r5!, {r2, r5, r8, r11, r12, lr, pc}
 *   @0x2eec9c strtmi sp, [r0], -lr, ror #3
 *   @0x2eeca0 stmvs r6!, {r0, r1, r3, r8, r11, sp, pc}
 *   @0x2eeca4 .word 0xff02f7ff
 *   @0x2eeca8 stmdahs r0, {r1, r9, r10, lr}
 *   @0x2eecac rschi pc, r0, r0, asr #32
 *   @0x2eecb0 blhs 0x3158e4 <FT_Bitmap_Embolden+0xa9e>
 *   @0x2eecb4 sbcshi pc, r12, r0, asr #5
 *   @0x2eecb8 tstle r10, r3, lsr r2
 *   @0x2eecbc bleq 0xf2b0f8 <b2_toiTime+0x7d1c54>
 *   @0x2eecc0 ldrblo pc, [pc, pc, asr #32]!
 *   @0x2eecc4 ldrbmi r6, [r1], -r0, ror #16
 *   @0x2eecc8 .word 0xff02f7ff
 *   @0x2eeccc .word 0xf0002800
 *   @0x2eecd0 stmdbls r10, {r0, r1, r2, r3, r6, r7, pc}
 *   @0x2eecd4 stc2 p7, c15, [r10, #-1020]
 *   @0x2eecd8 tstle r7, r7, lsl r8
 *   @0x2eecdc eorsvs r3, r7, #262144
 *   @0x2eece0 strb r10, [lr, r9, lsl #28]
 *   @0x2eece4 suble r2, sp, #3276800
 *   @0x2eece8 stmdahs r1, {r2, r4, r11, r12, sp}
 *   @0x2eecec sbchi pc, r2, r0, asr #4
 *   @0x2eecf0 strhls lr, [r0], -lr
 *   @0x2eecf4 mrsls r10, apsr
 *   @0x2eecf8 stmdavs r0!, {r2, r4, r8, sp}
 *   @0x2eecfc .word 0xf9c7f7f9
 *   @0x2eed00 blls 0x6074c8 <g_SWFaavertbuff+0x34400>
 *   @0x2eed04 sbcsle r2, r9, r0, lsl #22
 *   @0x2eed08 adcs r4, r5, lr, lsl r6
 *   @0x2eed0c ldmdalo r4, {r2, r11, r12, lr, pc}
 *   @0x2eed10 vadd.i8 d2, d0, d1
 *   @0x2eed14 strb r8, [r1, sp, lsr #1]!
 *   @0x2eed18 andle r2, r2, r8, lsr r8
 *   @0x2eed1c sbcsle r2, r1, r11, asr #16
 *   @0x2eed20 bvs 0xfe6fc0 <b2_toiTime+0x88db1c>
 *   @0x2eed24 addsmi r3, pc, #262144
 *   @0x2eed28 adchi pc, r2, r0, lsl #5
 *   @0x2eed2c .word 0xf8d62214
 *   @0x2eed30 blx 0x39edaa <ft_standard_glyph_names+0xb6>
 *   @0x2eed34 strtmi pc, [r0], -r7, lsl #6
 *   @0x2eed38 ldrbmi r2, [r9], -r3, lsl #4
 *   @0x2eed3c andhs r9, r2, #12, #4
 *   @0x2eed40 bl 0x613580 <g_SWFaavertbuff+0x404b8>
 *   @0x2eed44 andsls r0, r0, #196608
 *   @0x2eed48 andsls r9, r4, #536870913
 *   @0x2eed4c movwls r2, #0x4205
 *   @0x2eed50 andgt pc, r12, sp, asr #17
 *   @0x2eed54 mrc2 p7, #0x1, apsr_nzcv, c8, c15, #0x7
 *   @0x2eed58 .word 0xf8dd9b04
 *   @0x2eed5c stmdahs r5, {r2, r3, lr, pc}
 *   @0x2eed60 addhi pc, r6, r0, asr #32
 *   @0x2eed64 .word 0xf84c9a0d
 *   @0x2eed68 blls 0x6b6d7c <g_SWFlinevertbuff+0x63cb4>
 *   @0x2eed6c andlo pc, r4, r8, asr #17
 *   @0x2eed70 .word 0xf8c89b11
 *   @0x2eed74 blls 0x7bad9c <b2_toiTime+0x618f8>
 *   @0x2eed78 andlo pc, r12, r8, asr #17
 *   @0x2eed7c .word 0xf8c89b15
 *   @0x2eed80 .word 0xe79f3010
 *   @0x2eed84 stmdbge r11, {r5, r9, r10, lr}
 *   @0x2eed88 .word 0xf7ff68a7
 *   @0x2eed8c strmi pc, [r2], -pc, lsl #29
 *   @0x2eed90 .word 0xd16d2800
 *   @0x2eed94 blhs 0x3159c8 <FT_Bitmap_Embolden+0xb82>
 *   @0x2eed98 adcsvs sp, r11, #108544
 *   @0x2eed9c andls sp, r0, r10
 *   @0x2eeda0 mrsls r10, apsr
 *   @0x2eeda4 stmdavs r0!, {r4, r8, sp}
 *   @0x2eeda8 .word 0xf971f7f9
 *   @0x2eedac mcrls p2, #0x0, r6, c12, c8, #0x3
 *   @0x2eedb0 .word 0xd1612e00
 *   @0x2eedb4 ldmlo pc!, {r0, r1, r2, r3, r6, r12, sp, lr, pc} ^
 *   @0x2eedb8 movwls r10, #0x5b0c
 *   @0x2eedbc ldrbmi r6, [r1], -r0, ror #16
 *   @0x2eedc0 mcr2 p7, #0x4, pc, c6, c15, #0x7
 *   @0x2eedc4 subsle r2, r3, r0, lsl #16
 *   @0x2eedc8 .word 0xf7ff990a
 *   @0x2eedcc stmdahs r2!, {r0, r1, r2, r3, r7, r10, r11, r12, sp, lr, pc}
 *   @0x2eedd0 andsle r4, r5, r6, lsl #12
 *   @0x2eedd4 .word 0xf1a0d80d
 *   @0x2eedd8 mcrhs p6, #0x0, r0, c2, c4, #0x0
 *   @0x2eeddc blmi 0xfa4f04 <b2_toiTime+0x84ba60>
 *   @0x2eede0 mrseq pc, apsr
 *   @0x2eede4 andshs r6, r0, #120, #20
 *   @0x2eede8 ldrbtmi r6, [r11], #-697
 *   @0x2eedec ldcl p5, c15, [r6], #-796
 *   @0x2eedf0 stmdahs r4!, {r1, r2, r4, r5, r6, r8, r9, r10, sp, lr, pc}
 *   @0x2eedf4 stmdahs r5!, {r2, r3, r4, r5, r8, r9, r12, lr, pc}
 *   @0x2eedf8 stmdahs r11, {r1, r8, r11, r12, lr, pc} ^
 *   @0x2eedfc ldrsbt sp, [r7], -lr
 *   @0x2eee00 .word 0xf1086abb
 *   @0x2eee04 ldrmi r0, [r8, #0x801]
 *   @0x2eee08 .word 0xf8d7da32
 *   @0x2eee0c b 0x16deea4 <b2_toiTime+0xf85a00>
 *   @0x2eee10 andhs r1, r5, #8, #6
 *   @0x2eee14 andls r4, r12, #32, #12
 *   @0x2eee18 andls r10, lr, #12, #18
 *   @0x2eee1c andsls r2, r0, #805306368
 *   @0x2eee20 bleq 0x3e9a58 <t1_driver_class+0x184>
 *   @0x2eee24 andhs r9, r4, #536870913
 *   @0x2eee28 .word 0xf8cd9304
 *   @0x2eee2c .word 0xf7ffc00c
 *   @0x2eee30 blls 0x42e564 <g_RomDisk+0x36d44>
 *   @0x2eee34 .word 0xc00cf8dd
 *   @0x2eee38 ldcle p8, c2, [r9, #-8]
 *   @0x2eee3c vmulhs.f32 s18, s10, s26
 *   @0x2eee40 andhs pc, r3, r12, asr #16
 *   @0x2eee44 .word 0xf8cb9b0f
 *   @0x2eee48 .word 0xd1043004
 *   @0x2eee4c .word 0xf8cb2300
 *   @0x2eee50 blls 0x73ae78 <g_SWFvertbuff+0x67db0>
 *   @0x2eee54 blls 0x766e80 <b2_toiTime+0xd9dc>
 *   @0x2eee58 .word 0xf8cb2e22
 *   @0x2eee5c mrsle r3, apsr
 *   @0x2eee60 mrsle r2, apsr
 *   @0x2eee64 and r9, r0, r3, lsl r11
 *   @0x2eee68 .word 0xf8cb2300
 *   @0x2eee6c str r3, [r5, r12]!
 *   @0x2eee70 and r2, r1, r0, lsr #13
 *   @0x2eee74 ands r2, r2, r0
 *   @0x2eee78 stmibvs r9!, {r3, r6, r9, r10, lr} ^
 *   @0x2eee7c blx 0x19ece64 <b2_toiTime+0x12939c0>
 *   @0x2eee80 strbmi r2, [r8], -r0, lsl #8
 *   @0x2eee84 eorvs r6, r12, #236, #2
 *   @0x2eee88 .word 0xf7f86a69
 *   @0x2eee8c rsbvs pc, r12, #84, #20
 *   @0x2eee90 ldrtmi r6, [r0], -r12, lsr #5
 *   @0x2eee94 and r7, r2, r12, lsr #32
 *   @0x2eee98 and r2, r0, r6
 *   @0x2eee9c andslt r2, r7, r2
 *   @0x2eeea0 svchi #0xf0e8bd
 *   @0x2eeea4 andeq pc, r9, pc, lsl #27
 *   @0x2eeea8 .word 0xffffecdf
 *   @0x2eeeac .word 0x4607b5f7
 *   @0x2eeeb0 cdpge p8, #0x0, c6, c2, c3, #0x0
 *   @0x2eeeb4 strmi r2, [sp], -r0
 *   @0x2eeeb8 .word 0xf8464604
 *   @0x2eeebc blls 0x33e2d4
 *   @0x2eeec0 movwle r4, #0x32ab
 *   @0x2eeec4 svclt #0x182c00
 *   @0x2eeec8 eor r2, lr, r3
 *   @0x2eeecc mvnsle r2, r0, lsl #16
 *   @0x2eeed0 bhs 0x120cf40 <b2_toiTime+0xab3a9c>
 *   @0x2eeed4 stmdale r8, {r0, r2, r4, r12, lr, pc}
 *   @0x2eeed8 andsle r2, r12, r5, lsr #20
 *   @0x2eeedc .word 0xd1202a28
 *   @0x2eeee0 qasxmi r4, r9, r0
 *   @0x2eeee4 mcr2 p7, #0x6, pc, c15, c14, #0x7
 *   @0x2eeee8 bhs 0x21e6f5c <b2_toiTime+0x1a8dab8>
 *   @0x2eeeec bhs 0x2262efc <b2_toiTime+0x1b09a58>
 *   @0x2eeef0 ands sp, r6, r2
 *   @0x2eeef4 ands r3, r4, r1, lsl #8
 *   @0x2eeef8 tstle r2, r1, lsl #24
 *   @0x2eeefc movwls r3, #0x1301
 *   @0x2eef00 shadd16mi lr, r0, r3
 *   @0x2eef04 .word 0xf7fe4629
 *   @0x2eef08 .word 0xe00afefc
 *   @0x2eef0c andle r2, r7, r10, lsl #18
 *   @0x2eef10 ldrmi r4, [r10], -r11, lsr #5
 *   @0x2eef14 ldrmi sp, [r10], -r4
 *   @0x2eef18 blne 0x36cf6c <_ZTS13C_UTF16String+0x4018>
 *   @0x2eef1c mvnsle r2, sp, lsl #18
 *   @0x2eef20 blls 0x35372c
 *   @0x2eef24 movwls r3, #0x1301
 *   @0x2eef28 blls 0x368e54 <_ZTS12CDS_Priority+0xaeac>
 *   @0x2eef2c andlt r6, r3, r11, lsr r0
 *   @0x2eef30 ldrblt r11, [r3, #-0xdf0]!
 *   @0x2eef34 stmdavs r3, {r1, r8, r10, r11, sp, pc}
 *   @0x2eef38 stmvs r4, {r1, r2, r9, r10, lr}
 *   @0x2eef3c stclo p8, c15, [r4, #-276]
 *   @0x2eef40 strtmi r4, [r1], -r8, lsr #12
 *   @0x2eef44 mrc2 p7, #0x3, apsr_nzcv, c14, c14, #0x7
 *   @0x2eef48 adcmi r9, r3, #1024
 *   @0x2eef4c ldmdavc r10, {r2, r3, r5, r9, r12, lr, pc}
 *   @0x2eef50 andle r2, r1, r11, asr r10
 *   @0x2eef54 qaddle r2, sp, r1
 *   @0x2eef58 eor r3, r4, r1, lsl #6
 *   @0x2eef5c .word 0xd1042a7b
 *   @0x2eef60 strtmi r4, [r1], -r8, lsr #12
 *   @0x2eef64 .word 0xffa2f7ff
 *   @0x2eef68 bhs 0xd27090 <b2_toiTime+0x5cdbec>
 *   @0x2eef6c strtmi sp, [r8], -r4, lsl #2
 *   @0x2eef70 .word 0xf7fe4621
 *   @0x2eef74 sub pc, r1, r8, lsl #29
 *   @0x2eef78 .word 0xd10a2a3c
 *   @0x2eef7c addsmi r1, r4, #23040
 *   @0x2eef80 ldmdavc r10, {r1, r8, r11, r12, lr, pc} ^
 *   @0x2eef84 andle r2, sp, r12, lsr r10
 *   @0x2eef88 strtmi r4, [r1], -r8, lsr #12
 *   @0x2eef8c mrc2 p7, #0x5, apsr_nzcv, c9, c14, #0x7
 *   @0x2eef90 bhs 0x12a7068 <b2_toiTime+0xb4dbc4>
 *   @0x2eef94 mrrcne p1, #0x0, sp, r10, c10
 *   @0x2eef98 adcmi r9, r2, #268435456
 *   @0x2eef9c ldmdavc r10, {r0, r2, r3, r5, r9, r12, lr, pc} ^
 *   @0x2eefa0 .word 0xd12a2a3e
 *   @0x2eefa4 movwls r3, #0x1302
 *   @0x2eefa8 eor r2, r7, r0
 *   @0x2eefac .word 0xd1202a2f
 *   @0x2eefb0 movwls r3, #0x1301
 *   @0x2eefb4 ldmdavc r3, {r0, r2, r3, r4, sp, lr, pc}
 *   @0x2eefb8 smlatbeq r9, r3, r1, pc
 *   @0x2eefbc ldmible r3!, {r0, r8, r11, sp} ^
 *   @0x2eefc0 smlatbeq r12, r3, r1, pc
 *   @0x2eefc4 stmible pc!, {r0, r8, r11, sp} ^
 *   @0x2eefc8 bicseq pc, pc, r3, lsl r0
 *   @0x2eefcc blhs 0xee3384 <b2_toiTime+0x789ee0>
 *   @0x2eefd0 .word 0xf1a3d0ea
 *   @0x2eefd4 stmdahs r1, {r3, r5}
 *   @0x2eefd8 .word 0xf003d9e6
 *   @0x2eefdc ldmdahs r12!, {r0, r2, r3, r4, r5, r6, r7}
 *   @0x2eefe0 ldmdbhs r11, {r1, r5, r6, r7, r12, lr, pc} ^
 *   @0x2eefe4 ldmdbhs sp, {r5, r6, r7, r12, lr, pc} ^
 *   @0x2eefe8 blhs 0xc63368 <b2_toiTime+0x509ec4>
 *   @0x2eefec andlo sp, r1, #220
 *   @0x2eeff0 bls 0x3537fc
 *   @0x2eeff4 bicsle r4, lr, #536870922
 *   @0x2eeff8 ldrdhs lr, pc, [r3], -r6
 *   @0x2eeffc adcmi r9, r3, #1024
 *   @0x2ef000 ldmdavs r2!, {r0, r1, r9, r12, lr, pc}
 *   @0x2ef004 svclt #0x84293
 *   @0x2ef008 adcmi r2, r3, #3
 *   @0x2ef00c strls r11, [r1], #-3976
 *   @0x2ef010 rscsvs r9, r0, r1, lsl #22
 *   @0x2ef014 andlt r6, r2, r3, lsr r0
 *   @0x2ef018 ldrblt r11, [r7, #0xd70]!
 *   @0x2ef01c strmi r2, [r5], -r0, lsl #6
 *   @0x2ef020 andvs r6, r11, r11, lsl #1
 *   @0x2ef024 subvs r4, r11, r12, lsl #12
 *   @0x2ef028 mrc2 p7, #0x4, apsr_nzcv, c9, c14, #0x7
 *   @0x2ef02c stmvs pc!, {r0, r1, r3, r5, r11, sp, lr}
 *   @0x2ef030 movwls r4, #0x12bb
 *   @0x2ef034 ldmdavc r10, {r0, r2, r4, r6, r9, r12, lr, pc}
 *   @0x2ef038 andsle r2, r6, r11, asr r10
 *   @0x2ef03c andle r2, r9, r11, ror r10
 *   @0x2ef040 teqle r9, r8, lsr #20
 *   @0x2ef044 eorvs r2, r3, r2, lsl #4
 *   @0x2ef048 stmdage r1, {r1, r5, r7, sp, lr}
 *   @0x2ef04c .word 0xf7fe4639
 *   @0x2ef050 and pc, r6, r10, lsl lr
 *   @0x2ef054 eorvs r2, r3, r3, lsl #4
 *   @0x2ef058 stmdage r1, {r1, r5, r7, sp, lr}
 *   @0x2ef05c .word 0xf7ff4639
 *   @0x2ef060 stmdahs r0, {r0, r2, r5, r8, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ef064 blls 0x363548 <_ZTS12CDS_Priority+0x55a0>
 *   @0x2ef068 eorvs lr, r3, r4, lsr r0
 *   @0x2ef06c strtmi r2, [r8], -r3, lsl #4
 *   @0x2ef070 mrrcne p0, #0xa, r6, r10, c2
 *   @0x2ef074 andls r6, r1, #42
 *   @0x2ef078 mrc2 p7, #0x3, apsr_nzcv, c1, c14, #0x7
 *   @0x2ef07c strhs r6, [r1], -r11, lsr #16
 *   @0x2ef080 blls 0x353c8c
 *   @0x2ef084 eorle r4, r6, #-1342177269
 *   @0x2ef088 bllt 0xb89438 <b2_toiTime+0x42ff94>
 *   @0x2ef08c bhs 0x19cd0fc <b2_toiTime+0x1273c58>
 *   @0x2ef090 strlo sp, [r1], -r1, lsl #2
 *   @0x2ef094 bhs 0x1a670b4 <b2_toiTime+0x130dc10>
 *   @0x2ef098 cdplo p1, #0x0, c13, c1, c4, #0x0
 *   @0x2ef09c movwlo sp, #0x1102
 *   @0x2ef0a0 ands r9, r7, r1, lsl #6
 *   @0x2ef0a4 strtmi r6, [r8], -r11, lsr #32
 *   @0x2ef0a8 .word 0xff43f7ff
 *   @0x2ef0ac .word 0xf7fe4628
 *   @0x2ef0b0 stmdavs r11!, {r1, r2, r4, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ef0b4 strb r9, [r4, r1, lsl #6]!
 *   @0x2ef0b8 strtmi r6, [r8], -r3, lsr #32
 *   @0x2ef0bc blhs 0xecd130 <b2_toiTime+0x773c8c>
 *   @0x2ef0c0 movwhs r11, #0x1f14
 *   @0x2ef0c4 adcvs r2, r3, r4, lsl #6
 *   @0x2ef0c8 .word 0xff33f7ff
 *   @0x2ef0cc stmvs r10!, {r0, r1, r3, r5, r11, sp, lr} ^
 *   @0x2ef0d0 stmdblt r2, {r0, r8, r9, r12, pc}
 *   @0x2ef0d4 stmdavs r3!, {r0, r1, r5, r6, sp, lr} ^
 *   @0x2ef0d8 eorvs r11, r3, r11, lsl #18
 *   @0x2ef0dc blls 0x347370
 *   @0x2ef0e0 andlt r6, r3, r11, lsr #32
 *   @0x2ef0e4 strdeq r11, r12, [r0], -r0
 *   @0x2ef0e8 svcmi #0xf0e92d
 *   @0x2ef0ec ldrmi r11, [r8], r7, lsl #1
 *   @0x2ef0f0 .word 0xf04f460e
 *   @0x2ef0f4 uqsub8mi r3, r9, pc
 *   @0x2ef0f8 andlo pc, r0, r8, asr #17
 *   @0x2ef0fc ldrmi r4, [r5], -r4, lsl #12
 *   @0x2ef100 .word 0xff8bf7ff
 *   @0x2ef104 blhs 0x3d5d14 <error_g0017+0x2e9b8>
 *   @0x2ef108 blls 0x3235c0
 *   @0x2ef10c bleq 0x62b250 <g_SWFaavertbuff+0x58188>
 *   @0x2ef110 .word 0xa000f8d4
 *   @0x2ef114 movwlo r10, #0x1f03
 *   @0x2ef118 blls 0x3471ac
 *   @0x2ef11c blvs 0x46dd50 <g_RomDisk+0x76530>
 *   @0x2ef120 .word 0xf8d44635
 *   @0x2ef124 bllo 0x35314c
 *   @0x2ef128 stmdavs r1!, {r0, r1, r5, r7, sp, lr}
 *   @0x2ef12c addsmi r6, r9, #10682368
 *   @0x2ef130 strtmi sp, [r0], -lr, lsl #4
 *   @0x2ef134 .word 0xf7ff4639
 *   @0x2ef138 blls 0x46ef00 <g_RomDisk+0x776e0>
 *   @0x2ef13c .word 0xb12eb143
 *   @0x2ef140 svclt #0x3c455d
 *   @0x2ef144 muleq r7, r7, r8
 *   @0x2ef148 andeq lr, r7, r5, lsl #17
 *   @0x2ef14c strb r3, [r12, r12, lsl #10]!
 *   @0x2ef150 vmlami.f64 d1, d22, d29
 *   @0x2ef154 cmnmi r5, #173
 *   @0x2ef158 andpl pc, r0, r8, asr #17
 *   @0x2ef15c andge pc, r0, r4, asr #17
 *   @0x2ef160 andls pc, r8, r4, asr #17
 *   @0x2ef164 pop {r0, r1, r2, r12, sp, pc}
 *   @0x2ef168 svclt #0x8ff0
 *   @0x2ef16c bge 0xfed99c20 <b2_toiTime+0xfffffffffe64077c>
 *   @0x2ef170 svcmi #0xf0e92d
 *   @0x2ef174 .word 0x4606b099
 *   @0x2ef178 ldmdbge r1, {r0, r1, r2, r8, r12, pc}
 *   @0x2ef17c andls r9, r9, #201326592
 *   @0x2ef180 .word 0xff4bf7ff
 *   @0x2ef184 blhs 0x315dd8 <FT_Bitmap_Embolden+0xf92>
 *   @0x2ef188 cmphi r5, r0
 *   @0x2ef18c bls 0x7555b0 <g_szTestOggFile+0x134>
 *   @0x2ef190 stmvs r9, {r1, r4, r10, r11, r12, pc}
 *   @0x2ef194 stmdbhs r7, {r0, r1, r2, r3, r9, r12, pc}
 *   @0x2ef198 tstle r2, r6, lsl #2
 *   @0x2ef19c mcrne p8, #0x3, r6, c3, c7, #0x1
 *   @0x2ef1a0 andlo r6, r1, #11862016
 *   @0x2ef1a4 .word 0x463060b3
 *   @0x2ef1a8 ldmdbge r4, {r1, r4, r5, sp, lr}
 *   @0x2ef1ac .word 0xff35f7ff
 *   @0x2ef1b0 eorsvs r9, r7, r6, lsl r11
 *   @0x2ef1b4 adcsvs r2, r5, r3, lsl #22
 *   @0x2ef1b8 andhs sp, r8, #16, #2
 *   @0x2ef1bc andls r2, r6, #4194304
 *   @0x2ef1c0 blhs 0x3e71d0 <error_g0017+0x3fe74>
 *   @0x2ef1c4 stcls p1, c13, [r3, #-40]
 *   @0x2ef1c8 blhs 0x315ddc <FT_Bitmap_Embolden+0xf96>
 *   @0x2ef1cc teqhi r3, r0
 *   @0x2ef1d0 .word 0x3c019b0f
 *   @0x2ef1d4 movwls r3, #0xf301
 *   @0x2ef1d8 and r2, r1, r1, lsl #6
 *   @0x2ef1dc strhs r2, [r1, #-0x300]
 *   @0x2ef1e0 strtmi r9, [r11], #-2307
 *   @0x2ef1e4 .word 0xf10d9a09
 *   @0x2ef1e8 addeq r0, r9, r12, lsr r11
 *   @0x2ef1ec orreq lr, r3, #2048
 *   @0x2ef1f0 ldmdbge r4, {r2, r8, r12, pc}
 *   @0x2ef1f4 blge 0x713e28 <g_SWFvertbuff+0x40d60>
 *   @0x2ef1f8 movwls r9, #0xa10d
 *   @0x2ef1fc .word 0xf0002d00
 *   @0x2ef200 .word 0xf06f8115
 *   @0x2ef204 bls 0x5afe18 <g_SWFlineaavertbuff+0x5cd50>
 *   @0x2ef208 strtmi r4, [r1], -r11, ror #6
 *   @0x2ef20c .word 0xf8524658
 *   @0x2ef210 blls 0x4cf224 <SrcVerts+0x2c268>
 *   @0x2ef214 .word 0xf7fe691f
 *   @0x2ef218 stmdbls r6, {r0, r2, r4, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2ef21c stmdbeq r7, {r3, r8, r9, r11, sp, lr, pc}
 *   @0x2ef220 blhs 0x4b6b54 <SrcVerts+0x13b98>
 *   @0x2ef224 .word 0x8107f200
 *   @0x2ef228 .word 0xf003e8df
 *   @0x2ef22c .word 0x312d3704
 *   @0x2ef230 orrge r4, r2, r12, asr #24
 *   @0x2ef234 .word 0x1cda9b0f
 *   @0x2ef238 stmdble lr, {r2, r4, r7, r9, lr}
 *   @0x2ef23c bhs 0x200d2ac <b2_toiTime+0x18b3e08>
 *   @0x2ef240 ldmdavc r10, {r0, r1, r3, r8, r12, lr, pc} ^
 *   @0x2ef244 .word 0xd1082a72
 *   @0x2ef248 bhs 0x204d4b8 <b2_toiTime+0x18f4014>
 *   @0x2ef24c ldmvc r10, {r0, r2, r8, r12, lr, pc} ^
 *   @0x2ef250 .word 0xd1022a65
 *   @0x2ef254 andhs r3, r1, r5, lsl #6
 *   @0x2ef258 ldcne p0, c14, [r10, #-76]
 *   @0x2ef25c stmdble pc, {r2, r4, r7, r9, lr}
 *   @0x2ef260 bhs 0x1c8d2d0 <b2_toiTime+0x1533e2c>
 *   @0x2ef264 ldmdavc r10, {r2, r3, r8, r12, lr, pc} ^
 *   @0x2ef268 .word 0xd1092a61
 *   @0x2ef26c bhs 0x1e0d4dc <b2_toiTime+0x16b4038>
 *   @0x2ef270 ldmvc r10, {r1, r2, r8, r12, lr, pc} ^
 *   @0x2ef274 .word 0xd1032a73
 *   @0x2ef278 bhs 0x1c4d6e8 <b2_toiTime+0x14f4244>
 *   @0x2ef27c movwlo r11, #0x6f08
 *   @0x2ef280 movwls r2, #0xf000
 *   @0x2ef284 ldrbmi lr, [r8], -sp
 *   @0x2ef288 andhs r4, r0, #34603008
 *   @0x2ef28c ldrbmi lr, [r8], -r2
 *   @0x2ef290 andhs r4, r3, #34603008
 *   @0x2ef294 .word 0xffa8f7fe
 *   @0x2ef298 ldrbmi lr, [r8], -r3
 *   @0x2ef29c .word 0xf7fe4621
 *   @0x2ef2a0 bls 0x4ee4dc <SrcVerts+0x4b520>
 *   @0x2ef2a4 blhs 0x38e6f8 <_ZTS7CBucketILj16384ELj262144ELb1EE+0x2754>
 *   @0x2ef2a8 blhs 0x4232c8 <g_RomDisk+0x2baa8>
 *   @0x2ef2ac blhs 0x3632d0 <_ZTS12CDS_Priority+0x5328>
 *   @0x2ef2b0 .word 0xf808d105
 *   @0x2ef2b4 adcs r0, r7, r7
 *   @0x2ef2b8 andeq pc, r7, r8, lsr #16
 *   @0x2ef2bc .word 0xf848e0b4
 *   @0x2ef2c0 adcs r0, r1, r7
 *   @0x2ef2c4 .word 0xf8d69b0f
 *   @0x2ef2c8 adcmi r10, r3, #16
 *   @0x2ef2cc adchi pc, r12, r0, lsl #1
 *   @0x2ef2d0 bl 0xff3d5b24 <b2_toiTime+0xfffffffffec7c680>
 *   @0x2ef2d4 bhs 0x3f16ec
 *   @0x2ef2d8 movwlo sp, #0x1104
 *   @0x2ef2dc ldmiblo pc!, {r0, r3, r8, r12, sp, lr, pc} ^
 *   @0x2ef2e0 and r9, r6, pc, lsl #6
 *   @0x2ef2e4 .word 0xf0402a02
 *   @0x2ef2e8 .word 0xf1a980a6
 *   @0x2ef2ec movwlo r0, #0x1902
 *   @0x2ef2f0 .word 0xf858930f
 *   @0x2ef2f4 .word 0xb1291007
 *   @0x2ef2f8 .word 0xf7f84650
 *   @0x2ef2fc movwhs pc, #0x81c
 *   @0x2ef300 andlo pc, r7, r8, asr #16
 *   @0x2ef304 .word 0xf1094650
 *   @0x2ef308 bge 0x6ef714 <g_SWFvertbuff+0x1c64c>
 *   @0x2ef30c .word 0xff0bf7f7
 *   @0x2ef310 pkhbtmi r9, r2, r0, lsl #22
 *   @0x2ef314 .word 0xf0402b00
 *   @0x2ef318 stmdbls pc, {r1, r3, r7, pc}
 *   @0x2ef31c movwls r4, #0x264a
 *   @0x2ef320 stmdb r12, {r0, r1, r2, r6, r7, r8, r10, r12, sp, lr, pc} ^
 *   @0x2ef324 .word 0xf80a9b02
 *   @0x2ef328 .word 0xf8483009
 *   @0x2ef32c rsbs r10, r11, r7
 *   @0x2ef330 ldrbmi r2, [r8], -r0, lsl #6
 *   @0x2ef334 strtmi r9, [r1], -r0, lsl #6
 *   @0x2ef338 blge 0x7f7b50 <b2_toiTime+0x9e6ac>
 *   @0x2ef33c .word 0xf844f7ff
 *   @0x2ef340 ldclle p8, c2, [r8, #-12]!
 *   @0x2ef344 .word 0xf7f59814
 *   @0x2ef348 .word 0xf848fce9
 *   @0x2ef34c ldmdals r5, {r0, r1, r2}
 *   @0x2ef350 stc2l p7, c15, [r4], #980
 *   @0x2ef354 andeq pc, r4, r9, asr #17
 *   @0x2ef358 .word 0xf7f59816
 *   @0x2ef35c .word 0xf8c9fcdf
 *   @0x2ef360 ldmdals r7, {r3}
 *   @0x2ef364 ldc2l p7, c15, [r10], {245}
 *   @0x2ef368 andeq pc, r12, r9, asr #17
 *   @0x2ef36c ldmdbvs r3!, {r2, r3, r4, r6, sp, lr, pc}
 *   @0x2ef370 ldmdbge r0, {r9, sp}
 *   @0x2ef374 .word 0x91019200
 *   @0x2ef378 movwls r2, #0x5104
 *   @0x2ef37c blls 0x400be4 <g_RomDisk+0x93c4>
 *   @0x2ef380 mcr2 p7, #0x4, pc, c5, c8, #0x7
 *   @0x2ef384 pkhbtmi r9, r0, r0, lsl #22
 *   @0x2ef388 cmple r0, r0, lsl #22
 *   @0x2ef38c strhs r4, [r4, -r2, lsl #13]
 *   @0x2ef390 .word 0xf8cd4699
 *   @0x2ef394 ldrbmi r9, [r8], -r0
 *   @0x2ef398 bls 0x3c0c24 <error_g0017+0x198c8>
 *   @0x2ef39c .word 0xf7ff4653
 *   @0x2ef3a0 stmdahs r0, {r0, r1, r4, r11, r12, sp, lr, pc}
 *   @0x2ef3a4 stmdals r5, {r1, r2, r9, r11, r12, lr, pc}
 *   @0x2ef3a8 movwhs r4, #0x3641
 *   @0x2ef3ac .word 0xf7f79310
 *   @0x2ef3b0 eors pc, r12, r2, asr #31
 *   @0x2ef3b4 addsmi r9, r0, #12288
 *   @0x2ef3b8 usub8mi sp, r8, r5
 *   @0x2ef3bc .word 0xf7fe4621
 *   @0x2ef3c0 blls 0x42e4cc <g_RomDisk+0x36cac>
 *   @0x2ef3c4 ldrmi r3, [r10], #3841
 *   @0x2ef3c8 ldrmi sp, [r10], r3, ror #3
 *   @0x2ef3cc strbmi r9, [r2], #2308
 *   @0x2ef3d0 ldrbmi r4, [r3], #-1721
 *   @0x2ef3d4 movwls r4, #0x863a
 *   @0x2ef3d8 movwls r4, #0xc40b
 *   @0x2ef3dc addmi r9, r10, #49152
 *   @0x2ef3e0 blls 0x563460 <g_SWFlineaavertbuff+0x10398>
 *   @0x2ef3e4 andeq pc, r9, r8, asr r8
 *   @0x2ef3e8 andvc pc, r9, r3, asr r8
 *   @0x2ef3ec .word 0xf7f59202
 *   @0x2ef3f0 mlasvs r8, r5, r12, pc
 *   @0x2ef3f4 andeq pc, r9, r10, asr r8
 *   @0x2ef3f8 ldc2 p7, c15, [r0], {245}
 *   @0x2ef3fc rsbsvs r9, r8, r8, lsl #18
 *   @0x2ef400 andeq pc, r9, r1, asr r8
 *   @0x2ef404 stc2 p7, c15, [r10], {245}
 *   @0x2ef408 adcsvs r9, r8, r12, lsl #22
 *   @0x2ef40c andeq pc, r9, r3, asr r8
 *   @0x2ef410 stmdbeq r4, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2ef414 stc2 p7, c15, [r2], {245}
 *   @0x2ef418 bls 0x387800 <_ZTS13C_UTF16String+0x1e8ac>
 *   @0x2ef41c ldrb r3, [sp, r1, lsl #4]
 *   @0x2ef420 strbmi r9, [r1], -r5, lsl #16
 *   @0x2ef424 .word 0xff87f7f7
 *   @0x2ef428 strbt r3, [r7], r1, lsl #26
 *   @0x2ef42c ldmdals r0, {r4, r8, r10, r12, pc}
 *   @0x2ef430 pop {r0, r3, r4, r12, sp, pc}
 *   @0x2ef434 movwhs r8, #0x3ff0
 *   @0x2ef438 .word 0xe7f89310
 *   @0x2ef43c svcmi #0xf0e92d
 *   @0x2ef440 strmi r4, [r8], sp, lsl #12
 *   @0x2ef444 ldrmi r4, [r1], r6, lsl #12
 *   @0x2ef448 stcgt p6, c4, [pc, #-616]
 *   @0x2ef44c svcge #0x5b0ef
 *   @0x2ef450 strgt r4, [pc], #-1596
 *   @0x2ef454 strgt r12, [pc], #-3343
 *   @0x2ef458 eorvs r6, r3, r11, lsr #16
 *   @0x2ef45c adcsvs r2, r11, r2, lsl #6
 *   @0x2ef460 .word 0x3008f8d8
 *   @0x2ef464 andle r2, r1, r10, lsl #22
 *   @0x2ef468 .word 0xd1012b07
 *   @0x2ef46c adcsvs r2, r11, r3, lsl #6
 *   @0x2ef470 eorhs r10, r0, #4, #24
 *   @0x2ef474 stmdbge lr, {r4, r5, r9, r10, lr}
 *   @0x2ef478 .word 0xf7ff4623
 *   @0x2ef47c stmdavs r2!, {r0, r2, r4, r5, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2ef480 blle 0x10b9c88 <b2_toiTime+0x9607e4>
 *   @0x2ef484 ldrsblo pc, [r8], -r8
 *   @0x2ef488 .word 0xb000f8d6
 *   @0x2ef48c svclt #0x88429a
 *   @0x2ef490 ldmvs r3!, {r0, r1, r5, sp, lr}
 *   @0x2ef494 .word 0xf8d89303
 *   @0x2ef498 blhs 0x4bb4c0 <SrcVerts+0x18504>
 *   @0x2ef49c .word 0xf8d8d006
 *   @0x2ef4a0 tstlt r11, r12, lsl r0
 *   @0x2ef4a4 .word 0x2000f8d9
 *   @0x2ef4a8 ldrbpl r6, [r1], #2081
 *   @0x2ef4ac .word 0xf04fad11
 *   @0x2ef4b0 stmdavs r3!, {r11}
 *   @0x2ef4b4 vldrle d2, [r7, #-0]
 *   @0x2ef4b8 .word 0x3c0cf855
 *   @0x2ef4bc shasxmi r4, r9, r0
 *   @0x2ef4c0 strlo r4, [r12, #-0x64a]
 *   @0x2ef4c4 .word 0xf8556033
 *   @0x2ef4c8 .word 0xf8cd3c14
 *   @0x2ef4cc adcsvs r8, r3, r0
 *   @0x2ef4d0 .word 0xf7ff4653
 *   @0x2ef4d4 stmdblt r0, {r0, r2, r3, r6, r9, r10, r11, r12, sp, lr, pc} ^
 *   @0x2ef4d8 ldcvc p9, c6, [r10, #-236]!
 *   @0x2ef4dc teqvs r11, r3, lsl r4
 *   @0x2ef4e0 bllo 0x349574
 *   @0x2ef4e4 strb r6, [r4, r3, lsr #32]!
 *   @0x2ef4e8 blls 0x3b74f0 <error_g0017+0x10194>
 *   @0x2ef4ec andlt pc, r0, r6, asr #17
 *   @0x2ef4f0 strh r6, [r0], -r3
 *   @0x2ef4f4 rsblt r2, pc, r2, lsr #1
 *   @0x2ef4f8 svchi #0xf0e8bd
 *   @0x2ef4fc svcmi #0xf0e92d
 *   @0x2ef500 sadd8mi r11, r5, r1
 *   @0x2ef504 bge 0x65a148 <g_SWFlinevertbuff+0x7080>
 *   @0x2ef508 subsmi r9, r3, sp
 *   @0x2ef50c subsmi r10, r3, r12, lsl #20
 *   @0x2ef510 strmi r9, [r4], -r12, lsl #2
 *   @0x2ef514 b 0xfe374984 <b2_toiTime+0xfffffffffdc1b4e0>
 *   @0x2ef518 subsmi r2, r3, r3, lsr #5
 *   @0x2ef51c stmdblt r11, {r0, r1, r3, r4, r7, r9, r12, sp, pc}
 *   @0x2ef520 orrlo pc, r4, #1879048196
 *   @0x2ef524 rsbsmi pc, r4, r4, lsl #4
 *   @0x2ef528 .word 0xf8c49005
 *   @0x2ef52c .word 0x21000540
 *   @0x2ef530 ldrbeq pc, [r4, #0x8d4]
 *   @0x2ef534 .word 0xf104930f
 *   @0x2ef538 strtvs r0, [r1], #-880
 *   @0x2ef53c ldrbtlo pc, [r0], #-2244
 *   @0x2ef540 .word 0xb048f8d4
 *   @0x2ef544 .word 0xf8d4b128
 *   @0x2ef548 ldrsblt r2, [r2, -r8]
 *   @0x2ef54c .word 0xf5c70092
 *   @0x2ef550 .word 0xf8dde830
 *   @0x2ef554 stmibvs r6!, {r4, r5, pc}
 *   @0x2ef558 stmibvs r7!, {r0, r2, r6, r10, lr} ^
 *   @0x2ef55c ldrbthi pc, [r8], #-2244
 *   @0x2ef560 .word 0xf8c49508
 *   @0x2ef564 .word 0xf8c4547c
 *   @0x2ef568 .word 0xf1bb8474
 *   @0x2ef56c andle r0, r2, r0, lsl #30
 *   @0x2ef570 muleq r9, r11, r8
 *   @0x2ef574 swphs r4, r8, [r0]
 *   @0x2ef578 stmibhs r0, {r0, r1, r2, r3, r4, r6, r7, r11, r12, sp, lr, pc} ^
 *   @0x2ef57c strmi r4, [r10], sp, lsl #12
 *   @0x2ef580 .word 0x9609447a
 *   @0x2ef584 andls r9, r11, #-2147483647
 *   @0x2ef588 ldrmi r9, [r8, #0xb08]
 *   @0x2ef58c strhi pc, [r3, #0x80]
 *   @0x2ef590 mulhs r0, r8, r8
 *   @0x2ef594 movweq pc, #0x1108
 *   @0x2ef598 ldrsbtgt pc, [r4], -sp
 *   @0x2ef59c movwls r2, #0x7a0b
 *   @0x2ef5a0 ldrbtne pc, [r0], #-2268
 *   @0x2ef5a4 stmdale r2!, {r0, r2, r3, r6, r12, lr, pc}
 *   @0x2ef5a8 eorsle r2, r11, r6, lsl #20
 *   @0x2ef5ac bhs 0x3e5600 <error_g0017+0x3e2a4>
 *   @0x2ef5b0 strhi pc, [r0]
 *   @0x2ef5b4 bhs 0x3655d0 <_ZTS12CDS_Priority+0x7628>
 *   @0x2ef5b8 andshs r11, r0, #8, #30
 *   @0x2ef5bc sbcshi pc, sp, r0
 *   @0x2ef5c0 bhs 0x42789c <g_RomDisk+0x3007c>
 *   @0x2ef5c4 ldrbhi pc, [r9, #-0x0]!
 *   @0x2ef5c8 .word 0xf0402a05
 *   @0x2ef5cc movwhs r8, #0xb0
 *   @0x2ef5d0 .word 0xf0002209
 *   @0x2ef5d4 bhs 0x51ebc8 <SrcVerts+0x7bc0c>
 *   @0x2ef5d8 .word 0xd326d02b
 *   @0x2ef5dc eorle r2, r12, r9, lsl #20
 *   @0x2ef5e0 .word 0xf0402a0a
 *   @0x2ef5e4 movwhs r8, #0xa4
 *   @0x2ef5e8 .word 0xf0002216
 *   @0x2ef5ec bhs 0x85ebb0 <b2_toiTime+0x10570c>
 *   @0x2ef5f0 stmdale r8, {r0, r1, r4, r5, r12, lr, pc}
 *   @0x2ef5f4 eorle r2, r8, sp, lsl #20
 *   @0x2ef5f8 bhs 0x6a42ec <g_SWFlinevertbuff+0x51224>
 *   @0x2ef5fc bhs 0x6e36a8 <g_SWFvertbuff+0x105e0>
 *   @0x2ef600 ldrbhi pc, [r1, #-0x0]
 *   @0x2ef604 bhs 0xaa7858 <b2_toiTime+0x34e3b4>
 *   @0x2ef608 stmdale r6, {r0, r1, r3, r5, r12, lr, pc}
 *   @0x2ef60c .word 0xf0402a16
 *   @0x2ef610 movwhs r8, #0x8e
 *   @0x2ef614 .word 0xf0002207
 *   @0x2ef618 bhs 0xadeb84 <b2_toiTime+0x3856e0>
 *   @0x2ef61c bhs 0x2e36b8 <_ZN15b2ContactSolver27SolveTOIPositionConstraintsEii+0x2e0>
 *   @0x2ef620 add sp, r4, r2, rrx
 *   @0x2ef624 .word 0xf0002300
 *   @0x2ef628 movwhs r11, #0xd51
 *   @0x2ef62c .word 0xf000220d
 *   @0x2ef630 movwhs r11, #0xd4d
 *   @0x2ef634 .word 0xf000220b
 *   @0x2ef638 movwhs r11, #0xd49
 *   @0x2ef63c .word 0xf0002205
 *   @0x2ef640 movwhs r11, #0xd45
 *   @0x2ef644 .word 0xf0002218
 *   @0x2ef648 movwhs r11, #0xd41
 *   @0x2ef64c .word 0xf0002202
 *   @0x2ef650 movwhs r11, #0xd3d
 *   @0x2ef654 .word 0xf0002201
 *   @0x2ef658 movwhs r11, #0xd39
 *   @0x2ef65c .word 0xf000220a
 *   @0x2ef660 movwhs r11, #0xd35
 *   @0x2ef664 .word 0xf000220c
 *   @0x2ef668 movwhs r11, #0xd31
 *   @0x2ef66c .word 0xf0002208
 *   @0x2ef670 stmdals r7, {r0, r2, r3, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2ef674 addsmi r9, r0, #8, #20
 *   @0x2ef678 ldrhi pc, [r1, #-0x80]
 *   @0x2ef67c movweq pc, #0x2108
 *   @0x2ef680 .word 0xf8989307
 *   @0x2ef684 blhs 0x4bb690 <SrcVerts+0x186d4>
 *   @0x2ef688 stmdale r12, {r1, r5, r12, lr, pc}
 *   @0x2ef68c andsle r2, r11, r1, lsl #22
 *   @0x2ef690 blhs 0x3a4460 <af_blue_strings+0x213c>
 *   @0x2ef694 ldrhi pc, [r4, #-0x0]
 *   @0x2ef698 .word 0xf0402b06
 *   @0x2ef69c movwhs r8, #0x500
 *   @0x2ef6a0 .word 0xf0002203
 *   @0x2ef6a4 blhs 0x71eaf8 <g_SWFvertbuff+0x4ba30>
 *   @0x2ef6a8 stmdale r6, {r1, r2, r4, r12, lr, pc}
 *   @0x2ef6ac .word 0xf0402b0c
 *   @0x2ef6b0 movwhs r8, #0x4f6
 *   @0x2ef6b4 .word 0xf0002214
 *   @0x2ef6b8 blhs 0x75eae4 <b2_toiTime+0x5640>
 *   @0x2ef6bc blhs 0xb63704 <b2_toiTime+0x40a260>
 *   @0x2ef6c0 ldrbthi pc, [r3], #0
 *   @0x2ef6c4 stcllt p0, c15, [r11], #0
 *   @0x2ef6c8 andshs r2, r3, #0, #6
 *   @0x2ef6cc ldcllt p0, c15, [lr], #0
 *   @0x2ef6d0 andhs r2, r4, #0, #6
 *   @0x2ef6d4 ldcllt p0, c15, [r10], #0
 *   @0x2ef6d8 andshs r2, r5, #0, #6
 *   @0x2ef6dc ldcllt p0, c15, [r6], #0
 *   @0x2ef6e0 andshs r2, r7, #0, #6
 *   @0x2ef6e4 ldcllt p0, c15, [r2], #0
 *   @0x2ef6e8 .word 0xf1089a08
 *   @0x2ef6ec andls r0, r7, r5
 *   @0x2ef6f0 vqsub.s8 d4, d16, d0
 *   @0x2ef6f4 .word 0xf89884d4
 *   @0x2ef6f8 .word 0xf8983002
 *   @0x2ef6fc ldreq r2, [r11], #-1
 *   @0x2ef700 movwvs lr, #0x2a43
 *   @0x2ef704 mulhs r4, r8, r8
 *   @0x2ef708 .word 0xf8984313
 *   @0x2ef70c b 0x13b7720 <b2_toiTime+0xc5e27c>
 *   @0x2ef710 .word 0xf5032302
 *   @0x2ef714 .word 0xf5b242fa
 *   @0x2ef718 vrecps.f32 q2, q0, q13
 *   @0x2ef71c stmdals r6, {r2, r4, r6, r7, r10, pc}
 *   @0x2ef720 .word 0xf0402800
 *   @0x2ef724 ldreq r8, [r11], #-1232
 *   @0x2ef728 .word 0xf0004602
 *   @0x2ef72c bhs 0xadea70 <b2_toiTime+0x3855cc>
 *   @0x2ef730 ldrthi pc, [r5], #576
 *   @0x2ef734 stmdale r2, {r1, r2, r4, r5, r6, r7, r9, r11, sp}
 *   @0x2ef738 orreq pc, r11, #-2147483608
 *   @0x2ef73c stmdals r8, {r0, r2, r4, sp, lr, pc}
 *   @0x2ef740 movweq pc, #0x2108
 *   @0x2ef744 addmi r9, r3, #469762048
 *   @0x2ef748 strthi pc, [r9], #512
 *   @0x2ef74c .word 0xf8982afa
 *   @0x2ef750 stmdale r5, {r0, r12, sp}
 *   @0x2ef754 movwhs lr, #0x2b03
 *   @0x2ef758 cmnmi r6, #683671552
 *   @0x2ef75c mul r4, r4, r11
 *   @0x2ef760 rscseq pc, r11, #-2147483600
 *   @0x2ef764 bne 0xff7affb4 <b2_toiTime+0xffffffffff056b10>
 *   @0x2ef768 bls 0x47e520 <targetStr+0x32e0>
 *   @0x2ef76c .word 0xf0402a00
 *   @0x2ef770 ldreq r8, [r11], #-1194
 *   @0x2ef774 stclt p0, c15, [r10], #0
 *   @0x2ef778 cmplt sp, pc, lsl #4
 *   @0x2ef77c andhs r2, r1, r0, lsl #6
 *   @0x2ef780 .word 0xf802fa00
 *   @0x2ef784 rscvc pc, r0, r0, lsl #2
 *   @0x2ef788 andeq lr, r0, r8, lsl #20
 *   @0x2ef78c svclt #0x82800
 *   @0x2ef790 and r2, r0, r0, lsl #10
 *   @0x2ef794 stmdals r6, {r0, r1, r3, r5, r9, r10, lr}
 *   @0x2ef798 teqlt r10, r0, lsr r1
 *   @0x2ef79c ldrheq pc, [r4], -r2
 *   @0x2ef7a0 .word 0x41434243
 *   @0x2ef7a4 ands r9, r1, r6, lsl #6
 *   @0x2ef7a8 and r11, r1, r2, lsl #19
 *   @0x2ef7ac andls r2, r6, r1
 *   @0x2ef7b0 rsbseq pc, r0, #12, #2
 *   @0x2ef7b4 .word 0xf5b21a8a
 *   @0x2ef7b8 .word 0xf2806f80
 *   @0x2ef7bc .word 0xf8418470
 *   @0x2ef7c0 blls 0x63e3d8 <g_SWFaavertbuff+0x6b310>
 *   @0x2ef7c4 ldrbtne pc, [r0], #-2243
 *   @0x2ef7c8 stcllt p0, c15, [r1], #-0
 *   @0x2ef7cc .word 0xf0402a15
 *   @0x2ef7d0 cpsid ai
 *   @0x2ef7d4 bne 0xfe5b019c <b2_toiTime+0xfffffffffde56cf8>
 *   @0x2ef7d8 .word 0xf3402b07
 *   @0x2ef7dc .word 0xf1a1845e
 *   @0x2ef7e0 rfedb r1!
 *   @0x2ef7e4 rfedb r1!
 *   @0x2ef7e8 bne 0xfe33e7f8 <b2_toiTime+0xfffffffffdbe5354>
 *   @0x2ef7ec svceq #0xa1ebb5
 *   @0x2ef7f0 ldrbhi pc, [r3], #-768
 *   @0x2ef7f4 stmeq r5, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2ef7f8 stmdaeq r0, {r3, r6, r7, r8, r9, r11, sp, lr, pc}
 *   @0x2ef7fc vpadd.i8 d2, d0, d12
 *   @0x2ef800 ldm pc, {r1, r2, r3, r4, r6, r8, pc} ^
 *   @0x2ef804 andseq pc, sp, r3, lsl r0
 *   @0x2ef808 subeq r0, r9, r0, lsr r0
 *   @0x2ef80c cmpeq r12, r3, ror r0
 *   @0x2ef810 cmpeq r12, r12, asr r1
 *   @0x2ef814 cmpeq r12, r12, asr r1
 *   @0x2ef818 cmpeq r12, r12, asr r1
 *   @0x2ef81c qdsubeq r0, r12, r3
 *   @0x2ef820 addeq r0, r3, r3, ror #2
 *   @0x2ef824 addeq r0, r3, r3, lsl #1
 *   @0x2ef828 addeq r0, r3, r3, lsl #1
 *   @0x2ef82c rsceq r0, r1, r3, asr #1
 *   @0x2ef830 rsceq r0, pc, r8, ror #1
 *   @0x2ef834 strdeq r0, r1, [r6, -r7]
 *   @0x2ef838 cmpeq r12, r1, lsr #2
 *   @0x2ef83c .word 0x01460138
 *   @0x2ef840 .word 0xf0402d03
 *   @0x2ef844 .word 0xf8dc842c
 *   @0x2ef848 blhs 0x2fce40 <TT_RunIns+0x4c>
 *   @0x2ef84c strthi pc, [r7], #-0
 *   @0x2ef850 strlo pc, [r0, #0x8dc]
 *   @0x2ef854 .word 0xf0402b07
 *   @0x2ef858 stm r8, {r1, r5, r10, pc}
 *   @0x2ef85c strhs r0, [r0, #-0xc0]
 *   @0x2ef860 beq 0x3ab9a4 <error_g0017+0x4648>
 *   @0x2ef864 stchs p1, c14, [r0, #-232]
 *   @0x2ef868 ldrhi pc, [r9], #-64
 *   @0x2ef86c ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2ef870 .word 0xf7ff463a
 *   @0x2ef874 stmdahs r0, {r1, r3, r4, r6, r11, r12, sp, lr, pc}
 *   @0x2ef878 strthi pc, [sp], #-64
 *   @0x2ef87c .word 0x21064620
 *   @0x2ef880 .word 0xfffdf7fe
 *   @0x2ef884 .word 0xf0402800
 *   @0x2ef888 blls 0x650928 <g_SWFaavertbuff+0x7d860>
 *   @0x2ef88c .word 0xf8c32201
 *   @0x2ef890 .word 0xf8c35580
 *   @0x2ef894 eor r2, r6, r12, ror r5
 *   @0x2ef898 .word 0xf0402d00
 *   @0x2ef89c .word 0xf8dc8400
 *   @0x2ef8a0 blhs 0x2fce98 <TT_RunIns+0xa4>
 *   @0x2ef8a4 .word 0x83fbf000
 *   @0x2ef8a8 strls pc, [r0, #0x8dc]
 *   @0x2ef8ac movweq pc, #0x1109
 *   @0x2ef8b0 strlo pc, [r0, #0x8cc]
 *   @0x2ef8b4 .word 0x33fff109
 *   @0x2ef8b8 ldmdale r4, {r0, r2, r8, r9, r11, sp}
 *   @0x2ef8bc .word 0x21014620
 *   @0x2ef8c0 .word 0xffddf7fe
 *   @0x2ef8c4 .word 0xf0402800
 *   @0x2ef8c8 .word 0xf1b983ea
 *   @0x2ef8cc andle r0, r4, r3, lsl #30
 *   @0x2ef8d0 andeq pc, r6, #1073741870
 *   @0x2ef8d4 cmpmi r3, r3, asr r2
 *   @0x2ef8d8 movwhs lr, #0x1000
 *   @0x2ef8dc ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2ef8e0 .word 0xf7fe463a
 *   @0x2ef8e4 .word 0xf04ffc59
 *   @0x2ef8e8 rscs r0, r7, r0, lsl #20
 *   @0x2ef8ec .word 0xf0402d01
 *   @0x2ef8f0 .word 0xf1bb83d6
 *   @0x2ef8f4 .word 0xf0000f00
 *   @0x2ef8f8 stmdbvs r2!, {r2, r3, r5, r6, r7, pc} ^
 *   @0x2ef8fc ldrsblo pc, [r4], -r11
 *   @0x2ef900 .word 0x0000f8db
 *   @0x2ef904 strhne pc, [r2], -r2
 *   @0x2ef908 smlal r4, r4, r8, r7
 *   @0x2ef90c ldrge pc, [r12, #0x8dc]!
 *   @0x2ef910 svceq #0xf1ba
 *   @0x2ef914 bichi pc, r3, #0
 *   @0x2ef918 stmdbeq sp, {r0, r1, r5, r7, r8, r12, sp, lr, pc}
 *   @0x2ef91c svclt #0x82b12
 *   @0x2ef920 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2ef924 .word 0x3000f8da
 *   @0x2ef928 .word 0xf309fb03
 *   @0x2ef92c .word 0xf040429d
 *   @0x2ef930 .word 0xf04f83b6
 *   @0x2ef934 bl 0x4f293c <SrcVerts+0x4f980>
 *   @0x2ef938 .word 0xf8cd0289
 *   @0x2ef93c andls r8, r10, #4
 *   @0x2ef940 strhs r9, [r1, #-0xb01]
 *   @0x2ef944 blhs 0x42da98 <g_RomDisk+0x36278>
 *   @0x2ef948 .word 0xf8da9301
 *   @0x2ef94c addmi r1, sp, #0
 *   @0x2ef950 blls 0x5a41a0 <g_SWFlineaavertbuff+0x510d8>
 *   @0x2ef954 bleq 0x42daa8 <g_RomDisk+0x36288>
 *   @0x2ef958 .word 0xf8da930a
 *   @0x2ef95c .word 0xf8533088
 *   @0x2ef960 strlo r1, [r1, #-0x25]
 *   @0x2ef964 .word 0xf8cd9204
 *   @0x2ef968 .word 0xf7fec00c
 *   @0x2ef96c bls 0x42dea4 <g_RomDisk+0x36684>
 *   @0x2ef970 .word 0xc00cf8dd
 *   @0x2ef974 strb r4, [r8, r2, lsl #8]!
 *   @0x2ef978 .word 0xf10c9b01
 *   @0x2ef97c strbmi r0, [r12, #0xc01]
 *   @0x2ef980 .word 0x2c04f843
 *   @0x2ef984 .word 0x46cad3dc
 *   @0x2ef988 adc r2, r7, r0, lsl #10
 *   @0x2ef98c .word 0xf8dc2d01
 *   @0x2ef990 .word 0xf04035bc
 *   @0x2ef994 blhs 0x3107ac <af_shaper_get_elem+0x601a>
 *   @0x2ef998 orrhi pc, r1, #0
 *   @0x2ef99c strheq pc, [r2], -r8
 *   @0x2ef9a0 vmlal.s8 q9, d0, d0
 *   @0x2ef9a4 ldmdavs r10, {r2, r3, r4, r5, r6, r8, r9, pc}
 *   @0x2ef9a8 ldrbne pc, [r8, #0x8dc]
 *   @0x2ef9ac addmi r1, sp, #8716288
 *   @0x2ef9b0 cmnhi r5, #0, #4
 *   @0x2ef9b4 ldrbne pc, [r4, #0x8dc]
 *   @0x2ef9b8 bl 0x32fc08
 *   @0x2ef9bc .word 0xf8d30080
 *   @0x2ef9c0 .word 0xf5c61088
 *   @0x2ef9c4 ldrsht lr, [r12], -r12
 *   @0x2ef9c8 .word 0xf0402d02
 *   @0x2ef9cc ldm r8, {r3, r5, r6, r8, r9, pc}
 *   @0x2ef9d0 ldrmi r0, [r3], #-12
 *   @0x2ef9d4 stchs p0, c14, [r2, #-360]
 *   @0x2ef9d8 msrhi SPSR_c, #64
 *   @0x2ef9dc muleq r12, r8, r8
 *   @0x2ef9e0 ldrsb r1, [r3], #-163
 *   @0x2ef9e4 .word 0xf0402d02
 *   @0x2ef9e8 ldm r8, {r1, r3, r4, r6, r8, r9, pc}
 *   @0x2ef9ec .word 0xf7fe0003
 *   @0x2ef9f0 and pc, r11, r10, lsl #18
 *   @0x2ef9f4 .word 0xf0402d02
 *   @0x2ef9f8 .word 0xf8d88352
 *   @0x2ef9fc stmdbhs r0, {r2, r12}
 *   @0x2efa00 movthi pc, #0xd000
 *   @0x2efa04 .word 0x0000f8d8
 *   @0x2efa08 blx 0x186d9e4 <b2_toiTime+0x1114540>
 *   @0x2efa0c andeq pc, r0, r8, asr #17
 *   @0x2efa10 stchs p0, c14, [r2, #-388]
 *   @0x2efa14 ldrlo pc, [r12, #0x8dc]!
 *   @0x2efa18 movthi pc, #0x1040
 *   @0x2efa1c .word 0xf0002b00
 *   @0x2efa20 rfeib r8!
 *   @0x2efa24 blhs 0x2fba44 <ps_hints_apply+0xa644>
 *   @0x2efa28 teqhi r9, #192, #4
 *   @0x2efa2c ldrbhs pc, [r8, #0x8dc]
 *   @0x2efa30 .word 0xf0804293
 *   @0x2efa34 .word 0xf8d88334
 *   @0x2efa38 .word 0xf8dc2000
 *   @0x2efa3c .word 0xf84115d4
 *   @0x2efa40 strhs r2, [r0, #-0x23]
 *   @0x2efa44 sub r4, r9, r10, lsr #13
 *   @0x2efa48 .word 0xf8dc2d01
 *   @0x2efa4c .word 0xf04035bc
 *   @0x2efa50 blhs 0x3106f0 <af_shaper_get_elem+0x5f5e>
 *   @0x2efa54 msrhi CPSR_xc, #0
 *   @0x2efa58 strhlo pc, [r2], -r8
 *   @0x2efa5c .word 0xf2c02b00
 *   @0x2efa60 .word 0xf8dc831e
 *   @0x2efa64 addsmi r2, r3, #216, #10
 *   @0x2efa68 tsthi r9, #128
 *   @0x2efa6c ldrbhs pc, [r4, #0x8dc]
 *   @0x2efa70 eorlo pc, r3, r2, asr r8
 *   @0x2efa74 stchs p0, c14, [r4, #-40]
 *   @0x2efa78 tsthi r1, #64
 *   @0x2efa7c .word 0x2008f8d8
 *   @0x2efa80 .word 0x300cf8d8
 *   @0x2efa84 stcle p2, c4, [r6, #-616]!
 *   @0x2efa88 .word 0x3004f8d8
 *   @0x2efa8c andlo pc, r0, r8, asr #17
 *   @0x2efa90 stchs p0, c14, [r0, #-132]
 *   @0x2efa94 movwhi pc, #0x3040
 *   @0x2efa98 .word 0xf5b39b0f
 *   @0x2efa9c svclt #0xa84f00
 *   @0x2efaa0 .word 0xf8c83301
 *   @0x2efaa4 stmdals pc, {r12, sp}
 *   @0x2efaa8 orrlo pc, r0, r0, asr #11
 *   @0x2efaac .word 0xf8abf7fe
 *   @0x2efab0 andls r11, pc, r8, lsl #2
 *   @0x2efab4 .word 0xf642e010
 *   @0x2efab8 movwls r0, #0xf373
 *   @0x2efabc stchs p0, c14, [r0, #-48]
 *   @0x2efac0 rschi pc, sp, #192, #4
 *   @0x2efac4 .word 0xf6bf2b00
 *   @0x2efac8 rsc r10, r8, #14, #30
 *   @0x2efacc strhs r4, [r0, #-0x690]
 *   @0x2efad0 ldrbmi lr, [sp], -r9, lsl #14
 *   @0x2efad4 strhs lr, [r0, #-0x0]
 *   @0x2efad8 beq 0x36bc1c <_ZTS13C_UTF16String+0x2cc8>
 *   @0x2efadc bl 0x516718 <SrcVerts+0x7375c>
 *   @0x2efae0 .word 0xf8c3028a
 *   @0x2efae4 sbcs r2, r2, #112, #8
 *   @0x2efae8 bl 0x315b1c <FT_Bitmap_Embolden+0xcd6>
 *   @0x2efaec cpsid ai
 *   @0x2efaf0 bne 0x4efcb8 <SrcVerts+0x4ccfc>
 *   @0x2efaf4 .word 0x3080f8d3
 *   @0x2efaf8 svceq #0xa0ebb3
 *   @0x2efafc sbchi pc, sp, #0, #6
 *   @0x2efb00 stmibeq r3, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2efb04 bl 0xff53e310 <b2_toiTime+0xfffffffffede4e6c>
 *   @0x2efb08 bhs 0x931f14 <b2_toiTime+0x1d8a70>
 *   @0x2efb0c sbchi pc, r7, #0, #4
 *   @0x2efb10 .word 0xf012e8df
 *   @0x2efb14 eorseq r0, sp, r10, lsl r0
 *   @0x2efb18 tsteq r3, r5, asr r0
 *   @0x2efb1c teqeq r12, r3, lsr r1
 *   @0x2efb20 cmpeq lr, r8, asr #2
 *   @0x2efb24 smlalbbeq r0, r12, r6, r1
 *   @0x2efb28 .word 0x01d2019d
 *   @0x2efb2c andeq r0, r6, #-1073741762
 *   @0x2efb30 rsbseq r0, pc, #-1610612725
 *   @0x2efb34 addeq r0, lr, #1342177288
 *   @0x2efb38 andeq r0, r9, #-1610612727
 *   @0x2efb3c andseq r0, r6, #1342177292
 *   @0x2efb40 rsbeq r0, lr, #536870918
 *   @0x2efb44 adcseq r0, r10, #1342177291
 *   @0x2efb48 .word 0xf7fe4620
 *   @0x2efb4c .word 0xf1bbf9a0
 *   @0x2efb50 .word 0xd1030f00
 *   @0x2efb54 .word 0xf7f568e0
 *   @0x2efb58 adds pc, r12, #211968
 *   @0x2efb5c .word 0xf8db6962
 *   @0x2efb60 .word 0xf8db3008
 *   @0x2efb64 rfeib r2!
 *   @0x2efb68 ldrmi r1, [r8, r2]
 *   @0x2efb6c .word 0xf0402800
 *   @0x2efb70 blls 0x6505d0 <g_SWFaavertbuff+0x7d508>
 *   @0x2efb74 ldrsbpl pc, [r8], -r11
 *   @0x2efb78 .word 0x0000f8db
 *   @0x2efb7c stclvs p9, c6, [r2], #388
 *   @0x2efb80 strblo pc, [r0, #0x8d3]
 *   @0x2efb84 stmdahs r0, {r3, r5, r7, r8, r9, r10, lr}
 *   @0x2efb88 adchi pc, r5, #64
 *   @0x2efb8c movwhs lr, #0x17e2
 *   @0x2efb90 strtvs r6, [r3], #-2594
 *   @0x2efb94 .word 0xf8d92000
 *   @0x2efb98 stmibvs r6!, {r12, sp}
 *   @0x2efb9c eorvs r4, r3, #318767104
 *   @0x2efba0 .word 0x3004f8d9
 *   @0x2efba4 stmibvs r7!, {r5, r6, r7, r9, sp, lr} ^
 *   @0x2efba8 .word 0xf8d962a3
 *   @0x2efbac ldrmi r3, [lr], #-0
 *   @0x2efbb0 umaallo pc, r6, r4, r8
 *   @0x2efbb4 .word 0xf0402b00
 *   @0x2efbb8 strls r8, [r9], -lr, ror #4
 *   @0x2efbbc .word 0xf8d9e264
 *   @0x2efbc0 .word 0xf8d92008
 *   @0x2efbc4 .word 0xf8d97000
 *   @0x2efbc8 andls r5, r5, #4
 *   @0x2efbcc ldrbhs pc, [r12, #0x89c]
 *   @0x2efbd0 .word 0x100cf8d9
 *   @0x2efbd4 ldrsbmi pc, [r0], -r9
 *   @0x2efbd8 .word 0x3004f8dc
 *   @0x2efbdc .word 0xf0402a00
 *   @0x2efbe0 .word 0xf89c825e
 *   @0x2efbe4 bhs 0x2f7d04 <ps_hints_apply+0x6904>
 *   @0x2efbe8 subshi pc, r9, #64
 *   @0x2efbec strbhs pc, [r12, #-0x8dc]
 *   @0x2efbf0 .word 0x6020f8dc
 *   @0x2efbf4 .word 0x3080f8d3
 *   @0x2efbf8 blvs 0x199e068 <b2_toiTime+0x1244bc4>
 *   @0x2efbfc .word 0xf0002a00
 *   @0x2efc00 blvs 0x19d0540 <b2_toiTime+0x127709c>
 *   @0x2efc04 stmdbmi r1!, {r0, r1, r2, r3, r6, r9, r11, sp, lr, pc}
 *   @0x2efc08 ldmdblt r11!, {r2, r5, r10, r12} ^
 *   @0x2efc0c strbtmi r4, [r0], -r9, asr #12
 *   @0x2efc10 andgt pc, r12, sp, asr #17
 *   @0x2efc14 stc2 p7, c15, [r6, #-1016]
 *   @0x2efc18 .word 0xc00cf8dd
 *   @0x2efc1c strmi r4, [r1], r1, lsr #12
 *   @0x2efc20 .word 0xf7fe4660
 *   @0x2efc24 .word 0xf8ddfcff
 *   @0x2efc28 strmi r12, [r4], -r12
 *   @0x2efc2c svceq #0xf1b9
 *   @0x2efc30 eorshi pc, r5, #192, #4
 *   @0x2efc34 vmull.s8 q9, d0, d0
 *   @0x2efc38 bl 0x450508 <g_RomDisk+0x58ce8>
 *   @0x2efc3c .word 0xf89c0806
 *   @0x2efc40 cmnlt r5, #69
 *   @0x2efc44 .word 0x6008f8dc
 *   @0x2efc48 .word 0xf8d62102
 *   @0x2efc4c .word 0xf8d2209c
 *   @0x2efc50 ldrbmi r11, [r8], -r0
 *   @0x2efc54 blx 0x6adc3e <g_SWFlinevertbuff+0x5ab76>
 *   @0x2efc58 .word 0xf0402800
 *   @0x2efc5c .word 0xf8db823c
 *   @0x2efc60 .word 0xf2405058
 *   @0x2efc64 adcvs r2, r8, r2, lsl #4
 *   @0x2efc68 rscvs r8, r8, r10, lsr #1
 *   @0x2efc6c andeq lr, r8, r7, asr #23
 *   @0x2efc70 strhs r6, [r2], #-556
 *   @0x2efc74 andls pc, r0, r5, asr #17
 *   @0x2efc78 .word 0xf7f584ac
 *   @0x2efc7c strne pc, [r0], #-2127
 *   @0x2efc80 stmdals r5, {r3, r5, r7, r9, sp, lr}
 *   @0x2efc84 .word 0xf84af7f5
 *   @0x2efc88 rscvs r1, r8, #0, #8
 *   @0x2efc8c addmi pc, r0, r6, asr #17
 *   @0x2efc90 ldrsbths pc, [r4], -r11
 *   @0x2efc94 addhs pc, r4, r6, asr #17
 *   @0x2efc98 ldrtvs r4, [r2], #2727
 *   @0x2efc9c subsmi pc, r4, r11, asr #17
 *   @0x2efca0 .word 0xf8dce1f9
 *   @0x2efca4 .word 0xf04f000c
 *   @0x2efca8 .word 0xf8cd0a01
 *   @0x2efcac .word 0xf7f5c00c
 *   @0x2efcb0 .word 0xf8ddfb15
 *   @0x2efcb4 strbmi r12, [r9], -r12
 *   @0x2efcb8 ldrbge pc, [r12, #0x88c]
 *   @0x2efcbc .word 0xf8dc4660
 *   @0x2efcc0 .word 0xf8cd35c4
 *   @0x2efcc4 ldrmi r12, [r8, r12]
 *   @0x2efcc8 .word 0xc00cf8dd
 *   @0x2efccc ldrbpl pc, [r12, #0x88c]
 *   @0x2efcd0 .word 0xf0402800
 *   @0x2efcd4 .word 0xf8dc8200
 *   @0x2efcd8 bl 0xff4b7d60 <b2_toiTime+0xfffffffffed5e8bc>
 *   @0x2efcdc blls 0x431904 <g_RomDisk+0x3a0e4>
 *   @0x2efce0 .word 0xf8dc4621
 *   @0x2efce4 .word 0xf8ccb024
 *   @0x2efce8 .word 0xf8cc0020
 *   @0x2efcec strbtmi r0, [r0], -r4, lsr #32
 *   @0x2efcf0 andslo pc, r12, r12, asr #17
 *   @0x2efcf4 .word 0x6028f8dc
 *   @0x2efcf8 .word 0x902cf8dc
 *   @0x2efcfc andsvc pc, r8, r12, asr #17
 *   @0x2efd00 ldrbge pc, [r12, #0x88c]
 *   @0x2efd04 strblo pc, [r4, #0x8dc]
 *   @0x2efd08 .word 0xf8cd9204
 *   @0x2efd0c ldrmi r12, [r8, r12]
 *   @0x2efd10 .word 0xc00cf8dd
 *   @0x2efd14 ldrbpl pc, [r12, #0x88c]
 *   @0x2efd18 stmdahs r0, {r2, r9, r11, r12, pc}
 *   @0x2efd1c bicshi pc, r11, r0, asr #32
 *   @0x2efd20 eorhs pc, r0, r12, asr #17
 *   @0x2efd24 eorlt pc, r4, r12, asr #17
 *   @0x2efd28 eorvs pc, r8, r12, asr #17
 *   @0x2efd2c eorls pc, r12, r12, asr #17
 *   @0x2efd30 andseq pc, r8, r12, asr #17
 *   @0x2efd34 andseq pc, r12, r12, asr #17
 *   @0x2efd38 bvs 0xba8474 <b2_toiTime+0x44efd0>
 *   @0x2efd3c strtvs r2, [r3], #-769
 *   @0x2efd40 .word 0x3000f8d9
 *   @0x2efd44 ldrmi r6, [r3], #-2470
 *   @0x2efd48 eorvs r6, r3, #401408
 *   @0x2efd4c .word 0x3004f8d9
 *   @0x2efd50 ldrmi r6, [r3], #-2535
 *   @0x2efd54 .word 0xf8d96263
 *   @0x2efd58 adcvs r3, r3, #8
 *   @0x2efd5c .word 0x300cf8d9
 *   @0x2efd60 .word 0xf8d962e3
 *   @0x2efd64 ldrmi r3, [lr], #-0
 *   @0x2efd68 .word 0x3004f8d9
 *   @0x2efd6c .word 0xf894441f
 *   @0x2efd70 blhs 0x2fbe90 <ps_hints_apply+0xaa90>
 *   @0x2efd74 orrhi pc, r8, r0
 *   @0x2efd78 stcvs p1, c14, [r3], #-564
 *   @0x2efd7c blhs 0x33e98c
 *   @0x2efd80 strtmi sp, [r0], -r2, lsl #16
 *   @0x2efd84 .word 0xf883f7fe
 *   @0x2efd88 ands r2, pc, r1, lsl #6
 *   @0x2efd8c ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2efd90 .word 0xf7fe463a
 *   @0x2efd94 stmdahs r0, {r1, r3, r6, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2efd98 orrshi pc, sp, r0, asr #32
 *   @0x2efd9c .word 0x3000f8d9
 *   @0x2efda0 sub r4, r11, lr, lsl r4
 *   @0x2efda4 .word 0x3000f8d9
 *   @0x2efda8 and r4, r5, lr, lsl r4
 *   @0x2efdac .word 0x3000f8d9
 *   @0x2efdb0 .word 0xf8d9441e
 *   @0x2efdb4 ldrmi r3, [pc], #-4
 *   @0x2efdb8 ldrblo pc, [r12, #-0x8dc]!
 *   @0x2efdbc .word 0xf0402b00
 *   @0x2efdc0 stcvs p1, c8, [r3], #-396
 *   @0x2efdc4 .word 0xf0002b00
 *   @0x2efdc8 movwhs r8, #0x216a
 *   @0x2efdcc cmp r11, r3, lsr #8
 *   @0x2efdd0 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2efdd4 .word 0xf7fe463a
 *   @0x2efdd8 stmdahs r0, {r3, r5, r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2efddc cmnhi r11, r0, asr #32
 *   @0x2efde0 .word 0x21034620
 *   @0x2efde4 stc2l p7, c15, [r11, #-1016]
 *   @0x2efde8 stmdahs r0, {r7, r9, r10, lr}
 *   @0x2efdec cmphi r9, r0, asr #32
 *   @0x2efdf0 .word 0x3000f8d9
 *   @0x2efdf4 qasxmi r4, r0, r10
 *   @0x2efdf8 .word 0x4643441e
 *   @0x2efdfc .word 0xf7fe4631
 *   @0x2efe00 .word 0xf8d9f9cb
 *   @0x2efe04 strtmi r3, [r0], -r4
 *   @0x2efe08 .word 0xf8d9441e
 *   @0x2efe0c ldrmi r3, [pc], #-8
 *   @0x2efe10 .word 0x46434631
 *   @0x2efe14 .word 0xf7fe463a
 *   @0x2efe18 .word 0xf8d9f9bf
 *   @0x2efe1c sub r3, r3, r12
 *   @0x2efe20 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2efe24 .word 0xf7fe463a
 *   @0x2efe28 stmdahs r0, {r7, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2efe2c cmphi r3, r0, asr #32
 *   @0x2efe30 .word 0x3000f8d9
 *   @0x2efe34 .word 0xf8d9441e
 *   @0x2efe38 ldrmi r3, [pc], #-4
 *   @0x2efe3c ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2efe40 .word 0xf7fe463a
 *   @0x2efe44 stmdahs r0, {r0, r5, r6, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2efe48 tsthi lr, r0
 *   @0x2efe4c strtmi lr, [r0], -r3, asr #2
 *   @0x2efe50 shasxmi r4, r10, r1
 *   @0x2efe54 stc2l p7, c15, [r9, #-1016]!
 *   @0x2efe58 .word 0xf0402800
 *   @0x2efe5c qasxmi r8, r0, r12
 *   @0x2efe60 .word 0xf7fe2103
 *   @0x2efe64 strmi pc, [r0], r12, lsl #26
 *   @0x2efe68 .word 0xf0402800
 *   @0x2efe6c .word 0xf8d9811a
 *   @0x2efe70 strtmi r3, [r0], -r0
 *   @0x2efe74 .word 0xf8d9441e
 *   @0x2efe78 ldrmi r3, [pc], #-4
 *   @0x2efe7c .word 0x46434631
 *   @0x2efe80 .word 0xf7fe463a
 *   @0x2efe84 .word 0xf8d9f989
 *   @0x2efe88 strtmi r3, [r0], -r8
 *   @0x2efe8c .word 0xf8d9441e
 *   @0x2efe90 ldrmi r3, [pc], #-12
 *   @0x2efe94 .word 0x46434631
 *   @0x2efe98 .word 0xf7fe463a
 *   @0x2efe9c .word 0xf8d9f97d
 *   @0x2efea0 ldrmi r3, [lr], #-16
 *   @0x2efea4 ldrsblo pc, [r4], -r9
 *   @0x2efea8 qadd16mi r4, r0, pc
 *   @0x2efeac shasxmi r4, r10, r1
 *   @0x2efeb0 .word 0xf7fe2301
 *   @0x2efeb4 rsc pc, r7, r1, ror r9
 *   @0x2efeb8 ldrtmi r4, [r1], -r0, lsr #12
 *   @0x2efebc .word 0xf7fe463a
 *   @0x2efec0 stmdahs r0, {r2, r4, r5, r8, r10, r11, r12, sp, lr, pc}
 *   @0x2efec4 .word 0x8107f040
 *   @0x2efec8 .word 0x21034620
 *   @0x2efecc ldc2l p7, c15, [r7], {254}
 *   @0x2efed0 stmdahs r0, {r7, r9, r10, lr}
 *   @0x2efed4 rschi pc, r5, r0, asr #32
 *   @0x2efed8 .word 0x3000f8d9
 *   @0x2efedc qasxmi r4, r0, r1
 *   @0x2efee0 .word 0x4643441f
 *   @0x2efee4 .word 0xf7fe463a
 *   @0x2efee8 .word 0xf8d9f957
 *   @0x2efeec strtmi r3, [r0], -r4
 *   @0x2efef0 .word 0xf8d9441e
 *   @0x2efef4 ldrmi r3, [pc], #-8
 *   @0x2efef8 .word 0x46434631
 *   @0x2efefc .word 0xf7fe463a
 *   @0x2eff00 .word 0xf8d9f94b
 *   @0x2eff04 ldrmi r3, [lr], #-12
 *   @0x2eff08 strtmi lr, [r0], -pc, asr #15
 *   @0x2eff0c shasxmi r4, r10, r1
 *   @0x2eff10 stc2 p7, c15, [r11, #-1016]
 *   @0x2eff14 .word 0xf0402800
 *   @0x2eff18 .word 0xf8d980de
 *   @0x2eff1c str r3, [r12, r0]
 *   @0x2eff20 .word 0x3000f8d9
 *   @0x2eff24 ldm r9, {r0, r1, r2, r6, r8, r9, r10, sp, lr, pc}
 *   @0x2eff28 .word 0xf7f40003
 *   @0x2eff2c .word 0xf849ffc4
 *   @0x2eff30 andhs r0, r0, r4, lsl #22
 *   @0x2eff34 adc r9, r7, r6
 *   @0x2eff38 .word 0x636f6d70
 *   @0x2eff3c andeq r1, r10, r12, lsl #4
 *   @0x2eff40 strbne pc, [r0, #-0x8dc]!
 *   @0x2eff44 strheq pc, [r2], -r9
 *   @0x2eff48 .word 0xf7f5b129
 *   @0x2eff4c stmdahs r0, {r0, r1, r3, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2eff50 adchi pc, r5, r0
 *   @0x2eff54 stmdahs r0, {r11, sp, lr}
 *   @0x2eff58 adchi pc, r1, r0, asr #5
 *   @0x2eff5c .word 0xf8d39b0d
 *   @0x2eff60 addsmi r2, r0, #84, #10
 *   @0x2eff64 addshi pc, r11, r0, lsl #5
 *   @0x2eff68 vmla.i8 d9, d3, d5
 *   @0x2eff6c bne 0xff5c0d44 <b2_toiTime+0xfffffffffee678a0>
 *   @0x2eff70 .word 0xf3002bbf
 *   @0x2eff74 blls 0x4d01cc <SrcVerts+0x2d210>
 *   @0x2eff78 b 0x16c17a8 <b2_toiTime+0xf68304>
 *   @0x2eff7c .word 0xf8420c80
 *   @0x2eff80 blls 0x63ebb8 <g_SWFaavertbuff+0x6baf0>
 *   @0x2eff84 ldrbne pc, [r8, #-0x8d3]
 *   @0x2eff88 eorhi pc, r0, r1, asr r8
 *   @0x2eff8c .word 0xf8c19905
 *   @0x2eff90 .word 0xf8d38010
 *   @0x2eff94 qsublt r1, r12, r1
 *   @0x2eff98 eorne pc, r0, r1, asr r8
 *   @0x2eff9c strbmi r9, [r1], #-2053
 *   @0x2effa0 stmdals r5, {r2, r3, sp, lr, pc}
 *   @0x2effa4 ldrbne pc, [r0, #-0x8d3]
 *   @0x2effa8 svclt #0xac2900
 *   @0x2effac .word 0xf1084441
 *   @0x2effb0 mrsvs r0, apsr
 *   @0x2effb4 ldrbne pc, [r8, #-0x8d3]
 *   @0x2effb8 stmdavs r9, {r0, r5, r6, r10, lr} ^
 *   @0x2effbc stmdals r5, {r0, r6, r8, sp, lr}
 *   @0x2effc0 sbcvs r6, r1, r1, lsl #18
 *   @0x2effc4 rsble r2, r10, r0, lsl #18
 *   @0x2effc8 strbhs pc, [r0, #-0x8c3]
 *   @0x2effcc stmdbvs r3, {r0, r8, r11, sp, lr} ^
 *   @0x2effd0 .word 0x91079205
 *   @0x2effd4 subs r9, r7, r8, lsl #6
 *   @0x2effd8 svceq #0xf1ba
 *   @0x2effdc .word 0xf10ad002
 *   @0x2effe0 ldrsh r3, [r1], #-175
 *   @0x2effe4 subsle r2, r10, r0, lsl #26
 *   @0x2effe8 .word 0xf1093d01
 *   @0x2effec sub r0, r11, r4, lsl #18
 *   @0x2efff0 vadd.i8 d9, d12, d5
 *   @0x2efff4 addsmi r4, r8, #116, #6
 *   @0x2efff8 .word 0xf850d951
 *   @0x2efffc .word 0xf1a01c0c
 *   @0x2f0000 .word 0xf850030c
 *   @0x2f0004 movwls r2, #0x5c04
 *   @0x2f0008 andls r9, r8, #-1073741823
 *   @0x2f000c strblo pc, [r0, #-0x8cc]
 *   @0x2f0010 .word 0xf1bbe03a
 *   @0x2f0014 eorsle r0, r7, r0, lsl #30
 *   @0x2f0018 .word 0x300cf8db
 *   @0x2f001c .word 0xf1bbe004
 *   @0x2f0020 eorsle r0, r1, r0, lsl #30
 *   @0x2f0024 ldrsblo pc, [r0], -r11
 *   @0x2f0028 .word 0x0000f8db
 *   @0x2f002c eor r2, r3, r1, lsl #2
 *   @0x2f0030 svceq #0xf1bb
 *   @0x2f0034 .word 0xf8d9d028
 *   @0x2f0038 stmdals r9, {r12, sp}
 *   @0x2f003c .word 0xf8c94403
 *   @0x2f0040 .word 0xf8db3000
 *   @0x2f0044 ands r3, r4, r12
 *   @0x2f0048 svceq #0xf1bb
 *   @0x2f004c stmdbls r9, {r2, r3, r4, r12, lr, pc}
 *   @0x2f0050 .word 0x3000f8d9
 *   @0x2f0054 .word 0xf8c9440b
 *   @0x2f0058 .word 0xf8d93000
 *   @0x2f005c strmi r3, [r11], #-8
 *   @0x2f0060 andlo pc, r8, r9, asr #17
 *   @0x2f0064 ldrsblo pc, [r0], -r9
 *   @0x2f0068 .word 0xf8c9440b
 *   @0x2f006c .word 0xf8db3010
 *   @0x2f0070 .word 0xf8db3010
 *   @0x2f0074 .word 0x21000000
 *   @0x2f0078 ldrmi r4, [r8, r10, asr #12]
 *   @0x2f007c ldm r9, {r2, sp, lr, pc}
 *   @0x2f0080 andhs r0, r0, #192
 *   @0x2f0084 ldrbhs pc, [r12, #-0x8cc]!
 *   @0x2f0088 .word 0xf8c39b0d
 *   @0x2f008c .word 0xf8dd9470
 *   @0x2f0090 .word 0xf7ff801c
 *   @0x2f0094 andhs r11, r0, r9, ror r10
 *   @0x2f0098 adchs lr, r1, sp, lsl r0
 *   @0x2f009c adchs lr, r0, r11, lsl r0
 *   @0x2f00a0 .word 0x4640e019
 *   @0x2f00a4 andshs lr, r10, #23
 *   @0x2f00a8 andshs lr, r9, #0
 *   @0x2f00ac ldrmi r2, [sp], -r0, lsl #6
 *   @0x2f00b0 bllt 0x1f6e0b4 <b2_toiTime+0x1814c10>
 *   @0x2f00b4 andshs r2, r2, #0, #6
 *   @0x2f00b8 movwhs lr, #0x8
 *   @0x2f00bc and r2, r5, lr, lsl #4
 *   @0x2f00c0 andshs r2, r1, #0, #6
 *   @0x2f00c4 andhs lr, r0, #2
 *   @0x2f00c8 andls r2, r6, r1
 *   @0x2f00cc .word 0xf47f2d00
 *   @0x2f00d0 .word 0xf7ffab56
 *   @0x2f00d4 andslt r11, r1, r0, ror #22
 *   @0x2f00d8 svchi #0xf0e8bd
 *   @0x2f00dc andlo pc, r0, #132096
 *   @0x2f00e0 rscvc lr, r2, pc, asr #20
 *   @0x2f00e4 andmi pc, r0, r0, lsl #10
 *   @0x2f00e8 .word 0xf142181b
 *   @0x2f00ec b 0x16b08f4 <b2_toiTime+0xf57450>
 *   @0x2f00f0 b 0x1300144 <b2_toiTime+0xba6ca0>
 *   @0x2f00f4 ldrbmi r4, [r0, -r2]!
 *   @0x2f00f8 ldrblt r6, [r0, #0x803]!
 *   @0x2f00fc stmvs r2, {r0, r3, r4, r7, r9, lr}
 *   @0x2f0100 tsths r12, #1879048194
 *   @0x2f0104 .word 0x2101fb03
 *   @0x2f0108 .word 0xf013690b
 *   @0x2f010c .word 0xd1200204
 *   @0x2f0110 movweq pc, #0x4043
 *   @0x2f0114 stmdbvs r4, {r0, r1, r3, r8, sp, lr}
 *   @0x2f0118 .word 0x3c046843
 *   @0x2f011c .word 0xb163614a
 *   @0x2f0120 svchs #0x4f854
 *   @0x2f0124 stmdavs pc, {r0, r2, r3, r11, sp, lr} ^
 *   @0x2f0128 strtmi r6, [pc], #-2070
 *   @0x2f012c blle 0x680c10 <g_SWFlinevertbuff+0x2db48>
 *   @0x2f0130 ldrtmi r6, [lr], #-2135
 *   @0x2f0134 blle 0x580bf4 <g_SWFlineaavertbuff+0x2db2c>
 *   @0x2f0138 ldm r0, {r1, r3, r6, r8, sp, lr}
 *   @0x2f013c addsmi r0, r3, #12
 *   @0x2f0140 stmdbvs r2, {r0, r1, r2, r9, r12, lr, pc}
 *   @0x2f0144 subvs r1, r4, r12, asr r12
 *   @0x2f0148 eorne pc, r3, r2, asr #16
 *   @0x2f014c bllo 0x35f914 <_ZTS12CDS_Priority+0x196c>
 *   @0x2f0150 ldcllt p7, c14, [r0, #916]!
 *   @0x2f0154 mvnsmi lr, sp, lsr #18
 *   @0x2f0158 ldrblo pc, [pc, #0x4f]!
 *   @0x2f015c .word 0xf8d1688c
 *   @0x2f0160 stmdavs r3, {lr, pc}
 *   @0x2f0164 smlalbblt r6, r3, r2, r8
 *   @0x2f0168 bllo 0x34a5b4
 *   @0x2f016c andslo r6, r12, #1073741861
 *   @0x2f0170 .word 0x0104f021
 *   @0x2f0174 .word 0x1c0cf842
 *   @0x2f0178 ssub8mi lr, r9, r5
 *   @0x2f017c sadd16mi r4, r10, lr
 *   @0x2f0180 ldmdaeq r12, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f0184 andsle r4, r9, r1, ror #10
 *   @0x2f0188 stmdavc r6!, {r1, r4, r8, r11, r12, sp, pc}
 *   @0x2f018c addhs r3, r0, #16777216
 *   @0x2f0190 andsle r4, r0, r6, lsl r2
 *   @0x2f0194 blx 0x50a3b2 <SrcVerts+0x673f6>
 *   @0x2f0198 stmdbvs pc!, {r0, r8, r10, r12, lr}
 *   @0x2f019c svceq #0x4f017
 *   @0x2f01a0 .word 0xf047d109
 *   @0x2f01a4 .word 0x612f0704
 *   @0x2f01a8 adcsmi r6, r11, #458752
 *   @0x2f01ac stmvs r7, {r0, r1, r9, r12, lr, pc} ^
 *   @0x2f01b0 eorpl pc, r3, r7, asr #16
 *   @0x2f01b4 subsne r3, r2, r1, lsl #6
 *   @0x2f01b8 strb r3, [r3, r1, lsl #2]!
 *   @0x2f01bc .word 0xc00cf8d0
 *   @0x2f01c0 subvs r2, r3, r1, lsl #4
 *   @0x2f01c4 ble 0x740c34 <g_SWFvertbuff+0x6db6c>
 *   @0x2f01c8 svcpl #0x4f85c
 *   @0x2f01cc uqsaxmi r1, r1, r4
 *   @0x2f01d0 blle 0x53b1d8 <obj_has_event+0x668>
 *   @0x2f01d4 stcvs p8, c15, [r4, #-324]
 *   @0x2f01d8 ldmdavs r0!, {r0, r1, r2, r3, r5, r11, sp, lr}
 *   @0x2f01dc blle 0x3c0cc4 <error_g0017+0x19968>
 *   @0x2f01e0 rsbeq lr, r0, r1, lsl #17
 *   @0x2f01e4 ldrb r3, [r3, r1, lsl #24]!
 *   @0x2f01e8 strb r3, [r11, r1, lsl #4]!
 *   @0x2f01ec ldrhhi lr, [r0, #141]!
 *   @0x2f01f0 .word 0x73e1ea81
 *   @0x2f01f4 .word 0x73e1eba3
 *   @0x2f01f8 rscvc lr, r0, #128, #20
 *   @0x2f01fc rscvc lr, r0, #165888
 *   @0x2f0200 strhs r11, [r12], #-1328
 *   @0x2f0204 .word 0xf503fb04
 *   @0x2f0208 ble 0x440c64 <g_RomDisk+0x49444>
 *   @0x2f020c svclt #0xb42800
 *   @0x2f0210 andeq pc, r1, pc, rrx
 *   @0x2f0214 ldclt p0, c2, [r0, #-8]!
 *   @0x2f0218 addsmi r4, r10, #-2013265919
 *   @0x2f021c stmdbhs r0, {r0, r2, r9, r11, r12, lr, pc}
 *   @0x2f0220 strhhs r11, [r1], -r4
 *   @0x2f0224 rscslo pc, pc, pc, asr #32
 *   @0x2f0228 andhs r11, r4, r0, lsr sp
 *   @0x2f022c ldrlt r11, [r0, #-0xd30]!
 *   @0x2f0230 stmvs r3, {r1, r6, r8, r11, sp, lr}
 *   @0x2f0234 andhs r6, r0, r4, lsl #16
 *   @0x2f0238 andlo r6, r8, #5373952
 *   @0x2f023c .word 0x6118b194
 *   @0x2f0240 stmdblt r9!, {r3, r4, r7, r8, sp, lr}
 *   @0x2f0244 .word 0x5c08f852
 *   @0x2f0248 .word 0xf85261dd
 *   @0x2f024c and r5, r4, r4, lsl #24
 *   @0x2f0250 .word 0x5c04f852
 *   @0x2f0254 .word 0xf85261dd
 *   @0x2f0258 andsvs r5, sp, #8, #24
 *   @0x2f025c .word 0x33283c01
 *   @0x2f0260 strb r3, [r11, r8, lsl #4]!
 *   @0x2f0264 push {r4, r5, r8, r10, r11, r12, sp, pc}
 *   @0x2f0268 .word 0xf8dd4ff0
 *   @0x2f026c stmvs r5, {r2, r5, pc} ^
 *   @0x2f0270 .word 0xf1c86846
 *   @0x2f0274 bhs 0x2f327c <ps_hints_apply+0x1e7c>
 *   @0x2f0278 adchi pc, r1, r0
 *   @0x2f027c stmibvs r12, {r3, r8, r11, sp, lr} ^
 *   @0x2f0280 cps #0x7
 *   @0x2f0284 .word 0xf9918099
 *   @0x2f0288 strbmi r7, [r7, #-0x14]
 *   @0x2f028c strbmi sp, [r7, #-0x3d]!
 *   @0x2f0290 .word 0xf991d005
 *   @0x2f0294 strbmi r7, [r7, #-0x15]
 *   @0x2f0298 strbmi sp, [r7, #-0x37]!
 *   @0x2f029c .word 0xb3b7d137
 *   @0x2f02a0 tstle r4, r7, asr #10
 *   @0x2f02a4 stmdbeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f02a8 .word 0xf00045b1
 *   @0x2f02ac .word 0xf8558085
 *   @0x2f02b0 .word 0xf8daa029
 *   @0x2f02b4 blne 0xffccc2bc <b2_toiTime+0xffffffffff572e18>
 *   @0x2f02b8 ble 0x440d3c <g_RomDisk+0x4951c>
 *   @0x2f02bc addsmi r4, pc, #-268435449
 *   @0x2f02c0 vst1.8 {d29, d30}, [r0], r2
 *   @0x2f02c4 ands r7, r12, r4
 *   @0x2f02c8 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f02cc strbmi lr, [r7, #-0x7ec]!
 *   @0x2f02d0 .word 0xf04fd172
 *   @0x2f02d4 and r0, r1, r0, lsl #18
 *   @0x2f02d8 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f02dc strhtle r4, [r11], #-81
 *   @0x2f02e0 eorge pc, r9, r5, asr r8
 *   @0x2f02e4 .word 0x7000f8da
 *   @0x2f02e8 bleq 0x42b20c <g_RomDisk+0x339ec>
 *   @0x2f02ec .word 0x7004f8da
 *   @0x2f02f0 streq lr, [r11, -r7, asr #23]
 *   @0x2f02f4 ble 0xffec0d78 <b2_toiTime+0xffffffffff7678d4>
 *   @0x2f02f8 addsmi r4, pc, #-268435449
 *   @0x2f02fc vst1.64 {d29, d30}, [r0:128], r12
 *   @0x2f0300 smlabbvs r8, r2, r0, r6
 *   @0x2f0304 andsge pc, r8, r1, asr #17
 *   @0x2f0308 svchs #0xe056
 *   @0x2f030c strbeq sp, [r7], -r10, asr #3
 *   @0x2f0310 .word 0xf1b8d552
 *   @0x2f0314 svclt #0x140f02
 *   @0x2f0318 stmibvc r0, {r0, r1, r2, r3, r6, r10, r12, sp, lr, pc}
 *   @0x2f031c stmibeq r0, {r0, r1, r2, r3, r6, r12, sp, lr, pc}
 *   @0x2f0320 usada8hs r0, r4, pc, r11
 *   @0x2f0324 strvc pc, [r0, pc, asr #8]
 *   @0x2f0328 stmdbeq r0, {r0, r3, r4, r9, r11, sp, lr, pc}
 *   @0x2f032c .word 0xf04fd015
 *   @0x2f0330 ldrmi r0, [r1, #0x900]!
 *   @0x2f0334 .word 0xf855d02c
 *   @0x2f0338 .word 0xf8daa029
 *   @0x2f033c blne 0xffccc344 <b2_toiTime+0xffffffffff572ea0>
 *   @0x2f0340 ble 0x4c0dc4 <SrcVerts+0x1de08>
 *   @0x2f0344 addsmi r4, pc, #-268435449
 *   @0x2f0348 .word 0xf8c1da04
 *   @0x2f034c vst4.8 {d26, d27, d28, d29}, [r0:64], r8
 *   @0x2f0350 ands r7, r12, r4
 *   @0x2f0354 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f0358 andmi lr, r7, #61603840
 *   @0x2f035c and sp, r1, r8, lsl r0
 *   @0x2f0360 stmdbeq r1, {r0, r3, r8, r12, sp, lr, pc}
 *   @0x2f0364 ldrhle r4, [r3], -r1
 *   @0x2f0368 eorge pc, r9, r5, asr r8
 *   @0x2f036c .word 0x7000f8da
 *   @0x2f0370 bleq 0x42b294 <g_RomDisk+0x33a74>
 *   @0x2f0374 .word 0x7004f8da
 *   @0x2f0378 streq lr, [r11, -r7, asr #23]
 *   @0x2f037c ble 0xffec0e00 <b2_toiTime+0xffffffffff76795c>
 *   @0x2f0380 addsmi r4, pc, #-268435449
 *   @0x2f0384 vst1.64 {d29, d30}, [r0:128], r12
 *   @0x2f0388 .word 0xf8c16082
 *   @0x2f038c .word 0x6108a018
 *   @0x2f0390 stmiblt pc, {r0, r1, r2, r3, r7, r8, r11, sp, lr}
 *   @0x2f0394 strhle r4, [pc], -r7
 *   @0x2f0398 eorls pc, r7, r5, asr r8
 *   @0x2f039c .word 0xa000f8d9
 *   @0x2f03a0 blle 0x4c18f8 <SrcVerts+0x1e93c>
 *   @0x2f03a4 .word 0x0004f8d9
 *   @0x2f03a8 ldrbmi r4, [r4, #-0x482]
 *   @0x2f03ac .word 0xf8c1dc02
 *   @0x2f03b0 and r9, r1, r8, lsl r0
 *   @0x2f03b4 strb r3, [sp, r1, lsl #14]!
 *   @0x2f03b8 .word 0x31283a01
 *   @0x2f03bc pop {r0, r1, r3, r4, r6, r8, r9, r10, sp, lr, pc}
 *   @0x2f03c0 ldrblt r8, [r8, #0xff0]!
 *   @0x2f03c4 blx 0x3f96fe <g_RomDisk+0x1ede>
 *   @0x2f03c8 stcne p4, c0, [r5, #-4]!
 *   @0x2f03cc .word 0xf8d56866
 *   @0x2f03d0 tstlt r6, #196
 *   @0x2f03d4 ldrtmi r6, [r9], -r8, ror #16
 *   @0x2f03d8 mcr2 p7, #0x4, pc, c0, c15, #0x7
 *   @0x2f03dc strtlo r3, [r0], #-3585
 *   @0x2f03e0 eorlo r6, r0, r8, lsr #1
 *   @0x2f03e4 eorseq pc, pc, r0, lsr #32
 *   @0x2f03e8 .word 0xb1b660e8
 *   @0x2f03ec .word 0x0c0cf854
 *   @0x2f03f0 .word 0xf7ff4639
 *   @0x2f03f4 stmvs r11!, {r0, r1, r4, r5, r6, r9, r10, r11, r12, sp, lr, pc}
 *   @0x2f03f8 strlo r3, [r12], #-3585
 *   @0x2f03fc bhs 0x2f6f0c <ps_hints_apply+0x5b0c>
 *   @0x2f0400 subsmi r11, r2, #184, #30
 *   @0x2f0404 svclt #0xc82a7f
 *   @0x2f0408 .word 0xf8444603
 *   @0x2f040c .word 0x33203c14
 *   @0x2f0410 teqeq pc, #35
 *   @0x2f0414 .word 0x3c10f844
 *   @0x2f0418 ldcllt p7, c14, [r8, #924]!
 *   @0x2f041c movwhs r3, #0x102
 *   @0x2f0420 addmi r11, r3, #48, #10
 *   @0x2f0424 .word 0x0104f101
 *   @0x2f0428 rfeda r1!
 *   @0x2f042c movwlo r5, #0x2c04
 *   @0x2f0430 .word 0x4c06f831
 *   @0x2f0434 eorlt r1, r4, #44, #22
 *   @0x2f0438 svclt #0xb842a2
 *   @0x2f043c ldrb r4, [r0, r2, lsr #12]!
 *
 * ══ §2/7 anon_2b3f58  0x2b3f58  size 7748  700 条（0x2b3f58..0x2b5d9c）｜其中 1237 条已由别的卡落锚，本节不再重复
 * @func 0x2b4374 0x2b5d9c  size 6696  700 条
 * 部分覆盖: 本节 700/1674 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: anon_2b3f58×3 / anon_2b3f58+0x394×2 / 0xb65d4×2 / anon_2b3f58+0x788×2 / anon_2b3f58+0x41c×2 / anon_2b3f58+0x1858×2 / anon_2b3f58+0x470 / anon_2b3f58+0x444
 * 字段偏移 top8: 0x4×106 / 0xc×60 / 0x14×55 / 0x18×48 / 0x1c×23 / 0x17c×18 / 0x24×17 / 0x194×17
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b4374 cmp r2, #13
 *   @0x2b4378 add r3, r2, r3
 *   @0x2b437c push {r4, r5, r6, r7, lr}
 *   @0x2b4380 mov r5, r1
 *   @0x2b4384 sub sp, sp, #12
 *   @0x2b4388 mov r4, r0
 *   @0x2b438c bls 0x2b43c8 <jinit_input_controller+0x4e8>
 *   @0x2b4390 ldrb r2, [r1]
 *   @0x2b4394 cmp r2, #74
 *   @0x2b4398 beq 0x2b43f0 <jinit_input_controller+0x510>
 *   @0x2b439c ldr r2, [r4]
 *   @0x2b43a0 mov r12, #77
 *   @0x2b43a4 str r3, [r2, #0x18]
 *   @0x2b43a8 mov r0, r4
 *   @0x2b43ac ldr r3, [r4]
 *   @0x2b43b0 mov r1, #1
 *   @0x2b43b4 str r12, [r2, #0x14]
 *   @0x2b43b8 ldr r3, [r3, #0x4]
 *   @0x2b43bc blx r3
 *   @0x2b43c0 add sp, sp, #12
 *   @0x2b43c4 pop {r4, r5, r6, r7, pc}
 *   @0x2b43c8 cmp r2, #5
 *   @0x2b43cc bls 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b43d0 ldrb r2, [r1]
 *   @0x2b43d4 cmp r2, #74
 *   @0x2b43d8 bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b43dc ldrb r2, [r1, #0x1]
 *   @0x2b43e0 cmp r2, #70
 *   @0x2b43e4 bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b43e8 ldrb r2, [r1, #0x2]
 *   @0x2b43ec b 0x2b4408 <jinit_input_controller+0x528>
 *   @0x2b43f0 ldrb r2, [r1, #0x1]
 *   @0x2b43f4 cmp r2, #70
 *   @0x2b43f8 bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b43fc ldrb r2, [r1, #0x2]
 *   @0x2b4400 cmp r2, #73
 *   @0x2b4404 beq 0x2b447c <jinit_input_controller+0x59c>
 *   @0x2b4408 cmp r2, #88
 *   @0x2b440c bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b4410 ldrb r2, [r5, #0x3]
 *   @0x2b4414 cmp r2, #88
 *   @0x2b4418 bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b441c ldrb r2, [r5, #0x4]
 *   @0x2b4420 cmp r2, #0
 *   @0x2b4424 bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b4428 ldrb r2, [r5, #0x5]
 *   @0x2b442c cmp r2, #17
 *   @0x2b4430 beq 0x2b45b0 <jinit_input_controller+0x6d0>
 *   @0x2b4434 cmp r2, #19
 *   @0x2b4438 beq 0x2b45a4 <jinit_input_controller+0x6c4>
 *   @0x2b443c cmp r2, #16
 *   @0x2b4440 ldr r2, [r4]
 *   @0x2b4444 moveq r12, #108
 *   @0x2b4448 beq 0x2b43a4 <jinit_input_controller+0x4c4>
 *   @0x2b444c mov r12, #89
 *   @0x2b4450 str r12, [r2, #0x14]
 *   @0x2b4454 ldrb r12, [r5, #0x5]
 *   @0x2b4458 mov r0, r4
 *   @0x2b445c mov r1, #1
 *   @0x2b4460 str r12, [r2, #0x18]
 *   @0x2b4464 ldr r2, [r4]
 *   @0x2b4468 str r3, [r2, #0x1c]
 *   @0x2b446c ldr r3, [r4]
 *   @0x2b4470 ldr r3, [r3, #0x4]
 *   @0x2b4474 blx r3
 *   @0x2b4478 b 0x2b43c0 <jinit_input_controller+0x4e0>
 *   @0x2b447c ldrb r2, [r1, #0x3]
 *   @0x2b4480 cmp r2, #70
 *   @0x2b4484 bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b4488 ldrb r2, [r1, #0x4]
 *   @0x2b448c cmp r2, #0
 *   @0x2b4490 bne 0x2b439c <jinit_input_controller+0x4bc>
 *   @0x2b4494 mov r2, #1
 *   @0x2b4498 strb r2, [r0, #0x100]
 *   @0x2b449c ldrb r2, [r1, #0x5]
 *   @0x2b44a0 mov r12, #260
 *   @0x2b44a4 movw r1, #0x106
 *   @0x2b44a8 cmp r2, #1
 *   @0x2b44ac strb r2, [r0, #0x101]
 *   @0x2b44b0 ldrb r2, [r5, #0x6]
 *   @0x2b44b4 strb r2, [r0, #0x102]
 *   @0x2b44b8 ldrb r2, [r5, #0x7]
 *   @0x2b44bc strb r2, [r0, #0x103]
 *   @0x2b44c0 ldrb lr, [r5, #0x8]
 *   @0x2b44c4 ldrb r2, [r5, #0x9]
 *   @0x2b44c8 add r2, r2, lr, lsl #8
 *   @0x2b44cc strh r2, [r0, r12]
 *   @0x2b44d0 ldrb r12, [r5, #0xa]
 *   @0x2b44d4 ldrb r2, [r5, #0xb]
 *   @0x2b44d8 add r2, r2, r12, lsl #8
 *   @0x2b44dc strh r2, [r0, r1]
 *   @0x2b44e0 beq 0x2b451c <jinit_input_controller+0x63c>
 *   @0x2b44e4 ldr r2, [r0]
 *   @0x2b44e8 mov r12, #119
 *   @0x2b44ec mvn r1, #0
 *   @0x2b44f0 str r12, [r2, #0x14]
 *   @0x2b44f4 ldrb r12, [r0, #0x101]
 *   @0x2b44f8 str r12, [r2, #0x18]
 *   @0x2b44fc ldr r2, [r0]
 *   @0x2b4500 ldrb r12, [r0, #0x102]
 *   @0x2b4504 str r12, [r2, #0x1c]
 *   @0x2b4508 ldr r2, [r0]
 *   @0x2b450c ldr r2, [r2, #0x4]
 *   @0x2b4510 str r3, [sp, #0x4]
 *   @0x2b4514 blx r2
 *   @0x2b4518 ldr r3, [sp, #0x4]
 *   @0x2b451c ldr r2, [r4]
 *   @0x2b4520 mov r12, #260
 *   @0x2b4524 ldrb r1, [r4, #0x101]
 *   @0x2b4528 movw r0, #0x106
 *   @0x2b452c ldrh lr, [r4, r0]
 *   @0x2b4530 mov r6, #87
 *   @0x2b4534 ldrh r7, [r4, r12]
 *   @0x2b4538 mov r0, r4
 *   @0x2b453c str r1, [r2, #0x18]
 *   @0x2b4540 mov r1, #1
 *   @0x2b4544 ldrb r12, [r4, #0x102]
 *   @0x2b4548 str r7, [r2, #0x20]
 *   @0x2b454c str lr, [r2, #0x24]
 *   @0x2b4550 str r12, [r2, #0x1c]
 *   @0x2b4554 ldrb lr, [r4, #0x103]
 *   @0x2b4558 ldr r12, [r2, #0x4]
 *   @0x2b455c str r6, [r2, #0x14]
 *   @0x2b4560 str lr, [r2, #0x28]
 *   @0x2b4564 str r3, [sp, #0x4]
 *   @0x2b4568 blx r12
 *   @0x2b456c ldrb r1, [r5, #0xd]
 *   @0x2b4570 ldrb r2, [r5, #0xc]
 *   @0x2b4574 ldr r3, [sp, #0x4]
 *   @0x2b4578 orrs r2, r1, r2
 *   @0x2b457c moveq r1, r2
 *   @0x2b4580 bne 0x2b45bc <jinit_input_controller+0x6dc>
 *   @0x2b4584 smulbb r2, r1, r2
 *   @0x2b4588 sub r3, r3, #14
 *   @0x2b458c add r2, r2, r2, lsl #1
 *   @0x2b4590 cmp r2, r3
 *   @0x2b4594 ldrne r2, [r4]
 *   @0x2b4598 movne r12, #88
 *   @0x2b459c bne 0x2b43a4 <jinit_input_controller+0x4c4>
 *   @0x2b45a0 b 0x2b43c0 <jinit_input_controller+0x4e0>
 *   @0x2b45a4 ldr r2, [r4]
 *   @0x2b45a8 mov r12, #110
 *   @0x2b45ac b 0x2b43a4 <jinit_input_controller+0x4c4>
 *   @0x2b45b0 ldr r2, [r4]
 *   @0x2b45b4 mov r12, #109
 *   @0x2b45b8 b 0x2b43a4 <jinit_input_controller+0x4c4>
 *   @0x2b45bc ldr r2, [r4]
 *   @0x2b45c0 mov r12, #90
 *   @0x2b45c4 mov r1, #1
 *   @0x2b45c8 mov r0, r4
 *   @0x2b45cc str r12, [r2, #0x14]
 *   @0x2b45d0 ldrb r12, [r5, #0xc]
 *   @0x2b45d4 str r12, [r2, #0x18]
 *   @0x2b45d8 ldr r2, [r4]
 *   @0x2b45dc ldrb r12, [r5, #0xd]
 *   @0x2b45e0 str r12, [r2, #0x1c]
 *   @0x2b45e4 ldr r2, [r4]
 *   @0x2b45e8 ldr r2, [r2, #0x4]
 *   @0x2b45ec str r3, [sp, #0x4]
 *   @0x2b45f0 blx r2
 *   @0x2b45f4 ldrb r1, [r5, #0xc]
 *   @0x2b45f8 ldrb r2, [r5, #0xd]
 *   @0x2b45fc ldr r3, [sp, #0x4]
 *   @0x2b4600 b 0x2b4584 <jinit_input_controller+0x6a4>
 *   @0x2b4604 push {r4, r5, r6, r7, r8, lr}
 *   @0x2b4608 mov r4, r0
 *   @0x2b460c ldr r5, [r0, #0x18]
 *   @0x2b4610 ldr r3, [r5, #0x4]
 *   @0x2b4614 ldr r6, [r5]
 *   @0x2b4618 cmp r3, #0
 *   @0x2b461c beq 0x2b46c0 <jinit_input_controller+0x7e0>
 *   @0x2b4620 ldrb r7, [r6]
 *   @0x2b4624 subs r8, r3, #1
 *   @0x2b4628 addne r6, r6, #1
 *   @0x2b462c lsl r7, r7, #8
 *   @0x2b4630 bne 0x2b464c <jinit_input_controller+0x76c>
 *   @0x2b4634 ldr r3, [r5, #0xc]
 *   @0x2b4638 mov r0, r4
 *   @0x2b463c blx r3
 *   @0x2b4640 cmp r0, #0
 *   @0x2b4644 beq 0x2b46d8 <jinit_input_controller+0x7f8>
 *   @0x2b4648 ldm r5, {r6, r8}
 *   @0x2b464c ldr r2, [r4]
 *   @0x2b4650 mov r1, #91
 *   @0x2b4654 ldr r12, [r4, #0x17c]
 *   @0x2b4658 mov r0, r4
 *   @0x2b465c ldrb r3, [r6], #1
 *   @0x2b4660 sub r8, r8, #1
 *   @0x2b4664 str r1, [r2, #0x14]
 *   @0x2b4668 mov r1, #1
 *   @0x2b466c str r12, [r2, #0x18]
 *   @0x2b4670 add r7, r3, r7
 *   @0x2b4674 ldr r3, [r4]
 *   @0x2b4678 sub r7, r7, #2
 *   @0x2b467c str r7, [r3, #0x1c]
 *   @0x2b4680 ldr r3, [r4]
 *   @0x2b4684 ldr r3, [r3, #0x4]
 *   @0x2b4688 blx r3
 *   @0x2b468c cmp r7, #0
 *   @0x2b4690 str r6, [r5]
 *   @0x2b4694 str r8, [r5, #0x4]
 *   @0x2b4698 ble 0x2b46b8 <jinit_input_controller+0x7d8>
 *   @0x2b469c ldr r3, [r4, #0x18]
 *   @0x2b46a0 mov r0, r4
 *   @0x2b46a4 mov r1, r7
 *   @0x2b46a8 ldr r3, [r3, #0x10]
 *   @0x2b46ac blx r3
 *   @0x2b46b0 mov r0, #1
 *   @0x2b46b4 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b46b8 mov r0, #1
 *   @0x2b46bc pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b46c0 ldr r3, [r5, #0xc]
 *   @0x2b46c4 blx r3
 *   @0x2b46c8 cmp r0, #0
 *   @0x2b46cc ldrne r6, [r5]
 *   @0x2b46d0 ldrne r3, [r5, #0x4]
 *   @0x2b46d4 bne 0x2b4620 <jinit_input_controller+0x740>
 *   @0x2b46d8 mov r0, #0
 *   @0x2b46dc pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b46e0 push {r4, r5, r6, r7, r8, lr}
 *   @0x2b46e4 mov r8, r0
 *   @0x2b46e8 ldr r5, [r0, #0x18]
 *   @0x2b46ec ldr r4, [r5, #0x4]
 *   @0x2b46f0 ldr r6, [r5]
 *   @0x2b46f4 cmp r4, #0
 *   @0x2b46f8 beq 0x2b47c8 <jinit_input_controller+0x8e8>
 *   @0x2b46fc ldrb r3, [r6]
 *   @0x2b4700 sub r4, r4, #1
 *   @0x2b4704 add r2, r6, #1
 *   @0x2b4708 cmp r3, #255
 *   @0x2b470c bne 0x2b472c <jinit_input_controller+0x84c>
 *   @0x2b4710 b 0x2b47ec <jinit_input_controller+0x90c>
 *   @0x2b4714 ldrb r1, [r2]
 *   @0x2b4718 add r3, r2, #1
 *   @0x2b471c sub r4, r4, #1
 *   @0x2b4720 cmp r1, #255
 *   @0x2b4724 mov r2, r3
 *   @0x2b4728 beq 0x2b4794 <jinit_input_controller+0x8b4>
 *   @0x2b472c ldr r3, [r8, #0x194]
 *   @0x2b4730 cmp r4, #0
 *   @0x2b4734 ldr r1, [r3, #0x14]
 *   @0x2b4738 add r1, r1, #1
 *   @0x2b473c str r1, [r3, #0x14]
 *   @0x2b4740 stm r5, {r2, r4}
 *   @0x2b4744 bne 0x2b4714 <jinit_input_controller+0x834>
 *   @0x2b4748 ldr r3, [r5, #0xc]
 *   @0x2b474c mov r0, r8
 *   @0x2b4750 blx r3
 *   @0x2b4754 cmp r0, #0
 *   @0x2b4758 beq 0x2b47e4 <jinit_input_controller+0x904>
 *   @0x2b475c ldm r5, {r2, r4}
 *   @0x2b4760 b 0x2b4714 <jinit_input_controller+0x834>
 *   @0x2b4764 ldr r3, [r5, #0xc]
 *   @0x2b4768 mov r0, r8
 *   @0x2b476c blx r3
 *   @0x2b4770 cmp r0, #0
 *   @0x2b4774 beq 0x2b47e4 <jinit_input_controller+0x904>
 *   @0x2b4778 ldm r5, {r3, r4}
 *   @0x2b477c ldrb r7, [r3]
 *   @0x2b4780 add r6, r3, #1
 *   @0x2b4784 sub r4, r4, #1
 *   @0x2b4788 cmp r7, #255
 *   @0x2b478c mov r3, r6
 *   @0x2b4790 bne 0x2b47a0 <jinit_input_controller+0x8c0>
 *   @0x2b4794 cmp r4, #0
 *   @0x2b4798 bne 0x2b477c <jinit_input_controller+0x89c>
 *   @0x2b479c b 0x2b4764 <jinit_input_controller+0x884>
 *   @0x2b47a0 cmp r7, #0
 *   @0x2b47a4 ldr r3, [r8, #0x194]
 *   @0x2b47a8 bne 0x2b47f4 <jinit_input_controller+0x914>
 *   @0x2b47ac ldr r2, [r3, #0x14]
 *   @0x2b47b0 cmp r4, #0
 *   @0x2b47b4 add r2, r2, #2
 *   @0x2b47b8 str r2, [r3, #0x14]
 *   @0x2b47bc str r6, [r5]
 *   @0x2b47c0 str r4, [r5, #0x4]
 *   @0x2b47c4 bne 0x2b46fc <jinit_input_controller+0x81c>
 *   @0x2b47c8 ldr r3, [r5, #0xc]
 *   @0x2b47cc mov r0, r8
 *   @0x2b47d0 blx r3
 *   @0x2b47d4 cmp r0, #0
 *   @0x2b47d8 ldrne r6, [r5]
 *   @0x2b47dc ldrne r4, [r5, #0x4]
 *   @0x2b47e0 bne 0x2b46fc <jinit_input_controller+0x81c>
 *   @0x2b47e4 mov r0, #0
 *   @0x2b47e8 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b47ec mov r3, r2
 *   @0x2b47f0 b 0x2b4794 <jinit_input_controller+0x8b4>
 *   @0x2b47f4 ldr r3, [r3, #0x14]
 *   @0x2b47f8 cmp r3, #0
 *   @0x2b47fc bne 0x2b4814 <jinit_input_controller+0x934>
 *   @0x2b4800 str r7, [r8, #0x17c]
 *   @0x2b4804 mov r0, #1
 *   @0x2b4808 str r6, [r5]
 *   @0x2b480c str r4, [r5, #0x4]
 *   @0x2b4810 pop {r4, r5, r6, r7, r8, pc}
 *   @0x2b4814 ldr r2, [r8]
 *   @0x2b4818 mov r12, #116
 *   @0x2b481c mov r0, r8
 *   @0x2b4820 mvn r1, #0
 *   @0x2b4824 str r3, [r2, #0x18]
 *   @0x2b4828 ldr r3, [r8]
 *   @0x2b482c str r12, [r2, #0x14]
 *   @0x2b4830 str r7, [r3, #0x1c]
 *   @0x2b4834 ldr r3, [r8]
 *   @0x2b4838 ldr r3, [r3, #0x4]
 *   @0x2b483c blx r3
 *   @0x2b4840 ldr r3, [r8, #0x194]
 *   @0x2b4844 mov r2, #0
 *   @0x2b4848 str r2, [r3, #0x14]
 *   @0x2b484c b 0x2b4800 <jinit_input_controller+0x920>
 *   @0x2b4850 ldr r2, [r0, #0x194]
 *   @0x2b4854 mov r3, #0
 *   @0x2b4858 str r3, [r0, #0xc4]
 *   @0x2b485c str r3, [r0, #0x7c]
 *   @0x2b4860 str r3, [r0, #0x17c]
 *   @0x2b4864 strb r3, [r2, #0xc]
 *   @0x2b4868 strb r3, [r2, #0xd]
 *   @0x2b486c str r3, [r2, #0x14]
 *   @0x2b4870 str r3, [r2, #0xa0]
 *   @0x2b4874 bx lr
 *   @0x2b57b0 cmp r2, #11
 *   @0x2b57b4 mov r12, r1
 *   @0x2b57b8 push {r3, r4, r5, r6, r7, r8, r9, lr}
 *   @0x2b57bc mov r4, r0
 *   @0x2b57c0 bls 0x2b57d0 <jinit_input_controller+0x18f0>
 *   @0x2b57c4 ldrb r1, [r1]
 *   @0x2b57c8 cmp r1, #65
 *   @0x2b57cc beq 0x2b57fc <jinit_input_controller+0x191c>
 *   @0x2b57d0 ldr r12, [r4]
 *   @0x2b57d4 add r2, r2, r3
 *   @0x2b57d8 mov lr, #78
 *   @0x2b57dc mov r0, r4
 *   @0x2b57e0 mov r1, #1
 *   @0x2b57e4 str r2, [r12, #0x18]
 *   @0x2b57e8 ldr r3, [r4]
 *   @0x2b57ec str lr, [r12, #0x14]
 *   @0x2b57f0 ldr r3, [r3, #0x4]
 *   @0x2b57f4 blx r3
 *   @0x2b57f8 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b57fc ldrb r1, [r12, #0x1]
 *   @0x2b5800 cmp r1, #100
 *   @0x2b5804 bne 0x2b57d0 <jinit_input_controller+0x18f0>
 *   @0x2b5808 ldrb r1, [r12, #0x2]
 *   @0x2b580c cmp r1, #111
 *   @0x2b5810 bne 0x2b57d0 <jinit_input_controller+0x18f0>
 *   @0x2b5814 ldrb r1, [r12, #0x3]
 *   @0x2b5818 cmp r1, #98
 *   @0x2b581c bne 0x2b57d0 <jinit_input_controller+0x18f0>
 *   @0x2b5820 ldrb r1, [r12, #0x4]
 *   @0x2b5824 cmp r1, #101
 *   @0x2b5828 bne 0x2b57d0 <jinit_input_controller+0x18f0>
 *   @0x2b582c ldrb r9, [r12, #0x7]
 *   @0x2b5830 mov r2, #76
 *   @0x2b5834 ldrb r8, [r12, #0x9]
 *   @0x2b5838 mov r1, #1
 *   @0x2b583c ldrb r6, [r12, #0x5]
 *   @0x2b5840 ldrb r5, [r12, #0xb]
 *   @0x2b5844 ldr r3, [r0]
 *   @0x2b5848 ldrb r7, [r12, #0x8]
 *   @0x2b584c ldrb lr, [r12, #0xa]
 *   @0x2b5850 ldrb r12, [r12, #0x6]
 *   @0x2b5854 add r7, r7, r9, lsl #8
 *   @0x2b5858 add lr, lr, r8, lsl #8
 *   @0x2b585c str r7, [r3, #0x1c]
 *   @0x2b5860 add r12, r12, r6, lsl #8
 *   @0x2b5864 str lr, [r3, #0x20]
 *   @0x2b5868 str r12, [r3, #0x18]
 *   @0x2b586c str r5, [r3, #0x24]
 *   @0x2b5870 str r2, [r3, #0x14]
 *   @0x2b5874 ldr r3, [r3, #0x4]
 *   @0x2b5878 blx r3
 *   @0x2b587c mov r3, #1
 *   @0x2b5880 strb r5, [r4, #0x109]
 *   @0x2b5884 strb r3, [r4, #0x108]
 *   @0x2b5888 pop {r3, r4, r5, r6, r7, r8, r9, pc}
 *   @0x2b588c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b5890 sub sp, sp, #28
 *   @0x2b5894 ldr r9, [r0, #0x18]
 *   @0x2b5898 mov r6, r0
 *   @0x2b589c ldr r7, [pc, #0x1b4]
 *   @0x2b58a0 ldr r7, [pc, r7]
 *   @0x2b58a4 ldr r5, [r9, #0x4]
 *   @0x2b58a8 ldr r12, [r9]
 *   @0x2b58ac ldr r3, [r7]
 *   @0x2b58b0 cmp r5, #0
 *   @0x2b58b4 str r3, [sp, #0x14]
 *   @0x2b58b8 beq 0x2b59ec <jinit_input_controller+0x1b0c>
 *   @0x2b58bc ldrb r8, [r12]
 *   @0x2b58c0 subs r5, r5, #1
 *   @0x2b58c4 addne r12, r12, #1
 *   @0x2b58c8 lsl r8, r8, #8
 *   @0x2b58cc beq 0x2b5a04 <jinit_input_controller+0x1b24>
 *   @0x2b58d0 ldrb r3, [r12]
 *   @0x2b58d4 sub r5, r5, #1
 *   @0x2b58d8 add r12, r12, #1
 *   @0x2b58dc add r8, r3, r8
 *   @0x2b58e0 sub r8, r8, #2
 *   @0x2b58e4 cmp r8, #13
 *   @0x2b58e8 ble 0x2b5944 <jinit_input_controller+0x1a64>
 *   @0x2b58ec mov r10, #14
 *   @0x2b58f0 mov r4, #0
 *   @0x2b58f4 b 0x2b591c <jinit_input_controller+0x1a3c>
 *   @0x2b58f8 ldrb r1, [r12]
 *   @0x2b58fc add r3, sp, #4
 *   @0x2b5900 sub r5, r5, #1
 *   @0x2b5904 add r11, r12, #1
 *   @0x2b5908 strb r1, [r4, r3]
 *   @0x2b590c add r4, r4, #1
 *   @0x2b5910 cmp r4, r10
 *   @0x2b5914 bhs 0x2b597c <jinit_input_controller+0x1a9c>
 *   @0x2b5918 mov r12, r11
 *   @0x2b591c cmp r5, #0
 *   @0x2b5920 bne 0x2b58f8 <jinit_input_controller+0x1a18>
 *   @0x2b5924 ldr r3, [r9, #0xc]
 *   @0x2b5928 mov r0, r6
 *   @0x2b592c blx r3
 *   @0x2b5930 cmp r0, #0
 *   @0x2b5934 beq 0x2b59fc <jinit_input_controller+0x1b1c>
 *   @0x2b5938 ldr r12, [r9]
 *   @0x2b593c ldr r5, [r9, #0x4]
 *   @0x2b5940 b 0x2b58f8 <jinit_input_controller+0x1a18>
 *   @0x2b5944 cmp r8, #0
 *   @0x2b5948 movgt r10, r8
 *   @0x2b594c bgt 0x2b58f0 <jinit_input_controller+0x1a10>
 *   @0x2b5950 ldr r3, [r6, #0x17c]
 *   @0x2b5954 mov r11, r12
 *   @0x2b5958 mov r10, #0
 *   @0x2b595c cmp r3, #224
 *   @0x2b5960 bne 0x2b598c <jinit_input_controller+0x1aac>
 *   @0x2b5964 mov r2, r10
 *   @0x2b5968 mov r0, r6
 *   @0x2b596c add r1, sp, #4
 *   @0x2b5970 mov r3, r8
 *   @0x2b5974 bl 0x2b4374 <jinit_input_controller+0x494>
 *   @0x2b5978 b 0x2b59a8 <jinit_input_controller+0x1ac8>
 *   @0x2b597c ldr r3, [r6, #0x17c]
 *   @0x2b5980 rsb r8, r10, r8
 *   @0x2b5984 cmp r3, #224
 *   @0x2b5988 beq 0x2b5964 <jinit_input_controller+0x1a84>
 *   @0x2b598c cmp r3, #238
 *   @0x2b5990 bne 0x2b5a24 <jinit_input_controller+0x1b44>
 *   @0x2b5994 mov r2, r10
 *   @0x2b5998 mov r0, r6
 *   @0x2b599c add r1, sp, #4
 *   @0x2b59a0 mov r3, r8
 *   @0x2b59a4 bl 0x2b57b0 <jinit_input_controller+0x18d0>
 *   @0x2b59a8 cmp r8, #0
 *   @0x2b59ac str r11, [r9]
 *   @0x2b59b0 str r5, [r9, #0x4]
 *   @0x2b59b4 movle r0, #1
 *   @0x2b59b8 ble 0x2b59d4 <jinit_input_controller+0x1af4>
 *   @0x2b59bc ldr r3, [r6, #0x18]
 *   @0x2b59c0 mov r0, r6
 *   @0x2b59c4 mov r1, r8
 *   @0x2b59c8 ldr r3, [r3, #0x10]
 *   @0x2b59cc blx r3
 *   @0x2b59d0 mov r0, #1
 *   @0x2b59d4 ldr r2, [sp, #0x14]
 *   @0x2b59d8 ldr r3, [r7]
 *   @0x2b59dc cmp r2, r3
 *   @0x2b59e0 bne 0x2b5a54 <jinit_input_controller+0x1b74>
 *   @0x2b59e4 add sp, sp, #28
 *   @0x2b59e8 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b59ec ldr r3, [r9, #0xc]
 *   @0x2b59f0 blx r3
 *   @0x2b59f4 cmp r0, #0
 *   @0x2b59f8 bne 0x2b5a48 <jinit_input_controller+0x1b68>
 *   @0x2b59fc mov r0, #0
 *   @0x2b5a00 b 0x2b59d4 <jinit_input_controller+0x1af4>
 *   @0x2b5a04 ldr r3, [r9, #0xc]
 *   @0x2b5a08 mov r0, r6
 *   @0x2b5a0c blx r3
 *   @0x2b5a10 cmp r0, #0
 *   @0x2b5a14 beq 0x2b59fc <jinit_input_controller+0x1b1c>
 *   @0x2b5a18 ldr r12, [r9]
 *   @0x2b5a1c ldr r5, [r9, #0x4]
 *   @0x2b5a20 b 0x2b58d0 <jinit_input_controller+0x19f0>
 *   @0x2b5a24 ldr r2, [r6]
 *   @0x2b5a28 mov r1, #68
 *   @0x2b5a2c mov r0, r6
 *   @0x2b5a30 str r3, [r2, #0x18]
 *   @0x2b5a34 ldr r3, [r6]
 *   @0x2b5a38 str r1, [r2, #0x14]
 *   @0x2b5a3c ldr r3, [r3]
 *   @0x2b5a40 blx r3
 *   @0x2b5a44 b 0x2b59a8 <jinit_input_controller+0x1ac8>
 *   @0x2b5a48 ldr r12, [r9]
 *   @0x2b5a4c ldr r5, [r9, #0x4]
 *   @0x2b5a50 b 0x2b58bc <jinit_input_controller+0x19dc>
 *   @0x2b5a54 bl 0xb65d4 <__stack_chk_fail@plt>
 *   @0x2b5a58 ldrheq r8, [r3], -r0
 *   @0x2b5a5c push {r4, r5, r6, r7, r8, r9, r10, r11, lr}
 *   @0x2b5a60 sub sp, sp, #12
 *   @0x2b5a64 ldr r10, [r0, #0x194]
 *   @0x2b5a68 mov r11, r0
 *   @0x2b5a6c ldr r9, [r0, #0x18]
 *   @0x2b5a70 ldr r1, [r10, #0xa0]
 *   @0x2b5a74 ldr r6, [r9]
 *   @0x2b5a78 cmp r1, #0
 *   @0x2b5a7c ldr r4, [r9, #0x4]
 *   @0x2b5a80 str r1, [sp, #0x4]
 *   @0x2b5a84 beq 0x2b5c14 <jinit_input_controller+0x1d34>
 *   @0x2b5a88 ldr r2, [sp, #0x4]
 *   @0x2b5a8c ldr r5, [r10, #0xa4]
 *   @0x2b5a90 ldr r7, [r2, #0x10]
 *   @0x2b5a94 ldr r8, [r2, #0xc]
 *   @0x2b5a98 add r7, r7, r5
 *   @0x2b5a9c cmp r8, r5
 *   @0x2b5aa0 bls 0x2b5af8 <jinit_input_controller+0x1c18>
 *   @0x2b5aa4 cmp r4, #0
 *   @0x2b5aa8 str r6, [r9]
 *   @0x2b5aac str r4, [r9, #0x4]
 *   @0x2b5ab0 str r5, [r10, #0xa4]
 *   @0x2b5ab4 beq 0x2b5bb0 <jinit_input_controller+0x1cd0>
 *   @0x2b5ab8 cmp r4, #0
 *   @0x2b5abc cmpne r8, r5
 *   @0x2b5ac0 bls 0x2b5af0 <jinit_input_controller+0x1c10>
 *   @0x2b5ac4 subs r4, r4, #1
 *   @0x2b5ac8 add r5, r5, #1
 *   @0x2b5acc ldrb r3, [r6], #1
 *   @0x2b5ad0 moveq r2, #0
 *   @0x2b5ad4 movne r2, #1
 *   @0x2b5ad8 cmp r5, r8
 *   @0x2b5adc movhs r2, #0
 *   @0x2b5ae0 andlo r2, r2, #1
 *   @0x2b5ae4 cmp r2, #0
 *   @0x2b5ae8 strb r3, [r7], #1
 *   @0x2b5aec bne 0x2b5ac4 <jinit_input_controller+0x1be4>
 *   @0x2b5af0 cmp r5, r8
 *   @0x2b5af4 blo 0x2b5aa4 <jinit_input_controller+0x1bc4>
 *   @0x2b5af8 ldr r2, [r11, #0x10c]
 *   @0x2b5afc cmp r2, #0
 *   @0x2b5b00 bne 0x2b5b0c <jinit_input_controller+0x1c2c>
 *   @0x2b5b04 b 0x2b5cb0 <jinit_input_controller+0x1dd0>
 *   @0x2b5b08 mov r2, r3
 *   @0x2b5b0c ldr r3, [r2]
 *   @0x2b5b10 cmp r3, #0
 *   @0x2b5b14 bne 0x2b5b08 <jinit_input_controller+0x1c28>
 *   @0x2b5b18 ldr r1, [sp, #0x4]
 *   @0x2b5b1c str r1, [r2]
 *   @0x2b5b20 ldr r2, [sp, #0x4]
 *   @0x2b5b24 ldr r5, [r2, #0x8]
 *   @0x2b5b28 ldr r1, [r2, #0x10]
 *   @0x2b5b2c rsb r5, r8, r5
 *   @0x2b5b30 ldr r3, [r11, #0x17c]
 *   @0x2b5b34 mov r2, #0
 *   @0x2b5b38 str r2, [r10, #0xa0]
 *   @0x2b5b3c cmp r3, #224
 *   @0x2b5b40 beq 0x2b5be4 <jinit_input_controller+0x1d04>
 *   @0x2b5b44 cmp r3, #238
 *   @0x2b5b48 beq 0x2b5bd0 <jinit_input_controller+0x1cf0>
 *   @0x2b5b4c ldr r2, [r11]
 *   @0x2b5b50 add r8, r5, r8
 *   @0x2b5b54 mov r12, #91
 *   @0x2b5b58 mov r0, r11
 *   @0x2b5b5c mov r1, #1
 *   @0x2b5b60 str r3, [r2, #0x18]
 *   @0x2b5b64 ldr r3, [r11]
 *   @0x2b5b68 str r12, [r2, #0x14]
 *   @0x2b5b6c str r8, [r3, #0x1c]
 *   @0x2b5b70 ldr r3, [r11]
 *   @0x2b5b74 ldr r3, [r3, #0x4]
 *   @0x2b5b78 blx r3
 *   @0x2b5b7c cmp r5, #0
 *   @0x2b5b80 str r6, [r9]
 *   @0x2b5b84 str r4, [r9, #0x4]
 *   @0x2b5b88 movle r0, #1
 *   @0x2b5b8c ble 0x2b5ba8 <jinit_input_controller+0x1cc8>
 *   @0x2b5b90 ldr r3, [r11, #0x18]
 *   @0x2b5b94 mov r0, r11
 *   @0x2b5b98 mov r1, r5
 *   @0x2b5b9c ldr r3, [r3, #0x10]
 *   @0x2b5ba0 blx r3
 *   @0x2b5ba4 mov r0, #1
 *   @0x2b5ba8 add sp, sp, #12
 *   @0x2b5bac pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b5bb0 ldr r3, [r9, #0xc]
 *   @0x2b5bb4 mov r0, r11
 *   @0x2b5bb8 blx r3
 *   @0x2b5bbc cmp r0, #0
 *   @0x2b5bc0 beq 0x2b5c08 <jinit_input_controller+0x1d28>
 *   @0x2b5bc4 ldr r6, [r9]
 *   @0x2b5bc8 ldr r4, [r9, #0x4]
 *   @0x2b5bcc b 0x2b5ab8 <jinit_input_controller+0x1bd8>
 *   @0x2b5bd0 mov r2, r8
 *   @0x2b5bd4 mov r0, r11
 *   @0x2b5bd8 mov r3, r5
 *   @0x2b5bdc bl 0x2b57b0 <jinit_input_controller+0x18d0>
 *   @0x2b5be0 b 0x2b5b7c <jinit_input_controller+0x1c9c>
 *   @0x2b5be4 mov r2, r8
 *   @0x2b5be8 mov r0, r11
 *   @0x2b5bec mov r3, r5
 *   @0x2b5bf0 bl 0x2b4374 <jinit_input_controller+0x494>
 *   @0x2b5bf4 b 0x2b5b7c <jinit_input_controller+0x1c9c>
 *   @0x2b5bf8 ldr r3, [r9, #0xc]
 *   @0x2b5bfc blx r3
 *   @0x2b5c00 cmp r0, #0
 *   @0x2b5c04 bne 0x2b5ce8 <jinit_input_controller+0x1e08>
 *   @0x2b5c08 mov r0, #0
 *   @0x2b5c0c add sp, sp, #12
 *   @0x2b5c10 pop {r4, r5, r6, r7, r8, r9, r10, r11, pc}
 *   @0x2b5c14 cmp r4, #0
 *   @0x2b5c18 beq 0x2b5bf8 <jinit_input_controller+0x1d18>
 *   @0x2b5c1c ldrb r5, [r6]
 *   @0x2b5c20 subs r4, r4, #1
 *   @0x2b5c24 add r6, r6, #1
 *   @0x2b5c28 lsl r5, r5, #8
 *   @0x2b5c2c beq 0x2b5cc8 <jinit_input_controller+0x1de8>
 *   @0x2b5c30 ldrb r3, [r6]
 *   @0x2b5c34 sub r4, r4, #1
 *   @0x2b5c38 add r6, r6, #1
 *   @0x2b5c3c add r5, r3, r5
 *   @0x2b5c40 subs r5, r5, #2
 *   @0x2b5c44 bmi 0x2b5cbc <jinit_input_controller+0x1ddc>
 *   @0x2b5c48 ldr r3, [r11, #0x17c]
 *   @0x2b5c4c mov r0, r11
 *   @0x2b5c50 mov r1, #1
 *   @0x2b5c54 cmp r3, #254
 *   @0x2b5c58 subne r3, r3, #200
 *   @0x2b5c5c ldreq r8, [r10, #0x5c]
 *   @0x2b5c60 ldrne r8, [r10, r3, lsl #2]
 *   @0x2b5c64 ldr r3, [r11, #0x4]
 *   @0x2b5c68 cmp r8, r5
 *   @0x2b5c6c movhs r8, r5
 *   @0x2b5c70 add r2, r8, #20
 *   @0x2b5c74 ldr r3, [r3, #0x4]
 *   @0x2b5c78 blx r3
 *   @0x2b5c7c ldr r2, [r11, #0x17c]
 *   @0x2b5c80 mov r3, #0
 *   @0x2b5c84 str r5, [r0, #0x8]
 *   @0x2b5c88 add r7, r0, #20
 *   @0x2b5c8c str r8, [r0, #0xc]
 *   @0x2b5c90 mov r5, r3
 *   @0x2b5c94 strb r2, [r0, #0x4]
 *   @0x2b5c98 str r7, [r0, #0x10]
 *   @0x2b5c9c str r3, [r0]
 *   @0x2b5ca0 str r0, [sp, #0x4]
 *   @0x2b5ca4 str r0, [r10, #0xa0]
 *   @0x2b5ca8 str r3, [r10, #0xa4]
 *   @0x2b5cac b 0x2b5a9c <jinit_input_controller+0x1bbc>
 *   @0x2b5cb0 ldr r3, [sp, #0x4]
 *   @0x2b5cb4 str r3, [r11, #0x10c]
 *   @0x2b5cb8 b 0x2b5b20 <jinit_input_controller+0x1c40>
 *   @0x2b5cbc mov r8, #0
 *   @0x2b5cc0 mov r1, r8
 *   @0x2b5cc4 b 0x2b5b30 <jinit_input_controller+0x1c50>
 *   @0x2b5cc8 ldr r3, [r9, #0xc]
 *   @0x2b5ccc mov r0, r11
 *   @0x2b5cd0 blx r3
 *   @0x2b5cd4 cmp r0, #0
 *   @0x2b5cd8 beq 0x2b5c08 <jinit_input_controller+0x1d28>
 *   @0x2b5cdc ldr r6, [r9]
 *   @0x2b5ce0 ldr r4, [r9, #0x4]
 *   @0x2b5ce4 b 0x2b5c30 <jinit_input_controller+0x1d50>
 *   @0x2b5ce8 ldr r6, [r9]
 *   @0x2b5cec ldr r4, [r9, #0x4]
 *   @0x2b5cf0 b 0x2b5c1c <jinit_input_controller+0x1d3c>
 *   @0x2b5cf4 ldr r3, [r0, #0x17c]
 *   @0x2b5cf8 push {r4, lr}
 *   @0x2b5cfc cmp r3, #0
 *   @0x2b5d00 mov r4, r0
 *   @0x2b5d04 beq 0x2b5d54 <jinit_input_controller+0x1e74>
 *   @0x2b5d08 ldr r2, [r4, #0x194]
 *   @0x2b5d0c ldr r2, [r2, #0x10]
 *   @0x2b5d10 add r1, r2, #208
 *   @0x2b5d14 cmp r1, r3
 *   @0x2b5d18 beq 0x2b5d68 <jinit_input_controller+0x1e88>
 *   @0x2b5d1c ldr r3, [r4, #0x18]
 *   @0x2b5d20 mov r1, r2
 *   @0x2b5d24 mov r0, r4
 *   @0x2b5d28 ldr r3, [r3, #0x14]
 *   @0x2b5d2c blx r3
 *   @0x2b5d30 cmp r0, #0
 *   @0x2b5d34 beq 0x2b5d60 <jinit_input_controller+0x1e80>
 *   @0x2b5d38 ldr r3, [r4, #0x194]
 *   @0x2b5d3c mov r0, #1
 *   @0x2b5d40 ldr r2, [r3, #0x10]
 *   @0x2b5d44 add r2, r2, r0
 *   @0x2b5d48 and r2, r2, #7
 *   @0x2b5d4c str r2, [r3, #0x10]
 *   @0x2b5d50 pop {r4, pc}
 *   @0x2b5d54 bl 0x2b46e0 <jinit_input_controller+0x800>
 *   @0x2b5d58 cmp r0, #0
 *   @0x2b5d5c bne 0x2b5d98 <jinit_input_controller+0x1eb8>
 *   @0x2b5d60 mov r0, #0
 *   @0x2b5d64 pop {r4, pc}
 *   @0x2b5d68 ldr r3, [r4]
 *   @0x2b5d6c mov r12, #98
 *   @0x2b5d70 mov r0, r4
 *   @0x2b5d74 mov r1, #3
 *   @0x2b5d78 str r2, [r3, #0x18]
 *   @0x2b5d7c ldr r2, [r4]
 *   @0x2b5d80 str r12, [r3, #0x14]
 *   @0x2b5d84 ldr r3, [r2, #0x4]
 *   @0x2b5d88 blx r3
 *   @0x2b5d8c mov r3, #0
 *   @0x2b5d90 str r3, [r4, #0x17c]
 *   @0x2b5d94 b 0x2b5d38 <jinit_input_controller+0x1e58>
 *   @0x2b5d98 ldr r3, [r4, #0x17c]
 *
 * ══ §3/7 anon_2b7148  0x2b7148  size 3728  105 条（0x2b7148..0x2b7fd8）｜其中 827 条已由别的卡落锚，本节不再重复
 * @func 0x2b7148 0x2b7608  size 1216  105 条
 * 部分覆盖: 本节 105/304 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: jpeg_fill_bit_buffer×11 / anon_2b7148×4 / anon_2b7148+0x2fc×3 / jpeg_huff_decode×3 / jpeg_make_d_derived_tbl×2 / anon_2b7148+0x6c / anon_2b7148+0x288 / anon_2b7148+0x1e8
 * 字段偏移 top8: 0x14×28 / 0x18×27 / 0x4×26 / 0x10×24 / 0x28×23 / 0xc×20 / 0x2c×14 / 0x24×13
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2b7148 push {r4, r5, r6, lr}
 *   @0x2b714c mov r6, #0
 *   @0x2b7150 ldr r4, [r0, #0x198]
 *   @0x2b7154 mov r5, r0
 *   @0x2b7158 ldr r3, [r0, #0x194]
 *   @0x2b715c ldr r2, [r4, #0x10]
 *   @0x2b7160 ldr r12, [r3, #0x14]
 *   @0x2b7164 cmp r2, r6
 *   @0x2b7168 add lr, r2, #7
 *   @0x2b716c ldr r1, [r3, #0x8]
 *   @0x2b7170 movlt r2, lr
 *   @0x2b7174 add r2, r12, r2, asr #3
 *   @0x2b7178 str r2, [r3, #0x14]
 *   @0x2b717c str r6, [r4, #0x10]
 *   @0x2b7180 blx r1
 *   @0x2b7184 cmp r0, #0
 *   @0x2b7188 popeq {r4, r5, r6, pc}
 *   @0x2b718c ldr r1, [r5, #0x124]
 *   @0x2b7190 cmp r1, r6
 *   @0x2b7194 addgt r1, r4, r1, lsl #2
 *   @0x2b7198 movgt r2, r6
 *   @0x2b719c movgt r3, r4
 *   @0x2b71a0 ble 0x2b71b4 <jinit_merged_upsampler+0x218>
 *   @0x2b71a4 str r2, [r3, #0x18]
 *   @0x2b71a8 add r3, r3, #4
 *   @0x2b71ac cmp r3, r1
 *   @0x2b71b0 bne 0x2b71a4 <jinit_merged_upsampler+0x208>
 *   @0x2b71b4 ldr r3, [r5, #0x17c]
 *   @0x2b71b8 mov r1, #0
 *   @0x2b71bc ldr r2, [r5, #0xfc]
 *   @0x2b71c0 mov r0, #1
 *   @0x2b71c4 cmp r3, r1
 *   @0x2b71c8 str r1, [r4, #0x14]
 *   @0x2b71cc strbeq r3, [r4, #0x8]
 *   @0x2b71d0 str r2, [r4, #0x28]
 *   @0x2b71d4 pop {r4, r5, r6, pc}
 *   @0x2b71d8 ldr r3, [r0, #0x16c]
 *   @0x2b74f8 push {r4, r5, r6, r7, r8, r9, r10, lr}
 *   @0x2b74fc cmp r2, #0
 *   @0x2b7500 ldr r7, [r0, #0x178]
 *   @0x2b7504 sub sp, sp, #24
 *   @0x2b7508 mov r8, r0
 *   @0x2b750c mov r5, r1
 *   @0x2b7510 ldr r10, [r0, #0x198]
 *   @0x2b7514 lsl r7, r3, r7
 *   @0x2b7518 beq 0x2b7528 <jinit_merged_upsampler+0x58c>
 *   @0x2b751c ldr r3, [r10, #0x28]
 *   @0x2b7520 cmp r3, #0
 *   @0x2b7524 beq 0x2b75ec <jinit_merged_upsampler+0x650>
 *   @0x2b7528 ldr r3, [r8, #0x18]
 *   @0x2b752c ldr r0, [r8, #0x140]
 *   @0x2b7530 str r8, [sp, #0x14]
 *   @0x2b7534 ldr r12, [r3]
 *   @0x2b7538 cmp r0, #0
 *   @0x2b753c ldr r4, [r3, #0x4]
 *   @0x2b7540 subgt r5, r5, #4
 *   @0x2b7544 ldr r1, [r10, #0xc]
 *   @0x2b7548 addgt r9, sp, #4
 *   @0x2b754c str r12, [sp, #0x4]
 *   @0x2b7550 str r4, [sp, #0x8]
 *   @0x2b7554 movgt r4, #0
 *   @0x2b7558 ldr r2, [r10, #0x10]
 *   @0x2b755c bgt 0x2b7584 <jinit_merged_upsampler+0x5e8>
 *   @0x2b7560 b 0x2b75c4 <jinit_merged_upsampler+0x628>
 *   @0x2b7564 sub r2, r2, #1
 *   @0x2b7568 asr r3, r1, r2
 *   @0x2b756c tst r3, #1
 *   @0x2b7570 ldrhne r3, [r6]
 *   @0x2b7574 orrne r3, r7, r3
 *   @0x2b7578 strhne r3, [r6]
 *   @0x2b757c cmp r0, r4
 *   @0x2b7580 ble 0x2b75b8 <jinit_merged_upsampler+0x61c>
 *   @0x2b7584 cmp r2, #0
 *   @0x2b7588 add r4, r4, #1
 *   @0x2b758c ldr r6, [r5, #0x4]!
 *   @0x2b7590 bgt 0x2b7564 <jinit_merged_upsampler+0x5c8>
 *   @0x2b7594 mov r0, r9
 *   @0x2b7598 mov r3, #1
 *   @0x2b759c bl 0x2bea2c <jpeg_fill_bit_buffer>
 *   @0x2b75a0 cmp r0, #0
 *   @0x2b75a4 beq 0x2b75f8 <jinit_merged_upsampler+0x65c>
 *   @0x2b75a8 ldr r1, [sp, #0xc]
 *   @0x2b75ac ldr r2, [sp, #0x10]
 *   @0x2b75b0 ldr r0, [r8, #0x140]
 *   @0x2b75b4 b 0x2b7564 <jinit_merged_upsampler+0x5c8>
 *   @0x2b75b8 ldr r3, [r8, #0x18]
 *   @0x2b75bc ldr r12, [sp, #0x4]
 *   @0x2b75c0 ldr r4, [sp, #0x8]
 *   @0x2b75c4 ldr r5, [r10, #0x28]
 *   @0x2b75c8 mov r0, #1
 *   @0x2b75cc str r12, [r3]
 *   @0x2b75d0 str r4, [r3, #0x4]
 *   @0x2b75d4 sub r3, r5, #1
 *   @0x2b75d8 str r1, [r10, #0xc]
 *   @0x2b75dc str r2, [r10, #0x10]
 *   @0x2b75e0 str r3, [r10, #0x28]
 *   @0x2b75e4 add sp, sp, #24
 *   @0x2b75e8 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b75ec bl 0x2b7148 <jinit_merged_upsampler+0x1ac>
 *   @0x2b75f0 cmp r0, #0
 *   @0x2b75f4 bne 0x2b7528 <jinit_merged_upsampler+0x58c>
 *   @0x2b75f8 mov r0, #0
 *   @0x2b75fc add sp, sp, #24
 *   @0x2b7600 pop {r4, r5, r6, r7, r8, r9, r10, pc}
 *   @0x2b7604 ldr r3, [r0, #0xfc]
 *
 * ══ §4/7 png_read_row  0x2a7488  size 856  45 条（0x2a7488..0x2a77e0）｜其中 169 条已由别的卡落锚，本节不再重复
 * @func 0x2a749c 0x2a77b0  size 788  45 条
 * 部分覆盖: 本节 45/332 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_error×3 / png_combine_row×2 / anon_2b389c+0x3e8 / 0x473d78 / png_read_row+0x140 / 0xfeb73ad0 / png_crc_finish / 0xb6c40
 * 字段偏移 top8: 0x8×1 / 0x14×1 / 0x18×1 / 0x1c×1 / 0x20×1 / 0x24×1 / 0x228×1 / 0x-38×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a749c ldrtmi r0, [r11], -r12, ror #24
 *   @0x2a74a4 ldmdbvc r11, {r0, r2, r8, r9, r10, r11}
 *   @0x2a74ac ldm r12!, {r2, r3, r12, sp}
 *   @0x2a74b0 strgt r0, [pc], -pc
 *   @0x2a74c4 stm r6, {r0, r1, r2}
 *   @0x2a74c8 .word 0x2c000007
 *   @0x2a74dc .word 0xf894ffdb
 *   @0x2a74e0 blhs 0x2b3c84 <jpeg_finish_output+0x494>
 *   @0x2a74e8 .word 0x079f3134
 *   @0x2a74f0 .word 0xf8d421e8
 *   @0x2a74f4 bhs 0x3f3b9c <VS_Common+0x840>
 *   @0x2a74fc mrsne pc, apsr
 *   @0x2a75ac .word 0xf8d4ff3f
 *   @0x2a75b0 .word 0xf8d431b0
 *   @0x2a75b4 .word 0xf8c421a4
 *   @0x2a75b8 .word 0xf8943144
 *   @0x2a75bc blhs 0x473d78 <g_RomDisk+0x7c558>
 *   @0x2a75d4 .word 0xf8d43148
 *   @0x2a75d8 bllt 0xfeb73ad0 <b2_toiTime+0xfffffffffe41a62c>
 *   @0x2a75e4 .word 0xf8d477f0
 *   @0x2a75e8 stmiblt r3!, {r4, r6, r7, r8, r12, sp}
 *   @0x2a75f8 ldrtmi pc, [r1], -r5, ror #21
 *   @0x2a7600 .word 0x463801d0
 *   @0x2a7618 qsub16mi r2, r0, r4
 *   @0x2a7624 .word 0xf8c4213c
 *   @0x2a7628 svclt #0x881138
 *   @0x2a7644 .word 0xf50431d0
 *   @0x2a7648 swphs r7, r12, [r1]
 *   @0x2a765c ldmdblt r3, {r2, r3, r4, r5, r8, r12, sp}
 *   @0x2a76d0 stmdble r2, {r0, r1, r2, r3, r6, r7, r8, r12, sp}
 *   @0x2a76f8 movwlo r7, #0x11e2
 *   @0x2a7710 .word 0xf8d4ef56
 *   @0x2a7714 smmlseq r9, r12, r2, r3
 *   @0x2a771c blhs 0x12b42b4 <b2_toiTime+0xb5ae10>
 *   @0x2a7724 .word 0xf50411b0
 *   @0x2a7728 smlattlo r1, r2, r0, r7
 *   @0x2a7738 subseq r3, r10, #48, #2
 *   @0x2a774c .word 0x079b3134
 *   @0x2a7754 blhs 0x3f3efc <VS_Common+0xba0>
 *   @0x2a7764 bge 0x733f0c <g_SWFvertbuff+0x60e44>
 *   @0x2a7780 ldmdage r2, {r3, r5, r6, r7, r8, r12, sp}
 *   @0x2a7788 strtmi r0, [r0], -r3, lsl #7
 *   @0x2a7794 andle r0, r4, r0, lsl #30
 *   @0x2a77a0 .word 0xb125fa47
 *   @0x2a77ac strtmi pc, [r0], -r1, asr #20
 *
 * ══ §5/7 png_set_read_fn  0x2a804c  size 80  3 条（0x2a804c..0x2a809c）｜其中 17 条已由别的卡落锚，本节不再重复
 * @func 0x2a8054 0x2a8090  size 60  3 条
 * 部分覆盖: 本节 3/25 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: png_warning
 * 字段偏移 top8: 0x100×1 / 0x290×1 / 0x36c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a8054 tstlt r2, r8, lsl r1
 *   @0x2a807c stmdbmi r6, {r0, r1, r3, r4, r5, r6, r7, r8, r11, r12, sp, lr, pc}
 *   @0x2a808c ldclt p2, c3, [r0, #-64]
 *
 * ══ §6/7 png_read_image  0x2a7840  size 60  3 条（0x2a7840..0x2a787c）｜其中 12 条已由别的卡落锚，本节不再重复
 * @func 0x2a784c 0x2a7874  size 40  3 条
 * 部分覆盖: 本节 3/18 条（其余由其它卡的同一 @func 主张）
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x1c×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0x2a784c .word 0xf8d5ffb2
 *   @0x2a7850 .word 0x26007190
 *   @0x2a7870 ldrb pc, [r5, r11, lsl #28]!
 *
 * ══ §7/7 _spAnimationCallback(spAnimationState*, int, spEventType, spEvent*, int)  0xbeda0  size 8  2 条（0xbeda0..0xbeda8）
 * @func 0xbeda0 0xbeda8  size 8  2 条
 * 级别: 骨架（结构 + 锚点；语义未展开）
 * GOT 基址: 无标准序言
 * 门字节（加载点→目标全局）: 无
 * 调用序列: 无
 * 字段偏移 top8: 0x14×1
 * VFP 指令 0 条
 * 未主张: 形参/返回值、分支语义、字段含义 —— open
 * ────────────────────────────────────────────────────────────────────────────
 *   @0xbeda0 ldr r0, [r0, #0x14]
 *   @0xbeda4 b 0xbebe4 <_ZN17CSkeletonInstance13EventCallbackEi11spEventTypeP7spEventi>
 */
